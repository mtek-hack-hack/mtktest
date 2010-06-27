/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeSettings.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_PICT_BRIDGE_SUPPORT__

#define __MMI_PICT_BRIDGE_CROPPING_CAT88__



#include "SettingProfile.h"

#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeGProt.h"
#include "PictBridgeStruct.h"


/*
 * Global Variable
 */
extern pict_bridge_context_struct g_pict_bridge_context;
extern pict_bridge_xml_struct g_pict_bridge_xml;


/*
 * Local Variable
 */
pict_bridge_setting_struct g_pict_bridge_setting;


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_exec_print_settings_change_callback
 * DESCRIPTION
 *  Execution function for inline editor item changed callback
 * PARAMETERS
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_exec_print_settings_change_callback(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
        case 1: /* paper size */
        case 5: /* page format */
        case 7: /* pages per sheet */
            mmi_pict_entry_print_settings(); /* re-entry print setting screen again to change the item selectors */
            DeleteScreenIfPresent(SCR_ID_PICT_SETTINGS);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_fill_print_settings_inline_editor
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_fill_print_settings_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 paper_count = 1, copies_count = 1, format_count = 1;
    U8 layout_count = 1, border_count = 1, date_count = 1;
    U8 filename_count = 1, cropping_count = 1, fixed_count = 1;

    U8 i, cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* paper size */
    if (g_pict_bridge_xml.paper_sizes == 0)
    {
        g_pict_bridge_setting.paper_list[0] = (U8*) GetString(STR_ID_PICT_DEFAULT);
    }
    else
    {
        i = 0;
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_DEFAULT)
        {
            g_pict_bridge_setting.paper_list[i++] = (U8*) GetString(STR_ID_PICT_DEFAULT);
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_POSTCARD)
        {
            g_pict_bridge_setting.paper_list[i++] = (U8*) GetString(STR_ID_PICT_PAPER_POSTCARD);
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_4x6)
        {
            g_pict_bridge_setting.paper_list[i++] = (U8*) GetString(STR_ID_PICT_PAPER_4x6);
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_LETTER)
        {
            g_pict_bridge_setting.paper_list[i++] = (U8*) GetString(STR_ID_PICT_PAPER_LETTER);
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_A4)
        {
            g_pict_bridge_setting.paper_list[i++] = (U8*) GetString(STR_ID_PICT_PAPER_A4);
        }
        paper_count = i;
    }

    /* number of copies */
    if (g_pict_bridge_setting.page_format == 0) /* standard */
    {
        g_pict_bridge_setting.copies_list[0] = (U8*) GetString(STR_GLOBAL_1);
        g_pict_bridge_setting.copies_list[1] = (U8*) GetString(STR_GLOBAL_2);
        g_pict_bridge_setting.copies_list[2] = (U8*) GetString(STR_GLOBAL_3);
        g_pict_bridge_setting.copies_list[3] = (U8*) GetString(STR_GLOBAL_4);
        g_pict_bridge_setting.copies_list[4] = (U8*) GetString(STR_GLOBAL_5);
        g_pict_bridge_setting.copies_list[5] = (U8*) GetString(STR_GLOBAL_6);
        g_pict_bridge_setting.copies_list[6] = (U8*) GetString(STR_GLOBAL_7);
        g_pict_bridge_setting.copies_list[7] = (U8*) GetString(STR_GLOBAL_8);
        g_pict_bridge_setting.copies_list[8] = (U8*) GetString(STR_GLOBAL_9);
        g_pict_bridge_setting.copies_list[9] = (U8*) GetString(STR_GLOBAL_10);
        copies_count = 10;
    }
    else
    {
        g_pict_bridge_setting.copies_list[0] = (U8*) GetString(STR_GLOBAL_1);
        g_pict_bridge_setting.number_of_copies = 0;
    }

    /* page format */
    g_pict_bridge_setting.format_list[0] = (U8*) GetString(STR_ID_PICT_STANDARD);
    if (g_pict_bridge_context.printing_capability[7] == 0)
    {
        g_pict_bridge_setting.format_list[1] = (U8*) GetString(STR_ID_PICT_MULTIPLE);
        g_pict_bridge_setting.format_list[2] = (U8*) GetString(STR_ID_PICT_INDEX);
    #ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
        format_count = 3;
    #else
        format_count = 2;
    #endif
    }
    else
    {
        format_count = 1;
    }

    /* pages per sheet */
    if (g_pict_bridge_setting.page_format == 0) /* standard */
    {
        g_pict_bridge_setting.layout_list[0] = (U8*) GetString(STR_GLOBAL_1);
        g_pict_bridge_setting.layout = 0;
    }
    else
    {
        do
        {
            cnt = 0;
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_DEFAULT)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    g_pict_bridge_setting.layout_list[0] = (U8*) GetString(STR_GLOBAL_1);
                    layout_count = 1;
                    if (g_pict_bridge_xml.layouts[0] & PICT_LAYOUT_2UP)
                    {
                        g_pict_bridge_setting.layout_list[1] = (U8*) GetString(STR_GLOBAL_2);
                        layout_count++;
                        if (g_pict_bridge_xml.layouts[0] & PICT_LAYOUT_4UP)
                        {
                            g_pict_bridge_setting.layout_list[2] = (U8*) GetString(STR_GLOBAL_4);
                            layout_count++;
                        #ifdef __MMI_PICT_BRIDGE_INDEX_PRINT__
                            if ((g_pict_bridge_setting.page_format == 2) && (g_pict_bridge_xml.layouts[0] & PICT_LAYOUT_INDEX)) /* index */
                            {
                                g_pict_bridge_setting.layout_list[3] = (U8*) GetString(STR_ID_PICT_INDEX_ALL);
                                layout_count++;
                            }
                        #endif /* __MMI_PICT_BRIDGE_INDEX_PRINT__ */
                        }
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_POSTCARD)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    g_pict_bridge_setting.layout_list[0] = (U8*) GetString(STR_GLOBAL_1);
                    layout_count = 1;
                    if (g_pict_bridge_xml.layouts[1] & PICT_LAYOUT_2UP)
                    {
                        g_pict_bridge_setting.layout_list[1] = (U8*) GetString(STR_GLOBAL_2);
                        layout_count++;
                        if (g_pict_bridge_xml.layouts[1] & PICT_LAYOUT_4UP)
                        {
                            g_pict_bridge_setting.layout_list[2] = (U8*) GetString(STR_GLOBAL_4);
                            layout_count++;
                        #ifdef __MMI_PICT_BRIDGE_INDEX_PRINT__
                            if ((g_pict_bridge_setting.page_format == 2) && (g_pict_bridge_xml.layouts[1] & PICT_LAYOUT_INDEX)) /* index */
                            {
                                g_pict_bridge_setting.layout_list[3] = (U8*) GetString(STR_ID_PICT_INDEX_ALL);
                                layout_count++;
                            }
                        #endif /* __MMI_PICT_BRIDGE_INDEX_PRINT__ */
                        }
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_4x6)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    g_pict_bridge_setting.layout_list[0] = (U8*) GetString(STR_GLOBAL_1);
                    layout_count = 1;
                    if (g_pict_bridge_xml.layouts[2] & PICT_LAYOUT_2UP)
                    {
                        g_pict_bridge_setting.layout_list[1] = (U8*) GetString(STR_GLOBAL_2);
                        layout_count++;
                        if (g_pict_bridge_xml.layouts[2] & PICT_LAYOUT_4UP)
                        {
                            g_pict_bridge_setting.layout_list[2] = (U8*) GetString(STR_GLOBAL_4);
                            layout_count++;
                        #ifdef __MMI_PICT_BRIDGE_INDEX_PRINT__
                            if ((g_pict_bridge_setting.page_format == 2) && (g_pict_bridge_xml.layouts[2] & PICT_LAYOUT_INDEX)) /* index */
                            {
                                g_pict_bridge_setting.layout_list[3] = (U8*) GetString(STR_ID_PICT_INDEX_ALL);
                                layout_count++;
                            }
                        #endif /* __MMI_PICT_BRIDGE_INDEX_PRINT__ */
                        }
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_LETTER)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    g_pict_bridge_setting.layout_list[0] = (U8*) GetString(STR_GLOBAL_1);
                    layout_count = 1;
                    if (g_pict_bridge_xml.layouts[3] & PICT_LAYOUT_2UP)
                    {
                        g_pict_bridge_setting.layout_list[1] = (U8*) GetString(STR_GLOBAL_2);
                        layout_count++;
                        if (g_pict_bridge_xml.layouts[3] & PICT_LAYOUT_4UP)
                        {
                            g_pict_bridge_setting.layout_list[2] = (U8*) GetString(STR_GLOBAL_4);
                            layout_count++;
                        #ifdef __MMI_PICT_BRIDGE_INDEX_PRINT__
                            if ((g_pict_bridge_setting.page_format == 2) && (g_pict_bridge_xml.layouts[3] & PICT_LAYOUT_INDEX)) /* index */
                            {
                                g_pict_bridge_setting.layout_list[3] = (U8*) GetString(STR_ID_PICT_INDEX_ALL);
                                layout_count++;
                            }
                        #endif /* __MMI_PICT_BRIDGE_INDEX_PRINT__ */
                        }
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_A4)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    g_pict_bridge_setting.layout_list[0] = (U8*) GetString(STR_GLOBAL_1);
                    layout_count = 1;
                    if (g_pict_bridge_xml.layouts[4] & PICT_LAYOUT_2UP)
                    {
                        g_pict_bridge_setting.layout_list[1] = (U8*) GetString(STR_GLOBAL_2);
                        layout_count++;
                        if (g_pict_bridge_xml.layouts[4] & PICT_LAYOUT_4UP)
                        {
                            g_pict_bridge_setting.layout_list[2] = (U8*) GetString(STR_GLOBAL_4);
                            layout_count++;
                        #ifdef __MMI_PICT_BRIDGE_INDEX_PRINT__
                            if ((g_pict_bridge_setting.page_format == 2) && (g_pict_bridge_xml.layouts[4] & PICT_LAYOUT_INDEX)) /* index */
                            {
                                g_pict_bridge_setting.layout_list[3] = (U8*) GetString(STR_ID_PICT_INDEX_ALL);
                                layout_count++;
                            }
                        #endif /* __MMI_PICT_BRIDGE_INDEX_PRINT__ */
                        }
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
        } while(0);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    }

    /* border */
    if (g_pict_bridge_setting.layout == 0) /* one page per sheet */
    {
        g_pict_bridge_setting.border_list[0] = (U8*) GetString(STR_GLOBAL_ON);
    #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
        border_count = 1;
        do
        {
            cnt = 0;
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_DEFAULT)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[0] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = (U8*) GetString(STR_GLOBAL_OFF);
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_POSTCARD)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[1] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = (U8*) GetString(STR_GLOBAL_OFF);
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_4x6)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[2] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = (U8*) GetString(STR_GLOBAL_OFF);
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_LETTER)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[3] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = (U8*) GetString(STR_GLOBAL_OFF);
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_A4)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[4] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = (U8*) GetString(STR_GLOBAL_OFF);
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
        } while(0);
    #else /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
        g_pict_bridge_setting.border_list[1] = (U8*) GetString(STR_GLOBAL_OFF);
        border_count = 2;
    #endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
    }
    else
    {
        g_pict_bridge_setting.border_list[0] = (U8*) GetString(STR_GLOBAL_ON);
        g_pict_bridge_setting.border = 0;
    }

    /* date print */
    if (g_pict_bridge_xml.date_prints == 0)
    {
        g_pict_bridge_setting.date_list[0] = (U8*) GetString(STR_ID_PICT_DEFAULT);
    }
    else if (g_pict_bridge_setting.layout != 0) /* multiple page per sheet */
    {
        g_pict_bridge_setting.date_list[0] = (U8*) GetString(STR_ID_PICT_DEFAULT);
        g_pict_bridge_setting.date_print = 0;
    }
    else
    {
        i = 0;
        if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_DEFAULT)
        {
            g_pict_bridge_setting.date_list[i++] = (U8*) GetString(STR_ID_PICT_DEFAULT);
        }
        if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_OFF)
        {
            g_pict_bridge_setting.date_list[i++] = (U8*) GetString(STR_GLOBAL_OFF);
        }
        if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_ON)
        {
            g_pict_bridge_setting.date_list[i++] = (U8*) GetString(STR_GLOBAL_ON);
        }
        date_count = i;
    }

    /* filename print */
    if (g_pict_bridge_xml.filename_prints == 0)
    {
        g_pict_bridge_setting.filename_list[0] = (U8*) GetString(STR_ID_PICT_DEFAULT);
    }
    else if (g_pict_bridge_setting.layout != 0) /* multiple page per sheet */
    {
        g_pict_bridge_setting.filename_list[0] = (U8*) GetString(STR_ID_PICT_DEFAULT);
        g_pict_bridge_setting.filename_print = 0;
    }
    else
    {
        i = 0;
        if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_DEFAULT)
        {
            g_pict_bridge_setting.filename_list[i++] = (U8*) GetString(STR_ID_PICT_DEFAULT);
        }
        if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_OFF)
        {
            g_pict_bridge_setting.filename_list[i++] = (U8*) GetString(STR_GLOBAL_OFF);
        }
        if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_ON)
        {
            g_pict_bridge_setting.filename_list[i++] = (U8*) GetString(STR_GLOBAL_ON);
        }
        filename_count = i;
    }

    /* cropping */
    if (g_pict_bridge_xml.croppings == 0
#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    ||  g_pict_bridge_context.multi_file_select != 1
#endif
    )
    {
        g_pict_bridge_setting.cropping_list[0] = (U8*) GetString(STR_ID_PICT_DEFAULT);
    }
    else
    {
        i = 0;
        if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_DEFAULT)
        {
            g_pict_bridge_setting.cropping_list[i++] = (U8*) GetString(STR_ID_PICT_DEFAULT);
        }
        if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_OFF)
        {
            g_pict_bridge_setting.cropping_list[i++] = (U8*) GetString(STR_GLOBAL_OFF);
        }
        if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_ON)
        {
            g_pict_bridge_setting.cropping_list[i++] = (U8*) GetString(STR_GLOBAL_ON);
        }
        cropping_count = i;
    }

    /* fixed size */
    g_pict_bridge_setting.fixed_list[0] = (U8*) GetString(STR_ID_PICT_DISABLE);

    /* paper size */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(STR_ID_PICT_PAPER_SIZE));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[1],
        paper_count,
        g_pict_bridge_setting.paper_list,
        &g_pict_bridge_setting.paper_size);

    /* number of copies */
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) GetString(STR_ID_PICT_COPIES));

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[3],
        copies_count,
        g_pict_bridge_setting.copies_list,
        &g_pict_bridge_setting.number_of_copies);

    /* page format */
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (PU8) GetString(STR_ID_PICT_PAGE_FORMAT));

    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[5],
        format_count,
        g_pict_bridge_setting.format_list,
        &g_pict_bridge_setting.page_format);

    /* pages per sheet */
    SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[6], (PU8) GetString(STR_ID_PICT_LAYOUT));

    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[7],
        layout_count,
        g_pict_bridge_setting.layout_list,
        &g_pict_bridge_setting.layout);

    /* border */
    SetInlineItemActivation(&wgui_inline_items[8], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[8], (PU8) GetString(STR_ID_PICT_BORDER));

    SetInlineItemActivation(&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[9],
        border_count,
        g_pict_bridge_setting.border_list,
        &g_pict_bridge_setting.border);

    /* date print */
    SetInlineItemActivation(&wgui_inline_items[10], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[10], (PU8) GetString(STR_ID_PICT_DATE_PRINT));

    SetInlineItemActivation(&wgui_inline_items[11], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[11],
        date_count,
        g_pict_bridge_setting.date_list,
        &g_pict_bridge_setting.date_print);

    /* filename print */
    SetInlineItemActivation(&wgui_inline_items[12], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[12], (PU8) GetString(STR_ID_PICT_FILENAME_PRINT));

    SetInlineItemActivation(&wgui_inline_items[13], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[13],
        filename_count,
        g_pict_bridge_setting.filename_list,
        &g_pict_bridge_setting.filename_print);

    /* cropping */
    SetInlineItemActivation(&wgui_inline_items[14], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[14], (PU8) GetString(STR_ID_PICT_CROPPING));

    SetInlineItemActivation(&wgui_inline_items[15], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[15],
        cropping_count,
        g_pict_bridge_setting.cropping_list,
        &g_pict_bridge_setting.cropping);

    /* fixed size */
    SetInlineItemActivation(&wgui_inline_items[16], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[16], (PU8) GetString(STR_ID_PICT_FIXED_SIZE));

    SetInlineItemActivation(&wgui_inline_items[17], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[17],
        fixed_count,
        g_pict_bridge_setting.fixed_list,
        &g_pict_bridge_setting.fixed_size);

    RegisterInlineItemChangedNotification(mmi_pict_exec_print_settings_change_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_edit_print_settings_done
 * DESCRIPTION
 *  Completion function for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_edit_print_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 check_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    check_value = (g_pict_bridge_xml.croppings & PICT_CAPABILITY_OFF) ? 2 : 1;

    if (g_pict_bridge_setting.cropping == check_value)
    {
        mmi_pict_get_file_dimension();

        g_pict_bridge_setting.x_coordinate = 0;
        g_pict_bridge_setting.y_coordinate = 0;
        g_pict_bridge_setting.x_arix = g_pict_bridge_context.image_width;
        g_pict_bridge_setting.y_arix = g_pict_bridge_context.image_height;
#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT57__
        mmi_pict_entry_image_cropping();
#endif
#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT88__
        mmi_pict_entry_image_cropping_phase1();
#endif
#if !defined(__MMI_PICT_BRIDGE_CROPPING_CAT57__) && !defined(__MMI_PICT_BRIDGE_CROPPING_CAT88__)
        MMI_ASSERT(0);
#endif
    }
    else
    {
        mmi_pict_entry_print_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_register_print_settings_highlight_hdlr
 * DESCRIPTION
 *  Registration function for inline editor hightlight handler
 * PARAMETERS
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_register_print_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_pict_edit_print_settings_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_exit_print_settings
 * DESCRIPTION
 *  Exit function for print setting inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_exit_print_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_PICT_SETTINGS;
    Scr.entryFuncPtr = mmi_pict_entry_print_settings;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_settings
 * DESCRIPTION
 *  Entry function for print setting inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 IconList[] = 
    {
        IMG_GLOBAL_L1, 0,
        IMG_GLOBAL_L2, 0,
        IMG_GLOBAL_L3, 0,
        IMG_GLOBAL_L4, 0,
        IMG_GLOBAL_L5, 0,
        IMG_GLOBAL_L6, 0,
        IMG_GLOBAL_L7, 0,
        IMG_GLOBAL_L8, 0,
        IMG_GLOBAL_L9, 0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PICT_SETTINGS, mmi_pict_exit_print_settings, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PICT_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_PICT_SETTINGS, &inputBufferSize);
    SetParentHandler(0);

    mmi_pict_fill_print_settings_inline_editor();

    if (inputBuffer != NULL && IsScreenPresent(SCR_ID_PICT_SETTINGS) == 0)
    {
    #ifdef __MMI_PICT_BRIDGE_CROPPING__
        SetCategory57Data(wgui_inline_items, 16 /* 18 */, inputBuffer);
    #else
        SetCategory57Data(wgui_inline_items, 14 /* 18 */, inputBuffer);
    #endif
    }

    RegisterHighlightHandler(mmi_pict_register_print_settings_highlight_hdlr);

    ShowCategory57Screen(
        STR_ID_PICT_SETTINGS,
        mmi_pict_return_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
    #ifdef __MMI_PICT_BRIDGE_CROPPING__
        16 /* 18 */,
    #else
        14 /* 18 */,
    #endif
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_pict_edit_print_settings_done);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    DisableCategory57ScreenDone();
}


#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT57__
static U8* mmi_pict_x_coordinate_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    g_pict_bridge_setting.x_coordinate = 0;
    gui_itoa(g_pict_bridge_setting.x_coordinate, (UI_string_type) g_pict_bridge_setting.x_coordinate_display, 10);
    return g_pict_bridge_setting.x_coordinate_display;
}


