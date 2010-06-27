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
 * MobileServiceResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is defines enum values of Mobile Service applications.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMI_MOBILE_SERVICE_RES_H_
#define _MMI_MOBILE_SERVICE_RES_H_

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_MOBILE_SERVICE__

#include "MMIDataType.h"

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    SCR_ID_OPTRSER_LIST = MOBILE_SERVICE_BASE + 1,
    SCR_ID_OPTRSER_PIM_INTRO,
    SCR_ID_OPTRSER_PIM_LIST,
    SCR_ID_OPTRSER_END
} SCREENID_LIST_MOBILE_SERVICE;

typedef enum
{
    STR_ID_OPTRSER_TITLE = MOBILE_SERVICE_BASE + 1,
#ifdef WAP_SUPPORT
    STR_ID_OPTRSER_MUSIC,
    STR_ID_OPTRSER_GAME,
    STR_ID_OPTRSER_WEATHER,
    STR_ID_OPTRSER_FETION,
    STR_ID_OPTRSER_VIDEO,
    STR_ID_OPTRSER_NEW,
    STR_ID_OPTRSER_MYMONWAP,
    STR_ID_OPTRSER_MONWAP,
#endif /* WAP_SUPPORT */ 
#ifdef __SYNCML_SUPPORT__
    STR_ID_OPTRSER_PIM,
    STR_ID_OPTRSER_PIM_INTRO,
    STR_ID_OPTRSER_PIM_ENTER,
    STR_ID_OPTRSER_PIM_SYNC,
    STR_ID_OPTRSER_PIM_PB,
    STR_ID_OPTRSER_PIM_SETTING,
#ifdef WAP_SUPPORT
    STR_ID_OPTRSER_PIM_FEE,
    STR_ID_OPTRSER_PIM_ORDER,
    STR_ID_OPTRSER_PIM_CHECK,
#endif /* WAP_SUPPORT */ 
#endif /* __SYNCML_SUPPORT__ */ 
    STR_ID_OPTRSER_STK,
    STR_ID_OPTRSER_END
} STRINGID_LIST_MOBILE_SERVICE;

typedef enum
{
    IMG_ID_OPTRSER_STK = MOBILE_SERVICE_BASE + 1,
#ifdef WAP_SUPPORT
    IMG_ID_OPTRSER_MUSIC,
    IMG_ID_OPTRSER_GAME,
    IMG_ID_OPTRSER_WEATHER,
    IMG_ID_OPTRSER_FETION,
    IMG_ID_OPTRSER_VIDEO,
    IMG_ID_OPTRSER_NEW,
    IMG_ID_OPTRSER_MYMONWAP,
    IMG_ID_OPTRSER_MONWAP,
#endif /* WAP_SUPPORT */ 
#ifdef __SYNCML_SUPPORT__
    IMG_ID_OPTRSER_PIM,
    IMG_ID_OPTRSER_PIM_SYNC,
    IMG_ID_OPTRSER_PIM_PB,
    IMG_ID_OPTRSER_PIM_SETTING,
#ifdef WAP_SUPPORT
    IMG_ID_OPTRSER_PIM_ORDER,
    IMG_ID_OPTRSER_PIM_CHECK,
#endif /* WAP_SUPPORT */ 
#endif /* __SYNCML_SUPPORT__ */ 
    IMG_ID_OPTRSER_END
} IMAGEID_LIST_MOBILE_SERVICE;

#endif /* __MMI_MOBILE_SERVICE__ */ 

#endif /* _MMI_MOBILE_SERVICE_RES_H_ */ 

