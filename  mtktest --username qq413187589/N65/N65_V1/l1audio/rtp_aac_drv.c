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
 * rtp_aac_drv.c
 *
 * Project:
 * --------
 *   MTK6228
 *
 * Description:
 * ------------
 *   RTP Audio interface for AAC/HE-AAC
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
//#define STREAM_SUPPORT
//#define AUD_RTP_UNIT_TEST

#include "media.h"
#include "audio_rtp.h"
#include "l1sp_trc.h"
#include "afe.h"
#include "aac_drv.h"

#if  defined(STREAM_SUPPORT)

#if defined (AUD_RTP_UNIT_TEST)
static uint8 packet_buffer[1113] ={
0x80, 0xe1, 0xc8, 0xfc, 0x16, 0x32,
0xdc, 0x1b, 0x50, 0xb6, 0xaf, 0x0f, 0x00, 0x40, 0x00, 0x38, 0x0b, 0xb0, 0x0b, 0x28, 0x0b, 0x08,
0x20, 0x00, 0x20, 0x00, 0x00, 0x80, 0x0e, 0x21, 0x4e, 0xe3, 0x2e, 0x07, 0xe2, 0xfb, 0xa4, 0x84,
0x0d, 0xf6, 0x4c, 0x0d, 0xf6, 0xc5, 0x08, 0x90, 0x3f, 0x92, 0x81, 0x5b, 0xdd, 0x79, 0x05, 0xdb,
0x39, 0xca, 0xb1, 0x2f, 0x51, 0x9c, 0xe5, 0x21, 0xcb, 0x7b, 0xc0, 0x47, 0xdf, 0xbf, 0x5f, 0x49,
0xfe, 0x7d, 0xbf, 0x18, 0xc4, 0xfd, 0x97, 0xc7, 0x89, 0xfc, 0x09, 0xf8, 0xc6, 0x4b, 0xc3, 0x1c,
0x80, 0x8e, 0xa3, 0x30, 0x48, 0x4b, 0x27, 0xaa, 0xdd, 0x10, 0x8f, 0xaa, 0xc1, 0x71, 0x64, 0x8b,
0x1c, 0x9d, 0xd0, 0x63, 0xc3, 0x7a, 0xf1, 0x08, 0x06, 0xda, 0x75, 0x21, 0xb0, 0x32, 0xf0, 0x0b,
0x3c, 0xb4, 0x40, 0x6a, 0x71, 0x56, 0x01, 0xa0, 0xc1, 0x62, 0x0f, 0x03, 0x17, 0xa4, 0x54, 0xe0,
0xf0, 0x4b, 0x1c, 0x1f, 0xfe, 0x7d, 0x8f, 0xa4, 0x38, 0xcf, 0x38, 0xc5, 0xe7, 0x18, 0xb9, 0xcb,
0x1c, 0x63, 0x78, 0xc9, 0x36, 0x8d, 0xda, 0x37, 0xfe, 0xa6, 0x07, 0x93, 0x91, 0xfa, 0x33, 0xf5,
0xf4, 0x97, 0xf2, 0xcd, 0xfa, 0xb2, 0x4f, 0xf5, 0x87, 0xd1, 0xc8, 0x73, 0x5f, 0x46, 0x91, 0xe0,
0xdd, 0x94, 0x9e, 0x9f, 0x10, 0x46, 0xee, 0x5c, 0x9e, 0x1a, 0x51, 0x1b, 0x17, 0xbf, 0x2e, 0x40,
0x2c, 0x26, 0x08, 0x5f, 0x70, 0xcf, 0x56, 0xa3, 0x38, 0xfe, 0xde, 0x77, 0x31, 0x93, 0x08, 0xb8,
0x50, 0xd5, 0xd9, 0x8a, 0x30, 0x8c, 0xf9, 0xae, 0x55, 0x0c, 0x1a, 0x85, 0x36, 0xfa, 0xe4, 0x5a,
0xfe, 0x0d, 0x20, 0x2d, 0x7b, 0x64, 0xca, 0xc8, 0x18, 0xd1, 0x8c, 0x01, 0x1e, 0x77, 0xf6, 0xe8,
0x97, 0xd8, 0x0d, 0x31, 0x3f, 0x39, 0x7e, 0x47, 0xc8, 0x7e, 0x3a, 0xe1, 0x90, 0xf0, 0x9f, 0xae,
0x48, 0xdf, 0xf1, 0x21, 0x1f, 0xc3, 0x5f, 0x78, 0x25, 0x13, 0xaa, 0x92, 0x6f, 0x33, 0x27, 0x8b,
0x9e, 0x4d, 0x9d, 0x98, 0x85, 0x6c, 0x1e, 0x99, 0xb1, 0xb0, 0xc4, 0x83, 0x5c, 0x94, 0xe5, 0x90,
0xb9, 0x3f, 0xb7, 0x88, 0xa4, 0xdc, 0xd0, 0x44, 0xcd, 0x94, 0x9f, 0x62, 0x86, 0x52, 0x19, 0x28,
0x11, 0xa5, 0xb2, 0x7e, 0x9e, 0x74, 0x05, 0xa8, 0xba, 0x46, 0xd3, 0x6d, 0xba, 0xaa, 0xc4, 0xf6,
0x05, 0x88, 0x09, 0x30, 0x59, 0x54, 0x52, 0xb1, 0x9a, 0x79, 0x57, 0x7a, 0xf9, 0x96, 0x5b, 0xfb,
0xd4, 0xbc, 0x18, 0xb6, 0x98, 0xca, 0xc0, 0xd2, 0x3d, 0x35, 0x67, 0x95, 0x8f, 0xf4, 0x7f, 0x2a,
0xfd, 0xfe, 0xcf, 0x58, 0x61, 0x8a, 0x97, 0x07, 0x2a, 0x15, 0x87, 0xdc, 0xd6, 0x07, 0x8a, 0xdb,
0x2d, 0x81, 0x36, 0x43, 0x61, 0xbe, 0x4a, 0x17, 0x8b, 0x09, 0xcb, 0xb6, 0x13, 0x6c, 0xf0, 0x04,
0xe6, 0x2a, 0x07, 0xe0, 0x3f, 0x01, 0xf8, 0x0f, 0xc2, 0x1c, 0xb7, 0xbc, 0x1c, 0x21, 0x6c, 0x14,
0x55, 0xfc, 0x14, 0x48, 0x08, 0x94, 0x0e, 0x50, 0x02, 0xfe, 0xe3, 0xad, 0x9d, 0x1d, 0x25, 0x34,
0x30, 0xf4, 0x03, 0x5d, 0xf3, 0x5e, 0xe5, 0xfd, 0xfd, 0xa8, 0x2b, 0xb8, 0x11, 0xb6, 0xba, 0xba,
0xd9, 0x80, 0xee, 0xb0, 0x13, 0xfd, 0x77, 0xf5, 0x24, 0x0a, 0xf9, 0x68, 0x79, 0xaa, 0xfa, 0xba,
0xad, 0x11, 0x24, 0x1b, 0xb4, 0x3d, 0x93, 0xb7, 0x67, 0x98, 0x6b, 0x9d, 0x6d, 0xd1, 0x2c, 0x33,
0x4b, 0x2d, 0x35, 0xa6, 0x45, 0x0b, 0xf6, 0xd2, 0x22, 0x11, 0x0b, 0x39, 0x8c, 0xec, 0x5b, 0x18,
0x7a, 0x4b, 0x98, 0xf4, 0x86, 0xe2, 0xce, 0x59, 0x6b, 0x06, 0x36, 0x99, 0xd3, 0x39, 0x19, 0x1a,
0xe9, 0xbb, 0x4e, 0xee, 0x3a, 0x88, 0xf5, 0x9c, 0x2a, 0x42, 0x34, 0x83, 0x0b, 0x57, 0xb6, 0x18,
0xa2, 0xd9, 0x0c, 0x39, 0xf6, 0x99, 0x8a, 0xca, 0x22, 0xea, 0xd7, 0xf0, 0xce, 0x7f, 0x67, 0xee,
0x47, 0x51, 0x65, 0x80, 0xa9, 0x50, 0xb6, 0x28, 0x53, 0x43, 0x5c, 0x33, 0x0c, 0x55, 0x67, 0x44,
0xba, 0xf3, 0xcc, 0x9a, 0x3e, 0xea, 0x40, 0x59, 0x52, 0x06, 0x92, 0xb0, 0xf2, 0x52, 0x63, 0x38,
0xb3, 0x51, 0xb5, 0x5f, 0x5a, 0x99, 0x33, 0xba, 0x6e, 0xe4, 0x4c, 0xf7, 0x15, 0x74, 0xba, 0x5e,
0xc6, 0x6f, 0xc7, 0x7d, 0x76, 0x5e, 0x47, 0xd5, 0x5c, 0x95, 0x9a, 0x97, 0x08, 0x62, 0x67, 0x37,
0x9b, 0x61, 0xde, 0xca, 0x69, 0x46, 0xa8, 0x22, 0xd1, 0x7c, 0xed, 0x8b, 0x61, 0x22, 0xc8, 0xbd,
0x33, 0x9a, 0x6a, 0xc7, 0x97, 0x16, 0x89, 0xe3, 0x5c, 0xa4, 0xb0, 0xce, 0xbc, 0x39, 0x13, 0x72,
0x14, 0xcd, 0x9e, 0x45, 0xd0, 0x6f, 0x9c, 0x60, 0x16, 0x3e, 0x47, 0xc9, 0x7b, 0xe2, 0xfa, 0x3f,
0xa4, 0xae, 0x7c, 0x46, 0x41, 0xdf, 0x96, 0xa8, 0x9b, 0x3a, 0xa9, 0xbc, 0xbc, 0xc2, 0xd7, 0xc2,
0x78, 0x23, 0x23, 0xe8, 0x89, 0x74, 0x0d, 0xb7, 0xd6, 0x42, 0x40, 0x4a, 0x97, 0x74, 0xee, 0x7e,
0xaf, 0xec, 0x5d, 0xf9, 0xb3, 0x2a, 0x2e, 0x6a, 0x7e, 0xc8, 0xa6, 0x8b, 0x5f, 0xb3, 0x75, 0x3d,
0x6c, 0x57, 0x8d, 0xeb, 0xea, 0x99, 0x22, 0x50, 0x78, 0x4d, 0x68, 0xf7, 0x47, 0x1a, 0x04, 0xe0,
0x4f, 0x27, 0xac, 0x82, 0x70, 0x07, 0x88, 0x08, 0xcc, 0xac, 0xbc, 0x09, 0x36, 0xe8, 0xf9, 0x16,
0x39, 0x1a, 0x36, 0xda, 0x6d, 0x30, 0x56, 0x44, 0xd5, 0x08, 0x0b, 0x31, 0xa1, 0x38, 0x91, 0x43,
0xc9, 0x39, 0x2d, 0xc1, 0x9e, 0xca, 0x3a, 0x5c, 0x16, 0x8d, 0xee, 0x40, 0x00, 0x91, 0xa8, 0x3f,
0x11, 0xc0, 0x21, 0x0c, 0x14, 0x4d, 0xfc, 0x4c, 0x1b, 0x0c, 0x84, 0x4e, 0x05, 0x1e, 0xdf, 0x20,
0xb5, 0xfe, 0x07, 0x58, 0x34, 0xd2, 0x34, 0x26, 0xcf, 0x40, 0xf0, 0x23, 0x1b, 0x41, 0x36, 0xf1,
0xbd, 0xaf, 0x3b, 0x4c, 0xf7, 0x2d, 0x73, 0x2d, 0x97, 0x3a, 0x30, 0x8f, 0x14, 0x0b, 0x58, 0xfb,
0x7c, 0x9a, 0x41, 0x44, 0x0e, 0xda, 0xc8, 0xfc, 0x72, 0x5d, 0xaf, 0x6d, 0x89, 0x99, 0xc1, 0x21,
0x4f, 0x4c, 0x3c, 0xf0, 0x4d, 0x02, 0xee, 0xe1, 0x52, 0xaa, 0xae, 0xe9, 0x9d, 0x0f, 0x58, 0x04,
0x9e, 0x53, 0x80, 0xf5, 0x45, 0x7f, 0x91, 0x24, 0xf6, 0xf5, 0x6a, 0x06, 0xf3, 0xc1, 0x31, 0x3f,
0x4c, 0xe4, 0x76, 0xe9, 0xe1, 0x7c, 0x05, 0x76, 0xae, 0xa8, 0x1d, 0x59, 0x61, 0x77, 0xa6, 0xc7,
0xe9, 0x9e, 0x8a, 0x30, 0xb2, 0xe1, 0x64, 0x08, 0x43, 0xc2, 0x97, 0x28, 0xa2, 0x80, 0x3b, 0xc8,
0xa1, 0x52, 0x8d, 0xce, 0x03, 0x14, 0x05, 0x96, 0x6c, 0xa0, 0x3d, 0xc2, 0x84, 0x53, 0x83, 0x1c,
0xcf, 0x19, 0xbd, 0x11, 0x03, 0x8e, 0x8b, 0x0b, 0x84, 0xb3, 0x9e, 0x4c, 0xfc, 0xd2, 0xf2, 0x02,
0x7c, 0x67, 0xf3, 0xef, 0x67, 0x96, 0xe0, 0xc3, 0xa2, 0x0a, 0xe0, 0x91, 0x65, 0xc0, 0xdf, 0xad,
0xd5, 0x9b, 0xc7, 0xa2, 0x45, 0x9f, 0x13, 0xeb, 0xba, 0x53, 0xcc, 0xd1, 0xad, 0xa6, 0x5b, 0x3e,
0xbb, 0x6a, 0x64, 0xf0, 0xbb, 0x45, 0x44, 0x39, 0xa6, 0xd2, 0xbb, 0xdd, 0x0a, 0x56, 0x4d, 0xa5,
0xeb, 0x25, 0xbc, 0xb3, 0x9f, 0xc0, 0xa7, 0x3f, 0x83, 0x50, 0x8b, 0xf3, 0xeb, 0x29, 0x6d, 0x40,
0xbd, 0x96, 0xbf, 0xb1, 0x61, 0x94, 0xef, 0x26, 0xb8, 0x46, 0x59, 0xd7, 0x37, 0x95, 0xe1, 0xc8,
0x39, 0x7d, 0x0f, 0x74, 0xcf, 0x6d, 0xf7, 0x9a, 0x10, 0x09, 0x44, 0x46, 0x2c, 0xe1, 0x60, 0xd9,
0x22, 0xc5, 0x08, 0x80, 0xc0, 0xd9, 0x44, 0xcd, 0xe1, 0x99, 0x6b, 0x09, 0x58, 0xa5, 0xb0, 0x7f,
0x3f, 0x16, 0xef, 0x75, 0x51, 0x5b, 0xaa, 0xde, 0xcf, 0x13, 0xd2, 0xdc, 0x0e, 0x9a, 0x96, 0xc2,
0xa4, 0x72, 0x58, 0x0b, 0x76, 0x0c, 0xf6, 0xa6, 0x95, 0xd7, 0x3c, 0x73, 0xa7, 0x76, 0xa2, 0xee,
0x6c, 0x92, 0x0e, 0x99, 0xf7, 0xbd, 0xa2, 0x42, 0x28, 0x0e, 0xa0, 0x98, 0xb2, 0xca, 0x03, 0x0d,
0xf4, 0x86, 0xcb, 0xef, 0x5e, 0x43, 0x4c, 0xd4, 0xac, 0xf4, 0xf3, 0x9c, 0xf3, 0x80, 0x2c, 0x10,
0x52, 0x30, 0x9d, 0x5c, 0xe5, 0x93, 0x81, 0x51, 0x01, 0xfa, 0x14, 0x5f, 0x70, 0x01, 0x60, 0x1a,
0xc3, 0xf1, 0x1c
};