static U8* mmi_pict_x_coordinate_decrease(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_coordinate == 0)
    {
        g_pict_bridge_setting.x_coordinate = g_pict_bridge_context.image_width - 1;
    }
    else
    {
        g_pict_bridge_setting.x_coordinate--;
    }

    gui_itoa(g_pict_bridge_setting.x_coordinate, (UI_string_type) g_pict_bridge_setting.x_coordinate_display, 10);
    return g_pict_bridge_setting.x_coordinate_display;
}


static U8* mmi_pict_x_coordinate_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_coordinate == g_pict_bridge_context.image_width - 1)
    {
        g_pict_bridge_setting.x_coordinate = 0;
    }
    else
    {
        g_pict_bridge_setting.x_coordinate++;
    }

    gui_itoa(g_pict_bridge_setting.x_coordinate, (UI_string_type) g_pict_bridge_setting.x_coordinate_display, 10);
    return g_pict_bridge_setting.x_coordinate_display;
}


static U8* mmi_pict_y_coordinate_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    g_pict_bridge_setting.y_coordinate = 0;
    gui_itoa(g_pict_bridge_setting.y_coordinate, (UI_string_type) g_pict_bridge_setting.y_coordinate_display, 10);
    return g_pict_bridge_setting.y_coordinate_display;
}


