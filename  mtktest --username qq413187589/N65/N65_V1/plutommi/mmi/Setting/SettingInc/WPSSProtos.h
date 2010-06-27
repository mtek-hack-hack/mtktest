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
 *  WPSSProtos.h
 *
 * Project:
 * --------
 *  MAUI
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef WPSSRPROTOS_H
#define WPSSRPROTOS_H

#include "WallpaperDefs.h"
#include "DownloadDefs.h"
#include "PhoneSetup.h"
#include "mmi_phnset_dispchar.h"
/*
 * Screen Saver
 */
extern void HighlightPhnsetScreenSaver(void);
extern void EntryPhnsetScrSvr(void);
extern void EntryPhnsetScrSvrSettings(void);
extern void EntryPhnsetScrSvrSelect(void);
extern void EntryPhnsetScrSvrSystem(void);
extern void EntryPhnsetScrSvrDwnl(void);
extern void EntryPhnsetScrSvrFmgr(void);
extern void EntryPhnsetScrSvrSysView(void);
extern void PhnsetScrSvrSysViewLskHdlr(void);
extern PS8 PhnsetGetCurScrSvrFileName(void);

extern void ExitPhnsetScrSvrSettings(void);
extern void ExitPhnsetScrSvrSysView(void);
extern void ExitScrSetScreenSaver(void);

extern void SetScreenSaverLSK(S32);
extern void SetScreenSaverSelectLSK(S32);
extern void PhnsetScrSvrSysHiliteHdlr(S32);
extern void PhnsetDwnlScrSvrHiliteHdlr(S32);
extern U8 PhnsetConstDwnlScrSvrList(U8 **Names, U16 *DLSSImgID, S16 *HligtItem);
extern U8 PhnsetConstSysScrSvrList(U8 **pSysSSStrList, U16 *pSysSSImgIDList, S16 *HighliteItem);

extern void ScreenSaverKeyPressHandler(void);
extern void PhnsetScrSvrInlineHiliteHdlr(S32 nIndex);
extern void PhnsetScrSvrFillInline(InlineItem *);
extern void PhnsetScrSvrSettingLskHdlr(void);
extern void PhnsetRstScrSvrDefault(void);
extern void PhnsetGetScrSvrSetings(U8 *, U8 *);
extern void PhnsetGetCurScrSvr(U16 *);
extern void PhnsetReadNvramScrSvrSettings(void);
extern void ssDecrementCounter(void);
extern void ssIncrementCounter(void);
extern void setScreenSaverPopupTimeout(void);
extern void DeleteScreenSaverViewHistory(void);
extern PS8 PhnsetGetCurScrSvrName(void);
extern PS8 PhnsetGetScrSvrNameById(U16);
extern void viewScreenSaver(void);
extern SET_SS_SETTING_STATUS PhnsetGetCurScrSvrStatus(void);
extern void PhnsetScrSvrSysViewPre(void);
extern void PhnsetScrSvrSysViewNext(void);
extern void UpdateDeletedImageScreenSaver(U16);
extern BOOL PhnsetIsScrSvrAnalogClock(void);
extern BOOL PhnsetIsScrSvrDigitalClock(void);
extern BOOL PhnsetIsScrSvrPartialOn(void);
extern BOOL PhnsetIsScrSvrCurrentTheme(void);
extern BOOL PhnsetIsWPCurrentTheme(void);
extern void EntryPhnsetScrSvrDwnlView(void);
extern void PhnsetScrSvrDwnlViewLskHdlr(void);
extern void ExitPhnsetScrSvrDwnlView(void);
extern void PhnsetScrSvrDwnlViewNext(void);
extern void PhnsetScrSvrDwnlViewPre(void);

extern void InitScreenSaver(void);
extern void HintPhnsetScrSvrSetting(U16 index);
extern void HintPhnsetScrSvrSelect(U16 index);
extern void HighlightPhnsetScrSvrSetting(void);
extern void HighlightPhnsetScrSvrSelect(void);
extern void HighlightPhnsetScrSvrSystem(void);
extern void HighlightPhnsetScrSvrDwnl(void);
extern void HighlightPhnsetScrSvrFmgr(void);
extern S32 PhnsetScreenSaverBadFileCallBack(void);
extern void PhnsetScrSvrSelectFmgrCallBack(void *path, int is_short);
extern void PhnsetSetScrSvrByFileName(S8 *path);


/*
 * Wallpaper
 */
extern void HighlightPhnsetMainWallpaper(void);

#ifdef __MMI_AVATAR__
extern void mmi_phnset_avatar_entry(void);
#endif

#ifdef __MMI_SUB_WALLPAPER__
extern void HighlightPhnsetSubWallpaper(void);
#endif 
extern void HighlightPhnsetWallpaper(void);

