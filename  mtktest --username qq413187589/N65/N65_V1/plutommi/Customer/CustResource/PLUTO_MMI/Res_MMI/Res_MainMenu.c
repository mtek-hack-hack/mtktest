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
/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: Res_MainMenu.c

  	PURPOSE		: Populate Resource for MainMenu

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-19-2003

**************************************************************/


#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"
#include "MMI_features.h"
#include "gui_config.h"
#include "GlobalMenuItems.h"

#include "OrganizerResDef.h"
#include "ExtraResDef.h"
#include "PhoneBookResDef.h"
#include "FunAndGamesResDef.h"
#include "SettingResDef.h"
#ifdef __MMI_MESSAGES_CLUB__
#include "MessagesResDef.h"
#endif

#if defined( __MMI_IRDA_SUPPORT__ )
#include "ConnectivityResDef.h "
#endif

#ifdef __MMI_SUBLCD_MASTER_MODE__
#if defined(__MMI_AUDIO_PLAYER__)
#include "AudioPlayerResDef.h"
#endif

#if defined(__MMI_FM_RADIO__)
#include "FMRadioResDef.h"
#endif
#endif/*__MMI_SUBLCD_MASTER_MODE__*/

#ifdef __J2ME__
#include "j2me_custom.h"
#endif

#ifdef __MMI_UCM__
#include "UCMResDef.h"
#endif

#ifdef __MMI_MAPBAR_GIS__
#include "MB_GISResDef.h"
#endif

#ifdef __MMI_SUNAVI_GIS__
#include "SN_GISResDef.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__ 
#include "MTPNP_AD_resdef.h"
#endif /* __MMI_DUAL_SIM_MASTER__  */

#define TYPE(A)	TYPE_(A)
#define TYPE_(A) A##_MENU
#define  IMG_DIR(B)   IMG_DIR_(B)
#define  IMG_DIR_(B)  # B

/**************************************************************

	FUNCTION NAME		: PopulateMainMenuRes()

  	PURPOSE				: To Initialize the resources for the
						  Mainmenu

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				:

**************************************************************/
//Organizer

#if defined(__MMI_VERSION_2__)
	typedef enum
	{
	#if defined (__MMI_CALCULATOR__)
		EXTRA_ENUM_CALCULATOR,	
	#endif
	
	#if defined (__MMI_UNIT_CONVERTER__) || defined	(__MMI_EXTENDED_UNIT_CONVERTER__)
		EXTRA_ENUM_UNIT_CONVERTER,		
	#endif
	
	#if defined (__MMI_CURRENCY_CONVERTER__) || defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
		EXTRA_ENUM_CURRENCY_CONVERTER,
	#endif

	#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__) || defined(__MMI_CALORIE__)
		EXTRA_ENUM_HEALTH,
	#endif

        #if defined( __MMI_STOPWATCH__)        
            EXTRA_ENUM_STOPWATCH,
        #endif  

	#if defined(__MMI_APHORISM__)	
/* under construction !*/
	#endif

	#if defined(__MMI_IRDA_SUPPORT__)	
		EXTRA_ENUM_IRDA,
	#endif

	#if defined(__MMI_BT_SUPPORT__) 
		EXTRA_ENUM_BT,
	#endif
   #if defined (__MMI_EBOOK_READER__)
		EXTRA_ENUM_EBOOK,	
	#endif 
	#if defined(__MMI_DICTIONARY__)
		EXTRA_ENUM_DICTIONARY,
	#endif
	#if defined(__MMI_LANGLN__)
		EXTRA_ENUM_LANGLN,
	#endif
		EXTRA_ENUM_TOTAL	
	} ExtraMenu;

typedef enum
{
#if defined(__MMI_CALENDAR__)
	ORG_ENUM_CALRNDAR,
#endif

#if defined(__MMI_TODOLIST__)
	ORG_ENUM_TODOLIST,		
#endif

	ORG_ENUM_ALARM,	

	#if defined (__MMI_WORLD_CLOCK__) && !defined(__MMI_WORLD_CLOCK_TO_PHONESETUP__)
		ORG_ENUM_WORLDCLOCK,
	#endif
#ifdef __MMI_MESSAGES_CLUB__
		ORG_ENUM_SERVICE,
#endif
		ORG_ENUM_TOTAL	
	} OrganizerMenu;
#else
	typedef enum
	{
	#if defined(__MMI_CALENDAR__)
		ORG_ENUM_CALRNDAR,
	#endif
	
	#if defined(__MMI_TODOLIST__)
		ORG_ENUM_TODOLIST,		
	#endif
	
		ORG_ENUM_ALARM,	
	
#if defined (__MMI_CALCULATOR__)
	ORG_ENUM_CALCULATOR,	
#endif

#if defined (__MMI_UNIT_CONVERTER__) || defined	(__MMI_EXTENDED_UNIT_CONVERTER__)
	ORG_ENUM_UNIT_CONVERTER,		
#endif

#if defined (__MMI_CURRENCY_CONVERTER__) || defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
	ORG_ENUM_CURRENCY_CONVERTER,
#endif

#if defined (__MMI_WORLD_CLOCK__) && !defined(__MMI_WORLD_CLOCK_TO_PHONESETUP__)
	ORG_ENUM_WORLDCLOCK,
#endif

#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__) || defined(__MMI_CALORIE__)
	ORG_ENUM_HEALTH,
#endif

#if defined(__MMI_APHORISM__)	
/* under construction !*/
#endif
#ifdef __MMI_MESSAGES_CLUB__
	ORG_ENUM_SERVICE,
#endif
#if defined (__MMI_EBOOK_READER__)
		EXTRA_ENUM_EBOOK,	
#endif 
#if defined (__MMI_LANGLN__)
		EXTRA_ENUM_LANGLN,	
#endif 
	ORG_ENUM_TOTAL	
} OrganizerMenu;
#endif


