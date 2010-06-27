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

/*!\file mauimenu.c
 * \brief Context sensitive menu handling.
 */

/* MSF */
#include "msf_wid.h"
#include "msf_log.h"
#include "msf_lib.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_rc.h"
#include "mea_cfg.h"
#include "mea_def.h"
#include "maintsig.h"
#include "mauicmn.h"
#include "mauimenu.h"
#include "mauisig.h"

#ifdef WAP_SUPPORT
#include "msf_dcvt.h"  /* for mms_if.h */
#include "mms_def.h"  //for mamh.h
#include "mms_cfg.h"  /* for mms_if.h */
#include "mms_if.h"  /* for mauimh.h */
#include "mamh.h"   //for MEA_MH_DELETE_MM
#include "matypes.h"  /* for mauimh.h */
#include "mauimh.h"  /* for MEA_MH_NUM_LIST_DIAL */

#include "widget_extension.h"
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Constants
 *****************************************************************************/

 /*! Maximum number of items in a context dependent menu.
 */
#define MEA_MAX_CONTEXT_LIST_ITEMS      19

/******************************************************************************
 * Data-types
 *****************************************************************************/

typedef enum
{
    MEA_NAV_MENU_TYPE_ORIGINAL,
    MEA_NAV_MENU_TYPE_NEW
}MeaNavMenuEntryType;


/*! \struct MeaNavMenu
 *  Data-structure for a context sensitive menu */
typedef struct
{
    MsfWindowHandle menuHandle;
    /*! List to keep track of which items that are presented in the list */
    MeaNavMenuEntryType type[MEA_MAX_CONTEXT_LIST_ITEMS];
    union 
    {
        int             listItems[MEA_MAX_CONTEXT_LIST_ITEMS];
        MeaNavMenuItem  listItemsNew[MEA_MAX_CONTEXT_LIST_ITEMS];
    }item;
    int             listIndex;
    /*! Destination signal */
    MeaNavCallBack  signalHandler;
}MeaNavMenu;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Global variables
 *****************************************************************************/
static MeaNavMenu        meaNavMenu;
#ifdef WAP_SUPPORT
static MeaNavMenu        meaMmvNavMenu;
static MeaNavMenu        meaUseDetailNavMenu;
  #ifdef __UNIFIED_MSG_SUPPORT__
static MeaNavMenu        meaPropNavMenu;
  #endif
#endif /*WAP_SUPPORT*/

/******************************************************************************
 * Function implementations
 *****************************************************************************/
/*!
 * \brief Initiates data structures for the navigation menu.
 *
 *****************************************************************************/
void meaInitNavMenu(void)
{
    memset(&meaNavMenu, 0, sizeof(MeaNavMenu));
#ifdef WAP_SUPPORT
    memset(&meaMmvNavMenu, 0, sizeof(MeaNavMenu));
#endif /*WAP_SUPPORT*/
}

/*!
 * \brief Deallocates all resources used by the navigation menu.
 *
 *****************************************************************************/
void meaTerminateNavMenu(void)
{
    /* Terminate just in case */
    meaRemoveNavMenu();
    /* Clear obsolete data */
    memset(&meaNavMenu, 0, sizeof(MeaNavMenu));
}

#ifdef WAP_SUPPORT
/*! \brief Handles [Ok] action for the navigation menu.
 *  \param winHandle The window that generated the action.
 *****************************************************************************/
static void handleMmvOkAction(MsfWindowHandle winHandle)
{
    if (winHandle != meaMmvNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_7B3D0F5E23FB0B76C399A918BF7616B0, "(%s) (%d) erroneous window handle in event\n", __FILE__, 
            __LINE__));
    }
    if (NULL != meaMmvNavMenu.signalHandler)
    {
        meaMmvNavMenu.signalHandler(MEA_NAV_ACTION_OK);
    }
}

/*! \brief Handles [Back] action for the navigation menu.
 *  \param winHandle The window that generated the action.
 *****************************************************************************/
static void handleMmvBackAction(MsfWindowHandle winHandle)
{
    if (winHandle != meaMmvNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_7B3D0F5E23FB0B76C399A918BF7616B0, "(%s) (%d) erroneous window handle in event\n", __FILE__, 
            __LINE__));
    }
    if (NULL != meaMmvNavMenu.signalHandler)
    {
        meaMmvNavMenu.signalHandler(MEA_NAV_ACTION_BACK);
    }
}

