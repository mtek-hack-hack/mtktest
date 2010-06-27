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
 * mobile_suite_app.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * WAP/MMI interaction
 * 1. Key queue
 * 2. WAP/MMS screen enter/exit
 * 3. Full-screen editor and menu
 * 4. Misc. screens like popup
 * 5. WAP download & file manager integration
 * 6. New Push/Provision/MMS  notification
 * 7. RPC (widget_execute_MMI(), etc)
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
 * removed!
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

/*******************************************************************************
 * Common scenarios of MMI screen interaction:
 *
 * 1. WAP overlapped with MMI
 * 
 * 2. WAP overlapped with MMI, then press END key (wap_entry_idle_screen_notify)
 *
 * 3. widget_prepare_to_leave_screen() invoked, but MMI popup, wap_exit_widget_screen(), and then 
 *  widget_leave_screen_hdlr() found that WGUI_CTX->is_widget_screen is false, it doesn't GoBackHistory(). 
 *  MMI screen go back => wap_entry_widget_screen() found there is no window to display, and call
 *  widget_prepare_to_leave_screen() again.
 *
 * 4. WAP overlapped with MMI (including CTK), and out-of-memory
 *
 * To be continued ...
 *
 *******************************************************************************/

/*******************************************************************************
 * Rules on Inter-Task Synchronization:
 *
 * MMI resources are shared among three processes (MMI, WAP, Java), and there are more tasks to come in the future.
 * We need to define protocol to meet the following criteria:
 *
 * o Deadlock avoidance
 * o Screen-based shared memory must be released in wap_exit_widget_screen() synchronously.
 * o Prevent partial update the the LCD (e.g. clipping and double buffer might not be unlocked correctly)
 * 
 * -------------------------------
 * Problems of Race Condition if we invoke MMI functions from WAP task:
 *
 * We should prevent invoking MMI function from WAP task
 * o MMI funtions might enter NVRAM message loop, which can NOT be invoked in WAP context.
 *  (For example, entry function of idle screen might write NVRAM)
 *
 * WAP and MMI have the same priority, this prevents the following race condition when WAP and MMI 
 * 1. access global data structures
 * 2. invoke system service that do not put task itself into waiting queue. 
 *  (e.g. WAP might execute MMI functions that use StartTimer() to start event scheduler of MMI)
 * 3. No preemption between allocate_ilm and SEND_ILM 
 * (Assume we do not do blocking operations between two operations)
 * 4. MSF_MEM_ALLOC and MSF_SIGNAL_SEND!!
 *
 * However, it is still dangerous when 
 * o WAP/MMI use other blocking functions that use event groups or mutex (including filesystem API)
 *  For example, WAP decode an image from file.
 * o WAP/MMI display screen at the same time.
 *
 * If another task executes entry/exit function owned by a blocked task, its state might be incorrect.
 * For example: Partial update of screen:
 * a. widget_paint_hdlr is blocked, and MMI display new popup before it returns.
 * b. RedrawCategoryScreen is blocked, and enter WAP screen.
 * For the worst case, it might ASSERT.
 *
 * -------------------------------
 * o MMI wait for WAP:
 *  1. (Unfinished) Power off
 * 2. Wait WAP to shutdown UI from idle screen
 * 3. Wait WAP to display message notification screen from idle screen
 * 4. Wait WAP to get data of dynamic list (handled specially)
 *
 *  NOTE: BE CAREFUL NOT TO USE MMI FUNCTION WHEN MMI IS WAITING FOR WAP
 * If MMI wait for WAP , and WAP task use some MMI function that need to receive external queue,
 * then there will be deadlock!(For example, MMI API of JPEG, Audio receive extq from media task)
 * => When WAP is going to display message notification in idle screen, we wake up MMI before
 *    wap_entry_widget_screen()
 * => Idle screen must be executed in MMI task. (Already ASSERT() to check it)
 * => when WGUI_CTX->is_shutdown_UI is TRUE, we can not enter widget screen or show other window (e.g. HDIa_widgetExtShowPopup)
 *     Otherwise, it will widget_execute_MMI(show popup, KAL_TRUE) and cause deadlock.
 *
 * o Execute in WAP task asynchronously
 * 1. Keypad queue
 *
 * o When WAP wait MMI:
 *    1. HDIa_widgetSetInFocus -> wap_entry_widget_screen
 *   => If it is invoked from idle screen to show message, wap_entry_widget_screen() is invoked in widget_MMI_check_and_display_new_msg() instead
 *    2. Create Popup (e.g.  HDIa_widgetExtShowPopup) or enter MMI screens voluntarily (e.g. file manager, full-screen editor)
 *    3. widget_paint_hdlr, widget_paint_GIF_animation_hdlr, widget_paint_command_hdlr
 *    4. GoBackToHistory(WAP_SCREEN_WIDGET)  (not GoBackHistory())
 *    5. Enter and leave CTK screen 
 *    6. (?) sound playing
 *
 *  NOTE1: BE CAREFUL NOT TO GO BACK IDLE SCREEN WHEN WAP IS WAITING MMI
 * NOTE2: ALL SUCH RPC IN MMI TASK MUST BE GRACEFULLY CANCELED IN IDLE SCREEN
 * If WAP is suspended for MMI, and MMI go back to idle screen before the request is processed, there is deadlock
 *    => WAP should "not" invoke GoBackHistory(), DisplayIdleScreen(), .... in blocking mode
 *    => If protocol events happen before entering new screen, and other application go back history
 *       (i) There will still be deadlock in EntryIdleScreen before widget_execute_MMI(func, KAL_TRUE) is executing.
 *       (ii) For example, an End key event is queued in MMI ext queue, and WAP takes a lot of time to process 
 *        before widget_paint_hdlr() timer is fired. Then End key event is processed before widget_MMI_paint_hdlr
 *        where WIPC_CTX->WAP_is_waiting
 *       (iii) We cancel these RPC in idle screen
 *
 * o Execute in MMI task asynchronously
 * 1. widget_leave_screen_hdlr -> GoBackHistory
 *
 * -------------------------------
 * Other protocol to handle deadlock prevention
 *
 * o Mutex locked and unlocked inside of low-level functions
 *  => Mutex allocated in system functions like file API must be released inside the function too.
 *    They are transparent to use. 
 *     (e.g. lcd_fb_update, file API, blocking JPEG decoding, ...)
 * => NOT applicable to mutex/event groups held in a long period.
 *
 * o If widget_execute_MMI(funcA, KAL_TRUE) and then widget_execute_WAP(funcB, KAL_TRUE) 
 *  We do not wait event group for the second function.
 *
 * o Idle screen should always be executed in MMI task
 *  1. Idle screen call widget_MMI_on_enter_idle_screen and widget_MMI_check_and_display_new_msg
 * 2. Idle screen might invoke Java function
 * 3. Idle screen should not be re-entered
 *
 * -------------------------------
 * How to guarentee that WAP do not use MMI API/change MMI data/or draw on non-widget screen?
 * => All entry/exit/redraw functions should be executed in MMI task. Entry/redraw functions draw on the screen such that
 *   exit functions can only be executed if no other entry/redraw functions are running.
 *
 * Screen drawing of widget: 
 * o HDIa_widgetDrawXXX always check WGUI_CTX->is_widget_screen
 * o widget_paint_GIF_animation_hdlr are fired in WAP task, but widget_execute_MMI(widget_MMI_paint_GIF_animation_hdlr, KAL_TRUE)
 * o widget_paint_hdlr are fired in WAP task, but widget_execute_MMI(widget_MMI_paint_hdlr, KAL_TRUE)
 * o widget_paint_command_hdlr are  fired in WAP task, but widget_execute_MMI(widget_MMI_paint_command_hdlr, KAL_TRUE)
 *
 * Note: For widget_paint_hdlr and widget_paint_command_hdlr , we should not simply invoke the timer in MMI task because 
 * it can not guarentee integrity of widget data .
 * 
 * 
 *******************************************************************************/

#include "widget.h"

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stack_msgs.h"
#include "app_buff_alloc.h"
#include "kal_release.h"        /* Time */

#include "CommonScreens.h"
#include "EventsDcl.h"  /* MMI timer ID */

#include "MMIDataType.h"

#include "mmiapi_struct.h"
#include "wap_ps_struct.h"

#include "WapDef.h"
#include "WapType.h"
#include "msf_file.h"
#include "msf_cmmn.h"
#include "widget_extension.h"

// TODO: set settingprof into include path, otherwise we cannot include it
#include "phonebook\phonebookinc\PhoneBookGprot.h"
#include "DownloadProtos.h"     /* GetFreeDownloadXSlot() */
#include "SatDefs.h"    /* SAT_WAIT_IMAGE_ID */
#include "SettingDefs.h"
#include "SettingsGdcl.h"

#include "FrameworkGprot.h"
#include "FileMgr.h"
#include "fs_func.h"

#include "mmiapi_struct.h"
#include "mmiapi_func.h"

#include "conversions.h"
#include "app_str.h"
#include "app_usedetails.h"

#include "wgui_categories_inputs.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_defs.h"
#include "wgui_status_icons.h"
#include "wgui_softkeys.h"

#include "TimerEvents.h"
#include "IdleAppDef.h"
#include "gpio/gpioInc/GPIOInc.h"       /* Vibration/Backlight */
#include "SimDetectionGprot.h"

#ifdef MMS_SUPPORT
#include "mms_cfg.h"    /* for MMS_MAX_NO_OF_MSG */
#include "mms_def.h"    /* for mautils.h */
#include "sls_cfg.h"    /* for mautils.h */
#include "sls_if.h"     /* for mautils.h */
#include "mea_cfg.h"
#include "mea_def.h"    /* for MeaCreationModeType */
#include "matypes.h"    /* for mautils.h */
#include "mautils.h"    /* for meaFileName2MimeType */
#include "msig.h"
#include "fldmgr.h"
#endif /* MMS_SUPPORT */ 



#ifdef __DRM_SUPPORT__
#include "../../drm/include/drm_def.h"
#include "../../drm/include/drm_main.h"
#include "../../drm/include/drm_gprot.h"
#endif /* __DRM_SUPPORT__ */ 

#include "mdi_datatype.h"
#include "mdi_audio.h"  /* Message tone pause/resume */

#include "lcd_sw_rnd.h"
#include "gui_setting.h"

#include "CallmanagementGprot.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageGProt.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */ 


#include "IdleAppDef.h" /* Idle screen */
#include "IdleAppProt.h"
#include "AudioInc.h"
#include "ProfileGprots.h"      /* Alert type */
#include "AlarmFrameworkProt.h" /* Alarm */
#include "messages/messagesInc/MessagesResourceData.h"  /* message image */


#ifdef __USB_IN_NORMAL_MODE__
extern kal_bool is_mms_storage_exported_to_pc(void);
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
extern pBOOL mmi_usb_is_leaving_ms_mode(void);
#endif /* __USB_IN_NORMAL_MODE__ */ 
#define INDICATION_KEY_CODE      (255)
#define NONE_REPEATED_KEY_CODE   (255)

#ifdef MMS_SUPPORT
extern MeaCreationModeType meaConfGetCreationMode(void);
extern void meaConfGetImageResizeValue(MsfSize *size);
#endif /* MMS_SUPPORT */ 

extern U8 PhnsetGetDefEncodingType(void);
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
extern S16 MMI_prefered_input_type;
#endif


extern void mmi_msg_start_msg_sub_anm(void);

#ifdef WIDGET_DUAL_SIM_SUPPORT
extern kal_uint8 wap_get_sim_status(void);
extern kal_uint8 wap_get_sim_setting_mode(void);
#endif /* WIDGET_DUAL_SIM_SUPPORT */


#define WIDGET_MAX_PENDING_KEY_NUM    (4)

/* For WCSS editor replace mode state */
#define WIDGET_FULLSCREEN_EDITOR_IN_INSERT_MODE         (0)
#define WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE   (1)
#define WIDGET_FULLSCREEN_EDITOR_IN_REPLACE_MODE        (2)


kal_bool widget_suppress_play_msg_arrival_tone = KAL_FALSE;
/******************************************************************************
 * Local variables/functions
 ******************************************************************************/

static MmsStatusTypeEnum mms_indicator_type = MMS_STATUS_OFF;

#ifdef MMS_SUPPORT
void mms_unread_check(void);
#endif 

/******************************************************************************
 * Fullscreen editor
 ******************************************************************************/
/* Filename valid char table */
static const char WIDGET_SAVE_AS_VALID_CHARS[] = ".-_~ @0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";        /* '.' must be the first char */

static void wap_entry_fullscreen_editor_option(void);
static void wap_entry_fullscreen_editor(void);
static void widget_fullscreen_editor_highlight_done(void);
static void widget_fullscreen_editor_highlight_cancel(void);
static void widget_fullscreen_editor_highlight_input_method(void);
static int widget_check_fullscreen_editor_input_value(kal_bool go_back_history_if_fail);
static void widget_exit_fullscreen_editor(void);
static void widget_exit_fullscreen_editor_with_done(void);
static void widget_exit_fullscreen_editor_with_cancel(int level);
static void widget_exit_fullscreen_editor_with_cancel_level0(void);
static void widget_exit_fullscreen_editor_with_cancel_level1(void);
static void widget_fullscreen_editor_insert_character_dot(void);
static void widget_fullscreen_editor_customize_key(void);

/******************************************************************************
 * Task Management
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGiveControlToMMI
 * DESCRIPTION
 *  If WAP is busy, MMI can not process extq because MMI and WAP have the same priority.
 *  We put WAP task sleep.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtGiveControlToMMI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_WAP_TASK());   /* Not fatal */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GIVE_CONTROL_TO_MMI);

    wap_task_sleep(1);
}

/******************************************************************************
 * Circular Keypad Queue
 ******************************************************************************/

/*
 * We execute widget_general_keyboard_handler in WAP task. Otherwise, MsfAction and MsfUserEvent 
 * * might be inserted in WAP internal queue when WAP is blocked inside MSF_fsm and the execution order might be wrong.
 * *
 * * NOTE: The current implementation does not handle KEY_REPEAT in order to reduce queue size.
 */

/* 
 * If the processing time of certain keypad events exceeds WIDGET_KEY_TIMEOUT_TICKS,
 * we shall flush the key queue and stop processing it after WIDGET_KEY_TIMEOUT2_TICKS.
 */
#define WIDGET_KEY_TIMEOUT_TICKS (KAL_TICKS_1_SEC/2)
#define WIDGET_KEY_TIMEOUT2_TICKS (KAL_TICKS_100_MSEC)

#define WIDGET_KEY_REPEAT_DURATION_TIME      10


/*****************************************************************************
 * FUNCTION
 *  widget_init_key_queue
 * DESCRIPTION
 *  Initialize widget keypad queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_key_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WKEY_CTX->head = WKEY_CTX->tail = 0;
    WKEY_CTX->last_enqueue_time = 0;
    WKEY_CTX->last_process_time = 0;
    WKEY_CTX->is_processing_key = 0;
}

/* Insert keypad event into keypad queue */


/*****************************************************************************
 * FUNCTION
 *  widget_insert_key_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keycode     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_insert_key_queue(kal_uint16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int new_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(keycode < 256);

    new_tail = WKEY_CTX->tail + 1;
    if (new_tail == WIDGET_KEY_QUEUE_SIZE)
    {
        new_tail = 0;
    }

    if (WKEY_CTX->head == new_tail) /* Full */
    {
        /* We can safely drop the key because only KeyUp is enqueued. */
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    WKEY_CTX->keycode[WKEY_CTX->tail] = (kal_uint8) keycode;
    WKEY_CTX->tail = new_tail;
    return KAL_TRUE;
}

/* Retrieve keypad event from keypad queue */


/*****************************************************************************
 * FUNCTION
 *  widget_get_key_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keycode     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_get_key_queue(kal_uint16 *keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WKEY_CTX->head == WKEY_CTX->tail)
    {
        return KAL_FALSE;
    }
    *keycode = WKEY_CTX->keycode[WKEY_CTX->head];
    if (++WKEY_CTX->head == WIDGET_KEY_QUEUE_SIZE)
    {
        WKEY_CTX->head = 0;
    }
    return KAL_TRUE;
}

/* Check whether keypad queue is empty */


/*****************************************************************************
 * FUNCTION
 *  widget_key_queue_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_key_queue_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (WKEY_CTX->head == WKEY_CTX->tail) ? KAL_TRUE : KAL_FALSE;
}

/* 
 * Put keypad indication to WAP external queue. 
 * We typically keep atmost one keypad indication in WAP external queue. 
 */


/*****************************************************************************
 * FUNCTION
 *  widget_put_key_indication_in_ext_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_put_key_indication_in_ext_q(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;
    wap_mmi_key_indication_struct *mmi_key_ind =
        ((wap_mmi_key_indication_struct*) construct_local_para(sizeof(wap_mmi_key_indication_struct), TD_CTRL));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set keycode as 255 for an indication. Keycode  will be retrieved from key queue later in widget_wap_mmi_key_ind() */
    mmi_key_ind->keycode = INDICATION_KEY_CODE;
    mmi_key_ind->keytype = 0;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_MMI_KEY_INDICATION;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) mmi_key_ind;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}

/* Key released event */


/*****************************************************************************
 * FUNCTION
 *  widget_put_key_up_event_in_ext_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keycode     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_put_key_up_event_in_ext_q(kal_uint16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;
    wap_mmi_key_indication_struct *mmi_key_ind =
        ((wap_mmi_key_indication_struct*) construct_local_para(sizeof(wap_mmi_key_indication_struct), TD_CTRL));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_key_ind->keycode = keycode;
    mmi_key_ind->keytype = KEY_EVENT_UP;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_MMI_KEY_INDICATION;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) mmi_key_ind;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_key_handler
 * DESCRIPTION
 *  WAP general key handler for keypads used by MsfUserEvent and MsfAction
 *  (invoked in MMI task, set from widget_clear_all_handler())
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_KEY_HANDLER);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    /* Out-of-memory. WAP is resetting. */
    if (wap_status != WAP_RUNNING)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_KEY_HANDLER_END_WAP_NOT_RUNNING);

        widget_init_key_queue();

        GoBackHistory();
        return;
    }

    GetkeyInfo(&Keycode, &Keytype);

#ifdef __SENDKEY2_SUPPORT__
    /* Handle KEY_SEND2 events, convert it to KEY_SEND */
    if (Keycode == KEY_SEND2)
    {
        Keycode = KEY_SEND;
    }
#endif

    widget_enqueue_keypad_event(Keycode, Keytype);
}


/*****************************************************************************
 * FUNCTION
 *  widget_enqueue_keypad_event
 * DESCRIPTION
 *  Put an key event in key queue
 *  
 *  Note: We only enqueue KEY_EVENT_UP, but we will emulate KEY_EVENT_DOWN in widget_wap_mmi_key_ind()
 * PARAMETERS
 *  Keycode     [IN]        
 *  Keytype     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enqueue_keypad_event(U16 Keycode, U16 Keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Disable enqueuing of keypad event if the last keypad event took too much time to process */
    static kal_uint32 last_repeated_time = 0;
    kal_uint32 now;
    kal_bool was_empty;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     ***********************************************************************
     * 1. Check and convert the keytype: KEY_EVENT_UP, KEY_REPEAT
     ***********************************************************************
     * Although WAP/Widget may set the keyhandler with KEY_EVENT_DOWN, 
     * KEY_REPEAT and KEY_EVENT_UP, we will only insert the 
     * keycode with KEY_EVENT_UP into WAP internal key queue. 
     * We will convert the KEY_REPEAT to KEY_EVENT_UP and then insert 
     * it into WAP's internal key queue.
     */
    if (Keytype == KEY_EVENT_DOWN)
    {
        /* Don't process KEY_EVENT_DOWN, KEY_LONG_PRESS */
        return;
    }

    if (WGUI_CTX->is_painted_after_first_focus_changed == 0)
    {
        return;
    }

    /* Check the key number */
    if (!widget_key_queue_is_empty())
    {
        if (WKEY_CTX->tail > WKEY_CTX->head)
        {
            if (WKEY_CTX->tail - WKEY_CTX->head > WIDGET_MAX_PENDING_KEY_NUM)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENQUEUE_KEYPAD_EVENT_END_DROP_KEYEVENT);

                /* the key number exceed more than WIDGET_MAX_PENDING_KEY_NUM */
                return;
            }
        }
        else
        {
            if ((WIDGET_KEY_QUEUE_SIZE - WKEY_CTX->head) + WKEY_CTX->tail > WIDGET_MAX_PENDING_KEY_NUM)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENQUEUE_KEYPAD_EVENT_END_DROP_KEYEVENT);

                /* the key number exceed more than WIDGET_MAX_PENDING_KEY_NUM */
                return;
            }
        }
    }

    /* We only process KEY_LONG_PRESS & KEY_REPEAT in navigation keys */
    if ((Keytype == KEY_REPEAT || Keytype == KEY_LONG_PRESS) &&
        !(Keycode >= KEY_UP_ARROW && Keycode <= KEY_RIGHT_ARROW))
    {
        return;
    }

    kal_get_time(&now);
    if (Keytype == KEY_REPEAT || Keytype == KEY_LONG_PRESS)
    {
        if (last_repeated_time && (now - last_repeated_time) <= WIDGET_KEY_REPEAT_DURATION_TIME)
        {
            /* 
             * If key repeated frequecy is faster than widget paint frequency,
             * we will drop the repeated key
             */
            return;
        }
        else
        {
            /* 
             * last_repeated_time == 0 ||
             * now - last_repeated_time > WIDGET_PAINT_DELAY_TIME
             */
            last_repeated_time = now;
            Keytype = KEY_EVENT_UP;
        }
    }
    else if (Keytype == KEY_EVENT_UP)
    {
        if (last_repeated_time)
        {
            if (now - last_repeated_time <= WIDGET_KEY_REPEAT_DURATION_TIME)
            {   /* drop the key */
                /* The key has detected the repeat event, reset last_repeated_time  */
                last_repeated_time = 0;
                return;
            }
            /* The key has detected the repeat event, reset last_repeated_time  */
            last_repeated_time = 0;
        }
    }

    /*
     ***********************************************************************
     * 2. Check the key process time
     ***********************************************************************
     * Disable enqueuing of keypad event if the last keypad event 
     * took too much time to process
     */
    if (WKEY_CTX->last_process_time && WKEY_CTX->last_enqueue_time &&
        (now - WKEY_CTX->last_process_time < WIDGET_KEY_TIMEOUT2_TICKS) &&
        (WKEY_CTX->last_process_time - WKEY_CTX->last_enqueue_time >= WIDGET_KEY_TIMEOUT_TICKS))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENQUEUE_KEYPAD_EVENT_END_TIME_TOO_LONG);

        WKEY_CTX->head = WKEY_CTX->tail = 0;
        return;
    }
    else if (WKEY_CTX->last_process_time && WKEY_CTX->last_enqueue_time &&
             (WKEY_CTX->last_process_time - WKEY_CTX->last_enqueue_time < WIDGET_KEY_TIMEOUT_TICKS))
    {
        WKEY_CTX->last_process_time = WKEY_CTX->last_enqueue_time = 0;
    }
    else if (WKEY_CTX->last_process_time && (now - WKEY_CTX->last_process_time >= WIDGET_KEY_TIMEOUT2_TICKS))
    {
        WKEY_CTX->last_process_time = WKEY_CTX->last_enqueue_time = 0;
    }

    if (WKEY_CTX->last_enqueue_time == 0)
    {
        WKEY_CTX->last_enqueue_time = now;
        WKEY_CTX->last_process_time = 0;
    }

    /*
     ***********************************************************************
     * 3. insert the key in WAP/widget internal queue
     ***********************************************************************
     * 
     */
    was_empty = widget_key_queue_is_empty();

    if (widget_insert_key_queue(Keycode) && was_empty)
    {
        widget_put_key_indication_in_ext_q();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_wap_mmi_key_ind
 * DESCRIPTION
 *  Event handler of key indication, invoked from messsage loop of WAP external queue.
 *  Process one key one time.
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_wap_mmi_key_ind(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 keycode;
    wap_mmi_key_indication_struct *mmi_key_ind = (wap_mmi_key_indication_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND);

    if (WGUI_CTX->is_in_goto_idle_screen)
    {
        /* widget is in goto idle screen procedure */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND_END_DISCARD_KEY);
        return;
    }

    if (mmi_key_ind->keycode != INDICATION_KEY_CODE)    /* Key released */
    {
        /* set WKEY_CTX->last_process_time after KEY_EVENT_DOWN and KEY_EVENT_UP are both processed */
        WKEY_CTX->is_processing_key = 1;

        /* It guarentees that KEY_EVENT_DOWN and KEY_EVENT_UP are paired together. */
        if (WIDGET_IS_WAP_RUNNING)
        {
            widget_general_keyboard_handler(mmi_key_ind->keycode, KEY_EVENT_UP);
        }

        if (!widget_key_queue_is_empty())
        {
            widget_put_key_indication_in_ext_q();
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND_PUT_IN_Q);
        }
        return;
    }

    /* Key pressed */
    if (WKEY_CTX->last_process_time && WKEY_CTX->last_enqueue_time &&
        (WKEY_CTX->last_process_time - WKEY_CTX->last_enqueue_time > WIDGET_KEY_TIMEOUT_TICKS))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND_END_TIME_TOO_LONG);

        WKEY_CTX->head = WKEY_CTX->tail = 0;
        return;
    }

    if (!widget_get_key_queue(&keycode))
    {
        // WAP_DBG_ASSERT(0);   /* Maybe the key queue was flushed */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND_END_Q_EMPTY);

        return;
    }

    if (WIDGET_IS_WAP_RUNNING)
    {
        /*
         * Note that we should not simply call widget_general_keyboard_handler twice sequencially
         * * by passing KEY_EVENT_DOWN and KEY_EVENT_UP repectively.
         * *
         * * Take SMIL scrolling as example, for a SMIL with text on top and image on bottom,
         * * smaDeleteUserEvent delete user events after it receive MsfKey_Up + MsfPress (KEY_UP_ARROW + KEY_EVENT_DOWN) 
         * * at top of the text, and widget_form_scroll_up_sliding_SMIL() is executed for KEY_UP_ARROW + KEY_EVENT_UP.
         * * Then the text gadget will get focus and register user events again.
         * *
         * * If we invoke two widget_general_keyboard_handler() sequencially here. widget_form_scroll_up_sliding_SMIL()
         * * will be invoked here because it is function call, and smaDeleteUserEvent() is invoked later because it is 
         * * triggered by internal queue.
         * *
         */
        widget_general_keyboard_handler(keycode, KEY_EVENT_DOWN);
        widget_put_key_up_event_in_ext_q(keycode);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSimulateSEND
 * DESCRIPTION
 *  Simualte YES key pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSimulateSEND(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_enqueue_keypad_event(KEY_SEND, KEY_EVENT_UP);
}

/*****************************************************************************
 *
 * WAP/MMI interaction & window management
 *
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_ready_to_leave_screen
 * DESCRIPTION
 *  If there is no active window left, we should invoke a timer to go back from widget screen.
 *  The timer is used to guard a race condition that a window is created immediately.
 *  
 *  We don't go back to MMI by explicitly invoking GoBackHistory from WAP.
 *  (There are too many scenario to handle, e.g., leaving a push dialog in WAP or in idle screen are different)
 *  Instead, we check certain condition to determine whether to go back to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_ready_to_leave_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *screen;
    widget_header_struct *window;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * If no MsfWindow is left, we should leave widget screen.
     * Note that MsfScreen might not be released after WAP UI is shutdown, and we don't check it.
     */
    foreach_childs((&WGUI_CTX->widget_root), screen,
                   {
                   foreach_childs(screen, window,
                                  {
                                  if (IS_WINDOW_TYPE(window))
                                  {
                                  return KAL_FALSE;}
                                  }
                   );}
    );

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_READY_TO_LEAVE_SCREEN);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_leave_screen_goback
 * DESCRIPTION
 *  After timer expired,  leave widget screen.
 *  (Invoked as a tmer handler in WAP)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
// TODO: handle the case of CTK (when release all widgets)

static void widget_MMI_leave_screen_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Race condition. Do we need to check widget_ready_to_leave_screen() again? */
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!widget_ready_to_leave_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_LEAVE_SCREEN_GOBACK);
        return;
    }
    if (WGUI_CTX->is_widget_screen)
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_leave_screen_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_leave_screen_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Scenario: We need to GoBackHistory in MMI task. Otherwise, successive push/provision/MMS will 
     * enter idle screen in WAP task and create deadlock in widget_MMI_check_and_display_new_msg()
     */

    widget_stop_timer(WIDGET_EXIT_DELAY_TIMER);

    /* 
     * WAP modules might remove a window and create another window immediately.
     * We do not leave widget screen for this case.
     */
    if (!widget_ready_to_leave_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_LEAVE_SCREEN_HDLR_WITH_WINDOW);
        return;
    }
    if (!WGUI_CTX->is_widget_screen)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_LEAVE_SCREEN_HDLR_NOT_IN_WIDGET_SCREEN);
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_LEAVE_SCREEN_HDLR);

    /* WAP might be paused in history (by CTK screen or MMI), and we cannot GoBackToHistory() for this case */
    /* If the last screen is idle screen, widget_execute_MMI with blocking mode causes deadlock */
    widget_execute_MMI(widget_MMI_leave_screen_goback, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_prepare_to_leave_screen
 * DESCRIPTION
 *  Wait for a perod to check whether new window is created. If not, leave widget screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_prepare_to_leave_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: If we restart WAP task, the timer will be destroyed and it will never call widget_leave_screen_hdlr!!

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PREPARE_TO_LEAVE_SCREEN);

    widget_start_timer(
        WIDGET_EXIT_DELAY_TIMER,
        (widget_timer_func) widget_leave_screen_hdlr,
        (void*)WGUI_CTX->current_screen_level /* Deprecated */ ,
        WIDGET_EXIT_DELAY_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_shutdown_WAP_UI
 * DESCRIPTION
 *  Shutdown WAP UI from MMI task (Blocking operation)
 *  Invoked from idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_shutdown_WAP_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SHUTDOWN_WAP_UI);

    /* Invoked from MMI task. Otherwise, deadlock! */
    ASSERT(WIDGET_IS_MMI_TASK());

    /* 
     * Be paranoid. We do not want WAP to change MMI screens in this blocking function 
     * and we do not handle the case IsScreenPresent(WAP_SCREEN_WIDGET)
     */
    WAP_DBG_ASSERT(!WGUI_CTX->is_widget_screen &&
                   /* WGUI_CTX->current_screen_level > 0 && */ !IsScreenPresent(WAP_SCREEN_WIDGET));

    /* All history are cleared if invoked from idle screen */
    WGUI_CTX->current_screen_level = 0;

    /* Block MSF_SET_IN_FOCUS->wap_entry_widget_screen until widget_notify_shutdown_UI_finished() */
    WGUI_CTX->is_shutdown_UI = 1;

    /* Send shutdown indication to WAP */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_SHUTDOWN_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    /*
     * Put MMI into sleeping state and wait WAP.
     * * If WAP is already waiting MMI, then it cannot process the external queue and cause deadlock!
     */
    ASSERT(!WIPC_CTX->MMI_is_waiting && !WIPC_CTX->WAP_is_waiting);
    WIPC_CTX->MMI_is_waiting = 1;
    WIDGET_WAIT_MMI_LOCK();

    /* Be paranoid. Test if MEA/BRA is terminated */
#ifndef __PRODUCTION_RELEASE__
#ifdef MMS_SUPPORT
#ifndef __UNIFIED_MSG_SUPPORT__
    ASSERT(!MSF_moduleIsRunning(MSF_MODID_MEA));
#endif 
#endif /* MMS_SUPPORT */ 
    WAP_DBG_ASSERT(!bra_win_any_win_exists());  // TODO: Use ASSERT
#endif /* __PRODUCTION_RELEASE__ */ 
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SHUTDOWN_WAP_UI_END);
}


/*****************************************************************************
 * FUNCTION
 *  widget_notify_shutdown_UI_finished
 * DESCRIPTION
 *  After WAP finished shutdown of UI, wake up MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_notify_shutdown_UI_finished(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->is_shutdown_UI = 0;
    WGUI_CTX->status_bar_flags = 0;
    WGUI_CTX->is_painted_after_first_focus_changed = 0;

    /* We may send MSG_ID_WAP_BROWSER_SHUTDOWN_REQ without WIDGET_WAIT_MMI_LOCK() */
    if (!WIDGET_TRY_MMI_LOCK())
    {
        ASSERT(!WIPC_CTX->WAP_is_waiting && WIPC_CTX->MMI_is_waiting);
        WIPC_CTX->MMI_is_waiting = 0;
        WIDGET_SIGNAL_MMI_LOCK();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_shutdown_WAP_Widget_UI
 * DESCRIPTION
 *  Shutdown WAP UI and reset widget from MMI task (Blocking operation)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_shutdown_WAP_Widget_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SHUTDOWN_WAP_WIDGET_UI);
    /* Cancel all RPC to MMI task and un-block WAP */
    WIPC_CTX->idlescreen_seq_no++;
    if (WIPC_CTX->WAP_is_waiting)
    {
        widget_unlock_MMI_lock_hdlr();
    }

    /* Reset global variables */
    WEDITOR_CTX->active_object = NULL;
    
    HDIa_widgetExtCloseVideo();
    WGUI_CTX->current_video = NULL;
    WGUI_CTX->second_video = NULL;
    WGUI_CTX->current_video_state = WIDGET_VIDEO_NONE;

    widget_MMI_shutdown_WAP_UI();
    WGUI_CTX->tried_to_enter_widget_screen = 0;

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SHUTDOWN_WAP_WIDGET_UI_END);
}


