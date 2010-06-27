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
 * media.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Media file recording/playback
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __MEDIA_H
#define __MEDIA_H

#include "l1audio_def.h"
#include "gpt_sw.h"
#include "am.h"

#if !defined( MT6205B )
#include "ddload.h"     /* all chipsets, except MT6205B&MT6208, adopt dynamic downloading */
#endif

#define MASTER_GAIN_FACTOR          12
#define MEDIA_RB_DEFAULT_THRESHOLD  200
#define ID3V2_HEADER_LEN      10
#define DSP_WRITE(addr, data) (*(addr) = (kal_uint16)(data))

/*
   Warning:  any new declared variable should be placed at last of this structure 
             because "mediaControl" is used in ROMSA
*/

typedef struct {
   union {
      Media_SMF_Param      smf;
      Media_iMelody_Param  imy;
      uint32               vm;
   } param;
   int32          max_swing;        /* 0 ~ 32767                     */
   int8           key_shift;
   uint8          level;            /* Digital volume control 0~100 */
   uint8          gpt;
   bool           in_speech;
   Media_Format   format;
   Media_Event    end_status;
   uint16         rb_threshold;
   /* DSP ring buffer control variables */
   uint16         dsp_rb_base;
   uint16         dsp_rb_size;
   uint16         dsp_rb_end;
   uint16         dsp_last_sample;  /* The last sample written to DSP buffer by MCU, for last-sample padding */
   /* Ring buffer control variables */
   bool           eof;              /* Flag indicating End-Of-File   */
   bool           ob_flag_r;        /* if ob_flag_r is set, then the odd_byte for read is stored in odd_byte_r */
   bool           ob_flag_w;        /* if ob_flag_w is set, then the odd_byte for write is stored in odd_byte_w */
   uint8          odd_byte_r;
   uint8          odd_byte_w;
   uint16         *rb_base;         /* Pointer to the ring buffer    */
   uint32         rb_size;          /* Size of the ring buffer(word) */
   uint32         write;            /* R/W by MMI, R by WAV driver   */
   uint32         read;             /* R by MMI, R/W by WAV driver   */
   uint32         file_len;   /* for wav recordig */
#ifdef   DSP_WT_SYN
   int16          Media_FIR_Melody32K_1[25];
#endif
   bool           isDataConsumed;
   bool           is_stereo;
   bool           mono2stereo;
   bool           is_8KVoice;
   bool           CSD_Mode;
} mediaControl;


struct media_handle {
   kal_uint8      state;
   kal_bool       stop_flag;
   kal_int8       repeat_count;
   kal_uint8      volume_level;
   kal_uint8      index;
   kal_int32      start_time;
   kal_int32      current_time;
   kal_int32      stop_time;
   kal_uint32     data;
   void           (*handler)( Media_Handle *handle, Media_Event event );
   void           *param;
};

/*****************************************************************************
* Function Declaration
*****************************************************************************/
void  mediaInit( uint16 aud_id );
void  mediaHisr( uint16 flag );
int32 mediaGetFreeSpace( void );
int32 mediaGetDataCount( void );
void  mediaSetEvent( Media_Event event );
void  mediaHandler( void *data );
bool  mediaKeytoneForbidden( void );
bool  mediaIsDataConsumed( void );
mediaControl *mediaGetControl( void );
void  mediaDataNotification( void );

/* For Ring Buffer Access */
void  rb_ClearRB( void );
int32 rb_GetByteCount( void );
int32 rb_GetFreeSpace( void );
bool  rb_GetByte( uint8* data_8 );
bool  rb_GetWord( uint16* data_16 );
bool  rb_GetDWord( uint32* data_32 );
bool  rb_PeekByte( uint8* data_8 );
bool  rb_PeekWord( uint16* data_16 );
bool  rb_PeekDWord( uint32* data_32 );
bool  rb_PutByte( uint8 data_8 );
bool  rb_PutWord( uint16 data_16 );
bool  rb_PutDWord( uint32 data_32 );
uint32 rb_SkipNByte( uint32 skip_count );
uint32 rb_SkipNWord( uint32 skip_count );
uint32 rb_GetWriteIndex( void );
uint32 rb_GetReadIndex( void );
uint32 rb_GetSize( void );
uint16 rb_GetOBFlag( void );
uint16 rb_GetOddByte( void );
int rb_PutNByte( const uint8 *buffer, int len );
int rb_GetNByte( uint8 *buffer, int len );
/* For Ring Buffer Access */

void  pcmPlay( mediaControl *ctrl );
void  pcmRecord( mediaControl *ctrl );
void  pcmStop( void );
void  pcmPause( mediaControl *ctrl );
void  pcmResume( mediaControl *ctrl );
void  pcmPlaybackHisr( void );
void  pcmRecordHisr( void );

