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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Res_BarcodeReader.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#include "MMI_features.h"

#if defined(__MMI_BARCODEREADER__)

#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#include "MMI_features_barcodereader.h"
#include "barcodereaderResDef.h"       /* include this for BarcodeReader related resource IDs */

#include "PopulateRes.h"
#include "CustResDef.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  PopulateBarcodeReaderStrRes
 * DESCRIPTION
 *  Generate BarcodeReader application related resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateBarcodeReaderStrRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*********** BarcodeReader App *************/
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_APP_NAME, "QR Code Reader", "[BarcodeReader App Name]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_DECODE_FAILED, "decode failed", "[BarcodeReader App Name]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ERROR_DECODE_TIMEOUT, "Time Out", "[BarcodeReader App Name]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_SETTING, "Setting", "");
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_PREVIEW, "Preview", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FILELIST, "File list", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_SERVICE_SUMMARY, "Service summary", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP, "Help", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_SERVICE_SUMMARY_CONTENT, "Service summary", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_CONTENT1, "Help1", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_CONTENT2, "Help2", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_CONTENT3, "Help3", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_CONTENT4, "Help4", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_CONTENT5, "Help5", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_CONTENT6, "Help6", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_RECOGNIZE, "Recoginze", "");

    /*attribute string*/
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_N, "name", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_TIL, "title", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_DIV, "Department", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_COR, "Corporation", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_ADR, "Address", "");

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_ZIP, "Zip code", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_TEL, "Telphone", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_M, "Mobile", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_FAX, "Fax", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_EM, "Em", "");

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_URL, "Url", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_SM, "Sm", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_TO, "To", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_CT, "Contact", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_TXT, "Text", "");

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_INTR, "Intr", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_TYPE, "Type", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_LEN, "Length", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_FILE, "File", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_CR, "Copyright", "");

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_SUB, "Subject", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_DG, "Order", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ATTR_SID, "Service ID", "");

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ENCODING_ERROR, "encoding error", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_RECOGNIZE_ERROR, "recognize error", "");

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FILE_OPEN, "file open", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_OPTION, "option", "");

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_TO_ACCESSS, "access", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_SAVE_BOOKMARK, "save bookmark", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_TO_COMMEND, "to commend", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_TO_ORDER, "to order", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_SERVICE_TEL, "service tel", "");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_TO_LISTEN, "to listen", "");
    
#endif /*__MMI_BARCODEREADER_OPERATOR1__*/

   /*********** Option Menu *************/
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_RESTORE_DEFAULT, "Restore Default?", "[Menu-Restore Default]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FOCUS_MODE, "Focus Mode", "[Menu-Focus Mode]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FLASH, "Flash", "[Menu-Flash]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV, "EV", "[Menu-EV]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_STORAGE, "Storage", "[Menu-Add Storage]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_BANDING, "Banding", "[Menu-Banding]");

    
    /********** APPEND BARCODE **********/
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_RSK_CONTINUE, "Continue", "[Rsk - continue]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_LSK_RESET, "Reset", "[Lsk - reset]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_WRONG_SERIES, "Wrong Series", "[Help - Wrong Series]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_DUPLICATED_CODE, "Duplicated Code", "[Help - Duplicated Code]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_DECODE_NEXT, "Decode Next One?", "[Help - Decode next one]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_HELP_APPEND_BARCODE, "Append Structure Barcode", "[Help - Append Structure Barcode]");

   /*********** notify *************/
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_NOTIFY_DISK_FULL, "Disk Full", "[Notify-Disk Full]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_NOTIFY_NO_MEMORY_CARD, "No Memory Card", "[Notify-No Memory Card]");
    ADD_APPLICATION_STRING2(
        STR_ID_BARCODEREADER_NOTIFY_WRITE_PROTECTION,
        "Memory card is locked.\nCan't write in.",
        "[Notify-Write Protection]");
    ADD_APPLICATION_STRING2(
        STR_ID_BARCODEREADER_NOTIFY_HW_NOT_READY,
        "Camera module not ready.",
        "[Notify-HW Not Ready]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_NOTIFY_ERROR, "QRCode Reader Error", "[Notify-Camera Error]");

    ADD_APPLICATION_STRING2(
        STR_ID_BARCODEREADER_NOTIFY_RESTORE_DEFAULT_CONFIRM,
        "Restore Default?",
        "[Notify-Restore??]");

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE, "Decoding...", "[Notify-decoding]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_NOTIFY_SEND_TO, "Send To:", "[Notify-send to]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_NOTIFY_CONTENT, "Content:", "[Notify-decoding]");


    /************ Error String **************/
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ERROR_OVER_VERSION, "Unsupport Version", "[Notify-ERROR]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ERROR_MEMORY_NOT_ENOUGH, "Resource Not Enough", "[Notify-ERROR]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ERROR_BROKEN_IMAGE, "Unrecognized Code", "[Notify-ERROR]");
    
    /************ to applications ***********/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_TO_GENERAL, "General Manage", "[General]");
