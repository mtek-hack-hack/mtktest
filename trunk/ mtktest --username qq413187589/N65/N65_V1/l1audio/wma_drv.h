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
 *   wma.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  This file defines all the hardware/DSP registers used in WMA Driver
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
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
#include "ddload.h"  // WMA L2 support
#include "dsp_dll.h" // WMA L2 support

#define WMA_STATE_IDLE          0  // 1
#define WMA_STATE_PLAYING       1  // 3,2,0
#define WMA_STATE_PLAY_PAUSED   2  // 1,0
#define WMA_STATE_ENDING        3  // 0

#define SHERIEF_STATE_IDLE     0x00
#define SHERIEF_STATE_INIT     0x12
#define SHERIEF_STATE_RUNNING  0x20
#define SHERIEF_STATE_STOP     0x14
#define SHERIEF_STATE_END      0x18

#define WMA_RB_REQ_THR         200

#define WMA_ON  0x05
#define WMA_OFF 0x00

#define WAVE_FORMAT_MSAUDIO1  0x0160
#define WAVE_FORMAT_WMAUDIO2  0x0161

#define MIN_OBJECT_SIZE     24
#define DATA_OBJECT_SIZE    50
#define WMA_MAX_DATA_REQUESTED  1024

typedef int WMAERR;

#define WMAERR_OK               0
#define WMAERR_FAIL             1
#define WMAERR_INVALIDHEADER    2
#define WMAERR_NEWPACKET        3
#define WMAERR_CORRUPTDATA      4
#define WMAERR_UNSUPPORT        5

#define WMA_PARSE_ENCRYPTION    0

typedef struct tqword
{
   uint32   dwLo;
   uint32   dwHi;
}  qword;

typedef struct tPayloadParseInfo
{
   uint32 msObjectPres;
   uint32 cbParseOffset;
   uint16 cbPayloadSize;
   uint16 cbTotalSize;
   uint16 wBytesRead;
   uint16 wSubpayloadLeft;

   uint8 bStreamId;
   uint8 cbRepData;
   
   uint8 bSubPayloadState;
   uint8 bIsCompressedPayload;
   uint8 bNextSubPayloadSize;
   bool  fInvalidFrame;
}  payloadParseInfo;

typedef struct tPacketParseInfo
{
   uint32 cbParseOffset;
   uint32 cbExplicitPacketLength; 
   uint32 cbPadding;
   uint32 dwSCR;
   uint32 cPayloads;
   
   bool fParityPacket;
   bool fMultiPayloads;
   bool fEccPresent;
   uint8 bECLen;

   uint8 bPacketLenType;
   uint8 bPadLenType;
   uint8 bSequenceLenType;
   uint8 bOffsetLenType;
   uint8 bPayLenType;
}  packetParseInfo;

// internal structure for the ASF header parsing
typedef struct tFileHeaderParseInfo
{
   uint32 currPacketOffset;     // not just for packets
   uint32 nextPacketOffset;

   // ASF header
   uint32   cbHeader;
   uint32   cbPacketSize;
   uint32   cPackets;
   uint32   msDuration;
   uint32   cbLastPacketOffset;

   // audio prop
   uint32   nSamplesPerSec;
   uint32   nAvgBytesPerSec;
   uint32   nBlockAlign;
   uint16   wAudioStreamId;
   uint16   nVersion;
   uint16   nChannels;
   uint16   nEncodeOpt;

#if WMA_PARSE_ENCRYPTION
   // DRM
   uint32   cbSecretData;
   uint8    pbSecretData[32];
   uint8    pbType[16];
   uint8    pbKeyID[32];
   uint8    pbURL[256];
#endif
} fileHeaderParseInfo;

/* parser state  */
typedef enum
{
   csWMA_NewAsfPacket = 0,
   csWMA_DecodePayloadStart,
   csWMA_DecodePayload,
   csWMA_DecodePayloadHeader,
   csWMA_DecodeLoopStart,
   csWMA_DecodePayloadEnd,
   csWMA_DecodeCompressedPayload,
   csWMA_End
} asfParseState;

typedef struct tagAsfFileStateInternal
{
   fileHeaderParseInfo hdr_parse;

   // parse_state   
   asfParseState parse_state;

   // payload parsing
   uint32 cbPayloadOffset;
   uint32 cbPayloadLeft;
   uint32 cbBlockLeft;
   uint32 iPayload;
   bool  bBlockStart;

   // packet parsing
   packetParseInfo ppex;
   payloadParseInfo payload;
} asfFileStateInternal;

