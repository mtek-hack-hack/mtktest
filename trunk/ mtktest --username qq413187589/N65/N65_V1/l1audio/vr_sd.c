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
 * vr_sd.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Voice Recognition (speaker dependent)
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/* file system */
#include "fat_fs.h"
/* layer1 audio */
#include "media.h"
#include "ddload.h"

#if defined(VR_CYBERON)

/* VR engine */
#if defined(VR_CYBERON)
#include "vr_sd.h"
#endif   //  end of "#if defined(VR_CYBERON)"

/* VR task status */
#define  VR_STATE_IDLE                 0x00
#define  VR_STATE_INITIALIZED          0x01
#define  VR_STATE_READY                0x02
#define  VR_STATE_T_PROCESSING1        0x04
#define  VR_STATE_T_WAITING            0x08
#define  VR_STATE_T_PROCESSING2        0x10
#define  VR_STATE_R_PROCESSING         0x20

/* state definition inside VR_Process */
#define  VR_STATE_PROCESSING_INIT      0x01
#define  VR_STATE_PROCESSING_ENVDATA   0x02
#define  VR_STATE_PROCESSING_PUTDATA   0x04
#define  VR_STATE_PROCESSING_PROCESS   0x08

/* common definition */
#define  FR_BUF_SIZE_BYTE        34     // package size of GSM FR speech (in byte)
#define  FR_BUF_SIZE_WORD        17     // (in short)
#define  CEP_BUF_SIZE_BYTE       20     // storage size of Cepstrum features per frame (in byte)
#define  CEP_BUF_SIZE_WORD       10     // (in short)
#define  FRAME_BUF_NO            128    // maximum buf #
#define  FRAME_PER_SEC           50
#define  MAX_REC_SEC              3
#define  FRAME_BUF_MASK          (FRAME_BUF_NO-1)
#define  MSG_MASK                 7

#define  CYBERON_DYNAMIC_BUF    (FRAME_BUF_NO * FR_BUF_SIZE_BYTE)

#define  MAX_FR_STORAGE_SIZE     (FR_BUF_SIZE_BYTE * FRAME_PER_SEC * MAX_REC_SEC)
#define  DTW_TMP_BUF_SIZE      1500
#define  DTW_TMP_BUF_NUM          3
#define  MAX_DTW_TMP_BUF_SIZE    (DTW_TMP_BUF_SIZE * DTW_TMP_BUF_NUM)

#define  DISK_ERROR            0x01
#define  DISK_FULL             0x02

extern void ktLock( void );
extern void ktUnlock( void );

/***********************************************************
*                  GLOBAL PARAMETERS                       *
***********************************************************/
typedef struct{
   uint8     *ptrRunTimeMem;            // pointer to the run-time Memory
   uint8     *databaseDir;              // pointer to database directory
   uint8     *cirBufAddr[FRAME_BUF_NO]; // pointer to frame buffer
   int32     currentID;                 // current training ID
   uint32    tmp_file_header[5];
   bool      vrRecordingOn;             // recording status
   kal_wchar file_name[50];             // file path
   uint16    processState;              // status in VR_Process
   uint16    isDiskError;               // bit0: disk error, bit1: disk full
   uint8     cirBufReadIdx;             // index variable for circular buffer (read)
   uint8     cirBufWriteIdx;            // (write)
}vrsdStruct;

static struct{
   void      (*vr_handler)( void *data ); // evHandler, callback function
   uint32    sibRunTimeMemSize;         // run-time memory size in byte
   uint16    aud_id;                    // evHandler id
   uint16    state;                     // VR task status
}vrsdInitVar;

static vrsdStruct *vrsdVar;

/*********************************************
*  macro and sub-routines                    *
*********************************************/
#if defined(VR_CYBERON)
#define VR_ENGINE_INIT_CYB() { \
   if(BSR_Init(BSR_TAGS_LIMIT_20, vrsdVar->ptrRunTimeMem, vrsdInitVar.sibRunTimeMemSize) == BSRRES_FAILED) \
      return VR_FAILED; \
   if(BSR_SetMode(ENGINE_DEFAULT_MODE) == BSRRES_FAILED) \
      return VR_FAILED; \
   if( BSR_SelectContext(mdIDList, *mdIDListLen) == BSRRES_FAILED){ \
      if(vrsdVar->isDiskError & DISK_FULL)   return VR_FLASH_DISK_FULL; \
      if(vrsdVar->isDiskError & DISK_ERROR)   return VR_FLASH_ERROR; \
      return VR_FAILED; \
   } \
}  /* VR engine initialization */
#endif  // end of "#if defined(VR_CYBERON)"

