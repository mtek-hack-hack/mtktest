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
 *   wma.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  WMA Driver
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(WMA_DECODE)

//#define WMA_L2_DEBUG_DUMP_LOG  // WMA L2 support
#include "l1audio_def.h"
#include "wma_drv.h"
#include "afe.h"
#include "l1sp_trc.h"

#define WMA_PACKET_LOSS_HANDLING

#if defined(MT6228) || defined(MT6225)
#define PAGE_NUM 2
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PAGE_NUM 3
#else
#error The new chip should define DM page number
#endif

#define Hardeare_Mute 0

#ifdef WMA_L2_DEBUG_DUMP_LOG  // WMA L2 support
#define  WMA_CHECKSUM_MAX_SIZE  20480
kal_uint16 wmaChecksumInfo[WMA_CHECKSUM_MAX_SIZE];
kal_uint32 wmaCnt = 0xFFFFFFFF;
#endif

static const GUID CLSID_CAsfHeaderObjectV0 = {0x75b22630,0x668e,0x11cf, {0xa6,0xd9,0x00,0xaa,0x00,0x62,0xce,0x6c}};
static const GUID CLSID_CAsfPropertiesObjectV2 = {0x8cabdca1, 0xa947, 0x11cf, {0x8e, 0xe4, 0x0, 0xc0, 0xc, 0x20, 0x53, 0x65}};
static const GUID CLSID_CAsfStreamPropertiesObjectV1 = {0xb7dc0791, 0xa9b7, 0x11cf, {0x8e, 0xe6, 0x0, 0xc0, 0xc, 0x20, 0x53, 0x65}};
static const GUID CLSID_CAsfContentDescriptionObjectV0 = {0x75b22633,0x668e,0x11cf,{0xa6,0xd9,0x00,0xaa,0x00,0x62,0xce,0x6c}};
static const GUID CLSID_AsfXStreamTypeAcmAudio = {0xf8699e40,0x5b4d,0x11cf,{0xa8,0xfd,0x00,0x80,0x5f,0x5c,0x44,0x2b}};
static const GUID CLSID_AsfXSignatureAudioErrorMaskingStrategy = {0x49f1a440, 0x4ece, 0x11d0, {0xa3, 0xac, 0x0, 0xa0, 0xc9, 0x3, 0x48, 0xf6}};
static const GUID CLSID_AsfXAcmAudioErrorMaskingStrategy = {0xbfc3cd50,0x618f,0x11cf,{0x8b,0xb2,0x00,0xaa,0x00,0xb4,0xe2,0x20}};
static const GUID CLSID_CAsfStreamPropertiesObjectV2 = {0x818d0d47, 0x43, 0x4451, {0x92, 0x37, 0xda, 0xef, 0xbc, 0x48, 0x4f, 0x50}};
static const GUID CLSID_CAsfContentEncryptionObject = {0x2211b3fb, 0xbd23, 0x11d2, {0xb4, 0xb7, 0x00, 0xa0, 0xc9, 0x55, 0xfc, 0x6e}};

#ifdef WMA_L2_DEBUG_DUMP_LOG  // WMA L2 support
static kal_uint16 _file_name[128];
static uint32 _data_written;
static uint8  _dbg_str[128];
static FS_HANDLE  _file_handle = 0;
#endif

static const kal_uint8 SampleRateTable[] = {  // WMA L2 support
   0x00, /*8000*/   0x11,/* 11025 */ 0x12,/* 12000 */
   0x20, /*16000,*/ 0x21,/* 22050,*/ 0x22,/* 24000,*/
   0x40, /*32000,*/ 0x41,/* 44100,*/ 0x42 /* 48000 */
};

static uint32 asf_HnsQWORDtoMsDWORD (qword qw)
{
   uint32 msLo, msHi;

   msLo = (qw.dwHi*7296 + qw.dwLo)/10000;
   msHi = qw.dwHi*429496;

   return msLo + msHi;
}

static WMAERR asf_LoadHeaderObject(wmaMediaHandleInternal *ihdl)
{
   GUID  objectId;
   qword qwSize;
   uint32 cHeaders;
   uint8  align, arch;

   uint32 cbWanted;
   uint8 *pData;
   fileHeaderParseInfo *pInt;
   MHdl *hdl = (MHdl *) ihdl;

   pInt = &ihdl->sState.hdr_parse;
   cbWanted = MIN_OBJECT_SIZE + sizeof(uint32) + 2*sizeof(uint8);

   if (ihdl->fileSize < cbWanted)
      return WMAERR_INVALIDHEADER;

   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   pInt->currPacketOffset += cbWanted;

   LoadGUID(objectId, pData);
   LoadQWORD(qwSize, pData);
   LoadDWORD(cHeaders, pData);
   LoadBYTE(align, pData);
   LoadBYTE(arch, pData);

   if (!WMA_IsEqualGUID(&CLSID_CAsfHeaderObjectV0, &objectId) || align != 1 || arch != 2)
      return WMAERR_INVALIDHEADER;

   pInt->cbHeader = qwSize.dwLo;

   return WMAERR_OK;
}

static WMAERR asf_LoadObjectHeader(wmaMediaHandleInternal *ihdl, GUID *pObjectId, qword *pqwSize)
{
   uint8 *pData;
   uint32 cbWanted;
   fileHeaderParseInfo *pInt;
   MHdl *hdl = (MHdl *) ihdl;

   pInt = &ihdl->sState.hdr_parse;

   cbWanted = MIN_OBJECT_SIZE;
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   pInt->currPacketOffset += cbWanted;

   LoadGUID(*pObjectId, pData);
   LoadQWORD(*pqwSize, pData);

   return WMAERR_OK;
}

static WMAERR asf_LoadPropertiesObject(wmaMediaHandleInternal *ihdl, uint32 cbSize)
{
   qword qwPackets, qwPlayDuration, qwPreroll;
   uint32 dwMinPacketSize, dwMaxPacketSize;

   uint8  *pData;
   uint32 cbWanted;
   fileHeaderParseInfo *pInt;
   MHdl *hdl = (MHdl *) ihdl;

   pInt = &ihdl->sState.hdr_parse;
   cbSize -= MIN_OBJECT_SIZE;

   cbWanted = sizeof(GUID) + 6*sizeof(qword) + 4*sizeof(uint32);
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];

   // skip File ID, File Size and Creation Date
   pData += sizeof(GUID) + 2*sizeof(qword);
   LoadQWORD(qwPackets, pData);
   // Play Duration
   LoadQWORD(qwPlayDuration, pData);
   // skip send duration
   pData += sizeof(qword);
   // preroll
   LoadQWORD(qwPreroll, pData);
   // skip Flags
   pData += sizeof(uint32);
   LoadDWORD(dwMinPacketSize, pData);
   LoadDWORD(dwMaxPacketSize, pData);
   // skip Max Bitrate

   if ( (dwMinPacketSize != dwMaxPacketSize) ||
        (dwMinPacketSize == 0)               ||
        (qwPackets.dwLo == 0 && qwPackets.dwHi == 0) )
       return WMAERR_FAIL;

   pInt->cbPacketSize = dwMaxPacketSize;
   pInt->cPackets     = qwPackets.dwLo;
   pInt->msDuration   = asf_HnsQWORDtoMsDWORD(qwPlayDuration) - qwPreroll.dwLo;

   pInt->currPacketOffset += cbSize;

   return WMAERR_OK;
}

static WMAERR asf_LoadAudioObject(wmaMediaHandleInternal *ihdl, uint32 cbSize)
{
   GUID streamType, ecStrategy;
   uint32 cbTypeSpecific, cbErrConcealment;
   uint16 wStreamNum, wFormat;

   uint8  *pData;
   uint32 cbWanted;
   fileHeaderParseInfo *pInt;
   AsfXAcmAudioErrorMaskingData *pScramblingData;
   uint32 cbObjectOffset = 0;
   MHdl *hdl = (MHdl *) ihdl;

   pInt = &ihdl->sState.hdr_parse;
   cbSize -= MIN_OBJECT_SIZE;

   cbWanted = 2*sizeof(GUID) + sizeof(qword) + 3*sizeof(uint32) + sizeof(uint16);
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   cbObjectOffset += cbWanted;

   LoadGUID(streamType, pData);
   LoadGUID(ecStrategy, pData);
   // skip Time Offset
   pData += sizeof(qword);
   LoadDWORD(cbTypeSpecific, pData);
   LoadDWORD(cbErrConcealment, pData);
   LoadWORD(wStreamNum, pData);

   wStreamNum &= 0x7F;

   if ( !WMA_IsEqualGUID( &CLSID_AsfXStreamTypeAcmAudio, &streamType ) )
   {
      pInt->currPacketOffset += cbSize;   // Skip over the rest
      return WMAERR_OK;
   }

   if (wStreamNum==0)                     // Type specific
      return WMAERR_FAIL;

   pInt->wAudioStreamId = wStreamNum;     // Record the first audio stream

   if (cbTypeSpecific > 0)
   {
      cbWanted = cbTypeSpecific;
      autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &ihdl->pDataBuffer[0]);
      pData = &ihdl->pDataBuffer[0];
      cbObjectOffset += cbWanted;

      LoadWORD (wFormat ,pData);
      switch (wFormat)
      {
         case WAVE_FORMAT_WMAUDIO2:
            if (cbTypeSpecific < 28)  //sizeof(WMAUDIO2WAVEFORMAT)
                return WMAERR_FAIL;

            pInt->nVersion         = 2;
            LoadWORD (pInt->nChannels, pData);
            LoadDWORD(pInt->nSamplesPerSec, pData);
            LoadDWORD(pInt->nAvgBytesPerSec, pData);
            LoadWORD (pInt->nBlockAlign, pData);
            // skip Bit Per Sample, Codec Specific Data Size, and Sample pre block
            pData += 2*sizeof(uint16) + sizeof(uint32);
            LoadWORD (pInt->nEncodeOpt, pData);
            break;

         case WAVE_FORMAT_MSAUDIO1:
            if (cbTypeSpecific < 22)  //sizeof(MSAUDIO1WAVEFORMAT)
                return WMAERR_FAIL;

            pInt->nVersion         = 1;
            LoadWORD (pInt->nChannels, pData);
            LoadDWORD(pInt->nSamplesPerSec, pData);
            LoadDWORD(pInt->nAvgBytesPerSec, pData);
            LoadWORD (pInt->nBlockAlign, pData);
            // skip Bit Per Sample, Codec Specific Data Size, and Sample pre block
            pData += 2*sizeof(uint16) + sizeof(uint32);
            LoadWORD (pInt->nEncodeOpt, pData);
            break;

         default:  // unknown...
            return WMAERR_UNSUPPORT;
      }
   }

   if (pInt->nBlockAlign == 0)
      return WMAERR_FAIL;

   if (cbErrConcealment > 0)
   {
      if (WMA_IsEqualGUID(&CLSID_AsfXSignatureAudioErrorMaskingStrategy, &ecStrategy)) {
         cbWanted = sizeof(AsfXSignatureAudioErrorMaskingData);
      } else if (WMA_IsEqualGUID(&CLSID_AsfXAcmAudioErrorMaskingStrategy, &ecStrategy)) {
         cbWanted = 8;
      } else {
         return WMAERR_FAIL;
      }

      autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &ihdl->pDataBuffer[0]);
      pData = &ihdl->pDataBuffer[0];
      cbObjectOffset += cbErrConcealment;

      if (WMA_IsEqualGUID(&CLSID_AsfXAcmAudioErrorMaskingStrategy, &ecStrategy)) {
         pScramblingData = (AsfXAcmAudioErrorMaskingData *)pData;

         if (pScramblingData->span >1)
            return WMAERR_FAIL;
      } else if ( !WMA_IsEqualGUID(&CLSID_AsfXSignatureAudioErrorMaskingStrategy, &ecStrategy)) {
         return WMAERR_FAIL;
      }
   }

   pInt->currPacketOffset += cbSize;

   return WMAERR_OK;
}

