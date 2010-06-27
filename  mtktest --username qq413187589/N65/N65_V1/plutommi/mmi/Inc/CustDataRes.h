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
 *  CustDataRes.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************
   FILENAME : CustDataRes.h

      PURPOSE     : To define Common Structures used by the UI Elements and Cutomization Tool 
              for Customizing Strings and Images.

   REMARKS     : nil

   AUTHOR      : Subramanya BG 

   DATE     : 20thSept 2002.

   Copyright (c) 2002 All rights reserved by Pixtel Communications
*************************************************************/

#ifndef _PIXCOM_CUSTDATARES_H
#define _PIXCOM_CUSTDATARES_H

#include "MMIDataType.h"
// #include "CustDataProts.h"

/* 101806 E-NFB start */
#define MAX_ASSOCIATED_IDS	256
#define MAX_ASSOCIATED_LIST_IDS	256
/* 101806 E-NFB end */

#define  MAX_STRING_MAP_SIZE     65000
#define MAX_IMAGE_IDS_SIZE    65000
#define MAX_IMAGE_NAMES_SIZE  3000      /* Max Images Name */
/* 101205 audio resource Calvin Satrt */
#define MAX_AUDIO_IDS_SIZE    65000
#define MAX_AUDIO_NAMES_SIZE  3000      /* Max Audio Name */
/* 101205 audio resource Calvin End */

#define MAX_FILENAME_LEN      256       /* This defines the maximun length customizable string can have. */

/* neerajm5 */
#ifdef __MOD_SMSAL__
#define MAX_STRING_IDS        5000      /* Max StringIds to be Set by the pgmer. */
// #define MAX_IMAGE_IDS                        3000 //Max ImageIds to be Set by the pgmer.
#define MAX_SCREEN_IDS        1000      /* Max ScreenIds to be Set by the pgmer. */
#define MAX_ITEMS          1000 /* Max ItemsIds used for customizing structure to be Set by the pgmer. */
#else /* __MOD_SMSAL__ */ 
#define MAX_STRING_IDS        5000      /* Max StringIds to be Set by the pgmer. */
// #define MAX_IMAGE_IDS                        3000 //Max ImageIds to be Set by the pgmer.
#define MAX_SCREEN_IDS        1000      /* Max ScreenIds to be Set by the pgmer. */
#define MAX_ITEMS          1000 /* Max ItemsIds used for customizing structure to be Set by the pgmer. */
#endif /* __MOD_SMSAL__ */ 

#if defined DEVAPP_RESOURCE
#define STR_DATA_FILENAME     "..\\..\\VendorApp\\DevResource\\Resources\\DevAppStrRes.c"
#define STR_MAP_FILENAME      "..\\..\\VendorApp\\DevResource\\Resources\\DevAppStrMap.c"

#define IMG_DATA_FILENAME     "..\\..\\VendorApp\\DevResource\\Resources\\DevAppImgRes.c"
#define IMG_MAP_FILENAME      "..\\..\\VendorApp\\DevResource\\Resources\\DevAppImgMap.c"
#define HW_IMAGE_FILENAME     "..\\..\\VendorApp\\DevResource\\Resources\\DevAppImgDataHW.h"

#define ADO_DATA_FILENAME     "..\\..\\VendorApp\\DevResource\\Resources\\DevAppAdoRes.c"
#define ADO_MAP_FILENAME      "..\\..\\VendorApp\\DevResource\\Resources\\DevAppAdoMap.c"
#define HW_AUDIO_FILENAME     "..\\..\\VendorApp\\DevResource\\Resources\\DevAppAdoDataHW.h"

#define MENU_DATA_FILENAME    "..\\..\\VendorApp\\DevResource\\Resources\\DevAppMenuRes.c"

#define CUS_STR_RES_FILENAME     "..\\DevResource\\Resources\\CustStrList.txt"  /* Filename containg the array of STRING_LIST. */

#else /* defined DEVAPP_RESOURCE */ 

#define STR_DATA_FILENAME     "..\\..\\Customer\\CustResource\\CustStrRes.c"    /* Filename containg the array of CUSTOM_STRING. */
#define STR_MAP_FILENAME      "..\\..\\Customer\\CustResource\\CustStrMap.c"    /* Filename containg the array of CUSTOM_STRING_MAP. */

