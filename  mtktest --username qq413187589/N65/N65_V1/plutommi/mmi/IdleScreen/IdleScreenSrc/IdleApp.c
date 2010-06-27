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
 *  IdleApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for The Idle screen application
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"

#include "MiscFunctions.h"
#include "gui_themes.h"
#include "DateTimeGprot.h"
#include "CommonScreens.h"      /* DisplayPopup */
#include "wgui_status_icons.h"
#include "wgui_softkeys.h"
#include "UCS2prot.h"
#include "worldclock.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "CallHistoryGProts.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "CallManagementGprot.h"
#include "CallStructureManagementProt.h"
#include "CallHistoryMain.h"    /* CHISTResetCallLogIndex */
#include "SSCStringHandle.h"
#include "SettingGprots.h"
#include "audioinc.h"
#include "gpioInc.h"
#include "SettingProfile.h"
#include "SpeedDial.h"
#include "MessagesResourceData.h"
#include "WPSSProtos.h"
#include "PowerOnChargerProt.h"
#include "FunAndGamesDefs.h"
#include "DownloadDefs.h"
#include "QuickAccessMenuItemProt.h"
#include "AlarmFrameworkProt.h"
#include "ProfilesGexdcl.h"
#include "PhoneBookDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookProt.h"
#include "PhoneBookGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "PhoneSetupGprots.h"
#include "OrganizerGprot.h"     /* OrgDeInit */
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "FileManagerGProt.h"   /* file path / file error */
#include "FileManagerDef.h"     /* error string id */
#include "FlightModeGProt.h"
#include "VolumeHandler.h"
#include "EONSGProt.h"

#if defined(__MMI_DATE_TIME_SETTING_REMINDER__)
#include "rtc_sw.h"
#endif 

/* JBRW Sandeep */
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "JBrowserMMIGProts.h"
#endif 

/* Manish - adding for JMMS */
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
#include "JMMSPushHandling.h"
#include "JMMSMainMMS.h"
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

/* Dara */
#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
#include "JProvProts.h"
#endif 

#include "wgui_status_icons.h"
#include "wgui_ems.h"
#include "ShortcutsProts.h"     /* for 4-dedicated shortcuts 0101 */
#include "SATGProts.h"

#ifdef WAP_SUPPORT
#include "Wapadp.h"
#include "wap_ps_struct.h"
#endif 

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#endif 
#ifdef __J2ME__
#include "javaAgencyGprot.h"
#include "jvm_adaptor.h"
#endif /* __J2ME__ */ 

#ifdef __MMI_SWFLASH__
#include "SWFlashGprot.h"
#endif /* __MMI_SWFLASH__ */ 

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 

#if defined __MMI_OPP_SUPPORT__ || defined __MMI_BIP_SUPPORT__
#include "OPPMMIGprots.h"
#endif 

#ifdef __MOD_SMSAL__
#include "MessagesExDcl.h"
#include "SMSApi.h"
#endif /* __MOD_SMSAL__ */ 

#ifdef __MMI_CAMERA__
#include "lcd_if.h"     /* LCD layer enable flag */
#include "gdi_lcd_config.h"
#include "MMI_features_camera.h"
#include "mdi_datatype.h"
#include "mdi_camera.h" /* camera lib */
#include "CameraApp.h"
#endif /* __MMI_CAMERA__ */ 

#include "custom_util.h"

#include "NITZ.h"
#include "vObjects.h"
#include "OSThreadInterfaceGprot.h"
#include "NetworkSetupDefs.h"
#include "NetworkSetupGProt.h"

#ifdef __MMI_IMPS__
#include "mmi_imps_gprot.h"
#endif 

/* micha_POC */
#ifdef __MMI_POC__
#include "PoCGProt.h"
#endif 

#ifdef __MMI_VOIP__
#include "VoIPResDef.h"
#include "VoIPGProt.h"
#endif /* __MMI_VOIP__ */

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
#endif 
#if defined(__MMI_DOWNLOAD_AGENT__)
#include "App_mine.h"
#include "DLAgentDef.h"
#include "DLAgentGProt.h"
#endif /* defined(__MMI_DOWNLOAD_AGENT__) */ 

#ifdef __MMI_SML_MENU__
#include "PersonalizationProt.h"
#endif

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif

#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))
#include "SyncMLGProt.h"
#endif

#if defined(__FOTA_ENABLE__)
#include "DeviceManagementGProt.h"
#endif

#ifdef __MMI_CCA_SUPPORT__
#include "CentralConfigAgentGProt.h"
#endif

#ifdef __MMI_MMS_2__
#include "MMSViewerAPPDefs.h"
#include "MMSAppGprot.h"
#endif
#ifdef __MMI_BROWSER_2__
#include "PushInboxProts.h"
#endif

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif /* __MMI_UCM__ */

#ifdef __MMI_BG_SOUND_EFFECT__
#include "BGSoundType.h"
#endif

#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_Master_CallHistory.h"
#include "mtpnp_pfal_cellbroadcast.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#undef __NEWSIMULATOR


/***************************************************************************** 
* Define
*****************************************************************************/
#if defined( __MMI_MAINLCD_240X320__) || defined( __MMI_MAINLCD_320X240__)
    #define __MMI_IDLE_NO_NW_SEARCHING_SCREEN__
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
extern void EntryDualModeSwitchProgressInIdle(void);
extern U8 DualModeIsSwitching(void);
#endif 

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* diamond, 2005/10/12 idle revise */
typedef void (*FuncPtr) (void);
typedef U8(*FuncPtrRtn) (void);

typedef struct _idle_callback_info
{
    FuncPtrRtn idle_callback_chk_f; /* callback to check if there is any pending event in idle screen */
    FuncPtr idle_callback_exe_f;    /* callback to execute the corresponding function in idle screen  */
} IDLECALLBACKINFO;

/* end, diamond */


/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void EmergencyCallCheck(S16 keyCode, S16 keyType);
extern void MMIProcessActionMsg(void);
extern U8 *GetDeliverdReportMessage(void);
extern kal_bool INT_USBBoot(void);
extern EMSData *GetClass0MessagePtr(void);
extern U8 *GetClass0MessageHeader(void);
extern BOOL IsMyTimerExist(U16 nTimerId);
#ifdef __SAT__
extern void SATEVDLIdleScreenAvaliable(void);
#endif
extern void mmiapi_enter_idle_screen_notify(void);

#ifdef WAP_SUPPORT
extern void wap_internet_key_hdlr(void);
#endif 

#ifdef __MMI_AUDIO_PLAYER__
extern BOOL mmi_audply_is_playing(void);
extern void mmi_audply_set_subLCD_shown(BOOL is_shown);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifdef __MMI_FM_RADIO__
extern BOOL mmi_fmrdo_is_power_on(void);
extern void mmi_fmrdo_set_subLCD_shown(BOOL is_shown);
void mmi_fmrdo_power_on(BOOL turn_on);
#endif /* __MMI_FM_RADIO__ */ 

#if defined(__MMI_VRSD__)
extern void mmi_vrsd_rcg_pre_entry(void);
#endif 

#if defined(__MMI_VRSD_DIAL__)
extern BOOL mmi_vrsddial_check_sim_change(void);
#endif 

#if defined(__MMI_VRSI__)
extern void mmi_vrsi_rcg_pre_entry(void);
#endif 

/* Associate caller group in SIM card entry */
#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)
extern BOOL mmi_phb_init_check_sim_change(void);
#endif 

#ifdef __MMI_WGUI_MINI_TAB_BAR__
extern void ClndrPreEntryApp(void);
extern void fmgr_launch(void);
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 

/* diamond, 2005/07/05 Flight mode */
extern void EntryScrSimOptionMenu(void);
void EntryFlightModeIdleScreen(void);
void EntryFlightModeKeypadLockScreen(void);
void FlightModeDigitHandler(void);
/* end, diamond */

extern void InsertSimSetKeyPadLockFlag(void);
extern void UI_set_font(UI_font_type f);

#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
extern int widget_MMI_check_and_display_new_msg_when_keypad_lock(
            U16 KeyLockLSKStringID,
            U16 KeyLockLSKIconID,
            U16 KeyLockRSKStringID,
            U16 KeyLockRSKIconID);
extern int widget_MMI_check_and_display_new_msg(void);
extern void widget_check_msg_in_idle_screen(void);
#endif



/*****************************************************************************
* Local Function 
*****************************************************************************/
static U8 mmi_idle_missed_call_check(void);
#ifdef __MMI_NITZ__
static U8 mmi_idle_pending_nitz_check(void);
#endif 
#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
static U8 mmi_idle_widget_check_and_display_new_msg(void);
#endif


/****************************************************************************
* Global Variable                                                           
*****************************************************************************/
extern U16 gCurrLangIndex;
extern U16 gMaxDeployedLangs;
extern S32 MAIN_LCD_device_width;
extern sLanguageDetails *gLanguageArray;

#ifdef __HOMEZONE_SUPPORT__
extern U8 *gHomezoneText;
#endif 

extern U16 simErrorDisplayString;



/***************************************************************************** 
* Local Variable
*****************************************************************************/
idle_context_struct g_idle_context = 
{
    0,                      /* IsOnIdleScreen */
    SUBLCD_NOT_ON_IDLE,     /* IsSubLcdOnIdleScreen */
    0,                      /* IsOnDialerScreen */
    0,                      /* IsOnSimErrorScreen */
    0,                      /* IsOnSimErrorDialerScreen */
    0,                      /* IsScrSvrSleepIn */
    0,                      /* IsRSKPressOnScreenSaver */
    0,                      /* LongPressEnable */
    0,                      /* ScreenSaverRunFlag */
    0,                      /* ToNameScrFromIdleApp */
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    0,                      /* ToMainMenuScrFromIdleApp */
#endif 
    0,                      /* RskPressedFromIdleApp */
#ifdef __MMI_UCM__
    0,
#endif
    -1,                     /* IdleScreenDigitKeyCode */
    SET_CURRENT_PROFILE,    /* ToggleProfile */
#ifdef __MMI_SIMAP_SUPPORT__
    0,
#endif
    0,                      /* AutoLockTimeOut */
    {0}                     /* All dialled digits from idle screen */
};

idle_keylock_struct g_keylock_context = 
{
    0,      /* gKeyPadLockFlag */
    0,
    0,      /* KeyLockLSKStringID */
    0,      /* KeyLockRSKStringID */
    0,      /* KeyLockLSKIconID */
    0,      /* KeyLockRSKIconID */
    NULL    /* diamond, 2006/03/26 Generic exit function for keypad lock callback screens */
};

#ifdef __MMI_NITZ__
static idle_nitz_struct g_nitz_display = 
{
    0,      /* opname_from_nitz */
    0,      /* country_init */
    {0},    /* plmn[] */
    {0}     /* display_name[] */
};
#ifdef __MMI_DUAL_SIM_MASTER__
idle_nitz_struct g_nitz_display_2 = 
{
    0,      /* opname_from_nitz */
    0,      /* country_init */
    {0},    /* plmn[] */
    {0}     /* display_name[] */
};
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_NITZ__ */ 

static const IDLECALLBACKINFO mmi_idle_callbacks[] = 
{
    /* How to add callbacks for idle screen/keypad lock ? */
    /* 1. Fill the callbacks into this array     */

    /* Notice that the function type !        */
    /* 1. Checking  function should be U8 XXX(void)    */
    /* 2. Execution function should be void XXX(void)  */

#ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
    {mmi_sat_is_pending_idle_sat_cmd, mmi_sat_execute_idle_sat_cmd},
#endif
#ifdef __J2ME__
    {mmi_java_is_launch_from_idle, mmi_java_entry_mid_launch_from_idle}, /* new Java midlet */
#endif 
    {mmi_idle_missed_call_check, EntryCHISTNotifyMissedCall}, /* missed call */
    {mmi_msg_need_class0_msg_ind, mmi_msg_entry_class0_msg_ind}, /* new class 0 message */
#ifdef __MMI_UNIFIED_MESSAGE__
    {mmi_um_check_new_msg, mmi_um_pre_entry_new_msg_ind}, /* new unified message */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    {mmi_msg_need_new_sim_msg_ind, mmi_msg_entry_new_sim_msg_ind}, /* new unified message */
#endif
#else 
    {mmi_msg_need_new_msg_ind, mmi_msg_entry_new_msg_ind}, /* new short message */
#endif 
    {mmi_msg_need_mem_exceed_ind, mmi_msg_entry_mem_exceed_ind}, /* memory exceed notification */
    {mmi_msg_need_delivery_report_ind, mmi_msg_entry_deliver_report_ind}, /* deliver report */
    {mmi_msg_need_waiting_ind, mmi_msg_entry_msg_waiting_ind}, /* waiting message */
#ifdef __MMI_VOIP__
    {mmi_voip_need_msg_waiting_ind, mmi_voip_entry_msg_waiting_ind},
#endif
#ifdef __MMI_IMPS__
    {mmi_imps_check_invite_in_idle, NULL}, /* IMPS invitation */
#endif 
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    {mmi_vobj_is_pending_object, mmi_vobj_entry_recv_object}, /* unread vObjects */
#endif 
#if defined(__MMI_IRDA_SUPPORT__)
    {mmi_irda_get_recv_files_cnt, mmi_irda_entry_idle_notify_scr}, /* files from IrDA */
#endif 
#if (defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) && defined(__MMI_IRDA_SUPPORT__))
    {mmi_irda_is_any_theme_file_rcv, mmi_irda_theme_show_idle_notify_scr}, /* downloadable theme from IrDA */
#endif 
#if defined(__MMI_NITZ__)
    {mmi_idle_pending_nitz_check, EntryNitzScreen}, /* NITZ */
#endif 
    {mmi_msg_need_new_cb_ind, mmi_msg_entry_new_cb_ind}, /* new CB message */
#ifdef __MMI_DUAL_SIM_MASTER__
    {mmi_card2_msg_need_new_cb_ind, mmi_msg_entry_card2_new_cb_ind}, /* new SIM 2 CB message */
#endif /* __MMI_DUAL_SIM_MASTER__ */
#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
    {mmi_idle_widget_check_and_display_new_msg, NULL}, /* new message from widget */
#endif 
#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)
    {mmi_phb_init_check_sim_change, NULL}, /* associate caller group in SIM card entry */
#endif 
#if defined(__MMI_VRSD_DIAL__)
    {mmi_vrsddial_check_sim_change, NULL}, /* VRSD dial */
#endif 
#if defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
    {mmi_bt_get_recv_files_cnt, mmi_bt_entry_idle_notify_scr}, /* files from Bluetooth */
#endif
#if defined(__MMI_DOWNLOAD_AGENT__)
    {mmi_da_launch_ring_buffer_check, mmi_da_entry_new_push_ind}, /* download agent */
#endif 
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
    {mmi_jmms_need_mms_ind, mmi_jmms_entry_new_mms_ind}, /* new mms message */
#endif 
#if !defined (__MMI_UNIFIED_MESSAGE__) && defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
    {mmi_brw_new_push_msg_ind, mmi_brw_entry_new_push_msg_ind},  /* new wap push message */
#endif 
#if !defined (__MMI_CCA_SUPPORT__) && defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
    {mmi_prov_check_and_install_new_settings, mmi_prov_show_install_settings_dialog},
#endif 
#if defined (__MMI_BROWSER_2__)
    {mmi_brw_push_new_push_msg_ind, mmi_brw_push_entry_new_push_msg_ind},
    {mmi_brw_push_service_dlg_idle_scr_cb, mmi_brw_push_fetch_dlg_from_queue},
#endif
#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))
    {mmi_syncml_is_sync_alarm_expired, mmi_syncml_sync_alarm_hdlr}, /* sync */
#endif
#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
    {mmi_netset_unknown_operator_check, mmi_netset_unknown_operator_query}, /* user control plmn */
#endif
#if defined(__FOTA_ENABLE__)
    {mmi_dm_fwu_check_download_finish, mmi_dm_fwu_entry_download_finish_ind}, /* firmware upgrade finished */
#endif
#ifdef __MMI_CCA_SUPPORT__
    {mmi_cca_idle_check, mmi_cca_ui_entry_idle_screen},
#endif 

    {NULL, NULL}                                            /* dummy one, please add callbacks before this entity */
};

static U16 idleLRStringtID = 0; /* __MANUAL_MODE_NW_SEL__ */
static MMI_BOOL gIsIdleScreenReentry = MMI_FALSE;
extern S8 *idle_screen_wallpaper_name;


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_exe_callback
 * DESCRIPTION
 *  Execute callbacks before entry idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_idle_exe_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    pBOOL rtn = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; mmi_idle_callbacks[i].idle_callback_chk_f != NULL; i++)
    {
        if ((*mmi_idle_callbacks[i].idle_callback_chk_f) ())
        {
            rtn = MMI_TRUE;
            if (mmi_idle_callbacks[i].idle_callback_exe_f != NULL)
            {
                (*mmi_idle_callbacks[i].idle_callback_exe_f) ();
            }
            break;
        }
    }

    g_keylock_context.IsOnKeyLockCallbackScreen = (rtn == MMI_TRUE) ? 1 : 0;
    return rtn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_missed_call_check
 * DESCRIPTION
 *  Wrapper for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_idle_missed_call_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (GetMissedCallFlag() && 
        (((MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) && CHISTGetMissedCallCountBeforeView() != 0) || 
        ((MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) && MTPNP_AD_Get_MissedCallCount_BeforeView() != 0)))
#else
    if (GetMissedCallFlag() && CHISTGetMissedCallCountBeforeView())
#endif
    {
        return MMI_TRUE;
    }
    else
    {
        SetMissedCallFlag(FALSE);
        return MMI_FALSE;
    }
}