#else
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_VCARD, "vCard Manage", "[vCard]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_DTXT, "Content Manage", "[Content]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_SMSSELL, "Business Manage", "[Business]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_WAPSELL, "Business Manage", "[Business]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_IVRSELL, "Business Manage", "[Business]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EMAIL, "Email Manage", "[Email]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_SMS, "SMS Manage", "[SMS]");
#endif

    /************ functions *****************/
    /*commen string*/
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, "Save to folder", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SEND_BY_SMS, "send by sms", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SAVE_SMS, "Save sms", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK, "Save to phonebook", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL, "Save by email", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_OPEN_URL, "open url", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SAVE_URL, "save url", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_ORDER, "order", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_MAKE_CALL, "make call", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SAVE_EMAIL, "Save email", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL, "edit by email", "[Func save]");
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_EXIT, "exit", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK, "save to phonebook", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_EDIT_BY_MMS, "edit by mms", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_EDIT_BY_SMS, "edit by sms", "[Func save]");
#else
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_PREVIEW, "Preview", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, "back to main", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_SEND_BY_MMS, "send by mms", "[Func save]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FUNC_COMMEND, "comment", "[Func save]");
#endif

    ADD_APPLICATION_STRING2(
        STR_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK,
        "Save to Phonebook",
        "[Func save to phonebok]");

    ADD_APPLICATION_STRING2(
        STR_ID_BARCODEREADER_ORDER_CONFIRM,
        "This operation will send a SMS message, and may charge fee.",
        "[order confirm]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_ORDER_ATTENTION, "Attention!", "[order attention]");



    /*********** Storage *************/
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_STORAGE_PHONE, "Phone", "[Menu-Phone]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_STORAGE_MEMORY_CARD, "Memory Card", "[Menu-Memory Card]");

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FOCUS_MODE_AUTO, "AF Auto", "[AF - Manual]");
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FOCUS_MODE_MACRO, "AF Macro", "[AF - Macro]");
#endif 
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_INFINITE__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FOCUS_MODE_INFINITE, "AF Infinite", "[AF - Infinite]");
#endif 
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FOCUS_MODE_MANUAL, "AF Manual", "[AF - Manual]");
#endif 
#endif /* __BARCODEREADER_FOCUS_MODE__ */ 

   /*********** Flash *************/
#ifdef __MMI_BARCODEREADER_FLASH__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FLASH_OFF, "Off", "[Inline-Flash Off]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_FLASH_ON, "On", "[Inline-Flash On]");
#endif /* __BARCODEREADER_FLASH__ */ 

   /*********** Banding *************/
#ifdef __MMI_BARCODEREADER_BANDING__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_BANDING_50HZ, "50HZ", "[Inline-Banding 50Hz]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_BANDING_60HZ, "60HZ", "[Inline-Banding 60Hz]");
#endif /* __MMI_BARCODEREADER_BANDING__ */ 


   /*********** EV *************/
#ifdef __MMI_BARCODEREADER_EV_4__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_N4, "EV -4", "[Inline-EV -4]");
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_N3, "EV -3", "[Inline-EV -3]");
#endif 

#ifdef __MMI_BARCODEREADER_EV_2__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_N2, "EV -2", "[Inline-EV -2]");
#endif 

    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_N1, "EV -1", "[Inline-EV -1]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_0, "EV 0", "[Inline-EV 0]");
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_P1, "EV +1", "[Inline-EV +1]");

#ifdef __MMI_BARCODEREADER_EV_2__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_P2, "EV +2", "[Inline-EV +2]");
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_P3, "EV +3", "[Inline-EV +3]");
#endif 

#ifdef __MMI_BARCODEREADER_EV_4__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_EV_P4, "EV +4", "[Inline-EV +4]");
#endif 

#ifdef __MMI_CAMERA_23KEY__
    ADD_APPLICATION_STRING2(STR_ID_BARCODEREADER_RSK_CAPTURE, "Capture", "[RSK-Capture]");
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  PopulateBarcodeReaderImgRes
 * DESCRIPTION
 *  Generate Camrea related resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateBarcodeReaderImgRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* define Qrreader osd iamge path */
    #define MMI_BARCODEREADER_ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\BarcodeReader\\\\OSD\\\\"

   /******************************************
   * App
   *******************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_APP_ICON,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "");
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_PREVIEW_ICON,
        MMI_BARCODEREADER_ROOT_PATH"SB_Preview.pbm",
        "");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FILELIST_ICON,
        MMI_BARCODEREADER_ROOT_PATH"SB_FM.pbm",
        "");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_SERVICE_SUMMARY_ICON,
        MMI_BARCODEREADER_ROOT_PATH"SB_introduction.pbm",
        "");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_HELP_ICON,
        MMI_BARCODEREADER_ROOT_PATH"SB_Help.pbm",
        "");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_SETTING_ICON,
        MMI_BARCODEREADER_ROOT_PATH"SB_Setting.pbm",
        "");
#endif
   /******************************************
   * Menu Icon 
   *******************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_MENUICON_EV,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MENU_EV.pbm",
        "IMG_ID_BARCODEREADER_MENUICON_EV");

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_MENUICON_FOCUS_MODE,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MENU_FOCUS_MODE.pbm",
        "IMG_ID_BARCODEREADER_MENUICON_FOCUS_MODE");
#endif /* __BARCODEREADER_FOCUS_MODE__ */ 

#ifdef __MMI_BARCODEREADER_FLASH__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_MENUICON_FLASH,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MENU_FLASH.pbm",
        "IMG_ID_BARCODEREADER_MENUICON_FLASH");
#endif /* __BARCODEREADER_FLASH__ */ /* __BARCODEREADER_FOCUS_MODE__ */

#ifdef __MMI_BARCODEREADER_STORAGE__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_MENUICON_STORAGE,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MENU_STORAGE.pbm",
        "IMG_ID_BARCODEREADER_MENUICON_STORAGE");
#endif /* __BARCODEREADER_STORAGE__ */ 

#ifdef __MMI_BARCODEREADER_BANDING__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_MENUICON_BANDING,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MENU_BANDING.pbm",
        "IMG_ID_BARCODEREADER_MENUICON_BANDING");
#endif /* __BARCODEREADER_BANDING__ */ 


   /******************************************
   * MISC
   *******************************************/
#ifdef __MMI_SUBLCD__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_PREVIEW_SUBLCD_ICON,
        MMI_BARCODEREADER_ROOT_PATH"SB_BarcodeReader.gif",
        "IMG_ID_BARCODEREADER_PREVIEW_SUBLCD_ICON");
