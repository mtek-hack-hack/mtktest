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
 * MainMenuProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for main menu functions prototype
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

/**********************************************************************************
   Filename:      mainmenu_prot.h
   Author:
   Date Created:  September-07-2002
   Contains:      Main menu application
**********************************************************************************/
#include "MMI_features.h"

extern void exit_main_menu(void);
extern void handle_mainmenu_right_softkey_up(void);
extern void highlight_mainmenu_phonebook(void);
extern void highlight_mainmenu_messages(void);
extern void highlight_mainmenu_funandgames(void);
extern void highlight_mainmenu_organizer(void);
extern void highlight_mainmenu_settings(void);
extern void highlight_mainmenu_connect(void);

#ifdef __MMI_MESSAGES_CLUB__
extern void highlight_mainmenu_msgclub(void);
#endif 
#ifndef __DISABLE_SHORTCUTS_MENU__
extern void highlight_mainmenu_shortcuts(void);
#endif 
extern void highlight_mainmenu_services(void);
extern void initalize_main_menu_application(void);
extern void main_menu_shortcut_executer(S32 index);
extern void goto_main_menu(void);
extern void exit_main_menu(void);
extern void highlight_mainmenu_profiles(void);

#ifdef __MMI_UCM__
extern void highlight_mainmenu_callcenter(void);
#else /* __MMI_UCM__ */
extern void highlight_mainmenu_callhistory(void);
#endif /* __MMI_UCM__ */

extern void highlight_mainmenu_multimedia(void);
extern void highlight_mainmenu_filemngr(void);
#if defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__)
extern void highlight_mainmenu_extra(void);
#endif
extern void EntryMainMultimedia(void);
extern void EntryMainFileMngr(void);
extern void ExitMainFileMngr(void);
extern void EntryMainExtra(void);

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
extern void EntryMainAVZone(void);
extern void highlight_mainmenu_avzone(void);
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */
#ifdef __MMI_CUSTOMER_SERVICE__
extern void highlight_mainmenu_cust_services(void);
#endif /* __MMI_CUSTOMER_SERVICE__ */
#ifdef __MMI_MOBILE_SERVICE__
extern void highlight_mainmenu_op_services(void);
#endif /* __MMI_MOBILE_SERVICE__ */
#ifdef __MMI_MY_FAVORITE__
extern void highlight_mainmenu_my_favorite(void);
#endif /* __MMI_MY_FAVORITE__ */
#ifdef __MMI_OP01_MENU_NOSIM_LIST__
extern void highlight_mainmenu_multimedia_no_sim(void);
extern void highlight_mainmenu_organizer_no_sim(void);
extern void EntryMainMultimediaNoSim(void);
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */



