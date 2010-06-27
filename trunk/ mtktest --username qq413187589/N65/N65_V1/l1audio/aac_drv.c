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
 *   aac_drv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  AAC Decoder Driver (including SBR decoding, M4A decoding)
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
//#define AAC_DEBUG_ENABLE
//#define AAC_DEBUG_ICE_ENABLE
#if defined(AAC_DECODE)

#include "aac_drv.h"
#include "aac_huffman_table.h"
#include "l1sp_trc.h"
#include "med_utility.h"
#include "drm_gprot.h"

#ifdef AAC_PLUS_PS_DECODE

#include "aac_main.h"
#include "dcmgr.h"

extern kal_semid  WAVsema;

// Global Variable
void *rawDecoder = (void *)0;
AAC_IN_OUT_BUFFER AACBUFFER;
kal_uint8 *aacWorking_data = (kal_uint8 *)0;
kal_bool fDisableAACPS = false;

#endif // #ifdef AAC_PLUS_PS_DECODE

static const kal_int32 sampleRateTab[] =
{96000,88200,64000,48000,44100,32000,24000,22050,16000,12000,11025,8000};
static const kal_uint16 dspSRConfigTab[] =
{ASP_FS_48K, ASP_FS_44K, ASP_FS_32K, ASP_FS_24K, ASP_FS_22K, ASP_FS_16K, ASP_FS_12K, ASP_FS_11K, ASP_FS_8K};

static const kal_uint32 maxByterateFromIndex[12] = {
  0, 0, 0, 36000, 33076, 24000, 18000, 16538,
  16000, 12000, 9000, 6000
};
extern struct {
   kal_uint32 uCurOffset;
   kal_uint32 uResumeFrameOffset;
} audResumeInfo;

extern kal_uint32 SaveAndSetIRQMask( void );
extern void   RestoreIRQMask( uint32 );

//#if defined MP4_CODEC
#define VID_DEC_SEEK_HINT_SIZE 2047
void allocWorkingMemM4A(MHdl *hdl);
void freeWorkingMemM4A(MHdl *hdl);
//#endif // MP4_CODEC

#ifdef AAC_DEBUG_ENABLE
#define  AAC_CHECKSUM_MAX_SIZE  20480
kal_uint16 aacChecksumInfo[AAC_CHECKSUM_MAX_SIZE];
kal_uint32 aacCnt = 0xFFFFFFFF;
static kal_uint16 _file_name[128];
static uint32 _data_written;
static uint8  _dbg_str[128];
static FS_HANDLE  _file_handle = 0;
#endif // #ifdef AAC_DEBUG_ENABLE
#if defined(AAC_PLUS_DECODE)
kal_bool fDisableAACPlus = false;

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define CT_AAC_PLUS
#endif

#define DP_AAC_ROM_CTRL_ASP   32
#define DP_AAC_PLUS_CTRL_ASP   64
#define BITMASK(_cnt) (0xFFFFFFFF >> (32-_cnt))

static kal_uint32 aacPlusPeekBits(aacMediaHdl *ihdl, kal_uint32 puBitCnt, kal_uint32 uBaseOffset, kal_uint8 ubCnt)
{
	kal_uint32 uResult, uFileOffset, uCurPos;

#if defined(__PRODUCTION_RELEASE__)
   if(ubCnt >= 24){
      ihdl->aac.sbrParseError = true;
      return 0;
   }
#else
	ASSERT(ubCnt < 24);
#endif

	uFileOffset = uBaseOffset + (puBitCnt >> 3);
	FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);
	FSAL_Seek( ihdl->pstFSAL, uFileOffset);
	FSAL_Peek_UINT(ihdl->pstFSAL, &uResult);
	FSAL_Seek( ihdl->pstFSAL, uCurPos);
	return (uResult >> (32-(puBitCnt & 0x07) - ubCnt)) & BITMASK(ubCnt);
}

static void aacPlusProgramConfigElement(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint32 i;
   kal_uint8  num_front_channel_elements, num_side_channel_elements
            , num_back_channel_elements, num_lfe_channel_elements
            , num_assoc_data_elements, num_valid_cc_elements, dummy, comment_field_bytes;
         /*--- PCE ---*/

   /* element_instance_tag */
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   /* object type */
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 6);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_front_channel_elements, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_side_channel_elements, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_back_channel_elements, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_lfe_channel_elements, 2);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_assoc_data_elements, 3);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_valid_cc_elements, 4);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if (dummy == 1)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if (dummy == 1)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if (dummy == 1)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 3);

   for (i = 0; i < num_front_channel_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);

   for (i = 0; i < num_side_channel_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);

   for (i = 0; i < num_back_channel_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);

   for (i = 0; i < num_lfe_channel_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   for (i = 0; i < num_assoc_data_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   for (i = 0; i < num_valid_cc_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8-((*puBitCnt) & 0x07));

   FSAL_Read_Bytes( ihdl->pstFSAL, &comment_field_bytes, 1);
   FSAL_Skip_Bytes( ihdl->pstFSAL, comment_field_bytes);
   *puBitCnt += (comment_field_bytes+1) << 3;
}

static void aacPlusDataStreamElement(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8  byte_aligned, temp;
   kal_uint16 count;
   kal_int16 i;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &temp, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &byte_aligned, 1);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &temp, 8);
   count = (uint16)temp;

   if(count == 255){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &temp, 8);
      count += (uint16)temp;
   }

   if(byte_aligned)
      *puBitCnt += 8-(*puBitCnt & 0x07); // byte alignment

   for(i = count; --i >= 0;){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &temp, 8);
   }
}

/* Table 4.4.32 */
static kal_uint8 aacPlusExcludedChannels(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8  additional_excluded_chns, n = 0;
   do {
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &additional_excluded_chns, 7);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &additional_excluded_chns, 1);
#if defined(__PRODUCTION_RELEASE__)
      if(n == 255){
         ihdl->aac.sbrParseError = true;
         break;
      }
#else
	   ASSERT(n < 255);
#endif
      n++;
   } while (additional_excluded_chns == 1);
   return n;
}

/* Table 4.4.31 */
static kal_uint8 aacPlusDynamicRangeInfo(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8  i, dummy, band_incr;
   kal_uint8  n = 1, num_bands = 1;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if(dummy & 1){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8);
      n++;
   }

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if(dummy == 1){
      n += aacPlusExcludedChannels(ihdl, puBitCnt);
   }
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if(dummy & 1){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &band_incr, 4);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);
      n++;
      num_bands += band_incr;

      for (i = 0; i <num_bands; i++){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8);
         n++;
      }
   }
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if(dummy & 1){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8);
      n++;
   }

   for(i = 0; i < num_bands; i++){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8);
      n++;
   }
   return n;
}

/* Table 4.4.30 */
static kal_uint16 aacPlusExtensionPayload(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint16 count)
{
   kal_uint16 i, n, dataElementLength;
   kal_uint8  extension_type, data_element_version, loopCounter, dataElementLengthPart, dummy;
   kal_uint8  align = 4;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &extension_type, 4);

   switch(extension_type)
   {
      case EXT_SBR_DATA:
      case EXT_SBR_DATA_CRC:
          ihdl->aac.sbrPresentFlag = true;
#ifdef AAC_PLUS_PS_DECODE
          if( ihdl->aac.stereo != true){
            kal_uint8 *pBuf;
            kal_uint32 uBitCnt, uTmp, uCurPos, uMBufLen, uRes;

            uBitCnt = *puBitCnt;
            uBitCnt -= 4;
            uTmp = uBitCnt/8;
            uBitCnt %= 8;

            pBuf = (kal_uint8 *)get_ctrl_buffer( sizeof(kal_uint8)*2048 );

	         FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);
	         FSAL_Seek( ihdl->pstFSAL, (ihdl->fileOffset + ihdl->aac.rawDataBlockOffset));
	         uMBufLen = autGetBytes((MHdl *)ihdl, ihdl->pstFSAL, 2048, pBuf);
	         FSAL_Seek( ihdl->pstFSAL, uCurPos);
	         if((kal_int32)uMBufLen <= 0){
	            free_ctrl_buffer( pBuf );
	            return 0x7FFF;
	         }

	         uRes = checkPS( (char *)(pBuf+uTmp), sampleRateTab[ihdl->aac.sr_idx-3], uBitCnt);

	         if(PS_MODE == uRes)
               ihdl->aac.PSPresentFlag = true;

            free_ctrl_buffer( pBuf );
          }
#endif // #ifdef AAC_PLUS_PS_DECODE
          return 0x7FFF;
      case EXT_DYNAMIC_RANGE:
          n = aacPlusDynamicRangeInfo(ihdl, puBitCnt);
          return n;
      case EXT_FILL_DATA:
          /* fill_nibble = */
          FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);
          for(i = 0; i < count-1; i++){
             FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8);
          }
          return count;
      case EXT_DATA_ELEMENT:
          FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &data_element_version, 4);
          switch(data_element_version)
          {
             case ANC_DATA:
                 loopCounter = 0;
                 dataElementLength = 0;
                 do{
                    FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dataElementLengthPart, 8);
                    dataElementLength += dataElementLengthPart;
                    loopCounter++;
                 }while (dataElementLengthPart == 255);

                 for(i = 0; i < dataElementLength; i++){
                    /* data_element_byte[i] = */
                    FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8);
                 }
                 return (dataElementLength+loopCounter+1);
             default:
                 align = 0;
          }
      case EXT_FIL:
      default:
          FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, align);
          for(i = 0; i < count-1; i++){
              /* other_bits[i] = */
             FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8);
          }
          return count;
   }
}
/* Table 4.4.11 */
static void aacPlusFillElement(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8  tmp;
   kal_int16  count;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 4);
   count = (kal_int16)tmp;
   if(count == 15){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 8);
      count += (kal_int16)(tmp - 1);
   }

   while(count > 0) {
      count -= aacPlusExtensionPayload(ihdl, puBitCnt, count);
   }
}

#define bit_set(A, B) ((A) & (1<<(B)))

static void aacPlusWindowGroupingInfo(aacMediaHdl *ihdl, iCS *ics)
{
    kal_uint8 i, g;
    kal_uint8 sf_index = ihdl->aac.sr_idx;
    ics->num_windows=0;

    switch(ics->window_sequence){
       case ONLY_LONG_SEQUENCE:
       case LONG_START_SEQUENCE:
       case LONG_STOP_SEQUENCE:
           ics->num_windows = 1;
           ics->num_window_groups = 1;
           ics->window_group_length[ics->num_window_groups-1] = 1;
           ics->num_swb = num_swb_1024_window[sf_index];

           /* preparation of sect_sfb_offset for long blocks */
           /* also copy the last value! */

           for(i = 0; i < ics->num_swb; i++){
              ics->sect_sfb_offset[0][i] = swb_offset_1024_window[sf_index][i];
              ics->swb_offset[i] = swb_offset_1024_window[sf_index][i];
           }
           ics->sect_sfb_offset[0][ics->num_swb] = 1024;
           ics->swb_offset[ics->num_swb] = 1024;
           break;
       case EIGHT_SHORT_SEQUENCE:
           ics->num_windows = 8;
           ics->num_window_groups = 1;
           ics->window_group_length[ics->num_window_groups-1] = 1;
           ics->num_swb = num_swb_128_window[sf_index];

           for(i = 0; i < ics->num_swb; i++)
              ics->swb_offset[i] = swb_offset_128_window[sf_index][i];
           ics->swb_offset[ics->num_swb] = 128;

           for(i = 0; i < ics->num_windows-1; i++){
              if(bit_set(ics->scale_factor_grouping, 6-i) == 0){
                 ics->num_window_groups += 1;
                 ics->window_group_length[ics->num_window_groups-1] = 1;
              }else{
                  ics->window_group_length[ics->num_window_groups-1] += 1;
               }
           }

           /* preparation of sect_sfb_offset for short blocks */

           for(g = 0; g < ics->num_window_groups; g++){
              kal_uint16 width;
              kal_uint8  sect_sfb = 0;
              kal_uint16 offset = 0;

              for(i = 0; i < ics->num_swb; i++){
                  if(i+1 == ics->num_swb){
                     width = 128 - swb_offset_128_window[sf_index][i];
                  }else{
                      width = swb_offset_128_window[sf_index][i+1] -
                          swb_offset_128_window[sf_index][i];
                   }
                  width *= ics->window_group_length[g];
                  ics->sect_sfb_offset[g][sect_sfb++] = offset;
                  offset += width;
              }
              ics->sect_sfb_offset[g][sect_sfb] = offset;
           }
           break;
       default:
           ihdl->aac.sbrParseError = true;
    }
}

static void aacPlusIcsInfo(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 ics_reserved_bit;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics_reserved_bit, 1);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->window_sequence, 2);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->window_shape, 1);

   if(ics->window_sequence == EIGHT_SHORT_SEQUENCE){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->max_sfb, 4);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->scale_factor_grouping, 7);
   }else{
       FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->max_sfb, 6);
    }

   /* get the grouping information */
   aacPlusWindowGroupingInfo(ihdl, ics);

   if(ics->max_sfb > ics->num_swb){
      ihdl->aac.sbrParseError = true;
      return;
   }

   if(ics->window_sequence != EIGHT_SHORT_SEQUENCE){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->predictor_data_present, 1);
      if(ics->predictor_data_present){
         /* Not support */
         ihdl->aac.sbrParseError = true;
      }
   }
}

static void aacPlusSectionData(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 g, sect_esc_val, sect_bits;

   if(ics->window_sequence == EIGHT_SHORT_SEQUENCE)
      sect_bits = 3;
   else
      sect_bits = 5;
   sect_esc_val = (1<<sect_bits) - 1;

   for(g = 0; g < ics->num_window_groups; g++){
      kal_uint8 k = 0;
      kal_uint8 i = 0;

      while(k < ics->max_sfb){
         kal_uint8  sfb;
         kal_uint8  sect_len_incr;
         kal_uint16 sect_len = 0;
         kal_uint8  sect_cb_bits = 4;

         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->sect_cb[g][i], sect_cb_bits);

         if(ics->sect_cb[g][i] == NOISE_HCB)
            ics->noise_used = 1;
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &sect_len_incr, sect_bits);

         while(sect_len_incr == sect_esc_val){
            sect_len += sect_len_incr;
            FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &sect_len_incr, sect_bits);
         }

         sect_len += sect_len_incr;

         ics->sect_start[g][i] = k;
         ics->sect_end[g][i] = k + sect_len;

         if((k + sect_len >= 120) || (i >= 120)){ /* 8*15 */
            ihdl->aac.sbrParseError = true;
            break;
         }

         for(sfb = k; sfb < k + sect_len; sfb++)
            ics->sfb_cb[g][sfb] = ics->sect_cb[g][i];

         k += sect_len;
         i++;
      }
      ics->num_sec[g] = i;
   }
}

static kal_int8 aacPlusHuffmanScaleFactor(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint16 offset = 0;
   kal_uint8  b;
   while(hcb_sf[offset][1]){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &b, 1);
      offset += hcb_sf[offset][b];

      if(offset > 240){
         ihdl->aac.sbrParseError = true;
         break;
      }
   }
   return hcb_sf[offset][0];
}

static void aacPlusDecodeScaleFactors(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 g, sfb;
   kal_int16 t;
   kal_int8  noise_pcm_flag = 1;
   kal_int16 scale_factor = ics->global_gain;
   kal_int16 is_position = 0;
   kal_int16 noise_energy = ics->global_gain - 90;

   for(g = 0; g < ics->num_window_groups; g++){
      for(sfb = 0; sfb < ics->max_sfb; sfb++){
         switch (ics->sfb_cb[g][sfb])
         {
            case ZERO_HCB: /* zero book */
                ics->scale_factors[g][sfb] = 0;
                break;
            case INTENSITY_HCB: /* intensity books */
            case INTENSITY_HCB2:
                /* decode intensity position */
                t = aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
                is_position += (t - 60);
                ics->scale_factors[g][sfb] = is_position;

                break;
            case NOISE_HCB: /* noise books */
                /* decode noise energy */
                if(noise_pcm_flag){
                   kal_uint8 tmp1, tmp2;
                   noise_pcm_flag = 0;
                   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp1, 8);
                   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp2, 1);
                   t = (uint16)(tmp2 << 8) | (uint16)tmp1;
                   t = t - 256;
                }else{
                    t = aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
                    t -= 60;
                 }
                noise_energy += t;
                ics->scale_factors[g][sfb] = noise_energy;

                break;
            default: /* spectral books */
                /* scale_factors[g][sfb] must be between 0 and 255 */
                ics->scale_factors[g][sfb] = 0;
                /* decode scale factor */
                t = aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
                scale_factor += (t - 60);
                if (scale_factor < 0 || scale_factor > 255)
                    ihdl->aac.sbrParseError = true;
                ics->scale_factors[g][sfb] = scale_factor;

                break;
         }
      }
   }
}

static void aacPlusTnsData(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 w, filt, i, start_coef_bits, coef_bits, dummy;
   kal_uint8 n_filt_bits = 2;
   kal_uint8 length_bits = 6;
   kal_uint8 order_bits = 5;

   start_coef_bits = 0;
   if(ics->window_sequence == EIGHT_SHORT_SEQUENCE){
      n_filt_bits = 1;
      length_bits = 4;
      order_bits = 3;
   }

   for(w = 0; w < ics->num_windows; w++){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.n_filt[w], n_filt_bits);
      if(ics->tns.n_filt[w]){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.coef_res[w], 1);
         if(ics->tns.coef_res[w]){
            start_coef_bits = 4;
         }else{
             start_coef_bits = 3;
          }
      }

      for(filt = 0; filt < ics->tns.n_filt[w]; filt++){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.length[w][filt], length_bits);
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.order[w][filt], order_bits);

         if(ics->tns.order[w][filt]){
            FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.direction[w][filt], 1);
            FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.coef_compress[w][filt], 1);
            coef_bits = start_coef_bits - ics->tns.coef_compress[w][filt];
            if(coef_bits>8)
               ihdl->aac.sbrParseError = true;
            for(i = 0; i < ics->tns.order[w][filt]; i++)
               FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, coef_bits);
         }
      }
   }
}

static void aacPlusPulseData(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8 i, number_pulse, dummy;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &number_pulse, 2);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 6); /* pulse_start_sfb */

   for (i = 0; i < number_pulse+1; i++){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);
   }
}

static void aacPlusHuffman2stepQuad(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   kal_uint32 cw;
   kal_uint16 offset = 0;
   kal_uint8  extra_bits, dummy;
   kal_int8   tmp;

   cw = aacPlusPeekBits(ihdl, *puBitCnt, ihdl->fileOffset + ihdl->aac.rawDataBlockOffset, hcbN[cb]);

   offset = hcb_table[cb][cw].offset;
   extra_bits = hcb_table[cb][cw].extra_bits;

   if(extra_bits){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcbN[cb]);
      offset += (uint16)aacPlusPeekBits(ihdl, *puBitCnt, ihdl->fileOffset + ihdl->aac.rawDataBlockOffset, extra_bits);
      tmp = hcb_2_quad_table[cb][offset].bits - hcbN[cb];
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, tmp);
   }else{
       FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcb_2_quad_table[cb][offset].bits);
    }

   if(offset > hcb_2_quad_table_size[cb]){
      ihdl->aac.sbrParseError = true;
   }

   sp[0] = hcb_2_quad_table[cb][offset].x;
   sp[1] = hcb_2_quad_table[cb][offset].y;
   sp[2] = hcb_2_quad_table[cb][offset].v;
   sp[3] = hcb_2_quad_table[cb][offset].w;
}

