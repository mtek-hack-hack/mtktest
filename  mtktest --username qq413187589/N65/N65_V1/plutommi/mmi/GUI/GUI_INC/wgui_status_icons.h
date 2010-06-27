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
 * wgui_status_icons.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for status icon bars control.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 */

/*
 * removed!
 * removed!
 * removed!
*/


/**********************************************************************************
   Filename:      wgui_status_icons.h
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines
               Status Icon wrappers
**********************************************************************************/

#ifndef __WGUI_STATUS_ICONS_H__
#define __WGUI_STATUS_ICONS_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "wgui_categories.h"
#ifdef __MMI_TOUCH_SCREEN__

#ifndef _TOUCH_SCREEN_GPROT_H
#error "please include TouchScreenGprot.h before wgui_status_icons.h"
#endif 

#endif /* __MMI_TOUCH_SCREEN__ */ 
#define MAX_STATUS_ICON_BARS           3        /* 1 to ?         */
#define STATUS_ICON_TIMER_RATE            500   /* Milliseconds   */

    /* Bear, move from wgui_status_icons.c - for wgui.c to include */
#define MMI_N_STATUS_ICONS_LIST1 12
#define MMI_N_STATUS_ICONS_LIST2 8
#define MMI_N_STATUS_ICONS_LIST3 6

#ifdef __MMI_LCD_PARTIAL_ON__
#define MMI_N_STATUS_ICONS_PARTIAL_DISPLAY      4
    extern S16 MMI_status_icons_list_partial_display[MMI_N_STATUS_ICONS_PARTIAL_DISPLAY];
    extern S16 MMI_status_icons_partial_display_n_icons;
