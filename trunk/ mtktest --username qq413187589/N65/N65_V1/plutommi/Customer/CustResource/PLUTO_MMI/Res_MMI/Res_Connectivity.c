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

#include "MMI_features.h"
#include "CustomCfg.h"


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

#include "ConnectivityResDef.h"

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
#include "PictBridgeResDef.h"
#endif

#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_IRDA_SUPPORT__)
/* under construction !*/
#endif
#if defined(__MMI_BT_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_IRDA_SUPPORT__)
/* under construction !*/
#endif
#if defined(__MMI_BT_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__))) */
/***************************************************************************************************/
/*** USB Device Resource  ***/
/***************************************************************************************************/
#ifdef __MMI_USB_SUPPORT__

void PopulateExtDevUSBRes(void)
{
    ADD_APPLICATION_STRING2(STR_USB_CONFIG_TITLE,"USB Config:","USB Detection");
    ADD_APPLICATION_IMAGE2(IMG_USB_POWER_ON,CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_noanimation."__MMI_RES_TYPE_ACTIVE_SCREEN__,"Power on with USB boot mode");
    ADD_APPLICATION_IMAGE2(IMG_USB_CHGR_CMPLT,CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_ChgrCmplt."__MMI_RES_TYPE_ACTIVE_SCREEN__,"Power on with USB boot mode");
    ADD_APPLICATION_IMAGE2(IMG_ID_USB_CHARGING,CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_on.gif","Power on with USB boot mode");

#ifdef __MMI_SUBLCD__
    ADD_APPLICATION_IMAGE2(IMG_SUB_USB_POWER_ON,CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_USB_on.gif","Power on with USB boot mode");
    ADD_APPLICATION_IMAGE2(IMG_USB_SUB_CHGR_CMPLT,CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_USB_ChgrCmplt.gif","Power on with USB boot mode");
#ifdef __MMI_WEBCAM__
    ADD_APPLICATION_IMAGE2(IMG_ID_WEBCAM_SUB_BG, CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_USB_Webcam.gif","Webcam sublcd icon");
#endif
#endif /* __MMI_SUBLCD__ */



#ifdef __MMI_WEBCAM__
    /* Webcam Image Resource */
    ADD_APPLICATION_IMAGE2(IMG_ID_WEBCAM_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\webcam\\\\webcam_bg.gif","webcam screen");

    ADD_APPLICATION_IMAGE2(IMG_ID_WEBCAM_PAUSE_JPEG_0, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\webcam\\\\webcam_jpeg_0.jpg","Pause screen jpeg");
    ADD_APPLICATION_IMAGE2(IMG_ID_WEBCAM_PAUSE_JPEG_1, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\webcam\\\\webcam_jpeg_1.jpg","Pause screen jpeg");
    ADD_APPLICATION_IMAGE2(IMG_ID_WEBCAM_PAUSE_JPEG_2, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\webcam\\\\webcam_jpeg_2.jpg","Pause screen jpeg");
    ADD_APPLICATION_IMAGE2(IMG_ID_WEBCAM_PAUSE_JPEG_3, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\webcam\\\\webcam_jpeg_3.jpg","Pause screen jpeg");
#endif /* __MMI_WEBCAM__ */


#if defined(__MMI_USB_CDCACM_ONLY__)

    /* CDCACM Only */
    ADD_APPLICATION_STRING2(STR_USB_CONFIG_CDCACM_ONLY,"USB Detect! Set as COM port?","USB Detection");

#elif defined(__MMI_USB_MS_ONLY__)

    /* MS Only */
    ADD_APPLICATION_STRING2(STR_USB_CONFIG_MS_ONLY,"USB Detect! Shutdown for Mass storage?","USB Detection");

#else /* Both */

    /* Mass Storage & CDCACM */ 

    /* For charger/alarm power on */
    ADD_APPLICATION_STRING2(STR_USB_CONFIG_MS_ONLY,"USB Detect! Shutdown for Mass storage?","USB Detection");

    ADD_APPLICATION_STRING2(STR_USB_CONFIG_MS,"Mass Storage","USB Detection");
    ADD_APPLICATION_STRING2(STR_USB_CONFIG_CDCACM_DATA,"Data Port","USB Detection");
    //ADD_APPLICATION_STRING2(STR_USB_CONFIG_CDCACM_DEBUG,"Debug Port","USB Detection");

#endif  /* __MMI_USB_CDCACM_ONLY__ && __MMI_USB_CDCACM_ONLY__  */

#ifdef __MMI_WEBCAM__
    ADD_APPLICATION_STRING2(STR_ID_USB_CONFIG_WEBCAM,"Webcam","USB Detection");
    ADD_APPLICATION_STRING2(STR_ID_USB_NOTIFY_WEBCAM_ERROR,"Webcam device error","USB Device Error");	
    ADD_APPLICATION_STRING2(STR_ID_USB_NOTIFY_WEBCAM_CAM_ERROR,"Camera Device Error","USB Device Error");	    
    ADD_APPLICATION_STRING2(STR_ID_USB_WEBCAM_STOPPED,"Webcam Stopped","Webcam stopped");			
#endif /* __MMI_WEBCAM__ */

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    ADD_APPLICATION_STRING2(STR_USB_CONFIG_PICT_BRIGE, "PictBridge","USB Detection");
    ADD_APPLICATION_STRING2(STR_USB_PICT_BRIGE_CONFIGING,"PictBridge Configuring...","USB PictBridge Configing");
#endif

    ADD_APPLICATION_STRING2(STR_USB_SHUTDOWN_SCR,"Shutdown for Mass Storage...","USB Detection");
    ADD_APPLICATION_STRING2(STR_USB_POWER_ON_PROCESSING,"Power on for Mass Storage...","USB Detection");
    ADD_APPLICATION_STRING2(STR_USB_CDCACM_SETTING_SCR,"COM Port Configing...","USB Detection");

#ifdef __USB_IN_NORMAL_MODE__
    ADD_APPLICATION_STRING2(STR_ID_USB_MODE_PROGRESS,"Waiting","USB Detection");
    ADD_APPLICATION_STRING2(STR_ID_USB_MODE_EXPORTED_WARNING,"USB: Function not allowed!","USB Detection");
    ADD_APPLICATION_STRING2(STR_ID_USB_NO_MS_FOR_PC,"USB: No storage for PC","USB Detection");    
    ADD_APPLICATION_STRING2(STR_ID_USB_SYS_NOT_READY,"System not ready, Please try later!","USB Detection");    
#endif
    ADD_APPLICATION_STRING2(STR_ID_USB_IRCOMM_OCCUPY_CDCACM, "Please turn off IrDA","USB Detection");
	
    ADD_APPLICATION_STRING2(STR_ID_USB_UART2_OCCUPIED,"UART2 is Occupied!","USB Detection");    	

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    ADD_APPLICATION_STRING2(STR_ID_PICT_TITLE, "Print", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_CONFIGURATION, "Printer Configuring...", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_SETTINGS, "Print Setting", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_PREVIEW, "Preview", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_PRINTING, "Printing", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_QUERY, "Abort the printing job?\nPress Yes to abort or No to keep it in the background.", "PictBridge");

    ADD_APPLICATION_STRING2(STR_ID_PICT_BRIDGE, "PictBridge", "PictBridge");

    ADD_APPLICATION_STRING2(STR_ID_PICT_PAPER_SIZE, "Paper size", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_COPIES, "Number of copies", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_PAGE_FORMAT, "Page format", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_LAYOUT, "Pages per sheet", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_BORDER, "Border", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_DATE_PRINT, "Date print", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_FILENAME_PRINT, "File name print", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_CROPPING, "Cropping", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_FIXED_SIZE, "Fixed size", "PictBridge");

    ADD_APPLICATION_STRING2(STR_ID_PICT_DEFAULT, "Default", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_ENABLE, "Enable", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_DISABLE, "Disable", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_STANDARD, "Standard", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_MULTIPLE, "Multiple", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_INDEX, "Index", "PictBridge");

    ADD_APPLICATION_STRING2(STR_ID_PICT_PAPER_POSTCARD, "Postcard", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_PAPER_4x6, "4x6", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_PAPER_LETTER, "Letter", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_PAPER_A4, "A4", "PictBridge");

    ADD_APPLICATION_STRING2(STR_ID_PICT_CONTINUE, "Cont.", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_ERROR, "Print error!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_ERROR_PAPER, "Paper error!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_ERROR_INK, "Ink error!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_ERROR_HARDWARE, "Hardware error!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_ERROR_FILE, "File error!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_NO_PAPER, "No papers!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_NO_INK, "No ink!", "PictBridge");

    ADD_APPLICATION_STRING2(STR_ID_PICT_PRINTER_BUSY, "Printer busy!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_PRINTER_REMOVED, "Printer not connected!", "PictBridge");
#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    ADD_APPLICATION_STRING2(STR_ID_PICT_PRINTER_CONNECTED, "Printer connected!", "PictBridge");
#endif

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    ADD_APPLICATION_STRING2(STR_ID_PICT_MAX_FILES, "Max printable files: ", "PictBridge");
#endif

    ADD_APPLICATION_STRING2(STR_ID_PICT_X_COORDINATE, "Origin X coordinate", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_Y_COORDINATE, "Origin Y coordinate", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_X_ARIX, "Cropping width", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_Y_ARIX, "Cropping height", "PictBridge");

    ADD_APPLICATION_STRING2(STR_ID_PICT_CONNECT_TO_PC, "Connected to PC!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_INCOMPATIBLE_FILE, "Fail to open file!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_FILE_DELETED, "Print file deleted!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_INDEX_ALL, "All", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_CMD_NOT_EXECUTED, "Command not executed!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_PICT_USB_RESET, "USB reset!", "PictBridge");
    ADD_APPLICATION_STRING2(STR_ID_INVALID_JPG_FILE, "Invalid JPG file!", "PictBridge");

    ADD_APPLICATION_IMAGE2(IMG_ID_PICT_PRINTING, CUST_IMG_PATH"\\\\MAINLCD\\\\Bluetooth\\\\BPP\\\\BPP_PRINT.gif","PictBridge");
    ADD_APPLICATION_IMAGE2(IMG_ID_PICT_LAYOUT1, CUST_IMG_PATH"\\\\MAINLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt1.gif","PictBridge");
    ADD_APPLICATION_IMAGE2(IMG_ID_PICT_LAYOUT2, CUST_IMG_PATH"\\\\MAINLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt2.gif","PictBridge");
    ADD_APPLICATION_IMAGE2(IMG_ID_PICT_LAYOUT4, CUST_IMG_PATH"\\\\MAINLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt4.gif","PictBridge");
#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

} /* End of void PopulateExtDevUSBRes(void) */

#endif /* __MMI_USB_SUPPORT__ */





/***************************************************************************************************/
/*** Infrared Resource  ***/
/***************************************************************************************************/
#ifdef __MMI_IRDA_SUPPORT__

void PopulateExtDevIrDARes(void)
{
      /* String Resource */
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_TITLE,   "Infrared Setting","Infrared Setting title");
     ADD_APPLICATION_STRING2(STR_IRDA_MENU_OPEN,    "Open","Infrared Open");
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_CLOSE,  "Close","Infrared Close");
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_PERIOD, "Open 10 Minutes","Infrared Open a certain period");

#if defined(__MMI_IRDA_CARD_SUPPORT__) //Priyesh - Memory Card support
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_STORAGE, "Storage Location","Infrared Data Storage Location");
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_ACTIVATION, "Activation Menu","Infrared Activation Menu");
	ADD_APPLICATION_STRING2(STR_IRDA_STORAGE_PHONE, "Phone","Infrared Data Storage is Phone");
	ADD_APPLICATION_STRING2(STR_IRDA_STORAGE_CARD, "External Card","Infrared Data Storage is External Card");
	ADD_APPLICATION_STRING2(STR_IRDA_NO_CARD_ERROR, "No External Card Inserted","Infrared Data Storage can't be External Card");
	ADD_APPLICATION_STRING2(STR_IRDA_FILE_RECEIVED, "Infrared File(s) Received","Infrared files received");
#endif //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support

	ADD_APPLICATION_STRING2(STR_IRDA_RECV_DISK_FULL, "Disk Full, IrDA Receive Fail","Received file");
	ADD_APPLICATION_STRING2(STR_IRDA_RECV_ROOT_DIR_FULL, "Root Directory Full, IrDA Receive Fail","Root Directory Full");
	ADD_APPLICATION_STRING2(STR_IRDA_RECV_FILE_IND, "File stored at '\Received' folder","Received file");

	ADD_APPLICATION_STRING2(STR_IRDA_NOTY_RECV_FILE_BROWSE, "Browse","Received file");
	ADD_APPLICATION_STRING2(STR_IRDA_NOTY_RECV_FILE_HED, "Received","Received file");
	ADD_APPLICATION_STRING2(STR_IRDA_NOTY_RECV_FILE_TIL, "Files","Received file");

	ADD_APPLICATION_STRING2(STR_IRDA_DEV_BUSY, "IR Device Busy","Device Busy");
	ADD_APPLICATION_STRING2(STR_IRDA_SEND, "Sending","IR Device Sending");
	ADD_APPLICATION_STRING2(STR_IRDA_WRITE_FILE_FAIL, "Write File Failed","FS write failed");
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__ 
	/* shantanu -for DLT */
	ADD_APPLICATION_STRING2(STR_IRDA_THEME_FILE_RECV, "Received Theme File","Received File message");
	ADD_APPLICATION_STRING2(STR_ID_DLT_DO_YOU_WANT_TO_ACTIVATE, "Do you want to Activate Theme?","Do you want to message");
	/* shantanu -for DLT */
#endif

      /* Image Resource */
      /* Status icon is populate in Res_Gui.c */
	//ADD_APPLICATION_IMAGE2(IMG_IRDA_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\SI_IR.bmp","IrDA active icon");
	ADD_APPLICATION_IMAGE2(IMG_IRDA_MENU_TITLE, CUST_IMG_PATH"\\\\MAINLCD\\\\Irda\\\\SB_IR.pbm","IrDA menu icon");

      /*Menu Items*/
#if defined( __MMI_IRDA_SUPPORT__ )

#if !defined(__MMI_IRDA_CARD_SUPPORT__) //Priyesh - Memory Card Support
#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#else
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_MAIN, MAIN_MENU_EXTRA_MENUID, 3,
#endif
                                                         MENU_CONN_IRDA_OPEN,
                                                         MENU_CONN_IRDA_CLOSE,
                                                         MENU_CONN_IRDA_PERIOD,
	                                                    SHOW,MOVEABLEACROSSPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_TITLE, IMG_IRDA_MENU_TITLE ));
#else //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support
#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#else
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_MAIN, MAIN_MENU_EXTRA_MENUID, 2,
#endif
                                                         MENU_CONN_IRDA_ACTIVATION,
														 MENU_CONN_IRDA_STORAGE,
	                                                    SHOW,MOVEABLEACROSSPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_TITLE, IMG_IRDA_MENU_TITLE ));
#endif //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support

#if !defined(__MMI_IRDA_CARD_SUPPORT__) //Priyesh - Memory Card Support
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_OPEN, MENU_CONN_IRDA_MAIN, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_OPEN, IMG_IRDA_MENU_OPEN  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_CLOSE, MENU_CONN_IRDA_MAIN, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_CLOSE, IMG_IRDA_MENU_CLOSE  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_PERIOD, MENU_CONN_IRDA_MAIN, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_PERIOD, IMG_IRDA_MENU_PERIOD  ));
#else //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_ACTIVATION, MENU_CONN_IRDA_MAIN, 3,
                                                         MENU_CONN_IRDA_OPEN,
                                                         MENU_CONN_IRDA_CLOSE,
                                                         MENU_CONN_IRDA_PERIOD,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_ACTIVATION, IMG_IRDA_MENU_ACTIVATION ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_OPEN, MENU_CONN_IRDA_ACTIVATION, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_OPEN, IMG_IRDA_MENU_OPEN  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_CLOSE, MENU_CONN_IRDA_ACTIVATION, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_CLOSE, IMG_IRDA_MENU_CLOSE  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_PERIOD, MENU_CONN_IRDA_ACTIVATION, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_PERIOD, IMG_IRDA_MENU_PERIOD  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_STORAGE, MENU_CONN_IRDA_MAIN, 2,
                                                         MENU_CONN_IRDA_STORAGE_PHONE,
                                                         MENU_CONN_IRDA_STORAGE_CARD,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_STORAGE, IMG_IRDA_MENU_STORAGE ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_STORAGE_PHONE, MENU_CONN_IRDA_STORAGE, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_STORAGE_PHONE, IMG_IRDA_STORAGE_PHONE  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_STORAGE_CARD, MENU_CONN_IRDA_STORAGE, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_STORAGE_CARD, IMG_IRDA_STORAGE_CARD  ));