static int packet_size[1] =
{
   1113
};
#endif // #if defined (AUD_RTP_UNIT_TEST)

// AAC silence frame
static const uint8 silenceFrame[9] = {
0x21, 0x00, 0x49, 0x90, 0x02, 0x19, 0x00, 0x23, 0x80};

static const uint8 silenceFrame_mono[16] = {
0x01, 0x40, 0x20, 0x06, 0xB0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F };

static const kal_uint32 samplingFrequencyFromIndex[16] = {
  96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050,
  16000, 12000, 11025, 8000, 7350, 0, 0, 0
};

static const kal_uint32 maxByterateFromIndex[16] = {
  0, 0, 0, 36000, 33076, 24000, 18000, 16538,
  16000, 12000, 9000, 6000, 0, 0, 0, 0
};

#define  RTP_AAC_STATE_DL_INIT           0x00
#define  RTP_AAC_STATE_DL_CONFIGURED     0x01
#define  RTP_AAC_STATE_DL_READY          0x02
#define  RTP_AAC_STATE_DL_DECODE         0x03

#define  ADTS_HEADER_SIZE 7
#define  SIL_FRAME_SIZE  9
#define  SIL_FRAME_MONO_SIZE  16
#define  MAX_BUF_DUR  6  // in sec, worst case buffer size: 216kB
#define  MAX_PACKET_LOSS 5
#define  MAX_SPEC_CONFIG_NUM 50

