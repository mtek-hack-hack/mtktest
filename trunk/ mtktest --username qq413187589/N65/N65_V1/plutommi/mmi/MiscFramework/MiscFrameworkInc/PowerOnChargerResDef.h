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
 * PowerOnChargerResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for IDs for power-on charger applications
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

/*****************************************************************************

   Filename:   PowerOnChargerResDef.h

   Purpose: IDs of PowerOnCharger 

   Author:     Fion Yang

   Date:    Aug 10, 2007

   
*******************************************************************************/


enum STR_BOOTUP_LIST
{
    //STR_CHARGER_POWER_ON = CHARGER_BASE + 1,
    //STR_ALARM_STOP_MSG,                                        
    //STR_ALARM_PWRON_LSK,                                       
    //      STR_ALARM_PWRON_RSK,                                    
    //STR_ALARM_PWRON_MSG,                                       
    //      STR_ALARM_STOP_LSK,
    //STR_BATTERY_FULL_CHARGED,
    
    STR_LOW_BATTERY = CHARGER_BASE + 1,
    STR_LOW_BATTERY_MT_PROHIBIT,
    STR_OVER_VOLTAGE_BATTERY,
    STR_OVER_TEMP_BATTERY,
    STR_INVALID_BATTERY,
    STR_OVER_CURRENT_BATTERY,   /* MTK Robin 0924 */
    //STR_LOW_CURRENT_BATTERY,
    STR_CHARGE_BAD_CONTACT,
    STR_BATTERY_BAD_CONTACT,
    //STR_SUBLCD_ABNORMAL_BATTERY,
    STR_CHARGER_CONNECTED,
    STR_CHARGER_REMOVED,
    STR_USB_CHARGER_CONNECTED,
    STR_USB_CHARGER_REMOVED,
    STR_LOW_TEMP_BATTERY,
    STR_CHARGING_TIMEOUT,
    STR_INVALID_CHARGER,
    STR_LOW_BATTERY_SHUTDOWN
};

enum IMG_BOOTUP_LIST
{
    IMG_CHARGER_POWER_ON = CHARGER_BASE + 1,
    IMG_BATTERY_FULL_CHARGED,
    IMG_SUBLCD_CHARGER_POWER_ON,
    IMG_SUBLCD_CHARGING_COMPLETE,
    IMG_SUBLCD_ABNORMAL_BATTERY
};

enum SCR_BOOTUP__LIST
{
    SCR_CHARGER_POWER_ON = CHARGER_BASE + 1,
    SCR_CHARGING_COMPLETE,
    SCR_ABNORMAL_CHARGING,
    SCR_CHARGER_POPUP,
    SCR_LOW_POWEROFF_SCR
};