#endif //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support

#endif
}

#endif /* __MMI_IRDA_SUPPORT__ */








/***************************************************************************************************/
/*** General Bluetooth Resource  ***/
/***************************************************************************************************/
#ifdef __MMI_BT_SUPPORT__

#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
extern void PopulateExtDevHIDDRes(void);
#endif

typedef enum {
	NUM_MENU_CONN_BT_POWER,
	NUM_MENU_CONN_BT_SCH_AUDIO_DEV,
	#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
	NUM_MENU_CONN_BT_REMOTE_CONTROL,
	#endif
	NUM_MENU_CONN_BT_MYDEV,
	NUM_MENU_CONN_BT_ACT_DEV,                                 
	NUM_MENU_CONN_BT_SET,
	NUM_MENU_CONN_BT_ABOUT, 
	NUM_MENU_CONN_BT_MAX
};

typedef enum {

	NUM_MENU_BT_SET_VIS,
	NUM_MENU_BT_SET_NAME,
	NUM_MENU_BT_SET_AUTH,
	NUM_MENU_BT_SET_PATH,
    #ifdef __MMI_FTS_SUPPORT__
	NUM_MENU_BT_SET_FTP,
	#endif
#ifdef __MMI_BIP_SUPPORT__
	NUM_MENU_BT_SET_BIP,
#endif
    #ifdef __MMI_SIMAP_SUPPORT__
	NUM_MENU_BT_SET_SIMAP,
    #endif
	NUM_MENU_BT_SET_MAX
};