/*****************************************************************************
 * FUNCTION
 *  wap_exit_widget_screen
 * DESCRIPTION
 *  Exit function of widget screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_exit_widget_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    /* Deprecated check. Because we have at most one widget screen in the current design, 
       this check is no more needed */
    if (WGUI_CTX->is_entering_widget_screen)
    {
        return;
    }

    if (WGUI_CTX->is_widget_screen)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN_IN_WIDGET_SCREEN);

        HDIa_widgetExtCloseVideo();
        
        /*
         * Because we want to clear all handler (to stop list highlight effect)
         * , we enable clear all handler flag here.
         */
        widget_enable_clear_all_handler();
        widget_clear_all_handler();
        widget_restore_menu_background_if_required();
    #ifdef __MMI_WALLPAPER_ON_BOTTOM__
        wgui_reset_wallpaper_on_bottom();
    #endif 
        /* let MMI can sleep */
        TurnOffBacklight();
        mmi_phnset_enable_partial_ss();
        
        widget_reset_security_icon();
        widget_stop_animate(KAL_TRUE);
        /* Before exiting widget screen, enable source key */
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        ClearAllKeyHandler();
        ClearHighlightHandler();        // TODO: move to other place?

    #ifdef __MMI_TOUCH_SCREEN__
        widget_MMI_remove_pen_handler_if_necessary(NULL);
    #endif 

    #ifdef WIDGET_PRECACHE_IMAGE
        widget_MMI_free_precached_image_if_any();
    #endif 
        widget_close_status_icons_if_present();
    #ifdef WIDGET_RESIDENT_STATUS_ICON
        if (WGUI_CTX->dialog_with_hatch_background)
        {
            reset_title_status_icon();
            WGUI_CTX->dialog_with_hatch_background = 0;
        }
    #endif /* WIDGET_RESIDENT_STATUS_ICON */ 
        MMI_title_string = 0;
        MMI_menu_shortcut_number = -1;

        WGUI_CTX->is_widget_screen = KAL_FALSE;

        WGUI_CTX->is_painted = 0;

        // TODO: Make new API to reset lock level directly.
        /*
         * WAP and MMI are different task. 
         * * If exit handler is invoked before the drawing is finished, it has potential problems.
         */
        while (WGUI_CTX->lock_buffer_level > 0)
        {
            WGUI_CTX->lock_buffer_level--;
            gui_unlock_double_buffer();
        }

	#ifdef GUI_SUBMENU_USE_THICK_TITLE
		gui_setup_default_layout();
	#endif
        ExitCategoryFunction = MMI_dummy_function;
        RedrawCategoryFunction = MMI_dummy_function;
        GetCategoryHistory = dummy_get_history;
        GetCategoryHistorySize = dummy_get_history_size;

        if (widget_ready_to_leave_screen() || GetActiveScreenId() == IDLE_SCREEN_ID)
        {
            // TODO: We should handle this in different way
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN_END_TO_LEAVE);
            /* If leave widget screen, we need to stop sound in widget */
            widget_stop_sound_if_present();

            widget_stop_timer(WIDGET_EXIT_DELAY_TIMER);
            /*
             * Do not put widget screen into history; otherwise, after the new 
             * * screen go back and invoke wap_entry_widget_screen(), it might find
             * * no window to display
             */
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN_END_IN_HIST);
            widget_pause_sound_if_present();
            if (WGUI_CTX->last_screen_is_dialog)
            {
                /* 
                 * If widget's last screen is MsfDialog, 
                 * We already draw the background in grayscale. 
                 * The draw manager needs to know this, or the background
                 * will darker when draw manager popups another dialog.
                 *
                 * When entrying new screen, draw manager will reset it to 0.
                 */
                /* Removed, after applying grayscale background algorithm */
                //dm_set_popup_screen_background(MMI_TRUE);
            }
            
            /*
             * If the application register the callback of entry new screen,
             * we call here to notify the application.
             * The applications use this to handle the interrupt situation.
             */
            if (WGUI_CTX->switch_widget_screen_cb)
            {
//                Trace2(TRACE_GROUP_2, "[Widget] switch_widget_screen_cb in exit widget screen ");
                WGUI_CTX->previous_focused_window = WGUI_CTX->current_window;

                WGUI_CTX->switch_widget_screen_cb(WAP_LEAVE_WIDGET_SCREEN);
            }
            currHistory.scrnID = WAP_SCREEN_WIDGET;
            currHistory.entryFuncPtr = wap_entry_widget_screen;
            SET_CHR_AT(currHistory.inputBuffer, 0, 0);
            GetCategoryHistory(currHistory.guiBuffer);
            AddHistory(currHistory);
            WGUI_CTX->current_screen_level++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDeleteWidgetScreenIfPresent
 * DESCRIPTION
 *  Delete WAP_SCREEN_WIDGET if it is in the history
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool HDIa_widgetExtDeleteWidgetScreenIfPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DEL_WIDGET_SCREEN_IF_PRESENT);
    if (IsScreenPresent(WAP_SCREEN_WIDGET))
    {
        DeleteScreenIfPresent(WAP_SCREEN_WIDGET);
        WGUI_CTX->current_screen_level--;

        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtRegisterSwitchWidgetScreenCallback
 * DESCRIPTION
 *  Register the callback of exiting the widget screen
 * PARAMETERS
 *  FuncPtrShort
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtRegisterSwitchWidgetScreenCallback(FuncPtrShort cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_REG_SWITCH_WIDGET_SCREEN_CB);
    WGUI_CTX->switch_widget_screen_cb = cb_func;
}


/*****************************************************************************
 * FUNCTION
 *  widget_goback_history1
 * DESCRIPTION
 *  Go back two level of MMI screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_goback_history1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_exit_dummy_widget_screen
 * DESCRIPTION
 *  Entry function of widget screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_exit_dummy_widget_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*  
 * There is a race condition (race to happen)
 * 
 * 1. L4 send incoming call primitive to MMI task
 * 2. WAP/MMS is starting, WAP task sends RPC request to MMI task to enter widget screen 
 * 3. MMI task enters incoming call screen first. If we do not check in-call here, widget screen
 *  will hide incoming call screen.
 *
 */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_entry_new_screen_with_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_entry_new_screen_with_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_status == WAP_RUNNING && !WGUI_CTX->is_shutdown_UI && !mmi_shutdown_is_in_power_off_period())
    {
        if (widget_check_is_incoming_call())
        {
            history hist = {0};

            /* 
             * The phone shows incoming call screen,
             * but the users don't answer/reject the call, yet.
             *
             * When MT call rings but doesn't connect, 
             * we should not allow enter widget screen.
             * We insert widget screen before GetCmMarkerScrnID().
             */                    
            hist.scrnID = WAP_SCREEN_WIDGET;
            hist.entryFuncPtr = wap_entry_widget_screen;

            InsertHistoryBeforeThisScrnReference(GetCmMarkerScrnID(), &hist);
            return;
        }
        
    #ifndef __UNIFIED_MSG_SUPPORT__
        if (widget_check_no_call_or_wap_call())
    #endif /* __UNIFIED_MSG_SUPPORT__ */ 
        {
            wap_entry_widget_screen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_delete_widget_screen_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U8 wap_delete_widget_screen_cb(void* param)
{
    if (((kal_uint32)param == (kal_uint32)MMI_FALSE) && widget_check_is_in_call() && (WGUI_CTX->is_shutdown_UI == 0))
    {
        ilm_struct *ilm_ptr = NULL;

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WAP_DELETE_WIDGET_SCREEN_CB);
        /* someone wants to delete the widget screen in the history */
        WGUI_CTX->current_screen_level = 0;
    
        /* Block MSF_SET_IN_FOCUS->wap_entry_widget_screen until widget_notify_shutdown_UI_finished() */
        WGUI_CTX->is_shutdown_UI = 1;
    
        /* Send shutdown indication to WAP */
        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_SHUTDOWN_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_widget_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_entry_widget_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * If we do not enter widget screen because WAP is reseting or no window to display, we need to handle it very carefully,
     * * Otherwise, it may make MMI hang.
     * * 
     * * Note that we cannot GoBackHistory here to go to previous screen. 
     * * Assume the backtrace might be GoBackHistory->ExecutePopHistory-> wap_entry_widget_screen,
     * * GoBackHistory() again will cause problems.
     */

    kal_bool is_back_from_call_screen = KAL_FALSE;
    kal_bool is_back_from_history = CheckIsBackHistory()? KAL_TRUE : KAL_FALSE;
    kal_bool return_from_ctk = (widget_current_ctk_MMI_screen_id() != 0) ? KAL_TRUE : KAL_FALSE;
    U16 last_screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WAP_DBG_ASSERT(WGUI_CTX->current_screen_level == 0 || WGUI_CTX->current_screen_level == 1);

    last_screen_id = GetExitScrnID();

    /* reset WGUI_CTX->is_in_goto_idle_screen value */
    WGUI_CTX->is_in_goto_idle_screen = 0;

    /* On WAP resetting (e.g. out-of-memory), don't enter WAP screen */
    if (!WIDGET_IS_WAP_RUNNING)
    {
        /*
         * If out-of-memory occurs in CTK screen 
         * It will go back to widget screen and found wap is reseting
         */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_END_WAP_NOT_RUNNING);

        EntryNewScreen(WAP_SCREEN_WIDGET_DUMMY, wap_exit_dummy_widget_screen, NULL, NULL);
	#ifdef GUI_SUBMENU_USE_THICK_TITLE
		gui_setup_submenu_layout();
        wgui_title_set_thick(MMI_TRUE);
    #endif
        WGUI_CTX->current_screen_level = 0;
        WGUI_CTX->is_widget_screen = KAL_FALSE; /* We do not set exit handler to reset it */

        clear_key_handlers();
        SetGroupKeyHandler(GoBackHistory, widget_all_keys, MAX_KEYS, KEY_EVENT_UP);

        /* We do not insert widget screen into history */
        ExitCategoryFunction = UI_dummy_function;
        RedrawCategoryFunction = UI_dummy_function;
        GetCategoryHistory = dummy_get_history;
        GetCategoryHistorySize = dummy_get_history_size;
        return;
    }

    /* This contain potential problem */
    if (widget_ready_to_leave_screen()) /* No active MsfWindow in current widget screen */
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_NO_MSFWINDOW);

        /* Scenario: close MMS main menu (CTK screen) and go back to widget screen (with no window) */
        /* It is still widget screen, and it might create new MsfWindow later */
        WGUI_CTX->is_entering_widget_screen = 1;
        EntryNewScreen(WAP_SCREEN_WIDGET, wap_exit_widget_screen, NULL, NULL);
        WGUI_CTX->is_entering_widget_screen = 0;
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_NO_MSFWINDOW_2);

        WGUI_CTX->current_screen_level = 0;
        WGUI_CTX->is_widget_screen = KAL_TRUE;

        ShowCategoryDummyScreen();

        /* Leave widget screen immediately after pressing any key */
        clear_key_handlers();
        /* the following keypad handler GoBackHistory is not executed if a MsfWindow is created in the meanwhile */
        SetGroupKeyHandler(GoBackHistory, widget_all_keys, MAX_KEYS, KEY_EVENT_UP);

        /* Start timer to leave widget screen */
        widget_prepare_to_leave_screen();

        /*
         * We still need to set exit handler to reset status 
         * * (If GoBackHistory() is executed before widget_leave_screen_hdlr()
         */
        ExitCategoryFunction = UI_dummy_function;
        RedrawCategoryFunction = UI_dummy_function;
        GetCategoryHistory = dummy_get_history;
        GetCategoryHistorySize = dummy_get_history_size;
        return;
    }

    /*
     * (Deprecated)
     * * the exit handler wap_exit_widget_screen() should not be executed
     * * if there are two successive widget screen in MMI history
     * * e.g. WAP->dialling->WAP but the dialling screen doesn't put itself in history
     * * and we should not execute wap_exit_widget_screen again
     */
    WGUI_CTX->is_entering_widget_screen = 1;
	if (is_back_from_history && (CALL_MANAGEMENT_BASE <= GetActiveScreenId()) && (GetActiveScreenId() <= CALL_MANAGEMENT_BASE_MAX))
	{
	    /* goback history from the call related screen */
	    is_back_from_call_screen = KAL_TRUE;
	}
    EntryNewScreen(WAP_SCREEN_WIDGET, wap_exit_widget_screen, NULL, NULL);

#ifdef GUI_SUBMENU_USE_THICK_TITLE
	gui_setup_submenu_layout();
    wgui_title_set_thick(MMI_TRUE);
#endif

    if (is_back_from_history)
    {
        /* need to paint the screen again */
        WGUI_CTX->is_painted_after_first_focus_changed = 0;
    }
    WGUI_CTX->is_entering_widget_screen = 0;
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_PREVIOUS_EXIT_HDLE_DONE);
    
    SetDelScrnIDCallbackHandler(WAP_SCREEN_WIDGET, wap_delete_widget_screen_cb);

    if (!wgui_base_layer)
    {
        gdi_layer_get_base_handle(&wgui_base_layer);
    }

    WGUI_CTX->current_screen_level = 0;
    WGUI_CTX->is_widget_screen = KAL_TRUE;

    if (WGUI_CTX->who_want_to_enter_widget_screen != 0)
    {
        WGUI_CTX->who_want_to_enter_widget_screen = 0;
    }
    /* Prevent race condition of WIDGET_EXIT_DELAY_TIMER */
    widget_stop_timer(WIDGET_EXIT_DELAY_TIMER);

    /* Initialize global variables */
    widget_enable_clear_all_handler();

    /* initialize keys table */
    if (widget_all_keys[0] == 0xffff)
    {
        kal_uint16 i;

        for (i = 0; i < MAX_KEYS; i++)
        {
            widget_all_keys[i] = i;
        }
    }
    clear_key_handlers();
    ClearKeyEvents();   /* Clear key queue. For incoming message window */
    widget_init_key_queue();

#ifdef WIDGET_PRECACHE_IMAGE
	#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
		widget_precache_image_reset_layer_data();
	#else
		widget_precache_image_reset_all();
	#endif
#endif 

#ifdef WIDGET_RESIDENT_STATUS_ICON
    /*
     * We draw the screen after widget_paint() timer expires,
     * * the status icon bar might be redrawed before we draw widget screen.
     * *
     * * Between wap_entry_widget_screen() and widget_paint_hdlr(), 
     * * MMI_hide_status_icon_bars[] stay unchanged.
     * * Meanwhile, status-icon-blinking use MMI_hide_status_icon_bars[] to fill 
     * * the background of status icon area.
     * * We can not set/clear MMI_hide_status_icon_bars[] because the previous 
     * * screen is still displayed.
     * *
     * * If WAP is entered from idle screen.MMI_hide_status_icon_bars[]
     * * fills transparent color #0000FF in the status icon bar area, but 
     * * wap_entry_widget_screen() already invoked exit handler of idle screen and 
     * * remove idle screen layer for status icon bar. As a result, 
     * * status-icon-blinking draws a blue bar on top of the screen.
     * * 
     * * The solution is disable status icon bar until widget_paint_hdlr() draw the 
     * * screen and configure MMI_hide_status_icon_bars[] correctly.
     */
    hide_status_icon_bar(0);
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_integrated_enable(MMI_FALSE);
#endif

    if (WGUI_CTX->switch_widget_screen_cb)
    {
        /*
         * If previous focused window is the same with current window,
         * we will call switch_widget_screen_cb to notify the caller.
         */
        if (WGUI_CTX->previous_focused_window == WGUI_CTX->current_window)
        {
            WGUI_CTX->switch_widget_screen_cb(WAP_GOBACK_WIDGET_SCREEN);
        }
    }

    /* Prepare display and redraw */
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

    /*
     * 1. widget_paint_object will clear background except for MsfPaintbox, MsfEditor, CTK
     * * 2. If we are displaying MsfDialog, retain the old display content to follow MMI convention 
     * * 3. We do not clear screen for paintbox in widget_paint_object, and we need to do this when 
     * *  a paintbox is focused or re-displayed (cf. HDIa_widgetSetInFocus)
     * * 4. We do not clear screen when return from full screen editor to widget screen with MsfEditor focused
     * *    (We expect user application set focus to another MsfWindow immediately, and we 
     * *     do not want to screen to be erased for a short time)
     * * 5. (Tricky) We do not clear non-paintbox screen if the previous screen is WAP_SCREEN_DELETE_ALL
     * *  because we might use HDIa_widgetExtShowPopup  immediately after returning from this screen.
     */
    if (!widget_is_current_window_type(WIDGET_EDITOR_TYPE) && (widget_is_current_window_type(WIDGET_PAINTBOX_TYPE) ||   /* Back to paintbox */
                                                               (!return_from_ctk && (last_screen_id != WAP_SCREEN_DELETE_ALL) && (last_screen_id != WAP_SCREEN_OPTION_GROUP) && is_back_from_history))) /* MsfDialog should not display on top of MT screen */
    {
        clear_screen();
    }

    if (is_back_from_call_screen)
    {
        /* If goback from the call related screens, we also need to clear the screen. */
        clear_screen();
    }
	
    if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY)
    {
        widget_paint_status_bar_busy_animator(KAL_TRUE);
    }

    if (WGUI_CTX->in_paintbox)
    {
        /* Widget_paint() only draw gadgets, only BRS can draw texts */
        widget_paintbox_redraw();
		/*
		 * We have to also call widget_paint first.
         * If BRS is download the page content and we don't redraw widget screen first,
         * the users will feel the handset hang.
         */
    }

    /* Resume sound paused by another MMI screen */
    widget_resume_pending_sound_if_present();

    /* Start timer to paint widget screen */
    widget_paint();

    /* Setup MMI category screen */
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = widget_paint;  /* redraw */
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_END);
}


/*****************************************************************************
 * FUNCTION
 *  widget_allow_create_new_MMI_screen
 * DESCRIPTION
 *  Check whether we can display new window (e.g., poup, file manager, phonebook...)
 *  
 *  Note:
 *  1. We have three kinds of screen in WAP - widget, CTK, and other MMI screens used by WAP/MMS
 *  2. The rules is subset to the rules defined in widget_set_current_focus
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_allow_create_new_MMI_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We cannot display new window when shutdown UI in idle screen or out-of-memory */
    if (WGUI_CTX->is_shutdown_UI)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ALLOW_CREATE_NEW_MMI_SCREEN_FAILED_BY_SHUTDOWN);
        return KAL_FALSE;
    }

    /* 
     * We have unlocked RPC lock and cancel pending RPC requests to 
     * MMI task widget_MMI_on_enter_idle_screen.
     *
     * However, if WAP send RPC request to MMI task before widget_MMI_check_and_display_new_msg(). 
     * It creates deadlock. 
     *
     * Reference: EntryIdleScreen(). 
     * Note: We check GetExitScrnID() because g_idle_context.IsOnIdleScreen is not always set inside EntryIdleScreen().
     */
    if (WGUI_CTX->is_in_goto_idle_screen == 1 || g_idle_context.IsOnIdleScreen || GetExitScrnID() == IDLE_SCREEN_ID)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ALLOW_CREATE_NEW_MMI_SCREEN_FAILED_BY_GOTO_IDLE_SCREEN);
        WAP_DBG_ASSERT(0);  /* This check might block normal screen if we are careless */
        return KAL_FALSE;
    }

    if (widget_check_is_incoming_call())
    {
        /* The phone shows incoming call screen, but the users don't answer/reject the call, yet. */
        return KAL_FALSE;
    }

#ifndef __UNIFIED_MSG_SUPPORT__
    /* In unified message, we allow MMS enters widget screen in the call  */
    if (widget_check_is_in_non_wap_call())
    {
        return KAL_FALSE;
    }
#endif /* __UNIFIED_MSG_SUPPORT__ */

    if (!WIDGET_IS_WAP_RUNNING)
    {
        return KAL_FALSE;
    }

    if (mmi_shutdown_is_in_power_off_period())
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_goback_to_widget_screen
 * DESCRIPTION
 *  Go back to widget screen in MMI task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
// TODO: Use widget_goback_to_WAP_screens() to replace it

static void widget_MMI_goback_to_widget_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    if (IsScreenPresent(WAP_SCREEN_WIDGET))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_GOBACK_TO_WIDGET_SCREEN);

        GoBackToHistory(WAP_SCREEN_WIDGET);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_goback_to_widget_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_goback_to_widget_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOBACK_TO_WIDGET_SCREEN);

    if (IsScreenPresent(WAP_SCREEN_WIDGET)) /* To prevent callback in idle screen */
    {
        widget_execute_MMI(widget_MMI_goback_to_widget_screen, KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_goback_to_WAP_screens
 * DESCRIPTION
 *  Go back to widget or CTK screen in MMI task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_goback_to_WAP_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_MMI_screen_id ctk_scrid = widget_current_ctk_MMI_screen_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctk_scrid && IsScreenPresent(ctk_scrid))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_GOBACK_TO_WAP_SCREEN_CTK);
        GoBackToHistory(ctk_scrid);
    }
    else if (IsScreenPresent(WAP_SCREEN_WIDGET))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_GOBACK_TO_WAP_SCREEN_WIDGET);

        GoBackToHistory(WAP_SCREEN_WIDGET);
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_GOBACK_TO_WAP_SCREEN_OTHERS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_goback_to_WAP_screens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_goback_to_WAP_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_MMI_screen_id ctk_scrid = widget_current_ctk_MMI_screen_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOBACK_TO_WAP_SCREEN);

    if (g_idle_context.IsOnIdleScreen || (ctk_scrid == 0 && !IsScreenPresent(WAP_SCREEN_WIDGET)))
    {
        return;
    }

    widget_execute_MMI(widget_MMI_goback_to_WAP_screens, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_not_ready_goback_hdlr
 * DESCRIPTION
 *  Timer handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_not_ready_goback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_NOT_READY_GOBACK_HDLR);
    /* If not in this screen, the timer is already stopped */
    WAP_DBG_ASSERT(WGUI_CTX->in_not_ready_screen && WIDGET_IS_MMI_TASK());

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  wap_exit_widget_not_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_exit_widget_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_EXIT_WIDGET_NOT_READY);
    WAP_DBG_ASSERT(WGUI_CTX->in_not_ready_screen && WIDGET_IS_MMI_TASK());

    StopTimer((U16) WAP_NOT_READY_TIMER);
    if (WGUI_CTX->in_not_ready_screen == 1)
    {
        /* the exit function for wap_entry_widget_not_ready() */
        WGUI_CTX->in_not_ready_screen = 0;
    }
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    else
    {
        /* the exit function for wap_entry_image_precache() */
        wgui_status_icon_unlock_redrawing();
    }
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */
}

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING

/*****************************************************************************
 * FUNCTION
 *  widget_MMI_not_ready_goback_hdlr
 * DESCRIPTION
 *  Timer handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_precache_not_ready_goback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_image_precache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_entry_image_precache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WAP_ENTRY_IMAGE_PRECACHE);

    EntryNewScreen(WAP_SCREEN_NOT_READY, wap_exit_widget_not_ready, NULL, NULL);

    StartTimer((U16) WAP_NOT_READY_TIMER, 20000, widget_MMI_precache_not_ready_goback_hdlr);

    ShowCategory66Screen(
        MEA_STR_ID_MMS,
        MEA_IMG_TITLE_NORMAL,
        0,
        0,
        0,
        0,
        (U8*) GetString(WIDGET_STR_ID_PLEASE_WAIT),
        0,
        NULL);
    wgui_status_icon_lock_redrawing();

}

#endif /*WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING*/

/*****************************************************************************
 * FUNCTION
 *  wap_entry_widget_not_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_entry_widget_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WIDGET_NOT_READY);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    EntryNewScreen(WAP_SCREEN_NOT_READY, wap_exit_widget_not_ready, NULL, NULL);

    StartTimer((U16) WAP_NOT_READY_TIMER, 2000, widget_MMI_not_ready_goback_hdlr);
#ifdef MMS_SUPPORT
    ShowCategory66Screen(
        (U16) (WGUI_CTX->not_ready_for_MMS ? MEA_STR_ID_MMS : BRA_STR_ID_START_TITLE),
        (U16) (WGUI_CTX->not_ready_for_MMS ? MEA_IMG_TITLE_NORMAL : WAP_IMAGE_WAP_LOGO),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(WIDGET_STR_ID_PLEASE_WAIT),
        SAT_WAIT_IMAGE_ID,
        NULL);
#else /* MMS_SUPPORT */ 
    ShowCategory66Screen(
        BRA_STR_ID_START_TITLE,
        WAP_IMAGE_WAP_LOGO,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(WIDGET_STR_ID_PLEASE_WAIT),
        SAT_WAIT_IMAGE_ID,
        NULL);
#endif /* MMS_SUPPORT */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    WGUI_CTX->in_not_ready_screen = 1;
}

#ifdef WIDGET_ENABLE_TRANSITION_ANIMATION


/*****************************************************************************
 * FUNCTION
 *  wap_entry_transition_animation
 * DESCRIPTION
 *  Enter trasitional animation when screen swich
 *  1. It is a function call, the current MMI screen is suspended immediately
 *  2. It is a MMI screen instead of MsfCtkWindow, we do not need to set focus for it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_transition_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (WIPC_CTX->transition_animation_for_MMS)
    {
        case 2:
            msg = (U8*) GetString(WIDGET_STR_ID_IMAGE_RESIZE);
            break;
        default:    /* 0, 1, and others */
            msg = (U8*) GetString(WIDGET_STR_ID_PLEASE_WAIT);
            break;
    }
    EntryNewScreen(WAP_SCREEN_TRANSITION_ANIMATION, NULL, wap_entry_transition_animation, NULL);
    /* draw the blank softkey if no softkey button */
    show_softkey_background();
    ShowCategory66Screen(
        (U16) (WIPC_CTX->transition_animation_for_MMS ? MEA_STR_ID_MMS : BRA_STR_ID_START_TITLE),
        (U16) (WIPC_CTX->transition_animation_for_MMS ? MEA_IMG_TITLE_NORMAL : WAP_IMAGE_WAP_LOGO),
        0,
        0,
        0,
        0,
        msg,
    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        /* In non-blocking image drawing, we can't use GDI service */
        0, //SAT_WAIT_IMAGE_ID, gilbert
    #else
        SAT_WAIT_IMAGE_ID,
    #endif
        NULL);

    ClearAllKeyHandler();   /* End key is still valid */
    if (WIPC_CTX->transition_animation_disable_END)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDisplayTransitionAnimation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_MMS      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtDisplayTransitionAnimation(kal_bool is_MMS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_allow_create_new_MMI_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DISPLAY_TRANSITION_ANIMATION_NOT_ALLOW);
        return;
    }

    if (GetExitScrnID() == WAP_SCREEN_TRANSITION_ANIMATION || IsScreenPresent(WAP_SCREEN_TRANSITION_ANIMATION))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DISPLAY_TRANSITION_ANIMATION_ALREADY_EXIST);
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DISPLAY_TRANSITION_ANIMATION);

    WIPC_CTX->transition_animation_for_MMS = is_MMS;
    widget_execute_MMI(wap_entry_transition_animation, KAL_TRUE);
}

/*
 * In entering MMS screen, if user press End key before WAP task receive startup primitive, 
 * * widget_MMI_on_enter_idle_screen() can not terminate MMS.
 */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDisplayTransitionAnimationNoEnd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_MMS      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtDisplayTransitionAnimationNoEnd(kal_bool is_MMS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIPC_CTX->transition_animation_disable_END = 1;
    HDIa_widgetExtDisplayTransitionAnimation(is_MMS);
    WIPC_CTX->transition_animation_disable_END = 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_close_transition_animation
 * DESCRIPTION
 *  Close a transition animation screen if existed.
 *  
 *  Typically it should go back to widget screen unless the transition animation is suspended
 *  by another MMI screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_close_transition_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CLOSE_TRANSITION_ANIMATION);

    if (GetExitScrnID() == WAP_SCREEN_TRANSITION_ANIMATION)
    {
        GoBackHistory();
    }
    else
    {
        if (WGUI_CTX->who_want_to_enter_widget_screen != 0)
        {
            /*
             * If the interrupt (ex. call) comes when inserting MMS content, 
             * we add widget screen in the history and change 
             * WGUI_CTX->who_want_to_enter_widget_screen to WIDGET_VIRTUAL_SCREEN_ID.
             *
             * If closing the transition animation in the background, we need to 
             * remove the original widget screen first and replace the transition 
             * animation screen to the widget screen.
             */
            if (IsScreenPresent(WAP_SCREEN_WIDGET))
            {
                DeleteScreenIfPresent(WAP_SCREEN_WIDGET);
                HistoryReplace(WAP_SCREEN_TRANSITION_ANIMATION, WAP_SCREEN_WIDGET, wap_entry_widget_screen);
                WGUI_CTX->who_want_to_enter_widget_screen = 0;
                return;
            }
        }

        DeleteScreenIfPresent(WAP_SCREEN_TRANSITION_ANIMATION);
        WGUI_CTX->who_want_to_enter_widget_screen = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCloseTransitionAnimation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtCloseTransitionAnimation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We should not do anything in idlescreen in order to prevent deadlock */
    if (!g_idle_context.IsOnIdleScreen)
    {
        if (WIPC_CTX->MMI_is_waiting)
        {
            /* Typically on BRA/MEA UI shutdown in idle screen */
            widget_MMI_close_transition_animation();
        }
        else
        {
            widget_execute_MMI(widget_MMI_close_transition_animation, KAL_FALSE);
        }
    }
}

#else /* WIDGET_ENABLE_TRANSITION_ANIMATION */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDisplayTransitionAnimationNoEnd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_MMS      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtDisplayTransitionAnimationNoEnd(kal_bool is_MMS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(is_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDisplayTransitionAnimation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_MMS      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtDisplayTransitionAnimation(kal_bool is_MMS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(is_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCloseTransitionAnimation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtCloseTransitionAnimation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* WIDGET_ENABLE_TRANSITION_ANIMATION */ 


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_on_enter_idle_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_on_enter_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static kal_bool is_bootup_idle_screen = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_ON_ENTER_IDLE_SCREEN);
    /* Invoked from MMI task. Otherwise, deadlock! */
    ASSERT(WIDGET_IS_MMI_TASK());

    /* Now is in idle screen's EntryIdleScreen() procedure */
    WGUI_CTX->is_in_goto_idle_screen = 1;

    /* Cancel all RPC to MMI task and un-block WAP */
    WIPC_CTX->idlescreen_seq_no++;
    if (WIPC_CTX->WAP_is_waiting)
    {
        widget_unlock_MMI_lock_hdlr();
    }

    /* Reset global variables */
    WEDITOR_CTX->active_object = NULL;

    if (WGUI_CTX->tried_to_enter_widget_screen)
    {
        HDIa_widgetExtCloseVideo();
        WGUI_CTX->current_video = NULL;
        WGUI_CTX->second_video = NULL;
        WGUI_CTX->current_video_state = WIDGET_VIDEO_NONE;

        widget_MMI_shutdown_WAP_UI();
        WGUI_CTX->tried_to_enter_widget_screen = 0;
    }
    else if (is_bootup_idle_screen)
    {
        // TODO: invoke WAP timer to do these
        /* update push indication */
        bra_psl_unread_check();
    #ifdef MMS_SUPPORT
        mms_unread_check();
    #endif 
        widget_send_update_event_to_wap();
        is_bootup_idle_screen = KAL_FALSE;
    }
    /* EntryIdleScreen() will only call widget_MMI_on_enter_idle_screen() in searching network state */
    WGUI_CTX->is_in_goto_idle_screen = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_busy_progressing_screen_in_idle
 * DESCRIPTION
 *  Handle WAP key to enter WAP homepage directly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Temporary screen with all key disabled and no put in history. Invoked from wap_internet_key_hdlr() */
void wap_entry_busy_progressing_screen_in_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WAP_ENTRY_BUSY_PROCESSING_SCREEN);
    EntryNewScreen(WAP_SCREEN_TRANSITION_ANIMATION, NULL, NULL, NULL);
    /* draw the blank softkey if no softkey button */
    show_softkey_background();
    ShowCategory66Screen(
        (U16) BRA_STR_ID_START_TITLE,
        (U16) WAP_IMAGE_WAP_LOGO,
        0,
        0,
        0,
        0,
        (U8*) GetString(WIDGET_STR_ID_PLEASE_WAIT),
        SAT_WAIT_IMAGE_ID,
        NULL);

    ClearAllKeyHandler();   /* End key is still valid */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  widget_goto_idlescreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_goto_idlescreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_in_security_check() == MMI_TRUE || 
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_bootup_is_in_sim2_security_check() == MMI_TRUE ||
        gSecuritySetupContext.PINBlocked_2 ||
