/*******************************************************************************
* Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.,
* All rights reserved.
* This is unpublished proprietary source code of MobileSoft Technology
*
* The copyright notice above does not evidence any actual or intended
* publication of such source code 
*******************************************************************************
*/
/*******************************************************************************
* Module Name: cms_wap_custom_config.c 
* Module Function:
* Author Name:
* Create Date:
* 
*******************************************************************************
*/
#ifdef	CMS_NEW_APP
#include "kal_release.h"
#include "cms_wap_custom_config.h"


const	cms_wap_profile_struct  cms_wap_profile_default= 
{
  CMS_CFG_N_WAP_PROFILES,
  {/* wap profile content[N] */
   {
     1,/* config item no empty*/
     {0xE4,0xB8,0xAD,0xE5,0x9B,0xBD,0xE7,0xA7,0xBB,0xE5,0x8A,0xA8},/* config name*/
     "http://wap.skyworthmobile.com",/* config wap homepage*/
     "10.0.0.172",/* config wap gateway*/
     "80",/* config wap port*/
     14,/* config wap account*/
     1/* config wap account type*/
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   }
  }
};

const	cms_mms_profile_struct  cms_mms_profile_default=
{
  CMS_CFG_N_MMS_PROFILES,
  {/* mms profile content[N] */
   {
     1,/* config item no empty*/
     {0xE4,0xB8,0xAD,0xE5,0x9B,0xBD,0xE7,0xA7,0xBB,0xE5,0x8A,0xA8},/* config name*/
     "http://mmsc.monternet.com",/* config mms centre*/
     "10.0.0.172",/* config mms gateway*/
     "9201",/* config mms port*/
     4,/* config mms account*/
     1/* config mms account type*/
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   },
   {
     0,/* config item  empty*/
     "",
     "",
     "",
     "",
     0,
     1
   }
  }
};
#if 0
const	cms_wap_bookmark_struct cms_wap_bookmark_default=
{
  CMS_CFG_N_NBR_BOOKMARKS,
  {/* bookmark content[N] */
   {
     1,/* bookmark item no empty*/
     {0xE7,0xA7,0xBB,0xE5,0x8A,0xA8,0xE5,0x9C,0xA8,0xE7,0xBA,0xBF},/* Bookmark name*/
     "http://wap.linktone.com/d?p=R679FM"/* Bookmarkurl*/
   },
   {
     1,/* bookmark item no empty*/
     {0xE7,0xA9,0xBA,0xE4,0xB8,0xAD,0xE6,0xBC,0xAB,0xE6,0xAD,0xA5},/* Bookmark name*/
     "http://cwcs.kcmn.cn"/* Bookmarkurl*/
   },
   {
     1,/* bookmark item no empty*/
     {0xE5,0x8D,0x8E,0xE5,0x8A,0xA8,0xE5,0xA4,0xA9,0xE5,0x9C,0xB0},/* Bookmark name*/
     "http://wap.any8.com/sa/p.do?t=CO&f=cw"/* Bookmarkurl*/
   },
   {
     1,/* bookmark item no empty*/
     {0xE7,0xA7,0xBB,0xE5,0x8A,0xA8,0xE6,0xA2,0xA6,0xE7,0xBD,0x91},/* Bookmark name*/
     "http://wap.monternet.com"/* Bookmarkurl*/
   },
   {
     1,/* bookmark item no empty*/
     {0xE6,0x96,0xB0,0xE6,0xB5,0xAA,0xE4,0xBA,0x92,0xE5,0x8A,0xA8},/* Bookmark name*/
     "http://wap.sina.com.cn/cw.wml"/* Bookmarkurl*/
   },
   {
     1,/* bookmark item no empty*/
     {0x54,0x4F,0x4D,0xE5,0x9B,0xBE,0xE9,0x93,0x83,0xE5,0xA4,0xA7,0xE4,0xB8,0x96,0xE7,0x95,0x8C},/* Bookmark name*/
     "http://wap.tom.com/nz.jsp?c=61&t=0"/* Bookmarkurl*/
   },
   {
     1,/* bookmark item no empty*/
     {0x57,0x41,0x50,0xE6,0x90,0x9C,0xE7,0xB4,0xA2},/* Bookmark name*/
     "http://wapall.cn/?sid=362"/* Bookmarkurl*/
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   },
   {
     0,/* bookmark item  empty*/
     "",
     ""
   }
  }
};
#else
const	cms_wap_bookmark_struct cms_wap_bookmark_default=
{
  CMS_CFG_N_NBR_BOOKMARKS,
  {/* bookmark content[N] */
   {
     1,/* bookmark item no empty*/
     {0xE5,0x88,0x9B,0xE7,0xBB,0xB4,0xE5,0xAE,0x9D,0xE5,0x85,0xB8},/* Bookmark name*/
     "http://wap.skyworthmobile.com"/* Bookmarkurl*/
   },
  }
};
#endif

#include "custom_data.h"

const	cms_wap_config_struct   cms_wap_config_default=
{
  WAP_USER_AGENT,
  WAP_USER_AGENT_PROFILE,
  0,/*Cache Size*/
  0,/*Browse Timeout*/
  20/*Max N Push Msg*/
};

const	cms_mms_config_struct   cms_mms_config_default=
{
  3,/*Expires*/
  0,/*Allow Anonymous*/
  0,/*Send Delivery Report*/
  0,/*Read Report*/
  1,/*prior*/
  5*1000,/*Frame Time*/
  0,/*Auto receive*/
  1,/*Max Mms Size*/
  142/*Mms Version*/
};

const	cms_mmswap_config_struct        cms_config_default=
{
	0,
	&cms_wap_profile_default,
	&cms_mms_profile_default,
	&cms_wap_bookmark_default,
	&cms_wap_config_default,
	&cms_mms_config_default
};

#endif /* CMS_NEW_APP*/

