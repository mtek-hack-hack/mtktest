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
#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */
    
#include "MMIDataType.h"    /* for resource base */
    
#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
    
#include "CommonScreensResDef.h" /* for resource ID */


void PopulateCommonScreensResData(void)
{
	ADD_APPLICATION_MENUITEM ((MENU_INPUT_METHOD_AND_DONE_OPTION_ID, 0, 2,
								MENU_DONE_OPTION_ID,
								MENU_INPUT_METHOD_OPTION_ID,
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_OPTIONS, 0));
	ADD_APPLICATION_MENUITEM ((MENU_DONE_OPTION_ID,
								MENU_INPUT_METHOD_AND_DONE_OPTION_ID, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_DONE, 0));
	ADD_APPLICATION_MENUITEM ((MENU_INPUT_METHOD_OPTION_ID,
								MENU_INPUT_METHOD_AND_DONE_OPTION_ID, 0, 
								SHOW, NONMOVEABLE, DISP_LIST,
								STR_GLOBAL_INPUT_METHOD, 0));
        //replaced by Global String  
	//ADD_APPLICATION_STRING2(STR_INPUT_METHOD_CAPTION,"Input Methods","Title string for input methods screen");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_ABC,"Multitap ABC","Input methods list Option 1");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_abc,"Multitap abc","Input methods list Option 2");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_ABC,"Smart ABC","Input methods list Option 3");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_abc,"Smart abc","Input methods list Option 4");
#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_Abc,"Smart Abc","Input methods list Option 5");	
#endif
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_NUMERIC,"Numeric","Input methods list Option 5");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_BOPOMO,"Multitap BoPoMo","Input methods list Option 6");
    ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_BOPOMO,"Smart BoPoMo","Input methods list Option 7");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_TRADITIONAL_CHINESE_STROKE,"Traditional Chinese Stroke","Input methods list Option 8");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_PINYIN,"Multitap PinYin","Input methods list Option 9");
    ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_PINYIN,"Smart PinYin","Input methods list Option 10");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SIMPLIFIED_CHINESE_STROKE,"Simplified Chinese Stroke","Input methods list Option 11");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_INSERT_SYMBOLS,"Insert Symbols","Input methods list Option 12");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SELECT_SYMBOL,"Select Symbol","Title for the symbol picker screen");
#if defined(__MMI_LANG_HINDI__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SELECT_VOWEL,"Select Symbol","Title for the Hindi Vowel picker screen");
#endif
#if defined(__MMI_LANG_MARATHI__) 
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_MARATHI,"Multitap Marathi","Input methods list Option Multitap Mara");
#endif
#if defined(__MMI_MULTITAP_SPANISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_SPANISH,"Multitap ES","Input methods list Option Multitap ES");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_SPANISH,"Multitap es","Input methods list Option Multitap es");
#endif	
#if defined(__MMI_MULTITAP_POLISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_POLISH,"Multitap PO","Input methods list Option Multitap Po");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_POLISH,"Multitap po","Input methods list Option Multitap po");
#endif
#if defined(__MMI_T9_SPANISH__)||defined(__MMI_ZI_EU_SPANISH__)||defined(__MMI_ZI_SA_SPANISH__) || defined(__MMI_CSTAR_SPANISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_SPANISH,"Smart ES","Input methods list Option Smart ES");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_SPANISH,"Smart es","Input methods list Option Smart es");
#endif	

#if defined(__MMI_T9_POLISH__)||defined(__MMI_ZI_POLISH__) || defined(__MMI_CSTAR_POLISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_POLISH,"Smart PO","Input methods list Option Smart PO");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_POLISH,"Smart po","Input methods list Option Smart po");
#endif
#if defined(__MMI_MULTITAP_DANISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_DANISH,"Multitap DA","Input methods list Option Multitap DA");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_DANISH,"Multitap da","Input methods list Option Multitap da");
#endif
#if defined(__MMI_T9_SPANISH__)||defined(__MMI_ZI_EU_SPANISH__)||defined(__MMI_ZI_SA_SPANISH__) || defined(__MMI_CSTAR_SPANISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_SPANISH,"Smart ES","Input methods list Option Smart ES");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_SPANISH,"Smart es","Input methods list Option Smart es");
#endif	
#if defined(__MMI_T9_DANISH__)||defined(__MMI_ZI_DANISH__) || defined(__MMI_CSTAR_DANISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_DANISH,"Smart DA","Input methods list Option Smart DA");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_DANISH,"Smart da","Input methods list Option Smart da");
#endif
#if defined(__MMI_MULTITAP_HUNGARIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_HUNGARIAN,"Multitap HG","Input methods list Option Multitap HG");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_HUNGARIAN,"Multitap hg","Input methods list Option Multitap hg");
#endif

