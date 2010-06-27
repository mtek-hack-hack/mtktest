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
 *   l1tts.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   l1audio TTS interface
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "l1audio_def.h"
#if defined(CYBERON_DIC_TTS)
#include "./Tts/TDic.h"
#endif

#if defined(IFLY_TTS)
#include "./Tts/InterSound4.h"
#endif
#include "fat_fs.h"  /* file system */

#define TTS_NULL_START  0
#define TTS_INITIALIZED 1
#define TTS_IDLE        2
#define TTS_PLAYING     3
#define TTS_PAUSE       4
#define TTS_PREPARE_STOP   5

#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS)
#define BUF_SIZE 4096 //256 ms for 16KHz PCM

TTS_Handle *g_ttsHdl;

#if defined(IFLY_TTS)

#define TTS_NEED_MIN_HEAP ( TTS_MIN_HEAP + 32 )

#if defined ( IFLYTTS_RES_IN_FILE ) // resource data(resource.dat) of iFly TTS are in flie
   extern unsigned char* g_pResMap;
   #define IFLYTTS_RESOURCE_SIZE 4261580
#else
//
#endif

TTSERROR OnOutput(LPTTSVOID lpParameter, TTSWORD wCode, LPCTTSVOID lpcData, TTSDWORD dwSize)
{
   uint32 retrieved_events, bufLen, I;
   uint16 *bufSrc, *bufDest;
   uint8 *pBuf;
   TTS_Handle *ttsHdl;
   MHdl *mhdl;
   
   ttsHdl = (TTS_Handle *)lpParameter;
   mhdl   = (MHdl *)ttsHdl->spcmHdl;
   // must allow other service of l1audio can be run
   while( ( mhdl->GetFreeSpace( mhdl ) < dwSize ) ){
      if( ttsHdl->state == TTS_PREPARE_STOP ){
         InterSound4.Close( (HTTS)ttsHdl->customHdl );
         ttsHdl->state = TTS_IDLE;
         return TTSERR_OK;
      }
      retrieved_events = L1Audio_GetEventGroup();
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if( retrieved_events & (1<<I) ) {
            if( I != ttsHdl->aud_id )
               L1Audio_ExeEventHandler( I );
         }
      }
      kal_sleep_task(1);
   }

   if( ttsHdl->state == TTS_PREPARE_STOP ){
      InterSound4.Close( (HTTS)ttsHdl->customHdl );
      ttsHdl->state = TTS_IDLE;
      return TTSERR_OK;
   }
   
   mhdl->GetWriteBuffer( mhdl, &pBuf, &bufLen );
   kal_prompt_trace( MOD_L1SP, "iFlyTTS Output=%d", dwSize );
   kal_prompt_trace( MOD_L1SP, "Spcm Buf ptr=%x,len=%d", pBuf, bufLen );
   if( dwSize < bufLen )
      bufLen = dwSize >> 1;
   else
      bufLen = bufLen >> 1; //convert from byte size to word size
   bufSrc  = (uint16 *)lpcData;
   bufDest = (uint16 *)pBuf;
   
   for( I = bufLen ; I > 0 ; I-- )
      *bufDest++ = *bufSrc++;
   mhdl->WriteDataDone( mhdl, bufLen << 1 );
   //2nd part of data
   if( dwSize > ( bufLen << 1 ) ){
      bufLen = (dwSize >> 1) - bufLen;
      mhdl->GetWriteBuffer( mhdl, &pBuf, &I );
      bufDest = (uint16 *)pBuf;
      for( I = bufLen ; I > 0 ; I-- )
         *bufDest++ = *bufSrc++;
      mhdl->WriteDataDone( mhdl, bufLen << 1 );
   }
   ttsHdl->dataReq = KAL_FALSE;
   
   return TTSERR_OK;
}
/* Available for iFlyTTS only, this task will block for a while, but in Onput callback
   function, it will allow sleep for other task to run                                 */