typedef enum
{
        NUM_MENU_FTP_FILE_OPTION_GET,
        NUM_MENU_FTP_FILE_OPTION_REFRESH,
        NUM_MENU_FTP_FILE_OPTION_DETAIL,
        NUM_MENU_FTP_FILE_OPTION_BACK_TO_ROOT_DIR,
        NUM_MENU_FTP_FILE_OPTION_DISCONNECT,
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        NUM_MENU_FTP_FILE_OPTION_ADD_TO_LIST,
        NUM_MENU_FTP_FILE_OPTION_SHOW_LIST,
        NUM_MENU_FTP_FILE_OPTION_GET_LIST_FILE, 
        NUM_MENU_FTP_FILE_OPTION_GET_ALL,
#endif
        NUM_MENU_FTP_FILE_OPTION_MAX
};

typedef enum
{
        NUM_MENU_FTP_FOLDER_OPTION_GET,
        NUM_MENU_FTP_FOLDER_OPTION_REFRESH,
        NUM_MENU_FTP_FOLDER_OPTION_DETAIL,
        NUM_MENU_FTP_FOLDER_OPTION_BACK_TO_ROOT_DIR,
        NUM_MENU_FTP_FOLDER_OPTION_DISCONNECT,
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        NUM_MENU_FTP_FOLDER_OPTION_SHOW_LIST,
        NUM_MENU_FTP_FOLDER_OPTION_GET_LIST_FILE, 
#endif
        NUM_MENU_FTP_FOLDER_OPTION_MAX
};


void PopulateExtDevBTRes(void)
{
   /* String Resource */

	ADD_APPLICATION_STRING2(STR_BT_MENU_TITLE, "Bluetooth","Bluetooth Main Menu");
	ADD_APPLICATION_STRING2(STR_BT_LSK_DISC, "Disc.","LSK");
	ADD_APPLICATION_STRING2(STR_BT_CM_SETPATH, "Swap Bluetooth Voice Path","Bluetooth Setting title");	
	/* Configure Default Headset */
	ADD_APPLICATION_STRING2(STR_BT_CONNECT_LAST_HEADSET, "Connect Default Bluetooth Headset","LSK");
	ADD_APPLICATION_STRING2(STR_BT_NO_DEFAULT_HEADSET, "No Default Bluetooth Headset","Popup string");	



	
	ADD_APPLICATION_STRING2(STR_BT_LSK_CONN, "Conn.","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_POWER, "Power","Power menu");
	ADD_APPLICATION_STRING2(STR_BT_SWITCHING, "Switching","Power menu");
	ADD_APPLICATION_STRING2(STR_BT_SWITCHED_ON, "Bluetooth Switched On","Power menu");
	ADD_APPLICATION_STRING2(STR_BT_SWITCHED_OFF, "Bluetooth Switched Off","Power menu");
	ADD_APPLICATION_STRING2(STR_BT_RELEASE_ALL_CONN, "Release All Connections","Power menu");
	ADD_APPLICATION_STRING2(STR_BT_RELEASE_DEV_CONN, "Release Device Connections","Power menu");
	ADD_APPLICATION_STRING2(STR_BT_RELEASING, "Releasing","Power menu");
	ADD_APPLICATION_STRING2(STR_BT_CON_RELEASED, "Connection Released","Power menu");
	ADD_APPLICATION_STRING2(STR_BT_SEARCHING, "Searching","Searching");
	ADD_APPLICATION_STRING2(STR_BT_SCH_AUD_DEV, "Inquiry Audio Device","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_SCH_OPP_DEV, "Inquiry Opp Device","Bluetooth Setting title");
    /* Put Inquiry NEW Device at the first item of Mydev menu */
	ADD_APPLICATION_STRING2(STR_BT_SCH_ALL_DEV, "Inquiry New Device","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_SCH_RESULT, "Discovered Device","Discovered Device");
	ADD_APPLICATION_STRING2(STR_BT_INQUIRY_STOP, "Stop Searching","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_INQUIRY_STOPPING, "Stop Searching","Discovered Device");
	ADD_APPLICATION_STRING2(STR_BT_BOND, "Bond","Bond");
	ADD_APPLICATION_STRING2(STR_BT_BONDING, "Bonding","Bonding");
	ADD_APPLICATION_STRING2(STR_BT_BOND_FAILED, "Bonding Failed","Bonding Failed");
	ADD_APPLICATION_STRING2(STR_BT_SEND, "Send","Bond");
	ADD_APPLICATION_STRING2(STR_BT_ENTER_PASSCODE, "Passcode", "Passcode");
	ADD_APPLICATION_STRING2(STR_BT_PAIR_REQ, "Pair","Pair");
	ADD_APPLICATION_STRING2(STR_BT_PAIR_FAILED, "Pairing Failed","Pairing Failed");
	ADD_APPLICATION_STRING2(STR_BT_PAIR_SUCCEED, "Paired","Paired");
	ADD_APPLICATION_STRING2(STR_BT_START_PAIRING, "Pairing", "Pairing");
	ADD_APPLICATION_STRING2(STR_BT_CONNECT, "Connect","Connect");
	ADD_APPLICATION_STRING2(STR_BT_CONNECT_AND_SET_AS_DEFAULT_HF, "Connect and Set As Default Handsfree","Connect");
	ADD_APPLICATION_STRING2(STR_BT_ACCEPT_CONNECT_FROM, "Accept Connect From","Accept Connect From");
	ADD_APPLICATION_STRING2(STR_BT_CONNECTING, "Connecting", "Connecting");
	ADD_APPLICATION_STRING2(STR_BT_DISCONNECT, "Disconnect","Disconnect");
	ADD_APPLICATION_STRING2(STR_BT_DISCONNECTING, "Disconnecting", "Disconnecting");
	ADD_APPLICATION_STRING2(STR_BT_REFRESH, "Refresh", "Connecting");
	ADD_APPLICATION_STRING2(STR_BT_REFRESH_SERVICE_LIST, "Refresh Service List","Disconnect");
	ADD_APPLICATION_STRING2(STR_BT_REFRESHING, "Refreshing", "Disconnecting");
	ADD_APPLICATION_STRING2(STR_BT_DELETE, "Delete", "Delete");
	ADD_APPLICATION_STRING2(STR_BT_DELETING, "Deleting", "Deleting");
	ADD_APPLICATION_STRING2(STR_BT_DELETED, "Deleted", "Deleted");

	
	ADD_APPLICATION_STRING2(STR_BT_MYDEVICE, "My Device","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_CONN, "Connect","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_DISCONN, "Disconnect","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_CONNECTED_PROF, "Connected Service","Bluetooth Setting title");
    /* Configure Default Headset */
    ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_SET_DEFAULT_HS, "Set As Default Handsfree Headset","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_REN, "Rename","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_AUTH, "Authorisation","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_DEL, "Delete","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_DEL_ALL, "Delete All","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_SUP_SER, "Service List","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_MYDEV_OPT_SCH, "Inquiry New Device","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_ACT_DEV, "Active Device","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET, "Setting","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET_VIS, "Visibility","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET_NAME, "Change Device Name","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET_AUTH, "Authentication","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET_AUDIO_PATH, "Audio Path","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET_AUDIO_PATH_PHONE, "Leave in Phone","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET_AUDIO_PATH_HF, "Forward to BT Headset","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET_FTP, "FTP","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_SET_SIMAP, "Activate SIMAP", "Bluetooth Setting title");    
	ADD_APPLICATION_STRING2(STR_BT_ABOUT, "About","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_BD_NAME, "Device Name:","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_SERVICE, "Supported Service:","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_BD_ADDR, "BD Addr:","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_CONN_ED, "Connected","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DISCON_ED, "Disconnected","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_ESTAB, "Established","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_RELEASE, "Released","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AUDIO_SCO_CON, "Transfer Voice to BT Headset","Transfer Voice to BT Headset");
	ADD_APPLICATION_STRING2(STR_BT_AUDIO_SCO_DISCON, "Transfer Voice Back to Phone","Transfer Voice Back to Phone");
	ADD_APPLICATION_STRING2(STR_BT_PROF_SPP, "SPP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_LAP, "LAP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_DUN, "DUN Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_SYNC, "SYNC Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_OPP, "OPP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_FTP, "FTP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_FAX, "FAX Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_CTP, "CTP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_AUDIO_SOURCE, "AUDIO_SOURCE Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_AUDIO_SINK, "AUDIO_SINK Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_AVRCP_T, "AVRCP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_A2DP, "A2DP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_AVRCP, "AVRCP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_ICP, "ICP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_PAN_PANU, "PAN_PANU Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_PAN_NAP, "PAN_NAP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_PAN_GN, "PAN_GN Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_DIRECT_PRINTING, "BPP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_OBEX_IMAGING, "BIP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_OBEX_IMAGING_RESPONDER, "BIP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_HF, "Handsfree Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_HS, "Headset Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_BASIC_PRINTING, "BPP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_HID, "HID Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_SAP, "SAP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_PBAP, "PBAP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_OBEX_BPPS, "BPP Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROF_UNKNOWN, "Unknown Profile","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_NOT_READY, "Initializing Bluetooth Now, Wait a Moment !","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_HARDWARE_ERROR, "Hardware Error!","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEV_BUSY, "Device Busy","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_FAILED, "Failed","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_NOT_SUPPORT, "Not Support!","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_NOT_ALLOW, "Not Allow!","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_NO_SUPPORTED_PROFILE, "Service List Empty","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PWR_ON_CNF, "Power on Bluetooth First ?","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DISCONN_ALL_CONN_CNF, "Release All Connections First ?", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DISCONN_DEV_CONN_CNF, "Release Device Connections First ?", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_TRY_HFP_FIRST, "Try to connect with HFP first!", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_ONE_HEADSET_ALREADY_CONNECTED, "Already Connected with One Bluetooth Headset!", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PAIRED_DEV_FULL, "Paired Device Full, Delete Some Devices First!", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROHIBIT_BY_A2DP, "This Service is Prohibited by A2DP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROHIBIT_VIS_BY_A2DP, "Prohibited by A2DP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_SWITCH_SPEECH_PATH, "Switch Speech To", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_WAIT_PAIR_RESULT, "Waiting for Pairing Result", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_WAIT_INQUIRY_FINISH, "Cancelling Inquiry, Please Wait!", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DISABLE_VISIBILITY, "Set visibility to be off", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_ENABLE_VISIBILITY, "Set visibility to be ON", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_OPERATION_NOT_ALLOWED_DIS_HFP_FIRST, "Operation Not Allowed, Please Disconnect HFP First!", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_SET_NAME_LENGTH_LIMITATION, "Cannot be NULL!","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_TRUNCATE_NAME_FOR_DIFF_CHAR_SET, "Truncated Device Name !","Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROHIBIT_VIS_BY_MAX_ACL, "Prohibited by max links reached", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_PROHIBIT_BY_SIMAP, "Prohibited by SIMAP, Shall Deactivate SIMAP First!", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_ACTIVATING, "Activating", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_DEACTIVATING, "Deactivating", "Bluetooth Setting title");    
	ADD_APPLICATION_STRING2(STR_BT_CANCELLING, "Cancelling", "Bluetooth global cancelling notice");

	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CONTROL, "Remote Control", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CTRL_LAST_DEV, "Last Device", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CTRL_NO_LAST_DEV_INFO, "No Last Device Information", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CTRL_PAIRED_DEV, "Paired Device", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CTRL_DESKTOP, "Desktop", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CTRL_MEDIA_PLAYER, "Media Player", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CTRL_PRESENTER, "Presenter", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM, "Exit Remote Control ?", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CTRL_KEYBOARD, "Keyboard", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_UNSUPPORTED_KEY_CMD, "Please type 0~9 or A~Z !", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_REMOTE_CTRL_CONN_AUTH, "Accept HID request from ","Accept HID connect request string");



#ifdef __MMI_AVRCP_DEBUG__
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_UNIT_COMMAND, "UNIT COMMAND", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_SUBUNIT_COMMAND, "SUBUNIT COMMAND", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_SELECT, "SELECT", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_UP, "UP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_DOWN, "DOWN", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_LEFT, "LEFT", "Bluetooth Setting title");	
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_RIGHT, "RIGHT", "Bluetooth Setting title");	
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_RIGHT_UP, "RIGHT_UP", "Bluetooth Setting title");	
    ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_RIGHT_DOWN, "RIGHT_DOWN", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_LEFT_UP, "LEFT_UP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_LEFT_DOWN, "LEFT_DOWN", "Bluetooth Setting title");	
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_ROOT_MENU, "ROOT MENU", "Bluetooth Setting title");	
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_SETUP, "SETUP MENU", "Bluetooth Setting title");	
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_CONTENTS, "CONTENTS MENU", "Bluetooth Setting title");	
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_FAVORITE, "FAVORITE MENU", "Bluetooth Setting title");	
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_EXIT, "EXIT", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_0, "0", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_1, "1", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_2, "2", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_3, "3", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_4, "4", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_5, "5", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_6, "6", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_7, "7", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_8, "8", "Bluetooth Setting title");	
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_9, "9", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_DOT, "DOT", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_ENTER, "ENTER", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_CLEAR, "CLEAR", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_CHANNEL_UP, "CHANNEL_UP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_CHANNEL_DOWN, "CHANNEL_DOWN", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_PREVIOUS_CHANNEL, "PREVIOUS_CHANNEL", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_SOUND_SELECT, "SOUND_SELECT", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_INPUT_SELECT, "INPUT_SELECT", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_DISPLAY_INFO, "DISPLAY_INFO", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_HELP, "HELP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_PAGE_UP, "PAGE_UP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_PAGE_DOWN, "PAGE_DOWN", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_POWER, "POWER", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_VOLUME_UP, "VOLUME_UP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_VOLUME_DOWN, "VOLUME_DOWN", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_MUTE, "MUTE", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_PLAY, "PLAY", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_STOP, "STOP", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_PAUSE, "PAUSE", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_RECORD, "RECORD", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_REWIND, "REWIND", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_FAST_FORWARD, "FAST_FORWARD", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_EJECT, "EJECT", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_FORWARD, "FORWARD", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_BACKWARD, "BACKWARD", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_ANGLE, "ANGLE", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_SUBPICTURE, "SUBPICTURE", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_F1, "F1", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_F2, "F2", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_F3, "F3", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_F4, "F4", "Bluetooth Setting title");
	ADD_APPLICATION_STRING2(STR_BT_AVRCP_CMD_F5, "F5", "Bluetooth Setting title");