#define IMG_DATA_FILENAME     "..\\..\\Customer\\CustResource\\CustImgRes.c"    /* Filename containg the array of CUSTOM_IMAGE. */
#define IMG_MAP_FILENAME      "..\\..\\Customer\\CustResource\\CustImgMap.c"    /* Filename containg the array of CUSTOM_IMAGE_MAP. */
#define HW_IMAGE_FILENAME     "..\\..\\Customer\\CustResource\\CustImgDataHW.h"

#define ADO_DATA_FILENAME     "..\\..\\Customer\\CustResource\\CustAdoRes.c"
#define ADO_MAP_FILENAME      "..\\..\\Customer\\CustResource\\CustAdoMap.c"
#define HW_AUDIO_FILENAME     "..\\..\\Customer\\CustResource\\CustAdoDataHW.h"

#define MENU_DATA_FILENAME    "..\\..\\Customer\\CustResource\\CustMenuRes.c"   /* Filename containg the array of CUSTOM_MENU. */

#define CUS_STR_RES_FILENAME     "..\\CustResource\\CustStrList.txt"    /* Filename containg the array of STRING_LIST. */

#endif

#define IMG_DATA_FILENAME_EXT    "..\\..\\Customer\\CustResource\\CustImgResExt.c"      /* 040805 CustPack: Calvin added for newly separated set of images */
#define IMG_MAP_FILENAME_EXT     "..\\..\\Customer\\CustResource\\CustImgMapExt.c"      /* 040805 CustPack: Calvin added for newly separated set of images */
#define HW_IMAGE_FILENAME_EXT "..\\..\\Customer\\CustResource\\CustImgDataHWExt.h"
#define JAVA_GAME_FILENAME "..\\..\\Customer\\CustResource\\CustGameDataHW.h"

#define ADO_DATA_FILENAME_EXT    "..\\..\\Customer\\CustResource\\CustAdoResExt.c"
#define ADO_MAP_FILENAME_EXT     "..\\..\\Customer\\CustResource\\CustAdoMapExt.c"
#define HW_AUDIO_FILENAME_EXT "..\\..\\Customer\\CustResource\\CustAdoDataHWExt.h"

#define THEMES_RES_FILENAME      "..\\..\\Customer\\CustResource\\ThemeRes.c"   /* Filename containg the array of CUSTOM_THEMES. */
#define THEMES_RES_TABLE_FILENAME   "..\\..\\Customer\\CustResource\\ThemeResTable.c"   /* Filename containg the array of CUSTOM_THEMES_TABLE. */
#define THEMES_UI_FILENAME    "..\\..\\Customer\\CustResource\\ThemeComponents.h"       /* Filename containg the Filled Areas and Colors Declaration. */
#define THEMES_UI_FILENAME_EXTERN   "..\\..\\Customer\\CustResource\\ThemeComponentsx.h"        /* Filename containg the Externs for Filled Areas and Colors Declaration. */
#define GUI_SETTING_FILENAME  "..\\..\\Customer\\CustResource\\Gui_Setting.h"   /* Filename containg Gui settings define. */
#define BUILD_CFG_FILE        "..\\inc\\BuildCfg.h"     /* Filename containing the config flags */
#define CUSTOM_CFG_FILE       "..\\inc\\CustomCfg.h"    /* Filename containing the flag for developer first build */
#define FONT_FILENAME         "..\\..\\Customer\\CustResource\\FontRes.c"
#define GIFCONVERTER_FILENAME    "..\\..\\Customer\\Images\\Gifload.exe"
#define BMPCONVERTER_FILENAME    "..\\..\\Customer\\Images\\Bmpload.exe"
#define EMSCONVERTER_FILENAME    "..\\..\\Customer\\Images\\EMSLoad.exe"
#define EMS_IMAGE_PATH        "MAINLCD\\\\SMS\\\\PIC"
#define SUBMENU_IMAGE_PATH       "MAINLCD\\\\SUBMENU"
#define NFB_IMAGE_DATA_FILENAME "..\\..\\Customer\\CustResource\\CustNFBProgressImg.h"
#define NFB_IMAGE_RES_FILENAME  "..\\..\\Customer\\CustResource\\CustNFBProgressImg.c"