/*!\brief Displayes a previously created menu.
 * \return TRUE if the menu could be displayed. otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowMmvNavMenu(void)
{
    if (0 == meaMmvNavMenu.menuHandle)
    {
        return FALSE;
    }
    /* Title */
    (void)meaSetTitle(meaMmvNavMenu.menuHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_OPTIONS), 0);
    return meaDisplayWindow(meaMmvNavMenu.menuHandle, meaGetPosLeftTop());
}

void meaRemoveMmvNavMenu(void)
{
    /* Deregister window and remove actions */
    (void)meaDeleteWindow(meaMmvNavMenu.menuHandle);
    /* Delete invalid handles and list item data */
    memset(&meaMmvNavMenu, 0, sizeof(meaNavMenu));
}

/*!\brief Creates the data-structures for a context sensitive menu.
 * \param titleStrHandle The title of the menu, if 0 no title is displayed.
 * \param signalHandler The navigation callback function 
 *****************************************************************************/
MSF_BOOL meaCreateMmvNavMenu(MsfStringHandle titleStrHandle, 
    MeaNavCallBack signalHandler)
{
    MsfActionHandle actionHandle;
    if (0 != meaMmvNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_45E1234FA75EFC74E452A563800B607D, "(%s) (%d) mmv instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }

    memset(&meaMmvNavMenu, 0, sizeof(MeaNavMenu));
    /* Set destination signal converter */
    meaMmvNavMenu.signalHandler = signalHandler;
    /* Create the menu */
    actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA,
        MEA_GET_STR_ID(MEA_STR_ID_OK), MsfSelect, 0, 
        MSF_ACTION_PROPERTY_ENABLED);

    if (0 == (meaMmvNavMenu.menuHandle = MSF_WIDGET_MENU_APP_CREATE(MSF_MODID_MEA,
        actionHandle, NULL, MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
    {
        return FALSE;
    }
    /* Actions */
    /*  We couldn't register the action until we had a window handle.
     *  Now we have it so rock'n'roll. 
     */
    if (!meaRegisterAction(meaMmvNavMenu.menuHandle, actionHandle, handleMmvOkAction, 
        MEA_NOTUSED_FSM, 0))
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return FALSE;
    }
    
    if (!meaCreateAction(meaMmvNavMenu.menuHandle, MsfBack, handleMmvBackAction, 
		MEA_NOTUSED_FSM,  0, MEA_STR_ID_BACK))
    {
        return FALSE;
    }

    /* Add title only if titleStrId is valid */
    if (0 != titleStrHandle)
        (void)meaSetTitle(meaMmvNavMenu.menuHandle, titleStrHandle, 0);
    return TRUE;
}

/*!\brief Adds a item at the end of a previously created menu.
 * \param itemStrHandle The string that are displayed to the user.
 * \param contextValue A value that will be returned when meaGetNavMenuItem is
 *                    called.
 * \return TRUE if the item is generated successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaAddMmvNavMenuItem(MsfStringHandle itemStrHandle, int contextValue)
{
    ASSERT(meaMmvNavMenu.listIndex <= MEA_MAX_CONTEXT_LIST_ITEMS);
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMmvNavMenu.menuHandle, 
        meaMmvNavMenu.listIndex, itemStrHandle, 0, meaGetListNumImage(meaMmvNavMenu.listIndex), 0, TRUE))
    {
        return FALSE;
    }
    if (contextValue == MEA_MH_NUM_LIST_DIAL)
    {
        HDIa_widgetExtChoiceSetElemFlag(meaMmvNavMenu.menuHandle, 
            meaMmvNavMenu.listIndex, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);        
    }
    meaMmvNavMenu.type[meaMmvNavMenu.listIndex] = MEA_NAV_MENU_TYPE_ORIGINAL;
    meaMmvNavMenu.item.listItems[meaMmvNavMenu.listIndex] = contextValue;
    meaMmvNavMenu.listIndex++;
    return TRUE;
}

/*!\brief Returns the selected item in a menu.
 * \return The item that is currently selected or -1 if no selected item could
 *         be extracted.
 *****************************************************************************/
int meaGetMmvNavMenuItem(void)
{
    int index;
    if (0 == meaMmvNavMenu.menuHandle)
        return -1;
    index = meaGetSelectedChoiceIndex(meaMmvNavMenu.menuHandle);
    if ((index < 0) || (index >= MEA_MAX_CONTEXT_LIST_ITEMS))
        return -1;
    /*
     *	Insert code here for checking item type and returning the correct item
     */
    return meaMmvNavMenu.item.listItems[index];
}

/*! \brief Handles [Ok] action for the navigation menu.
 *  \param winHandle The window that generated the action.
 *****************************************************************************/
static void handleUseDetailOkAction(MsfWindowHandle winHandle)
{
    if (winHandle != meaUseDetailNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_7B3D0F5E23FB0B76C399A918BF7616B0, "(%s) (%d) erroneous window handle in event\n", __FILE__, 
            __LINE__));
    }
    if (NULL != meaUseDetailNavMenu.signalHandler)
    {
        meaUseDetailNavMenu.signalHandler(MEA_NAV_ACTION_OK);
    }
}

