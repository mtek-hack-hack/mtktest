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
*	resource_fmradio_skins.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM radio main screen skin settings
*
* Author:
* -------
*	Wilson Lien
*
*==============================================================================
* 				HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * Check in for new feature that supports subLCD application develop
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__

#include "gdi_lcd_config.h"

// dependent headers for FMRadioDef.h"
#include "PixtelDataTypes.h"
#include "gui_data_types.h"

#include "nvram_user_defs.h"
#include "FMRadioDef.h"
#include "FMRadioType.h"


#ifdef __MMI_FM_RADIO_ON_SUBLCD__
const mmi_fmrdo_sub_skin_struct g_fmrdo_subLCD_skins[] =
{
  {
	IMG_ID_FMRDO_SUB_SKIN_BACKGROUND,//background image
	255,255,255,//channel name text border color
	100,100,100,//channel name text color
	2,2,//channe name x,y
	47,18,//channel name w,h
	255, 255, 255, // frequency text on color
	150, 150, 150, // frequency text off color
	51,6,//frequency x,y
	40,12,//frequency w,h
	IMG_ID_FMRDO_SUB_SKIN_VOLUME,//volume image
	0,// volume bar type -> 0: horizontal, 1: vertical
	2,51,//x,y
	3,2,//volume indicator start gap,end gap
	IMG_ID_FMRDO_SUB_SKIN_TUNER_SCALE,//tuner scale background image
        IMG_ID_FMRDO_SUB_SKIN_TUNER_SCALE_INDICATOR,//tuner scale indicator image
	0,//tuner scale type->//0:horizontal,1:vertical
	3,19,//x,y
	9,//tuner scale ind offset
	1,0,//tuner scale start gap,end gap
 	IMG_ID_FMRDO_SUB_SKIN_STEP_DOWN_BUTTON_UP,//step down button up image
    IMG_ID_FMRDO_SUB_SKIN_STEP_DOWN_BUTTON_DOWN,//step down button down image
	37,45,//step down button x,y
	IMG_ID_FMRDO_SUB_SKIN_STEP_UP_BUTTON_UP,//step up button up image
    IMG_ID_FMRDO_SUB_SKIN_STEP_UP_BUTTON_DOWN,//step up button up image
	75,45,//step up button x,y
	IMG_ID_FMRDO_SUB_SKIN_SEARCH_BUTTON_ON_UP,//step mode image
    IMG_ID_FMRDO_SUB_SKIN_SEARCH_BUTTON_ON_DOWN,//channel mode image
    IMG_ID_FMRDO_SUB_SKIN_SEARCH_BUTTON_OFF_UP,//search mode image
    IMG_ID_FMRDO_SUB_SKIN_SEARCH_BUTTON_OFF_DOWN,//no use
	26,45,//mode indication x,y
	IMG_ID_FMRDO_SUB_SKIN_POWER_BUTTON_ON_UP,//power button on up image
    IMG_ID_FMRDO_SUB_SKIN_POWER_BUTTON_ON_DOWN,//power button on down image
    IMG_ID_FMRDO_SUB_SKIN_POWER_BUTTON_OFF_UP,//power button off up image
    IMG_ID_FMRDO_SUB_SKIN_POWER_BUTTON_OFF_DOWN,//power button off down image
	56,45,//power button x,y
	FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
    }
};
#endif/*__MMI_FM_RADIO_ON_SUBLCD__*/

#endif // __MMI_FM_RADIO__