static void asf_LoadContentDescriptionObject(wmaMediaHandleInternal *ihdl, uint32 cbSize)
{
   uint16 cbCDTitle, cbCDAuthor, cbCDCopyright, cbCDDescription, cbCDRating;
   uint8  *pData;
   uint32 cbWanted;
   fileHeaderParseInfo *pInt;
   MHdl *hdl = (MHdl *) ihdl;
   uint32 cbObjectOffset = 0;

   pInt = &ihdl->sState.hdr_parse;
   cbSize -= MIN_OBJECT_SIZE;

   cbWanted = 5*sizeof(uint16);
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   cbObjectOffset += cbWanted;

   LoadWORD(cbCDTitle, pData);
   LoadWORD(cbCDAuthor, pData);
   LoadWORD(cbCDCopyright, pData);
   LoadWORD(cbCDDescription, pData);
   LoadWORD(cbCDRating, pData);

   if (cbCDTitle > MAX_DESCRIPTION)
      cbWanted = MAX_DESCRIPTION;
   else
      cbWanted = cbCDTitle;
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset,
                            cbWanted, (uint8 *)&ihdl->description->title[0]);
   cbObjectOffset += cbCDTitle;

   if (cbCDAuthor > MAX_DESCRIPTION)
      cbWanted = MAX_DESCRIPTION;
   else
      cbWanted = cbCDAuthor;
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset,
                            cbWanted, (uint8 *)&ihdl->description->author[0]);
   cbObjectOffset += cbCDAuthor;

   if (cbCDCopyright > MAX_DESCRIPTION)
      cbWanted = MAX_DESCRIPTION;
   else
      cbWanted = cbCDAuthor;
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset,
                            cbWanted, (uint8 *)&ihdl->description->copyright[0]);
   cbObjectOffset += cbCDCopyright;

   if (cbCDDescription > MAX_DESCRIPTION)
      cbWanted = MAX_DESCRIPTION;
   else
      cbWanted = cbCDDescription;
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset,
                            cbWanted, (uint8 *)&ihdl->description->album[0]);
   ihdl->description->album[cbWanted] = '\0';
   cbObjectOffset += cbCDDescription;

   pInt->currPacketOffset += cbSize;
}

#if WMA_PARSE_ENCRYPTION
static WMAERR asf_LoadEncryptionObject(wmaMediaHandleInternal *ihdl, uint32 cbSize)
{
   uint32 cbWanted, cbLength;
   uint8 *pData;

   fileHeaderParseInfo *pInt;
   MHdl *hdl = (MHdl *) ihdl;
   uint32 cbObjectOffset = 0;

   pInt = &ihdl->sState.hdr_parse;
   cbSize -= MIN_OBJECT_SIZE;

   pInt->cbSecretData = 0;

   // Secret Data
   cbWanted = sizeof(uint32);
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   cbObjectOffset += cbWanted;

   LoadDWORD(cbWanted, pData);
   pInt->cbSecretData = cbWanted;
   if (cbWanted) {
      if (cbObjectOffset + cbWanted > cbSize)
         return WMAERR_FAIL;
      
      cbLength = cbWanted;
      if (cbWanted > 32)
         cbWanted = 32;
      autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &pInt->pbSecretData[0]);
      cbObjectOffset += cbLength;
      pInt->pbSecretData[cbWanted] = '\0';
   }

   // Type string
   cbWanted = sizeof(uint32);
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   cbObjectOffset += cbWanted;

   LoadDWORD(cbWanted, pData);
   if (cbWanted) {
      if (cbObjectOffset + cbWanted > cbSize)
         return WMAERR_FAIL;

      cbLength = cbWanted;
      if (cbWanted > 16)
         cbWanted = 16;
      autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &pInt->pbType[0]);
      cbObjectOffset += cbLength;
      pInt->pbType[cbWanted] = '\0';
   }

   // Key ID
   cbWanted = sizeof(uint32);
   if (cbObjectOffset + cbWanted > cbSize)
      return WMAERR_FAIL;;

   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   cbObjectOffset += cbWanted;

   LoadDWORD(cbWanted, pData);
   if (cbWanted) {
      if (cbObjectOffset + cbWanted > cbSize)
         return WMAERR_FAIL;

      cbLength = cbWanted;
      if (cbWanted > 32)
         cbWanted = 32;
      autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &pInt->pbKeyID[0]);
      cbObjectOffset += cbLength;
      pInt->pbKeyID[cbWanted] = '\0';
   }

   // License URL
   cbWanted = sizeof(uint32);
   if (cbObjectOffset + cbWanted > cbSize)
      return WMAERR_FAIL;

   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   cbObjectOffset += cbWanted;

   LoadDWORD(cbWanted, pData);

   if (cbWanted) {
      if (cbObjectOffset + cbWanted > cbSize)
         return WMAERR_FAIL;
      
      cbLength = cbWanted;
      if (cbWanted > 256)
         cbWanted = 256;
      autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->currPacketOffset + cbObjectOffset, cbWanted, &pInt->pbURL[0]);
      cbObjectOffset += cbLength;
      pInt->pbURL[cbWanted] = '\0';

      // Ignore others
   }

   pInt->currPacketOffset += cbSize;

   return WMAERR_OK;
}
#endif

static WMAERR asf_ParseAsfHeader(wmaMediaHandleInternal *ihdl)
{
   WMAERR wmarc;
   GUID   objId;
   qword  qwSize;
   fileHeaderParseInfo *pInt;
   uint8  fObject = 0;

   pInt = &ihdl->sState.hdr_parse;

   // Initialize current packet offset and Audio Stream ID
   pInt->currPacketOffset = 0;
   pInt->wAudioStreamId = 0;

   // ASF Header Object
   wmarc = asf_LoadHeaderObject(ihdl);
   if (wmarc != WMAERR_OK)
      return wmarc;

   pInt->cbHeader += DATA_OBJECT_SIZE;

   // Error: File too small
   if (ihdl->fileSize < pInt->cbHeader)
      return WMAERR_INVALIDHEADER;

   // Scan Header Objects
   while (pInt->currPacketOffset < pInt->cbHeader)
   {
      wmarc = asf_LoadObjectHeader(ihdl, &objId, &qwSize);
      if (wmarc != WMAERR_OK)
         return wmarc;

      if (WMA_IsEqualGUID(&CLSID_CAsfPropertiesObjectV2, &objId)) {
         wmarc = asf_LoadPropertiesObject(ihdl, qwSize.dwLo);
         if (wmarc != WMAERR_OK)
            return wmarc;
         fObject |= 0x01;
      } else if ( WMA_IsEqualGUID( &CLSID_CAsfStreamPropertiesObjectV1, &objId )
               || WMA_IsEqualGUID( &CLSID_CAsfStreamPropertiesObjectV2, &objId ) ) {
          if ( pInt->wAudioStreamId == 0  ){
             wmarc = asf_LoadAudioObject(ihdl, qwSize.dwLo);
             if (wmarc != WMAERR_OK)
                return wmarc;
             fObject |= 0x02;
          } else {
              pInt->currPacketOffset += qwSize.dwLo - MIN_OBJECT_SIZE;
          }
      } else if ( WMA_IsEqualGUID(&CLSID_CAsfContentDescriptionObjectV0, &objId)) {
      	 if (ihdl->description)
      	    asf_LoadContentDescriptionObject(ihdl, qwSize.dwLo);
      	 else
      	    pInt->currPacketOffset += qwSize.dwLo - MIN_OBJECT_SIZE;
      } else if ( WMA_IsEqualGUID(&CLSID_CAsfContentEncryptionObject, &objId)) {
#if WMA_PARSE_ENCRYPTION
         wmarc = asf_LoadEncryptionObject(ihdl, qwSize.dwLo);
         if (wmarc != WMAERR_OK)
            return wmarc;
#else
         return WMAERR_UNSUPPORT;
#endif
      } else {
          // skip over this object
          pInt->currPacketOffset += qwSize.dwLo - MIN_OBJECT_SIZE;
      }
   }

   pInt->cbLastPacketOffset = pInt->currPacketOffset;

   if (fObject != 0x03)
      return WMAERR_FAIL;

   return WMAERR_OK;
}

static uint32 asf_GetDataByType(wmaMediaHandleInternal *ihdl, uint8 LenType, uint32 Position, uint32 *Len) {
   uint8  *pData;
   uint16 w;
   uint32 dwValue, dw;
   MHdl *hdl = (MHdl *) ihdl;

   switch(LenType)
   {
      case 0x01:
         *Len =1;
         autGetBytesFromFile(hdl, ihdl->pstFSAL, Position, 1, &ihdl->pDataBuffer[0]);
         pData = &ihdl->pDataBuffer[0];
         dwValue =  (uint32)pData[0];
         break;
      case 0x02:
         *Len =2;
         autGetBytesFromFile(hdl, ihdl->pstFSAL, Position, 2, &ihdl->pDataBuffer[0]);
         pData = &ihdl->pDataBuffer[0];
         GetUnalignedWord(pData, w);
         dwValue =  (uint32)(w);
         break;
      case 0x03:
         *Len =4;
         autGetBytesFromFile(hdl, ihdl->pstFSAL, Position, 4, &ihdl->pDataBuffer[0]);
         pData = &ihdl->pDataBuffer[0];
         GetUnalignedDword(pData, dw);
         dwValue =  dw;
         break;
      default:
         dwValue = 0;
         *Len =0;
   }

   return dwValue;
}

