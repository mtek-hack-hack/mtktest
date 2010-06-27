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
*  CSBframework.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Category Screen Browser Framework
*
* Author:
* -------
*  
*
*==============================================================================
*           HISTORY
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
 * created by clearfsimport
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
#include "MMI_include.h"

#ifdef __MMI_CSB_BROWSER__


#include "CommonScreens.h"
#include "FileManagerGProt.h"
#include "gpioInc.h"

/* For Default Image */
#include "UserProfilesResDef.h"

#include "CatScreenBrowserDefs.h"
#include "CatScreenBrowserProts.h"


/* Global Variables */
extern csb_struct g_CSB_struct;
extern U8 csb_buffer[MAX_CSB_SCREEN_NAME_LENGTH];


extern csb_category_screen csb_category_screen_list[TOTAL_CATEGORY_SCREENS];

extern U16 csb_search_hint_popups[CSB_TOTAL_CONTROLS];
extern U16 csb_app_hint_popups[CSB_TOTAL_APP];

extern U8 g_csb_timer;
extern U8 g_csb_highlighted_item;

extern U16 g_csb_index;

extern void ReleaseEMSEditBuffer(void);

/*************************************************************
************************* FRAMEWORK **************************
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  csb_frm_create_csb_folder
 * DESCRIPTION
 *  Is csb Folder created
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void csb_frm_create_csb_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 csb_folder_path_ascii[MAX_CSB_PATH_LENGTH];
	S8 csb_folder_path_unicode[MAX_CSB_PATH_LENGTH * ENCODING_LENGTH];
	FS_HANDLE ret_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(csb_folder_path_ascii, "%c%s", MMI_CARD_DRV, CSB_DEFAULT_FOLDER);
    mmi_asc_to_ucs2((S8*) csb_folder_path_unicode, (S8*) csb_folder_path_ascii);

	ret_code = FS_GetFolderSize((PU16)csb_folder_path_unicode, FS_COUNT_IN_BYTE, NULL, 0);
	if(ret_code == FS_PATH_NOT_FOUND)
	{
		FS_CreateDir((PU16) csb_folder_path_unicode);
}

    sprintf(csb_folder_path_ascii, "%c%s", MMI_PUBLIC_DRV, CSB_DEFAULT_FOLDER);
    mmi_asc_to_ucs2((S8*) csb_folder_path_unicode, (S8*) csb_folder_path_ascii);

	ret_code = FS_GetFolderSize((PU16)csb_folder_path_unicode, FS_COUNT_IN_BYTE, NULL, 0);
	if(ret_code == FS_PATH_NOT_FOUND)
	{
		FS_CreateDir((PU16) csb_folder_path_unicode);
	}
}
 
/*************************************************************
**	FUNCTION NAME		: csb_frm_start_view_auto
**
** 	PURPOSE				: Enrty function for CSB Start View 
**						  in Auto Mode
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
***************************************************************/
void csb_frm_start_view_auto(void)
{
	/* Stop the time if started */
	StopTimer(CSB_AUTO_MODE_TIMER_ID);

	if(g_CSB_struct.screen_counter < TOTAL_CATEGORY_SCREENS)
	{

		/* ASSERT if entryFunPtr is NULL -- should never happen */
		ASSERT(g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].entryFuncPtr != NULL);
		/* Call the entry function pointer */
		g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter++].entryFuncPtr();
		SetKeyHandler(GoBackToMainMenu, KEY_END, KEY_EVENT_DOWN);
		SetKeyHandler(csb_show_current_screen_ID, KEY_SEND, KEY_EVENT_DOWN);
		/* Delete the history nodes added after every call */
		DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);
		/* Start the timer */
		StartTimer(CSB_AUTO_MODE_TIMER_ID, g_CSB_struct.csb_settings.timer_value, csb_frm_start_view_auto);
	}
	else
	{
		g_CSB_struct.screen_counter = 0;
		DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);
		GoBackHistory();
		/* Backlight was turned ON permanently while entering AUTO mode, turn ON it temporary now */
		TurnOffBacklight();

		/* Release the EMS buffer */
		ReleaseEMSEditBuffer();
	}
}

/*****************************************************************************
 * FUNCTION
 *  GoBackToMainMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex				[IN]            
 * RETURNS				void
 *****************************************************************************/
