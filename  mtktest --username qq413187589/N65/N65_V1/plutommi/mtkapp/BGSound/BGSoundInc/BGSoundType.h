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
 * BGSoundType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_BGSOUNDTYPE_H
#define _MMI_BGSOUNDTYPE_H

#include "MMI_features.h"

#ifdef __MMI_BG_SOUND_EFFECT__

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/* 
 * Define
 */
#define BGSND_MAX_EFFECT      5
#define BGSND_MAX_EXT_EFFECT  10        /* Shall same as "NVRAM_EF_BGSND_FILEPATH_TOTAL" in "nvram_user_defs.h" */
#define BGSND_TOTAL_EFFECT    (BGSND_MAX_EFFECT+BGSND_MAX_EXT_EFFECT)

#define BGSND_HIGHLIGHT_TIMER_DUR   500

#define BGSND_MAX_INTERVAL 120
#define BGSND_MIN_INTERVAL    1
#define BGSND_MAX_VOLUME      7
#define BGSND_DEFAULT_VOLUME  5

#define BGSND_INTERVAL_LEN 4    /* "1 ~ 120" */
#define BGSND_VOLUME_LEN      2 /* "0 ~ 7" */

/* 
 * Typedef 
 */
typedef struct
{
    U8 status;
    U8 play_type;
    U16 interval_sec;
    U8 volume;
    U8 curr_effect;
} bgsnd_cs_nvram_struct;

typedef struct
{
    bgsnd_cs_nvram_struct set;  /* call setup */
    bgsnd_cs_nvram_struct cm;   /* call manage (In call) */

    BOOL is_init;

#ifndef __UCM_SUPPORT__
    BOOL is_mt_call_select;
    BOOL is_mo_call_select;
    MMI_BOOL is_speech_on;      /* check if speech on */
    MMI_BOOL is_request_play;   /* check if user request to play while speech off */
#endif /* __UCM_SUPPORT__ */
    
    BOOL setup_playing;         /* To keep playing status in the phone setup menu */

    BOOL file_exist;  /* check if file exist */
#ifdef __DRM_SUPPORT__
    U8 current_function_status;/*distinguishing on setting or not*/
    BOOL drm_permission_state;
#endif
} bgsnd_context_struct;

/* 
 * Extern Global Variable
 */
extern bgsnd_context_struct g_bgsnd_cntx;

/* 
 * Extern Global Function
 */

#endif /* __MMI_BG_SOUND_EFFECT__ */ 
#endif /* _MMI_BGSOUNDTYPE_H */ 

