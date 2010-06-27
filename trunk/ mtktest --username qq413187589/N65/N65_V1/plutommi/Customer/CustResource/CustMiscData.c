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
/************************************************************** 
 FILENAME		: CustMiscData.c 
 PURPOSE		: Customized data items. 
 REMARKS		: nil 
 AUTHOR			: Customer
 DATE			: 
 **************************************************************/
#include "PixtelDataTypes.h"
#include "gui_setting.h"
//micha0406
#include "SimDetectionDef.h"
#include "CustResDef.h"
#ifdef __MMI_MESSAGES_CLUB__
#include "MessagesResourceData.h"
#include "MessagesExDcl.h"
#endif
//PMT VIKAS START 20050707
#if defined(__MMI_UI_DALMATIAN_STATUSBAR__) || defined(__MMI_UI_DALMATIAN_SOFTKEYS__)
#include "wgui.h"
#endif
//PMT VIKAS END 20050707
/***************************************************************
Start of SMS Club
****************************************************************/
#ifdef __MMI_MESSAGES_CLUB__
#define MSG_CLUB_NUMBER_CT "3355"
#define MSG_CLUB_NUMBER_CU "9355"

#define MSG_CLUB_NUMBER_BEGIN "61051011"
#define MSG_CLUB_NUMBER_END "00"

#define MSG_CLUB_NUMBER_OTHER_CT ""
#define MSG_CLUB_NUMBER_OTHER_CU "2704"

#define MSG_CLUB_DUMMY_CODE	"S00:"

#define MSG_CLUB_CODE_SUBSCRIBE "DY"
#define MSG_CLUB_CODE_ORDER "DB"
#define MSG_CLUB_CODE_EXPLAIN "ZF"

#define MSG_CLUB_CODE_CANCEL "0000"
#define MSG_CLUB_CODE_MORE "MORE"


typedef enum
{
	MSG_CLUB_COMIC,
	MSG_CLUB_LOVE,	
	MSG_CLUB_CHAT,
	MSG_CLUB_JOKE,
	MSG_CLUB_SEX,
	MSG_CLUB_FEMALE,
	MSG_CLUB_SPORT,
	MSG_CLUB_AUGURY,
	MSG_CLUB_OCCULT,
	MSG_CLUB_SWORDSMEN,
	MSG_CLUB_INTELLIGENCE,
	MSG_CLUB_ENTERTAIN,
	MSG_CLUB_CULTURE,
	MSG_CLUB_AFFAIRS,
	MSG_CLUB_ENGLISH,
	MSG_CLUB_FUNNY,
	MSG_CLUB_WEATHER,
	MSG_CLUB_VOICE,	
	MSG_CLUB_QUIT,
	MSG_CLUB_MORE,
	MSG_CLUB_NUM_OF_ITEMS
}msg_club_enum;

typedef enum
{
	MSG_CLUB_VOICE_CINEMA,
	MSG_CLUB_VOICE_ENGLISH,
	MSG_COUB_VOICE_HEALTHY,
	MSG_CLUB_NUM_OF_VOICE_ITEMS
}msg_club_voice_enum;

const msg_club_submenu_struct SubMenuComic[]=
{
	{STR_MSG_CLUB_01_01, {"PK", "PK"}, {"", ""}, "YXFHNLSL"},
	{STR_MSG_CLUB_01_02, {"WR", "WR"}, {"", ""}, "WEWRMS"},
	{STR_MSG_CLUB_01_03, {"AL", "AL"}, {"", ""}, "YXFHAL"},
	{STR_MSG_CLUB_01_04, {"MQ", "MQ"}, {"", ""}, "YXLABD"}
};

const msg_club_submenu_struct SubMenuLove[]=
{
	{STR_MSG_CLUB_02_01, {"Y", "Y"}, {"", ""}, "YXYWCS"},
	{STR_MSG_CLUB_02_02, {"MM", "MM"}, {"", ""}, "YXJQNV"},
	{STR_MSG_CLUB_02_03, {"QASX", "QASX"}, {"", ""}, "YXQASX"},
	{STR_MSG_CLUB_02_04, {"AT", "AT"}, {"", ""}, "YXCSKAL"},
	{STR_MSG_CLUB_02_05, {"LC", "LC"}, {"", ""}, "YXLC"}
};