void GoBackToMainMenu(void)
{
	/* In search By Screen ID, editor screen is to be deleted when press END key */
	if(SEARCH_MODE_SCREENID == csb_frm_get_search_mode())
	{
		DeleteUptoScrID(SCR_ID_CSB_SEARCH_SCR_ID);
	}

	TurnOffBacklight();

	/* Release the EMS buffer */
	ReleaseEMSEditBuffer();

	g_CSB_struct.screen_counter = 0;
	GoBackHistory();
}

/*************************************************************
**	FUNCTION NAME		: csb_frm_start_view_manual
**
** 	PURPOSE				: Enrty function for CSB Start View 
						  in Manual Mode
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
***************************************************************/
void csb_frm_start_view_manual(void)
{

	/* Manual Mode should be Interactive or Non-Interactive, ASSERT otherwise */
	ASSERT(g_CSB_struct.csb_settings.manual_mode == MANUAL_MODE_NONINTERACTIVE || g_CSB_struct.csb_settings.manual_mode == MANUAL_MODE_INTERACTIVE);

	if(g_CSB_struct.screen_counter < TOTAL_CATEGORY_SCREENS)
	{
		/* ASSERT if entryFunPtr is NULL -- should never happen */
		ASSERT(g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].entryFuncPtr != NULL);


		/* Call the entry function pointer of the categpry screen */
		g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter++].entryFuncPtr();
		
		/* Set the key handlers here for Manual Mode */
		SetKeyHandler(csb_frm_start_view_manual, KEY_VOL_DOWN, KEY_EVENT_DOWN);
		SetKeyHandler(GoToPreviousScreen, KEY_VOL_UP, KEY_EVENT_DOWN);
		SetKeyHandler(GoBackToMainMenu, KEY_END, KEY_EVENT_DOWN);
		SetKeyHandler(csb_show_current_screen_ID, KEY_SEND, KEY_EVENT_DOWN);

		/* Delete the history nodes added after every call */
		DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);
	}
	else
	{
		/* If all the screen counter exceeds the limit, set the global counter as ZERO 
		and delete screen from history and go back one level */
		g_CSB_struct.screen_counter = 0;
		DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);
		GoBackHistory();

		/* Release the EMS buffer */
		ReleaseEMSEditBuffer();
	}
}

/*************************************************************
**	FUNCTION NAME		: EntryCSBStartView
**
** 	PURPOSE				: Enrty function for CSB Start View
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
***************************************************************/
void EntryCSBStartView(void)
{

	/* ASSERT if none of AUTO or MANUAL mode is selected -- should never happen */
	ASSERT(g_CSB_struct.csb_settings.view_mode == VIEW_MODE_AUTO || g_CSB_struct.csb_settings.view_mode == VIEW_MODE_MANUAL);
	
	if(SEARCH_BY_VIEW == csb_frm_get_search_mode())
	{
		/* Check for AUTO or MANUAL mode */
		if(VIEW_MODE_AUTO == g_CSB_struct.csb_settings.view_mode)		
		{
			/* In AUTO mode, the back light must be ON always */
			TurnOnBacklight(0);							
			csb_frm_start_view_auto();
		} 
		else if(VIEW_MODE_MANUAL == g_CSB_struct.csb_settings.view_mode)
		{
			csb_frm_start_view_manual();
		}
	}
	/* In case of Search by Scr ID, the entered category screen should be displayed directly */
	else if(SEARCH_BY_SCREENID == csb_frm_get_search_mode())
	{
		/* This flag disables the key handlers which are not required */
		g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].entryFuncPtr();
	}
	/* If the search mode is CONT or APP, after any async eventsame screen shall appear */
	else if(SEARCH_BY_CONTROL == csb_frm_get_search_mode()
			||
			SEARCH_BY_APP == csb_frm_get_search_mode())
	{
		entry_csb_show_cat_scr();
	}
}

/*****************************************************************************
 * FUNCTION
 *  GoToPreviousScreen
 * DESCRIPTION
 *  Goes to previous screen, if the view mode is MANUAL
 * PARAMETERS
 *  nIndex				[IN]            
 * RETURNS				void
 *****************************************************************************/
void GoToPreviousScreen(void)
{
	/* Decrement the counter by 2, as its been incremented two times */
	g_CSB_struct.screen_counter -= 2;
	csb_frm_start_view_manual();
}