/*! \brief Handles [Back] action for the navigation menu.
 *  \param winHandle The window that generated the action.
 *****************************************************************************/
static void handleUseDetailBackAction(MsfWindowHandle winHandle)
{
    if (winHandle != meaUseDetailNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_7B3D0F5E23FB0B76C399A918BF7616B0, "(%s) (%d) erroneous window handle in event\n", __FILE__, 
            __LINE__));
    }
    if (NULL != meaUseDetailNavMenu.signalHandler)
    {
        meaUseDetailNavMenu.signalHandler(MEA_NAV_ACTION_BACK);
    }
}

/*!\brief Displayes a previously created menu.
 * \return TRUE if the menu could be displayed. otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowUseDetailNavMenu(void)
{
    if (0 == meaUseDetailNavMenu.menuHandle)
    {
        return FALSE;
    }
    /* Title */
    (void)meaSetTitle(meaUseDetailNavMenu.menuHandle, MEA_GET_STR_ID(MEA_STR_ID_OPTIONS), 0);
    return meaDisplayWindow(meaUseDetailNavMenu.menuHandle, meaGetPosLeftTop());
}

void meaRemoveUseDetailNavMenu(void)
{
    /* Deregister window and remove actions */
    (void)meaDeleteWindow(meaUseDetailNavMenu.menuHandle);
    /* Delete invalid handles and list item data */
    memset(&meaUseDetailNavMenu, 0, sizeof(MeaNavMenu));
}

/*!\brief Creates the data-structures for a context sensitive menu.
 * \param titleStrHandle The title of the menu, if 0 no title is displayed.
 * \param signalHandler The navigation callback function 
 *****************************************************************************/