static void aacPlusHuffmanSignBits(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 len, kal_int16 *sp)
{
   kal_uint8 i, tmp;

   for(i = 0; i < len; i++){
      if(sp[i]){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 1);
         if(tmp&1){
            sp[i] = -sp[i];
         }
      }
   }
}

static void aacPlusHuffmanBinaryQuad(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   kal_uint16 offset = 0;
   kal_uint8  b;

   while(!hcb3[offset].is_leaf){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &b, 1);
      offset += hcb3[offset].data[b];
   }

   if(offset > hcb_bin_table_size[cb]){
      ihdl->aac.sbrParseError = true;
   }

   sp[0] = hcb3[offset].data[0];
   sp[1] = hcb3[offset].data[1];
   sp[2] = hcb3[offset].data[2];
   sp[3] = hcb3[offset].data[3];
}

static void aacPlusHuffmanBinaryQuadSign(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   aacPlusHuffmanBinaryQuad(ihdl, puBitCnt, cb, sp);
   aacPlusHuffmanSignBits(ihdl, puBitCnt, 4, sp);
}

static void aacPlusHuffmanBinaryPair(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   kal_uint16 offset = 0;
   kal_uint8  b;

   while(!hcb_bin_table[cb][offset].is_leaf){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &b, 1);
      offset += hcb_bin_table[cb][offset].data[b];
   }

   if(offset > hcb_bin_table_size[cb]){
      ihdl->aac.sbrParseError = true;
   }

   sp[0] = hcb_bin_table[cb][offset].data[0];
   sp[1] = hcb_bin_table[cb][offset].data[1];
}

static void aacPlusHuffmanBinaryPairSign(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   aacPlusHuffmanBinaryPair(ihdl, puBitCnt, cb, sp);
   aacPlusHuffmanSignBits(ihdl, puBitCnt, PAIR_LEN, sp);
}

static void aacPlusHuffman2stepPair(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   kal_uint32 cw;
   kal_uint16 offset = 0;
   kal_uint8 extra_bits, dummy;

   cw = aacPlusPeekBits(ihdl, *puBitCnt, ihdl->fileOffset + ihdl->aac.rawDataBlockOffset, hcbN[cb]);

   offset = hcb_table[cb][cw].offset;
   extra_bits = hcb_table[cb][cw].extra_bits;

   if(extra_bits){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcbN[cb]);
      offset += aacPlusPeekBits(ihdl, *puBitCnt, ihdl->fileOffset + ihdl->aac.rawDataBlockOffset, extra_bits);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcb_2_pair_table[cb][offset].bits - hcbN[cb]);
   }else{
       FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcb_2_pair_table[cb][offset].bits);
    }

   if(offset > hcb_2_pair_table_size[cb]){
      ihdl->aac.sbrParseError = true;
   }

   sp[0] = hcb_2_pair_table[cb][offset].x;
   sp[1] = hcb_2_pair_table[cb][offset].y;
}

static void aacPlusHuffman2stepPairSign(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   aacPlusHuffman2stepPair(ihdl, puBitCnt, cb, sp);
   aacPlusHuffmanSignBits(ihdl, puBitCnt, PAIR_LEN, sp);
}

static void aacPlusHuffman2stepQuadSign(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   aacPlusHuffman2stepQuad(ihdl, puBitCnt, cb, sp);
   aacPlusHuffmanSignBits(ihdl, puBitCnt, QUAD_LEN, sp);
}

static kal_int16 aacPlusHuffmanCodebook( kal_uint8 i )
{
   static const kal_uint32 data = 16428320;
   if(i == 0) return (kal_int16)(data >> 16) & 0xFFFF;
   else       return (kal_int16)data & 0xFFFF;
}

static kal_int16 aacPlusHuffmanGetescape(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_int16 sp)
{
   kal_uint8 neg, i, tmp;
   kal_int32 j, off;

   if(sp < 0){
      if(sp != -16)
         return sp;
      neg = 1;
   }else{
       if(sp != 16)
          return sp;
       neg = 0;
    }

   for(i = 4; ; i++){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 1);
      if(tmp==0)
         break;
   }

   off = 0;
   {
      kal_int32 k, cnt;
      kal_uint8 i1;
      i1 = i;
      k = i1/8;
      if(k>0)
         for(cnt=0; cnt<k; cnt++){
            FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 8);
            off = ((uint32)off << (cnt*8))|(uint32)tmp;
         }
      i1 -= (8*k);
      if(i1>0){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, i1);
         off = ((uint32)off << i1)|(uint32)tmp;
      }
   }

   j = off | (1<<i);
   if(neg)
      j = -j;

   return j;
}

static void aacPlusHuffmanSpectralData(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   switch (cb)
   {
      case 1:
      case 2:
          aacPlusHuffman2stepQuad(ihdl, puBitCnt, cb, sp);
          break;
      case 3:
          aacPlusHuffmanBinaryQuadSign(ihdl, puBitCnt, cb, sp);
          break;
      case 4:
          aacPlusHuffman2stepQuadSign(ihdl, puBitCnt, cb, sp);
          break;
      case 5:
          aacPlusHuffmanBinaryPair(ihdl, puBitCnt, cb, sp);
          break;
      case 6:
          aacPlusHuffman2stepPair(ihdl, puBitCnt, cb, sp);
          break;
      case 7:
      case 9:
          aacPlusHuffmanBinaryPairSign(ihdl, puBitCnt, cb, sp);
          break;
      case 8:
      case 10:
          aacPlusHuffman2stepPairSign(ihdl, puBitCnt, cb, sp);
          break;
      case 12:
          aacPlusHuffman2stepPair(ihdl, puBitCnt, 11, sp);
          sp[0] = aacPlusHuffmanCodebook(0);
          sp[1] = aacPlusHuffmanCodebook(1);
          break;
      case 11:
          aacPlusHuffman2stepPairSign(ihdl, puBitCnt, 11, sp);
          sp[0] = aacPlusHuffmanGetescape(ihdl, puBitCnt, sp[0]);
          sp[1] = aacPlusHuffmanGetescape(ihdl, puBitCnt, sp[1]);
          break;
      default:
          break;
   }
}

static void aacPlusSpectralData(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_int8   i;
   kal_uint8  g, sect_cb_cache;
   kal_uint16 inc, k, p = 0;
   kal_uint8  groups = 0;
   kal_uint16 nshort = 128; // frameLength/8

   for(g = 0; g < ics->num_window_groups; g++)
   {
      p = groups*nshort;

      for (i = 0; i < ics->num_sec[g]; i++)
      {
         sect_cb_cache = ics->sect_cb[g][i];
         inc = (sect_cb_cache >= FIRST_PAIR_HCB) ? 2 : 4;

         switch (sect_cb_cache)
         {
            case ZERO_HCB:
            case NOISE_HCB:
            case INTENSITY_HCB:
            case INTENSITY_HCB2:
                 p += (ics->sect_sfb_offset[g][ics->sect_end[g][i]] -
                     ics->sect_sfb_offset[g][ics->sect_start[g][i]]);
                 break;
            default:
                 for (k = ics->sect_sfb_offset[g][ics->sect_start[g][i]];
                      k < ics->sect_sfb_offset[g][ics->sect_end[g][i]]; k += inc)
                 {
                    aacPlusHuffmanSpectralData(ihdl, puBitCnt, sect_cb_cache, &ics->spectral_Data[p]);
                    p += inc;
                 }
                 break;
         }
      }
      groups += ics->window_group_length[g];
   }
}

static void aacPlusIndividualChannelStream(aacMediaHdl *ihdl, iCS *ics,
                              kal_uint32 *puBitCnt, kal_uint8 common_window, kal_uint8 scal_flag)
{
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->global_gain, 8);

   if(!common_window && !scal_flag)
      aacPlusIcsInfo(ihdl, ics, puBitCnt);

   aacPlusSectionData(ihdl, ics, puBitCnt);
   aacPlusDecodeScaleFactors(ihdl, ics, puBitCnt);

   if (!scal_flag)
   {
      /* get pulse data */
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->pulse_data_present, 1);
      if(ics->pulse_data_present)
         aacPlusPulseData(ihdl, puBitCnt);

      /* get tns data */
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns_data_present, 1);
      if(ics->tns_data_present)
         aacPlusTnsData(ihdl, ics, puBitCnt);

      /* get gain control data */
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->gain_control_data_present, 1);
      if(ics->gain_control_data_present){
         ihdl->aac.sbrParseError = true;
         return;
      }
   }
   /* decode the spectral data */
   aacPlusSpectralData(ihdl, ics, puBitCnt);
}

static void aacPlusSingleChannelElement(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 element_instance_tag;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &element_instance_tag, 4);
   aacPlusIndividualChannelStream(ihdl, ics, puBitCnt, 0, 0);
}

static void aacPlusChannelPairElement(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 element_instance_tag, common_window;
   iCS *ics2;

   ics2 = (iCS*)med_alloc_ext_mem( sizeof(iCS) );
   if(ics2 == NULL){
      ihdl->aac.sbrParseError = true;
      return;
   }
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &element_instance_tag, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &common_window, 1);

   if(common_window){
      /* both channels have common ics information */
      aacPlusIcsInfo(ihdl, ics, puBitCnt);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->ms_mask_present, 2);
      if (ics->ms_mask_present == 1){
          kal_uint8 g, sfb;
          for(g = 0; g < ics->num_window_groups; g++){
             for(sfb = 0; sfb < ics->max_sfb; sfb++)
                FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->ms_used[g][sfb], 1);
          }
      }
   }
   memcpy(ics2, ics, sizeof(iCS));
   aacPlusIndividualChannelStream(ihdl, ics, puBitCnt, common_window, 0);
   aacPlusIndividualChannelStream(ihdl, ics2, puBitCnt, common_window, 0);
   med_free_ext_mem( (void **) &ics2 );
}

static void aacPlusCouplingChannelElement(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 c;
   kal_uint8 ind_sw_cce_flag = 0;
   kal_uint8 num_gain_element_lists = 0;
   kal_uint8 num_coupled_elements = 0;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &c, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ind_sw_cce_flag, 1);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_coupled_elements, 3);

   for (c = 0; c < num_coupled_elements + 1; c++){
      kal_uint8 cc_target_is_cpe, cc_target_tag_select;

      num_gain_element_lists++;
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cc_target_is_cpe, 1);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cc_target_tag_select, 4);

      if (cc_target_is_cpe){
         kal_uint8 cc_l, cc_r;
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cc_l, 1);
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cc_r, 1);

         if (cc_l && cc_r)
            num_gain_element_lists++;
      }
   }
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &c, 4);

   aacPlusIndividualChannelStream(ihdl, ics, puBitCnt, 0, 0);

   for (c = 1; c < num_gain_element_lists; c++){
      kal_uint8 cge;
      if (ind_sw_cce_flag){
          cge = 1;
      } else {
          FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cge, 1);
      }
      if (cge){
         aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
      } else {
          kal_uint8 g, sfb;

          for (g = 0; g < ics->num_window_groups; g++){
             for (sfb = 0; sfb < ics->max_sfb; sfb++){
                if (ics->sfb_cb[g][sfb] != ZERO_HCB)
                   aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
              }
          }
      }
   }
}

/* Refer to ISO/IEC 14496-3:2001(E)
   However,only required to parse SCE/CPE/LFE/CCE/DCE/PCE/FIL
   in raw_data_block(), without interpreting them.
*/
static void aacPlusSearchSBR(aacMediaHdl *ihdl)
{
   iCS *ics;
   kal_uint8  id_syn_ele;
   kal_uint32 puBitCnt=0;

   FSAL_Seek( ihdl->pstFSAL, (ihdl->fileOffset + ihdl->aac.rawDataBlockOffset));
   ics = (iCS*)med_alloc_ext_mem( sizeof(iCS) );
   if(ics == NULL){
      ihdl->aac.sbrParseError = true;
      return;
   }
   memset(ics, 0, sizeof(iCS));

   /* Table 4.4.3: raw_data_block() */
   while(1){
      FSAL_Read_Bits( ihdl->pstFSAL, &puBitCnt, &id_syn_ele, LEN_SE_ID);
      if( id_syn_ele == ID_END || ihdl->aac.sbrParseError == true) break;

      switch (id_syn_ele) {
         case ID_SCE:
             aacPlusSingleChannelElement(ihdl, ics, &puBitCnt);
             break;
         case ID_CPE:
             aacPlusChannelPairElement(ihdl, ics, &puBitCnt);
             break;
         case ID_LFE:
             aacPlusSingleChannelElement(ihdl, ics, &puBitCnt);
             break;
         case ID_CCE:
             aacPlusCouplingChannelElement(ihdl, ics, &puBitCnt);
             break;
         case ID_DSE:
             aacPlusDataStreamElement(ihdl, &puBitCnt);
             break;
         case ID_PCE:
             aacPlusProgramConfigElement(ihdl, &puBitCnt);
             break;
         case ID_FIL:
             aacPlusFillElement(ihdl, &puBitCnt);
             if(ihdl->aac.sbrPresentFlag){
                med_free_ext_mem( (void **) &ics );
                return;
             }
             break;
         default:
             med_free_ext_mem( (void **) &ics );
             return;
      }
   }
   med_free_ext_mem( (void **) &ics );
}
#endif // AAC_PLUS_DECODE

static kal_int32 aacGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   kal_uint32 file_size, data_size;

   FSAL_GetFileSize(pstFSAL, &file_size);
   data_size = file_size - fileOffset;

   if(data_size <= num_bytes){  // EOF
      num_bytes = data_size;
   }

   FSAL_Seek( pstFSAL, fileOffset);
   if(FSAL_Read_Bytes( pstFSAL, ptr, num_bytes) != FSAL_OK)
      return -1; // Playback should be terminated

   return num_bytes;
}
static void aacProcessCache(aacMediaHdl *ihdl, kal_int32 processCacheCnt)
{
   kal_uint32  i, k, uCurPos, frames_per_cache, valid_cache_number, current_cache_index, temp_offset, uOffset, buf_len;
   kal_uint8   *pbHeader;
   kal_int32   uCnt, uFrameCnt;

   ihdl->mh.GetWriteBuffer((MHdl*)ihdl, &pbHeader, &buf_len);
   current_cache_index = (kal_uint32)ihdl->AudioCacheTbl->current_cache_index;
   valid_cache_number = (kal_uint32)ihdl->AudioCacheTbl->valid_cache_number;
   frames_per_cache = (kal_uint32)ihdl->AudioCacheTbl->frames_per_cache;
   temp_offset = ihdl->AudioCacheTbl->start_offset[current_cache_index];

	if(current_cache_index == valid_cache_number-1){
	   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FINISH_RETURN, MEDIA_FORMAT_AAC );
	   return; // cache table finished
	}

   FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);

   uCnt = 0;
   uFrameCnt = 0;
   uOffset = 0;
   for (i=processCacheCnt; i != 0; i--) {
	   for (k=0; k < frames_per_cache; k++){
	       kal_int16   frame_length;

          if(!uCnt){
		       if( (uCnt = aacGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, temp_offset, buf_len, pbHeader)) < (ADTS_MAX_SIZE+1)){
		          valid_cache_number = current_cache_index + 1;
			       FSAL_Seek( ihdl->pstFSAL, uCurPos);
                ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
                ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
                ihdl->AudioCacheTbl->total_frame += uFrameCnt;
                kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_END, MEDIA_FORMAT_AAC, ihdl->AudioCacheTbl->total_frame);
                return;
		       }
		    }

          if(!(((uint16)pbHeader[uOffset] == 0xFF)&&(((uint16)pbHeader[1+uOffset] & 0xF6) == 0xF0))){
             uOffset++;
             if(!(((uint16)pbHeader[uOffset] == 0xFF)&&(((uint16)pbHeader[1+uOffset] & 0xF6) == 0xF0))){
                uOffset++;
                if(!(((uint16)pbHeader[uOffset] == 0xFF)&&(((uint16)pbHeader[1+uOffset] & 0xF6) == 0xF0))){
                   valid_cache_number = current_cache_index + 1;
			          FSAL_Seek( ihdl->pstFSAL, uCurPos);
                   ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
                   ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
                   ihdl->AudioCacheTbl->total_frame += uFrameCnt;
                   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FAILED, MEDIA_FORMAT_AAC, ihdl->AudioCacheTbl->total_frame );
                   return;
                }
             }
		    }

          frame_length = ((((uint32)pbHeader[3+uOffset] & 0x3)) << 11)
           | (((uint32)pbHeader[4+uOffset]) << 3) | (pbHeader[5+uOffset] >> 5);

          uOffset += (uint32)frame_length;
          uFrameCnt++;

		    if((uOffset+7) >= uCnt){
		       temp_offset += uOffset;
		       uCnt = 0;
		       uOffset = 0;
		    }
	   }
      if(current_cache_index){
         ihdl->AudioCacheTbl->accumulated_frames[current_cache_index]=
		   ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1]+k;
		   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_ACCFRAME, MEDIA_FORMAT_AAC, current_cache_index, ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1]+k );
		}else{
         ihdl->AudioCacheTbl->accumulated_frames[0]= k;
         kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_ACCFRAME, MEDIA_FORMAT_AAC, 0, k );
      }
		if(current_cache_index != valid_cache_number-1){
         ihdl->AudioCacheTbl->start_offset[++current_cache_index]=temp_offset+uOffset;
         kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, MEDIA_FORMAT_AAC, current_cache_index, temp_offset+uOffset );
      }

   }
   FSAL_Seek( ihdl->pstFSAL, uCurPos);
   ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
   ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
   ihdl->AudioCacheTbl->total_frame = ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1];
}