/*************************************************************
**	FUNCTION NAME		: csb_frm_validate_screen_name
**
** 	PURPOSE				: Validates the entered Screen ID
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
***************************************************************/
void csb_frm_validate_screen_name(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U16 index = 0;
	U16 scrID = 0;
	U8 cat_scr_name_ascii[MAX_CSB_SCREEN_NAME_LENGTH];
	U8 local_buffer[MAX_CSB_SCREEN_NAME_LENGTH * ENCODING_LENGTH];

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Set the screen counter as 0 */
	g_CSB_struct.screen_counter = 0;

	/* ASSERT if buffer is NULL */
	ASSERT(csb_buffer != NULL);

	/* Convert the Unicode string to Ansii as atoi does not work on Unicode */
	mmi_ucs2_to_asc((PS8) local_buffer, (PS8) csb_buffer);

	/* If nothing was written on the editor */
	if(CSB_NULL == *local_buffer)
	{
		csb_frm_show_error_message();
		return;
	}
	else if(IS_NUMERIC(*local_buffer))
	{
		scrID = (U16) atoi((S8*)local_buffer);

		while(index < TOTAL_CATEGORY_SCREENS)
		{	
			/* If the entered screen ID is the current screen ID, set the global screen counter
			and break the loop */
			if(g_CSB_struct.pscreen_info[index].cat_ID == scrID)
			{
				g_CSB_struct.screen_counter = index;
				break;
			}
			index++;
		}

		/* This will happen only when entered screen ID is not in the list */
		if(g_CSB_struct.screen_counter != index)
		{
			csb_frm_show_error_message();
			return;
		}
	}  
	else if(IS_ALPHABET(*local_buffer))
	{

		while(index < TOTAL_CATEGORY_SCREENS)
		{
			/* All category without ID will be on the top of the database having ID = 0,
				it is the limitation of the design */
			if(g_CSB_struct.pscreen_info[index].cat_ID != 0)
				break;

			/* Convert the name of Category screen from Unicode to Ansii */
			mmi_ucs2_to_asc((PS8)cat_scr_name_ascii, (PS8)g_CSB_struct.pscreen_info[index].cat_scr_name);

			/* Check, if the database have the matched the screen name */
			if(!(strcmp((S8*)cat_scr_name_ascii, (S8*)local_buffer)))
			{
				/* If yes, then store the current index and break */
				g_CSB_struct.screen_counter = index;
				break;
			}
			index++;
		}

		/* This will happen only when entered screen name is not in the list */
		if(g_CSB_struct.screen_counter != index)
		{
			csb_frm_show_error_message();
			return;
		}
	}
	else
	{
		csb_frm_show_error_message();
		return;
	}

	/* Clear the buffer after use */
	memset(csb_buffer, CSB_NULL, MAX_CSB_SCREEN_NAME_LENGTH);

	ASSERT(TOTAL_CATEGORY_SCREENS > g_CSB_struct.screen_counter);
	EntryCSBStartView();
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_show_error_message
 * DESCRIPTION
 *  shows the error string and NULLs the csb_buffer
 * PARAMETERS
 *  nIndex				[IN]            
 * RETURNS				void
 *****************************************************************************/
void csb_frm_show_error_message(void)
{
	DisplayPopup((PU8) GetString(STR_ID_CSB_SCR_NOT_EXIST_TEXT), IMG_GLOBAL_ERROR, 1, CSB_NOTIFY_DURATION, 0);
	/* reset the buffer */
	memset(csb_buffer, CSB_NULL, MAX_CSB_SCREEN_NAME_LENGTH);
	DeleteNHistory(1);
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_save_view_mode
 * DESCRIPTION
 *  Confirms the view mode change
 * PARAMETERS
 *  nIndex				[IN]            
 * RETURNS				void
 *****************************************************************************/
void csb_frm_save_view_mode(void)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	g_CSB_struct.csb_settings.view_mode = (U8) g_csb_highlighted_item;

	/* Write the updated value in NVRAM */
	csb_frm_write_in_nvram();

	DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CSB_NOTIFY_DURATION, 0);
	DeleteNHistory(1);
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_save_auto_mode_time
 * DESCRIPTION
 *  Confirms the Auto mode timer change
 * PARAMETERS
 *  nIndex				[IN]            
 * RETURNS				void
 *****************************************************************************/
void csb_frm_save_auto_mode_time(void)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	/* Multiply the "g_csb_timer" value with 1000, as the time shouldbe stored in milli seconds */
	g_CSB_struct.csb_settings.timer_value = (U16)(g_csb_timer * 1000);

	/* Write the updated value in NVRAM */
	csb_frm_write_in_nvram();

	DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CSB_NOTIFY_DURATION, 0);
	DeleteNHistory(1);

}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_save_manual_mode
 * DESCRIPTION
 *  Confirms the manual mode change
 * PARAMETERS
 *  nIndex				[IN]            
 * RETURNS				void
 *****************************************************************************/
