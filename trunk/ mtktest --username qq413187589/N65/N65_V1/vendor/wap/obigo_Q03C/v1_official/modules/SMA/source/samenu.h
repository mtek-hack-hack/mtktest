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

#ifndef _SAMENU_H_
#define _SAMENU_H_

#ifndef _msf_wid_h
#error msf_wid.h needs to be included berfore samenu.h!
#endif

#ifndef _SMA_CFG_H
#error sma_cfg.h needs to be included berfore samenu.h!
#endif

#ifndef _SAUISIG_H_
#error sausig.h needs to be included berfore samenu.h!
#endif



/******************************************************************************
 * Constants
 *****************************************************************************/

/* Data-structure for a context sensitive menu */
typedef struct
{
    MsfWindowHandle menuHandle;
    /* List to keep track of which items that are presented in the list */
    MSF_INT32 listItems[SMA_MAX_CONTEXT_LIST_ITEMS];
    MSF_INT32 listIndex;
    /* Destination signal */
}SmaMenu;

typedef enum
{
	SMA_NAV_MENU,		/* Navigation menu */
	SMA_LIST_MENU		/* Data list menu */
} SmaMenuType;


/******************************************************************************
 * Prototypes
 *****************************************************************************/
#ifdef WAP_SUPPORT
MsfImageHandle smaGetListNumImage(int i);
#endif /* WAP_SUPPORT*/
MSF_BOOL smaCreateMenu(SmaMenu *menu, SmaMenuType type, 
	MsfStringHandle titleStrHandle, MsfStringHandle okActionStrHandle,
	SmaActionCallBack okActionCallBack);
MSF_BOOL smaAddMenuItem(SmaMenu *menu, MsfStringHandle itemStrHandle, 	
	MSF_INT32 contextValue);
MSF_INT32 smaGetMenuItem(const SmaMenu *menu);
MSF_BOOL smaShowMenu(const MsfWindowHandle menuHandle);
void smaRemoveMenu(SmaMenu *menu);
MSF_BOOL smaGetContextMenuItem(SmaMenu *menu, MsfWindowHandle menuHandle, 
	const int *contextItems, int maxItems);
MSF_BOOL smaCreateContextMenuItem(SmaMenu *menu, MsfWindowHandle menuHandle, 
	unsigned int strId, int *contextItems, int itemValue, int index);
MSF_BOOL smaMenuCreateDestSig(SmaMenu *menu, MsfWindowHandle windowHandle, 
	MsfActionHandle actionHandle);
void smaMenuSetSelected(const SmaMenu *menu, MSF_UINT32 selection);
MSF_INT32 smaGetMenuItemIndex(const SmaMenu *menu);
void smaMenuSetFocus(const SmaMenu *menu);
#endif /* _SAMENU_H_ */


