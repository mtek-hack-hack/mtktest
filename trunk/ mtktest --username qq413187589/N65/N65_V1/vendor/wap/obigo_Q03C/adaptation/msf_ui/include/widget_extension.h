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
 *
 * Filename:
 * ---------
 * widget_extension.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Prototypes & MACRO of widget library extension 
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _WIDGET_EXTENSION_H
#define _WIDGET_EXTENSION_H

#ifndef _msf_int_h
#error "msf_int.h should be included"
#endif 

#include "ctk.h"

#include "wapadp.h"     /* Failsafe. To be removed in the future */


/* for switch widget screen */
#define WAP_GOBACK_WIDGET_SCREEN    (0x1000)
#define WAP_LEAVE_WIDGET_SCREEN     (0x1001)


/* Basic types */
typedef ctk_string_id widget_string_id;
typedef ctk_image_id widget_image_id;
typedef int (*MsfFormAudioCallBack)(void);

typedef enum
{
    WIDGET_STRING_PACK_ID,
    WIDGET_STRING_PACK_UCS2,
    WIDGET_STRING_PACK_UTF8
} widget_string_pack_enum;

typedef struct
{
    widget_string_pack_enum type;
    union
    {
        ctk_string_id id;
        kal_uint8 *ucs2;
        kal_uint8 *utf8;
    } _u;
} widget_string_pack_struct;


/* Widget API extension */

extern void HDIa_widgetExtRegisterSwitchWidgetScreenCallback(FuncPtrShort cb_func);

extern int HDIa_widgetWindowGetProperties(MsfWindowHandle window);

extern kal_bool HDIa_widgetExtDeleteWidgetScreenIfPresent(void);

extern kal_bool HDIa_widgetExtIsCurrentFocusedPaintbox(void);

extern kal_bool HDIa_widgetExtIsWaitingMessageNotificationInIdleScreen(void);

extern int HDIa_widgetExtPaintboxInputFocus(MsfGadgetHandle handle);
extern int HDIa_widgetGetSystemFontSize(void);  /* Deprecated */
extern int HDIa_widgetExtGetInputboxWidthBySize(int char_cnt, kal_bool is_passwd);

extern int HDIa_widgetExtBarSetMinPenOffsetValue(MsfGadgetHandle bar, int min_value);

extern void HDIa_widgetExtFromSetMMSViewer(MsfWindowHandle wnd);
extern void HDIa_widgetExtFromClearMMSViewer(MsfWindowHandle wnd);
extern void HDIa_widgetExtFormDisableGadgetBorder(MsfWindowHandle wnd, kal_bool do_disable);
extern void HDIa_widgetExtFormDisableScrolling(MsfWindowHandle wnd, kal_bool do_disable);       /* Unimplemented */
extern void HDIa_widgetExtFormSetSmilRemainTime(MsfWindowHandle wnd, int sec);
extern void HDIa_widgetExtFormSetSmilTotalTime(MsfWindowHandle wnd, int sec);
extern void HDIa_widgetExtFromSetAudioCallBack(MsfWindowHandle wnd, MsfFormAudioCallBack cb);
extern void HDIa_widgetExtFormSetArrowIndication(MsfWindowHandle wnd, int left, int right, int up, int down);
extern void HDIa_widgetExtFormGetSmilDisplaySize(MsfSize *size);

#ifdef WIDGET_SLIDING_SMIL_SUPPORT
extern void HDIa_widgetExtFormSetSlidingSMIL(
                MsfWindowHandle wnd,
                kal_bool image_on_top,
                kal_int16 max_text_gadget_height);
extern void HDIa_widgetExtFormClearSlidingSMIL(MsfWindowHandle wnd);

#ifdef WIDGET_SLIDING_SMIL_VBAR
extern void HDIa_widgetExtFormSetSlidingSMILTextHeight(
                MsfWindowHandle wnd,
                int total_text_height,
                int text_line_height);
extern void HDIa_widgetExtFormUpdateSlidingSMILTextOffset(MsfWindowHandle wnd, int text_scroll_offset);

#ifdef __MMI_TOUCH_SCREEN__
extern void HDIa_widgetExtFormRegisterSlidingSMILScrollNotification(MsfWindowHandle wnd,
                                                                    void (*text_scroll_notification_hdlr) (void));
extern void HDIa_widgetExtFormGetSlidingSMILTextOffsetByPen(MsfWindowHandle wnd, int *text_scroll_offset);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif /* WIDGET_SLIDING_SMIL_VBAR */ 
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

