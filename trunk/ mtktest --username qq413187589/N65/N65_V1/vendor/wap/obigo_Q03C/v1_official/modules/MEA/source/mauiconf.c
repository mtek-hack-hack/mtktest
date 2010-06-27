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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*!\file mauiconf.c
 * \brief User Interface for the configuration view.
 */

/* MSF */
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_lib.h"
#include "msf_def.h"
#include "msf_log.h"
#include "msf_cfg.h"
#include "msf_neta.h"
#include "msf_core.h"

/* MMS */
#include "mms_def.h"
#ifdef WAP_SUPPORT
#include "msig.h"     //for MMS_PATH_LEN
#include "fldmgr.h"
#include "mms_cfg.h"  //for MMS_MAX_NO_OF_MSG
#endif /* WAP_SUPPORT */

/* MEA */
#include "maintsig.h"
#include "mea_rc.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "mauicmn.h"
#include "maconf.h"
#include "mauiconf.h"
#include "mauiform.h"
#include "mamem.h"
#ifdef WAP_SUPPORT
#include "mauidia.h"
#include "mauisig.h"  //for meaDeleteWindow

#include "msf_file.h"  //for MSF_FILE_SET_RDONLY
//#include "kal_release.h" // for ASSERT //widget_extension.h has included it
#include "widget_extension.h"
#include "bra_if.h"
#ifdef __MTK_TARGET__
#include "fs_type.h"
#include "fs_func.h"
#endif /* __MTK_TARGET__ */

extern void msm_get_folder_info(char *path, int *file_num, long *file_size);
/* BRA */
extern void bra_create_ui(MSF_UINT8);
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \struct MeaMenuTable
 *  \brief Table data for all configuration menus.
 */
typedef struct 
{
    int             configId;           /*!< Menu ID. See #MeaConfigMenu */
    int             childId;            /*!< Menu item ID. See #MeaConfigGroups
                                             #MeaConfigFilter, #MeaConfigSend */
    MeaInputType    menuType;           /*!< Type of input form. */
    MeaInputActionCallBack callback;    /*!< Callback function for input form*/
    MeaInputActionBackCallBack backCallback; /*!< BACK Callback function */
    MsfStringHandle menuItems[MEA_CONFIG_MAX_MENU_DEPTH]; /*!< String 
                                                      handles for menu items */
    MSF_UINT32      titleStrId;         /*!< String ID for the form title */
}MeaMenuTable;


/******************************************************************************
 * Constants
 *****************************************************************************/

#ifndef WAP_SUPPORT
#define NET_ACCOUNT_BUFF_LEN 20  /* !< Maximum length for the name of a network
                                       account*/
#endif /* ~WAP_SUPPORT */

/******************************************************************************
 * Static data
 *****************************************************************************/

/*! This variable contains all menu information needed to present the 
 *  configuration menus 
 */