const msg_club_submenu_struct SubMenuChat[]=
{
	{STR_MSG_CLUB_03_01, {"AM", "AM"}, {"", ""}, "YXKZYLQ"},
	{STR_MSG_CLUB_03_02, {"WX", "WX"}, {"", ""}, "YXXDTX"}
};

const msg_club_submenu_struct SubMenuJoke[]=
{
	{STR_MSG_CLUB_04_01, {"JE", "JE"}, {"JPA", "JPA"}, "SFXH"},
	{STR_MSG_CLUB_04_02, {"HP", "HP"}, {"HPA", "HPA"}, "XXKXYX"},
	{STR_MSG_CLUB_04_03, {"LA", "LA"}, {"", ""}, "XXLLXH"},
	{STR_MSG_CLUB_04_04, {"MGD", "MGD"}, {"MGA", "MGA"}, "XXMGCD"}
};

const msg_club_submenu_struct SubMenuSex[]=
{
	{STR_MSG_CLUB_05_01, {"PM", "PM"}, {"PMA", "PMA"}, "XQAR"},
	{STR_MSG_CLUB_05_02, {"SG", "SG"}, {"SGA", "SGA"}, "SHXFSG"},
	{STR_MSG_CLUB_05_03, {"YDLY", "YDLY"}, {"", ""}, "YDLY"},
	{STR_MSG_CLUB_05_04, {"AQ", "AQ"}, {"AQA", "AQA"}, "SHBYJQ"},
	{STR_MSG_CLUB_05_05, {"MJD", "MJD"}, {"MJA", "MJA"}, "SHNXJK"},
	{STR_MSG_CLUB_05_06, {"FJD", "FJD"}, {"FJA", "FJA"}, "SHFNXJK"}
};

const msg_club_submenu_struct SubMenuFemale[]=
{
	{STR_MSG_CLUB_06_01, {"MR", "MR"}, {"MRA", "MRA"}, "SHSSMRKT"},
	{STR_MSG_CLUB_06_02, {"JFD", "JFD"}, {"JFA", "JFA"}, "SHJFSP"},
	{STR_MSG_CLUB_06_03, {"YJD", "YJD"}, {"YJA", "YJA"}, "SHYEJK"},
	{STR_MSG_CLUB_06_04, {"HSD", "HSD"}, {"HSA", "HSA"}, "XXHSSD"},
	{STR_MSG_CLUB_06_05, {"DYD", "DYD"}, {"DYA", "DYA"}, "XXDYZX"}
};

const msg_club_submenu_struct SubMenuSport[]=
{
	{STR_MSG_CLUB_07_01, {"ST", "ST"}, {"", ""}, "YXTYFB"},
	{STR_MSG_CLUB_07_02, {"TDW", "TDW"}, {"TYA", "TYA"}, "XWTYXW"},
	{STR_MSG_CLUB_07_03, {"TYZBJ", "TYZBJ"}, {"", ""}, "XWTYZBJ"},
	{STR_MSG_CLUB_07_04, {"ZCDMG", "ZCDMG"}, {"", ""}, "CPZCDMG"},
	{STR_MSG_CLUB_07_05, {"TYWHT", "TYWHT"}, {"", ""}, "YXTYWHT"}
};

const msg_club_submenu_struct SubMenuAugury[]=
{
	{STR_MSG_CLUB_08_01, {"MF", "MF"}, {"", ""}, "YXZXQY"},
	{STR_MSG_CLUB_08_02, {"XMQY", "XMQY"}, {"", ""}, "YXXMQY"},
	{STR_MSG_CLUB_08_03, {"GM", "GM"}, {"", ""}, "YCXZYC"},
	{STR_MSG_CLUB_08_04, {"TWT", "TWT"}, {"TWA", "TWA"}, "XXXLCS"},
	{STR_MSG_CLUB_08_05, {"CD", "CD"}, {"", ""}, "YXLATS"}
};

const msg_club_submenu_struct SubMenuOccult[]=
{
	{STR_MSG_CLUB_09_01, {"GA", "GA"}, {"", ""}, "YXMHDHGN"},
	{STR_MSG_CLUB_09_02, {"WT", "WT"}, {"", ""}, "YXDHJZJ"},
	{STR_MSG_CLUB_09_03, {"D", "D"}, {"", ""}, "YXZHW"},
	{STR_MSG_CLUB_09_04, {"H", "H"}, {"", ""}, "YXHLBT"}
};