#ifdef __MMI_TOUCH_SCREEN__
extern void HDIa_widgetExtFormRegisterMOBScrollNotification(
                MsfWindowHandle wnd,
		        MsfGadgetHandle v_bar,
                void (*text_scroll_notification_hdlr) (void));
extern void HDIa_widgetExtFormGetMOBTextOffsetByPen(MsfWindowHandle wnd, int *text_scroll_offset);

extern void HDIa_widgetExtFormSetMOBStyle(MsfWindowHandle wnd);
extern void HDIa_widgetExtFormGetMOBPosition(MsfWindowHandle wnd, MsfPosition *pos);
extern void HDIa_widgetExtFormGetMOBSize(MsfWindowHandle wnd, MsfSize *size);
#endif /* __MMI_TOUCH_SCREEN__ */ 

extern void HDIa_widgetExtDialogDisableTone(MsfWindowHandle wnd);

extern void HDIa_widgetExtActionSetText(MsfActionHandle action, MsfStringHandle label);


#ifdef WIDGET_PRECACHE_IMAGE
extern void HDIa_widgetExtEnablePreCacheImage(MsfImageHandle img);
#endif 

extern kal_bool HDIa_widgetExtCacheNonBlockingImage(MsfImageHandle image, MsfGadgetHandle gadget, FuncPtrShort precache_cb);
extern kal_bool HDIa_widgetExtSmilEditorCacheNonBlockingImage(MsfWindowHandle wnd, MsfImageHandle image, FuncPtrShort precache_cb);

extern void HDIa_widgetExtDisableImageAnimation(MsfImageHandle img);
extern void HDIa_widgetExtEnableImageAnimation(MsfImageHandle img);

extern MsfImageHandle HDIa_widgetExtGetImageFromGadget(MsfGadgetHandle gimg);

extern void HDIa_widgetExtSimulateSEND(void);

extern void HDIa_widgetExtGiveControlToMMI(void);
extern void HDIa_widgetExtPaintDirectly(void);

extern void HDIa_widgetExtDisplayTransitionAnimation(kal_bool is_MMS);
extern void HDIa_widgetExtDisplayTransitionAnimationNoEnd(kal_bool is_MMS);
extern void HDIa_widgetExtCloseTransitionAnimation(void);

typedef int (*MsfMenuExtHighlightHandle)(MsfWindowHandle menu, int index);
extern void HDIa_widgetExtMenuRegisterHighlightHandle(
                MsfWindowHandle menu,
                MsfMenuExtHighlightHandle cb_func);

extern void HDIa_widgetExtMenuProfileStyle(MsfWindowHandle menu);

extern U8 HDIa_widgetExtMsfToMMIImageFormat(MsfImageFormat format);
extern const char *HDIa_widgetExtFileNameToMimeType(const char *fname);
extern const char *HDIa_widgetExtMimeTypeToFileExt(const char *mime_type);
extern const char *HDIa_widgetExtImageGadgetGetSourceFile(MsfGadgetHandle handle);
extern const char* HDIa_widgetExtGetImageContentFile(MsfImageHandle image);

extern void HDIa_widgetExtImageUtilFixBox(
                kal_int32 bbox_width,
                kal_int32 bbox_height,
                kal_int32 src_width,
                kal_int32 src_height,
                kal_int32 *offset_x,
                kal_int32 *offset_y,
                kal_int32 *dest_width,
                kal_int32 *dest_height);

/*
 * System-related
 */
extern void widget_send_update_event_to_wap(void);

extern U8 widget_is_shutdown_UI(void);

/* 
 * Enter MMI screen 
 */
extern void HDIa_widgetExtEnterDeleteAllScreenNoInterrupt(void);
extern void HDIa_widgetExtLeaveDeleteAllScreen(void);

extern int HDIa_widgetExtShowPopup(MSF_UINT8 modId, MsfStringHandle dialogText, MsfDialogType type, int timeout);
extern int HDIa_widgetExtShowPopupExt(
            MSF_UINT8 modId,
            MsfStringHandle dialogText,
            ctk_image_id imageid,
            ctk_tone_id toneid,
            kal_bool imageOnBottom,
            int timeout);
extern void HDIa_widgetExtForcePopup(MsfStringHandle dialogText, MsfDialogType type, int timeout);