typedef struct aud_rtp_internal {
   AudRTP_DL_HANDLE    sAudHdl;
   kal_uint32          current_time;
   kal_uint32          uFrameDur;
   kal_uint32          bit_rate;
   kal_uint32          config;
   kal_bool            fCurrentPacketBeginsFrame;
   kal_bool            fCurrentPacketCompletesFrame;
   kal_uint8           bFreqIdx;
   kal_uint8           ADTS_Header[ADTS_HEADER_SIZE];
   kal_bool            audioMuxVersion;
   kal_bool            allStreamsSameTimeFraming;
   kal_uint8           numSubFrames;
   kal_uint8           numProgram;
   kal_uint8           numLayer;
   kal_uint8           audioSpecificConfig[MAX_SPEC_CONFIG_NUM];
   kal_uint32          audioSpecificConfigSize;
} aacRTPHdl;

static AudRTP_DL_HANDLE  *psAudRTPaac = 0;

static kal_bool getNibble( kal_uint8 const **configStr, kal_uint8 *resultNibble )
{
  kal_uint8 c = *configStr[0];
  if (c == '\0') return false; // reached the end

  if (c >= '0' && c <= '9') {
    *resultNibble = c - '0';
  } else if (c >= 'A' && c <= 'F') {
    *resultNibble = 10 + c - 'A';
  } else if (c >= 'a' && c <= 'f') {
    *resultNibble = 10 + c - 'a';
  } else {
    return false;
  }

  ++(*configStr); // move to the next nibble
  return true;
}

static kal_bool getByte( kal_uint8 const **configStr, kal_uint8 *resultByte )
{
  kal_uint8 firstNibble;
  kal_uint8 secondNibble = 0;

  if (!getNibble(configStr, &firstNibble)) return false;
  if (!getNibble(configStr, &secondNibble) && *configStr[0] != '\0') {
    // There's a second nibble, but it's malformed
    return false;
  }

  *resultByte = (firstNibble<<4)|secondNibble;
  return true;
}

static kal_uint32 _strlen(const kal_uint8 *s)
{
  kal_uint32 uResult = 0;

  while (*s != '\0'){
    uResult++;
    s++;
  }

  return uResult;
}