static WMAERR asf_ParsePacketHeader(wmaMediaHandleInternal *ihdl)
{
   uint8 b;
   uint8  *pData;
   uint32 cbWanted;
   packetParseInfo *pParseInfoEx;
   asfFileStateInternal *pInt;
   MHdl *hdl = (MHdl *) ihdl;

   pInt = &ihdl->sState;
   pParseInfoEx = &pInt->ppex;

   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->hdr_parse.currPacketOffset, 1, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];

   // ParsePacket begins
   pParseInfoEx->fParityPacket = false;
   pParseInfoEx->cbParseOffset = 1;
   b = pData[0];

   pParseInfoEx->fEccPresent = (bool)( (b&0x80) == 0x80 );
   pParseInfoEx->bECLen = 0;

   //To check if error correction present, 1 means exist
   if (pParseInfoEx->fEccPresent)
   {
      // Opaque Data Present
      if (b&0x10)
      {
         pParseInfoEx->fParityPacket = true;
         return WMAERR_OK;
      }

      // Error Correction Length Type (00, other for future)
      if (b&0x60)
         return WMAERR_FAIL;

      // Error Correction Data Length (should 0010)
      pParseInfoEx->bECLen = (b&0x0f);
      if (pParseInfoEx->bECLen != 2)
         return WMAERR_FAIL;
      pParseInfoEx->cbParseOffset += (uint32) pParseInfoEx->bECLen;

      autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->hdr_parse.currPacketOffset + pParseInfoEx->cbParseOffset,
                                             1, &ihdl->pDataBuffer[0]);
      pData = &ihdl->pDataBuffer[0];
      b = pData[0];
      pParseInfoEx->cbParseOffset++;
   }

   // KH: should loose the constraint
   pParseInfoEx->bPacketLenType = (b&0x60)>>5;
   if (pParseInfoEx->bPacketLenType != 0 && pParseInfoEx->bPacketLenType != 2)
      return WMAERR_FAIL;

   // KH: should loose the constraint
   pParseInfoEx->bPadLenType = (b&0x18)>>3;
   if (pParseInfoEx->bPadLenType == 3)
      return WMAERR_FAIL;

   pParseInfoEx->bSequenceLenType = (b&0x06)>>1;
   pParseInfoEx->fMultiPayloads = (bool)(b&0x01);

   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->hdr_parse.currPacketOffset + pParseInfoEx->cbParseOffset,
                                            1, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   b = pData[0];
   pParseInfoEx->cbParseOffset++;

   pParseInfoEx->bOffsetLenType = 3;
   if (b != 0x5d)
   {
      // Stream Number Length Type shall be 01
      if ((b&0xc0) != 0x40)
         return WMAERR_FAIL;

      // Media Object Number Length Type shall be 01
      if ((b&0x30) != 0x10)
         return WMAERR_FAIL;

      // KH: Offset should be 11 (should loose the constraint)
      pParseInfoEx->bOffsetLenType = (b&0x0c)>>2;
      if (pParseInfoEx->bOffsetLenType == 0)
         return WMAERR_FAIL;

      if ((b&0x03) != 0x01)
         return WMAERR_FAIL;
   }

   pParseInfoEx->cbExplicitPacketLength = asf_GetDataByType(ihdl, pParseInfoEx->bPacketLenType,
            pInt->hdr_parse.currPacketOffset + pParseInfoEx->cbParseOffset, &cbWanted);
   pParseInfoEx->cbParseOffset += cbWanted;

   asf_GetDataByType(ihdl, pParseInfoEx->bSequenceLenType,
            pInt->hdr_parse.currPacketOffset + pParseInfoEx->cbParseOffset, &cbWanted);
   pParseInfoEx->cbParseOffset += cbWanted;

   pParseInfoEx->cbPadding = asf_GetDataByType(ihdl, pParseInfoEx->bPadLenType,
            pInt->hdr_parse.currPacketOffset + pParseInfoEx->cbParseOffset, &cbWanted);
   pParseInfoEx->cbParseOffset += cbWanted;

   // Send time(4 bytes) and duration(2 bytes)
   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->hdr_parse.currPacketOffset + pParseInfoEx->cbParseOffset,
                                         6, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   pParseInfoEx->cbParseOffset += 6;

//KH   GetUnalignedDword(&pData[0], ihdl->mh.current_time);
   GetUnalignedDword(&pData[0], pParseInfoEx->dwSCR);

   // skip duration

   // ParsePacketEx begins
   pParseInfoEx->bPayLenType = 0;
   pParseInfoEx->cPayloads = 1;

   if (pParseInfoEx->fMultiPayloads)
   {
      autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->hdr_parse.currPacketOffset + pParseInfoEx->cbParseOffset,
                                      1, &ihdl->pDataBuffer[0]);
      pData = &ihdl->pDataBuffer[0];
      pParseInfoEx->cbParseOffset ++;

      b = pData[0];

      //KH: must not be 0 (we should accept 11)
      pParseInfoEx->bPayLenType = (b&0xc0)>>6;
      if (pParseInfoEx->bPayLenType != 2 && pParseInfoEx->bPayLenType != 1)
         return WMAERR_FAIL;

      pParseInfoEx->cPayloads = (uint32)(b&0x3f);
      if (pParseInfoEx->cPayloads == 0)
         return WMAERR_FAIL;
   }

   return WMAERR_OK;
}

static WMAERR asf_ParsePayloadHeader(wmaMediaHandleInternal *ihdl)
{
   uint32 dwPayloadSize;
   asfFileStateInternal *pInt;
   packetParseInfo *pParseInfoEx;
   payloadParseInfo *pPayload;
   MHdl *hdl = (MHdl *) ihdl;

   uint8  *pData;
   uint32 cbWanted;

   pInt = &ihdl->sState;
   pParseInfoEx = &pInt->ppex;
   pPayload = &pInt->payload;

   pPayload->cbParseOffset = pParseInfoEx->cbParseOffset;

   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->hdr_parse.currPacketOffset + pPayload->cbParseOffset,
                                   2, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   pPayload->cbParseOffset += 2;

   pPayload->bStreamId = (pData[0])&0x7f;

   asf_GetDataByType(ihdl, pParseInfoEx->bOffsetLenType,
            pInt->hdr_parse.currPacketOffset + pPayload->cbParseOffset, &cbWanted);
   pPayload->cbParseOffset += cbWanted;

   autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->hdr_parse.currPacketOffset + pPayload->cbParseOffset,
                                               1, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   pPayload->cbParseOffset++;

   pPayload->cbRepData = pData[0];
   pPayload->cbParseOffset += pPayload->cbRepData;

   if (pPayload->cbRepData == 1)
      pPayload->bIsCompressedPayload = 1;
   else
      pPayload->bIsCompressedPayload =0;

   if (pParseInfoEx->fMultiPayloads)
   {
      dwPayloadSize = asf_GetDataByType(ihdl, pParseInfoEx->bPayLenType,
               pInt->hdr_parse.currPacketOffset + pPayload->cbParseOffset, &cbWanted);
      pPayload->cbParseOffset += cbWanted;

   } else if (pParseInfoEx->cbExplicitPacketLength > 0) {
      dwPayloadSize = pParseInfoEx->cbExplicitPacketLength - pPayload->cbParseOffset
                      - pParseInfoEx->cbPadding;
   } else {
      dwPayloadSize = pInt->hdr_parse.cbPacketSize - pPayload->cbParseOffset
                      - pParseInfoEx->cbPadding;
   }

   pPayload->cbPayloadSize = (uint16)dwPayloadSize;
   pParseInfoEx->cbParseOffset = pPayload->cbParseOffset + pPayload->cbPayloadSize;

   if (pParseInfoEx->cbParseOffset > pInt->hdr_parse.cbPacketSize
       || (pParseInfoEx->cbParseOffset == pInt->hdr_parse.cbPacketSize
          && pInt->iPayload < pParseInfoEx->cPayloads - 1))
   {
      return WMAERR_CORRUPTDATA;
   }
   return WMAERR_OK;
}

static wmaFileStatus wma_UpdateNewPayload (wmaMediaHandleInternal *ihdl)
{
   WMAERR wmarc;
   asfFileStateInternal *pInt;
   MHdl *hdl = (MHdl *) ihdl;

   pInt = &ihdl->sState;

   do
   {
      switch (pInt->parse_state)
      {
         case csWMA_NewAsfPacket:
            pInt->hdr_parse.currPacketOffset = pInt->hdr_parse.nextPacketOffset;
            pInt->hdr_parse.nextPacketOffset += pInt->hdr_parse.cbPacketSize;

            // Add by KH to detect the end of file
            if ( (pInt->hdr_parse.currPacketOffset >= pInt->hdr_parse.cbLastPacketOffset) ||
                 (pInt->hdr_parse.nextPacketOffset > ihdl->fileSize) )
            {
               hdl->DataFinished(hdl);
               return cWMA_NoMoreFrames;
            }

            wmarc = asf_ParsePacketHeader (ihdl);

            if (wmarc != WMAERR_OK)
               return cWMA_BadPacketHeader;

            if (pInt->ppex.fParityPacket && pInt->ppex.fEccPresent)
               break;

            pInt->parse_state = csWMA_DecodePayloadStart;
            pInt->iPayload = 0;
            break;

         case csWMA_DecodePayloadStart:
            if (pInt->iPayload >= pInt->ppex.cPayloads)
            {
               pInt->parse_state = csWMA_NewAsfPacket;
               break;
            }

            wmarc = asf_ParsePayloadHeader(ihdl);
            if (wmarc != WMAERR_OK)
            {
               pInt->parse_state = csWMA_DecodePayloadEnd;
               break;
            }

            if (pInt->payload.cbRepData != 1)
               pInt->parse_state = csWMA_DecodePayload;
            else
               pInt->parse_state = csWMA_DecodeCompressedPayload;
            break;

         case csWMA_DecodePayload:
            if (pInt->payload.bStreamId !=pInt->hdr_parse.wAudioStreamId)
            {
               pInt->parse_state = csWMA_DecodePayloadEnd;
               break;
            }

            // A payload must be a multiple of audio "packets"
            //if (pInt->payload.cbPayloadSize % pInt->hdr_parse.nBlockAlign != 0) { // WMA L2 support
            //   pInt->parse_state = csWMA_DecodePayloadEnd;
            //   return cWMA_BrokenFrame;
            //}

            pInt->cbPayloadOffset = pInt->hdr_parse.currPacketOffset + pInt->payload.cbParseOffset;
            pInt->bBlockStart     = true;
            pInt->cbBlockLeft     = pInt->hdr_parse.nBlockAlign;
            pInt->cbPayloadLeft   = pInt->payload.cbPayloadSize - pInt->cbBlockLeft;
            pInt->parse_state = csWMA_DecodePayloadHeader;
            return cWMA_NoErr;

         case csWMA_DecodePayloadEnd:
            pInt->iPayload++;
            pInt->parse_state = csWMA_DecodePayloadStart;
            break;

         case csWMA_DecodeCompressedPayload:
            if (pInt->payload.bStreamId != pInt->hdr_parse.wAudioStreamId)
            {
               pInt->parse_state = csWMA_DecodePayloadEnd;
               break;
            }

            // A payload must be a multiple of audio "packets"
            //if (pInt->payload.cbPayloadSize % pInt->hdr_parse.nBlockAlign != 0) { // WMA L2 support
            //   pInt->parse_state = csWMA_DecodePayloadEnd;
            //   return cWMA_BrokenFrame;
            //}

            pInt->cbPayloadOffset = pInt->hdr_parse.currPacketOffset + pInt->payload.cbParseOffset;
            pInt->bBlockStart     = true;
            pInt->cbBlockLeft     = pInt->hdr_parse.nBlockAlign;
            pInt->payload.wBytesRead = 0;
            pInt->payload.bSubPayloadState = 1;
            pInt->parse_state = csWMA_DecodePayloadHeader;
            return cWMA_NoErr;

         default:
            return cWMA_Internal;
      }
   } while (1);

   return cWMA_NoErr;
}