#if defined(__MMI_T9_HUNGARIAN__)||defined(__MMI_ZI_HUNGARIAN__) || defined(__MMI_CSTAR_HUNGARIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_HUNGARIAN,"Smart HG","Input methods list Option Smart HG");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_HUNGARIAN,"Smart hg","Input methods list Option Smart hg");
#endif
#if defined(__MMI_MULTITAP_FRENCH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_FRENCH,"Multitap FR","Input methods list Option Multitap FR");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_FRENCH,"Multitap fr","Input methods list Option Multitap fr");
#endif
#if defined(__MMI_T9_FRENCH__)||defined(__MMI_ZI_CA_FRENCH__)||defined(__MMI_ZI_EU_FRENCH__) || defined(__MMI_CSTAR_FRENCH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_FRENCH,"Smart FR","Input methods list Option Smart FR");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_FRENCH,"Smart fr","Input methods list Option Smart fr");
#endif	
#if defined(__MMI_MULTITAP_GERMAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_GERMAN,"Multitap DE","Input methods list Option Multitap DE");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_GERMAN,"Multitap de","Input methods list Option Multitap de");
#endif
#if defined(__MMI_T9_GERMAN__)||defined(__MMI_ZI_GERMAN__) || defined(__MMI_CSTAR_GERMAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_GERMAN,"Smart DE","Input methods list Option Smart DE");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_GERMAN,"Smart de","Input methods list Option Smart de");
#endif	
#if defined(__MMI_MULTITAP_ITALIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_ITALIAN,"Multitap IT","Input methods list Option Multitap IT");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_ITALIAN,"Multitap it","Input methods list Option Multitap it");
#endif
#if defined(__MMI_T9_ITALIAN__)||defined(__MMI_ZI_ITALIAN__) || defined(__MMI_CSTAR_ITALIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_ITALIAN,"Smart IT","Input methods list Option Smart IT");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_ITALIAN,"Smart it","Input methods list Option Smart it");
#endif	
#if defined(__MMI_MULTITAP_RUSSIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_RUSSIAN,"Multitap RU","Input methods list Option Multitap RU");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_RUSSIAN,"Multitap ru","Input methods list Option Multitap ru");
#endif
#if defined(__MMI_MULTITAP_ARABIC__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_ARABIC,"Multitap Arabic","Input methods list Option Multitap AR");
#endif
#if defined(__MMI_MULTITAP_ARABIC__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_ARABIC_NUMERIC,"Arabic Numeric","Input methods list Option Arabic Numeric");
#endif
#if defined(__MMI_MULTITAP_PERSIAN__) 
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_PERSIAN,"Multitap Persian","Input methods list Option Multitap FA");
#endif

#if defined(__MMI_MULTITAP_URDU__) 
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_URDU,"Multitap Urdu","Input methods list Option Multitap UR");
#endif

#if defined(__MMI_T9_RUSSIAN__)|| defined (__MMI_ZI_RUSSIAN__)||defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) || defined(__MMI_CSTAR_RUSSIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_RUSSIAN,"Smart RU","Input methods list Option Smart RU");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_RUSSIAN,"Smart ru","Input methods list Option Smart ru");
#endif	
#if defined(__MMI_MULTITAP_BULGARIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_BULGARIAN,"Multitap BG","Input methods list Option Multitap BG");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_BULGARIAN,"Multitap bg","Input methods list Option Multitap bg");
#endif
#if defined(__MMI_MULTITAP_UKRAINIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_UKRAINIAN,"Multitap UK","Input methods list Option Multitap UK");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_UKRAINIAN,"Multitap uk","Input methods list Option Multitap uk");
#endif
#if defined(__MMI_T9_BULGARIAN__)|| defined (__MMI_ZI_BULGARIAN__) || defined(__MMI_CSTAR_BULGARIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_BULGARIAN,"Smart BG","Input methods list Option Smart BG");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_BULGARIAN,"Smart bg","Input methods list Option Smart bg");
#endif
#if defined(__MMI_T9_UKRAINIAN__)|| defined (__MMI_ZI_UKRAINIAN__) || defined(__MMI_CSTAR_UKRAINIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_UKRAINIAN,"Smart UK","Input methods list Option Smart UK");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_UKRAINIAN,"Smart uk","Input methods list Option Smart uk");
#endif
#if defined(__MMI_ZI_THAI__)|| defined (__MMI_T9_THAI__) || defined(__MMI_CSTAR_THAI__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_THAI,"Smart Thai","Input methods list Option Smart Thai");
#endif	
#if defined(__MMI_ZI_HEBREW__)||defined(__MMI_T9_HEBREW__) || defined(__MMI_CSTAR_HEBREW__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_HEBREW,"Smart Hebrew","Input methods list Option Smart HEBREW");
#endif	
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_ARABIC,"Smart Arabic","Input methods list Option Smart Arabic");
#ifdef __MMI_ZI_PERSIAN__
    ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_PERSIAN,"Smart Persian","Input methods list Option Smart Persian");