static kal_bool parseStreamMuxConfigStr( AudRTP_DL_HANDLE *hdl )
{
   aacRTPHdl* ihdl = (aacRTPHdl *) hdl;
   kal_uint8 const *pConfigStr = ihdl->sAudHdl.stCodecCap.aac.config;
   // Set default versions of the result parameters:
   ihdl->audioMuxVersion = 0;
   ihdl->allStreamsSameTimeFraming = 1;
   ihdl->numSubFrames = ihdl->numProgram = ihdl->numLayer = 0;
   ihdl->audioSpecificConfigSize = 0;

   do {
     kal_uint8 nextByte, remainingBit;
     kal_uint32 ascSize, i;
     kal_bool parseSuccess;
     if ( pConfigStr == NULL) break;

     if (!getByte(&pConfigStr, &nextByte)) break;
     ihdl->audioMuxVersion = (nextByte&0x80)>>7;
     if (ihdl->audioMuxVersion != 0) break;

     ihdl->allStreamsSameTimeFraming = (nextByte&0x40)>>6;
     ihdl->numSubFrames = (nextByte&0x3F);

     if (!getByte(&pConfigStr, &nextByte)) break;
     ihdl->numProgram = (nextByte&0xF0)>>4;

     ihdl->numLayer = (nextByte&0x0E)>>1;

     // The one remaining bit, and the rest of the string,
     // are used for "audioSpecificConfig":
     remainingBit = nextByte&1;

     ascSize = (_strlen(pConfigStr)+1)/2 + 1;

     i = 0;
     do {
       nextByte = 0;
       parseSuccess = getByte(&pConfigStr, &nextByte);
       ihdl->audioSpecificConfig[i++] = (remainingBit<<7)|((nextByte&0xFE)>>1);
       remainingBit = nextByte&1;
     } while (parseSuccess);
     if (i != ascSize) break; // part of the remaining string was bad
     ASSERT(i<MAX_SPEC_CONFIG_NUM);
     ihdl->audioSpecificConfigSize = ascSize;
     return true; // parsing succeeded
   } while (0);

   return false; // parsing failed
}

static void AudRTP_InitADTSHeader(AudRTP_DL_HANDLE *hdl)
{
   aacRTPHdl* ihdl = (aacRTPHdl *)hdl;
   kal_uint8 *pADTS_Header;
   kal_uint32 uBitCnt = 0;

   pADTS_Header = &ihdl->ADTS_Header[0];

   AudRTP_putbits(pADTS_Header, &uBitCnt, 0xFFF, 12); // syncword
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 1);      // ID
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 2);      // Layer
   AudRTP_putbits(pADTS_Header, &uBitCnt, 1, 1);      // Protection absent
   AudRTP_putbits(pADTS_Header, &uBitCnt, 1, 2);      // Profile
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 4);      // Reserve sample_frequency_index
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 1);      // private_bit
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 3);      // Reserve Channel_configuration
   AudRTP_putbits(pADTS_Header, &uBitCnt, 1, 1);      // original_copy
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 1);      // Home

   /* adts_variable_header */
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 1);      // copy_identification_bit
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 1);      // copy_identification_byte
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 13);     // Reserve length
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0x7FF, 11); // buffer_fullness
   AudRTP_putbits(pADTS_Header, &uBitCnt, 0, 2);      // no_raw_data_blocks_in_frame
}

static void AudRTP_UpdateADTSHeader(AudRTP_DL_HANDLE *hdl, kal_uint32 uFrameLen)
{
   uint8 *pADTS_Header;
   kal_uint32 uBitCnt;
   aacRTPHdl* ihdl = (aacRTPHdl *) hdl;

   pADTS_Header = &ihdl->ADTS_Header[0];
   uBitCnt = 18;

   AudRTP_putbits(pADTS_Header, &uBitCnt, ihdl->bFreqIdx, 4); // sample_frequency_index
   uBitCnt += 1;
   AudRTP_putbits(pADTS_Header, &uBitCnt, hdl->stCodecCap.aac.channel, 3); // Channel_configuration
   uBitCnt += 4;
   AudRTP_putbits(pADTS_Header, &uBitCnt, uFrameLen, 13); // length

}

static void aacPutNByte( AudRTP_DL_HANDLE *hdl, kal_uint8* pbBuf, kal_uint32 uLen )
{
   kal_uint8 *buffer;
   kal_uint32 buf_len;

   hdl->psMHdl->GetWriteBuffer( hdl->psMHdl, &buffer, &buf_len );
   if(uLen > buf_len){
      uLen -= buf_len;
      memcpy( buffer, pbBuf, buf_len);
      hdl->psMHdl->WriteDataDone(hdl->psMHdl, buf_len);
      pbBuf += buf_len;
   }
   if(uLen > 0){
      hdl->psMHdl->GetWriteBuffer( hdl->psMHdl, &buffer, &buf_len );
      memcpy( buffer, pbBuf, uLen);
      hdl->psMHdl->WriteDataDone(hdl->psMHdl, uLen);
   }
}

static AudRTP_STATUS AudRTP_AAC_GetCodecCapability(AudRTP_DL_HANDLE *hdl,
                                                   rtp_audio_codec_type codec_type,
                                                   rtp_audio_codec_cap *codec_cap )
{
   (void)hdl;

   if(codec_type ==  RTP_AUDIO_BSAC)
      return AudRTP_STATUS_SUCCESS; // Dummy function for BSAC codec

   ASSERT(codec_type == RTP_AUDIO_MP4A_LATM_AAC || codec_type ==  RTP_AUDIO_MPEG4_GENERIC_AAC);
   memset(codec_cap, 0, sizeof(rtp_audio_codec_cap));
   codec_cap->aac.object             = 2;  // LC AAC
   codec_cap->aac.channel            = 2;
   codec_cap->aac.streamType         = 5;  // MPEG-4 Audio streams
   codec_cap->aac.mode               = AAC_HBR;

   return AudRTP_STATUS_SUCCESS;
}

#define HexMapL 16

typedef struct
{
  kal_char chr;
  kal_uint8 value;
}CHexMap;

static const CHexMap HexMap[HexMapL] =
{
  {'0', 0}, {'1', 1},
  {'2', 2}, {'3', 3},
  {'4', 4}, {'5', 5},
  {'6', 6}, {'7', 7},
  {'8', 8}, {'9', 9},
  {'A', 10}, {'B', 11},
  {'C', 12}, {'D', 13},
  {'E', 14}, {'F', 15}
};

static kal_uint32 _httoi(const kal_uint8 *s)
{
  kal_uint32 uCnt, uResult = 0, uCnt1 = 0;
  kal_bool firsttime = true;

  while ((*s != '\0') && (uCnt1 < 4))
  {
    kal_bool found = false;
    for (uCnt = 0; uCnt < HexMapL; uCnt++)
    {
      if (*s == HexMap[uCnt].chr)
      {
        if (!firsttime) uResult <<= 4;
        uResult |= HexMap[uCnt].value;
        found = true;
        break;
      }
    }
    ASSERT(found);
    uCnt1++;
    s++;
    firsttime = false;
  }

  return uResult;
}