#ifdef __MMI_NITZ__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_pending_nitz_check
 * DESCRIPTION
 *  Wrapper for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_idle_pending_nitz_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8) g_nitz_cntx.IsNITZPending;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_opname_from_nitz
 * DESCRIPTION
 *  Update NITZ network name if a new message is received
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_update_opname_from_nitz(void)
{
    if (mmi_idle_is_on_idle_screen())
    {
        EntryIdleScreen(); /* IdleRefreshServiceIndicationArea(); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_nitz_content
 * DESCRIPTION
 *  Update NITZ network name from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_update_nitz_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_display_length = MAX_LENGTH_DISPLAY_NAME;
    U8 mcc_tmp_unicode[4 * ENCODING_LENGTH];
    U8 tmp_plmn[MAX_PLMN_LEN_MMI + 1];
    U8 tmp_display_name[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];

    U8 iCnt = 0;
    S32 StringWidth, StringHeight;
    stFontAttribute prev_f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tmp_plmn, 0 , MAX_PLMN_LEN_MMI + 1);
    memset(tmp_display_name, 0, MAX_LENGTH_DISPLAY_NAME);

    mmi_nitz_get_nitz_nw_name(tmp_plmn, tmp_display_name, (U8) MAX_LENGTH_DISPLAY_NAME - 1, &g_nitz_display.country_init);

    if (strlen((S8*)tmp_plmn) != 0 && strlen((S8*)tmp_display_name) != 0)
    {
    	strcpy((S8*)g_nitz_display.plmn, (S8*)tmp_plmn);
        if (g_nitz_display.country_init)
        {
            max_display_length -= 4;    /* 1 space char and 3 mcc digits */
        }
        
        if (mmi_ucs2strlen((S8*) tmp_display_name) >= max_display_length)
        {
            mmi_ucs2ncpy((S8*) g_nitz_display.display_name, (S8*) tmp_display_name, max_display_length);
        }
        else
        {
            mmi_ucs2cpy((S8*) g_nitz_display.display_name, (S8*) tmp_display_name);
        }

        /* add check if the NITZ display name exceeds the LCD width */
        memcpy(&prev_f, UI_font, sizeof(stFontAttribute));
        UI_set_font(&UI_DEFAULT_FONT);
        for (iCnt = (U8) mmi_ucs2strlen((PS8) g_nitz_display.display_name); iCnt > 0; iCnt--)
        {
            Get_StringWidthHeight((U8*) g_nitz_display.display_name, &StringWidth, &StringHeight);
            if ((StringWidth + 1) >= MAIN_LCD_device_width - (MMI_IDLE_STRING_MARGIN_GAP << 1))
            {
                g_nitz_display.display_name[iCnt * ENCODING_LENGTH] = 0x0;
                g_nitz_display.display_name[iCnt * ENCODING_LENGTH + 1] = 0x0;
            }
            else
            {
                break;
            }
        }
        UI_set_font(&prev_f);

        if (g_nitz_display.country_init)
        {
            mmi_asc_n_to_ucs2((S8*) mcc_tmp_unicode, (S8*) g_nitz_display.plmn, 3);
            mmi_ucs2cat((S8*) g_nitz_display.display_name, " ");
            mmi_ucs2cat((S8*) g_nitz_display.display_name, (S8*) mcc_tmp_unicode);
        }

        g_nitz_display.opname_from_nitz = 1;
    }
    else
    {
        g_nitz_display.opname_from_nitz = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_check_nitz_display_validation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_idle_check_nitz_display_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp(g_nitz_display.plmn, gPLMN, MAX_PLMN_LEN_MMI) != 0)
    {
        g_nitz_display.opname_from_nitz = 0;
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_sim2_nitz_content
 * DESCRIPTION
 *  Update NITZ network name from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_update_sim2_nitz_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_display_length = MAX_LENGTH_DISPLAY_NAME;
    U8 mcc_tmp_unicode[4 * ENCODING_LENGTH];
    U8 tmp_plmn[MAX_PLMN_LEN_MMI + 1];
    U8 tmp_display_name[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];

    U8 iCnt = 0;
    S32 StringWidth, StringHeight;
    stFontAttribute prev_f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tmp_plmn, 0 , MAX_PLMN_LEN_MMI + 1);
    memset(tmp_display_name, 0, MAX_LENGTH_DISPLAY_NAME);

    mmi_nitz_get_nitz_nw_name_sim2(tmp_plmn, tmp_display_name, (U8) MAX_LENGTH_DISPLAY_NAME - 1, &g_nitz_display_2.country_init);

    if (strlen((S8*)tmp_plmn) != 0 && strlen((S8*)tmp_display_name) != 0)
    {
    	strcpy((S8*)g_nitz_display_2.plmn, (S8*)tmp_plmn);
        if (g_nitz_display_2.country_init)
        {
            max_display_length -= 4;    /* 1 space char and 3 mcc digits */
        }
        
        if (mmi_ucs2strlen((S8*) tmp_display_name) >= max_display_length)
        {
            mmi_ucs2ncpy((S8*) g_nitz_display_2.display_name, (S8*) tmp_display_name, max_display_length);
        }
        else
        {
            mmi_ucs2cpy((S8*) g_nitz_display_2.display_name, (S8*) tmp_display_name);
        }

        /* add check if the NITZ display name exceeds the LCD width */
        memcpy(&prev_f, UI_font, sizeof(stFontAttribute));
        UI_set_font(&UI_DEFAULT_FONT);
        for (iCnt = (U8) mmi_ucs2strlen((PS8) g_nitz_display_2.display_name); iCnt > 0; iCnt--)
        {
            Get_StringWidthHeight((U8*) g_nitz_display_2.display_name, &StringWidth, &StringHeight);
            if ((StringWidth + 1) >= MAIN_LCD_device_width - (MMI_IDLE_STRING_MARGIN_GAP << 1))
            {
                g_nitz_display_2.display_name[iCnt * ENCODING_LENGTH] = 0x0;
                g_nitz_display_2.display_name[iCnt * ENCODING_LENGTH + 1] = 0x0;
            }
            else
            {
                break;
            }
        }
        UI_set_font(&prev_f);

        if (g_nitz_display_2.country_init)
        {
            mmi_asc_n_to_ucs2((S8*) mcc_tmp_unicode, (S8*) g_nitz_display_2.plmn, 3);
            mmi_ucs2cat((S8*) g_nitz_display_2.display_name, " ");
            mmi_ucs2cat((S8*) g_nitz_display_2.display_name, (S8*) mcc_tmp_unicode);
        }

        g_nitz_display_2.opname_from_nitz = 1;
    }
    else
    {
        g_nitz_display_2.opname_from_nitz = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_check_sim2_nitz_display_validation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_idle_check_sim2_nitz_display_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp(g_nitz_display_2.plmn, gPLMN_2, MAX_PLMN_LEN_MMI) != 0)
    {
        g_nitz_display_2.opname_from_nitz = 0;
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MMI_NITZ__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_widget_check_and_display_new_msg
 * DESCRIPTION
 *  Wrapper for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
static U8 mmi_idle_widget_check_and_display_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check WNOTI_CTX->check_msg_in_idle_screen first */
    widget_check_msg_in_idle_screen();
    if (g_keylock_context.gKeyPadLockFlag)
    {
        if (widget_MMI_check_and_display_new_msg_when_keypad_lock
            (g_keylock_context.KeyLockLSKStringID, g_keylock_context.KeyLockLSKIconID,
             g_keylock_context.KeyLockRSKStringID, g_keylock_context.KeyLockRSKIconID))
        {
            /* Check WNOTI_CTX->check_msg_in_idle_screen again */
            widget_check_msg_in_idle_screen();
            return MMI_TRUE;
        }
    }
    else
    {
        if (widget_MMI_check_and_display_new_msg())
        {
            /* Check WNOTI_CTX->check_msg_in_idle_screen again */
            widget_check_msg_in_idle_screen();
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif /* defined(OBIGO_Q03C) && defined(WAP_SUPPORT) && !defined (__UNIFIED_MSG_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_pen_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_idle_pen_block(void)
{
#ifndef __MMI_GPIO_DISABLE_SLEEP_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern BOOL gIsInSleepMode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gIsInSleepMode != 1)
#endif /* __MMI_GPIO_DISABLE_SLEEP_MODE__ */ 
        mmi_pen_block();
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_keypad_lock_string
 * DESCRIPTION
 *  This function is used to set keypad lock RSK string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_keypad_lock_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_keylock_context.KeyLockRSKStringID = 0;
    g_keylock_context.KeyLockRSKIconID = 0;
    g_keylock_context.KeyLockLSKStringID = 0;
    g_keylock_context.KeyLockLSKIconID = 0;

    if (g_idle_context.IsOnIdleScreen == 1 || g_idle_context.IsOnSimErrorScreen == 1)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK);
    #else 
        ShowStatusIcon(STATUS_ICON_KEYPAD_LOCK);
    #endif 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    #ifdef __MMI_TOUCH_SCREEN__
        g_keylock_context.KeyLockRSKStringID = SCREEN_LOCKED_TEXT;
    #else 
        g_keylock_context.KeyLockRSKStringID = KEYPAD_LOCKED_RSK_TEXT;
    #endif 
    #endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    #ifdef __MMI_TOUCH_SCREEN__
        g_keylock_context.KeyLockLSKStringID = SCREEN_LOCKED_TEXT;
    #else 
        g_keylock_context.KeyLockLSKStringID = KEYPAD_LOCKED_RSK_TEXT;
    #endif 
    #endif /* __MMI_KEYPAD_LOCK_PATTERN_2__ */ 
    }
    else
    {
        /* If active screen is not idle, pen is not blocked */
        /* Set RSK/LSK string to "unlock" because it is allowed to click the touch screen to unlock */
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        g_keylock_context.KeyLockRSKStringID = KEYPAD_LOCKED_RSK_TEXT;
    #endif 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        g_keylock_context.KeyLockLSKStringID = KEYPAD_LOCKED_RSK_TEXT;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_dummy_key_handler
 * DESCRIPTION
 *  This function is a dummy handler for idle screen keys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static FuncPtr dummyKeyHandler[MAX_KEYS];
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
/*shaokai modify it start 090907*/
void mmi_idle_dummy_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ScreenSaverStatus, ScreenSaverWait;
    U16 keyCode, keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetGetScrSvrSetings(&ScreenSaverStatus, &ScreenSaverWait);

    GetkeyInfo(&keyCode, &keyType);

    if (g_idle_context.IsOnIdleScreen)
    {
        /* postpone the screensaver after press keys */
        if (dummyKeyHandler[keyCode] != NULL && !g_keylock_context.gKeyPadLockFlag)
        {
#if defined(WIN32)
//Huyanwei Add It For Send2 Key ,Left key IN One
			   if ((keyCode == KEY_LSK) && (dummyKeyHandler[KEY_SEND1] != NULL)&&( currKeyFuncPtrs[KEY_SEND1][keyType] != NULL )  && (MTPNP_AD_Get_Startup_Mode() != MTPNP_AD_NVRAM_FLIGHT))
            		{
				(*dummyKeyHandler[KEY_SEND1]) ();
			}
#else
		     if ((keyCode == KEY_LSK) && (dummyKeyHandler[KEY_SEND1] != NULL)&&( currKeyFuncPtrs[KEY_SEND1][keyType] != NULL )  && (MTPNP_AD_Get_Startup_Mode() != MTPNP_AD_NVRAM_FLIGHT))
            		{            			
				(*dummyKeyHandler[KEY_SEND1]) ();
			}
#endif
			else
			{
            (*dummyKeyHandler[keyCode]) ();
        }
        }

        if (keyCode == KEY_ENTER && !g_keylock_context.gKeyPadLockFlag)
        {
            ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
        }
    }

    if (g_idle_context.IsOnIdleScreen)
    {
        StopTimer(SCREENSAVER_TIMER);
        StartTimer(SCREENSAVER_TIMER, ScreenSaverWait * 1000, EntryIdleSetScreenSaver);
    }
}
/*shaokai modify it end 090907*/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_date_time_reminder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_date_time_reminder(void)
{
#if defined(__MMI_DATE_TIME_SETTING_REMINDER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static BOOL datejust_reminder_shown = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!datejust_reminder_shown && RTC_is_MS_FirstPowerOn())
    {
        DisplayPopup((PU8) GetString(STR_DATE_TIME_UPDATE_REMINDER), IMG_GLOBAL_OK, 0, 2000, 0);
        datejust_reminder_shown = MMI_TRUE;
    }
#endif /* defined(__MMI_DATE_TIME_SETTING_REMINDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_dummy_key_in_screensaver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_dummy_key_in_screensaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 ScreenSaverStatus, ScreenSaverWait;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsClamClose())
    {
        return ;
    }

    PhnsetGetScrSvrSetings(&ScreenSaverStatus, &ScreenSaverWait);
    /* Compensatory key handler registration for screen saver.             */
    /* The idea here is to set those keys which are not set with handlers to a dummy handler. */
    /* But not that END key is still being set a handler (DisplayIdleScreen)        */
    /* for KEY_EVENT_DOWN in PowerAndEndKeyHandler.                  */
    if (g_keylock_context.gKeyPadLockFlag)
    {
        if (ScreenSaverStatus == 1) /* Screensaver is set to on */
        {
            for (i = KEY_0; i < MAX_KEYS; i++)
            {
                if ((GetKeyHandler(i, KEY_EVENT_DOWN) == NULL) && (GetKeyHandler(i, KEY_EVENT_UP) == NULL))
                {
                    SetKeyHandler(mmi_idle_dummy_key_handler, i, KEY_EVENT_DOWN);
                }
            }
            /*  add this because of PowerAndEndKeyHandler */
        #ifndef __MMI_KEYPAD_LOCK_PROMPT_TEXT__
            /* diamond, 2005/12/20 END key is registered to prompt text if __MMI_KEYPAD_LOCK_PROMPT_TEXT__ is on */
            SetKeyHandler(mmi_idle_dummy_key_handler, KEY_END, KEY_EVENT_DOWN);
        #endif /* __MMI_KEYPAD_LOCK_PROMPT_TEXT__ */ 
        }
    }
    else
    {
        if (ScreenSaverStatus == 1) /* Screensaver is set to on */
        {
            for (i = KEY_0; i < MAX_KEYS; i++)
            {
                if (i == KEY_ENTER && GetKeyHandler(i, KEY_EVENT_UP) == NULL && GetKeyHandler(i, KEY_EVENT_DOWN) == NULL && GetKeyHandler(i, KEY_LONG_PRESS) == NULL)
                {
                #ifndef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
                    dummyKeyHandler[i] = dummyKeyHandler[KEY_LSK];
                    SetKeyHandler(mmi_idle_dummy_key_handler, i, KEY_EVENT_DOWN);
                #endif
                    continue;
                }
                dummyKeyHandler[i] = GetKeyHandler(i, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_idle_dummy_key_handler, i, KEY_EVENT_DOWN);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_eg_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void nor_sweep_device(void);

static void mmi_idle_set_eg_events(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL egIsSet = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!egIsSet)
    {
        nor_sweep_device();
        egIsSet = 1;
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_start_keypad_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_start_keypad_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_set_eg_events();

    if (!g_keylock_context.gKeyPadLockFlag) /* keypad isn't lock now */
    {
        SETTING_AKPL_TIME GetAutoLockTimeOut = GetAutoKeypadLockTime();

        switch (GetAutoLockTimeOut)
        {
            case TIME_0:
                g_idle_context.AutoLockTimeOut = 0;
                break;
            case TIME_5:
                g_idle_context.AutoLockTimeOut = 5000;
                break;
            case TIME_30:
                g_idle_context.AutoLockTimeOut = 30000;
                break;
            case TIME_60:
                g_idle_context.AutoLockTimeOut = 60000;
                break;
            case TIME_2:
                g_idle_context.AutoLockTimeOut = 300000;
                break;
        }

        if (g_idle_context.AutoLockTimeOut != 0)
        {
            PRINT_INFORMATION("[Keypad Lock] mmi_idle_start_keypad_lock: Timer %d start", g_idle_context.AutoLockTimeOut);
            if (mmi_idle_is_on_idle_screen())
            {
                StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, IdleSetKeyPadLockFlag);
            }
            else
            {
                StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, InsertSimSetKeyPadLockFlag);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_restart_keypad_lock_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_restart_keypad_lock_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag == 1)
    {
        return;
    }

    if (g_idle_context.AutoLockTimeOut != 0 &&
        (g_idle_context.IsOnIdleScreen == 1 || g_idle_context.IsOnSimErrorScreen == 1))
    {
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
        if (g_idle_context.IsOnIdleScreen == 1)
        {
            StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, IdleSetKeyPadLockFlag);
        }
        if (g_idle_context.IsOnSimErrorScreen == 1)
        {
            StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, InsertSimSetKeyPadLockFlag);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_start_screensaver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_start_screensaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ScreenSaverStatus, ScreenSaverWait;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetGetScrSvrSetings(&ScreenSaverStatus, &ScreenSaverWait);

    if (ScreenSaverStatus == 0xFF)
    {
        PhnsetRstScrSvrDefault();
    }

    if (ScreenSaverStatus == 1) /* Screensaver is set to on */
    {
        StartTimer(SCREENSAVER_TIMER, ScreenSaverWait * 1000, EntryIdleSetScreenSaver);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_restart_screensaver_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_restart_screensaver_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ScreenSaverStatus, ScreenSaverWait;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.ScreenSaverRunFlag == 1) /* screensaver is running */
    {
        return;
    }

    if (g_idle_context.IsOnIdleScreen == 1)
    {
        PhnsetGetScrSvrSetings(&ScreenSaverStatus, &ScreenSaverWait);
        if (ScreenSaverStatus == 0xFF)
        {
            PhnsetRstScrSvrDefault();
        }

        if (ScreenSaverStatus == 1) /* screensaver is active */
        {
            StopTimer(SCREENSAVER_TIMER);
            StartTimer(SCREENSAVER_TIMER, ScreenSaverWait * 1000, EntryIdleSetScreenSaver);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_on_idle_screen
 * DESCRIPTION
 *  Is on idle screen?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_idle_is_on_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.IsOnIdleScreen == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_screensaver_running
 * DESCRIPTION
 *  Is screensaver running?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_idle_is_screensaver_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.ScreenSaverRunFlag == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


// Huyanwei Add It 090902
extern void EntrySlaveReadCallHistoryBySend(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_idle_screen
 * DESCRIPTION
 *  Idle screen with/without keypad lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IdleRefreshServiceIndicationArea(); /* Refresh Service Indication Area */

#if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif 

#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
    if (!mmi_idle_is_display_touch_shortcuts())
    {
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    }
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */

#ifdef __MMI_SWFLASH__
    if (dispchar_iswp_swflash() == MMI_TRUE)
    {
        ShowCategory34Screen(
            IDLE_SCREEN_LSK_TEXT, 
            IDLE_SCREEN_LSK_ICON, 
            idleLRStringtID, 
            IDLE_SCREEN_RSK_ICON, 
            PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
    }
    else
#endif /* _MMI_SWFLASH__ */
#ifdef __MMI_AVATAR__
    if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
    {
        ShowCategory34Screen(
            IDLE_SCREEN_LSK_TEXT, 
            IDLE_SCREEN_LSK_ICON, 
            idleLRStringtID, 
            IDLE_SCREEN_RSK_ICON, 
            PhnsetGetCurWallPaperIdx(), NULL, NULL);
    }
    else
#endif /* __MMI_AVATAR__ */
    {
    #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
        ShowCategory33Screen(IDLE_SCREEN_RSK_TEXT, IDLE_SCREEN_RSK_ICON, idleLRStringtID, IDLE_SCREEN_LSK_ICON, NULL);
    #else 
        ShowCategory33Screen(IDLE_SCREEN_LSK_TEXT, IDLE_SCREEN_LSK_ICON, idleLRStringtID, IDLE_SCREEN_RSK_ICON, NULL);
    #endif 
        mmi_phnset_save_wallpaper_to_speedup();
    }

    g_idle_context.LongPressEnable = 0;

    SetGroupKeyHandler(HandleIdleScreenDigitEntry, IdleScreenDigits, MAX_IDLE_SCREEN_DIGITS - 1, KEY_EVENT_DOWN);
    IdleSetLRKey();

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_status_icon_pen_event_hdlr(
        STATUS_ICON_KEYPAD_LOCK,
        WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
        IdleSetKeyPadLockFlag);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    SetCenterSoftkeyFunction(IdleScreenDigitHandler, KEY_EVENT_UP);
#endif 

#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
    if (!mmi_idle_is_display_touch_shortcuts())
    {
        SetCenterSoftkeyFunction(IdleScreenDigitHandler, KEY_EVENT_UP);
    }
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */

#ifdef __MMI_TOUCH_DIAL_SCREEN__
    memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
#endif 

    /* Voice Recognition */
#if defined(__MMI_VRSD__)
    SetRightSoftkeyFunction(mmi_vrsd_rcg_pre_entry, KEY_LONG_PRESS);
#endif 

#if defined(__MMI_VRSI__)
    SetRightSoftkeyFunction(mmi_vrsi_rcg_pre_entry, KEY_LONG_PRESS);
#endif 

    /* for 4-dedicated shortcuts */
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    RegisterDedicatedKeyHandlers();
#elif !defined(__DISABLE_SHORTCUTS_MENU__)
    SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
#endif 

    /* sync the behavior with DisplayIdleScreen */
    CHISTResetCallLogIndex();

#ifdef __MMI_KLG__
    SetKeyHandler(fmgr_launch, KEY_EXTRA_1, KEY_EVENT_UP);
    SetKeyHandler(ClndrPreEntryApp, KEY_EXTRA_2, KEY_EVENT_UP);
#endif /* __MMI_KLG__ */ 

#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    SetKeyHandler(EntryCHISTTabPaneIdleScreen, KEY_SEND, KEY_EVENT_DOWN);       /* diamond, 2005/09/13 key event DOWN to UP */
#else /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
#ifdef __MMI_DUAL_SIM_MASTER__
#ifdef __SENDKEY2_SUPPORT__
    if ((MTPNP_AD_Get_UsableSide() ==MTPNP_AD_DUALSIM_USABLE) ||(MTPNP_AD_Get_UsableSide() ==MTPNP_AD_SIMCARD1_USABLE))
    {
        SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND1, KEY_EVENT_DOWN);
    }
    if ((MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) || (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE))
    {
        #if defined(WIN32)
	  // Huyanwei Add It For Test Call History On PC 
        // SetKeyHandler(EntrySlaveReadCallHistoryBySend, KEY_SEND1, KEY_EVENT_DOWN);
	#else
	 //SetKeyHandler(MTPNP_PFAL_chist_slave_req_read_mixed_num_by_key, KEY_SEND2, KEY_EVENT_DOWN);
         SetKeyHandler(EntrySlaveReadCallHistoryBySend, KEY_SEND2, KEY_EVENT_DOWN);
	#endif
    }
#else /* __SENDKEY2_SUPPORT__ */
    if ((MTPNP_AD_Get_UsableSide() ==MTPNP_AD_DUALSIM_USABLE) ||(MTPNP_AD_Get_UsableSide() ==MTPNP_AD_SIMCARD1_USABLE) ||(MTPNP_AD_Get_UsableSide() ==MTPNP_AD_SIMCARD2_USABLE))
    {
        SetKeyHandler(MTPNP_PFAL_ReadDualMixedCallLog, KEY_SEND, KEY_EVENT_DOWN);  /* diamond, 2005/09/13 key event DOWN to UP */
    }
#endif /* __SENDKEY2_SUPPORT__ */
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND, KEY_EVENT_DOWN);  /* diamond, 2005/09/13 key event DOWN to UP */
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 

#if defined(WAP_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)
#ifdef __MMI_OP01_WITH_WAP_KEY__
    SetKeyHandler(mmi_idle_entry_internet_confirm, KEY_WAP, KEY_EVENT_UP);
#else
    SetKeyHandler(wap_internet_key_hdlr, KEY_WAP, KEY_LONG_PRESS);
#endif
#endif 

    /* camera fast access key */
#ifdef __MMI_CAMERA__
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
    #ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose())
        SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    else
        SetKeyHandler(mmi_camera_entry_app_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    #else
    SetKeyHandler(mmi_camera_entry_app_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    #endif
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */
#endif /* __MMI_CAMERA__ */

    /* volume key */
    SetDefaultVolumeKeyHandlers();

    ForceSubLCDScreen(ShowIdleAppSubLcd);

    /* 
     * Compensatory key handler registration for screen saver
     * The idea here is to set those keys which are not set with handlers to a dummy handler. 
     * But not that END key is still being set a handler (DisplayIdleScreen)  for KEY_EVENT_DOWN in PowerAndEndKeyHandler. 
     */
    mmi_idle_dummy_key_in_screensaver();

#ifdef __FLIGHT_MODE_SUPPORT__
    mmi_flight_mode_need_play_camp_on_tone();
#endif

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
    {
    #ifdef __MMI_UCM__
        mmi_idle_set_dial_mode(DIAL_MODE_WLAN);
    #else
        mmi_netset_set_dial_mode(DIAL_MODE_WLAN);
    #endif
    }
    else
    {
    #ifdef __MMI_UCM__
        mmi_idle_set_dial_mode(DIAL_MODE_GSM);
    #else
        mmi_netset_set_dial_mode(DIAL_MODE_GSM);
    #endif
    }
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_searching_screen
 * DESCRIPTION
 *  Searching screen with/without keypad lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_searching_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_keylock_context.gKeyPadLockFlag)
    {
        /* diamond, 2005/07/22 240x320 sync searching screen style with idle screen style */
    #ifdef __MMI_IDLE_NO_NW_SEARCHING_SCREEN__
        IdleRefreshServiceIndicationArea();
        
    #ifdef __MMI_SWFLASH__
        if (dispchar_iswp_swflash() == MMI_TRUE)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                idleLRStringtID, 
                IDLE_SCREEN_RSK_ICON, 
                PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
        }
        else
    #endif /* _MMI_SWFLASH__ */
    #ifdef __MMI_AVATAR__
        if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                idleLRStringtID, 
                IDLE_SCREEN_RSK_ICON, 
                PhnsetGetCurWallPaperIdx(), NULL, NULL);
        }
        else
    #endif /* __MMI_AVATAR__ */
        {
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            ShowCategory33Screen(IDLE_SCREEN_RSK_TEXT, IDLE_SCREEN_RSK_ICON, idleLRStringtID, IDLE_SCREEN_LSK_ICON, NULL);
        #else 
            ShowCategory33Screen(IDLE_SCREEN_LSK_TEXT, IDLE_SCREEN_LSK_ICON, idleLRStringtID, IDLE_SCREEN_RSK_ICON, NULL);
        #endif 
            mmi_phnset_save_wallpaper_to_speedup();
        }
    #else /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */
    #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
        ShowCategory120Screen(
            IDLE_SCREEN_RSK_TEXT,
            0,
            IDLE_SCREEN_LSK_TEXT,
            0,
            STR_IDLE_NETWORK_SRCH_SCR,
            IMG_IDLE_NETWORK_SRCH_SCR,
            NULL);
    #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
        ShowCategory120Screen(
            IDLE_SCREEN_LSK_TEXT,
            0,
            IDLE_SCREEN_RSK_TEXT,
            0,
            STR_IDLE_NETWORK_SRCH_SCR,
            IMG_IDLE_NETWORK_SRCH_SCR,
            NULL);
    #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
    #endif /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */ 
        /* end, diamond */

        SetGroupKeyHandler(HandleIdleScreenDigitEntry, IdleScreenDigits, MAX_IDLE_SCREEN_DIGITS - 1, KEY_EVENT_DOWN);
        g_idle_context.LongPressEnable = 0;

    #ifdef __MMI_TOUCH_DIAL_SCREEN__
        memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
    #endif 

    #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
        SetRightSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
    #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
        SetLeftSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
    #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 

#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
    #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
        SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_idle_enter_phb_list, KEY_LSK, KEY_EVENT_UP);
    #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
        SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_idle_enter_phb_list, KEY_RSK, KEY_EVENT_UP);
    #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */

        /* Voice Recognition */
    #if defined(__MMI_VRSD__)
        SetRightSoftkeyFunction(mmi_vrsd_rcg_pre_entry, KEY_LONG_PRESS);
    #endif 

    #if defined(__MMI_VRSI__)
        SetRightSoftkeyFunction(mmi_vrsi_rcg_pre_entry, KEY_LONG_PRESS);
    #endif 

    #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        RegisterDedicatedKeyHandlers();
    #elif !defined(__DISABLE_SHORTCUTS_MENU__)
        SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
    #endif 

    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        SetKeyHandler(EntryCHISTTabPaneIdleScreen, KEY_SEND, KEY_EVENT_DOWN);       /* diamond, 2005/09/13 key event DOWN to UP */
    #else /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    #ifdef __MMI_DUAL_SIM_MASTER__
    #ifdef __SENDKEY2_SUPPORT__
        if (MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_VALID)
        {
            SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND, KEY_EVENT_DOWN);
        }
        if (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_VALID)
        {
			//Huyanwei Modify it For PC Debug
           #if defined(WIN32)			
           		SetKeyHandler(EntrySlaveReadCallHistoryBySend, KEY_SEND1, KEY_EVENT_DOWN);
           #else			
			//SetKeyHandler(MTPNP_PFAL_chist_slave_req_read_mixed_num_by_key, KEY_SEND2, KEY_EVENT_DOWN);
			SetKeyHandler(EntrySlaveReadCallHistoryBySend, KEY_SEND2, KEY_EVENT_DOWN);			
	    #endif		   
        }
    #else /* __SENDKEY2_SUPPORT__ */
        if (!(MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD && 
              MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_VALID &&
              MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_VALID))
        {
            SetKeyHandler(MTPNP_PFAL_ReadDualMixedCallLog, KEY_SEND, KEY_EVENT_DOWN);  /* diamond, 2005/09/13 key event DOWN to UP */
        }
    #endif /* __SENDKEY2_SUPPORT__ */
    #else /* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND, KEY_EVENT_DOWN);  /* diamond, 2005/09/13 key event DOWN to UP */
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 

    #if defined(WAP_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)
    #ifdef __MMI_OP01_WITH_WAP_KEY__
        SetKeyHandler(mmi_idle_entry_internet_confirm, KEY_WAP, KEY_EVENT_UP);
    #else
        SetKeyHandler(wap_internet_key_hdlr, KEY_WAP, KEY_LONG_PRESS);
    #endif
    #endif 

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_status_icon_pen_event_hdlr(
            STATUS_ICON_KEYPAD_LOCK,
            WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
            IdleSetKeyPadLockFlag);
    #endif /* __MMI_TOUCH_SCREEN__ */

        ForceSubLCDScreen(ShowIdleAppSubLcd);
    }
    else
    {
        /* diamond, 2005/07/22 240x320 sync searching screen style with idle screen style */
        mmi_idle_set_keypad_lock_string();

    #ifdef __MMI_IDLE_NO_NW_SEARCHING_SCREEN__
        IdleRefreshServiceIndicationArea();
    #ifdef __MMI_SWFLASH__
        if (dispchar_iswp_swflash() == MMI_TRUE)
        {
            ShowCategory34Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
         }
         else
    #endif /* _MMI_SWFLASH__ */        
    #ifdef __MMI_AVATAR__
        if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
        {
            ShowCategory34Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                PhnsetGetCurWallPaperIdx(), NULL, NULL);
        }
        else
    #endif /* __MMI_AVATAR__ */
        {
            ShowCategory33Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                NULL);
            mmi_phnset_save_wallpaper_to_speedup();
        }
    #else /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */ 
        ShowCategory120Screen(
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            STR_IDLE_NETWORK_SRCH_SCR,
            IMG_IDLE_NETWORK_SRCH_SCR,
            NULL);
    #endif /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */ 
        /* end, diamond */

        /* diamond, 2006/06/09 Generic exit function for keypad lock callback screens */
        g_keylock_context.keypad_lock_screen_exit = GetCurrExitFuncPtr();
        SetCurrExitFuncPtr(mmi_idle_generic_keypad_lock_screen_exit_hdlr);

    #ifdef __MMI_TOUCH_SCREEN__
        mmi_idle_pen_block();
        SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);
    #else /* __MMI_TOUCH_SCREEN__ */ 
        SetRightSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_DOWN);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_key_event_backlight_check
 * DESCRIPTION
 *  Check backlight when key event occurs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_key_event_backlight_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_keylock_context.gKeyPadLockFlag && (g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen)) ||
        (g_keylock_context.gKeyPadLockFlag && g_idle_context.ScreenSaverRunFlag))
    {
        HalfModeBacklight();
    }
    else
    {
        TurnOnBacklight(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_key_event_keypad_lock_check
 * DESCRIPTION
 *  Handle the case of keypad timer is running in idle screen but the key event is not POUND key
 * PARAMETERS
 *  eventKey                [?]         
 *  KEYBRD_MESSAGE(?)       [IN]        *eventKey
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_key_event_keypad_lock_check(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsMyTimerExist(KEYPAD_LOCK_TIMER) == MMI_TRUE)
    {
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        if ((S16) eventKey->nKeyCode != KEY_POUND)
        {
            IdleHandleKeypadLockProcess();
        }
    #endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        if ((S16) eventKey->nKeyCode != KEY_STAR)
        {
            IdleHandleKeypadLockProcess();
        }
    #endif /* __MMI_KEYPAD_LOCK_PATTERN_2__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeInitSpecialMode
 * DESCRIPTION
 *  DeInit Special Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if (defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))
U8 gCurrentMode = NORMAL_MODE;
#endif 

/* Reset special function for special mode */
void DeInitSpecialMode(void)
{
#ifdef __MMI_ENGINEER_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gCurrentMode == ENGINEERING_MODE)
    {
        gCurrentMode = NORMAL_MODE;
        mdi_audio_resume_background_play();
        StartLEDPatternBackGround();
    }
#endif /* __MMI_ENGINEER_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SearchingSrceenTimeOutHandler
 * DESCRIPTION
 *  This function is a call back for searching screen expire
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SearchingSrceenTimeOutHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (!g_pwr_context.IsCampOnTonePlayed &&
        !g_pwr_context_2.IsCampOnTonePlayed &&
         mmi_bootup_is_in_sim2_security_check())
    {
        StartTimer(SEARCHING_SCREEN_TIMER, 10000, SearchingSrceenTimeOutHandler);
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG; /* 0x01: network attachment timeout */
    g_pwr_context.IsCampOnTonePlayed = 1; /* Camp on tone will not be played after the timeout */
#ifdef __MMI_DUAL_SIM_MASTER__
    g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
    g_pwr_context_2.IsCampOnTonePlayed = 1;
#endif

    if (g_idle_context.IsOnIdleScreen)
    {
        mmi_bootup_exit_network_searching();
    }

}


/*****************************************************************************
 * FUNCTION
 *  DisplayIdleScreen
 * DESCRIPTION
 *  Shows the idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern U8 gCallCost;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* highlight indexes should be reset when press end key for the call history module */
    gCallCost = 0;

    CHISTResetCallLogIndex();

    /* Execute the root history */
    ExecuteRootMainHistoryScreen(NULL);

    OrgDeInit();

#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    mmi_vobj_deinit();
#endif 

    AlmEnableSPOF();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_bootup_ready_to_certman
 * DESCRIPTION
 *  Send message to Certificate Manager for idle screen notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_bootup_ready_to_certman(void)
{
#ifdef __CERTMAN_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_CERTMAN;
    Message.oslMsgId = MSG_ID_MMI_READY_NOTIFY_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* WAP_SUPPORT */ 
}


#ifdef __MMI_DUAL_SIM_MASTER__
void mmi_idle_notify_dual_sim_status_to_wap(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_sim_info_notify_ind_struct *sim_info_notify_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_info_notify_ind = (wap_sim_info_notify_ind_struct *) OslConstructDataPtr(sizeof(wap_sim_info_notify_ind_struct));

    if (mmi_bootup_is_sim_valid())
    {
        if (mmi_bootup_is_sim2_valid())
        {
            sim_info_notify_ind->sim_status = WAP_SIM_ID_DUAL_SIM;
        }
        else
        {
            sim_info_notify_ind->sim_status = WAP_SIM_ID_SIM1;
        }
    }
    else
    {
        if (mmi_bootup_is_sim2_valid())
        {
            sim_info_notify_ind->sim_status = WAP_SIM_ID_SIM2;
        }
        else
        {
            sim_info_notify_ind->sim_status = WAP_SIM_ID_NO_SIM;
        }
    }

    switch(MTPNP_AD_Get_Startup_Mode())
    {
        case MTPNP_AD_NVRAM_CARD1:
            sim_info_notify_ind->setting_mode = WAP_SIM_ID_SIM1;
        break;

        case MTPNP_AD_NVRAM_CARD2:
            sim_info_notify_ind->setting_mode = WAP_SIM_ID_SIM2;
        break;

        case MTPNP_AD_NVRAM_FLIGHT:
            sim_info_notify_ind->setting_mode = WAP_SIM_ID_FLIGHT_MODE;
        break;

        case MTPNP_AD_NVRAM_DUALCARD:
        default:
            sim_info_notify_ind->setting_mode = WAP_SIM_ID_DUAL_SIM;
        break;
    }
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_SIM_INFO_NOTIFY_IND;
    Message.oslDataPtr = (oslParaType*) sim_info_notify_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* WAP_SUPPORT */ 
}
#endif /* __MMI_DUAL_SIM_MASTER__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_bootup_ready_to_wap
 * DESCRIPTION
 *  Send message to WAP for idle screen notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_bootup_ready_to_wap(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL wap_ready_sent = MMI_FALSE;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_ready_sent)
    {
        return;
    }

    wap_ready_sent = MMI_TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_MMI_READY_NOTIFY_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  CheckAndStopAudioPlayer
 * DESCRIPTION
 *  Stop audio player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
extern BOOL DirectMode;
#endif 

extern void MMI_notify_bootup_ready(void);

#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
static void CheckAndStopAudioPlayer(void)
{
#ifdef __MMI_AUDIO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_is_playing())
    {
        mmi_audply_do_stop_action();
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_power_on(FALSE);
    }
    else
#endif /* __MMI_FM_RADIO__ */ 
    #ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose())
        mmi_sublcd_camera_entry_option_screen();
    else
        mmi_camera_entry_app_screen();
    #else
        mmi_camera_entry_app_screen();
    #endif 
}
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */ 


/*****************************************************************************
 * FUNCTION
 *  IdleScreenEmergencyCallCheckNKeypadLock
 * DESCRIPTION
 *  Allow dial SOS number if keypad is locked in idle screen
 * PARAMETERS
 *  eventKey        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 IdleScreenEmergencyCallCheckNKeypadLock(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag)
    {
        EmergencyCallCheck(eventKey->nKeyCode, eventKey->nMsgType);
    }

    if ((g_idle_context.AutoLockTimeOut != 0) && (g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURKEY_HDLR, g_idle_context.AutoLockTimeOut);
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
        if (g_idle_context.IsOnIdleScreen)
        {
            StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, IdleSetKeyPadLockFlag);
        }
        if (g_idle_context.IsOnSimErrorScreen)  /* diamond, 2005/10/29, keypad lock in insert sim screen */
        {
            StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, InsertSimSetKeyPadLockFlag);
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  RedrawIdleScreen
 * DESCRIPTION
 *  Entry idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IdleRefreshServiceIndicationArea();
#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) && !(defined __MMI_TOUCH_IDLESCREEN_SHORTCUTS__))
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif
    if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
    {
    #ifdef __MMI_SWFLASH__
        if (dispchar_iswp_swflash() == MMI_TRUE)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                idleLRStringtID, 
                IDLE_SCREEN_RSK_ICON, 
                PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
        }
        else
    #endif /* _MMI_SWFLASH__ */
    #ifdef __MMI_AVATAR__
        if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                idleLRStringtID, 
                IDLE_SCREEN_RSK_ICON, 
                PhnsetGetCurWallPaperIdx(), NULL, NULL);
        }
    else
    #endif /* __MMI_AVATAR__ */
        {
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            ShowCategory33Screen(IDLE_SCREEN_RSK_TEXT, IDLE_SCREEN_RSK_ICON, idleLRStringtID, IDLE_SCREEN_LSK_ICON, NULL);
        #else 
            ShowCategory33Screen(IDLE_SCREEN_LSK_TEXT, IDLE_SCREEN_LSK_ICON, idleLRStringtID, IDLE_SCREEN_RSK_ICON, NULL);
        #endif
            mmi_phnset_save_wallpaper_to_speedup();
        }
    }
    else
    {
    #ifdef __MMI_SWFLASH__
        if (dispchar_iswp_swflash())
        {
            ShowCategory34Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
        }
        else
    #endif /* _MMI_SWFLASH__ */
    #ifdef __MMI_AVATAR__
        if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
        {
            ShowCategory34Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                PhnsetGetCurWallPaperIdx(), NULL, NULL);
        }
        else
    #endif /* __MMI_AVATAR__ */
        {
            ShowCategory33Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                NULL);
            mmi_phnset_save_wallpaper_to_speedup();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_generic_keypad_lock_screen_exit_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_generic_keypad_lock_screen_exit_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gIsIdleScreenReentry)
    {
        return;
    }

    /* diamond, 2006/03/26 Generic exit function for keypad lock callback screens */
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);