#endif
#if defined (__MMI_ZI_URDU__)  || defined(__MMI_CSTAR_URDU__)
    ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_URDU,"Smart Urdu","Input methods list Option Smart Urdu");
#endif

#if defined(__MMI_ZI_HINDI__) || defined(__MMI_T9_HINDI__) ||defined(__MMI_CSTAR_HINDI__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_HINDI,"Smart Hindi","Input methods list Option Smart Hindi");
#endif
#if defined(__MMI_ZI_BENGALI__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_BENGALI,"Smart Bengali","Input methods list Option Smart Bengali");
#endif

#if defined(__MMI_ZI_MARATHI__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_MARATHI,"Smart Marathi","Input methods list Option Smart Marathi");
#endif

#if defined(__MMI_ZI_PUNJABI__) 
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_PUNJABI,"Smart Punjabi","Input methods list Option Smart Punjabi");
#endif

#if defined(__MMI_ZI_TAMIL__) 
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_TAMIL,"Smart Tamil","Input methods list Option Smart Tamil");
#endif

#if defined(__MMI_ZI_TELUGU__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_TELUGU,"Smart Telugu","Input methods list Option Smart Telugu");
#endif
#if defined(__MMI_T9_PORTUGUESE__)||defined(__MMI_ZI_EU_PORTUGUESE__)||defined(__MMI_ZI_SA_PORTUGUESE__)||defined(__MMI_ZI_BZ_PORTUGUESE__) || defined(__MMI_CSTAR_PORTUGUESE__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_PORTUGUESE,"Smart PT","Input methods list Option Smart PT");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_PORTUGUESE,"Smart pt","Input methods list Option Smart pt");
#endif	
#if defined(__MMI_MULTITAP_PORTUGUESE__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_PORTUGUESE,"Multitap PT","Input methods list Option Multitap PT");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_PORTUGUESE,"Multitap pt","Input methods list Option Multitap pt");
#endif

#if defined (__MMI_MULTITAP_THAI__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_THAI,"Multitap Thai","Input methods list Option Multitap Thai");
#endif