static void vrsdFreeBuf(void)
{
   ktUnlock();
   if( vrsdInitVar.state >= VR_STATE_T_PROCESSING1){ // vrsdVar->vrRecordingOn){
      L1Audio_ClearFlag( vrsdInitVar.aud_id );  // unlock sleep mode
      L1Audio_FreeAudioID( vrsdInitVar.aud_id );
      L1Audio_UnhookHisrHandler( DP_D2C_SE_DONE ); // FR data input
   }
   free_ctrl_buffer( vrsdVar );
   vrsdVar = (vrsdStruct*)0;
}

#define VR_GET_DATA(len) { \
   for( I = len; I != 0; I-- ) \
   { \
      uint16 tmp = *addr++; \
      *buf++ = (uint8)(tmp & 0xFF);  \
      *buf++ = (uint8)((tmp>>8)&0xFF); \
   } \
} // must meet the required alignment

/*************************************************************************
*  Hisr routine, Get data from SHERIF and put it into circular buffer    *
**************************************************************************/
static void vrsdRecFRHisr( void *data )
{
   volatile uint16 *addr;
   volatile uint8 *buf;
   int32 I;

   if(!(vrsdVar->processState & (VR_STATE_PROCESSING_ENVDATA | VR_STATE_PROCESSING_PUTDATA))
      || (vrsdInitVar.state & VR_STATE_IDLE))
      return;
#if defined(VR_CYBERON)
   if( (uint8)(vrsdVar->cirBufWriteIdx - vrsdVar->cirBufReadIdx) >= FRAME_BUF_NO ) // overflow checking
      return;
   buf = vrsdVar->cirBufAddr[vrsdVar->cirBufWriteIdx&FRAME_BUF_MASK];  // destination
   vrsdVar->cirBufWriteIdx++;
#endif    // #if defined(VR_CYBERON)
   addr = DP_TX_TCH_S( 0, 1 ); // source

   VR_GET_DATA(FR_BUF_SIZE_WORD);
#if defined(VR_CYBERON)
   if((vrsdVar->cirBufWriteIdx&MSG_MASK) == MSG_MASK)  // callback per 160ms
      vrsdInitVar.vr_handler( (void *)0 );
#endif
}

/**********************************************
*   Get parameters of VR engine               *
***********************************************/
VR_Result VR_GetParameters(int16 *SimThrld, int16 *DiffThrld, int16 *RejThrld)
{
#if defined(VR_CYBERON)
   int16 NoiseRejThrld[8]; // dummy
   if(BSR_GetParameters(SimThrld, DiffThrld, RejThrld, NoiseRejThrld) == BSRRES_FAILED)
      return VR_FAILED;
#endif     // end of "#if defined(VR_CYBERON)"
   return VR_OK;
}

/**********************************************
*   Set parameters to VR engine               *
***********************************************/
VR_Result VR_SetParemeters(int16 SimThrld, int16 DiffThrld, int16 RejThrld)
{
#if defined(VR_CYBERON)
   int16 vrsdNoiseRejThrld[8]={0,0,0,0,0,0,0,0};
   if(BSR_SetParameters(SimThrld, DiffThrld, RejThrld, vrsdNoiseRejThrld) == BSRRES_FAILED)
#endif    // end of "#if defined(VR_CYBERON)"
      return VR_FAILED;
   return VR_OK;
}

static void vrsdResetVar(void)
{
   vrsdVar->ptrRunTimeMem=0;
   vrsdVar->databaseDir=0;
   vrsdVar->currentID=0;
   vrsdVar->vrRecordingOn=false;
   vrsdVar->processState=VR_STATE_PROCESSING_INIT;
   vrsdVar->isDiskError=0;
   vrsdVar->cirBufReadIdx=0;
   vrsdVar->cirBufWriteIdx=0;
}

