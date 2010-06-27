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
 * SimDetection.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for handle Normal Bootup
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : SimDetection.c

   PURPOSE     : handle Normal Bootup

   REMARKS     : nil

   AUTHOR      : Deepali Gupta

   DATE     : 12/03/03

**************************************************************/
#include "MMI_include.h"

#include "CommonScreens.h"
#include "MiscFunctions.h"
#include "ProtocolEvents.h"
#include "SimDetectionGprot.h"
#include "SimDetectionDef.h"
#include "QuickAccessMenuItem_def.h"
#include "QuickAccessMenuItemProt.h"    /* diamond, 2005/10/29, keypad lock in insert sim screen */
#include "SimDetectionGexdcl.h"
#include "ProtocolEvents.h"
#include "UCS2prot.h"
#include "TaskInit.h"
#include "wgui_status_icons.h"
#include "IdleAppDef.h"
#include "AlarmFrameworkProt.h"
#include "SSCStringHandle.h"
#include "PhoneBookTypes.h"
#include "SettingProfile.h"
#include "SettingGprots.h"
#include "ProfileGprots.h"
#include "PersonalizationDef.h"
#include "PersonalizationProt.h"
#include "SettingsGexdcl.h"
#include "gpioInc.h"
#include "MainMenuDef.h"
#include "PowerOnChargerProt.h"
#include "ProfilesGexdcl.h"
#include "bootup.h"
#include "CallSetUp.h"
#include "PhoneBookGprot.h"
#include "IdleAppProt.h"
#include "FunAndGamesDefs.h"
#include "GSM7BitDefaultAlphabet.h"
#include "SecuritySetup.h"
#include "SATGProts.h"
#include "VolumeHandler.h"
#include "CallManagementGProt.h"
#include "FlightModeGProt.h"
#include "SimDetectionHwMapFile.h"
#include "custom_util.h"
#include "CustResDef.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "ShortcutsProts.h"
#include "PhoneSetupGprots.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#endif 

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif 

#ifdef __MMI_POC__
#include "PoCGProt.h"
#endif 

#ifdef __FS_CHECKDRIVE_SUPPORT__
#include "Fmt_struct.h"
#ifdef __MMI_FILE_MANAGER__
#include "FileManagerGProt.h"
#endif 
#endif /* __FS_CHECKDRIVE_SUPPORT__ */ 

#ifdef __MMI_TOUCH_SCREEN__
#include "Wgui_touch_screen.h"
#endif 

#ifdef __MMI_OPP_SUPPORT__
#include "OPPMMIGprots.h"
#endif 

#if defined(__MMI_DOWNLOAD_AGENT__)
#include "App_mine.h"
#include "FileMgr.h"
#include "DLAgentDef.h"
#include "DLAgentGProt.h"
#endif /* defined(__MMI_DOWNLOAD_AGENT__) */ 

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#include "IrdaMMIScr.h"
extern void mmi_irda_exec_close_menu(void);
#endif /* __MMI_IRDA_SUPPORT__ */ 

#ifdef __CTM_SUPPORT__
#include "TextPhoneProt.h"
#endif

#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
#include "vObjects.h"
#endif

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#ifdef __MMI_IMPS__
#include "Mmi_imps_gprot.h"
#endif
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_CAMERA__
#include "lcd_if.h"     /* LCD layer enable flag */
#include "gdi_lcd_config.h"
#include "MMI_features_camera.h"
#include "mdi_datatype.h"
#include "mdi_camera.h" /* camera lib */
#include "CameraApp.h"
#endif /* __MMI_CAMERA__ */ 

#if defined(__MMI_VOIP__) && !defined(__MMI_UCM__)
#include "VoIPGProt.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_CHV_Verify.h"
#include "MTPNP_PFAL_DM_Setup.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_Slave_CHV.h"
#include "MTPNP_PFAL_Slave_Network.h"
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_Gemini_CHV.h"
#include "MTPNP_PFAL_Gemini_Network.h"
void MTPNP_PFAL_SIM2_ECCInfoSave(void *inMsg);
void MTPNP_PFAL_SIM2_PasswdReqResponse(void *inMsg);
void MTPNP_PFAL_SIM2_QueryFailureRsp(void *inMsg);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

/* External Functions   */

extern void FillCountDownNumber(sim_chv_info_struct chv_info);
extern void FillCountDownString(U8 TypeOfPass, U8 *PassCountdownDisp);
extern void CallBackPowerOnAnimationComplete(GDI_RESULT ret);
extern void DeInitSpecialMode(void);
extern void goto_opening_screen(void);
extern void IdleSetStatusIcon(S16);
extern void IdleResetStatusIcon(S16);

/* extern void RstSmuVerifyPINRspHdlr(void *); */
extern void InitInsertSimApp(void);
extern void RefreshDisplayOwnerNumber(U8 lineid);
extern CALL_DIR GetOutgoingCallOrigin(void);

/* 2009.06.26 added by hongzhe.liu for idle key set + */
extern void IdleStateSetkey();
/* 2009.06.26 added by hongzhe.liu for idle key set - */

#ifdef __J2ME__
#include "javaAgencyGprot.h"
#include "jvm_adaptor.h"
#endif /* __J2ME__ */ 

void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);
void PowerOnBatteryIndicationComplete(void);
void InsertSimSetKeyPadLockFlag(void);
extern void mdi_audio_set_audio_mode(U8 mode);

#ifdef __SAT__
extern void SATMessageWaitTimer(void);
#endif

#ifdef __MMI_BT_SUPPORT__
extern MMI_BOOL mmi_bt_ps_stack_and_hw_init(MMI_BOOL flight_mode, MMI_BOOL sim_inserted);
#endif 

/* Global Variables  */

#if ( defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))
extern U8 gCurrentMode;
#endif 

extern charbat_context_struct g_charbat_context;
extern U8 isEarphonePlugged;

/* Password buffers for PIN, PUK, phone lock and personalization lock */
S8 gInputNewPinBufferSecondTime[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
S8 gInputNewPinBufferFirstTime[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
S8 gInputPwdBuffer[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
S8 gSIM2PhoneLockPwdBuffer[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
#endif

/* Service area display buffers for line 1 and line 2 */
S8 gHomePLMNNum[MAX_PLMN_LEN_MMI + 1];
S8 gSimEccNumList[MAX_ECC_NUMBER_LIST_LENGTH][(EMERGENCY_NUMBER_LENGTH + 1)];
S8 gServProvderName[MAX_LENGTH_SERVICE_PROVIDER * ENCODING_LENGTH];
S8 gOperatorName[MAX_LENGTH_OPERATOR_NAME * ENCODING_LENGTH];
S8 gShortOperatorName[MAX_LENGTH_SHORT_OPERATOR_NAME * ENCODING_LENGTH];
S8 gOwnerName[MAX_LENGTH_OWNER_NUMBER * ENCODING_LENGTH];
U8 gOpNameValid = 0;
U8 gShortOpnameValid = 0;
U8 gSpnValid = 0;
MMI_OWNER_NUMBER_STRUCT gDispOwnerNumber[2];

#ifdef __MMI_WLAN_FEATURES__
U8 gWLANProviderName[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
#endif

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
S8 gSimEccNumList_2[MAX_ECC_NUMBER_LIST_LENGTH][(EMERGENCY_NUMBER_LENGTH + 1)];
#endif

/* SIM indication structures to hold the corresponding actions after power on animation completes */
MMISMUPASSWDREQIND gSMUPwdDataStruct;
MMISMUFAILIND gSMUFailIndStruct;

/* ECC buffers */
U16 EmergencyNumber[MAX_EMERGENCYNUMBER][4] = 
{
    {0x0039, 0x0031, 0x0031, 0x00}, /* 911 */
#ifdef __MEXICO_ECC__
    {0x0030, 0x0038, 0x0030, 0x00}, /* 080 */
    {0x0030, 0x0036, 0x0030, 0x00}, /* 060 */
    {0x0030, 0x0038, 0x00},         /* 08  */
#endif /* __MEXICO_ECC__ */ 
#ifdef __RUSSIA_ECC__
    {0x0030, 0x0031, 0x00},         /* 01  */
    {0x0030, 0x0032, 0x00},         /* 02  */
    {0x0030, 0x0033, 0x00},         /* 03  */
    {0x0030, 0x0030, 0x0031, 0x00}, /* 001 */
    {0x0030, 0x0030, 0x0032, 0x00}, /* 002 */
    {0x0030, 0x0030, 0x0033, 0x00}, /* 003 */
#endif /* __RUSSIA_ECC__ */
#if defined(__CPHS__)
    {0x0039, 0x0039, 0x0039, 0x00}, /* 999 */
#endif
    {0x0031, 0x0031, 0x0032, 0x00}  /* 112 */
};

U8 gCPHSRetryCount = 0;
static MMI_BOOL gVerifyPasswordSent = MMI_FALSE;

/* extern U8 isIdleScreenReached; */

typedef enum
{
    SIM_ERROR_DISPLAY_INSERT_SIM,
    SIM_ERROR_DISPLAY_SIM_ACCESS_ERROR
} SIM_ERROR_DISPLAY;

U16 simErrorDisplayString = STR_SIM_INSERTION_MSG;

#if defined(__FS_CHECKDRIVE_SUPPORT__)
// NOT DONE or NONE: 0
// SKIP: 1
// DONE: 2
// Processing: 3
U8 SanityCheckDone = 0;
#else /* defined(__FS_CHECKDRIVE_SUPPORT__) */ 
U8 SanityCheckDone = 2;
#endif /* defined(__FS_CHECKDRIVE_SUPPORT__) */ 

extern pwr_context_struct g_pwr_context;    /* in BootupApp.c */


/*****************************************************************************
 * FUNCTION
 *  InitSimDetection
 * DESCRIPTION
 *  Initialize all protocol handlers for SIM Messages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSimDetection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    SetProtocolEventHandler(SimECCInfoSave, PRT_SMU_STARTUP_INFO_IND);

    /* SimPasswdReqResponse: this indication implies that SIM is valid and may need security check */
    SetProtocolEventHandler(SimPasswdReqResponse, MSG_ID_GET_PIN_RES);

    /* SimQueryFailureRsp: this indication implies that SIM is invalid or not inserted */
    SetProtocolEventHandler(SimQueryFailureRsp, MSG_ID_SIM_CARD_FAILURE);
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    SetSlaveProtocolEventHandler(MTPNP_PFAL_SIM2_ECCInfoSave, PRT_SMU_STARTUP_INFO_IND);
    SetSlaveProtocolEventHandler(MTPNP_PFAL_SIM2_PasswdReqResponse, MSG_ID_GET_PIN_RES);
    SetSlaveProtocolEventHandler(MTPNP_PFAL_SIM2_QueryFailureRsp, MSG_ID_SIM_CARD_FAILURE);
    SetProtocolEventHandler(mmi_bootup_update_sim1_status, MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_IND);
    SetSlaveProtocolEventHandler(mmi_bootup_update_sim2_status, MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_IND);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    SetProtocolEventHandler(MTPNP_PFAL_SIM2_ECCInfoSave, PRT_SMU_STARTUP_INFO_IND);
    SetProtocolEventHandler(MTPNP_PFAL_SIM2_PasswdReqResponse, MSG_ID_GET_PIN_RES);
    SetProtocolEventHandler(MTPNP_PFAL_SIM2_QueryFailureRsp, MSG_ID_SIM_CARD_FAILURE);
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

    g_keylock_context.gKeyPadLockFlag = 0;
}

/**************************************************************************
*        Bootup Revise                *
**************************************************************************/

/* diamond, 2005/08/16 bootup revise */
#ifdef __MMI_DUAL_SIM_MASTER__
MMI_BOOL mmi_sim_error_is_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD || MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT)
    {
        return MMI_FALSE;
    }

    if ((MTPNP_PFAL_Is_Card1Absent() || MTPNP_PFAL_Is_Card1CHVBlocked()) && MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1)
    {
        return MMI_TRUE;
    }

    if ((MTPNP_PFAL_Is_Card2Absent() || MTPNP_PFAL_Is_Card2CHVBlocked()) && MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_hide_menu_items
 * DESCRIPTION
 *  Hide some menu items for no sim or sim blocked case
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_error_hide_menu_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FLIGHT_MODE_SUPPORT__
#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT && MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT) /* no query mode in dual sim case so startup mode can determine flight mode */
#else
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        mmi_flight_mode_hide_menu_items();
    }
#endif /* __FLIGHT_MODE_SUPPORT__ */

#ifdef __MMI_DUAL_SIM_MASTER__

    if (mmi_sim_error_is_present() ||
        (MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_CHVBLOCKED) && (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_CHVBLOCKED))
    {
        /* Gemini: this function is used to hide menu items if both SIM cards are not valid */
        mmi_frm_hide_menu_item(MENU_MTPNP_DM_SHOW_OWNER_NUMBER);
        mmi_frm_hide_menu_item(MENU9146_WELCOME_TEXT);       /* Hide "Greeting Text" in No SIM screen */
    #ifdef __MMI_NITZ__
        mmi_frm_hide_menu_item(MENU9145_SETTIMEANDDATENITZ); /* Hide "Auto update of date and time" in No SIM screen */
        mmi_frm_hide_menu_item(MENU_SETTING_MENU_TREE);
    #endif /* __MMI_NITZ__ */ 
    #ifdef __MMI_SIMAP_SUPPORT__
        mmi_frm_hide_menu_item(MENU_CONN_BT_SET_SIMAP);        /* Remote SIM mode */
    #endif
    #ifdef SYNCML_DM_SUPPORT
        mmi_frm_hide_menu_item(MENU_ID_DMUI_MAIN);
    #endif
    #ifdef __MMI_VRSD__
        mmi_frm_hide_menu_item(MENU_ID_VRSD_APP);
    #endif
    #ifdef __MMI_VRSI__
        mmi_frm_hide_menu_item(MENU_ID_VRSI_SETTING);
    #endif
    }
    if (mmi_sim_error_is_present())
    {
        mmi_frm_hide_menu_item(MENU_IDLE_SCR_DISP);
    }

#else /*__MMI_DUAL_SIM_MASTER__ */

    mmi_frm_hide_menu_item(MENU_SETTING_SHOW_OWN_NUMBER);/* Hide "Show Owner Number" in No SIM screen */
    mmi_frm_hide_menu_item(MENU9146_WELCOME_TEXT);       /* Hide "Greeting Text" in No SIM screen */
#ifdef __MMI_NITZ__
    mmi_frm_hide_menu_item(MENU9145_SETTIMEANDDATENITZ); /* Hide "Auto update of date and time" in No SIM screen */
    mmi_frm_hide_menu_item(MENU_SETTING_MENU_TREE);
#endif /* __MMI_NITZ__ */ 

    mmi_frm_hide_menu_item(MENU9169_SIM_LOCK);           /* Hide "SIM Lock" in No SIM screen */
    mmi_frm_hide_menu_item(MENU9167_FIXED_DIAL);         /* Hide "Fixed Dial" in No SIM screen */
    mmi_frm_hide_menu_item(MENU9168_BARRED_DAIL);        /* Hide "Barred Dail" in No SIM screen */
    mmi_frm_hide_menu_item(MENU9174_CP_PIN1);            /* Hide "Change Password/PIN1" in No SIM screen */
    mmi_frm_hide_menu_item(MENU9175_CP_PIN2);            /* Hide "Change Password/PIN2" in No SIM screen */
    mmi_frm_hide_menu_item(MENU_SETTING_SPEED_DIAL);     /* Hide "Speed Dial" in No SIM screen */

#ifdef __MMI_SIMAP_SUPPORT__
    mmi_frm_hide_menu_item(MENU_CONN_BT_SET_SIMAP);        /* Remote SIM mode */
#endif

#ifdef SYNCML_DM_SUPPORT
    mmi_frm_hide_menu_item(MENU_ID_DMUI_MAIN);
#endif

#ifdef __MMI_WLAN_FEATURES__
    mmi_frm_hide_menu_item(MENU9186_SELECTION_MODE);
    mmi_frm_hide_menu_item(MENU9189_GPRS_CONNECTION_MODE);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_NETSET_USER_CTRL_PLMN);
#endif
    mmi_frm_hide_menu_item(MESSAGES_MENU_SMS_MENUID);      /* SMS */
    mmi_frm_hide_menu_item(MESSAGES_MENU_MMS_MENUID);      /* MMS */
    mmi_frm_hide_menu_item(MENU_CHATAPP_ID);               /* Chat */
    mmi_frm_hide_menu_item(MESSAGES_MENU_VMAIL_MENUID);    /* Voice Mail */
    mmi_frm_hide_menu_item(MESSAGES_MENU_CB_MENUID);       /* Cell Broadcast */
    mmi_frm_hide_menu_item(MENU_ID_UM_MAIN);               /* Unified Message */

    mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_SETTING);
    mmi_frm_hide_menu_item(MENU_CALL_TIME_SETUP);          /* Call Time */
    mmi_frm_hide_menu_item(MENU_CALL_HISTORY_CALLCOST);    /* Call Cost */
    mmi_frm_hide_menu_item(MENU_CALL_HISTORY_SMSCOUNTER);  /* SMS Counter */
    mmi_frm_hide_menu_item(MENU_CALL_HISTORY_GPRSCOUNTER); /* GPRS Counter */
#ifndef __MMI_VOIP__
    mmi_frm_hide_menu_item(MENU8103_MISSED_CALLS);
    mmi_frm_hide_menu_item(MENU8102_DIALED_CALLS);	
    mmi_frm_hide_menu_item(MENU8101_RECEIVED_CALLS);
    mmi_frm_hide_menu_item(MENU8113_CALLHISTORY_RESETCALL);
#ifdef __MMI_CH_QUICK_END__
    mmi_frm_hide_menu_item(MENU_CALL_HISTORY_QUICK_END);
#endif
#endif /* __MMI_VOIP__ */
#else /* __MMI_WLAN_FEATURES__ */
    mmi_frm_hide_menu_item(MENU_IDLE_SCR_DISP);          /* Hide "Display Characteristic" in No SIM screen */ 
#ifdef __MMI_VRSD__
    mmi_frm_hide_menu_item(MENU_ID_VRSD_APP);
#endif
#ifdef __MMI_VRSI__
    mmi_frm_hide_menu_item(MENU_ID_VRSI_SETTING);
#endif
#endif /* __MMI_WLAN_FEATURES__ */

#endif /* __MMI_DUAL_SIM_MASTER__ */
}


#ifdef __MMI_DUAL_SIM_MASTER__
void mmi_sim_error_unhide_menu_items(void)
{
    if (!mmi_sim_error_is_present() &&
        !((MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_CHVBLOCKED) && (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_CHVBLOCKED)))
    {
        mmi_frm_unhide_menu_item(MENU_MTPNP_DM_SHOW_OWNER_NUMBER);
        mmi_frm_unhide_menu_item(MENU9146_WELCOME_TEXT);       /* Hide "Greeting Text" in No SIM screen */
    #ifdef __MMI_NITZ__
        mmi_frm_unhide_menu_item(MENU9145_SETTIMEANDDATENITZ); /* Hide "Auto update of date and time" in No SIM screen */
        mmi_frm_unhide_menu_item(MENU_SETTING_MENU_TREE);
    #endif /* __MMI_NITZ__ */ 
    #ifdef __MMI_SIMAP_SUPPORT__
        mmi_frm_unhide_menu_item(MENU_CONN_BT_SET_SIMAP);        /* Remote SIM mode */
    #endif
    #ifdef SYNCML_DM_SUPPORT
        mmi_frm_unhide_menu_item(MENU_ID_DMUI_MAIN);
    #endif
    #ifdef __MMI_VRSD__
        mmi_frm_unhide_menu_item(MENU_ID_VRSD_APP);
    #endif
    #ifdef __MMI_VRSI__
        mmi_frm_unhide_menu_item(MENU_ID_VRSI_SETTING);
    #endif
    }
    if (!mmi_sim_error_is_present())
    {
        mmi_frm_unhide_menu_item(MENU_IDLE_SCR_DISP);
    }

}
#endif /* __MMI_DUAL_SIM_MASTER__ */