#if defined (__MMI_MULTITAP_HEBREW__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_HEBREW,"Multitap Hebrew","Input methods list Option Multitap Hebrew");
#endif
#if defined(__MMI_MULTITAP_HINDI__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_HINDI,"Multitap Hindi","Input methods list Option Multitap Hindi");
#endif
#if defined(__MMI_MULTITAP_TAMIL__) 
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_TAMIL,"Multitap Tamil","Input methods list Option Multitap Tamil");
#endif
#if defined (__MMI_MULTITAP_BENGALI__)  
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_BENGALI,"Multitap Bengali","Input methods list Option Multitap Bengali");
#endif
#if defined(__MMI_MULTITAP_PUNJABI__) 
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_PUNJABI,"Multitap Punjabi","Input methods list Option Multitap Punjabi");
#endif
#if defined(__MMI_MULTITAP_TELUGU__) 
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_TELUGU,"Multitap Telugu","Input methods list Option Multitap Telugu");
#endif
#if defined(__MMI_ZI_TURKISH__)||defined(__MMI_T9_TURKISH__) || defined(__MMI_CSTAR_TURKISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_TURKISH,"Smart TR","Input methods list Option Smart TR");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_TURKISH,"Smart tr","Input methods list Option Smart tr");
#endif	
#if defined(__MMI_MULTITAP_TURKISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_TURKISH,"Multitap TR","Input methods list Option Multitap TR");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_TURKISH,"Multitap tr","Input methods list Option Multitap tr");
#endif
#if defined(__MMI_ZI_INDONESIAN__)||defined(__MMI_T9_INDONESIAN__)  || defined(__MMI_CSTAR_INDONESIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_INDONESIAN,"Smart ID","Input methods list Option Smart ID");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_INDONESIAN,"Smart id","Input methods list Option Smart id");
#endif	
#if defined(__MMI_MULTITAP_INDONESIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_INDONESIAN,"Multitap ID","Input methods list Option Multitap ID");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_INDONESIAN,"Multitap id","Input methods list Option Multitap id");
#endif
#if defined(__MMI_ZI_CZECH__)||defined(__MMI_T9_CZECH__) || defined(__MMI_CSTAR_CZECH__)// Gurdev 20050713 // Gurdev 20050713
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_CZECH,"Smart CZECH","Input methods list Option Smart CZECH");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_CZECH,"Smart czech","Input methods list Option Smart czech");
#endif	
#if defined(__MMI_MULTITAP_CZECH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_CZECH,"Multitap CZECH","Input methods list Option Multitap CZECH");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_CZECH,"Multitap czech","Input methods list Option Multitap czech");
#endif
#if defined(__MMI_ZI_MALAY__)||defined(__MMI_T9_MALAY__) || defined(__MMI_CSTAR_MALAY__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_MALAY,"Smart MS","Input methods list Option Smart MS");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_MALAY,"Smart ms","Input methods list Option Smart ms");
#endif	
#if defined(__MMI_MULTITAP_MALAY__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_MALAY,"Multitap MS","Input methods list Option Multitap MS");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_MALAY,"Multitap ms","Input methods list Option Multitap ms");
#endif
#if defined(__MMI_ZI_VIETNAMESE__)||defined(__MMI_T9_VIETNAMESE__)   || defined(__MMI_CSTAR_VIETNAMESE__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_VIETNAMESE,"Smart VI","Input methods list Option Smart VI");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_VIETNAMESE,"Smart vi","Input methods list Option Smart vi");
#endif	
#if defined(__MMI_MULTITAP_VIETNAMESE__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_VIETNAMESE,"Multitap VI","Input methods list Option Multitap VI");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_VIETNAMESE,"Multitap vi","Input methods list Option Multitap vi");
#endif
#if defined(__MMI_MULTITAP_FINNISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_FINNISH,"Multitap FI","Input methods list Option Multitap FI");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_FINNISH,"Multitap fi","Input methods list Option Multitap fi");
#endif	
#if defined(__MMI_T9_FINNISH__)||defined(__MMI_ZI_FINNISH__) || defined(__MMI_CSTAR_FINNISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_FINNISH,"Smart FI","Input methods list Option Smart FI");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_FINNISH,"Smart fi","Input methods list Option Smart fi");
#endif
#if defined(__MMI_ZI_HUNGARIAN__)||defined(__MMI_T9_HUNGARIAN__)  || defined(__MMI_CSTAR_HUNGARIAN__)// Gurdev 20050713
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_HUNGARIAN,"Smart HUNGARIAN","Input methods list Option Smart HUNGARIAN");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_HUNGARIAN,"Smart hungarian","Input methods list Option Smart hungarian");
#endif	
#if defined(__MMI_MULTITAP_HUNGARIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_HUNGARIAN,"Multitap HUNGARIAN","Input methods list Option Multitap HUNGARIAN");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_HUNGARIAN,"Multitap hungarian","Input methods list Option Multitap hungarian");
#endif
#if defined(__MMI_T9_NORWEGIAN__)  ||defined(__MMI_ZI_NORWEGIAN__)   || defined(__MMI_CSTAR_NORWEGIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_NORWEGIAN,"Smart NO","Input methods list Option Smart NO");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_NORWEGIAN,"Smart no","Input methods list Option Smart no");
#endif	
#if defined(__MMI_MULTITAP_NORWEGIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_NORWEGIAN,"Multitap NO","Input methods list Option Multitap NO");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_NORWEGIAN,"Multitap no","Input methods list Option Multitap no");
#endif
#if defined(__MMI_MULTITAP_SLOVAK__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_SLOVAK,"Multitap SK","Input methods list Option Multitap SK");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_SLOVAK,"Multitap sk","Input methods list Option Multitap sk");
#endif	
#if defined(__MMI_T9_SLOVAK__)||defined(__MMI_ZI_SLOVAK__) || defined(__MMI_CSTAR_SLOVAK__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_SLOVAK,"Smart SK","Input methods list Option Smart SK");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_SLOVAK,"Smart sk","Input methods list Option Smart sk");
#endif
#if defined(__MMI_ZI_DUTCH__)||defined(__MMI_T9_DUTCH__)   || defined(__MMI_CSTAR_DUTCH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_DUTCH,"Smart NL","Input methods list Option Smart VI");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_DUTCH,"Smart nl","Input methods list Option Smart vi");
#endif	
#if defined(__MMI_MULTITAP_DUTCH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_DUTCH,"Multitap NL","Input methods list Option Multitap VI");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_DUTCH,"Multitap nl","Input methods list Option Multitap vi");
#endif
#if defined(__MMI_MULTITAP_SWEDISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_SWEDISH,"Multitap SV","Input methods list Option Multitap SV");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_SWEDISH,"Multitap sv","Input methods list Option Multitap sv");
#endif	
#if defined(__MMI_T9_SWEDISH__)||defined(__MMI_ZI_SWEDISH__) || defined(__MMI_CSTAR_SWEDISH__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_SWEDISH,"Smart SV","Input methods list Option Smart SV");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_SWEDISH,"Smart sv","Input methods list Option Smart sv");
#endif