static kal_bool aacSeek( aacMediaHdl *ihdl, kal_bool fCacheEnable )
{   /* file offset must be aligned the first ADTS frame header */
   kal_int32  cnt, frameLen, startFrame;
   kal_uint16 start_index, end_index;
   kal_uint8  *pbHeader;
   kal_uint32 buf_len;

   ihdl->mh.read = 0;
   ihdl->mh.write = 0;
   ihdl->mh.GetWriteBuffer((MHdl*)ihdl, &pbHeader, &buf_len);
   start_index = 0;

   ASSERT(ihdl->frameDur != 0); // memory corrupted
   startFrame = (kal_uint64)ihdl->mh.start_time * 1000000 / ihdl->frameDur; // calculate start frame count

   /// Process cache table
   if((ihdl->AudioCacheTbl != 0) && fCacheEnable){
      end_index = ihdl->AudioCacheTbl->current_cache_index;
      /// Binary Search
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index + end_index) / 2;
         if (startFrame > (kal_int32)ihdl->AudioCacheTbl->accumulated_frames[middle_index])
            start_index = middle_index;
         else
            end_index = middle_index;
      }
      /// Linear Search
      if (start_index) {
         cnt = ihdl->AudioCacheTbl->accumulated_frames[start_index];
      } else {
         cnt = 0;
      }

   }else{
       cnt = 0;
   }
   {
      kal_uint32 uCnt, uOffset;
      kal_uint32 temp_offset;

      if(ihdl->AudioCacheTbl != 0){
         if(start_index)
	         temp_offset = ihdl->AudioCacheTbl->start_offset[start_index+1];
	      else
	         temp_offset = ihdl->AudioCacheTbl->start_offset[0];
	   }else{
	       temp_offset = ihdl->fileOffset;
	    }

      uCnt = 0;
	   uOffset = 0;

      for (; cnt < startFrame; cnt++) {

         if(!uCnt){
            if( (uCnt = aacGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, temp_offset, buf_len, pbHeader)) < ADTS_MAX_SIZE){
               break;
            }
         }

         if(!((pbHeader[0+uOffset] == 0xFF)&&((pbHeader[1+uOffset] & 0xF6) == 0xF0))){
            uOffset++;
            if(!((pbHeader[0+uOffset] == 0xFF)&&((pbHeader[1+uOffset] & 0xF6) == 0xF0)))
               uOffset++;
            if(!((pbHeader[0+uOffset] == 0xFF)&&((pbHeader[1+uOffset] & 0xF6) == 0xF0)))
               break;
         }
         frameLen = ((((uint32)pbHeader[3+uOffset] & 0x3)) << 11)
          | (((uint32)pbHeader[4+uOffset]) << 3) | (pbHeader[5+uOffset] >> 5);

         uOffset += frameLen;

         if((uOffset+7) >= uCnt){
            temp_offset += uOffset;
            uCnt = 0;
            uOffset = 0;
         }
      }
	   ihdl->fileOffset = temp_offset + uOffset;
	   ihdl->resumeFrameOffset = temp_offset + uOffset; // last frame offset aligned frame boundary
	   audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
   }

   if (cnt != startFrame){
      ihdl->mh.start_time = ihdl->mh.current_time = (kal_uint64)cnt * ihdl->frameDur / 1000000; // update start time
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_FAIL, MEDIA_FORMAT_AAC, startFrame, ihdl->fileOffset, ihdl->mh.start_time);
      return KAL_FALSE;
   }else{
       kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_RESULT, MEDIA_FORMAT_AAC, startFrame, ihdl->fileOffset, ihdl->mh.start_time);
       return KAL_TRUE;
    }
}

#if defined(AAC_PLUS_DECODE)
void AAC_Plus_Forbidden(void) // Disable SBR and PS
{
   fDisableAACPlus = true;
}
#endif // #if defined(AAC_PLUS_DECODE)

#ifdef AAC_PLUS_PS_DECODE

void AAC_PS_Forbidden(void) // Disable PS
{
   fDisableAACPS = true;
}

#endif // #ifdef AAC_PLUS_PS_DECODE

static void aacUpdateSR( aacMediaHdl *ihdl )
{
   MHdl *hdl = (MHdl *)ihdl;
#if defined(AAC_PLUS_DECODE) // check supported case only, including 16k, 22.05k and 24k
   if(!fDisableAACPlus){
      if(ihdl->aac.sr_idx == 6 ||ihdl->aac.sr_idx==7 || ihdl->aac.sr_idx==8
#if defined(CT_AAC_PLUS)
       || ihdl->aac.sr_idx == 9 ||ihdl->aac.sr_idx==10 || ihdl->aac.sr_idx==11
#endif
       ){
         aacPlusSearchSBR(ihdl);
         if(ihdl->aac.sbrPresentFlag == true){
            ihdl->aac.sr_idx -= 3; /* double sample rate */
            if(hdl->mediaType != MEDIA_FORMAT_M4A)
               hdl->mediaType = MEDIA_FORMAT_AAC_PLUS;
         }
      }
   }
#endif // AAC_PLUS_DECODE
   return;
}

/* Refer to ISO/IEC 14496-3:2001(E) Annex 1.A */
static Media_Status aacParseHeader(aacMediaHdl *ihdl, kal_uint8 *pBuf)
{
   kal_uint8  protection_absent, no_raw_data_blocks_in_frame, num_program_config_elements;
   kal_uint32 uBitCnt=0;

   if ((pBuf[0] == 0xFF) && ((pBuf[1] & 0xF0) == 0xF0)) { /* ADTS */
      /* fixed header */
      autGetBitsFromBuf(pBuf, &uBitCnt, 8); /* syncword(12) + ID(1) */
      autGetBitsFromBuf(pBuf, &uBitCnt, 5);
      if (autGetBitsFromBuf(pBuf, &uBitCnt, 2) != 0x00) /* layer */
         return MEDIA_BAD_FORMAT;
      protection_absent = autGetBitsFromBuf(pBuf, &uBitCnt, 1); /* protection absent */

      if ( autGetBitsFromBuf(pBuf, &uBitCnt, 2) != 0x01) /* profile object type */
         return MEDIA_UNSUPPORTED_TYPE;

      ihdl->aac.sr_idx = autGetBitsFromBuf(pBuf, &uBitCnt, 4); /* sampling frequency index */
      if(ihdl->aac.sr_idx < 3 || ihdl->aac.sr_idx > 11)
         return MEDIA_UNSUPPORTED_FREQ;

      autGetBitsFromBuf(pBuf, &uBitCnt, 1); /* private bit */
      {
         kal_uint8 channel;
         channel = autGetBitsFromBuf(pBuf, &uBitCnt, 3);
         if ( channel > 0x02) /* channel configuration */
            return MEDIA_UNSUPPORTED_CHANNEL;
         if ( channel == 2 ) ihdl->aac.stereo = true;
      }
      /* original/copy(1), home(1) */ /* copyright bit(1), copyright start(1) */
		autGetBitsFromBuf(pBuf, &uBitCnt, 4);

	 /* variable header */
		autGetBitsFromBuf(pBuf, &uBitCnt, 8);
		autGetBitsFromBuf(pBuf, &uBitCnt, 8);
		autGetBitsFromBuf(pBuf, &uBitCnt, 8);

		no_raw_data_blocks_in_frame = autGetBitsFromBuf(pBuf, &uBitCnt, 2);

      if (protection_absent == 0){
         if(no_raw_data_blocks_in_frame){ /* no_raw_data_blocks_in_frame */
            autGetBitsFromBuf(pBuf, &uBitCnt, 8);
            autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         }
         autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      }
      /* cache ADTS Fixed Header */
      kal_mem_cpy(ihdl->aac.bADTSFixedHeader, pBuf, 4);
      ihdl->aac.bADTSFixedHeader[3] &= 0xF0;
      ihdl->aac.bIsTypeADTS = KAL_TRUE;

   } else if ((pBuf[0] == 'A') && (pBuf[1] == 'D') && (pBuf[2] == 'I') && (pBuf[3] == 'F')) { /* ADIF */

      kal_uint8 uBitstreamType;
      autGetBitsFromBuf(pBuf, &uBitCnt, 8); /* read out 4 bytes */
      autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      if (autGetBitsFromBuf(pBuf, &uBitCnt, 1)) { /* copyright_id_present */
         kal_uint32 uCount;
         for (uCount=0; uCount<9; uCount++)
            autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      }
      autGetBitsFromBuf(pBuf, &uBitCnt, 2); /* origianl copy(1), home(1) */
      uBitstreamType = autGetBitsFromBuf(pBuf, &uBitCnt, 1);

      ihdl->aac.bitRate = autGetBitsFromBuf(pBuf, &uBitCnt, 8) |
      ((uint32)autGetBitsFromBuf(pBuf, &uBitCnt, 8) << 8) |
      ((uint32)autGetBitsFromBuf(pBuf, &uBitCnt, 7) << 16);

      num_program_config_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);

      if (0 == uBitstreamType) {
         autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         autGetBitsFromBuf(pBuf, &uBitCnt, 4);
      }
      {
         kal_uint32 uCount,i;
         kal_uint8  num_front_channel_elements, num_side_channel_elements
                  , num_back_channel_elements, num_lfe_channel_elements
                  , num_assoc_data_elements, num_valid_cc_elements, comment_field_bytes;
               /*--- PCE ---*/
         for (uCount = 0; uCount < num_program_config_elements + 1; uCount++)
         {
            autGetBitsFromBuf(pBuf, &uBitCnt, 4); /* element_instance_tag */
            if ( autGetBitsFromBuf(pBuf, &uBitCnt, 2) != 0x01) /* object type */
               return MEDIA_UNSUPPORTED_TYPE;

            ihdl->aac.sr_idx = autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            if(ihdl->aac.sr_idx < 3 || ihdl->aac.sr_idx > 11)
               return MEDIA_UNSUPPORTED_FREQ;
            num_front_channel_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            num_side_channel_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            num_back_channel_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            num_lfe_channel_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 2);
            num_assoc_data_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 3);
            num_valid_cc_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);

            if (autGetBitsFromBuf(pBuf, &uBitCnt, 1) == 1)
               autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            if (autGetBitsFromBuf(pBuf, &uBitCnt, 1) == 1)
               autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            if (autGetBitsFromBuf(pBuf, &uBitCnt, 1) == 1)
               autGetBitsFromBuf(pBuf, &uBitCnt, 3);
            for (i = 0; i < num_front_channel_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 5);
            for (i = 0; i < num_side_channel_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 5);
            for (i = 0; i < num_back_channel_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 5);
            for (i = 0; i < num_lfe_channel_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            for (i = 0; i < num_assoc_data_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            for (i = 0; i < num_valid_cc_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 5);

            uBitCnt += 8-(uBitCnt%8); // byte alignment

            comment_field_bytes = autGetBitsFromBuf(pBuf, &uBitCnt, 8);
            for (i = 0; i < comment_field_bytes; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         }
      }
      ihdl->aac.bIsTypeADIF = KAL_TRUE;
   } else {
      return MEDIA_FAIL;
   }
   ihdl->aac.rawDataBlockOffset = uBitCnt/8;
   ihdl->frameDur = (kal_uint64)SAMPLES_PER_FRAME * (kal_uint64)1000000000 / (kal_uint64) sampleRateTab[ihdl->aac.sr_idx];
   /* Currently, DSP decoder only support 1024 samples per frame */
   return MEDIA_SUCCESS;
}

static Media_Status aacSyncFirstFrame( aacMediaHdl *ihdl )
{  /* bit-stream should be more than 512 Bytes */
   Media_Status ret;
	kal_uint8  *ptr, *end;
	kal_uint32 num_bytes;
	kal_uint32 firstFrameOffset = 0;
	kal_bool found = KAL_FALSE;

	while( !found )
	{  // check if it is out of searching range
		if( firstFrameOffset > MAX_FRAME_CHECK_LEN)
			return MEDIA_BAD_FORMAT;

		num_bytes = autGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, ihdl->fileOffset, AAC_MAX_DATA_REQUESTED, &ihdl->buf[0]);
		if(num_bytes < (MIN_DATA_LEN *2)) return MEDIA_BAD_FORMAT;

		for( ptr = &ihdl->buf[0], end = (ptr + num_bytes - MIN_DATA_LEN) ; ptr < end; ptr++ )
		{
		   ret=aacParseHeader( ihdl, ptr );
			if( ret == MEDIA_SUCCESS ){
				ihdl->fileOffset += (uint32)(ptr - &ihdl->buf[0]);
				found = KAL_TRUE;
				break;
			}
		   if( ret != MEDIA_FAIL )
		      return ret;
		}
		if( !found ){
         ihdl->fileOffset += (num_bytes - MIN_DATA_LEN);
         firstFrameOffset += num_bytes - MIN_DATA_LEN;
      }
	}
   return MEDIA_SUCCESS;
}

static void aacIncTime( MHdl *hdl, uint32 num_bytes )
{
   (void)hdl;
   (void)num_bytes;
   return; // dummy function
}

static kal_int32 aacGetDSPDataCnt( aacMediaHdl *ihdl, kal_uint16 dspWriteIdx )
{
   int32 I;
   uint16 rb_w;

   if(dspWriteIdx == 0xFFFF){
      rb_w = *AAC_MCU_WRITE_PTR;
      ihdl->AAC_DSP_Write_Idx = rb_w;
   }else
      rb_w = dspWriteIdx;

   do {
      I = (int32)*AAC_DSP_READ_PTR;
   } while( I != (int32)*AAC_DSP_READ_PTR );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += ihdl->mh.dsp_rb_size;

   return (ihdl->mh.dsp_rb_size - I);  // total data size in word
}

static void aacWriteZero( aacMediaHdl *ihdl )
{
   int32 I, count, len;
   uint16 rb_w;

   rb_w = *AAC_MCU_WRITE_PTR;

   do {
      I = (int32)*AAC_DSP_READ_PTR;
   } while( I != (int32)*AAC_DSP_READ_PTR );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += ihdl->mh.dsp_rb_size;

   count = (int32)(ihdl->mh.dsp_rb_end - rb_w);

   if(count > I)
      count = I;

   len = I;
#if defined(MT6226) || defined(MT6227)
   DSP_WRITE( DSP_PM_ADDR(AAC_PAGE_NUM, rb_w), 0xFFFF );
   for( I = 1; I < count; I++ )
      DSP_WRITE( IDMA_SHORT_ADDR, 0xFFFF );
#else
   DSP_WRITE( DSP_PM_ADDR(AAC_PAGE_NUM, rb_w), 0 );
   for( I = 1; I < count; I++ )
      DSP_WRITE( IDMA_SHORT_ADDR, 0 );
#endif //#if defined(MT6226) || defined(MT6227)

   rb_w += (uint16)count;
   if( rb_w >= ihdl->mh.dsp_rb_end )
      rb_w = ihdl->mh.dsp_rb_base;
   *DAF_MCU_WRITE_PTR = rb_w;

   count = len - count;
   if( count > 0 ) {
#if defined(MT6226) || defined(MT6227)
     DSP_WRITE( DSP_PM_ADDR(AAC_PAGE_NUM, rb_w), 0xFFFF );
     for( I = 1; I < count; I++ )
        DSP_WRITE( IDMA_SHORT_ADDR, 0xFFFF );
#else
     DSP_WRITE( DSP_PM_ADDR(AAC_PAGE_NUM, rb_w), 0 );
     for( I = 1; I < count; I++ )
        DSP_WRITE( IDMA_SHORT_ADDR, 0 );
#endif //#if defined(MT6226) || defined(MT6227)
     *AAC_MCU_WRITE_PTR = rb_w + (uint16)count;
   }
}

static kal_int32 aacGetDSPIncOffset( aacMediaHdl *ihdl )
{
   int32 I;
   uint16 rb_r;

   rb_r = ihdl->wDspReadIdx;

   do {
      I = (int32)*AAC_DSP_READ_PTR;
   } while( I != (int32)*AAC_DSP_READ_PTR  );

   ihdl->wDspReadIdx = I;

   I = I - (int32)rb_r;
   if( I < 0 )
      I += ihdl->mh.dsp_rb_size;

   return (I<<1);  // total data size in byte
}
#ifdef AAC_PLUS_PS_DECODE
static void aacWriteDataToDSP(aacMediaHdl *ihdl)
{
   MHdl *hdl = (MHdl *)ihdl;
   MHdl *pstTmp = ihdl->pstMHdl;

   if( hdl->GetDataCount(pstTmp) > 1 ){
      kal_int32 mbDataLen, mbDataLenLow, mbDataLenHigh;
      kal_uint16 *buf;
      kal_uint16 report_data = 1;

      if(pstTmp->read >= pstTmp->rb_size)
      pstTmp->read = 0;
      buf = (uint16 *)&pstTmp->rb_base[pstTmp->read];

      mbDataLen = hdl->GetDataCount(pstTmp) >> 1; // in word
      if( mbDataLen >= SAMPLES_PER_FRAME){
         kal_uint16 *dsp_ptr;
         int len, uFrameSize;
         int DSP_ADDRESS_PM = *AAC_PS_BITSTR_ADDRESS;
         int MAX_LEN = *AAC_PS_BITSTR_Length;

// update resume offset
         uFrameSize = *buf++;
         ihdl->uCurFrame++;
         ihdl->mh.current_time = ihdl->uCurFrame * ihdl->frameDur / 1000000;
         ihdl->resumeFrameOffset += uFrameSize;
         audResumeInfo.uCurOffset += uFrameSize;
         pstTmp->read+=2;
         mbDataLen--;

         if(pstTmp->read >= pstTmp->rb_size)
         pstTmp->read = 0;
         buf = (uint16 *)&pstTmp->rb_base[pstTmp->read];
      
         len = *buf++;
         ASSERT( len < MAX_LEN);
         AACBUFFER.AAC_WRITE_LEN = len;
         if( len == 0)
            report_data = 2;
         pstTmp->read+=2;
         mbDataLen--;

         mbDataLenLow = (pstTmp->rb_size - pstTmp->read) >> 1; // in word
         if( mbDataLenLow > mbDataLen )
            mbDataLenLow = mbDataLen;
         mbDataLenHigh = mbDataLen - mbDataLenLow;

         dsp_ptr = (kal_uint16 *)DSP_PM_ADDR(0,DSP_ADDRESS_PM);

         if(mbDataLenLow >= len){
            pstTmp->read += len << 1;
            mbDataLenLow -= len;
            for( ;--len >= 0; )
               *dsp_ptr ++ = *buf++;
         }else{
            pstTmp->read += mbDataLenLow << 1;
            len -= mbDataLenLow;
            for( ;--mbDataLenLow >= 0; )
               *dsp_ptr ++ = *buf++;

            if( pstTmp->read >= pstTmp->rb_size ){
               pstTmp->read = 0;
               buf = (uint16 *)&pstTmp->rb_base[pstTmp->read];
               ASSERT(mbDataLenHigh >= len);
               pstTmp->read += len << 1;
               for( ;--len >= 0; )
                  *dsp_ptr ++ = *buf++;
            }
         }

         len = MAX_LEN - AACBUFFER.AAC_WRITE_LEN;
         for( ;--len >= 0; )
            *dsp_ptr ++ = 0;

         //raw data
         buf = (uint16 *)&pstTmp->rb_base[pstTmp->read];
         mbDataLen = hdl->GetDataCount(pstTmp) >> 1; // in word
         ASSERT(mbDataLen >= SAMPLES_PER_FRAME);

         {
            kal_uint16 *dsp_ptr;
            int len = SAMPLES_PER_FRAME;
            int DSP_ADDRESS_DM = *AAC_PS_PCM_ADDRESS;
            int dmovlay = *AAC_PS_PCM_DMOVLAY;

            mbDataLenLow = (pstTmp->rb_size - pstTmp->read) >> 1; // in word
            if( mbDataLenLow > mbDataLen )
               mbDataLenLow = mbDataLen;
            mbDataLenHigh = mbDataLen - mbDataLenLow;

            dsp_ptr = (kal_uint16 *)DSP_DM_ADDR(dmovlay,DSP_ADDRESS_DM);

            if(mbDataLenLow >= len){
               pstTmp->read += len << 1;
               mbDataLenLow -= len;
               for( ;--len >= 0; )
                  *dsp_ptr ++ = *buf++;
            }else{
               pstTmp->read += mbDataLenLow << 1;
               len -= mbDataLenLow;
               for( ;--mbDataLenLow >= 0; )
                  *dsp_ptr ++ = *buf++;

               if( pstTmp->read >= pstTmp->rb_size ){
                  pstTmp->read = 0;
                  buf = (uint16 *)&pstTmp->rb_base[pstTmp->read];
                  ASSERT(mbDataLenHigh >= len);
                  pstTmp->read += len << 1;
                  for( ;--len >= 0; )
                     *dsp_ptr ++ = *buf++;
               }
            }
         }
         AACBUFFER.AAC_Media_Buffer_R = (int) pstTmp->read + (int)AACBUFFER.AAC_Media_Buffer;
         *AACPS_BS_FLAG = report_data;
      }
   }else{
       kal_uint16 *dsp_ptr;
       kal_int32 len = SAMPLES_PER_FRAME;
       kal_int32 DSP_ADDRESS_DM = *AAC_PS_PCM_ADDRESS;
       kal_int32 dmovlay = *AAC_PS_PCM_DMOVLAY;

       *AACPS_BS_FLAG = 2;
        dsp_ptr = (kal_uint16 *)DSP_DM_ADDR(dmovlay,DSP_ADDRESS_DM);

       for( ;--len >= 0; )
          *dsp_ptr ++ = 0;
    }
}