#ifdef __MMI_WLAN_FEATURES__
void mmi_sim_error_wlan_only_idle_notify(void)
{
    g_pwr_context.CurrentServiceType = LIMITED_SERVICE; /* force to enter GSM no service state */
    g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;

    mmi_idle_notify_bootup_ready_to_wap();
    mmi_idle_notify_bootup_ready_to_certman(); /* to CertMan */
#ifdef __MMI_IMPS__
    mmi_imps_notify_idle_reached();
#endif
}
#endif /* __MMI_WLAN_FEATURES__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_process_pending_events
 * DESCRIPTION
 *  Process pending events in sim error screen or security check screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sim_error_process_pending_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_searching_or_idle_reached())
    {
        PendingAlarmInPwronPeriod();
    }
    else
    {
        PendingAlarmReminder(); /* to prevent pending alarm in sim error screen */
    }

    if (g_charbat_context.isChargerConnected == 1 && g_charbat_context.ChargingComplete == 0)
    {
        IdleScreenChargerConnected(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitSimErrorScreen
 * DESCRIPTION
 *  Initialize and enter SIM error screen
 * PARAMETERS
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void InitSimErrorScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_CHVBLOCKED) &&
        (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_CHVBLOCKED))
    {
        InitInsertSimApp();
    }
    else
    {
        InitAllApplications();
    }
#else
    InitInsertSimApp();
    RemoveStatusIconsForSimRemoved();
#endif

#ifdef __MMI_WLAN_FEATURES__
    mmi_netset_update_preferred_mode_menu();
    mmi_sim_error_wlan_only_idle_notify();
#endif
    mmi_sim_error_hide_menu_items();

#ifdef __MMI_UCM__
    if (mmi_ucm_is_sos_in_call_list())
#else
    if (EmergencyCallPresent())
#endif
    {
        DisplayPopup((U8*) GetString(simErrorDisplayString), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
        HistoryReplace(IDLE_SCREEN_ID, SCR_SIM_INSERTION, EntryScrnSimErrorScreen);
        DeleteBeyondScrTillScr(GetCmMarkerScrnID(), SCR_SIM_INSERTION);
        mmi_frm_add_history_before_cm_marker(SCR_SIM_INSERTION, EntryScrnSimErrorScreen);
    }
    else if (IsScreenPresent(IDLE_SCREEN_ID))
    {
        DisplayPopup((U8*) GetString(simErrorDisplayString), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
        HistoryReplace(IDLE_SCREEN_ID, SCR_SIM_INSERTION, EntryScrnSimErrorScreen);
        DeleteUptoScrID(SCR_SIM_INSERTION);
    #if 0
/* under construction !*/
/* under construction !*/
    #endif /* 0 */
    }
    else
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        mmi_idle_entry_dual_sim_root_screen();
        mmi_sim_error_notify_bootup_ready_to_wap();
    #else
        EntryScrnSimErrorScreen();
    #endif
        mmi_sim_error_process_pending_events();
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Is_InCard2securityCheck())
    {
        MTPNP_AD_Card2_CHV_Request();
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  InitSimBlockedScreen
 * DESCRIPTION
 *  Initialize and enter SIM blocked screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSimBlockedScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_CHVBLOCKED) &&
        (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_CHVBLOCKED))
    {
        InitInsertSimApp();
    }
    else
    {
        InitAllApplications();
    }
#else
    InitInsertSimApp();
    RemoveStatusIconsForSimRemoved();
#endif

#ifdef __MMI_WLAN_FEATURES__
    mmi_netset_update_preferred_mode_menu();
    mmi_sim_error_wlan_only_idle_notify();
#endif
    mmi_sim_error_hide_menu_items();

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_idle_entry_dual_sim_root_screen();
    mmi_sim_error_notify_bootup_ready_to_wap();
#else
    EntryScrnSimBlockRsp();
#endif
    mmi_sim_error_process_pending_events();

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Is_InCard2securityCheck())
    {
        MTPNP_AD_Card2_CHV_Request();
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */
}


#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
void mmi_bootup_sim2_validate_phone_lock(void)
{
    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED;

    /* Change gInputPwdBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gSIM2PhoneLockPwdBuffer);

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  ValidatePassword
 * DESCRIPTION
 *  Validate password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidatePassword(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* used to verify PIN or phone lock in power on period */
    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    if (gVerifyPasswordSent)
    {
        return;
    }
    gVerifyPasswordSent = MMI_TRUE;

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    /* unlock phone lock need to apply both L4C and L4C2 */
    /* unlock L4C2 first because power on procedure depends on L4C */
    if (g_pwr_context.PrevScreenIndicator == ENTER_PHONELOCK)
    {
        memcpy(gSIM2PhoneLockPwdBuffer, gInputPwdBuffer, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);

        if (g_pwr_context_2.PhoneLockNeeded == 1)
        {
            mmi_bootup_sim2_validate_phone_lock();
            kal_sleep_task(KAL_TICKS_100_MSEC);
        }
    }
    g_pwr_context.PhoneLockNeeded = 0;
    g_pwr_context_2.PhoneLockNeeded = 0;
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    PRINT_INFORMATION("@@@@@ Sending request for verifying password @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED;

    /* Change gInputPwdBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

/* end, diamond */

/**************************************************************************
   SIM Error APIs:
      void EntryScrnSimErrorScreen(void)
      void ExitScrnSimErrorScreen(void)
      void ShowSubLCDSimError(void)
      void ExitSubLCDSimError(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_register_keypad_lock_key_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sim_error_register_keypad_lock_key_events(void)
{
    if (g_keylock_context.gKeyPadLockFlag != 0)
    {
        #if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)
            SetGroupKeyHandler(
                EntryScrKeyPadLockOnPessingAnyKey,
                (PU16) PresentAllKeys,
                (U8) TOTAL_KEYS,
                (U16) KEY_EVENT_DOWN);
        #endif /* defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__) */ 

        #ifdef __MMI_TOUCH_SCREEN__
            mmi_idle_pen_block();   /* diamond, 2005/12/22 Disable touch panel if re-entry idle keypad lock screen */
            SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);
        #else /* __MMI_TOUCH_SCREEN__ */ 
        #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
            SetRightSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_UP);
        #endif 

        #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
            SetLeftSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_UP);
        #endif 
        #endif /* __MMI_TOUCH_SCREEN__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrnSimErrorScreen
 * DESCRIPTION
 *  Entry screen when no SIM is inserted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrnSimErrorScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U16 InsertSIMScreenDigits[MAX_INSERT_SCR_DIGITS] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        EntryIdleScreen();
        return;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    EntryNewScreen(SCR_SIM_INSERTION, ExitScrnSimErrorScreen, EntryScrnSimErrorScreen, NULL);

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens())
    {
    #if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    #endif 
        if (g_keylock_context.gKeyPadLockFlag == 0)
        {
            ShowCategory123Screen(
                0,
                0,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_RSK_SOS,
                0,
                simErrorDisplayString,
                IMG_GLOBAL_WARNING,
                NULL);
        }
        else
        {
            ShowCategory123Screen(
                0,
                0,
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                simErrorDisplayString,
                IMG_GLOBAL_WARNING,
                NULL);
        }
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */

    DinitHistory();         /* Dinit History is called to prevent memory leak */
    DeInitSpecialMode();    /* Back from engineer mode or factory mode */

    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;

    g_pwr_context.PrevScreenIndicator = ENTER_SIM_INSERTION;
    g_idle_context.IsOnSimErrorScreen = 1;

    /* Fix the case that caller group LED could not demo after entering FM/EM and then back to INSERT_SIM */
#if ( defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))
    gCurrentMode = NORMAL_MODE;
#endif 

#ifdef __MMI_DOWNLOAD_AGENT__
    mmi_da_enter_idle_screen_notify();
#endif 

    /* Provide Java functions in the SIM error main menu */
#ifdef __J2ME__
    jvm_enter_idle_screen_notify();
#endif 

    /* diamond, 2005/10/29, keypad lock in insert sim screen */
    mmi_idle_start_keypad_lock();
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        mmi_frm_kbd_reg_pre_key_hdlr(IdleScreenEmergencyCallCheckNKeypadLock);
    }
    /* end, diamond */

    guiBuffer = GetCurrGuiBuffer(SCR_SIM_INSERTION);

    ShowSubLCDScreen(ShowSubLCDSimError);
    DinitSubLCDHistory();

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif 

    if (0)
    {
    }
#ifdef __J2ME__
    else if (mmi_java_is_launch_from_idle())
    {
        mmi_java_entry_mid_launch_from_idle();
        mmi_sim_error_register_keypad_lock_key_events();
    }
#endif /* __J2ME__ */ 
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    else if (mmi_vobj_is_pending_object())
    {
        mmi_vobj_entry_recv_object(); /* unread vObjects */
        mmi_sim_error_register_keypad_lock_key_events();
    }
#endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__) */
#ifdef __MMI_OPP_SUPPORT__
    else if (mmi_opp_get_recv_files_cnt())
    {
        mmi_opp_entry_idle_notify_scr(); /* files from Bluetooth */
        mmi_sim_error_register_keypad_lock_key_events();
    }
#endif /* __MMI_OPP_SUPPORT__ */
#ifdef __MMI_DOWNLOAD_AGENT__
    else if (mmi_da_launch_ring_buffer_check())
    {
        mmi_da_entry_new_push_ind();
        mmi_sim_error_register_keypad_lock_key_events();
    }
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    else
    {
        if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
        {
            ShowCategory123Screen(
                0,
                0,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_RSK_SOS,
                0,
                simErrorDisplayString,
                IMG_GLOBAL_WARNING,
                NULL);

        #if ( (defined __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
            SetCenterSoftkeyFunction(HandleInsertSIMScrDigitEntry, KEY_EVENT_UP);
        #endif 

            SetLeftSoftkeyFunction(EntryScrSimOptionMenu, KEY_EVENT_UP);
            SetRightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);

            SetGroupKeyHandler(
                HandleInsertSIMScrDigitEntry,
                InsertSIMScreenDigits,
                MAX_INSERT_SCR_DIGITS - 1,
                KEY_EVENT_DOWN);

            SetDefaultVolumeKeyHandlers();

        #ifdef __MMI_CAMERA__
        #ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
            SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
        #else
            SetKeyHandler(mmi_camera_entry_app_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
        #endif
        #endif /* __MMI_CAMERA__ */

        /* for 4-dedicated shortcuts */
        #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
            RegisterDedicatedKeyHandlers();
        #elif !defined(__DISABLE_SHORTCUTS_MENU__)
            SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
        #endif

        #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_status_icon_pen_event_hdlr(
                STATUS_ICON_KEYPAD_LOCK,
                WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
                InsertSimSetKeyPadLockFlag);
        #endif /* __MMI_TOUCH_SCREEN__ */ 

        }
        else
        {
        #ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
            mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
        #endif 

            mmi_idle_set_keypad_lock_string();

        #if (defined  __MMI_TOUCH_SCREEN__ && defined __MMI_WGUI_CSK_ENABLE__ )
            ResetCenterSoftkey();
        #endif 

            ShowCategory123Screen(
                0,
                0,
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                simErrorDisplayString,
                IMG_GLOBAL_WARNING,
                NULL);

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
            mmi_idle_pen_block();   /* diamond, 2005/12/22 Disable touch panel if re-entry idle keypad lock screen */
            SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);
        #else /* __MMI_TOUCH_SCREEN__ */ 
        #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
            SetRightSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_UP);
        #endif 

        #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
            SetLeftSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_UP);
        #endif 
        #endif /* __MMI_TOUCH_SCREEN__ */

            if (g_idle_context.IsRSKPressOnScreenSaver)
            {
                EntryScrAfterPessingRSK();
                g_idle_context.IsRSKPressOnScreenSaver = 0;
            }
        }
    }
/* 2009.06.26 added by hongzhe.liu for idle key set + */
IdleStateSetkey();
/* 2009.06.26 added by hongzhe.liu for idle key set - */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrnSimErrorScreen
 * DESCRIPTION
 *  Exit screen when no SIM is inserted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrnSimErrorScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsOnSimErrorScreen = 0;
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
    ResetCenterSoftkey();
#endif 

