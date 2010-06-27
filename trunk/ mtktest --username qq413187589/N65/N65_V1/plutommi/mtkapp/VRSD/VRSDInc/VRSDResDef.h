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
 * VRSDEnum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Enum Value of voice recognition.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VRSDRESDEF_H
#define _MMI_VRSDRESDEF_H

/* if some header should be include before this one */
#include "MMIDataType.h"

/* 
 * Typedef 
 */
typedef enum
{
    /* Main Menu */
    SCR_ID_VRSD_MAIN_MENU = VRSD_BASE + 1,
    SCR_ID_VRSD_RECV_VOICE,
    SCR_ID_VRSD_RCG_FOUND,
    /* Voice Dial */
    SCR_ID_VRSD_DIAL_EMPTY_LIST,
    SCR_ID_VRSD_DIAL_MAIN_MENU,
    /* Voice Profile */
    SCR_ID_VRSD_PROFILE_MAIN_MENU,
    /* Voice Shortcut */
    SCR_ID_VRSD_SHORTCUT_LIST,
    SCR_ID_VRSD_SHORTCUT_OPTION,
    /* Delete All */
    SCR_ID_VRSD_DELETE_ALL,
    /* Tag Status */
    SCR_ID_VRSD_STATUS
} vrsd_scr_id_enum;

typedef enum
{
    STR_ID_VRSD_APP = VRSD_BASE + 1,
    STR_ID_VRSD_RCG,
    STR_ID_VRSD_DIAL,       /* This string ID should not change position. */
    STR_ID_VRSD_REDIAL,     /* This string ID should not change position. */
    STR_ID_VRSD_PROFILE,    /* This string ID should not change position. */
    STR_ID_VRSD_AUD_PLAYER, /* This string ID should not change position. */
    STR_ID_VRSD_SHORTCUT,   /* This string ID should not change position. */
    STR_ID_VRSD_TAG_STATUS,
    STR_ID_VRSD_CHANGE,
    STR_ID_VRSD_VOICE_IN,
    STR_ID_VRSD_VOICE_IN_AGAIN,
    STR_ID_VRSD_NO_TAG_EXIST,
    STR_ID_VRSD_NO_EMPTY_TAG,
    STR_ID_VRSD_RECV_VOICE_FAIL,
    STR_ID_VRSD_NO_SOUND,
    STR_ID_VRSD_NO_MATCH,
    STR_ID_VRSD_TOO_SIMILAR,
    STR_ID_VRSD_TOO_DIFFERENT,
    STR_ID_VRSD_DISC_FULL,
    STR_ID_VRSD_SPEAK_TOO_LONG,
    STR_ID_VRSD_SPEAK_TOO_SHORT,
    STR_ID_VRSD_WRONG_SESSION,
    /* Voice Dial */
    STR_ID_VRSD_DIAL_REFRESH_SIM,
    STR_ID_VRSD_DIAL_FOUND,
    STR_ID_VRSD_DIAL_AUTO_DIAL,
    /* Voice Redial */
    STR_ID_VRSD_REDIAL_CALLLOG_EMPTY,
    /* Profile */
    STR_ID_VRSD_PROFILE_SILENT,
    STR_ID_VRSD_PROFILE_CANNOT_SWITCH
} vrsd_str_id_enum;

typedef enum
{
    IMG_ID_VRSD_APP = VRSD_BASE + 1,
    IMG_ID_VRSD_RECORDING
} vrsd_img_id_enum;

/* 
 * Define
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#endif /* _MMI_VRSDRESDEF_H */ /* #ifndef _MMI_VRSDRESDEF_H */

