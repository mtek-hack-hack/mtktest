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
 * Filename:
 * ---------
 *  l1sp.h
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   Audio Task interface definition
 *
 * Author:
 * -------
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef L1AUDIO_H
#define L1AUDIO_H

#ifdef __MTK_TARGET__
  #include "kal_release.h"
  #include "l1audio_trace.h"
  #include "med_status.h"
  #include "app_buff_alloc.h"
  #include "fsal.h"
#else
  #include "kal_non_specific_general_types.h"
  #include "med_status.h"
  #include "fsal.h"
#endif

/* ------------------------------------------------------------------------------ */
/*  Audio Function Definition                                                     */
/* ------------------------------------------------------------------------------ */
#define  L1SP_KEYTONE         0
#define  L1SP_TONE            1
#define  L1SP_SPEECH          2
#define  L1SP_SND_EFFECT      3
#define  L1SP_AUDIO           4
#define  L1SP_VOICE           5
#define  L1SP_DAI             6
#define  L1SP_FM_RADIO        7
#define  L1SP_MAX_AUDIO       8

#define  SRC_VOICE_DAC        0
#define  SRC_AUDIO_DAC        1
#define  SRC_EXT_INPUT        2

#define  SND_SRC_MAP   (kal_uint32)((SRC_VOICE_DAC<<L1SP_KEYTONE*2) |      \
                                    (SRC_VOICE_DAC<<L1SP_TONE*2) |         \
                                    (SRC_VOICE_DAC<<L1SP_SPEECH*2) |       \
                                    (SRC_VOICE_DAC<<L1SP_SND_EFFECT*2) |   \
                                    (SRC_AUDIO_DAC<<L1SP_AUDIO*2) |        \
                                    (SRC_VOICE_DAC<<L1SP_VOICE*2) |        \
                                    (SRC_VOICE_DAC<<L1SP_DAI*2) |          \
                                    (SRC_EXT_INPUT<<L1SP_FM_RADIO*2))

#define  MAX_AUDIO_FUNCTIONS     18
#define  INVALID_AUDIO_ID        MAX_AUDIO_FUNCTIONS

typedef  void  (*L1Audio_EventHandler)(void*);


kal_int8 L1Audio_Disable_DSPSlowIdle(void);
kal_int8 L1Audio_Enable_DSPSlowIdle(void);

kal_uint16  L1Audio_GetAudioID( void );
void        L1Audio_FreeAudioID( kal_uint16 aud_id );
void        L1Audio_SetEventHandler( kal_uint16 audio_id, L1Audio_EventHandler handler );
void        L1Audio_SetEvent( kal_uint16 audio_id, void *data );
void        L1Audio_LSetEvent( kal_uint16 audio_id, void *data );
kal_bool    L1Audio_CheckFlag( kal_uint16 audio_id );
void        L1Audio_SetFlag( kal_uint16 audio_id );
void        L1Audio_ClearFlag( kal_uint16 audio_id );
void        L1Audio_HookHisrHandler( kal_uint16 magic_no, L1Audio_EventHandler handler, void *userData );
void        L1Audio_UnhookHisrHandler( kal_uint16 magic_no );
void        L1Audio_SetPostHisrHandler( L1Audio_EventHandler handler );
void        L1Audio_ResetPostHisrHandler( void );

void        L1Audio_EnterDedicatedMode( void );
void        L1Audio_LeaveDedicatedMode( void );
void        L1Audio_ResetDevice( void );

typedef void (*media_in_proc_call_type)( kal_uint32 arg1, void* arg2 );
void L1Audio_InProcCall(media_in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2);
void L1Audio_InProcCall2(media_in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2);

#define  NUM_DEBUG_INFO    8
#define  VM_DEBUG_INFO     0
#define  VOIPEVL_DEBUG_INFO  1
void        L1Audio_SetDebugInfo( kal_uint16 debug_info[NUM_DEBUG_INFO]);
kal_uint16  L1Audio_GetDebugInfo( kal_uint8 index );
/* ------------------------------------------------------------------------------ */
/*  Audio Front End Interface                                                     */
/* ------------------------------------------------------------------------------ */
/* -------------------------------- */
/*  Audio Output Device Definition  */
/* -------------------------------- */
#define  L1SP_BUFFER_0        0x01    /* NOTE: Don't use buffer definition directly   */
#define  L1SP_BUFFER_1        0x02    /*       Use speaker definition below           */
#define  L1SP_BUFFER_ST       0x04
#define  L1SP_BUFFER_EXT      0x08
#define  L1SP_BUFFER_EXT_G    0x10
#define  L1SP_STEREO2MONO     0x20     /* Do not use this term for speaker definition */
#define  L1SP_BUFFER_ST_M     (L1SP_BUFFER_ST|L1SP_STEREO2MONO)
#define  L1SP_EXT_DAC_BUF0    0x40 
#define  L1SP_EXT_DAC_BUF1    0x80

#define  L1SP_LNA_0           0
#define  L1SP_LNA_1           1
#define  L1SP_LNA_FMRR        3

extern const kal_uint8  L1SP_MICROPHONE1;
extern const kal_uint8  L1SP_MICROPHONE2;
extern const kal_uint8  L1SP_SPEAKER1;
extern const kal_uint8  L1SP_SPEAKER2;
extern const kal_uint8  L1SP_LOUD_SPEAKER;


#define  EXT_DAC_I2S          0x1 
#define  EXT_DAC_LINEIN       0x2 
extern const unsigned char  L1SP_EXT_DAC_I2S_BCLK_SCALE;
extern const unsigned char  L1SP_EXT_DAC_STEP; // the minimum step that has change of volume      
extern const unsigned char  L1SP_EXT_DAC_STEP_UNIT; // the times of 0.5dB in the minimum volume change    
extern void EXT_DAC_Init( void ); 
extern void EXT_DAC_SetPlaybackFreq( kal_uint16 frequency ); 
extern void EXT_DAC_TurnOnSpeaker( kal_uint8 src, kal_uint8 spk );
extern void EXT_DAC_TurnOffSpeaker( kal_uint8 spk ); 
extern void EXT_DAC_SetVolume( kal_uint8 spk, kal_uint8 vol );
extern void EXT_DAC_FixedLineInGain( kal_uint8 spk );

/* ------------------------------------------------------------------------------ */
/*  Audio Related Global Variables                                                */
/* ------------------------------------------------------------------------------ */
extern const signed short     Speech_Input_FIR_Coeff[6][45];
extern const signed short     Speech_Output_FIR_Coeff[6][45];
extern const unsigned short   Media_Playback_Maximum_Swing;
extern const signed short     Melody_FIR[25];

extern const unsigned short   DG_DL_Speech;
extern const unsigned short   DG_Microphone;
extern const unsigned short   DG_DAF;
extern const unsigned short   DG_MIDI;
extern const unsigned short   DG_IMY;

/* ------------------------------------------------------------------------------ */
/*  Key Tone Interface                                                            */
/* ------------------------------------------------------------------------------ */
void  KT_SetOutputDevice( kal_uint8 device );
void  KT_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void  KT_Play( kal_uint16 freq1, kal_uint16 freq2, kal_uint16 duration );
void  KT_Stop( void );
void  KT_StopAndWait(void);
void  KT_SetAmplitude( kal_int16 amp );
void  KT_SetFIR( kal_bool enable );


/* ------------------------------------------------------------------------------ */
/*  Tone Interface                                                                */
/* ------------------------------------------------------------------------------ */
typedef struct {
   kal_uint16   freq1;         /* First frequency                              */
   kal_uint16   freq2;         /* Second frequency                             */
   kal_uint16   on_duration;   /* Tone on duation(ms), 0 for continuous tone   */
   kal_uint16   off_duration;  /* Tone off duation(ms), 0 for end of playing   */
   kal_int8     next_tone;     /* Index of the next tone                       */
} L1SP_Tones;

typedef struct {
   kal_uint16   freq1;         /* First frequency                              */
   kal_uint16   freq2;         /* Second frequency                             */
   kal_uint16   on_duration;   /* Tone on duation(ms), 0 for continuous tone   */
   kal_uint16   off_duration;  /* Tone off duation(ms), 0 for end of playing   */
   kal_int8     next_tone;     /* Index of the next tone                       */
   kal_uint16   freq3;         /* Third frequency                              */
   kal_uint16   freq4;         /* Fourth frequency                             */
} L1SP_QTMF;

/* -------------------------------- */
/*  Example of Tone Definition      */
/* -------------------------------- */
/*
static const L1SP_Tones tone1_gsm[] = { { 425,   0,   0,   0,   0 } };
static const L1SP_Tones tone1_pcs[] = { { 350, 440,   0,   0,   0 } };
static const L1SP_Tones tone2_gsm[] = { { 425,   0, 500, 500,   0 } };
static const L1SP_Tones tone2_pcs[] = { { 480, 620, 500, 500,   0 } };
static const L1SP_Tones tone3_gsm[] = { { 425,   0, 200, 200,   0 } };
static const L1SP_Tones tone3_pcs[] = { { 480, 620, 200, 200,   0 } };
static const L1SP_Tones tone4[]     = { { 425,   0, 200,   0,   0 } };
static const L1SP_Tones tone5[]     = { { 425,   0, 200, 200,   1 },
                                        { 425,   0, 200, 200,   2 },
                                        { 425,   0, 200,   0,   0 } };
static const L1SP_Tones tone61[]    = { { 950,   0, 330,1000,   0 } };
static const L1SP_Tones tone62[]    = { {1400,   0, 330,1000,   0 } };
static const L1SP_Tones tone63[]    = { {1800,   0, 330,1000,   0 } };
static const L1SP_Tones tone7[]     = { { 425,   0, 200, 600,   1 },
                                        { 425,   0, 200,3000,   2 },
                                        { 425,   0, 200, 600,   3 },
                                        { 425,   0, 200,   0,   0 } };
*/

void  TONE_SetOutputDevice( kal_uint8 device );
void  TONE_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void  TONE_Play( const L1SP_Tones *tonelist );
void  TONE_Stop( void );
void  TONE_StopAndWait( void );
void  TONE_SetAmplitude( kal_int16 amp );
void  TONE_SetFIR( kal_bool enable );
void  TONE_SetHandler( void (*handler)(void) );
void  TONE_PlayQTMF( const L1SP_QTMF *tonelist ); /* QTMF Play Interface */


/* ------------------------------------------------------------------------------ */
/*  Speech Interface                                                              */
/* ------------------------------------------------------------------------------ */
void        L1SP_SetOutputDevice( kal_uint8 device );
void        L1SP_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void        L1SP_SetSpeechVolumeLevel( kal_uint8 level );
void        L1SP_Speech_On( kal_uint8 RAT_Mode );
void        L1SP_Speech_Off( void );
void        L1SP_SetInputSource( kal_uint8 src );
kal_uint8   L1SP_GetInputSource( void );
void        L1SP_SetMicrophoneVolume( kal_uint8 mic_volume );
kal_uint8   L1SP_GetMicrophoneVolume( void );
void        L1SP_SetSidetoneVolume( kal_uint8 sidetone );
kal_uint8   L1SP_GetSidetoneVolume( void );
void        L1SP_MuteMicrophone( kal_bool mute );
kal_bool    L1SP_IsMicrophoneMuted( void );
void        L1SP_SetFIR( kal_bool enable );
void        L1SP_Set_DAI_Mode( kal_uint8 mode );
void        L1SP_Write_Audio_Coefficients( const kal_int16 in_coeff[30], const kal_int16 out_coeff[30] );
void        L1SP_SetAfeLoopback( kal_bool enable );
kal_bool    L1SP_IsBluetoothOn( void );
void        L1SP_EnableSpeechEnhancement( kal_bool enable );

