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
 * SoundRecorderDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
 *============================================================================
 ****************************************************************************/
#ifndef SOUND_RECORDER_DEF_H
#define SOUND_RECORDER_DEF_H

#include "gui_data_types.h"
#include "SoundRecorderResDef.h"

// #define MAX_FILE_NAME_LEN 128
#define MAX_FILE_NAME_LEN 80
// #define MAX_PATH_LEN 128
#define MAX_PATH_LEN 16 /* because its path is fixed. i.e "c:\audio\" */
#define MAX_FULL_NAME_LEN (MAX_PATH_LEN+MAX_FILE_NAME_LEN)
#define NO_OF_LIST_ENTRIES 60

#define MAX_INPUT_FILE_LEN  35  /* max file length for user to input */
#define MAX_FILE_EXT_LEN 5      /* max file extension length */

#define MAX_STORAGE_PATH_LEN  20
#define STORAGE_PATH_PHONE (L"Audio")
#define STORAGE_PATH_CARD (L"Audio")

#define FILE_EXT_AMR (L".amr")
#define FILE_EXT_WAV (L".wav")
#define FILE_EXT_AWB (L".awb")
#define FILE_EXT_VM (L".vm")
/*add sim mark in file name*/
#define MMI_SNDREC_SIM_ONE_CAPTION (L"SIM1_")
#define MMI_SNDREC_SIM_TWO_CAPTION (L"SIM2_")

#define SNDREC_FILE_FILTER  FMGR_TYPE_WAV|FMGR_TYPE_AMR|FMGR_TYPE_VM

#define AMR_HIGH_BIT_RATE 1660
#define WAV_HIGH_BIT_RATE 8110
#define AWB_HIGH_BIT_RATE 2981
#define VM_HIGH_BIT_RATE 1700

#ifndef MAX_VOL_LEVEL
#define MAX_VOL_LEVEL 7
#endif 

#define RANDOM_POS   (8)

#endif /* SOUND_RECORDER_DEF_H */ 

