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


//micha0406
#ifndef _CUST_RES_DEF_H
#define _CUST_RES_DEF_H

#include "MMI_features.h"
#include "PlmnEnum.h"


#if 0
//huyanwei Modify It 

#ifdef __MMI_AUTO_LANG_EN__
#define MMI_DEFLANGSSC_FOR_AUTO "*#0044#"
#endif

#define SSC_SW_VERSION							"*#8375#"
#define SSC_HW_VERSION							"*#357#"			//Not used if __MMI_HW_VERSION__ is not turned on
#define SSC_ENGINEERING_MODE				"*#3646633#"
#define SSC_FACTORY_MODE						"*#66*#"
#define SSC_FACTORY_MODE_AUTOTEST		"*#87#"
#define SSC_SERIAL_NUMBER						"*#33778#"
#define SSC_SET_LCD_CONTRAST						"*#523#"
#define SSC_IR_OPEN                    "*#678#"
#define SSC_IR_CLOSE                    "*#876#"
#define SSC_VENDORAPP						"*#3366*#"

// diamond, 2005/05/13 for SSC disable
#define SSC_DISABLE_FOR_SHIPMENT	"*#6810#"

/* SML menu implementation */
#ifdef __MMI_SML_MENU__
#define SSC_SML_ADD_CODE	"###765*02#"
#define SSC_SML_REMOVE_CODE	"###765*07#"
#define SSC_SML_LOCK_CODE	"###765*05#"
#define SSC_SML_UNLOCK_CODE	"###765*08#"
#define SSC_SML_DEACTIVATE_CODE	"###765*78#" /* permanent unlock */
#define SSC_SML_LOCK_CMD	"*7525#"
#define SSC_SML_UNLOCK_CMD	"#7525#"
#define SSC_SML_QUERY_CMD	"*#7525#"
#ifdef __MMI_SML_NP_ONLY__
#define SSC_SML_UNLOCK_NP_CMD "*#7525*00#"
#endif
#endif /* __MMI_SML_MENU__ */

#else

#ifdef __MMI_AUTO_LANG_EN__
#define MMI_DEFLANGSSC_FOR_AUTO                "*#1581#" /* "*#0044#" */
#endif
//UNI@bw0719 增加单独的TV测试工程命令
#define SSC_TV_TEST			                           "*#1500#"

#define SSC_SW_VERSION						"*#1501#" /*UNISWVersion*/  /* "*#8375#" */
#define SSC_HW_VERSION						"*#1502#" /*UNIHWVersion*/ /*"*#357#"	 */		//Not used if __MMI_HW_VERSION__ is not turned on
#define SSC_ENGINEERING_MODE				"*#1511#" /*UNIENG*/ /* "*#3646633#" */
#define SSC_FACTORY_MODE					"*#1521#" /*UNIFAC*/ /* "*#66*#" */
#define SSC_FACTORY_MODE_AUTOTEST		"*#1522#"  /*UNIAutoTest*/ /*"*#87#" */
#define SSC_SERIAL_NUMBER					"*#1531#"  /*UNISN*/ /* "*#33778#" */
#define SSC_SET_LCD_CONTRAST				"*#1541#" /*UNILCD*/ /*"*#523#" */
#define SSC_IR_OPEN                                           "*#1551#" /*UNIIROpen*/ /* "*#678#" */
#define SSC_IR_CLOSE                                         "*#1552#" /*UNIIRClose*/ /* "*#876#" */
#define SSC_VENDORAPP						"*#1561#" /*UNI*/ /* "*#3366*#" */

// diamond, 2005/05/13 for SSC disable
#define SSC_DISABLE_FOR_SHIPMENT	              "*#1571#" /*UNIDisableSHIP*/ /* "*#6810#" */