const msg_club_submenu_struct SubMenuSwordsmen[]=
{
	{STR_MSG_CLUB_10_01, {"A", "A"}, {"", ""}, "YXDXYX"},
	{STR_MSG_CLUB_10_02, {"WLCS", "WLCS"}, {"", ""}, "YYWLCS"},
	{STR_MSG_CLUB_10_03, {"JHZX", "JHZX"}, {"", ""}, "YYJHZX"}
};
const msg_club_submenu_struct SubMenuIntelligence[]=
{
	{STR_MSG_CLUB_11_01, {"IQ", "YIQ"}, {"", ""}, "YXIQQ"},
	{STR_MSG_CLUB_11_02, {"YLCC", "YLCC"}, {"", ""}, "YLCCC"},
	{STR_MSG_CLUB_11_03, {"NJ", "NJ"}, {"NJA", "NJA"}, "XXNJJZW"}
};

const msg_club_submenu_struct SubMenuEntertain[]=
{
	{STR_MSG_CLUB_12_01, {"TAW", "TAW"}, {"YLA", "YLA"}, "XWYLXW"},
	{STR_MSG_CLUB_12_02, {"JR", "JR"}, {"", ""}, "TLJRJNH"}
};

const msg_club_submenu_struct SubMenuCulture[]=
{
	{STR_MSG_CLUB_13_01, {"CXD", "CXD"}, {"CXA", "CXA"}, "YCCXCK"},
	{STR_MSG_CLUB_13_02, {"MCD", "MCD"}, {"MCA", "MCA"}, "XXYYZX"},
	{STR_MSG_CLUB_13_03, {"PAM", "PAM"}, {"PAD", "PAD"}, "XXBJYCZX"},
	{STR_MSG_CLUB_13_04, {"SAM", "SAM"}, {"SAD", "SAD"}, "XXSHYCZX"},
	{STR_MSG_CLUB_13_05, {"GAM", "GAM"}, {"GAD", "GAD"}, "XXGZYCZX"},
	{STR_MSG_CLUB_13_06, {"TL", "TL"}, {"", ""}, "TLSSDD"},
	{STR_MSG_CLUB_13_07, {"JTD", "JTD"}, {"JTA", "JTA"}, "SHJTJJCS"}
};

const msg_club_submenu_struct SubMenuAffairs[]=
{
	{STR_MSG_CLUB_14_01, {"QJ", "QJ"}, {"QJA", "QJA"}, "QJXW"},
	{STR_MSG_CLUB_14_02, {"CJW", "CJW"}, {"CJA", "CJA"}, "XWCJXW"},
	{STR_MSG_CLUB_14_03, {"GNW", "GNW"}, {"GNA", "GNA"}, "XWGNXW"},
	{STR_MSG_CLUB_14_04, {"GJW", "GJW"}, {"GJA", "GJA"}, "XWGJXW"},
	{STR_MSG_CLUB_14_05, {"TGW", "TGW"}, {"SHA", "SHA"}, "XWSHXW"},
	{STR_MSG_CLUB_14_06, {"SJW", "SJW"}, {"SJA", "SJA"}, "XWSJXW"},
	{STR_MSG_CLUB_14_07, {"QCW", "QCW"}, {"QCA", "QCA"}, "XWQCXW"},
	{STR_MSG_CLUB_14_08, {"TTW", "TTW"}, {"TTA", "TTA"}, "XWYYTTXW"},
	{STR_MSG_CLUB_14_09, {"EMW", "EMW"}, {"EMA", "EMA"}, "XWYYCJXW"}
};