static AudRTP_STATUS AudRTP_AAC_Config(AudRTP_DL_HANDLE *hdl,
                                   rtp_audio_codec_type codec_type,
                                   rtp_audio_codec_cap *codec_cap,
                                   AudRTP_DL_CALLBACK callback,
                                   void *host_data, kal_uint32 session_id )
{
   aacRTPHdl* ihdl = (aacRTPHdl *) hdl;
   ASSERT((codec_type == RTP_AUDIO_MP4A_LATM_AAC) || (codec_type ==  RTP_AUDIO_MPEG4_GENERIC_AAC) || (codec_type ==  RTP_AUDIO_BSAC));
   ASSERT( hdl->uState == RTP_AAC_STATE_DL_INIT );

   hdl->callback = callback;
   hdl->host_data = (kal_uint32)host_data;
   hdl->session_id = session_id;
   memcpy( &hdl->stCodecCap, codec_cap, sizeof(rtp_audio_codec_cap));
   hdl->eAudCodecType = codec_type;

   hdl->uState = RTP_AAC_STATE_DL_CONFIGURED;

   if(codec_type ==  RTP_AUDIO_MP4A_LATM_AAC){
      if( !parseStreamMuxConfigStr( hdl ) )
          return AudRTP_STATUS_FAIL;
      hdl->stCodecCap.aac.config = &ihdl->audioSpecificConfig[0];
      if(hdl->stCodecCap.aac.cpresent || ((hdl->stCodecCap.aac.object != 2)&&(hdl->stCodecCap.aac.object != 5)))
         return AudRTP_STATUS_TYPE_NOT_SUPPORT;

      {
         ihdl->config = ihdl->audioSpecificConfig[0];
         ihdl->config <<= 8;
         ihdl->config |= ihdl->audioSpecificConfig[1];
      }
   }else{
      ihdl->config = _httoi(hdl->stCodecCap.aac.config);
    }

   {
      kal_uint32 i;
      ASSERT(ihdl->config != 0);
      i = (ihdl->config >> 7)& 0x0F;
      ASSERT(i<=12); // invalid index
      hdl->stCodecCap.aac.sample_rate = samplingFrequencyFromIndex[i];
      ihdl->bFreqIdx = i;
      ihdl->uFrameDur = 1024000/hdl->stCodecCap.aac.sample_rate;
      if((hdl->stCodecCap.aac.sample_rate > 48000) || (hdl->stCodecCap.aac.sample_rate < 8000))
         return AudRTP_STATUS_SAMPLE_RATE_NOT_SUPPORT;
   }

   if(codec_cap->aac.channel > 2)
      return AudRTP_STATUS_UNSUPPORT_CHANNEL_NUM;

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_CONFIG, hdl->stCodecCap.aac.sample_rate, ihdl->uFrameDur, codec_cap->aac.channel);
   return AudRTP_STATUS_SUCCESS;
}

static kal_uint32 AudRTP_AAC_GetSamplingFreq( AudRTP_DL_HANDLE *hdl )
{
   return hdl->stCodecCap.aac.sample_rate;
}

static kal_uint8 AudRTP_AAC_GetChannelNum( AudRTP_DL_HANDLE *hdl )
{
   return hdl->stCodecCap.aac.channel;
}

static void AudRTP_AAC_SetVolumeLevel( AudRTP_DL_HANDLE *hdl, kal_uint8 level )
{
   ASSERT( level <= 100 );
   AFE_SetDigitalGain( L1SP_AUDIO, level );
   AFE_SetDigitalGain( L1SP_VOICE, level );
}

static kal_uint32 AudRTP_AAC_GetBufferSize(AudRTP_DL_HANDLE *hdl )
{
   aacRTPHdl* ihdl = (aacRTPHdl *) hdl;
   ASSERT(maxByterateFromIndex[ihdl->bFreqIdx] != 0);
   ihdl->fCurrentPacketBeginsFrame = 1;
   ihdl->fCurrentPacketCompletesFrame = 1;
   return (maxByterateFromIndex[ihdl->bFreqIdx]*MAX_BUF_DUR); // 12 sec
}

