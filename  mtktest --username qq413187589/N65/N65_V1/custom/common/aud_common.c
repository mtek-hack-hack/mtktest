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
 * aud_common.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   Common Audio Customization Parameters 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "audcoeff_default.h"

/* SW_SYN_8K | SW_SYN_16K : Maximum Amplitude of MCU Software Synthesizer  */
const unsigned short Media_Playback_Maximum_Swing   = 12800;

/* DSP_WT_SYN Melody Compensation Filter  */ 
const signed short Melody_FIR[25] = 
{ 
   -21,  -269,     7,   141,  -326,  -203,   257,  -396,  -472,  1323, 
   192, -6458, 15256, -6458,   192,  1323,  -472,  -396,   257,  -203, 
  -326,   141,     7,  -269,   -21 
};

/*
 * Speech Enhancement Parameter
 * Refer to audcoeff_default.h
 */
const unsigned short Speech_Normal_Mode_Para[8] = DEFAULT_SPEECH_NORMAL_MODE_PARA;
const unsigned short Speech_Earphone_Mode_Para[8] = DEFAULT_SPEECH_EARPHONE_MODE_PARA;
const unsigned short Speech_LoudSpk_Mode_Para[8] = DEFAULT_SPEECH_LOUDSPK_MODE_PARA;
const unsigned short Speech_BT_Earphone_Mode_Para[8] = DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA;
const unsigned short Speech_BT_Cordless_Mode_Para[8] = DEFAULT_SPEECH_BT_CORDLESS_MODE_PARA;
const unsigned short Speech_AUX1_Mode_Para[8] = DEFAULT_SPEECH_AUX1_MODE_PARA;
const unsigned short Speech_AUX2_Mode_Para[8] = DEFAULT_SPEECH_AUX2_MODE_PARA;
const unsigned short Speech_AUX3_Mode_Para[8] = DEFAULT_SPEECH_AUX3_MODE_PARA;

#if defined(AUD_REVERB)                                                        
/*                                                                             
 * Audio Post Process Parameter - Reverb Sound Effect                          
 * Refer to audcoeff_default.h                                                 
 */                                                                            
const short Table_Reverb_Concert[66] = DEFAULT_TABLE_Reverb_CONCERT;       
const short Table_Reverb_Shower[66] = DEFAULT_TABLE_Reverb_SHOWER;         
const short Table_Reverb_Church[66] = DEFAULT_TABLE_Reverb_CHURCH;         
const short Table_Reverb_SmallRoom[66] = DEFAULT_TABLE_Reverb_SMALLROOM;   
const short Table_Reverb_Opera[66] = DEFAULT_TABLE_Reverb_OPERA;           
const short Table_Reverb_BathRoom[66] = DEFAULT_TABLE_Reverb_BATHROOM;     
                                                                               
const short *audio_Reverb_effect_table[6] =                                
{                                                                              
	Table_Reverb_Concert,                                                       
	Table_Reverb_Shower,                                                        
	Table_Reverb_Church,                                                        
	Table_Reverb_SmallRoom,                                                     
	Table_Reverb_Opera,                                                         
	Table_Reverb_BathRoom                                                       
};                                                                             
                                                                               
#endif /* AUD_REVERB */

#ifdef AUDIO_COMPENSATION_ENABLE
/* Audio Compensation Filter */
const signed short Audio_Compensation_Filter[2][45] = 
{ 
    { /* 0: Compensation Filter for Normal mode */
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0 
    },
    { /* 0: Compensation Filter for Headset mode */
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0 
    }
};
#endif /* AUDIO_COMPENSATION_ENABLE */