#endif
        gSecuritySetupContext.PINBlocked)
    {
        /* If SIM1 or SIM2 is in input PIN screen, we can't enter idle screen */
        GoBackHistory();
    }
    else
    {
        /* In normal case, pass PIN check */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOTO_IDLE_SCREEN);
        DisplayIdleScreen();
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOTO_IDLE_SCREEN_END);
    }
}
#ifndef __MED_MEM_POOL__
#define __MED_MEM_POOL__
#endif
#ifdef MMS_SUPPORT
#ifdef __MED_MEM_POOL__	
extern char *meaCreateFileName_jpg(const char *extension);
#endif
void goto_mms_editor(mms_content_entry_struct *data)
{
    ilm_struct *ilm_ptr = NULL;

    ASSERT(WGUI_CTX->is_widget_screen == FALSE);

    if (!MSF_wapIsReady())
    {
        WGUI_CTX->not_ready_for_MMS = 1;
        wap_entry_widget_not_ready();
        HDIa_widgetExtShowPopup(
            MSF_MODID_WIDGET,
            HDIa_widgetStringGetPredefined(MEA_STR_ID_NOT_AVAILABLE),
            MsfError,
            0);

        if (data && data->callback)
        {
            data->callback(data->callback_param);
        }

        return;
    }
  
    /* Disable key to prevent sending duplicated requests (End key still set) */
    ClearAllKeyHandler();
  
    if (IsReachMEAMaxNumofMsg(MMS_MAX_NO_OF_MSG - 1))
    {
        HDIa_widgetExtShowPopup(
            MSF_MODID_WIDGET,
            HDIa_widgetStringGetPredefined(MEA_STR_ID_MAX_NUMBER_OF_MSG),
            MsfError,
            0);
        if (data && data->callback)
        {
            data->callback(data->callback_param);
        }
        return;
    }

  #ifndef __UNIFIED_MSG_SUPPORT__
    if (MSF_moduleIsRunning(MSF_MODID_MEA))
    {
        /* 
         * Workaround for abnormal case:
         * History node of MEA is deleted by someone, and MEA is still running
         */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMS_CONTENT_INSERT_HDLR_WITH_MEA_RUNNING);

        WAP_DBG_ASSERT(0);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_SHUTDOWN_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }
  #endif /* __UNIFIED_MSG_SUPPORT__ */

    switch(data->mode)
    {
        case MEA_NEW_GENERAL:
        {
            mea_new_mms_req_struct *p = NULL;
            peer_buff_struct *peer_buff_ptr = NULL;
            char *fileName = NULL;
            int len = 0;
            long fileSize = 0;
            mms_content_entry_struct_peer_buf *peer_pdu = NULL;
            MSF_UINT16 buffer_size = 0, peer_pdu_len = 0;
			if(data->file_path != NULL)
			{				
#ifdef __DRM_SUPPORT__
				MSF_INT32 fileHandle;
				MSF_BOOL isDRM = FALSE;

				fileHandle = DRM_open_file((kal_wchar*) data->file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
				if (fileHandle > 0)
				{
					int objType = DRM_get_object_method(fileHandle, NULL);
        
					if (objType == DRM_METHOD_FORWARD_LOCK || objType == DRM_METHOD_COMBINED_DELIVERY)
					{
						DRM_close_file(fileHandle);
						HDIa_widgetExtShowPopup(
							MSF_MODID_WIDGET,
							HDIa_widgetStringGetPredefined(SMA_STR_ID_FAILED_TO_SAVE_DRM),
							MsfError,
							0);
                        if (data && data->callback)
                        {
                            data->callback(data->callback_param);
                        }
						return;
					}
					else if (objType == DRM_METHOD_SEPARATE_DELIVERY)
					{
						isDRM = TRUE;
					}
					DRM_close_file(fileHandle);
				}
	#endif /* __DRM_SUPPORT__ */ 
        
				len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) data->file_path);
				fileName = MSF_MEM_ALLOC(MSF_MODID_WIDGET, len + HDI_EXTERNAL_LEN + 1);
				strcpy(fileName, HDI_EXTERNAL_PATH);
				widget_ucs2_to_utf8_string((kal_uint8*) fileName + HDI_EXTERNAL_LEN, len + 1, (kal_uint8*) data->file_path);
    
				if (meaConfGetCreationMode() == MEA_CREATION_MODE_RESTRICTED &&
					meaIsRestrictedType((const char*)fileName) == FALSE)
				{
					MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
					HDIa_widgetExtShowPopup(
						MSF_MODID_WIDGET,
						HDIa_widgetStringGetPredefined(MEA_STR_ID_RESTRICTED_MIME_ACTION_NONE),
						MsfError,
						0);
                    if (data && data->callback)
                    {
                        data->callback(data->callback_param);
                    }
					return;
				}

	#ifdef JPG_ENCODE
				{
					const char *strMimeType = meaFileName2MimeType(fileName);
					MeaMediaType mType = meaMime2MediaType(strMimeType);
    
					/* Image Resize */
	#ifdef __DRM_SUPPORT__
					if (isDRM == FALSE && meaMediaType2ObjType(mType) == MEA_MEDIA_GROUP_IMAGE)
	#else 
					if (meaMediaType2ObjType(mType) == MEA_MEDIA_GROUP_IMAGE)
	#endif 
					{
						MsfSize size = {0, 0}, resize = {0, 0};
    
						meaConfGetImageResizeValue(&resize);
						if(HDIa_widgetExtImageFileGetSize(fileName, &size) != TRUE)
						{
							HDIa_widgetExtShowPopup(
								MSF_MODID_WIDGET,
								HDIa_widgetStringGetPredefined(MEA_STR_ID_FAILED_FILE_CORRUPT),
								MsfError,
								0);
                            if (data && data->callback)
                            {
                                data->callback(data->callback_param);
                            }
							return;
						}
    
						if((resize.width == 0 && resize.height == 0) || (size.width <= resize.width && size.height <= resize.height))  /* resizing off */
						{
						}
						else
						{
							char *name = NULL;
							char dest_name[MAX_FILE_NAME_LEN];
							int ret = MSF_WIDGET_EXT_RESIZING_SUCCEED;
    
							HDIa_widgetExtDisplayTransitionAnimationNoEnd(2);
							if (!HDIa_fileCheckDirExist(MEA_IMAGE_RESIZE_FOLDER))
							{
								(void)MSF_FILE_MKDIR(MEA_IMAGE_RESIZE_FOLDER);
							}
    
							memset(dest_name, 0x0 , MAX_FILE_NAME_LEN);
			#ifdef __MED_MEM_POOL__			
                        name = meaCreateFileName_jpg("jpg");
			#else							
							name = meaCreateFileName("jpg");
			#endif
							sprintf(dest_name, "%s%s", MEA_IMAGE_RESIZE_FOLDER, name);
						#ifndef __MED_MEM_POOL__
							MSF_MEM_FREE(MSF_MODID_MEA, name);
                           #endif
							ret = HDIa_widgetExtImageResizing(MSF_MODID_MEA, fileName, (char *) dest_name, resize.width, resize.height);
							switch (ret)
							{
							case MSF_WIDGET_EXT_RESIZING_SUCCEED:
								MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
								fileName = msf_cmmn_strdup(MSF_MODID_WIDGET, dest_name);
							case MSF_WIDGET_EXT_RESIZING_SUCCEED_WITH_UNCHANGED:
								break;
							case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL:
								MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
								fileName = NULL;
								HDIa_widgetExtShowPopup(
									MSF_MODID_WIDGET,
									HDIa_widgetStringGetPredefined(MEA_STR_ID_STORAGE_FULL),
									MsfError,
									0);
								HDIa_widgetExtCloseTransitionAnimation();
                                if (data && data->callback)
                                {
                                    data->callback(data->callback_param);
                                }
								return;
							case MSF_WIDGET_EXT_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF:
							case MSF_WIDGET_EXT_RESIZING_FAILED_IN_NO_QUOTA:
								MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
								fileName = NULL;
								HDIa_widgetExtShowPopup(
									MSF_MODID_WIDGET,
									HDIa_widgetStringGetPredefined(MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED),
									MsfError,
									0);
								HDIa_widgetExtCloseTransitionAnimation();
                                if (data && data->callback)
                                {
                                    data->callback(data->callback_param);
                                }
								return;
							case MSF_WIDGET_EXT_RESIZING_FAILED_IN_UNKNOWN_DIMENSION:
								MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
								fileName = NULL;
								HDIa_widgetExtShowPopup(
									MSF_MODID_WIDGET,
									HDIa_widgetStringGetPredefined(MEA_STR_ID_FAILED_FILE_CORRUPT),
									MsfError,
									0);
								HDIa_widgetExtCloseTransitionAnimation();
                                if (data && data->callback)
                                {
                                    data->callback(data->callback_param);
                                }
								return;
							case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_FAILED:
							case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK:
							case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION:
							default:
								MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
								fileName = NULL;
								HDIa_widgetExtShowPopup(
									MSF_MODID_WIDGET,
									HDIa_widgetStringGetPredefined(MEA_STR_ID_FAILED_TO_RESIZE_IMAGE),
									MsfError,
									0);
								HDIa_widgetExtCloseTransitionAnimation();
                                if (data && data->callback)
                                {
                                    data->callback(data->callback_param);
                                }
								return;
							}
						}
					}
				}
	#endif /* JPG_ENCODE */ 
				fileSize = HDIa_fileGetSize(fileName);
    
                if (fileSize <= 0 || 
                    fileSize > MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE || 
                    fileSize > (U64)msm_get_disk_free_space(WAP_STORAGE_MMS))
                {
                    MSF_UINT32 strId = (fileSize <= 0) ? MEA_STR_ID_FAILED_TO_ADD_EMPTY_OBJECT : MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED;
                    if(fileSize > (U64)msm_get_disk_free_space(WAP_STORAGE_MMS))
                    {
                        strId = MEA_STR_ID_STORAGE_FULL;
                    }
	#ifdef JPG_ENCODE
					if (meaIsResizedFile(fileName))
					{
						MSF_FILE_REMOVE(fileName);
					}
	#endif /* JPG_ENCODE */ 
					if (fileName)
					{
						MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
						fileName = NULL;
					}
					HDIa_widgetExtCloseTransitionAnimation();
					HDIa_widgetExtShowPopup(
						MSF_MODID_WIDGET,
						HDIa_widgetStringGetPredefined(strId),
						MsfAlert,
						0);
                    if (data && data->callback)
                    {
                        data->callback(data->callback_param);
                    }
					return;
				}
				HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
        
				/* Set the screen that wants to enter the widget screen */
				HDIa_widgetExtEntryVirtualWidgetScreen(GetExitScrnID());
            
				data->file_path = (char *)HDI_FileNameTranslate(fileName);



			}
            p = (mea_new_mms_req_struct*) construct_local_para((kal_uint16) sizeof(mea_new_mms_req_struct), TD_RESET);

        

        
            if (widget_ucs2_length((kal_uint8 *)data->subject) > MEA_MAX_SUBJECT_LENGTH || 
                widget_ucs2_length((kal_uint8 *)data->text_buffer) > MEA_MAX_TEXT_LENGTH)
            {
                p->isContentTruncated = TRUE;
            }
            else
            {
                p->isContentTruncated = FALSE;
            }

            buffer_size = 2000;
            peer_buff_ptr = construct_peer_buff(buffer_size, 0, 0, TD_RESET);        
            peer_pdu = (mms_content_entry_struct_peer_buf *) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
            ASSERT(peer_pdu_len == buffer_size);
            memset(peer_pdu, 0x00, sizeof(mms_content_entry_struct_peer_buf));
            if (peer_pdu)
            {
				if(data->subject != NULL)
				{
                    buffer_size = MEA_MAX_ENCODE_SUBJECT_LENGTH;      /* 82 */
					widget_ucs2_strncpy((kal_uint8*) peer_pdu->subject, (kal_uint8*) data->subject, buffer_size);
				}

				if(data->text_buffer != NULL)
				{
				    buffer_size = MEA_MAX_ENCODE_TEXT_LENGTH;   /* 1226 */
	                widget_ucs2_strncpy((kal_uint8*) peer_pdu->text_buffer, (kal_uint8*) data->text_buffer, buffer_size);
				}
				if(data->addr != NULL)
				{
                    buffer_size = MEA_MAX_ENCODE_ADDRESS_LENGTH;   /* 122 */				
					widget_ucs2_strncpy((kal_uint8*) peer_pdu->addr, (kal_uint8*) data->addr, buffer_size);
				}
            }
    
            p->mode = MEA_NEW_GENERAL;
            p->funcPtr = (void *)data->callback;
            p->funcParam = data->callback_param;
			if(data->file_path != NULL)
			{
				widget_ucs2_strcpy((kal_uint8*) p->commandInfo, (kal_uint8*) data->file_path);
			}
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;

            ilm_ptr->peer_buff_ptr = peer_buff_ptr;
            ilm_ptr->local_para_ptr = (local_para_struct*) p;
            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);





            if(data->file_path != NULL)
            {
                HDI_FileNameFree((kal_uint8 *)data->file_path);
                MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
            }
            break;
            
        }

        case MEA_NEW_ADDRESS:
        {
            mea_new_mms_req_struct *p = NULL;
        
            HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
            p = (mea_new_mms_req_struct*) construct_local_para((kal_uint16) sizeof(mea_new_mms_req_struct), 0);
        
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;
            p->mode = MEA_NEW_ADDRESS;
            widget_ucs2_strcpy((kal_uint8*) p->commandInfo, (kal_uint8*) data->addr);
        
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr = (local_para_struct*) p;
            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }

        case MEA_NEW_FILE:
        {
            mea_new_mms_req_struct *p = NULL;
            char *fileName = NULL;
            int len = 0;
            long fileSize = 0;
#ifdef __DRM_SUPPORT__
            MSF_BOOL isDRM = FALSE;
            int objType = DRM_get_object_method(0, (kal_wchar*) data->file_path);
    
            if (objType == DRM_METHOD_FORWARD_LOCK || objType == DRM_METHOD_COMBINED_DELIVERY)
            {
                HDIa_widgetExtShowPopup(
                    MSF_MODID_WIDGET,
                    HDIa_widgetStringGetPredefined(SMA_STR_ID_FAILED_TO_SAVE_DRM),
                    MsfError,
                    0);
                if (data && data->callback)
                {
                    data->callback(data->callback_param);
                }
                return;
            }
            else if (objType == DRM_METHOD_SEPARATE_DELIVERY)
            {
                isDRM = TRUE;
            }
#endif /* __DRM_SUPPORT__ */ 
        
            len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) data->file_path);
            fileName = MSF_MEM_ALLOC(MSF_MODID_WIDGET, len + HDI_EXTERNAL_LEN + 1);
            strcpy(fileName, HDI_EXTERNAL_PATH);
            widget_ucs2_to_utf8_string((kal_uint8*) fileName + HDI_EXTERNAL_LEN, len + 1, (kal_uint8*) data->file_path);
    
            if (meaConfGetCreationMode() == MEA_CREATION_MODE_RESTRICTED &&
                meaIsRestrictedType((const char*)fileName) == FALSE)
            {
                MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
                HDIa_widgetExtShowPopup(
                    MSF_MODID_WIDGET,
                    HDIa_widgetStringGetPredefined(MEA_STR_ID_RESTRICTED_MIME_ACTION_NONE),
                    MsfError,
                    0);
                if (data && data->callback)
                {
                    data->callback(data->callback_param);
                }
                return;
            }

#ifdef JPG_ENCODE
            {
                const char *strMimeType = meaFileName2MimeType(fileName);
                MeaMediaType mType = meaMime2MediaType(strMimeType);
    
                /* Image Resize */
#ifdef __DRM_SUPPORT__
                if (isDRM == FALSE && meaMediaType2ObjType(mType) == MEA_MEDIA_GROUP_IMAGE)
#else 
                if (meaMediaType2ObjType(mType) == MEA_MEDIA_GROUP_IMAGE)
#endif 
                {
                    MsfSize size = {0, 0}, resize = {0, 0};
    
                    meaConfGetImageResizeValue(&resize);
                    if(HDIa_widgetExtImageFileGetSize(fileName, &size) != TRUE)
                    {
                        HDIa_widgetExtShowPopup(
                            MSF_MODID_WIDGET,
                            HDIa_widgetStringGetPredefined(MEA_STR_ID_FAILED_FILE_CORRUPT),
                            MsfError,
                            0);
                        if (data && data->callback)
                        {
                            data->callback(data->callback_param);
                        }
                        return;
                    }
    
                    if((resize.width == 0 && resize.height == 0) || (size.width <= resize.width && size.height <= resize.height))  /* resizing off */
                    {
                    }
                    else
                    {
                        char *name = NULL;
                        char dest_name[MAX_FILE_NAME_LEN];
                        int ret = MSF_WIDGET_EXT_RESIZING_SUCCEED;
    
                        HDIa_widgetExtDisplayTransitionAnimationNoEnd(2);
                        if (!HDIa_fileCheckDirExist(MEA_IMAGE_RESIZE_FOLDER))
                        {
                            (void)MSF_FILE_MKDIR(MEA_IMAGE_RESIZE_FOLDER);
                        }
    
                        memset(dest_name, 0x0 , MAX_FILE_NAME_LEN);
                      //  name = meaCreateFileName("jpg");
			#ifdef __MED_MEM_POOL__			
                        name = meaCreateFileName_jpg("jpg");
			#else							
							name = meaCreateFileName("jpg");
			#endif
						
                        sprintf(dest_name, "%s%s", MEA_IMAGE_RESIZE_FOLDER, name);
		#ifndef __MED_MEM_POOL__					
                        MSF_MEM_FREE(MSF_MODID_MEA, name);
#endif                           
                        ret = HDIa_widgetExtImageResizing(MSF_MODID_MEA, fileName, (char *) dest_name, resize.width, resize.height);
                        switch (ret)
                        {
                        case MSF_WIDGET_EXT_RESIZING_SUCCEED:
                            MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
                            fileName = msf_cmmn_strdup(MSF_MODID_WIDGET, dest_name);
                        case MSF_WIDGET_EXT_RESIZING_SUCCEED_WITH_UNCHANGED:
                            break;
                        case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL:
                            MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
                            fileName = NULL;
                            HDIa_widgetExtShowPopup(
                                MSF_MODID_WIDGET,
                                HDIa_widgetStringGetPredefined(MEA_STR_ID_STORAGE_FULL),
                                MsfError,
                                0);
                            HDIa_widgetExtCloseTransitionAnimation();
                            if (data && data->callback)
                            {
                                data->callback(data->callback_param);
                            }
                            return;
                        case MSF_WIDGET_EXT_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF:
                        case MSF_WIDGET_EXT_RESIZING_FAILED_IN_NO_QUOTA:
                            MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
                            fileName = NULL;
                            HDIa_widgetExtShowPopup(
                                MSF_MODID_WIDGET,
                                HDIa_widgetStringGetPredefined(MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED),
                                MsfError,
                                0);
                            HDIa_widgetExtCloseTransitionAnimation();
                            if (data && data->callback)
                            {
                                data->callback(data->callback_param);
                            }
                            return;
                        case MSF_WIDGET_EXT_RESIZING_FAILED_IN_UNKNOWN_DIMENSION:
                            MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
                            fileName = NULL;
                            HDIa_widgetExtShowPopup(
                                MSF_MODID_WIDGET,
                                HDIa_widgetStringGetPredefined(MEA_STR_ID_FAILED_FILE_CORRUPT),
                                MsfError,
                                0);
                            HDIa_widgetExtCloseTransitionAnimation();
                            if (data && data->callback)
                            {
                                data->callback(data->callback_param);
                            }
                            return;
                        case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_FAILED:
                        case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK:
                        case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION:
                        default:
                            MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
                            fileName = NULL;
                            HDIa_widgetExtShowPopup(
                                MSF_MODID_WIDGET,
                                HDIa_widgetStringGetPredefined(MEA_STR_ID_FAILED_TO_RESIZE_IMAGE),
                                MsfError,
                                0);
                            HDIa_widgetExtCloseTransitionAnimation();
                            if (data && data->callback)
                            {
                                data->callback(data->callback_param);
                            }
                            return;
                        }
                    }
                }
            }
#endif /* JPG_ENCODE */ 
            fileSize = HDIa_fileGetSize(fileName);

            if (fileSize <= 0 || 
                fileSize > MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE || 
                fileSize > (U64)msm_get_disk_free_space(WAP_STORAGE_MMS))
            {
                MSF_UINT32 strId = (fileSize <= 0) ? MEA_STR_ID_FAILED_TO_ADD_EMPTY_OBJECT : MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED;
                if(fileSize > (U64)msm_get_disk_free_space(WAP_STORAGE_MMS))
                {
                    strId = MEA_STR_ID_STORAGE_FULL;
                }
#ifdef JPG_ENCODE
                if (meaIsResizedFile(fileName))
                {
                    MSF_FILE_REMOVE(fileName);
                }
#endif /* JPG_ENCODE */ 
                if (fileName)
                {
                    MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
                    fileName = NULL;
                }
                HDIa_widgetExtCloseTransitionAnimation();
                HDIa_widgetExtShowPopup(
                    MSF_MODID_WIDGET,
                    HDIa_widgetStringGetPredefined(strId),
                    MsfAlert,
                    0);
                if (data && data->callback)
                {
                    data->callback(data->callback_param);
                }
                return;
            }
            HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
        
            /* Set the screen that wants to enter the widget screen */
            HDIa_widgetExtEntryVirtualWidgetScreen(GetExitScrnID());
            
            data->file_path = (char *)HDI_FileNameTranslate(fileName);
            p = (mea_new_mms_req_struct*) construct_local_para((kal_uint16) sizeof(mea_new_mms_req_struct), 0);
    
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;
            p->mode = MEA_NEW_FILE;
            p->funcPtr = (void *)data->callback;
            p->funcParam = data->callback_param;
            widget_ucs2_strcpy((kal_uint8*) p->commandInfo, (kal_uint8*) data->file_path);
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr = (local_para_struct*) p;
            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    
            HDI_FileNameFree((kal_uint8 *)data->file_path);
            MSF_MEM_FREE(MSF_MODID_WIDGET, fileName);
            break;
        }

        case MEA_NEW_BUFFER:
        {
            mea_new_mms_req_struct *local_para_ptr = NULL;
            peer_buff_struct *peer_buff_ptr = NULL;
            MSF_UINT8 *peer_pdu = NULL;
            MSF_UINT16 buffer_size = 0, peer_pdu_len = 0;
        
            HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
        
            local_para_ptr = (mea_new_mms_req_struct*)
                construct_local_para((kal_uint16) sizeof(mea_new_mms_req_struct), 0);
        
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;
            local_para_ptr->mode = MEA_NEW_BUFFER;
        
            if (widget_ucs2_length((kal_uint8 *)data->subject) > MEA_MAX_SUBJECT_LENGTH || 
                widget_ucs2_length((kal_uint8 *)data->text_buffer) > MEA_MAX_TEXT_LENGTH)
            {
                local_para_ptr->isContentTruncated = TRUE;
            }
            else
            {
                local_para_ptr->isContentTruncated = FALSE;
            }
        
            buffer_size = MEA_MAX_SUBJECT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH;      /* 82 */
            widget_ucs2_strncpy((kal_uint8*) local_para_ptr->commandInfo, (kal_uint8*) data->subject, buffer_size);
        
            buffer_size = MEA_MAX_TEXT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH;   /* 1226 */
            peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(buffer_size, 0, 0, TD_CTRL);
            peer_pdu = (MSF_UINT8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
            if (peer_pdu)
            {
                widget_ucs2_strncpy((kal_uint8*) peer_pdu, (kal_uint8*) data->text_buffer, buffer_size);
            }
        
            ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
            ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        
        default:
            ASSERT(0);
    }
}

#define MEA_IND_FILE "/Mea/indicator"

/* Write indicator flag info to file */


/*****************************************************************************
 * FUNCTION
 *  mms_write_indicator_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mms_write_indicator_to_file(int flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* int result; */
    int filehandle;
    int openMode = MSF_FILE_SET_WRONLY | MSF_FILE_SET_CREATE | HDI_FILE_SET_CUSTOM_BLOCKING;
    char s[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s[0] = '0' + (int)(flag/10);
    s[1] = '0' + (int)(flag%10);
    s[2] = 0;

    if (MSF_FILE_GETSIZE_DIR(MEA_FOLDER_PATH) == MSF_FILE_ERROR_PATH)
    {
        (void)MSF_FILE_MKDIR(MEA_FOLDER_PATH);
    }

    filehandle = MSF_FILE_OPEN(MSF_MODID_MSM, MEA_IND_FILE, openMode, 0);
    if (filehandle >= 0)
    {
        /* result= */
        MSF_FILE_WRITE(filehandle, (char*)s, 3);
        MSF_FILE_CLOSE(filehandle);
    }
    else
    {
        MSF_FILE_REMOVE(MEA_IND_FILE);
    }
    return;
}

/* MMS Message Indicator */

/*****************************************************************************
 * FUNCTION
 *  widget_config_mms_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  statusType      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_config_mms_icon(kal_uint8 statusType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_BOOL hide_unread_flag = TRUE, hide_busy_flag = TRUE;
#ifdef WIDGET_DUAL_SIM_SUPPORT
    int sim_status = wap_get_sim_status();
    int setting_mode = wap_get_sim_setting_mode();
    MSF_BOOL show_dual_sim_icon_flag = FALSE;
    if(sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_DUAL_SIM ||
       sim_status == WAP_SIM_ID_SIM1 && setting_mode == WAP_SIM_ID_SIM1 ||
       sim_status == WAP_SIM_ID_SIM1 && setting_mode == WAP_SIM_ID_DUAL_SIM ||
       sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_SIM1 ||
       sim_status == WAP_SIM_ID_SIM2 && setting_mode == WAP_SIM_ID_SIM2 ||
       sim_status == WAP_SIM_ID_SIM2 && setting_mode == WAP_SIM_ID_DUAL_SIM ||
       sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_SIM2)
    {
        show_dual_sim_icon_flag = TRUE;
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CONFIG_MMS_ICON, statusType, sim_status, setting_mode);
#endif /*WIDGET_DUAL_SIM_SUPPORT*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(statusType & MMS_STATUS_FULL)
    {
        hide_unread_flag = FALSE;
        HideStatusIcon(STATUS_ICON_MMS_UNREAD);
#ifdef WIDGET_DUAL_SIM_SUPPORT
        HideStatusIcon(STATUS_ICON_MMS_UNREAD_SIM_1); 
        HideStatusIcon(STATUS_ICON_MMS_UNREAD_SIM_2);
#endif /*WIDGET_DUAL_SIM_SUPPORT*/
#ifdef WIDGET_DUAL_SIM_SUPPORT
        if(show_dual_sim_icon_flag)
        {
            BlinkStatusIcon(STATUS_ICON_MMS_UNREAD);
        }
#else
        BlinkStatusIcon(STATUS_ICON_MMS_UNREAD);
#endif /*WIDGET_DUAL_SIM_SUPPORT*/
    }
    else
    {
        if(statusType & MMS_STATUS_NEW_MESSAGE)
        {
            hide_unread_flag = FALSE;
            ShowStatusIcon(STATUS_ICON_MMS_UNREAD);
        }
        else
        {
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
        }
#ifdef WIDGET_DUAL_SIM_SUPPORT
        if((statusType & MMS_STATUS_SIM_1_NEW_MESSAGE) && show_dual_sim_icon_flag)
        {
            hide_unread_flag = FALSE;
            ShowStatusIcon(STATUS_ICON_MMS_UNREAD_SIM_1);
        }
        else
        {
            HideStatusIcon(STATUS_ICON_MMS_UNREAD_SIM_1);
        }

        if((statusType & MMS_STATUS_SIM_2_NEW_MESSAGE) && show_dual_sim_icon_flag)
        {
            hide_unread_flag = FALSE;
            ShowStatusIcon(STATUS_ICON_MMS_UNREAD_SIM_2);
        }
        else
        {
            HideStatusIcon(STATUS_ICON_MMS_UNREAD_SIM_2);
        }

#endif /*WIDGET_DUAL_SIM_SUPPORT*/                
    }

    if(hide_unread_flag == TRUE)
    {
        HideStatusIcon(STATUS_ICON_MMS_UNREAD);
#ifdef WIDGET_DUAL_SIM_SUPPORT
        HideStatusIcon(STATUS_ICON_MMS_UNREAD_SIM_1);
        HideStatusIcon(STATUS_ICON_MMS_UNREAD_SIM_2);
#endif /*WIDGET_DUAL_SIM_SUPPORT*/
    }

    if(statusType & MMS_STATUS_BUSY)
    {
        hide_busy_flag = FALSE;
        HideStatusIcon(STATUS_ICON_MMS_BUSY);
        BlinkStatusIcon(STATUS_ICON_MMS_BUSY);
    }
#ifdef WIDGET_DUAL_SIM_SUPPORT
    else
    {
        
        if((statusType & MMS_STATUS_SIM_1_BUSY) &&
           (sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_DUAL_SIM ||
            sim_status == WAP_SIM_ID_SIM1 && setting_mode == WAP_SIM_ID_SIM1 ||
            sim_status == WAP_SIM_ID_SIM1 && setting_mode == WAP_SIM_ID_DUAL_SIM ||
            sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_SIM1))
        {
            hide_busy_flag = FALSE;        
            HideStatusIcon(STATUS_ICON_MMS_BUSY_SIM_1);
            BlinkStatusIcon(STATUS_ICON_MMS_BUSY_SIM_1);
        }
        else
        {
            HideStatusIcon(STATUS_ICON_MMS_BUSY_SIM_1);
        }

        if((statusType & MMS_STATUS_SIM_2_BUSY) &&
            (sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_DUAL_SIM ||
             sim_status == WAP_SIM_ID_SIM2 && setting_mode == WAP_SIM_ID_SIM2 ||
             sim_status == WAP_SIM_ID_SIM2 && setting_mode == WAP_SIM_ID_DUAL_SIM ||
             sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_SIM2))
        {
            hide_busy_flag = FALSE;        
            HideStatusIcon(STATUS_ICON_MMS_BUSY_SIM_2);
            BlinkStatusIcon(STATUS_ICON_MMS_BUSY_SIM_2);
        }
        else
        {
            HideStatusIcon(STATUS_ICON_MMS_BUSY_SIM_2);
        }
    }
#endif /*WIDGET_DUAL_SIM_SUPPORT*/

    if(hide_busy_flag == TRUE)
    {
        HideStatusIcon(STATUS_ICON_MMS_BUSY);
#ifdef WIDGET_DUAL_SIM_SUPPORT
        HideStatusIcon(STATUS_ICON_MMS_BUSY_SIM_1);
        HideStatusIcon(STATUS_ICON_MMS_BUSY_SIM_2);
#endif /*WIDGET_DUAL_SIM_SUPPORT*/
    }

}


/*****************************************************************************
 * FUNCTION
 *  mms_set_indicator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  statusType      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_set_indicator(int statusType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool update_directly = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MSF_FILE_GETSIZE(MEA_IND_FILE) > 0)
    {
        int filehandle = 0;
        char s[3];        
        filehandle = MSF_FILE_OPEN(MSF_MODID_MSM, MEA_IND_FILE, MSF_FILE_SET_RDONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0);
        if (filehandle >= 0)
        {
            if (MSF_FILE_READ(filehandle, s, 3) == 3)
            {
                int oldStatusType = 0;
                
                oldStatusType = atoi(&s[0]);
                if(oldStatusType == statusType)
                {
                    MSF_FILE_CLOSE(filehandle);
                    return;
                }
            }
            MSF_FILE_CLOSE(filehandle);
        }
    }

    if (WGUI_CTX->is_painted_after_first_focus_changed)
    {
        update_directly = KAL_TRUE;
        if (WGUI_CTX->current_window && IS_CTK_TYPE(WGUI_CTX->current_window))
        {
            ctk_screen_handle scrid;
            
            scrid = HDIa_widgetCtkGetScreenHandle((MsfWindowHandle)(WGUI_CTX->current_window));
            /*
             * If current window is CTK but its state isn't acitve, widget doesn't draw ctk screen
             * and we don't update the status bar directly
             */
            if (CTK_SCREEN_STATE_ACTIVE != ctk_screen_get_current_state(scrid))
            {
                update_directly = KAL_FALSE;
            }
        }
    }

   if (GetActiveScreenId() == WAP_SCREEN_WIDGET && update_directly)
   {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMS_SET_INDICATOR_DIRECTLY);
        /*
         * If it is in widget screen and application changes the focus and finish the painting,
         * we allwo to update the status icon immediately.
         */
		mms_indicator_type = (MmsStatusTypeEnum)statusType;
		mms_write_indicator_to_file(mms_indicator_type);
        
        widget_config_mms_icon((kal_uint8)statusType);

    #ifdef WIDGET_RESIDENT_STATUS_ICON
        if (WGUI_CTX->current_window && !IS_DIALOG_TYPE(WGUI_CTX->current_window))
        {
            /*
             * We don't want to update the status in MsfDialog
             * because we will disable wallpaper on bottom when painting MsfDialog.
             * It may cuases the blank background of status bar problem.
             */
            ShowStatusIconsTitle();
            widget_redraw_status_icons();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMS_SET_INDICATOR_DIRECTLY_END);
        }
    #endif
   }
   else
   {
      ilm_struct *ilm_ptr = NULL;
   	  mmiapi_mms_icon_ind_struct *p= (mmiapi_mms_icon_ind_struct*) construct_local_para((kal_uint16)sizeof(mmiapi_mms_icon_ind_struct),0);
      WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMS_SET_INDICATOR, GetActiveScreenId(), WGUI_CTX->is_painted_after_first_focus_changed);
   
      /* 0: none
       * 1: new message
       * 2: busy
       * 3: full
       */
      p->type = statusType;
      mms_indicator_type = (MmsStatusTypeEnum)p->type;
      mms_write_indicator_to_file(mms_indicator_type);
      ilm_ptr = allocate_ilm( MOD_WAP );
      ilm_ptr->msg_id = MSG_ID_MMIAPI_MMS_IND;
      ilm_ptr->peer_buff_ptr = NULL;
      ilm_ptr->local_para_ptr = (local_para_struct *) p;
      SEND_ILM( MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
   }

}