static const 
MeaMenuTable menuTable[MEA_CONFIG_MENU_COUNT][MEA_CONFIG_MAX_MENU_DEPTH] =
{
    /*lint -e{785} */
    { /* MEA_CONFIG_MENU_DEFAULT [0][0]*/
        {MEA_CONFIG_MENU_DEFAULT, MEA_CONFIG_MENU_ROOT, MEA_SELECT_INPUT, 
            (MeaInputActionCallBack)meaConfigMenuCallback, 
            (MeaInputActionBackCallBack)meaConfigMenuBackCallback,
            MEA_CONFIG_MENU, MEA_STR_ID_CONFIG}
    },
    { /* MEA_CONFIG_MENU_ROOT [1][0]*/
        {MEA_CONFIG_COMPOSE, MEA_CONFIG_MENU_COMPOSE, MEA_SELECT_INPUT,
            NULL, NULL, 
            MEA_CONFIG_MENU_MC, MEA_STR_ID_CONFIG_COMPOSE},
        {MEA_CONFIG_SENDING, MEA_CONFIG_MENU_SEND, MEA_SELECT_INPUT, 
            (MeaInputActionCallBack)meaConfigMenuCallback, NULL,
            MEA_CONFIG_MENU_MS, MEA_STR_ID_CONFIG_SENDING},
		//[1][1]
        {MEA_CONFIG_RETRIEVAL, MEA_CONFIG_MENU_RETRIEVE, MEA_SELECT_INPUT,
            (MeaInputActionCallBack)meaConfigMenuCallback, NULL, 
            MEA_CONFIG_MENU_RETRIEVAL, MEA_STR_ID_CONFIG_MSG_RETRIEVAL},
        //[1][2]
        {MEA_CONFIG_FILTER, MEA_CONFIG_MENU_FILTER, MEA_SELECT_INPUT, 
            (MeaInputActionCallBack)meaConfigMenuCallback, NULL, 
            MEA_CONFIG_MENU_MR, MEA_STR_ID_CONFIG_MSG_FILTERS},

        {MEA_CONFIG_MMSC, -1, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaMmscCallback, NULL, 
            {0}, MEA_STR_ID_CONFIG_MMSC},

#ifndef WAP_SUPPORT
        {MEA_CONFIG_NETWORK, MEA_CONFIG_MENU_NETWORK, MEA_SELECT_INPUT, 
            (MeaInputActionCallBack)meaConfigMenuCallback, NULL, 
            MEA_CONF_MENU_STRS_NETWORK, MEA_STR_ID_CONFIG_NETWORK}

#endif /* ~WAP_SUPPORT */
    },
    {  {MEA_CONFIG_COMP_CREATION_MODE, -1, MEA_RADIO_BUTTON_INPUT,
            NULL, NULL,
            MEA_CONFIG_MENU_COMP_CREATION_MODE, MEA_STR_ID_CREATION_MODE},
            
#ifdef JPG_ENCODE
        {MEA_CONFIG_COMP_IMAGE_RESIZE, -1, MEA_RADIO_BUTTON_INPUT,
            NULL, NULL,
            MEA_CONFIG_MENU_COMP_IMAGE_RESIZE, MEA_STR_ID_IMAGE_RESIZE},
#endif

        {MEA_CONFIG_COMP_AUTO_SIGNATURE, -1, MEA_RADIO_BUTTON_INPUT,
            NULL, NULL,
            MEA_CONFIG_MENU_COMP_AUTO_SIGNATURE, MEA_STR_ID_AUTO_SIGNATURE},

        {MEA_CONFIG_COMP_AUTO_SIGNATURE_TEXT, MEA_IMG_SET_SIG_TEXT, MEA_TEXT_INPUT,
            NULL, NULL,
            {0}, 0},
    },
    { /* MEA_CONFIG_MENU_SEND [2][0]*/
#ifdef WAP_SUPPORT
        {MEA_CONFIG_EXP_TIME, MEA_IMG_SET_SEND_PERIOD, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaExpTimeCallback, NULL, 
            MEA_CONFIG_MENU_VALIDITY, MEA_STR_ID_CONFIG_VAL_PER},

        {MEA_CONFIG_DELIV_REPORT, MEA_IMG_SET_SEND_DR, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaDelivReportCallback, NULL, 
            MEA_CONFIG_MENU_DR, MEA_STR_ID_CONFIG_DR},

        {MEA_CONFIG_READ_REPORT, MEA_IMG_SET_SEND_RR, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaReadReportCallback, NULL, 
            MEA_CONFIG_MENU_RR, MEA_STR_ID_CONFIG_RR},

        {MEA_CONFIG_PRIORITY, MEA_IMG_SET_SEND_PRIORITY, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaPriorityCallback, NULL, 
            MEA_CONFIG_MENU_PRIORITY, MEA_STR_ID_CONFIG_PRIORITY},

        {MEA_CONFIG_SLIDE_DUR, MEA_IMG_SET_SEND_SLIDE_DUR, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaSlideDurCallback, NULL, 
            {0}, MEA_STR_ID_DURATION},

        {MEA_CONFIG_DELIVERY_TIME, MEA_IMG_SET_SEND_DELIVERY_TIME, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaDeliveryTimeCallback, NULL, 
            MEA_CONFIG_MENU_DELIVERY_TIME, MEA_STR_ID_CONFIG_DELIVERY_TIME}
#ifdef __MMI_MMS_BGSR_SUPPORT__
        ,{MEA_CONFIG_SAVE_ON_SEND, MEA_IMG_SET_SEND_DELIVERY_TIME, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaSaveOnSendCallback, NULL, 
            MEA_CONFIG_MENU_SOS, MEA_STR_ID_CONFIG_SOS}
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#else
        {MEA_CONFIG_EXP_TIME, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaExpTimeCallback, NULL, 
            MEA_CONFIG_MENU_VALIDITY, MEA_STR_ID_CONFIG_VAL_PER},

        {MEA_CONFIG_READ_REPORT, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaReadReportCallback, NULL, 
            MEA_CONFIG_MENU_RR, MEA_STR_ID_CONFIG_RR},

        {MEA_CONFIG_DELIV_REPORT, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaDelivReportCallback, NULL, 
            MEA_CONFIG_MENU_DR, MEA_STR_ID_CONFIG_DR},

        {MEA_CONFIG_PRIORITY, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaPriorityCallback, NULL, 
            MEA_CONFIG_MENU_PRIORITY, MEA_STR_ID_CONFIG_PRIORITY},

        {MEA_CONFIG_REPLY_CHRG_MENU, MEA_CONFIG_MENU_REP_CHRG_SETTINGS, 
            MEA_SELECT_INPUT, 
            (MeaInputActionCallBack)meaConfigMenuCallback, NULL, 
            MEA_CONFIG_MENU_REP_CHRG_ITEMS, MEA_STR_ID_REPLY_CHARGING},

        /* will cause sending error by unsupported MMSC */
        {MEA_CONFIG_SENDER_VISIBILITY, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaSenderVisibilityCallback, NULL, 
            MEA_CONFIG_MENU_SENDER_VISIBILITY, MEA_STR_ID_CONFIG_SEND_VISIBILITY},

        /* change to menu- Send Only/Save and Send/Save */
        {MEA_CONFIG_SAVE_ON_SEND, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaSaveOnSendCallback, NULL, 
            MEA_CONFIG_MENU_SOS, MEA_STR_ID_CONFIG_SOS},

        {MEA_CONFIG_SLIDE_DUR, -1, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaSlideDurCallback, NULL, 
            {0}, MEA_STR_ID_DURATION},

        {MEA_CONFIG_DELIVERY_TIME, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaDeliveryTimeCallback, NULL, 
            MEA_CONFIG_MENU_DELIVERY_TIME, MEA_STR_ID_CONFIG_DELIVERY_TIME}
#endif /* ~WAP_SUPPORT */

    },
    { /* MEA_CONFIG_MENU_FILTER [3][0]*/
#ifndef WAP_SUPPORT    
        {MEA_CONFIG_IM_SERVER, -1, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaImServerCallback, NULL, 
            {0}, MEA_STR_ID_CONFIG_IM_SERVER},

        {MEA_CONFIG_IM_SIZE, -1, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaImRetrSizeCallback, NULL, 
            {0}, MEA_STR_ID_CONFIG_IM_SIZE},
        
        {MEA_CONFIG_TREAT_AS_DEL, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaTreatAsDelCallback, NULL, 
            MEA_CONFIG_MENU_TREAT_AS_DEL, MEA_STR_ID_CONFIG_TREAT_AS_DEL},
        
        {MEA_CONFIG_RETR_SIZE, -1, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaDownloadSizeCallback, NULL, 
            {0}, MEA_STR_ID_MAX_RETR_SIZE},
#endif /* ~WAP_SUPPORT */
        
        {MEA_CONFIG_ALLOW_ANONYM, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaAllowAnonymCallback, NULL, 
            MEA_CONFIG_MENU_ALLOW_ANONYM, MEA_STR_ID_CONFIG_ANONYM},
        
#if defined(WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER) && WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER == 1
        {MEA_CONFIG_RETR_SIZE, -1, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaDownloadSizeCallback, NULL, 
            {0}, MEA_STR_ID_MAX_RETR_SIZE},
#endif
#ifndef WAP_SUPPORT        
        {MEA_CONFIG_ALLOW_PERSONAL, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaAllowPersonalCallback, NULL, 
            MEA_CONFIG_MENU_ALLOW_PERSONAL, MEA_STR_ID_CONFIG_PERS},
#endif /* WAP_SUPPORT */
        
        {MEA_CONFIG_ALLOW_ADVERT, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaAllowAdvertCallback, NULL, 
            MEA_CONFIG_MENU_ALLOW_ADVERT, MEA_STR_ID_CONFIG_ADVERT},
        
        {MEA_CONFIG_ALLOW_INFO, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaAllowInfoCallback, NULL, 
            MEA_CONFIG_MENU_ALLOW_INFO, MEA_STR_ID_CONFIG_INFO},
        
        {MEA_CONFIG_ALLOW_AUTO, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaAllowAutoCallback, NULL, 
            MEA_CONFIG_MENU_ALLOW_AUTO, MEA_STR_ID_CONFIG_AUTO},
        
        {MEA_CONFIG_ALLOW_STRING, -1, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaAllowStringCallback, NULL, 
            {0}, MEA_STR_ID_CONFIG_USER_STRING}
    },
    { /* MEA_CONFIG_MENU_NETWORK [4][0]*/
        {MEA_CONFIG_CONN_TYPE, MEA_CONFIG_CONN_TYPE, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaNetworkCallback, NULL, 
            MEA_CONFIG_MENU_CONN_TYPE, MEA_STR_ID_CONN_TYPE},

#ifndef WAP_SUPPORT
        {MEA_CONFIG_NET_ACCOUNT, MEA_CONFIG_NET_ACCOUNT, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaNetworkCallback, NULL, 
            {0}/*Special case: dynamic content*/, MEA_STR_ID_NETWORK_ACCOUNT},

        {MEA_CONFIG_WAP_GW, MEA_CONFIG_WAP_GW, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaNetworkCallback, NULL, 
            {0}, MEA_STR_ID_WAP_GATEWAY},
        
        {MEA_CONFIG_LOGIN, MEA_CONFIG_LOGIN, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaNetworkCallback, NULL, 
            {0}, MEA_STR_ID_LOGIN},
        
        {MEA_CONFIG_PASSWD, MEA_CONFIG_PASSWD, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaNetworkCallback, NULL, 
            {0}, MEA_STR_ID_PASSWD},
        
        {MEA_CONFIG_REALM, MEA_CONFIG_REALM, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaNetworkCallback, NULL, 
            {0}, MEA_STR_ID_REALM},
        
        {MEA_CONFIG_SEC_PORT, MEA_CONFIG_SEC_PORT, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaNetworkCallback, NULL, 
            {0}, MEA_STR_ID_SEC_PORT},
        
        {MEA_CONFIG_HTTP_PORT, MEA_CONFIG_HTTP_PORT, MEA_SINGLE_LINE_INPUT, 
            (MeaInputActionCallBack)meaNetworkCallback, NULL, 
            {0}, MEA_STR_ID_HTTP_PORT}
#endif /* ~WAP_SUPPORT */
    },
    { /* MEA_CONFIG_MENU_MMS_SETTINGS [5][0]*/
        /*  This menu reuses the first 4 entries in the MEA_CONFIG_MENU_SEND
         *  menu so if that menu changes, this menu has to be re-written 
         */
#ifdef WAP_SUPPORT
        {MEA_CONFIG_SENDING, MEA_CONFIG_MENU_SEND, MEA_SELECT_INPUT, 
            (MeaInputActionCallBack)meaConfigMenuCallback, NULL, 
            MEA_CONFIG_MENU_MMS, MEA_STR_ID_SEND_OPTIONS}
#else
        {MEA_CONFIG_SENDING, MEA_CONFIG_MENU_SEND, MEA_SELECT_INPUT, 
            (MeaInputActionCallBack)meaConfigMenuCallback, NULL, 
            MEA_CONFIG_MENU_MMS, MEA_STR_ID_CONFIG}
#endif /* WAP_SUPPORT */
    },
    { /* MEA_CONFIG_MENU_REP_CHRG_SETTINGS */
        {MEA_CONFIG_REPLY_CHARGING, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaReplyChargingCallback, NULL, 
            MEA_CONFIG_MENU_REPLY_CHARGING, MEA_STR_ID_REPLY_CHARGING},

        {MEA_CONFIG_REPLY_CHARGING_DEADLINE, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaReplyChargingDeadlineCallback, NULL,
            MEA_CONFIG_MENU_REPLY_CHARGING_DEADLINE, 
            MEA_STR_ID_REPLY_CHARGING_DEADLINE},
        
        {MEA_CONFIG_REPLY_CHARGING_SIZE, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaReplyChargingSizeCallback, NULL,
            MEA_CONFIG_MENU_REPLY_CHARGING_SIZE, 
            MEA_STR_ID_REPLY_CHARGING_SIZE}
    },      
    { /* MEA_CONFIG_MENU_RETRIEVE */
#ifdef __OP01_MMS_RETRIEVE_SETTING__
        /* not change structure of the menu, only change display string */
        {MEA_CONFIG_HOME_NETWORK, -1, MEA_RADIO_BUTTON_INPUT, 
        (MeaInputActionCallBack)meaRetrievalHomeModeCallback, NULL, 
        MEA_CFGMENU_ITEMS_RETRIEVE_ALLOWED, MEA_STR_ID_CONFIG_RETRIEVE_ALLOWED},

        {MEA_CONFIG_ROAM_NETWORK, -1, MEA_RADIO_BUTTON_INPUT, 
        (MeaInputActionCallBack)meaRetrievalRoamModeCallback, NULL, 
        MEA_CFGMENU_ITEMS_IMMEDIATELY_ROAM, MEA_STR_ID_CONFIG_RETRIEVE_IM_ROAM},

        {MEA_CONFIG_SEND_READ_REPORT, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaSendReadReportCallback, NULL, 
        MEA_CFGMENU_ITEMS_DELIVERY_REPORT_ALLOWED, MEA_STR_ID_CONFIG_DELIVERY_REPORT_ALLOWED},

        {MEA_CONFIG_DELIVERY_REPORT_ALLOWED, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaDeliveryReportAllowedCallback, NULL, 
        MEA_CFGMENU_ITEMS_SEND_READ_REPORT_ALLOWED, MEA_STR_ID_CONFIG_SEND_READ_REPORT_ALLOWED}
#else
        {MEA_CONFIG_HOME_NETWORK, -1, MEA_RADIO_BUTTON_INPUT, 
        (MeaInputActionCallBack)meaRetrievalHomeModeCallback, NULL, 
        MEA_CONFIG_MENU_RETRIEVAL_HOME, MEA_STR_ID_CONFIG_MSG_RETR_HOME_MODE},

        {MEA_CONFIG_ROAM_NETWORK, -1, MEA_RADIO_BUTTON_INPUT, 
        (MeaInputActionCallBack)meaRetrievalRoamModeCallback, NULL, 
        MEA_CONFIG_MENU_RETRIEVAL_ROAM, MEA_STR_ID_CONFIG_MSG_RETR_ROAM_MODE},

        {MEA_CONFIG_SEND_READ_REPORT, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaSendReadReportCallback, NULL, 
            MEA_CONFIG_MENU_SEND_READ_REPORT, MEA_STR_ID_CONFIG_SEND_READ_REPORT},

        {MEA_CONFIG_DELIVERY_REPORT_ALLOWED, -1, MEA_RADIO_BUTTON_INPUT, 
            (MeaInputActionCallBack)meaDeliveryReportAllowedCallback, NULL, 
            MEA_CONFIG_MENU_DELIVERY_REPORT_ALLOWED, MEA_STR_ID_CONFIG_DELIVERY_REPORT_ALLOWED}
#endif
    },
};