/************************************************************
* inquire run-time memory size                              *
*************************************************************/
uint32 VR_GetBufferSize(void)
{
   uint32 buffer_size;
   ktLock();
   ASSERT( vrsdVar == (vrsdStruct *)0 ); // to be removed
   vrsdVar = (vrsdStruct*)get_ctrl_buffer( sizeof(vrsdStruct) );
   ASSERT( vrsdVar != (vrsdStruct *)0 );

   vrsdResetVar();
#if defined(VR_CYBERON)
   buffer_size = vrsdInitVar.sibRunTimeMemSize + CYBERON_DYNAMIC_BUF;
#endif
   return (buffer_size);
}

/*************************************************************
*        Assign run-time memory                              *
**************************************************************/
void VR_SetBuffer(uint8 *RTmemory)
{
   int32 cnt;
   vrsdInitVar.state = VR_STATE_INITIALIZED;
   vrsdVar->ptrRunTimeMem = RTmemory;

   ASSERT(((uint32)RTmemory & 1)==0); // to insure two byte alignment
   for( cnt = 0; cnt < FRAME_BUF_NO; cnt++ )   /* arrange for circular buf */
#if defined(VR_CYBERON)
      vrsdVar->cirBufAddr[cnt] = &RTmemory[ vrsdInitVar.sibRunTimeMemSize + FR_BUF_SIZE_BYTE*cnt];
#endif // end of "#if defined(VR_CYBERON)"
}

/**************************************************************
*       Set database directory for flash access.              *
***************************************************************/
VR_Result VR_SetDatabaseDir(uint8 *Dir)
{
   ASSERT(vrsdInitVar.state & VR_STATE_INITIALIZED);
   vrsdInitVar.state = VR_STATE_READY;
   vrsdVar->databaseDir = Dir;
   return VR_OK;
}

/***************************************************************************
*   Start VR training with an assigned ID                                  *
****************************************************************************/
VR_Result VR_TRA_Start(uint16 wID, uint16 *mdIDList, uint16 *mdIDListLen, void (*vr_handler)(void *data ))
{
   mediaControl *mctrl;
   uint16 *RcgID; // dummy
   ASSERT(vrsdInitVar.state & VR_STATE_READY);
   vrsdInitVar.vr_handler = vr_handler;
   vrsdVar->currentID = wID;
   vrsdVar->isDiskError = 0;

   mctrl = mediaGetControl();
   mctrl->format = MEDIA_FORMAT_VRD;

   L1Audio_HookHisrHandler( DP_D2C_SE_DONE, vrsdRecFRHisr, 0 );

   vrsdVar->vrRecordingOn = true;
#if (defined(VR_CYBERON))   // VR engine initialization
   VR_ENGINE_INIT_CYB();
   if(BSR_TrainInit(wID) == BSRRES_FAILED)
      return VR_FAILED;
   if(BSR_CaptureInit() == BSRRES_FAILED)
      return VR_FAILED;
   AM_VMRecordOn( (uint16)0 ); /* GSM FR */
#endif // #if (defined(VR_CYBERON))

   vrsdInitVar.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( vrsdInitVar.aud_id );

   vrsdInitVar.state = VR_STATE_T_PROCESSING1;
   vrsdVar->processState = VR_STATE_PROCESSING_INIT;
   VR_Process(RcgID);
   return VR_OK;
}

/******************************************************
*       Start 2nd stage VR training                   *
*******************************************************/
VR_Result VR_TRA2Start(void)
{
   uint16 *RcgID; // dummy
   mediaControl *mctrl;

   ASSERT(vrsdInitVar.state & VR_STATE_T_WAITING);
   mctrl = mediaGetControl();
   mctrl->format = MEDIA_FORMAT_VRD;

   vrsdVar->vrRecordingOn = true;
#if (defined(VR_CYBERON))
   if(BSR_CaptureInit() == BSRRES_FAILED)
      return VR_FAILED;
   AM_VMRecordOn( (uint16)0 ); /* GSM FR */
#endif

   vrsdInitVar.state = VR_STATE_T_PROCESSING2;
   vrsdVar->processState = VR_STATE_PROCESSING_INIT;
   VR_Process(RcgID);
   return VR_OK;
}