extern void HDIa_widgetExtShowConfirm(MsfWindowHandle dialog, MsfStringHandle dialogText);
extern void HDIa_widgetExtCloseConfirm(void);

extern int HDIa_widgetExtSavePhoneNumber(kal_uint8 *number);
extern int HDIa_widgetExtSaveEmail(kal_uint8 *email);

extern void HDIa_widgetExtEntryVirtualWidgetScreen(U16 scrnID);

/* 
 * Sound 
 */
extern int HDIa_widgetExtSoundPlayOnWindow(MsfSoundHandle sound, MsfWindowHandle wnd);

extern int HDIa_widgetExtIsSoundPlaying(void);

extern int HDIa_widgetExtSoundGetDuration(void* file_name, kal_uint32 *duration);

/*
 * Rendering
 */
extern int HDIa_widgetExtStringGetSubSizeIgnoreSpace(
            MsfStringHandle string,
            MSF_UINT32 handle,
            int index,
            int nbrOfChars,
            int subwidth,
            MsfSize *size);
extern int HDIa_widgetExtStringGetVisibleIgnoreSpace(
            MsfStringHandle string,
            MSF_UINT32 handle,
            MsfSize *size,
            int startIndex,
            int includeInitialWhiteSpaces,
            int *nbrOfCharacters,
            int *nbrOfEndingWhiteSpaces,
            int *nbrOfInitialWhiteSpaces);

extern void HDIa_widgetExtStringSetCacheGetVisible(MsfStringHandle string);
extern void HDIa_widgetExtStringClearCacheGetVisible(MsfStringHandle string);

/*
 * Image Resizing
 */
#define MSF_WIDGET_EXT_RESIZING_SUCCEED                                         (1)
#define MSF_WIDGET_EXT_RESIZING_SUCCEED_WITH_UNCHANGED                          (0)
#define MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_FAILED                            (-1)
#define MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL             (-5)
#define MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION      (-6)
#define MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK               (-7)
#define MSF_WIDGET_EXT_RESIZING_FAILED_IN_NO_QUOTA                              (-10)
#define MSF_WIDGET_EXT_RESIZING_FAILED_IN_UNKNOWN_DIMENSION                     (-11)
#define MSF_WIDGET_EXT_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF              (-12)

extern int HDIa_widgetExtImageResizing(MSF_UINT8 modId, char *file, char *dest_file, int resize_w, int resize_h);

typedef enum
{
    WAP_SERVICE_ON_UNKNOWN_SIM,
    WAP_SERVICE_ON_MASTER_SIM,
    WAP_SERVICE_ON_SLAVE_SIM,
    WAP_SERVICE_ON_SIM_MAX
}widget_service_on_sim_enum;

extern kal_bool HDIa_widgetExtEnableSIMService(widget_service_on_sim_enum sim_id);



/*
 * Message Notification Mechanism
 */

extern void HDIa_widgetExtRegisterUrgentServiceLoading(kal_bool show_popup);
extern void HDIa_widgetExtClearUrgentServiceLoading(void);

extern void HDIa_widgetExtRegisterUrgentServiceIndication(kal_bool show_popup);
extern void HDIa_widgetExtClearUrgentServiceIndication(void);

extern void HDIa_widgetExtRegisterNewPush(void);
extern void HDIa_widgetExtClearPush(void);

extern void HDIa_widgetExtRegisterNewProvision(widget_service_on_sim_enum sim_id);
extern void HDIa_widgetExtClearProvision(void);

extern void HDIa_widgetExtRegisterDRMRightNotification(MsfStringHandle dialogText, MsfDialogType type);
extern void HDIa_widgetExtClearDRMRightNotification(void);

typedef enum
{
    WIDGET_MMS_NEW_MSG,
    WIDGET_MMS_NOTIFICATION,
    WIDGET_MMS_READ_REPORT,
    WIDGET_MMS_DELIVERY_REPORT
} widget_mms_msg_type_enum;

extern void HDIa_widgetExtRegisterNewMMS(kal_uint32 msgid, widget_mms_msg_type_enum type, kal_uint32 size);
extern void HDIa_widgetExtClearMMS(void);
extern kal_uint32 HDIa_widgetExtGetMMSMessageID(void);

extern void HDIa_widgetExtRegisterSystemMsg(MSF_UINT8 modId, widget_string_id titleid, widget_string_id msgid);
extern void HDIa_widgetExtClearSystemMsg(void);

/* 
 * Adaptation to CTK 
 */