void csb_frm_save_manual_mode(void)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	g_CSB_struct.csb_settings.manual_mode = (U8) g_csb_highlighted_item;

	/* Write the updated value in NVRAM */
	csb_frm_write_in_nvram();

	DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CSB_NOTIFY_DURATION, 0);
	DeleteNHistory(1);
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_prepare_search_hint_popups
 * DESCRIPTION
 *  Creates a list if Hint Popups for Search by Control
 * PARAMETERS
 *
 * RETURNS				void
 *****************************************************************************/
void csb_frm_prepare_search_hint_popups(void)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
	U16 index;
	U32	search_flag;

	/*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	/* Go through all the screens once, and increment the counter of every control when found */
	for(index = 0; index < TOTAL_CATEGORY_SCREENS; index++)
	{
		search_flag = g_CSB_struct.pscreen_info[index].cont_search_flags;

			if(CSB_CALL_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_CALL_SCR]++;
					
			if(CSB_COLOR_PICKER_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_COLOR_PICKER_SCR]++;
					
			if(CSB_EDITOR_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_EDITOR_SCR]++;
					
			if(CSB_IDLE_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_IDLE_SCR]++;
					
			if(CSB_IMAGE_VIEWER_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_IMAGE_VIEWER_SCR]++;
					
			if(CSB_LIST_MENU_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_LIST_MENU_SCR]++;
					
			if(CSB_MATRIX_MENU_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_MATRIX_MENU_SCR]++;
					
			if(CSB_POPUP_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_POPUP_SCR]++;
					
			if(CSB_PROGRESS_BAR_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_PROGRESS_BAR_SCR]++;
					
			if(CSB_SLIDER_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_SLIDER_SCR]++;
					
			if(CSB_RADIO_BUTTON_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_RADIO_BUTTON_SCR]++;
					
			if(CSB_CHECK_BOX_SCR & search_flag)
					csb_search_hint_popups[CSB_CONT_CHECK_BOX_SCR]++;
					
			if(CSB_SUB_LCD & search_flag)
					csb_search_hint_popups[CSB_CONT_SUB_LCD]++;
					
			if(CSB_PANEL & search_flag)
					csb_search_hint_popups[CSB_CONT_PANEL]++;//052907 CSB
	}
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_prepare_app_hint_popups
 * DESCRIPTION
 *  Creates a list if Hint Popups for Search by App
 * PARAMETERS
 *           
 * RETURNS				void
 *****************************************************************************/
void csb_frm_prepare_app_hint_popups(void)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
	U16 index;
	U32	search_flag;

	/*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	/* Go through all the screens once, and increment the counter of every control when found */
	for(index = 0; index < TOTAL_CATEGORY_SCREENS; index++)
	{
		search_flag = g_CSB_struct.pscreen_info[index].app_search_flags;

			if(CSB_CALLS & search_flag)
					csb_app_hint_popups[CSB_APP_CALLS]++;
			
			if(CSB_EDITOR & search_flag)
					csb_app_hint_popups[CSB_APP_EDITOR]++;
			
			if(CSB_ENGG_MODE & search_flag)
					csb_app_hint_popups[CSB_APP_ENGG_MODE]++;
			
			if(CSB_EXTRA & search_flag)
					csb_app_hint_popups[CSB_APP_EXTRA]++;
			
			if(CSB_FUN_AND_GAMES & search_flag)
					csb_app_hint_popups[CSB_APP_FUN_AND_GAMES]++;
			
			if(CSB_FILE_MANAGER & search_flag)
					csb_app_hint_popups[CSB_APP_FILE_MANAGER]++;
			
			if(CSB_MESSAGES & search_flag)
					csb_app_hint_popups[CSB_APP_MESSAGES]++;
			
			if(CSB_MISC & search_flag)
					csb_app_hint_popups[CSB_APP_MISC]++;
			
			if(CSB_MULTIMEDIA & search_flag)
					csb_app_hint_popups[CSB_APP_MULTIMEDIA]++;
			
			if(CSB_ORGANIZER & search_flag)
					csb_app_hint_popups[CSB_APP_ORGANIZER]++;
			
			if(CSB_PHONEBOOK & search_flag)
					csb_app_hint_popups[CSB_APP_PHONEBOOK]++;
			
			if(CSB_PROFILE & search_flag)
					csb_app_hint_popups[CSB_APP_PROFILE]++;
			
			if(CSB_SERVICES & search_flag)
					csb_app_hint_popups[CSB_APP_SERVICES]++;
			
			if(CSB_SHORTCUT & search_flag)
					csb_app_hint_popups[CSB_APP_SHORTCUT]++;
			
			if(CSB_SETTINGS & search_flag)
					csb_app_hint_popups[CSB_APP_SETTINGS]++;

			if(CSB_WAP & search_flag)
					csb_app_hint_popups[CSB_APP_WAP]++;

			if(CSB_HID & search_flag)
					csb_app_hint_popups[CSB_APP_HID]++;//052907 CSB
	}
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_prepare_hint_data
 * DESCRIPTION
 *  Creates a list if Hint Popups for Search by App
 * PARAMETERS
 *  nIndex				[IN]            
 * RETURNS				void
 *****************************************************************************/