#endif /* __MMI_LCD_PARTIAL_ON__ */ 
    enum STATUS_ICON_FORCE_DISPLAY
    {
        DEFAULT_BOTH,
        MAINLCD_ONLY,
        SUBLCD_ONLY
    };

    /* Icon names that the applications must use when they call                                  
       ShowStatusIcon or HideStatusIcon                   */
    enum STATUS_ICON_LIST
    {
        STATUS_ICON_SIGNAL_STRENGTH = 0,
        STATUS_ICON_BATTERY_STRENGTH,

#ifdef __MMI_DUAL_SIM_MASTER__
	STATUS_ICON_SLAVE_SIGNAL_STRENGTH,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef __MMI_WLAN_FEATURES__
	    STATUS_ICON_WLAN_SIGNAL,
    #endif
    #ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__     /* 022505 Calvin added */
        STATUS_ICON_ALTERNATE_LINE_L1,
        STATUS_ICON_ALTERNATE_LINE_L2,
    #endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
    #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) /* 112805 3G icon Calvin */
/* under construction !*/
/* under construction !*/
    #endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
    #ifdef __MMI_VOIP__//091806 voip icon
        STATUS_ICON_VOIP,
    #endif /* __MMI_VOIP__ */ 
        STATUS_ICON_ROAMING,
#ifdef __MMI_DUAL_SIM_MASTER__
	STATUS_ICON_SLAVE_ROAMING,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
        STATUS_ICON_CALL_DIVERT_L1L2,
        STATUS_ICON_CALL_DIVERT_L1,
        STATUS_ICON_CALL_DIVERT_L2,
#ifdef __MMI_DUAL_SIM_MASTER__
        STATUS_ICON_SLAVE_CALLFORWARD,
        STATUS_ICON_SLAVE_CALLFORWARD_L1,
        STATUS_ICON_SLAVE_CALLFORWARD_L2,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
        STATUS_ICON_MUTE,
        STATUS_ICON_INCOMING_SMS,
#ifdef __MMI_DUAL_SIM_MASTER__
	STATUS_ICON_SLAVE_INCOMING_SMS,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
        STATUS_ICON_MMS_UNREAD,
        STATUS_ICON_MMS_BUSY,        
#ifdef __MMI_DUAL_SIM_MASTER__
        STATUS_ICON_MMS_UNREAD_SIM_1,
        STATUS_ICON_MMS_UNREAD_SIM_2,
        STATUS_ICON_MMS_BUSY_SIM_1,
        STATUS_ICON_MMS_BUSY_SIM_2,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        STATUS_ICON_OUTBOX_INDICATOR,
    #endif /*  __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        STATUS_ICON_VIBRATION,
        STATUS_ICON_SILENT,
        STATUS_ICON_RING,
        STATUS_ICON_VIBRATE_AND_RING,
        STATUS_ICON_VIBRATE_THEN_RING,
        STATUS_ICON_EDGE,
        STATUS_ICON_GPRS_SERVICE,
        STATUS_ICON_EDGEC,
        STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR,  /* 010406 G icon Calvin */        
        
#ifdef __MMI_DUAL_SIM_MASTER__
        STATUS_ICON_SLAVE_EDGE, // for SIM2
        STATUS_ICON_SLAVE_GPRS_SERVICE,
        STATUS_ICON_SLAVE_EDGEC,
        STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR,
#endif

    #if (defined(OBIGO_Q05A) || defined(JATAAYU_SUPPORT)) && defined(WAP_SUPPORT)
        STATUS_ICON_SECURITY,
    #endif
        STATUS_ICON_EARPHONE_INDICATOR,
        STATUS_ICON_ALARM,
        STATUS_ICON_VOICE_RECORD,
        STATUS_ICON_KEYPAD_LOCK,
        STATUS_ICON_MISSED_CALL,
    #ifdef __MMI_DUAL_SIM_MASTER__
	 STATUS_ICON_CARD2MISSED_CALL,
    #endif  /*__MMI_DUAL_SIM_MASTER__*/
    
        STATUS_ICON_UNREAD_EMAIL,
        
        STATUS_ICON_UNREAD_VOICE_L1L2,
        STATUS_ICON_UNREAD_VOICE_L1,
        STATUS_ICON_UNREAD_VOICE_L2,
        STATUS_ICON_UNREAD_FAX_L1L2,
        STATUS_ICON_UNREAD_FAX_L1,
        STATUS_ICON_UNREAD_FAX_L2,
        STATUS_ICON_UNREAD_EMAIL_L1L2,
        STATUS_ICON_UNREAD_EMAIL_L1,
        STATUS_ICON_UNREAD_EMAIL_L2,
#ifdef __MMI_DUAL_SIM_MASTER__
        STATUS_ICON_UNREAD_VOICE_L1_MASTER,
        STATUS_ICON_UNREAD_VOICE_L2_MASTER,
        STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
        STATUS_ICON_UNREAD_FAX_L1_MASTER,
        STATUS_ICON_UNREAD_FAX_L2_MASTER,
        STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
        STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
        STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
        STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
        STATUS_ICON_UNREAD_NET_L1_MASTER,
        STATUS_ICON_UNREAD_NET_L2_MASTER,
        STATUS_ICON_UNREAD_NET_L1L2_MASTER,
        
        STATUS_ICON_UNREAD_VOICE_L1_SLAVE,
        STATUS_ICON_UNREAD_VOICE_L2_SLAVE,
        STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE,
        STATUS_ICON_UNREAD_FAX_L1_SLAVE,
        STATUS_ICON_UNREAD_FAX_L2_SLAVE,
        STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
        STATUS_ICON_UNREAD_EMAIL_L1_SLAVE,
        STATUS_ICON_UNREAD_EMAIL_L2_SLAVE,
        STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
        STATUS_ICON_UNREAD_NET_L1_SLAVE,
        STATUS_ICON_UNREAD_NET_L2_SLAVE,
        STATUS_ICON_UNREAD_NET_L1L2_SLAVE,
#endif  /*__MMI_DUAL_SIM_MASTER__*/
        STATUS_ICON_IMPS_MSG,
        STATUS_ICON_IMPS_LOGIN,
        STATUS_ICON_WAP,
        STATUS_ICON_POC,                        /* 030705 Calvin added */
        STATUS_ICON_BT,
        STATUS_ICON_BT_CON,
        STATUS_ICON_BT_ND,
        STATUS_ICON_IR,
        STATUS_ICON_STOP_WATCH,
        STATUS_ICON_CHAT_INDICATION_ROOM1,
        STATUS_ICON_CHAT_INDICATION_ROOM2,
        STATUS_ICON_NETWORK_CIPHER_GSM,         /* 021505 Calvin added */
    #ifdef __MMI_DUAL_SIM_MASTER__
        STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM,
    #endif
        STATUS_ICON_NETWORK_CIPHER_GPRS,        /* 021505 Calvin added */
        STATUS_ICON_JAVA_BG_VM,                 /* 031005 Calvin added */
        /* 101205 new icon Calvin Start */
    #ifdef __MMI_BG_SOUND_EFFECT__
        STATUS_ICON_BG_SOUND,
    #endif 
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        STATUS_ICON_REVERB_SOUND,
    #endif 
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        STATUS_ICON_AUD_SURROUND,
    #endif
    #ifdef __MMI_HOMEZONE_STATUS_ICON__
        STATUS_ICON_HOMEZONE,
        STATUS_ICON_CITYZONE,
    #endif /* __MMI_HOMEZONE_STATUS_ICON__ */ 
    #ifdef __CTM_SUPPORT__
        STATUS_ICON_TTY_INDICATOR,
    #endif 
    #ifdef __MMI_PICT_BRIDGE_SUPPORT__
        STATUS_ICON_PRINT,
        STATUS_ICON_PRINT_FAIL,
    #endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

        /* 101205 new icon Calvin End */
        STATUS_ICON_SUBLCD_SIGNAL_STRENGTH,
        STATUS_ICON_SUBLCD_BATTERY_STRENGTH,
        STATUS_ICON_SUBLCD_SMS,
        STATUS_ICON_SUBLCD_RING,
        STATUS_ICON_SUBLCD_VIBRATE,
        STATUS_ICON_SUBLCD_VIBRATE_AND_RING,
        STATUS_ICON_SUBLCD_VIBRATE_THEN_RING,
        STATUS_ICON_SUBLCD_SILENT,
        STATUS_ICON_SUBLCD_ALARM,
        STATUS_ICON_SUBLCD_MISSED_CALL,
        MAX_STATUS_ICONS
    };

    typedef struct _MMI_status_icon
    {
        S32 x, y;               /* Offset within a status icon bar                    */
        S32 width, height;      /* For quick lookup                             */
        MMI_ID_TYPE icon_ID;    /* MMI_ID_TYPE of the icon                         */
        U32 flags;              /* Internal flags: See flag names below               */
        U8 state;               /* For icons with multiple states                     */
        U8 group_ID;            /* 0: No group, 1,2,3 ... Groups                   */
        U8 priority;            /* 0: No priority, 1,2,3...Highest to Lowest priorities  */
        PU8 icon_data;          /* For quick lookup                             */
        S16 n_frames;           /* For quick lookup                             */
        S16 current_frame;      /* For animated icons                              */
    } MMI_status_icon;

