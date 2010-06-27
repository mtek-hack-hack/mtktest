/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   SyncMLDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for SyncML (ESI) structure
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
 ****************************************************************************/

#ifndef __SYNCML_DEF_H__
#define __SYNCML_DEF_H__

#ifdef __SYNCML_SUPPORT__

#include "SyncMLResDef.h"

#define MAX_SYNCML_PROFILES  (MAX_SYNCML_SV_PROFILES + MAX_SYNCML_PC_PROFILES)
#define MAX_SYNCML_PROXY_PORT_LEN      6

#define SYNCML_VOBJ_PATH     L"Z:\\@USER\\syncvobj.tmp"

#define SYNCML_PHB_CHANGE_LOG_FILE_PREFIX L"Z:\\@USER\\syncphb"
#define SYNCML_PHB_CHANGE_LOG_FILE_PATH   L"Z:\\@USER\\syncphb1.log"
#define SYNCML_TDL_CHANGE_LOG_FILE_PREFIX L"Z:\\@USER\\synctdl"
#define SYNCML_TDL_CHANGE_LOG_FILE_PATH   L"Z:\\@USER\\synctdl1.log"

#define SYNCML_CHANGE_LOG_RECORD_SIZE 7 /* U16(LUID) + U32(timestamp) + U8(operation) */

#define SYNCML_CHANGE_LOG_NOT_FOUND -1

#define SYNCML_OK 200
#define SYNCML_FAIL 500
#define SYNCML_INVALID_CREDENTIAL 401
#define SYNCML_MISSING_CREDENTIAL 407
#define SYNCML_DEVICE_FULL 420
#define SYNCML_PAYMENT_REQUIRED 402
/* yln added, other code need to be displayed */
#define SYNCML_CODE_FORBIDDEN 403       /* Server busy */
#define SYNCML_INCOMPLETE_CMD 412
#define SYNCML_DEVICE_FULL 420
#define SYNCML_SERVICE_UNAVAILABLE 503  /* Server busy */
#define SYNCML_DATASTORE_FAIL 510
#define SYNCML_SVR_FAIL 511
#define SYNCML_ERR_OCCUR 512
#define SYNCML_PROTOCOL_UNSUPPORT 513


#define DEFAULT_CCA_PROFILE_NAME    (L"New Profile")

enum SYNCML_RECORD_ACCESS_ENUM
{
    /* shall map to SYNCML_OP_ENUM in SyncML task */
    SYNCML_RECORD_GET = 0,
    SYNCML_RECORD_ADD,
    SYNCML_RECORD_MODIFY,
    SYNCML_RECORD_DELETE,
    SYNCML_RECORD_ALL,
    SYNCML_RECORD_ERASE, /* clear the change log of this record */
    SYNCML_RECORD_GET_DEL_NOTIFY = 6
};

enum SYNCML_REGULAR_SYNC_ENUM
{
    SYNCML_REGULAR_SYNC_NONE,         /* No regular sync */
    SYNCML_REGULAR_SYNC_DATA_CHANGED, /* When data is changed */
    SYNCML_REGULAR_SYNC_POWER_ON,     /* When handset is turned on */
    SYNCML_REGULAR_SYNC_EVERY_DAY,    /* Every day */
    SYNCML_REGULAR_SYNC_EVERY_WEEK,   /* Every week */
    SYNCML_REGULAR_SYNC_EVERY_MONTH,  /* Every month */
    SYNCML_REGULAR_SYNC_END
};

enum SYNCML_SYNC_TYPE_ENUM
{
    SYNCML_TYPE_DEFAULT,
    SYNCML_TYPE_BACKUP,
    SYNCML_TYPE_RESTORE,
    SYNCML_TYPE_EXPORT,
    SYNCML_TYPE_IMPORT,
    SYNCML_TYPE_END
};

/* Converted symbols to define CCA namespace mapping table. */
typedef enum
{
    CCA_NS_SYNCML_PROXY,
    CCA_NS_SYNCML_APPLICATION,
    CCA_NS_SYNCML_PORT,
    CCA_NS_SYNCML_PXAUTHINFO,
    CCA_NS_SYNCML_APPADDR,
    CCA_NS_SYNCML_APPAUTH,
    CCA_NS_SYNCML_RESOURCE,
    CCA_NS_SYNCML_TOTAL
} syncml_cca_symbol_enum;


#endif /* __SYNCML_SUPPORT__ */

#endif /* __SYNCML_DEF_H__ */