#endif /* __MMI_AVRCP_DEBUG__ */

	  
#ifdef __GOEP_AUTH__
	ADD_APPLICATION_STRING2(STR_OBEX_INPUT_AUTHPWD, "Authentication Password", "Authentication Password");
#endif /* GOEP_AUTH_TEST */


   /* Image Resource */
   /* Status icon is populate in Res_Gui.c */
	ADD_APPLICATION_IMAGE2(IMG_BT_MENU_TITLE, CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\SB_BT.pbm","Bluetooth menu icon");
	ADD_APPLICATION_IMAGE2(IMG_BT_SCH_TITLE, CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_Search","Bluetooth menu icon");

	ADD_APPLICATION_IMAGE2(IMG_BT_DEV_MOB, CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_MOB.pbm","Bluetooth menu icon");
	ADD_APPLICATION_IMAGE2(IMG_BT_DEV_LAP, CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_LAP.pbm","Bluetooth menu icon");
	ADD_APPLICATION_IMAGE2(IMG_BT_DEV_EAR, CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_EAR.pbm","Bluetooth menu icon");
	ADD_APPLICATION_IMAGE2(IMG_BT_DEV_OTHER, CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_other.pbm","Bluetooth menu icon");
	ADD_APPLICATION_IMAGE2(IMG_BT_DEV_PRT, CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_print.pbm","Bluetooth menu icon");


   /*Menu Items*/
	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_MAIN, 
#ifdef __MMI_VERSION_2__
		MAIN_MENU_EXTRA_MENUID, 
#else
#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#else
		MAIN_MENU_SERVICES_MENUID, 
#endif
#endif
		NUM_MENU_CONN_BT_MAX,
        MENU_CONN_BT_POWER,
        MENU_CONN_BT_SCH_AUDIO_DEV,
#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
        MENU_CONN_BT_REMOTE_CONTROL,
#endif
        MENU_CONN_BT_MYDEV,
        MENU_CONN_BT_ACT_DEV,                                 
        MENU_CONN_BT_SET,
        MENU_CONN_BT_ABOUT, 
	    SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,DISP_LIST,
	    STR_BT_MENU_TITLE, IMG_BT_MENU_TITLE ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_POWER, MENU_CONN_BT_MAIN, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_POWER, IMG_BT_POWER  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SCH_AUDIO_DEV, MENU_CONN_BT_MAIN, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_SCH_AUD_DEV, IMG_BT_SCH_AUD_DEV  ));

	#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_REMOTE_CONTROL, MENU_CONN_BT_MAIN, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                          STR_BT_REMOTE_CONTROL, IMG_BT_REMOTE_CONTROL  ));

	#endif




	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_MYDEV, MENU_CONN_BT_MAIN, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_MYDEVICE, IMG_BT_MYDEV  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_ACT_DEV, MENU_CONN_BT_MAIN, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_ACT_DEV, IMG_BT_ACT_DEV  ));


	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET, MENU_CONN_BT_MAIN,
                                            NUM_MENU_BT_SET_MAX,
											MENU_CONN_BT_SET_VIS,
											MENU_CONN_BT_SET_NAME,
											MENU_CONN_BT_SET_AUTH,
											MENU_CONN_BT_SET_AUDIO_PATH,
											#ifdef __MMI_FTS_SUPPORT__
											MENU_CONN_FTP_SETTING,
										        #endif										
                                            #ifdef __MMI_BIP_SUPPORT__
                                            MENU_CONN_BIP_SETTING,
                                            #endif
                                            #ifdef __MMI_SIMAP_SUPPORT__
                                            MENU_CONN_BT_SET_SIMAP,
                                            #endif
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_DEV_SET, IMG_BT_SET  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET_VIS, MENU_CONN_BT_SET, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_DEV_SET_VIS, IMG_BT_SET_VIS  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET_NAME, MENU_CONN_BT_SET, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_DEV_SET_NAME, IMG_BT_SET_NAME  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET_AUTH, MENU_CONN_BT_SET, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_DEV_SET_AUTH, IMG_BT_SET_AUTH  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET_AUDIO_PATH, MENU_CONN_BT_SET, 2,
											MENU_CONN_BT_SET_AUDIO_PATH_PHONE,
											MENU_CONN_BT_SET_AUDIO_PATH_HF,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_DEV_SET_AUDIO_PATH, IMG_BT_SET_AUDIO_PATH  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET_AUDIO_PATH_PHONE, MENU_CONN_BT_SET_AUDIO_PATH, 0,
	                              SHOW,NONMOVEABLE,DISP_LIST,
		                           STR_BT_DEV_SET_AUDIO_PATH_PHONE, IMG_BT_SET_AUDIO_PATH_PHONE  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET_AUDIO_PATH_HF, MENU_CONN_BT_SET_AUDIO_PATH, 0,
	                              SHOW,NONMOVEABLE,DISP_LIST,
		                           STR_BT_DEV_SET_AUDIO_PATH_HF, IMG_BT_SET_AUDIO_PATH_HF  ));

/*
	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET_FTS, MENU_CONN_BT_SET, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_SET_FTS, IMG_BT_SET_FTS  ));
*/
	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_SET_SIMAP, MENU_CONN_BT_SET, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_DEV_SET_SIMAP, IMG_BT_SET_SIMAP  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BT_ABOUT, MENU_CONN_BT_MAIN, 0,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BT_ABOUT, IMG_BT_ABOUT  ));

    #if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
    PopulateExtDevHIDDRes();
    #endif

}