#if defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
//FOR TWO DIMENTION MAIN MENU STYLE
	void PopulateMainMenuRes(void)
	{
	    U16 avzone_menu_item_count = 0;
	    /* On MT6217-series projects, it does not have video player and video recorder,
	       and we need to move 'multimedia' menu item to 'AV Zone' tab */
	    MMI_BOOL move_multimedia_to_avzone = MMI_FALSE;
	    
		/* First Level Main Menu */
		ADD_APPLICATION_MENUITEM((IDLE_SCREEN_MENU_ID,0,4,
			MAIN_MENU_AVZONE_MENU_ID,
			MAIN_MENU_PIM_MENU_ID,
			MAIN_MENU_ENTERTAINMENT_MENU_ID,
			MAIN_MENU_SYSTEM_MENU_ID,
			0,INSERTABLE,
			LIST_MATRIX_MENU,
			MAIN_MENU_MENU_TEXT,MAIN_MENU_PHONEBOOK_ICON));

		/* AV Zone */
    #if defined(__MMI_AUDIO_PLAYER__)
        avzone_menu_item_count++;
    #endif
    #if defined(__MMI_VIDEO_PLAYER__)
        avzone_menu_item_count++;
    #endif
    #if defined(__MMI_VIDEO_RECORDER__)
        avzone_menu_item_count++;
    #endif
    #if defined(__MMI_CAMERA__)
        avzone_menu_item_count++;
    #endif
    
        if (avzone_menu_item_count <= 2)
        {
            move_multimedia_to_avzone = MMI_TRUE;
            avzone_menu_item_count++;
        }

        if (move_multimedia_to_avzone)
        {
    		ADD_APPLICATION_MENUITEM((MAIN_MENU_AVZONE_MENU_ID,IDLE_SCREEN_MENU_ID,
                avzone_menu_item_count,
    		#if defined(__MMI_AUDIO_PLAYER__)
    			AUDIO_PLAYER_MAIN_MENUID,
    		#endif
    		#if defined(__MMI_VIDEO_PLAYER__)
    			MENU_ID_VDOPLY_APP,
    		#endif
    		#if defined(__MMI_VIDEO_RECORDER__)	
    			MENU_ID_VDOREC_APP,
    		#endif
    		#if defined(__MMI_CAMERA__)
    			MENU_ID_CAMERA_APP,
    		#endif
    		    MAIN_MENU_MULTIMEDIA_MENUID,
    			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_AVZONE_TEXT,MAIN_MENU_AVZONE_ICON));
        }
        else
        {
    		ADD_APPLICATION_MENUITEM((MAIN_MENU_AVZONE_MENU_ID,IDLE_SCREEN_MENU_ID,
                avzone_menu_item_count,
    		#if defined(__MMI_AUDIO_PLAYER__)
    			AUDIO_PLAYER_MAIN_MENUID,
    		#endif
    		#if defined(__MMI_VIDEO_PLAYER__)
    			MENU_ID_VDOPLY_APP,
    		#endif
    		#if defined(__MMI_VIDEO_RECORDER__)	
    			MENU_ID_VDOREC_APP,
    		#endif
    		#if defined(__MMI_CAMERA__)
    			MENU_ID_CAMERA_APP,
    		#endif
    			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_AVZONE_TEXT,MAIN_MENU_AVZONE_ICON));
    	}
		
		/* PIM */
		ADD_APPLICATION_MENUITEM((MAIN_MENU_PIM_MENU_ID,IDLE_SCREEN_MENU_ID,4,
			MAIN_MENU_PHONEBOOK_MENUID,
			MAIN_MENU_MESSAGES_MENUID,
	    #ifdef __MMI_UCM__
            MAIN_MENU_CALL_CENTER,
        #else /* __MMI_UCM__ */
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MAIN_MENU_CALL_HISTORY,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_CALL_HISTORY,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
	    #endif /* __MMI_UCM__ */
			MAIN_MENU_ORGANIZER_MENUID,
			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_PIM_TEXT,MAIN_MENU_PIM_ICON));

		/* Entertainment */
#ifdef __MMI_MESSAGES_CLUB__
		ADD_APPLICATION_MENUITEM((MAIN_MENU_ENTERTAINMENT_MENU_ID,IDLE_SCREEN_MENU_ID,5,
			MAIN_MENU_FUNANDGAMES_MENUID,
			MAIN_MENU_SERVICES_MENUID,
			MAIN_MENU_MULTIMEDIA_MENUID,
			MAIN_MENU_EXTRA_MENUID,
			MAIN_MENU_MSGCLUB_MENUID,
			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_ENTERTAINMENT_TEXT,MAIN_MENU_ENTERTAINMENT_ICON));
#else
        if (move_multimedia_to_avzone)
        {
    		ADD_APPLICATION_MENUITEM((MAIN_MENU_ENTERTAINMENT_MENU_ID,IDLE_SCREEN_MENU_ID,3,
    			MAIN_MENU_FUNANDGAMES_MENUID,
    			MAIN_MENU_SERVICES_MENUID,
    			MAIN_MENU_EXTRA_MENUID,
    			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_ENTERTAINMENT_TEXT,MAIN_MENU_ENTERTAINMENT_ICON));        
        }
        else
        {
    		ADD_APPLICATION_MENUITEM((MAIN_MENU_ENTERTAINMENT_MENU_ID,IDLE_SCREEN_MENU_ID,4,
    			MAIN_MENU_FUNANDGAMES_MENUID,
    			MAIN_MENU_SERVICES_MENUID,
    			MAIN_MENU_MULTIMEDIA_MENUID,
    			MAIN_MENU_EXTRA_MENUID,
    			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_ENTERTAINMENT_TEXT,MAIN_MENU_ENTERTAINMENT_ICON));
    	}
#endif

		/* System */
#ifndef __DISABLE_SHORTCUTS_MENU__
		ADD_APPLICATION_MENUITEM((MAIN_MENU_SYSTEM_MENU_ID,IDLE_SCREEN_MENU_ID,4,
			MAIN_MENU_SETTINGS_MENUID,
			MAIN_MENU_PROFILES_MENUID,
			EXTRA_SHORTCUTS_MENUID,
			MAIN_MENU_FILE_MNGR_MENUID,
			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_SYSTEM_TEXT,MAIN_MENU_SYSTEM_ICON));
#else
	ADD_APPLICATION_MENUITEM((MAIN_MENU_SYSTEM_MENU_ID,IDLE_SCREEN_MENU_ID,3,
			MAIN_MENU_SETTINGS_MENUID,
			MAIN_MENU_PROFILES_MENUID,
			MAIN_MENU_FILE_MNGR_MENUID,
			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_SYSTEM_TEXT,MAIN_MENU_SYSTEM_ICON));
#endif


			/* Phonebook */
			ADD_APPLICATION_MENUITEM((MAIN_MENU_PHONEBOOK_MENUID,MAIN_MENU_PIM_MENU_ID,MMI_PHB_MAIN_ENUM_TOTAL,
			#if defined(__MMI_PHB_QUICK_SEARCH__)
				MENU_ID_PHB_QUICK_SEARCH,		
			#endif
				MITEM101_PBOOK_SEARCH_ENTRY,
				MITEM102_PBOOK_NEW_ENTRY,
			#if defined(__MMI_PHB_MULTI_OPERATION__)
				MENU_ID_PHB_MULTI_OP,
			#else /* if defined(__MMI_PHB_MULTI_OPERATION__) */
				MITEM104_PBOOK_COPY_ALL,
				MITEM103_PBOOK_DELETE_ALL,
			#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
				MITEM109_PBOOK_CALLER_GROUPS,
				MENU_ID_PHB_EXTRA_NUMBER,
				MITEM110_PBOOK_SETTINGS,
			#if defined(__MMI_PHB_CALLER_RES_SETTING__)
				MENU_ID_PHB_CALLER_PIC,
				MENU_ID_PHB_CALLER_RING,
			#if defined(__MMI_INCOMING_CALL_VIDEO__)
				MENU_ID_PHB_CALLER_VIDEO,
			#endif
			#endif
				SHOW, MOVEABLEACROSSPARENT|INSERTABLE, DISP_LIST, MAIN_MENU_PHONEBOOK_TEXT,MAIN_MENU_PHONEBOOK_ICON));/*Manish*/

			/* phonebook for No SIM inserted mode- MTK 2005-09-03 Jo */
			ADD_APPLICATION_MENUITEM((MAIN_MENU_PHONEBOOK_NO_SIM_MENUID,MENU_SIM_OPTION_ID, MMI_PHB_MAIN_NO_SIM_ENUM_TOTAL,
			#if defined(__MMI_PHB_QUICK_SEARCH__)	
				MENU_ID_PHB_QUICK_SEARCH,		
			#endif
				MITEM101_PBOOK_SEARCH_ENTRY,
				MITEM102_PBOOK_NEW_ENTRY,
			#if defined(__MMI_PHB_MULTI_OPERATION__)
				MENU_ID_PHB_MULTI_OP,
			#else /* defined(__MMI_PHB_MULTI_OPERATION__) */
				MITEM103_PBOOK_DELETE_ALL,
			#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
				MITEM109_PBOOK_CALLER_GROUPS,
				MITEM110_PBOOK_SETTINGS_NO_SIM,
			#if defined(__MMI_PHB_CALLER_RES_SETTING__)
				MENU_ID_PHB_CALLER_PIC,
				MENU_ID_PHB_CALLER_RING,
			#if defined(__MMI_INCOMING_CALL_VIDEO__)
				MENU_ID_PHB_CALLER_VIDEO,
			#endif
			#endif
				SHOW, MOVEABLEACROSSPARENT|INSERTABLE, DISP_LIST, MAIN_MENU_PHONEBOOK_TEXT,MAIN_MENU_PHONEBOOK_ICON));


	/* messages */		/* defined in application */

	/* call history */
	ADD_APPLICATION_MENUITEM2((MAIN_MENU_CALL_HISTORY,
#ifndef __MMI_DUAL_SIM_MASTER__ 
        #ifdef __MMI_UCM__
		MAIN_MENU_CALL_CENTER,
	#else /*  __MMI_UCM__ */
		MAIN_MENU_PIM_MENU_ID,
	#endif /*  __MMI_UCM__ */
#else /* __MMI_DUAL_SIM_MASTER__  */
		MENU_MTPNP_DM_CALL_HISTORY,
#endif /* __MMI_DUAL_SIM_MASTER__  */
		MENU8103_MISSED_CALLS,MENU8102_DIALED_CALLS,	
		MENU8101_RECEIVED_CALLS, MENU8113_CALLHISTORY_RESETCALL,
		MENU_CALL_TIME_SETUP, MENU_CALL_HISTORY_CALLCOST,
		MENU_CALL_HISTORY_SMSCOUNTER,
#ifdef __MMI_GPRS_FEATURES__
		MENU_CALL_HISTORY_GPRSCOUNTER,
#endif
#ifdef __MMI_CH_QUICK_END__
#ifndef __MMI_UCM__
		MENU_CALL_HISTORY_QUICK_END,
#endif	/* __MMI_UCM__ */	
#endif	/* __MMI_CH_QUICK_END__ */	
                MENU_ITEM_END,
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,
#ifndef __MMI_DUAL_SIM_MASTER__ 
		MAIN_MENU_CALL_HISTORY_TEXT, 
#else /* __MMI_DUAL_SIM_MASTER__  */
		STRING_MTPNP_CARD1_CALL_HISTORY,
#endif /* __MMI_DUAL_SIM_MASTER__   */
#ifdef __MMI_UCM__
		IMG_ID_UCM_CALL_HISTORY
#else
		MAIN_MENU_CALL_HISTORY_ICON
#endif
        ));
	
	/* oganizer */
		ADD_APPLICATION_MENUITEM((MAIN_MENU_ORGANIZER_MENUID,MAIN_MENU_PIM_MENU_ID,ORG_ENUM_TOTAL,
				#if defined(__MMI_CALENDAR__)
					ORGANIZER_CALENDER_MENU,
				#endif
				#if defined(__MMI_TODOLIST__)
					ORGANIZER_TODOLIST_MENU,
				#endif
					ORGANIZER_ALARM_MENU,
					
				#if defined (__MMI_WORLD_CLOCK__)	
					ORGANIZER_WORLDCLOCK_MENU,
				#endif
					SHOW,MOVEABLEACROSSPARENT|INSERTABLE,DISP_LIST,
					MAIN_MENU_ORGANIZER_TEXT,MAIN_MENU_ORGANIZER_ICON));

	/* multimedia */ /* temporary */
		ADD_APPLICATION_MENUITEM2((MAIN_MENU_MULTIMEDIA_MENUID,
		    move_multimedia_to_avzone ? MAIN_MENU_AVZONE_MENU_ID : MAIN_MENU_ENTERTAINMENT_MENU_ID,

			#if defined(__MMI_MOBILE_TV_PLAYER__)
				MENU_ID_MOBILE_TV_PLAYER_APP,
			#endif

			#if defined(__MMI_IMAGE_VIEWER__)
				MENU_ID_IMGVIEW_APP,
			#endif	

			#if defined(__MMI_PHOTOEDITOR__)
				MENU_ID_PHOEDT_APP,
			#endif 

			#if defined(__MMI_BARCODEREADER__)
				MENU_ID_BARCODEREADER_APP,
			#endif
            
            #if defined(__MMI_VIDEO_EDITOR__)
                MENU_ID_VDOEDT_APP,
            #endif

//BUG MULTIMEDIA START 20050902
/*	Multimedia caption is not coming in the main menu,
	as there is a mismatch between MMEDIA_ENUM_TOTAL and number of Menu items. */
			#if defined(__MMI_AB_REPEATER__)
				MENU_ID_AB_REPEATER_MAIN,
			#endif
//BUG MULTIMEDIA END 20050902
			
			#if defined(__MMI_SOUND_RECORDER__) 
				MENU_ID_SNDREC_MAIN,
			#endif
			
			#if defined(__MMI_FM_RADIO__)
				MENU_ID_FMRDO_MAIN,
			#endif

			#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
				MENU_ID_FMSR_MAIN,
			#endif

                     /* hongzhe.liu add start */
                     #if defined(ANALOG_TV_SUPPORT)  
			       MENU_ID_ANALOG_TV_ENTRY,
      				#if defined(TV_RECORD_SUPPORT)
				//Huyanwei Add It 
				MENU_ID_ANALOG_TV_RECORD_ENTRY,
				#endif				
		       #endif
                     /* hongzhe.liu add end */
			   
			#if defined(__MMI_RING_COMPOSER__)	&& defined(__MMI_IMELODY_SUPPORT__) 
				MENU3103_RINGTONE_COMPOSER,
			#endif
			#if defined(__MMI_VOICE_MEMO__)
				MENU3104_VOICE_MEMO,
			#endif
			#if defined(__MMI_VRSD__)
				MENU_ID_VRSD_APP,
			#endif
			#if defined(__MMI_VRSI__)
				MENU_ID_VRSI_SETTING,
			#endif
                        #if defined(__MMI_SLIDESHOW__)
                                MENU_ID_SLIDSHOW_APP,
                        #endif
				MENU_ITEM_END,
			SHOW,MOVEABLEACROSSPARENT|INSERTABLE,1,MAIN_MENU_MMEDIA_TEXT
			,MAIN_MENU_MULTIMEDIA_ICON));

	/* multimedia in NO SIM option menu*/
	ADD_APPLICATION_MENUITEM((MAIN_MENU_OPTION_AVZONE_MENUID,MENU_SIM_OPTION_ID,4,

		#if defined(__MMI_CAMERA__)
			MAIN_MENU_OPTION_CAMERA_APP,
		#endif	

		#if defined(__MMI_VIDEO_RECORDER__)
			MAIN_MENU_OPTION_VDOREC_APP,
		#endif

		#if defined(__MMI_VIDEO_PLAYER__)
			MAIN_MENU_OPTION_VDOPLY_APP,
		#endif
		
		#if defined(__MMI_AUDIO_PLAYER__)
			MAIN_MENU_OPTION_AUDIO_PLAYER_APP,
		#endif
		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_AVZONE_TEXT
		,MAIN_MENU_MULTIMEDIA_ICON));
		
	/* profiles */	/* defined in application */

	/* fun and games */
		ADD_APPLICATION_MENUITEM((MAIN_MENU_FUNANDGAMES_MENUID,MAIN_MENU_ENTERTAINMENT_MENU_ID,FUN_ENUM_TOTAL,
			#if defined(__J2ME__)
				MENU3108_JAVA,
				MENU_ID_FNG_SETTING_JAVA,
                #ifdef OGDR_SECURITY_SETTING
				MENU_ID_FNG_SECURITY_JAVA,
				#endif

                #ifdef __SUPPORT_INFUSIO__
                MENU_ID_FNG_JAVA_EUREKA,
                #endif
			#endif

			#if defined(__MMI_GAME__) 
				MENU3105_GAMES,
			#endif
			#if defined(__MMI_3D_GAME__) 
				MENU_ID_FNG_3D_GAME,
			#endif			
			#if defined(__MMI_MOTION_APP__) 
				MENU_ID_MOTION_APP,
			#endif 
			#if defined (__MMI_THEMES_APPLICATION__)
				MENU3101_THEMES,
			#endif

			#if defined(__MMI_PICTURE_EDITOR_SUPPORT__)
				
			MENU_PICTURE_EDITOR,
			#endif

            #if defined(__MMI_AVATAR__)
                MENU_ID_AVATAR_EDITOR,
            #endif

			SHOW,MOVEABLEACROSSPARENT|INSERTABLE,1,MAIN_MENU_FUNANDGAMES_TEXT
			,MAIN_MENU_FUNANDGAMES_ICON));

		ADD_APPLICATION_MENUITEM2((MAIN_MENU_SERVICES_MENUID,MAIN_MENU_ENTERTAINMENT_MENU_ID,
#ifdef WAP_SUPPORT
				SERVICES_WAP_MENU_ID,
#endif
#ifdef __SYNCML_SUPPORT__
				MENU_ID_SYNCML_MAIN,
#endif
#ifdef __MMI_VOIP__
#ifndef __MMI_UCM__
                                MENU_ID_VOIP_MAIN,
#endif /* __MMI_UCM__ */                               
#endif /* __MMI_VOIP__ */
#ifdef __MMI_POC__
                                MENU_ID_POC_MAIN,
#endif
#if defined(WAP_SUPPORT) && defined(__TCPIP__)
                                SERVICES_DATA_CONNECT_MAIN_MENU_ID,
#endif
#if defined(__FOTA_ENABLE__)
                                SERVICES_FWU_MENU_ID,
#endif
#ifdef __MMI_RMGR__
                                MENU_ID_RMGR,
#endif                                
#if defined (SYNCML_DM_SUPPORT)
                                MENU_ID_DMUI_MAIN,
#endif    
                            #if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__)
                                MENU_ID_GIS,
                            #endif

                                SERVICES_INFO_NUM_MENU_ID,
                                MENU_ITEM_END,
				SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_SERVICES_TEXT,MAIN_MENU_SERVICES_ICON));

	/* extra */
		ADD_APPLICATION_MENUITEM((MAIN_MENU_EXTRA_MENUID,MAIN_MENU_ENTERTAINMENT_MENU_ID,EXTRA_ENUM_TOTAL,
				#if defined (__MMI_CALCULATOR__)
					EXTRA_CALCULATOR_MENU,
				#endif
				#if defined (__MMI_UNIT_CONVERTER__)	|| defined	(__MMI_EXTENDED_UNIT_CONVERTER__)
					EXTRA_UNITCONVERTOR_MENU,
				#endif
				#if defined (__MMI_CURRENCY_CONVERTER__) || defined	(__MMI_EXTENDED_CURRENCY_CONVERTER__)
					EXTRA_CURRENCYCONVERTOR_MENU,
				#endif
				#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__) || defined(__MMI_CALORIE__)
					EXTRA_HEALTH_MENU,
				#endif

                                #if defined( __MMI_STOPWATCH__)        
        	                        MENU_STOPWATCH,
        	                #endif                  
				#if defined(__MMI_APHORISM__)
/* under construction !*/
				#endif
				#if defined(__MMI_DICTIONARY__)
					EXTRA_DICTIONARY_MENU,
				#endif
				#if defined(__MMI_EBOOK_READER__)
					MAIN_MENU_EBOOK_MENUID,
				#endif
				#if defined(__MMI_IRDA_SUPPORT__)
					MENU_CONN_IRDA_MAIN,
				#endif
				#if defined(__MMI_BT_SUPPORT__)
					MENU_CONN_BT_MAIN,
				#endif
                		#if defined(__MMI_LANGLN__)
                			MENU_ID_LANGLN,
                		#endif

					SHOW,MOVEABLEACROSSPARENT|INSERTABLE,DISP_LIST,
					MAIN_MENU_EXTRA_TEXT,MAIN_MENU_EXTRA_ICON));

	/* Message Club */
	#ifdef __MMI_MESSAGES_CLUB__
		ADD_APPLICATION_MENUITEM((MAIN_MENU_MSGCLUB_MENUID,MAIN_MENU_ENTERTAINMENT_MENU_ID,0,SHOW,SHORTCUTABLE,1,
			STR_MSG_CLUB,MAIN_MENU_SHORTCUTS_ICON));
	#endif

	/* settings */
		ADD_APPLICATION_MENUITEM2((MAIN_MENU_SETTINGS_MENUID,MAIN_MENU_SYSTEM_MENU_ID,
		#ifdef __MMI_DUAL_SIM_MASTER__ 
			MENU_MTPNP_DM_SETTING,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
	    #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
			MENU_SETTING_CALIBRATION,
	    #endif
			MENU9102_INITIAL_SETUP,
		#ifndef __MMI_UCM__
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MENU8237_SCR8093_MNGCALL_MENU_MAIN,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_CALL_SETTING,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
	    #endif /* __MMI_UCM__ */
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MENU9185_NETWORK_SETUP,
			MENU9101_SECURITY,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_NETWORK_SETUP,
			MENU_MTPNP_DM_SECURITY_SETTING,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
			MENU_SETTING_RESTORE,
	#ifdef __MMI_SOUND_EFFECT__
			MENU_SETTING_SOUND_EFFECT,
	#endif
            MENU_ITEM_END,
			0,MOVEABLEACROSSPARENT|INSERTABLE,1,MAIN_MENU_SETTINGS_TEXT,
			MAIN_MENU_SETTINGS_ICON));

/* diamond, 2005/12/23 Phone setup in option menu */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_SETTINGS_NO_SIM_MENUID,MENU_SIM_OPTION_ID,
#ifdef __MMI_DUAL_SIM_MASTER__ 
			1 +
#endif /* __MMI_DUAL_SIM_MASTER__  */
#ifdef __MMI_SOUND_EFFECT__
			1 + 
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
			1 + 
#endif
#ifdef __MMI_WLAN_FEATURES__
			1 + 
#endif
			3,
#ifdef __MMI_DUAL_SIM_MASTER__ 
			MENU_MTPNP_DM_SETTING,
#endif /* __MMI_DUAL_SIM_MASTER__  */
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
			MENU_SETTING_CALIBRATION,
#endif
			MENU9102_INITIAL_SETUP,
#ifdef __MMI_WLAN_FEATURES__
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MENU9185_NETWORK_SETUP,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_NETWORK_SETUP,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
#endif
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MENU9101_SECURITY,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_SECURITY_SETTING,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
			MENU_SETTING_RESTORE,
#ifdef __MMI_SOUND_EFFECT__
			MENU_SETTING_SOUND_EFFECT,
#endif
			0,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_SETTINGS_TEXT,
			MAIN_MENU_SETTINGS_ICON));