static U8* mmi_pict_y_coordinate_decrease(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_coordinate == 0)
    {
        g_pict_bridge_setting.y_coordinate = g_pict_bridge_context.image_height - 1;
    }
    else
    {
        g_pict_bridge_setting.y_coordinate--;
    }

    gui_itoa(g_pict_bridge_setting.y_coordinate, (UI_string_type) g_pict_bridge_setting.y_coordinate_display, 10);
    return g_pict_bridge_setting.y_coordinate_display;
}


static U8* mmi_pict_y_coordinate_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_coordinate == g_pict_bridge_context.image_height - 1)
    {
        g_pict_bridge_setting.y_coordinate = 0;
    }
    else
    {
        g_pict_bridge_setting.y_coordinate++;
    }

    gui_itoa(g_pict_bridge_setting.y_coordinate, (UI_string_type) g_pict_bridge_setting.y_coordinate_display, 10);
    return g_pict_bridge_setting.y_coordinate_display;
}


static U8* mmi_pict_x_arix_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_coordinate + g_pict_bridge_setting.x_arix > g_pict_bridge_context.image_width)
    {
        g_pict_bridge_setting.x_arix = g_pict_bridge_context.image_width - g_pict_bridge_setting.x_coordinate;
    }
    gui_itoa(g_pict_bridge_setting.x_arix, (UI_string_type) g_pict_bridge_setting.x_arix_display, 10);
    return g_pict_bridge_setting.x_arix_display;
}


