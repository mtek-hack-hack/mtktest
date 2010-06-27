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
 *   w32_audio.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   L1Audio dummy functions for WIN32 environment
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <windows.h>
#include <math.h>
#include "time.h"

#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"

#include "stacklib.h"
#include "stack_timer.h"

#include "syscomp_config.h"
#include "task_config.h"

#include "device.h"
//#include "w32_timers.h"
#include "rtc_sw.h"
#include "l4a.h"
#include "uart_sw.h"
#include "drvsignals.h"

#include "l1audio.h"

static MHdl mhdl;
static Media_iMelody_Param iMelody_Param;
static Media_Wav_Param Wav_Param;
static Media_ToneSeq_Param ToneSeq_Param;
static Media_AMR_Param AMR_Param;
static Media_SMF_Param SMF_Param;

L1SP_TurnOnFIR(){};
L1SP_TurnOffFIR(){};
L1SP_IsFIROn(){};


void        L1SP_SetOutputDevice( kal_uint8 device ) {}
void        L1SP_LoadCommonSpeechPara( kal_uint16* c_para) {}
void        L1SP_SetSpeechMode( kal_uint8 mode, kal_uint16* m_para) {}
void        L1SP_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index ){}
void        L1SP_SetSpeechVolumeLevel( kal_uint8 level ) {}
void        L1SP_Speech_On( void ){}
void        L1SP_Speech_Off( void ){}
void        L1SP_SetInputSource( kal_uint8 src ){}
kal_uint8   L1SP_GetInputSource( void ){return 0;}
void        L1SP_SetMicrophoneVolume( kal_uint8 mic_volume ){}
kal_uint8   L1SP_GetMicrophoneVolume( void ){return 0;}
void        L1SP_SetSidetoneVolume( kal_uint8 sidetone ){}
kal_uint8   L1SP_GetSidetoneVolume( void ){return 0;}
void        L1SP_MuteMicrophone( kal_bool mute ){}
kal_bool    L1SP_IsMicrophoneMuted( void ){return 0;}
void        L1SP_SetFIR( kal_bool enable ){}
void        L1SP_SetEchoSuppression( kal_bool ec ){}
void        L1SP_SetEchoSuppressionParameter( kal_uint16 timeConst, kal_uint16 volConst ){}
void        L1SP_Set_DAI_Mode( kal_uint8 mode ){}
void        L1SP_Write_Audio_Coefficients( const kal_int16 in_coeff[30], const kal_int16 out_coeff[30] ){}
void        L1SP_SetAfeLoopback( kal_bool enable ){}


/* ------------------------------------------------------------------------------ */
/*  Key Tone Interface                                                            */
/* ------------------------------------------------------------------------------ */
void  KT_SetOutputDevice( kal_uint8 device ){}
void  KT_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index ){}

void  KT_Stop( void ){}
void  KT_SetAmplitude( kal_int16 amp ){}
void  KT_SetFIR( kal_bool enable ){}




void  TONE_SetOutputDevice( kal_uint8 device ) {}
void  TONE_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index ){}

void  TONE_Stop( void ){}
void  TONE_SetAmplitude( kal_int16 amp ){}
void  TONE_SetFIR( kal_bool enable ){}
void  TONE_PlayQTMF( const L1SP_QTMF *tonelist ){} /* QTMF Play Interface */




void  Media_SetOutputDevice( kal_uint8 device ){}
void  Media_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index ){}
void  Media_SetBuffer( kal_uint16 *buffer, kal_uint32 buf_len ){}
Media_Status  Media_Play( Media_Format format, void (*media_handler)( Media_Event event ), void *param ){return MEDIA_SUCCESS;}
Media_Status  Media_Record( Media_Format format, void (*media_handler)( Media_Event event ), void *param ){return MEDIA_SUCCESS;}
Media_Status  Media_Control( Media_Ctrl ctrl_no, kal_int32 ctrl_val ){return MEDIA_SUCCESS;}
void  Media_Stop( void ){}
void  Media_GetWriteBuffer( kal_uint16 **buffer, kal_uint32 *buf_len ){}
void  Media_WriteDataDone( kal_uint32 len ){}
void  Media_DataFinished( void ){}
void  Media_GetReadBuffer( kal_uint16 **buffer, kal_uint32 *buf_len ){}
void  Media_ReadDataDone( kal_uint32 len ){}
Media_Status Media_SetLevel( kal_uint8 level ){return MEDIA_SUCCESS;}
kal_uint32   Media_GetRecordedTime( void ) {return 5000;}

