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
 * audio_rtp.c
 *
 * Project:
 * --------
 *   MTK6229
 *
 * Description:
 * ------------
 *   RTP Audio interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
//#define STREAM_SUPPORT

#include "media.h"
#include "audio_rtp.h"

#if defined STREAM_SUPPORT

void AudRTP_putbits(unsigned char *in, unsigned int *bitcnt, int data, int data_length)
{
   int t,count;

   ASSERT(data_length>0 && data_length<=16);

   t = *bitcnt;

   if( (t & 0x7)== 0)
      in[t>>3] = 0;

   if( (t & 0x7) + data_length  <= 8)
      in[(t>>3)] |= (data << (8-((t&0x7) + data_length)));
   else {
      count = (t&7) + data_length;
      in[(t>>3)] |= (data >> (data_length - 8 + (t&7)));
      count -= 8;

      if(count > 8) {
         in[(t>>3)+1] = (unsigned char)((data >> (count-8))&0xFF);
         in[(t>>3)+2] = (unsigned char)((data << (16-count))&0xFF);
      } else {
         in[(t>>3)+1] = (unsigned char)((data << (8-count))&0xFF);
      }
   }
   *bitcnt += data_length;
}

kal_uint8 AudRTP_getbits(kal_uint8 *pBuf, kal_uint32 *puBitCnt, kal_uint32 uBitLen)
{
	static kal_uint8 bCurByte;
	kal_uint8 bMask;
	kal_uint32 uCurBitPos;
	kal_uint8 bValue;

   ASSERT(puBitCnt!=NULL);
	ASSERT(uBitLen>=1 && uBitLen<=8);

	uCurBitPos = *puBitCnt % 8;

	if(uCurBitPos==0) {
	   bCurByte = pBuf[*puBitCnt/8];
	}

	*puBitCnt += uBitLen;

	if(uCurBitPos+uBitLen<=8) {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) >> (8-(uCurBitPos+uBitLen)));
	} else {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) << (uBitLen-(8-uCurBitPos)));
		bCurByte = pBuf[*puBitCnt/8];
		bValue |= bCurByte>>(16-uBitLen-uCurBitPos);
	}

	return bValue;
}

kal_uint32 AudRTP_getPacketNum(kal_uint8 *pbBuf, kal_uint32 uBufSize)
{
   kal_uint32 uPacketNum, uTmp;

   ASSERT(uBufSize > 4);
   uTmp = (kal_uint32) *(pbBuf+2);
   uPacketNum = (kal_uint32) *(pbBuf+3);
   uPacketNum |= uTmp << 8;

   return uPacketNum;
}

kal_uint32 AudRTP_getTimeStamp(kal_uint8 *pbBuf, kal_uint32 uBufSize)
{
   kal_uint32 uTimeStamp = 0, uTmp, uCnt, uOffset;

   for(uCnt=4, uOffset=4; uCnt!=0; uCnt--, uOffset++){
      uTmp = (kal_uint32) *(pbBuf+uOffset);
      uTimeStamp |= uTmp << ((uCnt-1)*8);
   }
   return uTimeStamp;
}

AudRTP_DL_HANDLE *RTPAudio_OpenDLChannel( rtp_audio_codec_type codec_type )
{
   AudRTP_DL_HANDLE* psPtr = (AudRTP_DL_HANDLE*)0;
   if((codec_type == RTP_AUDIO_AMR) || (codec_type == RTP_AUDIO_AWB)){
      psPtr = RTPAMR_OpenDLChannel();
   }else if(codec_type == RTP_AUDIO_MP4A_LATM_AAC || codec_type ==  RTP_AUDIO_MPEG4_GENERIC_AAC){
         psPtr = RTPAAC_OpenDLChannel();
    }else{
        ASSERT(0); // Non support codec type
     }
   return psPtr;
}

#endif // #if defined STREAM_SUPPORT