/*******************************************************************/
/*   The new interface for DSP speech enhancement function / Bluetooth */
/*******************************************************************/
#define SPH_MODE_NORMAL  0
#define SPH_MODE_EARPHONE  1
#define SPH_MODE_LOUDSPK  2
#define SPH_MODE_BT_EARPHONE 3
#define SPH_MODE_BT_CORDLESS 4
#define SPH_MODE_AUX1  5
#define SPH_MODE_AUX2  6
#define SPH_MODE_AUX3  7
#define SPH_MODE_FM_VIA_BT_CORDLESS 8
#define SPH_MODE_UNDEFINED  9

#define NUM_COMMON_PARAS  12
#define NUM_MODE_PARAS  8
void L1SP_LoadCommonSpeechPara( kal_uint16 c_para[NUM_COMMON_PARAS] );
void L1SP_SetSpeechMode( kal_uint8 mode, kal_uint16 m_para[NUM_MODE_PARAS] );
kal_uint8 L1SP_GetSpeechMode( void );

#define SPH_MODE_BT_CARKIT SPH_MODE_AUX1

/* ------------------------------------------------------------------------------ */
/*  AMR encoder buffer management                                                 */
/* ------------------------------------------------------------------------------ */
kal_uint32 AMR515_BufferSize( void );
kal_uint16 AMR515_SetBuffer( void *buf, kal_uint32 buf_size );

/* ------------------------------------------------------------------------------ */
/*  Media File Playback/Recording Interface                                       */
/* ------------------------------------------------------------------------------ */
typedef enum {
   MEDIA_SUCCESS = MED_STAT_AUDIO_START,
   MEDIA_FAIL,
   MEDIA_REENTRY,                /* media reentry error                       */
   MEDIA_NOT_INITIALIZED,        /* media control is not initialized          */
   MEDIA_BAD_FORMAT,             /* media format error                        */
   MEDIA_BAD_PARAMETER,          /* media bad parameter error                 */
   MEDIA_BAD_COMMAND,            /* media bad command error                   */
   MEDIA_NO_HANDLER,             /* media no handler error                    */
   MEDIA_UNSUPPORTED_CHANNEL,    /* unsupported audio channel count           */
   MEDIA_UNSUPPORTED_FREQ,       /* unsupported audio freqency                */
   MEDIA_UNSUPPORTED_TYPE,       /* unsupported audio content                 */
   MEDIA_UNSUPPORTED_OPERATION,   /* unsupported operation on such audio type  */
   MEDIA_SEEK_FAIL,              /* seek fail indicator */
   MEDIA_SEEK_EOF,               /* seek end of file indicator */
   MEDIA_READ_FAIL,              /* read fail indicator */
   MEDIA_WRITE_FAIL,             /* write fail indicator */
   MEDIA_DISK_FULL,              /* disk full indicator */
   MEDIA_MERGE_TYPE_MISMATCH
} Media_Status;

typedef enum {
   MEDIA_NONE,
   MEDIA_DATA_REQUEST,
   MEDIA_DATA_NOTIFICATION,
   MEDIA_END,
   MEDIA_ERROR,
   MEDIA_DECODER_UNSUPPORT,
   MEDIA_REPEATED,
   MEDIA_TERMINATED,
   MEDIA_LED_ON,
   MEDIA_LED_OFF,
   MEDIA_VIBRATOR_ON,
   MEDIA_VIBRATOR_OFF,
   MEDIA_BACKLIGHT_ON,
   MEDIA_BACKLIGHT_OFF,
   MEDIA_EXTENDED_EVENT,
   MEDIA_READ_ERROR,
   MEDIA_UPDATE_DUR,
   MEDIA_STOP_TIME_UP
} Media_Event;

// Note : New defined media format should always be added at the last one,    
// otherwise it may induce unsync media format problem between MMI/MED and L1Audio.
typedef enum {
   MEDIA_FORMAT_GSM_FR,
   MEDIA_FORMAT_GSM_HR,
   MEDIA_FORMAT_GSM_EFR,
   MEDIA_FORMAT_AMR,
   MEDIA_FORMAT_AMR_WB,
   MEDIA_FORMAT_DAF,
   MEDIA_FORMAT_AAC,
   MEDIA_FORMAT_PCM_8K,
   MEDIA_FORMAT_PCM_16K,
   MEDIA_FORMAT_G711_ALAW,
   MEDIA_FORMAT_G711_ULAW,
   MEDIA_FORMAT_DVI_ADPCM,
   MEDIA_FORMAT_VRD,
   MEDIA_FORMAT_WAV,
   MEDIA_FORMAT_WAV_ALAW,
   MEDIA_FORMAT_WAV_ULAW,
   MEDIA_FORMAT_WAV_DVI_ADPCM,
   MEDIA_FORMAT_SMF,
   MEDIA_FORMAT_IMELODY,
   MEDIA_FORMAT_SMF_SND,
   MEDIA_FORMAT_MMF,
   MEDIA_FORMAT_AU,
   MEDIA_FORMAT_AIFF,
   MEDIA_FORMAT_VRSI,
   MEDIA_FORMAT_WMA,
   MEDIA_FORMAT_M4A,
   MEDIA_FORMAT_WAV_DVI_ADPCM_16K,
   MEDIA_FORMAT_VOIPEVL,
   MEDIA_FORMAT_AAC_PLUS,
   MEDIA_FORMAT_AAC_PLUS_V2,
   MEDIA_FORMAT_BSAC,
   MEDIA_FORMAT_MUSICAM = 32,
   MEDIA_FORMAT_AWB_PLUS,
   MEDIA_FORMAT_AWB_PLUS_EXTEND
} Media_Format;

typedef enum {
   MEDIA_AUD_COMP_LOUDSPEAKER,
   MEDIA_AUD_COMP_EARPHONE
} Media_Aud_Comp_Mode;

typedef struct {
   const kal_uint8   *smffile;
   kal_int32         filesize;            /* MIDI file size             */
   kal_int16         repeats;             /* 0 -> endless               */
} Media_SMF_Param;

typedef struct {
   const kal_uint8   *imyfile;
   kal_int32         filesize;            /* MIDI file size             */
   kal_int16         repeats;             /* 0 -> endless               */
   kal_int16         default_instrument;  /* default instrument(1~128)  */
} Media_iMelody_Param;

typedef struct {
   const kal_uint8 *wavefile;
   kal_int32       filesize;            /* Wave file size             */
   kal_int16       repeats;             /* 0 -> endless               */
   kal_int16       format;              /* add for direct wave        */
   kal_uint16      sampling_rate;       /* add for direct wave        */
} Media_Wav_Param;

typedef struct {
   const kal_uint8 *toneSeq;
   kal_int32     toneSeqLen;          /* tone sequence data length  */
   kal_int16     repeats;             /* 0 -> endless               */
} Media_ToneSeq_Param;

typedef struct{
   const kal_uint8 *mmffile;
   kal_int32 filesize;
   kal_int16 repeats;
} Media_MMF_Param;

typedef struct{
   const kal_uint8 *amrfile;
   kal_int32 filesize;
   kal_int16 repeats;
} Media_AMR_Param;

typedef struct {
   Media_Format   mediaType;
   kal_uint32     vmParam;
} Media_VM_PCM_Param;

typedef struct {
   kal_bool       isStereo;
   kal_int8       bitPerSample;
   kal_uint16     sampleFreq;
} Media_PCM_Stream_Param;

typedef enum {
   MEDIA_CTRL_MAX_SWING,
   MEDIA_CTRL_KEY_SHIFT
} Media_Ctrl;

// Audio Streaming Sender
typedef struct sender_stream_handle SSHdl;
struct sender_stream_handle {
   void (*PutData)( SSHdl *hdl, kal_uint8 *, kal_uint32 );
   void (*Flush)( SSHdl *hdl );

   kal_uint8 *rb_base;
   kal_int32 rb_size;
   kal_int32 rb_read;
   kal_int32 rb_write;
   kal_int32 rb_threshold;
   void (*callback)( void * );
   kal_bool wait;
   kal_int32 rb_read_total;
} ;
kal_bool is_SSHdl_valid(SSHdl *hdl);

typedef  struct mhdl MHdl;
typedef  struct media_handle Media_Handle;

struct mhdl {
   kal_uint8      state;
   kal_uint8      volume_level;
   kal_uint32     start_time;
   kal_uint32     current_time;
   kal_uint32     stop_time;
   kal_uint32     data;
   void           (*handler)( MHdl *handle, Media_Event event );
   void           *param;

   Media_Format   mediaType;
   kal_uint16     aud_id;
   // DSP ring buffer control variables
   kal_uint16         dsp_rb_base;
   kal_uint16         dsp_rb_size;
   kal_uint16         dsp_rb_end;
   // Media ring buffer control variables
   kal_uint8          *rb_base;         // Pointer to the ring buffer
   kal_int32          rb_size;          // Size of the ring buffer
   kal_int32          write;
   kal_int32          read;
   kal_bool           eof;
   kal_bool           waiting;
   kal_bool           mono2stereo;
   kal_bool           fStoreFileOffset;
   Media_Status       eSeekLastRet;
   kal_uint32         uSeekProgress;
   kal_uint32         uCurSeekFrm;
   Media_Status       eGetDurLastRet;
   kal_uint32         uGetDurProgress;
   kal_uint32         uCurGetDurFrm;
   kal_uint32         uStoreStartTime;
   kal_uint32         uTotalDuration;
   SSHdl              *ss_handle;

   void           (*SetBuffer)( MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len );
   void           (*GetWriteBuffer)( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len );
   void           (*GetReadBuffer)( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len );
   void           (*WriteDataDone)( MHdl *hdl, kal_uint32 len );
   void           (*FinishWriteData) (MHdl *hdl);
   void           (*ResetMediaBuf) (MHdl *hdl);
   void           (*ReadDataDone)( MHdl *hdl, kal_uint32 len );
   void           (*DataFinished)( MHdl *hdl );
   void           (*SetStoreFlag)( MHdl *hdl, kal_bool fStoreLastFileOffset );
   void           (*StoreFileOffset)(MHdl *hdl);
   void           (*SetFileOffset)(MHdl *hdl, kal_uint32 uCurOffset);
   kal_uint32     (*GetFileOffset)(MHdl *hdl);
   kal_int32      (*GetFreeSpace)( MHdl *hdl );
   kal_int32      (*GetDataCount)( MHdl *hdl );
   Media_Status   (*SetLevel)( MHdl *hdl, kal_uint8 level );
   kal_uint8      (*GetLevel)( MHdl *hdl );
   Media_Status   (*SetStartTime)( MHdl *hdl, kal_uint32 msStartTime );
   Media_Status   (*SetStopTime)( MHdl *hdl, kal_uint32 msStopTime );
   kal_uint32     (*GetCurrentTime)( MHdl *hdl );
   kal_uint32     (*GetTotalDuration)( MHdl *hdl );
   void           (*BuildCache) ( MHdl *hdl, Media_Status *eGetDurLastRet, kal_uint32 *uProgress );
   void           (*SetCacheTbl)( MHdl *hdl, kal_uint8 *ptr, void *param );
   kal_uint32     (*GetCacheDuration)(MHdl *hdl);

