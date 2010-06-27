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
 * JProvisioningResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines the string ,screen & Image ID  used for the OTA provisioning.
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

#ifndef _JPROVISIONINGRESDEF_H
#define _JPROVISIONINGRESDEF_H

#include "MMI_features.h"

#if defined (JATAAYU_SUPPORT)
#include "MMIDataType.h"

/* String IDs */
typedef enum
{
    STR_ID_PROV_INSTALL_SETTINGS = JATAAYU_PROVISIONING_BASE,
    /* add new string ID below this line */
    STR_ID_PROV_INVALID_BEARER,
    STR_ID_PROV_MAX_QUE_SIZE,
    STR_ID_PROV_INVALID_SETTINGS,
    STR_ID_PROV_NEW_SETTINGS,
    STR_ID_PROV_DATAACCOUNT_CAPTION,
    STR_ID_PROV_ENTER_PIN_CAPTION,
    STR_ID_PROV_AUTHENTICATION_PASSED,
    STR_ID_PROV_BOOKMARK_INVALID,
    STR_ID_PROV_BOOKMARK_STORED,
    STR_ID_PROV_INSTALL_BOOKMARK,
    STR_ID_PROV_NEW_BOOKMARK,
    STR_ID_PROV_ABORT_SETTINGS_SETUP,
    STR_ID_PROV_UNSUPPORTED_SETTING,
    STR_ID_PROV_CCA_BOOKMARK,
    STR_ID_PROV_CCA_BOOKMARKS,
    STR_ID_PROV_CCA_PROFILE_NAME,
    STR_ID_PROV_CCA_HOMEPAGE,
    STR_ID_PROV_CCA_MMSC_ADD,
    STR_ID_PROV_CCA_CONN_TYPE,
    STR_ID_PROV_CCA_DATA_ACCNT,
    STR_ID_PROV_CCA_PROXY_SERVER,
    /* add new string ID above this line */
    STR_ID_PROV_END
} STR_ID_JATAAYU_PROVISIONING_ENUM;

/* Screen IDs */
typedef enum
{
    SCR_ID_PROV_PROF_LIST = JATAAYU_PROVISIONING_BASE,
    /* add new screen ID below this line */
    SCR_ID_PROV_PROF_GPRS_DATA_ACCT,
    SCR_ID_PROV_PROF_GSM_DATA_ACCT,
    SCR_ID_PROV_PROF_NEW_SETTINGS_POPUP,
    SCR_ID_PROV_OMA_ENTER_PIN,
    SCR_ID_PROV_INSTALL_NEW_SETTINGS,
    SCR_ID_PROV_ABORT_SETTINGS_SETUP,
    /* add new screen ID above this line */
    SCR_ID_PROV_END
} SCR_ID_JATAAYU_PROVISIONING_ENUM;

/* Image IDs */
typedef enum
{
    IMG_ID_PROV_CANCEL = JATAAYU_PROVISIONING_BASE,
    /* add new image ID below this line */
    IMG_ID_PROV_MAX_QUE_SIZE,
    IMG_ID_PROV_INVALID_BEARER,
    IMG_ID_PROV_INVALID_SETTINGS,
    IMG_ID_PROV_AUTHENTICATION_PASSED,
    /* add new image ID above this line */
    IMG_ID_PROV_END
} IMG_ID_JATAAYU_PROVISIONING_ENUM;

#endif /* defined (JATAAYU_SUPPORT) */ 
#endif /* _JPROVISIONINGRESDEF_H */ 

