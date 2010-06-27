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
 *	DMUIResDef.h
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *	This file define resource id for DMUI application.
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
 *============================================================================
 *
 *****************************************************************************/
#ifndef _DMUIRESDEF_H
#define _DMUIRESDEF_H

#include "MMI_features.h"

#include "MMIDataType.h"

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    SCR_ID_DMUI_BASE = DMUI_BASE,
    /* add new screen ID below this line */

    SCR_ID_DMUI_MAIN,
    SCR_ID_DMUI_OPTION,
    SCR_ID_DMUI_INFO,
    SCR_ID_DMUI_INFO_CS,
    SCR_ID_DMUI_UPDATE,
    SCR_ID_DMUI_DOWNLOAD,
    SCR_ID_DMUI_DOWNLOAD_PROGRESS,
    SCR_ID_DMUI_ENTER_PIN,
    SCR_ID_DMUI_REBOOT,
    SCR_ID_DMUI_ALERT_INPUT,
    SCR_ID_DMUI_ALERT_SINGLE_CHOICE,
    SCR_ID_DMUI_ALERT_MULTI_CHOICE,
    SCR_ID_DMUI_WAITING,
    SCR_ID_DM_OTA_PROVISIONING_INFO,
    SCR_ID_DM_OTA_SKIP_CONFIRM,
    SCR_ID_DM_OTA_SERVERID_LIST,

    /* add new screen ID above this line */
    SCR_ID_DMUI_END
} SCR_ID_DMUI_ENUM;


/* String IDs */
typedef enum
{
    STR_ID_DMUI_BASE = DMUI_BASE,
    /* add new string ID below this line */

    STR_ID_DMUI_MAIN,
    STR_ID_DMUI_OPTION_CAPTION,
    STR_ID_DMUI_OP_ERASE,
    STR_ID_DMUI_ERASED,
    STR_ID_DMUI_LIST_EMPTY,
    STR_ID_DMUI_WAITING,
    STR_ID_DMUI_ACTIVATED,
    STR_ID_DMUI_USER_CANCELLED,
    STR_ID_DMUI_DELETE_ASK,

    /* string id for DM info setting */
    STR_ID_DMUI_INFO_CAPTION,
    STR_ID_DMUI_SERVERID,
    STR_ID_DMUI_SERVER_PASSWORD,
    STR_ID_DMUI_CONNECTION_SETTING,
    STR_ID_DMUI_SERVER_ADDRESS,
    STR_ID_DMUI_USERNAME,
    STR_ID_DMUI_USER_PASSWORD,
    STR_ID_DMUI_AUTHTYPE,
    STR_ID_DMUI_AUTHTYPE_NONE,
    STR_ID_DMUI_AUTHTYPE_BASIC,
    STR_ID_DMUI_AUTHTYPE_MD5,
    STR_ID_DMUI_AUTHTYPE_HMAC,
    STR_ID_DMUI_INFO_SERVERID_EMPTY,
    STR_ID_DMUI_INFO_SERVERID_EXIST,
    STR_ID_DMUI_INFO_SERVERID_INVALID,
    STR_ID_DMUI_INFO_INVALID_SERVER_ADDRESS,

    /* string id for DM connection setting */
    STR_ID_DMUI_CS_DATA_ACCOUNT,
    STR_ID_DMUI_CS_USE_PROXY,
    STR_ID_DMUI_CS_IP,
    STR_ID_DMUI_CS_PORT,
    STR_ID_DMUI_CS_PROXY_USERNAME,
    STR_ID_DMUI_CS_PROXY_PASSWORD,
    STR_ID_DMUI_CS_INVALID_PORT,
    STR_ID_DMUI_CS_INVALID_IP,

    /* string id for DM notification */
    STR_ID_DMUI_NOTIF_INIT_SESSION,
    STR_ID_DMUI_NOTIF_ENTER_PIN,
    STR_ID_DMUI_NOTIF_DOWNLOAD_CAPTION,
    STR_ID_DMUI_NOTIF_DOWNLOAD_TITLE,
    STR_ID_DMUI_NOTIF_DOWNLOAD_INFO,
    STR_ID_DMUI_NOTIF_UPDATE_CAPTION,
    STR_ID_DMUI_NOTIF_UPDATE_TITLE,
    STR_ID_DMUI_NOTIF_UPDATE_INFO,
    STR_ID_DMUI_NOTIF_UPDATE_REBOOT,
    STR_ID_DMUI_NOTIF_UPDATE_DEFER,
    STR_ID_DMUI_NOTIF_NAME,
    STR_ID_DMUI_NOTIF_TYPE,
    STR_ID_DMUI_NOTIF_SIZE,
    STR_ID_DMUI_NOTIF_DESCRIPTION,
    STR_ID_DMUI_NOTIF_UPDATE_REQUEST,
    STR_ID_DMUI_NOTIF_DOWNLOAD_REQUEST,
    STR_ID_DMUI_NOTIF_REBOOT,
    STR_ID_DMUI_NOTIF_REBOOT_PROGRESS,
    STR_ID_DMUI_DOWNLOAD_PROGRESS,

    /* string id for DM alert */
    STR_ID_DMUI_ALERT_DM_INFO_CAPTION,

    /* string id for DM provisioning */
    STR_ID_DM_OTA_PROFILE,
    STR_ID_DM_OTA_SERVERID_EXIST_REPLACE,
    STR_ID_DM_OTA_SERVERID_FULL_REPLACE,

    /* add new string ID above this line */
    STR_ID_DMUI_END
} STR_ID_DMUI_ENUM;

/* Image IDs */
typedef enum
{
    IMG_ID_DMUI_BASE = DMUI_BASE,
    IMG_ID_DMUI_MAIN,
    IMG_ID_DMUI_NO_IMAGE,
    IMG_ID_DMUI_SEL_IMAGE,
    IMG_ID_DMUI_SERVERID,
    IMG_ID_DMUI_SERVER_PASSWORD,
    IMG_ID_DMUI_CONNECTION_SETTING,
    IMG_ID_DMUI_SERVER_ADDRESS,
    IMG_ID_DMUI_USERNAME,
    IMG_ID_DMUI_USER_PASSWORD,
    IMG_ID_DMUI_AUTHTYPE,
    IMG_ID_DMUI_END
} IMG_ID_DMUI_ENUM;

#endif  /* _DMUIRESDEF_H */