typedef enum tagWMAHuffmanTableGroup
{
   Huffman_RLC_16,
   Huffman_RLC_44O,
   Huffman_RLC_44Q
} wmaHuffmanTableGroup;

typedef struct media_handle_internal {
   MHdl                       mh;      /* this should be the first line in this structure */
   STFSAL                     *pstFSAL;
   bool                       fParsed;
   uint32                     fileSize;
   asfFileStateInternal       sState;
   audInfoStruct              *description;
   wmaHuffmanTableGroup       tableGroup;
   Media_Event                end_status;
   int32                      bufStartTime;
   int32                      bufEndTime;
   int32                      dspBufTime;
   kal_bool                   WMA_decode_EOF;
   kal_int32                  WMA_DSP_data_Cnt;
   kal_uint32                 WMA_Total_Frame;
   kal_uint16                 WMA_DSP_write;
   kal_bool                   WMA_Packet_Loss;
   kal_bool                   uPacketNumPrev;
   uint16                     wReloadTabBase;
   uint16                     wReloadTabLen;
   uint32                     uPacketNum;
   const DLL_Func             *pmdllptr;
   uint8                      pDataBuffer[WMA_MAX_DATA_REQUESTED];
   kal_uint64                 uCurFrame;
} wmaMediaHandleInternal;

typedef struct tGUID
{
   uint32   Data1;
   uint16   Data2;
   uint16   Data3;
   uint8    Data4[ 8 ];
} GUID;

#define GetUnalignedWord( pb, w )    (w) = *(uint16*)(pb); 
#define GetUnalignedDword( pb, dw ) (dw) = *(uint32*)(pb);
#define GetUnalignedQword( pb, qw ) (qw) = *(qword*)(pb);

#define GetUnalignedWordEx( pb, w )     GetUnalignedWord( pb, w );   (pb) += sizeof(uint16);
#define GetUnalignedDwordEx( pb, dw )   GetUnalignedDword( pb, dw ); (pb) += sizeof(uint32);
#define GetUnalignedQwordEx( pb, qw )   GetUnalignedQword( pb, qw ); (pb) += sizeof(qword);

#define LoadBYTE( b, p )        b = *(uint8 *)(p);  (p) += sizeof(uint8);
#define LoadWORD( w, p )      (w) = *(uint16*)(p);  (p) += sizeof(uint16);
#define LoadDWORD( dw, p )   (dw) = *(uint32*)(p);  (p) += sizeof(uint32);
#define LoadQWORD( qw, p )   (qw) = *(qword *)(p);  (p) += sizeof(qword);

#define LoadGUID( g, p ) \
        { \
            LoadDWORD( (g).Data1, p ); \
            LoadWORD( (g).Data2, p ); \
            LoadWORD( (g).Data3, p ); \
            LoadBYTE( (g).Data4[0], p ); \
            LoadBYTE( (g).Data4[1], p ); \
            LoadBYTE( (g).Data4[2], p ); \
            LoadBYTE( (g).Data4[3], p ); \
            LoadBYTE( (g).Data4[4], p ); \
            LoadBYTE( (g).Data4[5], p ); \
            LoadBYTE( (g).Data4[6], p ); \
            LoadBYTE( (g).Data4[7], p ); \
        }

#define WMA_IsEqualGUID(rguid1, rguid2) (!kal_mem_cmp((void *)rguid1, (void *)rguid2, sizeof(GUID)))

/***************************************************************************/


typedef struct tAsfXAcmAudioErrorMaskingData
{
   uint8     span;
   uint16    virtualPacketLen;
   uint16    virtualChunkLen;
   uint16    silenceLen;
   uint8     silence[1];
} AsfXAcmAudioErrorMaskingData;

typedef struct tAsfXSignatureAudioErrorMaskingData
{
   uint32  maxObjectSize;
   uint16  chunkLen;
   uint16  signatureLen;
   uint8   signature[1];
} AsfXSignatureAudioErrorMaskingData;

typedef enum tagWMAFileStatus
{
   cWMA_NoErr,                 // -> always first entry
                                // remaining entry order is not guaranteed
   cWMA_BadAsfHeader,
   cWMA_BadPacketHeader,
   cWMA_BrokenFrame,
   cWMA_NoMoreFrames,
   cWMA_Internal               // really bad
} wmaFileStatus;