/* end, diamond */

	/* profiles */	/* defined in application */

	/* shortcuts */
#ifndef __DISABLE_SHORTCUTS_MENU__
		ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_MENUID,MAIN_MENU_SYSTEM_MENU_ID,0,SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,
			MAIN_MENU_SHORTCUTS_TEXT,MAIN_MENU_SHORTCUTS_ICON));
#endif


	/* file manager */
		ADD_APPLICATION_MENUITEM((MAIN_MENU_FILE_MNGR_MENUID,MAIN_MENU_SYSTEM_MENU_ID,0,
			SHOW,MOVEABLEACROSSPARENT|INSERTABLE,1,MAIN_MENU_FILE_MNGR_TEXT
			,MAIN_MENU_FILEMNGR_ICON));

/* Images */
		ADD_APPLICATION_IMAGE2(MAIN_MENU_AVZONE_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_AV.png" , "Icon used for avzone in mainmenu");
		ADD_APPLICATION_IMAGE2(MAIN_MENU_PIM_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_PI.png" , "Icon used for pim in mainmenu");
		ADD_APPLICATION_IMAGE2(MAIN_MENU_ENTERTAINMENT_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_EN.png" , "Icon used for entertainment in mainmenu");
		ADD_APPLICATION_IMAGE2(MAIN_MENU_SYSTEM_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_SY.png" , "Icon used for system in mainmenu");

		ADD_APPLICATION_IMAGE2(MAIN_MENU_AVZONE_ICON_SELECTED, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_AV_H.png" , "Icon used for avzone in mainmenu");
		ADD_APPLICATION_IMAGE2(MAIN_MENU_PIM_ICON_SELECTED, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_PI_H.png" , "Icon used for pim in mainmenu");
		ADD_APPLICATION_IMAGE2(MAIN_MENU_ENTERTAINMENT_ICON_SELECTED, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_EN_H.png" , "Icon used for entertainment in mainmenu");
		ADD_APPLICATION_IMAGE2(MAIN_MENU_SYSTEM_ICON_SELECTED, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_SY_H.png" , "Icon used for system in mainmenu");    

		ADD_APPLICATION_IMAGE(MAIN_MENU_PHONEBOOK_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_PB.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_MG.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_CA.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_ST.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_MM.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_FILEMNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_FM.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_FG.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_PR.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_OR.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_SV.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_EXTRA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_EX.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_SC.gif");

		ADD_APPLICATION_IMAGE(MAIN_MENU_CAMERA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_CM.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_VDOREC_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_VR.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_VDOPLY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_VP.gif");
		ADD_APPLICATION_IMAGE(MAIN_MENU_AUDPLY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_AP.gif");

        ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_CAMERA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MM.PBM");
        ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_VDOREC_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MM.PBM");
        ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_VDOPLY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MM.PBM");
        ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_AUDPLY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MM.PBM");

		/* No SIM Option Menu */
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_PHONEBOOK_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_PB.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MG.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_FG.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_OR.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_ST.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\tb_pr.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SC.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MM.PBM");
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_FILE_MNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_FM.PBM");
#if defined(__MMI_VERSION_2__)
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_EXTRA_APP_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_EX.PBM");
#endif
		ADD_APPLICATION_IMAGE(IMG_ID_FNG_FMGR_SUB_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\SB_FM.pbm");		

/* Strings */
		ADD_APPLICATION_STRING2(MAIN_MENU_AVZONE_TEXT,"AV Zone","String for AV zone in mainmenu");
		ADD_APPLICATION_STRING2(MAIN_MENU_PIM_TEXT,"PIM","String for PIM in mainmenu");
		ADD_APPLICATION_STRING2(MAIN_MENU_ENTERTAINMENT_TEXT,"Entertainment","String for Entertainment in mainmenu");
		ADD_APPLICATION_STRING2(MAIN_MENU_SYSTEM_TEXT,"System","String for System in mainmenu");

		ADD_APPLICATION_STRING2(MAIN_MENU_CAMERA_TEXT,"Camera","String for Camera in mainmenu");
		ADD_APPLICATION_STRING2(MAIN_MENU_VDOREC_TEXT,"Video Recorder","String for Video Recorder in mainmenu");
		ADD_APPLICATION_STRING2(MAIN_MENU_VDOPLY_TEXT,"Video Player","String for Video Player in mainmenu");
		ADD_APPLICATION_STRING2(MAIN_MENU_AUDPLY_TEXT,"Audio Player","String for Audio Player in mainmenu");

		/*	string definitions */
		ADD_APPLICATION_STRING(MAIN_MENU_MENU_TEXT,"Menu");
		ADD_APPLICATION_STRING(MAIN_MENU_TITLE_TEXT,"Main Menu");
		ADD_APPLICATION_STRING(MAIN_MENU_PHONEBOOK_TEXT,"PhoneBook");
		ADD_APPLICATION_STRING(MAIN_MENU_MESSAGES_TEXT,"Messages");
		ADD_APPLICATION_STRING(MAIN_MENU_FUNANDGAMES_TEXT,"Fun & Games");
		ADD_APPLICATION_STRING(MAIN_MENU_ORGANIZER_TEXT,"Organizer");
		ADD_APPLICATION_STRING(MAIN_MENU_PROFILES_TEXT,"User Profiles");
		ADD_APPLICATION_STRING(MAIN_MENU_SETTINGS_TEXT,"Settings");
		ADD_APPLICATION_STRING(MAIN_MENU_SHORTCUTS_TEXT,"Shortcuts");
		ADD_APPLICATION_STRING(MAIN_MENU_SERVICES_TEXT,"Services");
		ADD_APPLICATION_STRING(MAIN_MENU_CALL_HISTORY_TEXT,"Call History");
		ADD_APPLICATION_STRING2(MAIN_MENU_FILE_MNGR_TEXT,"File Manager","File Manager menu title");
		ADD_APPLICATION_STRING2(MAIN_MENU_MMEDIA_TEXT,"Multimedia","Multimedia menu title");
		ADD_APPLICATION_STRING2(MAIN_MENU_EXTRA_TEXT,"Extra","Extra menu title");

		/* images */
		ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_ICON, CUST_IMG_BASE_PATH"\\\\NoImage.bmp");
		ADD_APPLICATION_IMAGE(MAIN_MENU_AVZONE_TITLE,CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Funandgame\\\\SB_AVZone.pbm");
	}

#else/* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */
#if defined(__MMI_VERSION_2__)	/* Max 0224 */
void PopulateMainMenuRes(void)
{
#ifdef __MMI_SUBLCD_MASTER_MODE__
	ADD_APPLICATION_MENUITEM((MENU_ID_SUB_MAIN_MENU,0,MMI_SUB_MAIN_ENUM_TOTAL,

		#if defined(__MMI_AUDIO_PLAYER__)
			MENU_ID_SUB_AUDPLY,
		#endif
				
		#if defined(__MMI_FM_RADIO__)
			MENU_ID_SUB_FMRADIO,
		#endif

		SHOW,INSERTABLE,LIST_MENU,MAIN_MENU_MENU_TEXT
		,NULL));
        
	#if defined(__MMI_AUDIO_PLAYER__)
    	ADD_APPLICATION_MENUITEM((MENU_ID_SUB_AUDPLY, MENU_ID_SUB_MAIN_MENU, 0,
    		SHOW, NONMOVEABLE | SHORTCUTABLE, 0, STR_ID_AUDPLY_TITLE, IMG_ID_AUDPLY_ICON));
	#endif
    
	#if defined(__MMI_FM_RADIO__)
    	ADD_APPLICATION_MENUITEM((MENU_ID_SUB_FMRADIO, MENU_ID_SUB_MAIN_MENU, 0,
    		SHOW, MOVEABLEACROSSPARENT | SHORTCUTABLE, 0, STR_ID_FMRDO_TITLE, IMG_ID_FMRDO_APP ));
	#endif
#endif /*__MMI_SUBLCD_MASTER_MODE__*/


	/* main menu */
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__

	ADD_APPLICATION_MENUITEM((IDLE_SCREEN_MENU_ID,0,12,
		MAIN_MENU_PHONEBOOK_MENUID, 
		MAIN_MENU_MESSAGES_MENUID,
	#ifdef __MMI_UCM__
        MAIN_MENU_CALL_CENTER,
    #else /* __MMI_UCM__ */
	#ifndef __MMI_DUAL_SIM_MASTER__ 
		MAIN_MENU_CALL_HISTORY,
	#else /* __MMI_DUAL_SIM_MASTER__  */
		MENU_MTPNP_DM_CALL_HISTORY,
	#endif /* __MMI_DUAL_SIM_MASTER__  */
	#endif /* __MMI_UCM__ */
		MAIN_MENU_SETTINGS_MENUID, 
		MAIN_MENU_MULTIMEDIA_MENUID,
		MAIN_MENU_FILE_MNGR_MENUID,
		MAIN_MENU_FUNANDGAMES_MENUID,
		MAIN_MENU_PROFILES_MENUID, 
		MAIN_MENU_ORGANIZER_MENUID,
		MAIN_MENU_SERVICES_MENUID,
		MAIN_MENU_EXTRA_MENUID,
		#ifdef __MMI_MESSAGES_CLUB__
		MAIN_MENU_MSGCLUB_MENUID,
		#else
		EXTRA_SHORTCUTS_MENUID, 		
		#endif
		0,INSERTABLE,
		MATRIX_MENU /* CHANGABLE MENU STYLE -- DO NOT CHANGE MENU TYPE HERE!!! */,
		MAIN_MENU_MENU_TEXT,MAIN_MENU_PHONEBOOK_ICON));

	
         


#else /* !__MMI_MAINMENU_STYLE_CHANGE_EN__ */

	ADD_APPLICATION_MENUITEM((IDLE_SCREEN_MENU_ID,0,12,
		MAIN_MENU_PHONEBOOK_MENUID, 
		MAIN_MENU_MESSAGES_MENUID,
	#ifdef __MMI_UCM__
    	MAIN_MENU_CALL_CENTER,
    #else /* __MMI_UCM__ */
	#ifndef __MMI_DUAL_SIM_MASTER__ 
		MAIN_MENU_CALL_HISTORY,
	#else /* __MMI_DUAL_SIM_MASTER__  */
		MENU_MTPNP_DM_CALL_HISTORY,
	#endif /* __MMI_DUAL_SIM_MASTER__  */
    #endif /* __MMI_UCM__ */
		MAIN_MENU_SETTINGS_MENUID, 
		MAIN_MENU_MULTIMEDIA_MENUID,
		MAIN_MENU_FILE_MNGR_MENUID,
		MAIN_MENU_FUNANDGAMES_MENUID,
		MAIN_MENU_PROFILES_MENUID, 
		MAIN_MENU_ORGANIZER_MENUID,
		MAIN_MENU_SERVICES_MENUID,
		MAIN_MENU_EXTRA_MENUID,
		#ifdef __MMI_MESSAGES_CLUB__
		MAIN_MENU_MSGCLUB_MENUID,
		#else
		EXTRA_SHORTCUTS_MENUID, 		
		#endif
		0,INSERTABLE,TYPE(__MMI_MAINMENU_TYPE__),MAIN_MENU_MENU_TEXT,MAIN_MENU_PHONEBOOK_ICON));

#endif  /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */


	/* phonebook */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_PHONEBOOK_MENUID,IDLE_SCREEN_MENU_ID,MMI_PHB_MAIN_ENUM_TOTAL,
#if defined(__MMI_PHB_QUICK_SEARCH__)	
		MENU_ID_PHB_QUICK_SEARCH,		
#endif
		MITEM101_PBOOK_SEARCH_ENTRY,
		MITEM102_PBOOK_NEW_ENTRY,
#if defined(__MMI_PHB_MULTI_OPERATION__)
		MENU_ID_PHB_MULTI_OP,
#else /* defined(__MMI_PHB_MULTI_OPERATION__) */
		MITEM104_PBOOK_COPY_ALL,		
		MITEM103_PBOOK_DELETE_ALL,
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
		MITEM109_PBOOK_CALLER_GROUPS,
		MENU_ID_PHB_EXTRA_NUMBER,
		MITEM110_PBOOK_SETTINGS,
#if defined(__MMI_PHB_CALLER_RES_SETTING__)
		MENU_ID_PHB_CALLER_PIC,
		MENU_ID_PHB_CALLER_RING,
#if defined(__MMI_INCOMING_CALL_VIDEO__)
		MENU_ID_PHB_CALLER_VIDEO,
#endif
#endif
		SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, MAIN_MENU_PHONEBOOK_TEXT,MAIN_MENU_PHONEBOOK_ICON));

	/* phonebook for No SIM inserted mode- MTK 2005-09-03 Jo */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_PHONEBOOK_NO_SIM_MENUID,MENU_SIM_OPTION_ID, MMI_PHB_MAIN_NO_SIM_ENUM_TOTAL,
#if defined(__MMI_PHB_QUICK_SEARCH__)	
		MENU_ID_PHB_QUICK_SEARCH,		
#endif
		MITEM101_PBOOK_SEARCH_ENTRY,
		MITEM102_PBOOK_NEW_ENTRY,
#if defined(__MMI_PHB_MULTI_OPERATION__)
		MENU_ID_PHB_MULTI_OP,
#else /* defined(__MMI_PHB_MULTI_OPERATION__) */
		MITEM103_PBOOK_DELETE_ALL,
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
		MITEM109_PBOOK_CALLER_GROUPS,
		MITEM110_PBOOK_SETTINGS_NO_SIM,
#if defined(__MMI_PHB_CALLER_RES_SETTING__)
		MENU_ID_PHB_CALLER_PIC,
		MENU_ID_PHB_CALLER_RING,
#if defined(__MMI_INCOMING_CALL_VIDEO__)
		MENU_ID_PHB_CALLER_VIDEO,
#endif
#endif
		SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, MAIN_MENU_PHONEBOOK_TEXT,MAIN_MENU_PHONEBOOK_ICON));

	/* messages */		/* defined in application */

	/* call history */
	ADD_APPLICATION_MENUITEM2((MAIN_MENU_CALL_HISTORY,
#ifndef __MMI_DUAL_SIM_MASTER__ 
        #ifdef __MMI_UCM__
		MAIN_MENU_CALL_CENTER,
	#else /*  __MMI_UCM__ */
		IDLE_SCREEN_MENU_ID,
	#endif /*  __MMI_UCM__ */
#else /* __MMI_DUAL_SIM_MASTER__  */
		MENU_MTPNP_DM_CALL_HISTORY,
#endif /* __MMI_DUAL_SIM_MASTER__  */
		MENU8103_MISSED_CALLS,MENU8102_DIALED_CALLS,	
		MENU8101_RECEIVED_CALLS, MENU8113_CALLHISTORY_RESETCALL,
		MENU_CALL_TIME_SETUP, MENU_CALL_HISTORY_CALLCOST,
		MENU_CALL_HISTORY_SMSCOUNTER,
#ifdef __MMI_GPRS_FEATURES__
		MENU_CALL_HISTORY_GPRSCOUNTER,
#endif
#ifdef __MMI_CH_QUICK_END__
#ifndef __MMI_UCM__
		MENU_CALL_HISTORY_QUICK_END,
#endif	/* __MMI_UCM__ */	
#endif	/* __MMI_CH_QUICK_END__ */	
		MENU_ITEM_END,	
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,
#ifndef __MMI_DUAL_SIM_MASTER__ 
		MAIN_MENU_CALL_HISTORY_TEXT, 
#else /* __MMI_DUAL_SIM_MASTER__  */
		STRING_MTPNP_CARD1_CALL_HISTORY,
#endif /* __MMI_DUAL_SIM_MASTER__  */
#ifdef __MMI_UCM__
		IMG_ID_UCM_CALL_HISTORY
#else
		MAIN_MENU_CALL_HISTORY_ICON
#endif
		));

	/* settings */
	ADD_APPLICATION_MENUITEM2((MAIN_MENU_SETTINGS_MENUID,IDLE_SCREEN_MENU_ID,
	#if defined(G_SENSOR_SUPPORT)
	//Huyanwei Add It 
		MENU_ID_GSENSOR_0,
	#endif
	#if defined(HORSERACE_SUPPORT)
		MENU_ID_HORSERACE_0,
	#endif
	
		#ifdef __MMI_DUAL_SIM_MASTER__ 
			MENU_MTPNP_DM_SETTING,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
			MENU_SETTING_CALIBRATION,
#endif
			MENU9102_INITIAL_SETUP,
        #ifndef __MMI_UCM__
		#ifndef __MMI_DUAL_SIM_MASTER__   
			MENU8237_SCR8093_MNGCALL_MENU_MAIN,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_CALL_SETTING,
		#endif /*__MMI_DUAL_SIM_MASTER__ */
	#endif /* __MMI_UCM__ */
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MENU9185_NETWORK_SETUP,
			MENU9101_SECURITY,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_NETWORK_SETUP,
			MENU_MTPNP_DM_SECURITY_SETTING,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
			MENU_SETTING_RESTORE,
#ifdef __MMI_SOUND_EFFECT__
			MENU_SETTING_SOUND_EFFECT,
#endif
            MENU_ITEM_END,
			0,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_SETTINGS_TEXT,
			MAIN_MENU_SETTINGS_ICON));

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
	ADD_APPLICATION_MENUITEM2((MENU_ID_GSENSOR_0,MAIN_MENU_SETTINGS_MENUID,
		     MENU_ID_GSENSOR_3,
		     MENU_ID_GSENSOR_1,
		     MENU_ID_GSENSOR_2,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,G_SENSOR_STRING,G_SENSOR_IMAGE));
	ADD_APPLICATION_STRING(G_SENSOR_STRING, "G Sensor");	
	ADD_APPLICATION_IMAGE(G_SENSOR_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_SPH.PBM");
	
	ADD_APPLICATION_MENUITEM2((MENU_ID_GSENSOR_1,MENU_ID_GSENSOR_0,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,G_SENSOR_ON_STRING,G_SENSOR_ON_IMAGE));
	ADD_APPLICATION_STRING(G_SENSOR_ON_STRING, "On ");
	ADD_APPLICATION_IMAGE(G_SENSOR_ON_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\L_NB2.PBM");	

	ADD_APPLICATION_MENUITEM2((MENU_ID_GSENSOR_2,MENU_ID_GSENSOR_0,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,G_SENSOR_OFF_STRING,G_SENSOR_OFF_IMAGE));
	ADD_APPLICATION_STRING(G_SENSOR_OFF_STRING, "Off");	
	ADD_APPLICATION_IMAGE(G_SENSOR_OFF_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\L_NB3.PBM");		

	ADD_APPLICATION_MENUITEM2((MENU_ID_GSENSOR_3,MENU_ID_GSENSOR_0,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,G_SENSOR_CALIBRATION_STRING,G_SENSOR_CALIBRATION_IMAGE));
	ADD_APPLICATION_STRING(G_SENSOR_CALIBRATION_STRING, "Calibration");	
	ADD_APPLICATION_IMAGE(G_SENSOR_CALIBRATION_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\L_NB1.PBM");	


	ADD_APPLICATION_STRING(G_SENSOR_CALIBRATION_DES_STRNG, "Please keep this Phone flat ,then press OK Key to Calibrante G sensor ,press back key to exit this menu.");	
	
#endif

#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
	ADD_APPLICATION_MENUITEM2((MENU_ID_HORSERACE_0,MAIN_MENU_SETTINGS_MENUID,
		     MENU_ID_HORSERACE_1,
		     MENU_ID_HORSERACE_2,
		     MENU_ID_HORSERACE_3,
		     MENU_ID_HORSERACE_4,
		     MENU_ID_HORSERACE_5,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,HORSERACE_STRING,HORSERACE_IMAGE));
	ADD_APPLICATION_STRING(HORSERACE_STRING, "Colorful LED");
	ADD_APPLICATION_IMAGE(HORSERACE_IMAGE, CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_SPH.PBM");

	ADD_APPLICATION_MENUITEM2((MENU_ID_HORSERACE_1,MENU_ID_HORSERACE_0,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,HORSERACE_DEFAULT_STRING,HORSERACE_DEFAULT_IMAGE));
	ADD_APPLICATION_STRING(HORSERACE_DEFAULT_STRING, "Default");
	ADD_APPLICATION_IMAGE(HORSERACE_DEFAULT_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\L_NB1.PBM");

	ADD_APPLICATION_MENUITEM2((MENU_ID_HORSERACE_2,MENU_ID_HORSERACE_0,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,HORSERACE_RULE1_STRING,HORSERACE_RULE1_IMAGE));
	ADD_APPLICATION_STRING(HORSERACE_RULE1_STRING, "Rule 1");
	ADD_APPLICATION_IMAGE(HORSERACE_RULE1_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\L_NB2.PBM");

	ADD_APPLICATION_MENUITEM2((MENU_ID_HORSERACE_3,MENU_ID_HORSERACE_0,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,HORSERACE_RULE2_STRING,HORSERACE_RULE2_IMAGE));
	ADD_APPLICATION_STRING(HORSERACE_RULE2_STRING, "Rule 2");
	ADD_APPLICATION_IMAGE(HORSERACE_RULE2_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\L_NB3.PBM");	

	ADD_APPLICATION_MENUITEM2((MENU_ID_HORSERACE_4,MENU_ID_HORSERACE_0,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,HORSERACE_RULE3_STRING,HORSERACE_RULE3_IMAGE));
	ADD_APPLICATION_STRING(HORSERACE_RULE3_STRING, "Rule 3");
	ADD_APPLICATION_IMAGE(HORSERACE_RULE3_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\L_NB4.PBM");		

	ADD_APPLICATION_MENUITEM2((MENU_ID_HORSERACE_5,MENU_ID_HORSERACE_0,
	            MENU_ITEM_END,0,MOVEABLEWITHINPARENT|INSERTABLE,1,HORSERACE_OFF_STRING,HORSERACE_OFF_IMAGE));
	ADD_APPLICATION_STRING(HORSERACE_OFF_STRING, "OFF");
	ADD_APPLICATION_IMAGE(HORSERACE_OFF_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\L_NB5.PBM");		

#endif

	
/* diamond, 2005/12/23 Phone setup in option menu */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_SETTINGS_NO_SIM_MENUID,MENU_SIM_OPTION_ID,
#ifdef __MMI_DUAL_SIM_MASTER__ 
			1 +
#endif /* __MMI_DUAL_SIM_MASTER__  */
#ifdef __MMI_SOUND_EFFECT__
			1 + 
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
			1 + 
#endif
#ifdef __MMI_WLAN_FEATURES__
			1 + 
#endif
			3,
#ifdef __MMI_DUAL_SIM_MASTER__ 
			MENU_MTPNP_DM_SETTING,
#endif /* __MMI_DUAL_SIM_MASTER__ */
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
			MENU_SETTING_CALIBRATION,
#endif
			MENU9102_INITIAL_SETUP,
#ifdef __MMI_WLAN_FEATURES__
		#ifndef __MMI_DUAL_SIM_MASTER__ 
                        MENU9185_NETWORK_SETUP,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_NETWORK_SETUP,
		#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MENU9101_SECURITY,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_SECURITY_SETTING,
		#endif /*__MMI_DUAL_SIM_MASTER__  */
			MENU_SETTING_RESTORE,
#ifdef __MMI_SOUND_EFFECT__
			MENU_SETTING_SOUND_EFFECT,
#endif
			0,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_SETTINGS_TEXT,
			MAIN_MENU_SETTINGS_ICON));
/* end, diamond */

	/* multimedia */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_MULTIMEDIA_MENUID,IDLE_SCREEN_MENU_ID,MMEDIA_ENUM_TOTAL,

		   /* hongzhe.liu add start */
                    #if defined(ANALOG_TV_SUPPORT)  
			       MENU_ID_ANALOG_TV_ENTRY,
				#if defined(TV_RECORD_SUPPORT)
				//Huyanwei Add It 
				MENU_ID_ANALOG_TV_RECORD_ENTRY,
				#endif				
		       #endif
                /* hongzhe.liu add end */

		#if defined(__MMI_MOBILE_TV_PLAYER__)
			MENU_ID_MOBILE_TV_PLAYER_APP,
		#endif

		#if defined(__MMI_CAMERA__)
			MENU_ID_CAMERA_APP,
		#endif

		#if defined(__MMI_IMAGE_VIEWER__)
			MENU_ID_IMGVIEW_APP,
		#endif	

		#if defined(__MMI_VIDEO_RECORDER__)
			MENU_ID_VDOREC_APP,
		#endif
		
		#if defined(__MMI_VIDEO_PLAYER__)
			MENU_ID_VDOPLY_APP,
		#endif


        #if defined(__MMI_VIDEO_EDITOR__)
            MENU_ID_VDOEDT_APP,
        #endif

        #if defined(__MMI_BARCODEREADER__)
            MENU_ID_BARCODEREADER_APP,
        #endif
        
		#if defined(__MMI_PHOTOEDITOR__)
			MENU_ID_PHOEDT_APP,
		#endif 

		#if defined(__MMI_AUDIO_PLAYER__)
			AUDIO_PLAYER_MAIN_MENUID,
		#endif
		
		#if defined(__MMI_AB_REPEATER__)
			MENU_ID_AB_REPEATER_MAIN,
		#endif
		
		#if defined(__MMI_SOUND_RECORDER__) 
			MENU_ID_SNDREC_MAIN,
		#endif
		
		#if defined(__MMI_FM_RADIO__)
			MENU_ID_FMRDO_MAIN,
		#endif

		#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
			MENU_ID_FMSR_MAIN,
		#endif                 

		#if defined(__MMI_RING_COMPOSER__)	&& defined(__MMI_IMELODY_SUPPORT__) 
			MENU3103_RINGTONE_COMPOSER,
		#endif
		#if defined(__MMI_VOICE_MEMO__)
			MENU3104_VOICE_MEMO,
		#endif
		#if defined(__MMI_VRSD__)
			MENU_ID_VRSD_APP,
		#endif
		#if defined(__MMI_VRSI__)
			MENU_ID_VRSI_SETTING,
		#endif
                #if defined(__MMI_SLIDESHOW__)
                        MENU_ID_SLIDSHOW_APP,
                #endif
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_MMEDIA_TEXT
		,MAIN_MENU_MULTIMEDIA_ICON));

	/* file manager */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_FILE_MNGR_MENUID,IDLE_SCREEN_MENU_ID,0,
		SHOW,MOVEABLEWITHINPARENT,1,MAIN_MENU_FILE_MNGR_TEXT
		,MAIN_MENU_FILEMNGR_ICON));
	
	/* fun and games */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_FUNANDGAMES_MENUID,IDLE_SCREEN_MENU_ID,FUN_ENUM_TOTAL,
		#if defined(__J2ME__)
			MENU3108_JAVA,
			MENU_ID_FNG_SETTING_JAVA,
            #ifdef OGDR_SECURITY_SETTING
			MENU_ID_FNG_SECURITY_JAVA,
			#endif

            #ifdef __SUPPORT_INFUSIO__
            MENU_ID_FNG_JAVA_EUREKA,
            #endif
		#endif

		#if defined(__MMI_GAME__) 
			MENU3105_GAMES,
		#endif 
		#if defined(GSENSOR_GAME_SUPPORT)
		//HUyanwei Add it 
			MENU_ID_GSENSOR_GAME,
		#endif
		#if defined(__MMI_3D_GAME__) 
			MENU_ID_FNG_3D_GAME,
		#endif 		
		#if defined(__MMI_MOTION_APP__) 
			MENU_ID_MOTION_APP,
		#endif 		
		#if defined (__MMI_THEMES_APPLICATION__)
			MENU3101_THEMES,
		#endif

		#if defined(__MMI_PICTURE_EDITOR_SUPPORT__)
			MENU_PICTURE_EDITOR,
		#endif

        #if defined(__MMI_AVATAR__)
            MENU_ID_AVATAR_EDITOR,
        #endif

		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_FUNANDGAMES_TEXT
		,MAIN_MENU_FUNANDGAMES_ICON));
		
	/* profiles */	/* defined in application */
	

	/* oganizer */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_ORGANIZER_MENUID,IDLE_SCREEN_MENU_ID,ORG_ENUM_TOTAL,
			#if defined(__MMI_CALENDAR__)
				ORGANIZER_CALENDER_MENU,
			#endif
			#if defined(__MMI_TODOLIST__)
				ORGANIZER_TODOLIST_MENU,
			#endif
				ORGANIZER_ALARM_MENU,
				
			#if defined (__MMI_WORLD_CLOCK__)	
				ORGANIZER_WORLDCLOCK_MENU,
			#endif
			#ifdef __MMI_MESSAGES_CLUB__
				EXTRA_SHORTCUTS_MENUID,
			#endif
				SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,
				MAIN_MENU_ORGANIZER_TEXT,MAIN_MENU_ORGANIZER_ICON));
			
	/* services */
		ADD_APPLICATION_MENUITEM2((MAIN_MENU_SERVICES_MENUID,IDLE_SCREEN_MENU_ID,
#ifdef WAP_SUPPORT
				SERVICES_WAP_MENU_ID,
#endif
#ifdef __SYNCML_SUPPORT__
				MENU_ID_SYNCML_MAIN,
#endif
#ifdef __MMI_VOIP__
#ifndef __MMI_UCM__
                                MENU_ID_VOIP_MAIN,
#endif /* __MMI_UCM__ */                                 
#endif/* __MMI_VOIP__ */
#ifdef __MMI_POC__
                                MENU_ID_POC_MAIN,
#endif
#if defined(WAP_SUPPORT) && defined(__TCPIP__)
                                SERVICES_DATA_CONNECT_MAIN_MENU_ID,
#endif
#if defined(__FOTA_ENABLE__)
                                SERVICES_FWU_MENU_ID,
#endif
#ifdef __MMI_RMGR__
                                MENU_ID_RMGR,
#endif
#if defined(SYNCML_DM_SUPPORT)
                                MENU_ID_DMUI_MAIN,
#endif

                            #if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__)
                                MENU_ID_GIS,
                            #endif

                                SERVICES_INFO_NUM_MENU_ID,
                                MENU_ITEM_END,
				SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_SERVICES_TEXT,MAIN_MENU_SERVICES_ICON));

	/* extra */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_EXTRA_MENUID,IDLE_SCREEN_MENU_ID,EXTRA_ENUM_TOTAL,
			#if defined (__MMI_CALCULATOR__)
				EXTRA_CALCULATOR_MENU,
			#endif
			#if defined (__MMI_UNIT_CONVERTER__) || defined	(__MMI_EXTENDED_UNIT_CONVERTER__)
				EXTRA_UNITCONVERTOR_MENU,
			#endif
			#if defined (__MMI_CURRENCY_CONVERTER__) || defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
				EXTRA_CURRENCYCONVERTOR_MENU,
			#endif
			#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__) || defined(__MMI_CALORIE__)
				EXTRA_HEALTH_MENU,
			#endif

    	                #if defined( __MMI_STOPWATCH__)        
    	                        MENU_STOPWATCH,
    	                #endif              
			#if defined(__MMI_APHORISM__)
/* under construction !*/
			#endif
			#if defined(__MMI_DICTIONARY__)
					EXTRA_DICTIONARY_MENU,
			#endif
			#if defined(__MMI_EBOOK_READER__)
				MAIN_MENU_EBOOK_MENUID,
			#endif
			#if defined(__MMI_IRDA_SUPPORT__)
				MENU_CONN_IRDA_MAIN,
			#endif
			#if defined(__MMI_BT_SUPPORT__)
				MENU_CONN_BT_MAIN,
			#endif

            		#if defined(__MMI_LANGLN__)
            			MENU_ID_LANGLN,
            		#endif
				SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,
				MAIN_MENU_EXTRA_TEXT,MAIN_MENU_EXTRA_ICON));

	/* shortcuts */
#ifdef __MMI_MESSAGES_CLUB__
	ADD_APPLICATION_MENUITEM((MAIN_MENU_MSGCLUB_MENUID,IDLE_SCREEN_MENU_ID,0,SHOW,MOVEABLEWITHINPARENT|SHORTCUTABLE,1,
		STR_MSG_CLUB,MAIN_MENU_SHORTCUTS_ICON));
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_MENUID,MAIN_MENU_ORGANIZER_MENUID,0,SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,
		MAIN_MENU_SHORTCUTS_TEXT,IMG_SETTING_SHORTCUT));
#else
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_MENUID,IDLE_SCREEN_MENU_ID,0,SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,
		MAIN_MENU_SHORTCUTS_TEXT,MAIN_MENU_SHORTCUTS_ICON));
#endif
	/*	string definitions */
	ADD_APPLICATION_STRING(MAIN_MENU_MENU_TEXT,"Menu");
	ADD_APPLICATION_STRING(MAIN_MENU_TITLE_TEXT,"Main Menu");
	ADD_APPLICATION_STRING(MAIN_MENU_PHONEBOOK_TEXT,"PhoneBook");
	ADD_APPLICATION_STRING(MAIN_MENU_MESSAGES_TEXT,"Messages");
	ADD_APPLICATION_STRING(MAIN_MENU_FUNANDGAMES_TEXT,"Fun & Games");
	ADD_APPLICATION_STRING(MAIN_MENU_ORGANIZER_TEXT,"Organizer");
	ADD_APPLICATION_STRING(MAIN_MENU_PROFILES_TEXT,"User Profiles");
	ADD_APPLICATION_STRING(MAIN_MENU_SETTINGS_TEXT,"Settings");
	ADD_APPLICATION_STRING(MAIN_MENU_SHORTCUTS_TEXT,"Shortcuts");
	ADD_APPLICATION_STRING(MAIN_MENU_SERVICES_TEXT,"Services");
	ADD_APPLICATION_STRING(MAIN_MENU_CALL_HISTORY_TEXT,"Call History");
	ADD_APPLICATION_STRING2(MAIN_MENU_FILE_MNGR_TEXT,"File Manager","File Manager menu title");
	ADD_APPLICATION_STRING2(MAIN_MENU_MMEDIA_TEXT,"Multimedia","Multimedia menu title");
	ADD_APPLICATION_STRING2(MAIN_MENU_EXTRA_TEXT,"Extra","Extra menu title");

	/* images */
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_ICON, CUST_IMG_BASE_PATH"\\\\NoImage.bmp");
#ifdef __MMI_MAINLCD_176X220__

     ADD_APPLICATION_IMAGE(IMG_MAIN_MENU_PAGE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_BG.PNG");
#endif 
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    /* Matrix */
 	#ifdef __MMI_MAINMENU_MATRIX_SUPPORT__
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_PHONEBOOK_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_PB.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_MG.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_FG.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_OR.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_ST.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_SC.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_SV.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_PR.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_CA.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_MM.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_FILEMNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_FM.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_EXTRA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_EX.gif" );
    
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_PHONEBOOK_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_PB_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_MESSAGES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_MG_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_FUNANDGAMES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_FG_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_ORGANIZER_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_OR_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_SETTINGS_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_ST_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_SHORTCUTS_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_SC_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_SERVICES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_SV_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_PROFILES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_PR_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_CALL_HISTORY_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_CA_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_MULTIMEDIA_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_MM_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_FILEMNGR_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_FM_ANI.gif" );
    	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_EXTRA_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_EX_ANI.gif" );
    #endif /* __MMI_MAINMENU_MATRIX_SUPPORT__ */

    /* Page */
 	#ifdef __MMI_MAINMENU_PAGE_SUPPORT__ //071705 Calvin added
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_PHONEBOOK_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_PB.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_MG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_FG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_OR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_ST.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_SC.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_SV.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_PR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_CA.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_MM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_FILEMNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_FM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_EXTRA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_EX.gif");

	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\TB_BG.pbm");//070505 Calvin added
	#endif //__MMI_MAINMENU_PAGE_SUPPORT__

    /* List */
 	#ifdef __MMI_MAINMENU_LIST_SUPPORT__ //071705 Calvin added
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_PHONEBOOK_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_PB.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_MG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_FG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_OR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_ST.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_SC.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_SV.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_PR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_CA.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_MM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_FILEMNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_FM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_EXTRA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\MM_EX.gif");

	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\TB_BG.pbm");//070505 Calvin added
	#endif //__MMI_MAINMENU_LIST_SUPPORT__

    /* Circular */
	#ifdef __MMI_MAINMENU_CIRCULAR_SUPPORT__//071705 Calvin modified
	ADD_APPLICATION_IMAGE(IMG_MAIN_MENU_CIRCULAR_BG,	CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_BG.bmp"); //102804 Calvin add
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_PHONEBOOK_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_PB.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_MG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_FG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_OR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_ST.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_SC.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_SV.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_PR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_CA.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_MM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_FILEMNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_FM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_CIRCULAR_EXTRA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_EX.gif");
	#endif //__MMI_MAINMENU_CIRCULAR_SUPPORT__

    /* Rotate */
	#ifdef __MMI_MAINMENU_ROTATE_SUPPORT__
	ADD_APPLICATION_IMAGE(IMG_MAIN_MENU_CIRCULAR_BG,	CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\MM_BG.bmp"); //102804 Calvin add
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_PHONEBOOK_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_PB.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_MG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_FG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_OR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_ST.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_SC.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_SV.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_PR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_CA.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_MM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_FILEMNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_FM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_ROTATE_EXTRA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\ROTATE\\\\MM_EX.gif");
	#endif //__MMI_MAINMENU_ROTATE_SUPPORT__

	/* Tab */
	#ifdef __MMI_MAINMENU_TAB_SUPPORT__ //071705 Calvin modified
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_PHONEBOOK_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_PB.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_MG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_FG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_OR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_ST.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_SC.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_SV.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_PR.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_CA.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_MM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_FILEMNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_FM.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TAB_EXTRA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\TAB\\\\TB_EX.gif");
	#endif //__MMI_MAINMENU_TAB_SUPPORT__

#else /* !__MMI_MAINMENU_STYLE_CHANGE_EN__ */

    /* Main menu is not able to change */
	ADD_APPLICATION_IMAGE(MAIN_MENU_PHONEBOOK_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_PB.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_MG.gif");
	ADD_APPLICATION_IMAGE(MAIN_MENU_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_FG.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_OR.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_ST.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_SC.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_SV.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_PR.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_CA.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_MM.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_FILEMNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_FM.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_EXTRA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_EX.gif" );

	ADD_APPLICATION_IMAGE(MAIN_MENU_PHONEBOOK_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_PB_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_MESSAGES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_MG_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_FUNANDGAMES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_FG_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_ORGANIZER_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_OR_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_SETTINGS_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_ST_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_SHORTCUTS_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_SC_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_SERVICES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_SV_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_PROFILES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_PR_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_CALL_HISTORY_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_CA_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_MULTIMEDIA_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_MM_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_FILEMNGR_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_FM_ANI.gif" );
	ADD_APPLICATION_IMAGE(MAIN_MENU_EXTRA_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_EX_ANI.gif");

#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */

#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    /* Use 240x320 GIF because it is faster then BMP with hardware GIF decoder due to smaller data read from NOR Flash */
//    ADD_APPLICATION_IMAGE(IMG_MAIN_MENU_PAGE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_BG.GIF"); //delete by James
    ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_EMPTY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_transparent.pbm");
#endif
	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\TB_BG.pbm");//070505 Calvin added
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\TB_BG.pbm");//070505 Calvin added
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\TB_BG.pbm");//070505 Calvin added

	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_PHONEBOOK_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_PB.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MG.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_FG.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_OR.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_ST.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\tb_pr.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SC.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MM.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_FILE_MNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_FM.PBM");
#if defined(__MMI_VERSION_2__)
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_EXTRA_APP_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_EX.PBM");
#endif



#ifdef __MMI_SUBLCD__
#ifdef __MMI_SLIM_BOOTUP__
	ADD_APPLICATION_IMAGE2(IMG_SUBLCD_SYSTEM_SHUTDOWN,CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_ON.gif","Img Associated with SUBLCD Power Off Screen.");
#else
	ADD_APPLICATION_IMAGE2(IMG_SUBLCD_SYSTEM_SHUTDOWN,CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_OFF.gif","Img Associated with SUBLCD Power Off Screen.");
#endif
#endif /* __MMI_SUBLCD__ */

	/* file manage sub menu icon */
	ADD_APPLICATION_IMAGE(IMG_ID_FNG_FMGR_SUB_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\SB_FM.pbm");
}
#else	
void PopulateMainMenuRes(void)
{
	ADD_APPLICATION_MENUITEM((IDLE_SCREEN_MENU_ID,0,9,
		MAIN_MENU_PHONEBOOK_MENUID, 
		MAIN_MENU_MESSAGES_MENUID,
	#ifdef __MMI_UCM__
        MAIN_MENU_CALL_CENTER,
#else /* __MMI_UCM__ */
	#ifndef __MMI_DUAL_SIM_MASTER__ 
		MAIN_MENU_CALL_HISTORY,
	#else /* __MMI_DUAL_SIM_MASTER__  */
		MENU_MTPNP_DM_CALL_HISTORY,
	#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_UCM__ */
		MAIN_MENU_SETTINGS_MENUID, 
		MAIN_MENU_MULTIMEDIA_MENUID,		
		MAIN_MENU_FUNANDGAMES_MENUID,
		MAIN_MENU_PROFILES_MENUID, 
		MAIN_MENU_ORGANIZER_MENUID,
		#ifdef __MMI_MESSAGES_CLUB__
		MAIN_MENU_MSGCLUB_MENUID,
		#else
		MAIN_MENU_SERVICES_MENUID,
		#endif
		/* MAIN_MENU_SHORTCUTS_MENUID, */
		0,INSERTABLE,TYPE(__MMI_MAINMENU_TYPE__),MAIN_MENU_MENU_TEXT,MAIN_MENU_PHONEBOOK_ICON));

	/* multimedia */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_MULTIMEDIA_MENUID,IDLE_SCREEN_MENU_ID,MMEDIA_ENUM_TOTAL,
		#if defined(__MMI_MOBILE_TV_PLAYER__)
			MENU_ID_MOBILE_TV_PLAYER_APP,
		#endif
		#if defined(__MMI_CAMERA__)
			MENU_ID_CAMERA_APP,
		#endif

		#if defined(__MMI_IMAGE_VIEWER__)
			MENU_ID_IMGVIEW_APP,
		#endif
	
		#if defined(__MMI_VIDEO_RECORDER__)
			MENU_ID_VDOREC_APP,
		#endif

		#if defined(__MMI_VIDEO_PLAYER__)
			MENU_ID_VDOPLY_APP,
		#endif

        #if defined(__MMI_VIDEO_EDITOR__)
            MENU_ID_VDOEDT_APP,
        #endif

        #if defined(__MMI_BARCODEREADER__)
            MENU_ID_BARCODEREADER_APP,
        #endif

		#if defined(__MMI_PHOTOEDITOR__)
			MENU_ID_PHOEDT_APP,
		#endif 

		#if defined(__MMI_AUDIO_PLAYER__)
			AUDIO_PLAYER_MAIN_MENUID,
		#endif
		
		#if defined(__MMI_AB_REPEATER__)
			MENU_ID_AB_REPEATER_MAIN,
		#endif
		
		#if defined(__MMI_SOUND_RECORDER__) 
			MENU_ID_SNDREC_MAIN,
		#endif

		#if defined(__MMI_FM_RADIO__)
			MENU_ID_FMRDO_MAIN,
		#endif

		#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
			MENU_ID_FMSR_MAIN,
		#endif

                     /* hongzhe.liu add start */
                     #if defined(ANALOG_TV_SUPPORT)  
			       MENU_ID_ANALOG_TV_ENTRY,
      				#if defined(TV_RECORD_SUPPORT)
				//Huyanwei Add It 
				MENU_ID_ANALOG_TV_RECORD_ENTRY,
				#endif				
		       #endif
                     /* hongzhe.liu add end */

		#if defined(__MMI_RING_COMPOSER__)	&& defined(__MMI_IMELODY_SUPPORT__) 
			MENU3103_RINGTONE_COMPOSER,
		#endif
		
		#if defined(__MMI_VOICE_MEMO__)
			MENU3104_VOICE_MEMO,
		#endif

		#if defined(__MMI_VRSD__)
			MENU_ID_VRSD_APP,
		#endif

		#if defined(__MMI_VRSI__)
			MENU_ID_VRSI_SETTING,
		#endif

		#if defined(__MMI_FILE_MANAGER__)			/* file manager */
			MAIN_MENU_FILE_MNGR_MENUID,
      		#endif
                #if defined(__MMI_SLIDESHOW__)
                        MENU_ID_SLIDSHOW_APP,
                #endif
		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_MMEDIA_TEXT
		,MAIN_MENU_MULTIMEDIA_ICON));

	ADD_APPLICATION_MENUITEM((MAIN_MENU_FUNANDGAMES_MENUID,IDLE_SCREEN_MENU_ID,FUN_ENUM_TOTAL,
		#if defined(__J2ME__) 
			MENU3108_JAVA,
			MENU_ID_FNG_SETTING_JAVA,
			#ifdef OGDR_SECURITY_SETTING
			MENU_ID_FNG_SECURITY_JAVA,
			#endif

            #ifdef __SUPPORT_INFUSIO__
            MENU_ID_FNG_JAVA_EUREKA,
            #endif
		#endif

		#if defined(__MMI_GAME__)					 
			MENU3105_GAMES,
		#endif  
		#if defined(__MMI_3D_GAME__)
			MENU_ID_FNG_3D_GAME,
		#endif  				
		#if defined(__MMI_MOTION_APP__) 
			MENU_ID_MOTION_APP,
		#endif  
		#if defined (__MMI_THEMES_APPLICATION__)	 
			MENU3101_THEMES,
		#endif

		#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
			MENU_PICTURE_EDITOR,
		#endif

        #if defined(__MMI_AVATAR__)
            MENU_ID_AVATAR_EDITOR,
        #endif

			SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_FUNANDGAMES_TEXT
			,MAIN_MENU_FUNANDGAMES_ICON));
// MTK end

	ADD_APPLICATION_MENUITEM2((MAIN_MENU_CALL_HISTORY,
#ifndef __MMI_DUAL_SIM_MASTER__ 
        #ifdef __MMI_UCM__
		MAIN_MENU_CALL_CENTER,
	#else /*  __MMI_UCM__ */
		IDLE_SCREEN_MENU_ID,
	#endif /*  __MMI_UCM__ */
#else /* __MMI_DUAL_SIM_MASTER__  */
		MENU_MTPNP_DM_CALL_HISTORY,
#endif /* __MMI_DUAL_SIM_MASTER__  */
		MENU8103_MISSED_CALLS,MENU8102_DIALED_CALLS,	MENU8101_RECEIVED_CALLS,
		MENU8113_CALLHISTORY_RESETCALL,
		MENU_CALL_TIME_SETUP,MENU_CALL_HISTORY_CALLCOST,MENU_CALL_HISTORY_SMSCOUNTER,
#ifdef __MMI_GPRS_FEATURES__
		MENU_CALL_HISTORY_GPRSCOUNTER,
#endif
#ifdef __MMI_CH_QUICK_END__
#ifndef __MMI_UCM__
		MENU_CALL_HISTORY_QUICK_END,
#endif	/* __MMI_UCM__ */	
#endif	/* __MMI_CH_QUICK_END__ */	
		MENU_ITEM_END,
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,
#ifndef __MMI_DUAL_SIM_MASTER__ 
		MAIN_MENU_CALL_HISTORY_TEXT,
#else /* __MMI_DUAL_SIM_MASTER__  */
		STRING_MTPNP_CARD1_CALL_HISTORY,
#endif /*__MMI_DUAL_SIM_MASTER__  */
#ifdef __MMI_UCM__
		IMG_ID_UCM_CALL_HISTORY
#else
		MAIN_MENU_CALL_HISTORY_ICON
#endif
		));

//MTK added for Pixtel ABOUT
/* NOTE :: ABOUT FROM SETTING IS NOT TO BE REMOVED WITHOUT ARUN'S APPROVAL */
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
#else
//#if 0
	ADD_APPLICATION_MENUITEM2((MAIN_MENU_SETTINGS_MENUID,IDLE_SCREEN_MENU_ID,
		#ifdef __MMI_DUAL_SIM_MASTER__ 
			MENU_MTPNP_DM_SETTING,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
		MENU_SETTING_CALIBRATION,
#endif
		MENU9102_INITIAL_SETUP,
	#ifndef __MMI_UCM__
		#ifndef __MMI_DUAL_SIM_MASTER__   
		MENU8237_SCR8093_MNGCALL_MENU_MAIN,
		#else /* __MMI_DUAL_SIM_MASTER__ */
			MENU_MTPNP_DM_CALL_SETTING,
		#endif /*__MMI_DUAL_SIM_MASTER__  */
	#endif /* __MMI_UCM__ */
		#ifndef __MMI_DUAL_SIM_MASTER__ 
		MENU9185_NETWORK_SETUP,
		MENU9101_SECURITY,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_NETWORK_SETUP,
			MENU_MTPNP_DM_SECURITY_SETTING,
		#endif /*__MMI_DUAL_SIM_MASTER__ */
		MENU_SETTING_RESTORE,
#ifdef __MMI_SOUND_EFFECT__
		MENU_SETTING_SOUND_EFFECT,
#endif
        MENU_ITEM_END,
		0,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_SETTINGS_TEXT,
		MAIN_MENU_SETTINGS_ICON));
#endif		
//MTK end

/* diamond, 2005/12/23 Phone setup in option menu */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_SETTINGS_NO_SIM_MENUID,MENU_SIM_OPTION_ID,
#ifdef __MMI_DUAL_SIM_MASTER__ 
			1 +
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_SOUND_EFFECT__
			1 + 
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
			1 + 
#endif
#ifdef __MMI_WLAN_FEATURES__
			1 + 
#endif
			3,
#ifdef __MMI_DUAL_SIM_MASTER__ 
			MENU_MTPNP_DM_SETTING,
#endif /* __MMI_DUAL_SIM_MASTER__  */
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
			MENU_SETTING_CALIBRATION,
#endif
			MENU9102_INITIAL_SETUP,
#ifdef __MMI_WLAN_FEATURES__
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MENU9185_NETWORK_SETUP,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_NETWORK_SETUP,
		#endif /*__MMI_DUAL_SIM_MASTER__  */
#endif
		#ifndef __MMI_DUAL_SIM_MASTER__ 
			MENU9101_SECURITY,
		#else /* __MMI_DUAL_SIM_MASTER__  */
			MENU_MTPNP_DM_SECURITY_SETTING,
		#endif /* __MMI_DUAL_SIM_MASTER__  */
			MENU_SETTING_RESTORE,
#ifdef __MMI_SOUND_EFFECT__
			MENU_SETTING_SOUND_EFFECT,
#endif
			0,MOVEABLEWITHINPARENT|INSERTABLE,1,MAIN_MENU_SETTINGS_TEXT,
			MAIN_MENU_SETTINGS_ICON));
/* end, diamond */

	ADD_APPLICATION_MENUITEM((MAIN_MENU_ORGANIZER_MENUID,IDLE_SCREEN_MENU_ID,ORG_ENUM_TOTAL,
			#if defined(__MMI_CALENDAR__)
				ORGANIZER_CALENDER_MENU,
			#endif
			#if defined(__MMI_TODOLIST__)
				ORGANIZER_TODOLIST_MENU,
			#endif
				ORGANIZER_ALARM_MENU,
				
			#if defined (__MMI_CALCULATOR__)
				EXTRA_CALCULATOR_MENU,
			#endif
			#if defined (__MMI_UNIT_CONVERTER__) || defined	(__MMI_EXTENDED_UNIT_CONVERTER__)
				EXTRA_UNITCONVERTOR_MENU,
			#endif
			#if defined (__MMI_CURRENCY_CONVERTER__) || defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
				EXTRA_CURRENCYCONVERTOR_MENU,
			#endif
			#if defined (__MMI_WORLD_CLOCK__)	
				ORGANIZER_WORLDCLOCK_MENU,
			#endif
			#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__) || defined(__MMI_CALORIE__)
				EXTRA_HEALTH_MENU,
			#endif
			#if defined(__MMI_APHORISM__)
/* under construction !*/
			#endif
			#ifdef __MMI_MESSAGES_CLUB__
				MAIN_MENU_SERVICES_MENUID,
			#endif
			#if defined(__MMI_EBOOK_READER__)
				MAIN_MENU_EBOOK_MENUID,
			#endif
            		#if defined(__MMI_LANGLN__)
            			MENU_ID_LANGLN,
            		#endif
				SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,
				MAIN_MENU_ORGANIZER_TEXT,MAIN_MENU_ORGANIZER_ICON));


	/* phonebook */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_PHONEBOOK_MENUID,IDLE_SCREEN_MENU_ID,MMI_PHB_MAIN_ENUM_TOTAL,
#if defined(__MMI_PHB_QUICK_SEARCH__)
		MENU_ID_PHB_QUICK_SEARCH,		
#endif
		MITEM101_PBOOK_SEARCH_ENTRY,
		MITEM102_PBOOK_NEW_ENTRY,
#if defined(__MMI_PHB_MULTI_OPERATION__)
		MENU_ID_PHB_MULTI_OP,
#else /* defined(__MMI_PHB_MULTI_OPERATION__) */
		MITEM104_PBOOK_COPY_ALL,
		MITEM103_PBOOK_DELETE_ALL,
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
		MITEM109_PBOOK_CALLER_GROUPS,
		MENU_ID_PHB_EXTRA_NUMBER,
		MITEM110_PBOOK_SETTINGS,
#if defined(__MMI_PHB_CALLER_RES_SETTING__)
		MENU_ID_PHB_CALLER_PIC,
		MENU_ID_PHB_CALLER_RING,
#if defined(__MMI_INCOMING_CALL_VIDEO__)
		MENU_ID_PHB_CALLER_VIDEO,
#endif		
#endif
		SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, MAIN_MENU_PHONEBOOK_TEXT,MAIN_MENU_PHONEBOOK_ICON));

	/* phonebook for No SIM inserted mode- MTK 2005-09-03 Jo */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_PHONEBOOK_NO_SIM_MENUID,MENU_SIM_OPTION_ID, MMI_PHB_MAIN_NO_SIM_ENUM_TOTAL,
#if defined(__MMI_PHB_QUICK_SEARCH__)	
		MENU_ID_PHB_QUICK_SEARCH,		
#endif
		MITEM101_PBOOK_SEARCH_ENTRY,
		MITEM102_PBOOK_NEW_ENTRY,
#if defined(__MMI_PHB_MULTI_OPERATION__)
		MENU_ID_PHB_MULTI_OP,
#else /* defined(__MMI_PHB_MULTI_OPERATION__) */
		MITEM103_PBOOK_DELETE_ALL,
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
		MITEM109_PBOOK_CALLER_GROUPS,
		MITEM110_PBOOK_SETTINGS_NO_SIM,
#if defined(__MMI_PHB_CALLER_RES_SETTING__)
		MENU_ID_PHB_CALLER_PIC,
		MENU_ID_PHB_CALLER_RING,
#if defined(__MMI_INCOMING_CALL_VIDEO__)
		MENU_ID_PHB_CALLER_VIDEO,
#endif
#endif
		SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, MAIN_MENU_PHONEBOOK_TEXT,MAIN_MENU_PHONEBOOK_ICON));


//	ADD_APPLICATION_MENUITEM((MAIN_MENU_SETTINGS_MENUID,IDLE_SCREEN_MENU_ID,0,0,NONMOVEABLE,1,MAIN_MENU_SETTINGS_TEXT,
//		MAIN_MENU_SETTINGS_ICON));
	/* shortcuts */
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_MENUID,MENU9102_INITIAL_SETUP,0,SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,
		MAIN_MENU_SHORTCUTS_TEXT,IMG_SETTING_SHORTCUT));

	/* file manager */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_FILE_MNGR_MENUID,MAIN_MENU_MULTIMEDIA_MENUID,0,
		SHOW,MOVEABLEWITHINPARENT,1,MAIN_MENU_FILE_MNGR_TEXT
		,IMG_ID_FNG_FMGR_SUB_ICON));

	/* services */
    ADD_APPLICATION_MENUITEM2((MAIN_MENU_SERVICES_MENUID,
								#ifdef __MMI_MESSAGES_CLUB__
								MAIN_MENU_ORGANIZER_MENUID,
#else /* __MMI_MESSAGES_CLUB__ */
								IDLE_SCREEN_MENU_ID,
#endif /* __MMI_MESSAGES_CLUB__ */				           				            
                                /* menu item BEGIN */
#ifdef WAP_SUPPORT
                                SERVICES_WAP_MENU_ID,
#endif
#ifdef __SYNCML_SUPPORT__
                                MENU_ID_SYNCML_MAIN,
#endif
#ifdef __MMI_VOIP__
                                MENU_ID_VOIP_MAIN,
								#endif
#ifdef __MMI_POC__
                                MENU_ID_POC_MAIN,
								#endif
#if defined(WAP_SUPPORT) && defined(__TCPIP__)
                                SERVICES_DATA_CONNECT_MAIN_MENU_ID,
								#endif
#if defined(__FOTA_ENABLE__)
                                SERVICES_FWU_MENU_ID,
								#endif
								#if defined(__MMI_BT_SUPPORT__)
								MENU_CONN_BT_MAIN,
								#endif
								#if defined (SYNCML_DM_SUPPORT)
								MENU_ID_DMUI_MAIN,
								#endif
                            #if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__)
                                MENU_ID_GIS,
                            #endif
                                /* menu item END */
                                SERVICES_INFO_NUM_MENU_ID,
                                MENU_ITEM_END,
								SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,MAIN_MENU_SERVICES_TEXT,MAIN_MENU_SERVICES_ICON));

    /* message club */