/* 101806 E-NFB start */
#define ENFB_DATA_FILENAME      "..\\..\\Customer\\CustResource\\CustENFBImgMap.c"
/* 101806 E-NFB end */

/* Custom_String is the typedef array of customizable strings. */

/* typedef struct Custom_String
   {
   
   //#ifdef __UCS2_ENCODING
   // WCHAR  str[MAX_STRING_LEN];      //Customizable Strings.
   //#endif
   
   //#ifdef __ASCII
   S8  str[MAX_STRING_LEN];      //Customizable Strings.
   //#endif
   
   
   }CUSTOM_STRING; */

typedef U8 CUSTOM_STRING;

/* Custom_StringMap is the mapping array btw StringId & StringNum. */

typedef U32 CUSTOM_STRING_MAP;

typedef struct Custom_StrMap_Search
{
    U16 nMinStrId;  /* Minimum StringID defined by the developer. */
    U16 nMaxStrId;  /* Maximum StringID defined by the developer. */
    U16 nMapIndex;  /* Index of str in Custom_String_MAP. */
} CUSTOM_STRMAP_SEARCH;

typedef struct StringResourceList
{
    CUSTOM_STRING *pStringRes;
    U16 nTotalStrRes;
    CUSTOM_STRING_MAP *pStringMap;
    U16 nTotalStrMap;
    CUSTOM_STRMAP_SEARCH *pStrMapSearch;
    U16 nTotalStrMapSearch;
} StringResList;

//The below function updates the CUSTOM_STRING_MAP and CUSTOM_STRING Structure.
//MTK Leo add, for generate string list file in first pass.
extern void SetString(U16 StrId, S8 *String, S8 *enum_value, S8 *resfile);

/* MTK end */
extern void ClearHWIMageFile(void);

/* The below function gives the string of the StringId. */
extern S8 *GetString(U16 StringId);

/* The below function gives the string of the stringId, */
extern S8 *GetStringLang(U16 StringId, U16 lang_index);

/* The below function gives the current phone model */
extern const PS8 mmi_get_phone_model(void);

/* the below function gives the list of languages available on the device */
extern U16 GetLanguages(U8 ***pppLanguages);

/* the below function give the index of language specified by ssc_string */
extern U16 GetLanguageIndex(S8 *ssc_str);

/* the below function give the index of language specifid by lang_code */
extern U16 GetLanguageIndexByLangCode(S8 *lang_code);

/* the following functon sets the current language to the index specified */
extern void SetCurrentLanguage(S8 nIndex);

//MTK Leo add 20040409, to sync titleicon
//the following function gives the root menuitem index of ItemId in mainmenu
extern U16 GetRootParentIndex(U16 ItemId);

//MTK Leo end
//Custom_Image is the typedef array of customizable Images.
/* Converts the Image file name to Framework format */
typedef struct Custom_Image
{
    PU8 pImage; /* Customizable Image filenames. */
} CUSTOM_IMAGE;

typedef struct ImageNameList
{
    S8 filename[MAX_FILENAME_LEN];
} IMAGENAME_LIST;

/* Custom_ImageMap is the mapping array btw ImageId & ImageNum. */
typedef struct Custom_ImageMap
{
    U16 nImageNum;  /* Index of str in Custom_Image. */
} CUSTOM_IMAGE_MAP;

typedef struct Custom_ImageMapSearch
{
    U16 minImageId; /* Minimum ImageId defined by the developer. */
    U16 maxImageId; /* Maximum ImageId defined by the developer. */
    U16 index;      /* Index of str in Custom_Image. */
} CUSTOM_IMAGE_SEARCH_MAP;

/* 101806 E-NFB start */
typedef struct Custom_ENFB
{
    U16 count;
    U16 *IDs;
    CUSTOM_IMAGE *Ptr;
} CUSTOM_ENFB;