#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_status_icon_pen_event_hdlr();
#endif /* __MMI_TOUCH_SCREEN__ */ 

    StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDSimError
 * DESCRIPTION
 *  Entry screen for sublcd when no SIM is inserted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDSimError(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 stringID =
        (simErrorDisplayString ==
         SIM_ERROR_DISPLAY_SIM_ACCESS_ERROR) ? STR_SUBLCD_SIM_ACCESS_ERROR_MSG : STR_SUBLCD_SIM_INSERTION_MSG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (IsClamClose())
    {
        ShowSubLCDAnalogClockScreen();
    }
    else
    {
        ShowSubLCDLogoString();
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    ShowCategory301Screen((PU8) GetString(stringID), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    SetSubLCDExitHandler(ExitSubLCDSimError);
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_ON_IDLE_INSERT_SIM;
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDSimError
 * DESCRIPTION
 *  Exit screen for sublcd when no SIM is inserted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDSimError(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDSimError;
    AddSubLCDHistory(&SubLCDHistory);
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_NOT_ON_IDLE;
}

/**************************************************************************
   SIM Blocked APIs:
      void ExitScrnSimBlockRsp(void)
      void EntryScrnSimBlockRsp(void)
      void ShowSubLCDBlockedSIM(void)
      void ExitSubLCDBlockedSIM(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ExitScrnSimBlockRsp
 * DESCRIPTION
 *  Exit screen when SIM is blocked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrnSimBlockRsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsOnSimErrorScreen = 0;
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
    ResetCenterSoftkey();
#endif 

#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_status_icon_pen_event_hdlr();
#endif /* __MMI_TOUCH_SCREEN__ */ 

    StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrnSimBlockRsp
 * DESCRIPTION
 *  Entry screen when SIM is blocked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrnSimBlockRsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U16 BlockSIMScreenDigits[MAX_INSERT_SCR_DIGITS] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        EntryIdleScreen();
        return;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    EntryNewScreen(SCR_SIM_BLOCK, ExitScrnSimBlockRsp, EntryScrnSimBlockRsp, NULL);

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens())
    {
    #if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    #endif 
        if (g_keylock_context.gKeyPadLockFlag == 0)
        {
            ShowCategory123Screen(
                0,
                0,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_RSK_SOS,
                0,
                simErrorDisplayString,
                IMG_GLOBAL_WARNING,
                NULL);
        }
        else
        {
            ShowCategory123Screen(
                0,
                0,
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                simErrorDisplayString,
                IMG_GLOBAL_WARNING,
                NULL);
        }
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */

    DinitHistory();         /* Dinit History is called to prevent memory leak */
    DeInitSpecialMode();    /* Back from engineer mode or factory mode */

    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;

    g_pwr_context.PrevScreenIndicator = ENTER_SIM_BLOCK;
    g_idle_context.IsOnSimErrorScreen = 1;

#ifdef __MMI_DOWNLOAD_AGENT__
    mmi_da_enter_idle_screen_notify();
#endif 

#ifdef __J2ME__
    jvm_enter_idle_screen_notify();
#endif 

    /* diamond, 2005/10/29, keypad lock in insert sim screen */
    mmi_idle_start_keypad_lock();
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        mmi_frm_kbd_reg_pre_key_hdlr(IdleScreenEmergencyCallCheckNKeypadLock);
    }
    /* end, diamond */

    guiBuffer = GetCurrGuiBuffer(SCR_SIM_BLOCK);

    ShowSubLCDScreen(ShowSubLCDBlockedSIM);
    DinitSubLCDHistory();

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif 

    if (0)
    {
    }
#ifdef __J2ME__
    else if (mmi_java_is_launch_from_idle())
    {
        mmi_java_entry_mid_launch_from_idle();
        mmi_sim_error_register_keypad_lock_key_events();
    }
#endif /* __J2ME__ */ 
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    else if (mmi_vobj_is_pending_object())
    {
        mmi_vobj_entry_recv_object(); /* unread vObjects */
        mmi_sim_error_register_keypad_lock_key_events();
    }
#endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__) */
#ifdef __MMI_OPP_SUPPORT__
    else if (mmi_opp_get_recv_files_cnt())
    {
        mmi_opp_entry_idle_notify_scr(); /* files from Bluetooth */
        mmi_sim_error_register_keypad_lock_key_events();
    }
#endif /* __MMI_OPP_SUPPORT__ */
#ifdef __MMI_DOWNLOAD_AGENT__
    else if (mmi_da_launch_ring_buffer_check())
    {
        mmi_da_entry_new_push_ind();
        mmi_sim_error_register_keypad_lock_key_events();
    }
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    else
    {
        if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
        {
            ShowCategory123Screen(
                0,
                0,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_RSK_SOS,
                0,
                simErrorDisplayString,
                IMG_GLOBAL_WARNING,
                NULL);

        #if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
            SetCenterSoftkeyFunction(HandleInsertSIMScrDigitEntry, KEY_EVENT_UP);
        #endif 

            SetLeftSoftkeyFunction(EntryScrSimOptionMenu, KEY_EVENT_UP);
            SetRightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);

            SetGroupKeyHandler(
                HandleInsertSIMScrDigitEntry,
                BlockSIMScreenDigits,
                MAX_INSERT_SCR_DIGITS - 1,
                KEY_EVENT_DOWN);

            SetDefaultVolumeKeyHandlers();

        #ifdef __MMI_CAMERA__
        #ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
            SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
        #else
            SetKeyHandler(mmi_camera_entry_app_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
        #endif
        #endif /* __MMI_CAMERA__ */
/* 2009.06.26 added by hongzhe.liu for idle key set + */
IdleStateSetkey();
/* 2009.06.26 added by hongzhe.liu for idle key set - */
        /* for 4-dedicated shortcuts */
        #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
            RegisterDedicatedKeyHandlers();
        #elif !defined(__DISABLE_SHORTCUTS_MENU__)
            SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
        #endif

        #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_status_icon_pen_event_hdlr(
                STATUS_ICON_KEYPAD_LOCK,
                WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
                InsertSimSetKeyPadLockFlag);
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }
        else
        {
        #ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
            mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
        #endif 

            mmi_idle_set_keypad_lock_string();

        #if (defined  __MMI_TOUCH_SCREEN__ && defined __MMI_WGUI_CSK_ENABLE__ )
            ResetCenterSoftkey();
        #endif 

            ShowCategory123Screen(
                0,
                0,
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                simErrorDisplayString,
                IMG_GLOBAL_WARNING,
                NULL);

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
            mmi_idle_pen_block();   /* diamond, 2005/12/22 Disable touch panel if re-entry idle keypad lock screen */
            SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);
        #else /* __MMI_TOUCH_SCREEN__ */ 
        #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
            SetRightSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_UP);
        #endif 

        #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
            SetLeftSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_UP);
        #endif 
        #endif /* __MMI_TOUCH_SCREEN__ */

            if (g_idle_context.IsRSKPressOnScreenSaver)
            {
                EntryScrAfterPessingRSK();
                g_idle_context.IsRSKPressOnScreenSaver = 0;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDBlockedSIM
 * DESCRIPTION
 *  Entry screen for sulcd when SIM is blocked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDBlockedSIM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (IsClamClose())
    {
        ShowSubLCDAnalogClockScreen();
    }
    else
    {
        ShowSubLCDLogoString();
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    ShowCategory301Screen((PU8) GetString(STR_SIM_BLOCK_MSG), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    SetSubLCDExitHandler(ExitSubLCDBlockedSIM);
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_ON_IDLE_SIM_BLOCKED;
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDBlockedSIM
 * DESCRIPTION
 *  Exit screen for sulcd when SIM is blocked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDBlockedSIM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDBlockedSIM;
    AddSubLCDHistory(&SubLCDHistory);
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_NOT_ON_IDLE;
}

/**************************************************************************
   SIM Option Menu APIs:
      void EntryScrSimOptionMenu(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  EntryScrSimOptionMenu
 * DESCRIPTION
 *  Entry function for option button on 'insert sim' / 'blocked sim' / 'flight mode' screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSimOptionMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */

#if defined(__MMI_VERSION_2__)
    U16 MenuOptionIconList[MAX_SUB_MENUS] = 
    {
    #ifndef __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__
    #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
        MAIN_MENU_AVZONE_TITLE,
    #endif 
        IMG_ID_OPTION_MENU_PHONEBOOK_ICON,
        IMG_ID_OPTION_MENU_SETTINGS_ICON,    /* diamond, 2005/12/23 Phone setup in option menu */
        IMG_ID_OPTION_MENU_MULTIMEDIA_ICON,
        IMG_ID_OPTION_MENU_FILEMNGR_ICON,
        IMG_ID_OPTION_MENU_FUNANDGAMES_ICON,
        IMG_ID_OPTION_MENU_PROFILES_ICON,
        IMG_ID_OPTION_MENU_ORGANIZER_ICON,
        IMG_ID_OPTION_MENU_EXTRA_ICON,
        IMG_ID_OPTION_MENU_SHORTCUTS_ICON
    #else /* __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__ */ 
        IMG_GLOBAL_L1,
        IMG_GLOBAL_L2,
        IMG_GLOBAL_L3,
        IMG_GLOBAL_L4,
        IMG_GLOBAL_L5,
        IMG_GLOBAL_L6,
        IMG_GLOBAL_L7,
        IMG_GLOBAL_L8,
        IMG_GLOBAL_L9
    #if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        , IMG_GLOBAL_L10
    #endif 
    #endif /* __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__ */ 
    };
#else /* defined(__MMI_VERSION_2__) */ 
#ifdef __MMI_OP01_MENU_NOSIM_LIST__
    U16 MenuOptionIconList[MAX_SUB_MENUS] = 
        {
    #ifndef __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__
    #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
            MAIN_MENU_AVZONE_TITLE,
    #endif 
            IMG_ID_OPTION_MENU_PHONEBOOK_ICON,
            IMG_ID_OPTION_MENU_SETTINGS_ICON,
            IMG_ID_OPTION_MENU_MULTIMEDIA_ICON,
            IMG_ID_OPTION_MENU_FILEMNGR_ICON,
            IMG_ID_OPTION_MENU_FUNANDGAMES_ICON,
            IMG_ID_OPTION_MENU_PROFILES_ICON,
            IMG_ID_OPTION_MENU_ORGANIZER_ICON,
            IMG_ID_OPTION_MENU_EXTRA_ICON
    #else /* __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__ */ 
            IMG_GLOBAL_L1,
            IMG_GLOBAL_L2,
            IMG_GLOBAL_L3,
            IMG_GLOBAL_L4,
            IMG_GLOBAL_L5,
            IMG_GLOBAL_L6,
            IMG_GLOBAL_L7,
            IMG_GLOBAL_L8
    #if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
            , IMG_GLOBAL_L9
    #endif 
    #endif /* __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__ */ 
        };
#else /* __MMI_OP01_MENU_NOSIM_LIST__ */
    U16 MenuOptionIconList[MAX_SUB_MENUS] = 
    {
    #ifndef __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__
    #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
        MAIN_MENU_AVZONE_TITLE,
    #endif
        IMG_ID_OPTION_MENU_PHONEBOOK_ICON,
        IMG_ID_OPTION_MENU_MULTIMEDIA_ICON,
        IMG_ID_OPTION_MENU_FUNANDGAMES_ICON,
        IMG_ID_OPTION_MENU_PROFILES_ICON,
        IMG_ID_OPTION_MENU_ORGANIZER_ICON
    #ifdef __MMI_TOUCH_SCREEN__
        , IMG_CALIBRATION_MENU_ICON
    #endif
    #else /* __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__ */ 
        IMG_GLOBAL_L1,
        IMG_GLOBAL_L2,
        IMG_GLOBAL_L3,
        IMG_GLOBAL_L4,
        IMG_GLOBAL_L5
    #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
        , IMG_GLOBAL_L6
    #endif
    #ifdef __MMI_TOUCH_SCREEN__
        , IMG_GLOBAL_L7
    #endif
    #endif /* __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__ */ 
    };
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */
#endif /* defined(__MMI_VERSION_2__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    g_idle_context.ToMainMenuScrFromIdleApp = 1;    /* diamond, 2005/10/29, keypad lock in insert sim screen */
#endif 
#endif /* __MMI_TOUCH_SCREEN__ */ 

    EntryNewScreen(SCR_SIM_OPTION, NULL, EntryScrSimOptionMenu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_SIM_OPTION);

    SetParentHandler(MENU_SIM_OPTION_ID);

    nNumofItem = GetNumOfChild(MENU_SIM_OPTION_ID);

    nDispAttribute = GetDispAttributeOfItem(MENU_SIM_OPTION_ID);

    GetSequenceStringIds(MENU_SIM_OPTION_ID, nStrItemList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#ifdef __MMI_OP01_MENU_NOSIM_LIST__
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
#endif
    ShowCategory15Screen(
        STR_SIM_OPTION_CAPTION,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        MenuOptionIconList,
        LIST_MENU,
        0,
        guiBuffer);
#ifdef __MMI_OP01_MENU_NOSIM_LIST__   
    wgui_restore_list_menu_slim_style();
#endif    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* diamond, 2005/10/29, keypad lock in insert sim screen */
#if (defined(__MMI_KEYPAD_LOCK_PATTERN_2__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__))
    if (g_idle_context.ToMainMenuScrFromIdleApp == 1)
    {
        StartTimer(KEYPAD_LOCK_TIMER, KEYPAD_LOCK_TIMEOUT, IdleHandleKeypadLockProcess);
        SetKeyHandler(IdleHandlePoundKeyForKeypadLock, KEY_POUND, KEY_EVENT_UP);
    }
#endif /* (defined(__MMI_KEYPAD_LOCK_PATTERN_2__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__)) */ 
}

/**************************************************************************
   Enter PIN APIs:
      void EntryScrEnterPIN(void)
      void ShowSubLCDEnterPIN(void)
      void ExitSubLCDEnterPIN(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterPIN
 * DESCRIPTION
 *  Function inputs PIN from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterPIN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ENTER_PIN, NULL, EntryScrEnterPIN, NULL);

    if (GetScreenCountInHistory() > 0)
    {
        DinitHistory();
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ENTER_PIN);
    //if(!g_pwr_context.idleScreenFirst)
    //   g_pwr_context.PowerOnPeriod = 0;
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_SIM_LOCK;    /* 0x12: SIM lock */
    g_pwr_context.PrevScreenIndicator = ENTER_PIN_SCR;

    /* Callback to check input password length */
    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;
    FillCountDownString(MMI_SETTING_TYPE_CHV1, PassCountdownDisp);

#if !defined(__MMI_DUAL_SIM_MASTER__)
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_PIN_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);
#else /* __MMI_DUAL_SIM_MASTER__*/
    if (MTPNP_AD_Enable_Close_Card1PIN_Screen())
    {
        ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        0,
        STRING_MTPNP_ENTER_CARD1PIN,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);
    }
    else
    {
        ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STRING_MTPNP_ENTER_CARD1PIN,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);
    }
#endif /* __MMI_DUAL_SIM_MASTER__*/

    ShowSubLCDEnterPIN(); //ShowSubLCDScreen(ShowSubLCDEnterPIN);
    DinitSubLCDHistory();

    SetLeftSoftkeyFunction(ValidatePassword, KEY_EVENT_UP);