static void aacHdlBufInfoSwap( MHdl *pHdl1, MHdl *pHdl2 )
{
   kal_int32 iSize;
   kal_int32 iRead;
   kal_int32 iWrite;
   kal_bool  fEof;

   iWrite = pHdl1->write;
   iRead = pHdl1->read;
   iSize = pHdl1->rb_size;
   fEof = pHdl1->eof;

   pHdl1->write = pHdl2->write;
   pHdl1->read = pHdl2->read;
   pHdl1->rb_size = pHdl2->rb_size;
   pHdl1->eof = pHdl2->eof;

   pHdl2->write = iWrite;
   pHdl2->read = iRead;
   pHdl2->rb_size = iSize;
   pHdl2->eof = fEof;
}

#endif // #ifdef AAC_PLUS_PS_DECODE
static void aacHisr( void *data )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)data;
   MHdl *hdl = (MHdl *)ihdl;

   if( ihdl->end_status == MEDIA_TERMINATED )
      return;

   if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_IDLE ) {  // DSP in idle state
      kal_prompt_trace( MOD_L1SPHISR, " AAC_L1AUDIO_IDLE_STATE ");

      if (KAL_TRUE == ihdl->aac.bError) {         
         mhdlException( (MHdl*)ihdl, MEDIA_ERROR );
      } else if(KAL_TRUE == ihdl->aac.bDecUnsupport){
           mhdlException( (MHdl*)ihdl, MEDIA_DECODER_UNSUPPORT );
      } else if(ihdl->end_status == MEDIA_STOP_TIME_UP){
           mhdlException( (MHdl*)ihdl, MEDIA_STOP_TIME_UP );
      } else{
           mhdlException( (MHdl*)ihdl, MEDIA_END );
      }
      ihdl->end_status = MEDIA_TERMINATED;
      return;
   }

   if( ihdl->end_status == MEDIA_END || ihdl->end_status == MEDIA_STOP_TIME_UP)
      return;

#ifdef AAC_PLUS_PS_DECODE
   if(ihdl->fEnableARMDecoder){
      if( ihdl->fDecoderError )
         mhdlException( (MHdl*)ihdl, MEDIA_ERROR );
   }else
#endif // #ifdef AAC_PLUS_PS_DECODE
   if ((*AAC_ERROR_REPORT != 0) && (*AAC_ERROR_REPORT != 0x2222))  /* bypass the buffer underflow warning from DSP */
   {
      if(ihdl->AAC_Decode_EOF){
         ihdl->end_status = MEDIA_END;
         if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
            *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
         kal_prompt_trace( MOD_L1SPHISR, " AAC_L1AUDIO_END_STATE ");
         return;
      }
      /* check if DSP reports error */
      *AAC_MAIN_CONTROL = DSP_AAC_STATE_STOP;
      if(*AAC_ERROR_REPORT == 0x1111)
         ihdl->aac.bDecUnsupport = KAL_TRUE;
      else
         ihdl->aac.bError = KAL_TRUE;
      return;
   }

// update current time and file offset
   if(ihdl->wDspReadIdx != 0xFFFF){

#ifdef AAC_PLUS_PS_DECODE
      if(ihdl->fEnableARMDecoder){
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if 0
      }else
#endif // #ifdef AAC_PLUS_PS_DECODE
      {
         kal_int32 iFrameOffset;
         iFrameOffset = aacGetDSPIncOffset( ihdl );
         if(iFrameOffset){ // Don't increase current time as buffer underflow
            ihdl->uCurFrame++;
            ihdl->mh.current_time = ihdl->uCurFrame * ihdl->frameDur / 1000000;
            ihdl->resumeFrameOffset += iFrameOffset;
            audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
         }
      }

      if(ihdl->AudioCacheTbl != 0){  // update cache table
         kal_uint32 uAcumFrms, uTotalFrames, uCurCacheIdx;
         uCurCacheIdx = ihdl->AudioCacheTbl->current_cache_index;
         if(uCurCacheIdx)
            uAcumFrms = ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx-1];
         else
            uAcumFrms = 0;

         uTotalFrames = ihdl->uCurFrame;

         if((uTotalFrames-uAcumFrms)==ihdl->AudioCacheTbl->frames_per_cache){
            if(uCurCacheIdx){
               ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx] = uTotalFrames;
               kal_prompt_trace( MOD_L1SP, " AAC: Cache_AccFrame = %d, idx = %d", uTotalFrames, uCurCacheIdx);
		      }else{
               ihdl->AudioCacheTbl->accumulated_frames[0]= uTotalFrames;
               kal_prompt_trace( MOD_L1SP, " AAC: Cache_AccFrame = %d, idx = %d", uTotalFrames, 0);
            }
		      if(uCurCacheIdx != ihdl->AudioCacheTbl->valid_cache_number-1){
               ihdl->AudioCacheTbl->start_offset[++uCurCacheIdx]=ihdl->resumeFrameOffset;
               kal_prompt_trace( MOD_L1SP, " AAC: Cache_StrOffset = %d, idx = %d", ihdl->resumeFrameOffset, uCurCacheIdx);
               ihdl->AudioCacheTbl->current_cache_index = uCurCacheIdx;
               ihdl->AudioCacheTbl->total_frame = ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx-1];
            }
         }
      }
   }

   if( ihdl->mh.dsp_rb_base == 0 ) {   // DSP RingBuf initialization
      ihdl->mh.dsp_rb_base = *AAC_FIFO_BASE;
      ihdl->mh.dsp_rb_size = *AAC_FIFO_LENGTH;
      ihdl->mh.dsp_rb_end = ihdl->mh.dsp_rb_base + ihdl->mh.dsp_rb_size;
      ihdl->wDspReadIdx = *AAC_DSP_READ_PTR;
   }

#ifdef AAC_DEBUG_ENABLE
   if( (*AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING) && ( 1 == *AACPS_CHKSUM_ENABLE)){ // log checksum info.
   	  if(aacCnt == 0xFFFFFFFF){
   	     aacCnt = 0;
   	     aacChecksumInfo[aacCnt++] = *AACPS_OUTPUT_CHK_SUM;
   	  }else if(aacCnt < AAC_CHECKSUM_MAX_SIZE){
   	  	  aacChecksumInfo[aacCnt++] = *AACPS_OUTPUT_CHK_SUM;
         }

        *AACPS_CHKSUM_ENABLE = 0;
   }
#endif // #ifdef AAC_DEBUG_ENABLE

   if(!ihdl->AAC_Decode_EOF){
#ifdef AAC_PLUS_PS_DECODE
      if(ihdl->fEnableARMDecoder){
         aacWriteDataToDSP(ihdl);
      }else
#endif // #ifdef AAC_PLUS_PS_DECODE
      autWriteDataToDSP((MHdl*)ihdl, (uint16*)AAC_MCU_WRITE_PTR, (uint16*)AAC_DSP_READ_PTR, AAC_PAGE_NUM, aacIncTime);
   }else{
      kal_int32 data_Cnt;
      data_Cnt = aacGetDSPDataCnt(ihdl, ihdl->AAC_DSP_Write_Idx);

#ifdef AAC_PLUS_PS_DECODE
         if( ihdl->fEnableARMDecoder)
            {
                ihdl->end_status = MEDIA_END;
         if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
            *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
               kal_prompt_trace( MOD_L1SPHISR, " AAC_L1AUDIO_END_STATE ");
            return;
            }
#endif // #ifdef AAC_PLUS_PS_DECODE
      if(ihdl->AAC_DSP_Data_Cnt == data_Cnt) ihdl->uEOF_TimeOutCnt++;
      if(ihdl->AAC_DSP_Data_Cnt >= data_Cnt)
         ihdl->AAC_DSP_Data_Cnt -= (ihdl->AAC_DSP_Data_Cnt - data_Cnt);
      else
         ihdl->AAC_DSP_Data_Cnt = 0;
      if(ihdl->AAC_DSP_Data_Cnt <= 0 || ihdl->uEOF_TimeOutCnt > 5){
         ihdl->end_status = MEDIA_END;
         if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
            *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
         kal_prompt_trace( MOD_L1SPHISR, " AAC_L1AUDIO_END_STATE ");
      }else
         aacWriteZero(ihdl);

      return;
   }

#ifdef AAC_PLUS_PS_DECODE
   if(ihdl->fEnableARMDecoder){
      MHdl *pstTmp = ihdl->pstMHdl;
      if( ihdl->mh.current_time >= ihdl->mh.stop_time ) {

         ihdl->end_status = MEDIA_STOP_TIME_UP;
         if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
            *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
         kal_prompt_trace( MOD_L1SPHISR, " AAC_L1AUDIO_STOP_TIME_UP_STATE ");
         return;
         
      }

      if( (hdl->GetDataCount(hdl) <= 1) && (hdl->GetDataCount(pstTmp) <= 1) && hdl->eof ) {

         if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
          ihdl->AAC_Decode_EOF  = true;

      }

   }else
#endif // #ifdef AAC_PLUS_PS_DECODE

   if( ihdl->mh.current_time >= ihdl->mh.stop_time ) {
      ihdl->end_status = MEDIA_STOP_TIME_UP;
      if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
         *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
      kal_prompt_trace( MOD_L1SPHISR, " AAC_L1AUDIO_STOP_TIME_UP_STATE ");
      return;
   }

   if( (ihdl->mh.GetDataCount((MHdl*)ihdl) <= 1 )&& ihdl->mh.eof) {
      ihdl->AAC_DSP_Data_Cnt = aacGetDSPDataCnt(ihdl, 0xFFFF);
      if(ihdl->AAC_DSP_Data_Cnt){
         ihdl->AAC_Decode_EOF = KAL_TRUE;
         aacWriteZero(ihdl);
         return;
      }else{
         ihdl->end_status = MEDIA_END;
         if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
            *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
         kal_prompt_trace( MOD_L1SPHISR, " AAC_L1AUDIO_END_STATE ");
      }
   }

#ifdef AAC_PLUS_PS_DECODE
   if(ihdl->fEnableARMDecoder){
      MHdl *pstTmp = ihdl->pstMHdl;
      aacHdlBufInfoSwap( hdl, pstTmp );
      mhdlDataRequest(hdl, ihdl->end_status);
      aacHdlBufInfoSwap( hdl, pstTmp );
   }
   else
#endif // #ifdef AAC_PLUS_PS_DECODE

   mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
}

static void aacOpenDevice( aacMediaHdl *ihdl , kal_bool DDFlag)
{
   MHdl *hdl = (MHdl *)ihdl;
   ihdl->end_status = MEDIA_NONE; // Clear for streaming case
   ihdl->mh.dsp_rb_base = 0;

   KT_StopAndWait();
   TONE_StopAndWait();
   
#ifdef AAC_DEBUG_ICE_ENABLE
  #if defined(MT6228)
   *(volatile unsigned short int *)0x801201B0 |= 0x30;
   *(volatile unsigned short int *)0x80120210 |= 0xF00;
  #endif
  #if defined(MT6229) || defined(MT6230)
   *(volatile unsigned short int *)0x801201A0 |= 0x03;
   *(volatile unsigned short int *)0x801201B0 |= 0xFC0;
   *(volatile unsigned short int *)0x801201D0 |= 0x0C;
   *(volatile unsigned short int *)0x801201E0 |= 0x3F;
  #endif
#endif // #ifdef AAC_DEBUG_ICE_ENABLE

   mhdlDisallowSleep( (MHdl*)ihdl );
   ASSERT(*AAC_MAIN_CONTROL == DSP_AAC_STATE_IDLE);
 // DSP colleague provided the following control procedure
   *AAC_MAIN_CONTROL = DSP_AAC_STATE_START;
   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );
#if defined(BSAC_DECODE)
   if( hdl->mediaType == MEDIA_FORMAT_BSAC){
      //*DP_AUDIO_CTRL2 |= (DP_AAC_CTRL_ASP | DP_PCM_R_DIS);  //Dior modify
      *DP_AUDIO_CTRL2 |= DP_PCM_R_DIS;
      *DP_AUDIO_FLEXI_CTRL |= (FLEXI_VBI_ON  | FLEXI_SD_ON);
      *BSAC_NUN_OF_SUB_FRAME = ihdl->uNumOfSubFrame; // BSAC
      *BSAC_LAYER_LENTH = ihdl->uLayerLength; // BSAC
      if(DDFlag)
         DSP_DynamicDownload( DDID_BSAC );
      AM_AudioPlaybackOn( ASP_TYPE_BSAC, dspSRConfigTab[ihdl->aac.sr_idx-3] );
   }else{
#endif // #if defined(BSAC_DECODE)

#if defined(AAC_PLUS_DECODE)
    
       if(ihdl->aac.sbrPresentFlag)
       {
#ifdef AAC_PLUS_PS_DECODE         
        if( (ihdl->aac.stereo != true) && (!fDisableAACPS))
        {
                 *DP_AUDIO_CTRL2 |= (DP_PCM_R_DIS);
                 DSP_DynamicDownload( DDID_AAC_PLUS_PS );
                 *AACPLUS_CNTROL_WORD |= AAC_PLUS_ON;
                 *AACPLUS_CNTROL_WORD |= AAC_CTRL_Flexible;
    
    
#if defined(AUD_TIME_STRETCH)
                AudioPP_Disable();
#endif // AUD_TIME_STRETCH
                 AM_AudioPlaybackOn( ASP_TYPE_AACPLUS_PS, dspSRConfigTab[ihdl->aac.sr_idx-3] );
        }
        else
#endif
        {
          *AACPLUS_CNTROL_WORD |= AAC_CTRL_Flexible;
          *AACPLUS_STATUS  = AAC_PLUS_INIT;
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6225)
          *DP_AUDIO_CTRL2 |= ( DP_AAC_ROM_CTRL_ASP | DP_PCM_R_DIS | DP_AAC_PLUS_CTRL_ASP);
          DSP_DynamicDownload( DDID_AAC_PLUS );
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
          *DP_AUDIO_CTRL2 |= (DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
          DSP_DynamicDownload( DDID_AAC_PLUS );
          *AACPLUS_CNTROL_WORD |= AAC_PLUS_ON;
#else // currently, SBR decoding only available on MT 6225, MT6226, MT6226M, MT6227, and MT6228
       #error Need DSP guys give the control word
#endif
    
#if defined(AUD_TIME_STRETCH)
          AudioPP_Disable();
#endif // AUD_TIME_STRETCH
          AM_AudioPlaybackOn( ASP_TYPE_AACPLUS, dspSRConfigTab[ihdl->aac.sr_idx-3] );
        }
       }else
    
#endif // AAC_PLUS_DECODE
       {
          *DP_AUDIO_CTRL2 |= (DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
          if(DDFlag)
             DSP_DynamicDownload( DDID_AAC );
          AM_AudioPlaybackOn( ASP_TYPE_AAC, dspSRConfigTab[ihdl->aac.sr_idx-3] );
       }

#if defined(BSAC_DECODE)
   }
#endif // #if defined(BSAC_DECODE)

   {
      kal_uint16 I;
      for( I = 0; ; I++ ) {
         if (DSP_AAC_STATE_PLAYING == *AAC_MAIN_CONTROL || ihdl->end_status != MEDIA_NONE){
            kal_trace( TRACE_STATE, L1AUDIO_RUNNING_STATE );
            break;
         }

         if (DSP_AAC_STATE_IDLE == *AAC_MAIN_CONTROL) {
            /* This is the case when AAC codec has started and encoutered an error,
               aacPlaybackHisr found this and set the state to STOP, then AAC codec
               set the state to IDLE. */
            break;
         }
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
   ihdl->mh.state = AAC_STATE_PLAY;
}

static void aacCloseDevice( aacMediaHdl *ihdl )
{
   MHdl *hdl = (MHdl *)ihdl;
   kal_uint32 I;

   for( I = 0; ; I++ ) {
      if( DSP_AAC_STATE_IDLE == *AAC_MAIN_CONTROL ) /* DSP returns to idle state */
         break;
      if( DSP_AAC_STATE_PLAYING == *AAC_MAIN_CONTROL ) {
         *AAC_MAIN_CONTROL = DSP_AAC_STATE_STOP;  /* give ABORT command to the DSP */
         kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
      }
      ASSERT_REBOOT( I < 80 );
      kal_sleep_task( 2 );
   }

#if defined(BSAC_DECODE)
   if( hdl->mediaType == MEDIA_FORMAT_BSAC){
       //*DP_AUDIO_CTRL2 &= ~(DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
       *DP_AUDIO_CTRL2 &= ~DP_PCM_R_DIS;
       *DP_AUDIO_FLEXI_CTRL &= ~(FLEXI_VBI_ON  | FLEXI_SD_ON);
       AM_AudioPlaybackOff( true );
   }else{
#endif // #if defined(BSAC_DECODE)

#if defined(AAC_PLUS_DECODE)
       if(ihdl->aac.sbrPresentFlag){
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6225)
          *DP_AUDIO_CTRL2 &= ~( DP_AAC_ROM_CTRL_ASP | DP_PCM_R_DIS | DP_AAC_PLUS_CTRL_ASP);
          AM_AudioPlaybackOff( true );
          if(*AACPLUS_CNTROL_WORD == AAC_CTRL_Flexible)
             *AACPLUS_CNTROL_WORD &= ~AAC_CTRL_Flexible;
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
          *DP_AUDIO_CTRL2 &= ~(DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
          AM_AudioPlaybackOff( true );
          *AACPLUS_CNTROL_WORD &= ~( AAC_CTRL_Flexible | AAC_PLUS_ON );
#else
       #error Need DSP guys give the control word
#endif
    
#if defined(AUD_TIME_STRETCH)
          AudioPP_Enable();
#endif  // AUD_TIME_STRETCH
       }else
#endif // AAC_PLUS_DECODE
        {
           *DP_AUDIO_CTRL2 &= ~(DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
           AM_AudioPlaybackOff( true );
        }

#if defined(BSAC_DECODE)
   }
#endif // #if defined(BSAC_DECODE)

   mhdlAllowSleep( (MHdl*)ihdl );
}

static Media_Status aacMFClose( MHdl *hdl )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;
   ASSERT( hdl != 0 && hdl->state != AAC_STATE_PLAY);

   if( hdl->handler != NULL )
      mhdlFinalize( hdl, DP_D2C_AAC );

//#if defined MP4_CODEC
   if(hdl->mediaType == MEDIA_FORMAT_M4A)
      freeWorkingMemM4A(hdl);
//#endif // MP4_CODEC

#ifdef AAC_PLUS_PS_DECODE
   if(ihdl->fEnableARMDecoder){
      med_free_ext_mem( (void **) &ihdl->pstMHdl->rb_base);

#if APM_SUPPORT
      if (ihdl->fUseTCMFromAPM) {
         ihdl->fUseTCMFromAPM = false;
         aacWorking_data = (kal_uint8 *)0;
         APM_Release_Buffer();
      }
      else
#endif
      {
         med_free_ext_mem( (void **) &aacWorking_data);
      }
   }
    // free audio ID for aacDecodeTask
   L1Audio_FreeAudioID( ihdl->aud_id_decoder );
   free_ctrl_buffer( ihdl->pstMHdl );
#endif // #ifdef AAC_PLUS_PS_DECODE

   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, hdl->mediaType );

#ifdef AAC_DEBUG_ENABLE
   if (_file_handle == 0)
      ASSERT(0);

   {
   	kal_uint32 cnt;
      for(cnt=0; cnt<aacCnt;){
         kal_sprintf((void*)_dbg_str, "%X\n\0", (kal_int32)aacChecksumInfo[cnt++]);
         FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
      }

   }

   FS_Close(_file_handle);
   _file_handle = 0;

#endif // #ifdef AAC_DEBUG_ENABLE

   return MEDIA_SUCCESS;
}

static void aacProgressiveSeek( aacMediaHdl *ihdl )
{
   /// Process cache table
   aacProcessCache(ihdl, 1);
   if((ihdl->AudioCacheTbl->valid_cache_number-1)!= 0){
      ihdl->mh.uSeekProgress = ihdl->AudioCacheTbl->current_cache_index * 100 / (ihdl->AudioCacheTbl->valid_cache_number-1);
      ihdl->mh.eSeekLastRet = MEDIA_SUCCESS;
   }else{
      ihdl->mh.uSeekProgress = 0;
      ihdl->mh.eSeekLastRet = MEDIA_SEEK_FAIL;
   }
}

static void aacMFSeek( MHdl *hdl, Media_Status *eSeekLastRet, kal_uint32 *uProgress )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   if(hdl->uGetDurProgress == 0){

      ihdl->fileOffset = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;


      autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );

      {   /* Parse AAC Header */
         if (aacSyncFirstFrame(ihdl)!=MEDIA_SUCCESS ){
            hdl->eSeekLastRet = MEDIA_BAD_FORMAT;
            return;
         }
         aacUpdateSR(ihdl);
      }
      ihdl->AudioCacheTbl->start_offset[0]=ihdl->fileOffset;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, hdl->mediaType, 0, ihdl->fileOffset );
   }

   aacProgressiveSeek(ihdl); // update eSeekLastRet, uSeekProgress & uCurSeekFrm

   *eSeekLastRet = hdl->eSeekLastRet;
   *uProgress = hdl->uSeekProgress;
}