extern ctk_app_handle HDIa_widgetCtkGetApp(void);
extern MsfWindowHandle HDIa_widgetCtkCreate(MSF_UINT8 modId, ctk_screen_handle scrid);
extern ctk_screen_handle widget_ctk_screen_create(void);
extern void HDIa_widgetCtkSetOnPostPaint(MsfWindowHandle wnd, void (*callback) (void));

extern MsfWindowHandle HDIa_widgetCtkGetWindow(ctk_screen_handle scrid);
extern ctk_screen_handle HDIa_widgetCtkGetScreenHandle(MsfWindowHandle wnd);

#define WIDGET_CTK_FLAG_DISABLE_SLIM_MENU_STYLE (0x0001)
#define WIDGET_CTK_FLAG_BACKLIGHT_ALWAYS_ON     (0x0002)
#define WIDGET_CTK_SMIL_EDITOR_USING_SCRN_MEM   (0x0004)
typedef kal_uint16 widget_ctk_flag_t;
extern void HDIa_widgetCtkSetFlag(MsfWindowHandle ctk, widget_ctk_flag_t flags);
extern void HDIa_widgetCtkUnsetFlag(MsfWindowHandle ctk, widget_ctk_flag_t flags);

/* 
 * File manager integration
 */

typedef void (*widget_fmgr_input_callback) (const char *pathname, void *arg);

extern kal_bool HDIa_widgetExtFmgrMediaInput(const char *mime_types, widget_fmgr_input_callback callback, void *arg);
extern void HDIa_widgetExtFmgrMediaInputAbort(void);

typedef void (*widget_fmgr_filename_callback) (const char *pathname, void *arg);
extern kal_bool HDIa_widgetExtFmgrGetSaveFileName(
                    const char *suggested_name,
                    const char *mime_type,
                    widget_fmgr_filename_callback callback,
                    void *arg);
extern void HDIa_widgetExtFmgrSaveFileNameAbort(void);

/* 
 * Predefined window types (typically implemented with CTK)
 */

/* Text View */
extern MsfWindowHandle HDIa_widgetExtCreateTextView(
                        MSF_UINT8 modId,
                        const kal_uint8 *text,
                        ctk_string_id str_title,
                        ctk_image_id img_title);

extern MsfWindowHandle HDIa_widgetExtCreateTextViewSeparator(
                        MSF_UINT8 modId,
                        const kal_uint8 *text,
                        ctk_string_id str_title,
                        ctk_image_id img_title);

extern MsfWindowHandle HDIa_widgetExtCreateTextViewNoScrollBar(
                    MSF_UINT8 modId,
                    const kal_uint8 *text,
                    ctk_string_id str_title,
                    ctk_image_id img_title);

extern MsfWindowHandle HDIa_widgetExtCreateTextViewEx(
                    MSF_UINT8 modId,
                    const kal_uint8 *text,
                    ctk_string_id str_title,
                    ctk_image_id img_title,
                    kal_uint32 flags);

/* Wait View */
extern MsfWindowHandle HDIa_widgetExtCreateWaitView(MSF_UINT8 modId, ctk_string_id prompt_string);

/* Progress View */
extern void HDIa_widgetExtSetProgressPercentage(
                MsfWindowHandle wnd,
                MSF_UINT16 percent,
                const kal_uint8 *text1,
                const kal_uint8 *text2);
extern MsfWindowHandle HDIa_widgetExtCreateProgressView(
                        MSF_UINT8 modId,
                        ctk_string_id str_title,
                        ctk_image_id img_title,
                        kal_bool is_bar);

/* Message Indication */
extern MsfWindowHandle HDIa_widgetExtCreateMessageInd(
                        MSF_UINT8 modId,
                        widget_string_pack_struct msg1,
                        widget_string_pack_struct msg2,
                        ctk_image_id img);

/* List Menu (Common) */
extern int HDIa_widgetExtListMenuGetCount(MsfWindowHandle wnd);
extern int HDIa_widgetExtListMenuGetHilighted(MsfWindowHandle wnd);

/* List Menu (Fixed) */
extern MsfWindowHandle HDIa_widgetExtCreateListMenu(
                        MSF_UINT8 modId,
                        ctk_string_id str_title,
                        ctk_image_id img_title,
                        int num_items,
                        ctk_string_id *str_item_list,
                        ctk_image_id *img_item_list,
                        kal_uint8 *hint_list[],
                        kal_bool value_in_UTF8);