#if !defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr,KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (MTPNP_AD_Enable_Close_Card1PIN_Screen())
    {
        SetCategory111RightSoftkeyFunction(MTPNP_PFAL_Cancel_SIM1_VerifyAndUnblock,KEY_EVENT_UP);
    }
    else
    {
        if (mmi_bootup_get_active_flight_mode() == 1)
        {
            SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
        }
        else
        {
            SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr,KEY_EVENT_UP);
            SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
        }
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    SetKeyHandler(ValidatePassword,KEY_POUND,KEY_EVENT_UP);
       
    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidatePassword;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDEnterPIN
 * DESCRIPTION
 *  Entry function for sublcd for enter pin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDEnterPIN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (IsClamClose())
    {
        ShowSubLCDAnalogClockScreen();
    }
    else
    {
        ShowSubLCDLogoString();
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    ShowCategory301Screen((PU8) GetString(STR_SUBLCD_ENTER_PIN_MSG), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    SetSubLCDExitHandler(ExitSubLCDEnterPIN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDEnterPIN
 * DESCRIPTION
 *  Exit function for sublcd for enter pin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDEnterPIN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDEnterPIN;
    AddSubLCDHistory(&SubLCDHistory);
}

/**************************************************************************
   Enter Phone Lock APIs:
      void EntryScrEnterPhoneLock(void)
      void ShowSubLCDEnterPhoneLock(void)
      void ExitSubLCDEnterPhoneLock(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterPhoneLock
 * DESCRIPTION
 *  Entry screen for entring phone lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2006/02/22 Avoid to re-entry phone lock screen by AT emergency call if phone lock is verified */
    if (g_pwr_context.PowerOnMMIStatus == MMI_POWER_ON_SECURITY_NO_PSWD)
    {
        goto_opening_screen();
        return;
    }

    EntryNewScreen(SCR_ENTER_PHONELOCK, NULL, EntryScrEnterPhoneLock, NULL);

    if (GetScreenCountInHistory() > 0)
    {
        DinitHistory();
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ENTER_PHONELOCK);
    //if(!g_pwr_context.idleScreenFirst)
    //   g_pwr_context.PowerOnPeriod = 0;
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PHONE_LOCK;  /* 0x11: Phone lock */
    g_pwr_context.PrevScreenIndicator = ENTER_PHONELOCK;

    /* Callback to check input password length */
    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_PHONELOCK_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        MAX_PWD_LENGTH_MMI,
        NULL,
        guiBuffer);

    ShowSubLCDEnterPhoneLock(); //ShowSubLCDScreen(ShowSubLCDEnterPhoneLock);
    DinitSubLCDHistory();

    SetLeftSoftkeyFunction(ValidatePassword, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr,KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }
    SetKeyHandler(ValidatePassword,KEY_POUND,KEY_EVENT_UP);
       
    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidatePassword;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDEnterPhoneLock
 * DESCRIPTION
 *  Entry screen of sublcd for entring phone lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDEnterPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (IsClamClose())
    {
        ShowSubLCDAnalogClockScreen();
    }
    else
    {
        ShowSubLCDLogoString();
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    ShowCategory301Screen((PU8) GetString(STR_SUBLCD_ENTER_PHONELOCK_MSG), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    SetSubLCDExitHandler(ExitSubLCDEnterPhoneLock);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDEnterPhoneLock
 * DESCRIPTION
 *  Exit screen of sublcd for entring phone lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDEnterPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDEnterPhoneLock;
    AddSubLCDHistory(&SubLCDHistory);
}

/**************************************************************************
   Enter PUK APIs:
      void EntryScrEnterPUK(void)
      void ShowSubLCDEnterPUK(void)
      void ExitSubLCDEnterPUK(void)
      void EntryScrEnterNewPINFirstTime(void)
      void EntryScrEnterNewPINSecondTime(void)
      void ValidatePUK(void)
      void ValidateFirstAndSecondPin(void)
      void EntryScrPinDoNotMatch(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterPUK
 * DESCRIPTION
 *  Function inputs PUK from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterPUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ENTER_PUK, NULL, EntryScrEnterPUK, NULL);

    if (GetScreenCountInHistory() > 0)
    {
        DinitHistory();
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ENTER_PUK);
    //if(!g_pwr_context.idleScreenFirst) 
    //   g_pwr_context.PowerOnPeriod = 0;
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_SIM_LOCK;    /* 0x12: SIM lock */
    g_pwr_context.PrevScreenIndicator = ENTER_PUK_SCR;

    /* Callback to check input password length */
    RegisterInputBoxValidationFunction(ScrSettingPukValidation);
    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;
    FillCountDownString(MMI_SETTING_TYPE_UBCHV1, PassCountdownDisp);

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (!mmi_is_redrawing_bk_screens())
#endif
    {
        sprintf(g_idle_context.DialPadCallBuffer, ""); /* reset dial pad for input * to start ssc */
    }

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
    #ifdef __MMI_DUAL_SIM_MASTER__
        STRING_MTPNP_ENTER_CARD1PUK,
    #else
        STR_ENTER_PUK_MSG,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);

    ShowSubLCDScreen(ShowSubLCDEnterPUK);
    DinitSubLCDHistory();

    SetLeftSoftkeyFunction(EntryScrEnterNewPINFirstTime, KEY_EVENT_UP);
    SetKeyHandler(EntryScrEnterNewPINFirstTime, KEY_POUND, KEY_EVENT_UP);
    SetKeyHandler(SSCHandleEnterPUK, KEY_STAR, KEY_EVENT_DOWN); /* Allow enter SSC in PUK screen */

    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr, KEY_SEND, KEY_EVENT_UP);
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
#endif

    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = EntryScrEnterNewPINFirstTime;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PUK_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDEnterPUK
 * DESCRIPTION
 *  Entry function for sublcd screen enter PUK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDEnterPUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (IsClamClose())
    {
        ShowSubLCDAnalogClockScreen();
    }
    else
    {
        ShowSubLCDLogoString();
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    ShowCategory301Screen((PU8) GetString(STR_SUBLCD_ENTER_PUK_MSG), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    SetSubLCDExitHandler(ExitSubLCDEnterPUK);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDEnterPUK
 * DESCRIPTION
 *  Exit function for sublcd screen enter PUK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDEnterPUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDEnterPUK;
    AddSubLCDHistory(&SubLCDHistory);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterNewPINFirstTime
 * DESCRIPTION
 *  Function inputs new PIN first time from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterNewPINFirstTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ENTER_NEW_PIN, NULL, EntryScrEnterNewPINFirstTime, NULL);

    //if(!g_pwr_context.idleScreenFirst) 
    //   g_pwr_context.PowerOnPeriod = 0;
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_SIM_LOCK;    /* 0x12: SIM lock */
    g_pwr_context.PrevScreenIndicator = ENTER_NEW_PIN;

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
    #ifdef __MMI_DUAL_SIM_MASTER__
        STRING_MTPNP_ENTER_CARD1_NEW_PIN,
    #else
        STR_ENTER_NEW_PIN_MSG,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputNewPinBufferFirstTime,
        MAX_PWD_LENGTH_MMI,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(EntryScrEnterNewPINSecondTime, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(EntryScrEnterNewPINSecondTime,KEY_POUND,KEY_EVENT_UP);
       
    gSecuritySetupContext.PasswdLenCheckCallBack = EntryScrEnterNewPINSecondTime;
    if (mmi_ucs2strlen((S8*) gInputNewPinBufferFirstTime) < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterNewPINSecondTime
 * DESCRIPTION
 *  Function confirms new PIN from user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterNewPINSecondTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ENTER_CONFIRM_PIN, NULL, EntryScrEnterNewPINSecondTime, NULL);

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_SIM_LOCK;    /* 0x12: SIM lock */
    g_pwr_context.PrevScreenIndicator = ENTER_CONFIRM_PIN;

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
    #ifdef __MMI_DUAL_SIM_MASTER__
        STRING_MTPNP_ENTER_PIN_AGAIN,
    #else
        STR_ENTER_PIN_AGAIN_MSG,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputNewPinBufferSecondTime,
        MAX_PWD_LENGTH_MMI,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(ValidateFirstAndSecondPin, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }
    SetKeyHandler(ValidateFirstAndSecondPin,KEY_POUND,KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
       
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateFirstAndSecondPin;
    if (mmi_ucs2strlen((S8*) gInputNewPinBufferSecondTime) < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ValidatePUK
 * DESCRIPTION
 *  Function to validate PUK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidatePUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Validate password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */
    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */ 

    if (gVerifyPasswordSent)
    {
        return;
    }
    gVerifyPasswordSent = MMI_TRUE;

    PRINT_INFORMATION("@@@@@ Sending request for verifying pin  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));

    local_data->pin_type = MMI_TYPE_UNSPECIFIED; //MMI_TYPE_UBCHV1;

    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);
    mmi_ucs2_to_asc((S8*) local_data->new_pin, (S8*) gInputNewPinBufferFirstTime);

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  ValidateFirstAndSecondPin
 * DESCRIPTION
 *  Function to validate First and Second PIN
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateFirstAndSecondPin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if(!g_pwr_context.idleScreenFirst) 
    //   g_pwr_context.PowerOnPeriod = 1;

    /* if(mmi_ucs2strlen((S8*)gInputNewPinBufferSecondTime) < MMI_MIN_PASSWORD_LENGTH)
       {
       if(mmi_ucs2strlen((S8*)gInputNewPinBufferSecondTime) <=0)
       {
       return;
       }
       else
       {
       memset((S8*)gInputNewPinBufferSecondTime,0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
       EntryScrInvalidPINPUKPLOCKLength();
       return;
       }
       } */

    if (memcmp
        ((S8*) gInputNewPinBufferSecondTime, (S8*) gInputNewPinBufferFirstTime,
         (MAX_PWD_LENGTH_MMI - 1) * ENCODING_LENGTH) == 0)
    {
        PRINT_INFORMATION("Both Pin matches , calling ValidatePUK");
        ValidatePUK(); /* Also Store new pin to the Simulator [Manish to be done later] */
    }
    else
    {
        EntryScrPinDoNotMatch();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrPinDoNotMatch
 * DESCRIPTION
 *  Display Message 'PIN inputs do not match'
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrPinDoNotMatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) gInputNewPinBufferSecondTime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    memset((S8*) gInputNewPinBufferFirstTime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
#ifdef __MMI_DUAL_SIM_MASTER__
    DisplayPopup((U8*) GetString(STRING_MTPNP_CARD1_PIN_DONOT_MATCH), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
#else
    DisplayPopup((U8*) GetString(STR_PIN_DONOT_MATCH), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
#endif
    DeleteUptoScrID(SCR_ENTER_NEW_PIN);
}

/**************************************************************************
   S.O.S APIs:
      void GoToSOSDialScr(void)
      void HandleInsertSIMScrDigitEntry(void)
      void DialSOSNumber(void)
      void ExitDialSOSNumber(void)
      void ShowMakeSOSCallScr(void)
      void ExitShowMakeSOSCallScr(void)
      pBOOL IsSOSCall(void)
      void EntryScrSOSErrorMessage(U16 string_id)
      void EntryScrEmergencyCallDialing(void)
      pBOOL IsSOSPossible(void)
      pBOOL CheckSIMSOSEntries(S8* tempbuffer)
      pBOOL CheckValidEmergencyNo1(S8 *tempbuffer)
      void SimECCInfoSave(void *inMsg)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_ssc_input_handler
 * DESCRIPTION
 *  # key handler in sim error dialpad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_error_ssc_input_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (!SSCStringParsing3())
#endif
    {
        SSCStringParsing1();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoToSOSDialScr
 * DESCRIPTION
 *  Function takes care that from which buffer DialPadBuffer should be filled up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToSOSDialScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.PrevScreenIndicator == ENTER_NEW_PIN)
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) gInputNewPinBufferFirstTime);
        memset((S8*) gInputNewPinBufferFirstTime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    }
    else if (g_pwr_context.PrevScreenIndicator == ENTER_CONFIRM_PIN)
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) gInputNewPinBufferSecondTime);
        memset((S8*) gInputNewPinBufferSecondTime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) gInputPwdBuffer);
        memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        if (g_idle_context.DialPadCallBuffer[0] != '\0')
        {
            mmi_sim_error_reset_input_password_guibuffer();
        }
    }

    EntryScrEmergencyCallDialing();
}


/*****************************************************************************
 * FUNCTION
 *  HandleInsertSIMScrDigitEntry
 * DESCRIPTION
 *  Handle digit entry on insert SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleInsertSIMScrDigitEntry(void)
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
    DialSOSNumber();
}


/*****************************************************************************
 * FUNCTION
 *  DialSOSNumber
 * DESCRIPTION
 *  Function to make SOS calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DialSOSNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsOnSimErrorDialerScreen = 1;

    EntryNewScreen(SCR_DIAL_SOS_NUM, ExitDialSOSNumber, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_SIM_INSERTION);

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
        guiBuffer);

    if (g_idle_context.IdleScreenDigitKeyCode >= 0)
    {
        ExecuteCurrKeyHandler(g_idle_context.IdleScreenDigitKeyCode, KEY_EVENT_DOWN);
    }

    /* 090605 Dialing Calvin Start */
#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadCallHandler(EntryScrEmergencyCallDialing);
#else 
    SetCenterSoftkeyFunction(EntryScrEmergencyCallDialing, KEY_EVENT_UP);
#endif 
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) ) */ 
    /* 090605 Dialing Calvin Start */

#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == 0)   /* 2005/11/01 Cannot allow to dial in flight mode insert SIM screen */
#endif 
        SetKeyHandler(EntryScrEmergencyCallDialing, KEY_SEND, KEY_EVENT_UP);

    SetCategory16RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* diamond, 2005/11/20 Allow to entry phonebook in insert SIM screen */
    SetLeftSoftkeyFunction(IdleDialPadSavePhoneBook, KEY_EVENT_UP);

    /* For processing SSC */
    if ((g_pwr_context.PrevScreenIndicator == ENTER_SIM_INSERTION) ||
#ifdef __MMI_SML_NP_ONLY__
        (g_pwr_context.PrevScreenIndicator == ENTER_NP_PENDING) ||
#endif
        (g_pwr_context.PrevScreenIndicator == ENTER_SIM_BLOCK))
    {
        SetKeyHandler(mmi_sim_error_ssc_input_handler, KEY_POUND, KEY_EVENT_UP);
    }

#ifdef __MMI_STARKEY_TOGGLE_PROFILE__
    SetKeyHandler(mmi_sim_error_idle_toggle_profile, KEY_STAR, KEY_LONG_PRESS);
#else 
    SetKeyHandler(mmi_sim_error_idle_toggle_profile, KEY_POUND, KEY_LONG_PRESS);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ExitDialSOSNumber
 * DESCRIPTION
 *  Exit Function for dial SOS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitDialSOSNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.SOSCallFlagTOAvoidHistorySave != 1)   /* to avoid history save */
    {
        GenericExitScreen(SCR_DIAL_SOS_NUM, DialSOSNumber);
    }

    g_idle_context.IdleScreenDigitKeyCode = -1;
    g_idle_context.IsOnSimErrorDialerScreen = 0;

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    ResetCenterSoftkey();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ShowMakeSOSCallScr
 * DESCRIPTION
 *  Function to make SOS calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowMakeSOSCallScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    if (GetActiveScreenId() == SCR_SIM_INSERTION || GetActiveScreenId() == SCR_SIM_BLOCK)
    {
        g_idle_context.RskPressedFromIdleApp = 1;   /* diamond, 2005/10/29, keypad lock in insert sim screen */
    }
#endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 

    EntryNewScreen(SCR_MAKE_SOS_CALL, ExitShowMakeSOSCallScr, NULL, NULL);

#ifdef __MMI_TOUCH_SCREEN__
    if (g_keylock_context.gKeyPadLockFlag)
    {
        mmi_pen_unblock();
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
    mmi_asc_to_ucs2(g_idle_context.DialPadCallBuffer, "112");

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_DIAL_EMERGENCY_NUMBER),
        IMG_GLOBAL_QUESTION,
        NULL);

    SetLeftSoftkeyFunction(EntryScrEmergencyCallDialing, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* changed end key press from up to down to clear END key mapping to DisplayIdleScreen which is done at time of    ExecuteCurrExitHandler(). --vanita */
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);
    playRequestedTone(WARNING_TONE);

    /* diamond, 2005/10/29, keypad lock in insert sim screen */
#if (defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__))
    /* if(g_idle_context.ToNameScrFromIdleApp==1) */
    if (g_idle_context.RskPressedFromIdleApp == 1)
    {
        StartTimer(KEYPAD_LOCK_TIMER, KEYPAD_LOCK_TIMEOUT, IdleHandleKeypadLockProcess);
        SetKeyHandler(IdleHandlePoundKeyForKeypadLock, KEY_POUND, KEY_EVENT_UP);
    }
#endif /* (defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitShowMakeSOSCallScr
 * DESCRIPTION
 *  Exit Function for make SOS call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitShowMakeSOSCallScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.SOSCallFlagTOAvoidHistorySave != 1)
    {
        /* GenericExitScreen(SCR_MAKE_SOS_CALL, ShowMakeSOSCallScr); */
    }

    stopRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  IsSOSCall
 * DESCRIPTION
 *  Function for CM to notify is SOS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsSOSCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_pwr_context.ForCMToIdentifySOSCall;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrSOSErrorMessage
 * DESCRIPTION
 *  Popup error message for SOS screen
 * PARAMETERS
 *  string_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSOSErrorMessage(U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((U8*) GetString(string_id), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEmergencyCallDialing
 * DESCRIPTION
 *  Show the message Emergency Call Dialing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEmergencyCallDialing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    mmi_sim_error_set_emergency_call_path(); /* need to determine the emergency call shall be dialed out from L4 or L42 */
#endif

    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 1;

    /* diamond, 2005/11/28 Remove keypad lock icon if user pressed emergency call number */
    if (g_keylock_context.gKeyPadLockFlag == 1)
    {
        g_keylock_context.gKeyPadLockFlag = 0;
    #ifdef __MMI_TOUCH_SCREEN__
        ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_UNLOCK);
        UpdateStatusIcons();
    #else /* __MMI_TOUCH_SCREEN__ */ 
        IdleResetStatusIcon(STATUS_ICON_KEYPAD_LOCK);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    #ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
    #endif 
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (CheckValidEmergencyNo1(g_idle_context.DialPadCallBuffer, SIM1))
#else
    if (CheckValidEmergencyNo1(g_idle_context.DialPadCallBuffer))
#endif
    {
        g_pwr_context.ForCMToIdentifySOSCall = TRUE;

    #ifdef __FLIGHT_MODE_SUPPORT__
        if (mmi_bootup_get_active_flight_mode() == 1)   /* 2005/11/01 Cannot allow to dial in flight mode insert SIM screen */
        {
            EntryScrSOSErrorMessage(STR_MENU_FLIGHT_MODE);
        }
        else
    #endif /* __FLIGHT_MODE_SUPPORT__ */ 
        if (IsSOSPossible())
    #ifdef __MMI_Emergency_Call_911_Support__
            /*  For insert SIM case, dail 911 as emergency call */
            MakeCall((PS8) EmergencyNumber[0]);
    #else /* __MMI_Emergency_Call_911_Support__ */ 
            MakeCall(g_idle_context.DialPadCallBuffer);
    #endif /* __MMI_Emergency_Call_911_Support__ */ 
        else
        {
            EntryScrSOSErrorMessage(STR_NO_SERVICE_RUNNING_TEXT);
        }
    }
    else if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
    {
    #ifdef __FLIGHT_MODE_SUPPORT__
        if (mmi_bootup_get_active_flight_mode() == 1)   /* 2005/11/01 Cannot allow to dial in flight mode insert SIM screen */
        {
            EntryScrSOSErrorMessage(STR_MENU_FLIGHT_MODE);
        }
        else
    #endif /* __FLIGHT_MODE_SUPPORT__ */ 
            EntryScrSOSErrorMessage(STR_NOT_SOS_NUMBER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsSOSPossible
 * DESCRIPTION
 *  Return the possibility of SOS call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsSOSPossible(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.CurrentServiceType == FULL_SERVICE
        || g_pwr_context.CurrentServiceType == LIMITED_SERVICE
        || mmi_bootup_is_nw_registration_ok() == MMI_TRUE
#ifdef __MMI_DUAL_SIM_MASTER__
        || g_pwr_context_2.CurrentServiceType == FULL_SERVICE
        || g_pwr_context_2.CurrentServiceType == LIMITED_SERVICE
        || mmi_bootup_is_sim2_nw_registration_ok() == MMI_TRUE
#endif /* __MMI_DUAL_SIM_MASTER__ */
       )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CheckValidEmergencyNo1
 * DESCRIPTION
 *  Checks for Emergency Nos in Different conditions
 * PARAMETERS
 *  eccbuffer       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_DUAL_SIM_MASTER__
pBOOL CheckValidEmergencyNo1(S8 *eccbuffer, U8 simInterface)
#else
pBOOL CheckValidEmergencyNo1(S8 *eccbuffer)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S8 *tempbuffer;
    U16 AdditionalCheckNumber[5][5] = 
    {
        {0x002A, 0x0033, 0x0031, 0x0023, 0x002B}
        ,       /* prefix = *31#+ */
        {0x0023, 0x0033, 0x0031, 0x0023, 0x002B}
        ,       /* prefix = #31#+ */
        {0x002A, 0x0033, 0x0031, 0x0023}
        ,       /* prefix = *31# */
        {0x0023, 0x0033, 0x0031, 0x0023}
        ,       /* prefix = #31# */
        {0x002B}    /* prefix = + */
    };

    S8 EmergencyNumberExt[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetOutgoingCallOrigin() == CM_CALL_MO_STK)
    {
        if (mmi_ucs2cmp(eccbuffer, (PS8) L"112") == 0 || mmi_ucs2cmp(eccbuffer, (PS8) L"911") == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    /* diamond, 2006/02/08 Additional check for *31# and #31# before emergency call */
    /* diamond, 2006/03/26 Additional check for + before emergency call */
    if ((mmi_ucs2ncmp(eccbuffer, (PS8) AdditionalCheckNumber[0], 5) == 0) ||
        (mmi_ucs2ncmp(eccbuffer, (PS8) AdditionalCheckNumber[1], 5) == 0))
    {
        tempbuffer = eccbuffer + 10;
    }
    else if ((mmi_ucs2ncmp(eccbuffer, (PS8) AdditionalCheckNumber[2], 4) == 0) ||
             (mmi_ucs2ncmp(eccbuffer, (PS8) AdditionalCheckNumber[3], 4) == 0))
    {
        tempbuffer = eccbuffer + 8;
    }
    else if (mmi_ucs2ncmp(eccbuffer, (PS8) AdditionalCheckNumber[4], 1) == 0)
    {
        tempbuffer = eccbuffer + 2;
    }
    else
    {
        tempbuffer = eccbuffer;
    }

    if (mmi_ucs2strlen(tempbuffer) != 0)
    {
        for (i = 0; i < MAX_EMERGENCYNUMBER; i++)
        {
            if (mmi_ucs2cmp(tempbuffer, (PS8) EmergencyNumber[i]) == 0)
            {
                return 1;
            }

            /* diamond, 2006/03/31 Additional check for p or w after emergency call */
            mmi_ucs2cpy(EmergencyNumberExt, (PS8) EmergencyNumber[i]);
            mmi_ucs2cat(EmergencyNumberExt, (PS8) L"p");
            if (mmi_ucs2ncmp(tempbuffer, EmergencyNumberExt, mmi_ucs2strlen(EmergencyNumberExt)) == 0)
            {
                return 1;
            }

            mmi_ucs2cpy(EmergencyNumberExt, (PS8) EmergencyNumber[i]);
            mmi_ucs2cat(EmergencyNumberExt, (PS8) L"w");
            if (mmi_ucs2ncmp(tempbuffer, EmergencyNumberExt, mmi_ucs2strlen(EmergencyNumberExt)) == 0)
            {
                return 1;
            }

            /* diamond, 2006/05/12 Additional check for + after emergency call */
            mmi_ucs2cpy(EmergencyNumberExt, (PS8) EmergencyNumber[i]);
            mmi_ucs2cat(EmergencyNumberExt, (PS8) L"+");
            if (mmi_ucs2ncmp(tempbuffer, EmergencyNumberExt, mmi_ucs2strlen(EmergencyNumberExt)) == 0 &&
                mmi_ucs2ncmp(tempbuffer + ((mmi_ucs2strlen(tempbuffer) - 1) * ENCODING_LENGTH), (PS8) L"#", 1) != 0)
            {
                return 1;
            }
        }

#ifdef __MMI_DUAL_SIM_MASTER__
        if (mmi_phb_check_valid_sos_number(tempbuffer, simInterface) == 2)
#else
        if (mmi_phb_check_valid_sos_number(tempbuffer) == 2)
#endif
        {
            return 1;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SimECCInfoSave
 * DESCRIPTION
 *  Callback of PRT_SMU_STARTUP_INFO_IND
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SimECCInfoSave(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_startup_info_ind_struct *local_data = (mmi_smu_startup_info_ind_struct*) inMsg;
    U8 Count = 0;
    U8 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* fill ECC codes to buffer */
    if (local_data->num > 0)
    {
        for (Count = 0; Count < local_data->num; Count++)
        {
            j = Count * (NUM_OF_BYTE_ECC * 2 + 1);
            while (local_data->ecc[j] != '\0')
            {
                gSimEccNumList[Count][i] = local_data->ecc[j];
                i++;
                j++;
            }
            gSimEccNumList[Count][i] = '\0';
            i = 0;
        }
    }

#ifdef __MMI_AUTO_LANG_EN__
    /* process and store LP in context */
    PhnsetPLPInd(local_data->language);

    /* If UsrLangIdx != 0xFF, not necessary to handle it because */
    /* 1. PhnsetSetLangByNvramValue() has been executed --> Language has already set */
    /* 2. PhnsetSetLangByNvramValue() did not executed --> */
    /*    PhnsetSetLangByNvramValue() will be execute later and Language will be set at that time */
    if (PhnsetGetLang() == 0xFF)
    {
        SetCurrentLanguage((S8) PhnsetGetAutoLangIdx());    /* in ReadRes.c */
    }
#endif /* __MMI_AUTO_LANG_EN__ */ 

#ifdef __MANUAL_MODE_NW_SEL__
    /* get PLMN selection mode */
    PLMNGetSelectionModeReq();
#endif /* __MANUAL_MODE_NW_SEL__ */ 
}

/**************************************************************************
   SIM security check APIs:
      void SimPasswdReqResponse(void *inMsg)
      void SimQueryFailureRsp(void *inMsg)
      void EntryScrIncorrectPin(void)
      void EntryScrIncorrectPhoneLock(void)
      void EntryScrIncorrectPUK(void)
      void EntryScrPinBlocked(void)
      void ExitScrPinBlocked(void)
      void EntryScrCodeVerified(void)
      void ExitCodeVerifiedScr(void)
      void CodeVerifiedTimeoutFn(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_indication_bt_power_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_ind         [IN]        
 *  msg_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sim_indication_bt_power_on(U8 sim_ind, U16 msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_SUPPORT__
    static U8 BTPowerOnFlag = MMI_FALSE;
    pBOOL status;
#endif /* __MMI_BT_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IRDA_SUPPORT__
#if !defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_valid() == MMI_TRUE && sim_ind == 0 && msg_type != MMI_SIM_REFRESH &&
        MMI_IRDASCR_CNTX(irda_state) != MMIR_SCR_IRCLOSE)
#else
    if ((mmi_bootup_is_sim_valid() == MMI_TRUE || !MTPNP_PFAL_Is_Card2Absent()) && sim_ind == 0 && msg_type != MMI_SIM_REFRESH &&
        MMI_IRDASCR_CNTX(irda_state) != MMIR_SCR_IRCLOSE)
#endif
    {
        if (mmi_irda_is_ircomm_active() == MMI_TRUE)
        {
            mmi_irda_ircomm_disconnect_request();
        }
        mmi_irda_exec_close_menu();
    }
#endif /* __MMI_IRDA_SUPPORT__ */ 

#ifdef __MMI_BT_SUPPORT__
    if (BTPowerOnFlag)
    {
        return;
    }

    if (sim_ind == 0)   /* sim failure indication */
    {
        status = MMI_FALSE;
    }
    else    /* sim password indication */
    {
        switch (msg_type)
        {
            case MMI_TYPE_PHONELOCK:
            case MMI_TYPE_CHV1:
            case MMI_TYPE_UBCHV1:
            case MMI_TYPE_NP:
            case MMI_TYPE_NSP:
            case MMI_TYPE_SP:
            case MMI_TYPE_CP:
            case MMI_TYPE_IMSI_LOCK:
            case MMI_TYPE_LINK_NS_SP:
            case MMI_TYPE_LINK_SIM_C:
                return;
                break;

            case MMI_TYPE_SIM_CARD_BLOCKED:
                status = MMI_FALSE;
                break;

            case MMI_TYPE_NO_REQUIRED:
            default:
                status = MMI_TRUE;
                break;
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_bt_ps_stack_and_hw_init((mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT && MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT) ? FLIGHTMODE_SILENT : FLIGHTMODE_OFF, status);
#else
    mmi_bt_ps_stack_and_hw_init(mmi_bootup_get_active_flight_mode(), status);
#endif
    BTPowerOnFlag = MMI_TRUE;
#endif /* __MMI_BT_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_phone_lock_history
 * DESCRIPTION
 *  History of phone lock if SimPasswdReqResponse is received in call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_phone_lock_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryScrEnterPhoneLock();
    mmi_sim_error_process_pending_events();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_lock_history
 * DESCRIPTION
 *  History of PIN lock if SimPasswdReqResponse is received in call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sim_lock_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryScrEnterPIN();
    mmi_sim_error_process_pending_events();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_add_history_before_cm_marker
 * DESCRIPTION
 *  Add a screen to the history before CM_SCR_MARKER
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = scrn_id;
    Scr.entryFuncPtr = func_ptr;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) L"");

#ifdef __MMI_UCM__
    InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), Scr);
#else /* __MMI_UCM__ */
    #ifdef __MMI_VOIP__
        if (mmi_voip_app_total_call() != 0)
            InsertHistoryBeforeThisScrn(mmi_voip_app_get_marker_screen(), Scr);
        else
    #endif /* __MMI_VOIP__ */
            InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), Scr);
#endif /* __MMI_UCM__ */
}


/*****************************************************************************
 * FUNCTION
 *  SimPasswdReqResponse
 * DESCRIPTION
 *  This is called as a call back when MMI_SMU_PASSWORD_REQUIRED_IND is received from the L4
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ready_to_idle_screen_ind(void);

void SimPasswdReqResponse(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MMI will repeatedly receive this indication if its content isn't MMI_TYPE_NO_REQUIRED */
    /* (MMI_TYPE_PHONELOCK) -> (MMI_TYPE_CHV1) -> MMI_TYPE_NO_REQUIRED */

    static U8 gCodeVerifyRequiredFlag = 0;
    MMISMUPASSWDREQIND *local_data = (MMISMUPASSWDREQIND*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.PrevScreenIndicator == ENTER_SIM_INSERTION ||
        g_pwr_context.PrevScreenIndicator == ENTER_SIM_BLOCK)
    {
        return; /* diamond, 2005/12/26 If SIM is not inserted, verifying phone lock shall meet this message */
    }

#if defined(__MMI_DUAL_SIM_MASTER__)
    if (MTPNP_PFAL_Is_Card1Absent() &&
        MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_VALID)
    {
        /* if SIM1 is not inserted, but SIM2 valid, then operate factory retore shall meet this message */
        if (local_data->type == MMI_TYPE_NO_REQUIRED && MTPNP_AD_Is_During_Mode_Switch())
        {
            if (gCodeVerifyRequiredFlag)
            {
                MTPNP_PFAL_Entry_SIM1_Verified_Screen();
                MTPNP_AD_Enable_Card1_RF();
            }
        }
        return;
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    /* Retry count for PIN/PUK and personalization locks */
    FillCountDownNumber(local_data->chv_info);
    gCPHSRetryCount = local_data->cphs_retry_count;
#ifdef __MMI_SML_MENU__
    mmi_sml_power_on_query_req();
#endif 

    /* if((!g_pwr_context.PowerOnAnimationComplete) */
    if (mmi_bootup_is_power_on_animation_complete() == MMI_FALSE
#if defined(__FS_CHECKDRIVE_SUPPORT__)
        || (SanityCheckDone == 0) || (SanityCheckDone == 3)
#endif 
        )
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_RECV_SIM_PSWD);

    #if defined(__MMI_DUAL_SIM_MASTER__)
        switch (local_data->type)
        {
        case MMI_TYPE_NO_REQUIRED:
            /* set the card1 status to work */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_VALID);
            break;
        case MMI_TYPE_CHV1:
        case MMI_TYPE_CHV2:
        case MMI_TYPE_UBCHV1:
            /* set the card1 status to work */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_CHV1_REQUESTED);
            break;
        default:
            break;
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        
        memcpy(&gSMUPwdDataStruct, local_data, sizeof(MMISMUPASSWDREQIND));
        /* g_pwr_context.PasswdReqIndFlag=1; */
        if (mmi_bootup_is_power_on_animation_complete() == MMI_FALSE)
        {
            /* nand check first then receive this message */
            g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_ANIMATION_PSWD_REQ;       /* 0x05: Power on animation with password requirement indication */
        }
        g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_SECURITY_CHECK;        /* 0x08: Need security check */

        /* Robin 0719, Cannon+ SCR 3585: [China FT]MMI-PLNM is display TWN GSM  then display CU-GSM  */
        /* Current, MMI will postpone handling SMU_PASSWORD_REQUIRED_IND to align with power on animation */
        /* So will delay the IMSI retrieve, cause realize roaming status too late. */
        /* Duplicate here to get IMSI immediately once SIM password verified done. */
        if (local_data->type == MMI_TYPE_NO_REQUIRED)
        {
            g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_INVALID;  /* 0x01: Invalid SIM reset */
            if (g_pwr_context.testRoaming == 1) /* Shall send GET IMSI REQ once */
            {
                RequestToTestRoamingEnabled();
            }
        }

        return; /* postpone this indication after power on animation completes */
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_PROC_SIM_PSWD);

    /* Notify BT to start init bt ps stack and hw */
    mmi_bootup_sim_indication_bt_power_on(1, local_data->type);

    /* g_pwr_context.PasswdReqIndFlag=0; */
    g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_SECURITY_CHECK;   /* 0x08: Security check done */

    StopLEDPatternPowerOn();

    ClearKeyEvents();
    mmi_sim_error_reset_input_password_guibuffer();
    memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    memset((S8*) gInputNewPinBufferFirstTime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    memset((S8*) gInputNewPinBufferSecondTime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    gVerifyPasswordSent = MMI_FALSE;

    /* Close backling when enter password */
    if (local_data->type != 0)
    {
        FirstTimeTurnOnBackLight();
    }

    /* g_pwr_context.SimRemoveFlag=0; */
    g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_NOT_INSERT;       /* 0x02: SIM removed reset */
    //g_pwr_context.PowerOnTillIdleApp=1;
    //g_pwr_context.PowerOnPeriod=0;

    /* call this stop animation to stop all play power display, */
    /* which will stop all timer and avoid NVRAM & timer interlace problem */
    mmi_pwron_stop_animation();

    switch (local_data->type)
    {
            /* Directly jump to idle screen */
        case MMI_TYPE_NO_REQUIRED:

            g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_INVALID;  /* 0x01: Invalid SIM reset */

	#ifdef __MMI_DUAL_SIM_MASTER__
	    /* set the card1 status to work */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_VALID);
            /* rearrange the menu item */
            MTPNP_PFAL_Rearrange_MenuItem();
            /* rearrange the status bar on idle screen */
            MTPNP_PFAL_Rearrange_StatusBar();
	#endif /* __MMI_DUAL_SIM_MASTER__ */
	
            /* if(gSIMRefresh == 1) */
            if (mmi_bootup_is_sim_refresh() == MMI_TRUE)
            {
                g_phb_cntx.phb_ready = FALSE;   /* MTK 2003-12-22 Wilson, for SIM refresh */
                //g_pwr_context.IsSimValid = 1;
                //EntryIdleScreen();
            #ifdef __SAT__
                if (IsInSATScreen())
                {
                    SATMessageWaitTimer();
                    DisplayPopup(
                        (U8*) GetString(STR_ID_SIM_REFRESH),
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                }
                /* gSIMRefresh = 0; */

                if (GetActiveScreenId() == SCR_ENTER_PHONELOCK)
                {
                    ExitVariables();
                    EntryIdleScreen();
                }
            #endif /* __SAT__ */

                g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_REFRESH;      /* SIM refresh reset */

                /* diamond, 2006/04/04 Avoid the case of SIM refreshing before power on animation is complete */
                if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
                {
                    return;
                }
            }
            else
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_NO_PSWD;     /* 0x10: Security check */
            }
            // MTK end
            //g_pwr_context.PowerOnPeriod=1;
            PRINT_INFORMATION("MMI_TYPE_NO_REQUIRED");
            // gTypeNoReq = 1;
            //g_pwr_context.IsSimValid = 1;
            g_pwr_context.PrevScreenIndicator = 0;

        #ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
            mmi_sml_unlock_after_verified_paswd();
        #endif

        #ifdef __MMI_WLAN_FEATURES__
            mmi_netset_update_preferred_mode_menu();
        #endif

            /* Robin 0719, Cannon+ SCR 3585: [China FT]MMI-PLNM is display TWN GSM  then display CU-GSM  */
            /* Current, MMI will postpone handling SMU_PASSWORD_REQUIRED_IND to align with power on animation */
            /* So will delay the IMSI retrieve, cause realize roaming status too late. */
            /* Will duplicate to the top of this fucntion to get IMSI immediately once SIM password verified done. */
            if (g_pwr_context.testRoaming == 1) /* Shall send GET IMSI REQ once */
            {
                RequestToTestRoamingEnabled();
            }

            if (g_charbat_context.isChargerConnected == 1)
            {
                /* Hide status icon temporary, entry idle screen will start animation again */
                HideStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
                ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
                UpdateStatusIcons();
            }

            if (gCodeVerifyRequiredFlag)
            {
                EntryScrCodeVerified();
            }
            else
            {
                /* DinitHistory(); // Not necessary to deinit history because there might be an incoming call */
                mmi_bootup_exit_security_check();   /* send message to it slef notify ready to go to idle */
            }

        #ifdef __MMI_DUAL_SIM_MASTER__
            mmi_idle_notify_dual_sim_status_to_wap();
        #endif
            break;

        case MMI_TYPE_PHONELOCK:
            PRINT_INFORMATION("MMI_TYPE_PHONELOCK");
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            g_pwr_context.PhoneLockNeeded = 1;
        #endif
            if (g_pwr_context.PrevScreenIndicator == ENTER_PHONELOCK)
            {
                EntryScrIncorrectPhoneLock();
            }
            else
            {
                if (isInCall())
                {
                    mmi_frm_add_history_before_cm_marker(SCR_ENTER_PHONELOCK, mmi_bootup_phone_lock_history);
                }
                else
                {
                    EntryScrEnterPhoneLock();
                    mmi_sim_error_process_pending_events();
                }
            }
            break;

            /* Show Enter PIN Screen */
        case MMI_TYPE_CHV1:
            PRINT_INFORMATION("Enter PIN [MMI_TYPE_CHV1]");
        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the card1 status to work */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_CHV1_REQUESTED);
	#endif /* __MMI_DUAL_SIM_MASTER__ */
            if (g_pwr_context.PrevScreenIndicator == ENTER_PIN_SCR)
            {
                EntryScrIncorrectPin();
            }
            else
            {
                gCodeVerifyRequiredFlag = 1;
                if (isInCall())
                {
                    mmi_frm_add_history_before_cm_marker(SCR_ENTER_PIN, mmi_bootup_sim_lock_history);
                }
                else
                {
                    EntryScrEnterPIN();
                    mmi_sim_error_process_pending_events();
                }
            }
            break;

        case MMI_TYPE_CHV2:
            PRINT_INFORMATION("Enter PIN [MMI_TYPE_CHV2]");
            break;

        case MMI_TYPE_UBCHV1:
            PRINT_INFORMATION("MMI_TYPE_UBCHV1");
        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the card1 status to work */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_CHV1_REQUESTED);
	#endif /* __MMI_DUAL_SIM_MASTER__ */
            if ((g_pwr_context.PrevScreenIndicator == ENTER_CONFIRM_PIN) || GetActiveScreenId() == SCR_SSC_ENTER_PUK || IsScreenPresent(SCR_SSC_ENTER_PUK) == MMI_TRUE)
            {
                EntryScrIncorrectPUK();
            }
            else
            {
                EntryScrPinBlocked();
                gCodeVerifyRequiredFlag = 1;
            }
            break;

        case MMI_TYPE_UBCHV2:
            PRINT_INFORMATION("MMI_TYPE_UBCHV2");
            break;

        case MMI_TYPE_CHV1_BLOCKED:
            PRINT_INFORMATION("MMI_TYPE_CHV1_BLOCKED");
            break;

        case MMI_TYPE_CHV2_BLOCKED:
            /* L4 not taking care it */
            PRINT_INFORMATION("MMI_TYPE_CHV2_BLOCKED");
            break;

        case MMI_TYPE_SIM_CARD_BLOCKED:
            PRINT_INFORMATION("MMI_TYPE_SIM_CARD_BLOCKED");
            g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;

    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            /* case 12 with SIM1 blocked */
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
            {
                mmi_bootup_dual_sim_power_on();
            }
    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

	#ifdef __MMI_DUAL_SIM_MASTER__
            /* set the card1 status to block */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_CHVBLOCKED);
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
            /* set network register status to register failed */
            MTPNP_AD_Set_Card1NetStatus(MTPNP_AD_NW_STATUS_REGISTER_FAILED);

            /* rearrange the menu item */
            MTPNP_PFAL_Rearrange_MenuItem();
            /* rearrange the status bar on idle screen */
            MTPNP_PFAL_Rearrange_StatusBar();
	
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
	#endif /* __MMI_DUAL_SIM_MASTER__ */
            simErrorDisplayString = STR_SIM_BLOCK_MSG; 
            InitSimBlockedScreen();
            break;

        case MMI_TYPE_UBCHV2_BLOCKED:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_UBCHV2_BLOCKED");
            break;

        case MMI_TYPE_UBCHV1_CHV1_NOT_LOCK:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_UBCHV1_CHV1_NOT_LOCK");
            break;

        case MMI_TYPE_NP:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_NP");
        #ifdef __MMI_SML_NP_ONLY__
            mmi_bootup_sim_entry_pending_np_screen();
        #else /* __MMI_SML_NP_ONLY__ */ 
            if (gCPHSRetryCount == 0)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
                mmi_bootup_sim_indication_bt_power_on(1, MMI_TYPE_SIM_CARD_BLOCKED);
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                InitSimBlockedScreen();
            }
            else
            {
                if (g_pwr_context.PrevScreenIndicator == ENTER_NP)
                {
                    EntryScrIncorrectNP();
                }
                else
                {
                    EntryScrEnterNP();
                    mmi_sim_error_process_pending_events();
                }
            }
        #endif /* __MMI_SML_NP_ONLY__ */ 
            break;

        case MMI_TYPE_NSP:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_NSP");
            if (gCPHSRetryCount == 0)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
                mmi_bootup_sim_indication_bt_power_on(1, MMI_TYPE_SIM_CARD_BLOCKED);
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                InitSimBlockedScreen();
            }
            else
            {
                if (g_pwr_context.PrevScreenIndicator == ENTER_NSP)
                {
                    EntryScrIncorrectNSP();
                }
                else
                {
                    EntryScrEnterNSP();
                    mmi_sim_error_process_pending_events();
                }
            }
            break;

        case MMI_TYPE_SP:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_SP");
            if (gCPHSRetryCount == 0)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
                mmi_bootup_sim_indication_bt_power_on(1, MMI_TYPE_SIM_CARD_BLOCKED);
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                InitSimBlockedScreen();
            }
            else
            {
                if (g_pwr_context.PrevScreenIndicator == ENTER_SP)
                {
                    EntryScrIncorrectSP();
                }
                else
                {
                    EntryScrEnterSP();
                    mmi_sim_error_process_pending_events();
                }
            }
            break;

        case MMI_TYPE_CP:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_CP");
            if (gCPHSRetryCount == 0)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
                mmi_bootup_sim_indication_bt_power_on(1, MMI_TYPE_SIM_CARD_BLOCKED);
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                InitSimBlockedScreen();
            }
            else
            {
                if (g_pwr_context.PrevScreenIndicator == ENTER_CP)
                {
                    EntryScrIncorrectCP();
                }
                else
                {
                    EntryScrEnterCP();
                    mmi_sim_error_process_pending_events();
                }
            }
            break;

        case MMI_TYPE_IMSI_LOCK:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_IMSI_LOCK");
            if (gCPHSRetryCount == 0)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
                mmi_bootup_sim_indication_bt_power_on(1, MMI_TYPE_SIM_CARD_BLOCKED);
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                InitSimBlockedScreen();
            }
            else
            {
                if (g_pwr_context.PrevScreenIndicator == ENTER_SIMP)
                {
                    EntryScrIncorrectSIMP();
                }
                else
                {
                    EntryScrEnterSIMP();
                    mmi_sim_error_process_pending_events();
                }
            }
            break;