static void ttsTask( void *data )
{
   TTS_Handle *ttsHdl;
   MHdl *mhdl;
   HTTS hTTS;
   
   ttsHdl = (TTS_Handle *)data;
   hTTS = (HTTS)ttsHdl->customHdl;
   
   InterSound4.SetAttr(hTTS, TTSATTR_INPUT_CODEPAGE, (TTSVAR)TTSCODEPAGE_UNICODE);
   /*use last par to pass handler*/
   InterSound4.SetAttr(hTTS, TTSATTR_CALLBACK_PARAMETER, (TTSVAR)data);
   
   /* 設置PCM輸出回調 */
   InterSound4.SetAttr(hTTS, TTSATTR_OUTPUT_CALLBACK, (TTSVAR)OnOutput);
   /* 設置輸出語音數據 */
   InterSound4.SetAttr(hTTS, TTSATTR_OUTPUT_VOICE, TTSTRUE);
   /* 設置音量為正常音量 */
   InterSound4.SetAttr(hTTS, TTSATTR_VOLUME, TTSVOLUME_NORMAL);
   /* set codepage as UNICODE */
   InterSound4.SetAttr(hTTS, TTSATTR_INPUT_CODEPAGE, (TTSVAR)TTSCODEPAGE_BIG5);
   /* set speaker as YANPING */
   InterSound4.SetAttr(hTTS, TTSATTR_ROLE, (TTSVAR)TTSROLE_YANPING);

   mhdl   = (MHdl *)ttsHdl->spcmHdl;
   mhdl->read   = 0;
   mhdl->write  = 0;
   mhdl->Play( mhdl );
   ttsHdl->state = TTS_PLAYING;
   InterSound4.SynthText( hTTS, (LPCTTSVOID)(ttsHdl->text), -1 );
   mhdl->DataFinished( mhdl );
}

TTSERROR OnProgress(LPTTSVOID lpParameter, TTSDWORD dwProcBegin, TTSDWORD dwProcLen)
{
   TTS_Handle *ttsHdl;
   TTSPROGRESS ttsProc;
   ttsHdl = (TTS_Handle *)lpParameter;
   ttsProc.dwProcPos = dwProcBegin;
   ttsProc.dwProcLen = dwProcLen;
   // callback MED the progress now
   ttsHdl->handler( ttsHdl, TTS_PROGRESS, &ttsProc );
   return TTSERR_OK;
}

TTSERROR OnWatch(LPTTSVOID lpParameter, TTSWORD wSylType, LPCTTSVOID lpcSylText,
                  TTSDWORD dwTextLen, LPCTTSVOID lpcSylPhone, TTSDWORD dwPhoneLen)
{
   TTS_Handle *ttsHdl;
   TTS_PROCESS_DATA ttsProcData;
   
   ttsHdl = (TTS_Handle *)lpParameter;
   ttsProcData.lpcSylText  = lpcSylText;
   ttsProcData.wSylType    = wSylType;
   ttsProcData.dwTextLen   = dwTextLen;
   ttsProcData.lpcSylPhone = lpcSylPhone;
   ttsProcData.dwPhoneLen  = dwPhoneLen;
   // callback MED the ProcData now
   ttsHdl->handler( ttsHdl, TTS_WATCH, &ttsProcData );
   return TTSERR_OK;
}

#endif // end of IFLY_TTS


static kal_uint32 ttsGetBufSize( TTS_Handle *hdl )
{
   uint32 size;
#if defined(CYBERON_DIC_TTS)
   TDicTTS_RTResourceSize( &size );
   size += ( BUF_SIZE * sizeof(uint16) );
#elif defined(IFLY_TTS)
#if defined( IFLYTTS_RES_IN_FILE )
   size = TTS_NEED_MIN_HEAP + ( BUF_SIZE * sizeof(uint16) ) + IFLYTTS_RESOURCE_SIZE;
#else
   size = TTS_NEED_MIN_HEAP + ( BUF_SIZE * sizeof(uint16) );
#endif
#endif
   return size;
}