void csb_frm_prepare_hint_data(U16 index)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
	S8	hint_popup_in_ascii[MAX_CSB_HINT_LENGTH];

	/*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	/* This hintData is Global hint data used for HINTS */
	memset((PS8) hintData[index], 0, sizeof(hintData[index]));

	if(SEARCH_MODE_CONTROL == csb_frm_get_search_mode())
	{
		/* ASSERT if the index comes greater than the csb_search_hint_popups array size */
		ASSERT(index < CSB_TOTAL_CONTROLS);
		sprintf((S8*) hint_popup_in_ascii, "%d ", csb_search_hint_popups[index]);
	}
	else if(SEARCH_MODE_APP == csb_frm_get_search_mode())
	{
		/* ASSERT if the index comes greater than the csb_app_hint_popups array size */
		ASSERT(index < CSB_TOTAL_APP);
		sprintf((S8*) hint_popup_in_ascii, "%d ", csb_app_hint_popups[index]);
	}
	mmi_asc_to_ucs2((PS8) hintData[index], (PS8) hint_popup_in_ascii);
}

/**************************************************************
**	FUNCTION NAME		: pre_entry_csb_prepare_cat_scr_list
**
** 	PURPOSE				: Pre entry function to fill the array 
**							with category screen names
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
****************************************************************/
void pre_entry_csb_prepare_cat_scr_list(void)
{
	U16 current_screen_index = 0;
	U16 search_mode = csb_frm_get_search_mode();

	/* Resetting the number_of_screens to ZERO before searching */
	g_CSB_struct.number_of_screens = 0;

	/* If the search mode is Application */
	while(current_screen_index < TOTAL_CATEGORY_SCREENS)
	{
		if(search_mode == SEARCH_MODE_APP)
		{
			if(g_CSB_struct.current_flag & g_CSB_struct.pscreen_info[current_screen_index].app_search_flags)
		{
				csb_frm_add_screen_in_list(current_screen_index);
		}
		}
		else if(search_mode == SEARCH_MODE_CONTROL)
		{
			if(g_CSB_struct.current_flag & g_CSB_struct.pscreen_info[current_screen_index].cont_search_flags)
		{
			 csb_frm_add_screen_in_list(current_screen_index);
		}
		}
		current_screen_index++;
	}

	/* Number of category screens found should always less than the total category screens */
	ASSERT(g_CSB_struct.number_of_screens < TOTAL_CATEGORY_SCREENS);
	/* Entry function to list the category screen names found */
	entry_csb_cat_scr_list();
}

