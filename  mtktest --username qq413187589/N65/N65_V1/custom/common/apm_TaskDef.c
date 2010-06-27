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
 *   apm_TaskDef.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Defination of hooked process for Audio Post Process Manager
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
 * removed!
 * removed!
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

#ifndef __MAUI_BASIC__

#include "l1audio_def.h"
#include "APM_Task.h"

#if APM_SUPPORT

#if defined(AUD_REVERB)
const APM_TASK_PARA Reverb = {
   APM_TASKID_REVERB,
   APM_PROPERTY_READ_WRITE,
   0,
   16580,
   AudioPP_Reverb_Init,
   AudioPP_Reverb_Activate,
   AudioPP_Reverb_Deactivate,
   AudioPP_Reverb_ProcessData
};
#endif
#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
const APM_TASK_PARA Surround = {
   APM_TASKID_SURROUND,
   APM_PROPERTY_READ_WRITE,
   0,
   16580,
   AudioPP_Surround_Init,
   AudioPP_Surround_Activate,
   AudioPP_Surround_Deactivate,
   AudioPP_Surround_ProcessData
};
#endif

#if defined(AUDIO_EQUALIZER_ENABLE) && !defined(MT6225)
const APM_TASK_PARA Equalizer = {
   APM_TASKID_EQ,
   APM_PROPERTY_READ_WRITE,
   0,
   16580,
   AudioPP_AEQ_Init,
   AudioPP_AEQ_Activate,
   AudioPP_AEQ_Deactivate,
   AudioPP_AEQ_Process
};
#endif

const APM_TASK_PARA AudioGainControl = {
   APM_TASKID_AGC,
   APM_PROPERTY_READ_WRITE,
   1,
   0,
   AudioPP_AGC_Init,
   AudioPP_AGC_Activate,
   AudioPP_AGC_Deactivate,
   AudioPP_AGC_ProcessData
};

#if defined(__BT_A2DP_PROFILE__)
const APM_TASK_PARA SBC_Analyzer = {
   APM_TASKID_SBC,
   APM_PROPERTY_READ_ONLY,
   2,
   1632,
   sbc_Init,
   sbc_Activate,
   sbc_Deactivate,
   sbc_Process
};
#endif


#if defined( __BT_AUDIO_VIA_SCO__ )
const APM_TASK_PARA AudViaBt = {
   APM_TASKID_AVB,
   APM_PROPERTY_READ_ONLY,
   2,
   3200,
   avb_Init,
   avb_Activate,
   avb_Deactivate,
   avb_Process
};
#endif

const APM_TASK_PARA SPT_Analyzer = {
   APM_TASKID_SPT,
   APM_PROPERTY_READ_ONLY,
   3,
   0,
   NULL,
   spt_Activate,
   spt_Deactivate,
   spt_Process
};


// The order of process is as the sequence of Task list
// The first task will be processed at first
const APM_TASK_PARA *apmTaskList[] = {
#if defined(AUD_REVERB)
   &Reverb,
#endif
#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
   &Surround,
#endif   
#if defined(AUDIO_EQUALIZER_ENABLE) && !defined(MT6225)
   &Equalizer,
#endif
   &AudioGainControl,
#if defined(__BT_A2DP_PROFILE__)
   &SBC_Analyzer,
#endif
#if defined( __BT_AUDIO_VIA_SCO__ )
   &AudViaBt,
#endif
   &SPT_Analyzer,
   NULL
};
#endif

#endif
