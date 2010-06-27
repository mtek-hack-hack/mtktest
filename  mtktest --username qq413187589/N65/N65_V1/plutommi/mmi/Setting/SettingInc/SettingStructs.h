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
 * SettingStructs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : setting_structs.h

   PURPOSE     : Settings application structure definitions

   REMARKS     : nil

   AUTHOR      : Vanita Jain

   DATE     : 

**************************************************************/

#ifndef _PIXCOM_SETTINGSTRUCTS_H
#define _PIXCOM_SETTINGSTRUCTS_H

#include "SettingDefs.h"
#include "SettingGenum.h"

typedef enum _on_off_option
{
    MMI_OFF_OPTION,
    MMI_ON_OPTION
} MMIOPTION;

#define   MMI_DATE_DD_MMM_YYYY    1
#define   MMI_DATE_DD_MM_YY_H     2
#define   MMI_DATE_MM_DD_YY       3
#define   MMI_DATE_DD_MM_YY_S     4
#define   MMI_DATE_DD_MM_YY_P     5
#define   MMI_DATE_YYMMDD         6
#define   MMI_DATE_YY_MM_DD       7
#define   MMI_DATE_AUX_YY_MM_DD   8
#define   MMI_DATE_AUX_YYYY_MM_DD 9

typedef enum _sim_dn
{
    MMI_TYPE_NONE = 0,
    MMI_TYPE_ADN = 0x2,
    MMI_TYPE_FDN = 0x4,
    MMI_TYPE_BDN = 0x8,
    MMI_TYPE_ADN_BDN = 0x0A,
    MMI_TYPE_FDN_BDN = 0x0C
} SIMDNENUM;

typedef enum _sim_security_operation_enum
{
    MMI_VERIFY,
    MMI_DISABLE,
    MMI_ENABLE,
    MMI_CHANGE,
    MMI_UNBLOCK
} SIMSECURITYOPERATION;

// ************* Hardware Related Declarations *******************//
#define MMISMUDIALMODEREQSTRUCT mmi_smu_set_dial_mode_req_struct
#define MMISMULOCKREQSTRUCT      mmi_smu_lock_req_struct
#define PASSWORDREQ           mmi_smu_change_password_req_struct
#define SMUSTATUSREQ       mmi_smu_check_pin_status_req_struct
#define SMUSTATUSRSP       mmi_smu_check_pin_status_rsp_struct
#define RTCTIMEFORMAT         mmi_eq_set_rtc_time_req_struct    /* rtc_format_struct */
#define TIMEFORMAT            time_format_enum
#define FDLSIMSTATUSREQ       mmi_smu_read_file_info_req_struct
#define FDLSIMSTATUSRSP       mmi_smu_read_file_info_rsp_struct
#define DIALMODESTATUSRSPSTRUCT mmi_smu_get_dial_mode_rsp_struct

/* micha1126 */
#define SMULOCKRSP            mmi_smu_lock_rsp_struct

typedef enum timeformat
{
    TYPE_12_HOURS,  /* 0 */
    TYPE_24_HOURS   /* 1 */
} TIMEFORMATS;

#define TYPE_AM_PM TIME_HH_MM_12

typedef enum dateformat
{
    DATEFORMAT_DD_MMM_YYYY,
    DATEFORMAT_DD_MM_YYYY,
    DATEFORMAT_MM_DD_YYYY,
    DATEFORMAT_YYYY_MM_DD_S,
    DATEFORMAT_YYYY_MM_DD_H,
    DATEFORMAT_MMM_DD_YYYY
} DATEFORMATS;

// #define DATEFORMAT                           date_format_enum;

/* ************ Window Related Declarations ********************* // */

#endif /* _PIXCOM_SETTINGSTRUCTS_H */ 