extern void HDIa_widgetExtUpdateListMenu(
                MsfWindowHandle wnd,
                ctk_string_id str_title,
                ctk_image_id img_title,
                int num_items,
                ctk_string_id *str_item_list,
                ctk_image_id *img_item_list,
                kal_uint8 *hint_list[],
                kal_bool value_in_UTF8);

extern MsfWindowHandle HDIa_widgetExtCreateListMenuByValue(
                        MSF_UINT8 modId,
                        ctk_string_id str_title,
                        ctk_image_id img_title,
                        int num_items,
                        kal_uint8 **str_value_list,
                        ctk_image_id *img_item_list,
                        kal_uint8 *hint_list[],
                        kal_bool value_in_UTF8);
extern void HDIa_widgetExtUpdateListMenuByValue(
                MsfWindowHandle wnd,
                ctk_string_id str_title,
                ctk_image_id img_title,
                int num_items,
                kal_uint8 **str_value_list,
                ctk_image_id *img_item_list,
                kal_uint8 *hint_list[],
                kal_bool value_in_UTF8);

extern MsfWindowHandle HDIa_widgetExtCreateListMenuTwoIcons(
                        MSF_UINT8 modId,
                        ctk_string_id str_title,
                        ctk_image_id img_title,
                        int num_items,
                        kal_uint8 **str_value_list,
                        ctk_image_id *img_item_list,
                        ctk_image_id *img_item_list2,
                        kal_bool value_in_UTF8);
extern void HDIa_widgetExtUpdateListMenuTwoIcons(
                MsfWindowHandle wnd,
                ctk_string_id str_title,
                ctk_image_id img_title,
                int num_items,
                kal_uint8 **str_value_list,
                ctk_image_id *img_item_list,
                ctk_image_id *img_item_list2,
                kal_bool value_in_UTF8);

extern void HDIa_widgetExtListMenuSetItem(MsfWindowHandle wnd, int index, ctk_string_id strid, ctk_image_id imageid);
extern void HDIa_widgetExtListMenuSetItemByValue(
                MsfWindowHandle wnd,
                int index,
                kal_uint8 *string,
                ctk_image_id imageid,
                kal_bool value_in_UTF8);
extern void HDIa_widgetExtListMenuUpdateHint(MsfWindowHandle wnd, kal_uint8 *hint, int index, kal_bool hint_in_UTF8);

/* List Menu (Dynamic) */
typedef void (*widget_list_menu_callback) (int index, void *arg, kal_uint8 *string, int string_size,
                                           ctk_image_id *img);
typedef void (*widget_list_menu_hint_callback) (int index, void *arg, kal_uint8 *hint, int hint_size);
extern MsfWindowHandle HDIa_widgetExtCreateListMenuByCallback(
                        MSF_UINT8 modId,
                        ctk_string_id str_title,
                        ctk_image_id img_title,
                        int num_items,
                        kal_uint16 highlighted,
                        widget_list_menu_callback callback,
                        widget_list_menu_hint_callback callback_hint,
                        void *arg_for_callback);
extern void HDIa_widgetExtUpdateListMenuByCallback(
                MsfWindowHandle wnd,
                ctk_string_id str_title,
                ctk_image_id img_title,
                int num_items,
                kal_uint16 highlighted,
                widget_list_menu_callback callback,
                widget_list_menu_hint_callback callback_hint,
                void *arg_for_callback);

/* Choice Menu (Dynamic) */
typedef kal_uint8 *(*widget_radio_menu_callback) (void *arg, int index);
extern MsfWindowHandle HDIa_widgetExtCreateRadioMenuByCallback(
                        MSF_UINT8 modId,
                        ctk_string_id str_title,
                        ctk_image_id img_title,
                        int num_items,
                        kal_uint16 highlighted,
                        widget_radio_menu_callback callback,
                        void *arg_for_callback);

/* Advanced SMIL editor */
#ifdef WIDGET_ADVANCED_SMIL_EDITOR

#define WIDGET_SMIL_EDITOR_FLAG_AUDIO                 (0x0001)
#define WIDGET_SMIL_EDITOR_FLAG_ATTACHMENT            (0x0002)
#define WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM       (0x0004)

extern MsfWindowHandle HDIa_widgetExtCreateSmilEditor(
                        MSF_UINT8 modId,
                        widget_string_pack_struct str_title1,
                        widget_string_pack_struct str_title2,
                        ctk_image_id img_title,
                        MsfStringHandle inputString,
                        kal_uint16 maxSize,
                        MsfImageHandle image,
                        kal_uint16 flags);