   Media_Status   (*Play)( MHdl *hdl );
   Media_Status   (*Record)( MHdl *hdl );
   Media_Status   (*Stop)( MHdl *hdl );
   Media_Status   (*Pause)( MHdl *hdl );
   Media_Status   (*Resume)( MHdl *hdl );
   Media_Event    (*Process)( MHdl *hdl, Media_Event event );
   Media_Status   (*Close)( MHdl *hdl );

};

#define  MEDIA_VMP_AS_SPEECH     ((void*)0)
#define  MEDIA_VMP_AS_RINGTONE   ((void*)1)
#define  MEDIA_VMP_AMR           ((void*)0)
#define  MEDIA_VMP_AMR_WB        ((void*)2)

#define MAX_DESCRIPTION     80
typedef struct tWMADescription
{
   kal_uint32 time; // duration in milli-second
   kal_uint32 bitRate;
   kal_uint32 sampleRate;
   kal_bool stereo;
   kal_wchar title[MAX_DESCRIPTION+1];
   kal_wchar artist[MAX_DESCRIPTION+1];
   kal_wchar album[MAX_DESCRIPTION+1];
   kal_wchar author[MAX_DESCRIPTION+1];
   kal_wchar copyright[MAX_DESCRIPTION+1];
   kal_wchar date[MAX_DESCRIPTION+1];
   union
   {
      struct
      {
         kal_uint8 CRC;
         kal_uint8 channel_mode;
         kal_uint8 bit_rate_index;
      } DAF;
   } details;
} audInfoStruct;

typedef enum
{
 MEDIA_FORMAT_CHECK_SUCCESS = 0,
 MEDIA_FORMAT_CHECK_FAIL,
 MEDIA_FORMAT_CHECK_BAD_FILE,
 MEDIA_FORMAT_CHECK_INTERNAL_ERROR
}Media_Format_Check_Result;

typedef enum
{
 MEDIA_Check_FORMAT_3GPP,
 MEDIA_Check_FORMAT_MP3,
 MEDIA_Check_FORMAT_IMY,
 MEDIA_Check_FORMAT_MIDI,
 MEDIA_Check_FORMAT_SPMIDI, 
 MEDIA_Check_FORMAT_M4A,
 MEDIA_Check_FORMAT_MP4,
 MEDIA_Check_FORMAT_ASF,
 MEDIA_Check_FORMAT_DCF,
 MEDIA_Check_FORMAT_WAVE,
 MEDIA_Check_FORMAT_AAC,
 MEDIA_Check_FORMAT_AMR,
 MEDIA_Check_FORMAT_AWB, 
 MEDIA_Check_FORMAT_WMA,
 MEDIA_Check_FORMAT_WMV, 
 MEDIA_Check_FORMAT_UNKNOWN
}Media_Check_Format;

typedef enum
{
 /*audio codec*/
 MEDIA_AUDIO_CODEC_AAC,
 MEDIA_AUDIO_CODEC_AAC_PLUS,
 MEDIA_AUDIO_CODEC_EAAC_PLUS,
 MEDIA_AUDIO_CODEC_AMR,
 MEDIA_AUDIO_CODEC_AWB,
 MEDIA_AUDIO_CODEC_WMA,
 MEDIA_AUDIO_CODEC_MP3,
 MEDIA_AUDIO_CODEC_UNKNOWN
}Media_Check_Audio_Codec;

typedef enum
{
 /*video codec*/
 MEDIA_VIDEO_CODEC_H263,
 MEDIA_VIDEO_CODEC_H264,
 MEDIA_VIDEO_CODEC_MPEG4,
 MEDIA_VIDEO_CODEC_WMV,
 /**/
 MEDIA_VIDEO_CODEC_UNKNOWN
}Media_Check_Video_Codec;

void  Media_SetOutputDevice( kal_uint8 device );
void  Media_SetOutputVolume( kal_uint8 volume1, kal_int8 Media_SetOutputVolume );
void  Media_SetOutputVolume_ST( kal_uint8 volume );
void  Media_SetLevelVolume( kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level );
void  Media_SetBuffer( kal_uint16 *buffer, kal_uint32 buf_len );
void  Media_GetWriteBuffer( kal_uint16 **buffer, kal_uint32 *buf_len );
void  Media_WriteDataDone( kal_uint32 len );
void  Media_DataFinished( void );
void  Media_GetReadBuffer( kal_uint16 **buffer, kal_uint32 *buf_len );
void  Media_ReadDataDone( kal_uint32 len );
void  Media_GetFileHeader( kal_uint8 **header, kal_uint32 *len );
void  Media_SetRBThreshold( kal_uint16 threshold );   /* Ring buffer threshold in words */

Media_Status  Media_Play( Media_Format format, void (*media_handler)( Media_Event event ), void *param );
kal_uint32    Media_GetRecordedTime( void );
Media_Status  Media_Record( Media_Format format, void (*media_handler)( Media_Event event ), void *param );
void          Media_Stop( void );
Media_Status  Media_Pause( void );
Media_Status  Media_Resume( void );
Media_Status  Media_Control( Media_Ctrl ctrl_no, kal_int32 ctrl_val );
Media_Status  Media_SetLevel( kal_uint8 level );
kal_uint8     Media_GetLevel( void );
kal_bool      Media_IsCSDMode(void);

void  Media_SetMelodyFilter( kal_uint16 len, const kal_int16 *filter );
/* ------------------------------------------------------------------------------ */

Media_Handle   *JSmf_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_SMF_Param **param );
Media_Status   JSmf_Close( Media_Handle *handle );
Media_Status   JSmf_Play( Media_Handle *handle );
Media_Status   JSmf_Stop( Media_Handle *handle );
Media_Status   JSmf_Pause( Media_Handle *handle );
Media_Status   JSmf_Resume( Media_Handle *handle );
Media_Status   JSmf_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JSmf_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JSmf_GetCurrentTime( Media_Handle *handle );
kal_int32      JSmf_GetDuration( Media_Handle *handle );
kal_int32      JSmf_GetMidiDuration( const kal_uint8 *mid );
Media_Event    JSmf_QueryExtEvent( Media_Handle *handle, kal_int32 *note );
kal_bool       JSmf_isSpMidi( Media_Handle *handle );

kal_bool       JMidi_isBankQuerySupported( void );
void           JMidi_GetBankList( kal_bool custom, const kal_int16 **buf, kal_int16 *len);
void           JMidi_GetProgramList( kal_int16 bank, const kal_int8 **buf, kal_int16 *len);
const kal_uint8*JMidi_GetProgramName( kal_int16 bank, kal_int8 prog );
const kal_uint8*JMidi_GetKeyName( kal_int16 bank, kal_int8 prog, kal_int8 key );

Media_Handle   *JMidi_OpenDevice( void );
Media_Status   JMidi_CloseDevice( Media_Handle *handle );
Media_Status   JMidi_SendLongMsg( Media_Handle *handle, const kal_uint8 *buf, kal_uint16 len );
Media_Status   JMidi_SendShortMsg( Media_Handle *handle, kal_uint8 type, kal_uint8 data1, kal_uint8 data2 );
Media_Status   JMidi_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JMidi_GetLevel( Media_Handle *handle );
Media_Status   JMidi_SetTempo( Media_Handle *handle, kal_int32 milliTempo );
kal_int32      JMidi_GetTempo( Media_Handle *handle );
Media_Status   JMidi_SetRate( Media_Handle *handle, kal_int32 milliRate );
kal_int32      JMidi_GetRate( Media_Handle *handle );
Media_Status   JMidi_SetTSRate( Media_Handle *handle, kal_int32 Rate );   // For Time Stretch
Media_Status   JMidi_SetPitchTranspose( Media_Handle *handle, kal_int32 milliSt );
kal_int32      JMidi_GetPitchTranspose( Media_Handle *handle );
Media_Status   JMidi_SetChannelVolume( Media_Handle *handle, kal_int8 channel, kal_uint8 level );
kal_int8       JMidi_GetChannelVolume( Media_Handle *handle, kal_int8 channel );
Media_Status   JMidi_SetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 bank, kal_int8 program );
void           JMidi_GetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 *bank, kal_int8 *program );


Media_Handle   *JTone_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_ToneSeq_Param **param );
Media_Status   JTone_Close( Media_Handle *handle );
Media_Status   JTone_Play( Media_Handle *handle );
Media_Status   JTone_Stop( Media_Handle *handle );
Media_Status   JTone_Pause( Media_Handle *handle );
Media_Status   JTone_Resume( Media_Handle *handle );
Media_Status   JTone_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JTone_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JTone_GetCurrentTime( Media_Handle *handle );
kal_int32      JTone_GetDuration( Media_Handle *handle );
Media_Status   JTone_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JTone_GetLevel( Media_Handle *handle );
Media_Status   JTone_SetPitchShift(Media_Handle *handle, kal_int8 pitch_shift);
kal_int8       JTone_GetPitchShift(Media_Handle *handle);
Media_Status   JTone_SetSpeed(Media_Handle *handle, kal_uint32 speed_factor);
Media_Status   JTone_SetProgram(Media_Handle *handle, kal_uint8 program);
Media_Status   JTone_SetPlayStyle(Media_Handle *handle, kal_uint8 play_style);

Media_Handle   *JImy_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_iMelody_Param **param );
Media_Status   JImy_Close( Media_Handle *handle );
Media_Status   JImy_Play( Media_Handle *handle );
Media_Status   JImy_Stop( Media_Handle *handle );
Media_Status   JImy_Pause( Media_Handle *handle );
Media_Status   JImy_Resume( Media_Handle *handle );
Media_Status   JImy_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JImy_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JImy_GetCurrentTime( Media_Handle *handle );
kal_int32      JImy_GetDuration( Media_Handle *handle );
Media_Status   JImy_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JImy_GetLevel( Media_Handle *handle );
Media_Status   JImy_SetTSRate( Media_Handle *handle, kal_int32 rate);  // For Time Stretch