MSF_BOOL meaCreateUseDetailNavMenu(MsfStringHandle titleStrHandle, 
    MeaNavCallBack signalHandler)
{
    MsfActionHandle actionHandle;
    if (0 != meaUseDetailNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_FDA8E916DEDB53A5E0DABA7D2BC25B2B, "(%s) (%d) UseDetail instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }

    memset(&meaUseDetailNavMenu, 0, sizeof(MeaNavMenu));
    /* Set destination signal converter */
    meaUseDetailNavMenu.signalHandler = signalHandler;
    /* Create the menu */
    actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA,
        MEA_GET_STR_ID(MEA_STR_ID_OK), MsfSelect, 0, 
        MSF_ACTION_PROPERTY_ENABLED);

    if (0 == (meaUseDetailNavMenu.menuHandle = MSF_WIDGET_MENU_APP_CREATE(MSF_MODID_MEA,
        actionHandle, NULL, MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
    {
        return FALSE;
    }
    /* Actions */
    /*  We couldn't register the action until we had a window handle.
     *  Now we have it so rock'n'roll. 
     */
    if (!meaRegisterAction(meaUseDetailNavMenu.menuHandle, actionHandle, handleUseDetailOkAction, 
        MEA_NOTUSED_FSM, 0))
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return FALSE;
    }
    
    if (!meaCreateAction(meaUseDetailNavMenu.menuHandle, MsfBack, handleUseDetailBackAction, 
		MEA_NOTUSED_FSM,  0, MEA_STR_ID_BACK))
    {
        return FALSE;
    }

    /* Add title only if titleStrId is valid */
    if (0 != titleStrHandle)
        (void)meaSetTitle(meaUseDetailNavMenu.menuHandle, titleStrHandle, 0);
    return TRUE;
}

/*!\brief Adds a item at the end of a previously created menu.
 * \param itemStrHandle The string that are displayed to the user.
 * \param contextValue A value that will be returned when meaGetNavMenuItem is
 *                    called.
 * \return TRUE if the item is generated successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaAddUseDetailNavMenuItem(MsfStringHandle itemStrHandle, int contextValue)
{
    ASSERT(meaUseDetailNavMenu.listIndex <= MEA_MAX_CONTEXT_LIST_ITEMS);
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaUseDetailNavMenu.menuHandle, 
        meaUseDetailNavMenu.listIndex, itemStrHandle, 0, meaGetListNumImage(meaUseDetailNavMenu.listIndex), 0, TRUE))
    {
        return FALSE;
    }
    if (contextValue == MEA_MH_NUM_LIST_DIAL)
    {
        HDIa_widgetExtChoiceSetElemFlag(meaUseDetailNavMenu.menuHandle, 
            meaUseDetailNavMenu.listIndex, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);        
    }
    meaUseDetailNavMenu.type[meaUseDetailNavMenu.listIndex] = MEA_NAV_MENU_TYPE_ORIGINAL;
    meaUseDetailNavMenu.item.listItems[meaUseDetailNavMenu.listIndex] = contextValue;
    meaUseDetailNavMenu.listIndex++;
    return TRUE;
}

/*!\brief Returns the selected item in a menu.
 * \return The item that is currently selected or -1 if no selected item could
 *         be extracted.
 *****************************************************************************/
int meaGetUseDetailNavMenuItem(void)
{
    int index;
    if (0 == meaUseDetailNavMenu.menuHandle)
        return -1;
    index = meaGetSelectedChoiceIndex(meaUseDetailNavMenu.menuHandle);
    if ((index < 0) || (index >= MEA_MAX_CONTEXT_LIST_ITEMS))
        return -1;
    /*
     *	Insert code here for checking item type and returning the correct item
     */
    return meaUseDetailNavMenu.item.listItems[index];
}

  #ifdef __UNIFIED_MSG_SUPPORT__
/*!\brief Adds a item at the end of a previously created menu.
* \param itemStrHandle The string that are displayed to the user.
* \param contextValue A value that will be returned when meaGetNavMenuItem is
*                    called.
* \return TRUE if the item is generated successfully, otherwise FALSE.
*****************************************************************************/
MSF_BOOL meaAddPropNavMenuItem(MsfStringHandle itemStrHandle, int contextValue)
{
    if (meaPropNavMenu.listIndex >= MEA_MAX_CONTEXT_LIST_ITEMS)
    {
        return FALSE;
    }
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaPropNavMenu.menuHandle, 
        meaPropNavMenu.listIndex, itemStrHandle, 0, meaGetListNumImage(meaPropNavMenu.listIndex), 0, TRUE))
    {
        return FALSE;
    }
    if (contextValue == MEA_MH_NUM_LIST_DIAL)
    {
        HDIa_widgetExtChoiceSetElemFlag(meaPropNavMenu.menuHandle, 
            meaPropNavMenu.listIndex, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);        
    }
    meaPropNavMenu.type[meaPropNavMenu.listIndex] = MEA_NAV_MENU_TYPE_ORIGINAL;
    meaPropNavMenu.item.listItems[meaPropNavMenu.listIndex] = contextValue;
    meaPropNavMenu.listIndex++;
    return TRUE;
}
  


/*!\brief Returns the selected item in a menu.
* \return The item that is currently selected or -1 if no selected item could
*         be extracted.
*****************************************************************************/
int meaGetPropNavMenuItem(void)
{
    int index;
    if (0 == meaPropNavMenu.menuHandle)
        return -1;
    index = meaGetSelectedChoiceIndex(meaPropNavMenu.menuHandle);
    if ((index < 0) || (index >= MEA_MAX_CONTEXT_LIST_ITEMS))
        return -1;
    
    /* Insert code here for checking item type and returning the correct item */
    return meaPropNavMenu.item.listItems[index];
}