/********************************************************
*      Start VR recognition                             *
*********************************************************/
VR_Result VR_RCG_Start(uint16 *mdIDList,uint16 *mdIDListLen,void(*vr_handler)(void *data))
{
   mediaControl *mctrl;
   uint16 *RcgID; // dummy

   ASSERT(vrsdInitVar.state & VR_STATE_READY);
   vrsdInitVar.vr_handler = vr_handler;
   mctrl = mediaGetControl();
   mctrl->format = MEDIA_FORMAT_VRD;
   vrsdVar->isDiskError = 0;

   L1Audio_HookHisrHandler( DP_D2C_SE_DONE, vrsdRecFRHisr, 0 );

   vrsdVar->vrRecordingOn = true;
#if defined(VR_CYBERON)
   VR_ENGINE_INIT_CYB();
   if(BSR_RecogInit() == BSRRES_FAILED)
      return VR_FAILED;
   if(BSR_CaptureInit() == BSRRES_FAILED)
      return VR_FAILED;
   AM_VMRecordOn( (uint16)0 ); /* GSM FR */
#endif    // #if defined(VR_CYBERON)

   vrsdInitVar.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( vrsdInitVar.aud_id );
   vrsdInitVar.state = VR_STATE_R_PROCESSING;
   vrsdVar->processState = VR_STATE_PROCESSING_INIT;
   VR_Process(RcgID);
   return VR_OK;
}

/************************************************************
*    VR process sub-routines                                *
************************************************************/
#if defined(VR_CYBERON)
static VR_Result vrPutDataCYB(void)
{
   uint32 I;
   FRESULT res;
   uint8 *ptr;
   if((uint8)(vrsdVar->cirBufWriteIdx - vrsdVar->cirBufReadIdx) > 0){ // buffer is not empty
      do{
         ptr = vrsdVar->cirBufAddr[vrsdVar->cirBufReadIdx&FRAME_BUF_MASK];
         vrsdVar->cirBufReadIdx++;
         res = BSR_PutData(ptr);
      }while(((uint8)(vrsdVar->cirBufWriteIdx - vrsdVar->cirBufReadIdx) > 0) && (res == BSRRES_PROCESSING));
      if(res != BSRRES_PROCESSING){
         vrsdVar->processState = VR_STATE_PROCESSING_PROCESS;
         AM_VMRecordOff();
         AM_FlushQFunction();
         vrsdVar->vrRecordingOn = false;
         if(res == BSRRES_FAILED)   return VR_FAILED;
         vrsdInitVar.vr_handler( (void *)0 );
      }
   } // end of "if(vrsdVar->cirBufWriteIdx - vrsdVar->cirBufReadIdx > 0)"
   return VR_OK;
}
static VR_Result vrProcessCYB(void)
{
   FRESULT res;
   do{       //Process
      res = BSR_Process();
   } while(res == BSRRES_PROCESSING);
   if(res == BSRRES_FAILED)   return VR_FAILED;
   return VR_OK;
}
static VR_Result vrRcgGetResultCYB(uint16 *RcgID)
{
   FRESULT res;
   uint16 len; // useless
   res = BSR_GetRecogRes(RcgID, &len);   //GetRecogRes
   if(res==BSRRES_OK)   return VR_FINISHED;
   return VR_FAILED;
}
static VR_Result vrTraGetResultCYB(void)
{
   FRESULT resTrain;
   resTrain = BSR_GetTrainRes();      // get training result;
   if (resTrain == BSRRES_NEED_MORE_SAMPLE){
      vrsdInitVar.state = VR_STATE_T_WAITING;
      return VR_CONTINUE;
   }
   if(vrsdInitVar.state == VR_STATE_T_PROCESSING2 && resTrain == BSRRES_OK){
      BSR_SaveID();  //SaveID
      if(vrsdVar->isDiskError & DISK_FULL)   return VR_FLASH_DISK_FULL;
      if(vrsdVar->isDiskError & DISK_ERROR)   return VR_FLASH_ERROR;

      return VR_FINISHED;
   }
   return VR_FAILED;
}
static VR_Result vrGetErrorMsgCYB(void)
{
   BSR_Err msg;
   msg = BSR_GetLastError();
   switch(msg)
   {
	   case BSRERR_NO_SOUND:
	            return VR_NO_SOUND;
	   case BSRERR_TOO_SIM:
	            return VR_TOO_SIM;
	   case BSRERR_TOO_DIFF:
	            return VR_TOO_DIFF;
	   case BSRERR_SDMODEL_NOT_READY:
	            return VR_SDMODEL_NOT_READY;
	   case BSRERR_VOICE_BUF:
	            return VR_TOO_LONG;
	   case BSRERR_DUR_TOO_SHORT:
	            return VR_TOO_SHORT;
   }
   return VR_FAILED;
}
#endif   // end of "#if defined(VR_CYBERON)"