static void aacMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   if( 100 == hdl->uGetDurProgress ){ // cache table finished
      *eLastRet = MEDIA_SUCCESS;
      *uProgress = 100;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, hdl->mediaType, MEDIA_SUCCESS, 100 );
      return;
   }

   {
      Media_Status eSeekLastRet;
      kal_uint32 uProgress;
      aacMFSeek( hdl, &eSeekLastRet, &uProgress ); // parse fixed frames
   }
   *eLastRet = hdl->eSeekLastRet; // last result
   {
      kal_uint32 uCurPos;
      ASSERT(ihdl->uFileSize != 0);
      uCurPos = ihdl->AudioCacheTbl->start_offset[ihdl->AudioCacheTbl->current_cache_index];
      hdl->uGetDurProgress = (kal_uint64)uCurPos * (kal_uint64)100 / (kal_uint64)ihdl->uFileSize;
      if(ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number -1 ))
         hdl->uGetDurProgress = 100;
   }

   *uProgress = hdl->uGetDurProgress;

   if( 100 == hdl->uGetDurProgress ){
      hdl->uSeekProgress = 0;
      hdl->start_time = 0;
      ihdl->fileOffset = 0;
   }
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, hdl->mediaType, *eLastRet, *uProgress );
}

static void aacMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, void *param )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   ASSERT(((uint32)ptr & 0x03) == 0 );   /* make sure 4-byte alignment */
   ihdl->AudioCacheTbl = (AudioCacheTable *)ptr;

   if(!ihdl->aac.sr_idx){
      autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );
      if((aacSyncFirstFrame( ihdl ))!=MEDIA_SUCCESS){
         ihdl->AudioCacheTbl->frames_per_cache = 100;
         if(!ihdl->AudioCacheTbl->valid_cache_number)
            ihdl->AudioCacheTbl->valid_cache_number = MAX_CACHE_ENTRIES;
         return;
      }
   }

   if(ihdl->uFileSize <= (1 * 1024 * 1024)){ // 1MB
      kal_uint64 uFrames;
      uFrames = (kal_uint64)ihdl->uFileSize * (kal_uint64) sampleRateTab[ihdl->aac.sr_idx] / 40960000; //(40000 * 1024)
      ihdl->AudioCacheTbl->frames_per_cache = uFrames;
   }else{ // update frame per cache according to file size
       kal_uint32 uSize;
       uSize = ihdl->uFileSize / (50 * 1024 * 1024); // 50MB
       ihdl->AudioCacheTbl->frames_per_cache = (uSize * 1000) + 1000;
   }

   if(!ihdl->AudioCacheTbl->valid_cache_number)
      ihdl->AudioCacheTbl->valid_cache_number = MAX_CACHE_ENTRIES;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SET_CACHE_TBL, hdl->mediaType );
}

// Match next ADTS fixed header based on current file offset
static kal_bool aacReachNextFrame(aacMediaHdl *ihdl)
{
	uint32 nextFrameOffset = 0;

	while(1)
	{
		if( nextFrameOffset > MAX_FRAME_CHECK_LEN || ihdl->mh.eof)
			return KAL_FALSE;

		if(autGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, ihdl->fileOffset, 4, &ihdl->aac.bHeaderTmp[0]) != 4)
		   return KAL_FALSE;

      ihdl->aac.bHeaderTmp[3] &= 0xF0;
		if (kal_mem_cmp(ihdl->aac.bADTSFixedHeader, ihdl->aac.bHeaderTmp, 4)==0)
		   return KAL_TRUE;

		ihdl->fileOffset++;
		nextFrameOffset++;
	}
}

static Media_Status aacMFPlayFile( MHdl *hdl )
{
   kal_uint32 buf_len;
   Media_Status ret;
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   if(hdl->start_time || hdl->current_time || ihdl->aac.bIsTypeADIF){
      ihdl->fileOffset = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;
   }

   ihdl->AAC_Decode_EOF = KAL_FALSE;
   ihdl->uEOF_TimeOutCnt = 0;
   ihdl->AAC_DSP_Data_Cnt = 0x7FFFFFFF;
   ihdl->wDspReadIdx = 0xFFFF;

   autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );
   ihdl->uID3V2Size = ihdl->fileOffset;

   {   /* Parse AAC Header */
      if ((ret=aacSyncFirstFrame(ihdl))!=MEDIA_SUCCESS )
         return ret;
      aacUpdateSR(ihdl);
   }
   ihdl->uCurFrame = (kal_uint64)hdl->start_time * 1000000 / ihdl->frameDur;
   if(ihdl->AudioCacheTbl != 0)
      ihdl->AudioCacheTbl->start_offset[0] = ihdl->fileOffset;
   if(ihdl->aac.bIsTypeADTS){
      if(!hdl->fStoreFileOffset){
         FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
         if ((aacSeek(ihdl, true)==KAL_FALSE) || (ihdl->fileOffset >= ihdl->uFileSize)) // update file offset at start frame
            return MEDIA_SEEK_EOF;
      }else{
          ihdl->resumeFrameOffset = audResumeInfo.uResumeFrameOffset;
          ihdl->fileOffset = ihdl->resumeFrameOffset;
          if (aacReachNextFrame(ihdl)==KAL_FALSE){
             if(hdl->eof){
                mhdlException(hdl, MEDIA_END);
                return MEDIA_SUCCESS;
             }else{
                 return MEDIA_BAD_FORMAT;
                }
          }
          ihdl->resumeFrameOffset = ihdl->fileOffset;
          audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
       }
   }else{
       ihdl->uCurFrame = 0;
       hdl->current_time = hdl->start_time = 0;
   }

#ifdef AAC_PLUS_PS_DECODE
   if( !ihdl->aac.stereo && ihdl->aac.sbrPresentFlag && (!fDisableAACPS)){
      ihdl->fEnableARMDecoder = true;
      hdl->mediaType = MEDIA_FORMAT_AAC_PLUS_V2;
   }

   if(ihdl->fEnableARMDecoder){
      kal_uint8  *pBuf;
      kal_uint32 uMBufLen;
      MHdl *pstTmp = ihdl->pstMHdl;

      if(!aacWorking_data){
#if APM_SUPPORT
         aacWorking_data = APM_Allocate_Buffer((MAX_NUM_CHANNELS*SAMPLES_PER_FRAME*2) + MAINinternStaticSize + MAINexternStaticSize + MAINinternDynamicSize);
         if (aacWorking_data != NULL)
         {
            ihdl->fUseTCMFromAPM = true;
         }
         else
#endif
         {
            aacWorking_data = (kal_uint8 *)med_alloc_ext_mem((MAX_NUM_CHANNELS*SAMPLES_PER_FRAME*2) + MAINinternStaticSize + MAINexternStaticSize + MAINinternDynamicSize);
         }

         pstTmp->rb_base = (kal_uint8 *)med_alloc_ext_mem(AAC_OUT_BUF_SIZE);
      }

      pstTmp->rb_size = AAC_OUT_BUF_SIZE;
      pstTmp->read = 0;
      pstTmp->write = 0;
      pstTmp->eof = 0;
      hdl->eof = 0;

      ihdl->mh.GetWriteBuffer( hdl, &pBuf, &uMBufLen); // Len in byte
      uMBufLen = autGetBytesFromFile((MHdl*)hdl, ihdl->pstFSAL, ihdl->fileOffset, uMBufLen, pBuf);
      ihdl->mh.WriteDataDone( hdl, uMBufLen );
      // Decoder's input buffer initialization
      AACBUFFER.AAC_bitstreams_Buffer = hdl->rb_base;
      AACBUFFER.AAC_bitstreams_Buffer_W = (kal_int32)hdl->write + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
      AACBUFFER.AAC_bitstreams_Buffer_R =  (kal_int32)hdl->read + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
      // Decoder's output buffer initialization
      AACBUFFER.AAC_Media_Buffer = (kal_uint16 *)pstTmp->rb_base;
      AACBUFFER.AAC_Media_Buffer_W = (kal_int32)pstTmp->write+ (kal_int32)AACBUFFER.AAC_Media_Buffer;
      AACBUFFER.AAC_Media_Buffer_R = (kal_int32)pstTmp->read+(kal_int32)AACBUFFER.AAC_Media_Buffer;
      AACBUFFER.AAC_Media_Buffer_len = AAC_OUT_BUF_SIZE;

      rawDecoder = aac_init(&AACBUFFER,aacWorking_data, AAC_OUT_BUF_SIZE);
      if( rawDecoder == NULL){
         ihdl->fDecoderError = true;
         return MEDIA_ERROR;
      }

      do{
         kal_uint32 AAC_REPORT;
         AAC_REPORT = AAC_Decode_frame( rawDecoder,&AACBUFFER,aacWorking_data, hdl->rb_size);
         if( AAC_REPORT!= 0 &&  AAC_REPORT != 5){
            ihdl->fDecoderError = true;
            return MEDIA_ERROR;
         }
         if(AAC_REPORT == 5){
            return MEDIA_SEEK_EOF;
         }
         hdl->read = (kal_int32)AACBUFFER.AAC_bitstreams_Buffer_R - (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
         pstTmp->write = (kal_int32)AACBUFFER.AAC_Media_Buffer_W - (kal_int32)AACBUFFER.AAC_Media_Buffer;
         ihdl->mh.GetWriteBuffer((MHdl*)pstTmp, &pBuf, &uMBufLen);
      }while(uMBufLen >= AAC_MAX_OUT_LEN);
   }else

#endif // #ifdef AAC_PLUS_PS_DECODE
   {  /* Fill Media Buffer */
      kal_uint8 *pBuf;
      kal_int32 num_bytes;
      hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
      num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
      if(num_bytes < 0) return MEDIA_READ_FAIL;
      ihdl->fileOffset += num_bytes;
      hdl->WriteDataDone( hdl, num_bytes );
   }
   aacOpenDevice(ihdl, true);

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, hdl->mediaType);

   return MEDIA_SUCCESS;
}

static Media_Status aacMFStop( MHdl *hdl )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;
#ifdef AAC_PLUS_PS_DECODE
   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
#endif // #ifdef AAC_PLUS_PS_DECODE
   if( hdl->state == AAC_STATE_PAUSE || hdl->state == AAC_STATE_IDLE ){
#ifdef AAC_PLUS_PS_DECODE
      kal_give_sem( WAVsema );
#endif // #ifdef AAC_PLUS_PS_DECODE
      return MEDIA_SUCCESS;
   }

   ihdl->end_status = MEDIA_TERMINATED;
   aacCloseDevice( ihdl );

   hdl->state = AAC_STATE_IDLE;
#ifdef AAC_PLUS_PS_DECODE
   kal_give_sem( WAVsema );
#endif // #ifdef AAC_PLUS_PS_DECODE
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status aacMFPause( MHdl *hdl )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;
#ifdef AAC_PLUS_PS_DECODE
   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
#endif // #ifdef AAC_PLUS_PS_DECODE
   ASSERT( hdl->state == AAC_STATE_PLAY );

   if( ihdl->aac.bIsTypeADTS == KAL_FALSE ){
#ifdef AAC_PLUS_PS_DECODE
      kal_give_sem( WAVsema );
#endif // #ifdef AAC_PLUS_PS_DECODE
      return MEDIA_UNSUPPORTED_OPERATION;
   }
   ihdl->end_status = MEDIA_TERMINATED;

   aacCloseDevice( ihdl );
   hdl->state = AAC_STATE_PAUSE;
#ifdef AAC_PLUS_PS_DECODE
   kal_give_sem( WAVsema );
