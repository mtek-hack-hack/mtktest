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
 *  UCMGProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_GPROT_H
#define UCM_GPROT_H

typedef enum
{
    MMI_UCM_FROM_IDLE = 0,
    MMI_UCM_FROM_L4C,
    MMI_UCM_FROM_L4C_SIM2,
    MMI_UCM_FROM_SAT,
    MMI_UCM_FROM_WAP,
    MMI_UCM_FROM_ABM,
    MMI_UCM_MODULE_ORIGIN_TOTAL
} mmi_ucm_module_origin_enum;

typedef enum
{
    MMI_UCM_SIM1_ACTIVE = 0x01,
    MMI_UCM_SIM2_ACTIVE = 0x02,
    MMI_UCM_NW_STATUS_END_OF_ENUM
} mmi_ucm_nw_status_enum;

typedef enum
{
    MMI_UCM_VOICE_CALL_TYPE = 0x01,
    MMI_UCM_VOICE_CALL_TYPE_SIM2 = 0x02,
    MMI_UCM_DATA_CALL_TYPE  = 0x04, /* data call with in-call screen */
    MMI_UCM_DATA_CALL_TYPE_SIM2 = 0x08,
    MMI_UCM_CSD_CALL_TYPE   = 0x10, /* data call without in-call screen */
    MMI_UCM_CSD_CALL_TYPE_SIM2 = 0x20,
    MMI_UCM_VOIP_CALL_TYPE  = 0x40,
    MMI_UCM_VIDEO_CALL_TYPE = 0x80,
    MMI_UCM_CALL_TYPE_END_OF_ENUM
} mmi_ucm_call_type_enum;

typedef enum
{
    MMI_UCM_REG_CONNECT         = 0x01,
    MMI_UCM_REG_RELEASE         = 0x02,
    MMI_UCM_REG_REL_BEFORE_CONN = 0x04,
    MMI_UCM_CALL_EVENT_END_OF_ENUM
} mmi_ucm_call_event_enum;

#define MMI_UCM_SIM1_CALL_TYPE_ALL     (MMI_UCM_VOICE_CALL_TYPE | MMI_UCM_DATA_CALL_TYPE | MMI_UCM_CSD_CALL_TYPE)
#define MMI_UCM_SIM2_CALL_TYPE_ALL     (MMI_UCM_VOICE_CALL_TYPE_SIM2 | MMI_UCM_DATA_CALL_TYPE_SIM2 | MMI_UCM_CSD_CALL_TYPE_SIM2)
#define MMI_UCM_VOICE_CALL_TYPE_ALL    (MMI_UCM_VOICE_CALL_TYPE | MMI_UCM_VOICE_CALL_TYPE_SIM2)
#define MMI_UCM_DATA_CALL_TYPE_ALL     (MMI_UCM_DATA_CALL_TYPE | MMI_UCM_DATA_CALL_TYPE_SIM2)
#define MMI_UCM_CSD_CALL_TYPE_ALL      (MMI_UCM_CSD_CALL_TYPE | MMI_UCM_CSD_CALL_TYPE_SIM2)
#define MMI_UCM_CALL_TYPE_ALL          (MMI_UCM_VOICE_CALL_TYPE_ALL | MMI_UCM_DATA_CALL_TYPE_ALL | MMI_UCM_CSD_CALL_TYPE_ALL | MMI_UCM_VOIP_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE)
#define MMI_UCM_CALL_TYPE_NO_CSD       (MMI_UCM_VOICE_CALL_TYPE_ALL | MMI_UCM_DATA_CALL_TYPE_ALL | MMI_UCM_VOIP_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE)
#define MMI_UCM_CALL_TYPE_NO_DATA_CSD  (MMI_UCM_VOICE_CALL_TYPE_ALL | MMI_UCM_VOIP_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE)
#define MMI_UCM_CALL_TYPE_NO_SIM2      (MMI_UCM_SIM1_CALL_TYPE_ALL | MMI_UCM_VOIP_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE)
#define MMI_UCM_CALL_TYPE_DATA_CSD_ALL (MMI_UCM_DATA_CALL_TYPE_ALL | MMI_UCM_CSD_CALL_TYPE_ALL)

typedef void (*mmi_ucm_callback_func_ptr) (void *);

/* UCMMain.c */
extern void mmi_ucm_init(void);
extern void mmi_ucm_end_all_action(void);

/* UCMInterface.c */
extern S32 mmi_ucm_app_total_call(mmi_ucm_call_type_enum call_type);
extern S32 mmi_ucm_app_outgoing_call(mmi_ucm_call_type_enum call_type);
extern S32 mmi_ucm_app_incoming_call(mmi_ucm_call_type_enum call_type);
extern S32 mmi_ucm_app_active_call(mmi_ucm_call_type_enum call_type);
extern S32 mmi_ucm_app_held_call(mmi_ucm_call_type_enum call_type);
extern void mmi_ucm_app_make_call(mmi_ucm_call_type_enum call_type, U8 *num_uri);
extern MMI_BOOL mmi_ucm_app_make_call_with_source(mmi_ucm_module_origin_enum module_id, mmi_ucm_call_type_enum call_type, U8 *num_uri);
extern void mmi_ucm_app_headset_key(void);
extern void mmi_ucm_app_clam_open(void);
extern void mmi_ucm_app_clam_close(void);
extern U16 mmi_ucm_app_get_marker_scrn_id(void);
extern pBOOL isInCall(void);
extern pBOOL isOutgoingCall(void);
extern pBOOL isIncomingCall(void);
extern pBOOL IsWapCallPresent(void);
extern pBOOL GetWapCallPresent(void);
extern pBOOL IsFaxCallPresent(void);
extern U16 IsPhoneInMute(void);
extern void MutethePhone(void);
extern void UnMutethePhone(void);

/* UCMUI.c */
extern void mmi_ucm_app_entry_dial_option(U8 *num_uri, /* in UCS2 with null terminator. Caller should handle memory alloc/free for num_uri */
                                          mmi_ucm_callback_func_ptr callback_after_dial, /* callback function after the MO call is dialed. */
                                          void* callback_para);  /* a pointer to keep caller's static information */

/* UCMUtil.c */
extern mmi_ucm_nw_status_enum mmi_ucm_get_nw_service_status(void);
#endif /* UCM_GPROT_H */ 