/**********************************************************************************************
*  VR_Process(), Three things are involved in this function:                                  *
*  1. Feed data into VR engine to extract features                                            *
*  2. In training session, it will process the captured speech data like similarity checking, *
*     difference checking and model training.                                                 *
*  3. In recognition session, it will process the captured speech data and match the best     *
*     voice model trained                                                                     *
***********************************************************************************************/
#if defined(VR_CYBERON)
VR_Result VR_Process(uint16 *RcgID)
{
   VR_Result result;
   ASSERT(vrsdInitVar.state & (VR_STATE_T_PROCESSING1 | VR_STATE_T_PROCESSING2 | VR_STATE_R_PROCESSING));
   switch(vrsdVar->processState)
   {
      case VR_STATE_PROCESSING_INIT:
              vrsdVar->processState = VR_STATE_PROCESSING_PUTDATA;
      case VR_STATE_PROCESSING_PUTDATA:
              result = vrPutDataCYB();
              if(result == VR_FAILED){
                 result = vrGetErrorMsgCYB();
                 vrsdFreeBuf();
                 vrsdInitVar.state = VR_STATE_IDLE;
                 return result;
              }
              return VR_OK;

      case VR_STATE_PROCESSING_PROCESS:
              result = vrProcessCYB();
              if( result == VR_FAILED){
                 result = vrGetErrorMsgCYB();
                 vrsdFreeBuf();
                 vrsdInitVar.state = VR_STATE_IDLE;
                 return result;
              }

              if(vrsdInitVar.state == VR_STATE_R_PROCESSING){ // RCG
                 result = vrRcgGetResultCYB(RcgID);
                 if(result == VR_FAILED)
                    result = vrGetErrorMsgCYB();
                 vrsdFreeBuf();
                 vrsdInitVar.state = VR_STATE_IDLE;
                 return result;
              } // end of "if(vrsdInitVar.state == VR_STATE_R_PROCESSING)"

              result = vrTraGetResultCYB();  // Training
              if(result == VR_FAILED)
                 result = vrGetErrorMsgCYB();
              if(result != VR_CONTINUE){
                 vrsdFreeBuf();
                 vrsdInitVar.state = VR_STATE_IDLE;
              }
              return result;
      default:
           ASSERT(KAL_FALSE);  // should never reach here
   } // end of "switch(vrsdVar->processState)"
   return VR_FAILED;
}
#endif

/************************************************************
*       Stop/Abort VR task immediately                      *
*************************************************************/
void VR_Stop(void)
{
   uint32 I;
   if(vrsdInitVar.state == VR_STATE_IDLE)
      return;
#if defined(VR_CYBERON)
   if(vrsdVar->vrRecordingOn){
      AM_VMRecordOff();
      AM_FlushQFunction();
   }
#endif
   if(vrsdVar != (vrsdStruct *)0){
      vrsdFreeBuf();
      vrsdInitVar.state = VR_STATE_IDLE; /* return to idle state */
   }
}

/************************************************************
*       Get engine version                                  *
*************************************************************/
int32 VR_GetEngineVer(void)
{
#if defined(VR_CYBERON)
   return 1;
#endif
   return -1; // should never reach here
}

int32 vrsdCheckDiskFull(int32 errorCode)
{
   if(errorCode == FS_DISK_FULL){
      vrsdVar->isDiskError |= DISK_FULL;
      return 1;
   }
   else if(errorCode < 0){
      vrsdVar->isDiskError |= DISK_ERROR;
      return 1;
   }
   return 0;
}

void vrsdDiskErrorHandle(int32 errorCode, int32 fileHandle, kal_wchar *fileName)
{
   vrsdCheckDiskFull(errorCode);
   FS_Close( fileHandle );
   FS_Delete(fileName);
}