/*! \brief Handles [Ok] action for the navigation menu.
 *  \param winHandle The window that generated the action.
 *****************************************************************************/
static void handlePropNavOkAction(MsfWindowHandle winHandle)
{
    if (winHandle != meaPropNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_7B3D0F5E23FB0B76C399A918BF7616B0, "(%s) (%d) erroneous window handle in event\n", __FILE__, 
            __LINE__));
    }
    if (NULL != meaPropNavMenu.signalHandler)
    {
        meaPropNavMenu.signalHandler(MEA_NAV_ACTION_OK);
    }
}

/*! \brief Handles [Back] action for the navigation menu.
 *  \param winHandle The window that generated the action.
 *****************************************************************************/
static void handlePropNavBackAction(MsfWindowHandle winHandle)
{
    if (winHandle != meaPropNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_7B3D0F5E23FB0B76C399A918BF7616B0, "(%s) (%d) erroneous window handle in event\n", __FILE__, 
            __LINE__));
    }
    if (NULL != meaPropNavMenu.signalHandler)
    {
        meaPropNavMenu.signalHandler(MEA_NAV_ACTION_BACK);
    }
}

/*!\brief Displayes a previously created menu.
 * \return TRUE if the menu could be displayed. otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowPropNavMenu(void)
{
    if (0 == meaPropNavMenu.menuHandle)
    {
        return FALSE;
    }
    /* Title */
    (void)meaSetTitle(meaPropNavMenu.menuHandle, MEA_GET_STR_ID(MEA_STR_ID_OPTIONS), 0);
    return meaDisplayWindow(meaPropNavMenu.menuHandle, meaGetPosLeftTop());
}

void meaRemovePropNavMenu(void)
{
    /* Deregister window and remove actions */
    (void)meaDeleteWindow(meaPropNavMenu.menuHandle);
    /* Delete invalid handles and list item data */
    memset(&meaPropNavMenu, 0, sizeof(MeaNavMenu));
}

/*!\brief Creates the data-structures for a context sensitive menu.
 * \param titleStrHandle The title of the menu, if 0 no title is displayed.
 * \param signalHandler The navigation callback function 
 *****************************************************************************/
MSF_BOOL meaCreatePropNavMenu(MsfStringHandle titleStrHandle, 
    MeaNavCallBack signalHandler)
{
    MsfActionHandle actionHandle;
    if (0 != meaPropNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_5E48FA177935EE2D8C019A48BE88342E, "(%s) (%d) Property instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }

    memset(&meaPropNavMenu, 0, sizeof(MeaNavMenu));
    /* Set destination signal converter */
    meaPropNavMenu.signalHandler = signalHandler;
    /* Create the menu */
    actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA,
        MEA_GET_STR_ID(MEA_STR_ID_OK), MsfSelect, 0, 
        MSF_ACTION_PROPERTY_ENABLED);

    if (0 == (meaPropNavMenu.menuHandle = MSF_WIDGET_MENU_APP_CREATE(MSF_MODID_MEA,
        actionHandle, NULL, MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
    {
        return FALSE;
    }
    /* Actions */
    /*  We couldn't register the action until we had a window handle.
     *  Now we have it so rock'n'roll. 
     */
    if (!meaRegisterAction(meaPropNavMenu.menuHandle, actionHandle, handlePropNavOkAction, 
        MEA_NOTUSED_FSM, 0))
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return FALSE;
    }
    
    if (!meaCreateAction(meaPropNavMenu.menuHandle, MsfBack, handlePropNavBackAction, 
		MEA_NOTUSED_FSM,  0, MEA_STR_ID_BACK))
    {
        return FALSE;
    }

    /* Add title only if titleStrId is valid */
    if (0 != titleStrHandle)
        (void)meaSetTitle(meaPropNavMenu.menuHandle, titleStrHandle, 0);
    return TRUE;
}
  #endif
    
MsfWindowHandle meaGetNavMenuHandle(void)
{
    return meaNavMenu.menuHandle;
}
#endif /*WAP_SUPPORT*/

/*! \brief Handles [Ok] action for the navigation menu.
 *
 *  \param winHandle The window that generated the action.
 *****************************************************************************/
static void handleOkAction(MsfWindowHandle winHandle)
{
    if (winHandle != meaNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_7B3D0F5E23FB0B76C399A918BF7616B0, "(%s) (%d) erroneous window handle in event\n", __FILE__, 
            __LINE__));
    }
    if (NULL != meaNavMenu.signalHandler)
    {
        meaNavMenu.signalHandler(MEA_NAV_ACTION_OK);
    }
}

