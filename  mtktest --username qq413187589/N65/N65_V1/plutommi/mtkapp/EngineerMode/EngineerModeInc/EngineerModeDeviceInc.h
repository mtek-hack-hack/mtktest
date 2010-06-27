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
 * EngineerModeDeviceInc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode device port interface 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _ENGINEER_MODE_DEVICE_H
#define _ENGINEER_MODE_DEVICE_H

/* MTK Add Robin 1001 for saperate MMI feature by project */
#include "MMI_features.h"
/* MTK End */

#ifdef __MMI_ENGINEER_MODE__    /* MTK Add Robin 1001 for saperate MMI feature by project */

#include "MMIDataType.h"

/* ===== Defination ============ */
#define EM_HW_LEVEL_ACT_GET 0
#define EM_HW_LEVEL_ACT_SET 1

#define SET_GPIO_ACTION  0
#define SET_GPO_ACTION  1

/* ===== Type Define ============ */
typedef struct _LCDSET
{
    CUSTOM_EM_LCD_TYPE Type;
    CUSTOM_EM_LCD_FUNC_TYPE Func;
    U8 Count;
    U8 ParamBuf[8];
    custom_em_lcd_param_set_struct Param;
} LCDSET;

typedef struct _PWMSET
{
    U8 Count;
    CUSTOM_EM_PWM_TYPE Type;
    custom_em_pwm_param_set_struct Param;
} PWMSET;

/* ===== Function Declaration ============ */
extern void EntryEmLCDMenu(void);
extern void HighlightEmLCD(void);

extern void HighlightEmLCDSub(void);
extern void EntryEmLCDSubMenu(void);

extern void HighlightEmLCDMain(void);
extern void EntryEmLCDMainMenu(void);

extern void LSKEmLCDSetLCDHandler(void);
extern void EntryEmLCDSetLCDNextParam(void);

extern void HighlightEmLCDSetContrast(void);
extern void EntryEmLCDSetContrast(void);

extern void HighlightEmLCDSetBias(void);
extern void EntryEmLCDSetBias(void);

extern void HighlightEmLCDSetLineRate(void);
extern void EntryEmLCDSetLineRate(void);

extern void HighlightEmLCDSetTemperature(void);
extern void EnrtyEmLCDSetTemperature(void);

extern void ExitEmLCDInlineScreen(void);
extern void HighlightEmLCDSetColor(void);
extern void EnrtyEmLCDSetColor(void);
extern void EMLCMSetColorSendReq(void);
extern MMI_BOOL EMLCMSetColorCheckParameter(void);
extern void EMLCDSetColor(U8 red, U8 green, U8 blue);
extern void EMLcdDisplayDemoPicSelected(void *path, int is_short);
extern void EMLcdDisplayDemoPicScr(void);
extern void EMLcdDisplayDemoPic(void);
extern void HighlightEmLCDDiplayDemoPic(void);
extern void EnrtyEmLCDDisplayDemoPic(void);
extern void EMLCDSetColorExit(void);
extern void EMLCDDisplayDemoPicExit(void);

extern void HighlightEmGPIO(void);
extern void EntryEmGPIOMenu(void);

#ifdef CAMERA_MODULE
extern void HighlightEmExtCamera(void);
extern void EntryEmExtCameraMenu(void);

extern void HighlightEmExtCameraWrite(void);
extern void EntryEmExtCameraWriteMenu(void);
extern void ExitEmExtCameraWriteMenu(void);

extern void HighlightEmExtCameraRead(void);
extern void EntryEmExtCameraReadMenu(void);
extern void ExitEmExtCameraReadMenu(void);

#endif /* CAMERA_MODULE */ 

extern void HighlightEmGPIOList(void);
extern void EntryEmGPIOListMenu(void);
extern void LSKEmGPIOListMenu(void);

extern void HighlightEmGPIOSet(void);
extern void HighlightEmGPOSet(void);
extern void EntryEmGPIOSet(void);
extern void LSKEmGPIOSetCertain(void);

extern void ExitEMGPIODetail(void);
extern void EMGPIOHighlightHandler(S32 index);
extern void EMGPIODoneFunc(void);
extern void EntryEMGPIODetail(void);