/*****************************************************************************
 * FUNCTION
 *  csb_cat_scr_list_get_item
 * DESCRIPTION
 *  get the list of items
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  d(?)                [IN/OUT]        String image mask
 *  c(?)                [IN/OUT]        Image buffer
 *  b(?)                [IN/OUT]        String buffer
 * RETURNS
 * TRUE
*****************************************************************************/
pBOOL csb_cat_scr_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(str_img_mask);
	*img_buff_p = (PU8) GetImage(IMG_PROFILES_OUTDOOR);


	mmi_ucs2cpy((S8*) str_buff,(S8*) GetString(STR_ID_CSB_SHOW_CATEGORY_TEXT));

	/* Concatenate the categor ID to the category name */
	mmi_ucs2cat((S8*) str_buff,(S8*) csb_category_screen_list[item_index].pscreen_name);

	/* Concatenate the string to the category ID */
	mmi_ucs2cat((S8*) str_buff,(S8*) GetString(STR_ID_CSB_SCREEN_TEXT));
   
    return TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_add_screen_in_list
 * DESCRIPTION
 *  Creates a linked list for category screen names
 * PARAMETERS
 *  a(?)                [IN]			nIndex
 * RETURNS
 * TRUE
*****************************************************************************/
void csb_frm_add_screen_in_list(S32 nIndex)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
	/*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	/* Fill the structure with the information : Screen Name and Screen Index */
	csb_category_screen_list[g_CSB_struct.number_of_screens].pscreen_name = (U8*) g_CSB_struct.pscreen_info[nIndex].cat_scr_name;
	csb_category_screen_list[g_CSB_struct.number_of_screens].screen_index = (U16) nIndex;

	/* Increment the number of screens */
	g_CSB_struct.number_of_screens++;
}

 /*************************************************************
**	FUNCTION NAME		: entry_csb_show_cat_scr
**
** 	PURPOSE				: Entry function to display the selected 
**							category screen.
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
***************************************************************/
void entry_csb_show_cat_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* This flag disables the key handlers which are not required while showing category screen */
	/* Call the entry function pointer of the currently selected screen in the dynamic list */
	 g_CSB_struct.pscreen_info[g_CSB_struct.current_index].entryFuncPtr();
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_search_mode
 * DESCRIPTION
 *  Sets the current search mode
 * PARAMETERS
 *  U16			mode
 * RETURNS
 *  void
 *****************************************************************************/