#ifdef WAP_SUPPORT
static MsfWindowHandle meaConfMemoryStatusViewHandle;
static MeaPropItem * propItem;
#endif /* WAP_SUPPORT */

static MsfWindowHandle meaConfComposeViewHandle;
/******************************************************************************
 * Prototypes
 *****************************************************************************/
#ifdef WAP_SUPPORT
static void meaCreateConfMemoryStatusView(void);
static MSF_BOOL meaConfigActivateInlineMenu(MeaConfigMenu menu, int id, void *data, int start_index);
static int prepareListOfStrID(const MsfStringHandle items[], U16 *list_of_strid);
#else /* WAP_SUPPORT */
static MsfStringHandle *createNetworkAccountList(void);
#endif /* WAP_SUPPORT */
static void releaseNetworkAccountList(MsfStringHandle **list);
static MsfStringHandle *getStrItems(const MsfStringHandle items[], int size);

#ifdef __OP01_MMS_RETRIEVE_SETTING__
static MSF_BOOL meaConfigActivateRetrieveMenu( ctk_layout_handle layoutid, MeaConfigMenu menu, int id);
static MSF_BOOL meaConfigSaveRetrieveMenuValue(ctk_layout_handle layout_id, int menu_id, int *fail_index);
static MSF_BOOL meaConfigSetRoamStatus(void);
static MSF_BOOL meaConfigGetRoamStatus(void);
#endif
/******************************************************************************
 * Function implementation
 *****************************************************************************/

#ifdef WAP_SUPPORT
/*!
 *  \brief Memory satus view back action.
 *****************************************************************************/
void meaDeleteConfMemoryStatusView(void)
{
    meaDeleteWindow(meaConfMemoryStatusViewHandle);
    /* Delete obsolete handles */
    //memset(&meaConfMemoryStatusView, 0, sizeof(MeaConfMemoryStatusView));
    meaConfMemoryStatusViewHandle = 0;
}

/*!
 *  \brief Memory satus view back action.
 *****************************************************************************/
static void meaConfMemoryStatusViewGoBack(ctk_screen_handle scrid)
{
    CTK_UNUSED(scrid);
    meaDeleteConfMemoryStatusView();
}

/*!
 *  \brief Get MMS Folder Bytes.
 *****************************************************************************/
static MSF_UINT32 meaGetMMSFolderBytes(void)
{
#ifndef __MTK_TARGET__
    int files, type, size, i=0;
	MSF_UINT32 folderSize= 0;
	char tmpName[MMS_FILE_LEN];
	char pathName[MMS_PATH_LEN];
	
	files =  HDIa_fileGetSizeDir(MMS_FOLDER);
    if (files >= 1) 
    {
       while  ((HDIa_fileReadDir(MMS_FOLDER, i, tmpName,
            MMS_PATH_LEN, &type, &size) == HDI_FILE_OK) && 
            (i < files))
       {
           strcpy(pathName, MMS_FOLDER);
		   strcat(pathName,tmpName);
           size = HDIa_fileGetSize(pathName);
           folderSize +=size;
           i++; 
       }
    }   
    return folderSize;
#else
    kal_uint8* folderName = HDI_FileNameTranslate(MMS_FOLDER);
    MSF_INT32 folderSize = FS_GetFolderSize((const WCHAR*)folderName, FS_COUNT_IN_BYTE, NULL, 0);
	MSF_UINT32 totalSize = (folderSize <0)?0: folderSize;
	HDI_FileNameFree(folderName);
	return totalSize;
#endif /* !__MTK_TARGET__ */
}

/*!
 *  \brief Creation view back action.
 *****************************************************************************/
void meaDeleteConfComposeView(void)
{
    meaDeleteWindow(meaConfComposeViewHandle);
    meaConfComposeViewHandle = 0;
}

/*!
 * \brief Back action handler for Creation inline view.
 *****************************************************************************/
static void handleCreationBackAction(ctk_screen_handle scrId)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAUICONF_C2D8F2AA5BB71E4B9CFA59732817573C, "(%s) (%d)Creation Back action received", __FILE__, __LINE__));
    CTK_UNUSED(scrId);
    meaDeleteConfComposeView();
}

static void meaConfComposeViewDone(ctk_screen_handle scrId)
{
    ctk_layout_handle			layoutId =ctk_screen_get_layout(scrId);
    ctk_inline_item_type_enum	item_type;
    ctk_inline_result_union		item_value;
    int isOn;
    
    ctk_inline_get_result(layoutId, (MEA_CONFIG_COMP_AUTO_SIGNATURE + 1) * 2 - 1,&item_type, &item_value);
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_SELECT);
    isOn = item_value.select_highlight;

    ctk_inline_get_result(layoutId, (MEA_CONFIG_COMP_AUTO_SIGNATURE_TEXT + 1) * 2 - 2,&item_type, &item_value);
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_EDITOR);
    if (isOn && (!item_value.input_buffer || widget_ucs2_length((kal_uint8 *)item_value.input_buffer) == 0))
    {
        meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_NO_CONTENT), MEA_DIALOG_ERROR);
        return;
    }

    (void)meaShowConfirmDialog(BRA_STR_ID_SAVE_ASK, NULL, 
        MEA_CONFIG_FSM, MEA_SIG_CONF_SAVE_COMPOSE, (unsigned int)scrId);
}

/*!
 *  \brief Compose setting view.
 *    We don't use meaConfigActivateInlineMenu() because of
 *    1. different LSK, RSK behavior
 *    2. Auto signature setting items are quite different from meaConfigActivateInlineMenu()
 *    3. We don't put the setting value in registry since for creation mode and image resizing, we would check its setting before MEA is started (however, to bo revised...)
 *****************************************************************************/
/*lint -e{818} */
void meaCreateConfComposeView(void)
{
    ctk_screen_handle scrId;
    ctk_layout_handle layoutid;
    ctk_inline_create_struct layout_create;	
    ctk_inline_item_caption_copy_struct	 caption_create;
    ctk_inline_item_select_copy_struct select_create;
    ctk_inline_item_editor_copy_struct editor_create;

    const MeaMenuTable *menu = &menuTable[MEA_CONFIG_MENU_ROOT][MEA_CONFIG_COMPOSE];
    const MeaMenuTable *item;
    
    MsfTextType textType;
    U16 list_of_strid[MEA_CONFIG_MAX_MENU_DEPTH];
    int i = 0, value = 0, maxTextSize = 0, num_inline_items = 0;
    char *str = NULL;

    if (0 != meaConfComposeViewHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUICONF_FD8C080D5F40CE1676E154F4CE3FE82B, "(%s) (%d) The creation view instance is busy!\n", __FILE__, 
            __LINE__));
        return;
    }
	
    scrId = widget_ctk_screen_create();	
    ctk_screen_add_inline_Done_UA(scrId, NULL, meaConfComposeViewDone, KAL_TRUE);
    
    CTK_INIT_STRUCT(layout_create);
    layout_create.in_img_title = MEA_IMG_TITLE_NORMAL;
    layout_create.in_str_title = (ctk_string_id) menu->titleStrId;
    layout_create.in_cancel_fp = handleCreationBackAction;
    //layout_create.in_disable_done = KAL_TRUE; /* Let RSK be Clear/Back */
    
    for(i = 0, num_inline_items = 0; i < MEA_CONFIG_COMP_COUNT; i++, num_inline_items++)	/* inline editor item */
    {
        item = &menuTable[MEA_CONFIG_MENU_COMPOSE][i];
        if(item->titleStrId != 0)
        {
        	num_inline_items++;	/* caption */
        }
    }
    layout_create.in_num_items = num_inline_items;
    layoutid  = ctk_inline_create(HDIa_widgetCtkGetApp(), &layout_create);

    for (i = 0, num_inline_items = 0; i < MEA_CONFIG_COMP_COUNT; i++)
    {
        item = &menuTable[MEA_CONFIG_MENU_COMPOSE][i];

        /* Caption */
        if(item->titleStrId != 0)    
        {
            CTK_INIT_STRUCT(caption_create);
            caption_create.title = (ctk_string_id) item->titleStrId;
            if (item->childId != -1)
            {
                ctk_inline_set_item_copy(layoutid, num_inline_items++, (U16) (item->childId), 0, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);
            }
            else
            {
                ctk_inline_set_item_copy(layoutid, num_inline_items++, (U16) (WAP_IMAGE_SW_LIST_NB1 + i), 0, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);
            }
        }

        meaGetConfigData((MeaConfigMenu)MEA_CONFIG_MENU_COMPOSE, item->configId, NULL, &value, &str, &maxTextSize, &textType);
        
        /* Inline editor */
        switch (item->menuType)
        {
        case MEA_RADIO_BUTTON_INPUT:
            CTK_INIT_STRUCT(select_create);
            select_create.highlighted = value;
            select_create.num_options = prepareListOfStrID(item->menuItems, list_of_strid);
            select_create.list_options_strid = list_of_strid;
            ctk_inline_set_item_copy(layoutid, num_inline_items++, 0, 0, CTK_INLINE_ITEM_TYPE_SELECT, &select_create);
            break;
        case MEA_TEXT_INPUT: 
            CTK_INIT_STRUCT(editor_create); 
            editor_create.input_type = CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE;
            editor_create.max_len = maxTextSize;
            editor_create.default_text = (U8*)str;
            
            editor_create.is_UTF8 = KAL_TRUE;
            editor_create.str_title = MEA_STR_ID_EDIT_CONTENT;
            editor_create.img_title = MEA_IMG_TITLE_NORMAL;
            editor_create.use_input_method_menu = KAL_TRUE;
            ctk_inline_set_item_copy(layoutid, num_inline_items++, (U16)item->childId, 0, CTK_INLINE_ITEM_TYPE_EDITOR, &editor_create);
            break;
        default:
                WAP_DBG_ASSERT(0);
                break;
        }        
    }

    ctk_screen_attach_layout(scrId, layoutid);
    meaConfComposeViewHandle = HDIa_widgetCtkCreate(MSF_MODID_MEA, scrId);
    meaAddWidgetList(meaConfComposeViewHandle);
    meaDisplayWindow(meaConfComposeViewHandle, meaGetPosLeftTop());
}