#ifdef __MMI_TOUCH_SCREEN__
    ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_UNLOCK);
#else 
    HideStatusIcon(STATUS_ICON_KEYPAD_LOCK);
#endif 
    UpdateStatusIcons();
    PRINT_INFORMATION("[Keypad Lock] mmi_idle_generic_keypad_lock_screen_exit_hdlr");

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_unblock(); /* diamond, 2006/06/06 unblock pen is generic keypad lock screen exit handler */
#endif

    if (g_keylock_context.keypad_lock_screen_exit != NULL)
    {
        (*g_keylock_context.keypad_lock_screen_exit) ();
    }

}

#include "kbd_table.h"

extern void mmi_ucm_entry_call_center(void); //sc.wu DEVICE_KEY_EXT_FUNC1

void mmi_idle_calllog_key_hdr(void)    
{
    if (g_keylock_context.gKeyPadLockFlag == 0)
        mmi_ucm_entry_call_center();
}
#if 1
//Huyanwei Add it 
extern void mmi_entry_analog_tv(void);
extern void mmi_camera_entry_app_screen(void);
#ifdef  ANALOG_TV_SUPPORT
void Idle_Entry_tv(void)
{
	    if (g_keylock_context.gKeyPadLockFlag == 0)
	    {
	    	mmi_entry_analog_tv();
	    }
}
#endif 

/* 2009.05.06 modified by hongzhe.liu for function key + */
extern void mmi_audply_check_fmr_state_idle();
void Idle_Entry_audioplayer(void)
{
    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
    	mmi_audply_check_fmr_state_idle( );
    }
}

void Idle_Entry_MsgCenter()
{
	if (g_keylock_context.gKeyPadLockFlag == 0)
	{
		EntryScrMessagesMenuList();
	}
}


#if  (defined(RDA5800) || defined(RDA5802) || defined(RDA5802E)|| defined(RDA5803))   
extern void mmi_fmrdo_stop_audply(void );
void Idle_Entry_fm(void)
{
    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
    	mmi_fmrdo_stop_audply( );
    }
}
#endif
/* 2009.05.06 modified by hongzhe.liu for function key - */

void Idle_Entry_Camera(void)
{
	if (g_keylock_context.gKeyPadLockFlag == 0)
	{
		mmi_camera_entry_app_screen();
	}	
}

#endif

#if (defined(G_SENSOR_SUPPORT) || defined(HORSERACE_SUPPORT) || defined( __DIRECTION_SENSOR_SUPPORT__))
//Huyanwei Add It 

#if !defined(_STACK_MSGS_H)
#include "stack_msgs.h"
#endif
#include "AudioPlayerResDef.h"
#include "TimerEvents.h"

#endif


#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
#include "FSL_MMA.h"
extern VINT8 paraX ;
extern VINT8 paraY ;
extern VINT8 paraZ ;

extern void ReadData_GSensor(void) ;

typedef unsigned char VUINT8;

#include "TimerEvents.h"
#include "CallManagementStructEX.h"

extern U16 GetActiveScreenId(void);
extern VUINT8 Turn_Sense(void);
extern char GetXValue_GSensor(void);
extern char GetYValue_GSensor(void);
extern char GetZValue_GSensor(void);
extern CALL_STATE GetCurrentState(void);

extern unsigned short NVRAM_GSENSOR_DATA ;

extern int GetDirection(void);

extern int PlayIncomingtone ;

extern void mmi_ucm_play_incoming_tone(void);
extern void mmi_ucm_stop_incoming_tone(void);

extern void AFE_GSensor_TurnOnExtAmplifier(void);	
extern void AFE_GSensor_TurnOffExtAmplifier(void);	
extern int FlagOpener  ;
extern int FlagCloser    ;

extern void mdi_audio_set_mute(U8 vol_type, BOOL mute);
extern void mdi_audio_set_volume(U8 type, U8 volume);
extern int GSensor_GetRingToneCase(void) ;

void CloseTone(void)
{
#if 1
	//if(PlayIncomingtone == 0)
	{
		AFE_GSensor_TurnOffExtAmplifier();		
	}
#else
	mdi_audio_set_mute(0,0);
	mdi_audio_set_mute(4,0);
	mdi_audio_set_mute(6,0);
#endif
      //mmi_ucm_stop_incoming_tone();	
}

void OpenTone(void)
{
	if( (PlayIncomingtone == 1) )
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n Huyanwei Add It For Debug OpenTone()\r\n");
#endif
#if 1		
		if( GSensor_GetRingToneCase() == 1)
			return ;
		AFE_GSensor_TurnOnExtAmplifier();	
#else
	       mdi_audio_set_volume(/*MDI_VOLUME_MEDIA*/0, 4);
	       mdi_audio_set_volume(/*MDI_VOLUME_MEDIA*/4, 4);
   	       mdi_audio_set_volume(/*MDI_VOLUME_MEDIA*/6, 4);
#endif
	}
	//mmi_ucm_play_incoming_tone();	
}


#if 0
//Huyanwei Backup Old Method

extern void SetGSensorSleepMode(unsigned char  Mode);
static int G_SENSOR_POLL_TIMER_START = 0;
extern int aux_plug_in_state ;

void Process_InComingCall_G_Sensor(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
	static int Delay = 0;
	static int FlagsOpen = 1 ;
	static int times = 0;
	
	index = NVRAM_GSENSOR_DATA ;


	if ( 1 == G_SENSOR_POLL_TIMER_START)
		return;	

      if((index == 0 ) && (times == 0))
      {
		SetGSensorSleepMode(1);
		times ++;
      }
	
      if ( GetCurrentState() == CM_INCOMING_STATE )
      	{
      		
	      if(index == 0  )
	      {
	      			data = GetZValue_GSensor();
#if defined(NOKE_DEBUG)
				noke_dbg_printf("\r\ndata = 0x%02x, PlayIncomingtone=%d, FlagsOpen=%d \r\n",data,PlayIncomingtone,FlagsOpen);		
#endif
				if( (data >= 0x00)&&( data  <= 0x7f) )
				{
					//mdi_audio_stop_all();
					FlagsOpen = 0;
					CloseTone();
				}
				else
				{
					//mdi_audio_stop_all();
					if( Delay== 0 )
					{
						if( (GetPAPower() == 1) || (FlagsOpen== 0))
						{
							Delay++;
						}							
					}
					else
					{
						//if( (PlayIncomingtone == 1 ) &&  (FlagsOpen == 0) ) // Close Ring By Myself
						if( ( GetPAPower() == 0 ) && (FlagsOpen == 0) )      // Close Ring By Myself
						{
							FlagsOpen = 1 ;							
							OpenTone();
						}						
					}				
				}
		}
		else
		{
			// Do Nothing ........
	 		Delay = 0 ;	 		
			FlagsOpen = 1;
			times = 0;
      			SetGSensorSleepMode(0);
	 		StopTimer(POLL_G_SENSOR_TIMER);
			return ;	
		}		
      	}
	 else
	 {
	 		Delay = 0 ;
	 		FlagsOpen = 1;
			times = 0;
	 		CloseTone();
      			SetGSensorSleepMode(0);
	 		StopTimer(POLL_G_SENSOR_TIMER);
			return ;		
	 }
	StartTimer(POLL_G_SENSOR_TIMER, 100, Process_InComingCall_G_Sensor);

}


#include "UCMResDef.h"


void Process_SIM2InComingCall_G_Sensor(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
	static int FlagsOpen = 1 ;
	static int Delay = 0;
	static int times = 0;
	
	index = NVRAM_GSENSOR_DATA ;

      if((index == 0 ) && (times == 0))
      {
		SetGSensorSleepMode(1);
		times ++;
      }
	  
      if ( GetActiveScreenId() == SCR_ID_UCM_INCOMING /*GetCurrentState() == CM_INCOMING_STATE */)
      	{
	      if(index == 0  )
	      {
				data = GetZValue_GSensor();
#if defined(NOKE_DEBUG)
				noke_dbg_printf("\r\ndata = 0x%02x, PlayIncomingtone=%d, FlagsOpen=%d \r\n",data,PlayIncomingtone,FlagsOpen);						    		    		    		
#endif
				if( (data >= 0x00)&&( data  <= 0x7f) )
				{
					//mdi_audio_stop_all();
					FlagsOpen = 0;
					CloseTone();					
				}
				else
				{
					//mdi_audio_stop_all();
					if( Delay== 0 )
					{
						if( (GetPAPower() == 1) || (FlagsOpen== 0))
						{
							Delay++;
						}													
					}
					else
					{
						//if( (PlayIncomingtone == 1 ) && (FlagsOpen == 0) ) // Close Ring By Myself
						if( ( GetPAPower() == 0 ) && (FlagsOpen == 0) ) // Close Ring By Myself
						{
							FlagsOpen = 1 ;
							OpenTone();
						}						
					}
				}
		}
		else
		{
			// Do Nothing ........
			Delay = 0;
			FlagsOpen = 1;
			times = 0;
			StopTimer(POLL_G_SENSOR_TIMER);
			SetGSensorSleepMode(0);
			G_SENSOR_POLL_TIMER_START= 0;
			return ;
		}		
      	}
	 else
	 {
	 		Delay = 0;
			FlagsOpen = 1;
			times = 0 ;
		 	CloseTone();
	 		StopTimer(POLL_G_SENSOR_TIMER);
			SetGSensorSleepMode(0);
			G_SENSOR_POLL_TIMER_START = 0 ;
			return ;		
	 }
	 G_SENSOR_POLL_TIMER_START = 1;
	StartTimer(POLL_G_SENSOR_TIMER, 100, Process_SIM2InComingCall_G_Sensor);

}

#else
extern void SetGSensorSleepMode(unsigned char  Mode);
static int G_SENSOR_POLL_TIMER_START = 0;
extern int aux_plug_in_state ;

void Process_InComingCall_G_Sensor(void)
{
#if 0
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
	static int Delay = 0;
	static int FlagsOpen = 1 ;
	static int times = 0;
	
	index = NVRAM_GSENSOR_DATA ;


	if ( 1 == G_SENSOR_POLL_TIMER_START)
		return;	

      if((index == 0 ) && (times == 0))
      {
		SetGSensorSleepMode(1);
		kal_sleep_task(20);
		GetZValue_GSensor();
		times ++;
      }
	
      if ( GetCurrentState() == CM_INCOMING_STATE )
      	{
	      if(index == 0  )
	      {
	      			data = GetZValue_GSensor();
#if defined(NOKE_DEBUG)
				noke_dbg_printf("\r\n I data = 0x%02x, Delay = %d,PlayIncomingtone=%d, FlagsOpen=%d \r\n",data,Delay,PlayIncomingtone,FlagsOpen);		
#endif
				if( (data >= 0x00)&&( data  <= 0x7f) )
				{
					//mdi_audio_stop_all();
					if (GetPAPower() == 1)
					{
						FlagsOpen = 0;
						CloseTone();
						Delay = 1 ; // PA Opened
					}
				}
				else
				{
					//mdi_audio_stop_all();
					if( Delay == 0 )
					{
						if( (GetPAPower() == 1) )
						{
							Delay = 1 ;  //PA Opened
						}							
					}
					else
					{
						if( ( GetPAPower() == 0 ) && (FlagsOpen == 0) &&( FlagCloser ==1))      // Close Ring By Myself
						{
							FlagsOpen = 1 ;							
							OpenTone();
						}						
					}				
				}
		}
		else
		{
			// Do Nothing ........
	 		Delay = 0 ;	 		
			FlagsOpen = 1;
			times = 0;
      			SetGSensorSleepMode(0);
	 		StopTimer(POLL_G_SENSOR_TIMER);
			return ;	
		}		
      	}
	 else
	 {
	 		Delay = 0 ;
	 		FlagsOpen = 1;
			times = 0;
	 		CloseTone();
      			SetGSensorSleepMode(0);
	 		StopTimer(POLL_G_SENSOR_TIMER);
			return ;		
	 }
	StartTimer(POLL_G_SENSOR_TIMER, 50, Process_InComingCall_G_Sensor);
#endif
}


#include "UCMResDef.h"


void Process_SIM2InComingCall_G_Sensor(void)
{
#if 0
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
	static int FlagsOpen = 1 ;
	static int Delay = 0;
	static int times = 0;
	
	index = NVRAM_GSENSOR_DATA ;

      if((index == 0 ) && (times == 0))
      {
		SetGSensorSleepMode(1);
		kal_sleep_task(20);
		GetZValue_GSensor();
		times ++;
      }
	  
      if ( GetActiveScreenId() == SCR_ID_UCM_INCOMING /*GetCurrentState() == CM_INCOMING_STATE */)
      	{
	      if(index == 0  )
	      {
				data = GetZValue_GSensor();
#if defined(NOKE_DEBUG)
				//noke_dbg_printf("\r\n II data = 0x%02x, PlayIncomingtone=%d, FlagsOpen=%d \r\n",data,PlayIncomingtone,FlagsOpen);						    		    		    		
#endif
				if( (data >= 0x00)&&( data  <= 0x7f) )
				{
#if defined(NOKE_DEBUG)
					//noke_dbg_printf("\r\n II I data = 0x%02x, PlayIncomingtone=%d, FlagsOpen=%d,GetPAPower() =%d,FlagCloser = %d \r\n",data,PlayIncomingtone,FlagsOpen,GetPAPower(),FlagCloser);	
#endif
					if (GetPAPower() == 1)
					{
						FlagsOpen = 0;
						CloseTone();
						Delay = 1 ; // PA Opened
					}			
				}
				else
				{
					//mdi_audio_stop_all();
					if( Delay== 0 )
					{
						if( (GetPAPower() == 1) )
						{
							Delay = 1 ;  //PA Opened
						}												
					}
					else
					{
#if defined(NOKE_DEBUG)
						//noke_dbg_printf("\r\n II II data = 0x%02x, PlayIncomingtone=%d, FlagsOpen=%d,GetPAPower() =%d,FlagCloser = %d \r\n",data,PlayIncomingtone,FlagsOpen,GetPAPower(),FlagCloser);	
#endif
						if( ( GetPAPower() == 0 ) && (FlagsOpen == 0)  && ( FlagCloser != 0) ) // Close Ring By Myself
						{
							FlagsOpen = 1 ;
							OpenTone();
						}						
					}
				}
		}
		else
		{
			// Do Nothing ........
			Delay = 0;
			FlagsOpen = 1;
			times = 0;
			StopTimer(POLL_G_SENSOR_TIMER);
			SetGSensorSleepMode(0);
			G_SENSOR_POLL_TIMER_START= 0;
			return ;
		}		
      	}
	 else
	 {
	 		Delay = 0;
			FlagsOpen = 1;
			times = 0 ;
		 	CloseTone();
	 		StopTimer(POLL_G_SENSOR_TIMER);
			SetGSensorSleepMode(0);
			G_SENSOR_POLL_TIMER_START = 0 ;
			return ;		
	 }
	 G_SENSOR_POLL_TIMER_START = 1;
	StartTimer(POLL_G_SENSOR_TIMER, 50, Process_SIM2InComingCall_G_Sensor);
#endif
}

#endif



#include "VdoRecResDef.h"

extern void mmi_audply_press_prev_button_down(void);
extern void mmi_audply_press_prev_button_up(void);
extern void mmi_audply_press_next_button_down(void);
extern void mmi_audply_press_next_button_up(void);

extern void ProcessCallOnMessage(void) ;
extern void ProcessCallOffMessage(void);
extern void ProcessWallPaperUpMessage(void);
extern void ProcessWallPaperDownMessage(void);
extern void ProcessScreenSaverUpMessage(void);
extern void ProcessScreenSaverDownMessage(void);
extern void ProcessMusicUpMessage(void);
extern void ProcessMusicDownMessage(void);

extern void SendMessagesMMIToOne(msg_type MSG_ID );


void Process_Music_G_Sensor(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
	char play_music = 0 ;


	index = NVRAM_GSENSOR_DATA ;
	play_music =  mmi_audply_is_playing();
	
	if (  GetActiveScreenId() == SCR_ID_AUDPLY_MAIN  )
      	{
	      if((index == 0 ) && (play_music == KAL_TRUE))
	      {
			
				data =  GetDirection();
				if ( data == 1 )
				{
					ProcessMusicDownMessage();
					//SendMessagesMMIToOne(MSG_ID_GSENSOR_RIGHT);
				}
				else if ( data == 2 )
				{
					ProcessMusicUpMessage();
					//SendMessagesMMIToOne(MSG_ID_GSENSOR_LEFT);					
				}
				else
				{
					// Do Nothing ........								
				}
		}
		else
		{
			// Do Nothing ........			
		}		
      	}
	 else
	 {
	 		//StopTimer(POLL_G_SENSOR_TIMER);
	 		gui_cancel_timer(Process_Music_G_Sensor);
			return ;		
	 }
	//StartTimer(POLL_G_SENSOR_TIMER, 20, Process_Music_G_Sensor);
	gui_start_timer(20,Process_Music_G_Sensor);

}

#ifndef WIN32
extern int FlagGSensorSleep ;
#endif

void Process_WallPaper_G_Sensor(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	

	index = NVRAM_GSENSOR_DATA ;
	
	if (  GetActiveScreenId() == IDLE_SCREEN_ID  )
      	{
	      if((index == 0 ) )
	      {
				data =  GetDirection();
				if ( data == 1 )
				{
					ProcessWallPaperDownMessage();
					//SendMessagesMMIToOne(MSG_ID_GSENSOR_RIGHT);
				}
				else  if ( data ==  2 )
				{				
					ProcessWallPaperUpMessage();				
					//SendMessagesMMIToOne(MSG_ID_GSENSOR_LEFT);
				}
				else
				{
					// Do Nothing ........
				}
		}
		else
		{
			// Do Nothing ........			
		}		
      	}
	 else
	 {
	 		//StopTimer(POLL_G_SENSOR_TIMER);
	 		gui_cancel_timer(Process_WallPaper_G_Sensor);
			return ;		
	 }
	//StartTimer(POLL_G_SENSOR_TIMER, 20, Process_WallPaper_G_Sensor);
	gui_start_timer(20,Process_WallPaper_G_Sensor);

}

