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
*	Res_FMScheduleRec.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Schedule FM Radio record resource link
*
* Author:
* -------
*	Wilson Lien (mtk00676)
*
*==============================================================================
* 				HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h" 

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "GlobalDefs.h"             /* for global string */
#include "FMScheduleRecResDef.h"
#include "FunAndGamesResDef.h"

void PopulateFMScheduleRecRes(void)
{
	/*Main Menu List*/
	ADD_APPLICATION_MENUITEM((MENU_ID_FMSR_MAIN, MAIN_MENU_MULTIMEDIA_MENUID, 0,
		SHOW, SHORTCUTABLE, 0, STR_ID_FMSR_APP, IMG_ID_FMSR_APP ));

	/*Channel Setting*/
	ADD_APPLICATION_MENUITEM((MENU_ID_FMSR_CHAN_SETTING, 0, 2,
		MENU_ID_FMSR_CHAN_LIST,
		MENU_ID_FMSR_CHAN_MANUAL,
		SHOW, NONMOVEABLE, 0, STR_ID_FMSR_CHAN_SETTING, IMG_ID_FMSR_APP ));
	ADD_APPLICATION_MENUITEM((MENU_ID_FMSR_CHAN_LIST, MENU_ID_FMSR_CHAN_SETTING, 0,
		SHOW, NONMOVEABLE, 0, STR_ID_FMSR_CHAN_LIST, IMG_ID_FMSR_APP ));
	ADD_APPLICATION_MENUITEM((MENU_ID_FMSR_CHAN_MANUAL, MENU_ID_FMSR_CHAN_SETTING, 0,
		SHOW, NONMOVEABLE, 0, STR_ID_FMSR_CHAN_MANUAL, IMG_ID_FMSR_APP ));

	/*Edit Filename option*/
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	/*String*/
	ADD_APPLICATION_STRING2(STR_ID_FMSR_APP,	"Schedule FM Record",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_SAVE_CONFIRM,	"Save Setting?",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_CHAN_SETTING,	"Channel Setting",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_CHAN_LIST,	"Channel List",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_CHAN_MANUAL,	"Manual Input",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_REC_SETTING,	"Record Setting",	"Schedule FM Record String" );	

	ADD_APPLICATION_STRING2(STR_ID_FMSR_REPEAT,	"Repeat",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_ONCE,	"Once",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_EVERYDAY,	"Everyday",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_DAYS,	"Days",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_WEEKLY,	"Weekly",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_MONTHLY,	"Monthly",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_REC_FORMAT,	"Record Format",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_REC_TYPE,	"Record Type",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_REC_STORAGE,	"Storage",	"Schedule FM Record String" );

	ADD_APPLICATION_STRING2(STR_ID_FMSR_AMR,	"AMR",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_WAV,	"WAV",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_AWB,	"AWB",	"Schedule FM Record String" );	
    ADD_APPLICATION_STRING2(STR_ID_FMSR_REC_QUALITY,	"Audio Quality",	"Schedule FM Record String" );
    ADD_APPLICATION_STRING2(STR_ID_FMSR_REC_QUALITY_LOW,	"Low",	"Schedule FM Record String" );
    ADD_APPLICATION_STRING2(STR_ID_FMSR_REC_QUALITY_HIGH,	"High",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_NEW_FILE,	"New",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_APPEND_FILE,	"Append",	"Schedule FM Record String" );	
//	ADD_APPLICATION_STRING2(STR_ID_FMSR_PHONE,	"Phone",	"Schedule FM Record String" );	
//	ADD_APPLICATION_STRING2(STR_ID_FMSR_CARD,	"Card",	"Schedule FM Record String" );		

	ADD_APPLICATION_STRING2(STR_ID_FMSR_STOP,	"Stop",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_PAUSE,	"Pause",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_RESUME,	"Resume",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_RECORDING,	"Recording",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_BAD_FORMAT,	"Bad Format",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_INVALID_FORMAT,	"Invalid Format",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_DEVICE_BUSY,	"Device Busy",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_OPEN_FILE_ERROR,	"Can't Open",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_NO_CARD,	"Drive Not Found",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_WRITE_PROTECTION_ERROR,	"Write Protection!",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_VALID_FREQUENCY,	"Frequency: 87.5 ~ 108.0",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_FILENAME_TOO_LONG,	"Filename too long",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_FILE_EMPTY,	"File path empty",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_FILE_EXIST,	"File Exists",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_END_TIME_INCORRECT,	"End time must greater than start time",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_START_TIME_INCORRECT,	"Start time must greater than current time",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_TIME_OVERLAP,	"Record time overlapped",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_SYSTEM_INTERRUPT,	"System Interrupt",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_USER_STOP,	"User Stop",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_USER_PAUSE,	"User Pause",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_USE_DEFAULT_FILE,	"Use default file to record",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_TIME_EXPIRE,	"Record time expired",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_INVALID_FREQUENCY,	"Invalid FM frequency",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_CANT_CREATE_FOLDER,	"Can't create folder",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_IN_USB_MODE,	"Can't record in USB mode",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_RECORD_IN_BT_SCO,	"Can not record in bluetooth profile",	"Schedule FM Record String" );	
	ADD_APPLICATION_STRING2(STR_ID_FMSR_RECORD_FINISH_1,	"Schedule Record 1 Finish:",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_RECORD_FINISH_2,	"Schedule Record 2 Finish:",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_RECORD_FINISH_3,	"Schedule Record 3 Finish:",	"Schedule FM Record String" );
	ADD_APPLICATION_STRING2(STR_ID_FMSR_RECORD_FINISH_4,	"Schedule Record 4 Finish:",	"Schedule FM Record String" );	
    ADD_APPLICATION_STRING2(STR_ID_FMSR_APPEND_ERORR,	"can not append when format is WAV",	"Schedule FM Record String" );
	/*Image*/
	ADD_APPLICATION_IMAGE2( IMG_ID_FMSR_APP, CUST_IMG_PATH"\\\\MainLCD\\\\FMScheduleRec\\\\SB_FMschedule.pbm", "Schedule FM Record Image" );
	ADD_APPLICATION_IMAGE2( IMG_ID_FMSR_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\FMScheduleRec\\\\FMS_REC.gif", "Schedule FM Record Image" );
	
}
#endif // __MMI_FM_RADIO_SCHEDULE_REC__