typedef struct Custom_ENFB_Str
{
    U16 count;
    U16 *IDs;
    S8 **Ptr;
} CUSTOM_ENFB_STR;
/* 101806 E-NFB end */

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
/* 040805 CustPack: Calvin added */
typedef struct CustPack_Image_Header
{
    unsigned short MaxImageNumEXT;
    CUSTOM_IMAGE *CustImageNamesEXT;
} CUSTPACK_IMAGE_HEADER;

/* Calvin end */
/* __CUSTPACK_MULTIBIN Calvin END */

/* 101205 audio resource Calvin Satrt */
typedef struct Custom_Audio
{
    PU8 pAudio; /* Customizable Image filenames. */
} CUSTOM_AUDIO;

typedef struct AudioNameList
{
    S8 filename[MAX_FILENAME_LEN];
} AUDIONAME_LIST;

typedef struct Custom_AudioMap
{
    U16 nAudioNum;  /* Index of str in Custom_Image. */
} CUSTOM_AUDIO_MAP;

typedef struct Custom_AudioMapSearch
{
    U16 minAudioId; /* Minimum ImageId defined by the developer. */
    U16 maxAudioId; /* Maximum ImageId defined by the developer. */
    U16 index;      /* Index of str in Custom_Image. */
} CUSTOM_AUDIO_SEARCH_MAP;

typedef struct CustPack_Audio_Header
{
    unsigned short MaxAudioNumEXT;
    CUSTOM_AUDIO *CustAudioNamesEXT;
} CUSTPACK_AUDIO_HEADER;

/* 101205 audio resource Calvin End */

typedef struct
{
    S8 filename[MAX_FILENAME_LEN];
    S32 size;
} CUSTOM_RESOURCE_SIZE;

extern S8 *GetImage(U16 ImageId);
extern S8 *GetAudio(U16 AudioId);   /* 101205 audio resource Calvin added */

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern U16 GetImageIndex(U16 ImageId);
extern S8 *GetDefaultImage(void);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#define GetMedia(VideoId)  GetImage((U16)(VideoId))     /* 120304 Calvin added */

/* The below functions shall set the current max string ids and string numbers being populated in the string res files */
/* ===================Below Structures are mainly used for Customizing Tool========. */

/* Below are the flags of ItemTypes which gives us the Item Type and Item Layout. */

/* Text types */
#define CAPTION_TEXT       1
#define MENUITEM_TEXT         2
#define BUTTON1_TEXT       3
#define BUTTON2_TEXT       4
#define GENERAL_TEXT       5
#define RUNNING_TEXT       6
/* IMAGES are greater then 20. */
#define CAPTION_IMAGE         21
#define MENUITEMITEM_IMAGE    22
#define BUTTON1_IMAGE         23
#define BUTTON2_IMAGE         24
#define GENERAL_IMAGE         25
#define RUNNING_IMAGE         26

//Custom_ScreenItem is structure mainly used for the Customizing tool.
//This structure is necessary to display StringId/ImageId with screen id.
typedef struct Custom_ScreenItem
{
    U16 nItemId;    /* This can be a StringId or ImageId which would */
    /* be present in Custom_ImageMap/Custom_StringMap. */
    U16 nItemType;  /* This is a flag which are defined above for details. */
} CUSTOM_SCREEN_ITEM;

typedef struct Custom_Screen
{
    U16 nScrId;                                     /* Unique ScreenId defined by the developer. */
    U16 nNumofItem;                                 /* Number of Items in the screen. */
    struct Custom_ScreenItem ScreenItem[MAX_ITEMS]; /* defined above with details. */
} CUSTOM_SCREEN;

typedef struct ResourceInfo
{
    void *pValue;
    void *pDisplayValue;
    U32 nAppId;
    U32 nMinId;
    U32 nMaxId;
} ResourceInfo;

typedef struct MenuInfo
{
    U16 nId;
    U16 nParentId;
} MENU_INFO;

typedef struct ScreenInfo
{
    U16 nStringIdList[460];
    U16 nNoOfStrings;
    U16 nImageIdList[460];
    U16 nNoOfImages;
    MENU_INFO sMenuInfo[10];
    U16 nNoOfMenus;
} CURR_SCREEN_RESOURCE;

extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);

#endif /* _PIXCOM_CUSTDATARES_H */ 