void Process_TV_G_Sensor(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	

	index = NVRAM_GSENSOR_DATA ;
#ifdef ANALOG_TV_SUPPORT
	
	if (  GetActiveScreenId() == SCR_ID_TV_IN_APP  )
      	{
	      if((index == 0 ) )
	      {
				data =  GetDirection();
				if ( data == 1 )
				{
					ProcessTVChannelDownMessage();
					//SendMessagesMMIToOne(MSG_ID_GSENSOR_RIGHT);
				}
				else  if ( data ==  2 )
				{				
					ProcessTVChannelUpMessage();				
					//SendMessagesMMIToOne(MSG_ID_GSENSOR_LEFT);
				}
				else
				{
					// Do Nothing ........
				}
		}
		else
		{
			// Do Nothing ........			
		}		
      	}
	 else
	 {
	 		//StopTimer(POLL_G_SENSOR_TIMER);
	 		gui_cancel_timer(Process_TV_G_Sensor);
			return ;		
	 }
	//StartTimer(POLL_G_SENSOR_TIMER, 20, Process_WallPaper_G_Sensor);
	gui_start_timer(20,Process_TV_G_Sensor);
#endif
}


extern PHNSET_CNTX * g_phnset_cntx_p ;
void Process_ScreenSaver_G_Sensor(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
	index = NVRAM_GSENSOR_DATA ;
	
	if (  (GetActiveScreenId() == IDLE_SCREEN_ID) )
      	{
	      if((index == 0 ) && (g_phnset_cntx_p->curSSStatus == 1) )
	      {
				data =  GetDirection();
				if ( data == 1 )
				{
					ProcessScreenSaverUpMessage();
				}
				else if (data == 2)
				{
					ProcessScreenSaverDownMessage();
				}
				else
				{
					//......
				}
		}
		else
		{
			// Do Nothing ........			
		}		
      	}
	 else
	 {
	 		StopTimer(POLL_G_SENSOR_TIMER);
			return ;		
	 }
	StartTimer(POLL_G_SENSOR_TIMER, 20, Process_ScreenSaver_G_Sensor);

}
#endif


#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
extern void HorseRace_Circle(void);
extern void HorseRace_Follow(void);
extern void HorseRace_Flash(void);
extern void HorseRace_Walk(void);
extern void HorseRace_WalkWithBack(void);
extern void HorseRace_TriWalk(void);
extern void HorseRace_TriWalkWithBack(void);
extern void HorseRace_TriOppWalk(void);
extern void HorseRace_TriOppWalkWithBack(void);
extern void HorseRace_Step(void);
extern void HorseRace_CrossWalk(void);
extern void HorseRace_TwoLine(void);
extern void  HorseRace_OpenLED(void);
extern char HorseRace_PowerIsOpen(void);

extern void HorseRace_CloseLED(void);
extern void HorseRace_Music_StepOne(void);
extern void HorseRace_Music_StepTwo(void);
extern void HorseRace_Music_StepThree(void);
extern void HorseRace_Music_StepFour(void);
extern void HorseRace_Music_StepFive(void);
extern void HorseRace_Music_StepSix(void);
extern void HorseRace_KeyPadBackLightOn(void);
extern void HorseRace_KeyPadBackLightOff(void);

extern BOOL mmi_audply_is_playing(void) ;
extern BOOL mmi_audply_is_play_activated();
extern U16 GetActiveScreenId(void);

#include "nvram_common_defs.h"
#include "NVRAMProt.h"

extern  unsigned short NVRAM_HORSERACE_DATA ;

int FlagsReachIdle = 0 ;
int HorseRaceInitedFlag = 0 ;

void Init_HorseRaceData(void)
{
	S16 ErrCode = 0 ;
	ReadRecord(NVRAM_HORSERACE_LID, 1, (void *)&NVRAM_HORSERACE_DATA, NVRAM_HORSERACE_SIZE, &ErrCode);
	if (NVRAM_HORSERACE_DATA  > 4)
		NVRAM_HORSERACE_DATA = 4 ;
	
	HorseRaceInitedFlag = 1 ;
}

U8 ProcessColorLed(void)
{
	int i = 0 ;
	const int times  = 2 ;
	unsigned 	short index = 0 ;	

	static int State = 0 ; // State = 0,1,2,3,4,5 count six LED
	
	index = NVRAM_HORSERACE_DATA ;

	
	if ( index != 4 )
	{
		switch ( index )
		{
			case 0:
				i= 0 ;
				while( i < times)
				{
					HorseRace_Step();
					i++ ;
				}					
				break;
			case 1:
				i= 0 ;
				while( i < times)
				{
					HorseRace_Follow();
					i++ ;
				}
				break;
			case 2:
				i= 0 ;
				while( i < times)
				{
					HorseRace_Flash();
					i++ ;
				}
				break;
			case 3:
				i= 0 ;
				while( i < times)
				{
					HorseRace_Walk();
					i++ ;
				}
				break;
			case 4:
				i= 0 ;
				while( i < times)
				{
					HorseRace_WalkWithBack();
					i++ ;
				}
				break;			
			case 5:
				i= 0 ;
				while( i < times)
				{
					HorseRace_TriWalk();
					i++ ;
				}		
				break;
			case 6:
				i= 0 ;
				while( i < times)
				{
					HorseRace_TriWalkWithBack();
					i++ ;
				}		
			case 7:
				i= 0 ;
				while( i < times)
				{
					HorseRace_TriOppWalk();			
					i++ ;
				}
				break;
			case 8:
				i= 0 ;
				while( i < times)
				{
					HorseRace_TriOppWalkWithBack();
					i++ ;
				}
				break;
			case 9:
				i= 0 ;
				while( i < times)
				{
				   	HorseRace_Circle();
					i++ ;
				}
				break;	
			case 10:
				i= 0 ;
				while( i < times)
				{
					HorseRace_CrossWalk();
					i++ ;
				}
				break;
			case 11:
				i= 0 ;
				while( i < times)
				{
					HorseRace_TwoLine();
					i++ ;
				}			
				break;
			default:
				break;
		}
		HorseRace_CloseLED();
		return 1 ;
	}
	else
	{
		HorseRace_CloseLED();
		return 0 ;
	}
}

extern void mmi_audply_calc_spectrum(BOOL on);
extern mdi_result mdi_audio_get_spectrum(U8 *top_p, U8 *val_p);

U8 ProcessMusicColorLed(void)
{
	int i = 0 ;
	const int times  = 2 ;
	unsigned 	short index = 0 ;	
	U8 TopValue[16]  = { 0 };
	U8 HighValue[16] = { 0 } ;	
	index = NVRAM_HORSERACE_DATA ;	
	
	mmi_audply_calc_spectrum(TRUE);
       mdi_audio_get_spectrum(TopValue, HighValue); 
#if defined(NOKE_DEBUG)
	noke_dbg_printf(" tops = %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", TopValue[0], TopValue[1], TopValue[2], TopValue[3], TopValue[4], TopValue[5], TopValue[6], TopValue[7], TopValue[8], TopValue[9], TopValue[10], TopValue[11], TopValue[12], TopValue[13], TopValue[14], TopValue[15]);
       noke_dbg_printf(" vals = %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", HighValue[0], HighValue[1], HighValue[2], HighValue[3], HighValue[4], HighValue[5], HighValue[6], HighValue[7], HighValue[8], HighValue[9], HighValue[10], HighValue[11], HighValue[12], HighValue[13], HighValue[14], HighValue[15]);
#endif

	if ( index != 4 )
	{			
		switch ( HighValue[10]  / 80 )
			{
				case 0:					
					//HorseRace_Music_StepOne();
					HorseRace_Music_StepTwo();
					break;
				case 1:
					//HorseRace_Music_StepTwo();
					HorseRace_Music_StepFour();
					break;
				case 2:
					//HorseRace_Music_StepThree();
					HorseRace_Music_StepSix();
					break;
#if 0
				case 3:
					HorseRace_Music_StepFour();
					break;
				case 4:
					HorseRace_Music_StepFive();
					break;
				case 5:
					HorseRace_Music_StepSix();					
					break;
#endif					
				default:
					HorseRace_Music_StepSix();
					break;
			}
		HorseRace_CloseLED();		
		return 1 ;
	}
	else
	{
		HorseRace_CloseLED();
		return 0 ;
	}
}


void ProcessThreadWhilePowerOn(void)
{	
	char PowerOn = 0;
	int play_music  = KAL_FALSE ;

	PowerOn = HorseRace_PowerIsOpen();
	play_music =  mmi_audply_is_playing();
	if(  PowerOn == 0 ) 
	{
		HorseRace_OpenLED();
	}		
	
	if ( ( FlagsReachIdle == 0 ) &&(play_music != KAL_TRUE) )
	{
		ProcessColorLed();
	}	
	else
	{		
		HorseRace_CloseLED();
	}			
}


void HorseRaceThread(void)
{
	S16 ErrCode = 0 ;	
	int i = 0 ;
	const int times  = 5 ;
	int play_music  = KAL_FALSE ;
	unsigned 	short index = 0 ;	
	char PowerOn = 0;
	char DelayFlag = 0 ;

	index = NVRAM_HORSERACE_DATA ;
	play_music =  mmi_audply_is_playing();
	PowerOn = HorseRace_PowerIsOpen();
		
	if(  PowerOn == 0 ) 
	{
		HorseRace_OpenLED();
	}	
	
	if (  GetActiveScreenId() == SCR_ID_AUDPLY_MAIN  )
	{
		DelayFlag = 1 ;
	}
	else
	{
		DelayFlag = 0 ;
	}
	
	if ( (index != 4 ) && (play_music == KAL_TRUE) )
	{		
		ProcessColorLed();						
	}
	else
	{		
		HorseRace_CloseLED();
		StopTimer(POLL_HORSERACE_TIMER);
		if ( DelayFlag != 1 )
			return ;
	}			
	StartTimer(POLL_HORSERACE_TIMER, 2500, HorseRaceThread );
}

extern int FlagsReachIdle ;
extern int InTVScreen ;
extern int InCameraScreen;
extern int InVdorecScreen ;
#ifdef __MMI_FM_RADIO__
extern int InFMScreen ;
#endif
extern BOOL in_single_play_screen;

extern BOOL mmi_fmrdo_is_power_on(void);
extern void HorseRace_CloseLedPower(void) ;

void HorseRaceThreadTask(void)
{
	int play_music  = KAL_FALSE ;
	unsigned 	short index = 0 ;	
	char PowerOn = 0;

	index = NVRAM_HORSERACE_DATA ;
	play_music =  mmi_audply_is_playing();
	
	PowerOn = HorseRace_PowerIsOpen();		


	if (FlagsReachIdle == 1)
	{
#ifdef ANALOG_TV_SUPPORT	
		if( ( InTVScreen == 1) || ( InCameraScreen == 1 ) || (InVdorecScreen == 1 ) || ( InFMScreen == 1) || (mmi_fmrdo_is_power_on() == 1))
#elif defined __MMI_FM_RADIO__
		if( ( InCameraScreen == 1 ) || (InVdorecScreen == 1 ) || ( InFMScreen == 1) || (mmi_fmrdo_is_power_on() == 1))
#else
		if( ( InCameraScreen == 1 ) || (InVdorecScreen == 1 ) )
#endif 
		{
			HorseRace_CloseLED();
			return;
		}
			
		if (    (index != 4 ) && (  (play_music == KAL_TRUE) || (in_single_play_screen == 1) ))
		{
			if(  PowerOn == 0 ) 
			{
				HorseRace_OpenLED();
			}
			ProcessColorLed();			
			//ProcessMusicColorLed();
		}
		else
		{		
			HorseRace_CloseLED();
			HorseRace_CloseLedPower();
		}				
	}
	else
	{
		if ( (index != 4 ) )
		{
			if(  PowerOn == 0 ) 
			{
				HorseRace_OpenLED();
			}
			ProcessColorLed();			
		}
		else
		{		
			HorseRace_CloseLED();
			HorseRace_CloseLedPower();
		}						
	}
}


int  HorseRaceThreadTaskFlag(void)
{
	int play_music  = KAL_FALSE ;
	unsigned 	short index = 0 ;	

	index = NVRAM_HORSERACE_DATA ;
	
	if (FlagsReachIdle == 1)
	{
		play_music =  mmi_audply_is_playing();
#ifdef ANALOG_TV_SUPPORT		
		if( ( InTVScreen == 1) || ( InCameraScreen == 1 ) || (InVdorecScreen == 1 ) || ( InFMScreen == 1) ||( mmi_fmrdo_is_power_on() == 1) )
#elif defined __MMI_FM_RADIO__
		if( ( InCameraScreen == 1 ) || (InVdorecScreen == 1 ) || ( InFMScreen == 1) ||( mmi_fmrdo_is_power_on() == 1) )
#else
		if( ( InCameraScreen == 1 ) || (InVdorecScreen == 1 ))
#endif 
		{
				return  0 ;
		}
		
		if ( (index != 4 ) && ( (play_music == KAL_TRUE) || (in_single_play_screen == 1)  ))
		{
				return 1 ;
		}
		else
		{		
				return 0 ;
		}				
	}
	else
	{
		if ( (index != 4 ) ) /** Open **/
		{
				return 1 ;
		}
		else
		{		
				return 0 ;
		}				
		
	}
	return 0 ;
}


#endif


#if defined(G_SENSOR_SUPPORT) ||defined( __DIRECTION_SENSOR_SUPPORT__)
//Huyanwei Add It 

#if 1
extern void 	mmi_audply_press_prev_button_down(void);
extern void	mmi_audply_press_prev_button_up(void);
extern void 	mmi_audply_press_next_button_down(void);
extern void	mmi_audply_press_next_button_up(void);
#endif

#if 1
#include "PhoneSetupResList.h"
#include "custom_mmi_default_value.h"
#include "AudioPlayerResDef.h"
extern PHNSET_CNTX * g_phnset_cntx_p ;
extern U8 GetSystemWallPaperList(U8 **pSysWallpaperStrList, U16 *pSysWallpaperImgIDList, U16 *HighliteItem);
extern BOOL PhnsetSetDisplayFromAT(U8 idx, U8 type);
extern void mmi_dispchar_set_img_id(U8 nDataItemId, U16 *pBuffer) ;
extern void SetWallpaperByImgID(U16 imgID);
extern void draw_wallpaper(void);
extern void mmi_idle_entry_idle_screen(void);
extern GDI_HANDLE dm_get_wallpaper_layer(void);
	

#endif

extern void SendMessagesMMIToOne(msg_type MSG_ID );


void ProcessCallOnMessage(void)
{
	static int flags = 0 ;
	if(flags == 0)
	{
		flags = 1 ;
		#ifndef WIN32
		AFE_TurnOnExtAmplifier();
		#endif
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessCallOnMessage \r\n");
#endif
		flags = 0 ;
	}
}

void ProcessCallOffMessage(void)
{
	static int flags = 0 ;
	if(flags == 0)
	{
		flags = 1 ;
		#ifndef WIN32
		AFE_TurnOffExtAmplifier();
		#endif
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessCallOffMessage \r\n");
#endif
		flags = 0 ;		
	}
	return ;
}

void ProcessWallPaperUpMessage(void)
{
	U16 SysWpIDList[MAX_WALLPAPER_IMG];
	U16 nCount = 0 ;
	U16 CurrentIndex = 0 ;
	unsigned char temp = g_phnset_cntx_p->wpss_type ;
	static int flags = 0 ;
	GDI_HANDLE dm_new_layers;

	if ( (flags == 0) &&  (  GetActiveScreenId() == IDLE_SCREEN_ID  ))
	{	
		flags = 1 ;
		g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_WP;
		nCount = GetSystemWallPaperList(NULL, SysWpIDList, &CurrentIndex);
		
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n WallPaper nCount= %d ,CurrentIndex = %d \r\n",nCount,CurrentIndex);
#endif
		if( CurrentIndex < 1 )
			CurrentIndex = nCount-1;
		else
			CurrentIndex-- ;

		//	PhnsetSetDisplayFromAT(CurrentIndex,MMI_PHNSET_TYPE_WP);
		//	mmi_dispchar_set_img_id(NVRAM_FUNANDGAMES_SETWALLPAPER, &CurrentIndex);
		SetWallpaperByImgID(SysWpIDList[CurrentIndex]);
		g_phnset_cntx_p->wpss_type = temp ;
		
		//RedrawIdleScreen();
		//draw_wallpaper();
		//mmi_idle_entry_idle_screen();

		dm_new_layers = dm_get_wallpaper_layer();
		if ( dm_new_layers != GDI_ERROR_HANDLE)
		{
			gui_lock_double_buffer();
			gdi_image_abm_set_source_layer(dm_new_layers);
			gdi_layer_push_and_set_active(dm_new_layers);
			draw_wallpaper();
			gdi_layer_pop_and_restore_active();
			gui_unlock_double_buffer();
			gui_BLT_double_buffer(0,0,240-1,320-1);			
		}		
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessWallPaperUpMessage \r\n");
#endif
		flags = 0 ;			
	}
	return ;
}

void ProcessWallPaperDownMessage(void)
{
	U16 SysWpIDList[MAX_WALLPAPER_IMG];
	U16 nCount = 0 ;
	U16 CurrentIndex = 0 ;
	unsigned char temp = g_phnset_cntx_p->wpss_type ;
	static int flags = 0 ;
	GDI_HANDLE dm_new_layers;
	
	if ( (flags == 0) &&  (  GetActiveScreenId() == IDLE_SCREEN_ID  ))
	{	
		flags = 1 ;	
		g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_WP;
		nCount = GetSystemWallPaperList(NULL, SysWpIDList, &CurrentIndex);

#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n WallPaper nCount= %d ,CurrentIndex = %d \r\n",nCount,CurrentIndex);
#endif
		if( CurrentIndex >= nCount-1 )
			CurrentIndex = 0 ;
		else
			CurrentIndex++ ;
	//	PhnsetSetDisplayFromAT(CurrentIndex,MMI_PHNSET_TYPE_WP);
	//   mmi_dispchar_set_img_id(NVRAM_FUNANDGAMES_SETWALLPAPER, &CurrentIndex);
		SetWallpaperByImgID(SysWpIDList[CurrentIndex]);
		g_phnset_cntx_p->wpss_type = temp ;

		//RedrawIdleScreen();
		//draw_wallpaper();
		//mmi_idle_entry_idle_screen();
		dm_new_layers = dm_get_wallpaper_layer();
		if ( dm_new_layers != GDI_ERROR_HANDLE)
		{
			gui_lock_double_buffer();
			gdi_image_abm_set_source_layer(dm_new_layers);
			gdi_layer_push_and_set_active(dm_new_layers);
			draw_wallpaper();
			gdi_layer_pop_and_restore_active();
					
			gui_unlock_double_buffer();
			gui_BLT_double_buffer(0,0,240-1,320-1);
		}		
				
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessWallPaperDownMessage \r\n");
#endif
		flags = 0 ;
	}
	return ;
}

void ProcessScreenSaverUpMessage(void)
{
	U16 nCount = 0 ;
	static int flags = 0 ;
	if(flags == 0)
	{	
		flags = 1 ;		
		nCount = PhnsetConstSysScrSvrList(NULL,g_phnset_cntx_p->SysWPSSList,(S16*) & g_phnset_cntx_p->curHightlightItem);

		if (g_phnset_cntx_p->curHightlightItem <= 0)
		{
			g_phnset_cntx_p->curHightlightItem = nCount;
		}
			g_phnset_cntx_p->curHightlightItem--;

		g_phnset_cntx_p->curSsID = g_phnset_cntx_p->SysWPSSList[g_phnset_cntx_p->curHightlightItem];
		mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));

		 RedrawIdleScreen();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessScreenSaverUpMessage \r\n");
#endif
		flags = 0 ;
	}
	return ;
}	

void ProcessScreenSaverDownMessage(void)
{
	U16 nCount = 0 ;
	static int flags = 0 ;
	if(flags == 0)
	{	
		flags = 1 ;		
		nCount = PhnsetConstSysScrSvrList(NULL,g_phnset_cntx_p->SysWPSSList,(S16*) & g_phnset_cntx_p->curHightlightItem);

		if (g_phnset_cntx_p->curHightlightItem >= nCount - 1)
		{
		    g_phnset_cntx_p->curHightlightItem = -1;
		}
		g_phnset_cntx_p->curHightlightItem++;

		g_phnset_cntx_p->curSsID = g_phnset_cntx_p->SysWPSSList[g_phnset_cntx_p->curHightlightItem];
		mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));
		 RedrawIdleScreen();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessScreenSaverDownMessage \r\n");
#endif
		flags = 0 ;
	}
	return ;
}	

void ProcessMusicUpMessage(void)
{
	static int flags = 0 ;
	if ( (flags == 0) && ( GetActiveScreenId() == SCR_ID_AUDPLY_MAIN  ) )
	{	
		flags = 1 ;	
		mmi_audply_press_prev_button_down();
		#ifndef WIN32
		delayms(10);
		#endif
		mmi_audply_press_prev_button_up();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessMusicUpMessage \r\n");
#endif
#ifndef WIN32 //hongzhe.liu
		delayms(10);
		#endif
		flags = 0 ;
	}
	return ;
}	

void ProcessMusicDownMessage(void)
{
	static int flags = 0 ;
	if ( (flags == 0) && ( GetActiveScreenId() == SCR_ID_AUDPLY_MAIN  ) )
	{	
		flags = 1 ;	
		mmi_audply_press_next_button_down();
		#ifndef WIN32
		delayms(10);
		#endif		
		mmi_audply_press_next_button_up();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessMusicDownMessage \r\n");
#endif
#ifndef WIN32 //hongzhe.liu
		delayms(10);
		#endif
		flags = 0 ;
	}
	return ;
}	

#if defined(G_SENSOR_SUPPORT)



void SendMessageToCloseThreadOne(void)
{
#if 1
	//Huyanwei Add It For Thread 
	if((GetActiveScreenId() == IDLE_SCREEN_ID ) /*|| (GetActiveScreenId() == SCR_ID_AUDPLY_MAIN )*/ )
	{
		SendMessagesMMIToOne(MSG_ID_GSENSOR_OFF);
	}
#endif
}

void SendMessageToOpenThreadOne(void)
{
#if 1
	//Huyanwei Add It For Thread 
	if((GetActiveScreenId() == IDLE_SCREEN_ID)/* ||(GetActiveScreenId() == SCR_ID_AUDPLY_MAIN ) */)
	{
		SendMessagesMMIToOne(MSG_ID_GSENSOR_ON);
	}
#endif	
}
#endif

#endif


#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
void ProcessHorseRaceOnMessage(void)
{
	static int flags = 0 ;
	if(flags == 0)
	{	
		flags = 1 ;	
		ProcessColorLed();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessHorseRaceOnMessage \r\n");
#endif
		flags = 0 ;
	}
	return ;
}	

void ProcessHorseRaceOffMessage(void)
{
	static int flags = 0 ;
	if(flags == 0)
	{	
		flags = 1 ;	
		HorseRace_CloseLED();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessHorseRaceOffMessage \r\n");
#endif
		flags = 0 ;
	}
	return ;
}	
#endif


#if defined(G_SENSOR_SUPPORT)

#ifndef WIN32
extern int FlagGSensorSleep;
#endif
int SleepAtIdleScreen(void)
{
#ifndef WIN32
	if( ( (GetActiveScreenId() == IDLE_SCREEN_ID ) /* || (GetActiveScreenId() == SCR_ID_AUDPLY_MAIN )*/ )&& (FlagGSensorSleep == 1))
		return 1 ;
	else
#endif		
		return 0 ;	
}
#endif


#if defined(DOUBLE_BATTERY_SUPPORT)
 //Huyanwei Add It For Battery Level
#include "NVRAMProt.h"
extern  kal_uint32 g_adc_value;
extern  kal_uint16 g_adc_value_high ;
extern  kal_uint16 g_adc_value_low  ;
extern void UpdateBatteryLevel() ;
 #endif

/*shaokai add it start 090909*/
extern void EntryScrSetKeyPadVolumeLevel(void);

void Idle_Entry_Key_Volume(void)
{
	if (g_keylock_context.gKeyPadLockFlag == 0)
	{
		EntryScrSetKeyPadVolumeLevel();
	}	
}
/*shaokai add it  end 090909*/


#if defined(__FLASH_LIGHT_SUPPORT__)

extern void noke_drv_flash_light_on(kal_bool light_on);

void Idlekey_FlashLight(void)
{
	static kal_bool bFlashLightState = KAL_FALSE ;
	if(g_keylock_context.gKeyPadLockFlag == 1)
	{
		TurnOnBacklight(1);
		return ;
	}
	#if !defined(WIN32)
	noke_drv_flash_light_on(!bFlashLightState) ;
	#endif
	bFlashLightState = !bFlashLightState ;		
}

void idle_reset_vol_up_key(void)
{
	SetKeyHandler(Idle_Entry_Key_Volume,KEY_VOL_UP,KEY_EVENT_UP);
#ifndef __COUNTERFEIT_MONEY_LAMP_SUPPORT__	
	SetKeyHandler(Idle_Entry_Key_Volume,KEY_VOL_DOWN,KEY_EVENT_UP);
#endif
}