#define  STATUS_ICON_ANIMATE              0x00000001
#define STATUS_ICON_REVERSE_ANIMATE       0x00000002
#define STATUS_ICON_FORWARD_ANIMATE       0x00000004
#define STATUS_ICON_BLINK              0x00000008
#define STATUS_ICON_DISABLED           0x00000010
#define STATUS_ICON_DISPLAY               0x00000020

    typedef struct _MMI_status_icon_bar
    {
        S32 x, y;                   /* Icons are offset from this position                */
        U32 flags;                  /* all the icons between them.                        */
        S32 x1, y1, x2, y2;         /* Area occupied by the status bar: Used for hiding      */
        U8 group_ID;                /* 0: No group, 1,2,3 ... Groups                   */
        S16 n_icons;                /* Number of icons in the list of icons               */
        S16 *icon_list;             /* Pointer to the list of icons (Icon IDs used here)     */
        bitmap *graphics_context;   /* Pointer to the graphics context (Sub/Main LCD)        */
        U8 *layer_buffer;           /* Layer buffer on which the status icon bar is drawn    */ //061506 double buffer
        GDI_HANDLE layer_handle;    /* Layer handle on which the status icon bar is drawn    */ 
    } MMI_status_icon_bar;

#define STATUS_ICON_BAR_DISPLAY           0x00000001
#define STATUS_ICON_BAR_ARRANGE_VERTICAL  0x00000002
#define STATUS_ICON_BAR_ARRANGE_HORIZONTAL   0x00000004
#define STATUS_ICON_BAR_ARRANGE_ASCENDING 0x00000000
#define STATUS_ICON_BAR_ARRANGE_DESCENDING   0x00000008
#define STATUS_ICON_BAR_ARRANGE_PRIORITY  0x00000010
#define STATUS_ICON_BAR_DISABLE_BACKGROUND   0x00000020
#define STATUS_ICON_BAR_ENABLE_DOUBLE_BUFFER   0x00000040

    /* Distance in pixels between a status icon and its adjacent status icons  */