static kal_uint8* meaCreateMemoryStatusText(char * strUsage, char * strTotal, char * strFree, 
    int *textSize)
{
    kal_uint8 * text = MEA_ALLOC(*textSize);
    widget_utf8_to_ucs2_string(text, *textSize, (kal_uint8*) "");
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, textSize, MEA_STR_ID_USAGE);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, textSize, (kal_uint8*)strUsage);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, textSize, (kal_uint8*)"\n");
	text = widget_ucs2str_append_id(MSF_MODID_MEA, text, textSize, MEA_STR_ID_TOTAL);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, textSize, (kal_uint8*)strTotal);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, textSize, (kal_uint8*)"\n");
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, textSize, MEA_STR_ID_FREE);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, textSize, (kal_uint8*)strFree);
    return text;
}

/*!
 *  \brief Memory satus view.
 *****************************************************************************/
/*lint -e{818} */
static void meaCreateConfMemoryStatusView(void)
{
    ctk_screen_handle	scrid;
    kal_uint8 			*text;
    int					textSize;
    char				*strUsage;
    char				*strTotal;
    char				*strFree;

    MSF_UINT16 nMsgs, nUnreadMsgs;
    MSF_UINT32 fileSize;
    U64 totalFolderSize;
    MmsFolderType folder = MMS_ALL_FOLDERS;
    
    if (0 != meaConfMemoryStatusViewHandle)
        meaDeleteConfMemoryStatusView();
	
    /* Prepare text */
    textSize = 50; /* The default size. widget_ucs2str_append_* will realloc the buffer on necessary */

    /* Usage */
    folder &= ~MMS_HIDDEN;
    strUsage = MEA_ALLOC(strlen("100/100")+2);
    fldrMgrGetNumberOfMessages(folder, &nMsgs, &nUnreadMsgs);
    nMsgs = (nMsgs > MMS_MAX_NO_OF_MSG - 1) ? (MMS_MAX_NO_OF_MSG - 1) : nMsgs;
    sprintf(strUsage, " %d/%d", nMsgs, MMS_MAX_NO_OF_MSG-1);

    /* Free:*/
    strFree = MEA_ALLOC(strlen("1000 Bytes") + 2);
    totalFolderSize = msm_get_disk_free_space(WAP_STORAGE_MMS);
    if (totalFolderSize >= (10 * MEA_1_KB * MEA_1_KB))
    {
        sprintf(strFree, " %lu M", (MSF_UINT32)(totalFolderSize / (MEA_1_KB * MEA_1_KB)));
    }
    else if (totalFolderSize >= MEA_1_KB)
    {
        sprintf(strFree, " %lu K", (MSF_UINT32)(totalFolderSize / MEA_1_KB));
    }
    else
    {
        sprintf(strFree, " %lu Bytes", (MSF_UINT32)totalFolderSize);
    }

    strTotal = MEA_ALLOC(strlen("50000 K")+2);
    fileSize = meaGetMMSFolderBytes();

    if (fileSize > MEA_1_KB)
    {
        sprintf(strTotal, " %lu K", fileSize / MEA_1_KB);
    }
    else if (fileSize == 0)
    {
        sprintf(strTotal, " 0 K");
	}
    else
    {
        sprintf(strTotal, " 1 K");
	}

    text = meaCreateMemoryStatusText(strUsage, strTotal, strFree, &textSize);
    MEA_FREE(strUsage);
    MEA_FREE(strTotal);
    MEA_FREE(strFree);
    
    /* Create widow */
    meaConfMemoryStatusViewHandle = HDIa_widgetExtCreateTextViewNoScrollBar
        (MSF_MODID_MEA, text, MEA_STR_ID_MEMORY_STATUS, 0);

    MEA_FREE(text);
    meaAddWidgetList(meaConfMemoryStatusViewHandle);

    /* Set Key */
    scrid = HDIa_widgetCtkGetScreenHandle(meaConfMemoryStatusViewHandle);
    ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, meaConfMemoryStatusViewGoBack, KAL_TRUE);
    ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, meaConfMemoryStatusViewGoBack, KAL_TRUE);
    meaDisplayWindow(meaConfMemoryStatusViewHandle, meaGetPosLeftTop());
}

/*****************************************************************************
 * Inline config menu (Justin)
 *****************************************************************************/
typedef struct 
{
	MeaConfigMenu menu;
	int id;
	void *data;
} mea_config_menu_local_data;

static int getNumItems(const MsfStringHandle items[])
{
	int i = 0;
	const MsfStringHandle *h = items;
	while (*h++)
		i++;
	return i;
}

static int prepareListOfStrID(const MsfStringHandle items[], U16 *list_of_strid)
{
	int i = 0;

	while (items[i] != 0)
	{
		list_of_strid[i] = (U16) items[i];
		i++;
	}
	return i;
}

static void meaConfigInlineMenuDone(ctk_screen_handle scrid)
{
	//MsfWindowHandle h = HDIa_widgetCtkGetWindow(scrid);
	mea_config_menu_local_data* localdata;
	//int			fail_index = -1;
	
	// MEA
    const MeaMenuTable	*mt;
    const MeaMenuTable	*menu_item; // each item    
    int				menu_id;
    int 			menu_index;
    int				num_items;

    // CTK
    ctk_layout_handle			layout_id;
    ctk_inline_item_type_enum	item_type;
    ctk_inline_result_union		item_value;

    layout_id = ctk_screen_get_layout(scrid);
    localdata = (mea_config_menu_local_data*) ctk_screen_get_local_data(scrid);
    
	mt = &menuTable[localdata->menu][localdata->id];
	menu_id = mt->childId;
	num_items = getNumItems(mt->menuItems);

#ifdef __OP01_MMS_RETRIEVE_SETTING__
    if (menu_id == MEA_CONFIG_MENU_RETRIEVE) // only handle Retrieve Menu
    {
        if (!meaConfigGetRoamStatus())
        {
            /* when not roam, Retrieve Immediately is not displayed */
            num_items--; 
        }
    }
#endif
	
	for (menu_index = 0; menu_index < num_items; menu_index++)
	{
		menu_item = &menuTable[menu_id][menu_index];
		ctk_inline_get_result(layout_id, menu_index*2 + 1,&item_type, &item_value);
		if (menu_item->menuType == MEA_SINGLE_LINE_INPUT)
		{
			int len;
			char *strbuf;
			
			ASSERT(item_type == CTK_INLINE_ITEM_TYPE_SINGLE_LINE);
			len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)item_value.input_buffer);
			if ( len==0 )
			{
				meaShowDialog(MEA_GET_STR_ID(WIDGET_STR_ID_CANT_INPUT_EMPTY_VALUE), MEA_DIALOG_ALERT);
				return;
			}
			if (menu_id == MEA_CONFIG_MENU_FILTER && menu_item->configId == MEA_CONFIG_RETR_SIZE)
			{
			    strbuf = MEA_ALLOC(len+1);
			    widget_ucs2_to_utf8_string((kal_uint8 *) strbuf, len+1, (kal_uint8 *)item_value.input_buffer);
			    if (!meaDownloadSizeVerify(strbuf)) //strbuf will be free in this function
			        return;
			}
			if (menu_id == MEA_CONFIG_MENU_SEND && menu_item->configId == MEA_CONFIG_SLIDE_DUR)
			{
			    int tmpVal;
			    strbuf = MEA_ALLOC(len+1);
			    widget_ucs2_to_utf8_string((kal_uint8 *) strbuf, len+1, (kal_uint8 *)item_value.input_buffer);
			    tmpVal = atoi(strbuf);
			    if (tmpVal < MEA_CFG_MIN_DURATION || tmpVal > MEA_CFG_MAX_DURATION) 
			    {
			        char *dlgStr = NULL;
                    dlgStr = meaGetIntervalString(MEA_STR_ID_INTERVAL_PREFIX, MEA_CFG_MIN_DURATION, 
                        MEA_STR_ID_INTERVAL_INFIX, MEA_CFG_MAX_DURATION);
                    (void)showErrorDlg(dlgStr);
                    MEA_FREE(dlgStr);
			        return;
			    }
			}
		}
	}
    (void)meaShowConfirmDialog(BRA_STR_ID_SAVE_ASK, NULL, 
        MEA_CONFIG_FSM, MEA_SIG_CONF_SAVE_SETTINGS, (unsigned int)scrid);
}

