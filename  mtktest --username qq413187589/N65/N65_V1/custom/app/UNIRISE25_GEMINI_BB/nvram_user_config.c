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
 * nvram_user_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for customers to config/customize their parameters to NVRAM Layer and
 *    Driver Layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MAUI_BASIC__
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_release.h"

#include "nvram_defs.h"

#include "nvram_user_defs.h"
#include "nvram_editor_data_item.h"
#include "nvram_default_audio.h"
#include "custom_hw_default.h"
#include "custom_mmi_default_value.h"
#include "custom_nvram_editor_data_item.h"
#include "camera_para.h"

#ifdef OBIGO_Q05A
#include "custom_wap_config.h"
#endif /* OBIGO_Q05A */

/* DO NOT MODIFY THIS */
kal_uint8 const NVRAM_TOTAL_LID = NVRAM_EF_LAST_LID_CUST;
ltable_entry_struct* logical_data_item_table[NVRAM_EF_LAST_LID_CUST];

/* The pattern that defiines a LOCKED status. Choose one.*/
/* kal_uint8* CODED_LOCK_PATTERN = (kal_uint8*)NVRAM_LOCK_PATTERN_LOCKED; */
kal_uint8* CODED_LOCK_PATTERN = (kal_uint8*)NVRAM_LOCK_PATTERN_UNLOCKED;

/**
 * Hardcoded secret key. Always 8 bytes.
 * Note that this key will be used to decrypt LOCK_PATTERN.
 */
kal_uint8* CODED_SECRET_KEY = (kal_uint8*)"12abcdef";

__align(2) const kal_wchar CLEAN_FOLDER1[]= L"Z:\\@wap";
__align(2) const kal_wchar CLEAN_FOLDER2[]= L"Z:\\@mms";


kal_uint32 const NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT[] = {

                  200, 20,  /* PWM 1  Level 1 */
                  200, 40,  /* PWM 1  Level 2*/
                  200, 60,  /* PWM 1  Level 3*/
                  200, 80,  /* PWM 1  Level 4*/
                  200, 100, /* PWM 1 Level 5 */
	      5, 4,  /* PWM 2  Level 1 */ 
	      5, 5,  /* PWM 2  Level 2*/
	      5, 6,  /* PWM 2  Level 3*/
	      5, 7,  /* PWM 2  Level 4*/
              5, 8,  /* PWM 2  Level 5*/
                  200, 20,  /* PWM 3  Level 1 */
                  200, 40,  /* PWM 3  Level 2*/
                  200, 60,  /* PWM 3  Level 3*/
                  200, 80,  /* PWM 3  Level 4*/
                  200, 100, /* PWM 3 Level 5 */

#if (defined MTKLCM)
		  34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
		  44, 45, 46, 47, 48,
#elif (defined MTKLCM_COLOR)
                  /* Main LCD contrast level 1 ~ 15 */
                  148, 149, 150, 151, 152, 153, 154, 155, 156, 158, 
                  160, 162, 164, 166, 168,    
#else
                   /* Main LCD contrast level 1 ~ 15 */
                  120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 
                  140, 142, 144, 146, 148,    
#endif

                   /* Main LCD Bias Param (Reserved) */
                  0, 0, 0, 0, 0,    
                   /* Main LCD Linerate Param (Reserved) */
                  0, 0, 0, 0, 0,    
                   /* Main LCD Temperature Param (Reserved) */
                  0, 0, 0, 0, 0,    

                   /* Sub LCD contrast level 1 ~ 15 */
                  20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 
                  40, 42, 44, 46, 48,    
                   /* Sub LCD Bias Param (Reserved) */
                  0, 0, 0, 0, 0,    
                   /* Sub LCD Linerate Param (Reserved) */
                  0, 0, 0, 0, 0,    
                   /* Sub LCD Temperature Param (Reserved) */
                  0, 0, 0, 0, 0,    

                  /* Battery voltage Level */
                  3350000, /* Low Battery Power off */
                  3500000, /* Low Battery */
                  /* battery level 1 ~ 8 */
                  3550000, 3640000, 3740000, 3870000, 
                  9999999, 9999999, 9999999, 9999999,
                  200, 20,  /* PMIC6318 PWM Level 1 */
                  200, 40,  /* PMIC6318 PWM Level 2*/
                  200, 60,  /* PMIC6318 PWM Level 3*/
                  200, 80,  /* PMIC6318 PWM Level 4*/
                  200, 100 /* PMIC6318 PWM Level 5 */                  
};

   


