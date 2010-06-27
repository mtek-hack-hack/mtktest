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
 * widget_editor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MsfEditor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"

/****************************************************************
 EDITOR 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetEditorCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  initialString       [IN]        
 *  inputString         [IN]        
 *  type                [IN]        
 *  maxSize             [IN]        
 *  singleLine          [IN]        
 *  size                [?]         
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetEditorCreate(
                    MSF_UINT8 modId,
                    MsfStringHandle initialString,
                    MsfStringHandle inputString,
                    MsfTextType type,
                    int maxSize,
                    int singleLine,
                    MsfSize *size,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_editor_struct *w = widget_create_editor(modId);
    MsfStringHandle str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    /* widget_set_attrib(w,prompt,initialString); */

    if (inputString)
    {
        str = widget_copy_string(modId, inputString);
    }
    else
    {
        str = HDIa_widgetStringCreate(modId, "", MsfUtf8, 1, 0);
    }

    widget_set_attrib(w, text, str);
    DEC_REF(w->text);   /* need it to automatic free */

    if (maxSize <= 0)
    {
        maxSize = WIDGET_MAX_INPUT_LEN;
    }

    widget_resize_string(_STR(w->text), maxSize);
    /* DEC_REF(w->text); // TODO: ref count of w->text is 0! Wrong? */

    WAP_DBG_ASSERT(_STR(w->text)->parent_cnt == 1);
    WAP_DBG_ASSERT(_STR(w->text)->raw->parent_cnt == 1);

    w->text_type = type;
    w->input_max_size = maxSize;
    w->is_single_line = singleLine ? KAL_TRUE : KAL_FALSE;

    if (size)
    {
        w->size = *size;
    }
    else
    {
        w->size = WGUI_CTX->default_display_size;
    }

    w->property_mask = propertyMask;
    w->index = -1;  /* default no index */

    widget_set_attrib(w, style, defaultStyle);
    return (MsfWindowHandle) w;
}