extern void ExitEMPWMDetail(void);
extern void EMPWMHighlightHandler(S32 index);
extern void EMPWMDoneFunc(void);
extern void EntryEMPWMDetail(void);

extern void HighlightEmPWM(void);
extern void EntryEmPWMMenu(void);
extern void LSKEmPWMMenu(void);
extern void EntryEmPWMSetParam(void);
extern void LSKEmPWMStop(void);

#if defined(MT6318)
extern void HighlightEmPMIC6318(void);
extern void EntryEmPMIC6318Menu(void);

extern void HighlightEmPMICRegisterEditor(void);
extern void EntryEmPMICRegisterEditor(void);
extern void LSKEmPMICRegisterSetCertain(void);
extern void EntryEMPMICRegisterDetail(void);
extern void ExitEMPMICRegisterDetail(void);
extern void EMPMICRegisterHighlightHandler(S32 index);

extern void EMPMICRegisterSendReq(pmic_config_req_enum type, kal_uint16 register_index, kal_uint8 data);
extern void EMPMICRegisterRes(void *inMsg);

extern void EmPMICSendRequest(void);
extern void ExecutePMICToggle(void);
extern void EmPMICHiliteDescriptionOnOFF(U8 index);

/* Charger Status */
extern void HighlightEmPMICChargerStatus(void);
extern void EntryEMPMICChargerStatus(kal_uint8 char_status);

/* Set Charger */
extern void HighlightEmPMICSetCharger(void);
extern void EntryEmPMICSetCharger(void);
extern void HighlightEmPMICSetChargerChrEn(void);
extern void HighlightEmPMICSetChargerACCurrent(void);
extern void EntryEmPMICChrCurrent(void);
extern void EmPMICSetChrCurrent(void);
extern void HighlightEmPMICSetChargerUSBChren(void);
extern void HighlightEmPMICSetChargerUSBCurrent(void);

/* RGB LED */
extern void HighlightEmPMICRGB(void);
extern void EntryEmPMICRGBLED(void);
extern void HighlightEmPMICRLEDEnable(void);
extern void HighlightEmPMICGLEDEnable(void);
extern void HighlightEmPMICBLEDEnable(void);
extern void HighlightEmPMICRCurrent(void);
extern void EntryEmPMICRGBCurrent(void);
extern void HighlightEmPMICGCurrent(void);
extern void HighlightEmPMICBCurrent(void);
extern void EmPMICRGBSetCurrent(void);

/* KP LED */
extern void HighlightEmPMICKPLED(void);
extern void EntryEmPMICKPLED(void);
extern void HighlightEmPMICKPEnable(void);
extern void HighlightEmPMICKPDutyOption(void);
extern void EntryEmPMICKPDutyOption(void);
extern void SetPMICKPDuty(void);
extern void HighlightEmPMICKPDimClk(void);
extern void EntryEmPMICKPDimClk(void);
extern void SetPMICKPDIM(void);
extern void HighlightEmPMICKPChrPumpEnable(void);
extern void HighlightEmPMICKPChrPumpCurrent(void);
extern void EntryEmPMICKPChrPumpCurrent(void);
extern void EmPMICKPChrPumpSetCurrent(void);

/* BL LED */
extern void HighlightEmPMICBLLED(void);
extern void EntryEmPMICBLLED(void);
extern void HighlightEmPMICBLEnable(void);
extern void HighlightEmPMICBLDutyOption(void);
extern void EntryEmPMICBLDutyOption(void);
extern void SetPMICBLDuty(void);
extern void HighlightEmPMICBLDimClock(void);
extern void EntryEmPMICBLDimClk(void);
extern void SetPMICBLDIM(void);
extern void HighlightEmPMICBLDimBypassEnable(void);

/* Audio */
extern void HighlightEmPMICAudio(void);
extern void EntryEmPMICAudio(void);
extern void HighlightEmPMICAudioSpkEnable(void);
extern void HighlightEmPMICAudioSpkGain(void);
extern void EntryEmPMICSpeakerGain(void);
extern void EmPMICAudSetSpkGain(void);

/* Misc. */
extern void HighlightEmPMICMisc(void);
extern void EntryEmPMICMisc(void);
extern void EmPMICMiscSetHighlightIndex(S32 nIndex);