Media_Status  wavPlay( mediaControl *mctrl );
void  wavStop( void );
void  wavPause( mediaControl *mctrl );
void  wavResume( mediaControl *mctrl );
void  wavPlaybackHisr( void );
void  wavRecord( mediaControl *ctrl );
void  wavRecordHisr( void );
void  wavGetFileHeader( uint32 *len );
void  wavUpdateLevel( void );
void  wavInit( uint16 aud_id );
void  wavSetEvent( Media_Event event );

Media_Status  auPlay( mediaControl *mctrl );
void  auStop( void );
void  auPause( mediaControl *mctrl );
void  auResume( mediaControl *mctrl );
void  auPlaybackHisr( void );
void  auUpdateLevel( void );

Media_Status  aiffPlay( mediaControl *mctrl );
void  aiffStop( void );
void  aiffPause( mediaControl *mctrl );
void  aiffResume( mediaControl *mctrl );
void  aiffPlaybackHisr( void );
void  aiffUpdateLevel( void );

Media_Status dafPlay( mediaControl *ctrl );
void  dafStop( void );
void  dafPause( mediaControl *mctrl );
Media_Status  dafResume( mediaControl *mctrl );
void  dafPlaybackHisr( void );
void  dafUpdateLevel( void );

Media_Status aacPlay( mediaControl *ctrl );
void  aacStop( void );
Media_Status  aacPause( mediaControl *mctrl );
Media_Status  aacResume( mediaControl *mctrl );
void  aacPlaybackHisr( void );
void  aacUpdateLevel( void );

void  vmRecord( mediaControl *ctrl, uint16 type );
Media_Status  vmPlay( mediaControl *ctrl );
void  vmStop( void );
void  vmRecordHisr( void );
void  vmPlaybackHisr( void );
void  vmPause( mediaControl *ctrl );
void  vmResume( mediaControl *ctrl );

void  amrRecord( mediaControl *ctrl, uint16 type );
Media_Status  amrPlay( mediaControl *ctrl );
void  amrStop( void );
void  amrRecordHisr( void );
void  amrPlaybackHisr( void );
void  amrPause( mediaControl *ctrl );
void  amrResume( mediaControl *ctrl );
void  amrUpdateLevel( void );

void  amr515Init( uint16 aud_id );
void  amr515Record( mediaControl *ctrl );
void  amr515Stop( void );
void  amr515Pause(mediaControl *mctrl);
void  amr515Resume(mediaControl *mctrl);
void  amr515RecordHisr( void );

void VoIPevInit( void );
void  VoIPevRecord( mediaControl *ctrl );
void  VoIPevStop( void );
void  VoIPevPause( void );
void  VoIPevResume( void );

void  smfInit( uint16 aud_id );
void  smfSetEvent( Media_Event event );
Media_Status smfStart( mediaControl *ctrl );
void  smfStop( void );

/*
void  smfSndInit( void );
Media_Status smfSndPlay( Media_SMF_SND_Param *param );
void  smfSndMix( void );
*/

void  imyInit( uint16 aud_id );
void  imySetEvent( Media_Event event );
Media_Status imyStart( mediaControl *ctrl );
void  imyStop( void );

Media_Status smfDspStart( mediaControl *ctrl );
void  smfDspStop( void );

Media_Status imyDspStart( mediaControl *ctrl );
void  imyDspStop( void );

#if defined(EXT_AUDIO_CHIP)
/* abstract audio adaptation layer */
void AbsExtAudChip_Init(uint16 aud_int);
Media_Status AbsExtAudChip_Play( mediaControl *ctrl );
Media_Status AbsExtAudChip_Stop( mediaControl *ctrl );
Media_Status AbsExtAudChip_Pause( mediaControl *ctrl );
Media_Status AbsExtAudChip_Resume( mediaControl *ctrl );
Media_Status AbsExtAudChip_SetVolume( mediaControl *ctrl, uint8 volume );
Media_Status AbsExtAudChip_Control( mediaControl *ctrl );

/* audio adaptation layer */
typedef struct {
   const uint8 *melody_data;
   int32 data_length;
   int16 repeat_times;
   Media_Format  format;
   struct {
      int16  cmd_type;
      uint16 cmd_len;
      const uint8  *cmd_data;
      uint8 *return_data;
   }command;
} AudChipControl;

void ExtAudChip_Init( void  );
#define AudChip_Status Media_Status
#define ExtAudChip_ReturnSuccess {return MEDIA_SUCCESS;}
#define ExtAudChip_ReturnFail {return MEDIA_FAIL;}

AudChip_Status ExtAudChip_Play( AudChipControl *audControl  );
AudChip_Status ExtAudChip_Stop( AudChipControl *audControl  );
AudChip_Status ExtAudChip_Pause( AudChipControl *audControl  );
AudChip_Status ExtAudChip_Resume( AudChipControl *audControl  );
AudChip_Status ExtAudChip_SetVolume( AudChipControl *audControl , uint8 volume );
AudChip_Status ExtAudChip_Control( AudChipControl *audControl  );
void ExtAudChip_Reset( void );