/***************************************************************************************************/
/*** FTP OPP Resources ***/
/***************************************************************************************************/
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)

void PopulateExtDevFTPRes(void)
{
    /* String Resource */
#ifdef __MMI_FTS_SUPPORT__
    
	ADD_APPLICATION_STRING2(STR_FTP_SETTING, "FTP Settings","FTP Setting string");
	ADD_APPLICATION_STRING2(STR_FTP_SHARED_FOLDER, "Shared Folder","Shared Folder string");
	ADD_APPLICATION_STRING2(STR_FTP_ACCESS_RIGHT, "Access Right","Access Right string");

	ADD_APPLICATION_STRING2(STR_FTP_OPTION_FULLY_CONTROL, "Fully Control","Fully Control string");
	ADD_APPLICATION_STRING2(STR_FTP_OPTION_READ_ONLY, "Read Only","Read Only string");
	ADD_APPLICATION_STRING2(STR_FTP_CON_AUTH, "Accept FTP request from ","Accept FTP connect request string");
	ADD_APPLICATION_STRING2(STR_FTP_RECV_FILE_IND, "File stored at shared folder","Received file");
	ADD_APPLICATION_STRING2(STR_FTP_SERVER_BUSY, "FTP server is busy, please try again later","FTP server is busy");
       ADD_APPLICATION_STRING2(STR_FTP_DISCONN_CLIENT, "Disconnect client first!","Disconnect client first");
    ADD_APPLICATION_STRING2(STR_FTP_QUESTION_MARK, "?","Question mark");

       /* FTP Server Setting Menu */
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_SETTING, 
											MENU_CONN_BT_SET, 
											2,
                                 MENU_CONN_FTP_SHARED_FOLDER,
                                 MENU_CONN_FTP_ACCESS_RIGHT,/* Should be the last one */
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_FTP_SETTING, IMG_FTP_SETTING_TITLE ));
   /* FTP Server Setting Shared Folder */
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_SHARED_FOLDER, MENU_CONN_FTP_SETTING, 2,
	                                                    MENU_FMGR_SELECT_DONE,
	                                                    MENU_FMGR_GEN_OPTION_OPEN,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_FTP_SHARED_FOLDER, IMG_FTP_SHARED_FOLDER));

   /* FTP Server Setting Access Right */
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_ACCESS_RIGHT, MENU_CONN_FTP_SETTING, 2,
	                                                    MENU_CONN_FTP_ACCESS_RIGHT_OPTION_FULLY_CONTROL,
	                                                    MENU_CONN_FTP_ACCESS_RIGHT_OPTION_READ_ONLY,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_FTP_ACCESS_RIGHT, IMG_FTP_ACCESS_RIGHT));

	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_ACCESS_RIGHT_OPTION_FULLY_CONTROL, MENU_CONN_FTP_ACCESS_RIGHT, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_FTP_OPTION_FULLY_CONTROL, 0  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_ACCESS_RIGHT_OPTION_READ_ONLY, MENU_CONN_FTP_ACCESS_RIGHT, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_FTP_OPTION_READ_ONLY, 0  ));
#endif

#ifdef __MMI_FTC_SUPPORT__
	ADD_APPLICATION_STRING2(STR_FTP_FILE_BROWSER, "File Browser","File Browser string");
	ADD_APPLICATION_STRING2(STR_FTP_OPTION_GET, "Get","Get File string");
	ADD_APPLICATION_STRING2(STR_FTP_OPTION_BACK_TO_ROOT_DIR, "Back to Root Dir","Back to Root Dir string");
	ADD_APPLICATION_STRING2(STR_FTP_CON_EXIT, "Exit File Browser?","Confirm disconnection of current FTP session");
	ADD_APPLICATION_STRING2(STR_FTP_NOTY_RECV_FILE_BROWSE, "Browse","Received file");
	ADD_APPLICATION_STRING2(STR_FTP_NOTY_RECV_FILE_TIL, "files","Received file");
       ADD_APPLICATION_STRING2(STR_FTP_NOTY_RECV_FILE_TIL_SINGLE, "file","Received file");    
	ADD_APPLICATION_STRING2(STR_FTP_DETAIL_DATE, "Date:","Modified Date");
	ADD_APPLICATION_STRING2(STR_FTP_DETAIL_SIZE, "Size:","File Size");
	ADD_APPLICATION_STRING2(STR_FTP_NOTY_SHOW_PARTIAL_CONTENT_ONLY, "Display partial content only","Display partial content only");
       ADD_APPLICATION_STRING2(STR_FTPC_NOTIFY_BROWSE_FILES_FAILED, "Browse files failed","Browsing files failed");
       ADD_APPLICATION_STRING2(STR_FTPC_NOTIFY_GOEP_STATUS_BUSY, "Connection is busy","Conetion failed");
       ADD_APPLICATION_STRING2(STR_FTPC_NOTIFY_WORK_FOLDER_NO_EXIST, "FTP work folder is not existed","Create ftp working folder failed");
       ADD_APPLICATION_STRING2(STR_FTP_DEV_BUSY, "FTP service busy","Device Busy");
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
       ADD_APPLICATION_STRING2(STR_FTP_OPTION_ADD_TO_LIST, "Add to list","Add to download list string");
       ADD_APPLICATION_STRING2(STR_FTP_OPTION_SHOW_LIST, "Show download list","Show download list string");
       ADD_APPLICATION_STRING2(STR_FTP_OPTION_GET_LIST, "Get list files","Get list files string");
       ADD_APPLICATION_STRING2(STR_FTP_OPTION_GET_ALL, "Get all files","Get all files in file browser string");
       ADD_APPLICATION_STRING2(STR_FTP_DOWNLOAD_LIST, "Download List","Download List string");
       ADD_APPLICATION_STRING2(STR_FTP_LIST_OPTION_UP, "Up","Download List option string");
       ADD_APPLICATION_STRING2(STR_FTP_LIST_OPTION_DOWN, "Down","Download List option string");
       ADD_APPLICATION_STRING2(STR_FTP_LIST_ARRIVE_MAX, "List have arrived the max","List restrict string");
       ADD_APPLICATION_STRING2(STR_FTP_LIST_IS_EMPTY, "List is empty","List empty string");
       ADD_APPLICATION_STRING2(STR_FTP_LIST_FIRST_FILE, "The file is already the first file","List file first prompt string");
       ADD_APPLICATION_STRING2(STR_FTP_LIST_LAST_FILE, "The file is already the last file","List file last prompt string");
       ADD_APPLICATION_STRING2(STR_FTP_LIST_FILE_DEL_CONFIRM, "Delete?","List file delete confirm string");
       ADD_APPLICATION_STRING2(STR_FTP_LIST_ALL_FILE_DEL_CONFIRM, "Delete all?","Delete all files in list confirm string");
       ADD_APPLICATION_STRING2(STR_FTP_NO_FILE_CURR_FOLDER, "There is no file in current path","Current path no file string");
       ADD_APPLICATION_STRING2(STR_FTP_GET_ALL_CONFIRM_HEAD, "Get all the","Get all current pah files string");
       ADD_APPLICATION_STRING2(STR_FTP_GET_ALL_CONFIRM_TAIL, "file?","Get all current pah files string");
       ADD_APPLICATION_STRING2(STR_FTP_NO_FILE_IN_LIST, "There is no file in list","Download list no file string");
       ADD_APPLICATION_STRING2(STR_FTP_CLEAR_LIST, "It will clean the list, continue?","Clean list string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE, "Current","Receiving list file string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE_ALREADY_IN_LIST, "The file is already in list","File already in list string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE1, "file","error pop up file string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE_UNFINISHED, "file unfinished","error pop up file string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE_PREFIX, " ","error pop up file string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE_1ST, "st ","1st error pop up file string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE_2ND, "nd ","error pop up file string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE_3RD, "rd ","error pop up file string");
       ADD_APPLICATION_STRING2(STR_FTP_FILE_TH, "th ","error pop up file string");
       
