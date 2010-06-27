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
 * JavaProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define prototypes of Java related routines.
 *
 * Author:
 * -------
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

#ifndef JAVA_AGENCY_GPROT_H
#define JAVA_AGENCY_GPROT_H

// #include "MMI_features.h"

#ifdef __J2ME__

/*****************************************************************************
** 1.JAVA_CONTENT_MANAGER feature: (22)
** 1.1   JAVA_CM_BROWSER
 ******************************************************************************/
extern void InitJAVA(void);
extern void mmi_java_highlight_menu(void);
extern void mmi_java_store_setting(void);
extern void mmi_java_load_setting(void);
#ifdef __SUPPORT_INFUSIO__
extern void mmi_java_highlight_eureka(void);
#endif /* __SUPPORT_INFUSIO__ */
extern BOOL mmi_java_is_launch_from_idle(void);
extern void mmi_java_entry_mid_launch_from_idle(void);

/*****************************************************************************
 * 4. JAVA_INSTALL_UPDATE: (16)
 ******************************************************************************/

extern void mmi_java_local_install_content_routing(kal_uint8 *file_path);
extern BOOL mmi_java_is_installing(void);

/*****************************************************************************
 *
 * 7. Java Resume / Java Terminate  (JavaAgencyTaskSwitch.c)
 *
 ******************************************************************************/

extern void mmi_java_entry_terminate_dialog(void);
extern void mmi_java_entry_resume_dialog(void);
extern void mmi_java_entry_force_terminate_dialog(void);
extern U8 mmi_java_screen_delete_hdlr(void *in_param);
extern void mmi_java_entry_terminating(BOOL idle);

/*****************************************************************************
 *
 *  8. Java utility
 *
 ******************************************************************************/

extern BOOL mmi_java_is_in_voice_call(void);
extern BOOL mmi_java_is_in_idle_screen(void);
extern BOOL mmi_java_is_no_sim(void);
extern BOOL mmi_java_is_no_network_service(void);
extern void mmi_java_widget_not_ready(void);
extern void mmi_java_display_is_busy(void);
extern void mmi_java_display_push_busy_ok_hdlr(void);
extern void mmi_java_display_push_busy(void);
extern void mmi_java_display_is_busy_for_pause_mode(void);
extern BOOL mmi_java_check_and_display_is_busy(void);

extern BOOL mmi_java_tck_is_execute(void);

extern void mmi_java_entry_default_domain_setting(S32 domain);

extern U8 g_mmi_java_aud_volume_level;
extern U8 g_mmi_java_is_vib_on;
extern U8 g_mmi_java_is_net_icon_on;
extern U8 g_mmi_java_wap_prof_id;

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
extern U8 g_mmi_java_vk_permission;
#endif

extern U16 mmi_java_get_title_icon(void);

#endif /* __J2ME__ */
#endif /* JAVA_AGENCY_GPROT_H */ /* #define JAVA_AGENCY_PROT_H */