Media_Handle   *JWav_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_Wav_Param **param );
Media_Status   JWav_Close( Media_Handle *handle );
Media_Status   JWav_Load(Media_Handle *handle, kal_uint32 *requiredBufSize);
void           JWav_SetBuffer(Media_Handle *handle, kal_int16 *buffer, kal_uint32 buf_len);
Media_Status   JWav_Play( Media_Handle *handle );
Media_Status   JWav_Stop( Media_Handle *handle );
Media_Status   JWav_Pause( Media_Handle *handle );
Media_Status   JWav_Resume( Media_Handle *handle );
Media_Status   JWav_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JWav_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JWav_GetCurrentTime( Media_Handle *handle );
kal_int32      JWav_GetDuration( Media_Handle *handle );
Media_Status   JWav_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JWav_GetLevel( Media_Handle *handle );

Media_Handle   *JXWav_Open( void (*handler)( Media_Handle *handle, Media_Event event ));
Media_Status   JXWav_Close( Media_Handle *handle );
Media_Status   JXWav_Load(Media_Handle *handle, kal_uint32 *requiredBufSize);
void           JXWav_SetBuffer(Media_Handle *handle, kal_int16 *buffer, kal_uint32 buf_len);
Media_Status   JXWav_Play( Media_Handle *handle );
Media_Status   JXWav_Stop( Media_Handle *handle );
Media_Status   JXWav_Pause( Media_Handle *handle );
Media_Status   JXWav_Resume( Media_Handle *handle );
kal_int32      JXWav_GetCurrentTime( Media_Handle *handle );
Media_Status   JXWav_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JXWav_GetLevel( Media_Handle *handle );

Media_Handle   *JAmr_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_AMR_Param **param );
Media_Status   JAmr_Close( Media_Handle *handle );
Media_Status   JAmr_Play( Media_Handle *handle );
Media_Status   JAmr_Stop( Media_Handle *handle );
Media_Status   JAmr_Pause( Media_Handle *handle );
Media_Status   JAmr_Resume( Media_Handle *handle );
Media_Status   JAmr_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JAmr_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JAmr_GetCurrentTime( Media_Handle *handle );
Media_Status   JAmr_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JAmr_GetLevel( Media_Handle *handle );
Media_Status   JAmr_GetDuration( const kal_uint8 *amrfile, kal_int32 amrsize, kal_int32 *duration );

/* ------------------------------------------------------------------------------ */

// For Audio Equalizer
extern void AudioPP_Equalizer_SetMag( kal_int8 magnitude[8] );
void AudioPP_Equalizer_TurnOn( void );
void AudioPP_Equalizer_TurnOff( void );
kal_bool AudioPP_Equalizer_IsEnable( void );
void AEQ_Activate( kal_int16 asp_fs, kal_bool rampup );  /* l1audio internal use */

// For Audio Compensation Filter
void Media_SetAudioCompensation(Media_Aud_Comp_Mode mode, kal_int16 *coeff);
void Audio_Compensation_Activate( kal_bool check );      /* l1audio internal use */

// For Hardware FIR
void Audio_HW_FIR_Reset( void );                         /* l1audio internal use */

/* ---- AudioPP Manager Structure --- */
#define APM_PROPERTY_READ_WRITE 0
#define APM_PROPERTY_READ_ONLY  1

typedef enum {
   APM_TASKID_REVERB,
   APM_TASKID_SURROUND,
   APM_TASKID_AGC,
   APM_TASKID_SBC,
   APM_TASKID_AVB,
   APM_TASKID_SPT,
   APM_TASKID_TS,
   APM_TASKID_EQ
} APM_TaskID;

typedef struct APM_InfoStruct {
   kal_bool   isEOF;
   kal_bool   isChange;
   kal_bool   isStereo;
   kal_uint32 sampleFreq;
} APM_Info;

typedef struct APM_BufStruct {
   kal_int16   *inBuf;           // Input buffer
   kal_uint32  inBufLen;         //    size in Word
   kal_int16   *outBuf;          // Output buffer
   kal_uint32  outBufLen;        //    in Word
} APM_Buffer;

typedef struct APM_TCM_STRUCT {
   kal_uint32 *tcmBuf;          // TCM buffer
   kal_uint32 tcmBufLen;        //    in World
} APM_TCM;

typedef struct APM_TaskParaStruct {
   APM_TaskID apm_Id;
   kal_uint16 property;
   kal_uint16 level;
   kal_uint32 tcmSize;
   void (*Init)(APM_TCM *tcm);
   void (*Activate)(APM_Info *info);
   void (*Deactivate)(void);
   kal_bool (*Process)(APM_Buffer *buf, APM_Info *info);
} APM_TASK_PARA;


/* ---- Audio Post-Processing Interface ---- */
void HOST_APM_Register(APM_TaskID taskID);
void HOST_APM_UnRegister(APM_TaskID taskID);
void APM_Init( void );                                                 /* l1audio internal use */
void APM_ClearBuffer(void);                                            /* l1audio internal use */
void APM_Activate( kal_int16 asp_type, kal_int16 freqInd);             /* l1audio internal use */
void APM_Deactivate(void);                                             /* l1audio internal use */
void APM_SetEOF(void);                                                 /* l1audio internal use, in each audio driver */
kal_bool APM_IsEOF(void);                                              /* l1audio internal use, in each audio driver */
void APM_NOTIFY_MEDIA_END(void (*HookFunc)(void *data, Media_Event event), void *data, kal_bool isNew, Media_Event event);   /* l1audio internal use */
void APM_EXECUTE_END_HANDLER(void);                                    /* l1audio internal use */
kal_int32 APM_AV_DelayCount(void);                                     /* For AV sync, return samples/6        */
void APM_AV_ConsumeDelay(kal_int32 numInt);                            /* For AV sync, consume interrupt count */
kal_uint8 *APM_Allocate_Buffer(kal_uint32 bufSize);                    /* l1audio internal use */
void APM_Release_Buffer(void);                                         /* l1audio internal use */
void APM_NotifyDropFrame(kal_bool isDrop);                             /* l1audio internal use */


/* ------------------------------------------------------------------------------ */
//-- For Time Stretch
Media_Status AudioPP_TS_SetSpeed(kal_uint16 speed_mode);
void AudioPP_TS_Close(void);
kal_uint16 AudioPP_TS_GetSpeed(void);
kal_bool AudioPP_TS_IsEnable(void);
kal_bool AudioPP_TS_IsSupport(Media_Format eFormat, STFSAL *pstFSAL);

//-- For Reverb
extern void AudioPP_Reverb_SetCoeff(short *ReverbCoeff);
extern Media_Status AudioPP_Reverb_TurnOn(void);
extern void AudioPP_Reverb_TurnOff(void);
extern void AudioPP_Reverb_Enable(void);             /* l1audio internal use */
extern void AudioPP_Reverb_Disable(kal_bool wait);   /* l1audio internal use */

/* Internal Use */
void AudioPP_TS_Init(void);                          /* l1audio internal use */
void AudioPP_TS_Activate(kal_bool voice_init);       /* l1audio internal use */
void AudioPP_Close(void);                            /* l1audio internal use */
void AudioPP_Disable(void);                          /* l1audio internal use */
void AudioPP_Enable(void);                           /* l1audio internal use */
void AudioPP_SetMediaFormat(Media_Format eFormat);   /* l1audio internal use for Midi */
kal_int32 AudioPP_GetTSRate( void );                 /* l1audio internal use for Midi */

//-- For 3D Surround
extern void AudioPP_Surround_Enable( void );
extern void AudioPP_Surround_Disable( void );
extern void AudioPP_Surround_ModeSelect(kal_int32 mode);

/* ------------------------------------------------------------------------------ */
void SPT_Open( void );
void SPT_Close( void );
void SPT_GetSpectrum( kal_uint8 top[16], kal_uint8 val[16] );
void SPT_PutPcmData( const kal_int16 *pcm, kal_int32 len, kal_bool mono );    /* L1audio internal use */

/* FM Radio Interface */
void  FMR_PowerOn(void);
void  FMR_PowerOff(void);
kal_uint8 FMR_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up);
void  FMR_SetFreq(kal_int16 curf);
void FMR_AutoSearch(kal_uint8 dir, void(*fm_handler)(kal_int16 *data));
kal_int16 FMR_ManualSearch(kal_uint8 dir);
kal_int16 FMR_GetFreq(void);
void  FMR_Mute(kal_uint8 mute);
void  FMR_Mono(kal_uint8 MS);
void  FMR_Standby(kal_uint8 standby);
void FMR_SetOutputDevice( kal_uint8 device );
void  FMR_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );

#if defined(FM_RADIO_WITH_TV)
kal_uint16 FMR_GetSignalLevel( kal_uint16 curf );
#else
kal_uint8 FMR_GetSignalLevel( kal_uint16 curf );//UNI@bw_0719_BEIW1
#endif

void FMR_EvaluateRSSIThreshold(void);
void FMR_Radio_EngineerMode(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value);
kal_uint16 FMR_GetIFCount(kal_int16 curf);
kal_uint16 FMR_ReadByte(kal_uint8 addr);
void FMR_WriteByte(kal_uint8 addr, kal_uint16 data);
void FMR_SoftMuteOnOff(kal_uint8 On_Off);
void FMR_SoftMuteStage(kal_uint8 stage);
void FMR_StereoBlendStage(kal_uint8 stage);
kal_uint8 FMR_GetChipID(void);
kal_uint8 FMR_Get_H_L_side(kal_int16 curf);
kal_uint8 FMR_Get_stereo_mono(void);
kal_uint8 FMR_CheckOption(void);

/* ------------------------------------------------------------------------------ */

/* A/V Sync Interface */

kal_uint32 Media_A2V_GetInterruptCount(void);
void Media_A2V_EnableInterrupt(kal_bool bFlag, kal_uint32 start_count);
void Media_A2V_HookInterrupt(void (*a2v_lisr)(void));
void Media_A2V_SetTimeStamp(kal_uint16 wTimeStamp);
void Media_A2V_SetInterruptCount(kal_uint32 uInterruptCount);
kal_uint16 Media_A2V_GetAudioFrameCount(void);
kal_uint16 Media_A2V_GetVideoFrameCount(void);
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex);
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex);
kal_uint32 Media_A2V_GetRecInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex);
kal_uint32 Media_A2V_GetRecInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex);
kal_uint32 Media_A2V_GetAudioPlaybackDelay(Media_Format eFormat);
kal_uint32 Media_A2V_GetAudioRecordDelay(Media_Format eFormat);


/* ------------------------------------------------------------------------------ */
typedef enum {
   POC_AMR_NONE   = 0x00,
   POC_AMR_0475   = 0x01,
   POC_AMR_0515   = 0x02,
   POC_AMR_0590   = 0x04,
   POC_AMR_0670   = 0x08,
   POC_AMR_0740   = 0x10,
   POC_AMR_0795   = 0x20,
   POC_AMR_1020   = 0x40,
   POC_AMR_1220   = 0x80,
   POC_AMR_ALL    = 0xFF
} PoC_AMR_Type;