#endif /*__MMI_FTC_MULTIPULL_SUPPORT__*/

    

   /* FTP Client File Browser folder/file option*/
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_FILE_OPTION, 
                                                           0, 
                                                           NUM_MENU_FTP_FILE_OPTION_MAX,
	                                                    MENU_CONN_FTP_FILE_OPTION_GET,
	                                                    MENU_CONN_FTP_GEN_OPTION_REFRESH,
	                                                    MENU_CONN_FTP_GEN_OPTION_DETAIL,
	                                                    MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR,
	                                                    MENU_CONN_FTP_GEN_OPTION_DISCONNECT,
                                                           #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
                                                           MENU_CONN_FTP_FILE_OPTION_ADD_TO_LIST,
                                                           MENU_CONN_FTP_GEN_OPTION_SHOW_LIST,
                                                           MENU_CONN_FTP_GEN_OPTION_GET_LIST_FILE, 
                                                           MENU_CONN_FTP_FILE_OPTION_GET_ALL,
                                                           #endif /*__MMI_FTC_MULTIPULL_SUPPORT__*/
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_GLOBAL_OPTIONS, 0  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_FOLDER_OPTION,
                                                           0,
                                                           NUM_MENU_FTP_FOLDER_OPTION_MAX,
	                                                    MENU_CONN_FTP_FOLDER_OPTION_OPEN,
	                                                    MENU_CONN_FTP_GEN_OPTION_REFRESH,
	                                                    MENU_CONN_FTP_GEN_OPTION_DETAIL,
	                                                    MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR,
	                                                    MENU_CONN_FTP_GEN_OPTION_DISCONNECT,
                                                           #ifdef __MMI_FTC_MULTIPULL_SUPPORT__ 
	                                                    MENU_CONN_FTP_GEN_OPTION_SHOW_LIST,
                                                           MENU_CONN_FTP_GEN_OPTION_GET_LIST_FILE, 
                                                           #endif /*__MMI_FTC_MULTIPULL_SUPPORT__*/
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_GLOBAL_OPTIONS, 0  ));
	
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_EMPTY_FOLDER_OPTION, 0, 3,
	                                                    MENU_CONN_FTP_GEN_OPTION_REFRESH,
	                                                    MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR,
	                                                    MENU_CONN_FTP_GEN_OPTION_DISCONNECT,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_GLOBAL_OPTIONS, 0  ));
	
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_LIST_OPTION, 0, 6,
                                                           MENU_CONN_FTP_GEN_OPTION_GET_LIST_FILE, 
                                                           MENU_CONN_FTP_GEN_OPTION_DETAIL,
                                                           MENU_CONN_FTP_LIST_OPTION_UP, 
                                                           MENU_CONN_FTP_LIST_OPTION_DOWN,
                                                           MENU_CONN_FTP_LIST_OPTION_DELETE, 
                                                           MENU_CONN_FTP_LIST_OPTION_DELETE_ALL,
                                                           SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_GLOBAL_OPTIONS, 0  ));
   
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_LIST_OPTION_UP, 0, 0,
                                                           SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_FTP_LIST_OPTION_UP, 0  ));
   
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_LIST_OPTION_DOWN, 0, 0,
                                                           SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_FTP_LIST_OPTION_DOWN, 0  ));
   
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_LIST_OPTION_DELETE, 0, 0,
                                                           SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_GLOBAL_DELETE, 0  ));
   
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_LIST_OPTION_DELETE_ALL, 0, 0,
                                                           SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_GLOBAL_DELETE_ALL, 0  ));
   
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_FILE_OPTION_ADD_TO_LIST, 0, 0,
                                                        SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_FTP_OPTION_ADD_TO_LIST, 0  ));
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_GEN_OPTION_SHOW_LIST, 0, 0,
                                                        SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_FTP_OPTION_SHOW_LIST, 0  ));
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_GEN_OPTION_GET_LIST_FILE, 0, 0,
                                                        SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_FTP_OPTION_GET_LIST, 0  ));
       ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_FILE_OPTION_GET_ALL, 0, 0,
                                                        SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
       	                                                 STR_FTP_OPTION_GET_ALL, 0  ));
#endif /*__MMI_FTC_MULTIPULL_SUPPORT__*/

	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_FILE_OPTION_GET, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_FTP_OPTION_GET, 0  ));
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_FOLDER_OPTION_OPEN, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_GLOBAL_OPEN, 0  ));
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_GEN_OPTION_REFRESH, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_GLOBAL_REFRESH, 0  ));
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_GEN_OPTION_DETAIL, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_GLOBAL_DETAILS, 0  ));
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_FTP_OPTION_BACK_TO_ROOT_DIR, 0  ));
	ADD_APPLICATION_MENUITEM((MENU_CONN_FTP_GEN_OPTION_DISCONNECT, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_GLOBAL_DISCONNECT, 0  ));
#endif

/* General */
	ADD_APPLICATION_STRING2(STR_FTP_CON_DISCONNECTED, "FTP connection disconnected","FTP connection disconnected string");
	ADD_APPLICATION_STRING2(STR_FTP_RECV_DISK_FULL, "Disk Full", "Disk Full");
	ADD_APPLICATION_STRING2(STR_FTP_WRITE_FILE_FAIL, "Write File Failed","FS write failed");
}

#endif /* __MMI_FTS_SUPPORT__ || __MMI_FTC_SUPPORT__ */


#ifdef __MMI_BIP_SUPPORT__