const msg_club_submenu_struct SubMenuEnglish[]=
{
	{STR_MSG_CLUB_15_01, {"JS", "JS"}, {"", ""}, "WEYYJS"},
	{STR_MSG_CLUB_15_02, {"SJT", "SJT"}, {"SJM", "SJM"}, "WESJCKDY"},
	{STR_MSG_CLUB_15_03, {"LJD", "LJD"}, {"LJG", "LJG"}, "WELJCKYF"},
	{STR_MSG_CLUB_15_04, {"FJT", "FJT"}, {"FJW", "FJW"}, "WESJDGCH"},
	{STR_MSG_CLUB_15_05, {"SJD", "SJD"}, {"LJA", "LJA"}, "WELJDGCH"},
	{STR_MSG_CLUB_15_06, {"XG", "XG"}, {"XGW", "XGW"}, "WEXGN"},
	{STR_MSG_CLUB_15_07, {"YSJ", "YSJ"}, {"YSA", "YSA"}, "WEYSBSJS"},
	{STR_MSG_CLUB_15_08, {"TFJ", "TFJ"}, {"JDA", "JDA"}, "WETFJDJX"},
	{STR_MSG_CLUB_15_09, {"TFD", "TFD"}, {"TFA", "TFA"}, "WETFCH"},
	{STR_MSG_CLUB_15_10, {"TLD", "TLD"}, {"TLA", "TLA"}, "WETFCH"},
	{STR_MSG_CLUB_15_11, {"DCD", "DCD"}, {"DCA", "DCA"}, "WECHYDT"}
};

const msg_club_submenu_struct SubMenuFunny[]=
{
	{STR_MSG_CLUB_16_01, {"WHD", "WHD"}, {"WHA", "WHA"}, "WEYMWHZS"},
	{STR_MSG_CLUB_16_02, {"RKD", "RKD"}, {"RKA", "RKA"}, "WERKL"},
	{STR_MSG_CLUB_16_03, {"AYD", "AYD"}, {"AYA", "AYA"}, "WEAYYY"},
	{STR_MSG_CLUB_16_04, {"BGD", "BGD"}, {"BGA", "BGA"}, "WEBGSYY"},
	{STR_MSG_CLUB_16_05, {"YMD", "YMD"}, {"YMA", "YMA"}, "WEXFLXYM"},
	{STR_MSG_CLUB_16_06, {"DSD", "DSD"}, {"DSA", "DSA"}, "WESWCHYSY"},
	{STR_MSG_CLUB_16_07, {"MRD", "MRD"}, {"MRM", "MRM"}, "WEMRMY"},
	{STR_MSG_CLUB_16_08, {"QHL", "QHL"}, {"QHA", "QHA"}, "WEQHLP"},
	{STR_MSG_CLUB_16_09, {"MWD", "MWD"}, {"MWA", "MWA"}, "WESSCH"},
	{STR_MSG_CLUB_16_10, {"KYD", "KYD"}, {"KYA", "KYA"}, "WECKKY"},
	{STR_MSG_CLUB_16_11, {"MGK", "MGK"}, {"MGW", "MGW"}, "WEMGKY"}
};

const msg_club_submenu_struct SubMenuWeather[]=
{
	{STR_MSG_CLUB_17_01, {"TQ", "TQ"}, {"TW", "TW"}, "TQ"},
	{STR_MSG_CLUB_17_02, {"CY", "CY"}, {"CYA", "CYA"}, "TQCYZS"},
	{STR_MSG_CLUB_17_03, {"LSD", "LS"}, {"LSA", "LSA"}, "TQLSZS"},
	{STR_MSG_CLUB_17_04, {"CLZ", "CL"}, {"CLA", "CLA"}, "TQCLZS"},
	{STR_MSG_CLUB_17_05, {"HZ", "HZ"}, {"HZA", "HZA"}, "TQHZZS"},
	{STR_MSG_CLUB_17_06, {"SSD", "SD"}, {"SDA", "SDA"}, "TQSSDZS"},
	{STR_MSG_CLUB_17_07, {"ZW", "ZW"}, {"ZWA", "ZWA"}, "TQZWXZS"},
	{STR_MSG_CLUB_17_08, {"GMZ", "GMZSA"}, {"GMD", "GMZS"}, "TQGMZS"},
	{STR_MSG_CLUB_17_09, {"ZS", "ZS"}, {"ZSA", "ZSA"}, "TQZSZS"},
	{STR_MSG_CLUB_17_10, {"XC", "XC"}, {"XCA", "XCA"}, "TQXCZS"}
};


const msg_club_submenu_struct SubMenuAirCinema[]=
{
	{STR_MSG_CLUB_VOICE_01_01, {"", ""}, {"", ""}, "125905618019"},
	{STR_MSG_CLUB_VOICE_01_02, {"", ""}, {"", ""}, "125905618029"},
	{STR_MSG_CLUB_VOICE_01_03, {"", ""}, {"", ""}, "125905618039"},
	{STR_MSG_CLUB_VOICE_01_04, {"", ""}, {"", ""}, "125905618049"},
	{STR_MSG_CLUB_VOICE_01_05, {"", ""}, {"", ""}, "125905618059"}
};