static AudRTP_STATUS AudRTP_AAC_SetBuffer(AudRTP_DL_HANDLE *hdl, kal_uint8 *buffer, kal_uint32 buffer_size )
{
   ASSERT( hdl->uState == RTP_AAC_STATE_DL_CONFIGURED );
   hdl->uState = RTP_AAC_STATE_DL_READY;
   ASSERT(((uint32)buffer & 3) == 0 );       /* make sure 4-byte alignment */
   ASSERT( (buffer_size & 1) == 0 );         /* insure 2-byte alignment */
   hdl->psMHdl->SetBuffer( hdl->psMHdl, buffer, buffer_size );
   AudRTP_InitADTSHeader(hdl);

   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AAC_Close(AudRTP_DL_HANDLE *hdl )
{
   ASSERT( hdl->uState != RTP_AAC_STATE_DL_DECODE );

   hdl->psMHdl->Close(hdl->psMHdl);
   psAudRTPaac = (AudRTP_DL_HANDLE  *)0;
   free_ctrl_buffer( hdl );

   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AAC_Start(AudRTP_DL_HANDLE *hdl, kal_uint32 start_time )
{
   Media_Status res;
   aacRTPHdl* ihdl = (aacRTPHdl *) hdl;
   aacMediaHdl* aacHdl = (aacMediaHdl *)hdl->psMHdl;
   ASSERT( hdl->uState == RTP_AAC_STATE_DL_READY );

   if(hdl->psMHdl->write == 6) // buffer underflow
      return AudRTP_STATUS_FAIL;
#if defined(BSAC_DECODE)
   aacHdl->uNumOfSubFrame = hdl->stCodecCap.aac.uNumOfSubFrame; // BSAC
   aacHdl->uLayerLength = hdl->stCodecCap.aac.uLayerLength; // BSAC
#endif // #if defined(BSAC_DECODE)
   hdl->psMHdl->start_time = start_time;
   res = hdl->psMHdl->Play(hdl->psMHdl);
   if(res != MEDIA_SUCCESS) // Play fail
      return AudRTP_STATUS_FAIL;
   ihdl->current_time = start_time;
   hdl->psMHdl->current_time = start_time;
   hdl->uPacketLossCnt = 0;
   hdl->uState = RTP_AAC_STATE_DL_DECODE;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AAC_Stop(AudRTP_DL_HANDLE *hdl )
{
   aacRTPHdl* ihdl = (aacRTPHdl *) hdl;
   ASSERT( hdl->uState == RTP_AAC_STATE_DL_DECODE );
   hdl->psMHdl->Stop(hdl->psMHdl);
   hdl->psMHdl->write = 0;   // Reset Media Buffer
   hdl->psMHdl->read = 0;
   hdl->psMHdl->eof = false;
   hdl->psMHdl->waiting = false;
   hdl->uTotalFrameInBuf = 0;
   hdl->uPrePacketNum = 0;
   hdl->uPreTimeStamp = 0;
   ihdl->fCurrentPacketBeginsFrame = 1;
   ihdl->fCurrentPacketCompletesFrame = 1;

   hdl->uState = RTP_AAC_STATE_DL_READY;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AAC_GetPlayTime(AudRTP_DL_HANDLE *hdl, kal_uint32 *p_current_time)
{
   *p_current_time = hdl->psMHdl->current_time;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AAC_GetBufferStatus(AudRTP_DL_HANDLE *psRTPHdl, kal_uint32 *puCurBufDur,
               kal_uint32 *puBufFreeSize, kal_uint32 *puBufTotalSize, kal_uint32 *puMinBufTotalDur)
{
   aacRTPHdl* ihdl = (aacRTPHdl *) psRTPHdl;
   *puCurBufDur = psRTPHdl->uTotalFrameInBuf * ihdl->uFrameDur; // in ms
   // *puCurBufDur = psRTPHdl->uTotalFrameInBuf * ihdl->uFrameDur / 1000000;
   *puBufTotalSize = psRTPHdl->psMHdl->rb_size - 1;
   *puBufFreeSize = psRTPHdl->psMHdl->GetFreeSpace(psRTPHdl->psMHdl);
   *puMinBufTotalDur = MAX_BUF_DUR * 1000;

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_BUF_STATUS, *puCurBufDur, *puBufTotalSize, *puBufFreeSize, *puMinBufTotalDur );
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AAC_PutPacket(AudRTP_DL_HANDLE *hdl, kal_uint8 *buf, kal_uint32 buffer_size)
{
   uint8 *pbAU_Header;
   uint8 *pADTS_Header;
   uint32 AU_headers_length, AU_headers_length_bytes, uAU_size, uAU_index;
   kal_uint32 uPacketNum, uTimeStamp;
   kal_uint32 fNumAUHeaders, fNextAUHeader, resultSpecialHeaderSize;
   aacRTPHdl* ihdl = (aacRTPHdl *) hdl;
   kal_uint32 uBitCnt_Get = 0;

   pADTS_Header = &ihdl->ADTS_Header[0];
   uPacketNum = AudRTP_getPacketNum( buf, buffer_size );
   uTimeStamp = AudRTP_getTimeStamp( buf, buffer_size );
   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PUTPKT_FUNC, uPacketNum, uTimeStamp, buffer_size, MEDIA_FORMAT_AAC );

   if(hdl->uPrePacketNum == 0){
      hdl->uPrePacketNum = uPacketNum-1;
   }

   hdl->uPrePacketNum = uPacketNum;
   hdl->uPreTimeStamp = uTimeStamp;

   if( hdl->psMHdl->GetFreeSpace(hdl->psMHdl) < buffer_size ){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_OF, 1, MEDIA_FORMAT_AAC);
      mhdlException( hdl->psMHdl, (Media_Event)AudRTP_EVENT_BUF_OVERFLOW );
      return AudRTP_STATUS_FAIL;            /* buffer overflow */
   }

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PUT_PKT, uPacketNum, uTimeStamp, MEDIA_FORMAT_AAC);

   if(hdl->eAudCodecType ==  RTP_AUDIO_MP4A_LATM_AAC){
      kal_uint32 uFrameCnt, uFrameSize;
      kal_uint8 bTmp;
      buffer_size-=12;
      ASSERT(hdl->stCodecCap.aac.cpresent == 0);

      ihdl->fCurrentPacketBeginsFrame = ihdl->fCurrentPacketCompletesFrame;
              // whether the *previous* packet ended a frame

      // The RTP "M" (marker) bit indicates the last fragment of a frame:
      buf += 1;
      ihdl->fCurrentPacketCompletesFrame = ((*buf)>> 7)  & 0x01;
      buf += 11; // skip RTP header
         
      if(!ihdl->fCurrentPacketBeginsFrame){
         aacPutNByte( hdl, buf, buffer_size );
         ASSERT(ihdl->fCurrentPacketBeginsFrame <= 1);
      }else{
         kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_FRM_IN_PKT, ihdl->numSubFrames, MEDIA_FORMAT_AAC);
         for(uFrameCnt=0; uFrameCnt<=ihdl->numSubFrames; uFrameCnt++){
            uFrameSize = 0;
            do{
               bTmp = *buf++;
               uFrameSize += bTmp;
               buffer_size--;
            }while( bTmp == 0xFF );
            if(buffer_size < uFrameSize)
               uFrameSize = buffer_size;
            AudRTP_UpdateADTSHeader( hdl, uFrameSize + ADTS_HEADER_SIZE );
            aacPutNByte( hdl, pADTS_Header, ADTS_HEADER_SIZE );
            aacPutNByte( hdl, buf, uFrameSize );
            hdl->uTotalFrameInBuf++;
            buf += uFrameSize;
            buffer_size -= uFrameSize;
         }
         //ASSERT(buffer_size == 0);
      }

   }else{

      {
         ihdl->fCurrentPacketBeginsFrame = ihdl->fCurrentPacketCompletesFrame;
                 // whether the *previous* packet ended a frame

         // The RTP "M" (marker) bit indicates the last fragment of a frame:
         buf += 1;
         ihdl->fCurrentPacketCompletesFrame = ((*buf)>> 7)  & 0x01;
         buf += 11; // skip RTP header

         resultSpecialHeaderSize = 0;

         // default values:
         fNumAUHeaders = 0;
         fNextAUHeader = 0;

         if (hdl->stCodecCap.aac.uSizeLength > 0) {
           int32 bitsAvail;
           AU_headers_length = ((kal_uint32)buf[0]<<8)|(kal_uint32)buf[1];
           AU_headers_length_bytes = (AU_headers_length+7)/8;

           // The packet begins with a "AU Header Section".  Parse it, to
           // determine the "AU-header"s for each frame present in this packet:
           resultSpecialHeaderSize += 2;

           if (buffer_size < resultSpecialHeaderSize + AU_headers_length_bytes)
              return AudRTP_STATUS_FAIL;

           resultSpecialHeaderSize += AU_headers_length_bytes;

           // Figure out how many AU-headers are present in the packet:
           bitsAvail = AU_headers_length - (hdl->stCodecCap.aac.uSizeLength + hdl->stCodecCap.aac.uIndexLength);
           if (bitsAvail >= 0 && (hdl->stCodecCap.aac.uSizeLength + hdl->stCodecCap.aac.uIndexDeltaLength) > 0) {
             fNumAUHeaders = 1 + bitsAvail/(hdl->stCodecCap.aac.uSizeLength + hdl->stCodecCap.aac.uIndexDeltaLength);
           }
           if(bitsAvail%(hdl->stCodecCap.aac.uSizeLength + hdl->stCodecCap.aac.uIndexDeltaLength)){  // discard invalid packet
               kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_DISCAR, uPacketNum, MEDIA_FORMAT_AAC);
               hdl->uPacketLossCnt++;

               if( hdl->uPacketLossCnt > MAX_PACKET_LOSS  ){
                   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PKT_LOSS, (uPacketNum - hdl->uPrePacketNum), MEDIA_FORMAT_AAC );
                   mhdlException( hdl->psMHdl, (Media_Event)AudRTP_EVENT_PACKET_LOSS );
                   return AudRTP_STATUS_FAIL;
               }
               return AudRTP_STATUS_SUCCESS;            
           }
         }
      }

      pbAU_Header = buf+2;
      buf+=resultSpecialHeaderSize;
      buffer_size-=(12+resultSpecialHeaderSize);
      uAU_size = 0;
      uAU_index = 0;
      {
         kal_uint32 tmp = 0;
         kal_uint32 uSizeLength = hdl->stCodecCap.aac.uSizeLength;
         ASSERT(uSizeLength<=16);

         if(uSizeLength>8){
            uSizeLength -= 8;
            tmp = (kal_uint32)AudRTP_getbits(pbAU_Header, &uBitCnt_Get, 8);
         }
         ASSERT(uSizeLength != 0);
         uAU_size = AudRTP_getbits(pbAU_Header, &uBitCnt_Get, uSizeLength);
         uAU_size |= tmp<<uSizeLength;
      }
      ASSERT(hdl->stCodecCap.aac.uIndexLength != 0);
      uAU_index = (kal_uint32)AudRTP_getbits(pbAU_Header, &uBitCnt_Get, hdl->stCodecCap.aac.uIndexLength);
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_FRM_IN_PKT, fNumAUHeaders, MEDIA_FORMAT_AAC);
      while( fNumAUHeaders > 0 ) {
         fNumAUHeaders--;
         hdl->uTotalFrameInBuf++;
         AudRTP_UpdateADTSHeader( hdl, uAU_size + ADTS_HEADER_SIZE );
         aacPutNByte( hdl, pADTS_Header, ADTS_HEADER_SIZE );
         aacPutNByte( hdl, buf, uAU_size );
         buf += uAU_size;
         buffer_size -= uAU_size;
         ASSERT( buffer_size > 0 || (buffer_size==0&&fNumAUHeaders==0) );

         if(fNumAUHeaders > 0){
            kal_uint32 tmp = 0;
            {
               kal_uint32 uSizeLength = hdl->stCodecCap.aac.uSizeLength;
               ASSERT(uSizeLength<=16);

               if(uSizeLength>8){
                  uSizeLength -= 8;
                  tmp = (kal_uint32)AudRTP_getbits(pbAU_Header, &uBitCnt_Get, 8);
               }
               ASSERT(uSizeLength != 0);
               uAU_size = AudRTP_getbits(pbAU_Header, &uBitCnt_Get, uSizeLength);
               uAU_size |= tmp<<uSizeLength;
            }

            uAU_index = (kal_uint32)AudRTP_getbits(pbAU_Header,
                     &uBitCnt_Get, hdl->stCodecCap.aac.uIndexDeltaLength);
         }
      }
   }
   return AudRTP_STATUS_SUCCESS;
}