/*****************************************************************************
 * FUNCTION
 *  mms_unread_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_unread_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int filehandle;
    char s[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MSF_FILE_GETSIZE(MEA_IND_FILE) > 0)
    {
        filehandle = MSF_FILE_OPEN(MSF_MODID_MSM, MEA_IND_FILE, MSF_FILE_SET_RDONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0);
        if (filehandle >= 0)
        {
            if (MSF_FILE_READ(filehandle, s, 3) == 3)
            {
                mms_indicator_type = atoi(&s[0]);
                if (mms_indicator_type > 0)
                {
                    ilm_struct *ilm_ptr = NULL;
                    mmiapi_mms_icon_ind_struct *p =
                        (mmiapi_mms_icon_ind_struct*) construct_local_para(
                                                        (kal_uint16) sizeof(mmiapi_mms_icon_ind_struct),
                                                        0);
                    p->type = mms_indicator_type;
                    ilm_ptr = allocate_ilm(MOD_WAP);
                    ilm_ptr->msg_id = MSG_ID_MMIAPI_MMS_IND;
                    ilm_ptr->peer_buff_ptr = NULL;
                    ilm_ptr->local_para_ptr = (local_para_struct*) p;
                    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
                }
            }
            MSF_FILE_CLOSE(filehandle);
        }
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mms_is_file_can_be_forwarded_to_mms
 * DESCRIPTION 
 *  The function is used to check if the media can be forwarded to MMS 
 * PARAMETERS 
 *  filename     [IN]        Encoded by UCS2 
 * RETURNS 
 *  0: FASLE, 1: TRUE 
 *****************************************************************************/
int mms_is_file_can_be_forwarded_to_mms(const char *filename)
{
    int size = 0;
    char *str = NULL;

    if (mms_is_ready())
    {
        size = widget_ucs2_to_utf8_length_in_bytes((const kal_uint8 *) filename) + 1;
        str = MSF_MEM_ALLOC(MSF_MODID_WIDGET, size);
        widget_ucs2_to_utf8_string((kal_uint8 *)str, size, (const kal_uint8 *)filename);

        if(meaFileName2MimeType(str) != NULL)
        {
            char *ext = strrchr(str, '.');
            if(msf_cmmn_strcmp_nc(ext, ".dcf") == 0 || 
               msf_cmmn_strcmp_nc(ext, ".dm") == 0)
            {
                MSF_MEM_FREE(MSF_MODID_WIDGET, str);
                return FALSE;
            }
            MSF_MEM_FREE(MSF_MODID_WIDGET, str);
            return TRUE;
        }
        else
        {
            MSF_MEM_FREE(MSF_MODID_WIDGET, str);
            return FALSE;
        }
    }
    return FALSE;
}

#else /* MMS_SUPPORT */ 

/* Workaround */


/*****************************************************************************
 * FUNCTION
 *  mms_set_indicator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  statusType      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_set_indicator(int statusType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* MMS_SUPPORT */ 

/* MMS current Indicator (not including busy status) */


/*****************************************************************************
 * FUNCTION
 *  mms_current_indicator_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int mms_current_indicator_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (int)mms_indicator_type;
}

/******************************************************************************
 * Widget internal message box used by fullscreen editor
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wap_entry_widget_editor_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_icon        [IN]        
 *  message             [IN]         
 *  callback            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_entry_widget_editor_message(U16 message_icon, void *message, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopupCallBack((U8*) message, message_icon, 0, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE, callback);
}

/******************************************************************************
 * Widget Popup
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  force_to_display    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_display_popup(int force_to_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool display_on_idle_screen = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DISPLAY_POPUP);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

#ifndef __UNIFIED_MSG_SUPPORT__
    if (widget_check_is_in_non_wap_call())
    {
        return;
    }
#endif

    if (wap_is_new_msg_popup_handled() == KAL_TRUE)
    {
        /*
         * If the applications won't want to show the WAP/MMS popup or
         * the handset has the voice call, 
         * we return here directly.
         */
        return;
    }

    TurnOnBacklight(1);

    if (force_to_display & WIDGET_EXT_FORCE_POPUP_IN_IDLE_CHECKING == WIDGET_EXT_FORCE_POPUP_IN_IDLE_CHECKING)
    {
        /*
         * If calling widget_MMI_display_popup() from widget_MMI_check_and_display_new_msg(),
         * we don't need re-entry idle screen again 
         */
        display_on_idle_screen = KAL_FALSE;
        force_to_display &= ~(WIDGET_EXT_FORCE_POPUP_IN_IDLE_CHECKING);
        
    }
    else
    {
        /* Display it in idle screen or display popup otherwise */
        display_on_idle_screen = (g_idle_context.IsOnIdleScreen || g_idle_context.ScreenSaverRunFlag) && !widget_check_is_in_non_wap_call();
    }

    if (display_on_idle_screen)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DISPLAY_POPUP_GOTO_IDLE_SCREEN);
        WGUI_CTX->has_popup_in_idle_screen = 1;
        EntryIdleScreen();  /* DisplayIdleScreen() do nothing in idle screen */    
    }
    else
    {
        if (!AlmIsTonePlaying())
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DISPLAY_POPUP_DIRECTLY, force_to_display);
            if ((force_to_display == WIDGET_EXT_FORCE_POPUP_FLAG &&
                 WGUI_CTX->is_in_goto_idle_screen == 0) ||
                (force_to_display == WIDGET_EXT_DISPLAY_POPUP_FLAG && 
                 widget_allow_create_new_MMI_screen()))
            {
                /*
                 * Only show popup when widget screen is active.
                 * Can't show popup in the idle screen.
                 */
                DisplayPopup(
                    WGUI_CTX->popup_text,
                    WGUI_CTX->popup_imageid,
                    WGUI_CTX->popup_imageOnBottom,
                    WGUI_CTX->popup_timeout,
                    WGUI_CTX->popup_toneid);

                if (!widget_check_is_in_non_wap_call())
                {
                    /* we only set KEY_END when not in the voice call */
                    SetKeyHandler(widget_goto_idlescreen, KEY_END, KEY_EVENT_DOWN);
                }
            }
            WGUI_CTX->popup_text = NULL;
            WGUI_CTX->popup_imageid = 0;
            WGUI_CTX->popup_imageOnBottom = 0;
            WGUI_CTX->popup_timeout = 0;
            WGUI_CTX->popup_toneid = 0;
        }
	}
}


/* cf. HDIa_widgetExtShowPopup */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtShowPopup
 * DESCRIPTION
 *  This function is workable only when widget need to be active
 *  This function doesn't work in the idle screen
 * PARAMETERS
 *  modId           [IN]        
 *  dialogText      [IN]        
 *  type            [IN]        
 *  timeout         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtShowPopup(MSF_UINT8 modId, MsfStringHandle dialogText, MsfDialogType type, int timeout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_tone_id toneid;
    ctk_image_id imageid;
    kal_bool image_bottom;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_dialog_get_attributes(type, &imageid, &toneid, &image_bottom);

    HDIa_widgetExtShowPopupExt(modId, dialogText, imageid, toneid, image_bottom, timeout);
    return 0;
}

/*
 * Because HDIa_widgetExtShowPopup is used among different module, be sure not to 
 * * use HDIa_widgetRelease(), which has problems on HDIa_widgetReleaseAll().
 * *
 * * Note: Use HDIa_widgetExtRegisterPopupMsg() instead if you want to display on any
 * * MMI screens including idle screen.
 */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtShowPopupExt
 * DESCRIPTION
 *  This function is workable only when widget need to be active
 *  This function doesn't work in the idle screen
 * PARAMETERS
 *  modId               [IN]        
 *  dialogText          [IN]        
 *  imageid             [IN]        
 *  toneid              [IN]        
 *  imageOnBottom       [IN]        
 *  timeout             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtShowPopupExt(
        MSF_UINT8 modId,
        MsfStringHandle dialogText,
        ctk_image_id imageid,
        ctk_tone_id toneid,
        kal_bool imageOnBottom,
        int timeout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *text = HDIa_widgetExtStringGetUCS2buffer(dialogText);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(modId);

    if (!widget_allow_create_new_MMI_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SHOW_POPUP_EXT_NOT_ALLOW);
        return 0;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SHOW_POPUP_EXT);
    if (wap_is_new_msg_popup_handled() == KAL_TRUE)
    {
        /*
         * If the applications won't want to show the WAP/MMS popup or
         * the handset has the voice call, 
         * we return here directly.
         */
        return 0;
    }

    WGUI_CTX->popup_text = (U8*) text;
    WGUI_CTX->popup_imageid = imageid;
    WGUI_CTX->popup_imageOnBottom = (U8) imageOnBottom;
    WGUI_CTX->popup_timeout = (U32) (timeout == 0 ? UI_POPUP_NOTIFYDURATION_TIME : timeout);
    WGUI_CTX->popup_toneid = toneid;

    /*
     * Only show popup when widget screen is active.
     * Can't show popup in the idle screen.
     */
    widget_execute_MMI_i(widget_MMI_display_popup, (int)WIDGET_EXT_DISPLAY_POPUP_FLAG, KAL_TRUE);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtForcePopup
 * DESCRIPTION
 *  This function will force to show the popup even in the idle screen.
 * PARAMETERS
 *  modId           [IN]        
 *  dialogText      [IN]        
 *  type            [IN]        
 *  timeout         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void HDIa_widgetExtForcePopup(MsfStringHandle dialogText, MsfDialogType type, int timeout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_tone_id toneid;
    ctk_image_id imageid;
    kal_bool image_bottom;
    const kal_uint8 *text = HDIa_widgetExtStringGetUCS2buffer(dialogText);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We cannot display new window when shutdown UI in idle screen or out-of-memory */
    if (WGUI_CTX->is_shutdown_UI || !WIDGET_IS_WAP_RUNNING)
    {
        return;
    }
    if (mmi_shutdown_is_in_power_off_period())
    {
        WAP_DBG_ASSERT(0);
        return;
    }

#ifndef __UNIFIED_MSG_SUPPORT__
    if (widget_check_is_in_non_wap_call())
    {
        return;
    }
#endif

	WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SHOW_POPUP);

    if (wap_is_new_msg_popup_handled() == KAL_TRUE)
    {
        /*
         * If the applications won't want to show the WAP/MMS popup or
         * the handset has the voice call, 
         * we return here directly.
         */
        return;
    }

    /* image_bottom isn't used. The image is always at top */
    widget_dialog_get_attributes(type, &imageid, &toneid, &image_bottom);

    WGUI_CTX->popup_text = (U8*) text;
    WGUI_CTX->popup_imageid = imageid;
    WGUI_CTX->popup_imageOnBottom = (U8) image_bottom;
    WGUI_CTX->popup_timeout = (U32) (timeout == 0 ? UI_POPUP_NOTIFYDURATION_TIME : timeout);
    WGUI_CTX->popup_toneid = toneid;

    /* Force to show popup */
    widget_execute_MMI_i(widget_MMI_display_popup, (int)WIDGET_EXT_FORCE_POPUP_FLAG, KAL_TRUE);
}


/******************************************************************************
 * "Delete All" screen
 ******************************************************************************/
#ifdef MMS_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  widget_exit_delete_all_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_delete_all_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOffBacklight();
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_delete_all_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_delete_all_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_DELETE_ALL_SCREEN);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    EntryNewScreen(WAP_SCREEN_DELETE_ALL, widget_exit_delete_all_screen, wap_entry_delete_all_screen, NULL);

    TurnOnBacklight(0);

    ShowCategory8Screen(
        MEA_STR_ID_MMS,
        widget_get_title_icon(0),
        0,
        0,
        0,
        0,
        WIDGET_STR_ID_PLEASE_WAIT,
        SAT_WAIT_IMAGE_ID,
        NULL);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  widget_leave_delete_all_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_leave_delete_all_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_LEAVE_DELETE_ALL_SCREEN);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (GetExitScrnID() == WAP_SCREEN_DELETE_ALL)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(WAP_SCREEN_DELETE_ALL);
    }
}

#endif /* MMS_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtEnterDeleteAllScreenNoInterrupt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtEnterDeleteAllScreenNoInterrupt(void)
{
#ifdef MMS_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: What if MT received before RPC is processed.
    widget_execute_MMI(wap_entry_delete_all_screen, KAL_TRUE);
#endif /* MMS_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtLeaveDeleteAllScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtLeaveDeleteAllScreen(void)
{
#ifdef MMS_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory should be executed in asynchronous mode */
    widget_execute_MMI(widget_leave_delete_all_screen, KAL_FALSE);
#endif /* MMS_SUPPORT */ 
}

/******************************************************************************
 * Fullscreen editor
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_entry_cannot_switch_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_entry_cannot_switch_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, GetString(WIDGET_STR_ID_CANT_SWITCH_INPUT_METHOD), GoBackHistory);
}

#if 0   /* Removed 2004.04.13 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_highlight_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_highlight_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(widget_exit_fullscreen_editor_with_done, KEY_EVENT_UP);
    /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
    SetKeyHandler(widget_exit_fullscreen_editor_with_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_highlight_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_highlight_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(widget_exit_fullscreen_editor_with_cancel_level1, KEY_EVENT_UP);
    /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
    SetKeyHandler(widget_exit_fullscreen_editor_with_cancel_level1, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_highlight_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_highlight_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    if (WEDITOR_CTX->disable_switch_IM)
    {
        SetLeftSoftkeyFunction(widget_entry_cannot_switch_input_method, KEY_EVENT_UP);
        /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
        SetKeyHandler(widget_entry_cannot_switch_input_method, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
        /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
        SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  widget_two_goback_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_two_goback_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_fullscreen_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_fullscreen_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    U16 nStrItemList[3];
    U16 nNumofItem;
    S32 menuItemId = -1;
    S32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_FULLSCREEN_EDITOR_OPTION);

    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    EntryNewScreen(WAP_SCREEN_FULLSCREEN_EDITOR_OPTION, NULL, wap_entry_fullscreen_editor_option, NULL);

    guiBuffer = GetCurrGuiBuffer(WAP_SCREEN_FULLSCREEN_EDITOR_OPTION);

    nNumofItem = GetNumOfChild(WAP_MENU_FULLSCREEN_EDITOR_OPTION);
    GetSequenceStringIds(WAP_MENU_FULLSCREEN_EDITOR_OPTION, nStrItemList);
    /* set parent id */
    SetParentHandler(WAP_MENU_FULLSCREEN_EDITOR_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetHiliteHandler(WAP_MENU_FULLSCREEN_EDITOR_OPTION_DONE, widget_fullscreen_editor_highlight_done);
    SetHiliteHandler(WAP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL, widget_fullscreen_editor_highlight_cancel);
    SetHiliteHandler(WAP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD, widget_fullscreen_editor_highlight_input_method);

    menuItemId = GetChildMenuIDIndexByParentMenuID(
                    WAP_MENU_FULLSCREEN_EDITOR_OPTION,
                    WAP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD);
    if (menuItemId != -1)
    {
        if (WEDITOR_CTX->disable_switch_IM)
        {
            ResetBit(maskingByte, menuItemId);
        }
    }

    MaskHiliteItems(WAP_MENU_FULLSCREEN_EDITOR_OPTION, maskingByte);
    nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);

    ShowCategory15Screen(
        WIDGET_STR_ID_OPTION,
        widget_get_title_icon(0),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* after input method selection is done, it should go back twice to the editor screen */
    RegisterInputMethodScreenCloseFunction(widget_two_goback_history);
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

}

/* /////////////////////////////////////////////////////////////////////// */

/* initialize some global variables local to this file */


/*****************************************************************************
 * FUNCTION
 *  widget_setup_fullscreen_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object              [IN]         
 *  src                 [IN]         
 *  maxlen              [IN]        The UCS2 character count including terminating character ('\0')
 *  type                [IN]        
 *  input_required      [IN]        
 *  title               [IN]        
 *  CSS_format          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_setup_fullscreen_editor(
        widget_header_struct *object,
        kal_uint8 *src,
        int maxlen,
        MsfTextType type,
        kal_int8 input_required,
        MsfStringHandle title,
        const char *CSS_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_IN_INSERT_MODE;
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
    if (CSS_format && (type == MsfPasswordText || type == MsfPasswordNumber))
    {
        if (!app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*m") ||
            !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"m*m") ||
            !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*M") ||
            !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"M*M"))
        {
            /* If CSS format is *m, m*m, *M, M*M, we use the general fullscreen editor */
            WEDITOR_CTX->CSS_format = NULL;
        }
        else
        {
            /* If CSS format isn't *m, m*m, *M, M*M, we use WCSS editor */
            WEDITOR_CTX->CSS_format = CSS_format;
            WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE;
        }
    }
    else if (!CSS_format || !CSS_format[0] || 
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*m") ||
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"m*m") ||
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*M") ||
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"M*M"))
    {
        /* Keep input type unchanged */
        WEDITOR_CTX->CSS_format = NULL;
    }
    else if (!CSS_format || !CSS_format[0] || 
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*N"))
    {
        type = MsfNumber;
        WEDITOR_CTX->CSS_format = NULL;
        WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE;
    }
    else if (!CSS_format || !CSS_format[0] || 
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*n"))
    {
        type = MsfInteger;
        WEDITOR_CTX->CSS_format = NULL;
        WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE;
    }
    else
    {
        type = MsfText;
        WEDITOR_CTX->CSS_format = CSS_format;
        WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE;
    }
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 

    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    WEDITOR_CTX->active_object = object;
    WEDITOR_CTX->input_buffer = src;
    WEDITOR_CTX->input_buffer_max_len = maxlen;
    WEDITOR_CTX->texttype = type;
    WEDITOR_CTX->input_required = input_required;
    WEDITOR_CTX->disable_switch_IM = KAL_FALSE;
    WEDITOR_CTX->disable_symbol_picker = KAL_FALSE;
    WEDITOR_CTX->title = title;

    if (WEDITOR_CTX->CSS_format)
    {
        WEDITOR_CTX->disable_switch_IM = KAL_TRUE;
    }

    switch (type)
    {
            /* Reference: widget_input_gadget_use_fullscreen_editor() */
        case MsfNumeric:
        case MsfNumber:
            /* allow the entry of any numeric character */
            // TODO: It seems that INPUT_TYPE_NUMERIC will disable symbol picker, but we need it
            //WEDITOR_CTX->input_type = INPUT_TYPE_NUMERIC | INPUT_TYPE_OVERRIDE_DEFAULT;
            WEDITOR_CTX->input_type = INPUT_TYPE_NUMERIC;
            WEDITOR_CTX->disable_switch_IM = KAL_TRUE;
            break;
        case MsfIpAddress:
        case MsfInteger:
            /* allow the entry of any numeric, symbol, or punctuation character */
            //WEDITOR_CTX->input_type = INPUT_TYPE_NUMERIC_SYMBOL | INPUT_TYPE_OVERRIDE_DEFAULT;
            WEDITOR_CTX->input_type = INPUT_TYPE_NUMERIC_SYMBOL;
            WEDITOR_CTX->disable_switch_IM = KAL_TRUE;
            break;
        case MsfPasswordText:
            WEDITOR_CTX->input_type =
                //INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_OVERRIDE_DEFAULT;
                INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
            break;
        case MsfPasswordNumber:
            //WEDITOR_CTX->input_type = INPUT_TYPE_NUMERIC_PASSWORD | INPUT_TYPE_OVERRIDE_DEFAULT;
            WEDITOR_CTX->input_type = INPUT_TYPE_NUMERIC_PASSWORD;
            break;
        case MsfPhoneNumber:
            WEDITOR_CTX->input_type =
                //INPUT_TYPE_PHONE_NUMBER /* |INPUT_TYPE_PLUS_CHARACTER_HANDLING */  | INPUT_TYPE_OVERRIDE_DEFAULT;
                INPUT_TYPE_PHONE_NUMBER;
            WEDITOR_CTX->disable_switch_IM = KAL_TRUE;
            WEDITOR_CTX->disable_symbol_picker = KAL_TRUE;
            break;
        case MsfEmailAddress:
        case MsfUrl:    /* only english mode */
            WEDITOR_CTX->input_type =
                //INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_OVERRIDE_DEFAULT;
                INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
            break;
        case MsfMMIDefaultInputMethod:
            WEDITOR_CTX->input_type = INPUT_TYPE_ALPHANUMERIC_LOWERCASE;
            break;
        case MsfUpperCase:
            //WEDITOR_CTX->input_type = INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_OVERRIDE_DEFAULT;
            WEDITOR_CTX->input_type = INPUT_TYPE_ALPHANUMERIC_UPPERCASE;
            break;
        case MsfText:
            /* FALLTHROUGH no break */
        default:
            //WEDITOR_CTX->input_type = INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_OVERRIDE_DEFAULT;
            WEDITOR_CTX->input_type = INPUT_TYPE_ALPHANUMERIC_LOWERCASE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_is_digit
 * DESCRIPTION
 *  check the validity of the input value, and prompt error message
 *  It _must_ be called from widget_exit_fullscreen_editor_with_done()
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  1: ok 0: fail
 *****************************************************************************/
static kal_bool widget_ucs2_is_digit(kal_uint16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (ch <= CHR('9') && ch >= CHR('0')) ? KAL_TRUE : KAL_FALSE;
}


/* Return non-zero value for error message ID, and 0 for valid filename */


/*****************************************************************************
 * FUNCTION
 *  widget_validate_input_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  valid_chars     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 widget_validate_input_filename(const kal_uint8 *filename, const char *valid_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * The character set supported by the underlying filesystem is defined in ShortNameChars[]
     * * However, we further restrict the ASCII character to alphanumeric '-' '_' because
     * * the invalid character list is too long to be displayed on the screen 
     * *
     * * Note that we don't allow '.' because we don't want the user to modify filename extension
     * * and the first character should not be hyphen (-)
     * *
     * * Reference: msf_afii_create_posix_filename()
     */

    const char *t = (const char*)filename;
    const char *c;
    int match;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty */
    if (*t == '\0' && *(t + 1) == '\0')
    {
        return WIDGET_STR_ID_CANT_INPUT_EMPTY_VALUE;
    }

    /* start with hyphen */
    if (*t == '-' && *(t + 1) == '\0')
    {
        return WIDGET_STR_ID_SAVEAS_NAME_INVALID_CHARS;
    }

    /* check the character */
    do
    {
        if (*(t + 1) == 0 && !(*t & 0x80))  /* we only check ASCII, not chinese */
        {
            match = 0;

            c = valid_chars;

            do
            {
                if (*t == *c)
                {
                    match = 1;
                    break;
                }
            } while (*++c);

            if (!match) /* invalid char */
            {
                return WIDGET_STR_ID_SAVEAS_NAME_INVALID_CHARS;
            }
        }

        t += 2;
    } while (*t != '\0' || *(t + 1) != '\0');

    return 0;
}

/* 1: ok 0: fail */


/*****************************************************************************
 * FUNCTION
 *  widget_check_fullscreen_editor_input_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  go_back_history_if_fail     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int widget_check_fullscreen_editor_input_value(kal_bool go_back_history_if_fail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*fail_callback) (void);

    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (go_back_history_if_fail)
    {
        fail_callback = widget_goback_history1; /* leave the option menu */
    }
    else
    {
        fail_callback = GoBackHistory;
    }

    if (WEDITOR_CTX->texttype == MsfSaveAsFilename ||
        WEDITOR_CTX->texttype == MsfFile || WEDITOR_CTX->texttype == MsfFilePath)
    {
        U16 err_msgid;

        err_msgid = widget_validate_input_filename(WEDITOR_CTX->input_buffer, WIDGET_SAVE_AS_VALID_CHARS);
        if (err_msgid == 0)
        {
            return 1;
        }
        else
        {
            wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, GetString(err_msgid), fail_callback);
            return 0;
        }
    }
    else if (WEDITOR_CTX->texttype == MsfEmailAddress)
    {
        
        if (!applib_is_valid_email_address_unicode((const kal_wchar*)WEDITOR_CTX->input_buffer))
        {
            wap_entry_widget_editor_message(
                IMG_GLOBAL_ERROR,
                GetString(WIDGET_STR_ID_INPUT_FORMAT_ERROR),
                fail_callback);
            return 0;
        }
    }
    else if (WEDITOR_CTX->texttype == MsfPhoneNumber)
    {
        /* Follow MMS Addressing Model */
        kal_uint16 *ch = (kal_uint16*) WEDITOR_CTX->input_buffer;
        kal_bool match = KAL_TRUE;

        if (*ch == CHR('+'))
        {
            ch++;
        }

        if (*ch == CHR('\0'))
        {
            match = KAL_FALSE;
        }
        else
        {
            do
            {
                if (!widget_ucs2_is_digit(*ch))
                {
                    match = KAL_FALSE;
                    break;
                }
                ch++;
            }
            while (*ch != CHR('\0'));
        }

        if (!match)
        {
            wap_entry_widget_editor_message(
                IMG_GLOBAL_ERROR,
                GetString(WIDGET_STR_ID_INPUT_FORMAT_ERROR),
                fail_callback);
            return 0;
        }
    }

    if (WEDITOR_CTX->input_required == 1 /* 1 true, 0 false, -1 none */  &&
        CHR_AT(WEDITOR_CTX->input_buffer, 0) == CHR(0))
    {
        wap_entry_widget_editor_message(
            IMG_GLOBAL_ERROR,
            GetString(WIDGET_STR_ID_CANT_INPUT_EMPTY_VALUE),
            fail_callback);
        return 0;
    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
	/* Because WCSS editor doesn't support password mark, we need to check the WCSS format all the time */
	if(!widget_is_match_CSS_pattern(WEDITOR_CTX->input_buffer))
	{
	    char * format = (char*)widget_get_input_CSS_format_pattern();

        if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*A") ||
            !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"A*A"))
        {
            /* allow the entry of any uppercase letter, symbol, or punctuation character, Numeric characters are excluded. */
		    wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_A),fail_callback);
        }
        else if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*a") ||
                 !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"a*a"))
        {
            /* allow the entry of any lowercase letter, symbol, or punctuation character, Numeric characters are excluded. */
		    wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_A),fail_callback);
        }
        else if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*X") ||
                 !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"X*X"))
        {
            /* allow the entry of any uppercase letter, numeric, symbol, or punctuation character */
		    wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_X),fail_callback);
        }
        else if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*x") ||
                 !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"x*x"))
        {
            /* allow the entry of any lowercase letter, numeric, symbol, or punctuation character */
		    wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_X),fail_callback);
        }
        else if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*n") ||
                 !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"n*n"))
        {
            /* allow the entry of any numeric, symbol, or punctuation character */
		    wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_N),fail_callback);
        }
        else
        {
		    wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INPUT_FORMAT_ERROR),fail_callback);
        }
		return 0;	
	}
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 

    return 1;
}

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__

#if (CAT115_MAXSIZE - 1 < WIDGET_MAX_INPUT_LEN)
#error "Values of CAT115_MAXSIZE  and WIDGET_MAX_INPUT_LEN are not sync"
#endif 


#ifndef __MMI_TOUCH_SCREEN__

static void wap_entry_WCSS_editor(void);

/*****************************************************************************
 * FUNCTION
 *  wap_exit_WCSS_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_exit_WCSS_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: check if changed

    currHistory.scrnID = WAP_SCREEN_WCSS_EDITOR;
    currHistory.entryFuncPtr = wap_entry_WCSS_editor;
    GetCategoryHistory(currHistory.guiBuffer);
    SET_CHR_AT(currHistory.inputBuffer, 0, 0);
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_WCSS_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_WCSS_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    kal_uint8 *input_format;
    int input_format_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WCSS_EDITOR);

    /* Category115 use UCS2 string for input format */
    if (WEDITOR_CTX->CSS_format)
    {
        input_format_len = app_ucs2_strlen((const kal_int8 *)WEDITOR_CTX->CSS_format);
        input_format_len = (input_format_len + 1) * ENCODING_LENGTH;
        input_format = MSF_MEM_ALLOC(MSF_MODID_WIDGET, input_format_len);
        app_ucs2_strcpy((kal_int8*)input_format, (const kal_int8*)WEDITOR_CTX->CSS_format);
    }
    else
    {
        input_format = (kal_uint8*) L"*m";
        input_format_len = 6;
        WAP_DBG_ASSERT(0);  /* This case should be already prevented */
    }

    EntryNewScreen(WAP_SCREEN_WCSS_EDITOR, wap_exit_WCSS_editor, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(WAP_SCREEN_WCSS_EDITOR);

    ShowCategory115Screen_ext(
        WIDGET_STR_ID_INPUT_TITLE,
        widget_get_title_icon(0),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) WEDITOR_CTX->input_buffer,
        WEDITOR_CTX->input_buffer_max_len,
        (U8*) input_format,
        1,
        WEDITOR_CTX->input_type,
        guiBuffer);

    SetLeftSoftkeyFunction(wap_entry_fullscreen_editor_option, KEY_EVENT_UP);
    SetCategory115RightSoftkeyFunction(widget_exit_fullscreen_editor_with_cancel_level0, KEY_EVENT_UP);

    if (WEDITOR_CTX->CSS_format)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, input_format);
    }
}

#endif /* __MMI_TOUCH_SCREEN__ */

#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 

#ifdef WIDGET_LEAVE_EDITOR_IF_RELEASED
/* We need to leave full screen editor if the WAP page is reloaded (e.g. a script to reload the page periodically) */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_leave_fullscreen_editor_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_leave_fullscreen_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrid = GetExitScrnID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrid == WAP_SCREEN_FULLSCREEN_EDITOR ||
        scrid == WAP_SCREEN_WCSS_EDITOR || scrid == WAP_SCREEN_FULLSCREEN_EDITOR_OPTION)
    {
        GoBackToHistory(WAP_SCREEN_WIDGET);
    }
    else
    {
        DeleteScreenIfPresent(WAP_SCREEN_FULLSCREEN_EDITOR);
        DeleteScreenIfPresent(WAP_SCREEN_WCSS_EDITOR);
        DeleteScreenIfPresent(WAP_SCREEN_FULLSCREEN_EDITOR_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_leave_fullscreen_editor_screen_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_leave_fullscreen_editor_screen_if_present(widget_header_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object && WEDITOR_CTX->active_object == object)
    {
        /* Actually this should not happen */
        /* WAP_DBG_ASSERT(0); */
        WEDITOR_CTX->active_object = NULL;
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;

        if (WIPC_CTX->MMI_is_waiting)
        {
            widget_MMI_leave_fullscreen_editor_screen();
        }
        else
        {
            widget_execute_MMI(widget_MMI_leave_fullscreen_editor_screen, KAL_TRUE);
        }
    }
}
#else /* WIDGET_LEAVE_EDITOR_IF_RELEASED */ 


/*****************************************************************************
 * FUNCTION
 *  widget_leave_fullscreen_editor_screen_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_leave_fullscreen_editor_screen_if_present(widget_header_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object && WEDITOR_CTX->active_object == object)
    {
        /* Actually this should not happen */
        WAP_DBG_ASSERT(0);
        WEDITOR_CTX->active_object = NULL;
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    }
}

#endif /* WIDGET_LEAVE_EDITOR_IF_RELEASED */ 


/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXIT_FULLSCREEN_EDITOR);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    currHistory.scrnID = WAP_SCREEN_FULLSCREEN_EDITOR;
    currHistory.entryFuncPtr = wap_entry_fullscreen_editor;
    GetCategory5History(currHistory.guiBuffer);
    SET_CHR_AT(currHistory.inputBuffer, 0, 0);
    AddHistory(currHistory);

    WEDITOR_CTX->entered = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor_with_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_fullscreen_editor_with_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check the validity of input value
     * * For some cases, we also check input values in widget_set_current_focus()
     */
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!widget_check_fullscreen_editor_input_value(KAL_TRUE))
    {
        return;
    }

    widget_discard_editor_buffer();
    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_DONE;
    WEDITOR_CTX->active_object = NULL;
     /* WEDITOR_CTX->leave_from_fullscreen will be TRUE when leaving from widget fullscreen option menu. */
    WEDITOR_CTX->leave_from_fullscreen = KAL_TRUE;
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor_with_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_fullscreen_editor_with_cancel(int level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    widget_restore_editor_buffer(WEDITOR_CTX->input_buffer);
    widget_discard_editor_buffer();

    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_CANCEL;
    WEDITOR_CTX->active_object = NULL;
     /* WEDITOR_CTX->leave_from_fullscreen will be TRUE when leaving from widget fullscreen option menu. */    WEDITOR_CTX->leave_from_fullscreen = KAL_TRUE;
    GoBacknHistory((U16) level);
}