void csb_frm_set_search_mode(U16 mode)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

	/*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
	/* Set the current search mode, it will be used in creating the Dynamic list */
	g_CSB_struct.search_mode = (U8) mode;
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_get_search_mode
 * DESCRIPTION
 *  Returns the current search mode
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 csb_frm_get_search_mode(void)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

	/*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	return g_CSB_struct.search_mode;
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_testtool_callback
 * DESCRIPTION
 *  Callback to take snap shots one by one (non-blocking)
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
void csb_frm_testtool_callback(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
	BOOL error_code = TRUE;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	StopTimer(CSB_AUTO_MODE_TIMER_ID);

    /* Lock the buffer as we dont want to display the category screens */
    gdi_layer_lock_frame_buffer();

    /* ASSERT if the entryFuncPtr is NULL */
    ASSERT(g_CSB_struct.pscreen_info[g_csb_index].entryFuncPtr != NULL);
    /* Call the category as the buffer must built before calling csb_frm_save_screen_shot */
    g_CSB_struct.pscreen_info[g_csb_index].entryFuncPtr();

    /* Unlock the buffer as it is already built */
    gdi_layer_unlock_frame_buffer();

    /* API to create the file path and save the LAYER contents in JPEG format */
    error_code = (BOOL)csb_frm_save_screen_shot((U32)g_csb_index);

    if (error_code == FALSE)
    {
        /* Clear the key events */
        ClearKeyEvents();
        DisplayPopup((PU8) GetString(STR_ID_CSB_JPEG_FAIL_TEXT), IMG_GLOBAL_ERROR, 1, CSB_NOTIFY_DURATION, 0);
        DeleteUptoScrID(SCR_ID_CSB_TESTTOOL_SCR_ID);
		return;
    }

	/* Show processing screen till all the screenshots are taken */
    TestToolProcessingScr(STR_ID_CSB_PROCESSING_TEXT);

    g_csb_index++;

    /* Delete the screens from History, as all the screens are getting added in History */
    DeleteUptoScrID(SCR_ID_CSB_TESTTOOL_SCR_ID);
	DeleteScreenIfPresent(SCR_ID_CSB_DUMMY_SCR_ID);

	if(g_csb_index < TOTAL_CATEGORY_SCREENS)
	{
		EntryCSBTestToolRun();
	}
	else
	{
		g_csb_index = 0;
		/* Once all the category screenshots are taken, show the DONE pop-up */
		DisplayPopup((PU8) GetString(STR_ID_CSB_TESTTOOL_PASS), IMG_GLOBAL_ACTIVATED, 1, CSB_NOTIFY_DURATION, 0);
		DeleteUptoScrID(SCR_ID_CSB_TESTTOOL_SCR_ID);
	}
	
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_save_screen_shot
 * DESCRIPTION
 *  Function to create the file path and save the 
 *	LAYER contents in JPEG format
 * PARAMETERS
 *  U32			cat_ID
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL csb_frm_save_screen_shot(U32 nIndex)
{
	/*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

	U8	file_name_prefix_in_unicode[MAX_CSB_SCREEN_NAME_LENGTH * ENCODING_LENGTH];
	U8	file_name_prefix_in_ascii[MAX_CSB_SCREEN_NAME_LENGTH] = "category_";
	U8	local_file_path[MAX_CSB_PATH_LENGTH * ENCODING_LENGTH];
	
	gdi_handle handle = GDI_NULL_HANDLE;
	GDI_RESULT	error;

	/*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/

	/* Convert Ansii string to Unicode */
 	mmi_asc_to_ucs2((PS8) file_name_prefix_in_unicode, (PS8) file_name_prefix_in_ascii);

	mmi_ucs2cpy((PS8)local_file_path, (PS8) g_CSB_struct.csb_settings.csb_screenshots_folder_path);

	/* Concatenate the category screen prefix to the file name -- "category_" */
	mmi_ucs2cat((PS8)local_file_path, (PS8) file_name_prefix_in_unicode);
	/* Concatenate the category ID to the file name */
	mmi_ucs2cat((PS8)local_file_path, (PS8) g_CSB_struct.pscreen_info[nIndex].cat_scr_name);
	/* Append the extension of the file -- ".jpg" */
	mmi_ucs2cat((PS8)local_file_path, (PS8) L".jpg\0");

	/* Merge all the layers to one */
	gdi_layer_flatten_previous_to_base();
	handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;

	/* API to save the snapshot of the given the LAYER handle at the given path */
	error = gdi_layer_save_jpeg_file(handle, (S8*) local_file_path);

	if(error == GDI_FAILED)
	{
		return FALSE;
	}
	return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_select_folder_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  U32			cat_ID
 * RETURNS
 *  void
 *****************************************************************************/
void csb_frm_select_folder_callback(void *fullpath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8	csb_drive_phone_unicode[10];
	U8	csb_drive_card_unicode[10];
	U8  csb_default_folder_unicode[10];
	U8  temp_ascii[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(is_short);

	sprintf((S8*)temp_ascii, "%c%s", MMI_PUBLIC_DRV, ":\\");
	mmi_asc_to_ucs2((PS8) csb_drive_phone_unicode, (PS8) temp_ascii);

	
	sprintf((S8*)temp_ascii, "%c%s", MMI_CARD_DRV, ":\\");
	mmi_asc_to_ucs2((PS8) csb_drive_card_unicode, (PS8) temp_ascii);

	mmi_asc_to_ucs2((PS8) csb_default_folder_unicode, (PS8) "CSB\\");


	/* If the file path returned by FileManager is longer than MAX, show error popup */
	if(fullpath)
	{
	if((mmi_ucs2strlen((char*) fullpath)) > MAX_CSB_PATH_LENGTH)
	{
		DisplayPopup((PU8) GetString(STR_ID_CSB_FILE_PATH_TOO_LONG),
				IMG_GLOBAL_ERROR, 
				1, 
				CSB_NOTIFY_DURATION, 
				0);
	}
		else if(!(mmi_ucs2cmp((PS8) fullpath, (PS8) csb_drive_phone_unicode)))
	{

	/* Store the path returned by CallBack in the Global variable */
		mmi_ucs2cpy((PS8) g_CSB_struct.csb_settings.csb_screenshots_folder_path, (PS8)fullpath);

			mmi_ucs2cat((PS8) g_CSB_struct.csb_settings.csb_screenshots_folder_path, (PS8) csb_default_folder_unicode);

			/* Write the updated value in NVRAM */
			csb_frm_write_in_nvram();

			DisplayPopup((PU8) GetString(STR_GLOBAL_DONE),
					IMG_GLOBAL_ACTIVATED, 
					1, 
					CSB_NOTIFY_DURATION, 
					0);
		}
		else if(!(mmi_ucs2cmp((PS8) fullpath, (PS8) csb_drive_card_unicode)))
		{

			/* Store the path returned by CallBack in the Global variable */
			mmi_ucs2cpy((PS8) g_CSB_struct.csb_settings.csb_screenshots_folder_path, (PS8)fullpath);
		
			mmi_ucs2cat((PS8) g_CSB_struct.csb_settings.csb_screenshots_folder_path, (PS8) csb_default_folder_unicode);

			/* Write the updated value in NVRAM */
			csb_frm_write_in_nvram();

			DisplayPopup((PU8) GetString(STR_GLOBAL_DONE),
					IMG_GLOBAL_ACTIVATED, 
					1, 
					CSB_NOTIFY_DURATION, 
					0);
		}
		else
		{
			/* Store the path returned by CallBack in the Global variable */
			mmi_ucs2cpy((PS8) g_CSB_struct.csb_settings.csb_screenshots_folder_path, (PS8)fullpath);
		
		/* Write the updated value in NVRAM */
		csb_frm_write_in_nvram();

		DisplayPopup((PU8) GetString(STR_GLOBAL_DONE),
				IMG_GLOBAL_ACTIVATED, 
				1, 
				CSB_NOTIFY_DURATION, 
				0);
	}
	}
	else
	{
		GoBackHistory();
	}
	DeleteUptoScrID(SCR_ID_CSB_TESTTOOL_SCR_ID);
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_view_images_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  U32			cat_ID
 * RETURNS
 *  void
 *****************************************************************************/
void csb_frm_view_images_callback(void *fullpath, int is_short)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(fullpath);
    UI_UNUSED_PARAMETER(is_short);
	GoBackHistory();
}

void mmi_csb_exit_from_fmgr_empty_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_CSB_TESTTOOL_SCR_ID);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_check_if_card_present
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL csb_frm_check_if_card_present(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 drive;
	S32 status;
	pBOOL error_code = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    status = FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM);

	if(status >= 0)
	{
		error_code = TRUE;
		DisplayPopup((PU8) GetString(STR_GLOBAL_OK), IMG_GLOBAL_ERROR, 5, CSB_NOTIFY_DURATION, 0);
	}
	else
	{
		error_code = FALSE;
		DisplayPopup((PU8) GetString(STR_ID_CSB_NO_MEMORY_CARD), IMG_GLOBAL_ERROR, 5, CSB_NOTIFY_DURATION, 0);
	}

	return error_code;
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_check_disk_free_space
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL csb_frm_check_disk_free_space(U64 *pdisk_free_space)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U64 disk_free_space;
    U64 disk_total_space;
	U64 space_required;
    S32 fs_ret;
    FS_DiskInfo disk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	fs_ret = FS_GetDiskInfo((PU16) g_CSB_struct.csb_settings.csb_screenshots_folder_path, 
							&disk_info, 
							FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    disk_free_space = 0;
    disk_total_space = 0;
    if (fs_ret >= 0)
    {
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        disk_total_space = disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

		*pdisk_free_space = disk_free_space;

		// TO DO: the size of one screenshot???....make a MACRO */
		space_required = TOTAL_CATEGORY_SCREENS * 11 * 1024;
		
        if (disk_free_space <= space_required)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_read_from_nvram
 * DESCRIPTION
 *  Reads the csn settings from NVRAM
 * PARAMETERS
 *       
 * RETURNS				void
 *****************************************************************************/
void csb_frm_read_from_nvram(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Before reading from NVRAM, set the memory with NULL */
	memset(&g_CSB_struct.csb_settings, CSB_NULL, sizeof(csb_setting_struct));

	ReadRecord(NVRAM_EF_CSB_SETTINGS_LID, 
			1, 
			&g_CSB_struct.csb_settings, 
			sizeof(csb_setting_struct), 
			&error);
}

/*****************************************************************************
 * FUNCTION
 *  csb_frm_write_in_nvram
 * DESCRIPTION
 *  Writes the updated data in NVRAM
 * PARAMETERS
 *       
 * RETURNS				void
 *****************************************************************************/
void csb_frm_write_in_nvram(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	WriteRecord(NVRAM_EF_CSB_SETTINGS_LID, 
			1, 
			&g_CSB_struct.csb_settings, 
			NVRAM_CSB_SETTINGS_SIZE, 
			&error);
}



#endif /* __MMI_CSB_BROWSER__ */