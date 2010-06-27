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
 * widget_layout.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget window/gadget dimension 
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "app_str.h"
/****************************************************************
 Layout
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetSize(MSF_UINT32 handle, MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle)
    {
        if (IS_FLAG_STATIC(handle))     // TODO: What?
        {
            size->width = 0;
            size->height = 0;
        }

        switch (_H(handle)->data_type)
        {
            case WIDGET_GADGET_IMAGE_TYPE:
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
                break;

            case WIDGET_IMAGE_TYPE:
                /* FALLTHROUGH no break */
            case WIDGET_PRE_IMAGE_TYPE:
            {
                MsfSize *imgsize = widget_image_dimension(handle);

                if (imgsize)
                {
                    *size = *imgsize;
                }
                else
                {
                    size->width = 0;
                    size->height = 0;
                }
            }
                return 1;

            case WIDGET_GADGET_INPUT_TYPE:
                // TODO: return a minimum size if actual size is smaller than it
                if (_GINP(handle)->is_single_line)
                {
                    if (_GINP(handle)->size.width == 0)
                    {
                        _GINP(handle)->size.width = (short)WIDGET_DEFAULT_SINGLE_LINE_INPUT_WIDTH;
                    }
                    if (_GINP(handle)->size.height == 0)
                    {
                        _GINP(handle)->size.height = (short)WIDGET_DEFAULT_SINGLE_LINE_INPUT_HEIGHT;
                    }
                }
                else
                {
                    if (_GINP(handle)->size.width == 0)
                    {
                        _GINP(handle)->size.width = WIDGET_DEFAULT_MULTI_LINE_INPUT_WIDTH;
                    }
                    if (_GINP(handle)->size.height == 0)
                    {
                        _GINP(handle)->size.height = WIDGET_DEFAULT_MULTI_LINE_INPUT_HEIGHT;
                    }
                }
                break;

            case WIDGET_GADGET_SELECT_GROUP_TYPE:
                if (_GADGET_SELECT_GROUP(handle)->size.width == 0)
                {
                    _GADGET_SELECT_GROUP(handle)->size.width = WIDGET_DEFAULT_SELECT_GROUP_WIDTH;
                }
                if (_GADGET_SELECT_GROUP(handle)->size.height == 0)
                {
                    _GADGET_SELECT_GROUP(handle)->size.height = WIDGET_DEFAULT_SELECT_GROUP_HEIGHT;
                }
                /* _GADGET_SELECT_GROUP(handle)->size.height = 24 * _GADGET_SELECT_GROUP(handle)->menu_items_sum; */
                break;

            case WIDGET_ICON_TYPE:
            {
                S32 w, h;

                gui_measure_image((PU8) _ICON(handle)->icon_data, &w, &h);
                size->width = (S16) w;
                size->height = (S16) h;
            }
                return 1;

            case WIDGET_GADGET_BAR_TYPE:
                break;

                // TODO: use string->style for different font size
            case WIDGET_GADGET_STRING_TYPE: /* String Gadget and String size must be the same */
            {
                widget_gadget_string_struct *gstr = _GSTR(handle);
                S32 w, h;

                *size = gstr->size;

                if (gstr->text && (size->height == 0 || size->width == 0))
                {
                    kal_uint8 *str = (kal_uint8*)widget_string_content(gstr->text);
                    
                    widget_get_string_width_height(
                        (kal_uint8 *)str, 
                        0, 
                        app_ucs2_strlen((const kal_int8*)str), 
                        &w,
                        &h);
                    size->height = (MSF_INT16) h;
                    size->width = (MSF_INT16) w;
                }
            }
                return 1;

            case WIDGET_STRING_TYPE:
            {
                S32 w, h;
                U8 *stringdata = (U8*) widget_string_content(handle);

                w = h = 0;
                if (stringdata)
                {
                    widget_get_string_width_height(
                        (kal_uint8 *)stringdata, 
                        0, 
                        app_ucs2_strlen((const kal_int8*)stringdata), 
                        &w,
                        &h);
                }
                size->height = (MSF_INT16) h;
                size->width = (MSF_INT16) w;
            }
                return 1;

            case WIDGET_ACCESSKEY_TYPE:
            {
                size->height = 0;
                size->width = 0;
            }
                return 1;

            default:
                WAP_DBG_ASSERT(0);
        }

        if (_H(handle)->flag & WIDGET_FLAG_WINDOW)
        {
            *size = _W(handle)->size;
        }
        else
        {
            size->width = 0;
            size->height = 0;
        }
    }

    return 1;
}