static U8* mmi_pict_x_arix_decrease(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_arix > 1)
    {
        g_pict_bridge_setting.x_arix--;
    }
    else
    {
        g_pict_bridge_setting.x_arix = g_pict_bridge_context.image_width - g_pict_bridge_setting.x_coordinate;
    }
    gui_itoa(g_pict_bridge_setting.x_arix, (UI_string_type) g_pict_bridge_setting.x_arix_display, 10);
    return g_pict_bridge_setting.x_arix_display;
}


static U8* mmi_pict_x_arix_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_coordinate + g_pict_bridge_setting.x_arix < g_pict_bridge_context.image_width)
    {
        g_pict_bridge_setting.x_arix++;
    }
    else
    {
        g_pict_bridge_setting.x_arix = 1;
    }
    gui_itoa(g_pict_bridge_setting.x_arix, (UI_string_type) g_pict_bridge_setting.x_arix_display, 10);
    return g_pict_bridge_setting.x_arix_display;
}


static U8* mmi_pict_y_arix_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_coordinate + g_pict_bridge_setting.y_arix > g_pict_bridge_context.image_height)
    {
        g_pict_bridge_setting.y_arix = g_pict_bridge_context.image_height - g_pict_bridge_setting.y_coordinate;
    }
    gui_itoa(g_pict_bridge_setting.y_arix, (UI_string_type) g_pict_bridge_setting.y_arix_display, 10);
    return g_pict_bridge_setting.y_arix_display;
}


