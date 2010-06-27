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
 *  wgui_categories_CM.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Call Management related categories.
 *
 *  Author:
 * -------
 *  Leo Hu (MTK00563)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef WGUI_CATEGORIES_CM_H
#define WGUI_CATEGORIES_CM_H

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_tab_bars.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define DURATION_CM_HEIGHT          15
#define SHOW_DURATION               1
#define NO_DURATION                 0
#define UI_MAX_TAB_BAR_ITEMS                    20
extern tab_bar_item_type MMI_tab_bar_items[UI_MAX_TAB_BAR_ITEMS];



/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID = 0,
    WGUI_CATE_MOMT_RES_TYPE_VIDEO_ID,
    WGUI_CATE_MOMT_RES_TYPE_SWFLASH_ID,
    WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE,
    WGUI_CATE_MOMT_RES_TYPE_VIDEO_FILE,
    WGUI_CATE_MOMT_RES_TYPE_SWFLASH_FILE,
    WGUI_CATE_MOMT_RES_TYPE_AVATAR_FILE
} wgui_cate_momt_res_type_enum;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/* Category 16 */
#if (( defined ( __MMI_MAINLCD_176X220__ ) || defined (__MMI_MAINLCD_240X320__)  || defined (__MMI_MAINLCD_320X240__)) && defined (__GDI_MEMORY_PROFILE_2__) )
#ifndef __MMI_TOUCH_DIAL_SCREEN__
#ifdef __MMI_ALPHA_BLENDING__
void cat16_swflash_callback(S32 offset_x, S32 offset_y, S32 width, S32 height);
#endif
#endif
#endif

extern void RedrawCategory16Screen(void);
extern void ShowCategory16Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *Buffer,
                U32 BufferLength,
                U8 *history_buffer);
extern void ExitCategory16Screen(void);
extern U8 *GetCategory16History(U8 *history_buffer);
extern S32 GetCategory16HistorySize(void);
void SetCategory16RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
extern void RegisterCategory16NavigationKeys(void);
#ifdef __MMI_TOUCH_DIAL_SCREEN__
extern void PlayDialKeyPadTone(S16 key_type);
#endif

/* Category 17 */
extern void ShowCategory17Screen(
                U16 title_id,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 NotificationStringId,
                PU8 NameOrNumber,
                PU8 IP_Number,
                U16 CallLine,
                U16 default_image_id,
                U16 resource_id,
                PS8 resource_filename,
                wgui_cate_momt_res_type_enum resource_type,
                U16 repeat_count,
                BOOL is_visaul_update,
                BOOL is_aud_enable,
                BOOL is_play_aud_when_start,
                PU8 history_buffer);
#if defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_UCM__)
extern void ShowCategoryBothIncomingScreen(
	        U16 title_id,
	        U16 left_softkey,
	        U16 left_softkey_icon,
	        U16 right_softkey,
	        U16 right_softkey_icon,
	        U16 NotificationStringId,
	        PU8 NameOrNumber,
	        PU8 SlaveNameOrNumber,
	        PU8 IP_Number,
	        U16 CallLine,
	        U16 default_image_id,
	        U16 resource_id,
	        PS8 resource_filename,
	        wgui_cate_momt_res_type_enum resource_type,
	        U16 repeat_count,
	        BOOL is_visaul_update,
	        BOOL is_aud_enable,
	        BOOL is_play_aud_when_start,
	        PU8 history_buffer);
#endif  /*defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_UCM__)*/

extern void RedrawCategory17Screen(void);
extern void ExitCategory17Screen(void);

extern void StopCategory17Video(void);
extern void DisableCategory17Audio(void);
extern void EnableCategory17Audio(void);
extern void DisableCategory17VideoUpdate(void);
extern void EnableCategory17VideoUpdate(void);
extern void MOMTHideAnimation(void);
extern MMI_BOOL IsCategory17VideoValid(void);   /* call this function after ShowCategory17Screen */
extern MMI_BOOL IsCategory17SWFlashValid(void);  /* call this function after ShowCategory17Screen */
extern MMI_BOOL IsCategory17AvatarValid(void); /* call this function after ShowCategory17Screen */

/* Category 18 */
extern void ShowCategory18Screen(
                U16 title_id,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 NotificationStringId,
                PU8 NameOrNumber,
                PU8 IP_Number,
                U16 CallLine,
                U16 image_id,
                PS8 image_filename,
                MMI_BOOL isDisconnecting,
                PU8 history_buffer);