void PopulateExtDevBIPRes(void)
{
    /* String Resource */
    
	ADD_APPLICATION_STRING2(STR_BIP_SETTING, "BIP Setting","BIP Setting string");
	ADD_APPLICATION_STRING2(STR_BIP_SHARED_FOLDER, "Shared Folder","Shared Folder string");

	ADD_APPLICATION_STRING2(STR_BIP_CON_AUTH, "Accept BIP request from ","Accept BIP connect request string");
	ADD_APPLICATION_STRING2(STR_BIP_RECV_FILE_IND, "Image stored at ","Received file");
	ADD_APPLICATION_STRING2(STR_BIP_SERVER_BUSY, "BIP responder is busy","BIP responder is busy");

	ADD_APPLICATION_STRING2(STR_BIP_IMGLIST_BROWSER, "Image Browser","Image list browser string");
	ADD_APPLICATION_STRING2(STR_BIP_OPTION_GET, "Get Selected Images","Get image string");
	ADD_APPLICATION_STRING2(STR_BIP_OPTION_GET_ALL, "Get All Images","Get All File string");
	ADD_APPLICATION_STRING2(STR_BIP_OPTION_DETAIL, "Image Detail","Image detailed info string");
	ADD_APPLICATION_STRING2(STR_BIP_OPTION_GET_THM, "Preview thumbnail","Image detailed info string");
	ADD_APPLICATION_STRING2(STR_BIP_OPTION_REFRESH, "Refresh","Refresh");
	ADD_APPLICATION_STRING2(STR_BIP_OPTION_DISCONNECT, "Exit Image Browser","Disconnect string");
	ADD_APPLICATION_STRING2(STR_BIP_STATUS_DISCONNECTING, "Disconnecting","Disconnecting string");
	ADD_APPLICATION_STRING2(STR_BIP_STATUS_CONNECTING, "Connecting","Connecting string");
	ADD_APPLICATION_STRING2(STR_BIP_STATUS_GETTING, "Getting","Getting string");
	ADD_APPLICATION_STRING2(STR_BIP_STATUS_GETTING_IMGPROP, "Getting image property","Receiving string");
	ADD_APPLICATION_STRING2(STR_BIP_STATUS_GETTING_IMGTHM, "Getting thumbnail","Receiving string");
	ADD_APPLICATION_STRING2(STR_BIP_STATUS_RECEIVING, "Receiving","Receiving string");
	ADD_APPLICATION_STRING2(STR_BIP_STATUS_SENDING, "Sending","Sending string");
	ADD_APPLICATION_STRING2(STR_BIP_STATUS_ABORTING, "Aborting","Aborting string");
	ADD_APPLICATION_STRING2(STR_BIP_CON_EXIT, "Exit Image Browser?","Confirm disconnection of current BIP session");
	ADD_APPLICATION_STRING2(STR_BIP_DETAIL_ENCODING, "Encoding","Image Encoding");
	ADD_APPLICATION_STRING2(STR_BIP_DETAIL_PIXEL, "Pixel","Image Pixel");
	ADD_APPLICATION_STRING2(STR_BIP_DETAIL_SIZE, "Size","Image Size");
	ADD_APPLICATION_STRING2(STR_BIP_DETAIL_NAME, "Name","Image Name");
	ADD_APPLICATION_STRING2(STR_BIP_EXIT_IMGBROWSER, "Exit","Exit image browser");
	ADD_APPLICATION_STRING2(STR_BIP_REFRESH_IMGLIST, "Refreshing Image List","Refreshing Image List");

	ADD_APPLICATION_STRING2(STR_BIP_CON_DISCONNECTED, "Disconnected","BIP connection disconnected string");
	ADD_APPLICATION_STRING2(STR_BIP_RECV_DISK_FULL, "Disk Full", "Disk Full");
	ADD_APPLICATION_STRING2(STR_BIP_RECV_ROOT_DIR_FULL, "Root Dir Full", "Root Dir Full");
	ADD_APPLICATION_STRING2(STR_BIP_OPEN_FILE_FAIL, "Open File Failed","FS open failed");
	ADD_APPLICATION_STRING2(STR_BIP_WRITE_FILE_FAIL, "Write File Failed","FS write failed");
	ADD_APPLICATION_STRING2(STR_BIP_READ_FILE_FAIL, "Read File Failed","FS read failed");
	ADD_APPLICATION_STRING2(STR_BIP_XML_GEN_FAIL, "Xml generating Failed","Xml generating failed");

   ADD_APPLICATION_STRING2(STR_BIP_NOTY_RECV_FILE_BROWSE, "Browse","Received image");
   ADD_APPLICATION_STRING2(STR_BIP_NOTY_RECV_FILE_HED, "Received","Received image");
   ADD_APPLICATION_STRING2(STR_BIP_NOTY_RECV_FILE_TIL, "Images","Received image");
   ADD_APPLICATION_STRING2(STR_BIP_NOTY_RECV_FILE_SINGLE_TIL, "Image","Received image");

   ADD_APPLICATION_STRING2(STR_BIP_DEV_BUSY, "Bluetooth Device Busy","Device Busy");
   ADD_APPLICATION_STRING2(STR_BIP_NOTSUPPORT_BT_PUSH, "No Service Availible!","Not support BT PUSH");
   ADD_APPLICATION_STRING2(STR_BIP_CONNECTING_CLIENT, "Disconnect the BIP connection first!","Client is connecting");
   ADD_APPLICATION_STRING2(STR_BIP_DRM_FORBIDDEN, "DRM Forbidden!","DRM Forbidden");
   ADD_APPLICATION_STRING2(STR_BIP_GET_CUR_IMG, "Get","Get current image");
   ADD_APPLICATION_STRING2(STR_BIP_ADDTO_GETLIST, "Select","Select current image into download list");   
   ADD_APPLICATION_STRING2(STR_BIP_REMOVEFROM_GETLIST, "Unselect","remove current image from download list");

   ADD_APPLICATION_STRING2(STR_ID_BT_BIP, "BT BIP","BT BIP Profile");
    
   /*  Setting Menu */
	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_SETTING, 
											MENU_CONN_BT_SET, 
											1,
                                 MENU_CONN_BIP_SHARED_FOLDER,
	                              SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                           STR_BIP_SETTING, IMG_FTP_SETTING_TITLE ));
   /* Setting Shared Folder */
	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_SHARED_FOLDER, MENU_CONN_BIP_SETTING, 2,
                                                        MENU_FMGR_SELECT_DONE,
	                                                    MENU_FMGR_GEN_OPTION_OPEN,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_BIP_SHARED_FOLDER, 0));

   /* option*/
   
	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_IMGLIST_OPTION, 
                                                           0, 
                                                           6,
	                                                    MENU_CONN_BIP_OPTION_GET,
                                                        MENU_CONN_BIP_OPTION_IMG_DETAIL,
                                                        MENU_CONN_BIP_OPTION_GET_THM,
                                                        MENU_CONN_BIP_OPTION_GET_ALL,
                                                        MENU_CONN_BIP_OPTION_REFRESH,
	                                                    MENU_CONN_BIP_OPTION_DISCONNECT,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_GLOBAL_OPTIONS, 0  ));
 		                                                 

	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_OPTION_GET, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_BIP_OPTION_GET, 0  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_OPTION_GET_ALL, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_BIP_OPTION_GET_ALL, 0  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_OPTION_IMG_DETAIL, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_BIP_OPTION_DETAIL, 0  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_OPTION_GET_THM, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_BIP_OPTION_GET_THM, 0  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_OPTION_REFRESH, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_BIP_OPTION_REFRESH, 0  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_BIP_OPTION_DISCONNECT, 0, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                                 STR_BIP_OPTION_DISCONNECT, 0  ));

    /* images */
    ADD_APPLICATION_IMAGE2(IMG_BIP_DEFAULT_THM, CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BIP\\\\default_thm.gif","BIP imglist browser default thm icon");
    
}

#endif /* __MMI_BIP_SUPPORT__  */

/*---------------------------------*/

#ifdef __MMI_OPP_SUPPORT__
void PopulateExtDevOPPRes(void)
{
      /* String Resource */
	ADD_APPLICATION_STRING2(STR_OPP_RECV_DISK_FULL, "Disk Full","Disk Full");
	ADD_APPLICATION_STRING2(STR_OPP_RECV_ROOT_DIR_FULL, "Root Directory Full","Root Directory Full");
	ADD_APPLICATION_STRING2(STR_OPP_WRITE_FILE_FAIL, "Write File Failed","FS write failed");
	ADD_APPLICATION_STRING2(STR_OPP_RECV_FILE_IND, "File stored at  ","Received file");

	ADD_APPLICATION_STRING2(STR_OPP_NOTY_RECV_FILE_BROWSE, "Browse","Received file");
	ADD_APPLICATION_STRING2(STR_OPP_NOTY_RECV_FILE_HED, "Received","Received file");
	ADD_APPLICATION_STRING2(STR_OPP_NOTY_RECV_FILE_TIL, "file","Received file");
	ADD_APPLICATION_STRING2(STR_OPP_NOTY_RECV_ACCEPT, "Receive Data?","Accept new file");

	ADD_APPLICATION_STRING2(STR_OPP_DEV_BUSY, "Bluetooth Device Busy","Device Busy");
	ADD_APPLICATION_STRING2(STR_OPP_SEND, "Sending","Blutooth Device Sending");
	ADD_APPLICATION_STRING2(STR_OPP_CON_DISCONNECTED, "OPP connection disconnected","OPP connection disconnected string");
        ADD_APPLICATION_STRING2(STR_OPP_UNKNOWN_FILE_TYPE, "Unknown file type","Unknown file type");
        ADD_APPLICATION_STRING2(STR_OPP_NOTY_RECV_FOLDER, "Folder","Folder");
        ADD_APPLICATION_STRING2(STR_OPP_NOTY_RECV_MULTI_FILE_TIL, "files","files");
        ADD_APPLICATION_STRING2(STR_OPP_NOTY_CON_BUSY, "Connction is busy","Connection is busy String");
        ADD_APPLICATION_STRING2(STR_OPP_NOTY_DISCONNECTING, "Disconnecting","Disconnecting String");
    /* Image Resource */

      /*Menu Items*/

}

#endif  /* __MMI_OPP_SUPPORT__ */

#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)