static U8* mmi_pict_y_arix_decrease(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_arix > 1)
    {
        g_pict_bridge_setting.y_arix--;
    }
    else
    {
        g_pict_bridge_setting.y_arix = g_pict_bridge_context.image_height - g_pict_bridge_setting.y_coordinate;
    }
    gui_itoa(g_pict_bridge_setting.y_arix, (UI_string_type) g_pict_bridge_setting.y_arix_display, 10);
    return g_pict_bridge_setting.y_arix_display;
}


static U8* mmi_pict_y_arix_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_coordinate + g_pict_bridge_setting.y_arix < g_pict_bridge_context.image_height)
    {
        g_pict_bridge_setting.y_arix++;
    }
    else
    {
        g_pict_bridge_setting.y_arix = 1;
    }
    gui_itoa(g_pict_bridge_setting.y_arix, (UI_string_type) g_pict_bridge_setting.y_arix_display, 10);
    return g_pict_bridge_setting.y_arix_display;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_exec_print_settings_change_callback
 * DESCRIPTION
 *  Execution function for inline editor item changed callback
 * PARAMETERS
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_image_cropping_change_callback(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
        case 1: /* x coordinate */
        case 3: /* y coordinate */
            mmi_pict_entry_image_cropping(); /* re-entry image cropping screen again to change the item selectors */
            DeleteScreenIfPresent(SCR_ID_PICT_CROPPING);
            break;

        default:
            break;
    }
}