/* SML menu implementation */
#ifdef __MMI_SML_MENU__
#define SSC_SML_ADD_CODE	                            "*#15*01#"
#define SSC_SML_REMOVE_CODE	                     "*#15*02#"
#define SSC_SML_LOCK_CODE	                            "*#15*03#"
#define SSC_SML_UNLOCK_CODE	                     "*#15*04#"
#define SSC_SML_DEACTIVATE_CODE	              "*#15*05#" /* permanent unlock */
#define SSC_SML_LOCK_CMD	                            "*#15*06#"
#define SSC_SML_UNLOCK_CMD	                     "*#15*07#"
#define SSC_SML_QUERY_CMD	                            "*#15*08#"
#ifdef __MMI_SML_NP_ONLY__
#define SSC_SML_UNLOCK_NP_CMD                     "*#15*09#"
#endif
#endif /* __MMI_SML_MENU__ */

#endif 





#define CUST_IMG_BASE_PATH			"..\\\\..\\\\Customer\\\\Images"

//MTK Leo added, to customize mmi
	#define CUS_STR_DATA_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustStrRes.c" //Filename containg the array of CUSTOM_STRING.
	#define CUS_STR_MAP_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustStrMap.c" //Filename containg the array of CUSTOM_STRING_MAP.
	#define CUS_IMG_DATA_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustImgRes.c" //Filename containg the array of CUSTOM_IMAGE.
	#define CUS_IMG_MAP_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustImgMap.c" //Filename containg the array of CUSTOM_IMAGE_MAP.
	#define CUS_MENU_DATA_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustMenuRes.c" //Filename containg the array of CUSTOM_MENU.
	#define CUS_IMG_HW_FILENAME			"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustImgDataHW.h"
#if defined(__MMI_MAINLCD_128X160__)	
	#define CUST_IMG_PATH				"..\\\\..\\\\Customer\\\\Images\\\\PLUTO128X160"
#elif defined(__MMI_MAINLCD_176X220__)
	#define CUST_IMG_PATH				"..\\\\..\\\\Customer\\\\Images\\\\PLUTO176X220"
#elif defined(__MMI_MAINLCD_240X320__)
	#define CUST_IMG_PATH				"..\\\\..\\\\Customer\\\\Images\\\\PLUTO240X320"
#elif defined(__MMI_MAINLCD_320X240__)
	#define CUST_IMG_PATH				"..\\\\..\\\\Customer\\\\Images\\\\PLUTO320X240"
#else
	#define CUST_IMG_PATH				"..\\\\..\\\\Customer\\\\Images\\\\PLUTO"
#endif
/* 20061103 SubLCD start */
#if defined(CUST_SUBLCD_PATH)
    #undef CUST_SUBLCD_PATH
#endif
#if defined(__MMI_SUBLCD_48X64BW__)
    #define CUST_SUBLCD_PATH				"..\\\\..\\\\Customer\\\\Images\\\\SubLCDBW48X64"
#elif defined(__MMI_SUBLCD_64X96__)
    #define CUST_SUBLCD_PATH				"..\\\\..\\\\Customer\\\\Images\\\\SubLCD64X96"
#elif defined(__MMI_SUBLCD_96X64BW__)
    #define CUST_SUBLCD_PATH				"..\\\\..\\\\Customer\\\\Images\\\\SubLCDBW96X64"
#elif defined(__MMI_SUBLCD_96X64__)
    #define CUST_SUBLCD_PATH				"..\\\\..\\\\Customer\\\\Images\\\\SubLCD96X64"
#elif defined(__MMI_SUBLCD_128X128__)
    #define CUST_SUBLCD_PATH				"..\\\\..\\\\Customer\\\\Images\\\\SubLCD128X128"
#endif
/* 20061103 SubLCD end */
/*101205 audio resource Calvin Satrt */
	#define CUST_ADO_PATH				"..\\\\..\\\\Customer\\\\AUDIO\\\\PLUTO"
/*101205 audio resource Calvin End */

#ifndef __OPTR_NONE__
#include "Operator_CustResDef.h"
#endif

#endif