void meaConfigInlineMenuSave(ctk_screen_handle scrid)
{
	MsfWindowHandle h = HDIa_widgetCtkGetWindow(scrid);
	mea_config_menu_local_data* localdata;
	kal_bool	is_success = KAL_TRUE;
	int			fail_index = -1;
	
	// MEA
    const MeaMenuTable	*mt;
    const MeaMenuTable	*menu_item; // each item    
    int				menu_id;
    int 			menu_index;
    int				num_items;

    // CTK
    ctk_layout_handle			layout_id;
    ctk_inline_item_type_enum	item_type;
    ctk_inline_result_union		item_value;

	layout_id = ctk_screen_get_layout(scrid);
    localdata = (mea_config_menu_local_data*) ctk_screen_get_local_data(scrid);
    
	mt = &menuTable[localdata->menu][localdata->id];
	menu_id = mt->childId;
	num_items = getNumItems(mt->menuItems);
	
#ifdef __OP01_MMS_RETRIEVE_SETTING__
    if ( !meaConfigSaveRetrieveMenuValue(layout_id, menu_id, &fail_index))
    {
#endif
	for (menu_index = 0; menu_index < num_items; menu_index++)
	{
		menu_item = &menuTable[menu_id][menu_index];
		ctk_inline_get_result(layout_id, menu_index*2 + 1,&item_type, &item_value);
		switch (menu_item->menuType)
		{
			case MEA_SINGLE_LINE_INPUT:
			{
				char *strbuf;
				int len;
				ASSERT(item_type == CTK_INLINE_ITEM_TYPE_SINGLE_LINE);
				len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)item_value.input_buffer);
				strbuf = MEA_ALLOC(len+1);
				widget_ucs2_to_utf8_string((kal_uint8 *) strbuf, len+1, (kal_uint8 *)item_value.input_buffer);
				if (menu_item->callback(strbuf, 0, NULL, 0) == FALSE) //strbuf will be free in this function
				{
					is_success = KAL_FALSE;
					if (fail_index < 0)
						fail_index = menu_index;
				}
				//meaHandleOkFormAction(), callback function will free the string data by itself
				break;
			}
			case MEA_RADIO_BUTTON_INPUT:
				ASSERT(item_type == CTK_INLINE_ITEM_TYPE_SELECT);
				//some callbacks accept "p1" as argument.
				if (menu_item->callback(NULL, item_value.select_highlight, propItem, 0) == FALSE)
				{
					WAP_DBG_ASSERT(0); // This should NOT happen
					is_success = KAL_FALSE;
					if (fail_index < 0)
						fail_index = menu_index;
				}
				break;
			default:
				WAP_DBG_ASSERT(0); 
				break;
		}
	}

#ifdef __OP01_MMS_RETRIEVE_SETTING__
    }
#endif
	MSF_WIDGET_REMOVE(meaGetScreenHandle(), h);
	MSF_WIDGET_RELEASE(h);
	if (is_success)
	{
#ifdef WAP_SUPPORT
		/* update profile checksum */
		{
		extern void msm_compute_checksum_critical_file_by_index(int idx);
		msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
		}      
#endif
		meaShowDialog(MEA_GET_STR_ID(BRA_STR_ID_SAVED), MEA_DIALOG_PROMPT_DONE);
	}
	else
	{	
		/*
		 * Note that we should always create another window to input again because the  
		 * underlying GUI inline implementation might have problems by pressing "Done" twice
		 */
		meaConfigActivateInlineMenu(localdata->menu, localdata->id, localdata->data, 
					(fail_index < 0) ? 0:fail_index);
	}

	propItem = NULL;
	MEA_FREE(localdata);
}

void meaConfigInlineMenuCancel(ctk_screen_handle scrId)
{
	MsfWindowHandle h = HDIa_widgetCtkGetWindow(scrId);
	MSF_WIDGET_REMOVE(meaGetScreenHandle(), h);
    MSF_WIDGET_RELEASE(h);
}
 

 MSF_BOOL meaConfigActivateInlineMenu(MeaConfigMenu menu, int id, void *data, int start_index)
 {
 	// MEA
	const MeaMenuTable 			*mt; // main menu
	const MeaMenuTable			*menu_item; // each item
	int						menu_id;
	int						menu_index;
	U16						list_of_strid[MEA_CONFIG_MAX_MENU_DEPTH];

	int 					value, maxTextSize;
	char 					*str;
	MsfTextType 			textType;

	// Widget
	MsfWindowHandle			wnd;

	// CTK
	int 							num_items;
	ctk_screen_handle				scrid;
	ctk_layout_handle				layoutid;
	ctk_inline_create_struct		layout_create;
	
	ctk_inline_item_select_copy_struct		select_create;
	ctk_inline_item_single_line_copy_struct	single_line_create;
	ctk_inline_item_caption_copy_struct		caption_create;

	// Handle menu data 
    mt = &menuTable[menu][id];
	menu_id = mt->childId; // id != menu_id

	// Create CTK screen
	scrid = widget_ctk_screen_create();

	// set key
	ctk_screen_add_inline_Done_UA(scrid, NULL, meaConfigInlineMenuDone, KAL_TRUE);
	propItem = (MeaPropItem*)data;

	// Create layout
	num_items = getNumItems(mt->menuItems);

	CTK_INIT_STRUCT(layout_create);
#ifdef __OP01_MMS_RETRIEVE_SETTING__
    if (menu_id == MEA_CONFIG_MENU_RETRIEVE) 
    {
        meaConfigSetRoamStatus();
        if ( meaConfigGetRoamStatus()) 
        {
	        layout_create.in_num_items = num_items * 2;
            if (start_index >= num_items)
            {
                start_index = num_items - 1;
            }
        }
        else
        {
            layout_create.in_num_items = (num_items - 1) * 2;
            if (start_index >= num_items - 1)
            {
                start_index = num_items - 1 - 1;
            }
        }
        layout_create.in_highlighted = start_index*2+1;
    } 
    else 
    {
	    layout_create.in_num_items = num_items * 2;
	    layout_create.in_highlighted = start_index*2+1;
    }
#else /*__OP01_MMS_RETRIEVE_SETTING__*/
	layout_create.in_num_items = num_items * 2;
	layout_create.in_highlighted = start_index*2+1;
#endif /*__OP01_MMS_RETRIEVE_SETTING__*/
	layout_create.in_img_title = MEA_IMG_TITLE_NORMAL;
	layout_create.in_str_title = (ctk_string_id) mt->titleStrId;
	layout_create.in_cancel_fp = meaConfigInlineMenuCancel;
	layout_create.in_set_LSK = KAL_TRUE;
	layout_create.in_disable_done = KAL_TRUE; /* Let RSK be Clear/Back */
	
	layoutid  = ctk_inline_create(HDIa_widgetCtkGetApp(), &layout_create);
#ifdef __OP01_MMS_RETRIEVE_SETTING__
    if ( !meaConfigActivateRetrieveMenu( layoutid, menu,  id) )
    {
#endif
	// insert inline items
	for (menu_index = 0; menu_index < num_items; menu_index++)
	{
		menu_item = &menuTable[menu_id][menu_index];

		CTK_INIT_STRUCT(caption_create);
		caption_create.title = (ctk_string_id) menu_item->titleStrId;
		if (menu_item->childId != -1) //sending icon
		{
			ctk_inline_set_item_copy(layoutid, menu_index*2, 
				(U16) (menu_item->childId), 0, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);
		}
		else
		{
		    ctk_inline_set_item_copy(layoutid, menu_index*2, 
			    (U16) (WAP_IMAGE_SW_LIST_NB1 + menu_index), 0, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);
		}

		meaGetConfigData((MeaConfigMenu)menu_id, menu_item->configId, data,//NULL if we don't handle "data"
			&value, &str, &maxTextSize, &textType);
		switch (menu_item->menuType)
		{
			case MEA_SINGLE_LINE_INPUT:
				CTK_INIT_STRUCT(single_line_create);
				single_line_create.input_type = CTK_INPUT_TYPE_DEFAULT; // = 0;
				single_line_create.max_len = maxTextSize;
				single_line_create.default_text = (U8*) str;
				single_line_create.is_UTF8 = KAL_TRUE;
				single_line_create.activation = CTK_INLINE_ACTIVATION_AUTO;
				//ToDo: title string
				ctk_inline_set_item_copy(layoutid, menu_index*2 +1, 0, 0, CTK_INLINE_ITEM_TYPE_SINGLE_LINE, &single_line_create);
				
				break;
			case MEA_RADIO_BUTTON_INPUT:
				CTK_INIT_STRUCT(select_create);
				select_create.highlighted = value;
				select_create.num_options = prepareListOfStrID(menu_item->menuItems, list_of_strid);
				select_create.list_options_strid = list_of_strid;
				ctk_inline_set_item_copy(layoutid, menu_index*2 +1, 0, 0, CTK_INLINE_ITEM_TYPE_SELECT, &select_create);
				
				break;
			default:
				WAP_DBG_ASSERT(0);
				break;
		}

	    /*  Take care of special cases where we have to free allocated data 
	     *  from the meaGetConfigData function.
	     */
	    if (/*EA_CONFIG_MENU_ROOT == menu && 
	         MEA_CONFIG_MMSC == (MeaConfigGroups)mt->configId) ||*/
	        (MEA_CONFIG_MENU_SEND == menu_id &&
	         MEA_CONFIG_SLIDE_DUR == (MeaConfigSend)menu_item->configId) ||
	        (MEA_CONFIG_MENU_FILTER == menu_id &&
	         MEA_CONFIG_IM_SIZE == (MeaConfigFilter)menu_item->configId) ||
	        (MEA_CONFIG_MENU_FILTER == menu_id &&
	         MEA_CONFIG_RETR_SIZE == (MeaConfigFilter)menu_item->configId) ||
	        (MEA_CONFIG_MENU_NETWORK == menu_id && 
	         MEA_CONFIG_SEC_PORT == (MeaConfigNetwork)menu_item->configId) ||
	        (MEA_CONFIG_MENU_NETWORK == menu_id && 
	        MEA_CONFIG_HTTP_PORT == (MeaConfigNetwork)menu_item->configId))
		{
    	   MEA_FREE(str);
		}
	}
#ifdef __OP01_MMS_RETRIEVE_SETTING__
    }
#endif
	// start to display
	ctk_screen_attach_layout(scrid, layoutid);

	{
		mea_config_menu_local_data* localdata;
		localdata = MEA_ALLOC(sizeof(mea_config_menu_local_data));
		localdata->data = data;
		localdata->id = id;
		localdata->menu = menu;
		ctk_screen_set_local_data(scrid, (void *) localdata);
	}

	wnd = HDIa_widgetCtkCreate(MSF_MODID_MEA, scrid);
	meaDisplayWindow(wnd, meaGetPosLeftTop());
	return KAL_FALSE;
}