#endif /* __MMI_SUBLCD__ */ 
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_PREVIEW_BACKGROUND,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_bg.gif",
        "IMG_ID_BARCODEREADER_PREVIEW_SUBLCD_ICON");

    /*******************************************
    * Funcs
    ********************************************/
    /******** Applications ***********/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_TO_CARD,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_TO_CARD");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_TO_CONTENT,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_TO_CONTENT");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_TO_SMS,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_TO_SMS");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_TO_EMAIL,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_TO_EMAIL");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_TO_BUSINESS,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_TO_BUSINESS");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_TO_GENERAL,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_TO_GENERAL");

    /******** Functions ***********/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_SAVE,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_SAVE");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_EXIT,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_EXIT");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_MAKE_CALL,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_MAKE_CALL");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_EDIT_BY_MMS,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_EDIT_BY_MMS");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_EDIT_BY_SMS,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_EDIT_BY_SMS");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_SEND_BY_SMS,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_SEND_BY_SMS");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_OPEN_URL,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_OPEN_URL");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_SAVE_URL,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_SAVE_URL");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_FUNC_ORDER,
        MMI_BARCODEREADER_ROOT_PATH"APP_BarcodeReader.pbm",
        "IMG_ID_BARCODEREADER_FUNC_ORDER");

   /******************************************
   * OSD ICON
   *******************************************/
#ifdef __MMI_BARCODEREADER_FLASH__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FLASH_OFF,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_flash_off.pbm",
        "IMG_ID_BARCODEREADER_OSD_FLASH_OFF");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FLASH_OFF_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_flash_off_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_FLASH_OFF");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FLASH_ON,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_flash_on.pbm",
        "IMG_ID_BARCODEREADER_OSD_FLASH_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FLASH_ON_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_flash_on_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_FLASH_ON");
#endif /* __BARCODEREADER_FLASH__ */ 

#ifdef __MMI_BARCODEREADER_EV_4__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_P4,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_p4.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_P4");
#endif /* __BARCODEREADER_EV_4__ */ 

#ifdef __MMI_BARCODEREADER_EV_3__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_P3,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_p3.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_P3");
#endif /* __BARCODEREADER_EV_3__ */ 

#ifdef __MMI_BARCODEREADER_EV_2__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_P2,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_p2.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_P2");
#endif /* __BARCODEREADER_EV_2__ */ 

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_P1,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_p1.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_P1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_0,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_0.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_0");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_N1,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_n1.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_N1");

#ifdef __MMI_BARCODEREADER_EV_2__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_N2,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_n2.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_N2");
#endif /* __BARCODEREADER_EV_2__ */ 

#ifdef __MMI_BARCODEREADER_EV_3__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_N3,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_n3.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_N3");
#endif /* __BARCODEREADER_EV_3__ */ 

#ifdef __MMI_BARCODEREADER_EV_4__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_N4,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_n4.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_N4");
#endif /* __BARCODEREADER_EV_4__ */ 

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_INC,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_inc.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_INC");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_INC_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_inc_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_INC_SEL");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_DEC,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_dec.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_DEC");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_EV_DEC_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_ev_dec_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_EV_DEC_SEL");

   /*********** Auto Focus *************/
#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_AUTO,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_FOCUS_auto.pbm",
        "IMG_ID_BARCODEREADER_OSD_AUTOFOCUS_MODE_AUTO");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_AUTO_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_FOCUS_auto_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_AUTOFOCUS_MODE_AUTO");

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_MACRO,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_FOCUS_macro.pbm",
        "IMG_ID_BARCODEREADER_OSD_AUTOFOCUS_MODE_MACRO");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_MACRO_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_FOCUS_macro_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_AUTOFOCUS_MODE_MACRO");
#endif /* __MMI_BARCODEREADER_FOCUS_MODE_MACRO__ */ 
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_MANUAL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_FOCUS_manual.pbm",
        "IMG_ID_BARCODEREADER_OSD_AUTOFOCUS_MANUAL_MODE_MANURL");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_MANUAL_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_FOCUS_manual_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_AUTOFOCUS_MANUAL_MODE_MANURL");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_MF_BAR,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MF_bar.pbm",
        "IMG_ID_BARCODEREADER_OSD_ZOOM_BAR");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_MF_SLIDER,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MF_slider.pbm",
        "IMG_ID_BARCODEREADER_OSD_ZOOM_SLIDER");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_MF_INC,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MF_inc.pbm",
        "IMG_ID_BARCODEREADER_OSD_ZOOM_INC");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_MF_DEC,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MF_dec.pbm",
        "IMG_ID_BARCODEREADER_OSD_ZOOM_DEC");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_MF_INC_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MF_inc_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_ZOOM_INC_SEL");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_MF_DEC_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_MF_dec_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_ZOOM_DEC_SEL");
#endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 

   /*********** capture button *************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_CAPTURE,
#ifndef __MMI_BARCODEREADER_OPERATOR1__
        MMI_BARCODEREADER_ROOT_PATH"SCAN_capture.pbm",
#else
        MMI_BARCODEREADER_ROOT_PATH"SCAN_preview_Sel.gif",
#endif
        "IMG_ID_BARCODEREADER_OSD_CAPTURE");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_CAPTURE_SEL,
#ifndef __MMI_BARCODEREADER_OPERATOR1__
        MMI_BARCODEREADER_ROOT_PATH"SCAN_capture_sel.pbm",
#else
        MMI_BARCODEREADER_ROOT_PATH"SCAN_preview_Aim.gif",
#endif
        "IMG_ID_BARCODEREADER_OSD_CAPTURE_SEL");

   /*********** Storage *************/
#ifdef __MMI_BARCODEREADER_STORAGE__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_STORAGE_PHONE,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_STORAGE_phone.pbm",
        "IMG_ID_BARCODEREADER_OSD_STORAGE_PHONE");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_STORAGE_PHONE_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_STORAGE_phone_SEL.pbm",
        "IMG_ID_BARCODEREADER_OSD_STORAGE_PHONE");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_STORAGE_card.pbm",
        "IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD_SEL,
        MMI_BARCODEREADER_ROOT_PATH"SCAN_STORAGE_card_sel.pbm",
        "IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD");
#endif /* __BARCODEREADER_STORAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  PopulateBarcodeReaderMenuRes
 * DESCRIPTION
 *  Generate BarcodeReader related resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateBarcodeReaderMenuRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*********** BarcodeReader App *************/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP, MAIN_MENU_MULTIMEDIA_MENUID, 0,
                              SHOW, MOVEABLEACROSSPARENT | SHORTCUTABLE, 1, STR_ID_BARCODEREADER_APP_NAME,
                              IMG_ID_BARCODEREADER_APP_ICON));

   
#ifndef __MMI_BARCODEREADER_OPERATOR1__
   /*********** Option Menu *************/
#ifdef __MMI_BARCODEREADER_STORAGE__
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_OPTION, 
        0,
        2,
        MENU_ID_BARCODEREADER_OPTION_SETTINGS,
        MENU_ID_BARCODEREADER_OPTION_STORAGE,
                              0, 0, 1, STR_GLOBAL_OPTIONS, IMG_ID_BARCODEREADER_APP_ICON));

    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_OPTION_SETTINGS, MENU_ID_BARCODEREADER_OPTION,0,
        SHOW,NONMOVEABLE,1,STR_ID_BARCODEREADER_SETTING,0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_OPTION_STORAGE, MENU_ID_BARCODEREADER_OPTION,0,
        SHOW,NONMOVEABLE,1,STR_ID_BARCODEREADER_STORAGE,0));