static Media_Status ttsSetBuffer( TTS_Handle *hdl, kal_uint8* buffer, kal_uint32 buf_len )
{
   ASSERT( hdl != NULL && hdl->state == TTS_INITIALIZED );
   if( buf_len < hdl->GetBufSize( hdl ))
      return MEDIA_FAIL;
   else{
      int32 sdCardDrv;
      sdCardDrv = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
      kal_wsprintf( hdl->dataDir, "%c%s", sdCardDrv,":\\ttsRes\\");
         if(sdCardDrv <= 0)   
            sdCardDrv = 'D';
      hdl->spcmHdl->SetBuffer( hdl->spcmHdl, buffer, BUF_SIZE *sizeof(uint16) );
#if defined(CYBERON_DIC_TTS)
      // data path need to be confirmed
      //kal_wsprintf( hdl->dataDir, "d:\\TTSData\\");//currently this path takes no effect since the library contains database
      if( TDicTTS_Init( buffer + BUF_SIZE * sizeof(uint16), buf_len - BUF_SIZE * sizeof(uint16), hdl->dataDir) != TDIC_RES_OK )
         return MEDIA_FAIL;
#elif defined(IFLY_TTS)
      {
         TTSATTR	tAttr[2];
         uint32   readCnt = 0;
#if defined( IFLYTTS_RES_IN_FILE )
         {
            int32 file_handle;
            uint32 fileSize;
            
            
            kal_wsprintf( hdl->dataDir, "%c%s", sdCardDrv,":\\ttsRes\\Resource.dat");
            file_handle = FS_Open((const kal_wchar *)hdl->dataDir, FS_READ_ONLY); 
            ASSERT( file_handle > 0 );
            
            FS_GetFileSize(file_handle, &fileSize);
            //asign the Resource Buf Ptr for IFLY TTS
            g_pResMap = (unsigned char*)(buffer + BUF_SIZE * sizeof(uint16));
            
            ASSERT( FS_Read( file_handle, g_pResMap, fileSize, &readCnt) >= 0 );
            FS_Close( file_handle );
         }
#endif
         
         InterSound4.Initialize();
         tAttr[0].dwAttrId     = TTSATTR_USER_HEAP;
         tAttr[0].varAttrValue = (TTSVAR)(buffer + BUF_SIZE * sizeof(uint16) + readCnt);
         tAttr[1].dwAttrId     = TTSATTR_USER_HEAP_SIZE;
         tAttr[1].varAttrValue = (TTSVAR)TTS_MIN_HEAP;
         InterSound4.Create( (HTTS *)&hdl->customHdl, tAttr, sizeof(tAttr)/sizeof(tAttr[0]) );
      }
      
#endif
      hdl->state = TTS_IDLE;
      kal_prompt_trace( MOD_L1SP, "TDIC SetBuffer" );
      return MEDIA_SUCCESS;
   }
}

static Media_Status ttsPlay( TTS_Handle *hdl, kal_wchar *string, TTS_STR_TYPE strType )
{  
   ASSERT( hdl != NULL && hdl->state == TTS_IDLE );
#if defined(CYBERON_DIC_TTS)
   ASSERT( strType == TTS_STR_PHN_SBL );
#endif
   /*phonetic symbol transform*/
#if defined(CYBERON_DIC_TTS)
{
   Media_Status status;
   TDIC_FRESULT res;
   MHdl *pstMHdl = (MHdl *)hdl->spcmHdl;
   res = TDicTTS_PlayPron( string, hdl->speed );
   if( res != TDIC_RES_OK ){
      kal_prompt_trace(MOD_L1SP, "TDic Err =%d", res );
      return MEDIA_FAIL;
   }
   kal_prompt_trace( MOD_L1SP, "TDIC Play" );
   status = pstMHdl->Play( pstMHdl );
   if( status == MEDIA_SUCCESS ){
      hdl->state = TTS_PLAYING;
      return MEDIA_SUCCESS;
   }
   else{
      return MEDIA_FAIL;
   }
}
#elif defined(IFLY_TTS)
   hdl->text = (void*)string;
   L1Audio_SetEvent( hdl->aud_id, (void *)hdl );
   return MEDIA_SUCCESS;
#endif
}

static Media_Status ttsPause( TTS_Handle *hdl )
{
   Media_Status status;
   status = hdl->spcmHdl->Pause( hdl->spcmHdl );
   if( status == MEDIA_SUCCESS )
      hdl->state = TTS_PAUSE;
   kal_prompt_trace( MOD_L1SP, "TTS Pause" );
   return status;
}

