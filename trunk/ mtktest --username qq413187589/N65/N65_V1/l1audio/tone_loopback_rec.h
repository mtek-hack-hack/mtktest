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
 * tone_loopback_rec.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Tone Loop Back Recording
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __L1_STANDALONE__ // avoid link error
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#endif // #ifndef __L1_STANDALONE__

/* global includes */
#include "l1audio.h"

#ifndef __L1_STANDALONE__ // avoid link error
#include "device.h"
#include "resource_audio.h"
#include "custom_equipment.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#endif // #ifndef __L1_STANDALONE__

#include "afe.h"

#define DPRAM_base(a)    ((volatile kal_uint16*)0x50000000+(a))
#define DPRAM2_base(a)   ((volatile kal_uint16*)0x58000000+(a))

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)

#define DP_SP_CODEC_CTRL_base(a)             (DPRAM2_base(0x105)+(a))
#define DP_SP_AUDIO_INTERFACE_CTRL_base(a)   (DP_SP_CODEC_CTRL_base(0x09)+(a))

#else // #if defined(MT6229) || defined(MT6230) || defined(MT6268T)

#define DP_SP_CODEC_CTRL_base(a)             (DPRAM_base(0x62)+(a))
#define DP_SP_AUDIO_INTERFACE_CTRL_base(a)   (DPRAM_base(0x6B)+(a))

#endif // #if defined(MT6229) || defined(MT6230) || defined(MT6268T)

#define DP_VOL_OUT_PCM        DP_SP_AUDIO_INTERFACE_CTRL_base(0)
#define DP_VOL_IN_PCM         DP_SP_AUDIO_INTERFACE_CTRL_base(5)  /* gain on PCM input */

#define DP_AUDIO_PAR          DP_SP_AUDIO_INTERFACE_CTRL_base(1)

#define TLBR_STATE_IDLE  0
#define TLBR_STATE_INIT  1
#define TLBR_STATE_REC   2

#define BYTES_PER_FRAME  320
#define KT_AMP           0x3FFF
#define HW_AGC_SETTING     0x460F

#define VOICE_INPUT_FILTER_FLAG     0x1 
#define VOICE_OUTPUT_FILTER_FLAG    0x2

typedef struct{
   kal_uint8 *pBuf;
   kal_uint32 uSize;
   kal_uint8  bAnalogSpkGain;
   kal_uint8  uAnalogMicGain;
   kal_uint16 uFreq;
   kal_uint16 uUL_DigGain;
   kal_uint16 uDL_DigGain;
   kal_uint16 uKT_AMP;
}ToneLBR_Para;