typedef void (*play_finish_ind_func)(void);
static play_finish_ind_func play_finish_ind_handler=NULL;
void  TONE_SetHandler( void (*handler)(void) )
{
	play_finish_ind_handler = (handler);
}

#define SAMPLE_PER_SECOND	11025			  // sample per seconds
#define MAX_TONE_SECONDS	10				
#define PI            3.14159265358979

static HWAVEOUT     hWaveOut;          // Handle to sound card output
static WAVEHDR      WaveHeader;        // WAVE header for our sound data
static WAVEFORMATEX WaveFormat;        // The sound format

static char			tone_buffer[SAMPLE_PER_SECOND*MAX_TONE_SECONDS];
static const L1SP_Tones *current_tone;
static const L1SP_Tones	*tone_root;
static kal_bool is_busy;
static void CALLBACK w32_tone_play_finish(HWAVEOUT hwo,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2)
{
	switch(uMsg)
	{
	case WOM_OPEN:
		return;
	case WOM_CLOSE:
		return;
	case WOM_DONE:
		break;
	}
	if(!current_tone)
	{
		if(play_finish_ind_handler)
			play_finish_ind_handler();

		if (waveOutUnprepareHeader(hWaveOut,&WaveHeader,sizeof(WaveHeader)) != MMSYSERR_NOERROR)
			return ;
		is_busy = KAL_FALSE;
		return;
	}


	// ** Make the sound buffer **
	{
		int i;
		double x;
		
		int total_bytes = current_tone->on_duration *SAMPLE_PER_SECOND/1000;
		if(total_bytes > SAMPLE_PER_SECOND*MAX_TONE_SECONDS)
			total_bytes = SAMPLE_PER_SECOND*MAX_TONE_SECONDS;
		
		for(i=0;i<total_bytes;i++)
		{
			x = sin(i*2.0*PI*current_tone->freq1/(double)SAMPLE_PER_SECOND);
	        // ** scale x to a range of 0-255 (signed char) for 8 bit sound reproduction **
			tone_buffer[i] = (char)(127*x+128);
		}
		// ** Create the wave header for our sound buffer **
		WaveHeader.lpData=tone_buffer;
		WaveHeader.dwBufferLength=total_bytes;
		WaveHeader.dwFlags=WHDR_DONE;
		WaveHeader.dwLoops=0;
	}
    
    // ** Prepare the header for playback on sound card **
    if (waveOutPrepareHeader(hWaveOut,&WaveHeader,sizeof(WaveHeader)) != MMSYSERR_NOERROR)
        return;
    
	is_busy = KAL_TRUE;
	// ** Play the sound! **
    if (waveOutWrite(hWaveOut,&WaveHeader,sizeof(WaveHeader)) != MMSYSERR_NOERROR)
        return;

	// move to next tone
	if(current_tone->next_tone==0)
		current_tone = NULL;
	else
		current_tone = &(tone_root[current_tone->next_tone]);

}

void w32_audio_init(void)
{
    // ** Initialize the sound format we will request from sound card **    
    WaveFormat.wFormatTag = WAVE_FORMAT_PCM;		// Uncompressed sound format
    WaveFormat.nChannels = 1;						// 1=Mono 2=Stereo
    WaveFormat.wBitsPerSample = 8;					// Bits per sample per channel
    WaveFormat.nSamplesPerSec = SAMPLE_PER_SECOND;           // Sample Per Second
    WaveFormat.nBlockAlign = WaveFormat.nChannels * WaveFormat.wBitsPerSample / 8;
    WaveFormat.nAvgBytesPerSec = WaveFormat.nSamplesPerSec * WaveFormat.nBlockAlign;    
    WaveFormat.cbSize = 0;

	current_tone = NULL;
	is_busy = KAL_FALSE;

    // ** Open the audio device **
    if (waveOutOpen(&hWaveOut,0,&WaveFormat,(DWORD) w32_tone_play_finish,0,CALLBACK_FUNCTION) != MMSYSERR_NOERROR) 
    {        
        return;
    }

}



