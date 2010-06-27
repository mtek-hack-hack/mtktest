/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   FlightModeGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Flight Mode definitions
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

#ifndef __FLIGHT_MODE_GPROT_H__
#define __FLIGHT_MODE_GPROT_H__

extern void PhnsetFlightModeQueryBackground(void);

extern void mmi_frm_power_on_init_procedure(void);
extern void mmi_frm_power_on_set_mode(void);

extern void PhnsetFlightModeSaveStatusIconFlags(pBOOL nw_mode);
extern void PhnsetFlightModeRestoreStatusIconFlags(pBOOL nw_mode);

#ifdef __FLIGHT_MODE_SUPPORT__

extern void EntryPhnsetFlightMode(void);
extern void PhnsetFlightModeSelectionReq(void);
extern void PhnsetFlightModeSelectionRsp(void*);
extern void PhnsetFlightModeSaveMode(void);

extern void mmi_flight_mode_hide_menu_items(void);
extern void mmi_flight_mode_unhide_menu_items(void);
extern void mmi_flight_mode_switch_wlan(void);
extern void mmi_flight_mode_switch_bluetooth(void);
extern void mmi_flight_mode_switch_irda(void);

extern void mmi_phnset_switch_flight_mode(void);
extern void mmi_phnset_confirm_to_switch_mode(void);

extern void mmi_flight_mode_need_play_camp_on_tone(void);
extern void mmi_flight_mode_reset_camp_on_tone_event(void);

#ifdef __MMI_WLAN_FEATURES__
extern void mmi_phnset_enter_gsm_flight_mode(void);
extern void mmi_phnset_exit_gsm_flight_mode(void);
extern void mmi_phnset_power_on_query_with_normal_mode(void);
extern void mmi_phnset_power_on_query_with_flight_mode(void);
#endif /* __MMI_WLAN_FEATURES__ */

#endif /* __FLIGHT_MODE_SUPPORT__ */

extern void mmi_flight_mode_popup_in_dialing_sos(void);
extern U8 mmi_flight_mode_is_switching(void);
extern void mmi_flight_mode_switching_in_idle(void);

#endif /* __FLIGHT_MODE_GPROT_H__ */