static void wmaDataRequest( wmaMediaHandleInternal *ihdl )
{
   MHdl *hdl = (MHdl *) ihdl;

   if ( hdl->waiting || hdl->eof || (ihdl->end_status == MEDIA_END) )
      return;

   if ( hdl->GetFreeSpace(hdl) >= WMA_RB_REQ_THR ) {
      mhdlException( hdl, MEDIA_DATA_REQUEST );
      hdl->waiting = true;
   }
}

static void wmaIncTime( MHdl *hdl, uint32 num_bytes )
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if 0
}

static kal_int32 mediaWMAGetDSPDataCnt( wmaMediaHandleInternal *ihdl)
{
   int32 I;

   do {
      I = (int32)*WMA_BUFFER_DSP_READ;
   } while( I != (int32)*WMA_BUFFER_DSP_READ );

   I = (int32)ihdl->WMA_DSP_write - I;

   if( I < 0 )
      I += ihdl->mh.dsp_rb_size;

   return I;
}

static void wmaWriteZero( wmaMediaHandleInternal *ihdl )
{
   int32 I, count, len;
   uint16 rb_w;

   rb_w = *WMA_BUFFER_MCU_WRITE;

   do {
      I = (int32)*WMA_BUFFER_DSP_READ;
   } while( I != (int32)*WMA_BUFFER_DSP_READ );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += ihdl->mh.dsp_rb_size;

   count = (int32)(ihdl->mh.dsp_rb_end - rb_w);

   if(count > I)
      count = I;

   len = I;

   DSP_WRITE( DSP_DM_ADDR(PAGE_NUM, rb_w), 0x1111 );
   for( I = 1; I < count; I++ )
      DSP_WRITE( IDMA_SHORT_ADDR, 0x1111 );

   rb_w += (uint16)count;
   if( rb_w >= ihdl->mh.dsp_rb_end )
      rb_w = ihdl->mh.dsp_rb_base;
   *WMA_BUFFER_MCU_WRITE = rb_w;

   count = len - count;
   if( count > 0 ) {
     DSP_WRITE( DSP_DM_ADDR(PAGE_NUM, rb_w), 0x1111 );
     for( I = 1; I < count; I++ )
        DSP_WRITE( IDMA_SHORT_ADDR, 0x1111 );

     *WMA_BUFFER_MCU_WRITE = rb_w + (uint16)count;
   }
}

static void wmaHisr( void *data )
{
   MHdl *hdl;
   wmaMediaHandleInternal *ihdl = (wmaMediaHandleInternal *)data;

   hdl = (MHdl *) ihdl;

   if(*WMA_Soft_Reset == 1)
      return;

   if(*WMA_NUM_CHANNELS == 0x4321){ // WMA L2 support, reload table
      ihdl->wReloadTabBase = *WMA_BYTES_PER_SECONDS;
      ihdl->wReloadTabLen  = (*WMA_ENCODE_OPT) * 2;
      _idma_load_pm( 3, ihdl->wReloadTabBase, ihdl->wReloadTabLen, (const kal_uint8 *)(ihdl->pmdllptr->Array_Addr+(ihdl->wReloadTabBase*2)));
      *WMA_NUM_CHANNELS = 0;
      return;
   }

   if (ihdl->end_status == MEDIA_TERMINATED)
      return;

   if (*WMA_STATUS == SHERIEF_STATE_IDLE) {      
      if (ihdl->end_status == MEDIA_STOP_TIME_UP){
   	  	kal_prompt_trace( MOD_L1SPHISR, " WMA_L1AUDIO_IDLE_STATE ");
        mhdlException( hdl, MEDIA_STOP_TIME_UP );
   	  }else{
   	  	  hdl->state = WMA_STATE_ENDING;
          kal_prompt_trace( MOD_L1SPHISR, " WMA_L1AUDIO_IDLE_STATE ");
          mhdlException( hdl, MEDIA_END );
      }
      ihdl->end_status = MEDIA_TERMINATED;
      return;
   }

   if (ihdl->end_status == MEDIA_END || ihdl->end_status == MEDIA_STOP_TIME_UP)
      return;

   if (*WMA_DEBUG == 0x9999) {
      *WMA_DEBUG = 0x0000;
#if Hardeare_Mute
      *AFE_AMCU_CON1 &= ~0x0C;
#endif      
   } else if (*WMA_DEBUG != 0x0000) {      
#if Hardeare_Mute
      *AFE_AMCU_CON1 |= 0x0C;
#endif
      if (!hdl->waiting) {
         hdl->waiting = true;
         mhdlException( hdl, MEDIA_ERROR );
      }
      return;
   }

   if (hdl->dsp_rb_base == 0xFFFF) {   // DSP RingBuf initialization
      hdl->dsp_rb_base = *WMA_BUFFER_BASE;
      hdl->dsp_rb_size = *WMA_BUFFER_LENGTH;
      hdl->dsp_rb_end = hdl->dsp_rb_base + hdl->dsp_rb_size;
      if (hdl->write)
         ihdl->dspBufTime = ((int)ihdl->sState.ppex.dwSCR - ihdl->bufStartTime) * hdl->dsp_rb_size * 2 / hdl->write;
   }
#ifdef WMA_L2_DEBUG_DUMP_LOG  // WMA L2 support
   if((*WMA_STATUS == SHERIEF_STATE_RUNNING) &&(*WMA_VERSION_NUMBER == 0x1234)){ // log checksum info.
   	  if(wmaCnt == 0xFFFFFFFF){
   	     wmaCnt = 0;
   	  }else if(wmaCnt < WMA_CHECKSUM_MAX_SIZE){
   	  	if(*WMA_PACKET_LENGTH == 0x1DD6)
   	  	{
   	  		*WMA_VERSION_NUMBER = 1;
   	  	}
             wmaChecksumInfo[wmaCnt++] = *WMA_PACKET_LENGTH;
             wmaChecksumInfo[wmaCnt++] = *WMA_SAMPLING_RATE;
         }
	  *WMA_VERSION_NUMBER = 0;
   }
#endif

   if( !ihdl->WMA_decode_EOF ){
      autWriteDataToDSP( hdl, (uint16*)WMA_BUFFER_MCU_WRITE, (uint16*)WMA_BUFFER_DSP_READ, PAGE_NUM, wmaIncTime);
      if( !((hdl->GetDataCount(hdl) < 2) && (!hdl->eof) )) {
   // update current time
         ihdl->uCurFrame++;
         ihdl->mh.current_time = ihdl->uCurFrame * 2048 * 1000 / ihdl->sState.hdr_parse.nSamplesPerSec;
      }
   }else{
      kal_int32 data_Cnt;
      kal_int32 remainFrame;
      data_Cnt = mediaWMAGetDSPDataCnt(ihdl);
      remainFrame = ihdl->WMA_Total_Frame - *WMA_TOTAL_FRAME;
      if(ihdl->WMA_DSP_data_Cnt >= data_Cnt){
         ihdl->WMA_DSP_data_Cnt =  data_Cnt;
      }else{
         ihdl->WMA_DSP_data_Cnt = 0;
      }
      *WMA_VERSION_NUMBER = 0xFFFE;   // Enable DSP to check the end of file
      if((ihdl->WMA_DSP_data_Cnt <= 0) || (remainFrame <= 1 && ihdl->WMA_Packet_Loss)){
         if(ihdl->WMA_Packet_Loss){
            *WMA_ENCODE_OPT = (uint16)ihdl->sState.hdr_parse.nEncodeOpt;
            *WMA_BYTES_PER_SECONDS = (uint16)ihdl->sState.hdr_parse.nAvgBytesPerSec;
            *WMA_PACKET_LENGTH = (uint16)ihdl->sState.hdr_parse.nBlockAlign;
            *WMA_SAMPLING_RATE = (uint16)ihdl->sState.hdr_parse.nSamplesPerSec;
            *WMA_NUM_CHANNELS = (uint16)ihdl->sState.hdr_parse.nChannels;
            *WMA_VERSION_NUMBER = (uint16)ihdl->sState.hdr_parse.nVersion;
            *WMA_Soft_Reset = 1;
            ihdl->WMA_decode_EOF = false;
            ihdl->WMA_Total_Frame = 0;
            ihdl->WMA_Packet_Loss = false;
         }else{         
             ihdl->end_status = MEDIA_END;
             if( *WMA_STATUS == SHERIEF_STATE_RUNNING )
                *WMA_STATUS = SHERIEF_STATE_END;
             kal_prompt_trace( MOD_L1SPHISR, " WMA_L1AUDIO_END_STATE ");
          }
      }else {
      	 if( !((hdl->GetDataCount(hdl) < 2) && (!hdl->eof) )) {
   // update current time
            ihdl->uCurFrame++;
            ihdl->mh.current_time = ihdl->uCurFrame * 2048 * 1000 / ihdl->sState.hdr_parse.nSamplesPerSec;
         }
         wmaWriteZero(ihdl);
      }

      return;
   }

//KH   if (hdl->current_time >= hdl->stop_time)
   //if (ihdl->sState.ppex.dwSCR >= hdl->stop_time)
   //   hdl->eof = true;

   if (ihdl->mh.current_time >= hdl->stop_time){
   	  ihdl->end_status = MEDIA_STOP_TIME_UP;
   	  if( *WMA_STATUS == SHERIEF_STATE_RUNNING )
            *WMA_STATUS = SHERIEF_STATE_END;
      kal_prompt_trace( MOD_L1SPHISR, " WMA_L1AUDIO_STOP_TIME_UP_STATE ");
      return;
   }

   if(ihdl->WMA_Packet_Loss && (hdl->GetDataCount(hdl) < 2)){
      ihdl->WMA_decode_EOF = KAL_TRUE;
      hdl->read = 0;
      hdl->write = 0;
      return;
   }
      
   
   if( hdl->GetDataCount(hdl) < 2 && hdl->eof) {
      ihdl->WMA_DSP_write = *WMA_BUFFER_MCU_WRITE;
      ihdl->WMA_DSP_data_Cnt = mediaWMAGetDSPDataCnt(ihdl);
      if(ihdl->WMA_DSP_data_Cnt){
         ihdl->WMA_decode_EOF = KAL_TRUE;
         wmaWriteZero(ihdl);
         return;
      }else {
         ihdl->end_status = MEDIA_END;
         if( *WMA_STATUS == SHERIEF_STATE_RUNNING )
            *WMA_STATUS = SHERIEF_STATE_END;
         kal_prompt_trace( MOD_L1SPHISR, " WMA_L1AUDIO_END_STATE ");
      }

   }

   wmaDataRequest(ihdl);
}

