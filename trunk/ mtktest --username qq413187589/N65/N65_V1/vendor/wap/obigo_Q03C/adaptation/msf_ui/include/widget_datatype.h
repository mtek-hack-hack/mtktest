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
 * widget_datatype.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Widget data type definition
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

typedef enum
{
    // window category
    // WIDGET_SCREEN_TYPE,//0
    WIDGET_PRE_STRING_TYPE,             /* 0. For WIDGET_RO_PRE_STRING */
    WIDGET_ROOT_TYPE,                   /* 1 */
    WIDGET_SCREEN_TYPE,                 /* 2 */
    WIDGET_PAINTBOX_TYPE,               /* 3 */
    WIDGET_FORM_TYPE,                   /* 4 */
    WIDGET_DIALOG_TYPE,                 /* 5 */
    WIDGET_MENU_TYPE,                   /* 6 */
    WIDGET_EDITOR_TYPE,                 /* 7 */
    /* resource category */
    WIDGET_IMAGE_TYPE,                  /* 8 */
    WIDGET_STYLE_TYPE,                  /* 9 */
    WIDGET_STRING_TYPE,                 /* 10 */
    WIDGET_ICON_TYPE,                   /* 11 */
    WIDGET_ACTION_TYPE,                 /* 12 */
    WIDGET_SOUND_TYPE,                  /* 13 */
    /* gadget category */
    WIDGET_GADGET_STRING_TYPE,          /* 14 */
    WIDGET_GADGET_INPUT_TYPE,           /* 15 */
    WIDGET_GADGET_SELECT_GROUP_TYPE,    /* 16 */
    WIDGET_GADGET_IMAGE_TYPE,           /* 17 */
    WIDGET_GADGET_DATE_TYPE,            /* 18 */
    WIDGET_GADGET_BAR_TYPE,             /* 19 */
    /* internal use */
    WIDGET_CHOICE_ELEMENT_TYPE,         /* 20 */
    WIDGET_RAW_DATA_TYPE,               /* 21 */

    /* CTK extension */
    WIDGET_CTK_TYPE,    /* 22 */

    // static data
    // WIDGET_PRE_STRING_TYPE,
    WIDGET_ACCESSKEY_TYPE,  /* 23 */

    WIDGET_PRE_IMAGE_TYPE,  /* 24 */

    WIDGET_MAX_TYPE /* Less than 32, cf. WIDGET_WANT_FOCUS_LIST. Also represent free-ed data */
} widget_data_type_enum;

typedef enum
{
    WIDGET_CTK_PREDEFINED_CUSTOMIZED,
    WIDGET_CTK_PREDEFINED_TEXT_VIEW,
    WIDGET_CTK_PREDEFINED_WAIT_VIEW,
    WIDGET_CTK_PREDEFINED_PROGRESS_VIEW,
    WIDGET_CTK_PREDEFINED_LIST_MENU,
    WIDGET_CTK_PREDEFINED_DYNAMIC_LIST_MENU,
    WIDGET_CTK_PREDEFINED_DYNAMIC_RADIO_MENU,
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    WIDGET_CTK_PREDEFINED_SMIL_EDITOR,
#endif 
    WIDGET_CTK_PREDEFINED_MESSAGE_IND
} widget_ctk_predefined_type_enum;

#ifdef __PRODUCTION_RELEASE__
#define _ACTION(x)            ((widget_action_struct*)x)
#define _CHOICE_ELEMENT(x)    ((widget_choice_element_struct*)x)
#define _DIALOG(x)            ((widget_dialog_struct*)x)
#define _EDITOR(x)            ((widget_editor_struct*)x)
#define _FORM(x)           ((widget_form_struct*)x)
#define _CTK(x)               ((widget_ctk_struct*)x)
#define _GBAR(x)           ((widget_gadget_bar_struct*)x)
#define _GDATE(x)          ((widget_gadget_date_struct*)x)
#define _GINP(x)           ((widget_gadget_input_struct*)x)
#define _GADGET_INPUT(x)      ((widget_gadget_input_struct*)x)
#define _GIMG(x)           ((widget_gadget_image_struct*)x)
#define _GADGET_IMAGE(x)      ((widget_gadget_image_struct*)x)
#define _GADGET_SELECT_GROUP(x) ((widget_gadget_select_group_struct*)x)
#define _GSTR(x)           ((widget_gadget_string_struct*)x)
#define _GADGET_STRING(x)     ((widget_gadget_string_struct*)x)
#define _H(x)              ((widget_header_struct*)x)
#define _ICON(x)           ((widget_icon_struct*)x)
#define _IMG(x)               ((widget_image_struct*)x)
#define _IMAGE(x)          ((widget_image_struct*)x)
#define _M(x)              ((widget_menu_struct*)x)
#define _P(x)              ((widget_paintbox_struct*)x)
#define _PSTR(x)           ((widget_pre_string_struct*)x)
#define _ACCESSKEY(x)         ((widget_accesskey_struct*)x)
#define _PIMG(x)             ((widget_pre_image_struct*)x)
#define _RAW(x)               ((widget_raw_data_struct*)x)
#define _SCREEN(x)            ((widget_screen_struct*)x)
#define _SND(x)               ((widget_sound_struct*)x)
#define _STR(x)               ((widget_string_struct*)x)
#define _STRING(x)            ((widget_string_struct*)x)
#define _STYLE(x)          ((widget_style_struct*)x)
#define _W(x)              ((widget_window_struct*)x)
#define _WINDOW(x)            ((widget_window_struct*)x)
#define _V(x)              ((void*)x)
#else /* __PRODUCTION_RELEASE__ */ 
/* It is possible the the user application pass 0 as handle */