void ExtAudChip_SetEventHandler(void(*eventHandler)(void *param));
void ExtAudChip_SetEvent(void *param);

void ExtAudChip_NotifyError(void);
void ExtAudChip_NotifyStop(void);
void ExtAudChip_NotifyEOF(void);
void ExtAudChip_NotifyRepeated(void);


#if defined(YAMAHA_MA3)
void YamahaMa3_SpkAmpOn(void);
void YamahaMa3_SpkAmpOff(void);
#endif

#if defined(ROHM_8788)
void RegWrite( int nAdrs, int nData );
uint8 RegRead( int nAdrs );
#endif

#endif

void  ktInit( uint16 aud_id );
void  ktLock( void );
void  ktUnlock( void );
void  toneInit( uint16 aud_id );

void JSmf_Init( void );
void JImy_Init( void );
void JTone_Init( mediaControl *ctrl );
void JWav_Init( mediaControl *ctrl );
void JXWav_Init( mediaControl *ctrl );

/* Obsolete functions: MIDI playback interface using GMI interface */
Media_Status midiPlay( mediaControl *ctrl );
void  midiStop( void );

void iMelodyInit( uint16 aud_id );
Media_Status iMelodyPlay( mediaControl *ctrl );
void iMelodyStop( void );

/* A/V Sync interface */
#define VERIFY_AVSYNC 0
void Media_A2V_LISR( void );

void   FMR_Init(uint16 aud_id);

void   vrsdInit( void );

#define VERIFY_DATA_TO_DSP 0

/* VRSI interface */
void vrsiInit( void );

/* L1CTM interface */ 
void l1ctm_init( void );

// Audio Framework Revise
void mhdlInit( MHdl *hdl, kal_uint32 hisrMagic, void hisrHdlr( void *data ) );
void mhdlInitEx( MHdl *hdl, kal_uint32 hisrMagic, void hisrHdlr( void *data ) );
void mhdlFinalize( MHdl *hdl, kal_uint32 hisrMagic );
void mhdlException( MHdl *hdl, Media_Event event );
void mhdlAllowSleep( MHdl *hdl );
void mhdlDisallowSleep( MHdl *hdl );
void mhdlDataRequest( MHdl *hdl, Media_Event end_status);
void mhdlDataNotification( MHdl *hdl );

kal_uint8 autGetBitsFromBuf(kal_uint8 *pBuf, kal_uint32 *puBitCnt, kal_uint32 uBitLen);
kal_int32 autGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr);
kal_int32 autGetBytes(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 uLen, kal_uint8 *pbBuf);
void autSkipID3Tag( MHdl *hdl, STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *ptr );
void autWriteDataToDSP( MHdl *hdl, kal_uint16 *dspWritePtr, kal_uint16 *dspReadPtr, kal_uint32 pageNum, void(*incTime)(MHdl *handle, kal_uint32 num_bytes ));

// speech enhancement control functions
#define SPE_ES_FLAG     (1 << 0) 
#define SPE_AEC_FLAG    (1 << 1) 
#define SPE_EES_FLAG    (1 << 2) 
#define SPE_UL_NR_FLAG  (1 << 3) 
#define SPE_DL_NR_FLAG  (1 << 4) 
void SPE_LoadSpeechPara( uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS] );
void SPE_LoadSpeechPara_ES( uint16 timeConst, uint16 volConst );
void SPE_Init( void );
void SPE_TurnOnProcess(uint8 on_state);
void SPE_TurnOffProcess(uint8 off_state);
void SPE_Clear_DLL_Entry(uint8 cur_state);
void SPE_SetSBSD( bool state );
void SPE_SetULNR( bool ec );
void SPE_LoadLimiterPara(uint16 para);

/* L1SP interface */ 
void L1SP_Init( void );
void L1SP_LoadSpeechPara( void );
void L1SP_Register_Service(void (*onHandler)(void *), void (*offHandler)(void *));
void L1SP_UnRegister_Service( void );
void L1SP_SetState(kal_uint8 state);
kal_uint8 L1SP_GetState( void );

enum{
   L1SP_STATE_IDLE = 0, 
   L1SP_STATE_2G_SPEECH_ON,
   L1SP_STATE_3G_SPEECH_ON,
   L1SP_STATE_3G324M_SPEECH_ON,
   L1SP_STATE_3G_SPEECH_CLOSING,    
   L1SP_STATE_3G_SPEECH_CLOSED 
}; 

void sp3g_speech_init( uint8 RAT_Mode );
void sp3g_speech_close( void );

void VMI_HookPostHandler( void (*PostHandler)(void *) );
void VMI_UnhookPostHandler( void );

kal_uint32 L1Audio_GetEventGroup( void );
void L1Audio_ExeEventHandler( kal_uint32 event );

#endif /* __MEDIA_H */