static void wmaOpenDevice( wmaMediaHandleInternal *ihdl )
{
   uint8 I;
   kal_uint32 sr_index = 0;

   *DP_AUDIO_CTRL2 |= DP_PCM_R_DIS;
   mhdlDisallowSleep( (MHdl*)ihdl );

   switch( ihdl->sState.hdr_parse.nSamplesPerSec / 1000 ){             // update sample rate index of control table
      case 7: case 8:  sr_index = 0;
         break;
      case 10: case 11: sr_index = 1;
         break;
      case 12: sr_index = 2;
         break;
      case 15: case 16: sr_index = 3;
         break;
      case 21: case 22: sr_index = 4;
         break;
      case 23: case 24: sr_index = 5;
         break;
      case 31: case 32: sr_index = 6;
         break;
      case 43: case 44: sr_index = 7;
         break;
      case 47: case 48: sr_index = 8;
         break;

      default:
         ASSERT(KAL_FALSE);
   }

   AM_AudioPlaybackOn( ASP_TYPE_WMA, SampleRateTable[sr_index] );

   for (I = 0; ; I++)
   {
      if ((*WMA_STATUS == SHERIEF_STATE_RUNNING) || (ihdl->end_status != MEDIA_NONE))
         break;

      ASSERT_REBOOT( I < 100 );
      kal_sleep_task( 2 );
   }
}

static void wmaCloseDevice( wmaMediaHandleInternal *ihdl )
{
   uint8 I;

#if Hardeare_Mute
   *AFE_AMCU_CON1 &= ~0x0C;
#endif

   ihdl->end_status = MEDIA_TERMINATED;

   for (I = 0; ; I++)
   {
      if (*WMA_STATUS == SHERIEF_STATE_IDLE ){
         kal_trace( TRACE_STATE, L1AUDIO_IDLE_STATE );
         break;
      }

      ASSERT_REBOOT( I < 100 );
      kal_sleep_task( 2 );
   }

   *WMA_CNTROL_WORD = WMA_OFF;
   *DP_AUDIO_CTRL2 &= ~DP_PCM_R_DIS;

   AM_AudioPlaybackOff( true );
   mhdlAllowSleep( (MHdl*)ihdl );
}

static uint32 GetTimeByPacket(wmaMediaHandleInternal *ihdl, uint32 packetNum)
{
   asfFileStateInternal *pInt;
   uint8 *pData;
   uint32 packetOffset, dwSCR;
   MHdl *hdl = (MHdl *) ihdl;

   pInt = &ihdl->sState;
   packetOffset = pInt->hdr_parse.cbHeader + packetNum*pInt->hdr_parse.cbPacketSize;

   autGetBytesFromFile(hdl, ihdl->pstFSAL, packetOffset, 5, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   packetOffset += 5;

   // To check if error correction present, 1 means exist
   // Use linear interpolation
   if ((pData[0]&0x80) == 0x80 )
   {
      // Opaque Data Present, Error Correction Length Type (00, other for future)
      // Error Correction Data Length (should 0010)
      if ( (pData[0]&0x10) || (pData[0]&0x60) || ((pData[0]&0x0f) != 2) )
         return packetNum*(pInt->hdr_parse.msDuration / pInt->hdr_parse.cPackets);
   }

   // Packet Length Type
   packetOffset += (pData[3]&0x60)>>5;
   if ( (pData[3]&0x60) == 0x60 )
      packetOffset++;

   // KH: should loose the constraint
   packetOffset += (pData[3]&0x18)>>3;
   if ((pData[3]&0x18) == 0x18)
      packetOffset++;

   packetOffset += (pData[3]&0x06)>>1;
   if ((pData[3]&0x06) == 0x06)
      packetOffset++;

   autGetBytesFromFile(hdl, ihdl->pstFSAL, packetOffset, 4, &ihdl->pDataBuffer[0]);
   pData = &ihdl->pDataBuffer[0];
   GetUnalignedDword(&pData[0], dwSCR);

   return dwSCR;
}

static kal_bool wmaFileSeek( wmaMediaHandleInternal *ihdl )
{
   asfFileStateInternal *pInt;
   uint32 prePacket, postPacket, midPacket;
   uint32 preSCR, postSCR, midSCR;
   uint32 bufPacket;

   pInt = &ihdl->sState;

   prePacket = 0;
   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->fileSize);
   postPacket = (ihdl->fileSize - pInt->hdr_parse.cbHeader) / pInt->hdr_parse.cbPacketSize;
   if (postPacket > pInt->hdr_parse.cPackets)
      postPacket = pInt->hdr_parse.cPackets;
   if (postPacket > 0)
      postPacket--;

   preSCR = GetTimeByPacket(ihdl, prePacket);
   postSCR = GetTimeByPacket(ihdl, postPacket);

   if (postSCR < ihdl->mh.start_time)
      return KAL_FALSE;

   do {
      midPacket = (prePacket + postPacket) >> 1;
      midSCR = GetTimeByPacket(ihdl, midPacket);

      if (ihdl->mh.start_time < midSCR) {
         postPacket = midPacket;
         postSCR = midSCR;
      } else {
         prePacket = midPacket;
         preSCR = midSCR;
      }
   } while ((prePacket+1) < postPacket);


   bufPacket = 0;
   if (prePacket >= bufPacket)
      prePacket -= bufPacket;
   else
      prePacket = 0;

   ihdl->bufStartTime = GetTimeByPacket(ihdl, prePacket);
   pInt->hdr_parse.nextPacketOffset = pInt->hdr_parse.cbHeader
                                     + prePacket*pInt->hdr_parse.cbPacketSize;
   pInt->parse_state = csWMA_NewAsfPacket;

   return KAL_TRUE;
}

static void wmaSwapPutData(wmaMediaHandleInternal *ihdl, int32 num_bytes)
{
   int32 startPos, count;
   uint8 temp;
   uint8 *prePtr, *postPtr;

   if (num_bytes <= 0)
      return;

   count = num_bytes;
   startPos = ihdl->mh.write;
   if (startPos & 0x01) {
      startPos--;
      count++;
   }
   count = count >> 1;

   prePtr  = &ihdl->mh.rb_base[startPos];
   postPtr = prePtr + 1;

   for ( ; count>0; count--) {
      temp = *prePtr;
      *prePtr = *postPtr;
      *postPtr = temp;
      prePtr += 2;
      postPtr += 2;
   }
}

static WMAERR wmaFileGetPayloadData (wmaMediaHandleInternal *ihdl, uint8 *pBuf, uint32 *pcbBuffer, uint32 buf_len )
{
   asfFileStateInternal *pInt;
   MHdl *hdl = (MHdl *) ihdl;
   wmaFileStatus rc;
   asfParseState parse_state;
   uint32 num_bytes = buf_len;
   uint8  *pData;

   pInt = &ihdl->sState;
   *pcbBuffer = 0;

   do
   {
      switch (pInt->payload.bIsCompressedPayload)
      {
         case 1:
            do
            {
               switch (pInt->payload.bSubPayloadState)
               {
                  case 1: // Compressed payload just started
                     // To read subpayload length
                     autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->cbPayloadOffset, 1, &ihdl->pDataBuffer[0]);
                     pData = &ihdl->pDataBuffer[0];
                     pInt->cbPayloadOffset++;
                     pInt->bBlockStart = true;
                     pInt->cbBlockLeft = pInt->hdr_parse.nBlockAlign;

                     pInt->payload.bNextSubPayloadSize = pData[0];
                     pInt->payload.wSubpayloadLeft = pInt->payload.bNextSubPayloadSize;
                     if (pInt->payload.wSubpayloadLeft > 0)
                        pInt->payload.wSubpayloadLeft -= (uint16)pInt->cbBlockLeft;

                     if (pInt->payload.cbPayloadSize > pInt->payload.bNextSubPayloadSize)
                        pInt->payload.wBytesRead = pInt->payload.bNextSubPayloadSize+1;
                     else if (pInt->payload.cbPayloadSize == pInt->payload.bNextSubPayloadSize)
                        pInt->payload.wBytesRead = pInt->payload.bNextSubPayloadSize;

                     pInt->payload.bSubPayloadState = 2;
                     break;

                  case 2: // Subpayload started
                     if (pInt->cbBlockLeft == 0 && pInt->payload.wSubpayloadLeft == 0) {
                        pInt->payload.bSubPayloadState =3;
                        break;
                     } else {
                        if (pInt->cbBlockLeft == 0) {
                           if (pInt->payload.wSubpayloadLeft == 0)
                              return WMAERR_NEWPACKET;

                           if (pInt->payload.wSubpayloadLeft > 0)
                              pInt->payload.wSubpayloadLeft -= (uint16) pInt->hdr_parse.nBlockAlign;

                           pInt->bBlockStart = true;
                           pInt->cbBlockLeft = pInt->hdr_parse.nBlockAlign;
                        }
                        if (num_bytes > pInt->cbBlockLeft)
                           num_bytes = pInt->cbBlockLeft;

                        if (num_bytes > buf_len)
                           num_bytes = buf_len;

                        num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->cbPayloadOffset, num_bytes, pBuf);

                        if (num_bytes == -1)
                           return WMAERR_FAIL;

                        *pcbBuffer = num_bytes;
                        wmaSwapPutData(ihdl, num_bytes);

                        pInt->cbPayloadOffset += num_bytes;
                        pInt->cbBlockLeft -= num_bytes;

                        if (pInt->bBlockStart) {
                           pInt->bBlockStart = false;
                           return WMAERR_NEWPACKET;
                        }

                        return WMAERR_OK;
                     }
                     break;

                  case 3: // Subpayload finished
                     if (pInt->payload.cbPayloadSize > pInt->payload.wBytesRead)
                     {  // There are payloads to decode
                        // To read subpayload length
                        autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->cbPayloadOffset, 1, &ihdl->pDataBuffer[0]);
                        pData = &ihdl->pDataBuffer[0];
                        pInt->cbPayloadOffset++;
                        pInt->bBlockStart = true;
                        pInt->cbBlockLeft = pInt->hdr_parse.nBlockAlign;

                        pInt->payload.bNextSubPayloadSize = pData[0];
                        pInt->payload.wSubpayloadLeft = pInt->payload.bNextSubPayloadSize;
                        if (pInt->payload.wSubpayloadLeft > 0)
                           pInt->payload.wSubpayloadLeft -= (uint16)pInt->cbBlockLeft;

                        pInt->payload.wBytesRead += pInt->payload.bNextSubPayloadSize+1;
                        pInt->payload.bSubPayloadState =2;
                     }
                     else
                        pInt->payload.bSubPayloadState =4; // all subpayloads finished
                     break;

                  case 4: // All Subpayloads finished
                     parse_state = pInt->parse_state;
                     pInt->payload.bSubPayloadState =0;
                     pInt->cbPayloadLeft =0;
                     pInt->payload.bIsCompressedPayload =0;

                     pInt->parse_state = csWMA_DecodePayloadEnd;
                     rc = wma_UpdateNewPayload(ihdl);

                     pInt->parse_state = parse_state;  //restore
                     if (rc == cWMA_NoMoreFrames)
                        return WMAERR_NEWPACKET;
                     else if (rc != cWMA_NoErr)
                        return WMAERR_FAIL;
                     break;

                  default:
                     return WMAERR_NEWPACKET;
               }
            } while(1);
            break;

         default :
            if (pInt->cbBlockLeft == 0 && pInt->cbPayloadLeft == 0)
            {
               parse_state = pInt->parse_state;
               pInt->parse_state = csWMA_DecodePayloadEnd;

               rc = wma_UpdateNewPayload(ihdl);
               if (rc == cWMA_NoMoreFrames)
                  return WMAERR_NEWPACKET;
               else if (rc != cWMA_NoErr)
                  return WMAERR_FAIL;

               pInt->parse_state = parse_state; // restore

               if (pInt->payload.bIsCompressedPayload == 1)
                  break;
            }

            // Add by KH: Peek the packet number and frame_in_packet
        /*    if (pInt->bBlockStart) { // WMA L2 support
               autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->cbPayloadOffset, 1, &ihdl->pDataBuffer[0]);
               if ((ihdl->pDataBuffer[0]&0x0f)!= (ihdl->uPacketNum & 0x0F)) {
                  if (pInt->payload.fInvalidFrame) {
                     pInt->parse_state = csWMA_DecodePayloadEnd;
                     return WMAERR_OK;
                  } else {
                     pInt->payload.fInvalidFrame = true;
                     ihdl->fPacketLost = true;
                  }
               } else {
                  pInt->payload.fInvalidFrame = false;
                  ihdl->uPacketNum++;
               }
            }
          */