#if defined(__TDMB_SUPPORT__)

static AudRTP_STATUS   AudRTP_AAC_AddAccessUnit(AudRTP_DL_HANDLE *hdl, kal_uint8* buf, kal_uint32 buffer_size, kal_uint32 timestamp)
{
   aacRTPHdl* ihdl = (aacRTPHdl *) hdl;

   if( hdl->psMHdl->GetFreeSpace(hdl->psMHdl) < buffer_size ){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_OF, 1, MEDIA_FORMAT_AAC);
      mhdlException( hdl->psMHdl, (Media_Event)AudRTP_EVENT_BUF_OVERFLOW );
      return AudRTP_STATUS_FAIL;            /* buffer overflow */
   }

   aacPutNByte( hdl, buf, buffer_size );

   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AAC_RTP_Parser(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer,
                                      kal_uint32 buffer_size, kal_uint8 *au,
                                      kal_uint32 au_size, kal_uint32 *timestamp)
{
   // not implement yet
}
#endif // #if defined(__TDMB_SUPPORT__)
// must be sure aac_Handler would be invoked every D2M INT
static void aac_Handler( MHdl *handle, Media_Event event )
{
   aacRTPHdl* ihdl = (aacRTPHdl *) psAudRTPaac;
   ASSERT(psAudRTPaac != 0);
   (void)event;   /* do nothing */
   (void)handle;

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_FRM_IN_BUF, psAudRTPaac->uTotalFrameInBuf, MEDIA_FORMAT_AAC);
   //ASSERT(event != MEDIA_ERROR);

   if(event == MEDIA_ERROR){
      psAudRTPaac->callback(AudRTP_EVENT_MEDIA_ERROR, psAudRTPaac, (void  *)psAudRTPaac->host_data);
      return;
   }

   if((AudRTP_EVENT)event == AudRTP_EVENT_BUF_OVERFLOW){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_OF, 0, MEDIA_FORMAT_AAC);
      psAudRTPaac->callback(AudRTP_EVENT_BUF_OVERFLOW, psAudRTPaac, (void  *)psAudRTPaac->host_data);
      return;
   }else if((AudRTP_EVENT)event == AudRTP_EVENT_PACKET_LOSS){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PKT_LOSS, MAX_PACKET_LOSS, MEDIA_FORMAT_AAC);
      psAudRTPaac->callback(AudRTP_EVENT_PACKET_LOSS, psAudRTPaac, (void  *)psAudRTPaac->host_data);
      return;
    }

   if(handle->current_time > ihdl->current_time){
      kal_uint32 uFrameCnt;
      uFrameCnt = handle->current_time - ihdl->current_time;
      ASSERT(0 != ihdl->uFrameDur);
      uFrameCnt /= ihdl->uFrameDur;
      if(psAudRTPaac->uTotalFrameInBuf > uFrameCnt)
         psAudRTPaac->uTotalFrameInBuf -= uFrameCnt;
      if( psAudRTPaac->psMHdl->GetDataCount(psAudRTPaac->psMHdl) <= 1 ){
         kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_UF, 0, MEDIA_FORMAT_AAC);
         psAudRTPaac->callback(AudRTP_EVENT_BUF_UNDERFLOW, psAudRTPaac, (void  *)psAudRTPaac->host_data);
      }
      ihdl->current_time = handle->current_time;
   }
   psAudRTPaac->psMHdl->waiting = false;
}

