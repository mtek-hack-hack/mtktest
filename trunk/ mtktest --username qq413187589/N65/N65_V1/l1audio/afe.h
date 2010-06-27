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
 *   Audio Front End
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *******************************************************************************/
#ifndef AFE_H
#define AFE_H

void AFE_Init( void );
void AFE_TurnOn8K( void );
void AFE_TurnOff8K( void );
void AFE_TurnOff8K_Direct( void );
void AFE_TurnOnAudioClock( kal_uint8 clock );
void AFE_TurnOffAudioClock( void );
void AFE_TurnOnWTDMA( void );
void AFE_TurnOffWTDMA( void );
void AFE_TurnOnAudioPower( void );  // For hardware equalizer
void AFE_TurnOnDAI( void );
void AFE_TurnOffDAI( void );
void AFE_TurnOnSpeaker( kal_uint8 aud_func );
void AFE_TurnOffSpeaker( kal_uint8 aud_func );
void AFE_MuteSpeaker( kal_uint8 aud_func, kal_bool mute );
void AFE_TurnOnLoopback( void );
void AFE_TurnOffLoopback( void );
void AFE_TurnOnExtAmplifier( void );
void AFE_TurnOffExtAmplifier( void );

void AFE_SetInputSource( kal_uint8 src );
kal_uint8 AFE_GetInputSource( void );
void AFE_SetMicrophoneVolume( kal_uint8 mic_volume );
kal_uint8 AFE_GetMicrophoneVolume( void );
void AFE_TurnOnMicrophone( kal_uint8 aud_func );
void AFE_TurnOffMicrophone( kal_uint8 aud_func );
kal_bool AFE_IsMicrophoneOn( kal_uint8 aud_func );
void AFE_MuteMicrophone( kal_bool mute );
kal_bool AFE_IsMicrophoneMuted( void );

void AFE_SetSidetoneVolume( kal_uint8 sidetone );
void AFE_SetSidetone( kal_bool ec );
kal_uint8 AFE_GetSidetoneVolume( void );

void AFE_SetOutputDevice( kal_uint8 aud_func, kal_uint8 device );
kal_uint8 AFE_GetOutputDevice( kal_uint8 aud_func );
void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index );
void AFE_GetOutputVolume( kal_uint8 aud_func, kal_uint8 *volume1, kal_int8 *digital_gain_index );
void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level );
void AFE_TurnOnFIR( kal_uint8 aud_func );
void AFE_TurnOffFIR( kal_uint8 aud_func );
kal_bool  AFE_IsFIROn( kal_uint8 aud_func );

void AFE_Manager( void );

kal_uint8 AFE_TurnOnMicBias( void );
void AFE_TurnOffMicBias( void ); 

void AFE_TurnOnBluetooth( kal_uint16 param );
void AFE_TurnOffBluetooth( void );

void AFE_Initialize( void );
void AFE_SwitchExtAmplifier( kal_bool sw_on );

void AFE_Refresh( void );

void AFE_Mute( kal_bool mute );
void AFE_SetSamplingRate( kal_uint32 freq );
void AFE_SetHardwareMute( kal_bool mute );
void AFE_SetLevelVolume( kal_uint8 aud_func, kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level );

void AFE_EnableToneLoopBackFlag( kal_bool param );

kal_bool AFE_IsAudioLoudSpk( void );

#endif