#if defined (WMA_PACKET_LOSS_HANDLING)
            if(((uint16)ihdl->sState.hdr_parse.nEncodeOpt & 0x02)){
               if ((pInt->bBlockStart) || (pInt->cbBlockLeft == 0)) { // WMA L2 support
                  autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->cbPayloadOffset, 1, &ihdl->pDataBuffer[0]);                  
                  
                  if(0xFFFFFFFF == ihdl->uPacketNum){
                     ihdl->uPacketNum = (ihdl->pDataBuffer[0]&0xF0)>>4;
                     ihdl->WMA_Total_Frame += (ihdl->pDataBuffer[0]&0x0F);
                  }else{
                     ihdl->uPacketNum++;
                     ihdl->uPacketNum &= 0x0F;
                     if (((ihdl->pDataBuffer[0]&0xF0)>>4)!= ihdl->uPacketNum ) {
                        /*if (pInt->payload.fInvalidFrame) {
                           pInt->parse_state = csWMA_DecodePayloadEnd;
                           return WMAERR_OK;
                        } else {
                           pInt->payload.fInvalidFrame = true;
                           ihdl->fPacketLost = true;
                        }*/
                        ihdl->WMA_Packet_Loss = true;                       
                        ihdl->uPacketNum = ((ihdl->pDataBuffer[0]&0xF0)>>4)-1;
                        ihdl->uPacketNum &= 0x0F;
                        return WMAERR_OK;
                     } else {
                       // pInt->payload.fInvalidFrame = false;
                       // ihdl->uPacketNum++;
                          ihdl->WMA_Total_Frame += (ihdl->pDataBuffer[0]&0x0F);
                     }
                  }
               }
            }
#endif
            // return as much as we currently have left
            if (pInt->cbBlockLeft == 0)
            {
               // done with the file
               if (pInt->cbPayloadLeft == 0)
                  return WMAERR_NEWPACKET;

               pInt->cbPayloadLeft -= pInt->hdr_parse.nBlockAlign;
               pInt->bBlockStart = true;
               pInt->cbBlockLeft = pInt->hdr_parse.nBlockAlign;
            }
            if (num_bytes > pInt->cbBlockLeft)
               num_bytes = pInt->cbBlockLeft;

            if (num_bytes > buf_len)
               num_bytes = buf_len;

            num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, pInt->cbPayloadOffset, num_bytes, pBuf);
            if (num_bytes == -1)
               return WMAERR_FAIL;

            *pcbBuffer = num_bytes;
            wmaSwapPutData(ihdl, num_bytes);

            pInt->cbPayloadOffset += num_bytes;
            pInt->cbBlockLeft     -= num_bytes;

            if (pInt->bBlockStart) {
               pInt->bBlockStart = false;
               return WMAERR_NEWPACKET;
            }
            return WMAERR_OK;
      }

   } while(1);

   return WMAERR_OK;
}

static wmaFileStatus wmaDecodePayloadData( wmaMediaHandleInternal *ihdl, uint8 *pBuf, uint32 *len, uint32 buf_len )
{
   asfFileStateInternal *pInt;
   WMAERR wmarc;
   wmaFileStatus rc;

   pInt = &ihdl->sState;

   do
   {
      switch (pInt->parse_state)
      {
         case csWMA_DecodePayloadHeader:
            pInt->parse_state = csWMA_DecodeLoopStart;
            break;

         case csWMA_DecodeLoopStart:
            wmarc = wmaFileGetPayloadData (ihdl, pBuf, len, buf_len);

            if (wmarc == WMAERR_NEWPACKET) {
               pInt->parse_state = csWMA_DecodePayloadHeader;
               return cWMA_NoErr;
            } else if (wmarc == WMAERR_FAIL) {
               return cWMA_BadPacketHeader;
            }
            return cWMA_NoErr;

         default:
            *len = 0;

            rc = wma_UpdateNewPayload(ihdl);
            if (rc != cWMA_NoErr)
               return rc;

            break;
      }
   } while(1);

   return cWMA_NoErr;
}

static Media_Status wmaFillMediaBuf(wmaMediaHandleInternal *ihdl, uint8 *pBuf, uint32 buf_len)
{
   uint32 len;
   wmaFileStatus res;
   MHdl *hdl = (MHdl *) ihdl;

      if(ihdl->WMA_Packet_Loss){
         hdl->waiting = false;
         return MEDIA_SUCCESS;
      }
      
   do
   {
      res = wmaDecodePayloadData( ihdl, pBuf, &len, buf_len);
      if ( (res != cWMA_NoErr) && (res != cWMA_NoMoreFrames) )
         return MEDIA_FAIL;
      
      if(ihdl->WMA_Packet_Loss){
         hdl->waiting = false;
         return MEDIA_SUCCESS;
      }
      hdl->WriteDataDone( hdl, len );
      if (hdl->write == 0)
         ihdl->bufEndTime = ihdl->sState.ppex.dwSCR;
      pBuf = (uint8 *)&hdl->rb_base[hdl->write];
      buf_len -= len;
   } while ( (buf_len > 0) && !hdl->eof);
   return MEDIA_SUCCESS;
}

static void wmaDecideHuffmanGroup(wmaMediaHandleInternal *handle )
{
   uint32 weighted_bit_per_sample;
   uint32 boundary_072, boundary_116;
   fileHeaderParseInfo *hdrInfo = &handle->sState.hdr_parse;

   if (hdrInfo->nChannels == 1) {
      weighted_bit_per_sample = hdrInfo->nAvgBytesPerSec * 800;
   } else {
      weighted_bit_per_sample = hdrInfo->nAvgBytesPerSec * 640;
   }

   boundary_072 =  72 * hdrInfo->nSamplesPerSec;
   boundary_116 = 116 * hdrInfo->nSamplesPerSec;

   if (weighted_bit_per_sample < boundary_072) {
      if (hdrInfo->nSamplesPerSec >= 32000)
         handle->tableGroup = Huffman_RLC_44Q;
   } else if (weighted_bit_per_sample < boundary_116) {
      if (hdrInfo->nSamplesPerSec >= 32000)
         handle->tableGroup = Huffman_RLC_44O;
   }
}


/*
 * Description
 * -----------
 *  Read WMA compressed bitstream as a contiguous stream
 *
 * Syntax
 * ------------
 *   Media_Event wmaMFProcess( MHdl *hdl, Media_Event event);
 *
 * where:
 *
 *   hdl                  The media handle
 *   event                Process event
 *
 * Return Value
 * ------------
 * Media_Status    Return MEDIA_SUCCESS if the operation is complete. Return MEDIA_EOF otherwise.
 */