#endif // #ifdef AAC_PLUS_PS_DECODE
   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status aacMFResumeFile( MHdl *hdl )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   if( hdl->state != AAC_STATE_PAUSE )
      return MEDIA_FAIL;

   if(ihdl->AAC_Decode_EOF || hdl->eof){
      mhdlException(hdl, MEDIA_END);
      return MEDIA_SUCCESS;
   }

   hdl->read = 0;
   hdl->write = 0;
   hdl->eof = false;
   hdl->waiting = false;
   hdl->start_time = hdl->current_time;
   ihdl->fileOffset = ihdl->resumeFrameOffset;
   ihdl->wDspReadIdx = 0xFFFF;

   if(autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, 4, &ihdl->aac.bHeaderTmp[0]) == 4){
      ihdl->aac.bHeaderTmp[3] &= 0xF0;
      if (kal_mem_cmp(ihdl->aac.bADTSFixedHeader, ihdl->aac.bHeaderTmp, 4)!=0) {
         if (aacReachNextFrame(ihdl)==KAL_FALSE){
            if(hdl->eof){
               mhdlException(hdl, MEDIA_END);
               return MEDIA_SUCCESS;
            }else{
                return MEDIA_BAD_FORMAT;
               }
         }
         ihdl->resumeFrameOffset = ihdl->fileOffset;
         audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
      }

#ifdef AAC_PLUS_PS_DECODE
      if(ihdl->fEnableARMDecoder){
         kal_uint8  *pBuf;
         kal_uint32 uMBufLen;
         MHdl *pstTmp = ihdl->pstMHdl;

         pstTmp->rb_size = AAC_OUT_BUF_SIZE;
         pstTmp->read = 0;
         pstTmp->write = 0;

         ihdl->mh.GetWriteBuffer(hdl, &pBuf, &uMBufLen); // Len in byte
         uMBufLen = autGetBytesFromFile((MHdl*)hdl, ihdl->pstFSAL, ihdl->fileOffset, uMBufLen, pBuf);
         ihdl->mh.WriteDataDone( hdl, uMBufLen );
         // Decoder's input buffer initialization
         AACBUFFER.AAC_bitstreams_Buffer = hdl->rb_base;
         AACBUFFER.AAC_bitstreams_Buffer_W = (kal_int32)hdl->write + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
         AACBUFFER.AAC_bitstreams_Buffer_R =  (kal_int32)hdl->read + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
         // Decoder's output buffer initialization
         AACBUFFER.AAC_Media_Buffer = (kal_uint16 *)pstTmp->rb_base;
         AACBUFFER.AAC_Media_Buffer_W = (kal_int32)pstTmp->write+ (kal_int32)AACBUFFER.AAC_Media_Buffer;
         AACBUFFER.AAC_Media_Buffer_R = (kal_int32)pstTmp->read+(kal_int32)AACBUFFER.AAC_Media_Buffer;
         AACBUFFER.AAC_Media_Buffer_len = AAC_OUT_BUF_SIZE;

         rawDecoder = aac_init(&AACBUFFER,aacWorking_data, AAC_OUT_BUF_SIZE);
         if( rawDecoder == NULL){
            ihdl->fDecoderError = true;
            return MEDIA_ERROR;
         }
         do{
            kal_uint32 AAC_REPORT;
            AAC_REPORT = AAC_Decode_frame( rawDecoder,&AACBUFFER,aacWorking_data, hdl->rb_size);
            if( AAC_REPORT!= 0 &&  AAC_REPORT != 5){
               ihdl->fDecoderError = true;
               return MEDIA_ERROR;
            }
            if(AAC_REPORT == 5){
               return MEDIA_SEEK_EOF;
            }
            hdl->read = (kal_int32)AACBUFFER.AAC_bitstreams_Buffer_R - (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
            pstTmp->write = (kal_int32)AACBUFFER.AAC_Media_Buffer_W - (kal_int32)AACBUFFER.AAC_Media_Buffer;
            ihdl->mh.GetWriteBuffer((MHdl*)pstTmp, &pBuf, &uMBufLen);
         }while(uMBufLen >= AAC_MAX_OUT_LEN);
      }else

#endif // #ifdef AAC_PLUS_PS_DECODE

      {  /* file Media Buffer */
         kal_uint8 *pBuf;
         kal_int32 num_bytes;
         kal_uint32 buf_len;
         hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
         num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
         if(num_bytes < 0) return MEDIA_READ_FAIL;
         ihdl->fileOffset += num_bytes;
         hdl->WriteDataDone(hdl, num_bytes);
      }
      aacOpenDevice(ihdl, false);
   }else{
      mhdlException(hdl, MEDIA_END);
    }

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Event aacMFProcess( MHdl *hdl, Media_Event event )
{
   aacMediaHdl *ihdl = (aacMediaHdl *) hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch(event)
   {
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
         if( hdl->state == AAC_STATE_PLAY )
            aacCloseDevice( ihdl );
         hdl->state = AAC_STATE_IDLE;
         return event;
      case MEDIA_ERROR:
      case MEDIA_DECODER_UNSUPPORT:
         kal_trace( TRACE_ERROR, L1AUDIO_DSP_ERROR );
         if( hdl->state == AAC_STATE_PLAY )
            aacCloseDevice( ihdl );
         hdl->state = AAC_STATE_IDLE;
         return event;

      case MEDIA_DATA_REQUEST:

#ifdef AAC_PLUS_PS_DECODE
         if(ihdl->fEnableARMDecoder){
            kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
            L1Audio_SetEvent( ihdl->aud_id_decoder, hdl );
            kal_give_sem( WAVsema );
            if(ihdl->isStreaming)
               return MEDIA_DATA_REQUEST;
         }else
#endif // #ifdef AAC_PLUS_PS_DECODE
         {
            if(ihdl->isStreaming)
               return MEDIA_DATA_REQUEST;

//#if defined MP4_CODEC
            if(hdl->mediaType == MEDIA_FORMAT_M4A)
            {
               kal_uint8 *pBuf;
               kal_uint32 buf_len;
               kal_uint32 num_bytes, cnt = 0;
               MP4_Parser_Status eMP4Status;
               do{
                  hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
                  if(buf_len == 0 || hdl->eof) break;
                  eMP4Status = MP4_Audio_Read(ihdl->pstMp4Parser_M4A, pBuf, buf_len, &num_bytes);
                  if(eMP4Status == MP4_PARSER_READ_EOF)
                     hdl->DataFinished(hdl);
                  if((eMP4Status != MP4_PARSER_OK) && (eMP4Status != MP4_PARSER_READ_EOF))
                     return MEDIA_READ_ERROR;
                  hdl->WriteDataDone( hdl, num_bytes );
               }while(++cnt < 2);
               hdl->waiting = KAL_FALSE;
               return MEDIA_NONE;
            }
//#endif // MP4_CODEC
            {
               kal_uint8 *pBuf;
               kal_uint32 buf_len;
               kal_int32 num_bytes, cnt = 0;
               do{
                  hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
                  if(buf_len == 0 || hdl->eof) break;
                  num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
                  if(num_bytes < 0) return MEDIA_READ_ERROR;
                  ihdl->fileOffset += num_bytes;
                  hdl->WriteDataDone( hdl, num_bytes );
               }while(++cnt < 2);
            }
            hdl->waiting = KAL_FALSE;
         }

         {
            kal_uint64 uRatio;
            FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
            uRatio = (kal_uint64)ihdl->resumeFrameOffset * 100 / (kal_uint64)ihdl->uFileSize;
            if( uRatio > ihdl->uDurUpdateThd ){
               if(ihdl->uDurUpdateThd != 100)
                  ihdl->uDurUpdateThd += 20;
               return MEDIA_UPDATE_DUR;
            }
         }
            
         return MEDIA_NONE;

#if !defined(__PRODUCTION_RELEASE__)
      default:
         ASSERT(0); // should never reach here
#endif // #if !defined(__PRODUCTION_RELEASE__)
   }
   return MEDIA_NONE;
}

static Media_Status aacMFPlayStrm( MHdl *hdl )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;
   ihdl->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if(ihdl->pstFSAL == NULL)
      return MEDIA_FAIL;

   ihdl->fileOffset = 0;
   ihdl->end_status = MEDIA_NONE;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->current_time = hdl->start_time;

   ihdl->AAC_Decode_EOF = KAL_FALSE;
   ihdl->uEOF_TimeOutCnt = 0;
   ihdl->AAC_DSP_Data_Cnt = 0x7FFFFFFF;
   ihdl->wDspReadIdx = 0xFFFF;

   {
      FSAL_Status eFSALStatus;
      FSAL_Direct_SetRamFileSize(ihdl->pstFSAL, hdl->rb_size);
      eFSALStatus = FSAL_Open(ihdl->pstFSAL, hdl->rb_base, FSAL_ROMFILE);
      ASSERT(eFSALStatus == FSAL_OK);
   }

   {
      Media_Status ret;
      if ((ret=aacSyncFirstFrame(ihdl))!=MEDIA_SUCCESS){
         free_ctrl_buffer(ihdl->pstFSAL);
         return ret;
      }
      aacUpdateSR(ihdl);
   }
   ihdl->uCurFrame = (kal_uint64)hdl->start_time * 1000000 / ihdl->frameDur;

#ifdef AAC_PLUS_PS_DECODE
   if( !ihdl->aac.stereo && ihdl->aac.sbrPresentFlag && (!fDisableAACPS)){
      ihdl->fEnableARMDecoder = true;
      hdl->mediaType = MEDIA_FORMAT_AAC_PLUS_V2;
   }

   if(ihdl->fEnableARMDecoder){
      kal_uint8  *pBuf;
      kal_uint32 uMBufLen;
      MHdl *pstTmp = ihdl->pstMHdl;

      if(!aacWorking_data){
#if APM_SUPPORT
         aacWorking_data = APM_Allocate_Buffer((MAX_NUM_CHANNELS*SAMPLES_PER_FRAME*2) + MAINinternStaticSize + MAINexternStaticSize + MAINinternDynamicSize);
         if (aacWorking_data != NULL)
         {
            ihdl->fUseTCMFromAPM = true;
         }
         else
#endif
         {
            aacWorking_data = (kal_uint8 *)med_alloc_ext_mem((MAX_NUM_CHANNELS*SAMPLES_PER_FRAME*2) + MAINinternStaticSize + MAINexternStaticSize + MAINinternDynamicSize);
         }
         
         pstTmp->rb_base = (kal_uint8 *)med_alloc_ext_mem(AAC_OUT_BUF_SIZE);
      }

      pstTmp->rb_size = AAC_OUT_BUF_SIZE;
      pstTmp->read = 0;
      pstTmp->write = 0;

      // Decoder's input buffer initialization
      AACBUFFER.AAC_bitstreams_Buffer = hdl->rb_base;
      AACBUFFER.AAC_bitstreams_Buffer_W = (kal_int32)hdl->write + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
      AACBUFFER.AAC_bitstreams_Buffer_R =  (kal_int32)hdl->read + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
      // Decoder's output buffer initialization
      AACBUFFER.AAC_Media_Buffer = (kal_uint16 *)pstTmp->rb_base;
      AACBUFFER.AAC_Media_Buffer_W = (kal_int32)pstTmp->write+ (kal_int32)AACBUFFER.AAC_Media_Buffer;
      AACBUFFER.AAC_Media_Buffer_R = (kal_int32)pstTmp->read+(kal_int32)AACBUFFER.AAC_Media_Buffer;
      AACBUFFER.AAC_Media_Buffer_len = AAC_OUT_BUF_SIZE;

      rawDecoder = aac_init(&AACBUFFER,aacWorking_data, AAC_OUT_BUF_SIZE);
      if( rawDecoder == NULL){
         ihdl->fDecoderError = true;
         free_ctrl_buffer(ihdl->pstFSAL);
         return MEDIA_ERROR;
      }

      do{
         kal_uint32 AAC_REPORT;
         AAC_REPORT = AAC_Decode_frame( rawDecoder,&AACBUFFER,aacWorking_data, hdl->rb_size);
         if( AAC_REPORT!= 0 &&  AAC_REPORT != 5){
            ihdl->fDecoderError = true;
            free_ctrl_buffer(ihdl->pstFSAL);
            return MEDIA_ERROR;
         }
         if(AAC_REPORT == 5){
            free_ctrl_buffer(ihdl->pstFSAL);
            return MEDIA_SEEK_EOF;
         }
         hdl->read = (kal_int32)AACBUFFER.AAC_bitstreams_Buffer_R - (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
         pstTmp->write = (kal_int32)AACBUFFER.AAC_Media_Buffer_W - (kal_int32)AACBUFFER.AAC_Media_Buffer;
         ihdl->mh.GetWriteBuffer((MHdl*)pstTmp, &pBuf, &uMBufLen);
      }while(uMBufLen >= AAC_MAX_OUT_LEN);
   }

#endif // #ifdef AAC_PLUS_PS_DECODE

   aacOpenDevice(ihdl , true);
   free_ctrl_buffer(ihdl->pstFSAL);
   ihdl->pstFSAL = NULL;

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_STREAM, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static kal_bool aacReachNextFrameStrm( MHdl *hdl )
{
   kal_uint32 cnt, uDataCount;
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   uDataCount = hdl->GetDataCount(hdl); // number of bytes in ring buffer

   if (uDataCount<4)
      return KAL_FALSE;

   for (cnt=0; cnt<uDataCount-3; cnt++) {
      kal_int32 k;
      for(k=0; k<4; k++){
         kal_uint32 uLocation = hdl->read+k+cnt;
         if ((kal_int32)uLocation >= hdl->rb_size)
            uLocation -= hdl->rb_size;
         ihdl->aac.bHeaderTmp[k] = hdl->rb_base[uLocation];
      }
      ihdl->aac.bHeaderTmp[3] &= 0xF0;
      if (kal_mem_cmp(ihdl->aac.bADTSFixedHeader, ihdl->aac.bHeaderTmp, 4)==0) {
         if (cnt&0x01) // to avoid odd read index
            cnt--;
         hdl->read += cnt;
         if (hdl->read >= hdl->rb_size)
            hdl->read -= hdl->rb_size;
         return KAL_TRUE;
      }
   }
   return KAL_FALSE;
}

static Media_Status aacMFResumeStrm( MHdl *hdl )
{
   aacMediaHdl *handle = (aacMediaHdl *)hdl;

   ASSERT(hdl->state == AAC_STATE_PAUSE);

   hdl->waiting = false;

   if(aacReachNextFrameStrm(hdl)==KAL_FALSE)
      return MEDIA_BAD_FORMAT;

#ifdef AAC_PLUS_PS_DECODE
      if(handle->fEnableARMDecoder){
         kal_uint8  *pBuf;
         kal_uint32 uMBufLen;
         MHdl *pstTmp = handle->pstMHdl;

         rawDecoder = aac_init(&AACBUFFER,aacWorking_data, AAC_OUT_BUF_SIZE);
         if( rawDecoder == NULL){
            handle->fDecoderError = true;
            return MEDIA_ERROR;
         }
         do{
            kal_uint32 AAC_REPORT;
            AAC_REPORT = AAC_Decode_frame( rawDecoder,&AACBUFFER,aacWorking_data, hdl->rb_size);
            if( AAC_REPORT!= 0 &&  AAC_REPORT != 5){
               handle->fDecoderError = true;
               return MEDIA_ERROR;
            }
            if(AAC_REPORT == 5){
               return MEDIA_SEEK_EOF;
            }
            hdl->read = (kal_int32)AACBUFFER.AAC_bitstreams_Buffer_R - (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
            pstTmp->write = (kal_int32)AACBUFFER.AAC_Media_Buffer_W - (kal_int32)AACBUFFER.AAC_Media_Buffer;
            handle->mh.GetWriteBuffer((MHdl*)pstTmp, &pBuf, &uMBufLen);
         }while(uMBufLen >= AAC_MAX_OUT_LEN);
      }

#endif // #ifdef AAC_PLUS_PS_DECODE

   aacOpenDevice( handle , false);
   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );
   return MEDIA_SUCCESS;
}

kal_uint32 aacMFGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur;
   aacMediaHdl *ihdl = (aacMediaHdl *) hdl;
   ASSERT(ihdl->frameDur != 0);
   ASSERT(ihdl->AudioCacheTbl != 0);

   if(ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number-1)){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->total_frame * ihdl->frameDur / 1000000;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR_F, hdl->mediaType, uDur );
      return uDur;
   }

   if(ihdl->AudioCacheTbl->current_cache_index){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->accumulated_frames[ihdl->AudioCacheTbl->current_cache_index-1]*ihdl->frameDur/1000000;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR, hdl->mediaType, uDur );
      return uDur;
   }
   return 0;
}

kal_uint32 aacfMFGetTotalDuration( MHdl *hdl )
{
   kal_uint32 uDur;
   aacMediaHdl *ihdl = (aacMediaHdl *) hdl;
   ASSERT(ihdl->frameDur != 0);
   ASSERT(ihdl->AudioCacheTbl != 0);

// cache table finished
   if(ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number-1)){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->total_frame * ihdl->frameDur / 1000000;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR_F, hdl->mediaType, uDur );
      return uDur;
   }
   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);

   if (ihdl->resumeFrameOffset <= ihdl->uID3V2Size)
      uDur = 0;
   else
      uDur = (kal_uint64)hdl->current_time * (kal_uint64)(ihdl->uFileSize - ihdl->uID3V2Size) / (kal_uint64)(ihdl->resumeFrameOffset - ihdl->uID3V2Size);

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_TOTAL_DUR, hdl->mediaType, uDur );
   return uDur;
}

#if defined AAC_PLUS_PS_DECODE
static void aacDecodeTask( void *data )
{
   MHdl *hdl = (MHdl *)data;
   aacMediaHdl *ihdl = (aacMediaHdl *) hdl;
   MHdl *pstTmp = ihdl->pstMHdl;

   if( ihdl->end_status == MEDIA_TERMINATED )
      return;

   ASSERT( ihdl->fEnableARMDecoder );
   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
   if( hdl->state != AAC_STATE_PLAY ){
      hdl->waiting = KAL_FALSE;
      kal_give_sem( WAVsema );
      return;
   }

   {
      kal_uint8  *pBuf;
      kal_uint32 uMBufLen;

      if(!ihdl->isStreaming){      
//#if defined MP4_CODEC
         if(hdl->mediaType == MEDIA_FORMAT_M4A){
            kal_uint8 *pBuf;
            kal_uint32 buf_len;
            kal_uint32 num_bytes, cnt = 0;
            MP4_Parser_Status eMP4Status;
            do{
               hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
               if(buf_len == 0 || hdl->eof) break;
               eMP4Status = MP4_Audio_Read(ihdl->pstMp4Parser_M4A, pBuf, buf_len, &num_bytes);
               if(eMP4Status == MP4_PARSER_READ_EOF)
                  hdl->DataFinished(hdl);
               if((eMP4Status != MP4_PARSER_OK) && (eMP4Status != MP4_PARSER_READ_EOF)){
                  ihdl->fDecoderError = true;
                  hdl->waiting = KAL_FALSE;
                  kal_give_sem( WAVsema );
                  return;
               }
               hdl->WriteDataDone( hdl, num_bytes );
            }while(++cnt < 2);
         }else
//#endif // MP4_CODEC
         {
            hdl->GetWriteBuffer(hdl, &pBuf, &uMBufLen); // Len in byte
            while((kal_int32)(uMBufLen >= 1) && !hdl->eof){
               uMBufLen = autGetBytes(hdl, ihdl->pstFSAL, uMBufLen, pBuf);
               if((kal_int32)uMBufLen < 0){
                  ihdl->fDecoderError = true;
                  hdl->waiting = KAL_FALSE;
                  kal_give_sem( WAVsema );
                  return;
               }
               ihdl->mh.WriteDataDone( hdl, uMBufLen );
               hdl->GetWriteBuffer(hdl, &pBuf, &uMBufLen);
         
            }
         }      
      }

      AACBUFFER.AAC_bitstreams_Buffer_W = (kal_int32)(hdl->write) + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
      uMBufLen = (kal_uint32)ihdl->mh.GetFreeSpace(pstTmp); // output buffer

      if( !pstTmp->eof ){
         while(uMBufLen >= AAC_MAX_OUT_LEN){
            kal_uint32 uInReadIdx = (kal_uint32)hdl->read;
            kal_uint32 uTmp, savedMask;
            kal_uint32 AAC_REPORT;
	         kal_int32 R_ptr, W_ptr, data_remain, data_remain_prev = 0;

            uMBufLen = (kal_uint32)hdl->GetDataCount(hdl);
            if( (uMBufLen <  0x380) && (!hdl->eof))
            { break; }

            if( hdl->eof ){
	            R_ptr = AACBUFFER.AAC_bitstreams_Buffer_R;
	            W_ptr = AACBUFFER.AAC_bitstreams_Buffer_W;
               data_remain_prev = W_ptr - R_ptr;
               if( data_remain_prev < 0)
                  data_remain_prev += AAC_OUT_BUF_SIZE;
            }
            AAC_REPORT =  AAC_Decode_frame( rawDecoder,&AACBUFFER,aacWorking_data, hdl->rb_size);
            if( AAC_REPORT!= 0 &&  AAC_REPORT != 5){
               ihdl->fDecoderError = true;
               break;
            }

            uTmp = (kal_uint32)((kal_int32)AACBUFFER.AAC_bitstreams_Buffer_R - (kal_int32)AACBUFFER.AAC_bitstreams_Buffer);
            ASSERT((kal_int32)uTmp >= 0);
            hdl->read = uTmp;
            if(uInReadIdx<=uTmp){
               uInReadIdx = uTmp - uInReadIdx;
            }else{
               uInReadIdx = (hdl->rb_size - uInReadIdx) + uTmp;
            }
            pstTmp->write = (kal_int32)AACBUFFER.AAC_Media_Buffer_W - (kal_int32)AACBUFFER.AAC_Media_Buffer;
            savedMask = SaveAndSetIRQMask();
            ihdl->fileOffset += uInReadIdx;
            RestoreIRQMask(savedMask);
            uMBufLen = (kal_uint32)ihdl->mh.GetFreeSpace(pstTmp);

            if( hdl->eof ){
	            R_ptr = AACBUFFER.AAC_bitstreams_Buffer_R;
	            W_ptr = AACBUFFER.AAC_bitstreams_Buffer_W;
               data_remain = W_ptr - R_ptr;
               if( data_remain < 0)
                  data_remain += AAC_OUT_BUF_SIZE;

               if( data_remain <= 1   ||  data_remain >= data_remain_prev ){
                  pstTmp->eof = true;
                  hdl->read = hdl->write;
                  break;
               }
            }

            if(AAC_REPORT == 5){
               break;
            }

         }
      }
   }

   hdl->waiting = KAL_FALSE;
   kal_give_sem( WAVsema );
}
#endif // #if defined AAC_PLUS_PS_DECODE

