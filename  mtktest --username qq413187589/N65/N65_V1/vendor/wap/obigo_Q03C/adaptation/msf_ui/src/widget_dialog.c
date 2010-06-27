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
 * widget_dialog.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Widget dialog processing
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"

/****************************************************************
 DIALOG 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDialogCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  dialogText          [IN]        
 *  type                [IN]        
 *  timeoutTime         [IN]        
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetDialogCreate(
                    MSF_UINT8 modId,
                    MsfStringHandle dialogText,
                    MsfDialogType type,
                    MSF_UINT32 timeoutTime /* ignored */ ,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_dialog_struct *w = widget_create_dialog(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;
    widget_set_attrib(w, dialog_text, dialogText);
    w->dialog_type = type;
    w->timeout = timeoutTime;
    w->property_mask = propertyMask;

    widget_set_attrib(w, style, defaultStyle);

    return (MsfWindowHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDialogSetAttr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialog          [IN]        
 *  dialogText      [IN]        
 *  timeoutTime     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDialogSetAttr(MsfWindowHandle dialog, MsfStringHandle dialogText, MSF_UINT32 timeoutTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_set_attrib(_DIALOG(dialog), dialog_text, dialogText);

    _DIALOG(dialog)->timeout = timeoutTime;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDialogAddInput
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialog          [IN]        
 *  label           [IN]        
 *  inputText       [IN]        
 *  inputMode       [IN]        
 *  maxSize         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDialogAddInput(
        MsfWindowHandle dialog,
        MsfStringHandle label,
        MsfStringHandle inputText,
        MsfTextType inputMode,
        int maxSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfPosition position;
    MsfSize size;

    widget_gadget_input_struct *inp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_DIALOG(dialog)->input_sum == 0)
    {
        inp = _GINP(HDIa_widgetTextInputCreate(0, label, inputText, inputMode, maxSize, 1, 0, 0, 0));
        inp->index = _DIALOG(dialog)->input_sum;

        position.x = (short)WIDGET_DEFAULT_DIALOG_X;
        position.y = (short)(WIDGET_DEFAULT_DIALOG_Y + WIDGET_DEFAULT_DIALOG_HEIGHT + 10
                             + (WIDGET_DEFAULT_SINGLE_LINE_INPUT_HEIGHT + 10) * inp->index);
        size.width = (short)WIDGET_DEFAULT_SINGLE_LINE_INPUT_WIDTH;
        size.height = (short)WIDGET_DEFAULT_SINGLE_LINE_INPUT_HEIGHT;
        HDIa_widgetSetPosition((MSF_UINT32) inp, &position, 0);
        HDIa_widgetSetSize((MSF_UINT32) inp, &size);

        _DIALOG(dialog)->dialog_input = (MsfStringHandle)inp;
        _DIALOG(dialog)->input_sum++;

        widget_insert_last_childs(dialog, inp);
        return inp->index;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDialogRemoveInput
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialog      [IN]        
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDialogRemoveInput(MsfWindowHandle dialog, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_input_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= _DIALOG(dialog)->input_sum)
    {
        return 0;
    }
    if (_DIALOG(dialog)->input_sum)
    {
        if (_DIALOG(dialog)->dialog_input)
        {
            foreach(dialog, GADGET_INPUT, node,
                {
                    if (node->index > index)
                    {
                        node->index--;
                    }
                    else
                    {
                        if (node->index == index)
                        {
                            widget_remove_childs(dialog, node);
                        }
                    }
                }
            );

            HDIa_widgetRelease(_DIALOG(dialog)->dialog_input);
            _DIALOG(dialog)->dialog_input = (MsfGadgetHandle)NULL;
            _DIALOG(dialog)->input_sum--;
        }
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDialogSetInputAttr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialog          [IN]        
 *  index           [IN]        
 *  label           [IN]        
 *  inputText       [IN]        
 *  inputMode       [IN]        
 *  maxSize         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDialogSetInputAttr(
        MsfWindowHandle dialog,
        int index,
        MsfStringHandle label,
        MsfStringHandle inputText,
        MsfTextType inputMode,
        int maxSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_input_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    foreach(_H(dialog), GADGET_INPUT, node,
        {
            if (node->index == index)
            {
                return HDIa_widgetTextSetText((MSF_UINT32) node, label, inputMode, maxSize, inputText, 1);
            }
        }
    );
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDialogDisableTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtDialogDisableTone(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_DIALOG_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    _DIALOG(wnd)->is_tone_played = 1;
}