void mmi_pict_fill_image_cropping_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(STR_ID_PICT_X_COORDINATE));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemUserDefinedSelect(
        &wgui_inline_items[1],
        mmi_pict_x_coordinate_default,
        mmi_pict_x_coordinate_decrease,
        mmi_pict_x_coordinate_increase);

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) GetString(STR_ID_PICT_Y_COORDINATE));

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemUserDefinedSelect(
        &wgui_inline_items[3],
        mmi_pict_y_coordinate_default,
        mmi_pict_y_coordinate_decrease,
        mmi_pict_y_coordinate_increase);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (PU8) GetString(STR_ID_PICT_X_ARIX));

    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemUserDefinedSelect(
        &wgui_inline_items[5],
        mmi_pict_x_arix_default,
        mmi_pict_x_arix_decrease,
        mmi_pict_x_arix_increase);

    SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[6], (PU8) GetString(STR_ID_PICT_X_ARIX));

    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemUserDefinedSelect(
        &wgui_inline_items[7],
        mmi_pict_y_arix_default,
        mmi_pict_y_arix_decrease,
        mmi_pict_y_arix_increase);

    RegisterInlineItemChangedNotification(mmi_pict_image_cropping_change_callback);
}


void mmi_pict_register_image_cropping_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_pict_entry_print_preview);
}