extern void HighlightEmPMICLCMBLSetting(void);
extern void EntryPMICBLSettingMenu(void);
extern void ExitPMICBLSettingMenu(void);
extern void EmPMICBLLevelHighlightHandler(S32 index);
extern void EmPMICSetBLPWM(void);

#endif /* defined(MT6318) */ 

extern void HighlightEmEINT(void);
extern void EmPrepareEINTList(void);
extern void EntryEmEINTMenu(void);
extern void TestUpdateEmEINT(void);
extern void UpdateEmEINT(void);
extern void ExitEmEINTMenu(void);
extern void StopEmEINTMeun(void);
extern void UpdateEmEINTBatteryRecvHandler(void *inMsg);
extern void UpdateEmEINTGPIORecvHandler(void *inMsg);

extern void HighlightEmADC(void);
extern void EmPrepareADCList(void);
extern void EntryEmADCMenu(void);
extern void TestUpdateEmADC(void);
extern void UpdateEmADC(void *inMsg);
extern void ExitEmADCMenu(void);
extern void StopEmADCMenu(void);
extern void SendEmADCStartReq(void);
extern void SendEmADCStopReq(void);

#if defined(NAND_SUPPORT)       /* && defined(MMI_ON_HARDWARE_P) */
extern void HighlightEmNANDFormat(void);
extern void EntryEmNANDFormatMenu(void);
#endif /* defined(NAND_SUPPORT) */ 

#ifdef __OTG_ENABLE__
extern void HighlightEmDevUSB(void);
extern void EntryEmDevUSBMenu(void);
extern void HighlightEmDevUSBOTGSRP(void);
extern void EmDevUSBOTGSRPMenu(void);
#endif /* __OTG_ENABLE__ */ 

extern void HighlightEmClam(void);
extern void EntryClamMenu(void);

extern void HighlightEmHWLevel(void);
extern void EntryHWLevelMenu(void);
extern void PrepareHWLevelList(void);
extern void GetHightlightAndEnterHWList(void);
extern void EntryHWLevelDisplyDetail(void);
extern void EntryChangeHWLevel(void);
extern void EmHWLevelInfoAccess(U16 Type, U8 Item, U8 action, S32 *value);
extern void ApplyHWLevel(void);
extern void CheckHWLevelInfoDirty(void);
extern void SendSetHWLevelInfoReq(void);
extern void SendSetHWLevelInfoRsp(void *inMsg);

extern void InitEngineerModeBT(void);
extern void HighlightEmBTMenu(void);
extern void EntryEmBTMenu(void);
extern void HighlightEmBTGeneralTestMenu(void);
extern void EntryEmBTGeneralTestMenu(void);
extern void EntryEmBTTSMode(void);
extern void HighlightEmBTENTTSMenu(void);
extern void HighlightEmBTAddSCOLnk(void);
extern void HighlightEmBTRmvSCOLnk(void);
extern void HintEmBTENTTSMenu(U16 index);
extern void HighlightEmBTLoopback(void);
#if defined(__MMI_BT_MTK_SUPPORT__)
extern void HighlightEmBTExitTestMode(void);
extern void EMExitBTTestMode(void);
#endif
extern void HighlightEmBTAVRCPCmdList(void);
extern void ExitEMBTLoopback(void);
extern void EntryEmBTLoopback(void);
extern void EMBTLoopbackReq(void);
extern void EntryEmBTInProgress(void);
extern void EmBTInProgressAbort(void);
extern void EntryEmBTGetFWVersion(void);
extern void EntryEmBTAddSCOLnk(void);
extern void EntryEmBTRmvSCOLnk(void);
extern void HighlightEmBTGetFWVersionMenu(void);
extern void HintEmBTGetFWVersionMenu(U16 index);

extern void EntryEmBTTestMode(void);
extern void HighlightEmBTTestMenu(void);
extern void EntryEmBTDebugTrace(void);
extern void HighlightEmBTDebugTrace(void);
extern void EntryEmBTAddAudioConnection(void);
extern void HighlightEmBTAddAudioConnection(void);
extern void EntryEmBTRemoveAudioConnection(void);
extern void HighlightEmBTRemoveAudioConnection(void);