void  TONE_Play( const L1SP_Tones *tonelist )
{
	if(is_busy) return;
	
	current_tone = tone_root = tonelist;
	w32_tone_play_finish(0,WOM_DONE,0,0,0);
}

//static L1SP_Tones kt_tone[128];
//static int kt_tone_index=0;
void  KT_Play( kal_uint16 freq1, kal_uint16 freq2, kal_uint16 duration )
{
	/*
	if(is_busy) return;
	kt_tone_index ++;
	kt_tone_index %=128;
	kt_tone[kt_tone_index].freq1 = freq1;
	kt_tone[kt_tone_index].freq2 = freq2;
	kt_tone[kt_tone_index].on_duration = duration;
	kt_tone[kt_tone_index].next_tone = 0;
	TONE_Play(&(kt_tone[kt_tone_index]));
	*/
}

void L1SP_NormalMode_SetAECParameter(void){}
void L1SP_NormalMode_SetAEC(void){}
void wavSetAdpcmState(void){}
void mediaIsDataConsumed( void ){}
void mediaGetDataCount( void ){}
void amrGetDataCount(void){}
void AEQ_SetAudioEqualizer( kal_int8 magnitude[8] ){}
void AEQ_Activate( kal_int16 asp_fs, kal_bool rampup ){}
/* l1audio internal use */
kal_uint32 AMR515_BufferSize( void ){return 0;}
kal_uint16 AMR515_SetBuffer( void *buf, kal_uint32 buf_size ){return 0;}
Media_Status PoC_AMR_EncodeStart( PoC_AMR_Type vocoder, void (*media_handler)(void), kal_int32 frame_threshold ) {	return MEDIA_SUCCESS;}
void PoC_AMR_SetBuffer(kal_uint16 *buf, kal_uint32 len){}
PoC_AMR_Type PoC_AMR_GetVocoderCapability(void){return 0;}
Media_Status PoC_AMR_EncodeStop( void ){return MEDIA_SUCCESS;}
Media_Status PoC_AMR_DecodeStart( void ){return MEDIA_SUCCESS;}
Media_Status PoC_AMR_DecodeStop( void ){return MEDIA_SUCCESS;}
kal_int32 PoC_AMR_GetFrameCount( void ){return 0;}
kal_int32 PoC_AMR_GetPayload( kal_uint8 *buf, kal_int32 len, kal_int32 frames ){return 0;}
Media_Status PoC_AMR_PutPayload( const kal_uint8 *buf, kal_int32 len ){return MEDIA_SUCCESS;}


kal_bool gea_cidecipher (kal_uint8 *src_buff_ptr,
	   kal_uint8 *dest_buff_ptr,	
	   kal_uint16 buff_len,
	   kal_uint8 cipher_algo,	   
	   kal_bool direction,
	   kal_uint8 *input_sk,
	   kal_uint32 input_mk)
{ return KAL_TRUE;
}
kal_bool NANDsanitycheck_Factory(void) {return KAL_TRUE;}
void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms) {}

/* Dummy Audio Post Process Interface */
kal_bool AudioPP_TS_IsSupport(Media_Format eFormat, STFSAL *pstFSAL) { return KAL_TRUE; }
Media_Status AudioPP_TS_SetSpeed(kal_uint16 speed_mode) { return 0; }
void AudioPP_TS_Close(void) {}
void AudioPP_Reverb_SetCoeff(kal_int16* CoeffTable) {}
Media_Status AudioPP_Reverb_TurnOn( void ) {return 0;}
void AudioPP_Reverb_TurnOff(void) {}

	
void  Media_SetMelodyFilter( kal_uint16 len, const kal_int16 *filter ){}