void PoC_AMR_SetBuffer(kal_uint16 *buf, kal_uint32 len);
PoC_AMR_Type PoC_AMR_GetVocoderCapability(void);
Media_Status PoC_AMR_EncodeStart( PoC_AMR_Type vocoder, void (*media_handler)(void), kal_int32 frame_threshold );
Media_Status PoC_AMR_EncodeStop( void );
Media_Status PoC_AMR_DecodeStart( void );
Media_Status PoC_AMR_DecodeStop( void );
kal_int32 PoC_AMR_GetFrameCount( void );
kal_int32 PoC_AMR_GetPayload( kal_uint8 *buf, kal_int32 len, kal_int32 frames );
Media_Status PoC_AMR_PutPayload( const kal_uint8 *buf, kal_int32 len );

/* ------------------------------------------------------------------------------ */
/* VR SD Interface */
typedef enum
{
   VR_FINISHED,
   VR_OK,
   VR_FAILED,
   VR_CONTINUE,
   VR_NO_SOUND,
   VR_TOO_SIM,
   VR_TOO_DIFF,
   VR_SDMODEL_NOT_READY,
   VR_MISMATCH_ID,
   VR_EXISTENT_ID,
   VR_FLASH_DISK_FULL,
   VR_FLASH_ERROR,
   VR_STOP,
   VR_TOO_LONG,
   VR_TOO_SHORT
} VR_Result;

VR_Result VR_GetParameters(kal_int16 *SimThrld, kal_int16 *DiffThrld, kal_int16 *RejThrld);
VR_Result VR_SetParemeters (kal_int16 SimThrld, kal_int16 DiffThrld, kal_int16 RejThrld);
kal_uint32 VR_GetBufferSize(void);
void VR_SetBuffer(kal_uint8 *RTmemory);
VR_Result  VR_SetDatabaseDir(kal_uint8 *Dir);
VR_Result VR_TRA_Start(kal_uint16 wID, kal_uint16 *mdIDList, kal_uint16 *mdIDListLen, void (*vr_handler)(void *parameter ));
VR_Result VR_TRA2Start(void);
VR_Result VR_RCG_Start(kal_uint16 *mdIDList,kal_uint16 *mdIDListLen,void(*vr_handler)(void *parameter));
VR_Result VR_Process(kal_uint16 *RcgID);
void VR_Stop(void);
kal_int32 VR_GetEngineVer(void);
/* ------------------------------------------------------------------------------ */

typedef void* VRSI_Handle;

typedef enum {
   VRSI_OK,
   VRSI_FAIL
}VRSI_Status;

typedef enum {
   VRSI_PROCESS,
   VRSI_PLAY_REQUEST,
   VRSI_RECOG_MPR,
   VRSI_RECOG_OK,
   VRSI_DIGIT_RECOG_MPR,
   VRSI_DIGIT_RECOG_OK,
   VRSI_DIGIT_ADAPT_MPR,
   VRSI_DIGIT_ADAPT_OK,
   VRSI_TRAIN_TAG_1ST_MPR,
   VRSI_TRAIN_TAG_2ND_MPR,
   VRSI_TRAIN_TAG_OK,
   VRSI_ADD_TAGS_OK,
   VRSI_TTS_OK,
   VRSI_PLAY_TAG_OK,
   VRSI_START_CAPTURE_TIMER,
   VRSI_START_PLAYBACK_TIMER,
   VRSI_START_PROCESS_TIMER,
   VRSI_START_QUICK_TIMER,
   VRSI_STOP_TIMER,
   VRSI_ERROR
}VRSI_Event;

typedef enum {
   VRSI_ERR_NO,
   VRSI_ERR_UNINITIALIZED,
   VRSI_ERR_STATE_UNMATCH,
   VRSI_ERR_BUSY,
   VRSI_ERR_INSUFFICIENT_MEM,
   VRSI_ERR_TOO_MANY_TAGS,
   VRSI_ERR_WRONG_DATA_DIR,
   VRSI_ERR_WRONG_DATA_FILE,
   VRSI_ERR_LIBRARY_CORRUPT,
   VRSI_ERR_DB_FULL,
   VRSI_ERR_DB_ERROR,
   VRSI_ERR_NO_MATCH_TAG,
   VRSI_ERR_NO_SOUND,
   VRSI_ERR_LANG_NOT_SUPPORT,
   VRSI_ERR_BAD_GRAMMAR,
   VRSI_ERR_ADD_TAGS_FAIL,
   VRSI_ERR_TRAIN_TAG_FAIL,
   VRSI_ERR_RECOG_FAIL,
   VRSI_ERR_DIGIT_RECOG_FAIL,
   VRSI_ERR_DIGIT_ADAPT_FAIL,
   VRSI_ERR_TTS_TOO_LONG,
   VRSI_ERR_UNKNOWN
}VRSI_ErrMsg;


typedef enum{
   VRSI_LANG_TAIWAN,
   VRSI_LANG_CHINA,
   VRSI_LANG_AMERICAN,
   VRSI_LANG_BRITISH
}VRSI_Language;

// data structure
typedef struct{
   kal_uint16 *pTagName;
   kal_int32 tagLong;
   kal_uint16 tagID;
   kal_uint8 isPeopleName;
}VRSI_Tag_Param;

typedef struct {
   kal_uint16 **ppTagName;
   kal_int32 *pTagLong;
   kal_uint8  *pIsPeopleName;
   kal_uint16 numTag;
}VRSI_AddTags_Param;


typedef struct {
   kal_uint16 *pTagID;
   //kal_int32 *pTagLong;
   kal_uint16 **ppTagName;
   kal_uint16 numTag;
}VRSI_AddTags_Result;

typedef struct {
   kal_uint16 *pTagID;
   kal_int32 *pTagLong;
   kal_uint16 **ppTagName;
   kal_uint16 numTag;
   kal_uint16 resType;
   kal_int16 preCmd;
   kal_int16 postCmd;
}VRSI_Recog_Result;

typedef struct {
   kal_uint16 digitLen;
   kal_uint16 *pDigits;
}VRSI_Digit_Recog_Result;

// API functions
VRSI_Status VRSI_Init( void (*vrsi_handler)( VRSI_Event event ));
kal_uint32 VRSI_GetMemRequest(kal_uint16 maxFixedTag, kal_uint16 maxDynamicTag, kal_uint8 maxSDTag );
VRSI_Status VRSI_SetMem(kal_uint8 *memory, kal_uint32 size, kal_uint16 maxFixedTag, kal_uint16 maxDynamicTag, kal_uint8 maxSDTag ,kal_uint16 *vrsiDir); 
VRSI_Status VRSI_Add_Tags(const kal_uint8 *grammar, VRSI_AddTags_Param *param );
VRSI_Status VRSI_Train_Tag (const kal_uint8 *grammar, VRSI_Tag_Param *param );
VRSI_Status VRSI_Recog(const kal_uint8 *grammar );
VRSI_Status VRSI_Digit_Recog( VRSI_Language  lang, kal_uint16 limit );
VRSI_Status VRSI_Digit_Adapt( VRSI_Language  lang );
VRSI_Status VRSI_Play_Tag( const kal_uint8 *grammar , kal_uint16 tagID ,void* param  );
VRSI_Status VRSI_TTS_Play( VRSI_Language lang, kal_uint16 *pText );
VRSI_Status VRSI_Process( void );
void VRSI_ReadPrompt (  kal_uint8 *promptLen, const kal_uint16 **prompt );
void VRSI_MMI_Confirmed( void );
void VRSI_ReadResult( void **result );
VRSI_ErrMsg VRSI_GetErrMsg( void );
VRSI_Status VRSI_Gram_GetTagNum(const kal_uint8 *grammar , kal_int32 *tagNum );
VRSI_Status VRSI_Gram_ReadTagIDs(const kal_uint8 *grammar, kal_uint16 *pTagID , kal_int32 bufferSize, kal_int32 *readTagNum);
VRSI_Status VRSI_Gram_DeleteAllTags( const kal_uint8 *grammar );
VRSI_Status VRSI_DeleteTags(const kal_uint8 *grammar, kal_int32 tagNum, const kal_uint16 *pTagID, kal_int32 *delTagNum, kal_uint16 *pDelTagID );
VRSI_Status VRSI_TagExist( const kal_uint8 *grammar, kal_uint16 tagID, kal_bool *bExist  );
VRSI_Status VRSI_ReadTags(const kal_uint8 *grammar, kal_int32 tagNum, const kal_uint16 *pTagID, kal_uint16 **ppTagName, kal_int32 *pTagLong );
VRSI_Status VRSI_Stop( void );
VRSI_Status VRSI_Close( void );
VRSI_Status VRSI_QueryTagId(const kal_uint8 *grammar, kal_int32 tagLong, kal_uint16 *tagID );
VRSI_Status VRSI_QueryNextTagId(const kal_uint8 *grammar, kal_uint16 *tagID );
VRSI_Status VRSI_QueryAllTagIds(const kal_uint8 *grammar, kal_int32 tagLong, kal_uint16 buf_size, kal_uint16 *id_buf, kal_uint16 *tagNum, kal_bool *getAll );

// WMA API
//Media_Event WMA_Process( Media_Handle *hdl, Media_Event event );
//Media_Status WMA_SetStartTime( Media_Handle *hdl, kal_int32 msStartTime );
//Media_Status WMA_SetStopTime( Media_Handle *hdl, kal_int32 msStopTime );
//kal_int32 WMA_GetCurrentTime( Media_Handle *hdl );
//kal_int32 WMA_GetDuration( STFSAL *pstFSAL );
//Media_Status WMA_SetLevel( Media_Handle *hdl, kal_uint8 level );
//kal_uint8 WMA_GetLevel( Media_Handle *hdl );
//Media_Handle *WMA_Open(void(*handler)( Media_Handle *handle, Media_Event event ), STFSAL *pstFSAL);
//Media_Status WMA_Close( Media_Handle *hdl );
//void WMA_SetBuffer( Media_Handle *hdl, kal_uint8 *buffer, kal_uint32 buf_len );
//Media_Status WMA_Play( Media_Handle *hdl );
//Media_Status WMA_Stop( Media_Handle *hdl );
//Media_Status WMA_Pause( Media_Handle *hdl );
//Media_Status WMA_Resume( Media_Handle *hdl );
//Media_Status WMA_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo );

// AAC interface
//Media_Event AAC_Process( Media_Handle *hdl, Media_Event event );
//Media_Status AAC_SetStartTime( Media_Handle *hdl, kal_int32 msStartTime );
//Media_Status AAC_SetStopTime( Media_Handle *hdl, kal_int32 msStopTime );
//kal_int32 AAC_GetCurrentTime( Media_Handle *hdl );
//kal_int32 AAC_GetDuration( STFSAL *pstFSAL );
//Media_Status AAC_SetLevel( Media_Handle *hdl, kal_uint8 level );
//kal_uint8 AAC_GetLevel( Media_Handle *hdl );
//Media_Handle *AAC_Open(void(*handler)( Media_Handle *handle, Media_Event event ), STFSAL *pstFSAL);
//Media_Status AAC_Close( Media_Handle *hdl );
//void AAC_SetBuffer( Media_Handle *hdl, kal_uint8 *buffer, kal_uint32 buf_len );
//Media_Status AAC_Play( Media_Handle *hdl );
//Media_Status AAC_Stop( Media_Handle *hdl );
//Media_Status AAC_Pause( Media_Handle *hdl );
//Media_Status AAC_Resume( Media_Handle *hdl );
//Media_Status AAC_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo );
//kal_bool AAC_IsPPSupport( STFSAL *pstFSAL);
/* ------------------------------------------------------------------------------ */
#if defined(BGSND_ENABLE)
/* Sound effect interface */
typedef struct {
   STFSAL           *pstFSAL;
   kal_int16         repeats;             /* 0 -> endless               */
   Media_Format  format;
} Snd_Param;