/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor_with_cancel_level0
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_fullscreen_editor_with_cancel_level0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_exit_fullscreen_editor_with_cancel(0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor_with_cancel_level1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_fullscreen_editor_with_cancel_level1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_exit_fullscreen_editor_with_cancel(1);
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_insert_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_insert_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_direct_input((UI_character_type) c);
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_insert_character_dot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_insert_character_dot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_fullscreen_editor_insert_character(CHR('.'));
}



#ifdef WIDGET_TEST_CHINESE_TEXT_INPUT


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_insert_chinese_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_insert_chinese_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_fullscreen_editor_insert_character(0x4E2D);
    widget_fullscreen_editor_insert_character(0x6587);
    widget_fullscreen_editor_insert_character(0x6E2C);
    widget_fullscreen_editor_insert_character(0x8A66);
    widget_fullscreen_editor_insert_character(0x5B57);
    widget_fullscreen_editor_insert_character(0x4E32);
    widget_fullscreen_editor_insert_character(0x7532);
    widget_fullscreen_editor_insert_character(0x4E59);
    widget_fullscreen_editor_insert_character(0x4E19);
    widget_fullscreen_editor_insert_character(0x4E01);
    widget_fullscreen_editor_insert_character(0x0065);
    widget_fullscreen_editor_insert_character(0x0066);
    widget_fullscreen_editor_insert_character(0x0067);

}
#endif /* WIDGET_TEST_CHINESE_TEXT_INPUT */ 


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_customize_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_customize_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI WCSS editor will disable/enable '#' key by itself */

    switch (WEDITOR_CTX->texttype)
    {
        case MsfIpAddress:
            /* MMI WCSS editor will disable/enable '#' key by itself */
            if (WEDITOR_CTX->disable_switch_IM && !WEDITOR_CTX->CSS_format)
            {
                ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);
                ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
            }
            SetKeyHandler((FuncPtr) widget_fullscreen_editor_insert_character_dot, KEY_POUND, KEY_EVENT_DOWN);
            break;
/*
  We don't special handle the key behavior to sync SMS application
        case MsfPhoneNumber:
            // "MMS Addressing Model" told, the user should also be able to insert '-' and '.'
    #ifndef __MMI_MULTITAP_KEY_0__
            SetKeyHandler((FuncPtr) widget_fullscreen_editor_insert_character_plus, KEY_STAR, KEY_EVENT_DOWN);
    #endif 
            break;
*/
    }
#ifdef WIDGET_TEST_CHINESE_TEXT_INPUT
    SetKeyHandler((FuncPtr) widget_fullscreen_editor_insert_chinese_string, KEY_STAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_STAR, KEY_EVENT_UP);
#endif /* WIDGET_TEST_CHINESE_TEXT_INPUT */ 
}

#ifdef MMS_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_on_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fullscreen_editor_on_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(WIDGET_STR_ID_SEARCH, 0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_on_not_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fullscreen_editor_on_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_search_phonebook_or_ok
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fullscreen_editor_search_phonebook_or_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (CHR_AT(WEDITOR_CTX->input_buffer, 0) == CHR(0)) /* Empty buffer, search phone book */
    {
        if (WEDITOR_CTX->texttype == MsfPhoneNumber)
        {
            EntryPhbFromMMSNumber();    // TODO: send primitive
        }
        else
        {
            EntryPhbFromMMSEmail();
        }
    }
    else    /* Non-empty. Done */
    {
        /* Reference: widget_exit_fullscreen_editor_with_done() */
        if (!widget_check_fullscreen_editor_input_value(KAL_FALSE))
        {
            return;
        }

        widget_discard_editor_buffer();
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_DONE;
        WEDITOR_CTX->active_object = NULL;
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_goback_fullscreen_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_goback_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_GOBACK_FULLSCREEN_EDITOR);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (IsScreenPresent(WAP_SCREEN_FULLSCREEN_EDITOR))
    {
        GoBackToHistory(WAP_SCREEN_FULLSCREEN_EDITOR);  /* Return from phonebook screen */
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_fullscreen_editor_update_from_phonebook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_fullscreen_editor_update_from_phonebook(kal_uint8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Executed from MMI */
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WAP_DBG_ASSERT(!WEDITOR_CTX->entered);
    widget_ucs2_strncpy(WEDITOR_CTX->input_buffer, data, WEDITOR_CTX->input_buffer_max_len * 2);

    WEDITOR_CTX->disable_gui_buffer = KAL_TRUE;

    /* To prevent callback after returning to idle screen */
    if (IsScreenPresent(WAP_SCREEN_FULLSCREEN_EDITOR))
    {
        widget_execute_MMI(widget_MMI_goback_fullscreen_editor, KAL_TRUE);
    }
}

#endif /* MMS_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wap_entry_fullscreen_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 left_softkey = STR_GLOBAL_OPTIONS;
    S16 input_ext_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_FULLSCREEN_EDITOR);

    WEDITOR_CTX->entered = KAL_TRUE;

    EntryNewScreen(WAP_SCREEN_FULLSCREEN_EDITOR, widget_exit_fullscreen_editor, NULL, NULL);

    if (!WEDITOR_CTX->disable_gui_buffer)
    {
        guiBuffer = GetCurrGuiBuffer(WAP_SCREEN_FULLSCREEN_EDITOR);
    }
    else
    {
        /* Disable history such that the cursor will move to the last position */
        guiBuffer = NULL;
        WEDITOR_CTX->disable_gui_buffer = KAL_FALSE;
    }

#ifdef MMS_SUPPORT
#ifdef __MMI_PHB_NO_OPTIONAL_FIELD__
    if (WEDITOR_CTX->texttype == MsfPhoneNumber)
#else 
    if (WEDITOR_CTX->texttype == MsfPhoneNumber || WEDITOR_CTX->texttype == MsfEmailAddress)
#endif 
    {

        if (CHR_AT(WEDITOR_CTX->input_buffer, 0) == CHR(0))
        {
            left_softkey = WIDGET_STR_ID_SEARCH;
        }
        else
        {
            left_softkey = STR_GLOBAL_OK;
        }
    }
#endif /* MMS_SUPPORT */ 

    if (WEDITOR_CTX->texttype == MsfEmailAddress)
    {
#ifdef __MMI_TOUCH_SCREEN__
        /* sync the virtual keypad setting for edit e-Mail address with phone book */
        extern void mmi_phb_op_email_custom_function(void);
        mmi_phb_op_email_custom_function();
#endif /* __MMI_TOUCH_SCREEN__ */
        
        input_ext_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }

    /* Prevent title blinking */
    gui_lock_double_buffer();

    /* If could switch input method, we use the prefered input type */
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    if (WEDITOR_CTX->disable_switch_IM != KAL_TRUE &&
        (WEDITOR_CTX->input_type & INPUT_TYPE_USE_ONLY_ENGLISH_MODES != INPUT_TYPE_USE_ONLY_ENGLISH_MODES))
    {
        /* If input type has INPUT_TYPE_USE_ONLY_ENGLISH_MODES, we don't use prefered input type */
        WEDITOR_CTX->input_type = MMI_prefered_input_type | INPUT_TYPE_OVERRIDE_DEFAULT;
    }
#endif

    ShowCategory5Screen_ext(
        WIDGET_STR_ID_INPUT_TITLE,
        widget_get_title_icon(0),
        left_softkey,
        0,
        STR_GLOBAL_BACK,
        0,
        WEDITOR_CTX->input_type,
        (U8*) WEDITOR_CTX->input_buffer,
        WEDITOR_CTX->input_buffer_max_len,
        guiBuffer,
        input_ext_type,
        NULL,
        NULL);

    if (WEDITOR_CTX->in_replace_mode == WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE)
    {
        /*
         * If WCSS format is "*n" or "*N", 
         * we use Category5Screen but need change to replace mode. 
         */
        multiline_inputbox_toggle_insert_mode();
        WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_IN_REPLACE_MODE;
    }
#ifndef WIDGET_LANDSCAPE_STYLE
/* In Landscape 320x240, we don't have title/status bar in fullscreen editor */
    if (WEDITOR_CTX->title != 0)
    {
        widget_set_title(WEDITOR_CTX->title);
        /* ShowCategory5Screen already use show_title_status_icon() */
        draw_title();
    }
#endif /* #ifndef WIDGET_LANDSCAPE_STYLE */
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

#ifdef MMS_SUPPORT
#ifdef __MMI_PHB_NO_OPTIONAL_FIELD__
    if (WEDITOR_CTX->texttype == MsfPhoneNumber)
#else 
    if (WEDITOR_CTX->texttype == MsfPhoneNumber || WEDITOR_CTX->texttype == MsfEmailAddress)
#endif 
    {
        RegisterInputBoxEmptyFunction(widget_fullscreen_editor_on_empty);
        RegisterInputBoxNotEmptyFunction(widget_fullscreen_editor_on_not_empty);
        SetLeftSoftkeyFunction(widget_fullscreen_editor_search_phonebook_or_ok, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(wap_entry_fullscreen_editor_option, KEY_EVENT_UP);
    }
#else /* MMS_SUPPORT */ 
    SetLeftSoftkeyFunction(wap_entry_fullscreen_editor_option, KEY_EVENT_UP);
#endif /* MMS_SUPPORT */ 

    SetCategory5RightSoftkeyFunction(widget_exit_fullscreen_editor_with_cancel_level0, KEY_EVENT_UP);

    /* customize key */
    widget_fullscreen_editor_customize_key();
}


/*****************************************************************************
 * FUNCTION
 *  widget_enter_fullscreen_editor
 * DESCRIPTION
 *  enter full screen editor and put widget screen into history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enter_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* we only backup the buffer for the first time */
    widget_backup_editor_buffer(WEDITOR_CTX->input_buffer);

    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());   /* It should be invoked from widget_paint_hdlr */

#ifndef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
    wap_entry_fullscreen_editor();

#elif defined (__MMI_WCSS_INPUT_FORMAT_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
    /* WCSS editor (Category115Screen) only supported in non touch screen project */
    wap_entry_fullscreen_editor();

#else /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 
    if (WEDITOR_CTX->CSS_format)
    {
        wap_entry_WCSS_editor();
    }
    else
    {
        wap_entry_fullscreen_editor();
    }
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 
}

/******************************************************************************
 * Internal dialog category screen 
 ******************************************************************************/

/*
 * Since we do not enter a new category screen for dialog, 
 * * There is no explicit exit point of this category 123 since we might close the window by MsfAction
 * * As a result, we just call gui_hide_animations() in widget_paint
 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/*
 * Be very careful that we do not put widget screen into history on invoking widget_ShowCategory123Screen
 * However, we will temporarily override RedrawCategoryFunction as widget_RedrawCategory123Screen()
 */


/*****************************************************************************
 * FUNCTION
 *  widget_RedrawCategory123Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_RedrawCategory123Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

#ifdef __MMI_CHANGABLE_FONT__
    U8 old_font_size;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    gui_hide_animations();
    x1 = MMI_pop_up_dialog_x;
    y1 = MMI_pop_up_dialog_y;
    x2 = x1 + MMI_pop_up_dialog_width - 1;
    y2 = y1 + MMI_pop_up_dialog_height - 1;
    gui_reset_clip();
    wgui_draw_pop_up_screen_background(x1, y1, x2, y2, &wgui_pop_up_dialog_background, MMI_FALSE);

#ifdef __GDI_MEMORY_PROFILE_2__
	if (wgui_layer_1 == (gdi_handle) NULL)
	{
		/* Create layer fail */
		if (gdi_layer_create(0, 0, UI_device_width, UI_device_height, &wgui_layer_1) < 0)
		{
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
			return;
		}
	}

	gdi_layer_push_and_set_active(wgui_layer_1);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(TRUE, (U8)(current_MMI_theme->bg_opacity_full));
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#endif /* __GDI_MEMORY_PROFILE_2__ */

#ifdef __MMI_CHANGABLE_FONT__
    old_font_size = MMI_multiline_inputbox.text_font->size;
    MMI_multiline_inputbox.text_font->size = MEDIUM_FONT;

    show_multiline_inputbox();

    MMI_multiline_inputbox.text_font->size = old_font_size;
#else /* __MMI_CHANGABLE_FONT__ */ 
    show_multiline_inputbox();
#endif /* __MMI_CHANGABLE_FONT__ */ 

    gui_set_clip(x1 + 2, y1 + 2, x2 - 2, y2 - 2);
    wgui_show_transparent_animation();

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
    gdi_image_abm_set_source_layer(wgui_base_layer);
    gdi_layer_set_blt_layer(wgui_base_layer, wgui_layer_1, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */

    show_softkey_background();
    show_left_softkey();
    show_right_softkey();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ShowCategory123Screen_Common
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_bottom            [IN]        
 *  title                   [IN]        
 *  title_icon              [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  message                 [IN]        
 *  message_icon            [IN]        
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ShowCategory123Screen_Common
    (int image_bottom,
     U16 title, U16 title_icon, U16 left_softkey, U16 left_softkey_icon,
     U16 right_softkey, U16 right_softkey_icon, UI_string_type message, U16 message_icon, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l, fh;
    PU8 image;
    S32 width = 0, height = 0;
    S32 inputbox_h;
    S32 dialog_width = MMI_pop_up_dialog_width - 2*UI_POPUP_BORDER_SIZE;
    S32 x = MMI_pop_up_dialog_x + UI_POPUP_BORDER_SIZE;
    S32 y = MMI_pop_up_dialog_y + UI_POPUP_BORDER_SIZE;
    S32 dialog_y = MMI_pop_up_dialog_y + UI_POPUP_BORDER_SIZE;
    S32 dialog_height = MMI_pop_up_dialog_height - 2*UI_POPUP_BORDER_SIZE;
#ifdef __MMI_CHANGABLE_FONT__
    U8 old_font_size;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_integrated_register_redraw(NULL);
#endif
#if defined (WIDGET_RESIDENT_STATUS_ICON)

    if (WGUI_CTX->current_window && WGUI_CTX->current_dialog &&
        _W(WGUI_CTX->current_window) == _W(WGUI_CTX->current_dialog) &&
        (WGUI_CTX->current_dialog->property_mask & MSF_WINDOW_PROPERTY_EXT_STATUS_ICON))
    {
        /*
         * widget will clear the screen in widget_paint_object (WIDGET_DIALOG_TYPE) and 
         * we need to show the status bar in MsfDialog
         */
    }
    else
    {
        /*
         * If MsfDialog's background isn't blank, we don't want to show the status here.
         * The widget handles status icon bars by itself (WAP task controls), 
         * but sometimes MMI task will updates at the same time. (ex. have blinking icons).
         * It causes the background of the status bar is white color not the wallpaper image.
         * We will hide status icon when the window changed focus and draw the status bar in widget_paint.
         */
        hide_status_icon_bar(0);
    }
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 

    gui_lock_double_buffer();

    MMI_menu_shortcut_number = -1;
    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    image = get_image(message_icon);
    gui_measure_image(image, &width, &height);
    MMI_message_string = (UI_string_type) message;  /* get_string(message); */
    l = gui_strlen(MMI_message_string);
    create_multiline_inputbox_set_buffer(MMI_message_string, l, l, 0);
    MMI_multiline_inputbox.normal_text_color = *current_MMI_theme->popup_text_color;
    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
         UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR);
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;
    resize_multiline_inputbox(dialog_width, dialog_height);
    show_multiline_inputbox_no_draw();

#ifdef __MMI_CHANGABLE_FONT__
    old_font_size = MMI_multiline_inputbox.text_font->size;
    MMI_multiline_inputbox.text_font->size = MEDIUM_FONT;
#endif /* __MMI_CHANGABLE_FONT__ */ 

    gui_set_font(MMI_multiline_inputbox.text_font);
    fh = get_multiline_inputbox_line_height();
    if (image == NULL)
    {
        inputbox_h = (MMI_multiline_inputbox.n_lines * fh) + MMI_multiline_inputbox.text_y + MULTILINE_INPUTBOX_HEIGHT_PAD;

        /* Line height of multi-line inputbox is font height + 1 */
        inputbox_h = (inputbox_h < (dialog_height)) 
                        ? inputbox_h 
                        : (dialog_height);
        resize_multiline_inputbox(
            MMI_multiline_inputbox.width,
            inputbox_h);
        y = dialog_y + ((dialog_height - MMI_multiline_inputbox.height) >> 1);
    }
    else
    {
        inputbox_h = (MMI_multiline_inputbox.n_lines * fh) + MMI_multiline_inputbox.text_y + MULTILINE_INPUTBOX_HEIGHT_PAD;

        inputbox_h = (inputbox_h < (dialog_height - height)) 
                        ? inputbox_h 
                        : (dialog_height - height);
        resize_multiline_inputbox(MMI_multiline_inputbox.width, inputbox_h);

        y = dialog_y + (dialog_height >> 1) - ((MMI_multiline_inputbox.height + height) >> 1);
    }
    
    if (y < dialog_y)
    {
        y = dialog_y;
    }
    if (!image_bottom)
    {
        wgui_set_animation_image_y((UI_device_width >> 1), y, image);
        if (image == NULL)
        {
            move_multiline_inputbox(x, y);
        }
        else
        {
            move_multiline_inputbox(x, y + height);
        }
    }
    else
    {
        /* should have the image */
        move_multiline_inputbox(x, y);
        wgui_set_animation_image_y((UI_device_width >> 1), y + MMI_multiline_inputbox.height, image);
    }
#ifdef __MMI_CHANGABLE_FONT__
    MMI_multiline_inputbox.text_font->size = old_font_size;
#endif 

    gui_unlock_double_buffer();
    /* We do not create a new screen in addition to widget */

    widget_RedrawCategory123Screen();
}


/*****************************************************************************
 * FUNCTION
 *  widget_ShowCategory123Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                   [IN]        
 *  title_icon              [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  message                 [IN]        
 *  message_icon            [IN]        
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ShowCategory123Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        UI_string_type message,
        U16 message_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ShowCategory123Screen_Common
        (0,
         title, title_icon, left_softkey, left_softkey_icon,
         right_softkey, right_softkey_icon, message, message_icon, history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ShowCategory123Screen_ImageBottom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                   [IN]        
 *  title_icon              [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  message                 [IN]        
 *  message_icon            [IN]        
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ShowCategory123Screen_ImageBottom
    (U16 title, U16 title_icon, U16 left_softkey, U16 left_softkey_icon,
     U16 right_softkey, U16 right_softkey_icon, UI_string_type message, U16 message_icon, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ShowCategory123Screen_Common
        (1,
         title, title_icon, left_softkey, left_softkey_icon,
         right_softkey, right_softkey_icon, message, message_icon, history_buffer);
}

/******************************************************************************
 * Fullscreen menu
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_radio_menu_okay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_radio_menu_okay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (menu != NULL)
    {
        widget_notify(_H(menu), MsfNotifyStateChange);

        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                    if (cnt == WENTER_MENU_CTX->highlighted)
                        enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED); 
                    cnt++;
                }
            }
        );

        menu->highlight_index = -1;
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_OK;
        widget_goback_to_widget_screen();
    }
    else
    {
        widget_goback_to_widget_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_radio_menu_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_radio_menu_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (WENTER_MENU_CTX->target_menu != NULL)
    {
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_CANCEL;
        widget_goback_to_widget_screen();
    }
    else
    {
        widget_goback_to_widget_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_widget_fullscreen_radio_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void highlight_widget_fullscreen_radio_menu(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WENTER_MENU_CTX->highlighted = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_radio_menu_get_item_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pBOOL widget_fullscreen_radio_menu_get_item_hdlr(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;
    MsfStringHandle string1 = 0;
    int cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu == NULL || item_index < 0 || item_index >= menu->menu_items_sum)
    {
        /* WAP_DBG_ASSERT(0); */
        SET_CHR_AT(str_buff, 0, 0);
        *img_buff_p = NULL;
        return TRUE;
    }
    else
    {
        /* widget_get_childs_by_index(node, menu, item_index); */
        cnt = 0;
        foreach(_H(menu), CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (cnt == item_index)
                    {
                        string1 = node->string1;
                    }
                    cnt++;
                }
            }
        );

        if (string1 == 0)
        {
            SET_CHR_AT(str_buff, 0, 0);
        }
        else
        {
            widget_ucs2_strncpy((kal_uint8*) str_buff, widget_string_content(string1), MAX_SUB_MENU_SIZE);
        }

        *img_buff_p = get_image((MMI_ID_TYPE)
                                ((item_index ==
                                  WENTER_MENU_CTX->last_highlighted) ? RADIO_ON_IMAGE_ID : RADIO_OFF_IMAGE_ID));
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_fullscreen_radio_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_fullscreen_radio_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_FULLSCREEN_RADIO_MENU);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    EntryNewScreen(WAP_SCREEN_OPTION_GROUP, NULL, wap_entry_fullscreen_radio_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(WAP_SCREEN_OPTION_GROUP);

    if (!WENTER_MENU_CTX->target_menu)
    {
        /* Abnormal case. Be paranoid. */
        WAP_DBG_ASSERT(0);
        SetGroupKeyHandler(GoBackHistory, widget_all_keys, MAX_KEYS, KEY_EVENT_UP);
        return;
    }

    RegisterHighlightHandler(highlight_widget_fullscreen_radio_menu);
    ShowCategory184Screen(
        STR_GLOBAL_OPTIONS,
        widget_get_title_icon(0),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WENTER_MENU_CTX->target_menu->menu_items_sum,
        widget_fullscreen_radio_menu_get_item_hdlr,
        NULL,
        WENTER_MENU_CTX->last_highlighted,
        guiBuffer);

    SetLeftSoftkeyFunction(widget_fullscreen_radio_menu_okay, KEY_EVENT_UP);
    SetRightSoftkeyFunction(widget_fullscreen_radio_menu_back, KEY_EVENT_UP);
    /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
    SetKeyHandler(widget_fullscreen_radio_menu_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_checkbox_menu_okay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_checkbox_menu_okay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (menu != NULL)
    {
        WAP_DBG_ASSERT(menu->checkbox_menu_list_state != NULL);
        widget_notify(_H(menu), MsfNotifyStateChange);
        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (menu->checkbox_menu_list_state[cnt])
                    {
                        disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                        enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    else
                    {
                    disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    if (cnt == WENTER_MENU_CTX->highlighted)
                    {
                    enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                    }
                    cnt++;
                }
            }
        );

        MSF_MEM_FREE(MSF_MODID_WIDGET, menu->checkbox_menu_list_state);
        menu->checkbox_menu_list_state = NULL;
        menu->highlight_index = -1;

        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_OK;
        widget_goback_to_widget_screen();
    }
    else
    {
        if (menu->checkbox_menu_list_state != NULL)
        {
            MSF_MEM_FREE(MSF_MODID_WIDGET, menu->checkbox_menu_list_state);
            menu->checkbox_menu_list_state = NULL;
        }
        widget_goback_to_widget_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_checkbox_menu_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_checkbox_menu_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (WENTER_MENU_CTX->target_menu != NULL)
    {
        if (WENTER_MENU_CTX->target_menu->checkbox_menu_list_state != NULL)
        {
            MSF_MEM_FREE(MSF_MODID_WIDGET, WENTER_MENU_CTX->target_menu->checkbox_menu_list_state);
            WENTER_MENU_CTX->target_menu->checkbox_menu_list_state = NULL;
        }
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_CANCEL;
        widget_goback_to_widget_screen();
    }
    else
    {
        widget_goback_to_widget_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_widget_fullscreen_checkbox_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void highlight_widget_fullscreen_checkbox_menu(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WENTER_MENU_CTX->highlighted = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_checkbox_menu_get_item_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  str_buff        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pBOOL widget_fullscreen_checkbox_menu_get_item_hdlr(S32 item_index, UI_string_type str_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;
    MsfStringHandle string1 = 0;
    int cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu == NULL || item_index < 0 || item_index >= menu->menu_items_sum)
    {
        /* WAP_DBG_ASSERT(0); */
        SET_CHR_AT(str_buff, 0, 0);
        return TRUE;
    }
    else
    {
        /* widget_get_childs_by_index(node, menu, item_index); */
        cnt = 0;
        foreach(_H(menu), CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (cnt == item_index)
                    {
                        string1 = node->string1;
                    }
                    cnt++;
                }
            }
        );

        if (string1 == 0)
        {
            SET_CHR_AT(str_buff, 0, 0);
        }
        else
        {
            widget_ucs2_strncpy((kal_uint8*) str_buff, widget_string_content(string1), MAX_SUB_MENU_SIZE);
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_exit_fullscreen_checkbox_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_exit_fullscreen_checkbox_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu != NULL &&
        WENTER_MENU_CTX->state != WIDGET_ENTER_MENU_RETURN_OK &&
        WENTER_MENU_CTX->state != WIDGET_ENTER_MENU_RETURN_CANCEL)
    {
        WAP_DBG_ASSERT(menu->checkbox_menu_list_state != NULL);
        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (menu->checkbox_menu_list_state[cnt])
                    {
                        disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                        enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    else
                    {
                    disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    if (cnt == WENTER_MENU_CTX->highlighted)
                    {
                    enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                    }
                    cnt++;
                }
            }
        );

    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_fullscreen_checkbox_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_fullscreen_checkbox_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_FULLSCREEN_CHECKBOX_MENU);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    EntryNewScreen(WAP_SCREEN_MULTIPLE_OPTION_GROUP, wap_exit_fullscreen_checkbox_menu, wap_entry_fullscreen_checkbox_menu, guiBuffer);

    guiBuffer = GetCurrGuiBuffer(WAP_SCREEN_MULTIPLE_OPTION_GROUP);

    if (!WENTER_MENU_CTX->target_menu)
    {
        /* Abnormal case. Be paranoid. */
        WAP_DBG_ASSERT(0);
        SetGroupKeyHandler(GoBackHistory, widget_all_keys, MAX_KEYS, KEY_EVENT_UP);
        return;
    }

    if (WENTER_MENU_CTX->target_menu->checkbox_menu_list_state == NULL)
    {
        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state = MSF_MEM_ALLOC(MSF_MODID_WIDGET, WENTER_MENU_CTX->target_menu->menu_items_sum * sizeof(U8));
        memset(
            WENTER_MENU_CTX->target_menu->checkbox_menu_list_state,
            0,
            WENTER_MENU_CTX->target_menu->menu_items_sum * sizeof(U8));
    }

    {
        int cnt = 0;
        widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
        widget_choice_element_struct *node;

        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (node->state & MSF_CHOICE_ELEMENT_SELECTED == MSF_CHOICE_ELEMENT_SELECTED)
                    {
                        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state[cnt] = 1;
                    }
                    else
                    {
                        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state[cnt] = 0;
                    }
                    cnt++;
                }
            }
        );
    }

    RegisterHighlightHandler(highlight_widget_fullscreen_checkbox_menu);
    SetCheckboxToggleRightSoftkeyFunctions(widget_fullscreen_checkbox_menu_okay, widget_fullscreen_checkbox_menu_back);
    ShowCategory186Screen(
        STR_GLOBAL_OPTIONS,
        widget_get_title_icon(0),
        WENTER_MENU_CTX->target_menu->menu_items_sum,
        widget_fullscreen_checkbox_menu_get_item_hdlr,
        NULL,
        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state,
        WENTER_MENU_CTX->last_highlighted,
        guiBuffer);
    /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
    SetKeyHandler(widget_fullscreen_checkbox_menu_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  widget_enter_fullscreen_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enter_fullscreen_menu(widget_menu_struct *menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WENTER_MENU_CTX->target_menu == menu);
    WENTER_MENU_CTX->target_menu = menu;

    if (WENTER_MENU_CTX->target_menu->choice_type == MsfExclusiveChoice)
    {
        WENTER_MENU_CTX->highlighted = -1;

        foreach(_H(menu), CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                if (node->state & MSF_CHOICE_ELEMENT_SELECTED)
                {
                    WENTER_MENU_CTX->highlighted = cnt;
                }
                cnt++;}
            }
        );

        if (WENTER_MENU_CTX->highlighted < 0)
        {
            WENTER_MENU_CTX->highlighted = 0;
        }
        WENTER_MENU_CTX->last_highlighted = WENTER_MENU_CTX->highlighted;

        WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());   /* It should be invoked from widget_paint_hdlr */
        // if (widget_in_WAP_screens())         /* Prevent invoked in idle screen */
        wap_entry_fullscreen_radio_menu();
    }
    else if (WENTER_MENU_CTX->target_menu->choice_type == MsfMultipleChoice)
    {
        WENTER_MENU_CTX->highlighted = 0;
        WENTER_MENU_CTX->last_highlighted = WENTER_MENU_CTX->highlighted;

        WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());   /* It should be invoked from widget_paint_hdlr */
        wap_entry_fullscreen_checkbox_menu();
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_init_fullscreen_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_fullscreen_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(WENTER_MENU_CTX, 0, sizeof(widget_enter_menu_struct));
}

/******************************************************************************
 * Push Indicator
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  bra_psl_set_push_indicator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bra_psl_set_push_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mmiapi_unread_push_icon_ind_struct *p =
        (mmiapi_unread_push_icon_ind_struct*) construct_local_para(
                                                (kal_uint16) sizeof(mmiapi_unread_push_icon_ind_struct),
                                                0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->on_off = 1;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_UNREAD_PUSH_ICON_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  bra_psl_cancel_push_indicator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bra_psl_cancel_push_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mmiapi_unread_push_icon_ind_struct *p =
        (mmiapi_unread_push_icon_ind_struct*) construct_local_para(
                                                (kal_uint16) sizeof(mmiapi_unread_push_icon_ind_struct),
                                                0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->on_off = 0;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_UNREAD_PUSH_ICON_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/******************************************************************************
 * Download notification
 ******************************************************************************/
#if 0   /* Deprecated */
#if WAP_DOWNLOAD_FILE_NAME_MAXLEN < STR_SIZE(MSF_CFG_VIRTUAL_FILE_NAME_LENGTH + 1)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_IMELODY_SUPPORT__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/******************************************************************************
 * File Manager Integration
 ******************************************************************************/
// TODO: 1. If file manager is formating filesystem, and it returns to idle screen abnormally, then we can not enter file manager 
// TODO: 2. What if mmi_fmgr_select_path_and_enter returns immediately because device is busy?
// TODO: 3. Record the last visited path as starting point next time

static void widget_MMI_fmgr_enter_media_input(void);
static void widget_MMI_fmgr_media_input_done_hdlr(void *in_ptr, int is_short);
static void widget_fmgr_close_media_input(void);

static void widget_fmgr_close_get_save_path(void);
static void widget_MMI_fmgr_enter_get_save_path(void);
static void widget_fmgr_get_save_filename_callback(void);
static void widget_MMI_fmgr_get_save_path_done_hdlr(void *in_ptr, int is_short);
static void widget_MMI_savename_editor_cancel(void);
static void widget_MMI_savename_editor_done(void);
static void widget_savename_editor_highlight_done(void);
static void widget_savename_editor_highlight_cancel(void);
static void widget_savename_editor_highlight_input_method(void);
static void wap_entry_save_filename_editor_option(void);
static void wap_entry_save_filename_editor(void);


/*****************************************************************************
 * FUNCTION
 *  widget_init_fmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_fmgr(void)
{
#ifdef __MMI_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(WFMGR_CTX, 0, sizeof(widget_fmgr_struct));

    WFMGR_CTX->default_path = widget_ucs2_strdup(MSF_MODID_WIDGET, (kal_uint8*) L"root");

#ifdef __DRM_V01__
    HDIa_fileMkDir(WIDGET_DRM_TMP_FOLDER_MSF);
    msm_remove_files_under_dir(WIDGET_DRM_TMP_FOLDER_MSF);
#endif /* __DRM_V01__ */ 

#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_fmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_fmgr(void)
{
#ifdef __MMI_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WFMGR_CTX->default_path)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, WFMGR_CTX->default_path);
        WFMGR_CTX->default_path = NULL;
    }

    widget_fmgr_close_media_input();
    widget_fmgr_close_get_save_path();
#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_fmgr_enter_media_input
 * DESCRIPTION
 *  Choose a file/folder from file manager
 *  
 *  If the operation is aborted, we pass "callback" with argument "pathname" as NULL.
 *  
 *  Scenario to consider:
 *  o WAP invokes this API again when FMGR has not returned
 *  o FMGR go back history without callback
 *  o FMGR invoke callback for more than one times
 *  o End key in FMGR
 *  o FMGR -> (forward to MMS) MMS -> (Insert Image) FMGR
 *  
 *  Our solution: No mather how many times this API is invoked, we will invoke callback function
 *  for atmost one time during the operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Reference: HDIa_widgetExtMimeTypeToFileExt */