/* Category 19 */
extern void ShowCategory19Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_calls,
                U8 **CallList,
                U16 *CallLines,
                U16 *CallStates,
                MYTIME *CurrCallTime,
                S32 highlighted_item,
                U8 *history_buffer);
extern void ExitCategory19Screen(void);
extern S32 GetCategory19HistorySize(void);
extern U8 *GetCategory19History(U8 *history_buffer);
extern void RedrawCategory19Screen(void);

/* Category 20 */
extern void ShowCategory20Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *NameOrNumber,
                MYTIME *CurrCallTime,
                U16 CallLine,
                U16 CallState,
                MMI_BOOL isDisconnecting,
                U8 *history_buffer);

extern void ExitCategory20Screen(void);
extern void RedrawCategory20Screen(void);
extern S32 GetCategory20HistorySize(void);
extern U8 *GetCategory20History(U8 *history_buffer);

/* Category 308 */
extern void ShowCategory308Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *NameOrNumber,
                U16 bkg_image,
                U16 call_image,
                MYTIME *CurrCallTime,
                U8 *history_buffer,
                U8 show_duration);

extern void ExitCategory308Screen(void);
extern U8 *GetCategory308History(U8 *history_buffer);
extern S32 GetCategory308HistorySize(void);
extern void RedrawCategory308Screen(void);

/* Category 309 */
extern void ExitCategory309Screen(void);
extern U8 *GetCategory309History(U8 *history_buffer);
extern S32 GetCategory309HistorySize(void);
extern void RedrawCategory309Screen(void);
extern void ChangeCategory309Status(U8 index, U8 value);
extern void Show_MainImages_Category309(void);
extern void ShowCategory309Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *NumberorName,
                U16 bkg_image,
                MYTIME *CurrCallTime,
                U8 *status_calls,
                U8 *history_buffer);

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
void SetDialingKeypadCallHandler(void (*handler) (void));
void SetDialingKeypadPhonebookHandler(void (*handler) (void));
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 

extern void ShowCategory403Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items,
                MYTIME *CallDuration,
                U16 duration_icon,
                U8 **list_of_items,
                U16 *list_of_icons,
                S32 number_of_items,
                U16 highlighted_item,
                U8 *history_buffer);

extern void UpdateCategory403TabBar(
                UI_string_type title,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items);

extern void Category403UnBlinkTab(S8 tab);

extern void Category403BlinkTab(S8 tab);

void SetCategory403TabSelectCallback(void (*select_callback) (int index));

#if defined(__MMI_MAINLCD_320X240__)
    #define CAT404_INPUTBOX_X       (25)
    #define CAT404_INPUTBOX_Y       (50)
    #define CAT404_INPUTBOX_WIDTH   (275)
    #define CAT404_INPUTBOX_HEIGHT  (90)
#elif defined(__MMI_MAINLCD_240X320__)
    #define CAT404_INPUTBOX_X       (24)
    #define CAT404_INPUTBOX_Y       (93)
    #define CAT404_INPUTBOX_WIDTH   (192)
    #define CAT404_INPUTBOX_HEIGHT  (102)
#elif defined(__MMI_MAINLCD_176X220__)
    #define CAT404_INPUTBOX_X       (17)
    #define CAT404_INPUTBOX_Y       (62)
    #define CAT404_INPUTBOX_WIDTH   (144)
    #define CAT404_INPUTBOX_HEIGHT  (62)
#elif defined(__MMI_MAINLCD_128X160__)
    #define CAT404_INPUTBOX_X       (10)
    #define CAT404_INPUTBOX_Y       (65)
    #define CAT404_INPUTBOX_WIDTH   (108)
    #define CAT404_INPUTBOX_HEIGHT  (60)
#elif defined(__MMI_MAINLCD_128X128__)
    #define CAT404_INPUTBOX_X       (9)
    #define CAT404_INPUTBOX_Y       (51)
    #define CAT404_INPUTBOX_WIDTH   (110)
    #define CAT404_INPUTBOX_HEIGHT  (50)
#endif


extern void ShowCategory404Screen(
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            U16 bg_image,
            U8 *Buffer,
            U32 BufferLength,
            U8 *history_buffer);

#endif /* WGUI_CATEGORIES_CM_H */ 