void mmi_pict_exit_image_cropping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_PICT_CROPPING;
    Scr.entryFuncPtr = mmi_pict_entry_image_cropping;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


void mmi_pict_entry_image_cropping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 IconList[] = 
    {
        IMG_GLOBAL_L1, 0,
        IMG_GLOBAL_L2, 0,
        IMG_GLOBAL_L3, 0,
        IMG_GLOBAL_L4, 0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PICT_CROPPING, mmi_pict_exit_image_cropping, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PICT_CROPPING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_PICT_CROPPING, &inputBufferSize);
    SetParentHandler(0);

    mmi_pict_fill_image_cropping_inline_editor();

    if (inputBuffer != NULL && IsScreenPresent(SCR_ID_PICT_CROPPING) == 0)
    {
        SetCategory57Data(wgui_inline_items, 8, inputBuffer);
        //SetInlineDoneFlag(guiBuffer);
    }

    RegisterHighlightHandler(mmi_pict_register_image_cropping_highlight_hdlr);

    ShowCategory57Screen(
        STR_ID_PICT_CROPPING,
        mmi_pict_return_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        8,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_pict_entry_print_preview);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    DisableCategory57ScreenDone();
}
#endif /* __MMI_PICT_BRIDGE_CROPPING_CAT57__ */


