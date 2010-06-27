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
 *	afe.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Audio Manager
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
 *******************************************************************************/
#ifndef AM_H
#define AM_H

#include "l1audio_def.h"

#define  ASP_TYPE_VOICE       0
#define  ASP_TYPE_PCM_HI      1
#define  ASP_TYPE_MELODY_16K  2
#define  ASP_TYPE_DAF         3
#define  ASP_TYPE_AAC         32
#define  ASP_TYPE_AWBDEC      64
#define  ASP_TYPE_WMA         128
#define  ASP_TYPE_AACPLUS           256
#define  ASP_TYPE_AACPLUS_PS    512
#define  ASP_TYPE_AMR         1024
#define  ASP_TYPE_MUSICAM     2048     
#define  ASP_TYPE_BSAC        4096
#define  ASP_TYPE_AWB_PLUS    8192

#define  ASP_FS_8K            0x00
#define  ASP_FS_11K           0x11
#define  ASP_FS_12K           0x12
#define  ASP_FS_16K           0x20
#define  ASP_FS_22K           0x21
#define  ASP_FS_24K           0x22
#define  ASP_FS_32K           0x40
#define  ASP_FS_44K           0x41
#define  ASP_FS_48K           0x42

#define  PP_3D_MASK           0x001E
#define  PP_TS_MASK           0x002E
#define  PP_SBC_MASK          0x0040

void     AM_Init( void );
bool     AM_AudioManager( bool handover,uint16 speech_mode, int8 sub_channel );
void     AM_FlushQFunction( void );
void     AM_FillSilencePattern( volatile uint16 *addr, uint16 info, uint16 speech_mode );
uint16   AM_GetSpeechPatternLength( uint8 speech_mode );
void     AM_SpeechOn(uint32 rat_mode);
void     AM_SpeechOff( void );
bool     AM_IsSpeechOn( void );
void     AM_SetDAIMode ( uint8 mode );
bool     AM_IsDAIMode( void );
void     AM_WriteFirCoeffs( const int16 *in_coeff, const int16 *out_coeff );
void     AM_VMRecordOn( uint16 speech_mode );
void     AM_VMRecordOff( void );
void     AM_VMPlaybackOn( uint16 control, uint32 style );
void     AM_VMPlaybackOff( uint32 style );
void     AM_VMWriteParameter(uint16 sc_mode, uint16 sd_mode, bool isReset);
void     AM_MelodyOn( void );
void     AM_MelodyOff( void );
void     AM_KeyToneOn( void );
void     AM_KeyToneOff( void );
void     AM_ToneOn( void );
void     AM_ToneOff( void );
void     AM_PCM8K_PlaybackOn( void );
void     AM_PCM8K_PlaybackOff( bool wait );
void     AM_PCM16K_PlaybackOn( void );       /* PCM16K is for MT6205B only */
void     AM_PCM16K_PlaybackOff( bool wait );
void     AM_PCM8K_RecordOn( void );
void     AM_PCM8K_RecordOff( bool wait );
void     AM_PCM16K_RecordOn( void );         /*PCM16K recording support 6219 and latter version*/
void     AM_PCM16K_RecordOff( bool wait );
void     AM_AudioPlaybackOn( uint16 asp_type, uint16 asp_fs );
void     AM_AudioPlaybackOff( bool wait );
int16    AM_IsAudioPlaybackOn( void );
bool     AM_IsVMPlaybackOn( void );
void     AM_VRRecordOn( uint32 trainPhase );
void     AM_VRRecordOff( uint32 trainPhase );
void     AM_MuteULSpeech( bool mute );
bool     AM_IsULSpeechMuted( void );
void     AM_PCM_EX_On( uint32 type );
void     AM_PCM_EX_Off( uint32 type );
bool     AM_IsVoIPOn( void );
bool     AM_IsConflictState( void );
void     AM_EnterSpeechOff();
void     AM_LeaveSpeechOff();

// Bluetooth earphone control functions
void     AM_BluetoothOn( uint8 bt_mode);
void     AM_BluetoothOff( void );
bool     AM_IsBluetoothOn( void );
bool     AM_IsBTCordlessMode( void );

// Bluetooth cordkess mode control functions
void     AM_BTCordlessOn( void );
void     AM_BTCordlessOff( void );

// Sound effect control functions
void     AM_SND_PlaybackOn( void );
void     AM_SND_PlaybackOff( bool wait );

// Audio Post Process control functions
void     AM_SetPostProcessCtrl( uint16 ppMask, uint16 ppCtrl );
void     AM_ClearPostProcessCtrl( uint16 ppMask );

// Functions for modem loopback test 
void     AM_SetLoopBackTest( bool enable );
bool     AM_IsLoopBackTest( void );

void     AM_EnableToneLoopBackFlag( kal_bool param );

#endif


