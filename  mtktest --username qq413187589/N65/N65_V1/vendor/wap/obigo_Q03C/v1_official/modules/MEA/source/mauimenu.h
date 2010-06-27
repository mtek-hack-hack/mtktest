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

/*!\file mauimenu.h
 * \brief Common functions for the UI.
 */

#ifndef _MAUIMENU_H_
#define _MAUIMENU_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaNavAction
 *  Actions related to the context dependent menu */
typedef enum
{
    MEA_NAV_ACTION_OK,      /* !< The End User presses ok */
    MEA_NAV_ACTION_BACK     /* !< The End User presses back */
}MeaNavAction;


/******************************************************************************
 * Data-types
 *****************************************************************************/
typedef void (*MeaNavCallBack)(MeaNavAction actionType);
typedef MSF_BOOL (*MeaNavVisibilityCallBack)(int entryId);

/*! \struct MeaNavMenuItems
 *  \brief Holds all needed data for a navigation menu entry
 */
typedef struct {
    int             entryId;/*!< Unique id for this menu entry */
    MSF_UINT32      strId;  /*!< String to display for menu item */
    MeaStateMachine fsm;    /*!< Callback FSM */
    int             sig;    /*!< Callback signal */
    MeaNavVisibilityCallBack visibilityCallBack; /*!< Callback function used to
                                                      decide whether to show 
                                                      this menu entry */
}MeaNavMenuItem;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

void meaInitNavMenu(void);
void meaTerminateNavMenu(void);

MSF_BOOL meaCreateNavMenu(MsfStringHandle titleStrHandle, 
    MeaNavCallBack signalHandler);
int meaAddNavMenuItem(MsfStringHandle itemStrId, int contextValue);
MSF_BOOL meaAddNavMenuItemNew(const MeaNavMenuItem *navItem);
int meaGetNavMenuItem(void);
MeaNavMenuItem meaGetNavMenuItemNew(void);
#ifdef WAP_SUPPORT
MSF_BOOL meaShowMmvNavMenu(void);
void meaRemoveMmvNavMenu(void);
MSF_BOOL meaCreateMmvNavMenu(MsfStringHandle titleStrHandle, 
    MeaNavCallBack signalHandler);
MSF_BOOL meaAddMmvNavMenuItem(MsfStringHandle itemStrHandle, int contextValue);
int meaGetMmvNavMenuItem(void);

MSF_BOOL meaShowUseDetailNavMenu(void);
void meaRemoveUseDetailNavMenu(void);
MSF_BOOL meaCreateUseDetailNavMenu(MsfStringHandle titleStrHandle, 
    MeaNavCallBack signalHandler);
MSF_BOOL meaAddUseDetailNavMenuItem(MsfStringHandle itemStrHandle, int contextValue);
int meaGetUseDetailNavMenuItem(void);
  #ifdef __UNIFIED_MSG_SUPPORT__
MSF_BOOL meaAddPropNavMenuItem(MsfStringHandle itemStrHandle, int contextValue);
int meaGetPropNavMenuItem(void);
MSF_BOOL meaShowPropNavMenu(void);
void meaRemovePropNavMenu(void);
MSF_BOOL meaCreatePropNavMenu(MsfStringHandle titleStrHandle, MeaNavCallBack signalHandler);
  #endif
MsfWindowHandle meaGetNavMenuHandle(void);
#endif /*WAP_SUPPORT*/
MSF_BOOL meaShowNavMenu(void);
void meaRemoveNavMenu(void);

#endif


