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
 * power_on_off_display_defs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Resource IDs for the Power ON/Off Display
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef POWERONOFFDISPLAYDEFS_H
#define POWERONOFFDISPLAYDEFS_H

#include "MMIDataType.h"
/* Cylen 0926, customize display char */
/*
 * Move to SettingDefs.h
 * typedef enum{
 * }PHNSET_STR_ONOFF;
 */
typedef enum
{
    SCR_ID_PHNSET_POWER_ON = PHNSET_ONOFF_BASE + 1,
    SCR_ID_PHNSET_POWER_ON_SYSTEM_LIST,
    SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW,
    SCR_ID_PHNSET_POWER_ON_DOWNLOAD_LIST,
    SCR_ID_PHNSET_POWER_ON_USER_VIEW,
    SCR_ID_PHNSET_POWER_OFF,
    SCR_ID_PHNSET_POWER_OFF_SYSTEM_LIST,
    SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW,
    SCR_ID_PHNSET_POWER_OFF_DOWNLOAD_LIST,
    SCR_ID_PHNSET_POWER_OFF_USER_VIEW,
    SCR_ID_PHNSET_POWER_ON_OFF_LAST
} SCR_ID_PHNSET_ONOFF;

typedef enum
{

    /* Cylen 0926, customize display char */
    IMG_ID_PHNSET_ON_OFF_SYSTEM = PHNSET_ONOFF_BASE + 1,
    IMG_ID_PHNSET_ON_OFF_DOWNLAOD,
    IMG_ID_PHNSET_ON_OFF_CAPTION,
    IMG_ID_PHNSET_ON_OFF_START  /* Cylen 0926, customize display char */
} IMG_ID_PHNSET_ON_OFF;

/* Cylen 0926, customize display char */

#endif /* POWERONOFFDISPLAYDEFS_H */ 

