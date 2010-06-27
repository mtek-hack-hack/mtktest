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
 *  PhoneSetupGprots.h
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
 *  
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

#ifndef PHONESETUP_GPROTS_H_
#define PHONESETUP_GPROTS_H_

#include "MMI_features.h"

#ifndef __MMI_FEATURES__
#error "Please include MMI_features.h first"
#endif

/** 
  *   Default encoding type enum
  *   Notice:  This order should match with menu item!!
  **/
typedef enum
{
#ifdef __MMI_CHSET_BIG5__
    PHNSET_ENCOD_BIG5,
#endif    
#ifdef __MMI_CHSET_GB2312__        
    PHNSET_ENCOD_GB2312,
#endif
#ifdef __MMI_CHSET_GB18030__
    PHNSET_ENCOD_GB18030,
#endif    
    PHNSET_ENCOD_UCS2,

    PHNSET_ENCOD_LAST
} PHNSET_ENCODING_TYPE;

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
/* Calibration state machine */
typedef enum
{
    CALIBRATION_NULL_STATE,
    CALIBRATION_WELCOME_STATE,
    CALIBRATION_TOP_LEFT_POINT_STATE,   /* Don't change the order of these three enums */
    CALIBRATION_BOTTOM_RIGHT_POINT_STATE,
    CALIBRATION_CENTER_POINT_STATE,
    CALIBRATION_MAX_STATE
} PHNSET_CALIBRATION_STATE_ENUM;

typedef enum
{
    PHNSET_HANDWRITING_FAST,
    PHNSET_HANDWRITING_MEDIUM,
    PHNSET_HANDWRITING_SLOW
} PHNSET_HANDWRITING_SPEED_ENUM;

extern color PhnsetGetHandwritingColor(void);
extern PHNSET_HANDWRITING_SPEED_ENUM PhnsetGetHandwritingSpeed(void);

extern void PhnsetReadNvramCalibrationData(void);
extern BOOL PhnsetNeedFactoryDefaultCalibration(void);
extern void EntryPhnseFactoryDefaultCalibrationScr(void (*callback) (void));

#ifdef __MMI_HANDWRITING_PAD__
typedef enum
{
    TEST_CONTROL_AREA_WELCOME_STATE,
    TEST_CONTROL_AREA_TESTING_STATE,
    TEST_CONTROL_AREA_FINISH_STATE,
    TEST_CONTROL_AREA_MAX_STATE
} PHNSET_TEST_CONTROL_AREA_STATE_ENUM;

#endif /* __MMI_HANDWRITING_PAD__ */ 

#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

extern void HighlightPhnsetScr(void);
extern void HighlightPhnsetTimeAndDate(void);

extern U8 PhnsetGetTimeFormat(void);
extern U8 PhnsetGetDateFormat(void);
extern U8 PhnsetGetHomeCity(void);
extern void PhnsetInitTimeNDate(void);
extern void PhnsetSetDTFillInlineStruct(void *);
extern void PhnsetReinitHomeCityIdx(void);
extern void PhnsetMainLCDContrast(U8 level);
extern void PhnsetSubLCDContrast(U8 level);
extern void PhnsetChangeMainLCDContrastValue(U8 level);
extern void PhnsetChangeSubLCDContrastValue(U8 level);
extern void PhnsetSetShowDTStatus(U8 status);
extern MMI_BOOL PhnsetRestoreToNvramContrast(void);
extern MMI_BOOL PhnsetSetLangByNvramValue(void);

#ifdef __MMI_AUTO_LANG_EN__
extern void PhnsetSetLP(U8 LP);
extern U8 PhnsetGetLang(void);
extern void PhnsetPLPInd(U8 *LPArr);
extern U16 PhnsetGetAutoLangIdx(void);
#endif /* __MMI_AUTO_LANG_EN__ */ 

extern U8 PhnsetGetDefEncodingType(void);

#ifdef __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__
extern S32 mmi_phnset_2line_is_exist(void);
extern pBOOL mmi_phnset_2line_prfr_input_get_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p);
extern S32 mmi_phnset_get_current_preferr_input(void);
extern S32 mmi_phnset_2line_prfr_input_get_total_items(S32 set_default_value);
extern S32 mmi_phnset_2line_prfr_input_get_default(S32 item_index);
extern void mmi_phnset_2line_prfr_input_set_default(void);
extern void mmi_phnset_2line_prfr_input_complete_callback(S32 item_index, S32 selected_index);
#endif /* __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__ */ 

#ifdef __MMI_TVOUT__
extern void mmi_phnset_tvout_lcd_sleepin_handler(void);
extern void mmi_phnset_tvout_lcd_sleepout_handler(void);
extern void mmi_phnset_tvout_disable_tv_sleep_in(void);
extern void mmi_phnset_tvout_enable_tv_sleep_in(void);
extern void mmi_phnset_init_tvout(void);
extern void mmi_phnset_early_init_tvout_before_pwron(void);
extern void mmi_phnset_tvout_check_pwron_start(void);
#endif /* __MMI_TVOUT__ */ 

extern void mmi_phnset_disable_partial_ss(void);
extern void mmi_phnset_enable_partial_ss(void);

#if defined(__MMI_FILE_MANAGER__) && defined(_FILE_MGR_H_)
extern void PhnsetWallpaperForwardFromFmgr(void *path, FMGR_FILTER *filter, int is_short);
#ifdef __MMI_SUB_WALLPAPER__
extern void PhnsetSubWallpaperForwardFromFmgr(void *path, FMGR_FILTER *filter, int is_short);
#endif 
extern void PhnsetScrSvrForwardFromFmgr(void *path, FMGR_FILTER *filter, int is_short);

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
extern void PhnsetPwrOnOffForwardFromFmgr(void *path, FMGR_FILTER *filter, fmgr_tree_action_enum action, int is_short);
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

#endif /* #if defined(__MMI_FILE_MANAGER__) && defined(_FILE_MGR_H_) */

/* GPIO */
extern void PhnsetReadGPIOSetting(void);

/* wallpaper cache */
extern void mmi_phnset_save_wallpaper_to_speedup(void);

#ifdef __GEMINI__
extern l4c_dual_sim_uart_setting_enum PhnsetGetUARTConfig(void);
extern void PhnsetSetUARTConfig(l4c_dual_sim_uart_setting_enum uart_config);
#endif  /* __GEMINI__ */

#endif /* PHONESETUP_GPROTS_H_ */ 

