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
 *   aac_drv.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  AAC Decoder (including SBR decoding) Driver
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
 *============================================================================
 ****************************************************************************/
#include "media.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "aud_daf_parser.h"

#define AAC_CTRL_Flexible   0x1
#define AAC_PLUS_ON         0x4
#define AAC_PLUS_INIT       0x13
#define FLEXI_VBI_ON        0x1
#define FLEXI_SD_ON         0x4


#define AAC_STATE_PLAY   1
#define AAC_STATE_PAUSE  2
#define AAC_STATE_IDLE   3

#define DSP_AAC_STATE_IDLE     0
#define DSP_AAC_STATE_START    6
#define DSP_AAC_STATE_PLAYING  2
#define DSP_AAC_STATE_STOP    10
#define DSP_AAC_STATE_END     14


#define DSP_AAC_PS_STATE_IDLE          0
#define DSP_AAC_PS_STATE_START      0x16
#define DSP_AAC_PS_STATE_PLAYING  0x12
#define DSP_AAC_PS_STATE_STOP        0x1A
#define DSP_AAC_PS_STATE_END          0x1E

#define  AAC_MAX_OUT_LEN 2178
#define  AAC_OUT_BUF_SIZE  16384

#define AAC_MAX_DATA_REQUESTED  1024

#define MAX_FRAME_CHECK_LEN   (20*1024)
#define MIN_DATA_LEN          256
#define ADTS_MAX_SIZE         6 /* Should be enough */
#define SAMPLES_PER_FRAME     1024

#define PS_MODE	        1
#define SBR_MODE	        0
#define DETECT_ERROR	     -1


#define AAC_PAGE_NUM  2

#define MAX_CACHE_ENTRIES 254
typedef struct {
   kal_uint16 frames_per_cache;
   kal_uint16 valid_cache_number;
   kal_uint16 current_cache_index;
   kal_uint32 total_frame;
   kal_uint32 start_offset[MAX_CACHE_ENTRIES];
   kal_uint32 accumulated_frames[MAX_CACHE_ENTRIES];
} AudioCacheTable;

typedef struct aacVar{
   kal_bool     bError;
   kal_bool     bDecUnsupport;
   kal_bool     bIsTypeADTS;
   kal_bool     bIsTypeADIF;
   kal_bool     sbrPresentFlag;
   kal_bool     PSPresentFlag;
   kal_bool     sbrParseError;
   kal_bool     stereo;
   kal_uint32   rawDataBlockOffset;
   kal_uint32   bitRate;
   kal_uint8    bADTSFixedHeader[4];
   kal_uint8    bHeaderTmp[4];
   kal_uint8    sr_idx;
} aacInternal;

typedef struct mh_internal {
   MHdl     mh;
   aacInternal      aac;
   STFSAL           *pstFSAL;
   audInfoStruct    *description;
   kal_uint8        buf[AAC_MAX_DATA_REQUESTED];
   kal_bool         isStreaming;
   kal_bool         isM4AOpened;
   kal_uint32       fileOffset;
   kal_uint32       resumeFrameOffset;
   kal_uint32       uFileSize;
   kal_uint32       uID3V2Size;
   kal_uint32       uDurUpdateThd;
   Media_Event      end_status;
   AudioCacheTable  *AudioCacheTbl;
   kal_uint64       uCurFrame;
   kal_uint64       frameDur; // in ms * 10E-6

#if defined(BSAC_DECODE)
   kal_uint32       uNumOfSubFrame;     // BSAC
   kal_uint32       uLayerLength;  // BSAC
#endif // #if defined(BSAC_DECODE)

   // for M4A played back
   FS_FileLocationHint  *pst_vid_seek_hint_M4A;
   STMp4Parser *pstMp4Parser_M4A;
   STFSAL *pstFSALAudio_STSZ_M4A;
   STFSAL *pstFSALAudio_STCO_M4A;
   STFSAL *pstFSALAudio_M4A;
   kal_uint32 *pu_buffer_temp_a_M4A;
   kal_uint32 *pu_buffer_temp_stco_a_M4A;
   kal_uint32 *pu_buffer_temp_stsz_a_M4A;
   kal_uint32 *pu_buffer_STBL_cache_pool_M4A; /* STBL cache pool */
   kal_int32  AAC_DSP_Data_Cnt;
   kal_uint32 uEOF_TimeOutCnt;
   kal_uint16 AAC_DSP_Write_Idx;
   kal_uint16 wDspReadIdx;
   kal_bool   AAC_Decode_EOF;
#if defined AAC_PLUS_PS_DECODE
   kal_bool   fDecoderError;
   kal_bool   fEnableARMDecoder;
   kal_bool   fUseTCMFromAPM;
   MHdl       *pstMHdl;
   kal_uint16 aud_id_decoder; // ARM AAC decoder
#endif // #define AAC_PLUS_PS_DECODE
} aacMediaHdl;