#ifdef __MMI_SML_MENU__
        case MMI_TYPE_LINK_NS_SP:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_LINK_NS_SP");
            if (gCPHSRetryCount == 0)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
                mmi_bootup_sim_indication_bt_power_on(1, MMI_TYPE_SIM_CARD_BLOCKED);
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                InitSimBlockedScreen();
            }
            else
            {
                if (g_pwr_context.PrevScreenIndicator == ENTER_NS_SP)
                {
                    EntryScrIncorrectNSSP();
                }
                else
                {
                    EntryScrEnterNSSP();
                    mmi_sim_error_process_pending_events();
                }
            }
            break;

        case MMI_TYPE_LINK_SIM_C:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_LINK_SIM_C");
            if (gCPHSRetryCount == 0)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
                mmi_bootup_sim_indication_bt_power_on(1, MMI_TYPE_SIM_CARD_BLOCKED);
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                InitSimBlockedScreen();
            }
            else
            {
                if (g_pwr_context.PrevScreenIndicator == ENTER_SIM_C)
                {
                    EntryScrIncorrectSIMC();
                }
                else
                {
                    EntryScrEnterSIMC();
                    mmi_sim_error_process_pending_events();
                }
            }
            break;
#endif /* __MMI_SML_MENU__ */

        case MMI_TYPE_PERSONALIZATION_KEY:
            /* Not used by L4 */
            PRINT_INFORMATION("MMI_TYPE_PERSONALIZATION_KEY");
            break;

        case MMI_TYPE_UNSPECIFIED:
            /* Not a response from L4 needed by mmi to set PIN */
            PRINT_INFORMATION("MMI_TYPE_UNSPECIFIED");
            break;

        default:
            PRINT_INFORMATION("Unhandled enum type in SimPasswdReqResponse");
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SimQueryFailureRsp
 * DESCRIPTION
 *  This is called as a call back when MMI_SMU_FAIL_IND is received from the L4
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SimQueryFailureRsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMISMUFAILIND *local_data = (MMISMUFAILIND*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if((!g_pwr_context.PowerOnAnimationComplete) */
    if (mmi_bootup_is_power_on_animation_complete() == MMI_FALSE
#if defined(__FS_CHECKDRIVE_SUPPORT__)
        || (SanityCheckDone == 0) || (SanityCheckDone == 3)
#endif 
        )
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_RECV_SIM_FAIL);
        /* g_pwr_context.SimQueryFailIndFlag=1; */
        g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;       /* 0x01: Invalid SIM */
    #ifdef __MMI_DUAL_SIM_MASTER__
        /* set the card1 status to work */
        MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_ABSENT);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        if (local_data->cause != MMI_SIM_REFRESH)
        {
            g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_FAILURE_RSP;       /* 0x10: SIM failure rsp */
        }
        if (mmi_bootup_is_power_on_animation_complete() == MMI_FALSE)
        {
            /* nand check first then receive this message */
            g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_ANIMATION_SIM_FAIL;       /* 0x06: Power on animation with SIM failure indication */
        }
        memcpy(&gSMUFailIndStruct, local_data, sizeof(MMISMUFAILIND));

        return; /* postpone this indication after power on animation completes */
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_PROC_SIM_FAIL);

    /* Notify BT not to init bt ps stack and hw */
    mmi_bootup_sim_indication_bt_power_on(0, local_data->cause);

    //g_pwr_context.SimQueryFailIndFlag=0;
    //g_pwr_context.PowerOnPeriod=0;
    if (local_data->cause != MMI_SIM_REFRESH)
    {
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
        g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
    }

    StopLEDPatternPowerOn();

    /* g_pwr_context.IsSimValid = 0; */
    g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;   /* 0x01: Invalid SIM */