Media_Status SND_GetFormat(STFSAL *pstFSAL, Media_Format *pFormat);
Media_Handle *SND_Open(void(*handler)(Media_Handle *, Media_Event ), Snd_Param **param);
Media_Status SND_Close(Media_Handle *hdl);
Media_Status SND_Play( Media_Handle *hdl );
void SND_Stop( Media_Handle *hdl );
void SND_ConfigULMixer( Media_Handle *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain );
void SND_ConfigDLMixer( Media_Handle *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain );
void SND_SetOutputDevice( kal_uint8 device );
#endif /* ...BGSND_ENABLE */

/* SBC event */
typedef enum{
   A2DP_DATA_NOTIFY
} A2DP_Event;

typedef void (*A2DP_Callback)(A2DP_Event , void*);

typedef struct{
    kal_uint32 (*GetPayload)(kal_uint8 *, kal_uint32, kal_uint32 *);
    void (*GetPayloadDone)(void);
    void (*QueryPayloadSize)(kal_uint32 *, kal_uint32 *);
    kal_uint32 (*AdjustBitRateFromQos)(kal_uint8); // return adjusted bit rate
    kal_uint32 (*SetBitRate)(kal_uint32); // return adjusted bit rate
    kal_uint8 state;
} A2DP_codec_struct;

#ifndef __BT_A2DP_CODEC_TYPES__
#define __BT_A2DP_CODEC_TYPES__
typedef struct
{
	kal_uint8 min_bit_pool;
	kal_uint8 max_bit_pool;
	kal_uint8 block_len; // b0: 16, b1: 12, b2: 8, b3: 4
	kal_uint8 subband_num; // b0: 8, b1: 4
	kal_uint8 alloc_method; // b0: loudness, b1: SNR
	kal_uint8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 16000
	kal_uint8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
} bt_a2dp_sbc_codec_cap_struct;

typedef struct
{
	kal_uint8 layer; // b0: layerIII, b1: layerII, b0: layerI
	kal_bool CRC;
	kal_uint8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
	kal_bool MPF; // is support MPF-2
	kal_uint8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 24000, b4: 22050, b5: 16000
	kal_bool VBR; // is support VBR
	kal_uint16 bit_rate; // bit-rate index in ISO 11172-3 , b0:0000 ~ b14: 1110
} bt_a2dp_mp3_codec_cap_struct; /* all MPEG-1,2 Audio */

typedef struct
{
	kal_uint8 object_type; // b4: M4-scalable, b5: M4-LTP, b6: M4-LC, b7: M2-LC
	kal_uint16 sample_rate; // b0~b11: 96000,88200,64000,48000,44100,32000,24000,22050,16000,12000,11025,8000
	kal_uint8 channels; // b0: 2, b1: 1
	kal_bool VBR; // is supported VBR
	kal_uint32 bit_rate; // constant/peak bits per second in 23 bit UiMsbf, 0:unknown
} bt_a2dp_aac_codec_cap_struct; /* all MPEG-2,4 AAC */

typedef struct
{
	kal_uint8 version; // 1:ATRAC, 2:ATRAC2, 3:ATRAC3
	kal_uint8 channel_mode; // b0: joint stereo, b1: dual, b2: single
	kal_uint8 sample_rate; // b0: 48000, b1: 44100
	kal_bool VBR; // is supported VBR
	kal_uint32 bit_rate; // bit-rate index in ATRAC, b0: 0x0012 ~ b18: 0x0000
	kal_uint16 max_sul; // sound unit length in 16 bits UiMsbf
} bt_a2dp_atrac_codec_cap_struct; /* all ATRAC family */

typedef union
{
	bt_a2dp_sbc_codec_cap_struct sbc;
	bt_a2dp_mp3_codec_cap_struct mp3;
	bt_a2dp_aac_codec_cap_struct aac;
	bt_a2dp_atrac_codec_cap_struct atrac;
} bt_a2dp_audio_codec_cap_struct;

typedef struct
{
	kal_uint8 codec_type; // SBC, MP3
	bt_a2dp_audio_codec_cap_struct codec_cap;
} bt_a2dp_audio_cap_struct;
#endif /* __BT_A2DP_CODEC_TYPES__ */

#define SBC_MID_QUALITY 1
#define SBC_HIGH_QUALITY 2
#define SBC_BEST_QUALITY 3

void SBC_Init(void);
kal_uint32 SBC_GetMemReq(void);
A2DP_codec_struct *SBC_Open( Media_Format aud_fmt, A2DP_Callback pHandler, bt_a2dp_sbc_codec_cap_struct *sbc_config_data, kal_uint8 *buf, kal_uint32 buf_len);
void SBC_Close(void);
void SBC_InitiateBitPool(kal_uint8 channel_mode, kal_uint8 sample_rate, kal_uint8 *min, kal_uint8 *max );
void SBC_AdjustBitpool( kal_uint8 max_bitpool, kal_uint8 min_bitpool );
kal_uint32 SBC_SetQualityLevel(kal_uint32 level);

kal_uint32 A2DP_DAF_GetMemReq(void);
A2DP_codec_struct *A2DP_DAF_Open( MHdl *mhdl_handle, A2DP_Callback pHandler, bt_a2dp_mp3_codec_cap_struct *daf_config_data, kal_uint8 *buf, kal_uint32 buf_len);
void A2DP_DAF_Close( MHdl *mhdl_handle );

// L1CTM interface 
typedef enum{
   DIRECT_MODE,
   BAUDOT_MODE       
} L1Ctm_Interface; 

typedef enum{
   CTM_MO_SUCCESS,
   CTM_MO_FAIL, 
   CTM_MT_DETECTED, 
   CTM_CHAR_SENT, 
   CTM_CHAR_RECEIVED,
   CTM_TX_BURST_START,
   CTM_TX_BURST_END   
} L1Ctm_Event; 

typedef struct
{
    kal_int16   cprm_tone_demod_down_samp;                  // 1 (0, 1)   
} CTM_Param;

typedef void (*L1Ctm_Callback)(L1Ctm_Event , void*); 
kal_uint32 L1Ctm_GetMemReq(void);
void L1Ctm_Open(L1Ctm_Interface a, L1Ctm_Callback handler, kal_uint8 *buf, kal_uint32 buf_len, CTM_Param *ctm_param);
void L1Ctm_Close(void);
void L1Ctm_StartNegotiation(void);
kal_uint32 L1Ctm_TxPutText(const kal_uint8 *text, kal_uint32 len, kal_uint32 *left_space);
kal_uint32 L1Ctm_RxGetText(kal_uint8 *text, kal_uint32 len, kal_uint32 *left_count);

MHdl *AMR_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *VM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *DAF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *WAV_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *AIFF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *AU_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *AAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *BSAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *M4A_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *PCM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *WMA_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *PCM_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param);
MHdl *PCM_Strm_Rec_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param);
MHdl *AWB_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);

Media_Status AU_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status AIFF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status WAV_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status AMR_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status AAC_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status M4A_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status DAF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status WMA_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status VM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
Media_Status PCM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
Media_Status AWB_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );

Media_Status AAC_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status AMR_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status DAF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status JSmf_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status JImy_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status WMA_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status WAV_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status AIFF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status AU_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status AWB_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );

kal_bool AAC_IsPPSupport( STFSAL *pstFSAL);   /* L1Audio Internal Use */
kal_bool M4A_IsPPSupport( STFSAL *pstFSAL);   /* L1Audio Internal Use */
kal_bool AAC_IsADIF( STFSAL *pstFSAL);
void AAC_Plus_Forbidden(void);

/* VoRTP interface */
typedef kal_uint32 VORTP_STATUS;
#define VORTP_STATUS_SUCCESS                (VORTP_STATUS)0
#define VORTP_STATUS_FAIL                   (VORTP_STATUS)1
#define VORTP_STATUS_NOT_SUPPORTED_CONFIG   (VORTP_STATUS)2

typedef kal_uint32 VORTP_EVENT;
#define VORTP_EVENT_FATAL_ERROR   (VORTP_EVENT)0
#define VORTP_EVENT_UL_READY      (VORTP_EVENT)1
#define VORTP_EVENT_DL_ERROR      (VORTP_EVENT)2
#define VORTP_EVENT_TONE_FINISH   (VORTP_EVENT)3

#define RTP_CAP_UNSPECIFIED    0
typedef enum {
   RTP_CODEC_UNSPECIFIED = RTP_CAP_UNSPECIFIED,
   RTP_CODEC_SUPPORT = 1,
   RTP_CODEC_UNSUPPORT = 2
} rtp_cap_bool;

typedef enum {
   AudRTP_STATUS_SUCCESS,
   AudRTP_STATUS_FAIL,
   AudRTP_STATUS_NOT_OCTET_ALIGN,
   AudRTP_STATUS_NOT_SINGLE_CHANNEL,
   AudRTP_STATUS_UNSUPPORT_CHANNEL_NUM,
   AudRTP_STATUS_SAMPLE_RATE_NOT_SUPPORT,
   AudRTP_STATUS_TYPE_NOT_SUPPORT
} AudRTP_STATUS;

typedef enum {
   AudRTP_EVENT_BUF_OVERFLOW = 0x100,
   AudRTP_EVENT_BUF_UNDERFLOW = 0x200,
   AudRTP_EVENT_PACKET_LOSS = 0x400,
   AudRTP_EVENT_MEDIA_ERROR = 0x800
} AudRTP_EVENT;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   rtp_cap_bool octet_align, mode_change_neighbor, crc, robust_sorting;
   enum {
      AMR_MODE_UNSPECIFIED = RTP_CAP_UNSPECIFIED,
      AMR_MODE_0_0475 = 0x1,
      AMR_MODE_1_0515 = 0x2,
      AMR_MODE_2_0590 = 0x4,
      AMR_MODE_3_0670 = 0x8,
      AMR_MODE_4_0740 = 0x10,
      AMR_MODE_5_0795 = 0x20,
      AMR_MODE_6_1020 = 0x40,
      AMR_MODE_7_1220 = 0x80,
      AMR_MODE_ALL = 0xFF
   } mode_set;
   kal_uint16 mode_change_period;
   kal_uint16 interleaving; // defines the maximum number of frame-blocks allowed in an interleaving group
   kal_uint16 channels; // indicates max. number of channels
} rtp_audio_amr_cap_struct;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   rtp_cap_bool annexb;
} rtp_audio_g729_cap_struct;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   enum {
      G7231_BITRATE_UNSPECIFIED = RTP_CAP_UNSPECIFIED,
      G7231_BITRATE_0530 = 1,
      G7231_BITRATE_0630 = 2
   } bitrate;
   rtp_cap_bool annexa;   
} rtp_audio_g7231_cap_struct;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   rtp_cap_bool cn_payload;
} rtp_audio_g726_cap_struct;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   rtp_cap_bool cn_payload;
   enum {
      G711_RATE_UNSPECIFIED = RTP_CAP_UNSPECIFIED,
      G711_RATE_8000 = 1
   } rate;
   kal_uint8 channel; // the maximum
} rtp_audio_g711_cap_struct;