void PopulateExtDevHIDDRes(void)
{
    /* String Resource */
    /* Image Resource */
    ADD_APPLICATION_IMAGE(HID_IMG_BG, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_BACKGROUND.gif");

    ADD_APPLICATION_IMAGE(DESKTOP_IMG_01_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_01_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_01_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_01_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_02_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_02_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_02_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_02_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_03_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_03_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_03_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_03_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_04_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_04_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_04_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_04_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_05_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_05_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_05_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_05_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_06_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_06_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_06_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_06_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_07_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_07_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_07_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_07_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_08_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_08_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_08_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_08_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_09_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_09_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_09_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_09_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_10_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_10_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_10_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_10_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_11_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_11_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_11_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_11_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_DOWN.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_12_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_12_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_12_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(DESKTOP_IMG_12_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_DOWN.pbm");

    ADD_APPLICATION_IMAGE(MOUSE_IMG_UP_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_UP_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_OFF.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_UP_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_OFF.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_UP_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_DOWN_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_DOWN_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_OFF.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_DOWN_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_OFF.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_DOWN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_LEFT_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_LEFT_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_OFF.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_LEFT_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_OFF.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_LEFT_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_RIGHT_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_RIGHT_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_OFF.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_RIGHT_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_OFF.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_RIGHT_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MOUSE_IMG_COMMON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_ICON.pbm");

    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_01_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY01_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_01_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY01_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_01_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY01_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_01_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY01_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_02_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_02_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_02_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_02_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_03_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY03_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_03_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY03_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_03_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY03_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_03_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY03_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_04_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_04_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_04_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_04_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_05_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_05_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_05_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_05_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_06_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_06_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_06_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_06_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_07_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_07_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_07_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_07_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_08_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_08_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_08_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_08_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_09_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_09_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_09_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_09_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_10_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_10_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_10_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_10_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_11_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_11_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_11_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_11_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_DOWN.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_12_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_12_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_12_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_OFF.pbm");
    ADD_APPLICATION_IMAGE(MEDIA_PLAYER_IMG_12_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_DOWN.pbm");

    ADD_APPLICATION_IMAGE(PRESENTER_IMG_01_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY01_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_01_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY01_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_01_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY01_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_01_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY01_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_02_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_02_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_02_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_02_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_03_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY03_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_03_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY03_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_03_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY03_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_03_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY03_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_04_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_04_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_04_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_04_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_05_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_05_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_05_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_05_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_06_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_06_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_06_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_06_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_07_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_07_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_07_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_07_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_08_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_08_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_08_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_08_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_09_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_09_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_09_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_09_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_10_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_10_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_10_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_10_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_11_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_11_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_11_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_11_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_12_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_12_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_12_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_IMG_12_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_DOWN.pbm");

    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_UP_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_UP_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_UP_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_UP_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_DOWN_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_DOWN_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_DOWN_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_DOWN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_LEFT_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_LEFT_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_LEFT_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_LEFT_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_DOWN.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_RIGHT_DISALBE, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_DISABLE.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_RIGHT_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_RIGHT_ON, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_OFF.pbm");
    ADD_APPLICATION_IMAGE(PRESENTER_MOUSE_IMG_RIGHT_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_DOWN.pbm");
    


    /*Menu Items*/

}

#endif  /* __MMI_HIDD_SUPPORT__ && __MMI_BT_MTK_SUPPORT__ */

#ifdef __MMI_BPP_SUPPORT__
void PopulateExtDevBPPRes(void)
{
    /* String Resource */
    ADD_APPLICATION_STRING2(STR_BT_BPP_PRINT_BY_BT, "Print by Bluetooth","Print by Bluetooth");
	ADD_APPLICATION_STRING2(STR_BT_BPP_BT_PRINTING, "Bluetooth Printing", "Bluetooth Printing");
	ADD_APPLICATION_STRING2(STR_BT_BPP_AUTHENTICATING, "Password Exchange", "Password Exchange");    
	ADD_APPLICATION_STRING2(STR_BT_BPP_NEGOTIATING, "Negotiating","Negotiating");
	ADD_APPLICATION_STRING2(STR_BT_BPP_GETTING_CAPABILITY, "Getting Printer Capabilities","Getting Printer Capabilities");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_PRINT_SETTING, "Print Setting","Print Setting");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_PAPER, "Paper size","Paper size");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_PAPER_A4, "A4","A4");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_PAPER_US, "Letter","Letter");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_PAPER_4X6, "4x6","4x6");
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_SIDES, "Sides","Sides");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_SIDES_ONE, "One-Sided","One-Sided");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_SIDES_TWO, "Two-Sided","Two-Sided");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_PAGES, "Pages per sheet","Pages per sheet");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_ORIENTATION, "Orientation","Orientation");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_ORIENTATION_PORTRAIT, "Portrait","Portrait");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_ORIENTATION_LANDSCAP, "Landscap","Landscap");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_QUALITY, "Quality","Quality");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_QUALITY_HIGH, "High","High");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_QUALITY_NORMAL, "Normal","Normal");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_QUALITY_DRAFT, "Draft","Draft");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_COPIES, "Number of copies","Number of copies");
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_COPIES_ERROR, "Please input the number of copies","Please input the number of copies");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_COPIES_EXCEED, "Printer can only support","Printer can only support");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_SETTING_COPIES_EXCEED_END, "Copies","Copies");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_LAYOUT_PREVIEW, "Layout","Layout Preview");
    ADD_APPLICATION_STRING2(STR_BT_BPP_PRINT, "Print","Print");
    ADD_APPLICATION_STRING2(STR_BT_BPP_PRINT_JOB_CREATING, "Creating a print job","Creating a print job");
    ADD_APPLICATION_STRING2(STR_BT_BPP_PRINT_DOCUMENT_COMPOSING, "Composing print document","Composing print document");
    ADD_APPLICATION_STRING2(STR_BT_BPP_PRINTING, "Printing","Printing");
    ADD_APPLICATION_STRING2(STR_BT_BPP_BACKGROUND, "BackG.","Background");
    ADD_APPLICATION_STRING2(STR_BT_BPP_FOREGROUND, "ForeG.","Foreground");
    ADD_APPLICATION_STRING2(STR_BT_BPP_TROUBLE, "Troubleshooting","Troubleshooting");
    ADD_APPLICATION_STRING2(STR_BT_BPP_TROUBLE_NOTICE, "Please check printer","Please check printer");
    ADD_APPLICATION_STRING2(STR_BT_BPP_TROUBLE_JAM, "Printer paper jam","Printer paper jam");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_TROUBLE_PAUSED, "Printer paused this print job","Printer paused this print job");
    ADD_APPLICATION_STRING2(STR_BT_BPP_TROUBLE_DOOR, "Please check printer doors","Please check printer doors");            
    ADD_APPLICATION_STRING2(STR_BT_BPP_TROUBLE_MARKER, "Please check printer markers","Please check printer markers");            
    ADD_APPLICATION_STRING2(STR_BT_BPP_TROUBLE_MEDIA, "Please check printer media","Please check printer media");            
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_PRINTER_BUSY, "Another Print Job is Printing","Another Print Job is Printing");
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_AUTH_FAILED, "Authentication Failed","Authentication Failed");
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_CONNECT_FAILED, "Connect Failed","Connect Failed");    
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_GET_ATTR_FAILED, "Can't get capabilities from Printer","Can't get capabilities from Printer");        
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_CREATE_JOB_FAILED, "Print job creating failed","Print job creating failed");        
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_COMPOSE_FAILED, "Composing print document failed","Composing print document failed");        
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_READ_FILE_FAILED, "Read file failed","Read file failed");            
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_BACKGROUND_PRINTING, "Background Printing","Background Printing");            
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_PRINTED, "Document Printed","Document Printed");            
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_CANCELED, "Job Canceled","Job Canceled");            
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_DISCONNECTED, "BPP connection disconnected","BPP connection disconnected");                
    ADD_APPLICATION_STRING2(STR_BT_BPP_POPUP_FORMAT_WARNING, "Printer may only support JPEG format","Printer may only support JPEG format");                
    ADD_APPLICATION_STRING2(STR_BT_BPP_CANCEL, "Canceling","Canceling");                      

    /* Image Resource */
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_L_S1_C1,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_L_Side1_Cnt1.gif","Layout_Landscap_single_sided_one_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_L_S1_C2,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_L_Side1_Cnt2.gif","Layout_Landscap_single_sided_two_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_L_S1_C4,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_L_Side1_Cnt4.gif","Layout_Landscap_single_sided_four_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_L_S2_C1,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_L_Side2_Cnt1.gif","Layout_Landscap_two_sided_one_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_L_S2_C2,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_L_Side2_Cnt2.gif","Layout_Landscap_two_sided_two_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_L_S2_C4,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_L_Side2_Cnt4.gif","Layout_Landscap_two_sided_four_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_P_S1_C1,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt1.gif","Layout_Portrait_single_sided_one_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_P_S1_C2,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt2.gif","Layout_Portrait_single_sided_two_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_P_S1_C4,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt4.gif","Layout_Portrait_single_sided_four_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_P_S2_C1,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side2_Cnt1.gif","Layout_Portrait_two_sided_one_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_P_S2_C2,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side2_Cnt2.gif","Layout_Portrait_two_sided_two_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_LAYOUT_P_S2_C4,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side2_Cnt4.gif","Layout_Portrait_two_sided_four_pages_per_sheet");
    ADD_APPLICATION_IMAGE2(IMG_BPP_DEFAULT_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BPP\\\\BPP_Default_Logo.jpg","BPP print document default logo");

    /*Menu Items*/

}
#endif  /* __MMI_BPP_SUPPORT__ */


#endif  /* __MMI_BT_SUPPORT__ */



#endif /* DEVELOPER_BUILD_FIRST_PASS */

