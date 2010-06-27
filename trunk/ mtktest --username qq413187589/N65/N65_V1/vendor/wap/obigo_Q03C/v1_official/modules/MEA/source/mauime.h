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

/*!\file mauime.h
 * \brief Definitions for the message editor UI.
 */

#ifndef _MAUIME_H_
#define _MAUIME_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/* !\enum MeaMeAddrListMenuItem
 */
#ifdef WAP_SUPPORT
typedef enum
{
    MEA_ME_ADDR_LIST_ADD_NUMBER,
    MEA_ME_ADDR_LIST_ADD_EMAIL,
    MEA_ME_ADDR_LIST_EDIT,
    MEA_ME_ADDR_LIST_DELETE,
    MEA_ME_ADDR_LIST_DELETE_ALL
}MeaMeAddrListMenuItem;
#else
typedef enum
{
    MEA_ME_ADDR_LIST_DELETE,
    MEA_ME_ADDR_LIST_BACK
}MeaMeAddrListMenuItem;
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Prototypes
 *****************************************************************************/

MSF_BOOL meaMeCreatePropView(MeaPropItem *propItem, 
    MeaMeStartupMode mode);
void     meaMeDeletePropView(void);
MSF_BOOL meaMeSetPropertyValues(const MeaPropItem *propItem);
void     meaMeUiInit(void);

MSF_BOOL meaMeCreateNavMenu(MeaNavMenuItem *items);
void     meaMeDeleteNavMenu(void);
char     *meaMeGetMessageText(void);

MSF_BOOL meaMeCreateAddrInputView(MeaMeProperty type, const MeaAddrItem *items, 
    unsigned int editIndex);
void     meaMeDeleteAddrInputView(void);

MSF_BOOL meaMeCreateAddrListView(MeaMeProperty type, MeaAddrItem *items);
#ifdef WAP_SUPPORT
MSF_BOOL meaMeUpdateAddrListViewForAdd(const MeaAddrItem *items);
MSF_BOOL meaMeUpdateAddrListViewForEdit(const MeaAddrItem *items, unsigned int ind);
void meaMeAddAddrList(MeaAddrType type, char* name, char *addr);
MSF_BOOL meaMeUpdateEditContent(MeaSmilInfo *smilInfo, MeaPropItem *propItem, MeaMeStartupMode mode);
#endif /* WAP_SUPPORT */
void     meaMeDeleteAddrListView(void);
MSF_BOOL meaMeUpdateAddrListView(const MeaAddrItem *items);

MSF_BOOL meaMeCreateAddrListMenu(void);
void     meaMeDeleteAddrListMenu(void);
MSF_BOOL meaUiMeIsPropertyViewActive(void);
MSF_BOOL meaMeGetNumberValidFlag(void);
#endif