#endif

    /*********** FORWARD TO OTHER APPLIACTION MENU **********/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP_TO_GENERAL,
                              0,
                              10,
                              MENU_ID_BARCODEREADER_FUNC_SAVE,
                              MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS,
                              MENU_ID_BARCODEREADER_FUNC_SAVE_SMS,
                              MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS,
                              MENU_ID_BARCODEREADER_FUNC_MAKE_CALL,
                              MENU_ID_BARCODEREADER_FUNC_OPEN_URL,
                              MENU_ID_BARCODEREADER_FUNC_SAVE_URL,
                              MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK,
                              MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS,
                              MENU_ID_BARCODEREADER_FUNC_EXIT,
                              0, 0, 1, STR_ID_BARCODEREADER_TO_GENERAL, IMG_ID_BARCODEREADER_APP_ICON));

   /***********  Functions *************/

    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_EXIT, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_EXIT, IMG_ID_BARCODEREADER_FUNC_EXIT));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK,
                              IMG_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_EDIT_BY_MMS,
                              IMG_ID_BARCODEREADER_FUNC_EDIT_BY_MMS));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_EDIT_BY_SMS,
                              IMG_ID_BARCODEREADER_FUNC_EDIT_BY_SMS));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL,
                              IMG_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_ORDER, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_ORDER, IMG_ID_BARCODEREADER_FUNC_ORDER));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_URL, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_URL, IMG_ID_BARCODEREADER_FUNC_SAVE_URL));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_OPEN_URL, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_OPEN_URL, IMG_ID_BARCODEREADER_FUNC_OPEN_URL));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SEND_BY_SMS,
                              IMG_ID_BARCODEREADER_FUNC_SEND_BY_SMS));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL,
                              IMG_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_MAKE_CALL, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_MAKE_CALL,
                              IMG_ID_BARCODEREADER_FUNC_MAKE_CALL));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_SMS, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_SMS, IMG_ID_BARCODEREADER_FUNC_SAVE_SMS));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_EMAIL, MENU_ID_BARCODEREADER_APP_TO_GENERAL, 0, SHOW,
                              NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_EMAIL,
                              IMG_ID_BARCODEREADER_FUNC_SAVE_EMAIL));