/*! \brief Handles [Back] action for the navigation menu.
 *
 *  \param winHandle The window that generated the action.
 *****************************************************************************/
static void handleBackAction(MsfWindowHandle winHandle)
{
    if (winHandle != meaNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_7B3D0F5E23FB0B76C399A918BF7616B0, "(%s) (%d) erroneous window handle in event\n", __FILE__, 
            __LINE__));
    }
    if (NULL != meaNavMenu.signalHandler)
    {
        meaNavMenu.signalHandler(MEA_NAV_ACTION_BACK);
    }
}

/*!\brief Creates the data-structures for a context sensitive menu.
 *
 * \param titleStrHandle The title of the menu, if 0 no title is displayed.
 * \param signalHandler The navigation callback function 
 *****************************************************************************/
MSF_BOOL meaCreateNavMenu(MsfStringHandle titleStrHandle, 
    MeaNavCallBack signalHandler)
{
    MsfActionHandle actionHandle;
    if (0 != meaNavMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMENU_B308D4280296A2DC7B04F7DE3E738342, "(%s) (%d) instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }

    memset(&meaNavMenu, 0, sizeof(MeaNavMenu));
    /* Set destination signal converter */
    meaNavMenu.signalHandler = signalHandler;
    /* Create the menu */
    actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA,
        MEA_GET_STR_ID(MEA_STR_ID_OK), MsfSelect, 0, 
        MSF_ACTION_PROPERTY_ENABLED);

    if (0 == (meaNavMenu.menuHandle = MSF_WIDGET_MENU_APP_CREATE(MSF_MODID_MEA,
        actionHandle, NULL, MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
    {
        return FALSE;
    }
    /* Actions */

    /*  We couldn't register the action until we had a window handle.
     *  Now we have it so rock'n'roll. 
     */
    if (!meaRegisterAction(meaNavMenu.menuHandle, actionHandle, handleOkAction, 
        0, 0))
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return FALSE;
    }
    
    if (!meaCreateAction(meaNavMenu.menuHandle, MsfBack, handleBackAction, 0, 
        0, MEA_STR_ID_BACK))
    {
        return FALSE;
    }

    /* Add title only if titleStrId is valid */
    if (0 != titleStrHandle)
    {
        (void)meaSetTitle(meaNavMenu.menuHandle, titleStrHandle, 0);
    }

    return TRUE;
}

/*!\brief Adds a item at the end of a previously created menu.
 *
 * \param itemStrHandle The string that are displayed to the user.
 * \param contextValue A value that will be returned when meaGetNavMenuItem is
 *                    called.
 * \return TRUE if the item is generated successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaAddNavMenuItem(MsfStringHandle itemStrHandle, int contextValue)
{
    ASSERT(meaNavMenu.listIndex <= MEA_MAX_CONTEXT_LIST_ITEMS);
#ifdef WAP_SUPPORT
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaNavMenu.menuHandle, 
        meaNavMenu.listIndex, itemStrHandle, 0, meaGetListNumImage(meaNavMenu.listIndex), 0, TRUE))
#else
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaNavMenu.menuHandle, 
        meaNavMenu.listIndex, itemStrHandle, 0, 0, 0, TRUE))
#endif /*WAP_SUPPORT*/
    {
        return FALSE;
    }
#ifdef WAP_SUPPORT
    if(itemStrHandle == MEA_GET_STR_ID(MEA_STR_ID_SEND) )
    {
        HDIa_widgetExtChoiceSetElemFlag(meaNavMenu.menuHandle, 
            meaNavMenu.listIndex, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);        
    }
#endif /* WAP_SUPPORT */
    meaNavMenu.type[meaNavMenu.listIndex] = MEA_NAV_MENU_TYPE_ORIGINAL;
    meaNavMenu.item.listItems[meaNavMenu.listIndex] = contextValue;
    meaNavMenu.listIndex++;
    return TRUE;
}

/*!\brief Adds a item at the end of a previously created menu, extended version
 *
 * \param navItem All data for the menu item to be created
 * \return TRUE if the item is generated successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaAddNavMenuItemNew(const MeaNavMenuItem *navItem)
{
    ASSERT(meaNavMenu.listIndex <= MEA_MAX_CONTEXT_LIST_ITEMS);
    if ((NULL != navItem->visibilityCallBack) &&
        (FALSE == (navItem->visibilityCallBack)(navItem->entryId)))
    {
        return TRUE;
    } /* if */

#ifdef WAP_SUPPORT
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaNavMenu.menuHandle, 
        meaNavMenu.listIndex, MEA_GET_STR_ID(navItem->strId), 0, meaGetListNumImage(meaNavMenu.listIndex), 0, TRUE))