extern MsfStringHandle HDIa_widgetExtSmilEditorGetText(MsfWindowHandle wnd);

extern int HDIa_widgetExtSmilEditorGetTextLength(MsfWindowHandle wnd, int lengthInBytes);

extern void HDIa_widgetExtSmilEditorUpdateTitle(
                MsfWindowHandle wnd,
                widget_string_pack_struct str_title1,
                widget_string_pack_struct str_title2,
                ctk_image_id img_title);

extern void HDIa_widgetExtSmilEditorUpdateTitle2(MsfWindowHandle wnd, widget_string_pack_struct str_title2);

extern void HDIa_widgetExtSmilEditorUpdateImage(MsfWindowHandle wnd, MsfImageHandle image);

extern void HDIa_widgetExtSmilEditorUpdateImageEx(MsfWindowHandle wnd, MsfImageHandle image, kal_bool is_video);

extern void HDIa_widgetExtSmilEditorUpdateText(MsfWindowHandle wnd, MsfStringHandle inputString);

extern void HDIa_widgetExtSmilEditorChangeSlide(kal_bool is_true);

extern void HDIa_widgetExtSmilEditorSetFlag(MsfWindowHandle wnd, kal_uint16 flags);

extern void HDIa_widgetExtSmilEditorUnsetFlag(MsfWindowHandle wnd, kal_uint16 flags);

extern void HDIa_widgetExtSmilEditorRefresh(MsfWindowHandle wnd);

extern void HDIa_widgetExtSmilEditorSetUnmodified(MsfWindowHandle wnd);

extern kal_bool HDIa_widgetExtSmilEditorCheckModified(MsfWindowHandle wnd);

extern void HDIa_widgetExtSmilEditorEnterInputMethod(MsfWindowHandle wnd, void (*done_callback) (void));

extern void HDIa_widgetExtSmilEditorInsetText(MsfWindowHandle wnd, const kal_uint8 * in_str);

#endif /* WIDGET_ADVANCED_SMIL_EDITOR */ 

/* Extension to MsfChioceElement */
#define WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW   (0x01)
extern int HDIa_widgetExtChoiceSetElemFlag(MSF_UINT32 choice, int index, MSF_UINT8 flag);
extern int HDIa_widgetExtChoiceUnsetElemFlag(MSF_UINT32 choice, int index, MSF_UINT8 flag);
extern int HDIa_widgetExtChoiceGetFocusedElemFlags(MSF_UINT32 choice, MSF_UINT8 *flags);

/* Extension of window property */
#define MSF_WINDOW_PROPERTY_EXT_DISABLE_RIGHT_ARROW         (0x00100000)    /* For MsfMenu */
#define MSF_WINDOW_PROPERTY_EXT_VOLUME_KEY                  (0x00200000)    /* For MsfForm */
#define MSF_WINDOW_PROPERTY_EXT_STATUS_ICON                 (0x00400000)    /* For MsfDialog */
#define MSF_WINDOW_PROPERTY_EXT_DISBALE_SLIM_MENU_STYLE     (0x00800000)    /* For MsfMenu */
#define MSF_WINDOW_PROPERTY_EXT_IS_MESSAGE_APPLICATION      (0x01000000)    /* For MsfMenu */

/* Extension of MsfActionType */
#define MsfWidgetUsing      (1<<16)

/* Extension of MsfDialogType */
typedef enum
{
    MsfPromptEmpty = 30,
    MsfPromptSaveDone   /* Saved or Done */
} MsfDialogTypeExt;

/* Extension of MsfTextType */
typedef enum
{
    MsfSaveAsFilename = 50, /* posix characters + chinese.  '.' is also disallowed */
    MsfMMIDefaultInputMethod,
    MsfUpperCase,
    MsfPhoneNumberOrEmail   /* Deprecated */
} MsfTextTypeExt;

#define MsfUnsupportedMediaType  0xC0

/* Extension of MsfStringFormat */
typedef enum
{
    MsfUcs2 = MsfUtf8 + 10
        /* MsfAscii */
} MsfStringFormatExt;

/* Extension of MsfResourceType */
typedef enum
{
    MsfResourcePartialFile = 0x80
#ifdef __DRM_SUPPORT__
        , MsfResourceDRMFile = 0x81
#endif 
} MsfResourceTypeExt;

