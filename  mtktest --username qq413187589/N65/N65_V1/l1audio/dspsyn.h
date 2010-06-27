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
 * dspsyn.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   DSP Wavetable Synthesizer Driver
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef __DSPSYN_H__
#define __DSPSYN_H__

#if !defined( DSP_WT_SYN )
   #error dspsyn.h should not be included unless DSP_WT_SYN is defined.
#endif

#include "media.h"

#define  MAX_MIDI_PLAYERS        4
#define  MAX_TONE_PLAYERS        4
#define  MAX_WAV_PLAYERS         4

#define  DSPSYN_MIDI_STATE       0x0001       /* 0x0001|0x0002|0x0004|0x0008 are reserved for SMF  */
#define  DSPSYN_TONE_STATE       0x0010       /* 0x0010|0x0020|0x0040|0x0080 are reserved for TONE */
#define  DSPSYN_WAV_STATE        0x0100       /* 0x0100|0x0200|0x0400|0x0800 are reserved for WAV  */

#define  DSPSYN_MIDI_MASK        0x000F
#define  DSPSYN_TONE_MASK        0x00F0
#define  DSPSYN_WAV_MASK         0x0F00

#define  DSPSYN_CMD_NO_DATA      0x0000
#define  DSPSYN_CMD_CONTINUE     0xFFFD
#define  DSPSYN_CMD_STOP         0xFFFE
#define  DSPSYN_CMD_END          0xFFFF

#define  MAX_TRACK               32
#define  MAX_POLYPHONY           64
#define  MAX_CHANNEL             20
#define  MIDI_CHANNEL            0
#define  TONE_CHANNEL            16
#define  WAV_CHANNEL             20

#define CHANNEL_FLAG_MUTE        0x01
#define CHANNEL_FLAG_MONO        0x02
#define CHANNEL_FLAG_VIBE        0x04
#define CHANNEL_FLAG_ACTIVE      0x08

typedef struct {
   int16    bank;
   int16    pitchsens;
   int8     program;
   int8     volume;
   uint8    flag;
   uint8    dspChannel;
} MidiChannel;

void  DSPSYN_Init( void );
void  DSPSYN_SetEvent( Media_Event event );
void  DSPSYN_ResetMIDI( uint16 start, uint16 count );
MidiChannel *DSPSYN_GetMidiChannel( bool perc );
void  DSPSYN_FreeMidiChannel( MidiChannel *channel );

void  DSPSYN_Start( Media_Handle *handle, void (*end)(Media_Handle *handle),
                        void (*getCmd)(Media_Handle *handle,uint16 *dtime,uint16 cmd[4]), bool reset );
void DSPSYN_ReleaseHandle( Media_Handle *handle );

Media_Handle *DSPSYN_ObtainSmfHandle( void );
#define  DSPSYN_ReleaseSmfHandle    DSPSYN_ReleaseHandle
#define  DSPSYN_SMF_Start           DSPSYN_Start

Media_Handle *DSPSYN_ObtainWavHandle( void );
#define  DSPSYN_ReleaseWavHandle    DSPSYN_ReleaseHandle
#define  DSPSYN_WAV_Start           DSPSYN_Start

Media_Handle *DSPSYN_ObtainToneHandle( void );
#define  DSPSYN_ReleaseToneHandle   DSPSYN_ReleaseHandle
#define  DSPSYN_TONE_Start          DSPSYN_Start

bool DSPSYN_APM_Ending( void );

#endif