ltable_entry_struct logical_data_item_table_cust[] = 
{
	{
		NVRAM_EF_CACHE_BYTE_LID,
		NVRAM_CACHE_SIZE,
		NVRAM_CACHE_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"CT00",
		VER(NVRAM_EF_CACHE_BYTE_LID),
		"1-byte Setting\0",
		NVRAM_RESERVED_VALUE
	}
	,{
		NVRAM_EF_CACHE_SHORT_LID,
		NVRAM_CACHE_SIZE,
		NVRAM_CACHE_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"CT01",
		VER(NVRAM_EF_CACHE_SHORT_LID),
		"2-byte Setting\0",
		NVRAM_RESERVED_VALUE
	}
	,{
		NVRAM_EF_CACHE_DOUBLE_LID,
		NVRAM_CACHE_SIZE,
		NVRAM_CACHE_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"CT02",
		VER(NVRAM_EF_CACHE_DOUBLE_LID),
		"8-byte Setting\0",
		NVRAM_RESERVED_VALUE
	}

};

const kal_wchar * NVRAM_CLEAN_FOLDER_LIST[NVRAM_MAX_CLEAN_FOLDERS] =
{
	CLEAN_FOLDER1,
	CLEAN_FOLDER2
};
void	nvram_restore_byte_cache(kal_uint8 *buffer)
{
	buffer[NVRAM_SCREENSAVER_STATUS] = buffer[RESTORE_DEFAULT_SCREENSAVER_STATUS];
	buffer[NVRAM_SCREENSAVER_WAITING] = buffer[RESTORE_DEFAULT_SCREENSAVER_WAITING];
	buffer[NVRAM_SETTING_SPEED_DIAL] = buffer[RESTORE_DEFAULT_SPEED_DIAL];
	buffer[NVRAM_SETTING_CONTRAST_LEVEL] = buffer[RESTORE_DEFAULT_CONTRAST_LEVEL];
	buffer[NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL] = buffer[RESTORE_DEFAULT_CONTRAST_SUBLCD_LEVEL];
	buffer[NVRAM_SETTING_WELCOME_TEXT] = buffer[RESTORE_DEFAULT_WELCOME_TEXT];
	buffer[NVRAM_SETTING_APHORISM_TEXT] = buffer[RESTORE_DEFAULT_APHORISM_TEXT];
	buffer[NVRAM_SETTING_OWNER_NO] = buffer[RESTORE_DEFAULT_OWNER_NO];
	buffer[NVRAM_SETTING_STATUS_DT_TIME] = buffer[RESTORE_DEFAULT_STATUS_SHOW_DT_TIME];
	buffer[NVRAM_SETTING_AUTOUPDATE_DT_TIME] = buffer[RESTORE_DEFAULT_AUTOUPDATE_TIME];
	buffer[DATE_FORMAT] = buffer[RESTORE_DEFAULT_DATE_FORMAT];
	buffer[TIME_FORMAT] = buffer[RESTORE_DEFAULT_TIME_FORMAT];
	buffer[NVRAM_PROFILES_ACTIVATED] = 0;

#ifdef OBIGO_Q05A
	buffer[NVRAM_BRW_SHOW_IMAGE_MODE] = WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGE;
	buffer[NVRAM_BRW_SETTINGS_HOMEPAGE] = WAP_CUSTOM_CFG_DEFAULT_HOMEPAGE;
	buffer[NVRAM_BRW_SETTINGS_RENDER_MODE] = WAP_CUSTOM_CFG_DEFAULT_RENDER_MODE;
	buffer[NVRAM_BRW_SETTINGS_NAVIGATE_MODE] = WAP_CUSTOM_CFG_DEFAULT_NAVIGATE_MODE;
	buffer[NVRAM_BRW_SETTINGS_FONT_SIZE] = WAP_CUSTOM_CFG_DEFAULT_FONT_SIZE;
	buffer[NVRAM_BRW_SETTINGS_THUMBNAIL] = WAP_CUSTOM_CFG_DEFAULT_THUMBNAIL;
	buffer[NVRAM_BRW_SETTINGS_SCREEN_SIZE] = WAP_CUSTOM_CFG_DEFAULT_SCREEN_SIZE;
	buffer[NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX] = WAP_CUSTOM_CFG_DEFAULT_ENCODE_METHOD_INDEX;
	buffer[NVRAM_BRW_SETTINGS_SHOW_VIDEO] = WAP_CUSTOM_CFG_DEFAULT_SHOW_VIDEO;
	buffer[NVRAM_BRW_SETTINGS_PLAY_SOUND] = WAP_CUSTOM_CFG_DEFAULT_PLAY_SOUND;
	buffer[NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA] = WAP_CUSTOM_CFG_DEFAULT_LOAD_UNKOWN_MEDIA;
	buffer[NVRAM_BRW_SETTINGS_CSS] = WAP_CUSTOM_CFG_DEFAULT_CSS;
	buffer[NVRAM_BRW_SETTINGS_SCRIPTS] = WAP_CUSTOM_CFG_DEFAULT_SCRIPTS;
	buffer[NVRAM_BRW_SETTINGS_CACHE] = WAP_CUSTOM_CFG_DEFAULT_CACHE;
	buffer[NVRAM_BRW_SETTINGS_COOKIE] = WAP_CUSTOM_CFG_DEFAULT_COOKIE;
	buffer[NVRAM_BRW_SETTINGS_SHORTCUTS] = WAP_CUSTOM_CFG_DEFAULT_SHORTCUTS;
	buffer[NVRAM_BRW_SETTINGS_SECURITY_WARNINGS] = WAP_CUSTOM_CFG_DEFAULT_SECURITY_WARNINGS;
	buffer[NVRAM_BRW_SETTINGS_SEND_DEVICE_ID] = WAP_CUSTOM_CFG_DEFAULT_SEND_DEVICE_ID;
	buffer[NVRAM_BRW_RECENT_PAGES_SORTING_METHOD] = WAP_CUSTOM_CFG_DEFAULT_SORTING_METHOD;
	buffer[NVRAM_BRW_ACTIVATED_WAP_PROFILE_INDEX] = WAP_CUSTOM_DEFAULT_BRW_CONTENT_INDEX;
	buffer[NVRAM_BRW_ACTIVATED_MMS_PROFILE_INDEX] = WAP_CUSTOM_DEFAULT_MMS_CONTENT_INDEX;
#endif /* OBIGO_Q05A */
}
void	nvram_restore_short_cache(kal_uint16 *buffer)
{

	buffer[NVRAM_FUNANDGAMES_SETWALLPAPER] = 	buffer[RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER];
	buffer[NVRAM_CURRENT_SCREENSVER_ID] = 	buffer[RESTORE_DEFAULT_CURRENT_SCREENSVER_ID];
	buffer[NVRAM_SETTING_PREFER_INPUT_METHOD] = buffer[RESTORE_PREFER_INPUT_METHOD];
	buffer[NVRAM_CURRENT_POWER_ON_DISPLAY] = buffer[NVRAM_RESTORE_POWER_ON_DISPLAY];
	buffer[NVRAM_CURRENT_POWER_OFF_DISPLAY] = buffer[NVRAM_RESTORE_POWER_OFF_DISPLAY];
	buffer[NVRAM_SETWALLPAPER_SUB] = buffer[RESTORE_DEFAULT_SETWALLPAPER_SUB];
#ifdef OBIGO_Q05A
	buffer[NVRAM_BRW_PAGE_TIME_OUT_VALUE] = WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT;
	//buffer[NVRAM_BRW_SETTINGS_ZOOM_VALUE] = WAP_CUSTOM_CFG_DEFAULT_ZOOM_VALUE;
#endif /* OBIGO_Q05A */
}
void  nvram_restore_double_cache(kal_uint32 *buffer)
{
	double *dbuf = (double*) buffer;
	dbuf[NVRAM_PEN_CALIBRATION_VALUE1] = dbuf[NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE1];
	dbuf[NVRAM_PEN_CALIBRATION_VALUE2] = dbuf[NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE2];	
	dbuf[NVRAM_PEN_CALIBRATION_VALUE3] = dbuf[NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE3];	
	dbuf[NVRAM_PEN_CALIBRATION_VALUE4] = dbuf[NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE4];	
	dbuf[NVRAM_PEN_CALIBRATION_VALUE5] = dbuf[NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE5];	
	dbuf[NVRAM_PEN_CALIBRATION_VALUE6] = dbuf[NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE6];	
	dbuf[NVRAM_PEN_CALIBRATION_VALUE7] = dbuf[NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE7];	
	dbuf[NVRAM_PEN_CALIBRATION_VALUE8] = dbuf[NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE8];	
}

#endif /*!__MAUI_BASIC__*/