static void widget_MMI_fmgr_enter_media_input(void)
{
#ifdef __MMI_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_ENTER_MEDIA_INPUT);

    if (widget_allow_create_new_MMI_screen())
    {
        mmi_fmgr_select_path_and_enter(
            APP_MESSAGES,
            FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
            WIPC_CTX->fmgr_input_filter,
            (PS8) /* L"root" */ WFMGR_CTX->default_path,
            (PsExtFuncPtr) widget_MMI_fmgr_media_input_done_hdlr);
    }

    FMGR_FILTER_INIT(&WIPC_CTX->fmgr_input_filter);

#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFmgrMediaInput
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mime_types      [IN]        
 *  callback        [IN]        
 *  arg             [IN]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtFmgrMediaInput(const char *mime_types, widget_fmgr_input_callback callback, void *arg)
{
#ifdef __MMI_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    kal_bool is_match;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_allow_create_new_MMI_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FMGR_MEDIA_INPUT_NOT_ALLOW);
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FMGR_MEDIA_INPUT);
    WAP_DBG_ASSERT(!WFMGR_CTX->input_callback && !WFMGR_CTX->input_arg);

    /* init filter */
    FMGR_FILTER_INIT(&filter);

    is_match = KAL_TRUE;

#define WIDGET_SET_FMGR_FILTER(_type) \
   do {FMGR_FILTER_SET(&filter, _type); is_match = KAL_TRUE;} while(0)

    /* We might also need to support plain text because MEA MOB use it */
#ifdef WIDGET_JPEG_SUPPORT
    if (strstr(mime_types, "jpeg"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_JPG);
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_JPEG);
    }
#endif /* WIDGET_JPEG_SUPPORT */ 
    if (strstr(mime_types, "gif"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_GIF);
    }
    if (strstr(mime_types, "wbmp"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_WBMP);
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_WBM);
    }
    if (strstr(mime_types, "mid"))  /* Including "audio/mid" */
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_MID);
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_MIDI);
    }
    if (strstr(mime_types, "amr"))  /* Assume audio/amr is okay even the parameter is audio/amr-wb */
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_AMR);
    }
#ifdef __MMI_VCARD__
    if (strstr(mime_types, "vcard"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_VCF);
    }
#endif /* __MMI_VCARD__ */ 
#ifdef __MMI_VCALENDAR__
    if (strstr(mime_types, "vcalendar"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_VCS);
    }
#endif /* __MMI_VCALENDAR__ */ 
#ifdef MP4_CODEC
    if (strstr(mime_types, "video/mp4"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_MP4);
    }
    if (strstr(mime_types, "video/mpeg"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_MPG);
    }
    if (strstr(mime_types, "3gp"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_3GP);
    }
    if (strstr(mime_types, "3gpp2"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_3G2);
    }
#endif /* MP4_CODEC */ 

    if (strstr(mime_types, "application/text"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_EBOOK_TXT);
    }

	if (strstr(mime_types, "text/plain"))
	{
		WIDGET_SET_FMGR_FILTER(FMGR_TYPE_EBOOK_TXT);
	}

	if (strstr(mime_types, "chemical/x-pdb"))
	{
		WIDGET_SET_FMGR_FILTER(FMGR_TYPE_EBOOK_PDB);
	}

  	if (strstr(mime_types, "audio/vm"))
	{
		WIDGET_SET_FMGR_FILTER(FMGR_TYPE_VM);
	}

  	if (strstr(mime_types, "application/vnd.mtk.ems"))
	{
		WIDGET_SET_FMGR_FILTER(FMGR_TYPE_EMS);
	}
    
	if (strstr(mime_types, "application/mbc"))
	{
		WIDGET_SET_FMGR_FILTER(FMGR_TYPE_MBC);
	}

    if (strstr(mime_types, "application/vnd.mtk.mbc"))
	{
		WIDGET_SET_FMGR_FILTER(FMGR_TYPE_MBC);
	}


    if (strstr(mime_types, "mtk/med.thm"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_THEME);
    }

#ifdef __DRM_V02__
    if (strstr(mime_types, "application/vnd.oma.drm.dcf"))
    {
        WIDGET_SET_FMGR_FILTER(FMGR_TYPE_ODF);
    }
#endif /*__DRM_V02__*/

#ifdef MMS_SUPPORT
    if (meaConfGetCreationMode() == MEA_CREATION_MODE_FREE)
    {
#endif /* MMS_SUPPORT */ 
        if (strstr(mime_types, "bmp"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_BMP);
        }
    #ifdef GDI_USING_PNG
        if (strstr(mime_types, "png"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_PNG);
        }
    #endif /* GDI_USING_PNG */ 
        if (strstr(mime_types, "wav"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_WAV);
        }
        if (strstr(mime_types, "imelody"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_IMY);
        }
    #ifdef YAMAHA_MA3
        if (strstr(mime_types, "smaf"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_MMF);
        }
    #endif /* YAMAHA_MA3 */
    #ifdef DAF_DECODE
        if (strstr(mime_types, "mp3") || strstr(mime_types, "audio/mpeg"))      /* with disagreement */
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_DAF);
        }
    #endif /* DAF_DECODE */ 
    #ifdef MJPG_SUPPORT
        if (strstr(mime_types, "video/x-msvideo"))  /* with disagreement */
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_AVI);
        }
    #endif /* MJPG_SUPPORT */ 
    #ifdef AMRWB_DECODE
        if (strstr(mime_types, "amr-wb"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_AWB);
        }
    #endif /* AMRWB_DECODE */ 
    #ifdef WMA_DECODE
        if (strstr(mime_types, "wma"))  /* with disagreement */
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_WMA);
        }
    #endif /* WMA_DECODE */ 
    #ifdef AAC_DECODE
        if (strstr(mime_types, "audio/aac"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_AAC);
        }
        if (strstr(mime_types, "m4a"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_M4A);
        }
    #endif /* AAC_DECODE */ 
    #ifdef AIFF_DECODE
        if (strstr(mime_types, "aiff"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_AIF);
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_AIFF);
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_AIFC);
        }
    #endif
    #ifdef AU_DECODE
        if (strstr(mime_types, "audio/basic"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_AU);
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_SND);
        }
    #endif

    #ifdef __J2ME__
        if (strstr(mime_types, "text/vnd.sun.j2me.app-descriptor"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_JAD);
        }

        if (strstr(mime_types, "application/java-archive"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_JAR);
        }
    #endif
        if (strstr(mime_types, "application/vnd.mtk.lrc"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_LRC);
        }

    #ifdef SVG_SUPPORT
        if (strstr(mime_types, "image/svg+xml"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_SVG);
        }
    #endif /* SVG_SUPPORT */ 
    #ifdef M3D_SUPPORT
        if (strstr(mime_types, "application/vnd.mtk.m3d"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_M3D);
        }
    #endif /* M3D_SUPPORT */ 
    #ifdef __MMI_EBOOK_READER__
        if (strstr(mime_types, "application/x-pilot-pdb"))
        {
            WIDGET_SET_FMGR_FILTER(FMGR_TYPE_EBOOK_PDB);
        }
    #endif

    #ifdef MMS_SUPPORT
    }
    #endif 

    if (is_match == KAL_FALSE)
    {
        return KAL_FALSE;
    }

    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    WFMGR_CTX->input_callback = callback;
    WFMGR_CTX->input_arg = arg;

    WIPC_CTX->fmgr_input_filter = filter;

    widget_execute_MMI(widget_MMI_fmgr_enter_media_input, KAL_TRUE);

#endif /* __MMI_FILE_MANAGER__ */ 

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFmgrMediaInputAbort
 * DESCRIPTION
 *  Disable the next callback of file manager
 *  But we do not leave FMGR screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFmgrMediaInputAbort(void)
{
#ifdef __MMI_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FMGR_MEDIA_INPUT_ABORT);

    /*
     * widget_fmgr_close_media_input prevents it  from invoking callback function 
     * * We do not go back history here because this function will be invoked when MEA UI is shutdown
     */
    widget_fmgr_close_media_input();
#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_fmgr_media_input_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_ptr          [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_fmgr_media_input_done_hdlr(void *in_ptr, int is_short)
{
#ifdef __MMI_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len = 0;
    char *input_result_pathname = NULL;
    kal_bool ret = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_MEDIA_INPUT_DONE_HDLR);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!WFMGR_CTX->input_callback) /* Otherwise, operation canceled */
    {
        /* Operation canceled. Don't use callback. */
        return;
    }

    /* NOTE: WAP and MMI have the same priority, and hence we can use WAP memory allocator in MMI task */
    if (in_ptr == NULL || CHR_AT(in_ptr, 0) == CHR(0))
    {
        input_result_pathname = NULL;
    }
    else
    {
        if (is_short)
        {
            kal_uint8 *ucs2_buf = NULL;
            int        ucs2_buf_len = 0;
            int        input_len = 0;
            int        i = 0, index = 0;
            
            len = widget_ucs2_length((kal_uint8*) in_ptr) * 3; /* worst case */
            input_result_pathname = MSF_MEM_ALLOC(MSF_MODID_WIDGET, len + HDI_EXTERNAL_LEN + 1);
            strcpy(input_result_pathname, HDI_EXTERNAL_PATH);

            ucs2_buf_len = len + (HDI_EXTERNAL_LEN + 1) * ENCODING_LENGTH;
            ucs2_buf = MSF_MEM_ALLOC(MSF_MODID_WIDGET, ucs2_buf_len);
            memset(ucs2_buf, 0, ucs2_buf_len);
            
            input_len = widget_ucs2_length(in_ptr) * 2;
            widget_ucs2_strncpy(
                (kal_uint8*) ucs2_buf, 
                (const kal_uint8*)in_ptr, 
                (input_len>ucs2_buf_len)?ucs2_buf_len:input_len);
            /* find the last "\" because only file name is local encoding format (path is in UCS2 format) */
            for (i = 0; i < (ucs2_buf_len >> 1); i++)
            {
                if ( *(kal_uint16*)(ucs2_buf+i*2) == 0x002F || *(kal_uint16*)(ucs2_buf+i*2) == 0x005C) /* '/' or '\' */
                {
                    index = i*2;
                }
            }

            mmi_chset_mixed_text_to_ucs2_str(
                (kal_uint8*) ucs2_buf+index,
                (kal_int16)ucs2_buf_len,
                (kal_uint8*) in_ptr+index,
                PhnsetGetDefEncodingType());

            widget_ucs2_to_utf8_string(
                (kal_uint8*) input_result_pathname + HDI_EXTERNAL_LEN,
                len + 1,
                (kal_uint8*) ucs2_buf);

            MSF_MEM_FREE(MSF_MODID_WIDGET, ucs2_buf);
        }
        else
        {
            len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) in_ptr);
            input_result_pathname = MSF_MEM_ALLOC(MSF_MODID_WIDGET, len + HDI_EXTERNAL_LEN + 1);
            strcpy(input_result_pathname, HDI_EXTERNAL_PATH);

            widget_ucs2_to_utf8_string(
                (kal_uint8*) input_result_pathname + HDI_EXTERNAL_LEN,
                len + 1,
                (kal_uint8*) in_ptr);
        }
    }

    WFMGR_CTX->input_arg = (void*)&ret;
    WFMGR_CTX->input_callback(input_result_pathname, WFMGR_CTX->input_arg);

    if (input_result_pathname)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, input_result_pathname);
        input_result_pathname = NULL;
    }

    if (ret == KAL_TRUE)    /* WFMGR_CTX->input_arg = (void *)&ret; */
    {
        fmgr_reset_app_select();

        if (IsScreenPresent(WAP_SCREEN_WIDGET))
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_MEDIA_INPUT_DONE_HDLR_GOBACK_TO_WIDGET_SCREEN);

            GoBackToHistory(WAP_SCREEN_WIDGET);
        }
        else
        {
            if (!WGUI_CTX->is_widget_screen)
            {
                /*
                 * Something wrong happened. GoBackHistory() 
                 * * Otherwise, the screen may hang.
                 * * 2004.04.09 FMGR has a bug that might cause this.
                 */
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_MEDIA_INPUT_DONE_HDLR_GOBACK_HIST);
                WAP_DBG_ASSERT(0);

                if (!g_idle_context.IsOnIdleScreen)
                {
                    GoBackHistory();
                }
            }
        }

        widget_fmgr_close_media_input();

        widget_send_update_event_to_wap();  /* Otherwise, WAP won't process new signal in internal queue */
    }
#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_fmgr_close_media_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fmgr_close_media_input(void)
{
#ifdef __MMI_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WFMGR_CTX->input_callback = NULL;
    WFMGR_CTX->input_arg = NULL;
#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFmgrGetSaveFileName
 * DESCRIPTION
 *  Choose a filename to save from file manager
 *  
 *  If the operation is aborted, we pass "callback" with argument "pathname" as NULL.
 *  
 *  Scenario to consider:
 *  o WAP invokes this API again when FMGR has not returned
 *  o FMGR go back history without callback
 *  o FMGR invoke callback for more than one times
 *  o End key in FMGR
 *  o FMGR -> (forward to MMS) MMS -> (Save Image) FMGR
 *  
 *  Our solution: No mather how many times this API is invoked, we will invoke callback function
 *  for atmost one time during the operation.
 * PARAMETERS
 *  suggested_name      [IN]        Suggested filename (might be NULL)
 *  mime_type           [IN]        
 *  callback            [IN]        Callback function after the operation is completed or aborted
 *  arg                 [IN]        Passed to the callback function later
 * RETURNS
 *  kal_bool
 *****************************************************************************/
// TODO: 1. Reentrance 
// TODO: 2. Handling NAND flahs?

#ifdef __MMI_FILE_MANAGER__

#if (MSF_CFG_FILE_NAME_LENGTH> FMGR_MAX_INPUT_FILE_LEN)
#error "Values of MSF_CFG_FILE_NAME_LENGTH and FMGR_MAX_INPUT_FILE_LEN are not sync"
#endif 

#if (MSF_CFG_FILE_NAME_LENGTH > WIDGET_MAX_INPUT_LEN)
#error "Values of MSF_CFG_FILE_NAME_LENGTH  and WIDGET_MAX_INPUT_LEN are not sync"
#endif 

kal_bool HDIa_widgetExtFmgrGetSaveFileName(
            const char *suggested_name,
            const char *mime_type,
            widget_fmgr_input_callback callback,
            void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *filename_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME);

    /* Validity of input parameter */
    ASSERT(callback);

    /* Re-entrance without clear previous data (Cause memory leak) */
    WAP_DBG_ASSERT(!WFMGR_CTX->filename_callback && !WFMGR_CTX->filename_arg && !WFMGR_CTX->filename_suggested_name);

    if (!widget_allow_create_new_MMI_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME_NOT_ALLOW);
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    // TODO: for DRM objects, we save it as "foo.dm" or "foo.dcf" first, and rename it to original media extension
    // TODO: like "foo.gif" or "foo.mid". We do not know the original media extension here.

    WFMGR_CTX->filename_callback = callback;
    WFMGR_CTX->filename_arg = arg;
    WFMGR_CTX->filename_folder = NULL;
    WFMGR_CTX->filename_result_pathname = NULL;
    filename_ext = HDIa_widgetExtMimeTypeToFileExt(mime_type);
    if (!filename_ext)
    {
        WFMGR_CTX->filename_ext = widget_ucs2_strdup(MSF_MODID_WIDGET, (const kal_uint8*)L"");
    }
    else
    {
        WFMGR_CTX->filename_ext = widget_ucs2_strdup_from_utf8(MSF_MODID_WIDGET, (const kal_uint8*)filename_ext);
    }
    if (!suggested_name)
    {
        WFMGR_CTX->filename_suggested_name = widget_ucs2_strdup(MSF_MODID_WIDGET, (const kal_uint8*)L"");
    }
    else
    {
        WFMGR_CTX->filename_suggested_name = widget_ucs2_strdup_from_utf8(MSF_MODID_WIDGET, (const kal_uint8*)suggested_name);
    }

#ifdef __DRM_V01__
    if (0 == msf_cmmn_strcmp_nc(mime_type, "application/vnd.oma.drm.message"))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME_DRM);

        /* Create the folder again. We can not cleanup the folder manually because it resides in system disk */
        HDIa_fileMkDir(WIDGET_DRM_TMP_FOLDER_MSF);
        msm_remove_files_under_dir(WIDGET_DRM_TMP_FOLDER_MSF);

        /* default input filename */
        WFMGR_CTX->filename_folder = widget_ucs2_strdup(MSF_MODID_WIDGET, (const kal_uint8*)WIDGET_DRM_TMP_FOLDER_UCS2);
        if (WFMGR_CTX->filename_suggested_name)
        {
            widget_ucs2_strncpy(
                widget_get_temp_editor_buffer(),
                WFMGR_CTX->filename_suggested_name,
                STR_SIZE(MSF_CFG_FILE_NAME_LENGTH + 1));
        }
        else
        {
            widget_ucs2_strcpy(widget_get_temp_editor_buffer(), (const kal_uint8*)L"");
        }

        widget_execute_MMI(wap_entry_save_filename_editor, KAL_TRUE);
    }
    else
    {
#endif /* __DRM_V01__ */ 

        widget_execute_MMI(widget_MMI_fmgr_enter_get_save_path, KAL_TRUE);

    #ifdef __DRM_V01__
    }
    #endif 

    /*
     * If we press LSK very fast, MMI might go FMGR->editor->menu->done while 
     * * WAP is still paused and does not return from this function.
     * * As a result, we use widget_execute_WAP(widget_WAP_fmgr_get_save_path_callback, KAL_FALSE) below.
     */

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME_END);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFmgrSaveFileNameAbort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFmgrSaveFileNameAbort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME_ABORT);

    /*
     * widget_fmgr_close_get_save_path prevents it  from invoking callback function again.
     * * We do not go back history here because HDIa_widgetExtFmgrSaveFileNameAbort will be invoked when MEA or BRA UI is shutdown
     * * when it already returns to idle screen
     */

    // TODO: Handle WAP out-of-memory when select path

    widget_fmgr_close_get_save_path();
}

/* Cancel the operation, but do not close FMGR screen  */


/*****************************************************************************
 * FUNCTION
 *  widget_fmgr_close_get_save_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fmgr_close_get_save_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FMGR_CLOSE_GET_SAVE_PATH);

    WFMGR_CTX->filename_callback = NULL;
    WFMGR_CTX->filename_arg = NULL;
    if (WFMGR_CTX->filename_suggested_name)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, WFMGR_CTX->filename_suggested_name);
        WFMGR_CTX->filename_suggested_name = NULL;
    }
    if (WFMGR_CTX->filename_folder)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, WFMGR_CTX->filename_folder);
        WFMGR_CTX->filename_folder = NULL;
    }
    if (WFMGR_CTX->filename_result_pathname)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, WFMGR_CTX->filename_result_pathname);
        WFMGR_CTX->filename_result_pathname = NULL;
    }
    if (WFMGR_CTX->filename_ext)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, WFMGR_CTX->filename_ext);
        WFMGR_CTX->filename_ext = NULL;
    }
    if (WFMGR_CTX->filename_warning_prompt)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, WFMGR_CTX->filename_warning_prompt);
        WFMGR_CTX->filename_warning_prompt = NULL;
    }
}

/* Invoke file manager */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_fmgr_enter_get_save_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_fmgr_enter_get_save_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_CLOSE_GET_SAVE_FILE_NAME);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (widget_allow_create_new_MMI_screen())
    {
        mmi_fmgr_select_path_and_enter(
            APP_MESSAGES,
            FMGR_SELECT_FOLDER,
            filter,
            (PS8) WFMGR_CTX->default_path,
            (PsExtFuncPtr) widget_MMI_fmgr_get_save_path_done_hdlr);
    }
}

/* Finish by callback and return to wap screen */


/*****************************************************************************
 * FUNCTION
 *  widget_WAP_fmgr_get_save_path_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_WAP_fmgr_get_save_path_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WFMGR_CTX->filename_callback)
    {
        WFMGR_CTX->filename_callback(WFMGR_CTX->filename_result_pathname, WFMGR_CTX->filename_arg);
    }
    widget_fmgr_close_get_save_path();
}


/*****************************************************************************
 * FUNCTION
 *  widget_fmgr_get_save_filename_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fmgr_get_save_filename_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FMGR_GET_SAVE_PATH_CALLBACK);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK() || WIDGET_IS_WAP_TASK());

    /* HDIa_widgetExtFmgrGetSaveFileName might not yet return at this point */
    widget_execute_WAP(widget_WAP_fmgr_get_save_path_callback, KAL_FALSE);

    /* We created a dummy MsfWindow in msf_dlg */
    widget_goback_to_WAP_screens();
}

/* Callback by FMGR (in MMI task) */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_fmgr_get_save_path_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_ptr          [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_fmgr_get_save_path_done_hdlr(void *in_ptr, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_FMGR_GET_SAVE_PATH_DONE_HDLR);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!WFMGR_CTX->filename_callback)
    {
        /* Operation canceled. Don't use callback. */
        return;
    }

    WAP_DBG_ASSERT(!WFMGR_CTX->filename_folder && !WFMGR_CTX->filename_result_pathname);

    if (!in_ptr || CHR_AT(in_ptr, 0) == CHR(0))
    {
        /* To indicate operation cancelled in FMGR */
        WFMGR_CTX->filename_folder = NULL;
        WFMGR_CTX->filename_result_pathname = NULL;

        widget_fmgr_get_save_filename_callback();   /* Exit point */
    }
    else
    {
        WFMGR_CTX->filename_folder = widget_ucs2_strdup(MSF_MODID_WIDGET, in_ptr);

        /* default input filename */
        if (WFMGR_CTX->filename_suggested_name)
        {
            widget_ucs2_strncpy(
                widget_get_temp_editor_buffer(),
                WFMGR_CTX->filename_suggested_name,
                STR_SIZE(MSF_CFG_FILE_NAME_LENGTH + 1));
        }
        else
        {
            widget_ucs2_strcpy(widget_get_temp_editor_buffer(), (const kal_uint8*)L"");
        }

        wap_entry_save_filename_editor();
    }
}

/* Press Cancel  */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_savename_editor_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_savename_editor_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SAVE_NAME_CANCEL);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WAP_DBG_ASSERT(!WFMGR_CTX->filename_result_pathname);

    WFMGR_CTX->filename_result_pathname = NULL;
    widget_fmgr_get_save_filename_callback();   /* Exit point */
}

/* Press Done  */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_savename_editor_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_savename_editor_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 err_msgid = 0;
    kal_uint8 *input_name = widget_get_temp_editor_buffer();    /* UCS2 */

    kal_uint8 *result_name = NULL;  /* UCS2 */
    int result_alloc_size = 0, utf8_size = 0;

    kal_uint8 *temp_name = NULL;    /* UCS2 */
    int temp_alloc_size = 0, pathlen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SAVE_NAME_EDITOR_DONE);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WAP_DBG_ASSERT(!WFMGR_CTX->filename_result_pathname);

    /* Check format validity */
    err_msgid = widget_validate_input_filename(input_name, WIDGET_SAVE_AS_VALID_CHARS);
    if (err_msgid)
    {
        wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, GetString(err_msgid), widget_goback_history1);
        return;
    }

    /* Re-check the validity and existence of target folder (Be paranoid) */
    if (!WFMGR_CTX->filename_folder)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SAVE_NAME_EDITOR_DONE_WITH_NULL_FOLDER);
        WAP_DBG_ASSERT(0);
        WFMGR_CTX->filename_result_pathname = NULL;
        widget_fmgr_get_save_filename_callback();   /* Exit point */
        return;
    }

    {
        FS_HANDLE fd;

        fd = FS_Open((WCHAR*) WFMGR_CTX->filename_folder, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        if (fd < 0)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SAVE_NAME_EDITOR_DONE_WITH_INVALID_FOLDER);
            WAP_DBG_ASSERT(0);
            WFMGR_CTX->filename_result_pathname = NULL;
            widget_fmgr_get_save_filename_callback();   /* Exit point */
            return;
        }
        FS_Close(fd);
    }

    /* 
     * Delete index.ix & index.fr. Workaround for old release of MSF.
     * New MSF release will not  create .ix and .fr files in MSF AFI package for external pathname.
     */
    result_alloc_size = 256;
    result_name = MSF_MEM_ALLOC(MSF_MODID_WIDGET, result_alloc_size);
    result_name[0] = result_name[1] = 0;
    result_name = widget_ucs2str_append_ucs2(MSF_MODID_WIDGET, result_name, &result_alloc_size, WFMGR_CTX->filename_folder);
    result_name = widget_ucs2str_append_ucs2(MSF_MODID_WIDGET, result_name, &result_alloc_size, (const kal_uint8*)L"\\");

    pathlen = widget_ucs2_length(result_name);
    temp_alloc_size = (pathlen + 8 + 1 + 16 /* dummy */ ) * ENCODING_LENGTH;
    temp_name = MSF_MEM_ALLOC(MSF_MODID_WIDGET, temp_alloc_size);
    widget_ucs2_strcpy(temp_name, result_name);

    widget_ucs2_strcpy(temp_name + 2 * pathlen, (const kal_uint8*)L"index.ix");
    FS_Delete((WCHAR*) temp_name);
    widget_ucs2_strcpy(temp_name + 2 * pathlen, (const kal_uint8*)L"index.fr");
    FS_Delete((WCHAR*) temp_name);

    MSF_MEM_FREE(MSF_MODID_WIDGET, temp_name);
    temp_name = NULL;
    temp_alloc_size = 0;

    /* Check existence of input name (It could be file or folder) */
    result_name = widget_ucs2str_append_ucs2(MSF_MODID_WIDGET, result_name, &result_alloc_size, input_name);

    {
        FS_HANDLE fd;

        /* A file (not directory) exists. Delete it. */
        fd = FS_Open((WCHAR*) result_name, FS_READ_WRITE | FS_OPEN_SHARED | FS_OPEN_NO_DIR);
        if (fd >= 0)
        {
            FS_Close(fd);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SAVE_NAME_EDITOR_DONE_WITH_REMOVE_FILE);
            FS_Delete((WCHAR*) result_name);
        }

        /* A folder exists. We cannot remove it. Keep it simple. */
        fd = FS_Open((WCHAR*) result_name, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        if (fd >= 0)
        {
            FS_Close(fd);
            if (WFMGR_CTX->filename_warning_prompt)
            {
                MSF_MEM_FREE(MSF_MODID_WIDGET, WFMGR_CTX->filename_warning_prompt);
            }
            WFMGR_CTX->filename_warning_prompt = widget_ucs2_strdup(MSF_MODID_WIDGET, input_name);
            WFMGR_CTX->filename_warning_prompt = widget_ucs2str_append_ucs2(
                                                    MSF_MODID_WIDGET,
                                                    WFMGR_CTX->filename_warning_prompt,
                                                    0,
                                                    (const kal_uint8*)GetString(MSF_STR_ID_DLG_NO_REPLACE_TEXT2));
            DisplayPopup((U8*) WFMGR_CTX->filename_warning_prompt, 0 /* IMG_GLOBAL_ERROR */ , 0, 2000, ERROR_TONE);

            MSF_MEM_FREE(MSF_MODID_WIDGET, result_name);
            return;
        }
    }

    temp_alloc_size = (widget_ucs2_length(result_name) +
                       widget_ucs2_length(WFMGR_CTX->filename_ext) + 1) * ENCODING_LENGTH;
    temp_name = MSF_MEM_ALLOC(MSF_MODID_WIDGET, temp_alloc_size);
    widget_ucs2_strcpy(temp_name, result_name);
    temp_name = widget_ucs2str_append_ucs2(MSF_MODID_WIDGET, temp_name, &temp_alloc_size, WFMGR_CTX->filename_ext);
    {
        FS_HANDLE fd;

        fd = FS_Open((WCHAR*) temp_name, FS_READ_ONLY | FS_OPEN_SHARED);

        if (fd >= 0)
        {
            FS_Close(fd);

            if (WFMGR_CTX->filename_warning_prompt)
            {
                MSF_MEM_FREE(MSF_MODID_WIDGET, WFMGR_CTX->filename_warning_prompt);
            }
            /*
             * WFMGR_CTX->filename_warning_prompt = widget_ucs2_strdup(MSF_MODID_WIDGET, input_name);
             * WFMGR_CTX->filename_warning_prompt = widget_ucs2str_append_ucs2(MSF_MODID_WIDGET,     WFMGR_CTX->filename_warning_prompt, 0, WFMGR_CTX->filename_ext);
             * WFMGR_CTX->filename_warning_prompt = widget_ucs2str_append_ucs2(MSF_MODID_WIDGET, WFMGR_CTX->filename_warning_prompt , 0, (const kal_uint8*)GetString(MSF_STR_ID_DLG_NO_REPLACE_TEXT2));
             */
            WFMGR_CTX->filename_warning_prompt = widget_ucs2_strdup(MSF_MODID_WIDGET, (const kal_uint8*)GetString(MSF_STR_ID_DLG_EXISTS_TITLE));
            DisplayPopup((U8*) WFMGR_CTX->filename_warning_prompt, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);

            MSF_MEM_FREE(MSF_MODID_WIDGET, result_name);
            MSF_MEM_FREE(MSF_MODID_WIDGET, temp_name);
            return;
        }
    }
    MSF_MEM_FREE(MSF_MODID_WIDGET, temp_name);
    temp_name = NULL;
    temp_alloc_size = 0;

    /* Return filename (UCS2 -> UTF-8) */
    utf8_size = widget_ucs2_to_utf8_length_in_bytes(result_name) + HDI_EXTERNAL_LEN + 1;
    WFMGR_CTX->filename_result_pathname = MSF_MEM_ALLOC(MSF_MODID_WIDGET, utf8_size);
    strcpy((char*)WFMGR_CTX->filename_result_pathname, HDI_EXTERNAL_PATH);
    widget_ucs2_to_utf8_string(
        ((kal_uint8*) WFMGR_CTX->filename_result_pathname) + HDI_EXTERNAL_LEN,
        utf8_size - HDI_EXTERNAL_LEN,
        result_name);

    MSF_MEM_FREE(MSF_MODID_WIDGET, result_name);

    widget_fmgr_get_save_filename_callback();   /* Exit point */
}


/*****************************************************************************
 * FUNCTION
 *  widget_savename_editor_highlight_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_savename_editor_highlight_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(widget_MMI_savename_editor_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  widget_savename_editor_highlight_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_savename_editor_highlight_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(widget_MMI_savename_editor_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  widget_savename_editor_highlight_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_savename_editor_highlight_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_save_filename_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_save_filename_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_SAVE_FILE_NAME_EDITOR_OPTION);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    EntryNewScreen(WAP_SCREEN_SAVENAME_EDITOR_OPTION, NULL, wap_entry_save_filename_editor_option, NULL);

    guiBuffer = GetCurrGuiBuffer(WAP_SCREEN_SAVENAME_EDITOR_OPTION);

    nNumofItem = GetNumOfChild(WAP_MENU_FULLSCREEN_EDITOR_OPTION);
    GetSequenceStringIds(WAP_MENU_FULLSCREEN_EDITOR_OPTION, nStrItemList);

    SetParentHandler(WAP_MENU_FULLSCREEN_EDITOR_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetHiliteHandler(WAP_MENU_FULLSCREEN_EDITOR_OPTION_DONE, widget_savename_editor_highlight_done);
    SetHiliteHandler(WAP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL, widget_savename_editor_highlight_cancel);
    SetHiliteHandler(WAP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD, widget_savename_editor_highlight_input_method);

    ShowCategory15Screen(
        WIDGET_STR_ID_OPTION,
        widget_get_title_icon(0),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    RegisterInputMethodScreenCloseFunction(widget_goback_history1);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_save_filename_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_save_filename_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_SAVE_FILE_NAME_EDITOR);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    EntryNewScreen(WAP_SCREEN_SAVENAME_EDITOR, NULL, wap_entry_save_filename_editor, NULL);

    guiBuffer = GetCurrGuiBuffer(WAP_SCREEN_SAVENAME_EDITOR);

    /* Prevent title blinking */
    ShowCategory5Screen(
        MSF_STR_ID_DLG_TEXT_EDIT_FILENAME,
        widget_get_title_icon(0),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE /* Use default input method */ ,
        (U8*) widget_get_temp_editor_buffer(),
        MSF_CFG_FILE_NAME_LENGTH + 1,
        guiBuffer);

    SetLeftSoftkeyFunction(wap_entry_save_filename_editor_option, KEY_EVENT_UP);

    SetCategory5RightSoftkeyFunction(widget_MMI_savename_editor_cancel, KEY_EVENT_UP);  /* Go back to file manager */

}

#else /* __MMI_FILE_MANAGER__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFmgrGetSaveFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  suggested_name      [IN]        
 *  mime_type           [IN]        
 *  callback            [IN]        
 *  arg                 [IN]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtFmgrGetSaveFileName(
            const char *suggested_name,
            const char *mime_type,
            widget_fmgr_input_callback callback,
            void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFmgrSaveFileNameAbort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFmgrSaveFileNameAbort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* __MMI_FILE_MANAGER__ */ 

/******************************************************************************
 *
 * IPC
 *
 ******************************************************************************/

/*
 * NOTICE! THE ASSUMPTION OF THE FOLLOWING CODE IS WAP AND MMI HAVE THE SAME PRIORITY 
 */


/*****************************************************************************
 * FUNCTION
 *  widget_init_IPC
 * DESCRIPTION
 *  Initialze inter-process communication mechanism
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_IPC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WIPC_CTX->initialized)
    {
        WIPC_CTX->initialized = 1;

        WIPC_CTX->event_group = kal_create_event_group("widgetev");

        WIPC_CTX->wait_message_notification_in_idle_screen = 0;

        WIPC_CTX->pending_to_enter_widget_screen = 0;

    #ifdef WIDGET_TMPFIX_DYNAMIC_LIST
        WIPC_CTX->WAP_extq_mutex = kal_create_mutex("widgetext");

        WIPC_CTX->extq_mutex_locked_by_WAP = 0;
        WIPC_CTX->extq_mutex_locked_by_MMI = 0;
        WIPC_CTX->MMI_try_to_lock_extq_mutex = 0;
    #endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
        WIPC_CTX->idlescreen_seq_no = 0;
    }

    WIPC_CTX->update_event_is_sent = 0;

    WAP_DBG_ASSERT(!WIPC_CTX->wait_MMI_lock);

    WAP_DBG_ASSERT(!WIPC_CTX->is_executing_RPC);

    /*
     * We do not reset WIPC_CTX->is_executing_RPC because we always need to execute the callback 
     * * even if out-of-memory happened.
     */
}