/*********************************************************************************************
 * specific mms retrieve setting
*********************************************************************************************/
#ifdef __OP01_MMS_RETRIEVE_SETTING__

static MSF_BOOL meaConfigGetRetrieveMenuDispVal(MeaConfigMenu menu_id, int configId, int *pDispValue);
static MSF_BOOL meaConfigGetRetrieveMenuRegVal(int disp1, int disp2, int reg_cfg_id, int *pRegValue);

/***************************************************************************************
#define MEA_CONFIG_MENU_RETRIEVAL_HOME  {MEA_STR_ID_DEL_RETRIEVAL, \        //Delay
                                         MEA_STR_ID_IM_RETRIEVAL, \         //Immediately
                                         MEA_STR_ID_RES_RETRIEVAL_ROAM, 0}  //rejected

#define MEA_CONFIG_MENU_RETRIEVAL_ROAM  {MEA_STR_ID_AUTO_RETRIEVAL_ROAM, \  //as home
                                         MEA_STR_ID_ASK_RETRIEVAL_ROAM, \   //delay
                                         MEA_STR_ID_RES_RETRIEVAL_ROAM, 0}  //rejected

#define MEA_CONFIG_MENU_SEND_READ_REPORT {MEA_STR_ID_CONFIG_ON_REQUEST, \
                                          MEA_STR_ID_CONFIG_ALWAYS, \
                                          MEA_STR_ID_CONFIG_NEVER,0}

#define MEA_CONFIG_MENU_DELIVERY_REPORT_ALLOWED {MEA_STR_ID_YES, \
                                                MEA_STR_ID_NO,0}
****************************************************************************************/
typedef enum
{
    MEA_CFGMENU_RETRIEVE_ALLOWED,        /*!< allow retrieving */
    MEA_CFGMENU_IMMEDIATELY_ROAM,       /*!< Roaming network retrieve immediately */
    MEA_CFGMENU_DELIVERY_REPORT_ALLOWED,/*!< Delivery report allowed */
    MEA_CFGMENU_SEND_READ_REPORT,       /*!< Send read report */
    MEA_CFGMENU_RETRIEVE_COUNT          /*!< Not used, it is just a counter */
}MeaConfigRetrieveDisp;                 /*!< for display */

enum MeaAllowRetrievingValue{
    MeaAllowRetrievingYes,
    MeaAllowRetrievingNo
};

enum MeaRoamRetrieveImmediately{
    MeaRoamRetrieveImYes,
    MeaRoamRetrieveImNo
};

/*
typedef enum
{
    MEA_RETRIEVAL_MODE_ALWAYS_ASK = 0,	// < Delayed retrieval mode //
    MEA_RETRIEVAL_MODE_AUTOMATIC  = 1,	// < Immediate retrieval mode //
    MEA_RETRIEVAL_MODE_RESTRICTED = 2
}MeaRetrievalModeType;

typedef enum
{
    MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC  = 0,  // < Use same setting as home
    MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK = 1,  // < Delayed retrieval mode 
    MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED = 2   // < Restricted mode 
}MeaRetrievalModeRoamingType;
*/


/* value of DeliveryReportAllowed displayed in screen */
enum MeaDeliveryReportAllowedValue{
    MeaDeliveryReportNo,
    MeaDeliveryReportYes
};

/*
typedef enum
{
    MEA_DELIVERY_REPORT_YES,            //< Always send read report //
    MEA_DELIVERY_REPORT_NO              //< Never send read report  //
}MeaDeliveryReportType;
*/

/* value of send read report  displayed in screen */
enum MeaSendReadReportValue{
    MeaSendReadReportNo,
    MeaSendReadReportYes
};
/*
typedef enum
{   
    MEA_SEND_READ_REPORT_ON_REQUEST = 0,    //< Send read report on request //
    MEA_SEND_READ_REPORT_ALWAYS,            //< Always send read report //
    MEA_SEND_READ_REPORT_NEVER              //< Never send read report //
}MeaSendReadReportType;
*/
extern MSF_UINT32   ROAMING_STATUS; /*defined in mms_aapp.c*/
static MSF_BOOL  meaConfigRoamStatus = FALSE;   
static MSF_BOOL meaConfigSetRoamStatus(void)
{
    /*when power off abnormally, meaGetConfig()->roamingStatus is error*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* when power off abnormally, meaGetConfig()->roamingStatus is error*/
    meaConfigRoamStatus = ROAMING_STATUS; 
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAUICONF_EF1DB3753F68AA3FF4C921E6A636EA52, "meaConfigSetAndGetRoamStatus(MMS) = (%d)", meaConfigRoamStatus));

    return meaConfigRoamStatus;

}

static MSF_BOOL meaConfigGetRoamStatus(void)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAUICONF_33968A61A01A9C2E76DBC9D8696D3764, "meaConfigGetRoamStatus = (%d)", meaConfigRoamStatus));
    return meaConfigRoamStatus;
}

static MSF_BOOL meaConfigSaveRetrieveMenuValue(ctk_layout_handle layout_id, int menu_id, int *fail_index)
{
	// MEA 
    const MeaMenuTable	*menu_item; // each item    
    int 			index;
    int             allow_retrieve, roam_im, reg_value;
    ctk_inline_item_type_enum	item_type;
    ctk_inline_result_union		item_value;

    if (menu_id != MEA_CONFIG_MENU_RETRIEVE) // only handle Retrieve Menu
    {
        return FALSE;
    }

    /* handle allow retrieving and roam network immediately */
    index = MEA_CFGMENU_RETRIEVE_ALLOWED * 2 + 1;
    ctk_inline_get_result(layout_id, index, &item_type, &item_value);
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_SELECT);
    allow_retrieve = item_value.select_highlight;

    if ( meaConfigGetRoamStatus() )
    {
        index = MEA_CFGMENU_IMMEDIATELY_ROAM * 2 + 1;
        ctk_inline_get_result(layout_id, index, &item_type, &item_value);
        ASSERT(item_type == CTK_INLINE_ITEM_TYPE_SELECT);
        roam_im = item_value.select_highlight;
    }
    else
    {
        meaConfigGetRetrieveMenuDispVal( menu_id, MEA_CFGMENU_IMMEDIATELY_ROAM, &roam_im);
    }

    meaConfigGetRetrieveMenuRegVal(allow_retrieve, roam_im, MEA_CONFIG_HOME_NETWORK, &reg_value);
    menu_item = &menuTable[menu_id][MEA_CONFIG_HOME_NETWORK];
	if (menu_item->callback(NULL, reg_value, propItem, 0) == FALSE)
	{
		WAP_DBG_ASSERT(0); // This should NOT happen
		*fail_index = MEA_CFGMENU_RETRIEVE_ALLOWED;
        return KAL_FALSE;
	}

    meaConfigGetRetrieveMenuRegVal(allow_retrieve, roam_im, MEA_CONFIG_ROAM_NETWORK, &reg_value);
    menu_item = &menuTable[menu_id][MEA_CONFIG_ROAM_NETWORK];
	if (menu_item->callback(NULL, reg_value, propItem, 0) == FALSE)
	{
		WAP_DBG_ASSERT(0); // This should NOT happen
		*fail_index = MEA_CFGMENU_IMMEDIATELY_ROAM;
        return KAL_FALSE;
	}

    /* handle delivery report allowed */
    if ( meaConfigGetRoamStatus() )
    {
        index = MEA_CFGMENU_DELIVERY_REPORT_ALLOWED * 2 + 1;
    }
    else
    {
        index = (MEA_CFGMENU_DELIVERY_REPORT_ALLOWED-1) * 2 + 1;
    }        
    ctk_inline_get_result(layout_id, index, &item_type, &item_value);
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_SELECT);
    meaConfigGetRetrieveMenuRegVal(item_value.select_highlight, 0, MEA_CONFIG_DELIVERY_REPORT_ALLOWED, &reg_value);
    menu_item = &menuTable[menu_id][MEA_CONFIG_DELIVERY_REPORT_ALLOWED];
   	if (menu_item->callback(NULL, reg_value, propItem, 0) == FALSE)
	{
		WAP_DBG_ASSERT(0); // This should NOT happen
		*fail_index = MEA_CFGMENU_DELIVERY_REPORT_ALLOWED;
        return KAL_FALSE;
	}

    /* handle send read report */
    if ( meaConfigGetRoamStatus() )
    {
        index = MEA_CFGMENU_SEND_READ_REPORT * 2 + 1;
    }
    else
    {
        index = (MEA_CFGMENU_SEND_READ_REPORT-1) * 2 + 1;
    }        
    ctk_inline_get_result(layout_id, index, &item_type, &item_value);
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_SELECT);
    meaConfigGetRetrieveMenuRegVal(item_value.select_highlight, 0, MEA_CONFIG_SEND_READ_REPORT, &reg_value);
    menu_item = &menuTable[menu_id][MEA_CONFIG_SEND_READ_REPORT];
   	if (menu_item->callback(NULL, reg_value, propItem, 0) == FALSE)
	{
		WAP_DBG_ASSERT(0); // This should NOT happen
		*fail_index = MEA_CFGMENU_SEND_READ_REPORT;
        return KAL_FALSE;
	}

    return TRUE;
}

