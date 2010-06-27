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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/* MSF */
#include "msf_wid.h"
#include "msf_log.h"
#include "msf_lib.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"
#include "sls_def.h"

/* SMA */
#include "sma_rc.h"
#include "sma_cfg.h"
#include "sma_def.h"
#include "sauisig.h"
#include "satypes.h"
#include "saui.h"
#include "samenu.h"
#ifdef WAP_SUPPORT
extern MSF_BOOL meaSmilEditorIsActive(void);
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Data-types
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void removeMenuItems(const SmaMenu *smaMenu);

/******************************************************************************
 * Global variables
 *****************************************************************************/

/******************************************************************************
 * Function implementations
 *****************************************************************************/
#ifdef WAP_SUPPORT
MsfImageHandle smaGetListNumImage(int i)
{
   i++;
   switch(i)
   {
   case 1:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB1,0);
   case 2:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB2,0);
   case 3:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB3,0);
   case 4:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB4,0);
   case 5:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB5,0);
   case 6:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB6,0);
   case 7:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB7,0);
   case 8:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB8,0);
   case 9:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB9,0);
   case 10:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB10,0);
   case 11:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB11,0);
   case 12:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB12,0);
   case 13:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB13,0);
   case 14:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB14,0);
   case 15:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB15,0);
   case 16:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB16,0);
   case 17:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB17,0);
   case 18:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB18,0);
   case 19:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB19,0);
   case 20:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB20,0);
   default:
     return 0;
   }
}
#endif /* WAP_SUPPORT */

/*!\brief Creates the data-structures for a context sensitive menu.
 *
 * \param menu The SmaMenu
 * \param type Type of menu.
 * \param titleStrHandle The title of the menu, if 0 no title is displayed.
 * \param okActionStrHandle String to show for OK button
 * \param okActionCallBack Callback function for ok action.
 * \return TRUE on success else false
 *****************************************************************************/
MSF_BOOL smaCreateMenu(SmaMenu *menu, SmaMenuType type, 
	MsfStringHandle titleStrHandle, MsfStringHandle okActionStrHandle,
	SmaActionCallBack okActionCallBack)
{
	MsfActionHandle selectAction;
	if (menu->menuHandle != 0)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
            SAMENU_B308D4280296A2DC7B04F7DE3E738342, "(%s) (%d) instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    } /* if */

    memset(menu, 0, sizeof(SmaMenu));

	selectAction = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, okActionStrHandle,
		MsfSelect, 0, MSF_ACTION_PROPERTY_ENABLED);
    if (0 == selectAction)
    {
        return FALSE;
    } /* if */

	/* Create the menu */
	if ( SMA_NAV_MENU == type)
	{
	    menu->menuHandle = MSF_WIDGET_MENU_APP_CREATE(MSF_MODID_SMA, 
		    selectAction, NULL, MSF_CHOICE_ELEMENT_STRING_1, 0, 0);
	}
	else
	{
		menu->menuHandle  = MSF_WIDGET_MENU_CREATE(MSF_MODID_SMA, 
			MsfImplicitChoice, NULL, selectAction, NULL, 
			MSF_CHOICE_ELEMENT_STRING_1, 0, 0);
	} /* if */

    if (0 == menu->menuHandle)
    {
        return FALSE;
    } /* if */

#ifdef WAP_SUPPORT
    if (!meaSmilEditorIsActive())
#endif /* WAP_SUPPORT */
	if (!smaRegisterAction(menu->menuHandle, selectAction, 
		okActionCallBack, 0, 0))
    {
        return FALSE;
    } /* if */

    /* Add title only if titleStrId is valid */
    if (0 != titleStrHandle)
    {
        (void)MSF_WIDGET_SET_TITLE(menu->menuHandle, 
            titleStrHandle);
        (void)MSF_WIDGET_WINDOW_SET_PROPERTIES(menu->menuHandle, 
            MSF_WINDOW_PROPERTY_TITLE);
    } /* if */
    return TRUE;
} /* smaCreateMenu */

  
/*!\brief Adds a item at the end of a previously created menu.
 *
 * \param itemStrHandle The string that are displayed to the user.
 * \param conextValue A value that will be returned when smaGetMenuItem is
 *                    called.
 * \return TRUE if the item is generated successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaAddMenuItem(SmaMenu *menu, MsfStringHandle itemStrHandle, 
	MSF_INT32 contextValue)
{
    if (menu->listIndex >= SMA_MAX_CONTEXT_LIST_ITEMS)
        return FALSE;
#ifdef WAP_SUPPORT
    if (-1 == MSF_WIDGET_CHOICE_SET_ELEMENT(menu->menuHandle, 
        menu->listIndex, itemStrHandle, SMA_GET_STR_ID(SMA_STR_ID_EMPTY_STRING), 
        smaGetListNumImage(menu->listIndex), 0, TRUE))
#else
    if (-1 == MSF_WIDGET_CHOICE_SET_ELEMENT(menu->menuHandle, 
        menu->listIndex, itemStrHandle, 
        SMA_GET_STR_ID(SMA_STR_ID_EMPTY_STRING), 0, 0, TRUE))
#endif /* WAP_SUPPORT */
        return FALSE;
    menu->listItems[menu->listIndex] = contextValue;
    menu->listIndex++;
    return TRUE;
} /* smaAddMenuItem */