#else
    /*sms menu*/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP_TO_SMS,
        0,
        5,
        MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS,
        MENU_ID_BARCODEREADER_FUNC_SAVE_SMS,
        MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER,
        MENU_ID_BARCODEREADER_FUNC_PREVIEW,
        MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN,
                              0, 0, 1, STR_ID_BARCODEREADER_SMS, IMG_ID_BARCODEREADER_APP_ICON));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS, MENU_ID_BARCODEREADER_APP_TO_SMS, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SEND_BY_SMS, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_SMS, MENU_ID_BARCODEREADER_APP_TO_SMS, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_SMS, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, MENU_ID_BARCODEREADER_APP_TO_SMS, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_PREVIEW, MENU_ID_BARCODEREADER_APP_TO_SMS, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_PREVIEW, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, MENU_ID_BARCODEREADER_APP_TO_SMS, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, IMG_ID_BARCODEREADER_FUNC_SAVE));   

    /*vcard menu*/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP_TO_VCARD,
        0,
        9,
        MENU_ID_BARCODEREADER_FUNC_MAKE_CALL,
        MENU_ID_BARCODEREADER_FUNC_OPEN_URL,
        MENU_ID_BARCODEREADER_FUNC_SAVE_URL,
        MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL,
        MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK,
        MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS,
        MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER,
        MENU_ID_BARCODEREADER_FUNC_PREVIEW,
        MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN,
                              0, 0, 1, STR_ID_BARCODEREADER_VCARD, IMG_ID_BARCODEREADER_APP_ICON));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SEND_BY_SMS, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_PREVIEW, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_PREVIEW, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_MAKE_CALL, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
        HIDE, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_MAKE_CALL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_OPEN_URL, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
        HIDE, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_OPEN_URL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_URL, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
                              HIDE, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_URL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL, MENU_ID_BARCODEREADER_APP_TO_VCARD, 0,
                              HIDE, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL, IMG_ID_BARCODEREADER_FUNC_SAVE));

    /*text*/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP_TO_DTXT,
        0,
        6,
        MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS,
        MENU_ID_BARCODEREADER_FUNC_SEND_BY_MMS,
        MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL,
        MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER,
        MENU_ID_BARCODEREADER_FUNC_PREVIEW,
        MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN,
                              0, 0, 1, STR_ID_BARCODEREADER_DTXT, IMG_ID_BARCODEREADER_APP_ICON));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS, MENU_ID_BARCODEREADER_APP_TO_DTXT, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SEND_BY_SMS, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SEND_BY_MMS, MENU_ID_BARCODEREADER_APP_TO_DTXT, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SEND_BY_MMS, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL, MENU_ID_BARCODEREADER_APP_TO_DTXT, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, MENU_ID_BARCODEREADER_APP_TO_DTXT, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_PREVIEW, MENU_ID_BARCODEREADER_APP_TO_DTXT, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_PREVIEW, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, MENU_ID_BARCODEREADER_APP_TO_DTXT, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, IMG_ID_BARCODEREADER_FUNC_SAVE));
    
    /*email menu*/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP_TO_EMAIL,
        0,
        5,
        MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL,
        MENU_ID_BARCODEREADER_FUNC_SAVE_EMAIL,
        MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER,
        MENU_ID_BARCODEREADER_FUNC_PREVIEW,
        MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN,
                              0, 0, 1, STR_ID_BARCODEREADER_EMAIL, IMG_ID_BARCODEREADER_APP_ICON));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL, MENU_ID_BARCODEREADER_APP_TO_EMAIL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_EMAIL, MENU_ID_BARCODEREADER_APP_TO_EMAIL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_EMAIL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, MENU_ID_BARCODEREADER_APP_TO_EMAIL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_PREVIEW, MENU_ID_BARCODEREADER_APP_TO_EMAIL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_PREVIEW, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, MENU_ID_BARCODEREADER_APP_TO_EMAIL, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, IMG_ID_BARCODEREADER_FUNC_SAVE));
    
    /*wap sell menu*/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP_TO_WAPSELL,
        0,
        7,
        MENU_ID_BARCODEREADER_FUNC_MAKE_CALL,
        MENU_ID_BARCODEREADER_FUNC_OPEN_URL,
        MENU_ID_BARCODEREADER_FUNC_SAVE_URL,
        MENU_ID_BARCODEREADER_FUNC_COMMEND,
        MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER,
        MENU_ID_BARCODEREADER_FUNC_PREVIEW,
        MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN,
                              0, 0, 1, STR_ID_BARCODEREADER_WAPSELL, IMG_ID_BARCODEREADER_APP_ICON));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_OPEN_URL, MENU_ID_BARCODEREADER_APP_TO_WAPSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_OPEN_URL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_URL, MENU_ID_BARCODEREADER_APP_TO_WAPSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_URL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_COMMEND, MENU_ID_BARCODEREADER_APP_TO_WAPSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_COMMEND, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, MENU_ID_BARCODEREADER_APP_TO_WAPSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_PREVIEW, MENU_ID_BARCODEREADER_APP_TO_WAPSELL, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_PREVIEW, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, MENU_ID_BARCODEREADER_APP_TO_WAPSELL, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_MAKE_CALL, MENU_ID_BARCODEREADER_APP_TO_WAPSELL, 0,
        HIDE, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_MAKE_CALL, IMG_ID_BARCODEREADER_FUNC_SAVE));

    /*SMS sell*/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP_TO_SMSSELL,
        0,
        6,
        MENU_ID_BARCODEREADER_FUNC_MAKE_CALL,
        MENU_ID_BARCODEREADER_FUNC_ORDER,
        MENU_ID_BARCODEREADER_FUNC_COMMEND,
        MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER,
        MENU_ID_BARCODEREADER_FUNC_PREVIEW,
        MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN,
        0, 0, 1, STR_ID_BARCODEREADER_SMSSELL, IMG_ID_BARCODEREADER_APP_ICON));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_ORDER, MENU_ID_BARCODEREADER_APP_TO_SMSSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_ORDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_COMMEND, MENU_ID_BARCODEREADER_APP_TO_SMSSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_COMMEND, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, MENU_ID_BARCODEREADER_APP_TO_SMSSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_PREVIEW, MENU_ID_BARCODEREADER_APP_TO_SMSSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_PREVIEW, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, MENU_ID_BARCODEREADER_APP_TO_SMSSELL, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_MAKE_CALL, MENU_ID_BARCODEREADER_APP_TO_WAPSELL, 0,
        HIDE, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_MAKE_CALL, IMG_ID_BARCODEREADER_FUNC_SAVE));

    /*IVR sell*/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_APP_TO_IVRSELL,
        0,
        5,
        MENU_ID_BARCODEREADER_FUNC_MAKE_CALL,
        MENU_ID_BARCODEREADER_FUNC_COMMEND,
        MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER,
        MENU_ID_BARCODEREADER_FUNC_PREVIEW,
        MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN,
        0, 0, 1, STR_ID_BARCODEREADER_IVRSELL, IMG_ID_BARCODEREADER_APP_ICON));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_MAKE_CALL, MENU_ID_BARCODEREADER_APP_TO_IVRSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_MAKE_CALL, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_COMMEND, MENU_ID_BARCODEREADER_APP_TO_IVRSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_COMMEND, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, MENU_ID_BARCODEREADER_APP_TO_IVRSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_PREVIEW, MENU_ID_BARCODEREADER_APP_TO_IVRSELL, 0,
        SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_PREVIEW, IMG_ID_BARCODEREADER_FUNC_SAVE));
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, MENU_ID_BARCODEREADER_APP_TO_IVRSELL, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, IMG_ID_BARCODEREADER_FUNC_SAVE));

    /*file list*/
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FILE_LIST,
        0,
        3,
        MENU_ID_BARCODEREADER_FILE_OPEN,
        MENU_FMGR_GEN_OPTION_DELETE,
        MENU_FMGR_GEN_OPTION_DELETE_ALL,
        0, 0, 1, STR_ID_BARCODEREADER_FILELIST, IMG_ID_BARCODEREADER_FUNC_SAVE)); 
    ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_FILE_OPEN, MENU_ID_BARCODEREADER_FILE_LIST, 0,
                              SHOW, NONMOVEABLE, 1, STR_ID_BARCODEREADER_FILE_OPEN, IMG_ID_BARCODEREADER_FUNC_SAVE));