#ifdef __MMI_FM_RADIO__
/* FM Radio */
extern void EMFMRadioSendReq(void);
extern void EMFMRadioSendRes(void* inMsg);
extern void HighlightEmDevFMRadio(void);
extern void EntryEmDevFMRadioMenu(void);
extern void HighlightEmDevFMRadioMono(void);
extern void EntryEmDevFMRadioMonoMenu(void);
extern void HighlightEmDevFMRadioStereo(void);
extern void EntryEmDevFMRadioStereoMenu(void);
extern void HighlightEmDevFMRadioRSSI(void);
extern void EntryEmDevFMRadioRSSIMenu(void);
extern void HighlightEmDevFMRadioIFCountDelta(void);
extern void EntryEmDevFMRadioIFCountDeltaMenu(void);
extern void HighlightEmDevFMRadioRSSIInfo(void);
extern void EmDevFMRadioRSSIInfoInit(void);
extern void EntryEmDevFMRadioRSSIInfoMenu(void);
extern void EmDevFMRadioRSSIInfoLeftArrowHdlr(void);
extern void EmDevFMRadioRSSIInfoRightArrowHdlr(void);
extern void EmDevFMRadioRSSIInfoUpArrowHdlr(void);
extern void EmDevFMRadioRSSIInfoDownArrowHdlr(void);
extern void EMFMRadioRSSIInfoTimeoutHdlr(void);
#endif /* #ifdef __MMI_FM_RADIO__ */

extern void HighlightEmDevRTCXOSC(void);
extern void EntryEmDevRTCXOSC(void);
extern void EmSetRTCXOSCHandler(void);


#ifdef __MMI_EM_BT_RF_TEST__
extern void HighlightEmDevBtRfTest(void);
extern void EntryEmDevBtRfTestConfirm(void);
extern void EmBtRfTestDisableSleepMode(void);
extern void EmBtRfTestSleepModeHdlr(void* inMsg);
extern void EmBtRfTestEnterFlightMode(void);
extern void EmBtRfTestPowerOnBT(void);
extern void EmBtRfTestPowerOnBTRspHdlr(void *inMsg);

extern void EntryEmDevBtRfTest(void);
extern void EmBtRfTestExit(void);

extern void HighlightEmDevBtRfTX(void);
extern void HighlightEmDevBtRfRX(void);
extern void EntryEmDevBtRfTXRX(void);
extern void HighlightHandlerEmBtRFTestTxRxnline(S32 index) ;
extern void HighlightHandlerBtRfPacketTypeInline(S32 index) ;
extern void HighlightHandlerBtRfTxRxHopingInline(S32 index) ;
extern void EMBtRfTestTXRXSendReq(void);
extern void EMBtRfTestSendReq(void);
extern MMI_BOOL EmBtRfTestCheckTXRXValue(void);
extern void EmBtRfTestTXRXRspHdlr(void *inMsg);
extern void EmBtRfTestPwrCtrlLevelRspHdlr(void *inMsg);
extern void EntryEmDevBtRfTesting(void);
extern void EmBtRfTestPwrLevelUp(void);
extern void EmBtRfTestPwrLevelDown(void);
extern void ExitEmDevBtRfTXRX(void);

extern void HighlightEmDevBtRfBdAddr(void);
extern void EntryEmDevBtRfBdAddr(void);
extern void ExitEmDevBtRfBdAddr(void);
extern void EmBtRfTestSetBdAddrRspHdlr(void *inMsg);

extern void HighlightEmDevBtRfBdEnterTestMode(void);

#endif /* __MMI_EM_BT_RF_TEST__ */

#ifdef __MMI_BT_MTK_SUPPORT__
#define __MMI_EM_BT_GET_CHIP_VERION__
#endif /* __MMI_BT_SUPPORT__ */

#ifdef __MMI_EM_BT_GET_CHIP_VERION__
extern void HighlightEmBTGetChipVersionMenu(void);
extern void EmDevBtChipVersion(void) ;
extern void EmBtGetChipVersionRspHdlr(void *inMsg);
#endif


#endif /* __MMI_ENGINEER_MODE__ */ 

#endif /* _ENGINEER_MODE_DEVICE_H */ 