#else
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaNavMenu.menuHandle, 
        meaNavMenu.listIndex, MEA_GET_STR_ID(navItem->strId), 0, 0, 0, TRUE))
#endif /*WAP_SUPPORT*/
    {
        return FALSE;
    }
#ifdef WAP_SUPPORT
    if (navItem->strId != MEA_STR_ID_SEND_OPTIONS) //Only Send Option can use right arrow key
    {
        HDIa_widgetExtChoiceSetElemFlag(meaNavMenu.menuHandle, 
            meaNavMenu.listIndex, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
    }
#endif /* WAP_SUPPORT */
    meaNavMenu.type[meaNavMenu.listIndex] = MEA_NAV_MENU_TYPE_NEW;
    meaNavMenu.item.listItemsNew[meaNavMenu.listIndex] = *navItem;
    meaNavMenu.listIndex++;
    return TRUE;
}

/*!\brief Returns the selected item in a menu.
 *
 * \return The item that is currently selected or -1 if no selected item could
 *         be extracted.
 *****************************************************************************/
int meaGetNavMenuItem()
{
    int index;
    if (0 == meaNavMenu.menuHandle)
    {
        return -1;
    }
    index = meaGetSelectedChoiceIndex(meaNavMenu.menuHandle);
    if ((index < 0) || (index >= MEA_MAX_CONTEXT_LIST_ITEMS))
    {
        return -1;
    }
    /*
     *	Insert code here for checking item type and returning the correct item
     */
    return meaNavMenu.item.listItems[index];
}

/*!
 * \brief   Returns the selected item in a menu - with extended information.
 *          meaAddNavMenuItemNew() must've been used instead of 
 *          meaAddNavMenuItem()!
 * 
 * \return  The item that is currently selected or {0,0,0,0} if no selected 
 *          item could be extracted.
 *****************************************************************************/
MeaNavMenuItem meaGetNavMenuItemNew(void)
{
    MeaNavMenuItem error = {0};
    int index;

    if (0 == meaNavMenu.menuHandle)
    {
        return error;
    }
    index = meaGetSelectedChoiceIndex(meaNavMenu.menuHandle);
    if ((index < 0) || (index >= MEA_MAX_CONTEXT_LIST_ITEMS))
    {
        return error;
    }
    return meaNavMenu.item.listItemsNew[index];
} /* meaGetNavMenuItemNew */

/*!\brief Displayes a previously created menu.
 *
 * \return TRUE if the menu could be displayed. otherwise FALSE.
 *
 *****************************************************************************/
MSF_BOOL meaShowNavMenu()
{
    if (0 == meaNavMenu.menuHandle)
    {
        return FALSE;
    }
#ifdef WAP_SUPPORT	
    /* Title */
    (void)meaSetTitle(meaNavMenu.menuHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_OPTIONS), 0);
#endif /*WAP_SUPPORT*/
    return meaDisplayWindow(meaNavMenu.menuHandle, meaGetPosLeftTop());
}

/*!\brief Removes a previously created navigation menu.
 *
 *****************************************************************************/
void meaRemoveNavMenu()
{
    /* Deregister window and remove actions */
    (void)meaDeleteWindow(meaNavMenu.menuHandle);
    /* Delete invalid handles and list item data */
    memset(&meaNavMenu, 0, sizeof(meaNavMenu));
}