/* FM Radio Interface */
void  FMR_PowerOn(void){}
void  FMR_PowerOff(void){}
kal_uint8 FMR_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up){return 0;}
void  FMR_SetFreq(kal_int16 curf){}
void FMR_AutoSearch(kal_uint8 dir, void(*fm_handler)(kal_int16 *data)){}
kal_int16 FMR_ManualSearch(kal_uint8 dir){return 0;}
kal_int16 FMR_GetFreq(void){return 0;}
void  FMR_Mute(kal_uint8 mute){}
void  FMR_Mono(kal_uint8 MS){}
void  FMR_Standby(kal_uint8 standby){}
void FMR_SetOutputDevice( kal_uint8 device ){}
void  FMR_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index ){}

#ifndef WIN32
//Huyanwei Add It 
kal_uint8 FMR_GetSignalLevel(kal_int16 curf){return 0;}
#endif


void Media_SetOutputVolume_ST( kal_uint8 volume ) {}
void  Media_GetFileHeader( kal_uint8 **header, kal_uint32 *len ) {}
void  Media_SetRBThreshold( kal_uint16 threshold ) {}
kal_bool Media_IsCSDMode(void){return 0;}

void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada) {}

Media_Status  Media_Pause( void ){return MEDIA_SUCCESS;}
Media_Status  Media_Resume( void ){return MEDIA_SUCCESS;}