static Media_Status ttsResume( TTS_Handle *hdl )
{
   Media_Status status;
   
   if( hdl->state != TTS_PAUSE )
      return MEDIA_FAIL;
   status = hdl->spcmHdl->Resume( hdl->spcmHdl );
   if( status == MEDIA_SUCCESS )
      hdl->state = TTS_PLAYING;
   kal_prompt_trace( MOD_L1SP, "TTS Resume" );
   return status;
}

static Media_Status ttsStop( TTS_Handle *hdl )
{
   Media_Status status;
   if( hdl->state == TTS_IDLE )
      return MEDIA_SUCCESS;
   hdl->state = TTS_PREPARE_STOP;
   status = hdl->spcmHdl->Stop( hdl->spcmHdl );
#if defined(CYBERON_DIC_TTS)
   {
      TDIC_FRESULT res;
      if( (res = TDicTTS_Stop()) != TDIC_RES_OK )
         return MEDIA_FAIL;
   }
#elif defined(IFLY_TTS)
   {
      if( !hdl->spcmHdl->eof ){
         int32 I;
         for( I = 0 ; ; I++ )
         {
            if( hdl->state != TTS_IDLE )
               kal_sleep_task(1);
            ASSERT( I != 40 );
         }
      }
   }
#endif
   
   kal_prompt_trace( MOD_L1SP, "TTS Stop" );
   if( status == MEDIA_SUCCESS )
      hdl->state = TTS_IDLE;
   return status;
}

static Media_Status ttsClose( TTS_Handle *hdl )
{
   ASSERT( hdl != NULL && hdl->state != TTS_PLAYING );
#if defined(IFLY_TTS)
   L1Audio_FreeAudioID( hdl->aud_id );
   InterSound4.Release( (HTTS)hdl->customHdl );
   InterSound4.Uninitialize();
#endif
   hdl->spcmHdl->Close( hdl->spcmHdl );
   free_ctrl_buffer( hdl );
   hdl = NULL;
   kal_prompt_trace( MOD_L1SP, "TTS Close" );
   return MEDIA_SUCCESS;
}

static Media_Status ttsSetPitch( TTS_Handle *hdl, kal_uint32 pitch )
{
   ASSERT( hdl != NULL );
   if ( pitch == 0 || pitch > 100 )
      return MEDIA_BAD_PARAMETER;
#if defined( IFLY_TTS )
   hdl->pitch = -32768 + 655 * pitch; //mapping from 1~100 to -32768~32767;
   InterSound4.SetAttr( (HTTS)hdl->customHdl, TTSATTR_VOICE_TONE, (TTSVAR)hdl->pitch );
   kal_prompt_trace( MOD_L1SP, "TDIC SetSpeed %d", pitch );
   return MEDIA_SUCCESS;
#else // CYBERON
   return MEDIA_FAIL; // not support in Cyberon engine
#endif
}

static Media_Status ttsSetSpeed( TTS_Handle *hdl, kal_uint32 speed )
{
   ASSERT( hdl != NULL );
   if( speed == 0 || speed > 100 )
      return MEDIA_BAD_PARAMETER;
#if defined( IFLY_TTS )
   hdl->speed = -32768 + 655 * speed; //mapping from 1~100 to -32768~32767;
   InterSound4.SetAttr( (HTTS)hdl->customHdl, TTSATTR_VOICE_SPEED, (TTSVAR)hdl->speed );
#else
   hdl->speed = speed;
#endif
   kal_prompt_trace( MOD_L1SP, "TDIC SetSpeed %d", speed );
   return MEDIA_SUCCESS;
}

static Media_Status ttsSetVolume( TTS_Handle *hdl, kal_uint32 volume )
{
   ASSERT( hdl != NULL );
   if( volume == 0 || volume > 100 )
      return MEDIA_BAD_PARAMETER;
#if defined( IFLY_TTS )
   hdl->volume = -32768 + 655 * volume; //mapping from 1~100 to -32768~32767;
   InterSound4.SetAttr( (HTTS)hdl->customHdl, TTSATTR_VOLUME, (TTSVAR)hdl->volume );
   kal_prompt_trace( MOD_L1SP, "TDIC SetVol %d", volume );
   return MEDIA_SUCCESS;
#else // CYBERON
   return MEDIA_FAIL; // not support in Cyberon engine
#endif
}

