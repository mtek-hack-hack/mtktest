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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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
 ******************************************************************************
 *
 * File:            $Workfile:   sauilnk.c  $
 *
 * Date:            $Date:   May 17 2005 03:06:30  $
 *
 * Revision:        $Revision:   1.6  $
 *
 * Description:     Handling of displaying a list of links.
 *
 *****************************************************************************/

/*!\file sauilnk.c
 */

/* MSF */
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_cfg.h"
#include "msf_def.h"
#include "msf_lib.h"
#include "msf_log.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"
#include "sls_def.h"

/* MEA*/
#include "sma_rc.h"
#include "sma_def.h"
#include "satypes.h"
#include "salnk.h"
#include "sauilnk.h"
#include "saui.h"

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*!\struct SmaMvLinksMenu
 */
typedef struct
{
    MsfWindowHandle menuHandle;     /*!< The menu handle */
    MsfActionHandle okAction;       /*!< Ok action handle  */
    MsfActionHandle backAction;     /*!< Back action handle  */
    SmaLinkItem *links;             /*!< A list of links */
}SmaLinkMenu;

/******************************************************************************
 * Static data-structures
 *****************************************************************************/
static SmaLinkMenu   smaLinkMenu;

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Initiates the data-structures for the message viewer.
 *****************************************************************************/
void smaInitLinkMenu(void)
{
    /* Init widget data-structures */
    memset(&smaLinkMenu, 0, sizeof(smaLinkMenu));
}

/*!
 * \brief Handles actions for the links menu.
 *
 * \param winHandle The window handle.
 * \param actionHandle
 * \return
 *****************************************************************************/
MSF_BOOL smaLinkMenuHandleActions(MsfWindowHandle winHandle, 
    MsfActionHandle actionHandle)
{
    int index;
    int i;
    SmaLinkItem *links;
    if (winHandle == smaLinkMenu.menuHandle)
    {
        if (actionHandle == smaLinkMenu.okAction)
        {
            if (0 <= (index = widgetGetSelected(winHandle)))
            {
                for(i = 0, links = smaLinkMenu.links; (links != NULL) && 
                    (i != index); i++, links = links->next)
                    ;
                /* Start the BRA */
                if (NULL != links)
                {
                    smaStartBra(links->url);
                }
            }
            return TRUE;
        }
        if (actionHandle == smaLinkMenu.backAction)
        {
            smaDeleteLinkMenu();
            return TRUE;
        }

    }
    return FALSE;
}

/*!
 * \brief Display a list of links
 *
 * \param links A list of links to display.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaCreateLinkMenu(SmaLinkItem *links)
{
    MsfStringHandle strHandle;
    MsfPosition pos = {0, 0};
    int index;
    /* Verify input data */
    if (NULL == links)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
            SAUILNK_70C754D5FEEBCD594A7850F125E77FC6, "(%s) (%d) No links to display!\n", __FILE__, __LINE__));
        return FALSE;
    }
    memset(&smaLinkMenu, 0, sizeof(smaLinkMenu));
    smaLinkMenu.links = links;

    /* Create actions */
    /* Accept action */
    if (0 == (smaLinkMenu.okAction = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
        SMA_GET_STR_ID(SMA_STR_ID_OK), MsfSelect, 0, 
        MSF_ACTION_PROPERTY_ENABLED)))
    {
        return FALSE;
    }
	
    if (0 == (smaLinkMenu.menuHandle = MSF_WIDGET_MENU_CREATE(
        MSF_MODID_SMA, MsfImplicitChoice, NULL, smaLinkMenu.okAction, NULL, 
        MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
    {
        return FALSE;
    }

    /* Actions */
    if (0 == (smaLinkMenu.backAction = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA,
        SMA_GET_STR_ID(SMA_STR_ID_BACK), MsfBack, 0, 0)))
    {
        return FALSE;
    }
    if (0 > MSF_WIDGET_ADD_ACTION(smaLinkMenu.menuHandle, 
        smaLinkMenu.backAction))
    {
        return FALSE;
    }
    /* Create Handles */
    index = 0;
    while(NULL != links)
    {
        if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, 
            links->url, MsfUtf8, (int)(strlen(links->url) + 1), 0)))
        {
            (void)MSF_WIDGET_RELEASE(strHandle);
            return FALSE;
        }
        if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(smaLinkMenu.menuHandle, 
            index, strHandle, 0, 0, 0, TRUE))
        {
            (void)MSF_WIDGET_RELEASE(strHandle);
            return FALSE;
        }
        links = links->next;
        index++;
    }
    /* Window properties */
    (void)MSF_WIDGET_SET_TITLE(smaLinkMenu.menuHandle, 
        SMA_GET_STR_ID(SMA_STR_ID_LINKS));
    (void)MSF_WIDGET_WINDOW_SET_PROPERTIES(smaLinkMenu.menuHandle, 
        MSF_WINDOW_PROPERTY_TITLE);

    /* Bind menu to the screen and activate */
    if (0 < MSF_WIDGET_SCREEN_ADD_WINDOW(smaGetScreenHandle(), 
        smaLinkMenu.menuHandle, &pos, 0, 0))
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(smaGetScreenHandle(), TRUE);
        (void)MSF_WIDGET_SET_IN_FOCUS(smaLinkMenu.menuHandle, TRUE);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*! 
 * \brief De-allocates the GUI for the link viewer.
 *
 *****************************************************************************/
void smaDeleteLinkMenu(void)
{
    if (0 != smaLinkMenu.menuHandle)
    {
        /* Remove the menu */
        if (0 != smaLinkMenu.menuHandle)
        {
            (void)MSF_WIDGET_REMOVE(smaGetScreenHandle(), smaLinkMenu.menuHandle);
            (void)MSF_WIDGET_RELEASE(smaLinkMenu.menuHandle);
        }
        /* Remove actions */
        if (0 != smaLinkMenu.okAction)
        {
            (void)MSF_WIDGET_RELEASE(smaLinkMenu.okAction);
        }
        if (0 != smaLinkMenu.backAction)
        {
            (void)MSF_WIDGET_RELEASE(smaLinkMenu.backAction);
        }
        memset(&smaLinkMenu, 0, sizeof(SmaLinkMenu));
    }
}

/*!
 * \brief Terminates the link menu.
 *****************************************************************************/
void smaTerminateLinkMenu(void)
{
    smaDeleteLinkMenu();
}