Media_Handle   *JTone_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_ToneSeq_Param **param )
{
	*param = &ToneSeq_Param;
	return (Media_Handle*)&mhdl;
}
Media_Status   JTone_Close( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JTone_Play( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JTone_Stop( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JTone_Pause( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JTone_Resume( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JTone_SetStartTime( Media_Handle *handle, kal_int32 msStartTime ){return MEDIA_SUCCESS;}
Media_Status   JTone_SetStopTime( Media_Handle *handle, kal_int32 msStopTime ){return MEDIA_SUCCESS;}
kal_int32      JTone_GetCurrentTime( Media_Handle *handle ){return 0;}
kal_int32      JTone_GetDuration( Media_Handle *handle ){return 0;}
Media_Status   JTone_SetLevel( Media_Handle *handle, kal_uint8 level ){return MEDIA_SUCCESS;}
kal_uint8      JTone_GetLevel( Media_Handle *handle ){return 0;}
Media_Status   JTone_SetPitchShift(Media_Handle *handle, kal_int8 pitch_shift){return MEDIA_SUCCESS;}
kal_int8       JTone_GetPitchShift(Media_Handle *handle){return 0;}
Media_Status   JTone_SetSpeed(Media_Handle *handle, kal_uint32 speed_factor){return MEDIA_SUCCESS;}
Media_Status   JTone_SetProgram(Media_Handle *handle, kal_uint8 program){return MEDIA_SUCCESS;}
Media_Status   JTone_SetPlayStyle(Media_Handle *handle, kal_uint8 play_style){return MEDIA_SUCCESS;}

Media_Handle   *JImy_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_iMelody_Param **param )
{
	*param = &iMelody_Param;
	return (Media_Handle*)&mhdl;
}
Media_Status   JImy_Close( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JImy_Play( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JImy_Stop( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JImy_Pause( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JImy_Resume( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JImy_SetStartTime( Media_Handle *handle, kal_int32 msStartTime ){return MEDIA_SUCCESS;}
Media_Status   JImy_SetStopTime( Media_Handle *handle, kal_int32 msStopTime ){return MEDIA_SUCCESS;}
kal_int32      JImy_GetCurrentTime( Media_Handle *handle ){return 0;}
kal_int32      JImy_GetDuration( Media_Handle *handle ){return 0;}
Media_Status   JImy_SetLevel( Media_Handle *handle, kal_uint8 level ){return MEDIA_SUCCESS;}
kal_uint8      JImy_GetLevel( Media_Handle *handle ){return 0;}

Media_Handle   *JWav_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_Wav_Param **param )
{
	*param = &Wav_Param;
	return (Media_Handle*)&mhdl;
}
Media_Status   JWav_Close( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JWav_Load(Media_Handle *handle, kal_uint32 *requiredBufSize)
{	
	*requiredBufSize = 100;
	return MEDIA_SUCCESS;
}
void           JWav_SetBuffer(Media_Handle *handle, kal_int16 *buffer, kal_uint32 buf_len){}
Media_Status   JWav_Play( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JWav_Stop( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JWav_Pause( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JWav_Resume( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JWav_SetStartTime( Media_Handle *handle, kal_int32 msStartTime ){return MEDIA_SUCCESS;}
Media_Status   JWav_SetStopTime( Media_Handle *handle, kal_int32 msStopTime ){return MEDIA_SUCCESS;}
kal_int32      JWav_GetCurrentTime( Media_Handle *handle ){return 0;}
kal_int32      JWav_GetDuration( Media_Handle *handle ){return 0;}
Media_Status   JWav_SetLevel( Media_Handle *handle, kal_uint8 level ){return MEDIA_SUCCESS;}
kal_uint8      JWav_GetLevel( Media_Handle *handle ){return 0;}

Media_Handle   *JXWav_Open( void (*handler)( Media_Handle *handle, Media_Event event )){return (Media_Handle*)&mhdl;}
Media_Status   JXWav_Close( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JXWav_Load(Media_Handle *handle, kal_uint32 *requiredBufSize){return MEDIA_SUCCESS;}
void           JXWav_SetBuffer(Media_Handle *handle, kal_int16 *buffer, kal_uint32 buf_len){}
Media_Status   JXWav_Play( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JXWav_Stop( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JXWav_Pause( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JXWav_Resume( Media_Handle *handle ){return MEDIA_SUCCESS;}
kal_int32      JXWav_GetCurrentTime( Media_Handle *handle ){return 0;}
Media_Status   JXWav_SetLevel( Media_Handle *handle, kal_uint8 level ){return MEDIA_SUCCESS;}
kal_uint8      JXWav_GetLevel( Media_Handle *handle ){return 0;}

kal_uint32 Media_A2V_GetInterruptCount(void){return 0;}
void Media_A2V_EnableInterrupt(kal_bool bFlag, kal_uint32 start_count){}
void Media_A2V_HookInterrupt(void (*a2v_lisr)(void)){}
void Media_A2V_SetTimeStamp(kal_uint16 wTimeStamp){}

kal_uint16 Media_A2V_GetAudioFrameCount(void){return 0;}
kal_uint16 Media_A2V_GetVideoFrameCount(void){return 0;}
kal_uint32 Media_A2V_GetAudioInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex){return 0;}
kal_uint32 Media_A2V_GetAudioInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex){return 0;}
kal_uint32 Media_A2V_GetAudioPlaybackDelay(Media_Format eFormat){return 0;}
kal_uint32 Media_A2V_GetAudioRecordDelay(Media_Format eFormat){return 0;}

kal_uint32 Media_A2V_GetPlaybackInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex){return 0;}
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex){return 0;}
kal_uint32 Media_A2V_GetRecInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex){return 0;}
kal_uint32 Media_A2V_GetRecInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex){return 0;}

const kal_uint16 lenSpeechBitsAMR[9]={
    95, 103, 118, 134, 148, 159, 204, 244, 39
};
const kal_uint16 lenSpeechBitsAMR_WB[10]={
   132, 177, 253, 285, 317, 365, 397, 461, 477, 40
};

void GPTI_StartItem(void){}
void GPTI_StopItem(void){}

void Media_A2V_SetInterruptCount(kal_uint32 uInterruptCount){}
VR_Result VR_GetParameters(kal_int16 *SimThrld, kal_int16 *DiffThrld, kal_int16 *RejThrld){return 0;}
VR_Result VR_SetParemeters (kal_int16 SimThrld, kal_int16 DiffThrld, kal_int16 RejThrld){return 0;}
kal_uint32 VR_GetBufferSize(void){return 0;}
void VR_SetBuffer(kal_uint8 *RTmemory){}
VR_Result  VR_SetDatabaseDir(kal_uint8 *Dir){return 0;}
VR_Result VR_TRA_Start(kal_uint16 wID, kal_uint16 *mdIDList, kal_uint16 *mdIDListLen, void (*vr_handler)(void *parameter )){return 0;}
VR_Result VR_TRA2Start(void){return 0;}
VR_Result VR_RCG_Start(kal_uint16 *mdIDList,kal_uint16 *mdIDListLen,void(*vr_handler)(void *parameter)){return 0;}
VR_Result VR_Process(kal_uint16 *RcgID){return 0;}
void VR_Stop(void){}
kal_int32 VR_GetEngineVer(void){return 0;}


Media_Handle   *JAmr_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_AMR_Param **param )
{
	*param = &AMR_Param;
	return (Media_Handle*)&mhdl;
}
Media_Status   JAmr_Close( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JAmr_Play( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JAmr_Stop( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JAmr_Pause( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JAmr_Resume( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JAmr_SetStartTime( Media_Handle *handle, kal_int32 msStartTime ){return MEDIA_SUCCESS;}
Media_Status   JAmr_SetStopTime( Media_Handle *handle, kal_int32 msStopTime ){return MEDIA_SUCCESS;}
kal_int32      JAmr_GetCurrentTime( Media_Handle *handle ){return 0;}
Media_Status   JAmr_SetLevel( Media_Handle *handle, kal_uint8 level ){return MEDIA_SUCCESS;}
kal_uint8      JAmr_GetLevel( Media_Handle *handle ){return 0;}
Media_Status   JAmr_GetDuration( const kal_uint8 *amrfile, kal_int32 amrsize, kal_int32 *duration ){return MEDIA_SUCCESS;}



void free_NFI_bus(void) {}
void get_NFI_bus(void) {}



kal_bool       JMidi_isBankQuerySupported( void ){return 0;}
void           JMidi_GetBankList( kal_bool custom, const kal_int16 **buf, kal_int16 *len){}
void           JMidi_GetProgramList( kal_int16 bank, const kal_int8 **buf, kal_int16 *len){}
const kal_uint8*JMidi_GetProgramName( kal_int16 bank, kal_int8 prog ){return 0;}
const kal_uint8*JMidi_GetKeyName( kal_int16 bank, kal_int8 prog, kal_int8 key ){return 0;}

Media_Handle   *JMidi_OpenDevice( void ){return (Media_Handle*)&mhdl;}
Media_Status   JMidi_CloseDevice( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JMidi_SendLongMsg( Media_Handle *handle, const kal_uint8 *buf, kal_uint16 len ){return MEDIA_SUCCESS;}
Media_Status   JMidi_SendShortMsg( Media_Handle *handle, kal_uint8 type, kal_uint8 data1, kal_uint8 data2 ){return MEDIA_SUCCESS;}
Media_Status   JMidi_SetLevel( Media_Handle *handle, kal_uint8 level ){return MEDIA_SUCCESS;}
kal_uint8      JMidi_GetLevel( Media_Handle *handle ){return 0;}
Media_Status   JMidi_SetTempo( Media_Handle *handle, kal_int32 milliTempo ){return MEDIA_SUCCESS;}
kal_int32      JMidi_GetTempo( Media_Handle *handle ){return 0;}
Media_Status   JMidi_SetRate( Media_Handle *handle, kal_int32 milliRate ){return MEDIA_SUCCESS;}
kal_int32      JMidi_GetRate( Media_Handle *handle ){return 0;}
Media_Status   JMidi_SetPitchTranspose( Media_Handle *handle, kal_int32 milliSt ){return MEDIA_SUCCESS;}
kal_int32      JMidi_GetPitchTranspose( Media_Handle *handle ){return 0;}
Media_Status   JMidi_SetChannelVolume( Media_Handle *handle, kal_int8 channel, kal_uint8 level ){return MEDIA_SUCCESS;}
kal_int8       JMidi_GetChannelVolume( Media_Handle *handle, kal_int8 channel ){return 0;}
Media_Status   JMidi_SetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 bank, kal_int8 program ){return MEDIA_SUCCESS;}
void           JMidi_GetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 *bank, kal_int8 *program ){}

void wavGetAdpcmState      (void){}
void wavCopyAdpcmState     (void){}
void jpeg_video_play_lcd_id(void){}
void       *processing_lisr;
void sccb_config(void){}


Media_Handle   *JSmf_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_SMF_Param **param )
{
	*param = &SMF_Param;
	return (Media_Handle*)&mhdl;
}
Media_Status   JSmf_Close( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JSmf_Play( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JSmf_Stop( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JSmf_Pause( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JSmf_Resume( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status   JSmf_SetStartTime( Media_Handle *handle, kal_int32 msStartTime ){return MEDIA_SUCCESS;}
Media_Status   JSmf_SetStopTime( Media_Handle *handle, kal_int32 msStopTime ){return MEDIA_SUCCESS;}
kal_int32      JSmf_GetCurrentTime( Media_Handle *handle ){return 0;}
kal_int32      JSmf_GetDuration( Media_Handle *handle ){return 0;}
kal_int32      JSmf_GetMidiDuration( const kal_uint8 *mid ){return 100;}
Media_Event    JSmf_QueryExtEvent( Media_Handle *handle, kal_int32 *note ){return 0;}
kal_bool       JSmf_isSpMidi( Media_Handle *handle ){return KAL_FALSE;}

void SPT_Open( void ){}
void SPT_Close( void ){}
void SPT_GetSpectrum( kal_uint8 top[16], kal_uint8 val[16] ){}
void SPT_PutPcmData( const kal_int16 *pcm, kal_int32 len, kal_bool mono ){}    /* L1audio internal use */

#if defined(MT6205B) 
kal_uint8 AFE_TurnOnMicBias( void ) { return 0;}
void AFE_TurnOffMicBias( void ) {}
#else 
void AFE_TurnOnMicBias(void){}
void AFE_TurnOffMicBias( void ){}
#endif


MHdl *AMR_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *VM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *DAF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *AAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *WAV_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *AIFF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *AU_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *M4A_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *PCM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *WMA_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param) {return &mhdl;}
MHdl *PCM_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param) {return &mhdl;}
MHdl *PCM_Strm_Rec_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param) {return &mhdl;}

Media_Status VM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )	 { return MEDIA_SUCCESS; }
Media_Status AIFF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ) 	{ return MEDIA_SUCCESS; }
Media_Status PCM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ) 	{ return MEDIA_SUCCESS; }
Media_Status DAF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ) 	{ return MEDIA_SUCCESS; }
Media_Status M4A_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ) 	{ return MEDIA_SUCCESS; }
Media_Status AMR_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ) 	{ return MEDIA_SUCCESS; }
Media_Status WAV_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ) 	{ return MEDIA_SUCCESS; }
Media_Status AU_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ) 	{ return MEDIA_SUCCESS; }
Media_Status WMA_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ) {return MEDIA_SUCCESS;}
Media_Status AAC_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  ){return MEDIA_SUCCESS;}
kal_bool AAC_IsPPSupport( STFSAL *pstFSAL) {return 0;}
kal_bool M4A_IsPPSupport( STFSAL *pstFSAL) {return 0;}
void mhdlStoreFileOffset(void){}
void mhdlSetFileOffset(kal_uint32 uCurOffset){}
kal_uint32 mhdlGetFileOffset(void){return 0;}
Media_Status AAC_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }
Media_Status AMR_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }
Media_Status DAF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }
Media_Status JSmf_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }
Media_Status JImy_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }
Media_Status WMA_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }
Media_Status WAV_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }
Media_Status AIFF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }
Media_Status AU_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param ){ return MEDIA_SUCCESS; }