#ifdef __MMI_DUAL_SIM_MASTER__
    /* rearrange the menu item */
    MTPNP_PFAL_Rearrange_MenuItem();
    /* rearrange the status bar on idle screen */
    MTPNP_PFAL_Rearrange_StatusBar();
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /* g_pwr_context.PowerOnTillIdleApp=0; */
    ClearKeyEvents();
    FirstTimeTurnOnBackLight();

    mmi_idle_notify_bootup_ready_to_l4c();

    switch (local_data->cause)
    {
        case MMI_SIM_CARD_REMOVED:
            PRINT_INFORMATION("MMI_SIM_CARD_REMOVED");
            /* if(g_pwr_context.SimRemoveFlag==0) */
	     if (mmi_bootup_is_sim_removed() == MMI_FALSE)
            {
	#ifdef __MMI_DUAL_SIM_MASTER__
                /* set the card1 status to absent */
                MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_ABSENT);
                /* set the network to limit service */
                MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
                /* set network register status to register failed */
                MTPNP_AD_Set_Card1NetStatus(MTPNP_AD_NW_STATUS_REGISTER_FAILED);

                /* rearrange the menu item */
                MTPNP_PFAL_Rearrange_MenuItem();
                /* rearrange the status bar on idle screen */
	            MTPNP_PFAL_Rearrange_StatusBar();
	#endif /* __MMI_DUAL_SIM_MASTER__ */	
                /* g_pwr_context.SimRemoveFlag=1; */
                g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_NOT_INSERT;    /* 0x02: SIM removed */
                simErrorDisplayString = STR_SIM_INSERTION_MSG;
                InitSimErrorScreen();
            }
            break;

        case MMI_SIM_ACCESS_ERROR:
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            /* case 12 with SIM1 access error */
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD && MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
            {
                mmi_bootup_dual_sim_power_on();
            }
    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
	#ifdef __MMI_DUAL_SIM_MASTER__
            /* set the card1 status to absent */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_ABSENT);
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
            /* set network register status to register failed */
            MTPNP_AD_Set_Card1NetStatus(MTPNP_AD_NW_STATUS_REGISTER_FAILED);

            /* rearrange the menu item */
            MTPNP_PFAL_Rearrange_MenuItem();
            /* rearrange the status bar on idle screen */
            MTPNP_PFAL_Rearrange_StatusBar();
	#endif /* __MMI_DUAL_SIM_MASTER__ */		 
            PRINT_INFORMATION("MMI_SIM_ACCESS_ERROR");
            simErrorDisplayString = STR_SIM_ACCESS_ERROR_MSG;
            InitSimErrorScreen();
            break;

        case MMI_SIM_CMD_SUCCESS:
            PRINT_INFORMATION("MMI_SIM_CMD_SUCCESS");
            break;

        case MMI_SIM_CMD_FAIL:
	#ifdef __MMI_DUAL_SIM_MASTER__
            g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_NOT_INSERT;    /* 0x02: SIM removed */
            /* set the card1 status to absent */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_ABSENT);
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
            /* set network register status to register failed */
            MTPNP_AD_Set_Card1NetStatus(MTPNP_AD_NW_STATUS_REGISTER_FAILED);

            /* rearrange the menu item */
            MTPNP_PFAL_Rearrange_MenuItem();
            /* rearrange the status bar on idle screen */
            MTPNP_PFAL_Rearrange_StatusBar();
	#endif /* __MMI_DUAL_SIM_MASTER__ */				 
            PRINT_INFORMATION("MMI_SIM_CMD_FAIL");
            /* g_pwr_context.SimRemoveFlag=1; */
            g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_NOT_INSERT;        /* 0x02: SIM removed */
            simErrorDisplayString = STR_SIM_INSERTION_MSG;
            InitSimErrorScreen();
            break;

        case MMI_SIM_FATAL_ERROR:
	#ifdef __MMI_DUAL_SIM_MASTER__
            /* set the card1 status to absent */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_ABSENT);
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
            /* set network register status to register failed */
            MTPNP_AD_Set_Card1NetStatus(MTPNP_AD_NW_STATUS_REGISTER_FAILED);

            /* rearrange the menu item */
            MTPNP_PFAL_Rearrange_MenuItem();
            /* rearrange the status bar on idle screen */
            MTPNP_PFAL_Rearrange_StatusBar();
	#endif /* __MMI_DUAL_SIM_MASTER__ */		
            PRINT_INFORMATION("MMI_SIM_FATAL_ERROR");
            simErrorDisplayString = STR_SIM_ACCESS_ERROR_MSG;
            InitSimErrorScreen();
            break;

        case MMI_SIM_NO_INSERTED:
            PRINT_INFORMATION("MMI_SIM_NO_INSERTED");
    #ifdef __MMI_DUAL_SIM_MASTER__
	    #ifdef __MMI_SML_NP_ONLY__
            mmi_sml_power_on_query_req();
        #endif 
            g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_NOT_INSERT;    /* 0x02: SIM removed */
            /* set the card1 status to absent */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_ABSENT);
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
            /* set network register status to register failed */
            MTPNP_AD_Set_Card1NetStatus(MTPNP_AD_NW_STATUS_REGISTER_FAILED);

            /* rearrange the menu item */
            MTPNP_PFAL_Rearrange_MenuItem();
            /* rearrange the status bar on idle screen */
            MTPNP_PFAL_Rearrange_StatusBar();
	#endif /* __MMI_DUAL_SIM_MASTER__ */		 
            /* g_pwr_context.SimRemoveFlag=1; */
            g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_NOT_INSERT;        /* 0x02: SIM removed */
            simErrorDisplayString = STR_SIM_INSERTION_MSG;
            InitSimErrorScreen();
            break;

        case MMI_SIM_CHV_NOT_INIT:
            PRINT_INFORMATION("MMI_SIM_CHV_NOT_INIT");
            break;

        case MMI_SIM_CHV_RETRY_ALLOW:
            PRINT_INFORMATION("MMI_SIM_CHV_RETRY_ALLOW");
            break;

        case MMI_SIM_CHV_BLOCK:
            PRINT_INFORMATION("MMI_SIM_CHV_BLOCK");
            break;

        case MMI_SIM_ACCESS_NOT_ALLOW:
            PRINT_INFORMATION("MMI_SIM_ACCESS_NOT_ALLOW");
            break;

        case MMI_SIM_SAT_CMD_BUSY:
            PRINT_INFORMATION("MMI_SIM_SAT_CMD_BUSY");
            break;

        case MMI_SIM_DL_ERROR:
            PRINT_INFORMATION("MMI_SIM_DL_ERROR");
            break;

        case MMI_SIM_MEMORY_PROBLEM:
            PRINT_INFORMATION("MMI_SIM_MEMORY_PROBLEM");
            break;

        case MMI_SIM_TECHNICAL_PROBLEM:
            PRINT_INFORMATION("MMI_SIM_TECHNICAL_PROBLEM");
            break;

        case MMI_SIM_REFRESH:
            /* gSIMRefresh = 1; */
            g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_REFRESH;           /* 0x04 SIM refresh */
            break;

#ifdef __MMI_SIMAP_SUPPORT__
        case MMI_SIM_BT_ACCESS_PROFILE_ON:
            if (!mmi_bootup_get_active_bt_access_profile_mode())
            {
                g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_BT_ACCESS;     /* 0x40 BT SIM access profile */
                g_pwr_context.CurrentServiceType = LIMITED_SERVICE;             /* prevent from no following network attachment indication  */
                g_idle_context.SimReady = MMI_FALSE;

            #ifdef __MMI_DUAL_SIM_MASTER__
		/* set the network to limit service */
		MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
            #endif /* __MMI_DUAL_SIM_MASTER__ */

                mmi_sim_error_update_sim_access_profile_menu_items();

                if (isInCall())
                {
                    DeleteBeyondScrTillScr(GetCmMarkerScrnID(), IDLE_SCREEN_ID);
                    mmi_frm_add_history_before_cm_marker(IDLE_SCREEN_ID, EntryIdleScreen);
                }
                else
                {
                    EntryIdleScreen();
                }
            }
            break;

        case MMI_SIM_BT_ACCESS_PROFILE_OFF:
            if (mmi_bootup_get_active_bt_access_profile_mode())
            {
                g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_INVALID;       /* 0x02: SIM removed reset */
            	g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_BT_ACCESS;     /* 0x40 BT SIM access profile */

            #ifdef __MMI_DUAL_SIM_MASTER__
                /* set the card1 status to work */
                MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_VALID);
                /* rearrange the menu item */
                MTPNP_PFAL_Rearrange_MenuItem();
                /* rearrange the status bar on idle screen */
                MTPNP_PFAL_Rearrange_StatusBar();
            #endif  /* __MMI_DUAL_SIM_MASTER__ */
        
                mmi_sim_error_restore_sim_access_profile_menu_items();

                if (isInCall())
                {
                    DeleteBeyondScrTillScr(GetCmMarkerScrnID(), IDLE_SCREEN_ID);
                    mmi_frm_add_history_before_cm_marker(IDLE_SCREEN_ID, EntryIdleScreen);
                }
                else
                {
                    EntryIdleScreen();
                }
            }
            break;
