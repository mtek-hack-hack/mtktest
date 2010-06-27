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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   med_v_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Media-v task related message identity definition
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

   /*------------------------MED_V_MSG_CODE_BEGIN ---------------*/
MSG_ID_MEDIA_VISUAL_RECORD_REQ = MSG_ID_MED_V_CODE_BEGIN,
    MSG_ID_MEDIA_VISUAL_RECORD_CNF,
    MSG_ID_MEDIA_ENCODE_VISUAL_DATA_IND,
    MSG_ID_MEDIA_ENCODE_META_DATA_IND,
    MSG_ID_MEDIA_VISUAL_RECORD_FINISH_IND,
    MSG_ID_MEDIA_VISUAL_STOP_REQ,
    MSG_ID_MEDIA_VISUAL_STOP_CNF,
    MSG_ID_MEDIA_VISUAL_PLAY_REQ,
    MSG_ID_MEDIA_VISUAL_PLAY_CNF,
    MSG_ID_MEDIA_DECODE_VISUAL_DATA_IND,
    MSG_ID_MEDIA_VISUAL_PLAY_FINISH_IND,
    MSG_ID_MEDIA_VISUAL_SEEK_REQ,
    MSG_ID_MEDIA_VISUAL_SEEK_CNF,
    MSG_ID_MEDIA_VISUAL_FILE_MERGE_REQ,
    MSG_ID_MEDIA_VISUAL_FILE_MERGE_CNF,
    MSG_ID_MEDIA_VISUAL_TEMP_1, MSG_ID_MEDIA_VISUAL_TEMP_2, 
    MSG_ID_MEDIA_AUDIO_START_BUILD_CACHE_REQ,
    MSG_ID_MEDIA_AUDIO_STOP_BUILD_CACHE_REQ,
    MSG_ID_MEDIA_AUDIO_CLOSE_BUILD_CACHE_REQ,
    MSG_ID_MEDIA_AUDIO_PROCESS_BUILD_CACHE_REQ,
    MSG_ID_MEDIA_AUDIO_RESET_BUILD_CACHE_VARS_REQ,
    MSG_ID_MEDIA_AUDIO_BUILD_CACHE_FAIL_IND,
    MSG_ID_MEDIA_V_AUDIO_START_RECORD_REQ,
    MSG_ID_MEDIA_V_AUDIO_STOP_RECORD_REQ,
    MSG_ID_MEDIA_V_AUDIO_STOP_RECORD_CNF,
    MSG_ID_MEDIA_V_AUDIO_PAUSE_RECORD_REQ,
    MSG_ID_MEDIA_V_AUDIO_PAUSE_RECORD_CNF,
    MSG_ID_MEDIA_V_AUDIO_RESUME_RECORD_REQ,
    MSG_ID_MEDIA_V_AUDIO_RESUME_RECORD_CNF,    
    MSG_ID_MEDIA_V_AUDIO_READ_DATA_IND,
    MSG_ID_MEDIA_V_AUDIO_RECORD_ERROR_IND,    
    MSG_ID_MED_V_CODE_END = MSG_ID_MEDIA_V_AUDIO_RECORD_ERROR_IND,
   /*------------------------MED_V_MSG_CODE_END -----------------*/