/* SBC interface */
bt_a2dp_sbc_codec_cap_struct sbc_cap[1];
void SBC_InitiateBitPool( kal_uint8 channel_mode, kal_uint8 sample_rate, kal_uint8 *min, kal_uint8 *max ) {}
kal_uint32 SBC_GetMemReq(void) { return 0; }
A2DP_codec_struct *SBC_Open(
   Media_Format aud_fmt, 
   A2DP_Callback pHandler, 
   bt_a2dp_sbc_codec_cap_struct *sbc_config_data, 
   kal_uint8 *buf, 
   kal_uint32 buf_len ) { return 0; }
void SBC_Close(void) {}
void SBC_AdjustBitpool( kal_uint8 max_bitpool, kal_uint8 min_bitpool ) {}
kal_uint32 SBC_SetQualityLevel(kal_uint32 level) {return level;}

bt_a2dp_mp3_codec_cap_struct mp3_cap[1];
kal_uint32 A2DP_DAF_GetMemReq(void){return 0;}
A2DP_codec_struct *A2DP_DAF_Open( MHdl *mhdl_handle, A2DP_Callback pHandler, bt_a2dp_mp3_codec_cap_struct *daf_config_data, kal_uint8 *buf, kal_uint32 buf_len){return NULL;}
void A2DP_DAF_Close( MHdl *mhdl_handle ){return;}


