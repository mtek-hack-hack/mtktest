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
 * widget_icon.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget icons
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "IdleAppDef.h"
// #include "wgui_categories.h" /* For icon resource definition */
#include "wgui_categories_defs.h"
#include "wgui_categories.h"

/****************************************************************
 ICON
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetIconCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  iconType            [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfIconHandle HDIa_widgetIconCreate(MSF_UINT8 modId, MsfIconType iconType, MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_icon_struct *w = widget_create_icon(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;
    w->icon = iconType;

    switch (iconType)
    {
        case MsfButton:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfButtonPressed:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfRadioButton:
            w->icon_data = (int)get_image(RADIO_OFF_IMAGE_ID);
            break;
        case MsfRadioButtonPressed:
            w->icon_data = (int)get_image(RADIO_ON_IMAGE_ID);
            break;
        case MsfCheckBox:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfCheckBoxChecked:
            w->icon_data = (int)get_image(CHECKBOX_ON_IMAGE_ID);
            break;
        case MsfKey:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfBullet:
            w->icon_data = (int)get_image(RADIO_OFF_IMAGE_ID);
            break;
        case MsfTick:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfSquare:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfCircle:
            w->icon_data = (int)get_image(RADIO_OFF_IMAGE_ID);
            break;
        case MsfDisk:
            w->icon_data = (int)get_image(RADIO_OFF_IMAGE_ID);
            break;
        case MsfArrowHead:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfIcon1:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfIcon2:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfIcon3:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
        case MsfIcon4:
            w->icon_data = (int)get_image(CHECKBOX_OFF_IMAGE_ID);
            break;
    }
    widget_set_attrib(w, style, defaultStyle);
    return (MsfIconHandle) w;
}