#define STATUS_ICON_X_GAP              2
#define STATUS_ICON_Y_GAP              2
#define SUBLCD_STATUS_ICON_X_GAP       1
    extern MMI_status_icon MMI_status_icons[];
    extern MMI_status_icon_bar MMI_status_icon_bars[];

    /* Globals  */

    extern void (*MMI_hide_status_icon_bars[]) (void);
    extern U8 status_icon_display_ON;
    extern U8 status_icon_blink_animate_ON;
    extern U8 MMI_status_icons_blink_animate_ON_state;

    void register_hide_status_icon_bar(U8 status_bar_ID, void (*f) (void));
    extern void clear_hide_status_icon_bars(void);
    extern void arrange_status_icons(void);
    extern void show_status_icon(S16 icon_ID);
    extern void hide_status_icon(S16 icon_ID);
    extern void animate_status_icon(S16 icon_ID);
    extern void forward_animate_status_icon(S16 icon_ID);
    extern void reverse_animate_status_icon(S16 icon_ID);
    extern void blink_status_icon(S16 icon_ID);
    extern void disable_status_icon(S16 icon_ID);
    extern void enable_status_icon(S16 icon_ID);
    extern void set_status_icon_state(S16 icon_ID, U8 state);
    extern void reset_status_icon_state(S16 icon_ID);
    extern void set_status_icon_display(S32 state);
    extern void reset_status_icon_display(void);
    extern void show_status_icons(void);
    extern void hide_status_icons(void);
    extern void status_icon_timer_callback(void);
    extern void setup_status_icon_blink_animate(void);
    extern void show_status_icon_bar(U8 status_bar_ID);
    extern void hide_status_icon_bar(U8 status_bar_ID);
    extern void get_status_icon_bar_clip(U8 status_bar_ID, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
    extern void set_status_icon_bar_clip(U8 status_bar_ID, S32 x1, S32 y1, S32 x2, S32 y2);
    extern void set_status_icon_bar_type(U8 status_bar_ID, U32 flags);
    extern U32 get_status_icon_bar_type(U8 status_bar_ID);//061306 dummy category
    extern void set_status_icon_bar_layer(U8 status_bar_ID, GDI_HANDLE gdi_layer);//061506 double buffer
    extern U32 get_status_icon_bar_layer(U8 status_bar_ID);
    extern void reset_status_icons(void);
    extern void initialize_status_icons(void);
    extern void move_status_icons(S32 index, S32 x1, S32 y1, S32 x2, S32 y2);
    extern void close_status_icons(void);
    extern void refresh_status_icon_display(void);
    /* START VIJAY PMT 20060105 */
#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
    extern pBOOL whether_status_bar_at_bottom(void);
    extern void set_status_bar_at_bottom(void);
    extern void reset_status_bar_at_bottom(void);
#endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
    /* END VIJAY PMT 20060105 */

#if defined(__MMI_UI_TECHNO_STATUS_ICON__)
    extern void refresh_fixed_status_icon(S16 icon_id, S16 bar_id);
    extern S32 NumberOfDisplayedIcons(void);
    extern void ChangeStatusIconImageWithoutReArrange(S16 icon_ID, U16 image_ID);
#endif /* defined(__MMI_UI_TECHNO_STATUS_ICON__) */ 

    /* Application specific APIs  */

    /* void PopulateStatusIconResources(void); */
    extern void ShowStatusIcon(S16 icon_ID);
    extern void HideStatusIcon(S16 icon_ID);
    extern void UpdateStatusIcons(void);
    extern void UpdateSubLCDStatusIcons(void);
    extern void ChangeStatusIconLevel(S16 icon_ID, U8 level_percentage);
    extern void ChangeStatusIconImage(S16 icon_ID, U16 image_ID);       /* 022505 Calvin added */
    extern void AnimateStatusIcon(S16 icon_ID);
    extern void BlinkStatusIcon(S16 icon_ID);

    /* 030705 Calvin removed */
    //void LockStatusIconDisplay(void);
    //void UnlockStatusIconDisplay(void);
    /* Calvin end */

    extern void arrange_status_icons1(void);

    /* MTK JL add 040311 new sublcd color interface screen */
    extern void show_sublcd_status_background(S32 start_x, S32 start_y, S32 end_x, S32 end_y, U8 is_status_bar);
    extern void show_mainlcd_status_bar_background(U16 start_x, U16 start_y, U16 end_x, U16 end_y);
    extern void set_status_icons_display(MMI_BOOL state);

    extern void wgui_status_icon_set_display_layer(GDI_HANDLE display_layer);

    extern GDI_HANDLE wgui_status_icon_get_display_layer(void);

    extern void wgui_status_icon_integrated_get_area(S16 icon_ID, S32 *width, S32 *height);

    extern void wgui_status_icon_integrated_enable(MMI_BOOL enable);

    extern void wgui_status_icon_integrated_show(S16 icon_ID, S32 x, S32 y);

    extern void wgui_status_icon_integrated_register_redraw(void (*f) (void));

    extern void wgui_status_icon_reset_display_layer(void);

    extern void fill_status_bar_color(U8 bar_id);

    extern void wgui_status_icon_lock_redrawing(void);
    extern void wgui_status_icon_unlock_redrawing(void);
    extern void wgui_status_icon_set_block(MMI_BOOL blocking);

#ifdef __MMI_TOUCH_SCREEN__
    typedef enum
    {
        WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON,
        WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
        WGUI_STATUS_ICON_BAR_PEN_EVENT_MAX,
        WGUI_STATUS_ICON_BAR_PEN_NONE
    } wgui_status_icon_bar_pen_enum;
    extern void wgui_register_status_icon_pen_event_hdlr(
                    S16 icon_id,
                    wgui_status_icon_bar_pen_enum event_type,
                    FuncPtr f);
    extern MMI_BOOL wgui_execute_status_icon_pen_event_hdlr(S16 icon_id, wgui_status_icon_bar_pen_enum event_type);
    extern void wgui_reset_status_icon_pen_event_hdlr(void);
    extern BOOL wgui_status_icon_translate_pen_event(
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    S16 *icon_id,
                    wgui_status_icon_bar_pen_enum *event_type);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __cplusplus
}
#endif 

#endif /* __WGUI_STATUS_ICONS_H__ */ 