/***********************************************
*       write a record to file system          *
***********************************************/
int32 host_write_record(uint16 wID, uint8 *lpszModel, uint16 wModelLen, uint8 *lpszVoice, uint32 dwVoiceLen)
{
   uint32 len;
   int32  file_handle, errorCode;
   uint8  *ptr;

/* Preset file header, vrs_ptr->tmp_file_header is properly aligned for 4 bytes */
   ptr = (uint8 *)vrsdVar->tmp_file_header;
#if defined(VR_CYBERON)   // read model
   *(uint32 *) ptr = 0x56425943; // Chunk ID, "CYBV"
#endif
   *(uint32 *)(ptr+4) = (uint32)(wModelLen + dwVoiceLen + 18); // Chunk size
   *(uint16 *)(ptr+8) = wID;     // voice tag ID
   *(uint16 *)(ptr+10) = 0x4F56; // Sub-chunk1 ID, "VOCE"
   *(uint16 *)(ptr+12) = 0x4543; // Required alignment is 2
   *(uint16 *)(ptr+14) = (uint16)(dwVoiceLen&0x0000FFFF); // sub-chunk2 size
   *(uint16 *)(ptr+16) = (uint16)((dwVoiceLen>>16)&0x0000FFFF);
/* create a VRD file */
   kal_wsprintf(vrsdVar->file_name, "%w\\MTKVR_%04x.%s", vrsdVar->databaseDir,wID,"vrd");
   file_handle = FS_Open(vrsdVar->file_name,  FS_READ_WRITE | FS_CREATE_ALWAYS);
   if(vrsdCheckDiskFull(file_handle)) return 1;

/* write file header */
   FS_Write( file_handle, vrsdVar->tmp_file_header, 18, &len );

/* write voice data */
   FS_Write( file_handle, lpszVoice, dwVoiceLen, &len );

/* write sub-chunk2 ID and size */
   *(uint32 *)ptr = 0x4C444F4D; // "MODL"
   *(uint32 *)(ptr+4) = (uint32)wModelLen;
   FS_Write( file_handle, vrsdVar->tmp_file_header, 8, &len );

/* write HMM model or cepstrum features */
   errorCode = FS_Write( file_handle, lpszModel, wModelLen, &len );
   if( errorCode != FS_NO_ERROR || len != wModelLen ){
      vrsdDiskErrorHandle( errorCode, file_handle, vrsdVar->file_name);
      return 1;
   }
/* close file */
   FS_Close( file_handle );
   return 0;
}

/**********************************************
*  The function is used to read the model     *
**********************************************/
int32 host_read_model(uint16 wID, uint8 *lpszModel, uint16 wModelLen)
{
   int32  file_handle, errorCode;
   uint32 read_len, offset, chunkID;
/* open file */
   kal_wsprintf(vrsdVar->file_name, "%w\\MTKVR_%04x.%s", vrsdVar->databaseDir,wID,"vrd");
   file_handle = FS_Open(vrsdVar->file_name, FS_READ_ONLY);
   if(vrsdCheckDiskFull(file_handle)) return 0;

   /* Check to see if header is invalid, "MTKV" or "CYBV" chunk descriptor */
   FS_Read(file_handle, &chunkID, 4, &read_len);
#if defined(VR_CYBERON)   // read model
   ASSERT(chunkID == 0x56425943);
#endif
   FS_Seek(file_handle, 10, FS_FILE_CURRENT);
   FS_Read(file_handle, &offset, 4, &read_len);
   FS_Seek(file_handle, offset+4, FS_FILE_CURRENT);
   FS_Read(file_handle, &offset, 4, &read_len); // sub-chunk2 size (model size in byte)

#if defined(VR_CYBERON)   // read model ,fixed model size
   errorCode = FS_Read(file_handle, lpszModel, wModelLen, &read_len);
#endif
   if(errorCode < 0){
      vrsdDiskErrorHandle( errorCode, file_handle, vrsdVar->file_name);
      return 0;
   }
   FS_Close(file_handle);   /* close the file */
   return (int32)read_len;
}

void vrsdInit( void )  /*  VR task initialization */
{
   vrsdInitVar.state = VR_STATE_IDLE;
#if defined(VR_CYBERON)
   vrsdInitVar.sibRunTimeMemSize = BSR_GetRTMemSize(BSR_TAGS_LIMIT_20);
#endif
}

#endif // #if defined(VR_CYBERON)