#ifdef __MMI_MESSAGES_CLUB__
	ADD_APPLICATION_MENUITEM((MAIN_MENU_MSGCLUB_MENUID,
								IDLE_SCREEN_MENU_ID,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_MSG_CLUB,MAIN_MENU_MESSAGE_CLUB_ICON));
#endif

	//ADD_APPLICATION_MENUITEM((MAIN_MENU_CALL_HISTORY,IDLE_SCREEN_MENU_ID,0,0,0,1,MAIN_MENU_CALL_HISTORY_TEXT,
	//	MAIN_MENU_CALL_HISTORY_ICON));

	ADD_APPLICATION_STRING(MAIN_MENU_MENU_TEXT,"Menu");
	ADD_APPLICATION_STRING(MAIN_MENU_TITLE_TEXT,"Main Menu");

	ADD_APPLICATION_STRING(MAIN_MENU_PHONEBOOK_TEXT,"PhoneBook");
	ADD_APPLICATION_STRING(MAIN_MENU_MESSAGES_TEXT,"Messages");
	ADD_APPLICATION_STRING(MAIN_MENU_FUNANDGAMES_TEXT,"Fun & Games");
	ADD_APPLICATION_STRING(MAIN_MENU_ORGANIZER_TEXT,"Organizer");
	//MTK Joy modified
	ADD_APPLICATION_STRING(MAIN_MENU_PROFILES_TEXT,"User Profiles");
	//MTK end
	ADD_APPLICATION_STRING(MAIN_MENU_SETTINGS_TEXT,"Settings");
	ADD_APPLICATION_STRING(MAIN_MENU_SHORTCUTS_TEXT,"Shortcuts");
	ADD_APPLICATION_STRING(MAIN_MENU_SERVICES_TEXT,"Services");
	ADD_APPLICATION_STRING(MAIN_MENU_CALL_HISTORY_TEXT,"Call History");
	ADD_APPLICATION_STRING2(MAIN_MENU_FILE_MNGR_TEXT,"File Manager","File Manager menu title");
	ADD_APPLICATION_STRING2(MAIN_MENU_MMEDIA_TEXT,"Multimedia","Multimedia menu title");

	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_ICON, CUST_IMG_BASE_PATH"\\\\NoImage.bmp");

	ADD_APPLICATION_IMAGE(MAIN_MENU_PHONEBOOK_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_PB" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_MG" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_FG" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_OR" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_ST" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_SC" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_SV" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_PR" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_CA" __MMI_RES_TYPE_MAINMENU_MATRIX__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_MM" __MMI_RES_TYPE_MAINMENU_MATRIX__);