// Streaming PCM callback function, run in l1audio task
static void spcm_event_callback( MHdl *mhdl, Media_Event event )
{
   TTS_Handle *ttsHdl;
   
   ttsHdl = (TTS_Handle *)mhdl->ss_handle;
   if( ttsHdl->state == TTS_PREPARE_STOP )
      return;

   kal_prompt_trace(MOD_L1SP, "spcm_event");
  
   //ASSERT( ttsHdl->state == TTS_PLAYING || ttsHdl->state == TTS_IDLE);
   
   switch( event ){
      case MEDIA_END :
         ttsHdl->handler( ttsHdl, TTS_END, NULL );
         kal_prompt_trace( MOD_L1SP, "TTS PRC MED END" );
         break;

      case MEDIA_DATA_REQUEST :
#if defined(IFLY_TTS)
         ttsHdl->dataReq = KAL_TRUE;
         break;
#elif defined(CYBERON_DIC_TTS)
      {  
         uint8 *pBuf;
         uint32 bufLen, remainSize = 0;
         int32 fillLen;
         mhdl->GetWriteBuffer( mhdl, &pBuf, &bufLen );
         kal_prompt_trace( MOD_L1SP, "Spcm Buf ptr=%x,len=%d", pBuf, bufLen );
         fillLen = TDicTTS_GetTTSData( (kal_int16 *)pBuf, bufLen >> 1, &remainSize );
         //fillLen is in short
         kal_prompt_trace( MOD_L1SP, "TDIC get %d data1, remain %d", fillLen, remainSize );
         if( fillLen > 0 )
            mhdl->WriteDataDone( mhdl, fillLen << 1 );
         else 
            kal_prompt_trace( MOD_L1SP, "TDIC Get No Data" );
         
         mhdl->GetWriteBuffer( mhdl, &pBuf, &bufLen );
         kal_prompt_trace( MOD_L1SP, "Spcm Buf ptr=%x,len=%d", pBuf, bufLen );
         if( remainSize > 0 ){
            if( bufLen > 0 ){
               fillLen = TDicTTS_GetTTSData( (kal_int16 *)pBuf, bufLen >> 1, &remainSize );
               kal_prompt_trace( MOD_L1SP, "TDIC get %d data2, remain %d", fillLen, remainSize );
               if( fillLen > 0 )
                  mhdl->WriteDataDone( mhdl, fillLen << 1 );
               else
                  kal_prompt_trace( MOD_L1SP, "TDIC Get No Data" );
            }
         } else {
            TDIC_FRESULT ttsRes;
            ttsRes = TDicTTS_Process();
            switch(ttsRes){
               case TDIC_RES_OK:
                  mhdl->DataFinished( mhdl );
                  kal_prompt_trace( MOD_L1SP, "TDIC PRC done" );
                  break;
               case TDIC_RES_PROCESSING:
                  L1Audio_SetEvent( mhdl->aud_id, (void *)event );//let whole process run again
                  kal_prompt_trace( MOD_L1SP, "TDIC PRC needed" );
                  break;
               case TDIC_RES_TTSDATA:
                  kal_prompt_trace( MOD_L1SP, "TDIC PRC data" );
                  break;
               case TDIC_RES_FAILED:
               default:
                  kal_prompt_trace( MOD_L1SP, "TDic error code = %d", ttsRes );
                  ASSERT(0);
            }
         }
         mhdl->waiting = KAL_FALSE;
         break;
      }
#endif
      default:
         ASSERT(0);//should never reach here
   }
}

static Media_Status ttsSetAttr( TTS_Handle *hdl, kal_uint32 dwAttrId, kal_uint32 varAttrValue )
{
#if defined(IFLY_TTS)
   if( dwAttrId == TTS_ATTR_PROGRESS_CALLBACK )
      varAttrValue = (TTSVAR)OnProgress;
   //else if( dwAttrId == TTS_ATTR_WATCH_CALLBACK )
      //varAttrValue = 
   if( InterSound4.SetAttr( (HTTS)hdl->customHdl, dwAttrId, varAttrValue ) != TTSERR_OK)
      return MEDIA_SUCCESS;
   else
      return MEDIA_FAIL;
   
#else
   return MEDIA_FAIL;
#endif
}