#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT88__
static void mmi_pict_display_x_coordinate_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_setting.x_coordinate = index;
}


static void mmi_pict_display_y_coordinate_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_setting.y_coordinate = index;
}


static void mmi_pict_display_x_arix_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_setting.x_arix = index;
}


static void mmi_pict_display_y_arix_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_setting.y_arix = index;
}


void mmi_pict_entry_image_cropping_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 lower_limit[2];
    S32 upper_limit[2];
    S32 *current_value[2];
    void (*cb_func[2]) (S32 value);
    U8 *str_list[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PICT_CROPPING_PHASE1, NULL, mmi_pict_entry_image_cropping_phase1, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_PICT_CROPPING_PHASE1);
    SetParentHandler(0);

    lower_limit[0] = 0;
    upper_limit[0] = g_pict_bridge_context.image_width - 1;
    current_value[0] = &g_pict_bridge_setting.x_coordinate;
    cb_func[0] = mmi_pict_display_x_coordinate_callback;
    str_list[0] = (U8*) GetString(STR_ID_PICT_X_COORDINATE);

    lower_limit[1] = 0;
    upper_limit[1] = g_pict_bridge_context.image_height - 1;
    current_value[1] = &g_pict_bridge_setting.y_coordinate;
    cb_func[1] = mmi_pict_display_y_coordinate_callback;
    str_list[1] = (U8*) GetString(STR_ID_PICT_Y_COORDINATE);

    ShowCategory88Screen(
        STR_ID_PICT_CROPPING,
        mmi_pict_return_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        2,
        str_list,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_pict_entry_image_cropping_phase2, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


void mmi_pict_entry_image_cropping_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 lower_limit[2];
    S32 upper_limit[2];
    S32 *current_value[2];
    void (*cb_func[2]) (S32 value);
    U8 *str_list[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PICT_CROPPING_PHASE2, NULL, mmi_pict_entry_image_cropping_phase2, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_PICT_CROPPING_PHASE2);
    SetParentHandler(0);

    lower_limit[0] = 1;
    upper_limit[0] = g_pict_bridge_context.image_width - g_pict_bridge_setting.x_coordinate;
    g_pict_bridge_setting.x_arix = g_pict_bridge_context.image_width - g_pict_bridge_setting.x_coordinate;
    current_value[0] = &g_pict_bridge_setting.x_arix;
    cb_func[0] = mmi_pict_display_x_arix_callback;
    str_list[0] = (U8*) GetString(STR_ID_PICT_X_ARIX);

    lower_limit[1] = 1;
    upper_limit[1] = g_pict_bridge_context.image_height - g_pict_bridge_setting.y_coordinate;
    g_pict_bridge_setting.y_arix = g_pict_bridge_context.image_height - g_pict_bridge_setting.y_coordinate;
    current_value[1] = &g_pict_bridge_setting.y_arix;
    cb_func[1] = mmi_pict_display_y_arix_callback;
    str_list[1] = (U8*) GetString(STR_ID_PICT_Y_ARIX);

    ShowCategory88Screen(
        STR_ID_PICT_CROPPING,
        mmi_pict_return_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        2,
        str_list,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_pict_entry_print_preview, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_PICT_BRIDGE_CROPPING_CAT88__ */

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

