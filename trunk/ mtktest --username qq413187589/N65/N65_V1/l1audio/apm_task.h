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
 *   APM_Task.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Definition of external APM Task interface
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "l1audio_def.h"

#if APM_SUPPORT

#ifndef APM_TASK_DOT_H
#define APM_TASK_DOT_H

// Reverberation
#if defined(AUD_REVERB)
extern kal_bool AudioPP_Reverb_ProcessData(APM_Buffer *buf, APM_Info *info);
extern void AudioPP_Reverb_Activate(APM_Info *info);
extern void AudioPP_Reverb_Deactivate(void);
extern void AudioPP_Reverb_Init(APM_TCM *tcm);
#endif
// 3D Surround
#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
extern kal_bool AudioPP_Surround_ProcessData(APM_Buffer *buf, APM_Info *info);
extern void AudioPP_Surround_Activate(APM_Info *info);
extern void AudioPP_Surround_Deactivate(void);
extern void AudioPP_Surround_Init(APM_TCM *tcm);
#endif

// Equalizer
#if defined(AUDIO_EQUALIZER_ENABLE) && !defined(MT6225)
extern void AudioPP_AEQ_Init(APM_TCM *tcm);
extern void AudioPP_AEQ_Activate(APM_Info *info);
extern void AudioPP_AEQ_Deactivate(void);
extern kal_bool AudioPP_AEQ_Process(APM_Buffer *buf, APM_Info *info);
#endif

// Automatic Gain Control
extern kal_bool AudioPP_AGC_ProcessData(APM_Buffer *buf, APM_Info *info);
extern void AudioPP_AGC_Activate(APM_Info *info);
extern void AudioPP_AGC_Deactivate(void);
extern void AudioPP_AGC_Init(APM_TCM *tcm);

// SBC Task
#if defined(__BT_A2DP_PROFILE__)
extern void sbc_Init(APM_TCM *tcm);
extern void sbc_Activate(APM_Info *info);
extern void sbc_Deactivate(void);
extern kal_bool sbc_Process(APM_Buffer *buf, APM_Info *info);
#endif

// AvBT
#if defined( __BT_AUDIO_VIA_SCO__ )
extern void avb_Init(APM_TCM *tcm);
extern void avb_Activate(APM_Info *info);
extern void avb_Deactivate(void);
extern kal_bool avb_Process(APM_Buffer *buf, APM_Info *info);
#endif

// Spectrum display
extern void spt_Init(APM_TCM *tcm);
extern void spt_Activate(APM_Info *info);
extern void spt_Deactivate(void);
extern kal_bool spt_Process(APM_Buffer *buf, APM_Info *info);

#endif   // end APM_TASK_DOT_H
#endif   // end APM_SUPPORT