AudRTP_DL_HANDLE *RTPAAC_OpenDLChannel( void )
{
   AudRTP_DL_HANDLE* aacRTP = (AudRTP_DL_HANDLE *)get_ctrl_buffer( sizeof(aacRTPHdl) );
   ASSERT(aacRTP != 0);

   memset(aacRTP, 0, sizeof(aacRTPHdl));

   aacRTP->psMHdl = AAC_Open( aac_Handler,(STFSAL *)0, (void *)0);
   aacRTP->GetCodecCapability = AudRTP_AAC_GetCodecCapability;
   aacRTP->Config = AudRTP_AAC_Config;
   aacRTP->GetSamplingFreq = AudRTP_AAC_GetSamplingFreq;
   aacRTP->GetChannelNum = AudRTP_AAC_GetChannelNum;
   aacRTP->GetBufferSize = AudRTP_AAC_GetBufferSize;
   aacRTP->SetBuffer = AudRTP_AAC_SetBuffer;
   aacRTP->Close = AudRTP_AAC_Close;
   aacRTP->Start = AudRTP_AAC_Start;
   aacRTP->Stop = AudRTP_AAC_Stop;
   aacRTP->PutPacket = AudRTP_AAC_PutPacket;
#if defined(__TDMB_SUPPORT__)
   aacRTP->AddAccessUnit = AudRTP_AAC_AddAccessUnit;
   aacRTP->RTP_Parser = AudRTP_AAC_RTP_Parser;
#endif // #if defined(__TDMB_SUPPORT__)
   aacRTP->GetPlayTime = AudRTP_AAC_GetPlayTime;
   aacRTP->SetVolumeLevel = AudRTP_AAC_SetVolumeLevel;
   aacRTP->GetBufferStatus = AudRTP_AAC_GetBufferStatus;
   aacRTP->uState = RTP_AAC_STATE_DL_INIT;

   psAudRTPaac = aacRTP;
   return aacRTP;
}

#if defined(BSAC_DECODE)
AudRTP_DL_HANDLE *RTPBSAC_OpenDLChannel( void )
{
   AudRTP_DL_HANDLE* aacRTP = (AudRTP_DL_HANDLE *)get_ctrl_buffer( sizeof(aacRTPHdl) );
   ASSERT(aacRTP != 0);

   memset(aacRTP, 0, sizeof(aacRTPHdl));

   aacRTP->psMHdl = BSAC_Open( aac_Handler,(STFSAL *)0, (void *)0);
   aacRTP->GetCodecCapability = AudRTP_AAC_GetCodecCapability;
   aacRTP->Config = AudRTP_AAC_Config;
   aacRTP->GetSamplingFreq = AudRTP_AAC_GetSamplingFreq;
   aacRTP->GetChannelNum = AudRTP_AAC_GetChannelNum;
   aacRTP->GetBufferSize = AudRTP_AAC_GetBufferSize;
   aacRTP->SetBuffer = AudRTP_AAC_SetBuffer;
   aacRTP->Close = AudRTP_AAC_Close;
   aacRTP->Start = AudRTP_AAC_Start;
   aacRTP->Stop = AudRTP_AAC_Stop;
   aacRTP->PutPacket = AudRTP_AAC_PutPacket;
#if defined(__TDMB_SUPPORT__)
   aacRTP->AddAccessUnit = AudRTP_AAC_AddAccessUnit;
   aacRTP->RTP_Parser = AudRTP_AAC_RTP_Parser;
#endif // #if defined(__TDMB_SUPPORT__)
   aacRTP->GetPlayTime = AudRTP_AAC_GetPlayTime;
   aacRTP->SetVolumeLevel = AudRTP_AAC_SetVolumeLevel;
   aacRTP->GetBufferStatus = AudRTP_AAC_GetBufferStatus;
   aacRTP->uState = RTP_AAC_STATE_DL_INIT;

   psAudRTPaac = aacRTP;
   return aacRTP;
}
#endif // #if defined(BSAC_DECODE)

#if defined (AUD_RTP_UNIT_TEST)
/* Example code for doing Unit Test */

static uint8 test_media_buffer[40960];

void test_callback( AudRTP_EVENT event, AudRTP_DL_HANDLE *hdl, void *host_data )
{
   return;
}

static rtp_audio_codec_cap sCodecCap;
static uint32 uCnt=0;

void KT_Play( uint16 freq1, uint16 freq2, uint16 duration )
{
   AudRTP_DL_HANDLE *psDLhdl;
   int I;

   if(!(uCnt&0x01)){
      memset(&sCodecCap, 0, sizeof(sCodecCap));
      if( duration != 0 ) {

         psDLhdl = RTPAAC_OpenDLChannel();

         psDLhdl->GetCodecCapability( psDLhdl, RTP_AUDIO_MPEG4_GENERIC_AAC, &sCodecCap );

   // SDP initialization
         sCodecCap.aac.mode = AAC_HBR;
         sCodecCap.aac.config = "1210";
         sCodecCap.aac.channel = 2;
         sCodecCap.aac.uSizeLength = 13;
         sCodecCap.aac.uIndexLength = 3;
         sCodecCap.aac.uIndexDeltaLength = 3;
         sCodecCap.aac.sample_rate = 44100;

         psDLhdl->Config( psDLhdl, RTP_AUDIO_MPEG4_GENERIC_AAC, &sCodecCap, test_callback, 0, 0 );
         psDLhdl->SetBuffer(psDLhdl, test_media_buffer, sizeof( test_media_buffer));

         for( I = 0; I < 5; I++ ) {
            psDLhdl->PutPacket( psDLhdl, packet_buffer, packet_size[0]);
   //         kal_prompt_trace( MOD_L1SP, "PutPacket %d, packet size=%d\n", I, packet_size[0] );
            kal_sleep_task(2);
         }

         psDLhdl->Start(psDLhdl , 0);
   //      kal_prompt_trace( MOD_L1SP, "AAC RTP downlink Start\n" );

         for( I = 5; I < 30; I++ ) {
            psDLhdl->PutPacket( psDLhdl, packet_buffer, packet_size[0]);
   //         kal_prompt_trace( MOD_L1SP, "PutPacket %d, packet size=%d\n", I, packet_size[0] );
            kal_sleep_task(2);
         }

         psDLhdl->psMHdl->DataFinished(psDLhdl->psMHdl);
   //      kal_prompt_trace( MOD_L1SP, "AAC RTP downlink Stop\n" );
      }
   }else{
       ASSERT(psAudRTPaac != 0);
       psAudRTPaac->Stop(psAudRTPaac );
       psAudRTPaac->Close( psAudRTPaac );
    }
   uCnt++;
}
#endif // #if defined (AUD_RTP_UNIT_TEST)

#endif // #if  defined(STREAM_SUPPORT)