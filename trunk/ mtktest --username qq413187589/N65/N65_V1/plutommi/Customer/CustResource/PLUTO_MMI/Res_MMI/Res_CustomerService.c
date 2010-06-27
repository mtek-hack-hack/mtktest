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

   FILENAME : Res_CustomerService.c

   PURPOSE     : Populate Resource for 

   REMARKS     : 

   AUTHOR      : Lili Fan

   DATE     : May-08-2007

**************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_CUSTOMER_SERVICE__)

#include "PopulateRes.h"
#include "CustResDef.h"
#include "CustSerResDef.h"


/*****************************************************************************
 * FUNCTION
 *  PopulateCustomerServiceRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateCustomerServiceRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_CUSTSER_GUIDELINE,
        CUST_IMG_PATH "\\\\MainLCD\\\\CustomerServices\\\\CS_ServiceGuide.pbm",
        "Icon for submenu of guideline.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_CUSTSER_SALE,
        CUST_IMG_PATH "\\\\MainLCD\\\\CustomerServices\\\\CS_HandService.pbm",
        "Icon for submenu of sale.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_CUSTSER_HOTLINE,
        CUST_IMG_PATH "\\\\MainLCD\\\\CustomerServices\\\\CS_ServiceHotline.pbm",
        "Icon for submenu of hotline.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_CUSTSER_MANAGER,
        CUST_IMG_PATH "\\\\MainLCD\\\\CustomerServices\\\\CS_CustomerManager.pbm",
        "Icon for submenu of manager.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_CUSTSER_MYMONWAP,
        CUST_IMG_PATH "\\\\MainLCD\\\\CustomerServices\\\\CS_MyMonternet.pbm",
        "Icon for submenu of my monwap.");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_CUSTSER_SETTING,
        CUST_IMG_PATH "\\\\MainLCD\\\\CustomerServices\\\\CS_Setting.pbm",
        "Icon for submenu of setting.");

    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_TITLE, "Customer Service", "Title of Customer Service.");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_GUIDELINE, "Guideline", "menu text for guideline");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_GUIDELINE_CONTENT, "Guideline Content", "Guideline Content");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_SALE, "Sale", "menu text for sale");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_HOTLINE, "Hotline", "menu text for hotline");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_MANAGER, "Manager", "menu text for manager");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_MYMONWAP, "My Monwap", "menu text for my Monwap");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_MYMONWAP_CONTENT, "My Monwap Content", "My Monwap Content");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_MONWAP, "MONWAP", "menu text for Montenet");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_MONWAP_SMS, "Monwap SMS", "menu text for Monwap hilite string");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_MONWAP_SMS_CONTENT, "Monwap SMS Content", "onternet SMS Content");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_MONWAP_MMS, "Monwap MMS", "menu text for Monwap MMS");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_MONWAP_MMS_CONTENT, "Monwap SMS Content", "Monwap MMS Content");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_SETTING, "Setting", "menu text for setting");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_SETTING_HOTLINE, "Hotline", "menu text for hotline in setting");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_SETTING_MANAGER, "Manager", "menu text for manager in setting");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_SETTING_MANAGER_NAME, "Manager name", "menu text for Manager name");
    ADD_APPLICATION_STRING2(STR_ID_CUSTSER_SETTING_MANAGER_NUM, "Manager number", "menu text for Manager number");

    ADD_APPLICATION_MENUITEM((MENU_ID_CUSTSER_GUIDELINE, MAIN_MENU_CUST_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_CUSTSER_GUIDELINE, IMG_ID_CUSTSER_GUIDELINE));
    ADD_APPLICATION_MENUITEM((MENU_ID_CUSTSER_SALE, MAIN_MENU_CUST_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST,
                              STR_ID_CUSTSER_SALE, IMG_ID_CUSTSER_SALE));
    ADD_APPLICATION_MENUITEM((MENU_ID_CUSTSER_HOTLINE, MAIN_MENU_CUST_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST,
                              STR_ID_CUSTSER_HOTLINE, IMG_ID_CUSTSER_HOTLINE));
    ADD_APPLICATION_MENUITEM((MENU_ID_CUSTSER_MANAGER, MAIN_MENU_CUST_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST,
                              STR_ID_CUSTSER_MANAGER, IMG_ID_CUSTSER_MANAGER));
    ADD_APPLICATION_MENUITEM((MENU_ID_CUSTSER_MYMONWAP, MAIN_MENU_CUST_SERVICES_MENUID, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_CUSTSER_MYMONWAP, IMG_ID_CUSTSER_MYMONWAP));
    ADD_APPLICATION_MENUITEM((MENU_ID_CUSTSER_SETTING, MAIN_MENU_CUST_SERVICES_MENUID, 2, MENU_ID_CUSTSER_SETTING_HOTLINE,
                              MENU_ID_CUSTSER_SETTING_MANAGER, SHOW, MOVEABLEACROSSPARENT, DISP_LIST,
                              STR_ID_CUSTSER_SETTING, IMG_ID_CUSTSER_SETTING));
    ADD_APPLICATION_MENUITEM((MENU_ID_CUSTSER_SETTING_HOTLINE, MENU_ID_CUSTSER_SETTING, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_CUSTSER_SETTING_HOTLINE, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_CUSTSER_SETTING_MANAGER, MENU_ID_CUSTSER_SETTING, 0, SHOW, MOVEABLEACROSSPARENT,
                              DISP_LIST, STR_ID_CUSTSER_SETTING_MANAGER, 0));

}

#endif /* defined(__MMI_CUSTOMER_SERVICE__) */ 