#endif

    /*qrv editor releated*/
	ADD_APPLICATION_MENUITEM((MENU_ID_BARCODEREADER_TO_QRV_EDITOR, MENU_ID_IMGVIEW_FILE_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_VIEW,0));
	/* File Option Menu */
	ADD_APPLICATION_MENUITEM((	MENU_ID_BARCODEREADER_FILE_OPTION, 
						0,	
					#ifdef __FS_MOVE_SUPPORT__		
						8,
					#else
						6,
					#endif		
						MENU_ID_BARCODEREADER_TO_QRV_EDITOR,
						MENU_FMGR_GEN_OPTION_FORWARD,
						MENU_FMGR_GEN_OPTION_RENAME,
					#ifdef __FS_MOVE_SUPPORT__		
						MENU_FMGR_GEN_OPTION_COPY, 
						MENU_FMGR_GEN_OPTION_MOVE, 
					#endif		
						MENU_FMGR_GEN_OPTION_DELETE,
						MENU_FMGR_GEN_OPTION_DELETE_ALL,
						MENU_FMGR_GEN_OPTION_SORT,
						0, 
						0, 
						1,
						STR_GLOBAL_OPTIONS,
						IMG_ID_BARCODEREADER_APP_ICON));

	/* File Option Menu */
	ADD_APPLICATION_MENUITEM((	MENU_ID_BARCODEREADER_FILE_OPTION_NO_SIM, 
						0,	
					#ifdef __FS_MOVE_SUPPORT__		
						7,
					#else
						5,
					#endif		
						MENU_ID_BARCODEREADER_TO_QRV_EDITOR,
						MENU_FMGR_GEN_OPTION_RENAME,
					#ifdef __FS_MOVE_SUPPORT__		
						MENU_FMGR_GEN_OPTION_COPY, 
						MENU_FMGR_GEN_OPTION_MOVE, 
					#endif		
						MENU_FMGR_GEN_OPTION_DELETE,
						MENU_FMGR_GEN_OPTION_DELETE_ALL,
						MENU_FMGR_GEN_OPTION_SORT,
						0, 
						0, 
						1,
						STR_GLOBAL_OPTIONS,
						IMG_ID_BARCODEREADER_APP_ICON));

}


/*****************************************************************************
 * FUNCTION
 *  PopulateBarcodeReaderRes
 * DESCRIPTION
 *  Generate Camrea related resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateBarcodeReaderRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PopulateBarcodeReaderStrRes();
    PopulateBarcodeReaderImgRes();
    PopulateBarcodeReaderMenuRes();
}
#endif /* defined(__MMI_BARCODEREADER__) */ 