const msg_club_submenu_struct SubMenuAirEnglish[]=
{
	{STR_MSG_CLUB_VOICE_02_01, {"", ""}, {"", ""}, "125905688019"},
	{STR_MSG_CLUB_VOICE_02_02, {"", ""}, {"", ""}, "125905688029"},
	{STR_MSG_CLUB_VOICE_02_03, {"", ""}, {"", ""}, "125905688039"}
};

const msg_club_submenu_struct SubMenuAirHealthy[]=
{
	{STR_MSG_CLUB_VOICE_03_01, {"", ""}, {"", ""}, "125905657019"},
	{STR_MSG_CLUB_VOICE_03_02, {"", ""}, {"", ""}, "125905657029"},
	{STR_MSG_CLUB_VOICE_03_03, {"", ""}, {"", ""}, "125905657039"},
	{STR_MSG_CLUB_VOICE_03_04, {"", ""}, {"", ""}, "125905657049"},
	{STR_MSG_CLUB_VOICE_03_05, {"", ""}, {"", ""}, "125905657059"}
};

const msg_club_menu_struct MenuMSGClubVoice[]=
{
	{MSG_CLUB_VOICE_CINEMA, 5, STR_MSG_CLUB_VOICE_01, SubMenuAirCinema},
	{MSG_CLUB_VOICE_ENGLISH, 3, STR_MSG_CLUB_VOICE_02, SubMenuAirEnglish},
	{MSG_COUB_VOICE_HEALTHY, 5, STR_MSG_CLUB_VOICE_03, SubMenuAirHealthy}
};

const msg_club_menu_struct MenuMSGClub[]=
{
	{MSG_CLUB_COMIC, 		4, 	STR_MSG_CLUB_01, SubMenuComic},
	{MSG_CLUB_LOVE, 		5, 	STR_MSG_CLUB_02, SubMenuLove},
	{MSG_CLUB_CHAT, 		2, 	STR_MSG_CLUB_03, SubMenuChat},
	{MSG_CLUB_JOKE, 		4, 	STR_MSG_CLUB_04, SubMenuJoke},
	{MSG_CLUB_SEX, 			6, 	STR_MSG_CLUB_05, SubMenuSex},
	{MSG_CLUB_FEMALE, 		5, 	STR_MSG_CLUB_06, SubMenuFemale},
	{MSG_CLUB_SPORT, 		5, 	STR_MSG_CLUB_07, SubMenuSport},
	{MSG_CLUB_AUGURY, 		5, 	STR_MSG_CLUB_08, SubMenuAugury},
	{MSG_CLUB_OCCULT, 		4, 	STR_MSG_CLUB_09, SubMenuOccult},
	{MSG_CLUB_SWORDSMEN, 	3, 	STR_MSG_CLUB_10, SubMenuSwordsmen},
	{MSG_CLUB_INTELLIGENCE,	3, 	STR_MSG_CLUB_11, SubMenuIntelligence},
	{MSG_CLUB_ENTERTAIN, 	2, 	STR_MSG_CLUB_12, SubMenuEntertain},
	{MSG_CLUB_CULTURE, 		7, 	STR_MSG_CLUB_13, SubMenuCulture},
	{MSG_CLUB_AFFAIRS, 		8, 	STR_MSG_CLUB_14, SubMenuAffairs},
	{MSG_CLUB_ENGLISH, 		11, 	STR_MSG_CLUB_15, SubMenuEnglish},
	{MSG_CLUB_FUNNY, 		11, 	STR_MSG_CLUB_16, SubMenuFunny},
	{MSG_CLUB_WEATHER, 	10, 	STR_MSG_CLUB_17, SubMenuWeather},
	{MSG_CLUB_VOICE, 		0, 	STR_MSG_CLUB_VOICE, NULL},
	{MSG_CLUB_QUIT, 		0, 	STR_MSG_CLUB_QUIT, NULL},
	{MSG_CLUB_MORE, 		0, 	STR_MSG_CLUB_MORE, NULL}
};

U8 mmi_msg_club_get_item_total(void)
{
	return MSG_CLUB_NUM_OF_ITEMS;
}

U8 mmi_msg_club_get_voice_item_index(void)
{
	return MSG_CLUB_VOICE;
}

