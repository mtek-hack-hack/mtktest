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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * ConnectManageResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#ifndef _PIXTEL_CONNECT_MANAGE_H
#define _PIXTEL_CONNECT_MANAGE_H

#ifdef __CBM_CM_FEATURE__
typedef enum
{
    SCR_ID_CBM_LIST = CONNECT_MANAGE_BASE + 1,
    SCR_ID_CBM_DETAIL,
    SCR_ID_CBM_OPTION,
    SCR_ID_CBM_DISC_PRODUCESS,
    SCR_ID_CBM_EMPTY,
    SCR_ID_CBM_DUMP
} SCR_CONNECT_MANAGE;


typedef enum
{
    IMG_ID_CBM_MAIN_ICON = CONNECT_MANAGE_BASE + 1,
    IMG_ID_CBM_DUMP
}IMG_CONNECT_MANAGE;


typedef enum
{
    STR_ID_CBM_MAIN = CONNECT_MANAGE_BASE + 1,
    STR_ID_CBM_DETAIL,
    STR_ID_CBM_DISC,
    STR_ID_CBM_DISC_CONFIRM,
    STR_ID_CBM_DISC_ALL,
    STR_ID_CBM_DISC_ALL_CONFIRM,
    STR_ID_CBM_PROCESSING,
    STR_ID_CBM_NO_CONNECTION,
    STR_ID_CBM_DETAIL_APN,
    STR_ID_CBM_DETAIL_NUMBER,
    STR_ID_CBM_DETAIL_AP_NAME,
    STR_ID_CBM_DETAIL_TYPE,
    STR_ID_CBM_DETAIL_TYPE_GPRS,
    STR_ID_CBM_DETAIL_TYPE_CSD,
    STR_ID_CBM_DETAIL_TYPE_WIFI,
    STR_ID_CBM_DETAIL_TYPE_DAILUP,
    STR_ID_CBM_DETAIL_STATUS,
    STR_ID_CBM_DETAIL_UNTRANSFER,
    STR_ID_CBM_DETAIL_TRANSFERING,
    STR_ID_CBM_DETAIL_DISC,
    STR_ID_CBM_DETAIL_SEND_DATA_SIZE,
    STR_ID_CBM_DETAIL_RECEIVE_DATA_SIZE,
    STR_ID_CBM_DETAIL_ALL_DATA_SIZE,
    STR_ID_CBM_DETAIL_UP_DATA_RATE,
    STR_ID_CBM_DETAIL_DOWN_DATA_RATE,
    STR_ID_CBM_DETAIL_CONN_TIME,
    STR_ID_CBM_DETAIL_SHARE,
    STR_ID_CBM_DETAIL_NEXT,
    STR_ID_CBM_DETAIL_PREV
} STR_CONNECT_MANAGE;

#endif /* _PIXTEL_DATA_ACCOUNT_H */ 
#endif /* __CBM_CM_FEATURE__*/