Media_Event wmaMFProcess( MHdl *hdl, Media_Event event )
{
   wmaMediaHandleInternal *ihdl;
   uint32 buf_len;
   uint8 *pBuf;

   ihdl = (wmaMediaHandleInternal *) hdl;

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, MEDIA_FORMAT_WMA );

   if (ihdl == NULL)
      ASSERT(0);

   switch (event)
   {
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
         if (hdl->state == WMA_STATE_PLAYING) {
            *WMA_STATUS = SHERIEF_STATE_END;
            kal_trace( TRACE_STATE, L1AUDIO_END_STATE );
            wmaCloseDevice( ihdl );
         } else if (hdl->state == WMA_STATE_ENDING) {
            wmaCloseDevice( ihdl );
         }
         hdl->state = WMA_STATE_IDLE;
         return MEDIA_END;

      case MEDIA_DATA_REQUEST:
         hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);

         if (wmaFillMediaBuf(ihdl, pBuf, buf_len) == MEDIA_FAIL) {
            if (hdl->state == WMA_STATE_PLAYING) {
               *WMA_STATUS = SHERIEF_STATE_STOP;
               kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
               wmaCloseDevice( ihdl );
            }
            hdl->state = WMA_STATE_IDLE;
            kal_trace( TRACE_ERROR, L1AUDIO_MCU_ERROR );
            return MEDIA_ERROR;
         }

         hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);

         if ( (buf_len > 0) && !hdl->eof ) {
            if (wmaFillMediaBuf(ihdl, pBuf, buf_len) == MEDIA_FAIL) {
               if (hdl->state == WMA_STATE_PLAYING) {
                  *WMA_STATUS = SHERIEF_STATE_STOP;
                  kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
                  wmaCloseDevice( ihdl );
               }
               hdl->state = WMA_STATE_IDLE;
               kal_trace( TRACE_ERROR, L1AUDIO_MCU_ERROR );
               return MEDIA_ERROR;
            }
         }
         hdl->waiting = false;
         break;

      case MEDIA_ERROR:
         kal_trace( TRACE_ERROR, L1AUDIO_DSP_ERROR );
         if (*WMA_DEBUG == 0x5555) {
            if (hdl->state == WMA_STATE_PLAYING) {
               *WMA_STATUS = SHERIEF_STATE_STOP;
               kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
               wmaCloseDevice( ihdl );
            }
            hdl->state = WMA_STATE_IDLE;
            return MEDIA_ERROR;
         }

         ihdl->WMA_Total_Frame = 0;
         hdl->read = hdl->write = 0;
         ihdl->sState.parse_state = csWMA_NewAsfPacket;
         hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);

         if (wmaFillMediaBuf(ihdl, pBuf, buf_len) == MEDIA_FAIL) {
            if (hdl->state == WMA_STATE_PLAYING) {
               *WMA_STATUS = SHERIEF_STATE_STOP;
               kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
               wmaCloseDevice( ihdl );
            }
            hdl->state = WMA_STATE_IDLE;
            return MEDIA_ERROR;
         }
         *WMA_DEBUG = 0x0000;
         hdl->waiting = false;
         break;

      default:
         ASSERT(0);
   }
   return MEDIA_NONE;
}

/*
   WMA interface
*/

/*
 * Description
 * -----------
 * This function closes the media handle.
 *
 * Syntax
 * ------
 *
 * Media_Status wmaMFClose( MHdl *handle );
 *
 * where:
 *
 * handle         The media handle
 *
 * Return Value
 * ------------
 * Return MEDIA_SUCCESS when the operation is complete.
 */

Media_Status wmaMFClose( MHdl *hdl )
{
   ASSERT( hdl != 0 && hdl->state != WMA_STATE_PLAYING );
   mhdlFinalize( hdl, DP_D2C_WMA );
   free_ctrl_buffer( hdl );

   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, MEDIA_FORMAT_WMA );

#ifdef WMA_L2_DEBUG_DUMP_LOG  // WMA L2 support
   if (_file_handle == 0)
      ASSERT(0);

   {
   	  kal_uint32 cnt;
      for(cnt=0; cnt<wmaCnt;){
         kal_sprintf((void*)_dbg_str, "%X\n%X\n\0", (kal_int32)wmaChecksumInfo[cnt++], (kal_int32)wmaChecksumInfo[cnt++]);
         FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
      }

   }

   FS_Close(_file_handle);
   _file_handle = 0;

#endif

   return MEDIA_SUCCESS;
}

/*
 * Description
 * -----------
 *  Start the playback of the media handle.
 *
 * Syntax
 * ------
 *   Media_Status wmaMFPlayFile( MHdl *hdl );
 *
 * where:
 *
 *   hdl                 The media handle
 *
 * Return Value
 * ------------
 * Return MEDIA_SUCCESS if the operation is complete, return MEDIA_BAD_FORMAT otherwise
 * if the start time or stop time is out of range, it will be set to valid position.
 */

Media_Status wmaMFPlayFile( MHdl *hdl )
{
   WMAERR wmarc;
   uint32 buf_len;
   uint8 *pBuf;
   wmaMediaHandleInternal *ihdl = (wmaMediaHandleInternal *)hdl;

   ASSERT(*WMA_STATUS == SHERIEF_STATE_IDLE);

   KT_StopAndWait();
   TONE_StopAndWait();

   ihdl->WMA_decode_EOF = KAL_FALSE;
   ihdl->WMA_DSP_data_Cnt = 0x7FFFFFFF;
   ihdl->WMA_Packet_Loss = KAL_FALSE;
   ihdl->uPacketNum = 0xFFFFFFFF;
   ihdl->WMA_Total_Frame = 0;

   if (ihdl->fParsed) {
      hdl->read         = 0;
      hdl->write        = 0;
      hdl->eof          = false;
      hdl->waiting      = false;
      hdl->current_time = hdl->start_time;
   } else {
      /* parse ASF header */
      FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->fileSize);
      wmarc = asf_ParseAsfHeader(ihdl);
      if (wmarc == WMAERR_UNSUPPORT)
         return MEDIA_UNSUPPORTED_TYPE;
      
      if (wmarc != WMAERR_OK || ihdl->sState.hdr_parse.wAudioStreamId == 0)  // No audio stream
         return MEDIA_BAD_FORMAT;

      // Avoid sherif overflow
      if (ihdl->sState.hdr_parse.nAvgBytesPerSec > 32767)
         ihdl->sState.hdr_parse.nAvgBytesPerSec = 32767;

      // To ban file other than 44.1k Hz sample rate, Bit rate should be on 64k ~ 160k bps
      if ( (    (ihdl->sState.hdr_parse.nSamplesPerSec != 8000)  // WMA L2 support
             && (ihdl->sState.hdr_parse.nSamplesPerSec != 11025)
             && (ihdl->sState.hdr_parse.nSamplesPerSec != 12000)
             && (ihdl->sState.hdr_parse.nSamplesPerSec != 16000)
             && (ihdl->sState.hdr_parse.nSamplesPerSec != 22050)
             && (ihdl->sState.hdr_parse.nSamplesPerSec != 24000)
             && (ihdl->sState.hdr_parse.nSamplesPerSec != 32000)
             && (ihdl->sState.hdr_parse.nSamplesPerSec != 44100)
             && (ihdl->sState.hdr_parse.nSamplesPerSec != 48000) ) ||
           (ihdl->sState.hdr_parse.nBlockAlign > 14861)     ||
           (ihdl->sState.hdr_parse.nChannels > 2)           ||
           (ihdl->sState.hdr_parse.nChannels < 1))
         return MEDIA_UNSUPPORTED_TYPE;


      // DSP configuration
      wmaDecideHuffmanGroup( ihdl );
      switch (ihdl->tableGroup) {
         case Huffman_RLC_16:
            if(ihdl->sState.hdr_parse.nEncodeOpt & 0x01){
               DSP_DynamicDownload( DDID_WMA_16OB_HighRate );
               ihdl->pmdllptr = &pmdll_WMA_16OB; // WMA L2 support
            }else{
               DSP_DynamicDownload( DDID_WMA_16OB_LowRate );
               ihdl->pmdllptr = &pmdll_WMA_16OB; // WMA L2 support
            }
            break;
         case Huffman_RLC_44O:
            if (ihdl->sState.hdr_parse.nEncodeOpt & 0x1) {
               DSP_DynamicDownload( DDID_WMA_44OB );
               ihdl->pmdllptr = &pmdll_WMA_44OB; // WMA L2 support
            } else {
               return MEDIA_UNSUPPORTED_TYPE;    // Spec doesn't define this combination
            }
            break;
         case Huffman_RLC_44Q:
            if(ihdl->sState.hdr_parse.nEncodeOpt & 0x01){
               DSP_DynamicDownload( DDID_WMA_44QB_HighRate ); // WMA L2 support
               ihdl->pmdllptr = &pmdll_WMA_44QB;
            }else{
               DSP_DynamicDownload( DDID_WMA_44QB_LowRate ); // WMA L2 support
               ihdl->pmdllptr = &pmdll_WMA_44QB;
            }
            break;
         default:
            ASSERT(0);
      }
   }

   if ( wmaFileSeek(ihdl) == KAL_FALSE )
      return MEDIA_SEEK_EOF;

   hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
   if (wmaFillMediaBuf(ihdl, pBuf, buf_len) == MEDIA_FAIL)
      return MEDIA_FAIL;

   ihdl->uCurFrame = (kal_uint64)hdl->start_time * ihdl->sState.hdr_parse.nSamplesPerSec / 2048 / 1000;
   ihdl->bufStartTime = hdl->start_time;
   ihdl->end_status = MEDIA_NONE;
   hdl->dsp_rb_base = 0xFFFF;

   *WMA_CNTROL_WORD = WMA_ON;
   *WMA_STATUS = SHERIEF_STATE_INIT;
   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );
   *WMA_ENCODE_OPT = (uint16)ihdl->sState.hdr_parse.nEncodeOpt;
   *WMA_BYTES_PER_SECONDS = (uint16)ihdl->sState.hdr_parse.nAvgBytesPerSec;
   *WMA_PACKET_LENGTH = (uint16)ihdl->sState.hdr_parse.nBlockAlign;
   *WMA_SAMPLING_RATE = (uint16)ihdl->sState.hdr_parse.nSamplesPerSec;
   *WMA_NUM_CHANNELS = (uint16)ihdl->sState.hdr_parse.nChannels;
   *WMA_VERSION_NUMBER = (uint16)ihdl->sState.hdr_parse.nVersion;
   AFE_SetDigitalGain( L1SP_AUDIO, hdl->volume_level );

   hdl->state = WMA_STATE_PLAYING;
   ihdl->fParsed = true;
   wmaOpenDevice( ihdl );

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, MEDIA_FORMAT_WMA );

   return MEDIA_SUCCESS;
}

/*
 * Description
 * -----------
 *  Stop the playback of the media handle.
 *
 * Syntax
 * ------
 * Media_Status wmaMFStop( MHdl *hdl );
 *
 * where:
 *
 * hdl               The media handle
 *
 * Return Value
 * ------------
 * Return MEDIA_SUCCESS if the operation is complete.
 */

Media_Status wmaMFStop( MHdl *hdl )
{
   wmaMediaHandleInternal *ihdl = (wmaMediaHandleInternal *)hdl;

   if (hdl->state == WMA_STATE_IDLE)
      return MEDIA_SUCCESS;

   ASSERT( hdl->state & (WMA_STATE_PLAYING|WMA_STATE_PLAY_PAUSED) );

   if (hdl->state == WMA_STATE_PLAYING) {

      *WMA_STATUS = SHERIEF_STATE_STOP;
      kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
      wmaCloseDevice( ihdl );
   }else if (hdl->state == WMA_STATE_ENDING) {
      kal_trace( TRACE_STATE, L1AUDIO_END_STATE );
      wmaCloseDevice( ihdl );
    }

   hdl->state = WMA_STATE_IDLE;

   kal_trace( TRACE_FUNC, L1AUDIO_STOP, MEDIA_FORMAT_WMA );

   return MEDIA_SUCCESS;
}