#ifdef __DAILY_WALLPAPER__
extern void HighlightPhnsetWallpaperFix(void);
extern void HintPhnsetWallpaperRotate(U16 index);
extern BOOL PhnsetGetWallpaperRotateStatus(void);
extern void EntryPhnsetWallpaperFixRotate(void);
extern U8 PhnsetGetCurWallPaperIdx(void);
#else /* __DAILY_WALLPAPER__ */ 
extern U16 PhnsetGetCurWallPaperIdx(void);
#endif /* __DAILY_WALLPAPER__ */ 
extern void EntryPhnsetWallpaperSel(void);
extern void ExitScrWallpaperSelect(void);
extern void EntryPhnsetWallpaperSys(void);
extern void EntryPhnsetWallpaperFmgr(void);
extern void PhnsetWallpaperSysHiliteHandler(S32 nIndex);
extern void EntryPhnsetWallpaperSysView(void);
extern void PhnsetWallpaperSysViewPre(void);
extern void PhnsetWallpaperSysViewNext(void);
extern void ExitPhnsetWallpaperSysView(void);
extern void PhnsetWallpaperSet(void);
extern void ThemeManagerSetWallpaper(U16);
extern void ThemeManagerSetScreensaver(U16);
extern void EntryPhnsetWallpaperDwnl(void);
extern void ExitWallpaperDownload(void);
extern void PhnsetWallpaperDwnlHiliteHandler(S32 nIndex);
extern void EntryPhnsetWallpaperDwnlView(void);
extern void PhnsetWallpaperDwnlViewPre(void);
extern void PhnsetWallpaperDwnlViewNext(void);
extern void ExitPhnsetWallpaperDwnlView(void);
extern void PhnsetWallpaperDwnlSet(void);
extern void PhnsetRstWallpaperDefault(void);
extern void PhnsetRstSubWallpaperDefault(void);
extern void PhnsetReadWallpaper(void);
extern PS8 PhnsetGetCurWallpaperName(void);

#ifdef __MMI_SUB_WALLPAPER__
extern PS8 PhnsetGetCurSubWallpaperName(void);
#endif 
extern PS8 PhnsetGetWallpaperNameById(U16 Id);
extern void UpdateDeletedImageWallpaper(U16 ImageId);
extern void InitWallpaper(void);
extern void HighlightPhnsetWallpaperSys(void);
extern void HighlightPhnsetWallpaperDwnl(void);
extern void HighlightPhnsetWallpaperFmgr(void);
extern void PhnsetWallpaperSelectFmgrCallBack(void *path, int is_short);
extern void PhnsetWallpaperBadFileCallBack(U16 imgID);
extern void PhnsetWallpaperSubBadFileCallBack(U16 imgID);

extern void PhnsetSetWallpaperByImgID(U16 imgID);
extern void PhnsetSetWallpaperByFileName(S8 *path);
extern BOOL PhnsetSetDisplayFromAT(U8 idx, U8 type);
extern U8 PhnsetGetWallpaperIdxBound(void);
extern PS8 PhnsetGetFileNamePointer(PS8 path);
extern void EntryPhnsetWallpaperFmgr(void);
extern void PhnsetWpUsrDefFreeBuf(void);

extern void PhnsetWpSsPlayCallBack(S32 result);
extern void PhnsetWpUsrDefPreViewENDKeyHdlr(void);

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
extern void PhnsetReadPwrOnOffDisp(void);
extern void HighlightPhnsetPowerOn(void);
extern void HighlightPhnsetPowerOff(void);
extern void HighlightPhnsetPwrOnFmgr(void);
extern void HighlightPhnsetPwrOffFmgr(void);
extern void HighlightPhnsetPowerOnSys(void);
extern void HighlightPhnsetPowerOffSys(void);
extern void HintPhnsetPwrOnDisplay(U16 index);
extern void HintPhnsetPwrOffDisplay(U16 index);
extern void EntryPhnsetPowerOnOffSel(void);
extern void EntryPhnsetPowerOnOffSys(void);
extern void EntryPhnsetPwrOnOffSysView(void);
extern void PhnsetPwrOnOffSysViewPre(void);
extern void PhnsetPwrOnOffSysViewNext(void);
extern void PhnsetPowerOnOffSysHiliteHandler(S32 nIndex);
extern void PhnsetGetPwrOnDisp(U16 *id);
extern PS8 PhnsetGetPwrOnFileName(void);
extern void PhnsetGetPwrOffDisp(U16 *id);
extern PS8 PhnsetGetPwrOffFileName(void);
extern void PhnsetRstPwrOnDisplayDefault(void);
extern void PhnsetRstPwrOffDisplayDefault(void);
extern U16 PhnsetGetPwrOnDisplayDefault(void);
extern U16 PhnsetGetPwrOffDisplayDefault(void);
extern void PhnsetPwrOnOffPlayCallBack(S32 result);
extern void PhnsetPwrOnOffBadDisplayPopup(PS8 error_str);
extern void PhnsetSetPwrOnOffDisplay(void);
extern void PhnsetSetPwrOnOffDisplayByImgID(U16 imgID);
extern void PhnsetSetPwrOnOffDisplayByFileName(S8 *path);
extern void PhnsetPwrOnOffSelectFmgrCallBack(void *path, int is_short);
extern U8 PhnsetConstSysPwrOnOffList(U8 **pSysPwrOnOffStrList, U16 *pSysPwrOnOffImgIDList, S16 *HighliteItem);

#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

#ifdef __USB_IN_NORMAL_MODE__
extern void PhnsetWPUseDefault(void);
extern void PhnsetSSUseDefault(void);

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
extern void PhnsetPwrOnOffUseDefault(void);
#endif 
#endif /* __USB_IN_NORMAL_MODE__ */ 

#endif /* WPSSRPROTOS_H */ /* WPSSPROTOS_H */