/*
VORTP_UL_HANDLE *PoCAMR_OpenULChannel( void ){ return NULL; }
VORTP_DL_HANDLE *PoCAMR_OpenDLChannel( void ){ return NULL; }

VORTP_UL_HANDLE *VoRTP_OpenULChannel( void ){ return NULL; }
VORTP_DL_HANDLE *VoRTP_OpenDLChannel( void ){ return NULL; }
VORTP_STATUS VoRTP_StartInbandTone( 
   kal_uint32 freq1, kal_uint32 freq2, 
   kal_int32 amp_dbm0, kal_uint32 duration_msec, 
   VORTP_TONE_CALLBACK callback, void *host_data  ){ return VORTP_STATUS_FAIL; }
VORTP_STATUS VoRTP_StopInbandTone( void ){ return VORTP_STATUS_FAIL; }
 VoRTP interface */
void L1Ctm_Open(L1Ctm_Interface a, L1Ctm_Callback handler, kal_uint8 *buf, kal_uint32 buf_len, CTM_Param *ctm_param){ return; }
void L1Ctm_StartNegotiation(void){ return; }
void L1Ctm_Close(void){ return; }
kal_uint32 L1Ctm_GetMemReq(void){ return 0; }
kal_uint32 L1Ctm_RxGetText(kal_uint8 *text, kal_uint32 len, kal_uint32 *left_count){ return 0; }
kal_uint32 L1Ctm_TxPutText(const kal_uint8 *text, kal_uint32 len, kal_uint32 *left_space){ return 0; }