void idle_flashlight_convert_key(void)
{
	Idlekey_FlashLight() ;
	SetKeyHandler(idle_reset_vol_up_key,KEY_VOL_UP,KEY_EVENT_UP);
#ifndef __COUNTERFEIT_MONEY_LAMP_SUPPORT__
	SetKeyHandler(idle_reset_vol_up_key,KEY_VOL_DOWN,KEY_EVENT_UP);
#endif
}

#endif /* __FLASH_LIGHT_SUPPORT__ */

#if defined(__COUNTERFEIT_MONEY_LAMP_SUPPORT__)

extern void noke_drv_counterfeit_money_lamp_on(kal_bool light_on);

void Idlekey_CounterfeitMoneyLamp(void)
{
	static kal_bool bCounterfeitMoneyLampState = KAL_FALSE ;
	if(g_keylock_context.gKeyPadLockFlag == 1)
	{
		TurnOnBacklight(1);
		return ;
	}
	#if !defined(WIN32)
	noke_drv_counterfeit_money_lamp_on(!bCounterfeitMoneyLampState) ;
	#endif
	bCounterfeitMoneyLampState = !bCounterfeitMoneyLampState ;		
}

void idle_reset_vol_down_key(void)
{
	SetKeyHandler(Idle_Entry_Key_Volume,KEY_VOL_DOWN,KEY_EVENT_UP);
}

void idle_counterfeit_money_lamp_convert_key(void)
{
	Idlekey_CounterfeitMoneyLamp() ;
	SetKeyHandler(idle_reset_vol_down_key,KEY_VOL_DOWN,KEY_EVENT_UP);
}
#endif /* __COUNTERFEIT_MONEY_LAMP_SUPPORT__ */

void IdleStateSetkey(void)
{
/*shaokai add it start.090907*/
       SetKeyHandler(Idle_Entry_Key_Volume,KEY_VOL_UP, KEY_EVENT_UP);
       SetKeyHandler(Idle_Entry_Key_Volume,KEY_VOL_DOWN, KEY_EVENT_UP);
/*shaokai add it end.090907*/	   
	SetKeyHandler(Idle_Entry_Camera,KEY_CAMERA,KEY_EVENT_UP);
#ifdef ANALOG_TV_SUPPORT
	SetKeyHandler(Idle_Entry_tv,KEY_EXTRA_1, KEY_EVENT_UP);
#endif
	SetKeyHandler(Idle_Entry_MsgCenter,KEY_EXTRA_2, KEY_EVENT_UP);

#if defined(__FLASH_LIGHT_SUPPORT__)
	SetKeyHandler(idle_flashlight_convert_key,KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
#ifndef __COUNTERFEIT_MONEY_LAMP_SUPPORT__
	SetKeyHandler(idle_flashlight_convert_key,KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
#endif
#endif
#if defined(__COUNTERFEIT_MONEY_LAMP_SUPPORT__)
	SetKeyHandler(idle_counterfeit_money_lamp_convert_key,KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
#endif
}
/*****************************************************************************
 * FUNCTION
 *  EntryIdleScreen
 * DESCRIPTION
 *  Entry function for idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 gIsOnSearchingScreen = MMI_FALSE;
    U16 keyCode, keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(DOUBLE_BATTERY_SUPPORT)
	//Huyanwei Add It 
	S16 ErrCode = 0 ;
	ReadRecord(NVRAM_ADC_LID, 1, (void *)&g_adc_value, NVRAM_ADC_SIZE, &ErrCode);
	g_adc_value_high = (g_adc_value & 0xFFFF0000 )>> 16 ;
	g_adc_value_low  = (g_adc_value & 0x0000FFFF ) ;
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r g_adc_value_high = %d , g_adc_value_low= %d\n",g_adc_value_high,g_adc_value_low);
#endif
	#endif
	
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_bootup_is_sim_valid() == MMI_FALSE && mmi_netset_get_active_preferred_mode() == P_GSM_ONLY && mmi_bootup_get_active_bt_access_profile_mode() == 0)
    {
        if (simErrorDisplayString == STR_SIM_BLOCK_MSG)
        {
            EntryScrnSimBlockRsp();
        }
        else
        {
            EntryScrnSimErrorScreen();
        }
        return;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    GetkeyInfo(&keyCode, &keyType);
    if ((keyCode == KEY_LSK || keyCode == KEY_RSK) && (keyType == KEY_EVENT_DOWN || keyType == KEY_REPEAT)&& g_idle_context.IsOnIdleScreen == 1 && g_keylock_context.gKeyPadLockFlag == 0)
    {
        /*
         * The case is because the idle screen is re-entry between left softkey down and up event.
         * Once re-entry idle screen, the clicked state will be clean and then the up event will be ignore.
         */
        return;
    }

    /* diamond, 2006/02/22 Avoid to restart keypad lock and screensaver timer if EntryIdleScreen is called again when active screen is still idle screen */
    gIsIdleScreenReentry = (GetActiveScreenId() == IDLE_SCREEN_ID &&
                            gIsOnSearchingScreen == MMI_FALSE) ? MMI_TRUE : MMI_FALSE;


#if defined(DOUBLE_BATTERY_SUPPORT)
    //Huyanwei Add It
    UpdateBatteryLevel();
#endif

    EntryNewScreen(IDLE_SCREEN_ID, ExitIdleScreen, NULL, MMI_FULL_SCREEN);

    /* START PMT NEERAJ 20051021 */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens()) /* 010706 small screen Calvin */
    {
        RedrawIdleScreen();
        gIsIdleScreenReentry = MMI_FALSE;
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 
    /* END PMT NEERAJ 20051021 */

    g_pwr_context.PrevScreenIndicator = ENTER_IDLE_SCR;

    DinitHistory();
    DeInitSpecialMode();    /* EngineerMode/Factory Deinit */

#if defined(JATAAYU_SUPPORT) && defined(MMS_SUPPORT)
    mmi_jmms_free_media_layer_buffer(); /* free media layer buffer */
#endif

#ifdef __MMI_DOWNLOAD_AGENT__
    mmi_da_enter_idle_screen_notify();
#endif 

#ifdef __J2ME__
    jvm_enter_idle_screen_notify();
#endif 

#ifdef __MMI_SWFLASH__
    mmi_swflash_enter_idle_screen_notify();
#endif 

    mmiapi_enter_idle_screen_notify();

#ifndef __MMI_DUAL_SIM_MASTER__
#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_flight_mode_is_switching())
    {
        mmi_flight_mode_switching_in_idle();
        return;
    }
#endif    
#else
    if (DualModeIsSwitching())
    {
        EntryDualModeSwitchProgressInIdle();
        return;
    }
#endif    

#if defined(__MMI_WEBCAM__) && defined(__MMI_USB_SUPPORT__)
    /* entry webcam if it is still active */
    if (mmi_usb_webcam_is_active())
    {
        mmi_usb_webcam_entry_app_scr();
        return;
    }
#endif /* defined(__MMI_WEBCAM__) && defined(__MMI_USB_SUPPORT__) */ 

#ifdef __MMI_SIMAP_SUPPORT__
    if (mmi_bootup_get_active_bt_access_profile_mode())
    {
    #if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
        widget_MMI_on_enter_idle_screen();
    #endif

        if (mmi_bootup_is_searching_or_idle_reached() == MMI_FALSE)
        {

        }

        if (!gIsIdleScreenReentry)
        {
            mmi_idle_start_keypad_lock();   /* keypad lock in flight mode */
            mmi_idle_start_screensaver();   /* screen saver in flight mode */
        }

        g_idle_context.IsOnIdleScreen = 1;
        g_idle_context.IsOnDialerScreen = 0;
        g_idle_context.LongPressEnable = 0;
        g_idle_context.IdleScreenDigitKeyCode = -1;

        if (0)
        {
        }
    #ifdef __J2ME__
        else if (mmi_java_is_launch_from_idle())
        {
            mmi_java_entry_mid_launch_from_idle();
        }
    #endif /* __J2ME__ */ 
    #ifdef __MMI_DOWNLOAD_AGENT__
        else if (mmi_da_launch_ring_buffer_check())
        {
            mmi_da_entry_new_push_ind();
        }
    #endif /* __MMI_DOWNLOAD_AGENT__ */ 
        else
        {
            if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
            {
                mmi_idle_entry_bt_access_profile_idle_screen();
            }
            else
            {
                EntryFlightModeKeypadLockScreen(); /* share with flight mode keypad lock screen */

                g_keylock_context.keypad_lock_screen_exit = GetCurrExitFuncPtr();
                SetCurrExitFuncPtr(mmi_idle_generic_keypad_lock_screen_exit_hdlr);
            }
        }

        mmi_idle_dummy_key_in_screensaver();
        return;
    }
#endif /* __MMI_SIMAP_SUPPORT__ */

#ifdef __FLIGHT_MODE_SUPPORT__
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT && MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT) /* no query mode in dual sim case so startup mode can determine flight mode */
#else
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        if (mmi_bootup_is_searching_or_idle_reached() == MMI_FALSE)
        {
            g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: Flight mode idle screen */
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;        /* 0x01: network attachment timeout */
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
        #endif
            g_pwr_context.InvalidSimShowed = 1;
            TurnOffBacklight();
            StartLEDPatternBackGround();

            if (g_charbat_context.isChargerConnected)
            {
                StartTimer(BOOTUP_CHARGER_DETECT_TIMER, 3000, ChargerDetectTimeoutHdlr);
            }

            PendingAlarmReminder();

            mmi_idle_notify_bootup_ready_to_l4c(); /* to L4C */
            mmi_idle_notify_bootup_ready_to_wap(); /* to WAP */
            mmi_idle_notify_bootup_ready_to_certman(); /* to CertMan */

        #ifdef __MMI_IMPS__
            mmi_imps_notify_idle_reached();
        #endif 

            mmi_flight_mode_hide_menu_items();
        }

        g_idle_context.IsOnIdleScreen = 1;
        g_idle_context.IsOnDialerScreen = 0;
        g_idle_context.LongPressEnable = 0;
        g_idle_context.IdleScreenDigitKeyCode = -1;

        if (!gIsIdleScreenReentry)
        {
            mmi_idle_start_keypad_lock();   /* keypad lock in flight mode */
            mmi_idle_start_screensaver();   /* screen saver in flight mode */
        }

        if (0)
        {
        }
#ifdef __J2ME__
        else if (mmi_java_is_launch_from_idle())
        {
            mmi_java_entry_mid_launch_from_idle();
        }
    #endif /* __J2ME__ */ 
    #ifdef __MMI_DOWNLOAD_AGENT__
        else if (mmi_da_launch_ring_buffer_check())
        {
            mmi_da_entry_new_push_ind();
        }
    #endif /* __MMI_DOWNLOAD_AGENT__ */ 
        else
        {
            if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
            {
                EntryFlightModeIdleScreen();
            }
            else
            {
                EntryFlightModeKeypadLockScreen();
                /* diamond, 2006/03/26 Generic exit function for keypad lock callback screens */
                g_keylock_context.keypad_lock_screen_exit = GetCurrExitFuncPtr();
                SetCurrExitFuncPtr(mmi_idle_generic_keypad_lock_screen_exit_hdlr);
            }

            mmi_idle_dummy_key_in_screensaver();
        }
        gIsIdleScreenReentry = MMI_FALSE;

    #ifdef __MMI_DUAL_SIM_MASTER__
        if (MTPNP_PFAL_Is_InCard2securityCheck())
        {
            /* need to check SIM2 PIN1 when first time enter idle screen */
            /* coding here because flight mode check is true in dual sim mode */
            MTPNP_AD_Card2_CHV_Request();
            ClearInputEventHandler(MMI_DEVICE_ALL);
        }
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        return;
    }
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
    /* end, diamond */

    mmi_phb_reset_scr_id();
    NETSETCheckAndRestoreNetwork();

#ifdef __SAT__
    SATEVDLIdleScreenAvaliable();
#endif

#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_um_on_enter_idle_screen();
#endif 

#ifdef __CERTMAN_SUPPORT__
	mmi_certman_deinit();
#endif

#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
    widget_MMI_on_enter_idle_screen();
#endif 

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
    mmi_brw_unread_push_message_indication();
#endif 

#ifdef __MOD_SMSAL__
    mmi_msg_on_enter_idle_screen();
#endif /* __MOD_SMSAL__ */ 

    OslDumpDataInFile();

    /* This block carries all functions to be called when user enter idle screen first time. */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_searching_or_idle_reached() || !mmi_bootup_is_sim_valid())
#else
    if (mmi_bootup_is_searching_or_idle_reached() == MMI_FALSE)
#endif
    {
        TurnOffBacklight();
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_NW_SEARCHING;     /* 0x40: Network searching screen */

    #if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
        DirectMode = FALSE;
    #endif 

        PendingAlarmReminder();
        StartLEDPatternBackGround();

    #ifdef __MMI_DUAL_SIM_MASTER__
        if ((!g_pwr_context.IsCampOnTonePlayed && g_pwr_context.CurrentServiceType == FULL_SERVICE) ||
            (!g_pwr_context_2.IsCampOnTonePlayed && g_pwr_context_2.CurrentServiceType == FULL_SERVICE))
        {
            g_pwr_context.IsCampOnTonePlayed = 1;
            g_pwr_context_2.IsCampOnTonePlayed = 1;
            playRequestedTone(CAMP_ON_TONE);
        }
    #else
        if (!g_pwr_context.IsCampOnTonePlayed && g_pwr_context.CurrentServiceType == FULL_SERVICE)      /* Robin 1128 Play camp on tone after enter idle screen */
        {
            g_pwr_context.IsCampOnTonePlayed = 1;
            playRequestedTone(CAMP_ON_TONE);
        }
    #endif

    #ifdef __MMI_POC__
        if (g_pwr_context.CurrentServiceType == FULL_SERVICE)
        {
            mmi_poc_poweron_reg();
        }
    #endif /* __MMI_POC__ */ 

        if (g_charbat_context.isChargerConnected)
        {
            StartTimer(BOOTUP_CHARGER_DETECT_TIMER, 3000, ChargerDetectTimeoutHdlr);
        }

    #if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
        MMIProcessActionMsg();
    #endif 

        mmi_idle_notify_bootup_ready_to_l4c(); /* to L4C */
        mmi_idle_notify_bootup_ready_to_wap(); /* to WAP */
        mmi_idle_notify_bootup_ready_to_certman(); /* to CertMan */

    #ifdef __MMI_IMPS__
        mmi_imps_notify_idle_reached();
    #endif 

    #ifdef __MMI_SML_MENU__
        mmi_sml_display_auto_locked_notification();
    #endif

    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
        {
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG; /* No need to show network searching screen */
            g_pwr_context.IsCampOnTonePlayed = 1; /* No need to play camp on tone */
        }
    #endif /* __MMI_WLAN_FEATURES__ */
    }

    g_idle_context.IsOnIdleScreen = 1;
    g_idle_context.IsOnDialerScreen = 0;
    g_idle_context.IdleScreenDigitKeyCode = -1;




/* 2009.06.26 added by hongzhe.liu for idle key set + */
IdleStateSetkey();
/* 2009.06.26 added by hongzhe.liu for idle key set - */

    /* This checks if network attach indication has been recieved once after bootup. */
    /* If yes, then go to idle screen otherwise show network srch animation.    */
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (mmi_bootup_is_network_searching_complete() || mmi_bootup_is_sim2_network_searching_complete())
#else
    if (mmi_bootup_is_network_searching_complete() == MMI_TRUE)
#endif
    {
        /* isIdleScreenReached=1; */
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: Idle screen */
        gIsOnSearchingScreen = MMI_FALSE;

    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        if (!(mmi_bootup_is_network_searching_complete() && mmi_bootup_is_sim2_network_searching_complete()) && !IsMyTimerExist(SEARCHING_SCREEN_TIMER))
        {
            StartTimer(SEARCHING_SCREEN_TIMER, 10000, SearchingSrceenTimeOutHandler);
            gIsOnSearchingScreen = MMI_TRUE;
        }
    #endif

        if (!gIsIdleScreenReentry)
        {
            mmi_idle_start_keypad_lock();
            mmi_idle_start_screensaver();
        }
        gIsIdleScreenReentry = MMI_FALSE;
		#ifndef MMI_ON_WIN32
		#ifdef CMS_NEW_APP
		CmsProcessIdleEvent( );
		#endif 
		#endif

        if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
        {
            /* if g_msg_cntx.msg_status is not in idle state, need to help SMS to clear action queue */
            if (mmi_msg_need_clear_action_queue())
            {
                mmi_frm_sms_delete_action_pending();
            }

            if (mmi_idle_exe_callback() == MMI_FALSE)   /* no pending message */
            {
                mmi_idle_entry_idle_screen();   /* idle screen */
            }
        }
        else    /*  Keyapd is locked */
        {
            /* U16 KeyLockLSKStringtID=0, KeyLockRSKStringID=0, KeyLockLSKIconID=0, KeyLockRSKIconID=0; */
            mmi_idle_set_keypad_lock_string();

            /* if g_msg_cntx.msg_status is not in idle state, need to help SMS to clear action queue */
            if (mmi_msg_need_clear_action_queue())
            {
                mmi_frm_sms_delete_action_pending();
            }

            if (mmi_idle_exe_callback() == MMI_FALSE)   /* no pending message */
            {
                /* keypad lock idle screen */
                IdleRefreshServiceIndicationArea();
            #ifdef __MMI_SWFLASH__
                if (dispchar_iswp_swflash())
                {
                    ShowCategory34Screen(
                        g_keylock_context.KeyLockLSKStringID,
                        g_keylock_context.KeyLockLSKIconID,
                        g_keylock_context.KeyLockRSKStringID,
                        g_keylock_context.KeyLockRSKIconID,
                        PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
                }
                else
            #endif /* _MMI_SWFLASH__ */
            #ifdef __MMI_AVATAR__
                if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
                {
                    ShowCategory34Screen(
                        g_keylock_context.KeyLockLSKStringID,
                        g_keylock_context.KeyLockLSKIconID,
                        g_keylock_context.KeyLockRSKStringID,
                        g_keylock_context.KeyLockRSKIconID,
                        PhnsetGetCurWallPaperIdx(), NULL, NULL);
                }
                else
            #endif /* __MMI_AVATAR__ */
                {
                    ShowCategory33Screen(
                        g_keylock_context.KeyLockLSKStringID,
                        g_keylock_context.KeyLockLSKIconID,
                        g_keylock_context.KeyLockRSKStringID,
                        g_keylock_context.KeyLockRSKIconID,
                        NULL);
                    mmi_phnset_save_wallpaper_to_speedup();
                }
            }

        #ifdef __MMI_TOUCH_SCREEN__
            mmi_idle_pen_block(); /* diamond, 2006/06/06 Block pen in all keypad lock screens */
        #endif

        #ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
            mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
        #endif 

            /* diamond, 2006/03/26 Generic exit function for keypad lock callback screens */
            g_keylock_context.keypad_lock_screen_exit = GetCurrExitFuncPtr();
            SetCurrExitFuncPtr(mmi_idle_generic_keypad_lock_screen_exit_hdlr);

        #if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)
            SetGroupKeyHandler(
                EntryScrKeyPadLockOnPessingAnyKey,
                (PU16) PresentAllKeys,
                (U8) TOTAL_KEYS,
                (U16) KEY_EVENT_DOWN);
        #endif /* defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__) */ 

        #ifdef __MMI_TOUCH_SCREEN__
        #ifndef __MMI_KEYPAD_LOCK_PROMPT_TEXT__
            ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
            ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
        #endif /* __MMI_KEYPAD_LOCK_PROMPT_TEXT__ */ 
            SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);
        #else /* __MMI_TOUCH_SCREEN__ */ 
        #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
            SetRightSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_DOWN);
        #endif 
        #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
            SetLeftSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_DOWN);
        #endif 
        #endif /* __MMI_TOUCH_SCREEN__ */ 

            IdleSetLRKey();

        #ifdef __MMI_UNIFIED_MESSAGE__
            if (mmi_um_check_new_msg() && !mmi_um_is_sending_num_msg())
            {
                ClearInputEventHandler(MMI_DEVICE_ALL);
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */

            if (g_idle_context.IsRSKPressOnScreenSaver)
            {
                EntryScrAfterPessingRSK();
                g_idle_context.IsRSKPressOnScreenSaver = 0;
            }

            /* 
             * Compensatory key handler registration for screen saver
             * The idea here is to set those keys which are not set with handlers to a dummy handler. 
             * But note that END key is still being set a handler (DisplayIdleScreen)  for KEY_EVENT_DOWN in PowerAndEndKeyHandler. 
             */
            mmi_idle_dummy_key_in_screensaver();
        }

        mmi_idle_date_time_reminder();
    }
    else    /*  displays network seaching animation */
    {
        if (!gIsOnSearchingScreen)
        {
            StartTimer(SEARCHING_SCREEN_TIMER, 10000, SearchingSrceenTimeOutHandler);
            gIsOnSearchingScreen = MMI_TRUE;
        }

        mmi_idle_entry_searching_screen();
        mmi_idle_date_time_reminder();
    }

    mmi_frm_kbd_reg_pre_key_hdlr(IdleScreenEmergencyCallCheckNKeypadLock);

#ifdef __SAT__
    if (GetPostponedSATScreen())
    {
        (*GetPostponedSATScreen())();
        ClearPostponedSATScreen();
    }
#endif /* __SAT__ */

    gIsIdleScreenReentry = MMI_FALSE;

#ifdef JATAAYU_SUPPORT
    #ifdef WAP_SUPPORT
        mmi_brw_wap_deinit(); /* browser deinit */
    #endif 
    #ifdef MMS_SUPPORT
        mmi_jmms_deinit(); /* MMS deinit */
    #endif 
    mmi_ph_deinit_profiles(); /* profile deinit */
    mmi_prov_deinit();
#endif /* JATAAYU_SUPPORT */

#if defined (__MMI_BROWSER_2__) && defined (WAP_SUPPORT)
    mmi_brw_app_deinit();
#endif

#ifdef __MMI_MMS_2__
    mmi_mv_deinit_viewer();
    mmi_umms_reset_global();
#endif /* __MMI_MMS_2__ */