/* Extension of MsfNotificationType */
typedef enum
{
    MsfNotifyResourceError = MsfNotifyResourceFailed,
    MsfNotifyResourceReady = MsfNotifyResourceLoaded,

    MsfNotifyFailedResolution = 0x80,
    MsfNotifyFailedFSFull,
    MsfNotifyFailedNoResource,
    MsfNotifyFailedCorrupt
} MsfNotificationTypeExt;

typedef struct
{
    char *filename;
    int start_offset;
    int data_size;
} MsfPartialFileData;

extern kal_bool HDIa_widgetExtImageFileGetSize(char *file, MsfSize *size);
extern kal_bool HDIa_widgetExtCheckImageFile(char *file);

/* Remote loopup name from PHB */
extern void HDIa_widgetExtRemoteLookupPhbName(char *number, char *name, int sizeInByte);

/* Additional encoding conversion */
extern kal_bool HDIa_widgetExtBig5ToUTF8(
                    const kal_uint8 *src,
                    kal_int32 *srcLen,
                    kal_uint8 *dst,
                    kal_int32 *dstLen);
extern kal_bool HDIa_widgetExtUTF8ToBig5(
                    const kal_uint8 *src,
                    kal_int32 *srcLen,
                    kal_uint8 *dst,
                    kal_int32 *dstLen);

extern kal_bool HDIa_widgetExtGB2312ToUTF8(
                    const kal_uint8 *src,
                    kal_int32 *srcLen,
                    kal_uint8 *dst,
                    kal_int32 *dstLen);
extern kal_bool HDIa_widgetExtUTF8ToGB2312(
                    const kal_uint8 *src,
                    kal_int32 *srcLen,
                    kal_uint8 *dst,
                    kal_int32 *dstLen);

extern kal_bool HDIa_widgetExtGB18030ToUTF8(
                    const kal_uint8 *src,
                    kal_int32 *srcLen,
                    kal_uint8 *dst,
                    kal_int32 *dstLen);
extern kal_bool HDIa_widgetExtUTF8ToGB18030(
                    const kal_uint8 *src,
                    kal_int32 *srcLen,
                    kal_uint8 *dst,
                    kal_int32 *dstLen);


/* UTF8/UCS2 Encoding & String handling */
extern int widget_utf8_length(const kal_uint8 *s);
extern int widget_ucs2_length(const kal_uint8 *s);
extern int widget_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern int widget_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);

extern int widget_utf8_to_ucs2_string(kal_uint8 *dest, int dest_size, const kal_uint8 *src);
extern int widget_ucs2_to_utf8_string(kal_uint8 *dest, int dest_size, const kal_uint8 *src);

/* Resource system */
extern const kal_uint8 *HDIa_widgetExtImageGetPredefinedBuffer(MSF_UINT32 resid, int *length, MsfImageFormat *type);

/* Creating an UCS2 string */
extern const kal_uint8 *HDIa_widgetExtStringGetUCS2buffer(MsfStringHandle str);
extern const kal_uint8 *HDIa_widgetExtStringGetPredefinedUCS2buffer(MSF_UINT32 resid);

extern kal_uint8 *widget_ucs2_strcpy(kal_uint8 *dst, const kal_uint8 *src);
extern kal_uint8 *widget_ucs2_strncpy(kal_uint8 *dst, const kal_uint8 *src, int size);

extern kal_uint8 *widget_ucs2_strdup(MSF_UINT8 modId, const kal_uint8 *str);
extern kal_uint8 *widget_ucs2_strdup_from_utf8(MSF_UINT8 modId, const kal_uint8 *str);
extern kal_uint8 *widget_ucs2str_append_utf8(
                    MSF_UINT8 modId,
                    kal_uint8 *src,
                    int *allocated_size,
                    const kal_uint8 *add_utf8_str);
extern kal_uint8 *widget_ucs2str_append_ucs2(
                    MSF_UINT8 modId,
                    kal_uint8 *src,
                    int *allocated_size,
                    const kal_uint8 *add_ucs2_str);
extern kal_uint8 *widget_ucs2str_append_handle(
                    MSF_UINT8 modId,
                    kal_uint8 *src,
                    int *allocated_size,
                    MsfStringHandle stringHandle);
extern kal_uint8 *widget_ucs2str_append_id(MSF_UINT8 modId, kal_uint8 *src, int *allocated_size, int strid);