#ifdef AAC_DEBUG_ENABLE
extern kal_uint16 *L1audio_GetFileName(void);
#endif // #ifdef AAC_DEBUG_ENABLE

MHdl *AAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   aacMediaHdl *ihdl;
#ifdef AAC_DEBUG_ENABLE
   kal_uint16 *fileName;
#endif // #ifdef AAC_DEBUG_ENABLE

   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   hdl = (MHdl *) ihdl;
   if( handler != NULL )
      mhdlInit( hdl, DP_D2C_AAC, aacHisr );
   else
      mhdlInitEx( hdl, DP_D2C_AAC, aacHisr );

   hdl->handler   = handler;
   hdl->state     = AAC_STATE_IDLE;
   hdl->mediaType = MEDIA_FORMAT_AAC;
   ihdl->pstFSAL  = pstFSAL;
   hdl->Close     = aacMFClose;
   hdl->Pause     = aacMFPause;
   hdl->Stop      = aacMFStop;
   hdl->Process   = aacMFProcess;

   hdl->BuildCache    = aacMFBuildCache;
   hdl->SetCacheTbl  = aacMFSetCacheTbl;
   hdl->GetCacheDuration = aacMFGetCacheDur;
   hdl->GetTotalDuration = aacfMFGetTotalDuration;

   if(pstFSAL != NULL){
      ihdl->isStreaming = false;
      hdl->Play = aacMFPlayFile;
      hdl->Resume = aacMFResumeFile;
      kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, MEDIA_FORMAT_AAC );
   } else {
       ihdl->isStreaming = true;
       hdl->Play = aacMFPlayStrm;
       hdl->Resume = aacMFResumeStrm;
       kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_AAC );
   }
#if defined AAC_PLUS_PS_DECODE // register audio ID and event handler for aacDecodeTask
   ihdl->aud_id_decoder = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id_decoder, aacDecodeTask );
   ihdl->pstMHdl = (MHdl*)get_ctrl_buffer( sizeof(MHdl) );
   memset(ihdl->pstMHdl, 0, sizeof(MHdl));
   mhdlInitEx( ihdl->pstMHdl, DP_D2C_AAC, aacHisr );
#endif // #if defined AAC_PLUS_PS_DECODE
   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FILE_SIZE, MEDIA_FORMAT_AAC, ihdl->uFileSize);

#ifdef AAC_DEBUG_ENABLE
   fileName = L1audio_GetFileName();
   kal_wsprintf( _file_name, "%w.txt", fileName);
   _file_handle = FS_Open((const WCHAR *)_file_name, FS_CREATE);
   aacCnt = 0xFFFFFFFF;
#endif // #ifdef AAC_DEBUG_ENABLE

   return hdl;
}
#if defined(BSAC_DECODE)

MHdl *BSAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   aacMediaHdl *ihdl;

   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   hdl = (MHdl *) ihdl;
   if( handler != NULL )
      mhdlInit( hdl, DP_D2C_AAC, aacHisr );
   else
      mhdlInitEx( hdl, DP_D2C_AAC, aacHisr );

   hdl->handler   = handler;
   hdl->state     = AAC_STATE_IDLE;
   hdl->mediaType = MEDIA_FORMAT_BSAC;
   ihdl->pstFSAL  = pstFSAL;
   hdl->Close     = aacMFClose;
   hdl->Pause     = aacMFPause;
   hdl->Stop      = aacMFStop;
   hdl->Process   = aacMFProcess;

   hdl->BuildCache    = aacMFBuildCache;
   hdl->SetCacheTbl  = aacMFSetCacheTbl;
   hdl->GetCacheDuration = aacMFGetCacheDur;
   hdl->GetTotalDuration = aacfMFGetTotalDuration;

   if(pstFSAL != NULL){
      ihdl->isStreaming = false;
      hdl->Play = aacMFPlayFile;
      hdl->Resume = aacMFResumeFile;
      kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, MEDIA_FORMAT_BSAC );
   } else {
       ihdl->isStreaming = true;
       hdl->Play = aacMFPlayStrm;
       hdl->Resume = aacMFResumeStrm;
       kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_BSAC );
   }

#if defined AAC_PLUS_PS_DECODE // register audio ID and event handler for aacDecodeTask
   ihdl->aud_id_decoder = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id_decoder, aacDecodeTask );
   ihdl->pstMHdl = (MHdl*)get_ctrl_buffer( sizeof(MHdl) );
   memset(ihdl->pstMHdl, 0, sizeof(MHdl));
   mhdlInitEx( ihdl->pstMHdl, DP_D2C_AAC, aacHisr );
#endif // #if defined AAC_PLUS_PS_DECODE

   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FILE_SIZE, MEDIA_FORMAT_BSAC, ihdl->uFileSize);

   return hdl;
}

#endif // #if defined(BSAC_DECODE)

//#if defined MP4_CODEC

void allocWorkingMemM4A(MHdl *hdl)
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   ihdl->pst_vid_seek_hint_M4A = (FS_FileLocationHint *)med_alloc_ext_mem( sizeof(FS_FileLocationHint) * VID_DEC_SEEK_HINT_SIZE );
   ihdl->pstMp4Parser_M4A = (STMp4Parser *)get_ctrl_buffer( sizeof(STMp4Parser) );
   ihdl->pstFSALAudio_STSZ_M4A = (STFSAL *)get_ctrl_buffer( sizeof(STFSAL) );
   ihdl->pstFSALAudio_STCO_M4A = (STFSAL *)get_ctrl_buffer( sizeof(STFSAL) );
   ihdl->pstFSALAudio_M4A = (STFSAL *)get_ctrl_buffer( sizeof(STFSAL) );
   ihdl->pu_buffer_temp_a_M4A = (kal_uint32 *)get_ctrl_buffer( sizeof(kal_uint32) * (1024/4) );
   ihdl->pu_buffer_temp_stco_a_M4A = (kal_uint32 *)get_ctrl_buffer( sizeof(kal_uint32) * (1024/4) );
   ihdl->pu_buffer_temp_stsz_a_M4A = (kal_uint32 *)get_ctrl_buffer( sizeof(kal_uint32) * (1024/4) );
   ihdl->pu_buffer_STBL_cache_pool_M4A = (kal_uint32 *)med_alloc_ext_mem( sizeof(kal_uint32) * (1024/4*8) );

}

void freeWorkingMemM4A(MHdl *hdl)
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   med_free_ext_mem( (void **) &ihdl->pst_vid_seek_hint_M4A );
   free_ctrl_buffer( ihdl->pstMp4Parser_M4A );
   free_ctrl_buffer( ihdl->pstFSALAudio_STSZ_M4A );
   free_ctrl_buffer( ihdl->pstFSALAudio_STCO_M4A );
   free_ctrl_buffer( ihdl->pstFSALAudio_M4A );
   free_ctrl_buffer( ihdl->pu_buffer_temp_a_M4A );
   free_ctrl_buffer( ihdl->pu_buffer_temp_stco_a_M4A );
   free_ctrl_buffer( ihdl->pu_buffer_temp_stsz_a_M4A );
   med_free_ext_mem( (void **) &ihdl->pu_buffer_STBL_cache_pool_M4A );

}

kal_bool openM4aFile( MHdl *hdl, kal_bool fPreporcess )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;
   MP4_Parser_Status eMp4ParserRet;
   FSAL_Status eFSALRet;
   kal_uint32 filesize;
   kal_uint32 index;
   kal_uint64   temp;

#ifndef WIN32
   eFSALRet = FSAL_GetFileSize(ihdl->pstFSAL, &filesize);
   if(eFSALRet!=FSAL_OK)
      return false;

   for(index=0;index<VID_DEC_SEEK_HINT_SIZE;index++)
   {
       temp = ((kal_uint64)filesize*(kal_uint64)(index+1))/(kal_uint64)(VID_DEC_SEEK_HINT_SIZE+1);
       ihdl->pst_vid_seek_hint_M4A[index].Index = (kal_uint32)temp;
   }
   DRM_set_seek_hint(ihdl->pstFSAL->hFile, VID_DEC_SEEK_HINT_SIZE, ihdl->pst_vid_seek_hint_M4A);

   eMp4ParserRet = MP4_Parse(ihdl->pstMp4Parser_M4A, ihdl->pstFSAL);
   if(eMp4ParserRet!=MP4_PARSER_OK && eMp4ParserRet!=MP4_PARSER_WARNING_TRAILING_GARBAGE)
      return false;

   if(fPreporcess){
      eMp4ParserRet = MP4_STBL_CacheTablePreprocess(ihdl->pstMp4Parser_M4A, ihdl->pu_buffer_STBL_cache_pool_M4A, 2048 );
      if(eMp4ParserRet!=MP4_PARSER_OK )
         return false;
   }

   MP4_Audio_SetFSAL(ihdl->pstMp4Parser_M4A, ihdl->pstFSALAudio_M4A);
#endif
   eFSALRet = FSAL_Open_Attach(ihdl->pstFSALAudio_M4A, ihdl->pstFSAL);
   if(eFSALRet!=FSAL_OK)
      return false;

   FSAL_SetBuffer(ihdl->pstFSALAudio_M4A, 1024 ,(kal_uint8 *)ihdl->pu_buffer_temp_a_M4A);

   eFSALRet = FSAL_Open_Attach(ihdl->pstFSALAudio_STCO_M4A, ihdl->pstFSAL);
   if(eFSALRet !=FSAL_OK)
      return false;

   FSAL_SetBuffer(ihdl->pstFSALAudio_STCO_M4A, 1024 ,(kal_uint8 *)ihdl->pu_buffer_temp_stco_a_M4A);

   eFSALRet = FSAL_Open_Attach(ihdl->pstFSALAudio_STSZ_M4A, ihdl->pstFSAL);
   if(eFSALRet !=FSAL_OK)
      return false;

   FSAL_SetBuffer(ihdl->pstFSALAudio_STSZ_M4A, 1024 ,(kal_uint8 *)ihdl->pu_buffer_temp_stsz_a_M4A);

   MP4_SetFSAL_STCO(ihdl->pstMp4Parser_M4A, MP4_TRACK_AUDIO, ihdl->pstFSALAudio_STCO_M4A);
   MP4_SetFSAL_STSZ(ihdl->pstMp4Parser_M4A, MP4_TRACK_AUDIO, ihdl->pstFSALAudio_STSZ_M4A);
   MP4_UpdateSampleCount(ihdl->pstMp4Parser_M4A, MP4_TRACK_AUDIO);

   return true;
}

static Media_Status m4aMFPlayFile( MHdl *hdl )
{
   kal_uint32 buf_len;
   MP4_Parser_Status eMP4Status;
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   ASSERT(hdl->state == AAC_STATE_PAUSE || hdl->state == AAC_STATE_IDLE);
   if(hdl->start_time || hdl->current_time){
      ihdl->fileOffset = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;
   }

   ihdl->AAC_Decode_EOF = KAL_FALSE;
   ihdl->uEOF_TimeOutCnt = 0;
   ihdl->AAC_DSP_Data_Cnt = 0x7FFFFFFF;
   ihdl->wDspReadIdx = 0xFFFF;

   if((hdl->state != AAC_STATE_PAUSE) && !ihdl->isM4AOpened){
      if(!openM4aFile(hdl, true))
         return MEDIA_FAIL;
      ihdl->isM4AOpened = true;
   }

   {
      kal_uint32 uSampleNo;

      eMP4Status =  MP4_Audio_TimeToSampleNo(ihdl->pstMp4Parser_M4A, hdl->start_time, &uSampleNo );
      eMP4Status =  MP4_Audio_Seek(ihdl->pstMp4Parser_M4A, uSampleNo);
      if(eMP4Status != MP4_PARSER_OK)
         return MEDIA_SEEK_FAIL;
   }

   {
      kal_uint8 *pBuf;
      kal_uint32 num_bytes;
      hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
      eMP4Status = MP4_Audio_Read(ihdl->pstMp4Parser_M4A, pBuf, buf_len, &num_bytes);
      if(eMP4Status == MP4_PARSER_READ_EOF)
         hdl->DataFinished(hdl);
      if((eMP4Status != MP4_PARSER_OK) && (eMP4Status != MP4_PARSER_READ_EOF))
         return MEDIA_READ_FAIL;
      hdl->WriteDataDone( hdl, num_bytes );
      if(num_bytes < (MIN_DATA_LEN *2))
         return MEDIA_SEEK_EOF;
      if(aacParseHeader( ihdl, pBuf ) != MEDIA_SUCCESS)
         return MEDIA_FAIL;
   }

   {
      STFSAL   *pstFSAL = ihdl->pstFSAL;
      ihdl->pstFSAL = NULL;
      ihdl->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
      if(ihdl->pstFSAL == NULL)
         return MEDIA_FAIL;

      {
         FSAL_Status eFSALStatus;
         FSAL_Direct_SetRamFileSize(ihdl->pstFSAL, hdl->rb_size);
         eFSALStatus = FSAL_Open(ihdl->pstFSAL, hdl->rb_base, FSAL_ROMFILE);
         ASSERT(eFSALStatus == FSAL_OK);
      }

      aacUpdateSR(ihdl);

      free_ctrl_buffer(ihdl->pstFSAL);
      ihdl->pstFSAL = pstFSAL;
   }

#ifdef AAC_PLUS_PS_DECODE
   if( !ihdl->aac.stereo && ihdl->aac.sbrPresentFlag && (!fDisableAACPS)){
      ihdl->fEnableARMDecoder = true;
   }

   if(ihdl->fEnableARMDecoder){
      kal_uint8  *pBuf;
      kal_uint32 uMBufLen;
      MHdl *pstTmp = ihdl->pstMHdl;

      if(!aacWorking_data){

#if APM_SUPPORT
         aacWorking_data = APM_Allocate_Buffer((MAX_NUM_CHANNELS*SAMPLES_PER_FRAME*2) + MAINinternStaticSize + MAINexternStaticSize + MAINinternDynamicSize);
         if (aacWorking_data != NULL)
         {
            ihdl->fUseTCMFromAPM = true;
         }
         else
#endif
         {
            aacWorking_data = (kal_uint8 *)med_alloc_ext_mem((MAX_NUM_CHANNELS*SAMPLES_PER_FRAME*2) + MAINinternStaticSize + MAINexternStaticSize + MAINinternDynamicSize);
         }
		 
         pstTmp->rb_base = (kal_uint8 *)med_alloc_ext_mem(AAC_OUT_BUF_SIZE);
      }
      pstTmp->rb_size = AAC_OUT_BUF_SIZE;
      pstTmp->read = 0;
      pstTmp->write = 0;

      // Decoder's input buffer initialization
      AACBUFFER.AAC_bitstreams_Buffer = hdl->rb_base;
      AACBUFFER.AAC_bitstreams_Buffer_W = (kal_int32)hdl->write + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
      AACBUFFER.AAC_bitstreams_Buffer_R =  (kal_int32)hdl->read + (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
      // Decoder's output buffer initialization
      AACBUFFER.AAC_Media_Buffer = (kal_uint16 *)pstTmp->rb_base;
      AACBUFFER.AAC_Media_Buffer_W = (kal_int32)pstTmp->write+ (kal_int32)AACBUFFER.AAC_Media_Buffer;
      AACBUFFER.AAC_Media_Buffer_R = (kal_int32)pstTmp->read+(kal_int32)AACBUFFER.AAC_Media_Buffer;
      AACBUFFER.AAC_Media_Buffer_len = AAC_OUT_BUF_SIZE;

      rawDecoder = aac_init(&AACBUFFER,aacWorking_data, AAC_OUT_BUF_SIZE);
      if( rawDecoder == NULL){
         ihdl->fDecoderError = true;
         return MEDIA_ERROR;
      }

      do{
         kal_uint32 AAC_REPORT;
         AAC_REPORT = AAC_Decode_frame( rawDecoder,&AACBUFFER,aacWorking_data, hdl->rb_size);
         if( AAC_REPORT!= 0 &&  AAC_REPORT != 5){
            ihdl->fDecoderError = true;
            return MEDIA_ERROR;
         }
         if(AAC_REPORT == 5){
            return MEDIA_SEEK_EOF;
         }

         hdl->read = (kal_int32)AACBUFFER.AAC_bitstreams_Buffer_R - (kal_int32)AACBUFFER.AAC_bitstreams_Buffer;
         pstTmp->write = (kal_int32)AACBUFFER.AAC_Media_Buffer_W - (kal_int32)AACBUFFER.AAC_Media_Buffer;
         ihdl->mh.GetWriteBuffer((MHdl*)pstTmp, &pBuf, &uMBufLen);
      }while(uMBufLen >= AAC_MAX_OUT_LEN);
   }

#endif // #ifdef AAC_PLUS_PS_DECODE

   ASSERT(ihdl->frameDur != 0);
   ihdl->uCurFrame = (kal_uint64)hdl->start_time * 1000000 / ihdl->frameDur;
   aacOpenDevice(ihdl, true);
   return MEDIA_SUCCESS;
}

static Media_Status m4aMFResume( MHdl *hdl )
{
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;

   if(ihdl->AAC_Decode_EOF){
      mhdlException(hdl, MEDIA_END);
      return MEDIA_SUCCESS;
   }
   hdl->start_time = hdl->current_time;
   return m4aMFPlayFile(hdl);
}

MHdl *M4A_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   aacMediaHdl *ihdl;
   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, DP_D2C_AAC, aacHisr );

   allocWorkingMemM4A(hdl);

   hdl->handler   = handler;
   hdl->state     = AAC_STATE_IDLE;
   hdl->mediaType = MEDIA_FORMAT_M4A;
   ihdl->aac.bIsTypeADTS = true;
   ihdl->pstFSAL  = pstFSAL;
   hdl->Close     = aacMFClose;
   hdl->Stop      = aacMFStop;
   hdl->Process   = aacMFProcess;
   hdl->Play      = m4aMFPlayFile;
   hdl->Resume    = m4aMFResume;
   hdl->Pause     = aacMFPause;

#if defined AAC_PLUS_PS_DECODE // register audio ID and event handler for aacDecodeTask
   ihdl->aud_id_decoder = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id_decoder, aacDecodeTask );
   ihdl->pstMHdl = (MHdl*)get_ctrl_buffer( sizeof(MHdl) );
   memset(ihdl->pstMHdl, 0, sizeof(MHdl));
   mhdlInitEx( ihdl->pstMHdl, DP_D2C_AAC, aacHisr );