#ifndef __MTK_TARGET__ /* MoDIS only */
    mmi_netset_write_auto_test_result(MMI_TRUE);
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Is_InCard2securityCheck())
    {
        /* need to check SIM2 PIN1 when first time enter idle screen */
        /* coding here because flight mode check is true in dual sim mode */
        MTPNP_AD_Card2_CHV_Request();
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#if defined(HORSERACE_SUPPORT)
	FlagsReachIdle = 1 ;	
#endif


#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 

        //  Read Once To Make Sure Data Corrent Nicety
	mma745x_ReadXYZ8(&paraX, &paraY, &paraZ);

	//Process_WallPaper_G_Sensor();
	SendMessagesMMIToOne(MSG_ID_GSENSOR_ON);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ExitIdleScreen
 * DESCRIPTION
 *  Exit function for idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitScreen(IDLE_SCREEN_ID, EntryIdleScreen);

    g_idle_context.IsOnIdleScreen = 0;

    mmi_frm_kbd_reg_pre_key_hdlr(NULL);

    if (!g_idle_context.ScreenSaverRunFlag && !gIsIdleScreenReentry)
    {
        PRINT_INFORMATION("[Keypad Lock] ExitIdleScreen: Timer %d Stop", g_idle_context.AutoLockTimeOut);
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
    }

    if (!gIsIdleScreenReentry)
    {
        StopTimer(SCREENSAVER_TIMER);
    }

    StopTimer(KEYPADUNLOCKEDMESSAGE_TIMER);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_status_icon_pen_event_hdlr();
#endif

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
    ResetCenterSoftkey();
#endif 

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
	SendMessagesMMIToOne(MSG_ID_GSENSOR_OFF);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_remove_dialer_screen_exit_handler
 * DESCRIPTION
 *  Removal of dialer screen from history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_remove_dialer_screen_exit_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == IDLE_SCREEN_DIGIT_HANDLER_ID)
    {
        SetCurrExitFuncPtr(NULL); //ReplaceNewScreenHandler(IDLE_SCREEN_DIGIT_HANDLER_ID, NULL, NULL);
        g_idle_context.IsOnDialerScreen = 0;
        g_idle_context.IdleScreenDigitKeyCode = -1;
    }
    else
    {
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_check_nw_provider_name_length
 * DESCRIPTION
 *  Check if the input string length is larger than main lcd width
 * PARAMETERS
 *  unicode_string      [?]     
 *  U8*(?)
 * RETURNS
 *  pBOOL
 *****************************************************************************/
extern void UI_set_font(UI_font_type f);
pBOOL mmi_idle_check_nw_provider_name_length(U8 *unicode_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL rtn;
    S32 StringWidth, StringHeight;
    stFontAttribute prev_f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* copy the system font to backup */
    memcpy(&prev_f, UI_font, sizeof(stFontAttribute));

    /* set default font for length calculation */
    UI_set_font(&UI_DEFAULT_FONT);

    Get_StringWidthHeight(unicode_string, &StringWidth, &StringHeight);

    /* check the string length if it is larger than main lcd width */
    if ((StringWidth + 1) >= MAIN_LCD_device_width - (MMI_IDLE_STRING_MARGIN_GAP << 1))
    {
        rtn = MMI_FALSE;
    }
    else
    {
        rtn = MMI_TRUE;
    }

    /* restore the system font */
    UI_set_font(&prev_f);
    return rtn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_camp_on_chinese_network
 * DESCRIPTION
 *  Check if the current network is in Chinese area
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_idle_is_camp_on_chinese_network(U8 *plmn)
{
    if (memcmp(plmn, "460", 3) == 0 || /* CN */
        memcmp(plmn, "466", 3) == 0 || /* TW */
        memcmp(plmn, "454", 3) == 0)   /* HK */
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IdleRefreshServiceIndicationArea
 * DESCRIPTION
 *  To refresh Service indication Area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define SetLine1Text SetIdleScreenNetworkName
#define SetLine2Text SetIdleScreenNetworkStatus

void IdleRefreshServiceIndicationArea(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
    idleLRStringtID = IDLE_SCREEN_LSK_TEXT;
#else 
    idleLRStringtID = IDLE_SCREEN_RSK_TEXT;
#endif 

    SetLine1Text((U8*) NULL);
    SetLine2Text((U8*) NULL);

#ifdef __MMI_DUAL_SIM_MASTER__
    if (!MTPNP_PFAL_Is_FlightMode() && ( (MTPNP_AD_Get_Status() & MTPNP_AD_CARD1) != MTPNP_AD_CARD1 || MTPNP_PFAL_Is_Card1Absent() || MTPNP_PFAL_Is_Card1CHVBlocked() ) )
    {
        if ((MTPNP_AD_Get_Status() & MTPNP_AD_CARD1) != MTPNP_AD_CARD1)
        {
            MTPNP_PFAL_Show_Idle_Card1Closed();
            /* refresh card2 idle information */
        }
        else if (MTPNP_PFAL_Is_Card1Absent())
        {
            MTPNP_PFAL_Show_Idle_Card1Absent();
            /* refresh card2 idle information */
        }
        else if (MTPNP_PFAL_Is_Card1CHVBlocked())
        {
            MTPNP_PFAL_Show_Idle_Card1Blocked();
        }

        if (mmi_bootup_is_sim2_network_searching_complete() == MMI_FALSE)
        {
            MTPNP_PFAL_Show_Idle_NW_Register();
        }
        else
        {
            MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
        }
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (mmi_bootup_is_sim2_network_searching_complete() == MMI_FALSE)
    {
        MTPNP_PFAL_Show_Idle_NW_Register();
    }
#endif

    /* diamond, 2005/07/22 240x320 sync searching screen style with idle screen style */
#if defined(__MMI_IDLE_NO_NW_SEARCHING_SCREEN__) || defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_network_searching_complete() == MMI_FALSE)
    {
        mmi_ucs2ncpy(
            (PS8) gNWProviderName,
            (PS8) GetString(STR_IDLE_NETWORK_SRCH_SCR),
            MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        if (mmi_bootup_is_sim2_network_searching_complete() == MMI_TRUE)
        {
            MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
        }
    #endif
        return;
    }
#endif /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */ 
    /* end, diamond */

    if (g_pwr_context.CurrentServiceType == FULL_SERVICE)
    {
        /* MMI_BOOL SHOW_OPN = MMI_TRUE; */
        MMI_BOOL OPN_Exist;
        MMI_BOOL Short_OPN_Exist;
        MMI_BOOL SPN_Exist;
        MMI_BOOL MSISDN_Exist = PhnsetGetShowOwnerNumStatus() && (mmi_ucs2strlen(gOwnerName) != 0);
        stFontAttribute IdleScr_Medium_font = {0, 0, 0, MEDIUM_FONT, 0, 0};
        U8 Scenario;

    #if defined(__MMI_OPERATOR_NAME_MENU__)
        /* SHOW_OPN = PhnsetGetShowOPNStatus(); */
        if (PhnsetGetShowOPNStatus() == 0)  /* diamond, 2005/10/18 Hide the service area if this setting is off */
        {
            return;
        }
    #endif /* defined(__MMI_OPERATOR_NAME_MENU__) */ 

        /* Now the line1 string is temporarily set to "Searching" so clear line2 in this case */
        if (mmi_ucs2cmp((PS8) gNWProviderName, GetString(STR_ID_NETSET_SEARCHIN_NW)) == 0)
        {
            SetLine1Text(gNWProviderName);
            return;
        }

        if (IsChineseSet() && mmi_idle_is_camp_on_chinese_network(gPLMN) && !mmi_bootup_is_roaming()) /* Trad. Chinese and Simp. Chinese only */
        {
            /* Ignore OPN because OPN does not have UCS2 encoding */
            Scenario = (gSpnValid ? 2 : 0) + (mmi_idle_is_spn_b1_set() ? 1 : 0);
        }
        else
        {
            /* OPN*4 + SPN*2+ b1*1 */
            Scenario = ((gOpNameValid || gShortOpnameValid) ? 4 : 0) + (gSpnValid ? 2 : 0) + (mmi_idle_is_spn_b1_set() ? 1 : 0);
        }

        PRINT_INFORMATION("[Idle] display scenario: %d", Scenario);

        /* OPN_Exist means gOpNameValid and the string is not NULL */
        OPN_Exist = gOpNameValid && (mmi_ucs2strlen(gOperatorName) != 0) /* && SHOW_OPN */ ;
        Short_OPN_Exist = gShortOpnameValid && (mmi_ucs2strlen(gShortOperatorName) != 0) /* && SHOW_OPN */ ;
        SPN_Exist = gSpnValid && (mmi_ucs2strlen(gServProvderName) != 0);

        SetFont(IdleScr_Medium_font, (U8) gCurrLangIndex);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
        {
            switch (Scenario)   /* OPN--SPN--b1 */
            {
                case 0:                             /* OPN=OFF, SPN=OFF, b1=0 */
                case 1:                             /* OPN=OFF, SPN=OFF, b1=1 */
                    SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                    if (MSISDN_Exist)
                    {
                        SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                    }
                    break;

                case 2: /* OPN=OFF, SPN=ON, b1=0 */
                    if (MSISDN_Exist)
                    {
                        if (mmi_bootup_is_roaming() && !mmi_idle_is_rplmn_in_spdi_list())
                        {
                            SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                            if (SPN_Exist && !mmi_idle_is_spn_b2_set() && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                            {
                                SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                            }
                            else
                            {
                                SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                            }
                        }
                        else
                        {
                            SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                            if (SPN_Exist)
                            {
                                SetLine1Text((U8*) gServProvderName); /* Line 1 = SPN */
                            }
                        }
                    }
                    else
                    {
                        if (mmi_bootup_is_roaming() && !mmi_idle_is_rplmn_in_spdi_list())
                        {
                            SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                            if (SPN_Exist && !mmi_idle_is_spn_b2_set() && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                            {
                                SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                            }
                        }
                        else
                        {
                            if (SPN_Exist)
                            {
                                SetLine1Text((U8*) gServProvderName);  /* Line 1 = SPN */
                            }
                            else
                            {
                                SetLine1Text(gNWProviderName);  /* Line 2 = NULL */
                            }
                        }
                    }
                    break;

                case 3:                             /* OPN=OFF, SPN=ON, b1=1 */
                    SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                    if (mmi_bootup_is_roaming() && !mmi_idle_is_rplmn_in_spdi_list())
                    {
                        if (SPN_Exist && !mmi_idle_is_spn_b2_set() && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                        {
                            SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                        }
                        else if (MSISDN_Exist)
                        {
                            SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                        }
                        else
                        {
                            SetLine2Text((U8*) NULL);
                        }
                    }
                    else
                    {
                        if (SPN_Exist && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                        {
                            SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                        }
                        else if (MSISDN_Exist)
                        {
                            SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                        }
                        else
                        {
                            SetLine2Text((U8*) NULL);
                        }
                    }
                    break;

                case 4: /* OPN=ON, SPN=OFF, b1=0 */
                case 5: /* OPN=ON, SPN=OFF, b1=1 */
                    if (mmi_bootup_is_roaming() == MMI_TRUE)
                    {
                        SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                        if (OPN_Exist)
                        {
                            SetLine2Text((U8*) gOperatorName); /* Line 2 = OPN */
                        }
                        else if (Short_OPN_Exist)
                        {
                            SetLine2Text((U8*) gShortOperatorName);
                        }
                        else    /* They are both valid but NULL */
                        {
                            SetLine2Text((U8*) NULL);
                        }
                    }
                    else
                    {
                        if (OPN_Exist)
                        {
                            SetLine1Text((U8*) gOperatorName); /* Line 1 = OPN */
                        }
                        else if (Short_OPN_Exist)
                        {
                            SetLine1Text((U8*) gShortOperatorName);
                        }
                        else    /* They are both valid but NULL */
                        {
                            SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                        }
                        if (MSISDN_Exist)
                        {
                            SetLine2Text((U8*) gOwnerName); /* Line 2 = Owner Name */
                        }
                    }
                    break;

                case 6: /* OPN=ON, SPN=ON, b1=0 */
                case 7: /* OPN=ON, SPN=ON, b1=1 */
                    if (mmi_bootup_is_roaming() == MMI_TRUE && !mmi_idle_is_rplmn_in_spdi_list())
                    {
                        SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                        if (SPN_Exist && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                        {
                            SetLine2Text((U8*) gServProvderName);      /* Line 2 = SPN */
                        }
                        else if (MSISDN_Exist)
                        {
                            SetLine2Text((U8*) gOwnerName);
                        }
                        else
                        {
                            SetLine2Text((U8*) NULL);
                        }
                    }
                    else
                    {
                        if (OPN_Exist)
                        {
                            SetLine1Text((U8*) gOperatorName); /* Line 1 = OPN */
                            if (SPN_Exist && !mmi_idle_is_spn_b2_set() && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gOperatorName) != 0)
                            {
                                SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                            }
                            else if (MSISDN_Exist)
                            {
                                SetLine2Text((U8*) gOwnerName);        /* Line 2 = MSISDN */
                            }
                            else
                            {
                                SetLine2Text((U8*) NULL);
                            }
                        }
                        else if (Short_OPN_Exist)
                        {
                            SetLine1Text((U8*) gShortOperatorName);    /* Line 1 = Short OPN */
                            if (SPN_Exist && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gShortOperatorName) != 0)
                            {
                                SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                            }
                            else if (MSISDN_Exist)
                            {
                                SetLine2Text((U8*) gOwnerName);        /* Line 2 = MSISDN */
                            }
                            else
                            {
                                SetLine2Text((U8*) NULL);
                            }
                        }
                        else    /* They are both valid but NULL */
                        {
                            if (mmi_idle_is_spn_b1_set())
                            {
                                SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                                if (SPN_Exist && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                                {
                                    SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                                }
                                else if (MSISDN_Exist)
                                {
                                    SetLine2Text((U8*) gOwnerName);        /* Line 2 = MSISDN */
                                }
                                else
                                {
                                    SetLine2Text((U8*) NULL);
                                }
                            }
                            else
                            {
                                if (SPN_Exist)
                                {
                                    SetLine1Text((U8*) gServProvderName);  /* Line 1: SPN */
                                }
                                else
                                {
                                    SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                                }

                                if (MSISDN_Exist)
                                {
                                    SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                                }
                            }
                        }
                    }
                    break;

                default:
                    MMI_ASSERT(0);
                    break;
            }
        }

    #ifdef __MMI_NITZ__
        mmi_idle_update_nitz_content();
        if (g_nitz_display.opname_from_nitz && mmi_idle_check_nitz_display_validation())
        {
            PRINT_INFORMATION("[Idle] Network name from NITZ");
            if (mmi_bootup_is_roaming())
            {
                /* Roaming and receive NITZ network name */
                SetLine1Text(g_nitz_display.display_name);
            }
            else if (!OPN_Exist && mmi_idle_is_spn_b1_set()) /* not roaming but no OPN */
            {
                /* Network name from NITZ takes lower priority from OPN, but not replace SPN */
                SetLine1Text(g_nitz_display.display_name);
            }
        }
    #endif /* __MMI_NITZ__ */ 

    #ifdef __HOMEZONE_SUPPORT__
        if (gHomezoneText)
        {
            SetLine2Text((U8*) gHomezoneText);
        }
    #endif /* __HOMEZONE_SUPPORT__ */ 
    }
#ifdef __MANUAL_MODE_NW_SEL__
    else if (g_pwr_context.CurrentServiceType == LIMITED_SERVICE)
    {
    #ifdef __MMI_SIMAP_SUPPORT__
        if (mmi_bootup_get_active_bt_access_profile_mode())
        {
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8)L"SIM Access Profile", MAX_LENGTH_DISPLAY_NAME - 1);
        }
        else
    #endif /* __MMI_SIMAP_SUPPORT__ */
    #ifdef __MMI_WLAN_FEATURES__
        if (!mmi_bootup_is_sim_valid())
        {
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(simErrorDisplayString), MAX_LENGTH_DISPLAY_NAME - 1);
        }
        else
    #endif /* __MMI_WLAN_FEATURES__ */
        if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
        {
            if (mmi_bootup_is_nw_registration_ok() == MMI_FALSE)
            {
                mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_SIM_INVALID_SIM_TITLE), MAX_LENGTH_DISPLAY_NAME - 1); /* L1: "Invalid SIM" */
            }
            else
            {
                mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_LIMITED_SERVICE), MAX_LENGTH_DISPLAY_NAME - 1); /* L1: "Emergency" */
            }
        }
        else
        {
            /* L1: "Select Network" */
            /* diamond, 2005/12/18 Check if the input string length is larger than main lcd width */
            if (mmi_bootup_is_nw_registration_ok() == MMI_FALSE)
            {
                mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_SIM_INVALID_SIM_TITLE), MAX_LENGTH_DISPLAY_NAME - 1); /* L1: "Invalid SIM" */
            }
            else
            {
                if (mmi_idle_check_nw_provider_name_length((PU8) GetString(STR_ID_NETSET_MANUAL_MODE_TITLE)))
                {
                    mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_ID_NETSET_MANUAL_MODE_TITLE), MAX_LENGTH_DISPLAY_NAME - 1);
                }
                else
                {
                    mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_ID_NETSET_MANUAL_MODE_SHORT), MAX_LENGTH_DISPLAY_NAME - 1);
                }
            #ifndef __MMI_DUAL_SIM_MASTER__
            #ifdef __MMI_WLAN_FEATURES__
                if (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)
            #endif
                    idleLRStringtID = STR_GLOBAL_SELECT;
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }
        }
        SetLine1Text(gNWProviderName);
    }
    else if (g_pwr_context.CurrentServiceType == NO_SERVICE)
    {
        /* L1: "No Service" */
    #ifdef __FLIGHT_MODE_SUPPORT__
        if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_MENU_FLIGHT_MODE), MAX_LENGTH_DISPLAY_NAME - 1);
        else
    #endif /* __FLIGHT_MODE_SUPPORT__ */ 
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_NO_SERVICE), MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);
    }
    else    /* temporarily remove the string */
    {
        /* L1: "" */
        SetLine1Text((U8*) NULL);

    }

#else /* __MANUAL_MODE_NW_SEL__ */ 
    else if (g_pwr_context.CurrentServiceType == LIMITED_SERVICE)
    {
    #ifdef __MMI_SIMAP_SUPPORT__
        if (mmi_bootup_get_active_bt_access_profile_mode())
            mmi_ucs2ncpy((PS8) gNWProviderName, L"SIM Access Profile", MAX_LENGTH_DISPLAY_NAME - 1);
        else
    #endif /* __MMI_SIMAP_SUPPORT__ */
        /* L1: "Limited Service" */
    #ifdef __MMI_WLAN_FEATURES__
        if (!mmi_bootup_is_sim_valid())
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(simErrorDisplayString), MAX_LENGTH_DISPLAY_NAME - 1);
        else
    #endif /* __MMI_WLAN_FEATURES__ */
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_LIMITED_SERVICE), MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);
    }
    else    /* if ( gNoService ) */
    {
        /* L1: "No Service" */
    #ifdef __FLIGHT_MODE_SUPPORT__
        if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_MENU_FLIGHT_MODE), MAX_LENGTH_DISPLAY_NAME - 1);
        else
    #endif /* __FLIGHT_MODE_SUPPORT__ */ 
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_NO_SERVICE), MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);
    }

#endif /* __MANUAL_MODE_NW_SEL__ */ 

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT)
    {
        mmi_netset_update_preferred_mode_service_area();
    }
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim2_network_searching_complete() != MMI_FALSE)
    {
        MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
}

#undef SetLine1Text
#undef SetLine2Text


/*****************************************************************************
 * FUNCTION
 *  IdleToggleProfile
 * DESCRIPTION
 *  Toggles profiles between silent mode and current activated profile on long press of # key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleToggleProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == 5)
    {
        g_idle_context.ToggleProfile = SET_SILENT_PROFILE;
    }
    else
    {
        g_idle_context.ToggleProfile = SET_CURRENT_PROFILE;
    }

    ClearKeyEvents();
    if (g_idle_context.ToggleProfile == SET_CURRENT_PROFILE)
    {
        g_idle_context.ToggleProfile = SET_SILENT_PROFILE;
        ActivateSilentProfile();
    }
    else
    {
        g_idle_context.ToggleProfile = SET_CURRENT_PROFILE;
        DeactivateSilentProfile();
    }

#ifdef __MMI_STARKEY_TOGGLE_PROFILE__
    SetKeyHandler(NULL, KEY_STAR, KEY_EVENT_UP);
#else
    SetKeyHandler(NULL, KEY_POUND, KEY_EVENT_UP);
#endif

    /* diamond, 2005/10/21 disable long press if # is long pressed when earphone is plugged in */
#ifdef __MMI_BT_PROFILE__
    if (isEarphonePlugged || mmi_profiles_bt_is_activated())
#else 
    if (isEarphonePlugged)
#endif 
        IdleDisableLongPress();
}


/*****************************************************************************
 * FUNCTION
 *  IdleStopToggleTimer
 * DESCRIPTION
 *  Stop toggle Profile timer of # key..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleStopToggleTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TOGGLE_TIMER);
    VibratorOff();
}


/*****************************************************************************
 * FUNCTION
 *  IdleCallSpeedDialOnLongPress
 * DESCRIPTION
 *  Implements speed dial on idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleCallSpeedDialOnLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    S8 *tempbuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);

    if ((Keycode >= 1) && (Keycode <= 9))
    {
        mmi_idle_remove_dialer_screen_exit_handler();
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
    #else
        if (!g_phb_cntx.phb_ready)
    #endif
        {
            mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
            return;
        }

        tempbuffer = PhbGetSpeedDialNum(Keycode);
        if (tempbuffer != NULL)
        {
            mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, tempbuffer);
	#ifdef __MMI_DUAL_SIM_MASTER__
            mmi_ucm_app_entry_dial_option((U8*) g_idle_context.DialPadCallBuffer, NULL, NULL);
	#else /* __MMI_DUAL_SIM_MASTER__ */
            IdleDialPadCall();
	#endif /* __MMI_DUAL_SIM_MASTER__ */
        }
        else
        {
            IdleShowScrNoSpeedDialNumSaved();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  IdleShowScrNoSpeedDialNumSaved
 * DESCRIPTION
 *  Displays pop up: no speed dial number saved for this digit.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleShowScrNoSpeedDialNumSaved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@@ NO SPEED DIAL NUMBER SAVED @@@@@@@@@");
    DeleteUptoScrID(IDLE_SCREEN_ID);
    DisplayPopup((U8*) GetString(STR_NO_SPEED_DIAL_NUM_SAVED), IMG_GLOBAL_WARNING, 0, 2000, (U8) WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  IdleAbbrevDialling
 * DESCRIPTION
 *  Quick acces to phonebook entries.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleAbbrevDialling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tempbuffer[(MAX_LOCATION_DIGITS + 1) * ENCODING_LENGTH];
    U8 count, i = 0;
    U16 Location;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempbuffer, 0, ((MAX_LOCATION_DIGITS + 1) * ENCODING_LENGTH));

    /* Don't do anything when shifting out digits */
    if (mmi_ucs2strlen((PS8) g_idle_context.DialPadCallBuffer) >= (MAX_DIAL_PAD - 1))
    {
        return;
    }

    if ((g_idle_context.DialPadCallBuffer[0] >= '0') && (g_idle_context.DialPadCallBuffer[0] <= '9'))
    {
        /* This loop search for '#' in DialpadCallbuffer,if # is not found before MAX_LOCATION_DIGITS then return */
        for (count = 0; (g_idle_context.DialPadCallBuffer[count] != '#'); count++)
        {
            if (count > (MAX_LOCATION_DIGITS * ENCODING_LENGTH - 1) ||
                g_idle_context.DialPadCallBuffer[count] == '*' ||
                g_idle_context.DialPadCallBuffer[count] == '+' ||
                g_idle_context.DialPadCallBuffer[count] == 'p' ||
                g_idle_context.DialPadCallBuffer[count] == 'w')
            {
                return;
            }
            tempbuffer[i] = g_idle_context.DialPadCallBuffer[count];
            i++;
        }
        if (g_idle_context.DialPadCallBuffer[count + 2] == 0)   /* no other digits after the first found # */
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            if (MTPNP_AD_Get_UsableSide() < MTPNP_AD_SIMCARD1_USABLE)
            {
                return;
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */

            Location = (U16) gui_atoi((UI_string_type) tempbuffer);
            mmi_idle_remove_dialer_screen_exit_handler();
            mmi_phb_get_sim_entry_by_location((U16) Location);
        }
    }
    else if (!SSCStringParsing3())
    {
        SSCStringParsing1();
    }
}


/*****************************************************************************
 * FUNCTION
 *  IdleShowScrInvalidLocation
 * DESCRIPTION
 *  Displays popup for Invalid location
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleShowScrInvalidLocation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@@ INVALID LOCATION IN PHONE BOOK @@@@@@@@@");
    DisplayPopup((U8*) GetString(STR_INVALID_LOCATION), IMG_GLOBAL_WARNING, 0, 2000, (U8) WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  IdleShowScrNoPhoneNumEntry
 * DESCRIPTION
 *  Show pop up that no phone book entry saved on this location.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleShowScrNoPhoneNumEntry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@@ NO PHONE NUMBER CORRESPONDING TO THIS LOCATION @@@@@@@@@");
    DisplayPopup((U8*) GetString(STR_NO_PHONE_NUM), IMG_GLOBAL_WARNING, 0, 2000, (U8) WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  IdleDialPadSavePhoneBook
 * DESCRIPTION
 *  Save entered number in phonebook on press of LSK on dialler screen.
 *  
 *  Temorary function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleDialPadSavePhoneBook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VOIP__
    if (IsScreenPresent(SCR_ID_VOIP_CALL_EDITOR)) /* save voip uri */
    {        
        if (mmi_ucs2strlen((S8*)g_idle_context.DialPadCallBuffer))
        {
            mmi_phb_save_entry_for_service_field(NULL, (S8*)g_idle_context.DialPadCallBuffer, MMI_PHB_ENTER_FROM_VOIP);
        }
        else
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_VOIP_EMPTY_USERNAME),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE_IN_CALL);
            DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID); /* go back to call editor screen */
        }        
    }
    else
#endif /* __MMI_VOIP__ */
    {
        SaveNumberFromIdleScrn(g_idle_context.DialPadCallBuffer, 0);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  IdleDialPadCall
 * DESCRIPTION
 *  Make a call from scratch pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleDialPadCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __IP_NUMBER__
    SetTempUseIPNumber(FALSE);
#endif 

    /* to disable the dialing if no digit is present */
#ifdef __MMI_TOUCH_DIAL_SCREEN__
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
#else 
    if (!SSCStringParsing2())
#endif 
    {
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_pen_reset();
    #endif
        ClearInputEventHandler(MMI_DEVICE_ALL);
    #ifdef __MMI_BG_SOUND_EFFECT__
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (g_bgsnd_cntx.set.status == 0 || CheckValidEmergencyNo1(g_idle_context.DialPadCallBuffer, SIM1) == MMI_TRUE || CheckValidEmergencyNo1(g_idle_context.DialPadCallBuffer, SIM2) == MMI_TRUE)
    #else
        if (g_bgsnd_cntx.set.status == 0 || CheckValidEmergencyNo1(g_idle_context.DialPadCallBuffer) == MMI_TRUE)
    #endif
        {
            /* no background sound so not save dialer screen to history */
            mmi_idle_remove_dialer_screen_exit_handler();
        }
        MakeCall(g_idle_context.DialPadCallBuffer);
    #else /* __MMI_BG_SOUND_EFFECT__ */
        mmi_idle_remove_dialer_screen_exit_handler();
        MakeCall(g_idle_context.DialPadCallBuffer);
    #endif /* __MMI_BG_SOUND_EFFECT__ */
    }
}


#ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
/*****************************************************************************
 * FUNCTION
 *  IdleDialPadVideoCall
 * DESCRIPTION
 *  Dial video call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleDialPadVideoCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __IP_NUMBER__
    SetTempUseIPNumber(FALSE);
#endif 

    /* to disable the dialing if no digit is present */
#ifdef __MMI_TOUCH_DIAL_SCREEN__
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
#else 
    if (!SSCStringParsing2())
#endif 
    {
        mmi_idle_remove_dialer_screen_exit_handler();
        mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*)g_idle_context.DialPadCallBuffer);
    }
}
#endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */ 


/*****************************************************************************
 * FUNCTION
 *  DialIPNumber
 * DESCRIPTION
 *  Dial IP Number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __IP_NUMBER__
void DialIPNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetTempUseIPNumber(TRUE);

    if (!SSCStringParsing2())
    {
        mmi_idle_remove_dialer_screen_exit_handler();
        MakeCall(g_idle_context.DialPadCallBuffer);
    }
}
#endif /* __IP_NUMBER__ */ 


