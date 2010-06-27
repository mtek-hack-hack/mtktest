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
 *  DeviceManagementResDef.h    
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Device Management Defines
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
#ifndef DEVICE_MANAGEMENT_DEF_H
#define DEVICE_MANAGEMENT_DEF_H

#include "DataAccountDef.h"

typedef enum
{
    SCR_ID_DM_BASE = DEVICE_MANAGEMENT_BASE + 1,
    SCR_ID_DM_MAIN,
    SCR_ID_DM_FWU,                  /* Firmware Upgrade */
    SCR_ID_DM_TFTP,                 /* From TFTP */
    SCR_ID_DM_HTTP,                 /* From HTTP */
    SCR_ID_DM_TFTP_SETTINGS,        /* From TFTP - Settings */
    SCR_ID_DM_HTTP_SETTINGS,        /* From HTTP - Settings */
    SCR_ID_DM_HTTP_AUTH,        /* From HTTP - Authentication */
    SCR_ID_DM_UPGRADE_ANIMATION,    /* Upgrade */    
    SCR_ID_DM_UPGRADE_RESULT,    /* Result */
    SCR_ID_DM_OTAP_INSTALL_PROFILE, /*FOTA Provisioning setting*/
    SCR_ID_DM_OTAP_AUTO_FOTA, /*FOTA Provisioning setting*/
    SCR_ID_DM_END
} DM_SCR_IDS;

typedef enum
{
    STR_ID_DM_BASE = DEVICE_MANAGEMENT_BASE + 1,
    
    STR_ID_DM_APP,
    STR_ID_DM_FWU,                    /* Firmware Upgrade */
    STR_ID_DM_FWU_TFTP,               /* From TFTP */
    STR_ID_DM_FWU_HTTP,               /* From HTTP */
    STR_ID_DM_FWU_FILE,               /* From File */
    STR_ID_DM_DOWNLOAD_NOW,           /* Download Now */
    STR_ID_DM_SETTINGS,               /* Settings */
    STR_ID_DM_SERVER_NAME,            /* Server Name */
    STR_ID_DM_PORT,                   /* Port */
    STR_ID_DM_FILENAME,               /* File Name */
    STR_ID_DM_URL,                    /* URL */
    STR_ID_DM_DEFAULT_URL,            /* default URL: "http://" */
    STR_ID_DM_HTTP_NETWORK,           /* HTTP Network Profile */    
    STR_ID_DM_HTTP_DEFAULT,           /* Default */        
    STR_ID_DM_EDIT,                   /* Edit */
    STR_ID_DM_SELECT,                 /* Select */
    STR_ID_DM_DOWNLOADING,            /* Downloading */
    STR_ID_DM_DOWNLOADING_WARNING,    /* Already upgrading, not allowed */
    STR_ID_DM_UPGRADE_NOW,            /* Upgrade Now */
    STR_ID_DM_SHUTDOWN_NOTIFY,        /* Shutdown Notification */

    STR_ID_DM_RESULT_FILE_NOT_FOUND,  /* File not found */
    STR_ID_DM_RESULT_ACCESS_DENIED,   /* Access denied */
    STR_ID_DM_RESULT_SOC_ERROR,       /* Socket Error */
    STR_ID_DM_RESULT_TIMEOUT,         /* Time out */
    STR_ID_DM_RESULT_AUTH_FAIL,       /* Auth Fail */
    STR_ID_DM_RESULT_FINAL_CHECK_FAIL,/* Final Check Fail */

    STR_ID_DM_DOWNLOAD_RETRY,         /* Retry */
    STR_ID_DM_EMPTY_USERNAME,         /* Empty UserName */

    STR_ID_DM_EMPTY_SERVERNAME,       /* Empty ServerName */
    STR_ID_DM_EMPTY_FILERNAME,        /* Empty FileName */
    STR_ID_DM_INVALID_PORT,           /* Invalid Port */
    
    STR_ID_DM_PROF_ADDR,              /* FOTA Provisioning setting */
    STR_ID_DM_OTAP_INSTALL_PROFILE, /* FOTA Provisioning install */
    STR_ID_DM_OTAP_EXIT_INSTALL_CONFIRM,  /* Exit FOTA Provisioning confirm */
    STR_ID_DM_OTAP_AUTO_FOTA,

    STR_ID_DM_END
} DM_STRING_IDS;

typedef enum
{
    IMG_ID_DM_BASE = DEVICE_MANAGEMENT_BASE + 1,
    
    IMG_ID_DM_APP,
    IMG_ID_DM_FWU,

    IMG_ID_DM_FWU_FROM_TFTP,
    IMG_ID_DM_FWU_FROM_HTTP,
    IMG_ID_DM_FWU_FROM_FILE,
    
    IMG_DM_END
} DM_IMAGE_ID_ENUM;

#endif /* DEVICE_MANAGEMENT_DEF_H */