/* WAP status bar */
extern void widget_enable_status_bar(int indicator);
extern void widget_disable_status_bar(int indicator);
extern ctk_image_id widget_get_title_icon(ctk_image_id imageid);

/* Typically used by WAP, not by MMS (except for sound indication) */
#define WIDGET_STATUS_BAR_BUSY              (1<<0)        /* Data trasmitting/receiving (Set by application) */
#define WIDGET_STATUS_BAR_CSD               (1<<1)        /* The following four types are set by widget itself */
#define WIDGET_STATUS_BAR_GPRS              (1<<2)
#define WIDGET_STATUS_BAR_WIFI              (1<<3)
#define WIDGET_STATUS_BAR_DISCONNECT        (1<<4)
#define WIDGET_STATUS_BAR_SECURITY          (1<<5)
#define WIDGET_STATUS_BAR_SOUND_IND         (1<<6)        /* Used by MMS to indicate the sound is playing */
/* WIDGET_MMS_STATUS_BAR are used with BUSY CSD GPRS DISCONNECT */



/* Handling UCS2 string not aligned with 2 bytes. (Obigo adopts UTF8 by default) */
#ifndef CAST_PU8
#define CAST_PU8(RAW)   ((kal_uint8*)(RAW))
#endif
#ifndef CAST_CPU8
#define CAST_CPU8(RAW)  ((const kal_uint8*)(RAW))
#endif
#ifndef GET_U8_BYTE_TO_U16
#define GET_U8_BYTE_TO_U16(RAW, i)  ((kal_uint16)(CAST_CPU8(RAW)[i]))
#endif

#ifndef STR_SIZE
#define STR_SIZE(len) ((len)<<1)
#endif
#ifndef STR_AT
#define STR_AT(RAW, n) ((void*)(CAST_PU8(RAW)+STR_SIZE(n)))
#endif
#ifndef CHR_AT
#define CHR_AT(RAW, n) ((kal_uint16)(GET_U8_BYTE_TO_U16(RAW, STR_SIZE(n))+(GET_U8_BYTE_TO_U16(RAW, STR_SIZE(n)+1)<<8)))
#endif
#ifndef SET_CHR_AT
#define SET_CHR_AT(RAW, n, value)   do {                          \
                              kal_uint8 *_p = STR_AT(RAW, n);     \
                              kal_uint16 v= (kal_uint16) (value); \
                              _p[0] = (kal_uint8) (v & 0xff);     \
                              _p[1] = (kal_uint8) (v >> 8);       \
                           } while (0)
#endif
#ifndef CHR
#define CHR(x)      ((kal_uint16)(x))
#endif

#define STR_LEN(RAW)  widget_ucs2_length(CAST_CPU8(RAW))

/* Video MMS */
#define MsfVideoHandle      MSF_UINT32
typedef enum
{
    MsfVideoFormatStart = 0x40,
    Msf3gp,
    MsfMp4,
    MsfAvi
} MsfVideoFormat;

#define MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE        HDIa_widgetExtVideoCreateResource
#define MSF_WIDGET_EXT_GET_VIDEO_DURATION_TIME        HDIa_widgetExtGetVideoDurationTime
#define MSF_WIDGET_EXT_PLAY_VIDEO        HDIa_widgetExtPlayVideo
#define MSF_WIDGET_EXT_STOP_VIDEO        HDIa_widgetExtStopVideo
#define MSF_WIDGET_EXT_DISABLE_VIDEO_PLAY        HDIa_widgetExtDisableVideoPlay
#define MSF_WIDGET_EXT_ENABLE_VIDEO_PLAY        HDIa_widgetExtEnableVideoPlay

extern MsfImageHandle HDIa_widgetExtVideoCreateResource(
                        MSF_UINT8 modId,
                        char *resource,
                        MsfResourceType resourceType,
                        MsfVideoFormat videoFormat);
extern void HDIa_widgetExtDisableVideoPlay(MsfImageHandle image);
extern kal_int32 HDIa_widgetExtGetVideoDurationTime(MsfImageHandle image);
extern void HDIa_widgetExtPlayVideo(MsfImageHandle image);
extern void HDIa_widgetExtStopVideo(MsfImageHandle image);
extern void HDIa_widgetExtDisableVideoPlay(MsfImageHandle image);
extern void HDIa_widgetExtEnableVideoPlay(MsfImageHandle image);
extern void HDIa_widgetExtCloseVideo(void);

#endif /* _WIDGET_EXTENSION_H */ 