/*****************************************************************************
 * FUNCTION
 *  IdleScreenDigitHandler
 * DESCRIPTION
 *  Inputs the digits of a phone number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;
    U16 dial_pad_left_softkey = STR_GLOBAL_SAVE;

    U16 SpeedDialKeys[MAX_SPEED_DIAL_KEYS] =
        {KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9};

#ifdef __MMI_MULTITAP_KEY_0__
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS - 1] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};
#else
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS - 2] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, /*KEY_STAR,*/ KEY_POUND};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#ifdef __MMI_UCM__
    if (mmi_idle_get_dial_mode())
#else
    if (mmi_netset_get_dial_mode())
#endif
    {
        mmi_frm_unhide_menu_item(MENU_ID_DIALER_SCREEN_OPTIONS_INPUT_METHOD);
        mmi_netset_enter_wlan_dialer_screen();
        return;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_DIALER_SCREEN_OPTIONS_INPUT_METHOD);
    }
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */

    EntryNewScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, ExitIdleScreenDigitHandler, NULL, NULL);

    DeInitSpecialMode();

    g_idle_context.IsOnDialerScreen = 1;
    history_buffer = GetCurrGuiBuffer(IDLE_SCREEN_DIGIT_HANDLER_ID);

#if (UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif

#ifdef __MMI_UCM__
    #ifdef __MMI_VIDEO_TELEPHONY__
        dial_pad_left_softkey = STR_GLOBAL_OPTIONS;
    #else /* __MMI_VIDEO_TELEPHONY__ */
        #if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
            if (mmi_netset_get_active_preferred_mode() == P_GSM_PREFERRED || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
                dial_pad_left_softkey = STR_GLOBAL_OPTIONS;
            else
        #endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
                dial_pad_left_softkey = STR_GLOBAL_SAVE;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
#else /* __MMI_UCM__ */
    #if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
        if (mmi_netset_get_active_preferred_mode() == P_GSM_PREFERRED || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
            dial_pad_left_softkey = STR_GLOBAL_OPTIONS;
        else
    #endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
            dial_pad_left_softkey = STR_GLOBAL_SAVE;
#endif /* __MMI_UCM__ */

#if ( defined (__MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) && !defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__))
    if (mmi_bootup_get_active_flight_mode() != 1)
    {
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    }
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) && !defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)) */ 

    ShowCategory16Screen(
        dial_pad_left_softkey,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_idle_context.DialPadCallBuffer,
        MAX_DIAL_PAD,
        history_buffer);

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__))
#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
#ifndef __MMI_DUAL_SIM_MASTER__
    SetDialingKeypadCallHandler((mmi_bootup_is_sim_valid() == MMI_TRUE) ? IdleDialPadCall : EntryScrEmergencyCallDialing);
#else
    SetDialingKeypadCallHandler((MTPNP_AD_Get_UsableSide() >= MTPNP_AD_SIMCARD1_USABLE) ? IdleDialPadCall : EntryScrEmergencyCallDialing);
#endif
#else /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#ifdef __MMI_WGUI_CSK_ENABLE__
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_SetCenterFunc(IdleDialPadCall);
    SetCenterSoftkeyFunction((MTPNP_AD_Get_UsableSide() >= MTPNP_AD_SIMCARD1_USABLE) ? MTPNP_PFAL_CC_CSKHandler : EntryScrEmergencyCallDialing, KEY_EVENT_UP);
#else
    SetCenterSoftkeyFunction(((mmi_bootup_is_sim_valid() == MMI_TRUE) ? IdleDialPadCall : EntryScrEmergencyCallDialing), KEY_EVENT_UP);
#endif
#endif /* __MMI_WGUI_CSK_ENABLE__ */
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__)) */ 

    if (g_idle_context.IdleScreenDigitKeyCode >= 0)
    {
        ExecuteCurrKeyHandler(g_idle_context.IdleScreenDigitKeyCode, KEY_EVENT_DOWN);
    }

/* LSK on dialer screen */
#ifdef __MMI_UCM__
    /* 
     * [voice call + video call + video call] LSK: option (no matter preferred mode) 
     * [voice call + video call] LSK: option
     * [voice call + voip call]  LSK: option/save (concerning preferred mode)
     * [voice call] LSK: save
     */
    #ifdef __MMI_VIDEO_TELEPHONY__
        SetLeftSoftkeyFunction(mmi_idle_entry_dial_pad_option, KEY_EVENT_UP);
    #else /* __MMI_VIDEO_TELEPHONY__ */
        #if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
            if (mmi_netset_get_active_preferred_mode() == P_GSM_PREFERRED || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
                SetLeftSoftkeyFunction(mmi_idle_entry_dial_pad_option, KEY_EVENT_UP);
            else
        #endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
                SetLeftSoftkeyFunction(IdleDialPadSavePhoneBook, KEY_EVENT_UP);
    #endif /* __MMI_VIDEO_TELEPHONY__ */
#else /* __MMI_UCM__ */
    #if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
        if (mmi_netset_get_active_preferred_mode() == P_GSM_PREFERRED || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
            SetLeftSoftkeyFunction(mmi_netset_enter_wlan_dialer_option, KEY_EVENT_UP);
        else
    #endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
            SetLeftSoftkeyFunction(IdleDialPadSavePhoneBook, KEY_EVENT_UP);
#endif /* __MMI_UCM__ */

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(((MTPNP_AD_Get_UsableSide() >= MTPNP_AD_SIMCARD1_USABLE) ? IdleDialPadCall : EntryScrEmergencyCallDialing),KEY_EVENT_UP/*IdleDialPadCall*/);
#else
    SetKeyHandler(((mmi_bootup_is_sim_valid() == MMI_TRUE) ? IdleDialPadCall : EntryScrEmergencyCallDialing), KEY_SEND, KEY_EVENT_UP);
#endif

    SetKeyHandler(IdleAbbrevDialling, KEY_POUND, KEY_EVENT_UP);

    SetCategory16RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
    SetKeyHandler(((mmi_bootup_is_sim_valid() == MMI_TRUE) ? IdleDialPadVideoCall : EntryScrEmergencyCallDialing), KEY_ENTER, KEY_EVENT_UP);
#endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */

#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif 

#if (UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif

#ifdef __MMI_STARKEY_TOGGLE_PROFILE__
    if ((g_idle_context.LongPressEnable == 0) && !history_buffer) /* prevent from press * and then long press # */
#else /* __MMI_STARKEY_TOGGLE_PROFILE__ */ 
#ifdef __MMI_TOUCH_SCREEN__
    if ((g_idle_context.LongPressEnable == 0) && (g_idle_context.IdleScreenDigitKeyCode != KEY_STAR))
#else
    if ((g_idle_context.LongPressEnable == 0) && (g_idle_context.IdleScreenDigitKeyCode != KEY_STAR) && !history_buffer)
#endif
#endif /* __MMI_STARKEY_TOGGLE_PROFILE__ */ 
    {
        mmi_phb_call_set_dial_from_list(MMI_PHB_NONE);  /* diamond, 2006/02/13 Reset dial from list flag */

    #ifdef __MMI_DUAL_SIM_MASTER__
        if(MTPNP_AD_Get_UsableSide() >= MTPNP_AD_SIMCARD1_USABLE)
    #else
        if (mmi_bootup_is_sim_valid())
    #endif
        {
            if (PhbGetSpeedDialStatus() == MMI_TRUE)
            {
                SetGroupKeyHandler(IdleCallSpeedDialOnLongPress, SpeedDialKeys, MAX_SPEED_DIAL_KEYS - 1, KEY_LONG_PRESS);
            }

            SetKeyHandler(DialVoiceMail, KEY_1, KEY_LONG_PRESS);
        }

    #ifdef __MMI_STARKEY_TOGGLE_PROFILE__
        SetKeyHandler(IdleToggleProfile, KEY_STAR, KEY_LONG_PRESS);
    #else 
        SetKeyHandler(IdleToggleProfile, KEY_POUND, KEY_LONG_PRESS);
    #endif 

    #ifdef __MMI_POUNDKEY_ENTER_PROFILE__
        SetKeyHandler(mmi_profiles_entry_main_screen, KEY_POUND, KEY_LONG_PRESS);
    #endif 

    #ifdef __MMI_MULTITAP_KEY_0__
        SetGroupKeyHandler(IdleDisableLongPress, (PU16) IdleScreenDigits, (U8) MAX_IDLE_SCREEN_DIGITS - 1, KEY_EVENT_UP);
    #else
        SetGroupKeyHandler(IdleDisableLongPress, (PU16) IdleScreenDigits, (U8) MAX_IDLE_SCREEN_DIGITS - 2, KEY_EVENT_UP);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitIdleScreenDigitHandler
 * DESCRIPTION
 *  Exit function for idle screen digit handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitIdleScreenDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
    {
        GenericExitScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, FlightModeDigitHandler);
    }
    else
    {
        GenericExitScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, IdleScreenDigitHandler);
    }

    g_idle_context.IsOnDialerScreen = 0;
    g_idle_context.IdleScreenDigitKeyCode = -1;
#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
    ResetCenterSoftkey();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  HandleIdleScreenDigitEntry
 * DESCRIPTION
 *  This function is entered when a key is pressed at the Idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleIdleScreenDigitEntry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    sprintf(g_idle_context.DialPadCallBuffer, "");
    g_idle_context.IdleScreenDigitKeyCode = Keycode;

    /* diamond, 2005/07/05 Flight mode */
#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
    {
        FlightModeDigitHandler();
    }
    else
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
        /* end, diamond */
        IdleScreenDigitHandler();
}


#ifdef __MMI_MULTITAP_KEY_0__
extern void dialer_inputbox_handle_zero_key_long_press(void);
extern void MMI_key_0_up(void);
#endif /* #ifdef __MMI_MULTITAP_KEY_0__ */
/*****************************************************************************
 * FUNCTION
 *  IdleDisableLongPress
 * DESCRIPTION
 *  Disbale some long press handlers on up event of key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleDisableLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MULTITAP_KEY_0__
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS - 1] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};
#else
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS - 2] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, /*KEY_STAR,*/ KEY_POUND};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.LongPressEnable = 1;

    /* clear key long press event and key up event */
#ifdef __MMI_MULTITAP_KEY_0__
    SetGroupKeyHandler(NULL, (PU16) IdleScreenDigits, (U8) MAX_IDLE_SCREEN_DIGITS - 1, KEY_LONG_PRESS);
    SetGroupKeyHandler(NULL, (PU16) IdleScreenDigits, (U8) MAX_IDLE_SCREEN_DIGITS - 1, KEY_EVENT_UP);
    SetKeyHandler(dialer_inputbox_handle_zero_key_long_press, KEY_0, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(MMI_key_0_up, KEY_0, KEY_EVENT_UP);
#else
    SetGroupKeyHandler(NULL, (PU16) IdleScreenDigits, (U8) MAX_IDLE_SCREEN_DIGITS - 2, KEY_LONG_PRESS);
    SetGroupKeyHandler(NULL, (PU16) IdleScreenDigits, (U8) MAX_IDLE_SCREEN_DIGITS - 2, KEY_EVENT_UP);
#endif
    /* re-register key up event */
    SetKeyHandler(IdleAbbrevDialling, KEY_POUND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  IdleSetKeyPadLockFlag
 * DESCRIPTION
 *  This function is called when time out occurs on idle screen to set key pad lock flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleSetKeyPadLockFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[Keypad Lock] SetKeyPadLockFlag: gKeyPadLockFlag ON");

    g_keylock_context.gKeyPadLockFlag = 1;

#if 0   /* diamond, 2006/03/07 Not necessary to block pen here because pen is blocked in EntryIdleScreen */
	#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
	#endif
#endif /* 0 */ 

#ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
#endif 

    if (g_idle_context.ScreenSaverRunFlag != 1)
    {
        /* Screen saver is not running, using SetRightSoftkeyFunction() for redrew softkey */
        EntryIdleScreen();
    #ifndef __MMI_TOUCH_SCREEN__
        SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS /* MAX_KEYS - 1 */ , KEY_EVENT_DOWN);
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
        SetRightSoftkeyFunction(IdleRSKPressOnScreenSaver, KEY_EVENT_DOWN);
    #endif 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
        SetLeftSoftkeyFunction(IdleRSKPressOnScreenSaver, KEY_EVENT_DOWN);
    #endif 
    #endif /* __MMI_TOUCH_SCREEN__ */ 

    #ifdef __MMI_TOUCH_SCREEN__
        ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK);
        UpdateStatusIcons();    /* 101805 ChangeStatusIconImage Calvin: ChangeStatusIconImage will not call UpdateStatusIcon */
    #else /* __MMI_TOUCH_SCREEN__ */ 
        IdleSetStatusIcon(STATUS_ICON_KEYPAD_LOCK);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    else
    {
        /* Robin 1216, Screen saver is running, using SetKeyHandler() to prevent redrew softkey */
    #ifdef __MMI_TOUCH_SCREEN__
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_SEND, KEY_EVENT_DOWN);
    #else /* __MMI_TOUCH_SCREEN__ */ 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_RSK, KEY_EVENT_DOWN);
    #endif 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_LSK, KEY_EVENT_DOWN);
    #endif 

    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }

    PRINT_INFORMATION("[Keypad Lock] SetKeyPadLockFlag: Timer %d Expire", g_idle_context.AutoLockTimeOut);
    StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  IdleSetStatusIcon
 * DESCRIPTION
 *  Show Icon
 * PARAMETERS
 *  index       [IN]        
 *  U8(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IdleSetStatusIcon(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowStatusIcon(index);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  IdleResetStatusIcon
 * DESCRIPTION
 *  Hide Icon
 * PARAMETERS
 *  index       [IN]        
 *  U8(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IdleResetStatusIcon(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HideStatusIcon(index);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  IsChineseSet
 * DESCRIPTION
 *  This function tells whether current lang is set as chinese or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        return 1;
    }

    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        return 1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  IsEnglishSet
 * DESCRIPTION
 *  This function tells whether current lang is set as chinese or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsEnglishSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH) == 0)
    {
        return 1;
    }

    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_AUTO) == 0)
    {
        return 1;
    }

    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  IsTrChineseSet
 * DESCRIPTION
 *  This fn tells whether traditional chinese is set or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsTrChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  IsSmChineseSet
 * DESCRIPTION
 *  This fn tells whether simplified chinese is set or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsSmChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ReadValueCityNVRAM
 * DESCRIPTION
 *  Read city values from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReadValueCityNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 city_chosen1;
    U8 city_chosen2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE, &error);
    if (city_chosen1 == 0xff)
    {
        city_chosen1 = PhnsetGetHomeCity();
        city_chosen1++;
        WriteValue(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE, &error);

    }
    ReadValue(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE, &error);
    if (city_chosen2 == 0xff)
    {
        city_chosen2 = 0;
        WriteValue(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryIdleAppSubLcdWithErrorMsg
 * DESCRIPTION
 *  Show Sub LCD idle screen with error message
 * PARAMETERS
 *  message             [?]         
 *  message_icon        [IN]        
 *  history_buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EntryIdleAppSubLcdWithErrorMsg(U8 *message, U16 message_icon, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    DinitSubLCDHistory();
    ShowCategory301Screen(message, message_icon, history_buffer);
    SetSubLCDExitHandler(ExitSubLCDIdleScr);
}


/*****************************************************************************
 * FUNCTION
 *  ShowIdleAppSubLcd
 * DESCRIPTION
 *  Show Sub LCD idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
extern U8 gMMIClamState;
#endif 

void ShowIdleAppSubLcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *CityAbbr1, *CityAbbr2;
    FLOAT time_difference;
    U8 city_chosen1;
    U8 city_chosen2;
    U8 home_city_sublcd;
    FLOAT diff1, diff2;
    S16 error = -1;
    BOOL show_category_333_screen = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (IsSubLCDInMasterMode())
    {
        return ;
    }
    if (EntrySubLCDMasterFromIdle())
    {
        return ;
    }
#endif /* __MMI_SUBLCD_MASTER_MODE__ */   

    ExecSubLCDCurrExitHandler();
    DinitSubLCDHistory();

    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_ON_IDLE_NORMAL;
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (gMMIClamState == 1)
    {
        ShowCategory310Screen((U8*) get_string(STR_GLOBAL_LOGO), 0, NULL);
    }
    else
    {
        ShowSubLCDAnalogClockScreen();
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 


#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        show_category_333_screen = TRUE;
    }
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        show_category_333_screen = TRUE;
    }
#endif /* __MMI_FM_RADIO__ */ 

    if (show_category_333_screen)
    {
        ShowCategory333Screen();
    }
    else
    {
        ReadValue(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE, &error);
        ReadValue(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE, &error);
        home_city_sublcd = PhnsetGetHomeCity();
        home_city_sublcd++;

        if (city_chosen1 > 57)
        {
            city_chosen1 = 1;
        }

        if (city_chosen2 > 57)
        {
            city_chosen2 = 1;
        }
        if ((TimeZoneData[city_chosen1].CityAbbr != STR_WCLOCK_CITY_ABBRE_NONE) &&
            (TimeZoneData[city_chosen2].CityAbbr != STR_WCLOCK_CITY_ABBRE_NONE))
        {

            CityAbbr1 = GetString((U16) TimeZoneData[city_chosen1].CityAbbr);
            CityAbbr2 = GetString((U16) TimeZoneData[city_chosen2].CityAbbr);
            diff1 = TimeZoneData[city_chosen1].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;
            diff2 = TimeZoneData[city_chosen2].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;

            ShowCategory303Screen((U8*) CityAbbr1, (U8*) CityAbbr2, diff1, diff2, NULL);

        }
        else if (TimeZoneData[city_chosen1].CityAbbr != STR_WCLOCK_CITY_ABBRE_NONE)
        {
            CityAbbr1 = GetString((U16) TimeZoneData[city_chosen1].CityAbbr);
            time_difference = TimeZoneData[city_chosen1].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;
            ShowCategory312Screen((U8*) CityAbbr1, time_difference, NULL);

        }
        else if (TimeZoneData[city_chosen2].CityAbbr != STR_WCLOCK_CITY_ABBRE_NONE)
        {
            CityAbbr2 = GetString((U16) TimeZoneData[city_chosen2].CityAbbr);
            time_difference = TimeZoneData[city_chosen2].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;
            ShowCategory312Screen((U8*) CityAbbr2, time_difference, NULL);

        }
        else if ((TimeZoneData[city_chosen1].CityAbbr == STR_WCLOCK_CITY_ABBRE_NONE) &&
                 (TimeZoneData[city_chosen2].CityAbbr == STR_WCLOCK_CITY_ABBRE_NONE))
        {
            city_chosen1 = home_city_sublcd;
            CityAbbr1 = GetString((U16) TimeZoneData[city_chosen1].CityAbbr);
            time_difference = TimeZoneData[city_chosen1].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;
            ShowCategory312Screen((U8*) CityAbbr1, time_difference, NULL);
        }
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

#ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose() && FALSE == isInCall())
    {
        SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    }
#endif

    SetSubLCDExitHandler(ExitSubLCDIdleScr);

#ifdef __MMI_SUBLCD_MASTER_MODE__
    UnFreezeSubLCD();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDIdleScreen
 * DESCRIPTION
 *  Displays the idle screen of sub-LCD
 * PARAMETERS
 *  funcptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDIdleScreen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_SUBHIST_SUBLCD_IDLE_SCRN_HDLR); */
    PRINT_INFORMATION("SubLCDIdleScreen");

#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (IsSubLCDInMasterMode())
    {
        return;
    }
    if (EntrySubLCDMasterFromIdle())
    {
        return;
    }
#endif /* __MMI_SUBLCD_MASTER_MODE__ */   

    if (g_pwr_context.PrevScreenIndicator == ENTER_PIN_SCR)
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_ENTER_PIN_MSG), 0, NULL);
    }
    else if ((g_pwr_context.PrevScreenIndicator == ENTER_PUK_SCR) ||
             (g_pwr_context.PrevScreenIndicator == ENTER_CONFIRM_PIN) ||
             (g_pwr_context.PrevScreenIndicator == ENTER_NEW_PIN))
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_ENTER_PUK_MSG), 0, NULL);
    }
    else if (g_pwr_context.PrevScreenIndicator == ENTER_PHONELOCK)
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_ENTER_PHONELOCK_MSG), 0, NULL);
    }
    else if (g_pwr_context.PrevScreenIndicator == ENTER_SIM_INSERTION)
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_SIM_INSERTION_MSG), 0, NULL);
    }
    else if (g_pwr_context.PrevScreenIndicator == ENTER_SIM_BLOCK)
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_SIM_BLOCK_MSG), 0, NULL);
    }
    else /* if (g_pwr_context.PrevScreenIndicator == ENTER_IDLE_SCR) */
    {
        /* City names and time difference need to be added here  */
        ShowIdleAppSubLcd();
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

#ifdef __MMI_SUBLCD_MASTER_MODE__
    UnFreezeSubLCD();
#endif

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDIdleScr
 * DESCRIPTION
 *  Exit sublcd idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDIdleScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_NOT_ON_IDLE;
    SubLCDHistory.entryFuncPtr = SubLCDIdleScreen;
    AddSubLCDHistory(&SubLCDHistory);
}


/*****************************************************************************
 * FUNCTION
 *  IdleHandleKeypadLockProcess
 * DESCRIPTION
 *  This fn handle the press of star key , when LSK is pressed first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleHandleKeypadLockProcess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(KEYPAD_LOCK_TIMER);
    g_idle_context.RskPressedFromIdleApp = 0;

#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    g_idle_context.ToMainMenuScrFromIdleApp = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  IdleHandlePoundKeyForKeypadLock
 * DESCRIPTION
 *  This fn handle the press of star key , when LSK is pressed first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleHandlePoundKeyForKeypadLock(void)
{
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.RskPressedFromIdleApp == 0)
    {
        return;
    }
    g_idle_context.RskPressedFromIdleApp = 0;
#endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 

#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    if (g_idle_context.ToMainMenuScrFromIdleApp == 0)
    {
        return;
    }
    g_idle_context.ToMainMenuScrFromIdleApp = 0;
#endif /* __MMI_KEYPAD_LOCK_PATTERN_2__ */ 

    StopTimer(KEYPAD_LOCK_TIMER);
    g_keylock_context.gKeyPadLockFlag = 1;

    /* Lisen 02182005 */
#ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
#endif 

#ifdef __MMI_TOUCH_SCREEN__
    ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK);
    UpdateStatusIcons();    /* 101805 ChangeStatusIconImage Calvin: ChangeStatusIconImage will not call UpdateStatusIcon */
#else /* __MMI_TOUCH_SCREEN__ */ 
    IdleSetStatusIcon(STATUS_ICON_KEYPAD_LOCK);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    DisplayIdleScreen();
}


#if defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && !defined(__MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_manual_network_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_manual_network_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.RskPressedFromIdleApp = 1;

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_IDLE_NW_SEL_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(NETSETGetPLMNListCheck, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#if (defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__))
    if (g_idle_context.RskPressedFromIdleApp == 1)
    {
        StartTimer(KEYPAD_LOCK_TIMER, KEYPAD_LOCK_TIMEOUT, IdleHandleKeypadLockProcess);
        SetKeyHandler(IdleHandlePoundKeyForKeypadLock, KEY_POUND, KEY_EVENT_UP);
    }
#endif /* (defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__)) */ 
}
#endif /* defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && !defined(__MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  IdleSetLRKey
 * DESCRIPTION
 *  Change Idlescreen's L or RSK according to network status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleSetLRKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag)
    {
    #ifdef __MMI_TOUCH_SCREEN__
    #ifdef __MMI_KEYPAD_LOCK_PROMPT_TEXT__
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
        SetRightSoftkeyFunction(EntryScrKeyPadLockOnPessingAnyKey, KEY_EVENT_DOWN);
    #endif 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
        SetLeftSoftkeyFunction(EntryScrKeyPadLockOnPessingAnyKey, KEY_EVENT_DOWN);
    #endif 
    #endif /* __MMI_KEYPAD_LOCK_PROMPT_TEXT__ */ 
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    else    /* keypad unlocked */
    {
/* 2009.06.26 added by hongzhe.liu for idle key set + */
	IdleStateSetkey();
/* 2009.06.26 added by hongzhe.liu for idle key set - */
	
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD && 
            MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_VALID &&
            MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_VALID)
        {
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            SetRightSoftkeyFunction(EntryScrSimOptionMenu, KEY_EVENT_UP); /* Robin 1223 */
            SetLeftSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
        #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            SetLeftSoftkeyFunction(EntryScrSimOptionMenu, KEY_EVENT_UP);  /* Robin 1223 */
            SetRightSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 

    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            SetKeyHandler(EntryScrSimOptionMenu, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_phb_idle_enter_phb_list, KEY_LSK, KEY_EVENT_UP);
        #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            SetKeyHandler(EntryScrSimOptionMenu, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_phb_idle_enter_phb_list, KEY_RSK, KEY_EVENT_UP);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            ClearKeyEvents();
    #endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */
        }
        else
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #if defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && !defined(__MMI_DUAL_SIM_MASTER__)
        if (g_pwr_context.CurrentServiceType == LIMITED_SERVICE && 
            mmi_bootup_get_plmn_selection_mode() == MANUAL_MODE && 
    #ifdef __MMI_WLAN_FEATURES__
            mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY && 
    #endif
            mmi_bootup_is_nw_registration_ok() != MMI_FALSE)
        {
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            SetRightSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP); /* Robin 1223 */
            ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
            SetLeftSoftkeyFunction(mmi_idle_entry_manual_network_selection, KEY_EVENT_UP);
        #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            SetLeftSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);  /* Robin 1223 */
            ChangeRightSoftkey(STR_GLOBAL_SELECT, 0);
            SetRightSoftkeyFunction(mmi_idle_entry_manual_network_selection, KEY_EVENT_UP);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 

    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_idle_entry_manual_network_selection, KEY_LSK, KEY_EVENT_UP);
        #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_idle_entry_manual_network_selection, KEY_RSK, KEY_EVENT_UP);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            ClearKeyEvents();
    #endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */
        }
        else
    #endif /* defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && !defined(__MMI_DUAL_SIM_MASTER__) */ 
        {
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            SetRightSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP); /* Robin 1223 */
            SetLeftSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
        #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            SetLeftSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);  /* Robin 1223 */
            SetRightSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 

    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_phb_idle_enter_phb_list, KEY_LSK, KEY_EVENT_UP);
        #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_phb_idle_enter_phb_list, KEY_RSK, KEY_EVENT_UP);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            ClearKeyEvents();
    #endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */
        }
    }
}