/*****************************************************************************
 * FUNCTION
 *  widget_mmiapi_remote_proc_call_req
 * DESCRIPTION
 *  Message handler of remote procedure call request
 * PARAMETERS
 *  ilm_ptr     [IN]        Request data
 * RETURNS
 *  void
 *****************************************************************************/
void widget_mmiapi_remote_proc_call_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_remote_proc_call_struct *rpc = (mmiapi_remote_proc_call_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMIAPI_REMOTE_PROC_CALL_REQ);

    WIPC_CTX->RPC_finish_callback = rpc->finish_callback;
    WIPC_CTX->is_executing_RPC = 1;

    /*
     * Pending this callback until internal queue are processed in MSF_fsm(). 
     * * Otherwise, WAP task might not have chance to process its internal queues before 
     * * widget_execute_WAP() returns.
     */
    rpc->finish_callback = NULL;
    mmiapi_remote_proc_call_req(rpc, ilm_ptr->src_mod_id);
}

/* Callback handler to unlock widget/MMI event group */


/*****************************************************************************
 * FUNCTION
 *  widget_unlock_MMI_lock_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_unlock_MMI_lock_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not circular waiting */
    ASSERT(!WIPC_CTX->WAP_is_waiting || !WIPC_CTX->MMI_is_waiting);
    WIPC_CTX->WAP_is_waiting = 0;
    WIPC_CTX->MMI_is_waiting = 0;

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_UNLOCK_MMI_LOCK);

    if (!WIDGET_TRY_MMI_LOCK())
    {
		WIDGET_SIGNAL_MMI_LOCK();
    }
}

/* Cancel all RPC to MMI after enter idle screen */


/*****************************************************************************
 * FUNCTION
 *  widget_validate_MMI_RPC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_validate_MMI_RPC(kal_uint32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (arg == WIPC_CTX->idlescreen_seq_no)
    {
        return KAL_TRUE;
    }
    else
    {
    #ifndef __PRODUCTION_RELEASE__
        ASSERT(WIPC_CTX->idlescreen_seq_no > arg);  /* Overflow? */
    #endif 
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_MMI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_MMI(func_void func, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr;
    mmiapi_remote_proc_call_struct *rpc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI, (kal_uint32) func, (int)is_blocking);

    if (WIDGET_IS_MMI_TASK())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_IN_MMI_TASK);
        func();
        return;
    }

    if (mmi_shutdown_is_in_power_off_period())
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    /* Not in MMI task */
    ASSERT(WIDGET_IS_WAP_TASK() && !WIPC_CTX->WAP_is_waiting /* Impossible */ );

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    /* If MMI is sleeping for WIPC_CTX->WAP_extq_mutex. WAP task can manually unlock the mutex 
       to give MMI task a chance to run. */
    if (WIPC_CTX->MMI_is_waiting && is_blocking && !WIPC_CTX->MMI_try_to_lock_extq_mutex /* MMI drawing unfinished */ )
#else /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    if (WIPC_CTX->MMI_is_waiting && is_blocking)
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    {
        /* MMI is already waiting for WAP to do something */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_WAIT_WAP_TASK);
        WAP_DBG_ASSERT(0);  /* However, MMI can not process extq now, this function might not complete successfully */
        func();
        return;
    }

    /* MMI is not blocked */
    rpc = (mmiapi_remote_proc_call_struct*) construct_local_para(sizeof(mmiapi_remote_proc_call_struct), TD_CTRL);

    rpc->type = MMIAPI_RPC_VOID;
    rpc->func_ptr = (void*)func;
    rpc->finish_callback = is_blocking ? widget_unlock_MMI_lock_hdlr : NULL;
    rpc->blocking_data = NULL;
    rpc->validate_callback = widget_validate_MMI_RPC;
    rpc->optional_param = WIPC_CTX->idlescreen_seq_no;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rpc;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);

    /* WAP and MMI has the same priority, it keeps execution */

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    if (is_blocking && WIPC_CTX->MMI_try_to_lock_extq_mutex)
    {
        /* MMI is sleeping for WIPC_CTX->WAP_extq_mutex. unlock the mutex to give MMI task a chance to run. */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_UNLOCK_Q_MUTEX);
        WIPC_CTX->extq_mutex_locked_by_WAP = 0;
        kal_give_mutex(WIPC_CTX->WAP_extq_mutex);

        WIDGET_WAIT_MMI_LOCK();

        kal_take_mutex(WIPC_CTX->WAP_extq_mutex);
        ASSERT(!WIPC_CTX->extq_mutex_locked_by_MMI);
        WIPC_CTX->extq_mutex_locked_by_WAP = 1;
    }
    else
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    if (is_blocking)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_WAP_BLOCKED);
        WIPC_CTX->WAP_is_waiting = 1;
        WIDGET_WAIT_MMI_LOCK();
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_ASYNC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_WAP
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_WAP(func_void func, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr;
    mmiapi_remote_proc_call_struct *rpc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP, (kal_uint32) func, (int)is_blocking);

    if (WIDGET_IS_WAP_TASK())
    {
        /* Note that WAP internal queue might not be finished after function returns */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_IN_WAP_TASK);
        func();
        // It will always process internal queue after this.
        // widget_send_update_event();
        return;
    }

    if (mmi_shutdown_is_in_power_off_period())
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    /* Not in WAP task */
    ASSERT(WIDGET_IS_MMI_TASK() /* Java? */  && !WIPC_CTX->MMI_is_waiting /* Impossible */ );

    if (WIPC_CTX->WAP_is_waiting && is_blocking)
    {
        /* WAP is already waiting for MMI to do something */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_WAIT_MMI_TASK);
        WAP_DBG_ASSERT(0);  /* However, WAP can not process extq and internal queue now, this function might not complete successfully */
        func();
        return;
    }

    /* WAP is not blocked */
    rpc = (mmiapi_remote_proc_call_struct*) construct_local_para(sizeof(mmiapi_remote_proc_call_struct), TD_CTRL);

    rpc->type = MMIAPI_RPC_VOID;
    rpc->func_ptr = (void*)func;
    rpc->finish_callback = is_blocking ? widget_unlock_MMI_lock_hdlr : NULL;
    rpc->blocking_data = NULL;
    rpc->validate_callback = NULL;
    rpc->optional_param = 0;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rpc;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    /* WAP and MMI has the same priority, it keeps execution */
    if (is_blocking)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_MMI_BLOCKED);
        WIPC_CTX->MMI_is_waiting = 1;
        WIDGET_WAIT_MMI_LOCK();
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_ASYNC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_MMI_i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  arg             [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_MMI_i(func_int func, int arg, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr;
    mmiapi_remote_proc_call_struct *rpc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I, (kal_uint32) func, arg, (int)is_blocking);

    if (WIDGET_IS_MMI_TASK())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_IN_MMI_TASK);
        func(arg);
        return;
    }

    if (mmi_shutdown_is_in_power_off_period())
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    /* Not in MMI task */
    ASSERT(WIDGET_IS_WAP_TASK() && !WIPC_CTX->WAP_is_waiting /* Impossible */ );

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    if (WIPC_CTX->MMI_is_waiting && is_blocking && !WIPC_CTX->MMI_try_to_lock_extq_mutex /* MMI drawing unfinished */ )
#else 
    if (WIPC_CTX->MMI_is_waiting && is_blocking)
#endif 
    {
        /* MMI is already waiting for WAP to do something */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_WAIT_WAP_TASK);
        WAP_DBG_ASSERT(0);  /* However, MMI can not process extq now, this function might not complete successfully */
        func(arg);
        return;
    }

    /* MMI is not blocked */
    rpc = (mmiapi_remote_proc_call_struct*) construct_local_para(sizeof(mmiapi_remote_proc_call_struct), TD_CTRL);

    rpc->type = MMIAPI_RPC_INTEGER;
    rpc->func_ptr = (void*)func;
    rpc->finish_callback = is_blocking ? widget_unlock_MMI_lock_hdlr : NULL;
    rpc->_u.i = arg;
    rpc->blocking_data = NULL;
    rpc->validate_callback = widget_validate_MMI_RPC;
    rpc->optional_param = WIPC_CTX->idlescreen_seq_no;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rpc;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);

    /* WAP and MMI has the same priority, it keeps execution */
#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    if (is_blocking && WIPC_CTX->MMI_try_to_lock_extq_mutex)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_UNLOCK_Q_MUTEX);
        WIPC_CTX->extq_mutex_locked_by_WAP = 0;
        kal_give_mutex(WIPC_CTX->WAP_extq_mutex);

        WIDGET_WAIT_MMI_LOCK();

        kal_take_mutex(WIPC_CTX->WAP_extq_mutex);
        ASSERT(!WIPC_CTX->extq_mutex_locked_by_MMI);
        WIPC_CTX->extq_mutex_locked_by_WAP = 1;
    }
    else
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    if (is_blocking)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_WAP_BLOCKED);
        WIPC_CTX->WAP_is_waiting = 1;
        WIDGET_WAIT_MMI_LOCK();
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_ASYNC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_WAP_i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  arg             [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_WAP_i(func_int func, int arg, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr;
    mmiapi_remote_proc_call_struct *rpc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I, (kal_uint32) func, arg, (int)is_blocking);

    if (WIDGET_IS_WAP_TASK())
    {
        /* Note that WAP internal queue might not be finished after function returns */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I_IN_WAP_TASK);
        func(arg);
        // It will always process internal queue after this.
        // widget_send_update_event();
        return;
    }

    if (mmi_shutdown_is_in_power_off_period())
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    /* Not in WAP task */
    ASSERT(WIDGET_IS_MMI_TASK() /* Java? */  && !WIPC_CTX->MMI_is_waiting /* Impossible */ );

    if (WIPC_CTX->WAP_is_waiting && is_blocking)
    {
        /* WAP is already waiting for MMI to do something */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I_WAIT_MMI_TASK);
        WAP_DBG_ASSERT(0);  /* However, WAP can not process extq and internal queue now, this function might not complete successfully */
        func(arg);
        return;
    }

    /* WAP is not blocked */
    rpc = (mmiapi_remote_proc_call_struct*) construct_local_para(sizeof(mmiapi_remote_proc_call_struct), TD_CTRL);

    rpc->type = MMIAPI_RPC_INTEGER;
    rpc->func_ptr = (void*)func;
    rpc->finish_callback = is_blocking ? widget_unlock_MMI_lock_hdlr : NULL;
    rpc->_u.i = arg;
    rpc->blocking_data = NULL;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rpc;
    rpc->validate_callback = NULL;
    rpc->optional_param = 0;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    /* WAP and MMI has the same priority, it keeps execution */

    if (is_blocking)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I_MMI_BLOCKED);
        WIPC_CTX->MMI_is_waiting = 1;
        WIDGET_WAIT_MMI_LOCK();
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I_ASYNC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_MMI_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  arg             [IN]         
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_MMI_p(func_ptr func, void *arg, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_execute_MMI_i((func_int) func, (int)arg, is_blocking);
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_WAP_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  arg             [IN]         
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_WAP_p(func_ptr func, void *arg, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_execute_WAP_i((func_int) func, (int)arg, is_blocking);
}

extern PS8 lookUpNumber(PS8 number);
typedef struct
{
    PS8 number; /* input buffer */
    PS8 name;   /* output buffer */
    int size;   /* output buffer size */
} widget_MMI_lookup_number_struct;


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_lookUp_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_lookUp_number(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_MMI_lookup_number_struct *info = (widget_MMI_lookup_number_struct*) arg;
    int size = (widget_utf8_length((kal_uint8*) info->number) + 1) * ENCODING_LENGTH;
    PS8 ucs2Addr = NULL;
    PS8 ucs2Name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * 1. ask MMI task use lookUpNumber(ucs2Addr) to get ucs2 Name string
     * 2. convert this ucs2 Name string to utf8 string. Copy it to name ptr. 
     * If name is NULL or length=0, please copy number to name ptr.
     */
    ucs2Addr = MSF_MEM_ALLOC(MSF_MODID_WIDGET, size);
    widget_utf8_to_ucs2_string((kal_uint8*) ucs2Addr, size, (kal_uint8*) info->number);
    ucs2Name = lookUpNumber(ucs2Addr);
    MSF_MEM_FREE(MSF_MODID_WIDGET, ucs2Addr);

    if (ucs2Name != NULL && widget_ucs2_length((kal_uint8*) ucs2Name) > 0)
    {
        widget_ucs2_to_utf8_string((kal_uint8*) info->name, info->size, (kal_uint8*) ucs2Name);
    }
    else
    {
        /* No matched name, show the phone number */
        strncpy((char*)info->name, (char*)info->number, info->size);
        info->name[info->size - 1] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtRemoteLookupPhbName
 * DESCRIPTION
 *  MMS needs to lookup name from phonebook, but loopup procedure will access
 *  NVRAM. WAP require MMI to lookup name via RPC mechanism
 * PARAMETERS
 *  number          [IN]        The phone number that want to lookup
 *  name            [OUT]       The mapping name
 *  sizeInByte      [IN]        The name buffer size
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtRemoteLookupPhbName(char *number, char *name, int sizeInByte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If MMI is waiting WAP, copy "number" to "name" and return directly. */
    strncpy(name, number, sizeInByte);
    name[sizeInByte - 1] = '\0';

    if (!WIPC_CTX->MMI_is_waiting)
    {
        widget_MMI_lookup_number_struct lookupInfo = {0};

        lookupInfo.number = (PS8) number;
        lookupInfo.name = (PS8) name;
        lookupInfo.size = sizeInByte;
        widget_execute_MMI_p((func_ptr) widget_MMI_lookUp_number, (void*)(&lookupInfo), KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_enter_save_phone_number
 * DESCRIPTION
 *  Enter phonbook screen to save the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_enter_save_phone_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (widget_allow_create_new_MMI_screen())
    {
        SaveNumberFromIdleScrn((PS8) WIPC_CTX->save_phonebook_number, 0);
    }
    WIPC_CTX->save_phonebook_number = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSavePhoneNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtSavePhoneNumber(kal_uint8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_allow_create_new_MMI_screen())
    {
        return 0;
    }

    WIPC_CTX->save_phonebook_number = number;
    widget_execute_MMI(widget_enter_save_phone_number, KAL_TRUE);
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  widget_enter_save_email
 * DESCRIPTION
 *  Enter phonbook screen to save the Email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_enter_save_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (widget_allow_create_new_MMI_screen())
    {
#ifdef MMS_SUPPORT  /* should remove this and the one in PhoneBookStubsToOthers.c */
        mmi_phb_email_save_entry_to_phb_from_jmms((PS8) WIPC_CTX->save_phonebook_number);
#endif
    }
    WIPC_CTX->save_phonebook_number = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSaveEmail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtSaveEmail(kal_uint8 *email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_allow_create_new_MMI_screen())
    {
        return 0;
    }

    WIPC_CTX->save_phonebook_number = email;
    widget_execute_MMI(widget_enter_save_email, KAL_TRUE);
    return 1;
}

/******************************************************************************
 *
 * Context of GUI and fullscreen editor
 *
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_init_GUI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_GUI()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * We do not reset all flags of WGUI_CTX including
     * paint_seqnum, paint_seqnum_on_form_scroll, has_status_icons, form_with_sliding_bar, ...
     */
    WGUI_CTX->is_widget_screen = KAL_FALSE;     // TODO: is it correct???
    WGUI_CTX->is_access_key_trigger = KAL_FALSE;
    WGUI_CTX->current_screen_level = 0; // TODO: Should we reset this flag?
    WGUI_CTX->tried_to_enter_widget_screen = 0;
    WGUI_CTX->is_in_goto_idle_screen = 0;
    WGUI_CTX->is_shutdown_UI = 0;
    WGUI_CTX->is_all_handler_cleared = 0;
    WGUI_CTX->is_entering_widget_screen = 0;
    WGUI_CTX->is_painted = 0;
    WGUI_CTX->is_painted_after_first_focus_changed = 0;
    WGUI_CTX->animate_GIF_after_screen_painted = 0;
    WGUI_CTX->animate_busy_status_bar = 0;
    WGUI_CTX->MMS_screen_is_active = 0;
    WGUI_CTX->in_form = 1;
    WGUI_CTX->in_paintbox = 0;
    WGUI_CTX->in_editor = 0;
    WGUI_CTX->disable_yes_key_in_paintbox = 0;
    WGUI_CTX->last_screen_is_dialog = 0;
    WGUI_CTX->LSK_mask = 0;
    WGUI_CTX->RSK_mask = 0;
    WGUI_CTX->selected_input_in_paintbox = 0;

    WGUI_CTX->is_menu_item_index_selection_process = 0;
    WGUI_CTX->status_bar_flags = 0;
#ifdef WIDGET_DUAL_SIM_SUPPORT
    /* Keep the sim card of widget service */
    WGUI_CTX->service_on_sim = WAP_SERVICE_ON_UNKNOWN_SIM;
#endif /* WIDGET_DUAL_SIM_SUPPORT */
    WGUI_CTX->paint_level = 0;
    WGUI_CTX->lock_buffer_level = 0;
    WGUI_CTX->display_size.width = (short)MMI_SUBMENU_CONTENT_WIDTH;
    WGUI_CTX->display_size.height = (short)MMI_SUBMENU_CONTENT_HEIGHT;
    WGUI_CTX->default_display_size.width = (short)MMI_SUBMENU_CONTENT_WIDTH;
    WGUI_CTX->default_display_size.height = (short)MMI_SUBMENU_CONTENT_HEIGHT;
    WGUI_CTX->display_pos.x = (short)MMI_SUBMENU_CONTENT_X;
    WGUI_CTX->display_pos.y = (short)MMI_SUBMENU_CONTENT_Y;
    WGUI_CTX->current_pos = WGUI_CTX->display_pos;
#ifdef WIDGET_RESIDENT_STATUS_ICON
    WGUI_CTX->redraw_status_icons_pane = 0;
    WGUI_CTX->dialog_with_hatch_background = 0;
    WGUI_CTX->status_icons_pane_top.y = 0;
    WGUI_CTX->status_icons_pane_top.y = 0;
    WGUI_CTX->status_icons_pane_bottom.x = 0;
    WGUI_CTX->status_icons_pane_bottom.y = MMI_title_y - 1;
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 
    WGUI_CTX->bearer_type = WIDGET_GPRS;
    WGUI_CTX->who_want_to_enter_widget_screen = 0;
    WGUI_CTX->title_buffer[0] = 0;
#ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
    WGUI_CTX->allow_to_update_scrollbar_indication = 1;
    WGUI_CTX->v_scrollbar_value = -1;
    WGUI_CTX->h_scrollbar_value = -1;
    WGUI_CTX->scrollbar_indication_info = 0;
#endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */

    memset(&WGUI_CTX->widget_root, 0, sizeof(WGUI_CTX->widget_root));
    WGUI_CTX->widget_root.flag = WIDGET_ROOT_TYPE;

    /* Queues */
    WGUI_CTX->paint_cmd_head = NULL;
    WGUI_CTX->blinking_head = NULL;
    WGUI_CTX->blinking_on = KAL_FALSE;
    WGUI_CTX->marquee_head = NULL;
    WGUI_CTX->accesskey_head = NULL;

    /* Color */
    WGUI_CTX->cursor_shadow_color.r = WIDGET_CURSOR_SHADOW_COLOR_R;
    WGUI_CTX->cursor_shadow_color.g = WIDGET_CURSOR_SHADOW_COLOR_G;
    WGUI_CTX->cursor_shadow_color.b = WIDGET_CURSOR_SHADOW_COLOR_B;
    WGUI_CTX->cursor_shadow_color.alpha = WIDGET_CURSOR_SHADOW_COLOR_A;

    /* for check switching the widget screen */
    WGUI_CTX->switch_widget_screen_cb = NULL;
    WGUI_CTX->previous_focused_window = NULL;

    /* for pre-cache non-blocking image procedure */
    WGUI_CTX->precache_nb_image_cb = NULL;
    WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE;
    
    /* Current objects */
    WGUI_CTX->current_focused_paintbox = NULL;
    WGUI_CTX->current_focused_gadget = NULL;
    WGUI_CTX->current_screen = NULL;
    WGUI_CTX->current_window = NULL;
    WGUI_CTX->current_menu = NULL;
    WGUI_CTX->current_dialog = NULL;
    WGUI_CTX->current_vertical_scrollbar = NULL;
    WGUI_CTX->current_horizontal_scrollbar = NULL;
    WGUI_CTX->current_window_audio_cb = NULL;
    WGUI_CTX->current_video = NULL;
    WGUI_CTX->second_video = NULL;
    WGUI_CTX->current_video_state = WIDGET_VIDEO_NONE;
    WGUI_CTX->video_gdi_layer = 0;
    WGUI_CTX->top_gdi_layer = 0;
    WGUI_CTX->top_gdi_layer_buffer = NULL;
    WGUI_CTX->top_gdi_layer_is_button_bar = 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_GUI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_GUI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_release_paint_command_queue();
    // TODO: also release all marquee, blinking text... etc. even though they are released in HDIa_widgetReleaseAll
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_fullscreen_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    WEDITOR_CTX->active_object = NULL;
}

/******************************************************************************
 *
 * Message notification mechanism
 * (Migrated from mmiapi_wap.c)
 *
 ******************************************************************************/

/*
 *    Issues to consider:
 * o MO/MT Call
 * o Alarm
 * o Profile Alert Type 
 * o If we entered message menu, the notification should be cleared.
 * o Keypad lock
 * o Wait MEA/BRA UI shutdown before display another notification
 * o (Unfinished) SubLCD 
 *
 * Note:
 * We always display the latest provision/push/MMS. 
 *
 * EntryIdleScreen will
 * o Cleanup history
 * o Terminate WAP UI (blocking & synchronous)
 * o Display WAP message popup (keypad unlocked)
 * o Display message prompt (keypad locked)
 *
 */
// TODO: Ask - vibrator no automatically resume?

#define WIDGET_MSG_NOTIFICATION_NONE            (0)
#define WIDGET_MSG_NOTIFICATION_PUSH            (1)
#define WIDGET_MSG_NOTIFICATION_MMS	            (2)
#define WIDGET_MSG_NOTIFICATION_DRM_RIGHT       (3)
#define WIDGET_MSG_NOTIFICATION_PROVISION       (4)

/* static U8 widget_message_notification_keypad_lock_prompt[32 << 1]; */


/*****************************************************************************
 * FUNCTION
 *  widget_init_message_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_message_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&WIDGET_CTX->msg_notification_cntx, 0, sizeof(widget_msg_notification_struct));
}

/* 
 * Utility Functions 
 */


/*****************************************************************************
 * FUNCTION
 *  widget_message_notification_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_message_notification_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!(WNOTI_CTX->has_push || 
	      WNOTI_CTX->has_provision || 
	      WNOTI_CTX->has_DRM_right || 
	      WNOTI_CTX->has_MMS))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/* 
 * Tone 
 */


/*****************************************************************************
 * FUNCTION
 *  widget_play_msg_arrival_tone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prompt_text             [IN]
 *  suspend_bg_sound        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_play_msg_arrival_tone(PU8 prompt_text, kal_bool suspend_bg_sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ALERT_TYPE alertType;
    kal_bool       is_message_tone = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alertType = GetMtCallAlertTypeEnum();
    WNOTI_CTX->tone_id = 0;

    /* If alarm tone is interrupted by message tone, it will automatically resume */
    if (alertType == MMI_VIBRATION_AND_RING || alertType == MMI_VIBRATION_THEN_RING || alertType == MMI_RING)
    {
        if (widget_check_is_in_non_wap_call())
        {
            /* in MT/MO voice call */
            WNOTI_CTX->tone_id = SMS_IN_CALL_TONE;
            playRequestedTone(SMS_IN_CALL_TONE);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE_IN_CALL);
        }
        else
        {
            if (WNOTI_CTX->has_DRM_right && WNOTI_CTX->DRM_right_tone_id)
            {
                WNOTI_CTX->tone_id = WNOTI_CTX->DRM_right_tone_id;
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE_DRM_RIGHT_MSG);
            }
        #ifdef WIDGET_DUAL_SIM_SUPPORT
            else if (WNOTI_CTX->has_MMS && 
                     (prompt_text == (PU8)GetString(WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_2) ||
                      prompt_text == (PU8)GetString(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT_SIM_2) ||
                      prompt_text == (PU8)GetString(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT_SIM_2) ||
                      prompt_text == (PU8)GetString(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION_SIM_2)))
            {
                is_message_tone = KAL_TRUE;
                WNOTI_CTX->tone_id = CARD2_MESSAGE_TONE;
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE_MMS_SIM2);
            }
            else if (WNOTI_CTX->has_provision &&
                     prompt_text == (PU8)GetString(WIDGET_STR_ID_RECEIVED_PROVISION_SIM_2))
            {
                is_message_tone = KAL_TRUE;
                WNOTI_CTX->tone_id = CARD2_MESSAGE_TONE;
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE_PROV_SIM2);
            }
        #endif
            else
            {
                is_message_tone = KAL_TRUE;
                WNOTI_CTX->tone_id = MESSAGE_TONE;
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE, WNOTI_CTX->has_MMS, WNOTI_CTX->has_provision, prompt_text);
            }

            if (suspend_bg_sound && is_message_tone) /* tricky */
            {
                mdi_audio_suspend_background_play();
            }
            playRequestedTone(WNOTI_CTX->tone_id);
        }
    }

    if ((alertType == MMI_VIBRATION_ONLY) || (alertType == MMI_VIBRATION_AND_RING) ||
        (alertType == MMI_VIBRATION_THEN_RING))
    {
        if (!g_alm_frm_cntx.IsAlmTonePlaying)
        {
            PlaySmsVibratorOnce();
        }
    }
}

/* 
 * Popup 
 * (Not paused in history)
 */


/*****************************************************************************
 * FUNCTION
 *  exit_widget_msg_notification_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void exit_widget_msg_notification_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXIT_WIDGET_MSG_NOTIFICATION_POPUP);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (WNOTI_CTX->tone_id)
    {
        stopRequestedTone(WNOTI_CTX->tone_id);
    }

    if (WNOTI_CTX->tone_id == MESSAGE_TONE)/* tricky */
    {
        mdi_audio_resume_background_play();
    }
#ifdef WIDGET_DUAL_SIM_SUPPORT
    if (WNOTI_CTX->tone_id == CARD2_MESSAGE_TONE)/* tricky */
    {
        mdi_audio_resume_background_play();
    }
#endif

    if (WNOTI_CTX->has_DRM_right && 
        WNOTI_CTX->tone_id == WNOTI_CTX->DRM_right_tone_id &&
        WNOTI_CTX->notifycation_type != WIDGET_NOTIFICATION_DRM_RIGHT)
    {
        WNOTI_CTX->has_DRM_right = 0;
        WNOTI_CTX->DRM_right_tone_id = 0;
        WNOTI_CTX->DRM_right_image_id = 0;
        WNOTI_CTX->DRM_right_text = NULL;
    }
    GoBackSubLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  wap_leave_msg_notifcation_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_leave_msg_notifcation_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode, keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keyCode, &keyType);
    WNOTI_CTX->notifycation_type = WIDGET_NOTIFICATION_NONE;
    if (keyCode == KEY_END)
    {
        /* When press END key, back to idle screen */
        widget_goto_idlescreen();
    }
    else
    {
        GoBackHistory();
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wap_leave_msg_notifcation_pen_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL wap_leave_msg_notifcation_pen_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(point);
    /* When the user touch the popup, we will reset the current key information here. */
    SetkeyInfo(KEY_INVALID, MAX_KEY_TYPE);
    wap_leave_msg_notifcation_key_hdlr();
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wap_entry_msg_notification_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prompt      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_msg_notification_popup(PU8 prompt_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = IMG_NEW_MESSAGE_NOTIFICATION_MSG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_is_new_msg_popup_handled() == KAL_TRUE)
    {
        /*
         * If the applications won't want to show the WAP/MMS popup, 
         * we return here directly.
         */
        return;
    }
    
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_MSG_NOTIFICATION_POPUP);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    EntryNewScreen(WAP_SCREEN_MESSAGE_NOTIFICATION, exit_widget_msg_notification_popup, NULL, NULL);

    ClearKeyEvents();   /* Flush key queue */

    /*
     * We need to play sound after executing exit handler of the previous screen.
     * The previous screen can do correct handling of sound state.
     */
    if ((WNOTI_CTX->has_DRM_right) && (WNOTI_CTX->DRM_right_text == prompt_text))
    {
        /* 
         * Tricky!
         * WNOTI_CTX->DRM_right_text is only used for HDIa_widgetExtRegisterDRMRightNotification().
         *
         * If DRM right nitification popup is showed, we don't need to show it in the idle screen again.
         */

        img_id = WNOTI_CTX->DRM_right_image_id;
        WNOTI_CTX->notifycation_type = WIDGET_NOTIFICATION_DRM_RIGHT;
    }
    else if (WNOTI_CTX->has_MMS)
    {
        WNOTI_CTX->notifycation_type = WIDGET_NOTIFICATION_MMS;
    }
    else if (WNOTI_CTX->has_push)
    {
        WNOTI_CTX->notifycation_type = WIDGET_NOTIFICATION_PUSH;
    }
    else if (WNOTI_CTX->has_provision)
    {
        WNOTI_CTX->notifycation_type = WIDGET_NOTIFICATION_PROVISION;
    }
    else
    {
        WNOTI_CTX->notifycation_type = WIDGET_NOTIFICATION_OTHERS;
    }

    
    ShowCategory65Screen(prompt_text, img_id, NULL);
    ForceSubLCDScreen(mmi_msg_start_msg_sub_anm);
    if (widget_suppress_play_msg_arrival_tone == KAL_FALSE)
    {
        widget_play_msg_arrival_tone(prompt_text, KAL_TRUE); /* Set WNOTI_CTX->tone_id */
    }

    /* When the clam is closed, the handset will back to the idle screen */
    /* refer DisplayPopup() to set key/pen handler */
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);
    SetGroupKeyHandler(wap_leave_msg_notifcation_key_hdlr, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat65_register_pen_down_handler(wap_leave_msg_notifcation_pen_hdlr);
#endif

    mmi_frm_set_default_power_onoff_key();
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_MSG_NOTIFICATION_POPUP_END, prompt_text);
    
}

/*
 * Notify WAP to create message window
 * 
 * Note: The following functions should be executed in WAP task.
 */


/*****************************************************************************
 * FUNCTION
 *  widget_msg_notifiy_push
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __UNIFIED_MSG_SUPPORT__
static void widget_msg_notifiy_push(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MSG_NOTIFY_PUSH);

    /* When processing push in the idle screen, we clear the related settings */
    WNOTI_CTX->has_push = 0;    /* Prevent re-enter */
    bra_psl_notification_handler();
}
#endif /* !__UNIFIED_MSG_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  widget_msg_notifiy_urgent_service_loading
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_msg_notifiy_urgent_service_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MSG_NOTIFY_URGENT_SERVICE_LOADING);

    WNOTI_CTX->has_SLhigh = 0;    /* Prevent re-enter */
    bra_psl_SLhigh_notification_handler();
}


/*****************************************************************************
 * FUNCTION
 *  widget_msg_notifiy_urgent_service_indication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_msg_notifiy_urgent_service_indication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MSG_NOTIFY_URGENT_SERVICE_INDICATION);

    WNOTI_CTX->has_SIhigh = 0;    /* Prevent re-enter */
    bra_psl_SIhigh_notification_handler();
}


/*****************************************************************************
 * FUNCTION
 *  widget_msg_notifiy_provision
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_msg_notifiy_provision(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MSG_NOTIFY_PROVISION);

    /* When processing provision in the idle screen, we clear the related settings */
    WNOTI_CTX->has_provision = 0;   /* Prevent re-enter */
    WNOTI_CTX->provision_text = NULL;
    bra_prs_install_prov();
}


/*****************************************************************************
 * FUNCTION
 *  widget_msg_notifiy_DRM_right
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_msg_notifiy_DRM_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Only execute the function in the idle screen */
	WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MSG_NOTIFY_DRM_RIGHT);

    WAP_DBG_ASSERT(WNOTI_CTX->DRM_right_text);
    /* already play tone in widget_MMI_register_new_msg() */
    widget_suppress_play_msg_arrival_tone = KAL_TRUE;
	wap_entry_msg_notification_popup((PU8)WNOTI_CTX->DRM_right_text);
	widget_suppress_play_msg_arrival_tone = KAL_FALSE;
	WNOTI_CTX->has_DRM_right = 0; // Prevent re-enter
    WNOTI_CTX->DRM_right_tone_id = 0;
    WNOTI_CTX->DRM_right_image_id = 0;
    WNOTI_CTX->DRM_right_text = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_msg_notify_MMS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __UNIFIED_MSG_SUPPORT__
