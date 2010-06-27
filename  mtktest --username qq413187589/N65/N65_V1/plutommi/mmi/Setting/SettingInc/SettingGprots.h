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
 * SettingGprots.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : setting_gprot.h

   PURPOSE     : Settings application global function prototypes

   REMARKS     : nil

   AUTHOR      : Vanita Jain

   DATE     : 

**************************************************************/

#ifndef _PIXCOM_SETTINGGPROTS_H
#define _PIXCOM_SETTINGGPROTS_H
#include "SettingGenum.h"
#include "MMI_features.h"

extern void InitSettingApp(void);

/* micha0530 */
extern void EntryScrSettingMenu(void);
extern MMI_BOOL AutoRedialOnOffStatus(void);
extern U8 CallTimeReminderStatus(void);
extern SETTING_AKPL_TIME GetAutoKeypadLockTime(void);
extern U8 GetPhoneLock(void);
extern MMI_BOOL IsShowWelcomeScr1(void);
extern S8 *GetWelcomeText(void);
extern MMI_BOOL IsShowAphorismScr1(void);
extern MMI_BOOL GetCallTimeDisplay(void);
extern MMI_BOOL PhnsetGetNITZFuncStatus(void);
extern void SettingChangePasswdPuk(void);
extern MMI_BOOL PhnsetGetShowOwnerNumStatus(void);

/* Lisen 0921-1 */
#if defined(__MMI_OPERATOR_NAME_MENU__)
extern MMI_BOOL PhnsetGetShowOPNStatus(void);
#endif 
extern MMI_BOOL PhnsetGetShowDateTimeStatus(void);
extern MMI_BOOL SetLanguage(U8 *);
extern MMI_BOOL PhnsetSetDTFromAT(MYTIME mytime);
extern S16 PhnsetSetTimeFormat(U8 timeformat);
extern S16 PhnsetSetDateFormat(U8 dateformat);
extern BOOL ATSetHomeCity(U8 CityIndex);
extern void Highlight_ScreenSaver_Menu(void);
extern void GetSettingOptionsStatus(void);
extern SETTING_CTR GetCtrStatus(void);
extern U16 GetCtrTime(void);
extern MMI_BOOL PhnsetSetWelcomeText(MMI_BOOL mode, U8 dcs, U8 *text, U8 length);
extern void PhnsetGetWelcomeText(S8 *buf, U16 buf_len);
extern void InitSettingBootup(void);
extern void InitSettingNVRAM(void);
extern void RstrSettingPasswdScrSoftKeyFunc(U8 *text, U8 *cursor, S32 length);
extern pBOOL SET_DefaultDateFormat(void);
extern pBOOL SET_DefaultTimeFormat(void);
extern void GoToAddEditScreen(void);
extern void PhbUpdateSpeedDial(U8, U16, U8, PU8, PU8);
extern void PhbDeleteAllSpeedDial(U8 storage, U8 type);
extern MMI_BOOL PhbRestoreSpeedDial(void);
extern void SettingInlineCustomFunction(void);
extern void GetDateTimeSetupNvRam(void);
extern void PhnsetReadNvmHomeCityIdxNStoreCityName(void);
extern void PhnsetReinitHomeCity(void);
extern void PhnsetSendSetTimeReqMessage(void);
extern U8 PhnsetGetFontSize(void);

extern void InitSecuritySetupApp(void);
extern void SECSETVerifyPINRsp(void *info);
extern void SECSETGetPIN2StatusReq(void);
extern void SECSETChangePasswordPIN1Rsp(void *info);
extern void SECSETChangePasswordPIN2Rsp(void *info);

extern MMI_BOOL mmi_secset_is_in_puk_check(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern MMI_BOOL mmi_secset_is_in_sim2_puk_check(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#endif

extern MMI_BOOL mmi_phnset_check_themeid_wallpaper(U16 imgID);

#endif /* _PIXCOM_SETTINGGPROTS_H */ 