#endif // #if defined AAC_PLUS_PS_DECODE

   return hdl;
}

kal_bool M4A_IsPPSupport( STFSAL *pstFSAL )
{
   kal_uint32 buf_len;
   MP4_Parser_Status eMP4Status;
   aacMediaHdl *ihdl;
   MHdl *hdl;
   bool fPPSupport;
   kal_uint8 *tempBuf;

   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   hdl = (MHdl *) ihdl;
   ihdl->aac.bIsTypeADTS = true;
   ihdl->pstFSAL  = pstFSAL;
   mhdlInit( hdl, 0xFFFF, aacHisr );

   tempBuf = (kal_uint8 *)get_ctrl_buffer( sizeof(kal_uint8) * 2048 );
   hdl->SetBuffer(hdl, tempBuf, 2048);

   allocWorkingMemM4A(hdl);

   if (!openM4aFile(hdl, false)) {
      freeWorkingMemM4A(hdl);
      free_ctrl_buffer( tempBuf );
      free_ctrl_buffer( ihdl );
      return true;
   }


   {
      kal_uint32 uSampleNo;

      eMP4Status =  MP4_Audio_TimeToSampleNo(ihdl->pstMp4Parser_M4A, hdl->start_time, &uSampleNo );
      eMP4Status =  MP4_Audio_Seek(ihdl->pstMp4Parser_M4A, uSampleNo);
      if(eMP4Status != MP4_PARSER_OK) {
         freeWorkingMemM4A(hdl);
         free_ctrl_buffer( tempBuf );
         free_ctrl_buffer( ihdl );
         return true;
      }
   }

   {
      kal_uint8 *pBuf;
      kal_uint32 num_bytes;
      hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
      eMP4Status = MP4_Audio_Read(ihdl->pstMp4Parser_M4A, pBuf, buf_len, &num_bytes);
      if(eMP4Status == MP4_PARSER_READ_EOF)
         hdl->DataFinished(hdl);
      if((eMP4Status != MP4_PARSER_OK) && (eMP4Status != MP4_PARSER_READ_EOF)) {
         freeWorkingMemM4A(hdl);
         free_ctrl_buffer( tempBuf );
         free_ctrl_buffer( ihdl );
         return true;
      }
      hdl->WriteDataDone( hdl, num_bytes );
      aacParseHeader( ihdl, pBuf );
   }

//
   {
      STFSAL   *pstFSAL = ihdl->pstFSAL;
      ihdl->pstFSAL = NULL;
      ihdl->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
      if(ihdl->pstFSAL == NULL) {
         freeWorkingMemM4A(hdl);
         free_ctrl_buffer( tempBuf );
         free_ctrl_buffer( ihdl );
         return true;
      }

      {
         FSAL_Status eFSALStatus;
         FSAL_Direct_SetRamFileSize(ihdl->pstFSAL, hdl->rb_size);
         eFSALStatus = FSAL_Open(ihdl->pstFSAL, hdl->rb_base, FSAL_ROMFILE);
         ASSERT(eFSALStatus == FSAL_OK);
      }

      aacUpdateSR(ihdl);

      free_ctrl_buffer(ihdl->pstFSAL);
      ihdl->pstFSAL = pstFSAL;
   }
//

   fPPSupport = !(ihdl->aac.sbrPresentFlag);
   freeWorkingMemM4A(hdl);
   free_ctrl_buffer( tempBuf );
   free_ctrl_buffer( ihdl );
   return fPPSupport;
}

Media_Status M4A_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   MHdl *hdl;
   aacMediaHdl *ihdl;
   MP4_Parser_Status eMP4Status;
   kal_uint32 uMediaDuration;
   kal_uint8  sampleRateIndex;
   kal_bool   fSBRflag;
   STFSAL     *pstFSALTmp;
   MP4_Audio_Type eAudioType;
   kal_uint32 *puFSAL_Buf;

   puFSAL_Buf = (kal_uint32 *)get_ctrl_buffer( sizeof(kal_uint32) * (1024/4) );
   pstFSALTmp = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   memset(pstFSALTmp, 0, sizeof(STFSAL));
   if(FSAL_Open_Attach(pstFSALTmp, pstFSAL)!=FSAL_OK){
      free_ctrl_buffer( pstFSALTmp );
      free_ctrl_buffer( puFSAL_Buf );
      return MEDIA_FAIL;
   }
   FSAL_SetBuffer(pstFSALTmp, 1024 ,(kal_uint8 *)puFSAL_Buf);

   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   hdl = (MHdl *) ihdl;
   ihdl->pstFSAL = pstFSAL;

   contentInfo->title[0]  = '\0';
   contentInfo->artist[0] = '\0';
   contentInfo->album[0]  = '\0';
   contentInfo->time = 0;
   contentInfo->bitRate = 0;
   contentInfo->sampleRate = 0;
   contentInfo->stereo = false;

   ihdl->pstMp4Parser_M4A = (STMp4Parser *)get_ctrl_buffer( sizeof(STMp4Parser) );

   {
      MP4_Parser_Status eMp4ParserRet;
      eMp4ParserRet = MP4_Parse(ihdl->pstMp4Parser_M4A, ihdl->pstFSAL);
      if(eMp4ParserRet!=MP4_PARSER_OK && eMp4ParserRet!=MP4_PARSER_WARNING_TRAILING_GARBAGE){
         free_ctrl_buffer( ihdl->pstMp4Parser_M4A );
         free_ctrl_buffer( ihdl );
         free_ctrl_buffer( pstFSALTmp );
         free_ctrl_buffer( puFSAL_Buf );
         return MEDIA_FAIL;
      }
   }

   eAudioType = MP4_GetAudioType(ihdl->pstMp4Parser_M4A);

   if(eAudioType == MP4_AUDIO_AAC){
      sampleRateIndex = MP4_Audio_GetFreqIndex(ihdl->pstMp4Parser_M4A);
      if( 2 == ihdl->pstMp4Parser_M4A->bAudioChannelConfig )
         contentInfo->stereo = true;
   }

   eMP4Status = MP4_GetMediaDuration(ihdl->pstMp4Parser_M4A, &uMediaDuration, MP4_TRACK_AUDIO);

   if (eMP4Status==MP4_PARSER_OK) {
      kal_uint32 uAudioTimeScale;
      if (MP4_GetMediaTimeScale(ihdl->pstMp4Parser_M4A, &uAudioTimeScale, MP4_TRACK_AUDIO)==MP4_PARSER_OK){
         uMediaDuration = ((kal_uint64)uMediaDuration * 1000) / (kal_uint64)uAudioTimeScale;
         contentInfo->time = (eMP4Status == MP4_PARSER_OK)?uMediaDuration:0;
      }
   }

   free_ctrl_buffer( ihdl->pstMp4Parser_M4A );
   free_ctrl_buffer( ihdl );

   if(eAudioType == MP4_AUDIO_AAC){
      fSBRflag = !M4A_IsPPSupport( pstFSALTmp );
      contentInfo->sampleRate = sampleRateTab[sampleRateIndex-((kal_uint32)fSBRflag*3)];
   }else if(eAudioType == MP4_AUDIO_AMR){
      contentInfo->sampleRate = 8000;
   }else if(eAudioType == MP4_AUDIO_AMR_WB){
      contentInfo->sampleRate = 16000;
   }else{
      free_ctrl_buffer( pstFSALTmp );
      free_ctrl_buffer( puFSAL_Buf );
      return MEDIA_FAIL;
   }

   free_ctrl_buffer( pstFSALTmp );
   free_ctrl_buffer( puFSAL_Buf );
   return MEDIA_SUCCESS;
}

//#endif // MP4_CODEC

Media_Status AAC_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   MHdl *hdl;
   aacMediaHdl *ihdl;

   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( ( MHdl *)ihdl, 0xFFFF , aacHisr );
   ihdl->pstFSAL = pstFSAL;

   contentInfo->title[0]  = '\0';
   contentInfo->artist[0] = '\0';
   contentInfo->album[0]  = '\0';
   contentInfo->author[0]  = '\0';
   contentInfo->copyright[0]  = '\0';
   contentInfo->date[0]  = '\0';
   contentInfo->time = 0;
   contentInfo->bitRate = 0;
   contentInfo->sampleRate = 0;
   contentInfo->stereo = false;

   autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );
   {
      Media_Status ret;
      if ((ret=aacSyncFirstFrame( ihdl ))!=MEDIA_SUCCESS){
         free_ctrl_buffer( ihdl );
         return ret;
      }
      aacUpdateSR(ihdl);
   }
   if(ihdl->aac.bIsTypeADTS){
      kal_uint64 bitRate = maxByterateFromIndex[ihdl->aac.sr_idx];
      contentInfo->stereo = ihdl->aac.stereo;
      {
         uint32 file_size;
         FSAL_GetFileSize(ihdl->pstFSAL, &file_size);
         if(bitRate)
            contentInfo->time = (kal_uint64)file_size * 8000 / bitRate;
       }
   }else{
       contentInfo->stereo = true;
    }
   contentInfo->sampleRate = sampleRateTab[ihdl->aac.sr_idx];

   free_ctrl_buffer( ihdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, hdl->mediaType );
   return MEDIA_SUCCESS;
}

Media_Status AAC_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
   aud_info_struct *aud_info_p;

   Media_Status ret;
   FSAL_Status eFSALStatus;
   STFSAL *pstFSAL = 0;

   pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if(pstFSAL == NULL)
      return MEDIA_FAIL;
   memset(pstFSAL, 0, sizeof(STFSAL));
      
   if(NULL != filename){      
      eFSALStatus = FSAL_Open(pstFSAL, (void*)filename, FSAL_READ);
      if(eFSALStatus != FSAL_OK){
         free_ctrl_buffer(pstFSAL);
         return MEDIA_FAIL;
      }   
   }else{
       ASSERT(pbBuf != 0);
       ASSERT(uSize != 0)
       FSAL_Direct_SetRamFileSize(pstFSAL, uSize);
       eFSALStatus = FSAL_Open(pstFSAL, pbBuf, FSAL_ROMFILE);
       ASSERT(eFSALStatus == FSAL_OK);
   }

   ret = DAF_GetContentDescInfo( pstFSAL, contentInfo, (void *)0);

   if(NULL != filename){
      FSAL_Close(pstFSAL);
   }
   free_ctrl_buffer(pstFSAL);

   if( MEDIA_SUCCESS != ret )
      return ret;

   aud_info_p = (aud_info_struct*)get_ctrl_buffer( sizeof(aud_info_struct) );
   memset(aud_info_p, 0, sizeof(aud_info_struct));

   if(filename){
      if(!get_aud_meta_data_file(filename, aud_info_p)){
         free_ctrl_buffer( aud_info_p );
         return MEDIA_FAIL;
      }
   }else{
      ASSERT(0 != pbBuf);
      if(!get_aud_meta_data_array((kal_char *)pbBuf, uSize, aud_info_p)){
         free_ctrl_buffer( aud_info_p );
         return MEDIA_FAIL;
      }
   }

   memcpy(contentInfo->title, aud_info_p->title, sizeof(kal_wchar)* MAX_ID3_TITLE_LEN);
   memcpy(contentInfo->author, aud_info_p->artist, sizeof(kal_wchar)* MAX_ID3_ARTIST_LEN);
   memcpy(contentInfo->copyright, aud_info_p->copyright, sizeof(kal_wchar)* MAX_ID3_COPYRIGHT_LEN);
   memcpy(contentInfo->date, aud_info_p->year, sizeof(kal_wchar)* MAX_ID3_YEAR_LEN);

   free_ctrl_buffer( aud_info_p );
   return MEDIA_SUCCESS;
}

Media_Status AAC_Trim(STFSAL *pstIn, STFSAL *pstOut, kal_uint32 uStartTime, kal_uint32 uStopTime)
{
   kal_uint32 uStartOffset, uEndOffset;
   Media_Status eResult = MEDIA_SUCCESS;
   aacMediaHdl *ihdl;

   if(((kal_int32)uStopTime - (kal_int32)uStartTime) <= 0)
      return MEDIA_BAD_PARAMETER; // invalid stop time

   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   ihdl->pstFSAL         = pstIn;

   autSkipID3Tag( (MHdl *)ihdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );

   {   /* Parse AAC Header */
	  Media_Status ret;
     if ((ret=aacSyncFirstFrame(ihdl))!=MEDIA_SUCCESS){
         free_ctrl_buffer(ihdl);
         return ret;
	  }
   }
   // find the start/end offset of trim
   if(ihdl->aac.bIsTypeADTS){
	   kal_uint32 uFirstFrameFileOffset = ihdl->fileOffset;
	   ihdl->mh.start_time = uStartTime;
      if(aacSeek(ihdl, false) != KAL_TRUE){
		   free_ctrl_buffer(ihdl);
		   return MEDIA_SEEK_FAIL;
	   }
	   uStartOffset = ihdl->fileOffset;
	   ihdl->fileOffset = uFirstFrameFileOffset;

      ihdl->mh.start_time = uStopTime;
      if(aacSeek(ihdl, false) != KAL_TRUE){
         free_ctrl_buffer(ihdl);
		   return MEDIA_SEEK_FAIL;
	   }
      uEndOffset = ihdl->fileOffset;
	   ihdl->fileOffset = uStartOffset;
   }else{
	   free_ctrl_buffer(ihdl);
	   return MEDIA_UNSUPPORTED_TYPE;
   }
   //write fregment audio data
   {
	   FSAL_Status eFSALStatus;
	   kal_int32 uNumBytes;
	   kal_int32 uLength = (kal_int32)uEndOffset-(kal_int32)uStartOffset;

	   // refill buffer
	   while(uLength > 0){
		   kal_uint32 len = AAC_MAX_DATA_REQUESTED;
		   if(uLength<AAC_MAX_DATA_REQUESTED)
			   len = uLength;
		   uNumBytes = aacGetBytesFromFile((MHdl *)ihdl, ihdl->pstFSAL, ihdl->fileOffset, len, &ihdl->buf[0]);
		   if(uNumBytes<0){
            free_ctrl_buffer(ihdl);
            return MEDIA_READ_FAIL;
		   }
	      eFSALStatus = FSAL_Write(pstOut, &ihdl->buf[0], uNumBytes);
		   if(FSAL_OK != eFSALStatus){
            free_ctrl_buffer(ihdl);
            if(eFSALStatus == FS_DISK_FULL)
               return MEDIA_DISK_FULL;
            else
               return MEDIA_WRITE_FAIL;
		   }
		   ihdl->fileOffset += uNumBytes;
		   uLength -= uNumBytes;
	   }
   }
   free_ctrl_buffer(ihdl);
   return eResult;
}

Media_Status AAC_Merge(STFSAL *pstIn1, STFSAL *pstIn2, STFSAL *pstOut)
{
   // check to see whether streams could be merged
   // merge file
   kal_uint8    sr_idx = 0;
   kal_bool     stereo = 0;
   aacMediaHdl *ihdl;
   Media_Status eResult = MEDIA_SUCCESS;
   kal_uint32 file_size;
            
   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );

   {
      kal_uint32 cnt;
      for(cnt=0; cnt<2; cnt++)
      {
         memset(ihdl, 0, sizeof(aacMediaHdl));
         if(cnt==0){
            ihdl->pstFSAL = pstIn1;
         }else{
             ihdl->pstFSAL = pstIn2;
          }

         autSkipID3Tag( (MHdl *)ihdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );

         {   /* Parse AAC Header */
	        Media_Status ret;
           if ((ret=aacSyncFirstFrame(ihdl))!=MEDIA_SUCCESS){
               free_ctrl_buffer(ihdl);
               return ret;
	        }
         }

         if(0 == cnt){
            sr_idx = ihdl->aac.sr_idx;
            stereo = ihdl->aac.stereo;
         }else{
            if((sr_idx != ihdl->aac.sr_idx) || (stereo != ihdl->aac.stereo)){
               free_ctrl_buffer(ihdl);
               return MEDIA_MERGE_TYPE_MISMATCH;
            }
         }

         if(!ihdl->aac.bIsTypeADTS){
	         free_ctrl_buffer(ihdl);
	         return MEDIA_UNSUPPORTED_TYPE;
         }
         //write fregment audio data
         {
	         FSAL_Status eFSALStatus;
	         kal_int32 uNumBytes, uLength;

            FSAL_GetFileSize( ihdl->pstFSAL, &file_size);
            uLength = (kal_int32)(file_size - ihdl->fileOffset);

	         // refill buffer
	         while(uLength > 0){
	      	   kal_uint32 len = AAC_MAX_DATA_REQUESTED;
	      	   if(uLength < AAC_MAX_DATA_REQUESTED)
	      		   len = uLength;
	      	   uNumBytes = aacGetBytesFromFile((MHdl *)ihdl, ihdl->pstFSAL, ihdl->fileOffset, len, &ihdl->buf[0]);
	      	   if(uNumBytes<0){
                  free_ctrl_buffer(ihdl);
                  return MEDIA_READ_FAIL;
	      	   }
	            eFSALStatus = FSAL_Write(pstOut, &ihdl->buf[0], uNumBytes);
	      	   if(FSAL_OK != eFSALStatus){
                  free_ctrl_buffer(ihdl);
                  if(eFSALStatus == FS_DISK_FULL)
                     return MEDIA_DISK_FULL;
                  else
                     return MEDIA_WRITE_FAIL;
	      	   }
	      	   ihdl->fileOffset += uNumBytes;
	      	   uLength -= uNumBytes;
	         }
         }
      }
   }
   free_ctrl_buffer(ihdl);
   return eResult;
}

kal_bool AAC_IsPPSupport( STFSAL *pstFSAL)
{
   aacMediaHdl *ihdl;
   Media_Status ret;
   bool fPPSupport;
   MHdl *hdl;

   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   ihdl->pstFSAL = pstFSAL;
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, 0xFFFF, aacHisr );

   autSkipID3Tag( (MHdl *)ihdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );

   if ((ret=aacSyncFirstFrame(ihdl))!=MEDIA_SUCCESS ){
      free_ctrl_buffer( ihdl );
      return false;
   }
   aacUpdateSR(ihdl);

   fPPSupport = !(ihdl->aac.sbrPresentFlag);
   free_ctrl_buffer( ihdl );
   return fPPSupport;
}

kal_bool AAC_IsADIF( STFSAL *pstFSAL)
{
   aacMediaHdl *ihdl;
   Media_Status ret;
   bool fIsADIF;
   MHdl *hdl;

   ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
   memset(ihdl, 0, sizeof(aacMediaHdl));
   ihdl->pstFSAL = pstFSAL;
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, 0xFFFF, aacHisr );

   autSkipID3Tag( (MHdl *)ihdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );

   if ((ret=aacSyncFirstFrame(ihdl))!=MEDIA_SUCCESS ){
      free_ctrl_buffer( ihdl );
      return false;
   }

   fIsADIF = ihdl->aac.bIsTypeADIF;
   free_ctrl_buffer( ihdl );
   return fIsADIF;
}

#endif /* AAC_DECODE */