#ifdef __MMI_MESSAGES_CLUB__
	ADD_APPLICATION_IMAGE(MAIN_MENU_MESSAGE_CLUB_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\"IMG_DIR(__MMI_MAINMENU_TYPE__)"\\\\MM_MC" __MMI_RES_TYPE_MAINMENU_MATRIX__);
#endif

	ADD_APPLICATION_IMAGE(MAIN_MENU_PHONEBOOK_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_PB_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_MESSAGES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_MG_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_FUNANDGAMES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_FG_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_ORGANIZER_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_OR_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_SETTINGS_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_ST_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_SHORTCUTS_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_SC_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_SERVICES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_SV_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_PROFILES_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_PR_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_CALL_HISTORY_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_CA_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
	ADD_APPLICATION_IMAGE(MAIN_MENU_MULTIMEDIA_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_MM_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
#ifdef __MMI_MESSAGES_CLUB__
	ADD_APPLICATION_IMAGE(MAIN_MENU_MESSAGE_CLUB_ANIMATION,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\MM_MC_ANI" __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__);
#endif

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    /* Use 240x320 GIF because it is faster then BMP with hardware GIF decoder due to smaller data read from NOR Flash */
    ADD_APPLICATION_IMAGE(IMG_MAIN_MENU_PAGE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\MM_BG.GIF");
    ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_EMPTY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_transparent.pbm");
#endif
	ADD_APPLICATION_IMAGE(MAIN_MENU_MATRIX_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\MATRIX\\\\TB_BG.pbm");//070505 Calvin added
	ADD_APPLICATION_IMAGE(MAIN_MENU_PAGE_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\TB_BG.pbm");//070505 Calvin added
	ADD_APPLICATION_IMAGE(MAIN_MENU_LIST_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\LIST\\\\TB_BG.pbm");//070505 Calvin added

	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_PHONEBOOK_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_PB.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_MESSAGES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MG.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_FUNANDGAMES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_FG.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_ORGANIZER_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_OR.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SETTINGS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_ST.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_PROFILES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_PR.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SHORTCUTS_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SC.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_SERVICES_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_MULTIMEDIA_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MM.PBM");
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_FILE_MNGR_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_FM.PBM");
#ifdef __MMI_MESSAGES_CLUB__
	ADD_APPLICATION_IMAGE(MAIN_MENU_TITLE_MESSAGE_CLUB_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Message\\\\SB_MC.pbm");
#endif

#ifdef __MMI_SUBLCD__
#ifdef __MMI_SLIM_BOOTUP__
	ADD_APPLICATION_IMAGE2(IMG_SUBLCD_SYSTEM_SHUTDOWN,CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_ON.gif","Img Associated with SUBLCD Power Off Screen.");
#else
	ADD_APPLICATION_IMAGE2(IMG_SUBLCD_SYSTEM_SHUTDOWN,CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_OFF.gif","Img Associated with SUBLCD Power Off Screen.");
#endif
#endif /* __MMI_SUBLCD__ */

	/* file manage sub menu icon */
	ADD_APPLICATION_IMAGE(IMG_ID_FNG_FMGR_SUB_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\SB_FM.pbm");
}
#endif	// #if defined(__MMI_VERSION_2__)
#endif
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */


