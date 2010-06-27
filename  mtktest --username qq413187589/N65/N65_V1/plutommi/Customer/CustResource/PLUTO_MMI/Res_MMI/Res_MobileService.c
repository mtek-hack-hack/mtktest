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
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : Res_MobileService.c

   PURPOSE     : Populate Resource for 

   REMARKS     : 

   AUTHOR      : Lili Fan

   DATE     : May-08-2007

**************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_MOBILE_SERVICE__)

#include "PopulateRes.h"
#include "CustResDef.h"
#include "MobileServiceResDef.h"


/*****************************************************************************
 * FUNCTION
 *  PopulateMobileServiceRes
 * DESCRIPTION
 *  Populate all mobile service resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateMobileServiceRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef WAP_SUPPORT
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_MUSIC,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_MusicChannel.pbm",
        "Icon for music item of mobile service.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_GAME,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_Games.pbm",
        "Icon for game item of mobile service.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_WEATHER,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_NewsWeather.pbm",
        "Icon for weather item of mobile service.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_FETION,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_Fetion.pbm",
        "Icon for fetion item of mobile service.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_VIDEO,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_MobileVideo.pbm",
        "Icon for video item of mobile service.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_NEW,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_WhatNews.pbm",
        "Icon for new service item of mobile service.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_MYMONWAP,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_MO.pbm",
        "Icon for mymonwap of mobile service.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_MONWAP,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_Monternet.pbm",
        "Icon for monwap of mobile service.");
#endif
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_STK,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_STK.pbm",
        "Icon for stk of mobile service.");

#ifdef __SYNCML_SUPPORT__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_PIM,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_PhonebookManager.pbm",
        "Icon for submenu of mypim.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_PIM_SYNC,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\PBM_PhonebookUpdate.pbm",
        "Icon for submenu of pim sync.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_PIM_PB,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\PBM_Phonebook.pbm",
        "Icon for submenu of pim sync.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_PIM_SETTING,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\PBM_Setting.pbm",
        "Icon for submenu of pim setting.");
#ifdef WAP_SUPPORT
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_PIM_CHECK,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\PBM_OnlineInquiry.pbm",
        "Icon for submenu of pim check.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_OPTRSER_PIM_ORDER,
        CUST_IMG_PATH "\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\PBM_SubscribeSservices.pbm",
        "Icon for submenu of pim order.");
#endif
#endif
  

    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_TITLE, "Mobile Service", "Title of Mobile Service.");
#ifdef WAP_SUPPORT
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_MUSIC, "wireless music", "menu text for Mobile Service.");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_GAME, "game", "menu text for Mobile Service.");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_WEATHER, "news&weather", "menu text for Mobile Service.");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_FETION, "fetion", "menu text for Mobile Service.");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_VIDEO, "video", "menu text for Mobile Service.");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_NEW, "new service", "menu text for Mobile Service.");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_MYMONWAP, "my monwap", "menu text for Mobile Service.");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_MONWAP, "monwap", "menu text for Mobile Service.");
#endif
#ifdef __SYNCML_SUPPORT__
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM, "MY PIM", "menu text for my pim");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM_INTRO, "PIM intro", "mypim introduction text");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM_ENTER, "PIM enter", "mypim highlighted string");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM_SETTING, "PIM setting", "menu text for pim settting");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM_SYNC, "PIM sync", "menu text for pim sync");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM_PB, "PIM phonebook", "menu text for pim phonebook");
#ifdef WAP_SUPPORT
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM_CHECK, "PIM network check", "menu text for pim newwork check");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM_FEE, "PIM fee", "mypim highlighted string");
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_PIM_ORDER, "PIM order", "menu text for pim order");
#endif
#endif
    ADD_APPLICATION_STRING2(STR_ID_OPTRSER_STK, "STK", "menu text for STK");


#ifdef WAP_SUPPORT
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_MUSIC, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_MUSIC, IMG_ID_OPTRSER_MUSIC));  
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_GAME, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_GAME, IMG_ID_OPTRSER_GAME));  
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_WEATHER, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_WEATHER, IMG_ID_OPTRSER_WEATHER));  
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_FETION, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_FETION, IMG_ID_OPTRSER_FETION));  
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_VIDEO, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_VIDEO, IMG_ID_OPTRSER_VIDEO));  
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_NEW, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_NEW, IMG_ID_OPTRSER_NEW));  
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_MYMONWAP, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_MYMONWAP, IMG_ID_OPTRSER_MYMONWAP));  
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_MONWAP, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_MONWAP, IMG_ID_OPTRSER_MONWAP));  
#endif
#ifdef __SYNCML_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_PIM, MAIN_MENU_OP_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_OPTRSER_PIM, IMG_ID_OPTRSER_PIM));    
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_PIM_ENTER, 0, 
        3
#ifdef WAP_SUPPORT
        +2
#endif
        ,
#ifdef WAP_SUPPORT
       MENU_ID_OPTRSER_PIM_ORDER, 
#endif
       MENU_ID_OPTRSER_PIM_SYNC,
       MENU_ID_OPTRSER_PIM_PB, 
#ifdef WAP_SUPPORT
       MENU_ID_OPTRSER_PIM_CHECK,
#endif
       MENU_ID_OPTRSER_PIM_SETTING, 
                              SHOW,NONMOVEABLE, DISP_LIST, STR_ID_OPTRSER_PIM, IMG_ID_OPTRSER_PIM));    
#ifdef WAP_SUPPORT
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_PIM_ORDER, MENU_ID_OPTRSER_PIM_ENTER, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STR_ID_OPTRSER_PIM_ORDER, IMG_ID_OPTRSER_PIM_ORDER));    
#endif
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_PIM_PB, MENU_ID_OPTRSER_PIM_ENTER, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STR_ID_OPTRSER_PIM_PB, IMG_ID_OPTRSER_PIM_PB));
#ifdef WAP_SUPPORT
    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_PIM_CHECK, MENU_ID_OPTRSER_PIM_ENTER, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STR_ID_OPTRSER_PIM_CHECK, IMG_ID_OPTRSER_PIM_CHECK));
#endif
 ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_PIM_SETTING, MENU_ID_OPTRSER_PIM_ENTER, 
							  2, 
							  MENU_ID_SYNCML_PROFILE,
							  MENU_ID_SYNCML_APPLICATIONS,
							  SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STR_ID_OPTRSER_PIM_SETTING, IMG_ID_OPTRSER_PIM_SETTING));

    ADD_APPLICATION_MENUITEM((MENU_ID_OPTRSER_PIM_SYNC, MENU_ID_OPTRSER_PIM_ENTER, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STR_ID_OPTRSER_PIM_SYNC, IMG_ID_OPTRSER_PIM_SYNC));
#endif
}

#endif /* defined(__MMI_MOBILE_SERVICE__) */ 