static void widget_msg_notify_MMS(void)
{
#ifdef MMS_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MSG_NOTIFY_MMS);

    /* When processing new message in the idle screen, we clear the related settings */
    WNOTI_CTX->has_MMS = 0; /* Prevent re-enter */
    WNOTI_CTX->MMS_count = 0;
    WNOTI_CTX->MMS_text = NULL;
    /*
     * Reference: MMSa_newMessage
     */
    WAP_DBG_ASSERT(!MSF_moduleIsRunning(MSF_MODID_MEA));
    WAP_DBG_ASSERT(WNOTI_CTX->MMS_msgid);
    switch (WNOTI_CTX->MMS_type)
    {
        case WIDGET_MMS_NEW_MSG:
        case WIDGET_MMS_READ_REPORT:
        case WIDGET_MMS_DELIVERY_REPORT:
            handleNewMessage(WNOTI_CTX->MMS_msgid);
            break;
        case WIDGET_MMS_NOTIFICATION:
            handleDownloadMessage(WNOTI_CTX->MMS_msgid, (MSF_UINT32) WNOTI_CTX->MMS_size);
            break;
    }
#endif /* MMS_SUPPORT */ 
}
#endif /* !__UNIFIED_MSG_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_register_new_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_register_new_msg(int arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 msg_text = (PU8)arg;
    kal_bool display_on_idle_screen = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_REGISTER_NEW_MSG, arg);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (wap_is_new_msg_popup_handled() == KAL_TRUE)
    {
        /*
         * If the applications won't want to show the WAP/MMS popup, 
         * we return here directly.
         */
        return;
    }

    if (widget_check_is_in_non_wap_call())
    {
        WNOTI_CTX->pending_by_call = 1;
    }

    TurnOnBacklight(1);

    /* Display it in idle screen or display popup otherwise */
#ifdef __UNIFIED_MSG_SUPPORT__        
    /* new MMS or new Push may be processed at the idle screen or UM's dummy screen */
    display_on_idle_screen = (g_idle_context.IsOnIdleScreen || g_idle_context.ScreenSaverRunFlag || !mmi_um_is_sending_num_msg()) && !widget_check_is_in_non_wap_call();
#else
    display_on_idle_screen = (g_idle_context.IsOnIdleScreen || g_idle_context.ScreenSaverRunFlag) && !widget_check_is_in_non_wap_call();
#endif

#ifdef __UNIFIED_MSG_SUPPORT__    
    if((WNOTI_CTX->has_MMS == 1 || WNOTI_CTX->has_push == 1) && (GetExitScrnID() == SCR_ID_UM_NEW_MSG_IND))
    {
        /* widget doesn't contorl new MMS and WAP push if unified message exists */
        return;
    }
#endif


    WNOTI_CTX->check_msg_in_idle_screen = WIDGET_MSG_NOTIFICATION_HAS_MSG;
    /* Display it in idle screen or display popup otherwise */
    if (display_on_idle_screen)
    {
		/* 
		 * We need to check flag here again to avoid the situation
		 * ex. In idle screen show new MMS, we need entry widget screen and to show unread message.
		 * But it is possible to process previous new MMS (for non-idle screen), and causes the problem.
		 */
		if (WNOTI_CTX->has_system_msg || 
		#ifndef __UNIFIED_MSG_SUPPORT__
			WNOTI_CTX->has_MMS ||
			WNOTI_CTX->has_push ||
		#endif
			WNOTI_CTX->has_SLhigh ||
			WNOTI_CTX->has_SIhigh ||
        #ifdef MSF_MODID_PRS
			WNOTI_CTX->has_provision ||
        #endif
			WNOTI_CTX->has_DRM_right)
		{        
			WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_REGISTER_NEW_MSG_GOTO_IDLE_SCREEN);

            if (g_keylock_context.gKeyPadLockFlag)
            {
                /* If we show message in keypad lock idle screen, we set the message text */
                WNOTI_CTX->msg_text_in_keypadlock = msg_text;
            }
            else
            {
                /*
                 * we will play arrival tone in widget_MMI_check_and_display_new_msg_when_keypad_lock() 
                 * because widget may not show notification when there is other
                 * higher priority interrupt screen in keypad lock idle screen.
                 */
                if (!mmi_bootup_get_active_flight_mode() || WNOTI_CTX->has_system_msg)
                {
                    /* If in the flight mode, we don't want to show notification popup */
                    widget_play_msg_arrival_tone(msg_text, KAL_FALSE);        // TODO: Play sound in message dialog of WAP?
                }


                WNOTI_CTX->msg_text_in_keypadlock = NULL;
            }
            WNOTI_CTX->check_msg_in_idle_screen = WIDGET_MSG_NOTIFICATION_WANT_TO_SHOW_IN_IDLE;

			EntryIdleScreen();  /* DisplayIdleScreen() do nothing in idle screen */
		}
    }
    else
    {
        if (widget_check_is_in_non_wap_call())        
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_REGISTER_NEW_MSG_IN_CALL);
            /* We don't display popup window in MO/MT call; Play tone only */
            playRequestedTone(SMS_IN_CALL_TONE);
        }
        else if (!AlmIsTonePlaying())
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_REGISTER_NEW_MSG_POPUP_DIRECTLY);
            wap_entry_msg_notification_popup(msg_text);
    	}

    } /* if (display_on_idle_screen) */

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtRegisterSystemMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  titleid     [IN]        
 *  msgid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtRegisterSystemMsg(MSF_UINT8 modId, widget_string_id titleid, widget_string_id msgid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // We can not print log here because widget_init_space_reservation invokes this function (from WAP task init)
    // WIDGET_LOG("HDIa_widgetExtRegisterSystemMsg()");
    if (WNOTI_CTX->has_system_msg == 0)
    {
        WNOTI_CTX->has_system_msg = 1;
    
        switch (modId)
        {
        #ifdef MMS_SUPPORT
            case MSF_MODID_MEA:
            case MSF_MODID_MMS:
            case MSF_MODID_SMA:
            case MSF_MODID_SLS:
                WNOTI_CTX->system_msg_icon = MEA_IMG_TITLE_NORMAL;
                break;
        #endif /* MMS_SUPPORT */ 
            default:
                WNOTI_CTX->system_msg_icon = WAP_IMAGE_WAP_LOGO;
                break;
        }
    
        WNOTI_CTX->system_msg_title = titleid;
        WNOTI_CTX->system_msg_msg = msgid;
        
        /* If in the idle screen, need to show system message directly. */
        if ((g_idle_context.IsOnIdleScreen || g_keylock_context.gKeyPadLockFlag || g_idle_context.ScreenSaverRunFlag) && !widget_check_is_in_non_wap_call())
        {
            /* We only display the system message in the idle screen */
            TurnOnBacklight(1);
            widget_execute_MMI_i((func_int)EntryIdleScreen, (int)NULL, KAL_FALSE);
        }

    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_REGISTER_SYSTEM_MSG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtClearSystemMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtClearSystemMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WNOTI_CTX->has_system_msg = 0;
    WNOTI_CTX->system_msg_icon = 0;
    WNOTI_CTX->system_msg_title = 0;
    WNOTI_CTX->system_msg_msg = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtRegisterNewPush
 * DESCRIPTION
 *  We will popup the notification first, and invoke push procedure in the idle screen
 *  We clear WNOTI_CTX->has_push until back to the idle screen.
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtRegisterNewPush(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_REGISTER_NEW_PUSH);

    WNOTI_CTX->has_push = 1;
    widget_execute_MMI_i(widget_MMI_register_new_msg, (int)GetString(WIDGET_STR_ID_RECEIVED_PUSH), KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtClearPush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtClearPush(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WNOTI_CTX->has_push = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtRegisterUrgentServiceLoading
 * DESCRIPTION
 *  one of WAP push, but has high priority to indicate the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtRegisterUrgentServiceLoading(kal_bool show_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_REGISTER_URGENT_SERVICE_LOADING);

    WNOTI_CTX->has_SLhigh = 1;
    if (show_popup)
    {
        widget_execute_MMI_i(widget_MMI_register_new_msg, (int)GetString(WIDGET_STR_ID_RECEIVED_PUSH), KAL_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtClearUrgentServiceLoading
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtClearUrgentServiceLoading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WNOTI_CTX->has_SLhigh = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtRegisterUrgentServiceIndication
 * DESCRIPTION
 *  one of WAP push, but has high priority to indicate the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtRegisterUrgentServiceIndication(kal_bool show_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_REGISTER_URGENT_SERVICE_INDICATION);

    WNOTI_CTX->has_SIhigh = 1;
    if (show_popup)
    {
        widget_execute_MMI_i(widget_MMI_register_new_msg, (int)GetString(WIDGET_STR_ID_RECEIVED_PUSH), KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtClearUrgentServiceIndication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtClearUrgentServiceIndication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WNOTI_CTX->has_SIhigh = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtRegisterNewProvision
 * DESCRIPTION
 *  We will popup the notification first, and invoke provision procedure in the idle screen
 *  We clear WNOTI_CTX->has_provision until back to the idle screen.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtRegisterNewProvision(widget_service_on_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_REGISTER_NEW_PROVISION);

#ifdef WIDGET_DUAL_SIM_SUPPORT
    if (sim_id == WAP_SERVICE_ON_MASTER_SIM)
    {
        WNOTI_CTX->provision_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_PROVISION_SIM_1);
    }
    else if (sim_id == WAP_SERVICE_ON_SLAVE_SIM)
    {
        WNOTI_CTX->provision_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_PROVISION_SIM_2);
    }
    else
    {
        WNOTI_CTX->provision_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_PROVISION);
    }
    
#else
    sim_id = WAP_SERVICE_ON_MASTER_SIM;
    WNOTI_CTX->provision_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_PROVISION);

#endif /* WIDGET_DUAL_SIM_SUPPORT */
    WNOTI_CTX->has_provision = 1;

    widget_execute_MMI_i(widget_MMI_register_new_msg, (int)WNOTI_CTX->provision_text, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtClearProvision
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtClearProvision(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WNOTI_CTX->has_provision = 0;
    WNOTI_CTX->provision_text = NULL;
}


/*****************************************************************************
* FUNCTION
*	HDIa_widgetExtRegisterDRMRightNotification
*
* DESCRIPTION
*
* PARAMETERS
*  MsfStringHandle            [IN]
*  MsfDialogType              [IN]
* RETURNS
*	void
* GLOBALS AFFECTED
*	
*****************************************************************************/ 
void HDIa_widgetExtRegisterDRMRightNotification(MsfStringHandle dialogText, MsfDialogType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ALERT_TYPE alertType;
    ctk_tone_id toneid;
    ctk_image_id imageid;
    kal_bool image_bottom;
    const kal_uint8 *text = HDIa_widgetExtStringGetUCS2buffer(dialogText);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_REGISTER_DRM_RIGHT);

    /* image_bottom isn't used. The image is always at top */
    widget_dialog_get_attributes(type, &imageid, &toneid, &image_bottom);
    alertType = GetMtCallAlertTypeEnum();

    if (alertType == MMI_VIBRATION_AND_RING || alertType == MMI_VIBRATION_THEN_RING || alertType == MMI_RING)
    {
        if (toneid == SUCCESS_TONE)
        {
            /* Because SUCCESS_TONE is no sound, we change it to MESSAGE_TONE */
            toneid = MESSAGE_TONE;
        }
    }
    else
    {
        toneid = 0;
    }

	WNOTI_CTX->has_DRM_right = 1;
    WNOTI_CTX->DRM_right_tone_id = toneid;
    WNOTI_CTX->DRM_right_image_id = imageid;
    WNOTI_CTX->DRM_right_text = (U8*)text;
	widget_execute_MMI_i(widget_MMI_register_new_msg, (int)WNOTI_CTX->DRM_right_text, KAL_FALSE);
}


/*****************************************************************************
* FUNCTION
*	HDIa_widgetExtClearDRMRightNotification
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*	void
* GLOBALS AFFECTED
*	
*****************************************************************************/ 
void HDIa_widgetExtClearDRMRightNotification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	WNOTI_CTX->has_DRM_right = 0;
    WNOTI_CTX->DRM_right_tone_id = 0;
    WNOTI_CTX->DRM_right_image_id = 0;
    WNOTI_CTX->DRM_right_text = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtRegisterNewMMS
 * DESCRIPTION
 *  We will popup the notification first, and invoke new MMS procedure in the idle screen
 *  We clear WNOTI_CTX->has_MMS until back to the idle screen.
 *  
 * PARAMETERS
 *  msgid       [IN]        
 *  type        [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtRegisterNewMMS(kal_uint32 msgid, widget_mms_msg_type_enum type, kal_uint32 size)
{
#ifdef MMS_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WIDGET_DUAL_SIM_SUPPORT
    int sim_status = wap_get_sim_status();
    int setting_mode = wap_get_sim_setting_mode();
    MSF_BOOL show_dual_sim_pop_flag = FALSE;
    if(sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_DUAL_SIM ||
       sim_status == WAP_SIM_ID_SIM1 && setting_mode == WAP_SIM_ID_SIM1 ||
       sim_status == WAP_SIM_ID_SIM1 && setting_mode == WAP_SIM_ID_DUAL_SIM ||
       sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_SIM1 ||
       sim_status == WAP_SIM_ID_SIM2 && setting_mode == WAP_SIM_ID_SIM2 ||
       sim_status == WAP_SIM_ID_SIM2 && setting_mode == WAP_SIM_ID_DUAL_SIM ||
       sim_status == WAP_SIM_ID_DUAL_SIM && setting_mode == WAP_SIM_ID_SIM2)
    {
        show_dual_sim_pop_flag = TRUE;
    }

    if(show_dual_sim_pop_flag == FALSE)
    {
        return;
    }

#endif /*WIDGET_DUAL_SIM_SUPPORT*/


#ifdef __USB_IN_NORMAL_MODE__
	if (mmi_usb_is_leaving_ms_mode())
	{
	    WAP_DBG_ASSERT(msgid);
	    ASSERT(type < 16);  /* 4 bit */

	    WNOTI_CTX->has_MMS = 1;
	    WNOTI_CTX->MMS_count++;

	    WNOTI_CTX->MMS_msgid = msgid;
	    WNOTI_CTX->MMS_type = type;
	    WNOTI_CTX->MMS_size = size;
		return;
	}

    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_REGISTER_NEW_MMS, msgid, (int)type, size);
    WAP_DBG_ASSERT(msgid);
    ASSERT(type < 16);  /* 4 bit */

    WNOTI_CTX->has_MMS = 1;
    WNOTI_CTX->MMS_count++;

    WNOTI_CTX->MMS_msgid = msgid;
    WNOTI_CTX->MMS_type = type;
    WNOTI_CTX->MMS_size = size;

#ifdef WIDGET_DUAL_SIM_SUPPORT
    /*
     * In dual sim situation,
     * we will check if SIM id of message match SIM status of the phone.
     */
    if (wap_get_sim_status() == WAP_SIM_ID_DUAL_SIM ||
        (wap_get_sim_status() == WAP_SIM_ID_SIM1 && fldrGetMessageSimId(msgid) == MMS_SIM_CARD_MASTER) ||
        (wap_get_sim_status() == WAP_SIM_ID_SIM2 && fldrGetMessageSimId(msgid) == MMS_SIM_CARD_SLAVE))
#endif /*WIDGET_DUAL_SIM_SUPPORT*/
    {
        switch (type)
        {
            case WIDGET_MMS_NEW_MSG:
    #ifdef WIDGET_DUAL_SIM_SUPPORT
            if (fldrGetMessageSimId(msgid) == MMS_SIM_CARD_MASTER)
            {
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_1);
            }
            else
            {
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_2);
            }
    #else
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_MSG);
    #endif /*WIDGET_DUAL_SIM_SUPPORT*/
                break;
    
            case WIDGET_MMS_READ_REPORT:
    #ifdef WIDGET_DUAL_SIM_SUPPORT
            if (fldrGetMessageSimId(msgid) == MMS_SIM_CARD_MASTER)
            {
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT_SIM_1);
            }
            else
            {
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT_SIM_2);
            }
    #else
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT);
    #endif /*WIDGET_DUAL_SIM_SUPPORT*/
                break;
    
            case WIDGET_MMS_DELIVERY_REPORT:
    #ifdef WIDGET_DUAL_SIM_SUPPORT
            if (fldrGetMessageSimId(msgid) == MMS_SIM_CARD_MASTER)
            {
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT_SIM_1);
            }
            else
            {
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT_SIM_2);
            }
    #else
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT);
    #endif /*WIDGET_DUAL_SIM_SUPPORT*/
                break;
    
            case WIDGET_MMS_NOTIFICATION:
    #ifdef WIDGET_DUAL_SIM_SUPPORT
            if (fldrGetMessageSimId(msgid) == MMS_SIM_CARD_MASTER)
            {
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION_SIM_1);
            }
            else
            {
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION_SIM_2);
            }
    #else
                WNOTI_CTX->MMS_text = (U8*)GetString(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION);
    #endif /*WIDGET_DUAL_SIM_SUPPORT*/
    
                break;
    
            default:
                ASSERT(0);
        }
    
        /*
         * widget_MMI_register_new_msg must be executed "asynchronously" because 
         * if widget_msg_notifiy_MMS() found new message, it will invoke HDIa_widgetExtRegisterNewMMS 
         * again.
         */
    
        widget_execute_MMI_i(widget_MMI_register_new_msg, (int)WNOTI_CTX->MMS_text, KAL_FALSE);
    }

#endif /* MMS_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtClearMMS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtClearMMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CLEAR_MMS);

    WNOTI_CTX->has_MMS = 0;
    WNOTI_CTX->MMS_count = 0;

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGetMMSMessageID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 HDIa_widgetExtGetMMSMessageID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WNOTI_CTX->has_MMS)
    {
        return WNOTI_CTX->MMS_msgid;
    }
    else
    {
        return 0;
    }
}

/******************************************************************************
 *
 * Callback functions for MMI
 *
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_on_exit_CM
 * DESCRIPTION
 *  Invoked when all active call ended (in MMI task)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_on_exit_CM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(!widget_check_is_in_call());

    if (WNOTI_CTX->pending_by_call)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_ON_EXIT_CM);

        WNOTI_CTX->pending_by_call = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_check_and_display_new_msg_when_keypad_lock
 * DESCRIPTION
 *  This function must be invoked from EntryIdleScreen (Keypad locked)
 * PARAMETERS
 *  KeyLockLSKStringID      [IN]        
 *  KeyLockLSKIconID        [IN]        
 *  KeyLockRSKStringID      [IN]        
 *  KeyLockRSKIconID        [IN]        
 * RETURNS
 *  Whether WAP take over the display
 *****************************************************************************/
int widget_MMI_check_and_display_new_msg_when_keypad_lock(
        U16 KeyLockLSKStringID,
        U16 KeyLockLSKIconID,
        U16 KeyLockRSKStringID,
        U16 KeyLockRSKIconID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img = 0;
    S8 *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!MSF_wapIsReady())
    {
        return 0;
    }
    else
    {
        if (widget_message_notification_is_empty())
        {
            if (WNOTI_CTX->has_system_msg)
            {
                str = (S8*)get_string((MMI_ID_TYPE)WNOTI_CTX->system_msg_msg);
                img = IMG_GLOBAL_INFO;
            }
        }
        else
        {
            str = (S8*)(WNOTI_CTX->msg_text_in_keypadlock);
            if (WNOTI_CTX->has_DRM_right && str == (S8*)(WNOTI_CTX->DRM_right_text))
            {
                /* 
                 * Tricky!
                 * WNOTI_CTX->DRM_right_text is only used for HDIa_widgetExtRegisterDRMRightNotification().
                 *
                 * If DRM right nitification popup is showed, we don't need to show it in the idle screen again.
                 */

                img = WNOTI_CTX->DRM_right_image_id;
            }
            else
            {
                /* 
                 * If __UNIFIED_MSG_SUPPORT__ is enable,
                 * the widget doesn't need to handel wap push and new MMS 
                 * because MMI unified message handles it.
                 */
                img = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
            }
        }

        if (str != NULL)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_WHEN_KEYPAD_LOCK);
            if (WNOTI_CTX->check_msg_in_idle_screen == WIDGET_MSG_NOTIFICATION_WANT_TO_SHOW_IN_IDLE)
            {
                /*
                 * we will play arrival tone in 
                 * widget_MMI_check_and_display_new_msg_when_keypad_lock() 
                 * because widget may not show notification when there is other
                 * higher priority interrupt screen in keypad lock idle screen.
                 *
                 * We only play arrivial tone once when invoke the popup from widget_MMI_register_new_msg()
                 */
                widget_play_msg_arrival_tone((PU8)str, KAL_FALSE);
                WNOTI_CTX->check_msg_in_idle_screen = WIDGET_MSG_NOTIFICATION_SHOWN_IN_KEYPAD_LOCK;
            }

            /* We need to draw the idle screen to be the background */
            gui_lock_double_buffer();
            RedrawIdleScreen();
            DisplayConfirm(
                KeyLockLSKStringID,
                KeyLockLSKIconID,
                KeyLockRSKStringID,
                KeyLockRSKIconID,
                (PU16) str,
                img,
                0);
            gui_unlock_double_buffer();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            return 1;
        }

        /* If we don't show category, we should return 0 and let idlescreen does its job */
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_display_system_msg
 * DESCRIPTION
 *  Display system message
 *  Reference: mmi_msg_entry_mem_exceed_ind()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_go_back_from_system_msg(void);
static void widget_end_key_from_system_msg(void);

void wap_entry_display_system_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENTRY_DISPLAY_SYSTEM_MSG);
    EntryNewScreen(WAP_SCREEN_SYSTEM_MESSAGE, NULL, wap_entry_display_system_msg, NULL);

    ShowCategory2Screen(
        WNOTI_CTX->system_msg_title,
        WNOTI_CTX->system_msg_icon,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WNOTI_CTX->system_msg_msg,
        NULL);

    /* Don't need to suspend background sound */
    widget_play_msg_arrival_tone((U8*)GetString(WNOTI_CTX->system_msg_msg), KAL_FALSE);

    SetRightSoftkeyFunction(widget_go_back_from_system_msg, KEY_EVENT_UP);
    SetKeyHandler(widget_go_back_from_system_msg, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(widget_end_key_from_system_msg, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  widget_go_back_from_system_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_go_back_from_system_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WNOTI_CTX->has_system_msg = 0;
    WNOTI_CTX->system_msg_icon = 0;
    WNOTI_CTX->system_msg_title = 0;
    WNOTI_CTX->system_msg_msg = 0;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  widget_end_key_from_system_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_end_key_from_system_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WNOTI_CTX->has_system_msg = 0;
    WNOTI_CTX->system_msg_icon = 0;
    WNOTI_CTX->system_msg_title = 0;
    WNOTI_CTX->system_msg_msg = 0;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_check_and_display_new_msg
 * DESCRIPTION
 *  This function must be invoked from EntryIdleScreen (Keypad unlocked)
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether WAP take over the display
 *****************************************************************************/
int widget_MMI_check_and_display_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 
     * We display provision -> push -> MMS sequentially
     * and it should go back to idle screen again before we display the next notification
     *
     * Because the WAP UI is shutdowning in idle screen, 
     * we wait until WAP UI is completely terminated in order to simplify window management.
     * 
     */
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(WIDGET_IS_MMI_TASK());
    ASSERT(!WIPC_CTX->MMI_is_waiting && !WIPC_CTX->WAP_is_waiting);

    WAP_DBG_ASSERT(g_idle_context.IsOnIdleScreen);

    ASSERT(!WIPC_CTX->wait_message_notification_in_idle_screen);        /* Be paranoid */

   /*
    * MMI task may invoke WAP task to enter widget screen. 
    * We need to avoid deadlock when MMI task waits WAP task enter widget screen but 
    * WAP task calls HDIa_widgetExtForcePopup().
    */
    WGUI_CTX->is_in_goto_idle_screen = 1;
    /* We need to clear msg_text_in_keypadlock when entry idle screen without keypad lock */
    WNOTI_CTX->msg_text_in_keypadlock = NULL;
    if (!MSF_wapIsReady() || WNOTI_CTX->check_msg_in_idle_screen == WIDGET_MSG_NOTIFICATION_NO_MSG)
    {
        ret = 0;
    }
    else
    {
        if (WNOTI_CTX->has_system_msg)
        {
            ClearKeyEvents();
            WGUI_CTX->is_in_goto_idle_screen = 0;
            wap_entry_display_system_msg();
    		
    		return 1; /* Do not continue displaying idle screen */
    	}	
        else if (WNOTI_CTX->has_SLhigh)
        {
            /* need to process this notification before than others */
            WIPC_CTX->wait_message_notification_in_idle_screen = 1;
            ClearKeyEvents();
            widget_execute_WAP(widget_msg_notifiy_urgent_service_loading, KAL_TRUE);
            ret = 1;
        }
        else if (WNOTI_CTX->has_SIhigh)
        {
            /* need to process this notification before than others */
            WIPC_CTX->wait_message_notification_in_idle_screen = 1;
            ClearKeyEvents();
            widget_execute_WAP(widget_msg_notifiy_urgent_service_indication, KAL_TRUE);
            ret = 1;
        }
    #ifndef __UNIFIED_MSG_SUPPORT__
        else if (WNOTI_CTX->has_push)
        {
            WIPC_CTX->wait_message_notification_in_idle_screen = 1;
            ClearKeyEvents();
            widget_execute_WAP(widget_msg_notifiy_push, KAL_TRUE);
            ret = 1;
        }
    #ifdef __USB_IN_NORMAL_MODE__
        else if (WNOTI_CTX->has_MMS && !(mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc()))
    #else
        else if (WNOTI_CTX->has_MMS)
    #endif
        {
            // TODO: We should display the first screen with MMI category, which reduce a lot of efforts.
            WIPC_CTX->wait_message_notification_in_idle_screen = 1;
            ClearKeyEvents();
            widget_execute_WAP(widget_msg_notify_MMS, KAL_TRUE);
            ret = 1;
        }
    #endif  /* !__UNIFIED_MSG_SUPPORT__ */
    	else if (WNOTI_CTX->has_DRM_right)
    	{
    		/* We need to redraw the idle screen first to avoid the background screen is the previous one */
    		ClearKeyEvents();
            RedrawIdleScreen();
            WGUI_CTX->is_in_goto_idle_screen = 0;
    		widget_msg_notifiy_DRM_right();
    		
    		return 1; /* Do not continue displaying idle screen */
    	}
        else if (WNOTI_CTX->has_provision)
        {
            WIPC_CTX->wait_message_notification_in_idle_screen = 1;
            ClearKeyEvents();
            widget_execute_WAP(widget_msg_notifiy_provision, KAL_TRUE);
            ret = 1;
        }
        else if (WGUI_CTX->has_popup_in_idle_screen == 1)
        {
            ClearKeyEvents();
            WGUI_CTX->is_in_goto_idle_screen = 0;
            /* Force to show popup (HDIa_widgetExtShowPopup or HDIa_widgetExtForcePopup) */
            widget_MMI_display_popup(WIDGET_EXT_FORCE_POPUP_IN_IDLE_CHECKING | WIDGET_EXT_FORCE_POPUP_FLAG);
            WGUI_CTX->has_popup_in_idle_screen = 0;
            return 1; /* Do not continue displaying idle screen */
        }
    }

    if (ret)
    {
        /* widget_send_update_event_to_wap(); // Deprecated 2004.05.16. Use widget_execute_WAP() instead */

        /* 
         * We expect WAP to create new screen, but we cannot count on this.
         * Otherwise, it may cause MMI to hang if WAP has a small bug that it do not create new message window.
         *
         * NOTE: widget_execute_WAP() guarentee that WAP will finish processing its internal queue 
         * before returning back to MMI, but IT DOES NOT GUARENTEE THAT IT WILL CREATE NEW SCREENS
         * because if file I/O is blocked, WAP will finish internal queue and wait for file ready indication from external queue
         *
         */
        int retry = 0;
        gdi_handle base_handle;

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CHECK_AND_DISPLAY_MSG, ret);

        /* Prevent race condition that WAP wait to display something in MMI task after previous widget_execute_WAP() returned */
        ASSERT(!WIPC_CTX->MMI_is_waiting && !WIPC_CTX->WAP_is_waiting);
        WIPC_CTX->MMI_is_waiting = 1;

        /* We entry the dummy screen to avoid the other application update the screen in the idle screen */
	    EntryNewScreen(WAP_SCREEN_WIDGET_DUMMY, wap_exit_dummy_widget_screen, NULL, NULL);

        /* we clear the fullscreen first and then widget to update the screen. */
        gdi_layer_get_base_handle(&base_handle);
        gdi_layer_push_and_set_active(base_handle);
        gdi_layer_clear(GDI_COLOR_WHITE);
        gdi_layer_pop_and_restore_active();

        do
        {
			if (!(g_idle_context.IsOnIdleScreen || GetActiveScreenId() == WAP_SCREEN_WIDGET_DUMMY) )
            {
                WAP_DBG_ASSERT(0);  /* HDIa_widgetSetInFocus does not enter widget screen if WIPC_CTX->wait_message_notification_in_idle_screen is set */
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CHECK_AND_DISPLAY_MSG_NOT_IN_WIDGET_SCREEN);
                WIPC_CTX->wait_message_notification_in_idle_screen = 0;
                WIPC_CTX->pending_to_enter_widget_screen = 0;
                WIPC_CTX->MMI_is_waiting = 0;
                WGUI_CTX->is_in_goto_idle_screen = 0;
                return ret;
            }
            if (WIPC_CTX->pending_to_enter_widget_screen)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CHECK_AND_DISPLAY_MSG_REQUEST_TO_DISPLAY_WIDGET_SCREEN);
                WIPC_CTX->pending_to_enter_widget_screen = 0;
                WIPC_CTX->wait_message_notification_in_idle_screen = 0;
                WIPC_CTX->MMI_is_waiting = 0;
                wap_entry_widget_screen();
                WGUI_CTX->is_in_goto_idle_screen = 0;
                return ret;
            }

            kal_sleep_task(kal_milli_secs_to_ticks(100));
        } while (retry++ < 40); /* Wait 4 sec */
    #ifndef __PRODUCTION_RELEASE__
        ASSERT(0);
    #endif 
    }

    WIPC_CTX->pending_to_enter_widget_screen = 0;
    WIPC_CTX->wait_message_notification_in_idle_screen = 0;
    WIPC_CTX->MMI_is_waiting = 0;
    WGUI_CTX->is_in_goto_idle_screen = 0;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_check_msg_in_idle_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void widget_check_msg_in_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * If no msg notification need to be shown in idle screen,
     * we change WNOTI_CTX->check_msg_in_idle_screen value.
     * Or we keep WNOTI_CTX->check_msg_in_idle_screen value without change.
     */
    if (!WNOTI_CTX->has_system_msg &&
        !WNOTI_CTX->has_SLhigh &&
        !WNOTI_CTX->has_SIhigh &&
    #ifndef __UNIFIED_MSG_SUPPORT__
        !WNOTI_CTX->has_push &&
        !WNOTI_CTX->has_MMS &&
    #endif /* __UNIFIED_MSG_SUPPORT__ */
        !WNOTI_CTX->has_DRM_right &&
        !WNOTI_CTX->has_provision &&
        !WGUI_CTX->has_popup_in_idle_screen)
    {
        WNOTI_CTX->check_msg_in_idle_screen = WIDGET_MSG_NOTIFICATION_NO_MSG;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_scrollbar_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 widget_get_scrollbar_width()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Scrollbar width. It should sync with ThemeRes.c. */
    return UI_SCROLLBAR_WIDTH;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtEntryVirtualWidgetScreen
 * DESCRIPTION
 *  This function is used with HDIa_widgetExtDisplayTransitionAnimation() serial API.
 *  When HDIa_widgetExtCloseTransitionAnimation() is called, we will reset who_want_to_enter_widget_screen
 *  
 * PARAMETERS
 *  scrnID            [IN]
 * RETURNS
 *  
 *****************************************************************************/
void HDIa_widgetExtEntryVirtualWidgetScreen(U16 scrnID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(scrnID != WIDGET_VIRTUAL_SCREEN_ID);
    WGUI_CTX->who_want_to_enter_widget_screen = scrnID;
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_shutdown_UI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 widget_is_shutdown_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WGUI_CTX->is_shutdown_UI;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtIsCurrentFocusedPaintbox
 * DESCRIPTION
 *  To check if current window is focused on paintbox
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool HDIa_widgetExtIsCurrentFocusedPaintbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_window == WGUI_CTX->current_focused_paintbox)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtIsWaitingMessageNotificationInIdleScreen
 * DESCRIPTION
 *  Provide API for the application to know the situation that
 *  back to idle screen and need WAP task to show the notification
 *  In this case, WAP task can't use any block function ask MMI to do the actions
 *  (ex. Need use MsfDialog not use HDIa_widgetExtForcePopup, or cause the deadlock)
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool HDIa_widgetExtIsWaitingMessageNotificationInIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     *  Provide API for the application to know the situation that
     *  back to idle screen and need WAP task to show the notification
     *  In this case, WAP task can't use any block function ask MMI to do the actions
     *  (ex. Need use MsfDialog not use HDIa_widgetExtForcePopup, or cause the deadlock)
     */
    if (WIPC_CTX->wait_message_notification_in_idle_screen)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}