static MSF_BOOL meaConfigActivateRetrieveMenu( ctk_layout_handle layoutid, MeaConfigMenu menu, int id)
{
 	// MEA
	const MeaMenuTable 			*mt; // main menu
	const MeaMenuTable			*menu_item; // each item
	int						menu_id;
	int						menu_index, index = 0;
	U16						list_of_strid[MEA_CONFIG_MAX_MENU_DEPTH];

	int 					value;// maxTextSize;
 
	// CTK
	int 							num_items;
	
	ctk_inline_item_select_copy_struct		select_create;
	ctk_inline_item_caption_copy_struct		caption_create;

	// Handle menu data 
    mt = &menuTable[menu][id];
	menu_id = mt->childId; // id != menu_id
    if (menu_id != MEA_CONFIG_MENU_RETRIEVE) // only handle Retrieve Menu
        return FALSE;
	num_items = getNumItems(mt->menuItems);

	// insert inline items
	for (menu_index = 0; menu_index < num_items; menu_index++)
	{
        if ( (menu_index == MEA_CFGMENU_IMMEDIATELY_ROAM) && (!meaConfigGetRoamStatus()))
        {
            continue;
        }
		menu_item = &menuTable[menu_id][menu_index];

		CTK_INIT_STRUCT(caption_create);
		caption_create.title = (ctk_string_id) menu_item->titleStrId;
		if (menu_item->childId != -1) //sending icon
		{
			ctk_inline_set_item_copy(layoutid, index*2, 
				(U16) (menu_item->childId), 0, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);
		}
		else
		{
		    ctk_inline_set_item_copy(layoutid, index*2, 
			    (U16) (WAP_IMAGE_SW_LIST_NB1 + index), 0, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);
		}
/*
		meaGetConfigData((MeaConfigMenu)menu_id, menu_item->configId, data,//NULL if we don't handle "data"
			&value, &str, &maxTextSize, &textType);
        */
        meaConfigGetRetrieveMenuDispVal((MeaConfigMenu)menu_id, menu_index, &value);
        WAP_DBG_ASSERT(menu_item->menuType==MEA_RADIO_BUTTON_INPUT);

		CTK_INIT_STRUCT(select_create);
		select_create.highlighted = value;
		select_create.num_options = prepareListOfStrID(menu_item->menuItems, list_of_strid);
		select_create.list_options_strid = list_of_strid;
		ctk_inline_set_item_copy(layoutid, index*2 +1, 0, 0, CTK_INLINE_ITEM_TYPE_SELECT, &select_create);

        index++;
	}
    return TRUE;
}
/**************************************************************
 * get value which will be set to registry
 **************************************************************/
static MSF_BOOL meaConfigGetRetrieveMenuRegVal(int disp1, int disp2, int reg_cfg_id, int *pRegValue)
{

    /* Allow Retrieving */
    if (reg_cfg_id == MEA_CONFIG_HOME_NETWORK)
    {
        if (disp1 == MeaAllowRetrievingYes)
        {
            *pRegValue = MEA_RETRIEVAL_MODE_AUTOMATIC;
        }           
        else if(disp1 == MeaAllowRetrievingNo)
        {
            *pRegValue = MEA_RETRIEVAL_MODE_RESTRICTED;
        }           
        else
        {
            ASSERT(0);
        }           
    }
    else if (reg_cfg_id == MEA_CONFIG_ROAM_NETWORK) /*Roam immediatly retrieve */
    { 
        if ( (disp1 == MeaAllowRetrievingYes) && (disp2 == MeaRoamRetrieveImNo))
        {
            *pRegValue = MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK;
        }           
        else if ( ((disp1 == MeaAllowRetrievingYes) && (disp2 == MeaRoamRetrieveImYes))
           ||((disp1 == MeaAllowRetrievingNo) && (disp2 == MeaRoamRetrieveImYes)) )
        {
           *pRegValue = MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC;
        }
        else if ((disp1 == MeaAllowRetrievingNo) && (disp2 == MeaRoamRetrieveImNo))
        {
            *pRegValue = MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED;
        }
        else
        {
            ASSERT(0);
        }
    } 
    else if (reg_cfg_id == MEA_CONFIG_DELIVERY_REPORT_ALLOWED)  /* delivery report */
    { 
        if (disp1 == MeaDeliveryReportYes)
        {
            *pRegValue = MEA_DELIVERY_REPORT_YES;
        }
        else if (disp1 == MeaDeliveryReportNo)
        {
            *pRegValue = MEA_DELIVERY_REPORT_NO;
        }
        else
        {
            ASSERT(0);
        }
    }
    else if (reg_cfg_id == MEA_CONFIG_SEND_READ_REPORT) /* send read report */
    { 
        if (disp1 == MeaSendReadReportYes)
        {
            *pRegValue = MEA_SEND_READ_REPORT_ALWAYS;
        }            
        else if (disp1 == MeaSendReadReportNo)
        {
            *pRegValue = MEA_SEND_READ_REPORT_NEVER;
        }
        else
        {
            ASSERT(0);
        }
    }
    return TRUE;
}

static MSF_BOOL meaConfigGetRetrieveMenuDispVal(MeaConfigMenu menu_id, int configId, int *pDispValue)
{
    int     nHomeRegVal, nRoamRegVal, nRegVal;
    char  * str;
    int     maxTextSize;
    MsfTextType textType;

    if (menu_id != MEA_CONFIG_MENU_RETRIEVE)
        return FALSE;

    /* Allow Retrieving */
    if (configId == MEA_CFGMENU_RETRIEVE_ALLOWED)  {
        meaGetConfigData((MeaConfigMenu)menu_id, MEA_CONFIG_HOME_NETWORK, NULL,
			&nHomeRegVal, &str, &maxTextSize, &textType);

        meaGetConfigData((MeaConfigMenu)menu_id, MEA_CONFIG_ROAM_NETWORK, NULL,
			&nRoamRegVal, &str, &maxTextSize, &textType);
        if ( ((nHomeRegVal == MEA_RETRIEVAL_MODE_AUTOMATIC)&&(nHomeRegVal == MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK))
          || ((nHomeRegVal == MEA_RETRIEVAL_MODE_AUTOMATIC)&&(nRoamRegVal == MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC)))
        {
            *pDispValue = MeaAllowRetrievingYes; //Allow Retrieving: yes
        } 
        else if  ( ((nHomeRegVal == MEA_RETRIEVAL_MODE_RESTRICTED)&&(nHomeRegVal == MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED))
          || ((nHomeRegVal == MEA_RETRIEVAL_MODE_RESTRICTED)&&(nRoamRegVal == MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC))) 
        {
            *pDispValue = MeaAllowRetrievingNo; //Allow Retrieving: yes
        }
        else
        {
            *pDispValue = MeaAllowRetrievingYes; //set to default value, compatible with MTK setting
        }
    }
    else if (configId == MEA_CFGMENU_IMMEDIATELY_ROAM) /*Roam immediatly retrieve */
    { 
        meaGetConfigData((MeaConfigMenu)menu_id, MEA_CONFIG_HOME_NETWORK, NULL,
			&nHomeRegVal, &str, &maxTextSize, &textType);
        meaGetConfigData((MeaConfigMenu)menu_id, MEA_CONFIG_ROAM_NETWORK, NULL,
			&nRoamRegVal, &str, &maxTextSize, &textType);
        if ( ((nHomeRegVal == MEA_RETRIEVAL_MODE_AUTOMATIC) && (nRoamRegVal == MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC))  //home:immediately   roam:as home
           ||((nHomeRegVal == MEA_RETRIEVAL_MODE_RESTRICTED)&& (nRoamRegVal == MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC)))
        {
            *pDispValue = MeaRoamRetrieveImYes; //roam immediately retrieve : yes
        } 
        else if (((nHomeRegVal == MEA_RETRIEVAL_MODE_AUTOMATIC) && (nRoamRegVal == MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK))  //home:immediately   roam:as home
              || ((nHomeRegVal == MEA_RETRIEVAL_MODE_RESTRICTED)&& (nRoamRegVal == MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED)))
        {
            *pDispValue = MeaRoamRetrieveImNo; //roam immediately retrieve : no
        }
        else
        {
            *pDispValue = MeaRoamRetrieveImYes; //set to default value, compatible with MTK setting
        }
    } 
    else if (configId == MEA_CFGMENU_DELIVERY_REPORT_ALLOWED)  /* delivery report */
    { 
        meaGetConfigData((MeaConfigMenu)menu_id, MEA_CONFIG_DELIVERY_REPORT_ALLOWED, NULL,
			&nRegVal, &str, &maxTextSize, &textType);
        if (nRegVal == MEA_DELIVERY_REPORT_YES)  //delivery report : yes (in registry)
        {
            *pDispValue = MeaDeliveryReportYes; //delivery report : yes(for display)
        } 
        else if (nRegVal == MEA_DELIVERY_REPORT_NO) 
        {
            *pDispValue = MeaDeliveryReportNo; //delivery report : no(for display, defualt)
        }
        else
        {
            ASSERT(0);
        }
    }
    else if (configId == MEA_CFGMENU_SEND_READ_REPORT) /* send read report */
    { 
       meaGetConfigData((MeaConfigMenu)menu_id, MEA_CONFIG_SEND_READ_REPORT, NULL,
			&nRegVal, &str, &maxTextSize, &textType);
        if (nRegVal == MEA_SEND_READ_REPORT_ALWAYS)  //send read report : MEA_STR_ID_CONFIG_ALWAYS (in registry)
        {
            *pDispValue = MeaSendReadReportYes; //send read report : yes(for display)
        }
        else if (nRegVal == MEA_SEND_READ_REPORT_NEVER)
        {
            *pDispValue = MeaSendReadReportNo; //send read report  : no(for display, defualt)
        }
        else if (nRegVal == MEA_SEND_READ_REPORT_ON_REQUEST)
        {
            *pDispValue = MeaSendReadReportNo; //send read report  : no(for display, defualt)
        }
        else
        {
            ASSERT(0);
        }
    }
    return TRUE;
}


#endif /* __OP01_MMS_RETRIEVE_SETTING__*/
#else /* WAP_SUPPORT */

/*!
 * \brief Creates a list of network accounts.
 *        This function creates a widget string for each account name
 *        and puts it in a list allocated by the function. 
 * \return The list of string handles on success, otherwise NULL.
 *****************************************************************************/