#if defined(__MMI_MULTITAP_CROATIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_CROATIAN,"Multitap HR","Input methods list Option Multitap HR");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_CROATIAN,"Multitap hr","Input methods list Option Multitap hr");
#endif	
#if defined(__MMI_T9_CROATIAN__)||defined(__MMI_ZI_CROATIAN__) || defined(__MMI_CSTAR_CROATIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_CROATIAN,"Smart HR","Input methods list Option Smart HR");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_CROATIAN,"Smart hr","Input methods list Option Smart hr");
#endif
#if defined(__MMI_ZI_ROMANIAN__)||defined(__MMI_T9_ROMANIAN__) || defined(__MMI_CSTAR_ROMANIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_ROMANIAN,"Smart RO","Input methods list Option Smart RM");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_ROMANIAN,"Smart ro","Input methods list Option Smart rm");
#endif	
#if defined(__MMI_MULTITAP_ROMANIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_ROMANIAN,"Multitap RO","Input methods list Option Multitap RM");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_ROMANIAN,"Multitap ro","Input methods list Option Multitap rm");
#endif
#if defined(__MMI_MULTITAP_SLOVENIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_SLOVENIAN,"Multitap SL","Input methods list Option Multitap SL");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_SLOVENIAN,"Multitap sl","Input methods list Option Multitap sl");
#endif	
#if defined(__MMI_T9_SLOVENIAN__)||defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_CSTAR_SLOVENIAN__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_SLOVENIAN,"Smart SL","Input methods list Option Smart SL");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_SLOVENIAN,"Smart sl","Input methods list Option Smart sl");
#endif

#if defined(__MMI_MULTITAP_GREEK__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_U_GREEK,"Multitap EL","Input methods list Option Multitap EL");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_MULTITAP_L_GREEK,"Multitap el","Input methods list Option Multitap el");
#endif	
#if defined(__MMI_T9_GREEK__)||defined(__MMI_ZI_GREEK__) || defined(__MMI_CSTAR_GREEK__)
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_U_GREEK,"Smart EL","Input methods list Option Smart EL");
	ADD_APPLICATION_STRING2(STR_INPUT_METHOD_MENU_SMART_L_GREEK,"Smart el","Input methods list Option Smart el");
#endif

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
	ADD_APPLICATION_STRING2(STR_ID_IME_WRITING_LANGUAGE_123 ,"123...","123...");
	ADD_APPLICATION_STRING2(STR_ID_IMG_WRITING_LANGUAGE_NONE ,"None", "None");
#endif


    ADD_APPLICATION_STRING2(STR_ID_APPMEM_WAITING_FOR_STOP, "Please Wait...", "Waiting for stopping an application");
    ADD_APPLICATION_STRING2(STR_ID_APPMEM_ATTR_STOPPING, " (Stopping)", "Attribute of an application being stopped");
    ADD_APPLICATION_STRING2(STR_ID_APPMEM_PROMPT_STOP_APP, "Stop other applications to release memory", "help text");
    ADD_APPLICATION_STRING2(STR_ID_APPMEM_STOP, "Stop", "Stop text "); 
    ADD_APPLICATION_STRING2(STR_ID_APPMEM_WAIT, "Wait", "Wait text in Softkey");
    ADD_APPLICATION_STRING2(STR_ID_APPMEM_OUT_OF_MEMORY, "Out of Memory", "Out of Memory");
    ADD_APPLICATION_STRING2(STR_ID_APPMEM_NOTIFY_STARTING_NEW, "Starting New Application", "Dialog message");        
    ADD_APPLICATION_STRING2(STR_ID_APPMEM_NOTIFY_STOPPED, "Application Stopped", "Dialog message");
    ADD_APPLICATION_STRING2(STR_ID_APPMEM_NOTIFY_STOP_FAILED, "Failed to Stop Application", "Dialog message");        
}