/*****************************************************************************
 * FUNCTION
 *  widget_typecast
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
__inline void *widget_typecast(void *x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: enable it
    // WAP_VERBOSE_ASSERT(x != NULL);
    return x;
}

#define WIDGET_TYPECAST(type, x) ((type*)widget_typecast((void *)x))

#define _ACTION(x)            WIDGET_TYPECAST(widget_action_struct, x)
#define _CHOICE_ELEMENT(x)    WIDGET_TYPECAST(widget_choice_element_struct, x)
#define _DIALOG(x)            WIDGET_TYPECAST(widget_dialog_struct, x)
#define _EDITOR(x)            WIDGET_TYPECAST(widget_editor_struct, x)
#define _FORM(x)           WIDGET_TYPECAST(widget_form_struct, x)
#define _CTK(x)               WIDGET_TYPECAST(widget_ctk_struct, x)
#define _GBAR(x)           WIDGET_TYPECAST(widget_gadget_bar_struct, x)
#define _GDATE(x)          WIDGET_TYPECAST(widget_gadget_date_struct, x)
#define _GINP(x)           WIDGET_TYPECAST(widget_gadget_input_struct, x)
#define _GADGET_INPUT(x)      WIDGET_TYPECAST(widget_gadget_input_struct, x)
#define _GIMG(x)           WIDGET_TYPECAST(widget_gadget_image_struct, x)
#define _GADGET_IMAGE(x)      WIDGET_TYPECAST(widget_gadget_image_struct, x)
#define _GADGET_SELECT_GROUP(x) WIDGET_TYPECAST(widget_gadget_select_group_struct, x)
#define _GSTR(x)           WIDGET_TYPECAST(widget_gadget_string_struct, x)
#define _GADGET_STRING(x)     WIDGET_TYPECAST(widget_gadget_string_struct, x)
#define _H(x)              WIDGET_TYPECAST(widget_header_struct, x)
#define _ICON(x)           WIDGET_TYPECAST(widget_icon_struct, x)
#define _IMG(x)               WIDGET_TYPECAST(widget_image_struct, x)
#define _IMAGE(x)          WIDGET_TYPECAST(widget_image_struct, x)
#define _M(x)              WIDGET_TYPECAST(widget_menu_struct, x)
#define _P(x)              WIDGET_TYPECAST(widget_paintbox_struct, x)
#define _PSTR(x)           WIDGET_TYPECAST(widget_pre_string_struct, x)
#define _ACCESSKEY(x)         WIDGET_TYPECAST(widget_accesskey_struct, x)
#define _PIMG(x)             WIDGET_TYPECAST(widget_pre_image_struct, x)
#define _RAW(x)               WIDGET_TYPECAST(widget_raw_data_struct, x)
#define _SCREEN(x)            WIDGET_TYPECAST(widget_screen_struct, x)
#define _SND(x)               WIDGET_TYPECAST(widget_sound_struct, x)
#define _STR(x)               WIDGET_TYPECAST(widget_string_struct, x)
#define _STRING(x)            WIDGET_TYPECAST(widget_string_struct, x)
#define _STYLE(x)          WIDGET_TYPECAST(widget_style_struct, x)
#define _W(x)              WIDGET_TYPECAST(widget_window_struct, x)
#define _WINDOW(x)            WIDGET_TYPECAST(widget_window_struct, x)
#define _V(x)              WIDGET_TYPECAST(void, x)

#endif /* __PRODUCTION_RELEASE__ */ 

#define IS_DATA_TYPE(w,t)     (((widget_header_struct*)w)->data_type==t)

#define IS_SCREEN_TYPE(w)     IS_DATA_TYPE(w,WIDGET_SCREEN_TYPE)

#define IS_WINDOW_TYPE(w)     (  (_H(w)->flag & WIDGET_FLAG_WINDOW)\
                        &&!(_H(w)->flag & WIDGET_FLAG_GADGET))

#define IS_GADGET_TYPE(w)     (_H(w)->flag & WIDGET_FLAG_GADGET)

#define IS_WINDOW_GADGET_TYPE(w) (_H(w)->flag & WIDGET_FLAG_WINDOW)

#define IS_PAINTBOX_TYPE(w)      IS_DATA_TYPE(w,WIDGET_PAINTBOX_TYPE)
#define IS_FORM_TYPE(w)       IS_DATA_TYPE(w,WIDGET_FORM_TYPE)
#define IS_DIALOG_TYPE(w)     IS_DATA_TYPE(w,WIDGET_DIALOG_TYPE)
#define IS_MENU_TYPE(w)       IS_DATA_TYPE(w,WIDGET_MENU_TYPE)
#define IS_EDITOR_TYPE(w)     IS_DATA_TYPE(w,WIDGET_EDITOR_TYPE)
#define IS_CTK_TYPE(w)        IS_DATA_TYPE(w,WIDGET_CTK_TYPE)

#define IS_IMAGE_TYPE(w)      IS_DATA_TYPE(w,WIDGET_IMAGE_TYPE)
#define IS_SOUND_TYPE(w)      IS_DATA_TYPE(w,WIDGET_SOUND_TYPE)
#define IS_STYLE_TYPE(w)      IS_DATA_TYPE(w,WIDGET_STYLE_TYPE)
#define IS_STRING_TYPE(w)     IS_DATA_TYPE(w,WIDGET_STRING_TYPE)
#define IS_ICON_TYPE(w)       IS_DATA_TYPE(w,WIDGET_ICON_TYPE)
#define IS_ACTION_TYPE(w)     IS_DATA_TYPE(w,WIDGET_ACTION_TYPE)

#define IS_GADGET_STRING_TYPE(w)    IS_DATA_TYPE(w,WIDGET_GADGET_STRING_TYPE)
#define IS_GADGET_INPUT_TYPE(w)        IS_DATA_TYPE(w,WIDGET_GADGET_INPUT_TYPE)
#define IS_GADGET_INPUT_TYPE2(w)    (IS_DATA_TYPE(w,WIDGET_GADGET_INPUT_TYPE) && !_GINP(w)->is_string_gadget_emulation)
#define IS_GADGET_SELECT_GROUP_TYPE(w) IS_DATA_TYPE(w,WIDGET_GADGET_SELECT_GROUP_TYPE)
#define IS_GADGET_IMAGE_TYPE(w)        IS_DATA_TYPE(w,WIDGET_GADGET_IMAGE_TYPE)
#define IS_GADGET_DATE_TYPE(w)         IS_DATA_TYPE(w,WIDGET_GADGET_DATE_TYPE)
#define IS_GADGET_BAR_TYPE(w)       IS_DATA_TYPE(w,WIDGET_GADGET_BAR_TYPE)

#define IS_RAW_DATA_TYPE(w)            IS_DATA_TYPE(w,WIDGET_RAW_DATA_TYPE)
#define IS_CHOICE_ELEMENT_TYPE(w)      IS_DATA_TYPE(w,WIDGET_CHOICE_ELEMENT_TYPE)

#define IS_PRE_STRING_TYPE(w)       IS_DATA_TYPE(w,WIDGET_PRE_STRING_TYPE)
#define IS_ACCESSKEY_TYPE(w)        IS_DATA_TYPE(w,WIDGET_ACCESSKEY_TYPE)
#define IS_PRE_IMAGE_TYPE(w)         IS_DATA_TYPE(w,WIDGET_PRE_IMAGE_TYPE)

#ifdef WIDGET_RO_PRE_STRING
#define IS_FLAG_STATIC(w)           ((_H(w)->flag & WIDGET_FLAG_STATIC) || IS_PRE_STRING_TYPE(w))
#else 
#define IS_FLAG_STATIC(w)           (_H(w)->flag & WIDGET_FLAG_STATIC)
#endif 