static MsfStringHandle *createNetworkAccountList(void)
{
    int id;
    int index;
    int accountCount;
    MsfStringHandle *strings;
    char buffer[NET_ACCOUNT_BUFF_LEN];

    /* Count total number of network accounts */
    accountCount = 0;
    id = MSF_NETWORK_ACCOUNT_GET_FIRST();
    while(id >= 0)
    {
        ++accountCount;
        id = MSF_NETWORK_ACCOUNT_GET_NEXT(id);
    }

    if (accountCount > MEA_CONFIG_MAX_MENU_DEPTH) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUICONF_180DE993D037E1C8B4D84C67600D6816, "(%s) (%d) WARNING! Not all network accounts could be enumerated\n", 
            __FILE__, __LINE__));        
    }
    
    strings = MEA_ALLOC((unsigned int)(accountCount + 1) * 
        sizeof(MsfStringHandle));

    /* Add items to the list */
    id = MSF_NETWORK_ACCOUNT_GET_FIRST();
    index = 0;
    while (id >= 0 && index < (MEA_CONFIG_MAX_MENU_DEPTH - 1))
    {
        //long srcLen;
        //memset(buffer, 0, 40);
        //if (0 > MSF_NETWORK_ACCOUNT_GET_NAME(id, buffer, 40))
        if (0 > MSF_NETWORK_ACCOUNT_GET_NAME(id, buffer, NET_ACCOUNT_BUFF_LEN))
        {
            MEA_FREE(strings);
            return NULL;
        }
        strings[index] = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, buffer, 
            MsfUtf8, (int)strlen(buffer) + 1, 0);
        if (0 == strings[index])
        {
            MEA_FREE(strings);
            return NULL;
        }
        index++;
        id = MSF_NETWORK_ACCOUNT_GET_NEXT(id);
    }
    /* Set an end marker last in the list */
    strings[index] = 0;
    return strings;
}
#endif /* WAP_SUPPORT */

/*!
 * \brief Allocates an array of string handles.
 *
 * \param items An array of resource IDs
 * \param size The size in bytes of the array.
 * \return The newly allocated array if everything was ok or else the old
 *          array.
 *****************************************************************************/
static MsfStringHandle *getStrItems(const MsfStringHandle items[], int size)
{
    int i, n;
    MsfStringHandle *tmpItems;
    tmpItems = MEA_ALLOC((unsigned)size);
    for (i = 0, n = 1; items[i] != 0; i++)
    {
        tmpItems[i] = MEA_GET_STR_ID(items[i]);
        n++;
    }
    tmpItems[n - 1] = 0;
    return tmpItems;
} /*getStrItems*/

/*!
 *  \brief Activates an arbitrary configuration menu.
 *  \param menu The menu to activate.
 *  \param id The ID of the form to activate. See #MeaConfigGroups
 *            #MeaConfigFilter, #MeaConfigSend.
 *  \param data If not NULL then this data will be set instead of global
 *              configuration data.
 *  \return Always FALSE since the form should stay visible until we close it.
 *****************************************************************************/
MSF_BOOL meaConfigActivateMenu(MeaConfigMenu menu, int id, void *data)
{
    MeaInputItem item;
    int value, maxTextSize;
    char *str;
    MsfTextType textType;
    MeaMenuTable *mt;
    
    mt = (MeaMenuTable *)&menuTable[menu][id];
#ifdef WAP_SUPPORT
	//if (mt->childId==/*4*/-2) //profile Jo 030902
	if (menu == MEA_CONFIG_MENU_ROOT && id == MEA_CONFIG_NETWORK)
	{
		bra_create_ui(BRA_UI_PROF_MENU);
		return FALSE;
	}
	if (menu == MEA_CONFIG_MENU_ROOT && id == MEA_CONFIG_COMPOSE)
	{
		meaCreateConfComposeView();
		return FALSE;
	}	
	if (menu == MEA_CONFIG_MENU_ROOT && id == MEA_CONFIG_MEMORY_STATUS)
	{
		meaCreateConfMemoryStatusView();
		return FALSE;
	}
	if (menu == MEA_CONFIG_MENU_ROOT || menu == MEA_CONFIG_MENU_MMS_SETTINGS)
	{
		return meaConfigActivateInlineMenu(menu, id, data, 0);
	}
	// It should not come here
	WAP_DBG_ASSERT(menu == MEA_CONFIG_MENU_DEFAULT);	
#endif /* WAP_SUPPORT */

    item.dataPtr = data;
    item.uintValue = (unsigned int)mt->childId;
    item.callback = mt->callback;
    item.backCallback = mt->backCallback;
    item.type = mt->menuType;
    item.items = NULL;
    str = NULL;
    switch (item.type)
    {
    case MEA_TEXT_INPUT:
    case MEA_SINGLE_LINE_INPUT:
        meaGetConfigData(menu, mt->configId, data,
            &value, &str, &maxTextSize, &textType);
        item.selectedItem = value;
        item.maxTextSize = (unsigned)maxTextSize;
        item.textType = textType;
        item.text = str;
        break;
    case MEA_RADIO_BUTTON_INPUT:
    case MEA_SELECT_INPUT:
        meaGetConfigData(menu, mt->configId, data,
            &value, &str, &maxTextSize, &textType);
        item.selectedItem = value;
        if (MEA_CONFIG_MENU_NETWORK == menu &&
            MEA_CONFIG_NET_ACCOUNT == (MeaConfigNetwork)id) 
        {
            /*  Special case since the network account strings are dynamic. 
             *  The string handles needs to be released after the form is 
             *  closed and for this purpose the string handles are saved in
             *  the menuTable. */
#ifndef WAP_SUPPORT
            item.items = createNetworkAccountList();
#endif /* ~WAP_SUPPORT */
        }
        else
        {
            item.items = getStrItems(mt->menuItems, 
                sizeof(mt->menuItems));
        }
        break;
    default:
        break;
    }
    (void)meaCreateInputForm(&item, MEA_GET_STR_ID(mt->titleStrId));
    
    /*  Take care of special cases where we have to free allocated data 
     *  from the meaGetConfigData function.
     */
    if ((MEA_CONFIG_MENU_ROOT == menu && 
         MEA_CONFIG_MMSC == (MeaConfigGroups)mt->configId) ||
        (MEA_CONFIG_MENU_SEND == menu &&
         MEA_CONFIG_SLIDE_DUR == (MeaConfigSend)mt->configId) ||
        (MEA_CONFIG_MENU_FILTER == menu &&
         MEA_CONFIG_IM_SIZE == (MeaConfigFilter)mt->configId) ||
        (MEA_CONFIG_MENU_FILTER == menu &&
         MEA_CONFIG_RETR_SIZE == (MeaConfigFilter)mt->configId) ||
        (MEA_CONFIG_MENU_NETWORK == menu && 
         MEA_CONFIG_SEC_PORT == (MeaConfigNetwork)mt->configId) ||
        (MEA_CONFIG_MENU_NETWORK == menu && 
         MEA_CONFIG_HTTP_PORT == (MeaConfigNetwork)mt->configId))
    {
        MEA_FREE(str);
    }

    /*  Special case since the network account strings are dynamic. 
     *  The string handles needs to be released after the form is 
     *  created.
     */
    if (MEA_CONFIG_MENU_NETWORK == menu &&
        MEA_CONFIG_NET_ACCOUNT == (MeaConfigNetwork)mt->configId) 
    {
        releaseNetworkAccountList(&(item.items));
    }

    MEA_FREE(item.items);
    item.items = NULL;
    return FALSE;
} /*meaConfigActivateMenu*/

/*!
 *  \brief Handles the selection of configuration type.
 * \param  str N/A.
 * \param  value The selected menu item.
 * \param  p1 N/A.
 * \param  p2 The new menu to show.
 * \return Always FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL 
meaConfigMenuCallback(char *str, int value, void *p1, int p2)
{
    if (str)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
            MAUICONF_22A3CC5FB120F4F91A8D7F9BE884D7BD, "(%s) (%d) Meaningless logging to avoid warnings\n", __FILE__, 
            __LINE__));
    }
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MAUICONF_085152B6BD22201A1196EB106D7D207A, "(%s) (%d) Callback for root menu\n", __FILE__, 
        __LINE__));
    return meaConfigActivateMenu((MeaConfigMenu)p2, value, p1);
} /*meaConfigMenuCallback*/

/*!
 * \brief  Handles the Back-action from the settings menu.
 * \param  p1 N/A.
 * \param  p2 The new menu to show.
 * \return Always FALSE.
 *****************************************************************************/
/*lint -e{818} */
void meaConfigMenuBackCallback(void *p1, int p2)
{
    if (p1 || p2)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
            MAUICONF_22A3CC5FB120F4F91A8D7F9BE884D7BD, "(%s) (%d) Meaningless logging to avoid warnings\n", __FILE__, 
            __LINE__));
    }
    /* If it is the last menu we send a signal to maconf so it can
     * deactivate the module if necessary */
    (void)MEA_SIGNAL_SENDTO(MEA_CONFIG_FSM, MEA_SIG_CONF_DEACTIVATE);            
} /*meaConfigMenuBackCallback*/

/*!
 * \brief Initiates internal data-structures for the config view.
 *
 *****************************************************************************/
void meaConfigUiInit()
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MAUICONF_0D76FFCD7CC8A15989304B8D3533A644, "(%s) (%d) Initiating config UI\n", __FILE__, __LINE__));
} /*meaConfigUiInit*/

/*!
 * \brief Frees a list of network account strings.
 *****************************************************************************/
/*lint -e{818} */
static void releaseNetworkAccountList(MsfStringHandle **list)
{
    int i = 0;
    while ((*list)[i] && i < MEA_CONFIG_MAX_MENU_DEPTH) 
    {
        (void)MSF_WIDGET_RELEASE((*list)[i]);
        (*list)[i++] = 0;
    }
} /*releaseNetworkAccountList*/

