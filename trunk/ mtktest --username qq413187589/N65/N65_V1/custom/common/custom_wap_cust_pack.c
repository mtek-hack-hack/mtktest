/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_wap_cust_pack.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains WAP/MMS configuration default value. 
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"        /* Basic data type */
#include "custom_wap_config.h"
#if (defined(__OP01_WAP_DATACFG__) || defined(__OP01_MMS_DATACFG__))
#include "custom_nvram_editor_data_item.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#endif /* (defined(__OP01_WAP_DATACFG__) || defined(__OP01_MMS_DATACFG__)) */

#include "custom_data_account.h"



#ifdef OBIGO_Q03C
#ifdef __OP01_WAP_DATACFG__

#error "=================================================== in file custom_wap_cust_pack.c"
#if 0 // del by hongzhe.liu : here doesn't complie

const custom_wap_profile_struct wap_profile_default = 
{
    WAP_CUSTOM_CFG_N_WAP_PROFILES,
    {
     {  /* wap profile 1 - Monwap(GPRS) */
      1,
      0,
      80,
      "\xe7\xa7\xbb\xe5\x8a\xa8\xe6\xa2\xa6\xe7\xbd\x91\xef\xbc\x88\x47\x50\x52\x53\xef\xbc\x89",
      "http://wap.monternet.com",
      CUSTOM_DEFAULT_WAP_PROFILE1,  
      1,
      10, 0, 0, 172,
      "",
      ""},
     {  /* wap profile 2 - Internet(GPRS) */
      1,
      0,
      80,
      "\x47\x50\x52\x53\xe8\xbf\x9e\xe6\x8e\xa5\xe4\xba\x92\xe8\x81\x94\xe7\xbd\x91",
      "http://wap.monternet.com",
      CUSTOM_DEFAULT_WAP_PROFILE2,
      1,
      10, 0, 0, 172,
      "",
      ""},
     {  /* wap profile 3 - Monwap(Modem) */
      1,
      0,
      80,
      "\xe7\xa7\xbb\xe5\x8a\xa8\xe6\xa2\xa6\xe7\xbd\x91\xef\xbc\x88\xe6\x8b\xa8\xe5\x8f\xb7\xef\xbc\x89",
      "http://wap.monternet.com",
      CUSTOM_DEFAULT_WAP_PROFILE3,
      1,
      10, 0, 0, 172,
      "",
      ""},
     {  /* wap profile 4 - Internet(Modem) */
      1,
      0,
      80,
      "\xe6\x8b\xa8\xe5\x8f\xb7\xe8\xbf\x9e\xe6\x8e\xa5\xe4\xba\x92\xe8\x81\x94\xe7\xbd\x91",
      "http://wap.monternet.com",
      CUSTOM_DEFAULT_WAP_PROFILE4,
      1,
      10, 0, 0, 172,
      "",
      ""},
     {  /* wap profile 5 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* wap profile 6 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* wap profile 7 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* wap profile 8 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* wap profile 9 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* wap profile 10 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""}
     }
};
#endif //hongzhe.liu

#else
/* __CUSTPACK_MULTIBIN     Johnnie   BEGIN */

#ifdef WAP2
//Huyanwei Touch Here
const custom_wap_profile_struct wap_profile_default = 
{
	WAP_CUSTOM_CFG_N_WAP_PROFILES,
	{
#if  defined(GPRS_TH_SUPPORT)
	#include "wap_gprs_config_th.h"
#elif defined(GPRS_SM_SUPPORT)
	#include "wap_gprs_config_sm.h"
#elif defined(GPRS_SM_TH_SUPPORT)
	#include "wap_gprs_config_sm_th.h"
#elif defined(GPRS_DEFAULT_SUPPORT)
   	#include "wap_gprs_config_defult.h"
#endif
	}
};


#if 0 /* wap config backup  hongzhe.liu */

{  /* wap profile 1 - FET */
      1,
      0,
      9201,
      "FET",
      "http://mobile.fetnet.net",
      CUSTOM_DEFAULT_WAP_PROFILE1,
      1,
      210, 241, 199, 199,
      "",
		""
	    },
     {  /* wap profile 2 - CHT */
      1,
      0,
      8080,
      "CHT",
      "http://wap.emome.net",
      CUSTOM_DEFAULT_WAP_PROFILE2,
      1,
      10, 1, 1, 1,
      "",
		""
	    },
     {  /* wap profile 3 - Taiwan mobile */
      1,
      0,
      80,
      "Taiwan mobile",
      "http://ewap",
      CUSTOM_DEFAULT_WAP_PROFILE3,
      1,
      10, 1, 1, 1,
      "",
		""
	    },
    	  {  /* wap profile 4 - CHINA MOBILE */
      1,
      0,
	      80,
	      "China Mobile",
	      "http://wap.monternet.com",
      CUSTOM_DEFAULT_WAP_PROFILE4,
      1,
	      10, 0, 0, 172,
      "",
	      ""
	   },	
	 {
		/* wap profile 5 - FET */
      1,
      0,
		8080,
		"AIS GPRS",
		"http://wap.mobilelife.co.th",
      CUSTOM_DEFAULT_WAP_PROFILE5,
      1,
		203,170,229,034,
      "",
		""
	 },
        {  /* wap profile 6 - CHT */
      1,
      0,
	      8080,
	      "DTAC GPRS",
	      "http://wap.djuice.co.th",
      CUSTOM_DEFAULT_WAP_PROFILE6,
      1,
	      203,155,200,133,
      "",
	      ""
	  },
	  {  /* wap profile 7 - True mobile */
      1,
      0,
      8080,
	      "TRUE MOVE GPRS",
	      "http://wap.trueworld.net",
      CUSTOM_DEFAULT_WAP_PROFILE7,
      1,
	      10,4,4,4,
	      "true",
	      "true"
	  },

#endif

#else

#error "=================================================== in file custom_wap_cust_pack.c"
#if 0 // del by hongzhe.liu : here doesn't complie

const custom_wap_profile_struct wap_profile_default = 
{
    WAP_CUSTOM_CFG_N_WAP_PROFILES,
    {
     {  /* wap profile 1 - FET */
      1,
      0,
      0,
      "FET",
      "http://mobile.fetnet.net",
      CUSTOM_DEFAULT_WAP_PROFILE1,
      3,
      210, 241, 199, 199,
      "",
      ""},
     {  /* wap profile 2 - CHT */
      1,
      0,
      0,
      "CHT",
      "http://wap.emome.net",
      CUSTOM_DEFAULT_WAP_PROFILE2,
      3,
      10, 1, 1, 1,
      "",
      ""},
     {  /* wap profile 3 - Taiwan mobile */
      1,
      0,
      0,
      "Taiwan mobile",
      "http://ewap",
      CUSTOM_DEFAULT_WAP_PROFILE3,
      3,
      10, 1, 1, 1,
      "",
      ""},
     {  /* wap profile 4 - TransAsia */
      1,
      0,
      0,
      "TransAsia",
      "http://www.hank.net.tw",
      CUSTOM_DEFAULT_WAP_PROFILE4,
      3,
      211, 78, 224, 100,
      "",
      ""},
     {  /* wap profile 5 - CHINA MOBILE */
      1,
      0,
      0,
      "China Mobile",
      "http://wap.monternet.com",
      CUSTOM_DEFAULT_WAP_PROFILE5,
      3,
      10, 0, 0, 172,
      "",
      ""},
     {  /* wap profile 6 - KGT */
      1,
      0,
      0,
      "KGT",
      "http://mobile1.fetnet.net",
      CUSTOM_DEFAULT_WAP_PROFILE6,
      3,
      210, 241, 199, 199,
      "",
      ""},
     {  /* wap profile 7 - Mobitai */
      1,
      0,
      0,
      "Mobitai",
      "http://www.mobeelife.net",
      CUSTOM_DEFAULT_WAP_PROFILE7,
      3,
      192, 168, 77, 5,
      "",
      ""},
     {  /* wap profile 8 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* wap profile 9 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* wap profile 10 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_WAP_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""}
     }
};

#endif //hongzhe.liu

#endif /* WAP2 */
#endif /* __OP01_WAP_DATACFG__ */
#ifdef __OP01_MMS_DATACFG__

#error "=================================================== in file custom_wap_cust_pack.c"
#if 0 // del by hongzhe.liu : here doesn't complie

const custom_mms_profile_struct mms_profile_default = 
{
    WAP_CUSTOM_CFG_N_MMS_PROFILES,
    {
     {  /* wap profile 1 - MMS(GPRS) */
      1,
      0,
      80,
      "\xe7\xa7\xbb\xe5\x8a\xa8\xe6\xa2\xa6\xe7\xbd\x91\xef\xbc\x88\x47\x50\x52\x53\xef\xbc\x89",
      "http://mmsc.monternet.com",
      CUSTOM_DEFAULT_MMS_PROFILE1,
      1,
      10, 0, 0, 172,
      "",
      ""},
     {  /* wap profile 2 - MMS(GPRS) */
      1,
      0,
      80,
      "\x47\x50\x52\x53\xe8\xbf\x9e\xe6\x8e\xa5\xe4\xba\x92\xe8\x81\x94\xe7\xbd\x91",
      "http://mmsc.monternet.com",
      CUSTOM_DEFAULT_MMS_PROFILE2,
      1,
      10, 0, 0, 172,
      "",
      ""},
     {  /* wap profile 3 - Monwap(Modem) */
      1,
      0,
      80,
      "\xe7\xa7\xbb\xe5\x8a\xa8\xe6\xa2\xa6\xe7\xbd\x91\xef\xbc\x88\xe6\x8b\xa8\xe5\x8f\xb7\xef\xbc\x89",
      "http://mmsc.monternet.com",
      CUSTOM_DEFAULT_MMS_PROFILE3,
      1,
      10, 0, 0, 172,
      "",
      ""},
     {  /* wap profile 4 - Monwap(Modem) */
      1,
      0,
      80,
      "\xe6\x8b\xa8\xe5\x8f\xb7\xe8\xbf\x9e\xe6\x8e\xa5\xe4\xba\x92\xe8\x81\x94\xe7\xbd\x91",
      "http://mmsc.monternet.com",
      CUSTOM_DEFAULT_MMS_PROFILE4,
      1,
      10, 0, 0, 172,
      "",
      ""},
     {  /* mms profile 5 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
        {  /* mms profile 6 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
        {  /* mms profile 7 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
      {  /* mms profile 8 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* mms profile 9 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* mms profile 10 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""}
     }
};

#endif //hongzhe.liu

#else

#ifdef WAP2
//Huyanwei Touch Here 
const custom_mms_profile_struct mms_profile_default = 
{
    WAP_CUSTOM_CFG_N_MMS_PROFILES,
    {
#if defined(GPRS_TH_SUPPORT)
	#include "mms_gprs_config_th.h"
#elif defined(GPRS_SM_SUPPORT)
	#include "mms_gprs_config_sm.h"
#elif defined(GPRS_SM_TH_SUPPORT)
	#include "mms_gprs_config_sm_th.h"
#elif defined(GPRS_DEFAULT_SUPPORT)
	#include "mms_gprs_config_default.h"
#endif
     }
};

#if 0 // mms profile config backup : hongzhe.liu
     {  /* mms profile 1 - FET */
      1,
      0,
      9201,
      "FET MMS",
      "http://mms",
      CUSTOM_DEFAULT_MMS_PROFILE1,
      1,
      210, 241, 199, 199,
      "",
      ""},
     {  /* mms profile 2 - CHT */
      1,
      0,
      8080,
      "CHT MMS",
      "http://mms.emome.net:8002",
      CUSTOM_DEFAULT_MMS_PROFILE2,
      1,
      10, 1, 1, 1,
      "",
      ""},
     {  /* mms profile 3 - TWN */
      1,
      0,
      80,
      "Taiwan mobile MMS",
      "http://mms",
      CUSTOM_DEFAULT_MMS_PROFILE3,
      1,
      10, 1, 1, 1,
      "",
      ""},
      {  /* mms profile 1 - CHINA MOBILE *///sc.wu mms setting default
      1,
      0,
      80,
      "China Mobile MMS",
      "http://mmsc.monternet.com",
      CUSTOM_DEFAULT_MMS_PROFILE4,
      1,
      10, 0, 0, 172,
      "",
      ""},
	{  /* mms profile 2 - AIS */
      1,
      0,
      8080,
      "AIS MMS",
      "http://mms.mobilelife.co.th",
      CUSTOM_DEFAULT_MMS_PROFILE5,
      1,
      203,170,229,034,
      "",
      ""},
      {  /* mms profile 3 - DTAC */
      1,
      0,
      8080,
      "DTAC MMS",
      "http://mms.dtac.co.th:8002",
      CUSTOM_DEFAULT_MMS_PROFILE6,
      1,
      203,155,200,133,
      "",
      ""},
     {  /* mms profile 4 - TRUE */
      1,
      0,
      8080,
      "TRUE MMS",
      "http://mms.trueworld.net:8002",
      CUSTOM_DEFAULT_MMS_PROFILE7,
      1,
      10,4,7,39,
      "true",
      "true"
      },      

#endif


#else

#error "=================================================== in file custom_wap_cust_pack.c"
#if 0 // del by hongzhe.liu : doesn't compile here
const custom_mms_profile_struct mms_profile_default = 
{
    WAP_CUSTOM_CFG_N_MMS_PROFILES,
    {
     {  /* mms profile 1 - FET */
      1,
      0,
      0,
      "FET MMS",
      "http://mms",
      CUSTOM_DEFAULT_MMS_PROFILE1,
      3,
      210, 241, 199, 199,
      "",
      ""},
     {  /* mms profile 2 - CHT */
      1,
      0,
      0,
      "CHT MMS",
      "http://mms.emome.net:8002",
      CUSTOM_DEFAULT_MMS_PROFILE2,
      3,
      10, 1, 1, 1,
      "",
      ""},
     {  /* mms profile 3 - TCC */
      1,
      0,
      0,
      "Taiwan mobile MMS",
      "http://mms",
      CUSTOM_DEFAULT_MMS_PROFILE3,
      3,
      10, 1, 1, 1,
      "",
      ""},
     {  /* mms profile 4 - TransAsia */
      1,
      0,
      0,
      "TransAsia MMS",
      "http://mms",
      CUSTOM_DEFAULT_MMS_PROFILE4,
      3,
      211, 78, 224, 100,
      "",
      ""},
     {  /* mms profile 5 - CHINA MOBILE */
      1,
      0,
      0,
      "China Mobile MMS",
      "http://mmsc.monternet.com",
      CUSTOM_DEFAULT_MMS_PROFILE5,
      3,
      10, 0, 0, 172,
      "",
      ""},
     {  /* mms profile 6 - KGT */
      1,
      0,
      0,
      "KGT MMS",
      "http://mms.kgtmms.net.tw/mms/wapenc",
      CUSTOM_DEFAULT_MMS_PROFILE6,
      1,
      172, 28, 33, 5,
      "",
      ""},
     {  /* mms profile 7 - Mobitai */
      1,
      0,
      0,
      "Mobitai MMS",
      "http://mms.mobeelife.net/mms/wapenc",
      CUSTOM_DEFAULT_MMS_PROFILE7,
      3,
      192, 168, 77, 5,
      "",
      ""},
      {  /* mms profile 8 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* mms profile 9 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""},
     {  /* mms profile 10 - Empty */
      1,
      1,
      0,
      "",
      "",
      CUSTOM_DEFAULT_MMS_PROFILE_EMPTY,
      3,
      0, 0, 0, 0,
      "",
      ""}
     }
};
#endif //hongzhe.liu

#endif /* WAP2 */
#endif /* __OP01_MMS_DATACFG__ */

#ifdef __OP01_DEFAULT_BOOKMARK__
const custom_wap_bkm_struct wap_bkm_default = 
{
    WAP_CUSTOM_CFG_N_NBR_BOOKMARKS,
    {
     { /* bookmark 1 - op01 homepage */
      0,
      0,
      "\xE7\xA7\xBB\xE5\x8A\xA8\xE6\xA2\xA6\xE7\xBD\x91",
      "http://wap.monternet.com"},
     { /* bookmark 2 - customer webpage */  
      0,
      0,
      "\xE6\x88\x91\xE7\x9A\x84\xE6\xA2\xA6\xE7\xBD\x91", 
      "http://wap.monternet.com/portal/wap/menu.do?menuid=200003"},
     { /* bookmark 3 - customer webpage */ 
      0,
      0,
      "\xE7\x99\xBE\xE5\xAE\x9D\xE7\xAE\xB1", 
      "http://wap.monternet.com/?cp22=v22bbx"},
	  { /* bookmark 4 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 5 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 6 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 7 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 8 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 9 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 10 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 11 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 12 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 13 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 14 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 15 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 16 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 17 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 18 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 19 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 20 - empty */
      1,
      1,
      "",
      ""}
     }
};
#else /* __OP01_DEFAULT_BOOKMARK__ */
const custom_wap_bkm_struct wap_bkm_default = 
{
    WAP_CUSTOM_CFG_N_NBR_BOOKMARKS,
    {
     {  /* bookmark 1 - yahoo */
      1,
      0,
      "yahoo",
      "http://wap.yahoo.com"},
     {  /* bookmark 2 - sina */
      1,
      0,
      "sina",
      "http://wap.sina.com"},
     {  /* bookmark 3 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 4 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 5 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 6 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 7 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 8 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 9 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 10 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 11 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 12 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 13 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 14 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 15 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 16 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 17 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 18 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 19 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 20 - empty */
      1,
      1,
      "",
      ""}
     }
};
#endif /* end of  __OP01_DEFAULT_BOOKMARK__ */

const custom_wap_trustList_struct wap_trustList_default = 
{
    WAP_CUSTOM_CFG_N_NBR_TRUSTLISTS,
    {
        {  /* trust list 1 - empty*/
         1,
         0,
         ""},
        {  /* trust list 2 - empty*/
         1,
         0,
        ""},
        {  /* trust list 3 - empty */
         1,
         0,
         ""},
        {  /* trust list 4 - empty */
         1,
         0,
         ""},
        {  /* trust list 5 - empty */
         1,
         0,
         ""},
        {  /* trust list 6 - empty */
         1,
         0,
         ""},
        {  /* trust list 7 - empty */
         1,
         0,
         ""},
        {  /* trust list 8 - empty */
         1,
         0,
         ""},
        {  /* trust list 9 - empty */
         1,
         0,
         ""},
        {  /* trust list 10 - empty */
         1,
         0,
         ""},
    }
};

const custom_wap_root_ca_struct wap_root_ca_default = 
{
    WAP_CUSTOM_CFG_N_ROOT_CA,
    {
     {  /* root ca 1 - Entrust WTLS */
      1,
      0,
      1,
      {
       0x01, 0x02, 0x01, 0x00, 0x04, 0x4c, 0x45, 0x6e, 0x74, 0x72, 0x75, 0x73, 0x74, 0x2e,
       0x6e, 0x65, 0x74, 0x20, 0x57, 0x41, 0x50, 0x20, 0x43, 0x41, 0x20, 0x28, 0x63, 0x29, 0x20, 0x31,
       0x39, 0x39, 0x39, 0x3b, 0x20, 0x4c, 0x69, 0x6d, 0x69, 0x74, 0x65, 0x64, 0x20, 0x6c, 0x69, 0x61,
       0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x2e, 0x20, 0x53, 0x65, 0x65, 0x20, 0x77, 0x77, 0x77, 0x2e,
       0x65, 0x6e, 0x74, 0x72, 0x75, 0x73, 0x74, 0x2e, 0x6e, 0x65, 0x74, 0x2f, 0x57, 0x41, 0x50, 0x43,
       0x50, 0x53, 0x3b, 0x20, 0x38, 0xa0, 0x42, 0xd1, 0x5e, 0x3e, 0xe7, 0x59, 0x01, 0x00, 0x04, 0x4c,
       0x45, 0x6e, 0x74, 0x72, 0x75, 0x73, 0x74, 0x2e, 0x6e, 0x65, 0x74, 0x20, 0x57, 0x41, 0x50, 0x20,
       0x43, 0x41, 0x20, 0x28, 0x63, 0x29, 0x20, 0x31, 0x39, 0x39, 0x39, 0x3b, 0x20, 0x4c, 0x69, 0x6d,
       0x69, 0x74, 0x65, 0x64, 0x20, 0x6c, 0x69, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x2e, 0x20,
       0x53, 0x65, 0x65, 0x20, 0x77, 0x77, 0x77, 0x2e, 0x65, 0x6e, 0x74, 0x72, 0x75, 0x73, 0x74, 0x2e,
       0x6e, 0x65, 0x74, 0x2f, 0x57, 0x41, 0x50, 0x43, 0x50, 0x53, 0x3b, 0x20, 0x02, 0x00, 0x00, 0x03,
       0x01, 0x00, 0x01, 0x00, 0x80, 0x95, 0x3d, 0x7e, 0x62, 0x32, 0x16, 0x64, 0xc2, 0x08, 0x21, 0x0a,
       0xda, 0x99, 0x29, 0x9a, 0x21, 0x82, 0x5f, 0xf3, 0x94, 0x8b, 0xc1, 0x14, 0x79, 0x1c, 0xa2, 0xba,
       0x7f, 0x59, 0x0a, 0x26, 0x23, 0x01, 0x47, 0xd4, 0x09, 0xe2, 0x36, 0x19, 0xac, 0xe6, 0xce, 0xb5,
       0x78, 0xb9, 0xe0, 0x4f, 0x1f, 0xe0, 0x0f, 0x3e, 0xa0, 0x5d, 0xe9, 0xd6, 0xb7, 0x57, 0xb0, 0xb8,
       0xc9, 0x98, 0x3a, 0xd3, 0xfd, 0x3e, 0x19, 0x4b, 0x1e, 0x16, 0xe3, 0x77, 0x9b, 0x55, 0xf0, 0x65,
       0x53, 0x5a, 0x7b, 0x42, 0x66, 0xa7, 0xbe, 0x6b, 0x3a, 0x95, 0x50, 0x75, 0x1e, 0xee, 0xed, 0x97,
       0xfb, 0xaf, 0x8f, 0x4c, 0xc6, 0x82, 0xcf, 0xf7, 0x12, 0x84, 0x3b, 0xee, 0x14, 0x52, 0x31, 0x8e,
       0xca, 0xa5, 0x10, 0x8f, 0x75, 0xcb, 0x88, 0x6d, 0x01, 0x88, 0xc7, 0x6f, 0x57, 0xa5, 0xac, 0xfc,
       0x41, 0xb7, 0xc6, 0x62, 0xc9, 0x00, 0x80, 0x00, 0xff, 0xbc, 0x32, 0x9a, 0x40, 0x39, 0xab, 0xe8,
       0x26, 0x01, 0x12, 0x82, 0xe7, 0x46, 0x80, 0x30, 0xae, 0x8d, 0x5b, 0x3d, 0x8a, 0x06, 0xe6, 0x2e,
       0xf2, 0x88, 0x79, 0xf5, 0x7e, 0x1a, 0x0f, 0xc0, 0x11, 0xbd, 0xb6, 0xca, 0xc4, 0x8c, 0x49, 0xff,
       0x7b, 0x1f, 0x82, 0x85, 0x94, 0x70, 0xd5, 0xbd, 0xc0, 0xd0, 0x30, 0x68, 0xf7, 0x8c, 0x70, 0x1e,
       0x7d, 0x24, 0xea, 0xa0, 0xd6, 0x53, 0x95, 0xf2, 0x09, 0x78, 0x0c, 0x83, 0x93, 0x27, 0x71, 0x53,
       0x64, 0x02, 0xd9, 0x7f, 0xe2, 0x10, 0x64, 0xe2, 0x97, 0x22, 0x5d, 0x8e, 0x62, 0x29, 0x25, 0x14,
       0xa0, 0x6e, 0x0c, 0x03, 0xc6, 0x2c, 0x40, 0x4c, 0xc1, 0xfa, 0xf7, 0x68, 0x35, 0x5a, 0xcc, 0x2c,
       0x37, 0xe8, 0x1c, 0x0c, 0x59, 0x2f, 0xf9, 0x9e, 0xc5, 0x7b, 0xc8, 0x48, 0x0f, 0x1b, 0x0b, 0x9d,
       0x66, 0xbf, 0x6a, 0xba, 0xb8, 0xc2, 0x7d},
      437},
     {  /* root ca 2 - Verisign Class 3 */
      1,
      0,
      2,
      { 0x30, 0x82, 0x02,
        0x3c, 0x30, 0x82, 0x01, 0xa5, 0x02, 0x10, 0x70, 0xba, 0xe4, 0x1d, 0x10, 0xd9, 0x29, 0x34, 0xb6,
        0x38, 0xca, 0x7b, 0x03, 0xcc, 0xba, 0xbf, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
        0x0d, 0x01, 0x01, 0x02, 0x05, 0x00, 0x30, 0x5f, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
        0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x0e,
        0x56, 0x65, 0x72, 0x69, 0x53, 0x69, 0x67, 0x6e, 0x2c, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31, 0x37,
        0x30, 0x35, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x2e, 0x43, 0x6c, 0x61, 0x73, 0x73, 0x20, 0x33,
        0x20, 0x50, 0x75, 0x62, 0x6c, 0x69, 0x63, 0x20, 0x50, 0x72, 0x69, 0x6d, 0x61, 0x72, 0x79, 0x20,
        0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x41, 0x75,
        0x74, 0x68, 0x6f, 0x72, 0x69, 0x74, 0x79, 0x30, 0x1e, 0x17, 0x0d, 0x39, 0x36, 0x30, 0x31, 0x32,
        0x39, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x5a, 0x17, 0x0d, 0x32, 0x38, 0x30, 0x38, 0x30, 0x31,
        0x32, 0x33, 0x35, 0x39, 0x35, 0x39, 0x5a, 0x30, 0x5f, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55,
        0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13,
        0x0e, 0x56, 0x65, 0x72, 0x69, 0x53, 0x69, 0x67, 0x6e, 0x2c, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31,
        0x37, 0x30, 0x35, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x2e, 0x43, 0x6c, 0x61, 0x73, 0x73, 0x20,
        0x33, 0x20, 0x50, 0x75, 0x62, 0x6c, 0x69, 0x63, 0x20, 0x50, 0x72, 0x69, 0x6d, 0x61, 0x72, 0x79,
        0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x41,
        0x75, 0x74, 0x68, 0x6f, 0x72, 0x69, 0x74, 0x79, 0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a,
        0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d, 0x00, 0x30, 0x81,
        0x89, 0x02, 0x81, 0x81, 0x00, 0xc9, 0x5c, 0x59, 0x9e, 0xf2, 0x1b, 0x8a, 0x01, 0x14, 0xb4, 0x10,
        0xdf, 0x04, 0x40, 0xdb, 0xe3, 0x57, 0xaf, 0x6a, 0x45, 0x40, 0x8f, 0x84, 0x0c, 0x0b, 0xd1, 0x33,
        0xd9, 0xd9, 0x11, 0xcf, 0xee, 0x02, 0x58, 0x1f, 0x25, 0xf7, 0x2a, 0xa8, 0x44, 0x05, 0xaa, 0xec,
        0x03, 0x1f, 0x78, 0x7f, 0x9e, 0x93, 0xb9, 0x9a, 0x00, 0xaa, 0x23, 0x7d, 0xd6, 0xac, 0x85, 0xa2,
        0x63, 0x45, 0xc7, 0x72, 0x27, 0xcc, 0xf4, 0x4c, 0xc6, 0x75, 0x71, 0xd2, 0x39, 0xef, 0x4f, 0x42,
        0xf0, 0x75, 0xdf, 0x0a, 0x90, 0xc6, 0x8e, 0x20, 0x6f, 0x98, 0x0f, 0xf8, 0xac, 0x23, 0x5f, 0x70,
        0x29, 0x36, 0xa4, 0xc9, 0x86, 0xe7, 0xb1, 0x9a, 0x20, 0xcb, 0x53, 0xa5, 0x85, 0xe7, 0x3d, 0xbe,
        0x7d, 0x9a, 0xfe, 0x24, 0x45, 0x33, 0xdc, 0x76, 0x15, 0xed, 0x0f, 0xa2, 0x71, 0x64, 0x4c, 0x65,
        0x2e, 0x81, 0x68, 0x45, 0xa7, 0x02, 0x03, 0x01, 0x00, 0x01, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
        0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x02, 0x05, 0x00, 0x03, 0x81, 0x81, 0x00, 0xbb, 0x4c, 0x12,
        0x2b, 0xcf, 0x2c, 0x26, 0x00, 0x4f, 0x14, 0x13, 0xdd, 0xa6, 0xfb, 0xfc, 0x0a, 0x11, 0x84, 0x8c,
        0xf3, 0x28, 0x1c, 0x67, 0x92, 0x2f, 0x7c, 0xb6, 0xc5, 0xfa, 0xdf, 0xf0, 0xe8, 0x95, 0xbc, 0x1d,
        0x8f, 0x6c, 0x2c, 0xa8, 0x51, 0xcc, 0x73, 0xd8, 0xa4, 0xc0, 0x53, 0xf0, 0x4e, 0xd6, 0x26, 0xc0,
        0x76, 0x01, 0x57, 0x81, 0x92, 0x5e, 0x21, 0xf1, 0xd1, 0xb1, 0xff, 0xe7, 0xd0, 0x21, 0x58, 0xcd,
        0x69, 0x17, 0xe3, 0x44, 0x1c, 0x9c, 0x19, 0x44, 0x39, 0x89, 0x5c, 0xdc, 0x9c, 0x00, 0x0f, 0x56,
        0x8d, 0x02, 0x99, 0xed, 0xa2, 0x90, 0x45, 0x4c, 0xe4, 0xbb, 0x10, 0xa4, 0x3d, 0xf0, 0x32, 0x03,
        0x0e, 0xf1, 0xce, 0xf8, 0xe8, 0xc9, 0x51, 0x8c, 0xe6, 0x62, 0x9f, 0xe6, 0x9f, 0xc0, 0x7d, 0xb7,
        0x72, 0x9c, 0xc9, 0x36, 0x3a, 0x6b, 0x9f, 0x4e, 0xa8, 0xff, 0x64, 0x0d, 0x64 },
      576},
     {  /* root ca 3 - empty */
      1,
      1,
      0,
      "",
      0}
     }
};

const custom_wap_config_struct wap_config_default = 
{
    WAP_CUSTOM_CFG_MAX_CACHE_SIZE,
    WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT,
    WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG,
    WAP_CUSTOM_CFG_PUSH_SET_ENABLE_PUSH,
    WAP_CUSTOM_CFG_PUSH_SET_TRUST_SETTING,
    WAP_CUSTOM_CFG_PUSH_SET_SL_SETTING,
    WAP_CUSTOM_CFG_DEFAULT_UA_HEADER,
    WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL,
    &wap_trustList_default
};

const custom_mms_config_struct mms_config_default = 
{
    WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE,
    WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG,
    WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG,
    WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER,
    WAP_CUSTOM_CFG_MAX_MMS_GET_RETRY,
    WAP_CUSTOM_CFG_MAX_MMS_POST_MSG_RETRY,
    WAP_CUSTOM_CFG_MAX_MMS_POST_PDU_RETRY,
    WAP_CUSTOM_CFG_MMS_GET_TIMEOUT,
    WAP_CUSTOM_CFG_MMS_POST_TIMEOUT,
    WAP_CUSTOM_CFG_MMS_SLIDE_DURATION,
    WAP_CUSTOM_CFG_MMS_IMMED_RETRIEVAL_MODE,
    WAP_CUSTOM_CFG_MMS_ROAM_RETRIEVAL_MODE,
    WAP_CUSTOM_CFG_MMS_ALLOW_ADVERTIMSEMENT,
    WAP_CUSTOM_CFG_MMS_ALLOW_ANONYMOUS,
    WAP_CUSTOM_CFG_MMS_REQ_DELIVERY_REPORT,
    WAP_CUSTOM_CFG_MMS_REQ_READ_REPORT,
    WAP_CUSTOM_CFG_MMS_SEND_DELIVERY_REPORT,
    WAP_CUSTOM_CFG_MMS_SEND_READ_REPORT,
    WAP_CUSTOM_CFG_MMS_VERSION,
    WAP_CUSTOM_CFG_MAX_MMS_SLIDES,
    WAP_CUSTOM_CFG_MAX_MMS_ADDRESS,
    WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT
};

const wap_custpack_header custpack_wap_ptr = 
{
    0,
    &wap_profile_default,
    &mms_profile_default,
    &wap_bkm_default,
    &wap_root_ca_default,
    &wap_config_default,
    &mms_config_default
};

/* __CUSTPACK_MULTIBIN     Johnnie   END */
#endif /* OBIGO_Q03C */ 

#ifdef OBIGO_Q05A
const custom_wap_bkm_struct wap_bkm_default = 
{
    WAP_CUSTOM_CFG_N_NBR_BOOKMARKS,
    {
     {  /* bookmark 1 - yahoo */
      1,
      0,
      "Yahoo",
      "http://wap.yahoo.com"},
     {  /* bookmark 2 - sina */
      1,
      0,
      "Sina",
      "http://wap.sina.com"},
     {  /* bookmark 3 - google */
      1,
      0,
      "Google",
      "http://wap.google.com"},
     {  /* bookmark 4 - rediff */
      1,
      0,
      "Rediff",
      "http://mobile.rediff.com"},
     {  /* bookmark 5 - obigo */
      1,
      0,
      "Obigo",
      "http://wap.obigo.com"},
     {  /* bookmark 6 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 7 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 8 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 9 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 10 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 11 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 12 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 13 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 14 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 15 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 16 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 17 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 18 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 19 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 20 - empty */
      1,
      1,
      "",
      ""}
     }
};
#endif /* OBIGO_Q05A */ 