typedef enum {
   UNSUPPORTED = 0,
   AAC_LBR = 1,
   AAC_HBR = 2
} AudRTP_AAC_MODE;

typedef struct {

  // MP4A_LATM  // RFC 3016
    kal_uint32    rate;   // indicates the RTP time stamp clock rate
    kal_uint32    bitrate;
    kal_bool      cpresent;
    kal_uint16    ptime;

  // MPEG4_GENERIC  // RFC3640
    AudRTP_AAC_MODE        mode;
    kal_uint32    streamType;
    kal_uint32    uSizeLength;
    kal_uint32    uIndexLength;
    kal_uint32    uIndexDeltaLength;
    kal_uint32    uConstantSize;
    kal_uint32    uConstantDuration;
    kal_uint32    uMaxDisplacement;
    kal_uint32    uDeinterleaveBufSize;

  // common
    kal_uint32    profile_level_id;  // indicate MP4 audio profile level
    kal_uint8     *config;
    kal_uint32    object;  // MP4 Audio object type 

    kal_uint32    channel;
    kal_uint32    sample_rate;
#if defined(BSAC_DECODE)
    kal_uint32    uNumOfSubFrame;     // BSAC
    kal_uint32    uLayerLength;  // BSAC
#endif // #if defined(BSAC_DECODE)
} rtp_audio_aac_cap_struct;

typedef enum {
   RTP_AUDIO_NONE = 0,
   RTP_AUDIO_AMR = 1,
   RTP_AUDIO_G729 = 2,
   RTP_AUDIO_G7231 = 4,
   RTP_AUDIO_G726_16 = 8,
   RTP_AUDIO_G726_24 = 16,
   RTP_AUDIO_G726_32 = 32,
   RTP_AUDIO_G726_40 = 64,
   RTP_AUDIO_PCMA = 128,
   RTP_AUDIO_PCMU = 256,
   RTP_AUDIO_CN = 512,
   RTP_AUDIO_AWB = 1024,
   RTP_AUDIO_MP4A_LATM_AAC = 2048,
   RTP_AUDIO_MPEG4_GENERIC_AAC = 4096,
   RTP_AUDIO_AWB_PLUS = 8192,
   RTP_AUDIO_BSAC = 16384,
   RTP_AUDIO_MP2 = 32768,
   RTP_AUDIO_MP3 = 65536
} rtp_audio_codec_type;

typedef union {
   rtp_audio_amr_cap_struct   amr;
   rtp_audio_g729_cap_struct  g729;
   rtp_audio_g7231_cap_struct g7231;
   rtp_audio_g726_cap_struct  g726;
   rtp_audio_g711_cap_struct  g711;
   rtp_audio_aac_cap_struct   aac;
} rtp_audio_codec_cap;

typedef struct AudRTPDownlinkHandleStruct AudRTP_DL_HANDLE;
typedef void (*AudRTP_DL_CALLBACK)( AudRTP_EVENT event, AudRTP_DL_HANDLE *handle,
                                   void *host_data );

typedef struct{
   kal_uint8  *pAddrs;
   kal_uint32 uPktSize;
   kal_uint32 uSeqNum;
   kal_uint32 uTimeStamp;   
}JitterBuf;

#define MAX_JIT_PKT_CNT 5

struct AudRTPDownlinkHandleStruct {
   AudRTP_STATUS         (*GetCodecCapability)(AudRTP_DL_HANDLE *handle,
                                               rtp_audio_codec_type codec_type,
                                               rtp_audio_codec_cap *codec_cap );
   AudRTP_STATUS         (*Config)(AudRTP_DL_HANDLE *handle,
                                   rtp_audio_codec_type codec_type,
                                   rtp_audio_codec_cap *codec_cap,
                                   AudRTP_DL_CALLBACK callback,
                                   void *host_data, kal_uint32 session_id );
   kal_uint32            (*GetBufferSize)(AudRTP_DL_HANDLE *handle );
   AudRTP_STATUS         (*SetBuffer)(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer,
                                      kal_uint32 buffer_size );
   AudRTP_STATUS         (*Close)(AudRTP_DL_HANDLE *handle );
   AudRTP_STATUS         (*Start)(AudRTP_DL_HANDLE *handle, kal_uint32 start_time );
   AudRTP_STATUS         (*Stop)(AudRTP_DL_HANDLE *handle );
   AudRTP_STATUS         (*PutPacket)(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer,
                                      kal_uint32 buffer_size);
   AudRTP_STATUS         (*GetPlayTime)(AudRTP_DL_HANDLE *handle, kal_uint32 *p_current_time);
   AudRTP_STATUS         (*GetBufferStatus)(AudRTP_DL_HANDLE *handle, kal_uint32 *puCurBufDur, kal_uint32 *puBufFreeSize, kal_uint32 *puBufTotalSize, kal_uint32 *puMinBufTotalDur);

#if defined(__TDMB_SUPPORT__)
   AudRTP_STATUS         (*AddAccessUnit)(AudRTP_DL_HANDLE *handle, kal_uint8* au, kal_uint32 size, kal_uint32 timestamp);
   // Add Access Unit
   AudRTP_STATUS         (*RTP_Parser)(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer, 
                                      kal_uint32 buffer_size, kal_uint8 *au, 
                                      kal_uint32 au_size, kal_uint32 *timestamp);
#endif // #if defined(__TDMB_SUPPORT__)

   kal_uint32            (*GetSamplingFreq)(AudRTP_DL_HANDLE *handle );
   kal_uint8             (*GetChannelNum)(AudRTP_DL_HANDLE *handle );
   void                  (*SetVolumeLevel)( AudRTP_DL_HANDLE *handle, kal_uint8 level );
   
   // internal use
   void                  (*callback)( AudRTP_EVENT event, AudRTP_DL_HANDLE *handle,
                                   void *host_data );

   rtp_audio_codec_cap   stCodecCap;
   rtp_audio_codec_type  eAudCodecType;
   JitterBuf             stJitBuf[MAX_JIT_PKT_CNT];
   MHdl                  *psMHdl;
   kal_uint32            host_data;
   kal_uint32            session_id;
   kal_uint32            uPrePacketNum;
   kal_uint32            uPreTimeStamp;
   kal_uint32            uTotalFrameInBuf;
   kal_uint32            uJitterBufPacketCnt;
   kal_uint32            uState;
   kal_uint32            uPacketLossCnt;
};

AudRTP_DL_HANDLE *RTPAudio_OpenDLChannel( rtp_audio_codec_type codec_type );

typedef struct VoRTPUplinkHandleStruct VORTP_UL_HANDLE;
typedef struct VoRTPDownlinkHandleStruct VORTP_DL_HANDLE;
typedef void (*VORTP_UL_CALLBACK)( VORTP_EVENT event, VORTP_UL_HANDLE *handle, void *host_data );
typedef void (*VORTP_DL_CALLBACK)( VORTP_EVENT event, VORTP_DL_HANDLE *handle, void *host_data );
typedef void (*VORTP_TONE_CALLBACK)( VORTP_EVENT event, void *host_data );

struct VoRTPUplinkHandleStruct {
   rtp_audio_codec_type (*GetAvailableCodecs)( VORTP_UL_HANDLE *handle, 
                                               rtp_audio_codec_type *alt_codec_type );
   VORTP_STATUS         (*GetCodecCapability)( VORTP_UL_HANDLE *handle, 
                                               rtp_audio_codec_type codec_type, 
                                               rtp_audio_codec_cap *codec_cap,
                                               kal_bool alternated );
   VORTP_STATUS         (*Config)            ( VORTP_UL_HANDLE *handle, 
                                               rtp_audio_codec_type codec_type, 
                                               rtp_audio_codec_cap *codec_cap,
                                               VORTP_UL_CALLBACK callback, 
                                               void *host_data,
                                               kal_uint32 session_id );
   kal_uint32           (*GetBufferSize)     ( VORTP_UL_HANDLE *handle );
   VORTP_STATUS         (*SetBuffer)         ( VORTP_UL_HANDLE *handle, 
                                               kal_uint8 *buffer, 
                                               kal_uint32 buffer_size );
   VORTP_STATUS         (*Close)             ( VORTP_UL_HANDLE *handle );
   VORTP_STATUS         (*Start)             ( VORTP_UL_HANDLE *handle, kal_uint32 timestamp );
   VORTP_STATUS         (*Stop)              ( VORTP_UL_HANDLE *handle );
   VORTP_STATUS         (*SetMix)            ( VORTP_UL_HANDLE *handle, kal_bool enable ); // default on
   kal_int32            (*GetPacketCount)    ( VORTP_UL_HANDLE *handle );
   kal_uint32           (*GetPacket)         ( VORTP_UL_HANDLE *handle, 
                                               kal_uint8 *buffer, 
                                               kal_uint32 buffer_size, 
                                               rtp_audio_codec_type *codec_type );
   /* Below is for internal use */
   kal_uint8 			state;
   VORTP_UL_CALLBACK 	callback;
   void 				*host_data;
   kal_uint32 			session_id;
   kal_uint32 			timestamp;
};

struct VoRTPDownlinkHandleStruct {
   rtp_audio_codec_type (*GetAvailableCodecs)( VORTP_DL_HANDLE *handle, 
                                               rtp_audio_codec_type *alt_codec_type );
   VORTP_STATUS         (*GetCodecCapability)( VORTP_DL_HANDLE *handle, 
                                               rtp_audio_codec_type codec_type, 
                                               rtp_audio_codec_cap *codec_cap,
                                               kal_bool alternated );
   VORTP_STATUS         (*Config)            ( VORTP_DL_HANDLE *handle, 
                                               rtp_audio_codec_type codec_type, 
                                               rtp_audio_codec_cap *codec_cap,
                                               VORTP_DL_CALLBACK callback, 
                                               void *host_data,
                                               kal_uint32 session_id );
   kal_uint32           (*GetBufferSize)     ( VORTP_DL_HANDLE *handle );
   VORTP_STATUS         (*SetBuffer)         ( VORTP_DL_HANDLE *handle, 
                                               kal_uint8 *buffer, 
                                               kal_uint32 buffer_size );
   VORTP_STATUS         (*Close)             ( VORTP_DL_HANDLE *handle );
   VORTP_STATUS         (*Start)             ( VORTP_DL_HANDLE *handle );
   VORTP_STATUS         (*Stop)              ( VORTP_DL_HANDLE *handle );
   VORTP_STATUS         (*PutPacket)         ( VORTP_DL_HANDLE *handle, 
                                               kal_uint8 *buffer, 
                                               kal_uint32 buffer_size, 
                                               rtp_audio_codec_type codec_type );
   /* Below is for internal use */
   kal_uint8 			state;
   VORTP_DL_CALLBACK 	callback;
   void 				*host_data;
   kal_uint32 			session_id;
};

