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

	FILENAME	: Res_.c

  	PURPOSE		: Populate Resource for 

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-11-2003

**************************************************************/
#include "CustomCfg.h"
#include "MMI_features.h"


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "SSCResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

/**************************************************************

	FUNCTION NAME		: PopulateSSCRes()

  	PURPOSE				: To Initialize the resources for the 
						  SSC screens

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/

void PopulateSSCRes()
{
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_ENGLISH_STR_ID,"Language is set to English","Set English SSC string screen.");
#if defined(__MMI_LANG_SM_CHINESE__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_SCHINESE_STR_ID,"Language is set to simplified Chinese","Set Simplified Chinese SSC string screen.");
#endif
#if defined(__MMI_LANG_TR_CHINESE__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_TCHINESE_STR_ID,"Language is set to traditional Chinese","Set Traditional Chinese SSC string screen.");
#endif
#if defined(__MMI_LANG_SPANISH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_SPANISH_STR_ID,"Language set to Spanish","Set Spanish SSC string screen.");
#endif	
#if defined(__MMI_LANG_DANISH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_DANISH_STR_ID,"Language set to Danish","Set Danish SSC string screen.");
#endif
#if defined(__MMI_LANG_POLISH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_POLISH_STR_ID,"Language set to polish","Set polish SSC string screen.");
#endif
#if defined(__MMI_LANG_FRENCH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_FRENCH_STR_ID,"Language set to French","Set French SSC string screen.");
#endif	
#if defined(__MMI_LANG_GERMAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_GERMAN_STR_ID,"Language set to German","Set German SSC string screen.");
#endif	
#if defined(__MMI_LANG_ITALIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_ITALIAN_STR_ID,"Language set to Italian","Set Italian SSC string screen.");
#endif	
#if defined(__MMI_LANG_THAI__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_THAI_STR_ID,"Language set to Thai","Set Thai SSC string screen.");
#endif
#if defined(__MMI_LANG_HINDI__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_HINDI_STR_ID,"Language set to Hindi","Set Hindi SSC string screen.");
#endif

#if defined(__MMI_LANG_MARATHI__) 
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_MARATHI_STR_ID,"Language set to Marathi","Set Marathi SSC string screen.");
#endif
#if defined(__MMI_LANG_TAMIL__) 
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_TAMIL_STR_ID,"Language set to Tamil","Set Tamil SSC string screen.");
#endif
#if defined(__MMI_LANG_BENGALI__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_BENGALI_STR_ID,"Language set to Bengali","Set Bengali SSC string screen.");
#endif

#if defined(__MMI_LANG_PUNJABI__) 
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_PUNJABI_STR_ID,"Language set to Punjabi","Set Punjabi SSC string screen.");
#endif
#if defined(__MMI_LANG_TELUGU__) 
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_TELUGU_STR_ID,"Language set to Telugu","Set Telugu SSC string screen.");
#endif
#if defined(__MMI_LANG_RUSSIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_RUSSIAN_STR_ID,"Language set to Russian","Set Russian SSC string screen.");
#endif
#if defined(__MMI_LANG_BULGARIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_BULGARIAN_STR_ID,"Language set to Bulgarian","Set Bulgarian SSC string screen.");
#endif
#if defined(__MMI_LANG_UKRAINIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_UKRAINIAN_STR_ID,"Language set to Ukrainian","Set Ukrainian SSC string screen.");
#endif
#if defined(__MMI_LANG_PORTUGUESE__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_PORTUGUESE_STR_ID,"Language set to Portuguese","Set Portuguese SSC string screen.");
#endif	
#if defined(__MMI_LANG_CZECH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_CZECH_STR_ID,"Language set to Czech","Set Czech SSC string screen.");
#endif
#if defined(__MMI_LANG_TURKISH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_TURKISH_STR_ID,"Language set to Turkish","Set Turkish SSC string screen.");
#endif	
#if defined(__MMI_LANG_VIETNAMESE__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_VIETNAMESE_STR_ID,"Language set to Vietnamese","Set Vietnamese SSC string screen.");
#endif	
#if defined(__MMI_LANG_INDONESIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_INDONESIAN_STR_ID,"Language set to Indonesian","Set Indonesian SSC string screen.");
#endif	
#if defined(__MMI_LANG_MALAY__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_MALAY_STR_ID,"Language set to Malay","Set Malay SSC string screen.");
#endif
#if defined(__MMI_LANG_FINNISH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_FINNISH_STR_ID,"Language set to Finnish","Set Finnish SSC string screen.");
#endif
#if defined(__MMI_LANG_HUNGARIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_HUNGARIAN_STR_ID,"Language set to Hungarian","Set Hungarian SSC string screen.");
#endif
#if defined(__MMI_LANG_NORWEGIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_NORWEGIAN_STR_ID,"Language set to Norwegian","Set Norwegian SSC string screen.");
#endif
#if defined(__MMI_LANG_SLOVAK__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_SLOVAK_STR_ID,"Language set to Slovak","Set Slovak SSC string screen.");
#endif
#if defined(__MMI_LANG_DUTCH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_DUTCH_STR_ID,"Language set to Dutch","Set Dutch SSC string screen.");
#endif
#if defined(__MMI_LANG_SWEDISH__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_SWEDISH_STR_ID,"Language set to Swedish","Set Swedish SSC string screen.");
#endif
#if defined(__MMI_LANG_CROATIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_CROATIAN_STR_ID,"Language set to Croatian","Set Croatian SSC string screen.");
#endif
#if defined(__MMI_LANG_ROMANIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_ROMANIAN_STR_ID,"Language set to Romanian","Set Romanian SSC string screen.");
#endif
#if defined(__MMI_LANG_SLOVENIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_SLOVENIAN_STR_ID,"Language set to Slovenian","Set Slovenian SSC string screen.");
#endif

#if defined(__MMI_LANG_GREEK__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_GREEK_STR_ID,"Language set to Greek","Set Greek SSC string screen.");
#endif
#if defined(__MMI_LANG_ARABIC__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_ARABIC_STR_ID,"Language set to Arabic","Set Arabic SSC string screen.");
#endif
#if defined(__MMI_LANG_PERSIAN__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_PERSIAN_STR_ID,"Language set to Persian","Set Persian SSC string screen.");
#endif

#if defined(__MMI_LANG_URDU__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_URDU_STR_ID,"Language set to Urdu","Set Urdu SSC string screen.");
#endif

#if defined(__MMI_LANG_HEBREW__)
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_HEBREW_STR_ID,"Language set to Hebrew","Set Hebrew SSC string screen.");
#endif
	ADD_APPLICATION_STRING2(SSC_SCR_LANGUAGE_DEFAULT_STR_ID,"Language is set to Default","Set Default Language SSC string screen.");
	ADD_APPLICATION_STRING2(SSC_SCR_ENGINEER_MODE_STR_ID,"Engineer Mode is not set","Set Engineer mode SSC Screen.");

	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_DEFAULT,"Error in Set Default Language","String assoicated with Error in Set Default.");
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_ENGLISH,"Error in Set English Language","String assoicated with Error in Set English.");
#if defined(__MMI_LANG_SM_CHINESE__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_SCHINESE,"Error in Set Simplified Chinese Language","String assoicated with Error in Set Simplified Chinese.");
#endif
#if defined(__MMI_LANG_TR_CHINESE__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_TCHINESE,"Error in Set Traditional Chinese Language","String assoicated with Error in Set Traditional Chinese.");
#endif
#if defined(__MMI_LANG_SPANISH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_SPANISH,"Error in Set Spanish Language","String assoicated with Error in Set Spanish.");
#endif	
#if defined(__MMI_LANG_DANISH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_DANISH,"Error in Set Danish Language","String assoicated with Error in Set Danish.");
#endif
#if defined(__MMI_LANG_POLISH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_POLISH,"Error in Set polish Language","String assoicated with Error in Set polish.");
#endif
#if defined(__MMI_LANG_FRENCH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_FRENCH,"Error in Set French Language","String assoicated with Error in Set French.");
#endif	
#if defined(__MMI_LANG_CZECH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_CZECH,"Error in Set Czech Language","String assoicated with Error in Set Czech.");
#endif
#if defined(__MMI_LANG_GERMAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_GERMAN,"Error in Set German Language","String assoicated with Error in Set German.");
#endif	
#if defined(__MMI_LANG_ITALIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_ITALIAN,"Error in Set Italian Language","String assoicated with Error in Set Italian.");
#endif	
#if defined(__MMI_LANG_THAI__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_THAI,"Error in Set Thai Language","String assoicated with Error in Set Thai.");
#endif
#if defined(__MMI_LANG_HINDI__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_HINDI,"Error in Set Hindi Language","String assoicated with Error in Set Hindi.");
#endif

#if defined(__MMI_LANG_MARATHI__) 
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_MARATHI,"Error in Set Marathi Language","String assoicated with Error in Set Marathi.");
#endif
#if defined(__MMI_LANG_TAMIL__) 
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_TAMIL,"Error in Set Tamil Language","String assoicated with Error in Set Tamil.");
#endif
#if defined(__MMI_LANG_BENGALI__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_BENGALI,"Error in Set Bengali Language","String assoicated with Error in Set Bengali.");
#endif
#if defined(__MMI_LANG_PUNJABI__) 
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_PUNJABI,"Error in Set Punjabi Language","String assoicated with Error in Set Punjabi.");
#endif
#if defined(__MMI_LANG_TELUGU__) 
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_TELUGU,"Error in Set Telugu Language","String assoicated with Error in Set Telugu.");
#endif
#if defined(__MMI_LANG_RUSSIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_RUSSIAN,"Error in Set Russian Language","String assoicated with Error in Set Russian.");
#endif
#if defined(__MMI_LANG_BULGARIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_BULGARIAN,"Error in Set Bulgarian Language","String assoicated with Error in Set Bulgarian.");
#endif
#if defined(__MMI_LANG_UKRAINIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_UKRAINIAN,"Error in Set Ukrainian Language","String assoicated with Error in Set Ukrainian.");
#endif
#if defined(__MMI_LANG_PORTUGUESE__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_PORTUGUESE,"Error in Set Portuguese Language","String assoicated with Error in Set Portuguese.");
#endif	
#if defined(__MMI_LANG_TURKISH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_TURKISH,"Error in Set Turkish Language","String assoicated with Error in Set Turkish.");
#endif	
#if defined(__MMI_LANG_VIETNAMESE__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_VIETNAMESE,"Error in Set Vietnamese Language","String assoicated with Error in Set Vietnamese.");
#endif	
#if defined(__MMI_LANG_INDONESIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_INDONESIAN,"Error in Set Indonesian Language","String assoicated with Error in Set Indonesian.");
#endif	
#if defined(__MMI_LANG_MALAY__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_MALAY,"Error in Set Malay Language","String assoicated with Error in Set Malay.");
#endif
#if defined(__MMI_LANG_FINNISH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_FINNISH,"Error in Set Finnish Language","String assoicated with Error in Set Finnish.");
#endif
#if defined(__MMI_LANG_HUNGARIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_HUNGARIAN,"Error in Set Hungarian Language","String assoicated with Error in Set hungarian.");
#endif
#if defined(__MMI_LANG_NORWEGIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_NORWEGIAN,"Error in Set Norwegian Language","String assoicated with Error in Set Norwegian.");
#endif
#if defined(__MMI_LANG_SLOVAK__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_SLOVAK,"Error in Set Slovak Language","String assoicated with Error in Set Slovak.");
#endif
#if defined(__MMI_LANG_DUTCH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_DUTCH,"Error in Set Dutch Language","String assoicated with Error in Set Dutch.");
#endif
#if defined(__MMI_LANG_SWEDISH__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_SWEDISH,"Error in Set Swedish Language","String assoicated with Error in Set Swedish.");
#endif
#if defined(__MMI_LANG_CROATIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_CROATIAN,"Error in Set Croatian Language","String assoicated with Error in Set Croatian.");
#endif
#if defined(__MMI_LANG_ROMANIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_ROMANIAN,"Error in Set Romanian Language","String assoicated with Error in Set Romanian.");
#endif
#if defined(__MMI_LANG_SLOVENIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_SLOVENIAN,"Error in Set Slovenian Language","String assoicated with Error in Set Slovenian.");
#endif

#if defined(__MMI_LANG_GREEK__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_GREEK,"Error in Set Greek Language","String assoicated with Error in Set Greek.");
#endif
#if defined(__MMI_LANG_ARABIC__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_ARABIC,"Error in Set Arabic Language","String assoicated with Error in Set Arabic.");
#endif
#if defined(__MMI_LANG_PERSIAN__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_PERSIAN,"Error in Set Persian Language","String assoicated with Error in Set Persian.");
#endif
#if defined(__MMI_LANG_URDU__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_URDU,"Error in Set Urdu Language","String assoicated with Error in Set Urdu.");
#endif
#if defined(__MMI_LANG_HEBREW__)
	ADD_APPLICATION_STRING2(SSC_STR_ERR_SET_HEBREW,"Error in Set Hebrew Language","String assoicated with Error in Set Hebrew.");
#endif
	ADD_APPLICATION_STRING2(SSC_SCR_IMEI_CAPTION_ID,"IMEI","Display IMEI SSC Screen.");

	ADD_APPLICATION_STRING2(SSC_SCR_SW_VERSION_CAPTION_ID,"Software Version","Display Software Version SSC screen.");
//micha1009, Chicago Cust. Feature
	ADD_APPLICATION_STRING2(SSC_SCR_HW_VERSION_CAPTION_ID,"Hardware Version","Display Hardware Version SSC screen.");
	ADD_APPLICATION_STRING2(SSC_SCR_SERIAL_NUMBER_CAPTION_ID,"Serial Number","Display Serial Number SSC screen.");
	ADD_APPLICATION_STRING2(SSC_SCR_FACTORY_MODE_STR_ID,"Factory Mode is not set","Set Factory mode SSC Screen.");

}

#endif


