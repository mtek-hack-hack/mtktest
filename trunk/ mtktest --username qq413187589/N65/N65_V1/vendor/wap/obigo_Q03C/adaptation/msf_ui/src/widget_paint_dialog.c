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
 * widget_paint_dialog.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfDialog paint routines
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "widget.h"
#include "settingprofile.h"     /* for MESSAGE_TONE */
#include "ProfileGProts.h"      /* for playRequestedTone */
#include "gpio/gpioInc/GPIOInc.h"				/* Vibration/Backlight */

/****************************************************************
 paint dialog
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_dialog_left_softkey_dismiss_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_dialog_left_softkey_dismiss_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WGUI_CTX->current_dialog);
    if (WGUI_CTX->current_dialog != NULL)
    {
        HDIa_widgetRemove((MSF_UINT32) WGUI_CTX->current_screen, (MSF_UINT32) WGUI_CTX->current_dialog);
        widget_notify(_H(WGUI_CTX->current_dialog), MsfNotifyLostFocus);

        // Added 2004.06.23
        // TODO: We still do not handle next_screen
        if (WGUI_CTX->current_dialog->next_window)
        {
            if (_H(WGUI_CTX->current_dialog->next_window)->data_type >= WIDGET_MAX_TYPE /* Already released */  ||
                !IS_WINDOW_TYPE(WGUI_CTX->current_dialog->next_window))
            {
                WAP_DBG_ASSERT(0);
                return;
            }
            HDIa_widgetSetInFocus((MSF_UINT32) WGUI_CTX->current_dialog->next_window, 1);
        }

        /* This is already done in meaDeleteDialog or bra_dlg_dialog_delete */
        /* HDIa_widgetRelease((MSF_UINT32)WGUI_CTX->current_dialog); // TODO: do we need to release it? */
        WGUI_CTX->current_dialog = NULL;
        widget_paint();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_dialog_get_attributes
 * DESCRIPTION
 *  Convert MsfDialogType to tone, image, etc
 * PARAMETERS
 *  type                [IN]        Dialog type
 *  imageid             [OUT]       
 *  toneid              [OUT]       
 *  imageOnBottom       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void widget_dialog_get_attributes(
        MsfDialogType type,
        ctk_image_id *imageid,
        ctk_tone_id *toneid,
        kal_bool *imageOnBottom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *imageOnBottom = KAL_FALSE;
    *toneid = WARNING_TONE;
    *imageid = IMG_GLOBAL_WARNING;

    switch (type)
    {
        case MsfWarning:            /* FALLTHROUGH */
        case MsfAlert:
            *imageid = IMG_GLOBAL_WARNING;
            break;
        case MsfConfirmation:       /* FALLTHROUGH */
        case MsfPrompt:
            *imageid = IMG_GLOBAL_QUESTION;
            *toneid = WARNING_TONE; /* convention */
            break;
        case MsfInfo:
            *imageid = IMG_GLOBAL_INFO;
            *toneid = SUCCESS_TONE;
            break;
        case MsfError:
            *imageid = IMG_GLOBAL_ERROR;
            *toneid = ERROR_TONE;
            break;
        case MsfPromptEmpty:
            *imageid = IMG_GLOBAL_EMPTY;
            *toneid = EMPTY_LIST_TONE;
            /* *imageOnBottom = KAL_TRUE; // Icon always on top after w04.14 */
            break;
        case MsfPromptSaveDone:
            *imageid = IMG_GLOBAL_ACTIVATED;
            *toneid = SUCCESS_TONE;
            break;
        default:
            WAP_DBG_ASSERT(0);
            *imageid = IMG_GLOBAL_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_dialog
 * DESCRIPTION
 *  main routine to draw dialog, set keyboard handler
 * PARAMETERS
 *  dialog      [IN]     -  dialog window
 *  size        [IN]     -  default size
 *  pos         [IN]     -  absolute position
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_dialog(widget_dialog_struct *dialog, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool image_bottom = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->current_dialog = dialog;

    // TODO: maybe we can use Category165 for MsfPrompt
    TurnOnBacklight(1);
    if (dialog->dialog_type == MsfPrompt)
    {
        /*
         * WML Script - Dialog.prompt() 
         * Currently, we only support only one inputbox in the dialog 
         */
        if (dialog->input_sum)
        {
            /* After the page is download finished, we allow the users to enter full screen editor */
            if ((WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_NONE) &&
                (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY) != WIDGET_STATUS_BAR_BUSY)
            {
                widget_gadget_input_struct *inp = (widget_gadget_input_struct *)dialog->dialog_input;
                void *buffer;

                /* fetch the raw data */
                WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_WANT_EXECUTE;
                buffer = widget_string_content(inp->text);
            #ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ 
                widget_init_input_CSS_pattern((char*)inp->format_pattern);
            #endif

                /* entet the fullscreen editor and put widget screen in history */
                widget_setup_fullscreen_editor(
                    _H(inp),
                    buffer,
                    inp->input_max_size + 1,
                    inp->text_type,
                    inp->is_input_required,
                    0,
                    (const char*)inp->format_pattern);
                widget_enter_fullscreen_editor();
                return;
            }
        }
    }
    else
    {
        ctk_image_id icon = 0;
        ctk_tone_id tone = 0;

        widget_dialog_get_attributes(dialog->dialog_type, &icon, &tone, &image_bottom);

        if (!dialog->is_tone_played)
        {
            dialog->is_tone_played = 1;
            if (tone)
            {
                playRequestedTone(tone);
            }
        }

        if (image_bottom)
        {
            widget_ShowCategory123Screen_ImageBottom(
                0,
                0,
                0,
                0,
                0,
                0,
                (UI_string_type) widget_string_content(dialog->dialog_text),
                icon,
                NULL);
        }
        else
        {
            widget_ShowCategory123Screen(
                0,
                0,
                0,
                0,
                0,
                0,
                (UI_string_type) widget_string_content(dialog->dialog_text),
                icon,
                NULL);
        }

        RedrawCategoryFunction = widget_RedrawCategory123Screen;
    }
    /* 
     * Setting the dismiss key. 
     * Note that BRA usually creates its own Action instead of using this.
     */
    /* Need handle the action of MsfDialog specilally. */
    WGUI_CTX->LSK_mask = MsfWidgetUsing;
    change_left_softkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(widget_dialog_left_softkey_dismiss_handler, KEY_EVENT_UP);
}