VORTP_UL_HANDLE *PoCAMR_OpenULChannel( void );
VORTP_DL_HANDLE *PoCAMR_OpenDLChannel( void );

VORTP_UL_HANDLE *VoRTP_OpenULChannel( void );
VORTP_DL_HANDLE *VoRTP_OpenDLChannel( void );
VORTP_STATUS VoRTP_StartInbandTone( 
   kal_uint32 freq1, kal_uint32 freq2, 
   kal_int32 amp_dbm0, kal_uint32 duration_msec, 
   VORTP_TONE_CALLBACK callback, void *host_data  );
VORTP_STATUS VoRTP_StopInbandTone( void );
void VoRTP_Init( void );
void VoRTP_SetEventLogging( kal_bool enable );

kal_bool BT_PcmLoopbackTest(void);

/* Ket tone detection interface*/
void KtDetectStart(void (*callback)(kal_int16 key));
void KtDetectStop( void );

// AFE interface 
void AFE_GetMappedGain(kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level,
                   kal_uint8 *AnalogGain, kal_int8 *DigitalGain);

Media_Format_Check_Result media_get_codec_type( void *p_filename, Media_Check_Format media_format,
                         Media_Check_Video_Codec *p_video_codec, Media_Check_Audio_Codec *p_audio_codec);
Media_Format_Check_Result media_get_format_type( void *file_name, Media_Check_Format *p_media_format);
kal_bool media_codec_type_check ( void *p_filename, Media_Check_Video_Codec video_codec, Media_Check_Audio_Codec audio_codec);

/*====================start of  l1TTS interface ===================*/
typedef enum
{
	TTS_STR_TEXT,     /*regard input as normal text */
	TTS_STR_PHN_SBL,  /*regard input as phonetic symbol*/
	TTS_STR_CHAR      /*regard input as character set. When this type is set, the engine usually synthesize character by character*/
}TTS_STR_TYPE;

typedef kal_uint8    TTS_LANG;
typedef kal_uint8    TTS_TYPE;
typedef kal_uint8    TTS_GENDER;

//The following definition may be extended in the future.

//TTS_LANGUAGE definition
#define	TTS_LANG_ENG   0x1;	/*English*/
#define	TTS_LANG_TWN   0x2;	/*Taiwan-accent Chinese*/
#define	TTS_LANG_MDN   0x4;	/*Mandarin*/

//TTS_TYPE definition
#define	TTS_TYPE_GENERAL  0x1	/*General Purpose TTS*/
#define	TTS_TYPE_DIC      0x2	/*Dictionary*/
#define	TTS_TYPE_NAME     0x4	/*Name*/
#define	TTS_TYPE_GPS      0x8	/*GPS, traffic guiding*/
#define	TTS_TYPE_WEATHER  0x10	/*weather report*/
#define	TTS_TYPE_STOCK    0x20	/*stock report*/

//TTS_GENDER definition
#define	TTS_GENDER_MALE   0x1
#define	TTS_GENDER_FEMALE 0x2
#define	TTS_GENDER_BOY    0x4
#define	TTS_GENDER_GIRL   0x8

/* constants for values of field dwParamId */
#define TTS_ATTR_INPUT_CODEPAGE    0x00000101	/* input code page, e.g. GBK */
#define TTS_ATTR_TEXT_SCOPE        0x00000103	/* text scope, e.g. number */
#define TTS_ATTR_INPUT_MODE        0x00000200	/* input mode, e.g. from fixed buffer, from callback */
#define TTS_ATTR_PROGRESS_CALLBACK 0x00000206	/* progress callback entry */
#define TTS_ATTR_READ_DIGIT        0x00000302	/* how to read digit, e.g. read as number, read as value  */
#define TTS_ATTR_CHINESE_NUMBER_1  0x00000303	/* how to read number "1" in Chinese */
#define TTS_ATTR_PHONEME_WATCH     0x00000402	/* how to watch phoneme, e.g. Chinese Pin-Yin */
#define TTS_ATTR_WATCH_CALLBACK    0x00000403	/* watch callback entry */
#define TTS_ATTR_SPEAK_STYLE       0x00000501	/* speak style */

/* constants for values of attribute TTSATTR_INPUT_CODEPAGE */
#define TTS_CODEPAGE_GBK             936   /* GBK (default) */
#define TTS_CODEPAGE_BIG5            950   /* Big5 */
#define TTS_CODEPAGE_UTF16LE         1200  /* UTF-16 little-endian */
#define TTS_CODEPAGE_UTF16BE         1201  /* UTF-16 big-endian */

/* constants for values of attribute TTSATTR_TEXT_SCOPE */
#define TTS_SCOPE_UNLIMITED          0     /* unlimited scope (default) */
#define TTS_SCOPE_CHINESE_NUMBER     1     /* Chinese number */
#define TTS_SCOPE_CHINESE_VALUE      2     /* Chinese value */
#define TTS_SCOPE_CHINESE_DATETIME   3     /* Chinese date or time */

/* constants for values of attribute TTSATTR_INPUT_MODE */
#define TTS_INPUT_FIXED_BUFFER       0     /* from fixed buffer */
#define TTS_INPUT_CALLBACK           1     /* from callback */

/* constants for values of attribute TTSATTR_READ_DIGIT */
#define TTS_READDIGIT_AUTO           0     /* decide automatically (default) */
#define TTS_READDIGIT_AS_NUMBER      1     /* say digit as number */
#define TTS_READDIGIT_AS_VALUE       2     /* say digit as value */

/* constants for values of attribute TTSATTR_CHINESE_NUMBER_1 */
#define TTS_CHNUM1_READ_YAO          0     /* read number "1" [yao1] in chinese (default) */
#define TTS_CHNUM1_READ_YI           1     /* read number "1" [yi1] in chinese */

/* constants for values of attribute TTSATTR_PHONEME_WATCH */
#define TTS_PHONEME_NONE             0     /* none (default) */
#define TTS_PHONEME_PINYIN           1     /* Chinese Pin-Yin */

/* constants for values of attribute TTSATTR_SPEAK_STYLE */
#define TTSSTYLE_PLAIN			0		/* plain speak style */
#define TTSSTYLE_NORMAL			1		/* normal speak style (default) */
#define TTSSTYLE_VIVID			2		/* vivid speak style */

typedef enum {
   TTS_END,
   TTS_ERROR,
   TTS_DATA_REQUEST,
   TTS_WATCH,                  /* TTS tell current synth information      */
   TTS_PROGRESS                 /* TTS tell the synth progress             */
} TTS_Event;

typedef struct _tagTTSProcessData TTS_PROCESS_DATA;
struct _tagTTSProcessData
{
   const void *lpcSylText;   /* the pointer of text      */
   kal_uint32 dwTextLen;     /* length of text (in byte) */
   const void *lpcSylPhone;  /* pointer of pinyin        */
   kal_uint32 dwPhoneLen;    /* length of pinyin(in byte)*/
   kal_uint16 wSylType;      /* text type                */
};

typedef struct _tagTTSProgress TTSPROGRESS;
struct _tagTTSProgress
{
   kal_uint32    dwProcPos;  /* the offset(in byte) of currently synthesizing context of original input text*/
   kal_uint32    dwProcLen;  /* the length(in byte) of currently synthesizing context of original input text*/
};

typedef struct _tagTTSAttr TTS_ATTR;
struct _tagTTSAttr
{
   kal_uint32    dwAttrId;      /* attribute id */
   kal_uint32    varAttrValue;  /* attribute value */
};

typedef struct ttsHandle TTS_Handle;

struct ttsHandle {
	void (*handler)(TTS_Handle *hdl, TTS_Event event, void *data);
	kal_uint32 speed;
	kal_uint32 pitch;
	kal_uint32 volume;
	Media_Status (*SetBuffer)(TTS_Handle *hdl, kal_uint8* buffer, kal_uint32 buf_len);
	kal_uint32   (*GetBufSize)(TTS_Handle *hdl);
	Media_Status (*Play)(TTS_Handle *hdl, kal_wchar* string, TTS_STR_TYPE strType);
	Media_Status (*Pause)(TTS_Handle *hdl);
	Media_Status (*Resume)(TTS_Handle *hdl);
	Media_Status (*Stop)(TTS_Handle *hdl);
	Media_Status (*Close)(TTS_Handle *hdl);
	Media_Status (*SetPitch)(TTS_Handle *hdl, kal_uint32 pitch);
	Media_Status (*SetVolume)(TTS_Handle *hdl, kal_uint32 volume);
	Media_Status (*SetSpeed)(TTS_Handle *hdl, kal_uint32 speed);
	Media_Status (*SetAttr)(TTS_Handle *hdl, kal_uint32 dwAttrId, kal_uint32 varAttrValue);
	TTS_STR_TYPE   strType;
	TTS_LANG    lang;
	TTS_TYPE    type;
	TTS_GENDER  gender;
/*other internal variable*/
#if defined(IFLY_TTS)
   kal_bool  dataReq;
   kal_uint16 aud_id;
   void *customHdl;
   void *text;
#endif
	kal_uint16 state;
   MHdl *spcmHdl;
   Media_Event event;
   kal_wchar dataDir[100];
   kal_bool  bProcessDone;
};

TTS_Handle *TTS_Open(void(*callback)(TTS_Handle *hdl, TTS_Event event, void *data), TTS_LANG lang, TTS_TYPE type, TTS_GENDER gender);
/*====================end of l1TTS interface ===================*/

/*====================start of 3G interface ===================*/
#define RAT_2G_MODE  0
#define RAT_3G_MODE  1 
#define RAT_3G324M_MODE 2

typedef enum {
   SP3G_CODEC_READY,
   SP3G_CODEC_CLOSED,
   SP3G_UL_DATA_NOTIFY,
   SP3G_UL_DATA_DEALY_TICK
} SP3G_Event;

void SP3G_Request(void);
void SP3G_UL_SetFrameType(kal_uint8 amr_frame_type);
void SP3G_UL_GetSpeechFrame(kal_uint16*frame_index, kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len);
void SP3G_DL_PutSpeechFrame(kal_uint32 CFN, kal_uint8 sub_flow_id, kal_uint8 frame_type, kal_bool crc_status, kal_uint8 *subflow);
void SP3G_Closed_Confirm( void );
//void SP3GVT_DL_PutSpeechFrame(kal_uint8 *dl_data, kal_uint32 size, kal_bool error_flag);
kal_uint8 SP3GVT_DL_PutSpeechFrame(kal_uint8 *dl_data, kal_uint32 size, kal_bool error_flag, kal_uint8 *dl_frame_number);
kal_uint8 SP3GVT_DL_DropSpeechFrame(kal_uint32 number, kal_uint8 *dl_frame_number);
void SP3GVT_UL_GetSpeechFrame(kal_uint8 *ul_data, kal_uint32 ul_space, kal_uint32 *size);
void SP3GVT_SetDelayValue(kal_uint32 delay);
/*====================end of 3G interface =====================*/

#endif