void AFE_GetMappedGain(kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level,
                   kal_uint8 *AnalogGain, kal_int8 *DigitalGain){}
void AFE_SetLevelVolume(kal_uint8 aud_func, kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level)
{  
}  
void  Media_SetLevelVolume( kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level )
{   
}                   
void AudioPP_Surround_Enable(void)
{
}
void AudioPP_Surround_Disable(void)
{
}
void AudioPP_Surround_ModeSelect(kal_int32 mode)
{
}

void AM_SetLoopBackTest( kal_bool enable )
{
}

kal_bool AM_IsVoIPOn( void ){return 0;}

TTS_Handle *TTS_Open(void(*callback)(TTS_Handle *hdl, TTS_Event event, void *data), TTS_LANG lang, TTS_TYPE type, TTS_GENDER gender){ return NULL; }
void SP3G_Request(void){ return; }
void SP3G_UL_SetFrameType(kal_uint8 amr_frame_type){ return; }
void SP3G_UL_GetSpeechFrame(kal_uint16*frame_index, kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len){ return; }
void SP3G_DL_PutSpeechFrame(kal_uint32 CFN, kal_uint8 sub_flow_id, kal_uint8 frame_type, kal_bool crc_status, kal_uint8 *subflow){ return; }
void SP3G_Closed_Confirm( void ){ return; }
kal_uint8 SP3GVT_DL_PutSpeechFrame(kal_uint8 *dl_data, kal_uint32 size, kal_bool error_flag, kal_uint8 *dl_frame_number){return 0;}
kal_uint8 SP3GVT_DL_DropSpeechFrame(kal_uint32 number, kal_uint8 *dl_frame_number){return 0;}
void SP3GVT_UL_GetSpeechFrame(kal_uint8 *ul_data, kal_uint32 ul_space, kal_uint32 *size){ return; }
void SP3GVT_SetDelayValue(kal_uint32 delay){ return; }

// For Audio Equalizer
void AudioPP_Equalizer_SetMag( kal_int8 magnitude[8] ) {}
void AudioPP_Equalizer_TurnOn( void ) {}
void AudioPP_Equalizer_TurnOff( void ) {}
kal_bool AudioPP_Equalizer_IsEnable( void ) {return KAL_FALSE;}

// For Audio Compensation Filter
void Media_SetAudioCompensation(Media_Aud_Comp_Mode mode, kal_int16 *coeff) {}
void Audio_Compensation_Activate( kal_bool rampup ) {}

// For Hardware FIR
void Audio_HW_FIR_Reset( void ) {}

