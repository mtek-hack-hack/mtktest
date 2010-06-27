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
 *  gui_main_menu_post_oem.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Main Menu Post OEM Layer Header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GUI_MAIN_MENU_POST_OEM_H__
#define __GUI_MAIN_MENU_POST_OEM_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && defined(__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__) && (__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__ == HIGHLIGHT_EFFECT_SLIDE)
#define __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
#endif /* defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && defined(__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__) && (__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__ == HIGHLIGHT_EFFECT_SLIDE) */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
extern void gui_main_menu_matrix_slide_start(void);
extern void gui_main_menu_matrix_slide_end(void);
extern void gui_main_menu_matrix_slide_stop(void);

extern S32 gui_main_menu_matrix_slide_is_under_control(void);
#else /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */
#define gui_main_menu_matrix_slide_start()  
#define gui_main_menu_matrix_slide_end()
#define gui_main_menu_matrix_slide_stop()

#define gui_main_menu_matrix_slide_is_under_control()   0
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

#endif /* __GUI_MAIN_MENU_POST_OEM_H__ */