U8 mmi_msg_club_get_voice_item_total(void)
{
	return MSG_CLUB_NUM_OF_VOICE_ITEMS;
}

S8* mmi_msg_club_get_number_ct(void)
{
	return MSG_CLUB_NUMBER_CT;
}

S8* mmi_msg_club_get_number_cu(void)
{
	return MSG_CLUB_NUMBER_CU;
}

S8* mmi_msg_club_get_number_begin(void)
{
	return MSG_CLUB_NUMBER_BEGIN;
}

S8* mmi_msg_club_get_number_end(void)
{
	return MSG_CLUB_NUMBER_END;
}

S8* mmi_msg_club_get_number_other_ct(void)
{
	return MSG_CLUB_NUMBER_OTHER_CT;
}

S8* mmi_msg_club_get_number_other_cu(void)
{
	return MSG_CLUB_NUMBER_OTHER_CU;
}

S8* mmi_msg_club_get_code_dummy(void)
{
	return MSG_CLUB_DUMMY_CODE;
}

S8* mmi_msg_club_get_code_subscribe(void)
{
	return MSG_CLUB_CODE_SUBSCRIBE;
}

S8* mmi_msg_club_get_code_order(void)
{
	return MSG_CLUB_CODE_ORDER;
}

S8* mmi_msg_club_get_code_explain(void)
{
	return MSG_CLUB_CODE_EXPLAIN;
}

S8* mmi_msg_club_get_code_cancel(void)
{
	return MSG_CLUB_CODE_CANCEL;
}

S8* mmi_msg_club_get_code_more(void)
{
	return MSG_CLUB_CODE_MORE;
}


#endif

/***************************************************************
End of SMS Club
***************************************************************/


/***************************************************************
Start of EMS Template
****************************************************************/
#define EMS_MANUFACTURER_PICTURE_NUM 8
U8 EmsPictureNum(void)
{
	return EMS_MANUFACTURER_PICTURE_NUM;
}
#define EMS_MANUFACTURER_MELODY_NUM 5
U8 EmsMelodyNum(void)
{
	return EMS_MANUFACTURER_MELODY_NUM;
}
/***************************************************************
End of EMS Template
***************************************************************/

/***************************************************************
Start Font Height and Item Height mapping Table
***************************************************************/

#if (LCD_HEIGHT ==128)
const U8 MenuItemHeight[][3]=
{
//PMT VIKAS START 20050913
#if defined(__MMI_UI_DALMATIAN_STATUSBAR__) || defined(__MMI_UI_DALMATIAN_SOFTKEYS__)
{0,16,MMI_MENUITEM_HEIGHT }
#else
{0,16,18}
#endif
//PMT VIKAS END 20050913
};
#elif (LCD_HEIGHT ==160)
const U8 MenuItemHeight[][3]=
{
//PMT VIKAS START 20050913
#if defined(__MMI_UI_DALMATIAN_STATUSBAR__) || defined(__MMI_UI_DALMATIAN_SOFTKEYS__)
{0,15,MMI_MENUITEM_HEIGHT }
#else
{0,15,17},
#endif
//PMT VIKAS END 20050913
{16,18,20}
};
#else 
//Like Jupiter
const U8 MenuItemHeight[][3]=
{
//PMT VIKAS START 20050707
#if defined(__MMI_UI_DALMATIAN_STATUSBAR__) || defined(__MMI_UI_DALMATIAN_SOFTKEYS__)
{0,18,MMI_MENUITEM_HEIGHT }
#else
{0,18,22}
#endif
//PMT VIKAS END 20050707
};
#endif
U8 GetMenuItemHeight(U8 font_height)
{
	U8 range_count = sizeof (MenuItemHeight)/(sizeof(U8)*3);
	U8 i;
	for (i=0;i<range_count;i++)
	{
		if ( font_height>=MenuItemHeight[i][0] && font_height<=MenuItemHeight[i][1] )
			return MenuItemHeight[i][2];
	}
	return 0;
}
/***************************************************************
End of Font Height and Item Height mapping Table
***************************************************************/


/**************************************************************
Start of URL address of Default Downloadable Theme site 
**************************************************************/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

const S8 *gDefaultDLT_URL="http://203.123.36.7/wap";

#endif

/**************************************************************
End of URL address of Default Downloadable Theme site 
**************************************************************/
