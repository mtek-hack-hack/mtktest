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
 * ProfilesDefs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends forSettings application definitions
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : ProfilesDefs.h

   PURPOSE     : Settings application definitions

   REMARKS     : nil

   AUTHOR      : Ashima Bajaj

   DATE     : 

**************************************************************/

#ifndef _PIXCOM_PROFILESDEFS_H
#define _PIXCOM_PROFILESDEFS_H
#define VIB_THEN_RING_DURATION 6000

/* MTK robin 1119, AT command set wallpaper and profile */
#define MAX_PROFILE_NUM 7

#ifdef __MMI_VIDEO_CALL_TONE__

#ifdef __MMI_DUAL_PROFILE_SUPPORT__
#define STR_TONE_SETUP_RING_TONE_DEF STR_TONE_SETUP_SIM1_VOICE_RING_TONE
#define STR_TONE_SETUP_SIM2_RING_TONE_DEF STR_TONE_SETUP_SIM2_VOICE_RING_TONE
#define STR_PROFILES_RING_TONE_SETUP_CAPTION_DEF STR_PROFILES_SIM1_VOICE_RING_TONE_SETUP_CAPTION
#define STR_PROFILES_SIM2_RING_TONE_SETUP_CAPTION_DEF STR_PROFILES_SIM2_VOICE_RING_TONE_SETUP_CAPTION
#else /*__MMI_DUAL_PROFILE_SUPPORT__*/
#define STR_TONE_SETUP_RING_TONE_DEF STR_TONE_SETUP_VOICE_RING_TONE
#define STR_PROFILES_RING_TONE_SETUP_CAPTION_DEF STR_PROFILES_VOICE_RING_TONE_SETUP_CAPTION
#endif /*__MMI_DUAL_PROFILE_SUPPORT__*/

#else /*__MMI_VIDEO_CALL_TONE__*/

#ifdef __MMI_DUAL_PROFILE_SUPPORT__
#define STR_TONE_SETUP_RING_TONE_DEF STR_TONE_SETUP_SIM1_RING_TONE
#define STR_TONE_SETUP_SIM2_RING_TONE_DEF STR_TONE_SETUP_SIM2_RING_TONE
#define STR_PROFILES_RING_TONE_SETUP_CAPTION_DEF STR_PROFILES_SIM1_RING_TONE_SETUP_CAPTION
#define STR_PROFILES_SIM2_RING_TONE_SETUP_CAPTION_DEF STR_PROFILES_SIM2_RING_TONE_SETUP_CAPTION
#else /*__MMI_DUAL_PROFILE_SUPPORT__*/
#define STR_TONE_SETUP_RING_TONE_DEF STR_TONE_SETUP_RING_TONE
#define STR_PROFILES_RING_TONE_SETUP_CAPTION_DEF STR_PROFILES_RING_TONE_SETUP_CAPTION
#endif /*__MMI_DUAL_PROFILE_SUPPORT__*/

#endif /*__MMI_VIDEO_CALL_TONE__*/



#ifdef __MMI_DUAL_PROFILE_SUPPORT__
#define STR_TONE_SETUP_MESSAGE_TONE_DEF STR_TONE_SETUP_SIM1_MESSAGE_TONE
#define STR_MESSAGE_TONE_CAPTION_DEF STR_SIM1_MESSAGE_TONE_CAPTION
#define STR_SIM2_MESSAGE_TONE_CAPTION_DEF STR_SIM2_MESSAGE_TONE_CAPTION
#else
#define STR_TONE_SETUP_MESSAGE_TONE_DEF STR_TONE_SETUP_MESSAGE_TONE
#define STR_MESSAGE_TONE_CAPTION_DEF STR_MESSAGE_TONE_CAPTION
#endif


typedef enum
{
    TONE_RINGTONE,
    TONE_POWEROFFTONE,
    TONE_POWERONTONE,
    TONE_CONVEROPENTONE,
    TONE_COVERCLOSETONE,
    TONE_MESSAGETONE,
    TONE_KEYPADTONE,
    TONE_ALARMTONE,

    TONE_MAX_TONE_TYPE
} PROFILE_TONE_TYPE_ENUM;

/* MTK end */

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__

typedef enum
{

    PRF_MENU_EXTMLD_DONE,
    PRF_MENU_EXTMLD_DEL,
    PRF_MENU_EXTMLD_ADD,

    PRF_MENU_EXTMLD_MAX
} PRF_SET_EXTMLD_MENU_ITEM;

typedef enum
{

    PRF_MENU_EXTMLD_DRV_PHONE,
    PRF_MENU_EXTMLD_DRV_CARD,

    PRF_MENU_EXTMLD_DRV_MAX
} PRF_SET_EXTMLD_DRV_MENU_ITEM;

#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

typedef enum
{
    PRFSET_MELODY_TYPE_UNKNOW,
    PRFSET_MELODY_TYPE_RING,
    PRFSET_MELODY_TYPE_CARD2_RING,
    PRFSET_MELODY_TYPE_ALARM,
    PRFSET_MELODY_TYPE_PHB_RING,
    PRFSET_MELODY_TYPE_ENGINEERMODE,
    PRFSET_MELODY_TYPE_VIDEO_CALL,

    PRFSET_MELODY_TYPE_MAX
} PRFSET_MELODY_CONF_TYPE;

typedef enum
{
    MMI_PROFILES_BT_HFP_ACL,
    MMI_PROFILES_BT_HFP_SCO
} MMI_PROFILES_BT_CONNECT_TYPE_ENUM;

typedef enum
{
    MMI_PROFILES_BT_IND,
    MMI_PROFILES_BT_RSP,
    MMI_PROFILES_BT_REQ
} MMI_PROFILES_BT_IND_TYPE_ENUM;

typedef enum
{
    MMI_PROFILES_BT_OK,
    MMI_PROFILES_BT_FAIL,
    MMI_PROFILES_BT_TIMEOUT,
    MMI_PROFILES_BT_BUSY
} MMI_PROFILES_BT_RES_ENUM;

#endif /* _PIXCOM_PROFILESDEFS_H */ 