#endif /* __MMI_SIMAP_SUPPORT__ */

        default:
            PRINT_INFORMATION("Invalid cause from SIM FAIL error");
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectPin
 * DESCRIPTION
 *  Flash message incorrect PIN try again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectPin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    DisplayPopup((U8*) GetString(STRING_MTPNP_WRONG_CARD1_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
#else
    DisplayPopup((U8*) GetString(STR_INCORRECT_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectPhoneLock
 * DESCRIPTION
 *  Flash message incorrect phonelock try again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((U8*) GetString(STR_INCORRECT_PHONELOCK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectPUK
 * DESCRIPTION
 *  Flash message incorrect PUK try again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectPUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    DisplayPopup((U8*) GetString(STRING_MTPNP_INCORRECT_CARD1_PUK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
#else
    DisplayPopup((U8*) GetString(STR_INCORRECT_PUK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
#endif
    DeleteUptoScrID(SCR_ENTER_PUK);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrPinBlocked
 * DESCRIPTION
 *  Flash message PIN is blocked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrPinBlocked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_POP_UP_HISTORY, ExitScrPinBlocked, NULL, NULL);
    GenericExitScreen(SCR_ENTER_PUK, EntryScrEnterPUK);
#ifdef __MMI_DUAL_SIM_MASTER__
    ShowCategory123Screen(0, 0, 0, 0, 0, 0, STRING_MTPNP_SIM1_PIN_BLOCKED, IMG_GLOBAL_WARNING, NULL);
#else
    ShowCategory123Screen(0, 0, 0, 0, 0, 0, STR_PIN_BLOCKED_PUK, IMG_GLOBAL_WARNING, NULL);
#endif
    playRequestedTone(WARNING_TONE);
    StartTimer(CODE_VERIFIED_TIMER, CODE_VERIFIED_TIMEOUT, GoBackHistory);
    SetGroupKeyHandler(GoBackHistory, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrPinBlocked
 * DESCRIPTION
 *  Exit function for PIN blocked screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrPinBlocked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    StopTimer(CODE_VERIFIED_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrCodeVerified
 * DESCRIPTION
 *  PopUp when code is verified
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrCodeVerified(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((U8*) GetString(STR_CODE_VERIFIED), IMG_GLOBAL_ACTIVATED, 0, 2000, (U8) SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ENTER_PIN);
    DeleteScreenIfPresent(SCR_ENTER_PUK);
    DeleteScreenIfPresent(SCR_ENTER_NEW_PIN);
    DeleteScreenIfPresent(SCR_ENTER_CONFIRM_PIN);
    DeleteScreenIfPresent(SCR_ENTER_NP);
    DeleteScreenIfPresent(SCR_ENTER_NSP);
    DeleteScreenIfPresent(SCR_ENTER_CP);
    DeleteScreenIfPresent(SCR_ENTER_SP);
    DeleteScreenIfPresent(SCR_ENTER_SIMP);
#ifdef __MMI_SML_MENU__
    DeleteScreenIfPresent(SCR_ENTER_NS_SP);
    DeleteScreenIfPresent(SCR_ENTER_SIM_C);
#endif /* __MMI_SML_MENU__ */

    if (isInCall())
    {
        /* input PIN1 screen + incoming call + code accepted screen */
        mmi_frm_add_history_before_cm_marker(GLOBAL_SCR_DUMMY, mmi_bootup_exit_security_check);
    }
    else
    {
        /* input PIN1 screen + unfinished code accepted screen + incoming call */
        GenericExitScreen(GLOBAL_SCR_DUMMY, mmi_bootup_exit_security_check);
    }
}


/**************************************************************************
   SSC APIs:
      void SSCHandleEnterPUK(void)
      void ExitSSCHandleEnterPUK(void)
      void ValidateSSCStringPUK(void)
      void MakeCallSSCStringPUK(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  SSCHandleEnterPUK
 * DESCRIPTION
 *  Input PUK by SSC string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleEnterPUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) == 0)
    {
        SSCHandleEnterPUKCommon();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleEnterPUKCommon
 * DESCRIPTION
 *  Input PUK by SSC string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleEnterPUKCommon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SSC_ENTER_PUK, ExitSSCHandleEnterPUK, NULL, NULL);
    GetkeyInfo(&Keycode, &Keytype);
    if (mmi_ucs2strlen(g_idle_context.DialPadCallBuffer) == 0)
    {
        g_idle_context.IdleScreenDigitKeyCode = Keycode;
    }

    history_buffer = GetCurrGuiBuffer(SCR_SSC_ENTER_PUK);

#if ( defined (__MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) && !defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__))
    if (mmi_bootup_get_active_flight_mode() != 1)
    {
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    }
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) && !defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)) */ 

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
    SetDialingKeypadPhonebookHandler(NULL);
#endif

    ShowCategory16Screen(
        0,
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

    SetKeyHandler(ValidateSSCStringPUK, KEY_POUND, KEY_EVENT_UP);
    SetCategory16RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  SSCHandleEnterPUKFromSecset1
 * DESCRIPTION
 *  Input PUK by SSC string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleEnterPUKFromSecset1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.NewPassword) == 0)
    {
        SSCHandleEnterPUKCommon();
    }
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  SSCHandleEnterPUKFromSecset2
 * DESCRIPTION
 *  Input PUK by SSC string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleEnterPUKFromSecset2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern MTPNP_CHAR g_slave_inputpwdbuffer[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
    if (mmi_ucs2strlen((S8*) g_slave_inputpwdbuffer) == 0)
    {
        SSCHandleEnterPUKCommon();
    }
}

#endif


/*****************************************************************************
 * FUNCTION
 *  ExitSSCHandleEnterPUK
 * DESCRIPTION
 *  Exit function for SSC screen from PUK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSSCHandleEnterPUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitScreen(SCR_SSC_ENTER_PUK, SSCHandleEnterPUK);
    g_idle_context.IdleScreenDigitKeyCode = -1;
}


/*****************************************************************************
 * FUNCTION
 *  ValidateSSCStringPUK
 * DESCRIPTION
 *  Validate is it a valid SSC for puk screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateSSCStringPUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SSCStringParsing3())
    {
        DisplayPopup((U8*) GetString(STR_INCORRECT_SSC), IMG_GLOBAL_WARNING, 0, 2000, (U8) ERROR_TONE);
        mmi_ssc_delete_sim_operation_screens();
    }
}


/*****************************************************************************
 * FUNCTION
 *  MakeCallSSCStringPUK
 * DESCRIPTION
 *  Make call for PUK screen SSC
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeCallSSCStringPUK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MakeCall(g_idle_context.DialPadCallBuffer);
}

/**************************************************************************
   NAND sanity check APIs:
      void PWR_NAND_SanityCheck_Popup(void)
      void PWR_NAND_SanityCheck_response_handler(void)
      void PWR_NAND_SanityCheck_skip_check(void)
      void PWR_NAND_SanityCheck_proceed_check(void)
      void PWR_NAND_SanityCheckDisplay_Exit(void)
      void PWR_NAND_SanityCheckDisplay(void)
**************************************************************************/
#ifdef __FS_CHECKDRIVE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  PWR_NAND_SanityCheck_Popup
 * DESCRIPTION
 *  NAND check popup for done
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern pBOOL isInCall(void);
extern void mmi_pwron_entry_animation_screen(void);

static void PWR_NAND_SanityCheck_Popup(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        2000,
        (U8) SUCCESS_TONE);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SanityCheckDone = 2;
    DeleteScreenIfPresent(SCR_NAND_FLASH_CHECK);
    DeleteScreenIfPresent(SCR_NAND_CHECK_PROCESSING);
    DeleteScreenIfPresent(SCR_CHARGER_POPUP);

    /* Aviod no history to go back */
    if (!IsScreenPresent(SCR_OPEN_SCREEN_ID))
    {
        if (isInCall())
        {
            mmi_frm_add_history_before_cm_marker(SCR_OPEN_SCREEN_ID, mmi_pwron_entry_animation_screen);
        }
        else
        {
            GenericExitScreen(SCR_OPEN_SCREEN_ID, mmi_pwron_entry_animation_screen);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  PWR_NAND_SanityCheck_skip_check
 * DESCRIPTION
 *  Skip NAND check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PWR_NAND_SanityCheck_skip_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SanityCheckDone = 1; /* Exit category 165 screen shall be called by another entry new screen */
    mmi_bootup_exit_nand_check_query();
}


/*****************************************************************************
 * FUNCTION
 *  PWR_NAND_SanityCheck_proceed_check
 * DESCRIPTION
 *  Proceed NAND check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PWR_NAND_SanityCheck_proceed_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    mmi_fmt_check_drive_req_strcut *req =
        (mmi_fmt_check_drive_req_strcut*) OslConstructDataPtr(sizeof(mmi_fmt_check_drive_req_strcut));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SanityCheckDone == 1)
    {
        /* this is a race condition that the user press No when the counter remains 1 */
       return;
    }

    EntryNewScreen(SCR_NAND_CHECK_PROCESSING, NULL, PWR_NAND_SanityCheck_proceed_check, NULL);

#ifdef __MMI_FILE_MANAGER__
    req->drive = MMI_PUBLIC_DRV;
#endif 
    if (SanityCheckDone != 3)
    {
        SanityCheckDone = 3;    /* processing */
        /* Send message to FMT */
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_FMT;
        Message.oslMsgId = MSG_ID_MMI_FMT_CHECK_DRIVE_REQ;
        Message.oslDataPtr = (oslParaType*) req;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        SetProtocolEventHandler(PWR_NAND_SanityCheck_Popup, PRT_MMI_FMGR_CHECK_DRIVE_RSP);
    }

    ShowCategory66Screen(
        STR_NAND_CHECK_TITLE,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_NAND_CHECK_PROCESSING),
        IMG_GLOBAL_PROGRESS,
        NULL);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  PWR_NAND_SanityCheckDisplay_Exit
 * DESCRIPTION
 *  Exit NAND check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PWR_NAND_SanityCheckDisplay_Exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    restore_small_screen();
#endif

    stopRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  PWR_NAND_SanityCheckDisplay
 * DESCRIPTION
 *  Display NAND check operation screen
 *  Pressing End key will come back here except during a call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCat165TimerExpireFunc(FuncPtr f);
static void PWR_NAND_SanityCheckDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_NAND_FLASH_CHECK);

    /* Some application might be performed during NAND check */
    /* if the user press end key, here will be the root entry function */
    if (GetActiveScreenId() != SCR_NAND_FLASH_CHECK)    /* root and only nand check screen */
    {
        if (SanityCheckDone == 0)
        {
            EntryNewScreen(SCR_NAND_FLASH_CHECK, PWR_NAND_SanityCheckDisplay_Exit, PWR_NAND_SanityCheckDisplay, NULL);

        #ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
            force_no_small_screen();
        #endif

            ShowCategory165Screen_ext(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_NAND_CHECK),
                IMG_GLOBAL_QUESTION,
                10,
                guiBuffer);

            SetCat165TimerExpireFunc(PWR_NAND_SanityCheck_proceed_check);

            playRequestedTone(WARNING_TONE);
            StopLEDPatternPowerOn();

            ShowIdleAppSubLcd();

            SetKeyHandler(PWR_NAND_SanityCheck_skip_check, KEY_END, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(PWR_NAND_SanityCheck_proceed_check, KEY_EVENT_UP);
            SetRightSoftkeyFunction(PWR_NAND_SanityCheck_skip_check, KEY_EVENT_UP);
        }
        else
        {
            /* skip or done or processing */
            mmi_bootup_exit_low_battery_warning();  /* a little strange... */
        }
    }
}

#endif /* __FS_CHECKDRIVE_SUPPORT__ */ 

/**************************************************************************
   Welcome screen APIs:
      void ShowWelcomeScr(void)
      void ExitWelcomeScreen(void)
      void ShowAphorismScr(void)
      void ExitAphorismScreen(void)
      S8* GetAphorismScrText(void)
      void BeforeEntryIdleScr(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowWelcomeScr
 * DESCRIPTION
 *  Show welcome screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowWelcomeScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *WelcomeString = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_START_WELCOME);

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_WELCOME;  /* 0x20: Welcome screen */

    if (IsShowWelcomeScr1())
    {
        EntryNewScreen(WELCOME_SCREEN_ID, ExitWelcomeScreen, ShowWelcomeScr, NULL);
        DeleteScreenIfPresent(GLOBAL_SCR_DUMMY);

        WelcomeString = GetWelcomeText();

        StartTimer(WELCOME_SCR_TIMER, WELCOME_SCR_TIME, mmi_bootup_exit_welcome_screen);

        ShowCategory61Screen((U8*) WelcomeString, IMG_WELCOME_SCR, NULL);
        OslMfree(WelcomeString);

        /* diamond, 2005/12/22 Not allow to press END key to prevent from going back to power on animation */
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        mmi_bootup_exit_welcome_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitWelcomeScreen
 * DESCRIPTION
 *  Exit welcome screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitWelcomeScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_STOP_WELCOME);
    StopTimer(WELCOME_SCR_TIMER);
}

#if defined(__MMI_APHORISM__)
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
#endif /* defined(__MMI_APHORISM__) */ // #if defined(__MMI_APHORISM__)


/*****************************************************************************
 * FUNCTION
 *  BeforeEntryIdleScr
 * DESCRIPTION
 *  Function to be called before entry into idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BeforeEntryIdleScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (  g_pwr_context.InvalidSim && !g_pwr_context.InvalidSimShowed) */
    if (mmi_bootup_is_nw_registration_ok() == MMI_FALSE && !g_pwr_context.InvalidSimShowed)
    {
        g_pwr_context.InvalidSimShowed = 1;
        DisplayInvalidSimInfo();

        DinitHistory(); /* do not go back to power on animation */
        ExitIdleScreen();

        if (g_charbat_context.isChargerConnected)
        {
            StartTimer(BOOTUP_CHARGER_DETECT_TIMER, 3000, ChargerDetectTimeoutHdlr);
        }
    }
    else
    {
        if (isEarphonePlugged)  /* MTK add, Robin 1015 for earphone indication comming before power on indication */
        {
#ifdef __CTM_SUPPORT__
            mmi_ctm_switch_tty_status(MMI_TRUE);
            if (mmi_ctm_is_tty_on())
            {
            	 /* TTY in, hide earphone icon */
#if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
                IdleResetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
#endif
                mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
                SetModeSpeechVolume();
                mmi_profiles_headset_deactivate_profile();
            }
            else /* not TTY, it's earphone */
#endif /* __CTM_SUPPORT__ */ 
            {
            SetModeSpeechVolume();
            mmi_profiles_headset_activate_profile();
            }
        }
        else if (gactivatedprofile == MMI_PROFILE_HEADSET)
        {
            mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
            SetModeSpeechVolume();
            mmi_profiles_headset_deactivate_profile();
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        mmi_idle_entry_dual_sim_root_screen();
    #else
        EntryIdleScreen();
    #endif
    }
}

/**************************************************************************
   Abnormal reset APIs:
      U8 GetAbnormalReset(void)
      void SetAbnormalReset(void)
      void ResetAbnormalReset(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  GetAbnormalReset
 * DESCRIPTION
 *  Get the status of abnormal reset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetAbnormalReset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_pwr_context.AbnormalReset;
}


/*****************************************************************************
 * FUNCTION
 *  SetAbnormalReset
 * DESCRIPTION
 *  Set the status of abnormal reset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetAbnormalReset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pwr_context.AbnormalReset = 1;
    g_pwr_context.IsCampOnTonePlayed = 1;
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_LOW_BATTERY;  /* 0x08: Power on animation complete */
#ifdef __MMI_DUAL_SIM_MASTER__
    g_pwr_context_2.IsCampOnTonePlayed = 1;
    g_pwr_context_2.PowerOnMMIStatus = MMI_POWER_ON_LOW_BATTERY;
#endif
    SanityCheckDone = 2;    /* diamond, 2005/12/18 NAND check should be "done" in abnormal reset */
}


/*****************************************************************************
 * FUNCTION
 *  ResetAbnormalReset
 * DESCRIPTION
 *  Reset the status of abnormal reset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetAbnormalReset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pwr_context.AbnormalReset = 0;
}

/**************************************************************************
   Other APIs:
      void ServiceIndicationStringDisplay(void *inMsg)
      void mmi_ready_to_idle_screen_ind_hdlr(void* msg)
      void mmi_ready_to_idle_screen_ind(void)
      void mmi_idle_notify_bootup_ready_to_l4c(void)
      void DisplayInvalidSimInfo(void)
      void RemoveStatusIconsForSimRemoved(void)
      void FirstTimeTurnOnBackLight(void)
      void PowerOnBatteryIndicationCompletePhase2(void)
      void PowerOnBatteryIndicationComplete(void)
      void CallBackPowerOnAnimationComplete(GDI_RESULT ret)
      void ExitLowBatteryScrAtPowerOn(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ServiceIndicationStringDisplay
 * DESCRIPTION
 *  This function is a call back for MSG_ID_MMI_CPHS_MMI_INFO_IND
 *  It will be passed to CPHSMMInfoInd first
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ServiceIndicationStringDisplay(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_mmi_info_ind_struct *local_data = (mmi_cphs_mmi_info_ind_struct*) inMsg;
    U8 i = 0, len = 0;
    PS8 pString;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gOpNameValid = local_data->is_opname_valid;
    gShortOpnameValid = local_data->is_sopname_valid;
    gSpnValid = local_data->is_spn_valid;

    /* not to display RPLMN if SPN say so */
    if (gSpnValid == 1)
    {
        g_pwr_context.RequireRPLMN = local_data->is_spn_RPLMN_required;
    }

    if (gOpNameValid)
    {
        mmi_asc_to_ucs2(gOperatorName, (S8*) local_data->opname);
    }

    if (gShortOpnameValid)
    {
        mmi_asc_to_ucs2(gShortOperatorName, (S8*) local_data->sopname);
    }

    if (gSpnValid)
    {
        if (local_data->spn[0] >= 0x80) /* diamond, 2005/08/03 support SPN with UCS2 from SIM */
        {
            U8 *convertedData = NULL;
            U8 dcs;

            switch (local_data->spn[0])
            {
                case 0x80:
                    dcs = MMI_UCS2_DCS;
                    break;
                case 0x81:
                    dcs = MMI_UCS2_81;
                    break;
                case 0x82:
                    dcs = MMI_UCS2_82;
                    break;
                default:
                    dcs = 0;
                    break;
            }
            if (dcs == 0)
            {
                gSpnValid = 0;
            }
            else
            {
                convertedData = CovertStringForPlatform(
                                    local_data->spn + 1,
                                    (U16) (strlen((PS8) (local_data->spn + 1))),
                                    dcs,
                                    NULL);
                mmi_ucs2cpy((PS8) gServProvderName, (PS8) convertedData);
                OslMfree(convertedData);
            }
        }
        else
        {
            mmi_asc_to_ucs2(gServProvderName, (S8*) local_data->spn);
        }
    }

    /* Owner Number */
    memset((void*)&gDispOwnerNumber, 0, sizeof(gDispOwnerNumber));
    if (local_data->no_msisdn > 0)
    {
        for (i = 0; ((i < MAX_LINE_NUM) && (i < local_data->no_msisdn)); i++)
        {
            if (local_data->msisdn[i].alpha_id_size != 0)
            {
                len =
                    (((local_data->msisdn[i].alpha_id_size) >
                      MAX_PB_NAME_LENGTH) ? MAX_PB_NAME_LENGTH : (local_data->msisdn[i].alpha_id_size));
                InputboxConvertGSMToDeviceEncoding(
                    local_data->msisdn[i].alpha_id,
                    gDispOwnerNumber[i].name,
                    len,
                    (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
                    local_data->msisdn[i].alpha_id_dcs,
                    0,
                    1);
            }

            if ((strlen((S8*) local_data->msisdn[i].digit) != 0) ||
                (local_data->msisdn[i].ton_npi != 0xFF && ((local_data->msisdn[i].ton_npi) & 0x10) != 0))
            {
                /* Prevent PS error. Watch out!! should sync with l4csmu_addr_struct */
                local_data->msisdn[i].digit[MAX_PB_NUMBER_LENGTH] = 0x0;
                local_data->msisdn[i].digit[MAX_PB_NUMBER_LENGTH - 1] = 0x0;
                if (((local_data->msisdn[i].ton_npi) & 0x10) != 0)
                {
                    len = MAX_PB_NUMBER_LENGTH;
                    gDispOwnerNumber[i].number[0] = '+';
                    pString = (PS8) gDispOwnerNumber[i].number + ENCODING_LENGTH;
                }
                else
                {
                    len = MAX_PB_NUMBER_LENGTH + 1;
                    pString = (PS8) gDispOwnerNumber[i].number;
                }

                mmi_asc_n_to_ucs2((PS8) pString, (S8*) local_data->msisdn[i].digit, len);
            }
        }
    }

    RefreshDisplayOwnerNumber((U8) g_callset_context.LineID);   /* in LineSwitching.c */

    if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
    {
        IdleRefreshServiceIndicationArea();
        idle_screen_show_network_details(); /* EntryIdleScreen(); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ready_to_idle_screen_ind_hdlr
 * DESCRIPTION
 *  Ready go to idle handler
 *  We use this message to enter idle screen, this is used to solve NVRAM/timer interlace problem
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ready_to_idle_screen_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* there might be an very critail timing issue here */

    /*
     * (PS. set Tab=3 to view the following diagram correctly)
     * 
     * (1) =======================================================
     * 
     * [Sim ready, send SIM_READY_IND to MMI]
     * 
     * 
     * PS         ------------------------------------------------
     * 
     * (SIM ready)
     * SIM        ----------*-------------------------------------
     * | SIM_RDY_IND
     * v
     * PWRON HDLR ------------------------------------------------
     * 
     * 
     * MT SCREEN  ------------------------------------------------
     * 
     * 
     * [MSG Queue: (1)SIM_RDY_INC]
     * 
     * ===========================================================
     * 
     * 
     * (2) =======================================================
     * 
     * [Before SIM_RDY_IND arrive MMI, MT Call happened]
     * (MT Call)
     * PS         ------------*-----------------------------------
     * | MT_CALL_IND
     * |
     * SIM        ----------*-|-----------------------------------
     * | |
     * v |
     * PWRON HDLR ------------|-----------------------------------
     * |                                    
     * v                                    
     * MT SCREEN  ------------------------------------------------ 
     * 
     * 
     * [MSG Queue: (1)SIM_RDY_INC, (2) MT_CALL_IND]
     * ===========================================================
     * 
     * 
     * (3) =======================================================
     * 
     * [Then we will process SIM_RDY_INC, it will call this function 
     * to send MMI_RDT_TO_IDLE_SCR_IND to it self]
     * 
     * 
     * (MT Call)
     * PS         ------------*-----------------------------------
     * | MT_CALL_IND
     * |
     * SIM        ----------*-|-----------------------------------
     * | |
     * | |
     * PWRON HDLR ----------#-|-----------------------------------
     * |                                    
     * v
     * MT SCREEN  ------------------------------------------------ 
     * 
     * 
     * [MSG Queue: (1) MT_CALL_IND (2) MMI_RDT_TO_IDLE_SCR_IND ]
     * ===========================================================
     * 
     * (4) Then will proceed MT_CALL_IND first, it will enter MT call screen.
     * (5) But it will follow up by proceeding MMI_RDT_TO_IDLE_SCR_IND, it 
     * will force to enter idle screen. So the MT call screen will gone..
     * 
     * [Soultion]
     * We have to check if it is already in MT call screen. If yes, we do not send 
     * MSG_ID_MMI_READY_TO_IDLE_SCREEN_IND.
     * 
     */

    /* 
     * the reason to send out this message, it to solve NVRAM/Timer interleaving problem 
     * while powering on.
     */

#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_idle_context.IsOnSimErrorScreen == 1)
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (isInCall())
    {
        /* is in call, after call end, call management will lead to idle screen */
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_CALL_BEFORE_IDLE);
        return;
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_READY_TO_IDLE);

    ClearProtocolEventHandler(MSG_ID_MMI_READY_TO_IDLE_SCREEN_IND);
    goto_opening_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ready_to_idle_screen_ind
 * DESCRIPTION
 *  Send message to MMI itself for ready to idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ready_to_idle_screen_ind(void) /* this function is call by MMI */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_SEND_MSG_2_MMI);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_READY_TO_IDLE_SCREEN_IND;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    SetProtocolEventHandler(mmi_ready_to_idle_screen_ind_hdlr, MSG_ID_MMI_READY_TO_IDLE_SCREEN_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_bootup_ready_to_l4c
 * DESCRIPTION
 *  Send message to L4C to notify idle screen reached
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_bootup_ready_to_l4c(void)  /* this function is call by MMI */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL l4c_ready_sent = MMI_FALSE;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (l4c_ready_sent)
    {
        return;
    }

    l4c_ready_sent = MMI_TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_READY_NOTIFY_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  DisplayInvalidSimInfo
 * DESCRIPTION
 *  Display invalid SIM info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayInvalidSimInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_INVALID_SIM_INFO, NULL, DisplayInvalidSimInfo, NULL);

    ShowCategory2Screen(
        STR_SIM_INVALID_SIM_TITLE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        STR_SIM_INVALID_SIM_TXT,
        NULL);

    if (gSecuritySetupContext.PINBlocked || IsScreenPresent(IDLE_SCREEN_ID))
    {
        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(EntryIdleScreen, KEY_EVENT_UP);
    }

    /* end the network searching screen */
    g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
}


/*****************************************************************************
 * FUNCTION
 *  RemoveStatusIconsForSimRemoved
 * DESCRIPTION
 *  Remove invalid status icon when sim is removed or blocked in running condition
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RemoveStatusIconsForSimRemoved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_REMOVE_ICONS);

    HideStatusIcon(STATUS_ICON_ROAMING);
    HideStatusIcon(STATUS_ICON_CALL_DIVERT_L1L2);
#ifdef __MMI_CFU_SEPARATE_LINE__
    HideStatusIcon(STATUS_ICON_CALL_DIVERT_L1);
    HideStatusIcon(STATUS_ICON_CALL_DIVERT_L2);
#endif /* __MMI_CFU_SEPARATE_LINE__ */ 
    HideStatusIcon(STATUS_ICON_INCOMING_SMS);
#ifndef __MMI_TOUCH_SCREEN__
    HideStatusIcon(STATUS_ICON_KEYPAD_LOCK);
#endif 

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY || mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        HideStatusIcon(STATUS_ICON_MISSED_CALL);
#ifdef __MMI_DUAL_SIM_MASTER__
        HideStatusIcon(STATUS_ICON_CARD2MISSED_CALL);
#endif
#ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
        HideStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
#endif 
    }

    HideStatusIcon(STATUS_ICON_UNREAD_VOICE_L1L2);
    HideStatusIcon(STATUS_ICON_UNREAD_VOICE_L1);
    HideStatusIcon(STATUS_ICON_UNREAD_VOICE_L2);
    HideStatusIcon(STATUS_ICON_UNREAD_FAX_L1L2);
    HideStatusIcon(STATUS_ICON_UNREAD_FAX_L1);
    HideStatusIcon(STATUS_ICON_UNREAD_FAX_L2);

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY || mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL_L1L2);
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL_L1);
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL_L2);
    }

    HideStatusIcon(STATUS_ICON_SUBLCD_SMS);
    HideStatusIcon(STATUS_ICON_MMS_UNREAD);
    HideStatusIcon(STATUS_ICON_MMS_BUSY);
#ifndef __MMI_DUAL_SIM_MASTER__
    HideStatusIcon(STATUS_ICON_CHAT_INDICATION_ROOM1);
    HideStatusIcon(STATUS_ICON_CHAT_INDICATION_ROOM2);
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (MTPNP_PFAL_Is_Card1Absent() && MTPNP_PFAL_Is_Card2Absent())
    {
        HideStatusIcon(STATUS_ICON_CHAT_INDICATION_ROOM1);
        HideStatusIcon(STATUS_ICON_CHAT_INDICATION_ROOM2);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY || mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        HideStatusIcon(STATUS_ICON_WAP);
    }

    HideStatusIcon(STATUS_ICON_NETWORK_CIPHER_GSM);
    HideStatusIcon(STATUS_ICON_NETWORK_CIPHER_GPRS);

#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
#ifndef __MMI_DUAL_SIM_MASTER__
    ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH);