/*
 * Description
 * -----------
 *  Pause the playback of the media handle
 *
 * Syntax
 * ------
 *   Media_Status wmaMFPause( MHdl *hdl );
 *
 * where:
 *
 *    hdl                 The media handle
 *
 * Return Value
 * ------------
 * Return MEDIA_SUCCESS if the operation is complete.
 */

Media_Status wmaMFPause( MHdl *hdl )
{
   wmaMediaHandleInternal *ihdl = (wmaMediaHandleInternal *)hdl;

   ASSERT( (hdl->state == WMA_STATE_PLAYING) || (hdl->state == WMA_STATE_ENDING) );

   *WMA_STATUS = SHERIEF_STATE_STOP;
   kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
   wmaCloseDevice( ihdl );
   hdl->state = WMA_STATE_PLAY_PAUSED;

   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, MEDIA_FORMAT_WMA );

   return MEDIA_SUCCESS;
}

/*
 * Description
 * ----------------
 *  Resume the playback of the media handle
 *
 * Syntax
 * ------
 * Media_Status wmaMFResume( MHdl *hdl );
 *
 * where:
 *
 *   hdl                  The media handle
 *
 * Return Value
 * ------------
 * Return MEDIA_SUCCESS if the operation is complete, return MEDIA_FAIL otherwise.
 */

Media_Status wmaMFResumeFile( MHdl *hdl )
{
   wmaMediaHandleInternal *ihdl = (wmaMediaHandleInternal *)hdl;
   uint32 buf_len;
   uint8 *pBuf;

   KT_StopAndWait();
   TONE_StopAndWait();

   if ( (hdl->state & WMA_STATE_PLAY_PAUSED) == 0 )
      return MEDIA_FAIL;

/*
   if(ihdl->WMA_decode_EOF && (!ihdl->WMA_Packet_Loss)){
      mhdlException( hdl, MEDIA_END );
      return MEDIA_SUCCESS;
   }
*/

   ihdl->WMA_decode_EOF = KAL_FALSE;
   ihdl->WMA_DSP_data_Cnt = 0x7FFFFFFF;
   ihdl->WMA_Packet_Loss = KAL_FALSE;
   ihdl->uPacketNum = 0xFFFFFFFF;
   ihdl->WMA_Total_Frame = 0;
   
   hdl->read       = 0;
   hdl->write      = 0;
   hdl->eof        = false;
   hdl->waiting    = false;
   hdl->start_time = hdl->current_time;
   ihdl->bufStartTime = hdl->current_time;
   ihdl->sState.payload.fInvalidFrame = true;

   if ( wmaFileSeek(ihdl) == KAL_FALSE )
      return MEDIA_SEEK_FAIL;

   hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);

   if (wmaFillMediaBuf(ihdl, pBuf, buf_len) == MEDIA_FAIL)
      return MEDIA_FAIL;

   switch (ihdl->tableGroup) {
      case Huffman_RLC_16:
         if(ihdl->sState.hdr_parse.nEncodeOpt & 0x01){
            DSP_DynamicDownload( DDID_WMA_16OB_HighRate );
            ihdl->pmdllptr = &pmdll_WMA_16OB; // WMA L2 support
         }else{
             DSP_DynamicDownload( DDID_WMA_16OB_LowRate );
             ihdl->pmdllptr = &pmdll_WMA_16OB; // WMA L2 support
          }
         break;
      case Huffman_RLC_44O:
         DSP_DynamicDownload( DDID_WMA_44OB );
         ihdl->pmdllptr = &pmdll_WMA_44OB; // WMA L2 support
         break;
      case Huffman_RLC_44Q:
         if(ihdl->sState.hdr_parse.nEncodeOpt & 0x01){
            DSP_DynamicDownload( DDID_WMA_44QB_HighRate ); // WMA L2 support
            ihdl->pmdllptr = &pmdll_WMA_44QB;
         }else{
             DSP_DynamicDownload( DDID_WMA_44QB_LowRate ); // WMA L2 support
            ihdl->pmdllptr = &pmdll_WMA_44QB;
          }
         
         break;
      default:
         ASSERT(0);
   }

   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE ); // WMA L2 support
   *WMA_ENCODE_OPT = (uint16)ihdl->sState.hdr_parse.nEncodeOpt;
   *WMA_BYTES_PER_SECONDS = (uint16)ihdl->sState.hdr_parse.nAvgBytesPerSec;
   *WMA_PACKET_LENGTH = (uint16)ihdl->sState.hdr_parse.nBlockAlign;
   *WMA_SAMPLING_RATE = (uint16)ihdl->sState.hdr_parse.nSamplesPerSec;
   *WMA_NUM_CHANNELS = (uint16)ihdl->sState.hdr_parse.nChannels;
   *WMA_VERSION_NUMBER = (uint16)ihdl->sState.hdr_parse.nVersion;
   *WMA_CNTROL_WORD = WMA_ON;
   *WMA_STATUS      = SHERIEF_STATE_INIT;

   ihdl->end_status = MEDIA_NONE;
   hdl->state = WMA_STATE_PLAYING;

   /* Set Digital Gain for WMA */
   AFE_SetDigitalGain( L1SP_AUDIO, hdl->volume_level );

   wmaOpenDevice( ihdl );

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, MEDIA_FORMAT_WMA );

   return MEDIA_SUCCESS;
}

/*
 * Description
 * -----------
 *  Get time needed to play the file in millisecond units at any time.
 *
 * Syntax
 * ------------
 *  kal_int32 WMA_GetDuration( STFSAL *pstFSAL );
 *
 * where:
 *
 *   pstFSAL        Pointer to the FSAL structure of the opened file
 *
 * Return Value
 * ------------
 * Return playback duration in  millisecond units.
 */

kal_int32 WMA_GetDuration( STFSAL *pstFSAL )
{
   wmaMediaHandleInternal *ihdl;
   kal_int32 duration;

   ihdl = (wmaMediaHandleInternal*)get_ctrl_buffer( sizeof(wmaMediaHandleInternal) );
   memset(ihdl, 0, sizeof(wmaMediaHandleInternal));
   ihdl->pstFSAL = pstFSAL;
   ihdl->description = NULL;
   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->fileSize);
   asf_ParseAsfHeader(ihdl);
   duration = ihdl->sState.hdr_parse.msDuration;
   free_ctrl_buffer( ihdl );
   return duration;
}

/*
 * Description
 * -----------
 *  Retrieves the content description for the WMA file.
 *  Content descriptions are such as the song title, the
 *  author, the copyright info, the song description,
 *  and the rating info. All these are part of the
 *  standard ASF description.
 *  Not all songs have content descriptions.
 *  It can be called at any time.
 *
 * Syntax
 * ------------
 *   Media_Status WMA_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo);
 *
 * where:
 *
 *   pstFSAL           Pointer to the FSAL structure.
 *   contentInfo       Pointer to audio information structure.
 *
 * Return Value
 * ------------
 * Media_Status    Return MEDIA_SUCCESS if the operation is complete. Return MEDIA_FAIL otherwise.
 */

Media_Status WMA_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   wmaMediaHandleInternal *ihdl;
   ihdl = (wmaMediaHandleInternal*)get_ctrl_buffer( sizeof(wmaMediaHandleInternal) );
   memset(ihdl, 0, sizeof(wmaMediaHandleInternal));
   mhdlInit( ( MHdl *)ihdl, 0xFFFF , wmaHisr );
   ihdl->pstFSAL = pstFSAL;
   ihdl->description = contentInfo;
   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->fileSize);
   ihdl->description->title[0]  = '\0';
   ihdl->description->artist[0] = '\0';
   ihdl->description->album[0]  = '\0';
   ihdl->description->author[0]  = '\0';
   ihdl->description->copyright[0]  = '\0';
   ihdl->description->date[0]  = '\0';
   asf_ParseAsfHeader(ihdl);
   ihdl->description->time       = ihdl->sState.hdr_parse.msDuration;   // duration in milli-sec
   ihdl->description->bitRate    = ihdl->sState.hdr_parse.nAvgBytesPerSec << 3;
   ihdl->description->sampleRate = ihdl->sState.hdr_parse.nSamplesPerSec;
   ihdl->description->stereo     = (ihdl->sState.hdr_parse.nChannels == 2)?true:false;

   free_ctrl_buffer( ihdl );

   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, MEDIA_FORMAT_WMA );

   return MEDIA_SUCCESS;
}

Media_Status WMA_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
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

   ret = WMA_GetContentDescInfo( pstFSAL, contentInfo, (void *)0);
   
   if(NULL != filename){
      FSAL_Close(pstFSAL);
   }
   free_ctrl_buffer(pstFSAL);

   return ret;
}

/*
 * Description
 * -----------
 * This function is used to open a handle for WMA file playback. It should be invoked before any
 * other operation.
 *
 * Syntax
 * ------------
 *   MHdl *WMA_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL);
 *
 *  where:
 *
 *   handler        Call-back function used for handling events during playback.
 *   pstFSAL        Pointer to the FSAL structure.
 *
 *  Return Value
 *  ------------
 *  The media handle. Return NULL if no handle can be opened
 */
#ifdef WMA_L2_DEBUG_DUMP_LOG  // WMA L2 support
extern kal_uint16 *TestWMA_GetFileName(void);
#endif
MHdl *WMA_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   wmaMediaHandleInternal *ihdl;
#ifdef WMA_L2_DEBUG_DUMP_LOG  // WMA L2 support
   kal_uint16 *fileName;
#endif

   ihdl = (wmaMediaHandleInternal*)get_ctrl_buffer( sizeof(wmaMediaHandleInternal) );
   memset(ihdl, 0, sizeof(wmaMediaHandleInternal));
   hdl = (MHdl *) ihdl;

   mhdlInit( hdl, DP_D2C_WMA, wmaHisr );

   hdl->handler        = handler;
   hdl->state          = WMA_STATE_IDLE;
   hdl->mediaType      = MEDIA_FORMAT_WMA;
   ihdl->pstFSAL       = pstFSAL;
   ihdl->description   = NULL;
   ihdl->sState.payload.fInvalidFrame = true;

   hdl->Play    = wmaMFPlayFile;
   hdl->Stop    = wmaMFStop;
   hdl->Pause   = wmaMFPause;
   hdl->Resume  = wmaMFResumeFile;
   hdl->Process = wmaMFProcess;
   hdl->Close   = wmaMFClose;

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, MEDIA_FORMAT_WMA );

#ifdef WMA_L2_DEBUG_DUMP_LOG  // WMA L2 support
   fileName = TestWMA_GetFileName();
   kal_wsprintf( _file_name, "%w.txt", fileName);
   _file_handle = FS_Open((const WCHAR *)_file_name, FS_CREATE);
   wmaCnt = 0xFFFFFFFF;
#endif

   return hdl;
}
#endif  /* WMA_DECODE */