/* diamond, 2005/07/05 Flight mode */

/*****************************************************************************
 * FUNCTION
 *  EntryFlightModeIdleScreen
 * DESCRIPTION
 *  Entry idle screen in flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFlightModeIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change current service type */
    g_pwr_context.CurrentServiceType = NO_SERVICE;

    PRINT_INFORMATION("Flight Mode");

    /* EntryNewScreen(SCR_FLIGHT_MODE_IDLE, EntryFlightModeIdleScreen, NULL, NULL); */

    StopLEDPatternNoService();

    /* display "Flight Mode" in the service area of idle screen */
    IdleRefreshServiceIndicationArea();

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif 

#ifdef __MMI_SWFLASH__
    if (dispchar_iswp_swflash() == MMI_TRUE)
    {
        ShowCategory34Screen(
            IDLE_SCREEN_LSK_TEXT,
            IDLE_SCREEN_LSK_ICON,   /* Menu */
            IDLE_SCREEN_RSK_TEXT,
            IDLE_SCREEN_RSK_ICON,
    		PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
    }
    else
#endif /* _MMI_SWFLASH__ */
#ifdef __MMI_AVATAR__
    if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
    {
        ShowCategory34Screen(
            IDLE_SCREEN_LSK_TEXT,
            IDLE_SCREEN_LSK_ICON,
            IDLE_SCREEN_RSK_TEXT,
            IDLE_SCREEN_RSK_ICON,
            PhnsetGetCurWallPaperIdx(), NULL, NULL);
    }
    else
#endif /* __MMI_AVATAR__ */
    {
    #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
        ShowCategory33Screen(IDLE_SCREEN_RSK_TEXT, IDLE_SCREEN_RSK_ICON, idleLRStringtID, IDLE_SCREEN_LSK_ICON, NULL);
    #else 
        ShowCategory33Screen(IDLE_SCREEN_LSK_TEXT, IDLE_SCREEN_LSK_ICON, idleLRStringtID, IDLE_SCREEN_RSK_ICON, NULL);
    #endif 
        mmi_phnset_save_wallpaper_to_speedup();
    }

    /* reset icons to indicate no service available */
    ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, 0);
    ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, 0);
    /* IdleResetStatusIcon(STATUS_ICON_ROAMING); */

    /* Voice Recognition */
#if defined(__MMI_VRSI__)
    SetRightSoftkeyFunction(mmi_vrsi_rcg_pre_entry, KEY_LONG_PRESS);
#endif 

#ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
    SetRightSoftkeyFunction(EntryScrSimOptionMenu, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
#else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
    SetLeftSoftkeyFunction(EntryScrSimOptionMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
#endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */

#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
    #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
        SetKeyHandler(EntryScrSimOptionMenu, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_idle_enter_phb_list, KEY_LSK, KEY_EVENT_UP);
    #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
        SetKeyHandler(EntryScrSimOptionMenu, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_idle_enter_phb_list, KEY_RSK, KEY_EVENT_UP);
    #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
        ClearKeyEvents();
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_status_icon_pen_event_hdlr(
        STATUS_ICON_KEYPAD_LOCK,
        WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
        IdleSetKeyPadLockFlag);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    SetCenterSoftkeyFunction(FlightModeDigitHandler, KEY_EVENT_UP);
#endif 

#ifdef __MMI_TOUCH_DIAL_SCREEN__
    memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
#endif 

#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    RegisterDedicatedKeyHandlers();
#elif !defined(__DISABLE_SHORTCUTS_MENU__)
    SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
#endif

#ifdef __MMI_CAMERA__
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
    #ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose())
        SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    else
        SetKeyHandler(mmi_camera_entry_app_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    #else
    SetKeyHandler(mmi_camera_entry_app_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    #endif
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */
#endif /* __MMI_CAMERA__ */

    SetGroupKeyHandler(HandleIdleScreenDigitEntry, IdleScreenDigits, MAX_IDLE_SCREEN_DIGITS - 1, KEY_EVENT_DOWN);

    /* volume key */
    SetDefaultVolumeKeyHandlers();

    ForceSubLCDScreen(ShowIdleAppSubLcd);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFlightModeKeypadLockScreen
 * DESCRIPTION
 *  Entry keypad lock screen in flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFlightModeKeypadLockScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
#endif

    mmi_idle_set_keypad_lock_string();

    IdleRefreshServiceIndicationArea();
#ifdef __MMI_SWFLASH__
    if (dispchar_iswp_swflash())
    {
        ShowCategory34Screen(
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
    	    PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
    }
	else
#endif /* _MMI_SWFLASH__ */    
#ifdef __MMI_AVATAR__
    if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
    {
        ShowCategory34Screen(
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            PhnsetGetCurWallPaperIdx(), NULL, NULL);
    }
    else
#endif /* __MMI_AVATAR__ */
    {
        ShowCategory33Screen(
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            NULL);
        mmi_phnset_save_wallpaper_to_speedup();
    }

#if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)
    SetGroupKeyHandler(EntryScrKeyPadLockOnPessingAnyKey, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);
#endif 

#ifdef __MMI_TOUCH_SCREEN__
    mmi_idle_pen_block();   /* diamond, 2005/12/22 Disable touch panel if re-entry idle keypad lock screen */
#ifndef __MMI_KEYPAD_LOCK_PROMPT_TEXT__
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
#endif /* __MMI_KEYPAD_LOCK_PROMPT_TEXT__ */ 
    SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);
#else /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    SetRightSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_DOWN);
#endif 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    SetLeftSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_DOWN);
#endif 
#endif /* __MMI_TOUCH_SCREEN__ */ 

    if (g_idle_context.IsRSKPressOnScreenSaver)
    {
        EntryScrAfterPessingRSK();
        g_idle_context.IsRSKPressOnScreenSaver = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  FlightModeDigitHandler
 * DESCRIPTION
 *  Flight mode digit handler in dial pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FlightModeDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;

#ifdef __MMI_MULTITAP_KEY_0__
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS - 1] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};
#else
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS - 2] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, /*KEY_STAR,*/ KEY_POUND};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, ExitIdleScreenDigitHandler, NULL, NULL);

    g_idle_context.IsOnDialerScreen = 1;
    history_buffer = GetCurrGuiBuffer(IDLE_SCREEN_DIGIT_HANDLER_ID);

#if ( defined (__MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) && !defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__))
    if (mmi_bootup_get_active_flight_mode() != 1)
    {
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    }
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) && !defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)) */ 

    ShowCategory16Screen(
        STR_GLOBAL_SAVE,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_idle_context.DialPadCallBuffer,
        MAX_DIAL_PAD,
        history_buffer);

    if (g_idle_context.IdleScreenDigitKeyCode >= 0)
    {
        ExecuteCurrKeyHandler(g_idle_context.IdleScreenDigitKeyCode, KEY_EVENT_DOWN);
    }

    // SetKeyHandler(EntryScrEmergencyCallDialing,KEY_SEND,KEY_EVENT_UP); /* no emergency call allowed */
    SetCategory16RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* diamond, 2005/11/14 Allow to entry phonebook in flight mode */
    SetLeftSoftkeyFunction(IdleDialPadSavePhoneBook, KEY_EVENT_UP);
    SetKeyHandler(IdleAbbrevDialling, KEY_POUND, KEY_EVENT_UP);

#ifdef __MMI_STARKEY_TOGGLE_PROFILE__
    if ((g_idle_context.LongPressEnable == 0) && !history_buffer) /* prevent from press * and then long press # */
#else /* __MMI_STARKEY_TOGGLE_PROFILE__ */ 
#ifdef __MMI_TOUCH_SCREEN__
    if ((g_idle_context.LongPressEnable == 0) && (g_idle_context.IdleScreenDigitKeyCode != KEY_STAR))
#else
    if ((g_idle_context.LongPressEnable == 0) && (g_idle_context.IdleScreenDigitKeyCode != KEY_STAR) && !history_buffer)
#endif
#endif /* __MMI_STARKEY_TOGGLE_PROFILE__ */ 
    {
    #ifdef __MMI_STARKEY_TOGGLE_PROFILE__
        SetKeyHandler(IdleToggleProfile, KEY_STAR, KEY_LONG_PRESS);
    #else 
        SetKeyHandler(IdleToggleProfile, KEY_POUND, KEY_LONG_PRESS);
    #endif 

    #ifdef __MMI_POUNDKEY_ENTER_PROFILE__
        SetKeyHandler(mmi_profiles_entry_main_screen, KEY_POUND, KEY_LONG_PRESS);
    #endif 

    #ifdef __MMI_MULTITAP_KEY_0__
        SetGroupKeyHandler(IdleDisableLongPress, (PU16) IdleScreenDigits, (U8) MAX_IDLE_SCREEN_DIGITS - 1, KEY_EVENT_UP);
    #else
        SetGroupKeyHandler(IdleDisableLongPress, (PU16) IdleScreenDigits, (U8) MAX_IDLE_SCREEN_DIGITS - 2, KEY_EVENT_UP);
    #endif
    }
}
/* end, diamond */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_star_key_disable_long_press
 * DESCRIPTION
 *  Special handler for star key pressed in touch screen dial pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_star_key_disable_long_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == IDLE_SCREEN_DIGIT_HANDLER_ID && g_idle_context.LongPressEnable == 0)
    {
        IdleDisableLongPress();
    }
}


#ifdef __MMI_SIMAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_bt_access_profile_idle_screen
 * DESCRIPTION
 *  Entry idle screen in BT access profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_bt_access_profile_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 IdleScreenDigits[MAX_IDLE_SCREEN_DIGITS] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("BT SIM Access Profile");

    StopLEDPatternNoService();

    IdleRefreshServiceIndicationArea();

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif 

#ifdef __MMI_SWFLASH__
    if (dispchar_iswp_swflash() == MMI_TRUE)
    {
        ShowCategory34Screen(
            IDLE_SCREEN_LSK_TEXT,
            IDLE_SCREEN_LSK_ICON,   /* Menu */
            IDLE_SCREEN_RSK_TEXT,
            IDLE_SCREEN_RSK_ICON,
            PhnsetGetCurWallPaperIdx(), idle_screen_wallpaper_name, NULL);
    }
    else
#endif /* _MMI_SWFLASH__ */
#ifdef __MMI_AVATAR__
    if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
    {
        ShowCategory34Screen(
            IDLE_SCREEN_LSK_TEXT,
            IDLE_SCREEN_LSK_ICON,   /* Menu */
            IDLE_SCREEN_RSK_TEXT,
            IDLE_SCREEN_RSK_ICON,
            PhnsetGetCurWallPaperIdx(), NULL, NULL);
    }
    else
#endif /* __MMI_AVATAR__ */
    {
    #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
        ShowCategory33Screen(IDLE_SCREEN_RSK_TEXT, IDLE_SCREEN_RSK_ICON, idleLRStringtID, IDLE_SCREEN_LSK_ICON, NULL);
    #else 
        ShowCategory33Screen(IDLE_SCREEN_LSK_TEXT, IDLE_SCREEN_LSK_ICON, idleLRStringtID, IDLE_SCREEN_RSK_ICON, NULL);
    #endif 
        mmi_phnset_save_wallpaper_to_speedup();
    }

#ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
        SetRightSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
    else
#endif /* __MMI_WLAN_FEATURES__ */
        SetRightSoftkeyFunction(EntryScrSimOptionMenu, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
#else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
        SetLeftSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
    else
#endif /* __MMI_WLAN_FEATURES__ */
        SetLeftSoftkeyFunction(EntryScrSimOptionMenu, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_phb_idle_enter_phb_list, KEY_EVENT_UP);
#endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_status_icon_pen_event_hdlr(
        STATUS_ICON_KEYPAD_LOCK,
        WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
        IdleSetKeyPadLockFlag);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    SetCenterSoftkeyFunction(FlightModeDigitHandler, KEY_EVENT_UP);
#endif 

#ifdef __MMI_TOUCH_DIAL_SCREEN__
    memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
#endif 

#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    RegisterDedicatedKeyHandlers();
#elif !defined(__DISABLE_SHORTCUTS_MENU__)
    SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
#endif

#ifdef __MMI_CAMERA__
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
    #ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose())
        SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    else
        SetKeyHandler(mmi_camera_entry_app_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    #else
    SetKeyHandler(mmi_camera_entry_app_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    #endif
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */
#endif /* __MMI_CAMERA__ */

    SetGroupKeyHandler(HandleIdleScreenDigitEntry, IdleScreenDigits, MAX_IDLE_SCREEN_DIGITS - 1, KEY_EVENT_DOWN);

    /* volume key */
    SetDefaultVolumeKeyHandlers();

    ForceSubLCDScreen(ShowIdleAppSubLcd);

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
    {
    #ifdef __MMI_UCM__
        mmi_idle_set_dial_mode(DIAL_MODE_WLAN);
    #else
        mmi_netset_set_dial_mode(DIAL_MODE_WLAN);
    #endif
    }
    else
    {
    #ifdef __MMI_UCM__
        mmi_idle_set_dial_mode(DIAL_MODE_GSM);
    #else
        mmi_netset_set_dial_mode(DIAL_MODE_GSM);
    #endif
    }
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
}

#endif /* __MMI_SIMAP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_allow_to_show_song_name
 * DESCRIPTION
 *  Is idle screen allow to display song name in line 3?
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
pBOOL mmi_idle_is_allow_to_display_song_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD || MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT)
    {
        return MMI_TRUE;
    }
    else if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_VALID)
    {
        return MMI_TRUE;
    }
    else if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_VALID)
    {
        return MMI_TRUE;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid())
    {
    	return MMI_TRUE;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_SIMAP_SUPPORT__
    else if (mmi_bootup_get_active_bt_access_profile_mode())
    {
        return MMI_TRUE;
    }
#endif /* __MMI_SIMAP_SUPPORT__ */
#ifdef __MMI_WLAN_FEATURES__
    else if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
    	return MMI_TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */
    else
    {
    	return MMI_FALSE;
    }
}


#ifdef __MMI_OP01_WITH_WAP_KEY__
/*****************************************************************************
 * FUNCTION
 *  mmi_entry_internet_confirm
 * DESCRIPTION
 *  Let user confirm whether entry internet
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_internet_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = (UI_string_type) GetString(STR_ID_ENTRY_WAP_CONFIRM);

    DisplayConfirm(
        STR_GLOBAL_YES, 
        0, 
        STR_GLOBAL_NO, 
        0, 
        (UI_string_type) message,
        IMG_GLOBAL_QUESTION, 
        WARNING_TONE);

    /* Set the key handlers */
    SetLeftSoftkeyFunction(wap_internet_key_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_OP01_WITH_WAP_KEY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_delete_dialpad_from_history
 * DESCRIPTION
 *  Delete dialpad screen after make call (only available for background sound)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_delete_dialpad_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
}


#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_display_touch_shortcuts
 * DESCRIPTION
 *  Allow to display tocuh idle screen shortcuts?
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_idle_is_display_touch_shortcuts(void)
{
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT && MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT) /* no query mode in dual sim case so startup mode can determine flight mode */
#else
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        return MMI_FALSE;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD && 
             MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_VALID &&
             MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_VALID)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else
    {
        return MMI_TRUE;
    }
}
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */


#if defined(HORSERACE_SUPPORT)
//Huyanwei Add it 
extern int FlagsReachIdle ;
extern void SendMessagesMMIToTwo(msg_type MSG_ID);
#endif


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dual_sim_root_screen
 * DESCRIPTION
 *  Dual SIM: Entry root screen from bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_dual_sim_root_screen(void)
{

#if ( defined(HORSERACE_SUPPORT) )
	//Huyanwei Add It 
	FlagsReachIdle = 1 ;
	SendMessagesMMIToTwo( MSG_ID_HORSERACE_OFF );
#if defined(NOKE_DEBUG)
	noke_dbg_printf("Huyanwei Debug Entry Idle Screen Branches \r\n");
#endif
#endif
   
    if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT)
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
        {
            // case 4, 8 ,12
            // still idle screen
            if ((MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && MTPNP_PFAL_Is_Card1CHVBlocked()) || 
                (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && MTPNP_PFAL_Is_Card2CHVBlocked()))
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* SIM1 is ready but enter SIM blocked screen */
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                EntryScrnSimBlockRsp();
            }
            else
            {
                    if (IsShowWelcomeScr1() == MMI_FALSE ||
                        GetActiveScreenId() == WELCOME_SCREEN_ID ||
                        IsScreenPresent(IDLE_SCREEN_ID) ||
                        (MTPNP_PFAL_Is_Card1CHVBlocked() && MTPNP_PFAL_Is_Card2CHVBlocked()))
                    {
                        EntryIdleScreen();
                    }
                    else
                    {
                        ShowWelcomeScr(); //EntryIdleScreen();
                    }
            }
        }
        else
        {
            // case 2, 6 ,10
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* SIM1 is ready but enter SIM error screen */
                simErrorDisplayString = STR_SIM_INSERTION_MSG;
                EntryScrnSimErrorScreen();
            }
            else
            {
                if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && MTPNP_PFAL_Is_Card1CHVBlocked())
                {
                    simErrorDisplayString = STR_SIM_BLOCK_MSG;
                    EntryScrnSimBlockRsp();
                }
                else
                {
                    EntryIdleScreen();
                }
            }
        }
    }
    else
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
        {
            // case 3, 7 ,11
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1)
            {
                simErrorDisplayString = STR_SIM_INSERTION_MSG;
                EntryScrnSimErrorScreen();
            }
            else
            {
                if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && MTPNP_PFAL_Is_Card2CHVBlocked())
                {
                    simErrorDisplayString = STR_SIM_BLOCK_MSG;
                    EntryScrnSimBlockRsp();
                }
                else
                {
                    if (IsShowWelcomeScr1() == MMI_FALSE ||
                        GetActiveScreenId() == WELCOME_SCREEN_ID ||
                        IsScreenPresent(IDLE_SCREEN_ID) ||
                        MTPNP_PFAL_Is_Card2CHVBlocked())
                    {
                        EntryIdleScreen();
                    }
                    else
                    {
                        ShowWelcomeScr(); //EntryIdleScreen();
                    }
                }
            }
        }
        else
        {
            // case 1, 5 ,7
            // still insert sim screen
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 || MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2)
            {
                simErrorDisplayString = STR_SIM_INSERTION_MSG;
                EntryScrnSimErrorScreen();
            }
            else
            {
                EntryIdleScreen();
            }
        }
    }
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It

#include "adcsche.h"
#ifndef MMI_ON_WIN32
extern _BATTI_STS_GROUP_ENUM_ get_main_batt_sta(void) ;
extern _BATTI_STS_GROUP_ENUM_ get_sub_batt_sta(void);
extern kal_uint8 ExistSubBattery();
#endif

extern void SetBatteryTwoLevel(U8 value) ;
extern U8 GetBatteryTwoLevel();
extern U8 GetBatteryTwoFull();
extern void SetBatteryTwoFull(U8 value);

extern U8 GetBatteryOneFull();
extern void SetBatteryOneFull(U8 value);


U8 IsBatteryLow(void)
{
	#ifndef MMI_ON_WIN32
	if(  ((get_main_batt_sta() == BATT_STATE_LEVEL0) && (get_sub_batt_sta() ==BATT_STATE_LEVEL0  ) ) ||
		((get_main_batt_sta() == BATT_STATE_LEVEL0) && (ExistSubBattery() == 0)) ||
		((get_main_batt_sta() == BATT_STATE_NO_BAT) && (get_sub_batt_sta() ==BATT_STATE_LEVEL0  )))
	{
		return 1 ;
	}
	else
	{
		return 0;
	}
	#else
	return 0 ;
	#endif
}


#include "SimDetectionDef.h"
extern charbat_context_struct g_charbat_context ;

extern void refresh_status_icon_display(void);

void UpdateBatteryILevel()
{
	_BATTI_STS_GROUP_ENUM_ nLevel_main = 0  ;
	#ifndef MMI_ON_WIN32	
	nLevel_main = get_main_batt_sta();
	#endif
	switch(nLevel_main)
	{
		case BATT_STATE_NO_BAT:
		case BATT_STATE_LEVEL0 :
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].state =  0 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].current_frame=  0 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_ANIMATE ;	
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_BAR_DISPLAY ;				
			break;
		case BATT_STATE_LEVEL1:
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].state =  0 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].current_frame=  0 ;			
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_ANIMATE ;	
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_BAR_DISPLAY ;				
			break;
		case BATT_STATE_LEVEL2:
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].state =  1 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].current_frame=  1 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_ANIMATE ;		
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_BAR_DISPLAY ;				
			break;
		case BATT_STATE_LEVEL3:
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].state =  2 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].current_frame=  2 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_ANIMATE ;		
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_BAR_DISPLAY ;	
			break;
		case BATT_STATE_LEVEL4 :
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].state =  3 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].current_frame=  3 ;			
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_ANIMATE ;				
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_BAR_DISPLAY ;				
			break ;
		default:
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].state =  0 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].current_frame=  0 ;
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_ANIMATE ;		
			MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].flags |= STATUS_ICON_BAR_DISPLAY ;				
			break;
		
	}	
}


void UpdateBatteryIILevel()
{
	_BATTI_STS_GROUP_ENUM_ nLevel_sub = 0  ;
#ifndef MMI_ON_WIN32	
	nLevel_sub = get_sub_batt_sta();
#endif
	
	//Sub Battery
	switch(nLevel_sub)
	{
		case BATT_STATE_NO_BAT:
		case BATT_STATE_LEVEL0 :
			SetBatteryTwoLevel(0);
			break;
		case BATT_STATE_LEVEL1:
			SetBatteryTwoLevel(0);
			break;
		case BATT_STATE_LEVEL2:
			SetBatteryTwoLevel(1);
			break;
		case BATT_STATE_LEVEL3:
			SetBatteryTwoLevel(2);
			break;
		case BATT_STATE_LEVEL4 :
			SetBatteryTwoLevel(3);
			break ;
		default:
			SetBatteryTwoLevel(0);
			break;
	}	
}



extern U8 GetMainBatteryChargeState() ;

void UpdateBatteryLevel()
{
	U8 bIsCharging = (g_charbat_context.isChargerConnected==1)?1:0 ;
	//bIsCharging Is USB Charge Connect.....
	if (bIsCharging == 0)
	{
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\nUpdateBatteryLevel Display State\r\n");
#endif
			//Main Battery 
			UpdateBatteryILevel();

			//Second Battery
			UpdateBatteryIILevel();

#if 1
			//Huyanwei Add It For Reset Battery II State
			SetBatteryOneFull(0);
			SetBatteryTwoFull(0);
#endif			
	}
	else	
	{
		//Charging 

		U8 Main_Charging = 1 ;
#ifndef MMI_ON_WIN32		
		if( ExistSubBattery() == 1)
		{
			if(GetMainBatteryChargeState() == 1)
			{
				Main_Charging = 1 ;
			}
			else
			{
				Main_Charging = 0 ;
			}
		}
		else
		{
			Main_Charging = 1 ;
		}
#endif		

#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r Charging ... \n");		
#endif
		if (Main_Charging == 1 )
		{
			//Main Charging
			//MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].state = 	(MMI_status_icons[STATUS_ICON_BATTERY_STRENGTH].state +1) %4 ;
			//Huyanwei Del It For Itself Deal 
  		         S32 i;
#if defined(NOKE_DEBUG)
			noke_dbg_printf(" UpdateBatteryLevel  Main Battery Charging ...\n\r");        
#endif
			if(GetBatteryOneFull() == 0)			
			{
				if (MMI_status_icons[1].flags & STATUS_ICON_ANIMATE)
				{
						MMI_status_icons[1].current_frame++;
						if (MMI_status_icons[1].current_frame >= MMI_status_icons[1].n_frames)
						{
							MMI_status_icons[1].current_frame = 0;
						}
				}
			}
			else
			{
				UpdateBatteryILevel();
			}
			//Update Second Battery
			UpdateBatteryIILevel();
		}
		else		
		{
			//Sub Charging
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\n UpdateBatteryLevel Sub Battery Charging ...\n\r");        
#endif
			if(GetBatteryTwoFull() == 0)
			{
				SetBatteryTwoLevel((GetBatteryTwoLevel()+1) % 4);				
			}
			else
			{
				SetBatteryTwoLevel(3);	//Can Del It , Because It was Seted By IdleScreenBatteryFullCharged	
				UpdateBatteryIILevel();
			}
			
			//Update Main Battery 
			MMI_status_icons[1].current_frame = 0;
			UpdateBatteryILevel();
		}
	}
#if 0
	refresh_status_icon_display();
#endif
}

#endif