#else /* __MMI_DUAL_SIM_MASTER__ */
    switch (MTPNP_AD_Get_Status())
    {
    case MTPNP_AD_DUALCARD:
	ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
	ChangeStatusIconImage(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
	break;
    case MTPNP_AD_CARD1:
	ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
	ChangeStatusIconImage(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
	break;
     case MTPNP_AD_CARD2:
	ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
	ChangeStatusIconImage(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH); 
	break;
     case MTPNP_AD_FLIGHT:
	ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
	ChangeStatusIconImage(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
	break;
    default:
	break;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
#else /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
    HideStatusIcon(STATUS_ICON_ALTERNATE_LINE_L1);
    HideStatusIcon(STATUS_ICON_ALTERNATE_LINE_L2);
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 

#ifdef __MMI_POC__
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY || mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        HideStatusIcon(STATUS_ICON_POC);
    }
#endif 

#ifndef __MMI_BT_MTK_SUPPORT__
#ifdef __MMI_BT_SUPPORT__
    HideStatusIcon(STATUS_ICON_BT);
    HideStatusIcon(STATUS_ICON_BT_CON);
    HideStatusIcon(STATUS_ICON_BT_ND);
#endif /* __MMI_BT_SUPPORT__ */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */ 

#ifdef __MMI_IMPS__
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY || mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        HideStatusIcon(STATUS_ICON_IMPS_MSG);
        HideStatusIcon(STATUS_ICON_IMPS_LOGIN);
    }
#endif /* __MMI_IMPS__ */ 

    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  FirstTimeTurnOnBackLight
 * DESCRIPTION
 *  Enter this function once after maui is finished to turn on backlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FirstTimeTurnOnBackLight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 FirstTime = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!FirstTime)
    {
        FirstTime = 1;
        TurnOffBacklight();

        if (isEarphonePlugged)  /* for earphone indication comming before power on indication */
        {
            mmi_profiles_headset_activate_profile();
            SetModeSpeechVolume();
        }
    }
    else
    {
        TurnOnBacklight(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PowerOnBatteryIndicationCompletePhase2
 * DESCRIPTION
 *  Start to process SimQueryFailureRsp or SimPasswdReqResponse
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PowerOnBatteryIndicationCompletePhase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_SetDiskFlag();

    if (mmi_bootup_is_sim_failure_received() == MMI_TRUE)   /* if(g_pwr_context.SimQueryFailIndFlag) */
    {
    #ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
        SimQueryFailureRsp(&gSMUFailIndStruct);
    #else
        MTPNP_PFAL_SIM2_QueryFailureRsp(&gSMUFailIndStruct);
    #endif
    }
    else if (mmi_bootup_is_sim_need_security_check() == MMI_TRUE)       /* else if(g_pwr_context.PasswdReqIndFlag) */
    {
    #ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
        SimPasswdReqResponse(&gSMUPwdDataStruct);
    #else
        MTPNP_PFAL_SIM2_PasswdReqResponse(&gSMUPwdDataStruct);
    #endif
    }
    else if (mmi_bootup_is_sim_valid() == MMI_TRUE)
    {
        goto_opening_screen();
    }
    /* else */
    /* diamond, 2006/04/17 Re-entry power on animation */
}


/*****************************************************************************
 * FUNCTION
 *  PowerOnBatteryIndicationComplete
 * DESCRIPTION
 *  Function to be called after power on animatin is completed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PowerOnBatteryIndicationComplete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_pwr_context.PowerOnAnimationComplete=1; */
    if (mmi_bootup_is_in_security_check() != MMI_TRUE)
    {
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_NAND_CHECK;       /* 0x09: NAND check screen */
    }

#ifdef __FS_CHECKDRIVE_SUPPORT__
    if (FS_CheckDiskFlag() && g_pwr_context.NandIdCheckRes && SanityCheckDone != 2)
    {
        if ((SanityCheckDone == 0) || (SanityCheckDone == 3))
        {
            if (IsScreenPresent(SCR_NAND_CHECK_PROCESSING))
            {
                GoBackToHistory(SCR_NAND_CHECK_PROCESSING);
            }
            else if (IsScreenPresent(SCR_NAND_FLASH_CHECK))
            {
                GoBackToHistory(SCR_NAND_FLASH_CHECK);
            }
            else
            {
                PWR_NAND_SanityCheckDisplay();
            }
            return; /* wait for PRT_MMI_FMGR_CHECK_DRIVE_RSP */
        }
    }
    else
    {
        SanityCheckDone = 2;
    }
#endif /* __FS_CHECKDRIVE_SUPPORT__ */ 
    mmi_bootup_exit_nand_check_query();
}


/*****************************************************************************
 * FUNCTION
 *  BatteryCheckAfterPowerOnAnimation
 * DESCRIPTION
 *  Battrey status check function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BatteryCheckAfterPowerOnAnimation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Low battery warning */
    if (g_charbat_context.chargerLevel == BATTERY_LOW_TX_PROHIBIT ||
        g_charbat_context.chargerLevel == BATTERY_LOW_WARNING)
    {
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_LOW_BATTERY;      /* 0x08: Power on animation complete */
        EntryNewScreen(SCR_CHARGER_POPUP, ExitLowBatteryScrAtPowerOn, NULL, NULL);
        ClearKeyEvents();
        ShowCategory64Screen(STR_LOW_BATTERY, IMG_GLOBAL_WARNING, 0);
        /* StartTimer(LOW_BATTERY_SCR_TIMER,LOW_BATTERY_SCR_TIMEOUT, PowerOnBatteryIndicationComplete ); */
        StartTimer(LOW_BATTERY_SCR_TIMER, LOW_BATTERY_SCR_TIMEOUT, mmi_bootup_exit_low_battery_warning);

    }
    else
    {
        mmi_bootup_exit_low_battery_warning();
    }
}


#if defined(DOUBLE_BATTERY_SUPPORT)
 //Huyanwei Add It For Battery Level
 #include "NVRAMProt.h"
 kal_uint32 g_adc_value= 0;
 kal_uint16 g_adc_value_high = 0;
 kal_uint16 g_adc_value_low  = 0;
 #endif

/*****************************************************************************
 * FUNCTION
 *  CallBackPowerOnAnimationComplete
 * DESCRIPTION
 *  Callback function when power on animation is completed
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CallBackPowerOnAnimationComplete(GDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    extern pBOOL AUTO_POWER;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* power on sequence after animation: */
    /* animation stop -> CallBackPowerOnAnimationComplete -> PowerOnBatteryIndicationComplete -> */
    /* (nand check) -> PowerOnBatteryIndicationCompletePhase2 -> (security check) */

#if defined(DOUBLE_BATTERY_SUPPORT)
	//Huyanwei Add it 
	S16 ErrCode = 0 ;
	ReadRecord(NVRAM_ADC_LID, 1, (void *)&g_adc_value, NVRAM_ADC_SIZE, &ErrCode);
	g_adc_value_high =(g_adc_value & 0xFFFF0000 )>> 16 ;
	g_adc_value_low  =(g_adc_value & 0x0000FFFF ) ;
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r g_adc_value_high = %d , g_adc_value_low= %d\n",g_adc_value_high,g_adc_value_low);
#endif
#endif	

    /* Low battery shutdown */
    if (((g_charbat_context.batteryStatus == PMIC_VBAT_STATUS || g_charbat_context.batteryStatus == PMIC_CHARGER_OUT) && g_charbat_context.isChargerConnected == 0)     /* Battery Status */
        && (g_charbat_context.chargerLevel == BATTERY_LOW_POWEROFF) /* Battery Level */ )
    {
    	#if defined(DOUBLE_BATTERY_SUPPORT)
	//Huyanwei Add It 		
	#ifndef WIN32
	if( 1 == IsBatteryLow() )
	#endif		
	#endif	
       {
        ShowLowPowerShutdownScr();
        return;
       }
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_sim2_power_on_animation_complete())
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (ret < 0 || ret == GDI_IMAGE_IS_STILL_IMAGE)
    {
    #ifdef __MMI_TOUCH_SCREEN__
    #ifndef __MTK_TARGET__
        if (PhnsetNeedFactoryDefaultCalibration() && !AUTO_POWER) /* skip pen calibration for MoDIS auto power on test */
    #else
        if (PhnsetNeedFactoryDefaultCalibration())
    #endif
		{
            /* Although we have not reached idle screen, but it still sends MSG_ID_MMI_READY_NOTIFY_REQ to L4
               to allow ATD command in the first-time boot after flash download. */
        #ifdef __MTK_TARGET__
            mmi_idle_notify_bootup_ready_to_l4c();
        #endif
            EntryPhnseFactoryDefaultCalibrationScr(mmi_bootup_exit_low_battery_warning);
        }
        else
        {
            /* Broken animation image - force enter */
            mmi_bootup_exit_low_battery_warning();
        }
    #else /* __MMI_TOUCH_SCREEN__ */
        /* Broken animation image - force enter */
        mmi_bootup_exit_low_battery_warning();
    #endif /* __MMI_TOUCH_SCREEN__ */
        return;
    }

    /* SIM ready/fail indication has been arrival */
    /* if( g_pwr_context.PasswdReqIndFlag || g_pwr_context.SimQueryFailIndFlag ) */
    if (g_pwr_context.PowerOnMMIStatus > 0x04)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        /* 
         * Pen calibration is invoked between power-on animation and mmi_bootup_exit_animation()
         *
         * 1. On production line, LCD might not be connected and it's impossible to complete pen calibration.
         *    However, we may need to use ATD command to test RF hardware. If we invoke pen calibration 
         *    before poweron animation, network is not ready at the time and ATD command never succeeds, 
         *    it causes problem in hardware testing.
         * 
         * 2. If we invoke pen calibration at idle screen, we cannot use pen to input PIN code, etc.
         *
         * As a result, pen calibration is invoked immediately after power-on animation.
         */
    #ifndef __MTK_TARGET__
        if (PhnsetNeedFactoryDefaultCalibration() && !AUTO_POWER) /* skip pen calibration for MoDIS auto power on test */
    #else
        if (PhnsetNeedFactoryDefaultCalibration())
    #endif
        {
            /* Although we have not reached idle screen, but it still sends MSG_ID_MMI_READY_NOTIFY_REQ to L4
               to allow ATD command in the first-time boot after flash download. */
        #ifdef __MTK_TARGET__
            mmi_idle_notify_bootup_ready_to_l4c();
        #endif
             EntryPhnseFactoryDefaultCalibrationScr(mmi_bootup_exit_animation);
             
        }
        else
        {
            mmi_bootup_exit_animation();
        }
    #else /* __MMI_TOUCH_SCREEN__ */
        mmi_bootup_exit_animation();
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitLowBatteryScrAtPowerOn
 * DESCRIPTION
 *  Exit Low battery screen when it appears just after power on animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitLowBatteryScrAtPowerOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitScreen(SCR_CHARGER_POPUP, mmi_bootup_exit_low_battery_warning);
    StopTimer(LOW_BATTERY_SCR_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrInvalidPINPUKPLOCKLength
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrInvalidPINPUKPLOCKLength(void) /* referred by personalization.c */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_INVALID_PINPUKPLOCK_LENGTH_RUNNING_TEXT),
        IMG_GLOBAL_WARNING,
        0,
        ST_NOTIFYDURATION,
        (U8) ERROR_TONE);
}

/**************************************************************************
   Insert SIM keypad lock APIs:
      void InsertSimRSKPressOnScreenSaver(void)
      void InsertSimSetKeyPadLockFlag(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  InsertSimRSKPressOnScreenSaver
 * DESCRIPTION
 *  Handle RSK pressed in keypad locked insert SIM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InsertSimRSKPressOnScreenSaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsRSKPressOnScreenSaver = 1;
    if (IsScreenPresent(SCR_SIM_BLOCK) || GetActiveScreenId() == SCR_SIM_BLOCK)
    {
        EntryScrnSimBlockRsp();
    }
    else
    {
        EntryScrnSimErrorScreen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  InsertSimSetKeyPadLockFlag
 * DESCRIPTION
 *  Timeout to lock keypad in insert SIM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InsertSimSetKeyPadLockFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_keylock_context.gKeyPadLockFlag = 1;

#if 0   /* diamond, 2006/03/07 Not necessary to block pen here because pen is blocked in EntryIdleScreen */
	#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
	#endif
#endif /* 0 */ 

#ifdef __MMI_KEYPADLOCK_WITH_KEYTONE__

#else 
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
#endif 

    if (IsScreenPresent(SCR_SIM_BLOCK) || GetActiveScreenId() == SCR_SIM_BLOCK)
    {
        EntryScrnSimBlockRsp();
    }
    else
    {
        EntryScrnSimErrorScreen();
    }

#ifdef __MMI_TOUCH_SCREEN__
    SetKeyHandler(InsertSimRSKPressOnScreenSaver, KEY_SEND, KEY_EVENT_DOWN);
#else /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
    SetRightSoftkeyFunction(InsertSimRSKPressOnScreenSaver, KEY_EVENT_DOWN);
#endif 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
    SetLeftSoftkeyFunction(InsertSimRSKPressOnScreenSaver, KEY_EVENT_DOWN);
#endif 
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_TOUCH_SCREEN__
    ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK);
    UpdateStatusIcons();
#else /* __MMI_TOUCH_SCREEN__ */ 
    IdleSetStatusIcon(STATUS_ICON_KEYPAD_LOCK);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
}


#ifdef __MMI_SIMAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_update_sim_access_profile_menu_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_error_update_sim_access_profile_menu_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_NITZ__
    mmi_frm_hide_menu_item(MENU9145_SETTIMEANDDATENITZ); /* Hide "Auto update of date and time" in SAP screen */
    mmi_frm_hide_menu_item(MENU_SETTING_MENU_TREE);
#endif /* __MMI_NITZ__ */ 
    mmi_frm_hide_menu_item(MENU9169_SIM_LOCK);           /* Hide "SIM Lock" in SAP screen */
    mmi_frm_hide_menu_item(MENU9167_FIXED_DIAL);         /* Hide "Fixed Dial" in SAP screen */
    mmi_frm_hide_menu_item(MENU9168_BARRED_DAIL);        /* Hide "Barred Dail" in SAP screen */
    mmi_frm_hide_menu_item(MENU9174_CP_PIN1);            /* Hide "Change Password/PIN1" in SAP screen */
    mmi_frm_hide_menu_item(MENU9175_CP_PIN2);            /* Hide "Change Password/PIN2" in SAP screen */
    mmi_frm_hide_menu_item(MENU_SETTING_SPEED_DIAL);     /* Hide "Speed Dial" in No SIM screen */
#ifdef __MMI_WLAN_FEATURES__
    mmi_frm_hide_menu_item(MENU9186_SELECTION_MODE);
    mmi_frm_hide_menu_item(MENU9189_GPRS_CONNECTION_MODE);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */
#else /* __MMI_WLAN_FEATURES__ */
    mmi_frm_hide_menu_item(MENU9185_NETWORK_SETUP);      /* Hide "Network Setup" in SAP screen */
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)
#endif
    {
        mmi_frm_hide_menu_item(MESSAGES_MENU_SMS_MENUID);      /* SMS */
        mmi_frm_hide_menu_item(MESSAGES_MENU_MMS_MENUID);      /* MMS */
        mmi_frm_hide_menu_item(MENU_CHATAPP_ID);               /* Chat */
        mmi_frm_hide_menu_item(MESSAGES_MENU_VMAIL_MENUID);    /* Voice Mail */
        mmi_frm_hide_menu_item(MESSAGES_MENU_CB_MENUID);       /* Cell Broadcast */
        mmi_frm_hide_menu_item(MENU_ID_UM_MAIN);               /* Unified Message */

        mmi_frm_hide_menu_item(MENU_CALL_TIME_SETUP);          /* Call Time */
        mmi_frm_hide_menu_item(MENU_CALL_HISTORY_CALLCOST);    /* Call Cost */
        mmi_frm_hide_menu_item(MENU_CALL_HISTORY_SMSCOUNTER);  /* SMS Counter */
        mmi_frm_hide_menu_item(MENU_CALL_HISTORY_GPRSCOUNTER); /* GPRS Counter */

        mmi_frm_hide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_MAIN);
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_SETTING);

        mmi_frm_hide_menu_item(MENU9186_SELECTION_MODE);
        mmi_frm_hide_menu_item(MENU9189_GPRS_CONNECTION_MODE);
    #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */
    }

    PhnsetFlightModeSaveStatusIconFlags(MMI_FALSE);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_restore_sim_access_profile_menu_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_error_restore_sim_access_profile_menu_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_NITZ__
    mmi_frm_unhide_menu_item(MENU9145_SETTIMEANDDATENITZ); /* Hide "Auto update of date and time" in SAP screen */
    mmi_frm_unhide_menu_item(MENU_SETTING_MENU_TREE);
#endif /* __MMI_NITZ__ */ 
    mmi_frm_unhide_menu_item(MENU9169_SIM_LOCK);           /* Hide "SIM Lock" in SAP screen */
    mmi_frm_unhide_menu_item(MENU9167_FIXED_DIAL);         /* Hide "Fixed Dial" in SAP screen */
    mmi_frm_unhide_menu_item(MENU9168_BARRED_DAIL);        /* Hide "Barred Dail" in SAP screen */
    mmi_frm_unhide_menu_item(MENU9174_CP_PIN1);            /* Hide "Change Password/PIN1" in SAP screen */
    mmi_frm_unhide_menu_item(MENU9175_CP_PIN2);            /* Hide "Change Password/PIN2" in SAP screen */
    mmi_frm_unhide_menu_item(MENU_SETTING_SPEED_DIAL);     /* Hide "Speed Dial" in SAP screen */
#ifdef __MMI_WLAN_FEATURES__
    mmi_frm_unhide_menu_item(MENU9186_SELECTION_MODE);
    mmi_frm_unhide_menu_item(MENU9189_GPRS_CONNECTION_MODE);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */
#else /* __MMI_WLAN_FEATURES__ */
    mmi_frm_unhide_menu_item(MENU9185_NETWORK_SETUP);      /* Hide "Network Setup" in SAP screen */
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)
#endif
    {
        mmi_frm_unhide_menu_item(MESSAGES_MENU_SMS_MENUID);      /* SMS */
        mmi_frm_unhide_menu_item(MESSAGES_MENU_MMS_MENUID);      /* MMS */
        mmi_frm_unhide_menu_item(MENU_CHATAPP_ID);               /* Chat */
        mmi_frm_unhide_menu_item(MESSAGES_MENU_VMAIL_MENUID);    /* Voice Mail */
        mmi_frm_unhide_menu_item(MESSAGES_MENU_CB_MENUID);       /* Cell Broadcast */
        mmi_frm_unhide_menu_item(MENU_ID_UM_MAIN);               /* Unified Message */

        mmi_frm_unhide_menu_item(MENU_CALL_TIME_SETUP);          /* Call Time */
        mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_CALLCOST);    /* Call Cost */
        mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_SMSCOUNTER);  /* SMS Counter */
        mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_GPRSCOUNTER); /* GPRS Counter */

        mmi_frm_unhide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_MAIN);
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_SETTING);

        mmi_frm_unhide_menu_item(MENU9186_SELECTION_MODE);
        mmi_frm_unhide_menu_item(MENU9189_GPRS_CONNECTION_MODE);
    #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */
    }

    PhnsetFlightModeRestoreStatusIconFlags(MMI_FALSE);
    UpdateStatusIcons();
}

#endif /* __MMI_SIMAP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_idle_toggle_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_error_idle_toggle_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STARKEY_TOGGLE_PROFILE__
    if (mmi_ucs2strlen(g_idle_context.DialPadCallBuffer) == 1 && mmi_ucs2ncmp(g_idle_context.DialPadCallBuffer, (S8*) L"*", 1) == 0)
#else
    if (mmi_ucs2strlen(g_idle_context.DialPadCallBuffer) == 1 && mmi_ucs2ncmp(g_idle_context.DialPadCallBuffer, (S8*) L"#", 1) == 0)
#endif
    {
        IdleToggleProfile();
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_notify_bootup_ready_to_wap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_error_notify_bootup_ready_to_wap(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_MMI_READY_NOTIFY_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* WAP_SUPPORT */
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sim_error_set_emergency_call_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_error_set_emergency_call_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    E_MTPNP_AD_CHANNELS call_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(MTPNP_AD_Get_Startup_Mode())
    {
        case MTPNP_AD_NVRAM_CARD1:
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
        break;

        case MTPNP_AD_NVRAM_CARD2:
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
        break;

        case MTPNP_AD_NVRAM_DUALCARD:
            if (MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
            {
                /* case 11 */
                if (mmi_bootup_is_in_security_check() || mmi_bootup_is_in_sim2_security_check())
                {
                    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
                }
                else
                {
                    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
                }
            }
            else
            {
                //MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
                call_channel = MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL);
                MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, (call_channel == MTPNP_AD_CHANNEL_NONE) ? MTPNP_AD_CHANNEL_DEFAULT_MASTER : call_channel);
            }
        break;
    }
}
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */


void mmi_sim_error_reset_input_password_guibuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ENTER_PHONELOCK ||
        GetActiveScreenId() == SCR_ENTER_PIN ||
        GetActiveScreenId() == SCR_ENTER_PUK ||
        GetActiveScreenId() == SCR_ENTER_CONFIRM_PIN)
    {
        EntryNewScreen(SCR_ID_PASSWORD_INPUT_DUMMY, NULL, NULL, NULL);

        if (GetHistoryScrID(SCR_ENTER_PHONELOCK, &History) == ST_SUCCESS ||
            GetHistoryScrID(SCR_ENTER_PIN, &History) == ST_SUCCESS ||
            GetHistoryScrID(SCR_ENTER_PUK, &History) == ST_SUCCESS)
        {
            if (History->guiBuffer != NULL)
            {
                memset(History->guiBuffer, 0, ENCODING_LENGTH);
            }
        }
    }
}

