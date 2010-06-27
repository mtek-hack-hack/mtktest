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


#include "CustDataRes.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "FontDCl.h"
#include "FontRes.h"
#include "GlobalMenuItems.h"



#define	MAX_TOTALSTRLEN_1	90000 
#define	MAX_STRINGID_1	MAX_STRING_MAP_SIZE


unsigned short  CurrMaxMenuItemIndex=1500;

unsigned short CurrMaxImageId=1000;
unsigned short CurrMaxSearchImageId=150;
unsigned short  CurrMaxImageNum=600;
unsigned short CurrMaxImageIdEXT=1000;
unsigned short CurrMaxSearchImageIdEXT=150;
unsigned short  CurrMaxImageNumEXT=600;

/*101205 audio resource Calvin Satrt */
unsigned short CurrMaxAudioId=1000;
unsigned short CurrMaxSearchAudioId=150;
unsigned short  CurrMaxAudioNum=600;
unsigned short CurrMaxAudioIdEXT=1000;
unsigned short CurrMaxSearchAudioIdEXT=150;
unsigned short  CurrMaxAudioNumEXT=600;
/*101205 audio resource Calvin End */

/* 101806 E-NFB start */
// #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
unsigned short CurrMaxENFBAssociatedIDNum=0;
CUSTOM_ENFB_STR ENFBAssociatedIDList[MAX_ASSOCIATED_IDS];
// #endif
/* 101806 E-NFB end */

/* dummy declaration for resource gen */

sLanguageDetails gLanguageArray[MAX_LANGUAGES];
U16 gMaxDeployedLangs = 3;

//CUSTOM_IMAGE	nCustImageNames[MAX_IMAGE_NAMES_SIZE];
CUSTOM_IMAGE_MAP ImageIdMap[MAX_IMAGE_IDS_SIZE];
CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMap[500];

// __CUSTPACK_MULTIBIN Calvin BEGIN
/* 040805 CustPack: Calvin added */
CUSTOM_IMAGE_MAP ImageIdMapEXT[MAX_IMAGE_IDS_SIZE];
CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMapEXT[500];
/* Calvin end */
// __CUSTPACK_MULTIBIN Calvin END

/*
CUSTOM_STRING_MAP	StrMap_1[MAX_STRINGID_1];
CUSTOM_STRING	StrRes_1[MAX_TOTALSTRLEN_1];
CUSTOM_STRMAP_SEARCH	StrMapSearch[500];

StringResList	gStringList[MAX_LANGUAGES]={
{(CUSTOM_STRING*)StrRes_1,2688,(CUSTOM_STRING_MAP*)StrMap_1,3625,(CUSTOM_STRMAP_SEARCH *)StrMapSearch,223}, 
};
*/


IMAGENAME_LIST	ImageNameList[MAX_IMAGE_NAMES_SIZE];

// __CUSTPACK_MULTIBIN Calvin BEGIN
IMAGENAME_LIST	ImageNameListEXT[MAX_IMAGE_NAMES_SIZE];//040805 CustPack: Calvin added
// __CUSTPACK_MULTIBIN Calvin END

/*101205 audio resource Calvin Satrt */
CUSTOM_AUDIO_MAP AudioIdMap[MAX_AUDIO_IDS_SIZE];
CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMap[500];
CUSTOM_AUDIO_MAP AudioIdMapEXT[MAX_AUDIO_IDS_SIZE];
CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMapEXT[500];
AUDIONAME_LIST	AudioNameList[MAX_AUDIO_NAMES_SIZE];
AUDIONAME_LIST	AudioNameListEXT[MAX_AUDIO_NAMES_SIZE];//040805 CustPack: Calvin added
/*101205 audio resource Calvin End */

CUSTOM_MENU		nCustMenus[MAX_MENU_ITEMS];