void smaMenuSetFocus(const SmaMenu *menu)
{
	(void)MSF_WIDGET_SET_IN_FOCUS(menu->menuHandle, TRUE);
} /* smaMenuSetFocus */

/*!\brief Set a menu item as selected
 *
 * \param menu the menu to work with.
 * \param selection the number of the item to set as selected
 *****************************************************************************/
void smaMenuSetSelected(const SmaMenu *menu, MSF_UINT32 selection)
{
	if ( menu == NULL)
	{
		return;
	} /* if */
	
	/* nothing to do if set selected failes */
	(void)MSF_WIDGET_CHOICE_SET_ELEM_STATE(menu->menuHandle, (int)selection, 
		MSF_CHOICE_ELEMENT_SELECTED);
} /* smaMenuSetSelected */
  

/*!\brief Returns the selected item in a menu.
 *
 * \return The item that is currently selected or -1 if no selected item could
 *         be extracted.
 *****************************************************************************/
MSF_INT32 smaGetMenuItem(const SmaMenu *menu)
{
    int index;

    if (0 == menu->menuHandle)
	{
        return -1;
    } /* if */
	index = smaGetSelectedChoiceIndex(menu->menuHandle);
    if ((index < 0) || (index >= SMA_MAX_CONTEXT_LIST_ITEMS))
	{
        return -1;
	} /* if */
    return menu->listItems[index];
} /* smaGetMenuItem */


/*!\brief Returns the number of selected item in a menu.
 *
 * \return The number of the item that is currently selected or -1 if 
 *		no selected item could be extracted.
 *****************************************************************************/
MSF_INT32 smaGetMenuItemIndex(const SmaMenu *menu)
{
    MSF_INT32 index;

    if (0 == menu->menuHandle)
	{
        return -1;
	} /* if */
    index = smaGetSelectedChoiceIndex(menu->menuHandle);
    if ((index < 0) || (index >= SMA_MAX_CONTEXT_LIST_ITEMS))
	{
        return -1;
	} /* if */
	return index;
} /* smaGetMenuItem */


/*!\brief Displayes a previously created menu.
 *
 * \param the menu to show
 * \return TRUE if the menu could be displayed. otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaShowMenu(const MsfWindowHandle menuHandle)
{
	if (0 == menuHandle)
        return FALSE;
    return smaBindAndShowWindow(menuHandle, smaGetPosLeftTop());
} /* smaShowMenu */

/*!\brief Removes a previously created menu.
 *
 * \param the menu to remove
 *****************************************************************************/
void smaRemoveMenu(SmaMenu *menu)
{
	removeMenuItems(menu);
	(void)smaDeleteWindow(menu->menuHandle);
    /* Delete invalid handles and list item data */
    memset(menu, 0x00, sizeof(menu));
} /* smaRemoveMenu */

/*!\brief Removes all elements from a menu.
 *
 *\param smaMenu The menu to remove elements from
 *****************************************************************************/
static void removeMenuItems(const SmaMenu *menu)
{
	/* Remove Widgets */
    if (0 != menu->menuHandle)
    {
        /* Remove elements */
        while(MSF_WIDGET_CHOICE_SIZE(menu->menuHandle) > 0)
        {
            (void)MSF_WIDGET_CHOICE_REMOVE_ELEMENT(menu->menuHandle, 0);
        } /* while */
    } /* if */
} /* removeMenuItems */