TTS_Handle* TTS_Open( void (*callback)(TTS_Handle *hdl, TTS_Event event, void *data ),
                     TTS_LANG lang, TTS_TYPE type, TTS_GENDER gender)
{
   TTS_Handle *ttsHdl;
   Media_PCM_Stream_Param param;
   
   ttsHdl = get_ctrl_buffer(sizeof(TTS_Handle));
   ttsHdl->handler      = callback;
   ttsHdl->GetBufSize   = ttsGetBufSize;
   ttsHdl->SetBuffer    = ttsSetBuffer;
   ttsHdl->Play         = ttsPlay;
   ttsHdl->Pause        = ttsPause;
   ttsHdl->Resume       = ttsResume;
   ttsHdl->Stop         = ttsStop;
   ttsHdl->Close        = ttsClose;
   ttsHdl->SetPitch     = ttsSetPitch;
   ttsHdl->SetVolume    = ttsSetVolume;
   ttsHdl->SetSpeed     = ttsSetSpeed;
   ttsHdl->SetAttr      = ttsSetAttr;
   ttsHdl->pitch        = 50;
   ttsHdl->volume       = 50;
   ttsHdl->speed        = 50;
   ttsHdl->state        = TTS_INITIALIZED;
   //L1Audio_SetEventHandler( ttsHdl->aud_id, ttsProcess );
   
   param.isStereo       = false;
   param.bitPerSample   = 16;
#if ( defined(IFLY_TTS) && !defined( IFLYTTS_RES_IN_FILE ) )
   param.sampleFreq     = 8000;  // for const data evaluation version, only 8K. Should be updated later.
#else
   param.sampleFreq     = 16000;
#endif
   ttsHdl->spcmHdl      = PCM_Strm_Open( spcm_event_callback, &param );
   ttsHdl->spcmHdl->ss_handle  = (SSHdl *)ttsHdl;//force ttsHdl to be attached to spcmHdl
   g_ttsHdl = ttsHdl;
   /*Check if the parameter is correct and open suitable engine*/
#if defined(IFLY_TTS)
   ttsHdl->gender = TTS_GENDER_FEMALE;
   ttsHdl->lang   = TTS_LANG_MDN;
   ttsHdl->type   = TTS_TYPE_GPS;
   ttsHdl->aud_id = L1Audio_GetAudioID();
   ttsHdl->dataReq= KAL_TRUE;
   L1Audio_SetEventHandler( ttsHdl->aud_id, ttsTask );
#endif
   return ttsHdl;
}

#if defined(CYBERON_DIC_TTS)
/*=======================================================================
 *[Purpose]
 * Engine calls this function to load TTS data to memory from NAND Flash
 * [Return Value]
 * return file size (in byte) or -1 if fail
 * [Parameter]
 * lpszFilePath : path of data
 * lpbyBuf      : pointer of memory buffer which is used to read a file
 * bufSize      : size of lpbyBuf
 * [Remark]
 * Engine communicate outlayer with the interface
========================================================================*/
int TDic_HOST_load_dict_data_callback(TDicWchar* lpszFilePath, uint8* lpBuf, uint32 bufSize)
{
   int32 file_handle;
   uint32 fileSize, readCnt;
   file_handle = FS_Open((const kal_wchar *)lpszFilePath, FS_READ_ONLY); 
   ASSERT(file_handle > 0);
   
   FS_GetFileSize(file_handle, &fileSize);
   ASSERT(fileSize <= bufSize);
   
   ASSERT( FS_Read( file_handle, lpBuf, fileSize, &readCnt) >= 0 );
   FS_Close(file_handle);
   return fileSize;
}

void TDic_HOST_Debug_Trace_callback(signed char* lpszString)
{
   kal_prompt_trace(MOD_L1SPHISR, "%s", (char*)lpszString);
}
#endif

#endif //#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS)
