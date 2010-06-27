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
 *  BarcodeReader.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_BARCODEREADER__

#ifndef __MMI_CAMERA__
#error "Please turn on __MMI_CAMERA__"
#endif 


#include "lcd_if.h"     /* LCD layer enable flag */
#include "lcd_sw_rnd.h" /* for LCD size */

#include "MMI_features_barcodereader.h" /* features */


#ifdef __MTK_TARGET__
#include "nvram_data_items.h"   /* ID to store file path */
#endif /* __MTK_TARGET__ */ 

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#include "drm_def.h"
#include "DRM_main.h"
#endif /* __DRM_SUPPORT__ */ 


/* framework related headers */
#include "gui.h"        /* Gui functions */
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "wgui.h"       /* for GetDateTime() */
#include "CommonScreens.h"      /* DisplayPopup() */
#include "gpioInc.h"    /* LED */
#include "SettingProfile.h"
#include "wgui_status_icons.h"
#include "wgui_softkeys.h"
#include "FileManagerGProt.h"   /* file path */
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "FileMgrStruct.h"
#include "mmiapi_enum.h"        /* Stop LED */
#include "MainMenuDef.h"        /* Multimedia icon */
#include "ProfileGprots.h"      /* playRequestedTone */
#include "SimDetectionGprot.h"
#include "conversions.h"


/************************************************************************
* Supported functions related header file
************************************************************************/
#include "CallManagementGprot.h"        /* for call management related functions */
#include "SMSApi.h"     /* for SMS related functions */
#include "wap_ps_struct.h"      /* for wap related functions */
#include "PhonebookTypes.h"     /* for phonebook related functions */
#include "phonebookgprot.h"     /* for phonebook related functions */

/* gdi, mid headers */
#include "gdi_image_jpeg.h"     /* jpeg decoder */
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_audio.h"

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

#ifdef __MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__
#include "wgui_touch_screen.h"
#endif /* __MMI_BARCODEREADER_FEATURE_TOUCH_SCREEN__ */

#include "resource_barcodereader_skins.h"       /* UI custom config */
#include "BarcodeReader.h"      /* camera app data */
#include "BarcodeReaderGprot.h"
#include "barcodereaderResDef.h"       /* resource ID def */

#include "gui_setting.h"
#include "wgui.h"
#include "wgui_title.h"
#include "wapadp.h"
#include "USBDeviceGprot.h"
#include "app_datetime.h"
#include "datetimetype.h"

/*envent interupt .h*/
#include "ProtocolEvents.h"
#include "CommonScreens.h"

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "NetworkSetupDefs.h"
#include "VoIPGProt.h"
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#include "EmailAppProt.h"
#endif

#include "CameraGprot.h"

#if defined(__MMI_DUAL_SIM_MASTER__)
#include "MTPNP_AD_master_header.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif /*__MMI_UCM__*/

//#define __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__

/****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/
extern BOOL r2lMMIFlag;
extern fmgr_context_struct *fmgr_p ;
static S8 mmi_barcode_urlHttp[10] = {0x68, 0x74, 0x74, 0x70, 0x3a, 0x1b, 0x5c, 0x1b, 0x5c, 0x00};
static S8 mmi_barcode_urlHttps[11] = {0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x1b, 0x5c, 0x1b, 0x5c, 0x00};
static const PS8 mmi_barcode_urlPattern[MMI_BARCODEREADER_MAX_NUM_URL_PATTERN] = { "http", "www.", "wap." };
static const U16 mmi_barcode_urlPattern_length[MMI_BARCODEREADER_MAX_NUM_URL_PATTERN] = {4, 4, 4};
static const PS8 mmi_barcode_urlValidHttpPrefix[MMI_BARCODEREADER_MAX_NUM_VALID_HTTP_PREFIX] =
    { "http://", "http:\\\\", mmi_barcode_urlHttp, "https://", "https:\\\\", mmi_barcode_urlHttps};
#ifdef __MMI_BARCODEREADER_OPERATOR1__
static mmi_barcodereader_attribute_struct mmi_barcodereader_attribute[] =
{
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_N,	        MMI_BARCODEREADER_ATTRIBUTE_VALUE_N     ,   STR_ID_BARCODEREADER_ATTR_N      },
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_TIL,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_TIL   ,	STR_ID_BARCODEREADER_ATTR_TIL    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_DIV,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_DIV   ,	STR_ID_BARCODEREADER_ATTR_DIV    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_COR,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_COR   ,	STR_ID_BARCODEREADER_ATTR_COR    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_ADR,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_ADR   ,	STR_ID_BARCODEREADER_ATTR_ADR    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_ZIP,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_ZIP   ,	STR_ID_BARCODEREADER_ATTR_ZIP    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_M,	        MMI_BARCODEREADER_ATTRIBUTE_VALUE_M     ,	STR_ID_BARCODEREADER_ATTR_M      },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_FAX,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_FAX   ,	STR_ID_BARCODEREADER_ATTR_FAX    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_EM,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM    ,	STR_ID_BARCODEREADER_ATTR_EM     },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_SM,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_SM    ,	STR_ID_BARCODEREADER_ATTR_SM     },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_TO,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_TO    ,	STR_ID_BARCODEREADER_ATTR_TO     },   
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_SUB,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB   ,	STR_ID_BARCODEREADER_ATTR_SUB    },
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_TXT,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_TXT   ,	STR_ID_BARCODEREADER_ATTR_TXT    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_INTR,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_INTR  ,	STR_ID_BARCODEREADER_ATTR_INTR   },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_CT,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_CT    ,	STR_ID_BARCODEREADER_ATTR_CT     },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_TYPE,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_TYPE  ,	STR_ID_BARCODEREADER_ATTR_TYPE   },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_URL,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL   ,	STR_ID_BARCODEREADER_ATTR_URL    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_DG,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_DG    ,	STR_ID_BARCODEREADER_ATTR_DG     },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_TEL,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL   ,	STR_ID_BARCODEREADER_ATTR_TEL    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_LEN,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_LEN   ,	STR_ID_BARCODEREADER_ATTR_LEN    },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_FILE,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_FILE  ,	STR_ID_BARCODEREADER_ATTR_FILE   },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_CR,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_CR    ,	STR_ID_BARCODEREADER_ATTR_CR     },  
    {   MMI_BARCODEREADER_ATTRIBUTE_NAME_SID,	    MMI_BARCODEREADER_ATTRIBUTE_VALUE_SID   ,	STR_ID_BARCODEREADER_ATTR_SID    }  
};
static mmi_barcodereader_applist_struct mmi_barcodereader_applist[] = 
{
    {MMI_BARCODEREADER_APP_VCARD_ID,    MMI_BARCODEREADER_APP_VCARD},
    {MMI_BARCODEREADER_APP_EMAIL_ID,    MMI_BARCODEREADER_APP_EMAIL},
    {MMI_BARCODEREADER_APP_SMS_ID,      MMI_BARCODEREADER_APP_SMS},
    {MMI_BARCODEREADER_APP_DTXT_ID,     MMI_BARCODEREADER_APP_DTXT},
    {MMI_BARCODEREADER_APP_SMSSELL_ID,  MMI_BARCODEREADER_APP_SMSSELL},
    {MMI_BARCODEREADER_APP_WAPSELL_ID,  MMI_BARCODEREADER_APP_WAPSELL},
    {MMI_BARCODEREADER_APP_IVRSELL_ID,  MMI_BARCODEREADER_APP_IVRSELL}
};
#define MMI_BARCODEREADER_CURRENT_APP_COUNT (sizeof(mmi_barcodereader_applist) / sizeof(mmi_barcodereader_applist[0]))
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#define DUMMY_COMMAND      (0)

#define MMI_BARCODEREADER_AF_LARGE_WIDTH               (25)
#define MMI_BARCODEREADER_AF_NORMAL_WIDTH           (25)
#define MMI_BARCODEREADER_AF_SMALL_WIDTH               (25)

#define MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(X,Y,TMP)\
            TMP=X;                                  \
            X=Y;                                    \
            Y=(LCD_WIDTH-1)-TMP;

#define  MMI_BARCODEREADER_IS_NUM(c)  (((c)>='0') && ((c)<='9'))

/****************************************************************************
* Setting command map                                                                
*****************************************************************************/

/* mapping mmi settings to mdi command. */

/*********** EV ***********/
const U8 barcodereader_ev_command_map[MMI_BARCODEREADER_SETTING_EV_COUNT + 1] = 
{
#ifdef __MMI_BARCODEREADER_EV_4__
    MDI_CAMERA_EV_N4,   /* CAMERA_SETTING_EV_N4 */
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    MDI_CAMERA_EV_N3,   /* CAMERA_SETTING_EV_N3 */
#endif 

#ifdef __MMI_BARCODEREADER_EV_2__
    MDI_CAMERA_EV_N2,   /* CAMERA_SETTING_EV_N2 */
#endif 

    MDI_CAMERA_EV_N1,   /* CAMERA_SETTING_EV_N1 */
    MDI_CAMERA_EV_0,    /* CAMERA_SETTING_EV_0 */
    MDI_CAMERA_EV_P1,   /* CAMERA_SETTING_EV_P1 */

#ifdef __MMI_BARCODEREADER_EV_2__
    MDI_CAMERA_EV_P2,   /* CAMERA_SETTING_EV_P2 */
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    MDI_CAMERA_EV_P3,   /* CAMERA_SETTING_EV_P3 */
#endif 

#ifdef __MMI_BARCODEREADER_EV_4__
    MDI_CAMERA_EV_P4,   /* CAMERA_SETTING_EV_P4 */
#endif 
    DUMMY_COMMAND
};

const U8 barcodereader_flash_command_map[MMI_BARCODEREADER_SETTING_FLASH_COUNT + 1] = 
{
    MDI_CAMERA_FLASH_OFF,   /* CAMERA_SETTING_FLASH_OFF */
    MDI_CAMERA_FLASH_ON,    /* CAMERA_SETTING_FLASH_ON */
    DUMMY_COMMAND
};
const U8 barcodereader_focus_mode_command_map[MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT + 1] = 
{

    MDI_CAMERA_AUTOFOCUS_MODE_AUTO,

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    MDI_CAMERA_AUTOFOCUS_MODE_MACRO,
#endif 
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    MDI_CAMERA_AUTOFOCUS_MODE_MANUAL,
#endif 
    DUMMY_COMMAND
};
const U8 barcodereader_banding_command_map[MMI_BARCODEREADER_SETTING_BANDING_COUNT + 1] = 
{
    MDI_CAMERA_BANDING_50HZ,
    MDI_CAMERA_BANDING_60HZ,
    DUMMY_COMMAND
};



/***************************************************************************** 
* Enum
*****************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_STATE_EXIT = 0,
    MMI_BARCODEREADER_STATE_PREVIEW,
    MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE,
    MMI_BARCODEREADER_STATE_OPTION_MENU,
    MMI_BARCODEREADER_STATE_ALL
} barcodereader_state_enum;

/* BarcodeReader Context */
typedef struct
{
    /* strings for inline selection display */
    /* +1 avoid this feature's item is zero */
    UI_string_type flash_str[MMI_BARCODEREADER_FLASH_ITEM_COUNT + 1];
    UI_string_type ev_str[MMI_BARCODEREADER_EV_ITEM_COUNT + 1];
    UI_string_type af_mode_str[MMI_BARCODEREADER_FOCUS_MODE_ITEM_COUNT + 1];
    UI_string_type storage_str[MMI_BARCODEREADER_STORAGE_ITEM_COUNT + 1];
    UI_string_type banding_str[MMI_BARCODEREADER_BANDING_ITEM_COUNT + 1];

    /* selected item */
    S32 flash_selected;
    S32 ev_selected;
    S32 af_mode_selected;
    S32 storage_selected;
    U8 storage_total_num;

    S32 banding_selected;
    
} barcodereader_menu_context_struct;

typedef struct 
{
    U16 image_id;
    U16 string_id;
}mmi_barcodereader_menu_list_node;
/***************************************************************************** 
* External functions
*****************************************************************************/
extern U8 PhnsetGetDefEncodingType(void);

/***************************************************************************** 
* Local variable
*****************************************************************************/

static barcodereader_context_struct g_barcodereader_cntx;
static barcodereader_menu_context_struct g_barcodereader_menu_cntx;

#ifdef __MMI_BARCODEREADER_OPERATOR1__
static mmi_barcodereader_menu_list_node g_barcodereader_list_node[] = 
{
    {IMG_ID_BARCODEREADER_PREVIEW_ICON,          STR_ID_BARCODEREADER_PREVIEW},
    {IMG_ID_BARCODEREADER_FILELIST_ICON,         STR_ID_BARCODEREADER_FILELIST},
    {IMG_ID_BARCODEREADER_SERVICE_SUMMARY_ICON,  STR_ID_BARCODEREADER_SERVICE_SUMMARY},
    {IMG_ID_BARCODEREADER_HELP_ICON,             STR_ID_BARCODEREADER_HELP},
    {IMG_ID_BARCODEREADER_SETTING_ICON,          STR_ID_BARCODEREADER_SETTING}
};
#define MMI_BARCODEREADER_MENU_COUNT (sizeof(g_barcodereader_list_node)/sizeof(mmi_barcodereader_menu_list_node))
#endif

/***************************************************************************** 
* Functions declaration
*****************************************************************************/
#define MMI_BARCODEREADER_CHECK_STATE(_STATE_)            MMI_ASSERT(g_barcodereader_cntx.app_state == _STATE_);

/***************************************************************************** 
* Functions declaration
*****************************************************************************/
/* screen entry function start */
static void mmi_barcodereader_highlight_app(void);

#ifdef __MMI_BARCODEREADER_OPERATOR1__
/*main screen*/
       void mmi_barcodereader_enter_main_screen(void); 
static void mmi_barcodereader_main_screen_highlight_hdlr(S32 current_index);
/*file list*/
static void mmi_barcodereader_enter_filelist_storage_select_screen(void);
static void mmi_barcodereader_enter_filelist_screen(void);
//static void mmi_barcodereader_enter_filelist_option_screen(void);
//static void mmi_barcodereader_enter_filelist_option_highlight_hdlr(S32 index);
//static void mmi_barcodereader_enter_filelist_option_select_hdlr(void);
static void mmi_barcodereader_enter_from_filelist_to_app_preview(void);
static S32 mmi_barcodereader_read_string_from_file(PS16 path_and_name);
static void mmi_barcodereader_enter_filelist_file_select_done_hdlr(void *path, int is_short);
static void mmi_barcodereader_filelist_storage_select_screen_highlight_hdlr(S32 current_index);
/*service summary screen*/
static void mmi_barcodereader_enter_service_summary_screen(void);
/*help screen*/
static void mmi_barcodereader_enter_help_screen(void);
static void mmi_barcodereader_set_interupt_hdlr(void);
#endif
#ifndef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_entry_editor_screen(void);
static void mmi_barcodereader_exit_editor_screen(void);
#endif
/*preview screen , both UI scheme has preview screen*/
static void mmi_barcodereader_enter_preview_screen(void);
static void mmi_barcodereader_exit_preview_screen(void);

/*init/config framework's environment*/
static void mmi_barcodereader_init_framework(void);
static void mmi_barcodereader_init_camera(void);

/*option menu screen*/
static void mmi_barcodereader_enter_setting_screen(void);
static void mmi_barcodereader_exit_setting_screen(void);
/* screen entry function end */

static void mmi_barcodereader_enter_preview_state(void);
static void mmi_barcodereader_exit_preview_state(void);


#if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
static void mmi_barcodereader_start_capture_and_decode(void);
#endif
static void mmi_barcodereader_enter_capture_and_decode_state(void);
static void mmi_barcodereader_exit_capture_and_decode_state(void);

static void mmi_barcodereader_preview_start(void);
static void mmi_barcodereader_preview_stop(void);
static U16 mmi_barcodereader_get_error_string(S32 error_code);

static void mmi_barcodereader_entry_option_menu_screen(void);


#ifdef __MMI_BARCODEREADER_OPERATOR1__
static MMI_BOOL mmi_barcodereader_ucs2_check_continue_signal(PS8 string, U32 length, S8 escape_signal);
//static MMI_BOOL mmi_barcodereader_check_operator1_escape_signal_encoding(PS8 string, U32 length, PS8 escape_signal);
static U32 mmi_barcodereader_calc_attribute_multi_content(PS8 string, U32 string_length, S8 seperate);
static U32 mmi_barcodereader_split_multi_content(PS8 string, U32 string_length, S8 seperate, HILITE_STR *p, U32 count);

static void mmi_barcodereader_format_string(void);
static void mmi_barcodereader_add_highlight_content(U32 highlight_attr, PS8 string, S32 start, U16 length, U16 string_id);
static void mmi_barcodereader_multi_content_select_screen(void);
static void mmi_barcodereader_save_phonebook_from_content_select(void);
static void mmi_barcodereader_fille_phb_content(
                                                PS16 pbName, 
                                                PS16 pbNumber, 
                                                PHB_OPTIONAL_FIELDS_STRUCT *opt_fields,
                                                PHB_INFO_FIELDS_STRUCT *info_fields);
static void mmi_barcodereader_enter_app_preview_screen(void);
static void mmi_barcodereader_exit_app_preview_screen(void);
static void mmi_barcodereader_app_preview_callback(S32 selected_idx);
static void mmi_barcodereader_decode_listen_hdlr(void);
#ifdef __MMI_BARCODEREADER_GEN_TYPE_FILE__
static void mmi_barcodereader_gen_type_file(void);
#endif
#endif



static void mmi_barcodereader_highlight_to_qrv_editor(void);
static void mmi_barcodereader_enter_qrv_editor_screen(void);
static void mmi_barcodereader_exit_qrv_editor_screen(void);
/* MISC utility functions */
static void mmi_barcodereader_set_key_hdlr(void);
static void mmi_barcodereader_check_restore_path(void);
static BOOL mmi_barcodereader_check_and_restore_valid_drv(void);
static void mmi_barcodereader_exit_current_state(void);
static void mmi_barcodereader_enter_state(barcodereader_state_enum state);
static void mmi_barcodereader_preview_clear_background(void);
static BOOL mmi_barcodereader_get_storage_file_path(PS8 filepath);
static BOOL mmi_barcodereader_get_storage_disk_path(PU16 drive, PS8 drv_buf);
static void mmi_barcodereader_display_error_popup(void);
static void mmi_barcodereader_preview_set_blt_layer(BOOL is_previewing);
static void mmi_barcodereader_check_flash_status(void);
static mmi_chset_enum mmi_barcodereader_get_encoding_type(const S8 *str);
static void mmi_barcodereader_load_setting(void);
static void mmi_barcodereader_store_setting(void);
static void mmi_barcodereader_restore_setting(void);
static void mmi_barcodereader_option_setting_set_value(void);

/* resource related functions */
static void mmi_barcodereader_create_preview_resource(void);
static void mmi_barcodereader_free_preview_resource(void);

static void mmi_barcoderader_malloc_memory_and_create_adm_resource(void);
static void mmi_barcoderader_free_memory_and_destory_adm_resource(void);

static BOOL mmi_barcodereader_create_resource(void);
static void mmi_barcodereader_free_resource(void);

#ifdef __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__
static void mmi_barcodereader_re_focus_press(void);
#endif

/* key mapping functions */
static void mmi_barcodereader_capture_button_press(void);
static void mmi_barcodereader_capture_button_release(void);
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
static void mmi_barcodereader_af_and_capture(void);
static void mmi_barcodereader_focus_button_press(void);
#if 0
/* under construction !*/
#endif
static void mmi_barcodereader_focus_mode_change(BOOL is_next);
static void mmi_barcodereader_af_mode_hotkey_press(void);
#endif
#ifdef __MMI_BARCODEREADER_STORAGE__
static void mmi_barcodereader_storage_hotkey_press(void);
static void mmi_barcodereader_storage_change(BOOL is_next);
static void mmi_barcodereader_highlight_storage_hdlr(S32 idx);
static void mmi_barcodereader_set_storage_value(void);
static void mmi_barcodereader_exit_select_storage_screen_without_selecting(void);
static U8 mmi_barcodereader_delete_select_storage_screen_without_selecting(void *ptr);
static void mmi_barcodereader_entry_storage_screen(void);
static void mmi_barcodereader_highlight_settings(void);
static void mmi_barcodereader_highlight_storage(void);
#endif
#ifdef __MMI_BARCODEREADER_BANDING__
static void mmi_barcodereader_banding_hotkey_press(void);
static void mmi_barcodereader_banding_change(MMI_BOOL is_next);
#endif
#ifdef __MMI_BARCODEREADER_FLASH__
static void mmi_barcodereader_flash_hotkey_press(void);
static void mmi_barcodereader_flash_change(BOOL is_next);
#endif

static void mmi_barcodereader_ev_status_hotkey_press(void);

static S32 mmi_barcodereader_create_file_dir(PS8 filepath);

static void mmi_barcodereader_key_hdlr(void);
static void mmi_barcodereader_dummy_func(void);
static void mmi_barcodereader_ev_status_change(mmi_barcodereader_ev_status_enum status_change);
static void mmi_barcodereader_ev_status_revert(mmi_barcodereader_ev_status_enum status_change);
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
static void mmi_barcodereader_mf_status_change(mmi_barcodereader_mf_status_enum status_change);
static void mmi_barcodereader_mf_status_revert(mmi_barcodereader_mf_status_enum status_change);
#endif
static void mmi_barcodereader_lsk_press(void);
static void mmi_barcodereader_lsk_release(void);
static void mmi_barcodereader_rsk_press(void);
static void mmi_barcodereader_rsk_release(void);

//static void mmi_barcodereader_save_confirm_rsk_release(void);
//static void mmi_barcodereader_save_confirm_lsk_release(void);

static void mmi_barcodereader_autofocus_callback(mdi_result result);

#ifdef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_ucs2_strtoken(PS8 string, S8 seperate , PS32 length);
#endif

/* UI related functions */
static void mmi_barcodereader_draw_osd(void);
static void mmi_barcodereader_draw_osd_timer(void);
static void mmi_barcodereader_draw_hint(void);
static void mmi_barcodereader_draw_softkey(void);
static void mmi_barcodereader_draw_icon(void);
static void mmi_barcodereader_draw_title(void);
static void mmi_barcodereader_draw_style_text(
                PS8 str,
                S32 offset_x,
                S32 offset_y,
                barcodereader_style_text_struct *style_txt);
#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
static void mmi_barcodereader_draw_focus_process(void);
#endif
static void mmi_barcodereader_draw_bolder_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 bolder_width, gdi_color frame_color);
static void mmi_barcodereader_hide_hint(void);
static void mmi_barcodereader_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time);



#ifndef __MMI_BARCODEREADER_OPERATOR1__
static U8 mmi_barcodereader_is_symbol_valid(int c, U8 inBracket, U8 numIndex);
static S16 mmi_barcodereader_get_ucs2char(S8 *buf);
static S16 mmi_barcodereader_to_lower_case(PS8 ptr);
static U8 mmi_barcodereader_check_gsm_char(PU16 ch);
#endif
/* touch screen support */
#if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)
static void mmi_barcodereader_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_barcodereader_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_barcodereader_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_barcodereader_touch_scr_hit_test(S32 pos_x, S32 pos_y, barcodereader_ui_touch_struct *touch_obj);
#endif /* defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__) */ 

#ifdef __MMI_SUBLCD__
/* sub screen */
static void mmi_barcodereader_sublcd_draw_icon(void);
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_HORIZONTAL_BARCODEREADER__
static void mmi_barcodereader_check_sensor_orientation(void);
static void mmi_barcodereader_check_osd_orientation(void);
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 

#if defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
static void mmi_barcodereader_mf_forward(void);
static void mmi_barcodereader_mf_backward(void);
static void mmi_barcodereader_mf_stop(void);
static void mmi_barcodereader_mf_forward_continue(void);
static void mmi_barcodereader_mf_backward_continue(void);
#endif /* defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__) */ 


static MMI_BOOL mmi_barcodereader_parse_text(void);
#ifndef __MMI_BARCODEREADER_OPERATOR1__
//static U16 mmi_barcodereader_unicode_to_ascii(S8 *pOutBuffer, S8 *pInBuffer);
static void mmi_barcodereader_parser_general(void);
static void mmi_barcodereader_forward_to_apps(void);
#else
static MMI_BOOL mmi_barcodereader_parser_operator1(void);
static void mmi_barcodereader_forward_to_apps_operator1(void);
#endif

static void mmi_barcodereader_callback(S32 selected_idx);

#ifndef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_exit_forward_to_apps(void);
static void mmi_barcodereader_init_forward_menu(void);
#endif


static void mmi_barcodereader_copy_from_unicode_to_unicode(U16 which, U8* dest, S32 length);

/*******************************************************
* URL
*******************************************************/
static void mmi_barcodereader_func_save(void);
static void mmi_barcodereader_get_next_filename(PS8 file_buf_p);
static void mmi_barcodereader_save_done(void);
static void mmi_barcodereader_save_done_timeout(void);
#ifndef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_func_exit(void);
#endif

/*******************************************************
* URL
*******************************************************/
static void mmi_barcodereader_func_save_url(void);
static void mmi_barcodereader_func_open_url(void);

/*******************************************************
* Call Management
*******************************************************/
static void mmi_barcodereader_func_make_call(void);
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
static void mmi_barcodereader_func_make_voip_call(void);
#endif

/*******************************************************
* SMS
*******************************************************/
static void mmi_barcodereader_send_sms_callback(void *dummy, module_type mod, U16 flag);
static void mmi_barcodereader_save_sms_callback(void *dummy, module_type mod, U16 flag);
static void mmi_barcodereader_func_save_sms(void);
static void mmi_barcodereader_func_edit_by_sms(void);
#ifndef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_func_send_by_sms(void);
#endif

#ifdef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_func_preview(void);
static void mmi_barcodereader_func_back_to_main(void);
static void mmi_barcodereader_func_url(void);
static void mmi_barcodereader_func_url_hilight_hdlr(S32 index);
#endif

/********************************************************
* Phonebook
********************************************************/
static void mmi_barcodereader_func_save_to_phonebook(void);

/********************************************************
* MMS
********************************************************/
static void mmi_barcodereader_func_edit_by_mms(void);

/********************************************************
* ORDER
********************************************************/
static void mmi_barcodereader_func_order(void);

/********************************************************
* commend
********************************************************/
#ifdef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_func_to_commend(void);
#endif

/********************************************************
* email
********************************************************/
#ifdef __MMI_BARCODEREADER_OPERATOR1__
#ifdef __MMI_EMAIL__
static void mmi_barcodereader_func_send_by_email(void);
static void mmi_barcodereader_func_save_email(void);
#endif
#endif

/******************************************************
* Highlight Handlers
*******************************************************/
static void mmi_barcodereader_hilight_save(void);
static void mmi_barcodereader_hilight_open_url(void);
static void mmi_barcodereader_hilight_make_call(void);
static void mmi_barcodereader_hilight_edit_by_sms(void);
#ifndef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_hilight_send_by_sms(void);
static void mmi_barcodereader_hilight_exit(void);
#endif
static void mmi_barcodereader_hilight_save_url(void);
static void mmi_barcodereader_hilight_save_sms(void);
static void mmi_barcodereader_hilight_save_to_phonebook(void);
static void mmi_barcodereader_hilight_edit_by_mms(void);
static void mmi_barcodereader_hilight_order(void);


#ifdef __MMI_BARCODEREADER_OPERATOR1__
#ifdef __MMI_EMAIL__
static void mmi_barcodereader_hilight_send_by_email(void);
static void mmi_barcodereader_hilight_save_email(void);
#endif
#endif

#ifdef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_hilight_preview(void);
static void mmi_barcodereader_hilight_back_to_main(void);
static void mmi_barcodereader_hilight_enter_from_filelist_to_app_preview(void);
static void mmi_barcodereader_hilight_to_commend(void);
#endif

/******************************************************
* App memory related functions
*******************************************************/
static void mmi_barcodereader_app_mem_stop_callback(void);
static void mmi_barcodereader_app_mem_success_callback(void);
static void mmi_barcodereader_free_adm_resource(void);
static void mmi_barcodereader_create_adm_resource(void);

static U8 mmi_barcodereader_del_scr_callback(void* ptr);
static void mmi_barcodereader_decode_result_hdlr(mdi_result ret, U8 encoding, U8 nsymbol, U8 symbolid, U8 paritydata, mdi_camera_barcode_type_enum barcode_type);
static void mmi_barcodereader_enter_tip_screen(void);
static void mmi_barcodereader_exit_tip_screen(void);


static MMI_BOOL mmi_barcodereader_is_network_permit(MMI_BOOL is_net);
/***************************************************************************** 
* Functions Implementation
*****************************************************************************/


#ifdef __MMI_BARCODEREADER_OPERATOR1__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_order
 * DESCRIPTION
 *  high light handler of function save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_enter_main_screen()
{
    int     i;
    U16     image_list[MMI_BARCODEREADER_MENU_COUNT];
    U16     string_list[MMI_BARCODEREADER_MENU_COUNT];
    U8      *gui_buffer;

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
        {
        /* in mass storage mode */
        
        if (mmi_usb_check_path_exported((PS8) MMI_BARCODEREADER_STORAGE_FILEPATH_PHONE))
            {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
            }
        }
#endif

    mmi_barcoderader_malloc_memory_and_create_adm_resource();

    EntryNewScreen(
        SCR_ID_BARCODEREADER_MAIN,
        NULL,
        mmi_barcodereader_enter_main_screen,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_BARCODEREADER_MAIN, mmi_barcodereader_del_scr_callback);

    for(i = 0 ; i < MMI_BARCODEREADER_MENU_COUNT ; i++)
    {
        image_list[i] = g_barcodereader_list_node[i].image_id;
        string_list[i] = g_barcodereader_list_node[i].string_id;
    }

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_MAIN);
    RegisterHighlightHandler(mmi_barcodereader_main_screen_highlight_hdlr);

    ShowCategory52Screen(
        STR_ID_BARCODEREADER_APP_NAME,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP) ,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_BARCODEREADER_MENU_COUNT,
        string_list,
        image_list,
        NULL,
        0,
        0,
        gui_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_order
 * DESCRIPTION
 *  high light handler of function save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_main_screen_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_main_screen_highlight_hdlr(S32 current_index)
{
    switch(current_index)
    {
    case MMI_BARCODEREADER_MENULIST_PREVIEW:
        SetKeyHandler(mmi_barcodereader_enter_preview_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_barcodereader_enter_preview_screen, KEY_EVENT_UP);
        break;

    case MMI_BARCODEREADER_MENULIST_FILELIST:
        SetKeyHandler(mmi_barcodereader_enter_filelist_storage_select_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_barcodereader_enter_filelist_storage_select_screen, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        break;

    case MMI_BARCODEREADER_MENULIST_SERVICE_SUMMARY:
        SetKeyHandler(mmi_barcodereader_enter_service_summary_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_barcodereader_enter_service_summary_screen, KEY_EVENT_UP);
        break;

    case MMI_BARCODEREADER_MENULIST_HELP:
        SetKeyHandler(mmi_barcodereader_enter_help_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_barcodereader_enter_help_screen, KEY_EVENT_UP);
        break;

    case MMI_BARCODEREADER_MENULIST_SETTING:
        SetKeyHandler(mmi_barcodereader_enter_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_barcodereader_enter_setting_screen, KEY_EVENT_UP);
        break;

    default:
        SetKeyHandler(MMI_dummy_function, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(MMI_dummy_function, KEY_EVENT_UP);
        break;
    }

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


static void mmi_barcodereader_enter_filelist_storage_select_screen(void)
{
    U8* guiBuffer;
    MMI_ID_TYPE item_icons[] = 
    {
        IMG_ID_BARCODEREADER_MENUICON_STORAGE,
        0,
    };

    InitializeCategory57Screen();

    EntryNewScreen(
        SCR_ID_BARCODEREADER_FILELIST_STORAGE_SELECT, 
        NULL, 
        mmi_barcodereader_enter_filelist_storage_select_screen, 
        NULL);

    mmi_fmgr_get_exist_storage_inline_list(
        (S8)MMI_PUBLIC_DRV,
        &g_barcodereader_menu_cntx.storage_total_num,&(g_barcodereader_cntx.drv_inline_list_p),
        (U8*)&g_barcodereader_menu_cntx.storage_selected);
    
    SetInlineItemCaption(&wgui_inline_items[0], (PU8)GetString((U16)(STR_ID_BARCODEREADER_STORAGE)));
    SetInlineItemActivation(&wgui_inline_items[1],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0 );
    SetInlineItemSelect( &wgui_inline_items[1],
        g_barcodereader_menu_cntx.storage_total_num,
        (U8 **) g_barcodereader_cntx.drv_inline_list_p,
                       &g_barcodereader_menu_cntx.storage_selected);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_SETTING);

    RegisterHighlightHandler(mmi_barcodereader_filelist_storage_select_screen_highlight_hdlr);
    ShowCategory57Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        sizeof(item_icons) / sizeof(item_icons[0]),
        item_icons,
        wgui_inline_items,
        0,
        NULL);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_barcodereader_enter_filelist_screen);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


static void mmi_barcodereader_filelist_storage_select_screen_highlight_hdlr(S32 current_index)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_barcodereader_enter_filelist_screen); 
}


static void mmi_barcodereader_enter_filelist_screen(void)
{
    S8 file_path[FMGR_PATH_BUFFER_SIZE];
    FMGR_FILTER filter;

    //mmi_fmgr_get_exist_storage_inline_list((S8)g_barcodereader_cntx.setting.storage,&total_num,&(g_barcodereader_cntx.drv_inline_list_p),(PU8)&current_storage_index);
    mmi_fmgr_get_drive_letter_by_inline_index((U8)g_barcodereader_menu_cntx.storage_selected,(S8*)&g_barcodereader_cntx.storage_disk);
    //mmi_fmgr_get_drive_letter_by_inline_index(current_storage_index,(S8*)&g_barcodereader_cntx.setting.storage);

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_MBC);
    
    if(!mmi_barcodereader_get_storage_disk_path(&g_barcodereader_cntx.storage_disk, file_path))
    {
        
        return;
    }
    mmi_ucs2cat(file_path, (const char *)FMGR_DEFAULT_FOLDER_BARCODE);

    //EntryNewScreen(SCR_ID_BARCODEREADER_EDITOR, NULL, mmi_barcodereader_enter_filelist_screen, NULL);
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    mmi_fmgr_select_path_and_enter(
        APP_BARCODEREADER,
        FMGR_SELECT_BROWSE,
        filter,
        (S8*)file_path,
        (PsExtFuncPtr) mmi_barcodereader_enter_filelist_file_select_done_hdlr);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


static void mmi_barcodereader_enter_from_filelist_to_app_preview(void)
{
    S32 result;
    S32 index;
    FMGR_FILE_INFO_STRUCT file_info;
    S16 path_and_name[FMGR_MAX_PATH_LEN];
    S8 drv_buf[8];
    
    index = mmi_fmgr_kernel_get_cur_idx();
    mmi_fmgr_kernel_get_file_info(index, &file_info);
    if (mmi_barcodereader_get_storage_disk_path(&g_barcodereader_cntx.storage_disk, drv_buf))
    {
        mmi_ucs2cpy((PS8) path_and_name, (PS8) drv_buf);
        mmi_ucs2cat((PS8) path_and_name, (PS8) MMI_BARCODEREADER_STORAGE_FILEPATH_PHONE);
     }
    mmi_ucs2cat((PS8)path_and_name, file_info.file_name);
    
    //GoBackHistory();

    result = mmi_barcodereader_read_string_from_file(path_and_name);
    if(result < FS_NO_ERROR)
    {
        g_barcodereader_cntx.last_error.error_result = result;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
        mmi_barcodereader_display_error_popup();
        return;
    }

    if(mmi_barcodereader_parser_operator1() == MMI_TRUE)
    {
        mmi_barcodereader_enter_app_preview_screen();
    }
    else
    {
        mmi_barcodereader_display_error_popup();
    }

}


static S32 mmi_barcodereader_read_string_from_file(PS16 path_and_name)
{
    S32 result = FS_NO_ERROR;
    UINT read_size;
    FS_HANDLE handle;

    handle = FS_Open((const WCHAR *)path_and_name, FS_READ_ONLY);  
    if (handle >= FS_NO_ERROR)
    {
        memset(g_barcodereader_cntx.text_buf, 0, BR_TEXT_BUFFER_SIZE);
        FS_Read(handle, g_barcodereader_cntx.text_buf, BR_TEXT_BUFFER_SIZE, &read_size);
        mmi_ucs2_to_asc(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf);
        FS_Close(handle);
    }
    
    result = handle;
    return result;
}


static void mmi_barcodereader_enter_filelist_file_select_done_hdlr(void *path, int is_short)
{
    if (path == NULL)   /* User does not select file and go back directly. */
    {
        GoBackHistory();
        return;
    }

    mmi_ucs2cpy((PS8)g_barcodereader_cntx.file_path, path);
    //mmi_barcodereader_enter_filelist_option_screen();
}


static void mmi_barcodereader_enter_service_summary_screen(void)
{
    PS8 buffer;
    S32 buffersize;

    buffer = GetString(STR_ID_BARCODEREADER_SERVICE_SUMMARY_CONTENT);
    buffersize = strlen(buffer);
    
    EntryNewScreen(
        SCR_ID_BARCODEREADER_SERVICE_SUMMARY,
        NULL,
        mmi_barcodereader_enter_service_summary_screen,
        NULL);

    ShowCategory74Screen(
        STR_ID_BARCODEREADER_ORDER_ATTENTION,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)buffer,
        buffersize,
        NULL);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


static void mmi_barcodereader_enter_help_screen(void)
{
    U8  i;
    S8 *buffer[MMI_BARCODEREADER_HELP_CONTENT_PHASE_COUNT];
    S32 total_buffer_size = 0;
    
    EntryNewScreen(
        SCR_ID_BARCODEREADER_HELP,
        NULL,
        mmi_barcodereader_enter_help_screen,
        NULL);

    for(i = 0 ; i < MMI_BARCODEREADER_HELP_CONTENT_PHASE_COUNT ; i++)
    {
        buffer[i] = (GetString((U16)(STR_ID_BARCODEREADER_HELP_START + 1 + i)));
        total_buffer_size += mmi_ucs2strlen(buffer[i]) * ENCODING_LENGTH + 2;     
    }
    total_buffer_size += 2;

    g_barcodereader_cntx.buffer_from_screen_asm = 
        (S8 *)applib_mem_screen_alloc(total_buffer_size);

    mmi_ucs2cpy((S8 *)g_barcodereader_cntx.buffer_from_screen_asm, "");
    for(i = 0 ; i < MMI_BARCODEREADER_HELP_CONTENT_PHASE_COUNT ; i++)
    {
        mmi_ucs2cat((S8 *)(g_barcodereader_cntx.buffer_from_screen_asm), (S8 *)(buffer[i]));    
        mmi_ucs2cat((S8 *)(g_barcodereader_cntx.buffer_from_screen_asm), "\n");
    }
    
    ShowCategory74Screen(
        STR_ID_BARCODEREADER_HELP,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)g_barcodereader_cntx.buffer_from_screen_asm,
        //buffer[1],
        total_buffer_size,
        NULL);
    
    applib_mem_screen_free(g_barcodereader_cntx.buffer_from_screen_asm);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


static void mmi_barcodereader_set_interupt_hdlr(void)
{
    mmi_frm_block_general_interrupt_event(
        MMI_FRM_INT_BATTERY 
        | MMI_FRM_INT_EARPHONE
    #ifdef __MTK_TARGET__
        | MMI_FRM_INT_FMGR_CARD
#endif
    );
}
   
#endif /* __MMI_BARCODEREADER_OPERATOR1__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_order
 * DESCRIPTION
 *  high light handler of function save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_order, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_order, KEY_EVENT_UP);
}


#ifdef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_hilight_to_commend(void)
{
    SetKeyHandler(mmi_barcodereader_func_to_commend, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_to_commend, KEY_EVENT_UP);
}


static void mmi_barcodereader_hilight_preview(void)
{
    SetKeyHandler(mmi_barcodereader_func_preview, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_preview, KEY_EVENT_UP);
}


static void mmi_barcodereader_hilight_back_to_main(void)
{
    SetKeyHandler(mmi_barcodereader_func_back_to_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_back_to_main, KEY_EVENT_UP);
}


static void mmi_barcodereader_hilight_enter_from_filelist_to_app_preview(void)
{
    SetKeyHandler(mmi_barcodereader_enter_from_filelist_to_app_preview, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_enter_from_filelist_to_app_preview, KEY_EVENT_UP);
    //mmi_barcodereader_enter_from_filelist_to_app_preview(g_barcodereader_cntx.file_path);
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_save
 * DESCRIPTION
 *  high light handler of function save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save, KEY_EVENT_UP);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_edit_by_mms
 * DESCRIPTION
 *  high light handler of function edit by mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_edit_by_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_edit_by_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_edit_by_mms, KEY_EVENT_UP);
}

#ifdef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_hilight_send_by_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    SetKeyHandler(mmi_barcodereader_func_send_by_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_send_by_email, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_barcodereader_dummy_func, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_dummy_func, KEY_EVENT_UP);
#endif
}

static void mmi_barcodereader_hilight_save_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    SetKeyHandler(mmi_barcodereader_func_save_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save_email, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_barcodereader_dummy_func, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_dummy_func, KEY_EVENT_UP);
#endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_save_to_phonebook
 * DESCRIPTION
 *  high light handler of function edit by sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_save_to_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_save_to_phonebook, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save_to_phonebook, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_edit_by_sms
 * DESCRIPTION
 *  high light handler of function edit by sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_edit_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_edit_by_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_edit_by_sms, KEY_EVENT_UP);
}


#ifndef __MMI_BARCODEREADER_OPERATOR1__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_send_by_sms
 * DESCRIPTION
 *  high light handler of function sent by sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_send_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_send_by_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_send_by_sms, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_exit
 * DESCRIPTION
 *  high light handler of function exit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_exit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_exit, KEY_EVENT_UP);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_save_url
 * DESCRIPTION
 *  high light handler of function make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_save_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_save_url, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save_url, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_save_sms
 * DESCRIPTION
 *  high light handler of function save sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_save_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_save_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save_sms, KEY_EVENT_UP);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_open_url
 * DESCRIPTION
 *  high light handler of function open url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_open_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_open_url, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_open_url, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_make_call
 * DESCRIPTION
 *  high light handler of function make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hilight_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    switch (mmi_netset_get_active_preferred_mode())
    {
        case P_WLAN_ONLY:
            SetKeyHandler(mmi_barcodereader_func_make_voip_call, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_barcodereader_func_make_voip_call, KEY_EVENT_UP);
            break;

        case P_GSM_PREFERRED:
        case P_WLAN_PREFERRED:
            if (mmi_barcodereader_is_network_permit(MMI_FALSE))
            {
                SetKeyHandler(mmi_netset_entry_dial_mode_selection, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(mmi_netset_entry_dial_mode_selection, KEY_EVENT_UP);
                mmi_netset_register_call_entry_func(mmi_barcodereader_func_make_call, mmi_barcodereader_func_make_voip_call);
            }
            else
            {
                SetKeyHandler(mmi_barcodereader_func_make_voip_call, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(mmi_barcodereader_func_make_voip_call, KEY_EVENT_UP);
            }
            break;

        case P_GSM_ONLY:
        default:
            SetKeyHandler(mmi_barcodereader_func_make_call, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_barcodereader_func_make_call, KEY_EVENT_UP);
            break;
    }
#else /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
    SetKeyHandler(mmi_barcodereader_func_make_call, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_make_call, KEY_EVENT_UP);
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_order
 * DESCRIPTION
 *  functions to send sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buffer;
    S32 bufferSize;
    U32 length;
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BARCODEREADER_ORDER_CONFIRM, NULL, mmi_barcodereader_func_order, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_ORDER_CONFIRM);

    buffer = GetString(STR_ID_BARCODEREADER_ORDER_CONFIRM);

    mmi_ucs2cpy(g_barcodereader_cntx.input_string_tmp, buffer); 
    mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)L"\n"); 

    mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)GetString(STR_ID_BARCODEREADER_NOTIFY_SEND_TO));
      
    if(g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SID].str_addr!=NULL)
    {
        length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SID].length;
        mmi_barcodereader_copy_from_unicode_to_unicode(MMI_BARCODEREADER_ATTRIBUTE_SID, (U8*)g_barcodereader_cntx.working_buffer, length);
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Data: %s---*\n",g_barcodereader_cntx.working_buffer);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)g_barcodereader_cntx.working_buffer);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)L".");
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)L"\n"); 
    }
      
     
    mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)GetString(STR_ID_BARCODEREADER_NOTIFY_CONTENT));
    if(g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].str_addr!=NULL)
    {
        length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].length;
        mmi_barcodereader_copy_from_unicode_to_unicode(MMI_BARCODEREADER_ATTRIBUTE_DG, (U8*)g_barcodereader_cntx.working_buffer, length);
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Data: %s---*\n",g_barcodereader_cntx.working_buffer);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)g_barcodereader_cntx.working_buffer);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)L".");
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,(PS8)L"\n");
    }
    
    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.input_string_tmp);

    ShowCategory74Screen(
        STR_ID_BARCODEREADER_ORDER_ATTENTION,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_barcodereader_cntx.input_string_tmp,
        bufferSize,
        NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Fatal error after here!---*\n");
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    SetKeyHandler(mmi_barcodereader_func_send_by_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_send_by_sms, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(mmi_barcodereader_func_edit_by_sms, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_func_edit_by_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}





/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_edit_by_mms
 * DESCRIPTION
 *  functions to save to phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_edit_by_mms(void)
{
#ifdef MMS_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    U16 *src;
    U16 *dest;
    S32 length = 0;
    U16 idx = 0;
#else
    U16 input_subject[MMI_BARCODEREADER_MAX_MMS_SUBJECT+1];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    if (g_barcodereader_cntx.selected_app_type == MMI_BARCODEREADER_APP_DTXT)
    {
        /*this interface has some error , the subject lenth is not in use, so hide code as follows*/
//         mms_text_insert_hdlr(
//             g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].str_addr,
//             g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].length,
//             g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr,
//             g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length);

        mmi_ucs2ncpy(
            (S8*)input_subject, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].length);
        memset(input_subject + 2* g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].length, 0 , 2);
        mms_text_insert_hdlr(
            (S8*)input_subject,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].length,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length);
    }
    else
    {
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_COMMON;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
        mmi_barcodereader_display_error_popup();
        return;
    }
#else
    {
        length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
        src = (U16*) & g_barcodereader_cntx.formatted_text_buf[0];
        dest = (U16*)&g_barcodereader_cntx.input_string[0];
        for (idx = 0; idx < length ; idx++)
        {
            *dest++ = *src++;
        }
        *dest = 0;
        
        mmi_ucs2_to_asc((PS8) g_barcodereader_cntx.input_string_tmp, (PS8) g_barcodereader_cntx.input_string);
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---MMS, input_string: %s---*\n", g_barcodereader_cntx.input_string_tmp);
        mms_text_insert_hdlr("", 0, (char*)g_barcodereader_cntx.input_string, (unsigned int)length);
    }
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_save_to_phonebook
 * DESCRIPTION
 *  functions to save to phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_save_to_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    U32 content_count = 1;
    U16 i;
    PHB_INFO_FIELDS_STRUCT info_fields;
    PHB_OPTIONAL_FIELDS_STRUCT opt_fields;
    S16 pbNick[(MAX_PB_NAME_LENGTH + 1)] = {0};
    S16 pbName[(MAX_PB_NAME_LENGTH + 1)] = {0};
    S16 pbNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1)] = {0};
#else
    U16 *src;
    U16 *dest;
    S32 length;
    U16 idx = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    if (g_barcodereader_cntx.selected_app_type != MMI_BARCODEREADER_APP_VCARD)
    {
        /* only phone number information */
        length = g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length;
        src = (U16*) g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr;
        dest = (U16*) g_barcodereader_cntx.input_string;

        for (idx = 0; idx < length * ENCODING_LENGTH; idx += ENCODING_LENGTH)
        {
            if (((U16) '0' <= *src && *src <= (U16) '9') || *src == (U16) 'p' || *src == (U16) 'w' || *src == (U16) '+')
            {
                *dest++ = *src;
            }
            
            src++;
        }
        
        *dest = 0;
        mmi_ucs2_to_asc((PS8) g_barcodereader_cntx.input_string_tmp, (PS8) g_barcodereader_cntx.input_string);
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Save Number to Phonebook, g_barcodereader_cntx.input_string: %s---*\n",
            g_barcodereader_cntx.input_string_tmp);
        mmi_phb_save_entry_from_others(NULL, (PS8) g_barcodereader_cntx.input_string, NULL, NULL, NULL, NULL, NULL);
    }
    else
    {
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_COMMON;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;

        mmi_barcodereader_display_error_popup();
        return;
    }
#else
        if (g_barcodereader_cntx.selected_app_type != MMI_BARCODEREADER_APP_VCARD)
        {
            g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_COMMON;
            g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
            
            mmi_barcodereader_display_error_popup();
            return;
        }

        mmi_ucs2cpy((PS8)pbNick, "");
        g_barcodereader_cntx.phb_multiple_content_to_select = 0;

        for (i = 0 ; i < MMI_BARCODEREADER_ATTRIBUTE_ALL ; i++)
        {
            if ((g_barcodereader_cntx.app_content.ct_attribute & mmi_barcodereader_attribute[i].value) &&
                (g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_MULTI_CONTENT_ATTRIBUTE))
            {
                content_count = mmi_barcodereader_calc_attribute_multi_content(
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    g_barcodereader_cntx.app_content.ct_element[i].length,
                    MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);
                if (content_count > 1)
                {
                    g_barcodereader_cntx.phb_multiple_content_to_select |= 
                        mmi_barcodereader_attribute[i].value;
                }
            }
        }

        if (g_barcodereader_cntx.phb_multiple_content_to_select > 0)
        {
            mmi_barcodereader_multi_content_select_screen();
            return;
        }
        else
        {
            memset(&opt_fields, 0, sizeof(PHB_OPTIONAL_FIELDS_STRUCT));
            memset(&info_fields, 0, sizeof(PHB_INFO_FIELDS_STRUCT));
            mmi_barcodereader_fille_phb_content(pbName, pbNumber, &opt_fields, &info_fields);
        }

        mmi_phb_save_entry_from_others((PS8) pbName, (PS8) pbNumber, &opt_fields, NULL, &info_fields, (PS8) pbNick, NULL);
#endif
        
}


/*****************************************************************************
* FUNCTION
*  mmi_barcodereader_func_save_sms
* DESCRIPTION
*  functions to save sms
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_barcodereader_func_save_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    S32 length;
    U16 *src;
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    U32 content_count = 0;
#define MMI_BARCDEREADER_SMS_SM_LENGTH 20
    S8  number1[(20 + 1) * ENCODING_LENGTH], number2[20 + 1];
    HILITE_STR attr_content[MMI_BARCODEREADER_CONTENT_MAX_COUNT]; 
#endif
    //MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

#ifdef __MMI_BARCODEREADER_OPERATOR1__
    if (g_barcodereader_cntx.selected_app_type != MMI_BARCODEREADER_APP_SMS)
    {
        return;
    }

    src = (U16*)g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr;

    if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length > MMI_BARCODEREADER_MAX_SMS_CONTENT )
        length = MMI_BARCODEREADER_MAX_SMS_CONTENT;
    else 
            length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length;

    if (mmi_frm_sms_check_UCS2((U16*)src,(U16)length))
    {
    sendData->string = OslMalloc((length + 1) * ENCODING_LENGTH);
    sendData->dcs = SMSAL_UCS2_DCS;
        mmi_ucs2ncpy((PS8) sendData->string, (PS8)src, length);
        sendData->stringlength = length;   
    }
    else
    {
        U32 len,buf_len;
        len = mmi_frm_sms_count_extension_char((U16*)src,(U32)length);
        
        /* due to ctrl buffer max buffer size is 2048b */
        buf_len = ((len+length+1)*ENCODING_LENGTH < 2048)? (len+length+1)*ENCODING_LENGTH:2048;
        
        sendData->string = OslMalloc(buf_len);
        sendData->dcs = SMSAL_DEFAULT_DCS;
        mmi_frm_sms_add_escape_symbol_for_extension_char((U16*)sendData->string,(U16*) src, (U16)length);
        sendData->stringlength = mmi_ucs2strlen(sendData->string);
    }

    /*get sms receiver*/
    content_count = mmi_barcodereader_calc_attribute_multi_content(
        g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr,
        g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length,
        MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);  
    if (content_count == 1)
    {
        length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length;
    }
    else
    {
        if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
        {
            content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
        }
        
        mmi_barcodereader_split_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length, 
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
            attr_content, 
            content_count);
        
        /*currently the sms only support one number receiver*/
        length = attr_content[0].length;
    }
    if (length > MMI_BARCDEREADER_SMS_SM_LENGTH)
    {
        //result = MMI_FALSE;
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_TOO_LONG_NUMBER;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;    
    }
    mmi_ucs2ncpy((PS8)number1, g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr, length);
    memset(number1 + ENCODING_LENGTH * length, 0, 2);
    mmi_ucs2_to_asc(number2, number1);
#else
    {
        length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
        
        if (length > MMI_BARCODEREADER_MAX_SMS_CONTENT )
            length = MMI_BARCODEREADER_MAX_SMS_CONTENT;
        
        src = (U16*) & g_barcodereader_cntx.formatted_text_buf[0];
        
        /* set number 0 */
        memset((S8*) sendData->number, 0, sizeof(sendData->number));
        
        if (mmi_frm_sms_check_UCS2((U16*)src,(U16)length))
        {
            sendData->string = OslMalloc((length+1)*ENCODING_LENGTH);
            sendData->dcs = SMSAL_UCS2_DCS;
            mmi_ucs2ncpy((PS8) sendData->string, (PS8)src, length);
            sendData->stringlength = length;   
        }
        else
        {
            U32 len,buf_len;
            len = mmi_frm_sms_count_extension_char((U16*)src,(U32)length);
            
            /* due to ctrl buffer max buffer size is 2048b */
            buf_len = ((len+length+1)*ENCODING_LENGTH < 2048)? (len+length+1)*ENCODING_LENGTH:2048;
            
            sendData->string = OslMalloc(buf_len);
            sendData->dcs = SMSAL_DEFAULT_DCS;
            mmi_frm_sms_add_escape_symbol_for_extension_char((U16*)sendData->string,(U16*) src, (U16)length);
            sendData->stringlength = mmi_ucs2strlen(sendData->string);        
        }
    }
    
#endif

    sendData->sendrequire = MMI_FRM_SMS_SAVE_DISPLAY_SAVING_SCREEN;
    /*this one should be modified*/
    sendData->status = SMSAL_STO_DRAFT;

#if defined(__MMI_DUAL_SIM_MASTER__)
    sendData->sendrequire |= MMI_FRM_SMS_DISP_SIM_OPT;
#endif
    
    mmi_frm_sms_save_sms_for_other_app(mmi_barcodereader_save_sms_callback, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_edit_by_sms
 * DESCRIPTION
 *  functions to edit sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_edit_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_entry_write_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_api_entry_write_struct));
    S32 length = 0;
    #define MMI_BARCDEREADER_SMS_SM_LENGTH 20  /*current sms only supoort 20 character count number */
    U16 *src;
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    U32 content_count = 0;
    U8 i;
    HILITE_STR attr_content[MMI_BARCODEREADER_CONTENT_MAX_COUNT];
    S8 *temp_p;
    S8  number1[(20 + 1) * ENCODING_LENGTH], number2[20 + 1];
#endif
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    switch(g_barcodereader_cntx.selected_app_type)
    {
    case MMI_BARCODEREADER_APP_SMS:
        src = (PU16)g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr;
        if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length > MMI_BARCODEREADER_MAX_SMS_CONTENT )
            length = MMI_BARCODEREADER_MAX_SMS_CONTENT;
        else 
            length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length;


        if (mmi_frm_sms_check_UCS2((U16*)src, (U16)length))
        {
            sendData->string = OslMalloc((length+1)*ENCODING_LENGTH);
        sendData->dcs = SMSAL_UCS2_DCS;
            mmi_ucs2ncpy((PS8) sendData->string, (PS8)src, length);
            sendData->stringlength = length;   
        }
        else
        {
            U32 len, buf_len;
            len = mmi_frm_sms_count_extension_char((U16*)src,(U32)length);
            
            /* due to ctrl buffer max buffer size is 2048b */
            buf_len = ((len+length+1)*ENCODING_LENGTH < 2048)? (len+length+1)*ENCODING_LENGTH:2048;
            
            sendData->string = OslMalloc(buf_len);
            sendData->dcs = SMSAL_DEFAULT_DCS;
            mmi_frm_sms_add_escape_symbol_for_extension_char((U16*)sendData->string,(U16*) src, (U16)length);
            sendData->stringlength = mmi_ucs2strlen(sendData->string);
        }

        memset(sendData->string + length * ENCODING_LENGTH, 0, 2);
        
        /*get sms receiver*/
        content_count = mmi_barcodereader_calc_attribute_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length,
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);  
        if (content_count == 1)
        {
            length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length;
        }
        else
        {
            if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
            {
                content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
            }
            
            mmi_barcodereader_split_multi_content(
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr, 
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length, 
                MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
                attr_content, 
                content_count);
            
            /*currently the sms only support one number receiver*/
            length = attr_content[0].length;
        }
        if (length > MMI_BARCDEREADER_SMS_SM_LENGTH)
        {
            g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_TOO_LONG_NUMBER;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;    
            break;
        }
        mmi_ucs2ncpy(number1, g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr, length);
        memset(number1 + ENCODING_LENGTH * length, 0, 2);
        mmi_ucs2_to_asc(number2, number1);
        sendData->ascii_addr= (U8*)number2;
        sendData->flag |= MMI_FRM_SMS_ENTRY_WRITE_REPLY; /* number will filled*/
        break;
        
    case MMI_BARCODEREADER_APP_SMSSELL:
        if (g_barcodereader_cntx.is_commend == MMI_FALSE)
        {
            length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SID].length;
            if (length > MMI_BARCDEREADER_SMS_SM_LENGTH)
            {
                length = MMI_BARCDEREADER_SMS_SM_LENGTH; 
            }
            mmi_ucs2_n_to_asc(
                (PS8)number1, 
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SID].str_addr, 
                length * 2);
            number1[length] = 0;
            sendData->ascii_addr = (U8*)number1;
            
            /*sms content*/
            if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].length > MMI_BARCODEREADER_MAX_SMS_CONTENT )
                length = MMI_BARCODEREADER_MAX_SMS_CONTENT;
            else 
                length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].length;

            src = (PU16)g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].str_addr;

            if (mmi_frm_sms_check_UCS2(
                (U16*)src,
                (U16)length))
            {
                sendData->string = OslMalloc((length + 1) * ENCODING_LENGTH);
                mmi_ucs2ncpy(
                    sendData->string,
                    (PS8)src, 
                    length);
                memset(sendData->string + length * ENCODING_LENGTH, 0, 2);
                sendData->dcs = SMSAL_UCS2_DCS;
                sendData->stringlength = length;
            }
            else
            {
                U32 len, buf_len;
                len = mmi_frm_sms_count_extension_char((U16*)src,(U32)length);
                
                /* due to ctrl buffer max buffer size is 2048b */
                buf_len = ((len+length+1)*ENCODING_LENGTH < 2048)? (len+length+1)*ENCODING_LENGTH:2048;
                
                sendData->string = OslMalloc(buf_len);
                sendData->dcs = SMSAL_DEFAULT_DCS;
                mmi_frm_sms_add_escape_symbol_for_extension_char(
                    (U16*)sendData->string,
                    (U16*) src, 
                    (U16)length);
                sendData->stringlength = mmi_ucs2strlen(sendData->string); 
            }
            sendData->flag |= MMI_FRM_SMS_ENTRY_WRITE_REPLY;
            break;
        }
        else
        {
            // will deal it the same as MMI_BARCODEREADER_APP_IVRSELL, MMI_BARCODEREADER_APP_WAPSELL, MMI_BARCODEREADER_APP_VCARD
        }

    case MMI_BARCODEREADER_APP_IVRSELL:
    case MMI_BARCODEREADER_APP_WAPSELL:
    case MMI_BARCODEREADER_APP_VCARD:
        sendData->dcs = SMSAL_UCS2_DCS;
        mmi_ucs2cpy(g_barcodereader_cntx.formatted_text_buf, "");
        for(i = 0; i < MMI_BARCODEREADER_ATTRIBUTE_ALL; i++)      
        {
            if (g_barcodereader_cntx.app_content.ct_attribute & mmi_barcodereader_attribute[i].value)
            {
                mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)GetString(mmi_barcodereader_attribute[i].string_id));
                mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L":");
                length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
                mmi_ucs2ncat(
                    g_barcodereader_cntx.formatted_text_buf, 
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    g_barcodereader_cntx.app_content.ct_element[i].length);
                memset(g_barcodereader_cntx.formatted_text_buf + (length + g_barcodereader_cntx.app_content.ct_element[i].length) * ENCODING_LENGTH, 0, 2);
                mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L";");
            }
        }
        sendData->string = g_barcodereader_cntx.formatted_text_buf;
        sendData->stringlength = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
        /*modify the last signal to '.' */
        temp_p = mmi_ucs2rchr(g_barcodereader_cntx.formatted_text_buf, ';');
        *temp_p = '.';   
        if (sendData->stringlength > MMI_BARCODEREADER_MAX_SMS_CONTENT)
        {
            sendData->stringlength = MMI_BARCODEREADER_MAX_SMS_CONTENT;
        }
        break;
        
    case MMI_BARCODEREADER_APP_EMAIL:
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_COMMON;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
        break;
        
    case MMI_BARCODEREADER_APP_DTXT:
        mmi_ucs2cpy(g_barcodereader_cntx.formatted_text_buf, "");
        if (g_barcodereader_cntx.app_content.ct_attribute & mmi_barcodereader_attribute[MMI_BARCODEREADER_ATTRIBUTE_SUB].value)
        {
            if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].length != 0)
            {
                mmi_ucs2ncat(
                    g_barcodereader_cntx.formatted_text_buf, 
                    g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].str_addr,
                    g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].length);
                mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L"\n");
            }
        }
        length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
        mmi_ucs2ncat(
            g_barcodereader_cntx.formatted_text_buf, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length);
        memset(g_barcodereader_cntx.formatted_text_buf + 
            (length + g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length) * 2, 
            0, 2);       
        sendData->string = g_barcodereader_cntx.formatted_text_buf;
        sendData->stringlength = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
        break;
                
    default:
        break;
    }
    //mmi_frm_sms_api_entry_write_msg(sendData);
#else
    {
        length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
        
        if (length > MMI_BARCODEREADER_MAX_SMS_CONTENT )
            length = MMI_BARCODEREADER_MAX_SMS_CONTENT;
        
        src = (U16*) & g_barcodereader_cntx.formatted_text_buf[0];

        if (mmi_frm_sms_check_UCS2((U16*)src, (U16)length))
        {
            sendData->string = OslMalloc((length+1)*ENCODING_LENGTH);
            sendData->dcs = SMSAL_UCS2_DCS;
            mmi_ucs2ncpy((PS8) sendData->string, (PS8)src, length);
            sendData->stringlength = length;   
        }
        else
        {
            U32 len,buf_len;
            len = mmi_frm_sms_count_extension_char((U16*)src,(U32)length);
            
            /* due to ctrl buffer max buffer size is 2048b */
            buf_len = ((len+length+1)*ENCODING_LENGTH < 2048)? (len+length+1)*ENCODING_LENGTH:2048;
            
            sendData->string = OslMalloc(buf_len);
            sendData->dcs = SMSAL_DEFAULT_DCS;
            mmi_frm_sms_add_escape_symbol_for_extension_char((U16*)sendData->string,(U16*) src, (U16)length);
            sendData->stringlength = mmi_ucs2strlen(sendData->string);        
        }    
        
    } 
#endif   
    
    mmi_frm_sms_api_entry_write_msg(sendData);
    OslMfree(sendData);
}

#ifndef __MMI_BARCODEREADER_OPERATOR1__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_send_by_sms
 * DESCRIPTION
 *  functions to send sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_send_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    U32 length=0;
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    U32 content_count;
    HILITE_STR attr_content[MMI_BARCODEREADER_CONTENT_MAX_COUNT];
    #define MMI_BARCDEREADER_SMS_SM_LENGTH 20  /*current sms only supoort 20 character count number */
#else
    U16 *src;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
    g_barcodereader_cntx.total_receiver = 1;

#ifdef __MMI_BARCODEREADER_OPERATOR1__
    switch(g_barcodereader_cntx.selected_app_type)
    {
    case MMI_BARCODEREADER_APP_SMS:
        
        //sendData->string = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr;
        if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length > MMI_BARCODEREADER_MAX_SMS_CONTENT )
            sendData->stringlength = MMI_BARCODEREADER_MAX_SMS_CONTENT;
        else 
            sendData->stringlength = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length;
        //mmi_ucs2ncpy(sendData->string, g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr, length);
        sendData->string = OslMalloc((sendData->stringlength + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy(sendData->string, g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr, sendData->stringlength);
        memset(sendData->string + sendData->stringlength * ENCODING_LENGTH, 0, 2);
        sendData->dcs = SMSAL_UCS2_DCS;

        /*get sms receiver*/
        content_count = mmi_barcodereader_calc_attribute_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length,
                        MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);  
        if (content_count == 1)
        {
            length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length;
        }
        else
        {
            if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
            {
                content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
            }
            
            mmi_barcodereader_split_multi_content(
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr, 
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length, 
                MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
                attr_content, 
                content_count);
            
            /*currently the sms only support one number receiver*/
            length = attr_content[0].length;
        }
        if (length > MMI_BARCDEREADER_SMS_SM_LENGTH)
        {
            length = MMI_BARCDEREADER_SMS_SM_LENGTH; 
        }
        mmi_ucs2_n_to_asc(
            (PS8)sendData->number, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr, 
            length);
        //strcpy(sendData->number ,"13811479771");
        sendData->number[length] = 0;

        //for multi receiver
        g_barcodereader_cntx.current_receiver = 1;
        g_barcodereader_cntx.total_receiver = content_count;
        break;

    case MMI_BARCODEREADER_APP_VCARD:
        sendData->dcs = SMSAL_UCS2_DCS;
        break;
        
    case MMI_BARCODEREADER_APP_EMAIL:
        /*should do nothing*/
        break;
        
    case MMI_BARCODEREADER_APP_DTXT:
        break;
        
    case MMI_BARCODEREADER_APP_WAPSELL:
        break;
        
    case MMI_BARCODEREADER_APP_SMSSELL:
        /*number*/
        
        break;
        
    case MMI_BARCODEREADER_APP_IVRSELL:
        break;
        
    default:
        break;
    }

/*this paragraph is used to suit for the old parse*/
#else
    {
        length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
        
        if (length > MMI_BARCODEREADER_MAX_SMS_CONTENT )
            length = MMI_BARCODEREADER_MAX_SMS_CONTENT;
        
        /* set number 0 */
        memset((S8*) sendData->number, 0, sizeof(sendData->number));
        
        src = (U16*) & g_barcodereader_cntx.formatted_text_buf[0];

        if (mmi_frm_sms_check_UCS2((U16*)src, (U16)length))
        {
            sendData->string = OslMalloc((length+1)*ENCODING_LENGTH);
            sendData->dcs = SMSAL_UCS2_DCS;
            mmi_ucs2ncpy((PS8) sendData->string, (PS8)src, length);
            sendData->stringlength = length;   
        }
        else
        {
            U32 len,buf_len;
            len = mmi_frm_sms_count_extension_char((U16*)src,(U32)length);
            
            /* due to ctrl buffer max buffer size is 2048b */
            buf_len = ((len+length+1)*ENCODING_LENGTH < 2048)? (len+length+1)*ENCODING_LENGTH:2048;
            
            sendData->string = OslMalloc(buf_len);
            sendData->dcs = SMSAL_DEFAULT_DCS;
            mmi_frm_sms_add_escape_symbol_for_extension_char((U16*)sendData->string,(U16*) src, (U16)length);
            sendData->stringlength = mmi_ucs2strlen(sendData->string);        
        }    
    }
#endif 

#if defined(__MMI_DUAL_SIM_MASTER__)
     sendData->sendrequire |= MMI_FRM_SMS_DISP_SIM_OPT;
#endif
     
    //mmi_frm_sms_api_entry_write_msg(&sendData);
    mmi_frm_sms_send_sms_for_other_app(mmi_barcodereader_send_sms_callback, MOD_MMI, sendData);
    OslMfree(sendData);
}
#endif


#ifdef __MMI_BARCODEREADER_OPERATOR1__
#ifdef __MMI_EMAIL__
static void mmi_barcodereader_func_send_by_email()
{
    mmi_email_app_send_param_struct email_param;
    S8 *string_addr;
    U16 length, i;
    U32 content_count;
    HILITE_STR attr_content[MMI_BARCODEREADER_CONTENT_MAX_COUNT];
    S16 subject[EMAIL_COMP_SUBJ_LEN];
    S16 content[EMAIL_MAX_CONT_LEN];
    S16 to[MMI_EMAIL_MAX_LEN_ADDR_LIST][MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1];
    U8 flag = 0;

    mmi_email_app_send_init_param_to_null(&email_param);
    email_param.is_save_to_draft = g_barcodereader_cntx.is_save_to_draft;
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    /*should add not cmcc code */
#else
    switch (g_barcodereader_cntx.selected_app_type)
    {
    case MMI_BARCODEREADER_APP_DTXT:
    case MMI_BARCODEREADER_APP_EMAIL:
        /*fill the to address*/
        if (g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_ATTRIBUTE_VALUE_TO)
        {
            flag |= EMAIL_TO_FILL_FLAG;
            content_count = mmi_barcodereader_calc_attribute_multi_content(
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TO].str_addr,
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TO].length,
                MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);  
            if (content_count == 1)
            {
                length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TO].length;
                if (length > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
                {
                    length = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS;
                }

                mmi_ucs2ncpy(
                    (PS8)to[0], 
                    g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TO].str_addr, 
                    length);
                memset(to[0] + length * ENCODING_LENGTH, 0, 2);
                email_param.to_addr[0].addr_mail = (PS8)to[0];
            }
            else
            {
                if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
                {
                    content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
                }
                if (content_count > MMI_EMAIL_MAX_LEN_ADDR_LIST)
                {
                    content_count = MMI_EMAIL_MAX_LEN_ADDR_LIST;
                }
                
                mmi_barcodereader_split_multi_content(
                    g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TO].str_addr, 
                    g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TO].length, 
                    MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
                    attr_content, 
                    content_count);
                
                for (i = 0 ; i < content_count ; i++)
                {
                    length = attr_content[i].length;
                    if (length >  MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)  // 60 * 2
                    {
                        length = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS;
                    }
                    mmi_ucs2ncpy((PS8)to[i], attr_content[i].str_addr, length);
                    memset(to[i] + length * ENCODING_LENGTH, 0, 2);
                    
                    email_param.to_addr[i].addr_mail = (PS8)to[i];/*UCS2 string*/
                }
            }
            
        }
        
        /*file content*/
        if (g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB)
        {
            flag |= EMAIL_SUBJ_FILL_FLAG;
            length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].length;
            if (length > EMAIL_COMP_SUBJ_LEN)
            {
                length = EMAIL_COMP_SUBJ_LEN;
            }
            mmi_ucs2ncpy(
                (PS8)subject, 
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SUB].str_addr, 
                length);
            memset(subject + length * ENCODING_LENGTH, 0, 2);

            email_param.subj = (PS8)subject;    
        }

        if (g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_ATTRIBUTE_VALUE_TXT)
        {
            flag |= EMAIL_CONT_FILL_FLAG;
            length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length;
            if (length > EMAIL_MAX_CONT_LEN)
            {
                length = EMAIL_MAX_CONT_LEN;
            }
            mmi_ucs2ncpy(
                (PS8)content, 
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr, 
                length);
            memset(content + length * ENCODING_LENGTH, 0, 2);
            
            email_param.cont = (PS8)content;
        }
        break;

    default:
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_COMMON;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;

        mmi_barcodereader_display_error_popup();
        return;
    }

#endif    
    mmi_email_app_send(&email_param, flag);

}

static void mmi_barcodereader_func_save_email()
{
    g_barcodereader_cntx.is_save_to_draft = MMI_TRUE;
    mmi_barcodereader_func_send_by_email();
}
#endif
#endif

#ifdef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_func_preview(void)
{
    mmi_barcodereader_enter_preview_screen();
    DeleteUptoScrID(SCR_ID_BARCODEREADER_MAIN);
}


static void mmi_barcodereader_func_back_to_main(void)
{
    DeleteUptoScrID(SCR_ID_BARCODEREADER_MAIN);
    GoBackHistory();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_make_call
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *src;
    S32 length;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    length = g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length;
    src =  g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr;
#else
    length = g_barcodereader_cntx.highlight[g_barcodereader_cntx.current_highlight].content.length;
    src = g_barcodereader_cntx.highlight[g_barcodereader_cntx.current_highlight].content.str_addr;
#endif

    mmi_ucs2ncpy(g_barcodereader_cntx.input_string, src, length);
    memset(g_barcodereader_cntx.input_string + length * 2, 0, 2);

    mmi_ucs2_to_asc((PS8) g_barcodereader_cntx.input_string_tmp, (PS8) g_barcodereader_cntx.input_string);
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---MakeCall, g_barcodereader_cntx.input_string: %s---*\n", g_barcodereader_cntx.input_string_tmp);
#ifdef __MMI_UCM__
    mmi_ucm_app_entry_dial_option((PU8)g_barcodereader_cntx.input_string, NULL, NULL);
#else /* __MMI_UCM__ */ 
    MakeCall((PS8) g_barcodereader_cntx.input_string);
#endif
}


#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_make_voip_call
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_make_voip_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *src;
    U16 *dest;
    S32 length;
    U16 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length;
    src = (U16*) g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr;
    dest = (U16*)g_barcodereader_cntx.input_string;

    for (idx = 0; idx < length * ENCODING_LENGTH; idx += ENCODING_LENGTH)
    {
        if (((U16) '0' <= *src && *src <= (U16) '9') || *src == (U16) 'p' || *src == (U16) 'w' || *src == (U16) '+')
        {
            *dest++ = *src;
        }

        src++;
    }

    *dest = 0;
    mmi_ucs2_to_asc((PS8) g_barcodereader_cntx.input_string_tmp, (PS8) g_barcodereader_cntx.input_string);
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---mmi_voip_app_make_call, g_barcodereader_cntx.input_string: %s---*\n", g_barcodereader_cntx.input_string_tmp);
    mmi_voip_app_make_call((PU8) g_barcodereader_cntx.input_string);
}
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_save_url
 * DESCRIPTION
 *  send save url request to wap task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_save_url(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length;
    S16 url_addr[MMI_BARCODEREADER_MAX_URL_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__    
    if (g_barcodereader_cntx.selected_app_type == MMI_BARCODEREADER_APP_BUSINESS)
    {
        length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].length;
        if (length > MMI_BARCODEREADER_MAX_URL_LEN)
        {
            length = MMI_BARCODEREADER_MAX_URL_LEN;
        }
        mmi_ucs2ncpy(
            (PS8)url_addr, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].str_addr,
            length);
    }
    else
    {
        length =g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length; 
        if (length > MMI_BARCODEREADER_MAX_URL_LEN)
            length = MMI_BARCODEREADER_MAX_URL_LEN;

        mmi_ucs2ncpy(
            (PS8)url_addr, 
            g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr,
            length);
    }
    memset(url_addr + length * ENCODING_LENGTH, 0, length);
#else
    length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].length; 
    if (length > MMI_BARCODEREADER_MAX_URL_LEN)
        length = MMI_BARCODEREADER_MAX_URL_LEN;
    mmi_ucs2ncpy(
        (PS8)url_addr, 
        g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].str_addr,
        length); 
    memset(url_addr + length * ENCODING_LENGTH, 0, length);
#endif
    wap_start_browser(WAP_BROWSER_ADD_BOOKMARK, (PU8)url_addr);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_open_url
 * DESCRIPTION
 *  send open url request to wap task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_open_url(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    PU8 src;
    PU8 dest;
    U16 idx = 0;
#endif
    S32 length;
    S16 url_addr[MMI_BARCODEREADER_MAX_URL_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    length =g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length * ENCODING_LENGTH; 
    if (length>=MMI_BARCODEREADER_MAX_URL_LEN*ENCODING_LENGTH)
        length = (MMI_BARCODEREADER_MAX_URL_LEN-1)*ENCODING_LENGTH;

    src = (PU8) g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr;
    dest = (PU8)&url_addr[0];
    for (idx = 0; idx < length ; idx++)
    {
        *dest++ = *src++;
    }
    *dest = 0;
    *(dest + 1) = 0;
#else
    length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].length; 
    if (length > MMI_BARCODEREADER_MAX_URL_LEN)
        length = MMI_BARCODEREADER_MAX_URL_LEN;
    mmi_ucs2ncpy(
        (PS8)url_addr, 
        g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].str_addr,
        length);
    memset(url_addr + length * ENCODING_LENGTH, 0, length);
#endif
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)url_addr);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_save_done
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_save_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0, mmi_barcodereader_save_done_timeout);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_save_done_timeout
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_save_done_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    /*DeleteNHistory(1);*/
#endif
    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_save
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    U32 written;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* blt base only */
    gdi_layer_set_blt_layer(g_barcodereader_cntx.base_layer_handle, 0, 0, 0);

    /*get the storage file path*/
    {
        S32 create_result = 0;
        mmi_barcodereader_get_storage_file_path(buf_filename);
        create_result = mmi_barcodereader_create_file_dir((PS8)buf_filename);
        g_barcodereader_cntx.last_error.error_result = FS_NO_ERROR;

        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            g_barcodereader_cntx.last_error.error_result = FS_WRITE_PROTECTION;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
        }
        else if (create_result == FS_DISK_FULL)
        {
            
            g_barcodereader_cntx.last_error.error_result = FS_DISK_FULL;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            g_barcodereader_cntx.last_error.error_result = FS_ROOT_DIR_FULL;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
        }

        if (create_result < FS_NO_ERROR)
        {
            g_barcodereader_cntx.last_error.error_result = create_result;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
            mmi_barcodereader_display_error_popup();
            return;
        }
    }

    
    gdi_layer_lock_frame_buffer();

    /* show popup category */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 

    EntryNewScreen(SCR_ID_BARCODEREADER_SAVE, NULL, NULL, NULL);

    ShowCategory65Screen((PU8) GetString(STR_GLOBAL_SAVING), IMG_GLOBAL_SAVE, NULL);
    g_barcodereader_cntx.is_cat65_show = TRUE;

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

    mmi_barcodereader_get_next_filename(buf_filename);

    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---save file path = %s---*\n", buf_filename);

    file_handle = FS_Open((U16*) buf_filename, FS_CREATE | FS_READ_WRITE);

    if (file_handle >= FS_NO_ERROR)
    {
        S32 string_buffer_size = mmi_ucs2strlen(g_barcodereader_cntx.text_buf) * ENCODING_LENGTH;
        U8 file_header[2] = {0xFE,0xff};
        FS_Write(file_handle, (void*)file_header, 2, (U32*) & written);
        FS_Write(file_handle, (void*)g_barcodereader_cntx.text_buf, string_buffer_size + 1, (U32*) & written);
        FS_Close(file_handle);
        /*should fmgr support to search hidden file*/
        //FS_SetAttributes((WCHAR*)buf_filename,FS_ATTR_HIDDEN);

        /* cant write in whole file, must be disk full */
        if (string_buffer_size+1 != written)
        {
            /* delete the file that is not save complete */
            FS_Delete((U16*) buf_filename);

            g_barcodereader_cntx.last_error.error_result = FS_DISK_FULL;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;

            if (g_barcodereader_cntx.is_cat65_show)
            {
                g_barcodereader_cntx.is_cat65_show = FALSE;
                ExitCategoryFunction();
            }

            /* will display a popup, go out application and re-enter */
            mmi_barcodereader_display_error_popup();
            return;
        }
    }
    else
    {
        g_barcodereader_cntx.last_error.error_result = file_handle;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
  
        if (g_barcodereader_cntx.is_cat65_show)
        {
            g_barcodereader_cntx.is_cat65_show = FALSE;
            ExitCategoryFunction();
        }

        /* will display a popup, go out application and re-enter */
        mmi_barcodereader_display_error_popup();
        return;
    }

    if (g_barcodereader_cntx.is_cat65_show)
    {
        g_barcodereader_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }
    mmi_barcodereader_save_done();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_next_filename
 * DESCRIPTION
 *  get next file name for QRcode decoded text
 * PARAMETERS
 *  file_buf_p      [IN]        
 *  a(?)            [OUT]       Next filename
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_get_next_filename(PS8 file_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buffer[FMGR_MAX_PATH_LEN];
    U16 path[FMGR_MAX_PATH_LEN], temp_path[FMGR_MAX_PATH_LEN];
    MYTIME currentDateTime, inc_time, result_time;
    FS_HANDLE handle = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get/store sequentail number */
    switch (g_barcodereader_cntx.selected_app_type)
    {
        case MMI_BARCODEREADER_APP_VCARD:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_VCARD);
            break;

#ifdef __MMI_BARCODEREADER_OPERATOR1__
        case MMI_BARCODEREADER_APP_WAPSELL:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_WAPSELL);
            break;

        case MMI_BARCODEREADER_APP_SMSSELL:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_SMSSELL);
            break;

        case MMI_BARCODEREADER_APP_IVRSELL:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_IVRSELL);
            break;
#else
        case MMI_BARCODEREADER_APP_BUSINESS:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_BUSINESS);
#endif
        case MMI_BARCODEREADER_APP_EMAIL:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_EMAIL);
            break;

        case MMI_BARCODEREADER_APP_SMS:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_SMS);
            break;

        case MMI_BARCODEREADER_APP_DTXT:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_DTXT);
            break;

#ifndef __MMI_BARCODEREADER_OPERATOR1__
        case MMI_BARCODEREADER_APP_PHONENUMBER:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_PHONENUMBER);
            break;

        case MMI_BARCODEREADER_APP_URL:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_URL);
            break;

        case MMI_BARCODEREADER_APP_EMAILADDRESS:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_EMAILADDRESS);
            break;
#endif        
        default:
            sprintf((PS8) buffer, "%s", "");
            break; 
    }

    mmi_asc_to_ucs2((PS8) temp_path, (PS8) buffer);

    GetDateTime(&currentDateTime);

    kal_wsprintf(
        path, 
        "%02d%02d%02d_%02d%02d%02d", 
        currentDateTime.nYear,
        currentDateTime.nMonth,
        currentDateTime.nDay,
        currentDateTime.nHour,
        currentDateTime.nMin,
        currentDateTime.nSec);
    mmi_ucs2cat((PS8)temp_path, (PS8)path);
    mmi_ucs2cat((PS8)temp_path, (PS8) MMI_BARCODEREADER_FILE_EXT_NAME);
    mmi_barcodereader_get_storage_file_path((PS8)path);

    mmi_ucs2cat((PS8)path, (PS8)temp_path);
    handle = FS_Open(path, FS_READ_ONLY);
    memset(&inc_time, 0, sizeof(MYTIME));
    inc_time.nSec = 1;
    while (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);
        IncrementTime(currentDateTime, inc_time, &result_time);
        memcpy(&currentDateTime,&result_time,sizeof(MYTIME));
        mmi_asc_to_ucs2((PS8) temp_path, (PS8) buffer);
        kal_wsprintf(
            path, 
            "%02d%02d%02d_%02d%02d%02d", 
            result_time.nYear,
            result_time.nMonth,
            result_time.nDay,
            result_time.nHour,
            result_time.nMin,
            result_time.nSec);
        mmi_ucs2cat((PS8)temp_path, (PS8)path);
        mmi_ucs2cat((PS8)temp_path, (PS8) MMI_BARCODEREADER_FILE_EXT_NAME);
        mmi_barcodereader_get_storage_file_path((PS8)path);
        mmi_ucs2cat((PS8)path, (PS8)temp_path);
        handle = FS_Open(path, FS_READ_ONLY);
    }
    if (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);  
    }
    
    mmi_ucs2cpy(file_buf_p, (S8*)path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_init_forward_menu
 * DESCRIPTION
 *  initialize forward menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_init_forward_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE, mmi_barcodereader_hilight_save);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_EXIT, mmi_barcodereader_hilight_exit);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK, mmi_barcodereader_hilight_save_to_phonebook);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS, mmi_barcodereader_hilight_edit_by_sms);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS, mmi_barcodereader_hilight_save_sms);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS, mmi_barcodereader_hilight_send_by_sms);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL, mmi_barcodereader_dummy_func);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_EMAIL, mmi_barcodereader_dummy_func);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL, mmi_barcodereader_dummy_func);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS, mmi_barcodereader_hilight_edit_by_mms);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL, mmi_barcodereader_hilight_make_call);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_OPEN_URL, mmi_barcodereader_hilight_open_url);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_URL, mmi_barcodereader_hilight_save_url);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_ORDER, mmi_barcodereader_hilight_order);
#else
    /*sms*/
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS, mmi_barcodereader_hilight_edit_by_sms);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS, mmi_barcodereader_hilight_save_sms);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER, mmi_barcodereader_hilight_save);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_PREVIEW, mmi_barcodereader_hilight_preview);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_BACK_TO_MAIN, mmi_barcodereader_hilight_back_to_main);
    
    /*vcard*/
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK, mmi_barcodereader_hilight_save_to_phonebook);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL, mmi_barcodereader_hilight_save_email);

    /*txt*/
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SEND_BY_MMS, mmi_barcodereader_hilight_edit_by_mms);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL, mmi_barcodereader_hilight_send_by_email);
    
    /*mail*/
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_EMAIL, mmi_barcodereader_hilight_save_email);
    
    /*wap sell*/
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_OPEN_URL, mmi_barcodereader_hilight_open_url);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_SAVE_URL, mmi_barcodereader_hilight_save_url);
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_COMMEND, mmi_barcodereader_hilight_to_commend);

    /*sms sell*/
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_ORDER, mmi_barcodereader_hilight_order);

    /*ivr sell*/
    SetHiliteHandler(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL, mmi_barcodereader_hilight_make_call);

    /*file list option*/
    SetHiliteHandler(MENU_ID_BARCODEREADER_FILE_OPEN, mmi_barcodereader_hilight_enter_from_filelist_to_app_preview);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_save_sms_callback
 * DESCRIPTION
 *  callback function of save_sms
 * PARAMETERS
 *  dummy               [?]         
 *  mod                 [IN]        
 *  flag                [IN]        
 *  U16(?)              [IN]        Flag
 *  module_type(?)      [IN]        Mod
 *  void(?)             [OUT]       Dummy
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_save_sms_callback(void *dummy, module_type mod, U16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_result_handler_struct result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result.delete_sms_screen = KAL_TRUE;
    result.display_popup = KAL_TRUE;
    result.request_type = MMI_FRM_SMS_REQ_SAVE;
    result.result = flag;
    mmi_frm_sms_api_result_handler(&result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_send_sms_callback
 * DESCRIPTION
 *  callback function of send_sms
 * PARAMETERS
 *  dummy               [?]         
 *  mod                 [IN]        
 *  flag                [IN]        
 *  U16(?)              [IN]        Flag
 *  module_type(?)      [IN]        Mod
 *  void(?)             [OUT]       Dummy
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_send_sms_callback(void *dummy, module_type mod, U16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_result_handler_struct result;
#ifdef __MMI_BARCODEREADER_OPERATOR1__    
    PS8 src;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FRM_SMS_OK == flag)
    {
        /********************************
        * delete order check screen
        ********************************/
        DeleteScreenIfPresent(SCR_ID_BARCODEREADER_ORDER_CONFIRM);
    }


    if (g_barcodereader_cntx.total_receiver == 1 || flag != MMI_FRM_SMS_OK)
    {
        result.delete_sms_screen = KAL_TRUE;
        result.display_popup = KAL_TRUE;
        result.request_type = MMI_FRM_SMS_REQ_SEND;
        result.result = flag;
        mmi_frm_sms_api_result_handler(&result);
    }
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    else if (g_barcodereader_cntx.total_receiver != 1)
    {
        mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
        S32 length=0;
        HILITE_STR attr_content[MMI_BARCODEREADER_CONTENT_MAX_COUNT];

        if (g_barcodereader_cntx.current_receiver >= g_barcodereader_cntx.total_receiver)
        {
            return;
            }

        if (g_barcodereader_cntx.selected_app_type == MMI_BARCODEREADER_APP_SMS)
            {
#define MMI_BARCODEREADER_SMS_SM_COUNT 20
            //S8 number[MMI_BARCODEREADER_SMS_SM_COUNT + 1];

            /*number */
            mmi_barcodereader_split_multi_content(
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].str_addr, 
                g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SM].length, 
                MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
                attr_content, 
                g_barcodereader_cntx.total_receiver);
            length = attr_content[g_barcodereader_cntx.current_receiver].length;
            src = attr_content[g_barcodereader_cntx.current_receiver].str_addr;

            if (length > MMI_BARCODEREADER_SMS_SM_COUNT)
            {
                length = MMI_BARCODEREADER_SMS_SM_COUNT;
            }

            mmi_ucs2_n_to_asc((PS8)sendData->number, (PS8)src, (U32)(length * 2));
            sendData->number[length] = 0;

            /*content*/
            src = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].str_addr;
            
                if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length > MMI_BARCODEREADER_MAX_SMS_CONTENT )
                    length = MMI_BARCODEREADER_MAX_SMS_CONTENT;
                else 
                    length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TXT].length;

            if (mmi_frm_sms_check_UCS2((U16*)src,(U16)length))
            {
            sendData->string = OslMalloc((length + 1) * ENCODING_LENGTH);
            sendData->dcs = SMSAL_UCS2_DCS;
                mmi_ucs2ncpy((PS8) sendData->string, (PS8)src, length);
                sendData->stringlength = length;   
            }
            else
            {
                U32 len,buf_len;
                len = mmi_frm_sms_count_extension_char((U16*)src,(U32)length);
                
                /* due to ctrl buffer max buffer size is 2048b */
                buf_len = ((len+length+1)*ENCODING_LENGTH < 2048)? (len+length+1)*ENCODING_LENGTH:2048;
                
                sendData->string = OslMalloc(buf_len);
                sendData->dcs = SMSAL_DEFAULT_DCS;
                mmi_frm_sms_add_escape_symbol_for_extension_char((U16*)sendData->string,(U16*) src, (U16)length);
                sendData->stringlength = mmi_ucs2strlen(sendData->string);
            }
            memset(sendData->string + length * ENCODING_LENGTH, 0, 2);
        }      
        
            sendData->sendcheck |= MMI_FRM_SMS_SCR;
            
        #if defined(__MMI_DUAL_SIM_MASTER__)
            sendData->sendrequire |= MMI_FRM_SMS_DISP_SIM_OPT;
        #endif
        mmi_frm_sms_send_sms_for_other_app(mmi_barcodereader_send_sms_callback, MOD_MMI, sendData);
            OslMfree(sendData);
        }        
#endif

}






#ifndef __MMI_BARCODEREADER_OPERATOR1__


static void mmi_barcodereader_exit_forward_to_apps(void)
{
    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_forward_to_apps
 * DESCRIPTION
 *  forward selected content to applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_forward_to_apps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    U16 menu_id = 0;
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    if (g_barcodereader_cntx.app_list_idx_count == 0)
        g_barcodereader_cntx.selected_app_type = MMI_BARCODEREADER_NONE;
    else
        g_barcodereader_cntx.selected_app_type =
           g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.selected_hilight_idx];
#else
    g_barcodereader_cntx.selected_app_type =
           g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.selected_hilight_idx];
#endif
    switch (g_barcodereader_cntx.selected_app_type)
    {
        case MMI_BARCODEREADER_APP_VCARD:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_VCARD;
            title_id = STR_ID_BARCODEREADER_TO_CARD;
            mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK);
            break;

#ifndef __MMI_BARCODEREADER_OPERATOR1__
        case MMI_BARCODEREADER_APP_BUSINESS:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_BUSINESS;
            title_id = STR_ID_BARCODEREADER_TO_BUSINESS;
            if (mmi_bootup_is_network_service_available() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
            {
            #if !defined(__MMI_DUAL_SIM_MASTER__)           
                if ((mmi_bootup_is_sim_valid()==TRUE) && g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].length != 0 && g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SID].length != 0)
            #else   /* __MMI_DUAL_SIM_MASTER__ */
                if ((mmi_bootup_is_sim_valid()==TRUE || !MTPNP_PFAL_Is_Card2Absent()) && g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].length != 0 && g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SID].length != 0)
            #endif  /* __MMI_DUAL_SIM_MASTER__ */
                {
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_ORDER);
                }
                else
                {
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_ORDER);
                }
            #ifdef WAP_SUPPORT
                if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].length != 0)
                {
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
                }
                else
                {
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
                }
            #else
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            #endif
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_ORDER);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            }
            break;
#else
        case MMI_BARCODEREADER_APP_SMSSELL:
            break;

        case MMI_BARCODEREADER_APP_WAPSELL:
            break;

        case MMI_BARCODEREADER_APP_IVRSELL:
            break;
#endif
        case MMI_BARCODEREADER_APP_SMS:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_SMS;
            title_id = STR_ID_BARCODEREADER_TO_SMS;
        #if !defined(__MMI_DUAL_SIM_MASTER__)
            if (mmi_bootup_is_sim_valid() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
        #else   /* __MMI_DUAL_SIM_MASTER__ */
            if ((mmi_bootup_is_sim_valid() == TRUE || !MTPNP_PFAL_Is_Card2Absent()) &&
                mmi_bootup_get_active_flight_mode() == 0)
        #endif  /* __MMI_DUAL_SIM_MASTER__ */
            {
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
            }
            break;
        case MMI_BARCODEREADER_APP_EMAIL:
            /*used to show email save to draft box or not*/
            g_barcodereader_cntx.is_save_to_draft = MMI_FALSE;
            menu_id = MENU_ID_BARCODEREADER_APP_TO_EMAIL;
            title_id = STR_ID_BARCODEREADER_TO_EMAIL;
        #if !defined(__MMI_DUAL_SIM_MASTER__)
            if (mmi_bootup_is_sim_valid() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
        #else   /* __MMI_DUAL_SIM_MASTER__ */
            if ((mmi_bootup_is_sim_valid() == TRUE || !MTPNP_PFAL_Is_Card2Absent()) &&
                mmi_bootup_get_active_flight_mode() == 0)
        #endif  /* __MMI_DUAL_SIM_MASTER__ */
            {
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_EMAIL);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL);
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_EMAIL);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL);
            }
            break;
        case MMI_BARCODEREADER_APP_DTXT:
            /*used to show email save to draft box or not*/
            g_barcodereader_cntx.is_save_to_draft = MMI_FALSE;
            menu_id = MENU_ID_BARCODEREADER_APP_TO_DTXT;
            title_id = STR_ID_BARCODEREADER_TO_CONTENT;
        #if !defined(__MMI_DUAL_SIM_MASTER__)
            if (mmi_bootup_is_sim_valid() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
        #else   /* __MMI_DUAL_SIM_MASTER__ */
            if ((mmi_bootup_is_sim_valid() == TRUE || !MTPNP_PFAL_Is_Card2Absent()) &&
                mmi_bootup_get_active_flight_mode() == 0)
        #endif  /* __MMI_DUAL_SIM_MASTER__ */
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
            #ifdef MMS_SUPPORT
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            #else
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            #endif

            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL);
            }
            break;
#ifndef __MMI_BARCODEREADER_OPERATOR1__
        case MMI_BARCODEREADER_APP_PHONENUMBER:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_GENERAL;
            title_id = STR_ID_BARCODEREADER_TO_GENERAL;
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
            mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK);
            if (mmi_barcodereader_is_network_permit(MMI_TRUE))
            {

                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
                if (mmi_barcodereader_is_network_permit(MMI_FALSE))
                {
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                #ifdef MMS_SUPPORT
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                #else
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                #endif
                }
                else
                {
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                }
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            }
            break;
        case MMI_BARCODEREADER_APP_URL:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_GENERAL;
            title_id = STR_ID_BARCODEREADER_TO_GENERAL;
            if (mmi_barcodereader_is_network_permit(MMI_TRUE))
            {
            #ifdef WAP_SUPPORT
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            #else
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            #endif
            #ifdef WAP_SUPPORT
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
            #else
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
            #endif
                if (mmi_barcodereader_is_network_permit(MMI_FALSE))
                {
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                #ifdef MMS_SUPPORT
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                #else
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                #endif
                }
                else
                {
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                }
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            }
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
            break;
        case MMI_BARCODEREADER_APP_EMAILADDRESS:
        case MMI_BARCODEREADER_NONE:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_GENERAL;
            title_id = STR_ID_BARCODEREADER_TO_GENERAL;

            if (mmi_barcodereader_is_network_permit(MMI_FALSE))
            {
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
            #ifdef MMS_SUPPORT
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            #else
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            #endif
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            }
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
            break;
#endif
        default:
            ASSERT(0);
            break;
    }

#ifdef JATAAYU_SUPPORT
    /* if mms is reentranted, then hide edit_by_mms function */
    if (mms_is_re_entrant())
        mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
#endif

    EntryNewScreen(SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION, mmi_barcodereader_exit_forward_to_apps, mmi_barcodereader_forward_to_apps, NULL);

    /* allocate storage path buffer */
    g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_barcodereader_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    mmi_barcodereader_get_storage_file_path((PS8)g_barcodereader_cntx.storage_filepath);


    /* ENTRY CATEGORY SCREEN */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION);
    nItems = GetNumOfChild_Ext(menu_id);
    GetSequenceStringIds_Ext(menu_id, ItemList);
    GetSequenceImageIds_Ext(menu_id, ItemIcons);
    SetParentHandler(menu_id);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(menu_id, PopUpList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif


#ifdef __MMI_BARCODEREADER_OPERATOR1__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_forward_to_apps_operator1
 * DESCRIPTION
 *  operator1 forward to app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_forward_to_apps_operator1(void)
{
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    U16 menu_id = 0;
    U16 title_id = 0;

    g_barcodereader_cntx.selected_app_type = g_barcodereader_cntx.app_type_list[0];

    switch (g_barcodereader_cntx.app_type_list[0])
    {
    case MMI_BARCODEREADER_APP_VCARD:
        menu_id = MENU_ID_BARCODEREADER_APP_TO_VCARD;
        title_id = STR_ID_BARCODEREADER_VCARD;
        if (g_barcodereader_cntx.highlight[g_barcodereader_cntx.current_highlight].highlight_type == 
            MMI_BARCODEREADER_HIGHLIGHT_TYPE_TEL ||
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.current_highlight].highlight_type == 
            MMI_BARCODEREADER_HIGHLIGHT_TYPE_M)
        {
            mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
        }
        break;

    case MMI_BARCODEREADER_APP_EMAIL:
        menu_id = MENU_ID_BARCODEREADER_APP_TO_EMAIL;
        title_id = STR_ID_BARCODEREADER_EMAIL;
        break;

    case MMI_BARCODEREADER_APP_SMS:
        menu_id = MENU_ID_BARCODEREADER_APP_TO_SMS;
        title_id = STR_ID_BARCODEREADER_SMS;
        break;

    case MMI_BARCODEREADER_APP_DTXT:
        menu_id = MENU_ID_BARCODEREADER_APP_TO_DTXT;
        title_id = STR_ID_BARCODEREADER_DTXT;
        break;

    case MMI_BARCODEREADER_APP_WAPSELL:
        menu_id = MENU_ID_BARCODEREADER_APP_TO_WAPSELL;
        title_id = STR_ID_BARCODEREADER_WAPSELL;
        if (g_barcodereader_cntx.highlight[g_barcodereader_cntx.current_highlight].highlight_type == 
            MMI_BARCODEREADER_HIGHLIGHT_TYPE_TEL)
        {
            mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
        }
        break;

    case MMI_BARCODEREADER_APP_SMSSELL:
        menu_id = MENU_ID_BARCODEREADER_APP_TO_SMSSELL;
        title_id = STR_ID_BARCODEREADER_SMSSELL;
        if (g_barcodereader_cntx.highlight[g_barcodereader_cntx.current_highlight].highlight_type == 
            MMI_BARCODEREADER_HIGHLIGHT_TYPE_TEL)
        {
            mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
        }
        break;

    case MMI_BARCODEREADER_APP_IVRSELL:
        menu_id = MENU_ID_BARCODEREADER_APP_TO_IVRSELL;
        title_id = STR_ID_BARCODEREADER_IVRSELL;
        if (g_barcodereader_cntx.highlight[g_barcodereader_cntx.current_highlight].highlight_type == 
            MMI_BARCODEREADER_HIGHLIGHT_TYPE_TEL)
        {
            mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
        }
        break;

    default:
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
        mmi_barcodereader_display_error_popup();
        return;
    }

    EntryNewScreen(SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION, NULL, mmi_barcodereader_forward_to_apps_operator1, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION);
    nItems = GetNumOfChild_Ext(menu_id);
    GetSequenceStringIds_Ext(menu_id, ItemList);
    /*GetSequenceImageIds_Ext(menu_id, ItemIcons);*/
    SetParentHandler(menu_id);
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    for (i = 0; i < nItems; i++)
    {
        ItemIcons[i] = IMG_GLOBAL_L1 + i;
    }

    ConstructHintsList(menu_id, PopUpList);
    
    ShowCategory52Screen(
        title_id,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_flash_status
 * DESCRIPTION
 *  check flash status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_check_flash_status(void)
{
#ifdef __MMI_BARCODEREADER_FLASH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.setting.flash == MMI_BARCODEREADER_SETTING_FLASH_OFF)
    {
        mdi_camera_flash_setting(FALSE);
    }
    else
    {
        mdi_camera_flash_setting(TRUE);
    }
#endif /* __BARCODEREADER_FLASH__ */ 
}




#ifndef __MMI_BARCODEREADER_OPERATOR1__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_ucs2char
 * DESCRIPTION
 *  Get Ascii or UCS2 character
 * PARAMETERS
 *  buf         [?]         
 *  a(?)        [IN]        Address of string
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
static S16 mmi_barcodereader_get_ucs2char(S8 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (*buf + ((*(buf + 1)) << 8));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_is_symbol_valid
 * DESCRIPTION
 *  Check if symbol is valid to insert use number
 * PARAMETERS
 *  c               [IN]        Current use number record length
 *  inBracket       [IN]        
 *  numIndex        [IN]        
 *  a(?)            [IN]        Input character
 *  b(?)            [IN]        Bracket waiting flag
 * RETURNS
 *  1: symbol is valid, 0: symbol is not valid
 *****************************************************************************/
static U8 mmi_barcodereader_is_symbol_valid(int c, U8 inBracket, U8 numIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_BARCODEREADER_IS_NUM(c))
    {
        return 1;
    }

    switch (c)
    {
        case '+':
            if (numIndex == 0)
            {
                status = 1;
            }
            break;
        case '(':
            status = 1;
            break;
        case ')':
            if (inBracket)
            {
                status = 1;
            }
            break;
        case 'p':
        case 'w':
        case '-':
            if (numIndex >= MMI_BARCODEREADER_USE_NUM_MIN_LENGTH)
            {
                status = 1;
            }
            break;
        default:
            status = 0;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_to_lower_case
 * DESCRIPTION
 *  Convert ascii upper case character to unicode lower case
 * PARAMETERS
 *  ptr         [IN]        
 *  a(?)        [IN]        Ptr   a pointer points to an ascii character
 * RETURNS
 *  a pointer points to an unicode character
 *****************************************************************************/
static S16 mmi_barcodereader_to_lower_case(PS8 ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 two_byte_A = 0x0041;
    S16 two_byte_Z = 0x005A;
    S16 unicode_lower;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*((S16*) ptr) >= two_byte_A && *((S16*) ptr) <= two_byte_Z)
    {
        unicode_lower = (S16) ('a' + (*ptr) - 'A');
    }
    else
    {
        unicode_lower = *((S16*) (ptr));
    }
    return unicode_lower;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_gsm_char
 * DESCRIPTION
 *  Check if it is a gsm character
 * PARAMETERS
 *  ch          [IN]        
 *  a(?)        [IN]        Char
 * RETURNS
 *  TRUE if it is a gsm character; FALSE otherwise
 *****************************************************************************/
static U8 mmi_barcodereader_check_gsm_char(PU16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ascii_min = 0x0000;
    U16 ascii_max = 0x007f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*ch >= ascii_min && *ch <= ascii_max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_parse_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_barcodereader_parse_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.app_list_idx = 0;
    g_barcodereader_cntx.app_list_idx_count = 0;
    g_barcodereader_cntx.selected_app_type = MMI_BARCODEREADER_NONE;
    result = MMI_FALSE;
    /* phase 1 : parse specific format */
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    result = mmi_barcodereader_parser_operator1();
#else
    mmi_barcodereader_parser_general();
#endif

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_unicode_to_ascii
 * DESCRIPTION
 *  Converts Unicode encode string to Ascii
 *  
 *  Caller has to ensure that pOutBuffer
 *  should be  large enough
 * PARAMETERS
 *  pOutBuffer      [?]     
 *  pInBuffer       [?]     
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_barcodereader_unicode_to_ascii(S8 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*pInBuffer == 0) && (*(pInBuffer + 1) == 0)))
    {
        
        *pOutBuffer = *(pInBuffer);

        /* check if 0x003b or not */
        if((*pOutBuffer) == ';' && (*(pInBuffer+1) != 0))
            *pOutBuffer = (char)0xee;

        pInBuffer += 2;
        pOutBuffer++;
        count++;
    }

    *pOutBuffer = 0;
    return count;
}


#ifdef __MMI_BARCODEREADER_OPERATOR1__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_parser_operator1
 * DESCRIPTION
 *  check if operator1 format
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_barcodereader_parser_operator1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length, total_length;
    MMI_BOOL is_operator1 = MMI_TRUE;
    S8*  tmp_p;
    U8   i;   


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*erase all the data*/
    memset(&g_barcodereader_cntx.app_content, 0, sizeof(mmi_barcodereader_app_content_struct));
    //mmi_ucs2_to_asc(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf);
    //mmi_barcodereader_unicode_to_ascii(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf);
    //mmi_ucs2cpy(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf);

    /**********************************************************************************************
     * The actual end of formatted_text_buf should be 0x0 0x0, not a single 0x0.
     * This is tmp solution to fix this problem
     **********************************************************************************************/
    /*do {
        g_barcodereader_cntx.formatted_text_buf_length = strlen(g_barcodereader_cntx.formatted_text_buf);
        if (g_barcodereader_cntx.formatted_text_buf[g_barcodereader_cntx.formatted_text_buf_length+1]==0)
            break;
        else
            g_barcodereader_cntx.formatted_text_buf[g_barcodereader_cntx.formatted_text_buf_length] = 0;
    }while(1);*/

    //PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---String length = %d ---*\n",
    //                   g_barcodereader_cntx.formatted_text_buf_length);

    /* check the last 2 symbol, should be ';' ';' */
    g_barcodereader_cntx.text_buf_length = mmi_ucs2strlen(g_barcodereader_cntx.text_buf);
    if (g_barcodereader_cntx.text_buf[(g_barcodereader_cntx.text_buf_length - 1) * 2] != ';' ||
        g_barcodereader_cntx.text_buf[(g_barcodereader_cntx.text_buf_length - 2) * 2] != ';')
    {
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---not !! end---*\n");
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
        
        return MMI_FALSE;
    }


    /*transfer to lower case*/
    mmi_ucs2lwr(g_barcodereader_cntx.text_buf);
    
    tmp_p = g_barcodereader_cntx.text_buf;
    /*skip file symbal*/
    i = 0;
    length = mmi_ucs2strlen(g_barcodereader_cntx.text_buf) * 2;
    while (*tmp_p != 0)
    {
        if (*tmp_p == MMI_BARCODEREADER_SP_ID)
        {
            //g_barcodereader_cntx.text_buf = tmp_p;
            break;
        }
        else if (*tmp_p == ':' || i >= (length - 1))
        {
            g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;

            return MMI_FALSE;
        }
        else
        {
            tmp_p++;
            i++;
        }
    }
  
    
    /* operator symbol */
    tmp_p += 2;
    /* version symbol */
    tmp_p += 2;    

    /* application id */
    mmi_barcodereader_ucs2_strtoken(tmp_p, ':' , &length);
    if (length == 0)
    {
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;

        return MMI_FALSE;
    }
    else
    {
        if (mmi_barcodereader_ucs2_check_continue_signal(tmp_p, length, '%') == MMI_TRUE)
        {
            g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
            return MMI_FALSE;
        }
//         while (mmi_barcodereader_ucs2_check_continue_signal(string, length, '%') == MMI_TRUE)
//         {
//             mmi_barcodereader_ucs2_strtoken(tmp_p + (length + 1) * 2, ':' , &length);
//         }
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---3rd symbol = %s ---*\n", tmp_p);
    }

    for(i = 0; i < MMI_BARCODEREADER_CURRENT_APP_COUNT; i++)
    {
        if(mmi_ucs2ncmp(tmp_p, (PS8)mmi_barcodereader_applist[i].name, length) == 0)
        {
            g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.app_list_idx] = 
                mmi_barcodereader_applist[i].value;
            break;
        }
    }

    if (i == MMI_BARCODEREADER_CURRENT_APP_COUNT)
    {
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
        return MMI_FALSE;
    }

    /*attribute id*/
    tmp_p += (length + 1) * 2;
    mmi_barcodereader_ucs2_strtoken(tmp_p, ':' , &length);
    while (length != 0 && is_operator1 == TRUE)
    {
        for(i = 0 ; i < MMI_BARCODEREADER_ATTRIBUTE_ALL; i++)
        {
            total_length = 0;
            if(mmi_ucs2ncmp(tmp_p, (PS8)mmi_barcodereader_attribute[i].name, length) == 0)
            {
                tmp_p += (length + 1) * 2;
                total_length = 0;            
                do
                {
                    mmi_barcodereader_ucs2_strtoken(tmp_p + total_length * 2, ';' , &length);
                    if (length == 0)
                    {
                        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
                        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;

                        return MMI_FALSE;
                    }
                    if(mmi_barcodereader_ucs2_check_continue_signal(tmp_p + total_length * 2, length, '%') == MMI_TRUE)
                    {
                        total_length += length;
                    }
                    else
                    {
                        total_length += length;
                        break;
                    }
                }while (1);

                g_barcodereader_cntx.app_content.ct_element[i].str_addr = tmp_p;
                g_barcodereader_cntx.app_content.ct_element[i].length = total_length;
                g_barcodereader_cntx.app_content.ct_attribute |= mmi_barcodereader_attribute[i].value;

                tmp_p += (total_length + 1) * 2;
                break;
            } 
        }
        if (i == MMI_BARCODEREADER_ATTRIBUTE_ALL)
        {
            g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
            
            return MMI_FALSE;
        }
        mmi_barcodereader_ucs2_strtoken(tmp_p, ':' , &length);
        if(length != 0)
        {
            ;
        }
        else if (*tmp_p == ';')
        {
            /*parse is over*/
            break;
        }
        else
        {
            g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;

            return MMI_FALSE;
        }
    }

    /*to judge it is operator1 attribu*/
    switch (g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.app_list_idx])
    {
        case MMI_BARCODEREADER_APP_VCARD:
            if ((g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_APP_VCARD_ATTR_MUST) == 
                MMI_BARCODEREADER_APP_VCARD_ATTR_MUST && 
                (g_barcodereader_cntx.app_content.ct_attribute & ~MMI_BARCODEREADER_APP_VCARD_ATTR_ALL) == 0)
            {
                is_operator1 = MMI_TRUE;
            }
            else
            {
                is_operator1 = MMI_FALSE;
            }
            break;

        ////TODO : lack of the encoding document to finish this
        case MMI_BARCODEREADER_APP_SMSSELL:
            if ((g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_APP_SMSSELL_ATTR_MUST) == 
                MMI_BARCODEREADER_APP_SMSSELL_ATTR_MUST && 
                (g_barcodereader_cntx.app_content.ct_attribute & ~MMI_BARCODEREADER_APP_SMSSELL_ATTR_ALL) == 0)
            {
                is_operator1 = MMI_TRUE;
            }
            else
            {
                is_operator1 = MMI_FALSE;
            }
            break;

        ////TODO : lack of the encoding document to finish this
        case MMI_BARCODEREADER_APP_WAPSELL:
            if ((g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_APP_WAPSELL_ATTR_MUST) == 
                MMI_BARCODEREADER_APP_WAPSELL_ATTR_MUST && 
                (g_barcodereader_cntx.app_content.ct_attribute & ~MMI_BARCODEREADER_APP_WAPSELL_ATTR_ALL) == 0)
            {
                is_operator1 = MMI_TRUE;
            }
            else
            {
                is_operator1 = MMI_FALSE;
            }
            break;
            
        ////TODO : lack of the encoding document to finish this
        case MMI_BARCODEREADER_APP_IVRSELL:
            if ((g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_APP_IVRSELL_ATTR_MUST) == 
                MMI_BARCODEREADER_APP_IVRSELL_ATTR_MUST && 
                (g_barcodereader_cntx.app_content.ct_attribute & ~MMI_BARCODEREADER_APP_IVRSELL_ATTR_ALL) == 0)
            {
                is_operator1 = MMI_TRUE;
            }
            else
            {
                is_operator1 = MMI_FALSE;
            }
            
            break;
            
        case MMI_BARCODEREADER_APP_DTXT:
            if ((g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_APP_DTXT_ATTR_MUST) == 
                MMI_BARCODEREADER_APP_DTXT_ATTR_MUST && 
                (g_barcodereader_cntx.app_content.ct_attribute & ~MMI_BARCODEREADER_APP_DTXT_ATTR_ALL) == 0)
            {
                is_operator1 = MMI_TRUE;
            }
            else
            {
                is_operator1 = MMI_FALSE;
            }
            break;
            
        case MMI_BARCODEREADER_APP_SMS:
            if ((g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_APP_SMS_ATTR_MUST) == 
                MMI_BARCODEREADER_APP_SMS_ATTR_MUST && 
                (g_barcodereader_cntx.app_content.ct_attribute & ~MMI_BARCODEREADER_APP_SMS_ATTR_ALL) == 0)
            {
                is_operator1 = MMI_TRUE;
            }
            else
            {
                is_operator1 = MMI_FALSE;
            }
            break;
            
        case MMI_BARCODEREADER_APP_EMAIL:
            if ((g_barcodereader_cntx.app_content.ct_attribute & MMI_BARCODEREADER_APP_EMAIL_ATTR_MUST) == 
                MMI_BARCODEREADER_APP_EMAIL_ATTR_MUST && 
                (g_barcodereader_cntx.app_content.ct_attribute & ~MMI_BARCODEREADER_APP_EMAIL_ATTR_ALL) == 0)
            {
                is_operator1 = MMI_TRUE;
            }
            else
            {
                is_operator1 = MMI_FALSE;
            }
            break;
            
        default:
            is_operator1 = MMI_FALSE;
            break;
    }

    if (is_operator1 == MMI_FALSE)
    {
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_ENCODING_ERROR;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
    }
    return is_operator1;

}
#endif

#ifndef __MMI_BARCODEREADER_OPERATOR1__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_parser_general
 * DESCRIPTION
 *  app menu item hilight hdlr
 * PARAMETERS
 *  void
 *  PS8(?)      [OUT]       P_out_text
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_parser_general(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S8 Pattern[MMI_BARCODEREADER_MAX_LEN_URL_PATTERN * ENCODING_LENGTH];
    kal_bool valid_http_prefix = KAL_TRUE;
    U16 idx, start_idx, current_idx, seek_idx;
    BOOL is_url = TRUE;
    BOOL is_number = FALSE;
    int digit_c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. translate to UCS2 String */
    //mmi_asc_to_ucs2(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf);
    mmi_ucs2cpy(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf);
    g_barcodereader_cntx.formatted_text_buf_length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

    /* 2. if Not, check if contain URL or Number or email */
    idx = 0;
    start_idx = idx;
    current_idx = idx;
    seek_idx = idx;

    while (mmi_ucs2cmp((S8*) & g_barcodereader_cntx.formatted_text_buf[idx], "\0"))
    {
        is_url = FALSE;
        for (i = 0; i < MMI_BARCODEREADER_MAX_NUM_URL_PATTERN && is_url == FALSE; i++)
        {
            /* PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser I, check url pattern %d: %s---*\n",i,mmi_barcode_urlPattern[i]); */
            mmi_asc_to_ucs2(Pattern, mmi_barcode_urlPattern[i]);
            /* search the pattern in the MsgTxt */

            if (mmi_ucs2ncmp
                ((S8*) & g_barcodereader_cntx.formatted_text_buf[idx], Pattern, mmi_barcode_urlPattern_length[i]) == 0)
            {
                is_url = TRUE;
            }
            /* select the minimum one, i.e. http://www.mtk.com "http://" will be selected instead of "www." */
            if (is_url == TRUE)
            {

                PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser I, url pattern matches: %s---*\n",
                                     mmi_barcode_urlPattern[i]);
                /* Determine if the http prefix is valid. For example, "http:##" is not valid. */
                if ((strncmp(mmi_barcode_urlPattern[i], "http", 4)) == 0)
                {
                    int j = 0;
                    S16 http_prefix[MMI_BARCODEREADER_MAX_LEN_URL_PATTERN];
                    S16 http_prefix_in_msg[MMI_BARCODEREADER_MAX_LEN_URL_PATTERN];
                    S16 tmp_c;
                    int k = 0;

                    for (; j < MMI_BARCODEREADER_MAX_NUM_VALID_HTTP_PREFIX; j++)
                    {
                        int http_prefix_len = strlen((S8*) mmi_barcode_urlValidHttpPrefix[j]);

                        mmi_asc_n_to_ucs2((S8*) http_prefix, mmi_barcode_urlValidHttpPrefix[j], http_prefix_len);
                        mmi_ucs2ncpy(
                            (S8*) http_prefix_in_msg,
                            (S8*) & g_barcodereader_cntx.formatted_text_buf[idx],
                            http_prefix_len);
                        http_prefix_in_msg[http_prefix_len] = 0;

                        for (; k < http_prefix_len; k++)
                        {
                            tmp_c = mmi_barcodereader_to_lower_case((PS8) & http_prefix_in_msg[k]);
                            http_prefix_in_msg[k] = tmp_c;
                        }
                        if (mmi_ucs2ncmp((S8*) http_prefix_in_msg, (S8*) http_prefix, http_prefix_len) == 0)
                        {
                            break;
                        }
                    }

                    if (j == MMI_BARCODEREADER_MAX_NUM_VALID_HTTP_PREFIX)
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser I, url pattern invalid ---*\n");
                        valid_http_prefix = KAL_FALSE;
                    }
                    else
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser I, url pattern valid ---*\n");
                    }
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser I, url pattern valid ---*\n");
                    valid_http_prefix = KAL_TRUE;
                }
                start_idx = current_idx = idx;

                /* get one url until 0x20, 0x0d, 0x0a, 0x00 */
                while (mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], " ", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], "\r", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], "\n", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], "\0", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], ",", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], "(", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], ")", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], ";", 1))
                {
                    /* must reserve two bytes for null terminator */
                    if (mmi_barcodereader_check_gsm_char((PU16) & g_barcodereader_cntx.formatted_text_buf[current_idx]))
                    {
                        /* skip extension character 0x1b */
                        current_idx += ENCODING_LENGTH;
                    }
                    else
                    {
                        break;
                    }
                }

                if (valid_http_prefix && g_barcodereader_cntx.app_list_idx < MMI_BARCODEREADER_APPLIACTION_LIST_NUM)
                {
                    /* PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser I, Add url to list---*\n"); */
                    g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].length =
                        (current_idx - start_idx) / ENCODING_LENGTH;
                    g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].str_addr =
                        (PS8) & g_barcodereader_cntx.formatted_text_buf[start_idx];
                    g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.app_list_idx] = MMI_BARCODEREADER_APP_URL;
                    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,
                                         "*---Parser I, app_list_idx = %d, length = %d, value = %d ---*\n",
                                         g_barcodereader_cntx.app_list_idx,
                                         g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].length,
                                         (int)(g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].str_addr));
                    g_barcodereader_cntx.app_list_idx++;
                }

                idx = current_idx;
            }

        }   /* end of checking pattern "http" "www." "wap." */

        valid_http_prefix = KAL_TRUE;

      /*********************************************************************
      * Check Number
      *********************************************************************/
        if (is_url == FALSE)
        {
            int pickNow = 0;
            U8 inBracket = 0;
            U8 non_digit_count = 0;
            U16 digit_count = 1;

            start_idx = idx;
            current_idx = idx;

            do
            {
                digit_c = mmi_barcodereader_get_ucs2char((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx]);

                if (mmi_barcodereader_is_symbol_valid(digit_c, inBracket, (U8) digit_count) &&
                    (digit_count - 1 < MMI_BARCODEREADER_MAX_DIGITS))
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser II, valid symbol: %d---*\n", digit_c);
                    if ((digit_c != '-') && (digit_c != '(') && (digit_c != ')'))
                    {
                        non_digit_count++;
                        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser II-1, picked, digit_count = %d ---*\n",
                                             digit_count);
                        digit_count++;
                    }

                    if (digit_c == '(')
                    {
                        inBracket++;
                    }
                    else if ((digit_c == ')') && inBracket)
                    {
                        inBracket--;
                    }
                }
                else
                {
                    /* Nth digit_c is an invalid symbol */
                    if (digit_count > 1 && ((current_idx / 2) < g_barcodereader_cntx.formatted_text_buf_length))
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser II,invlid symbol = %d, picknow ---*\n",
                                             digit_c);
                        current_idx -= ENCODING_LENGTH;
                        pickNow = 1;
                    }
                    else
                    {
                        if (non_digit_count > 0)
                        {
                            current_idx -= ENCODING_LENGTH;
                        }
                        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser II,invlid symbol = %d, not picknow ---*\n",
                                             digit_c);
                        is_number = FALSE;
                        break;
                    }
                }

                if ((current_idx / 2) + 1 >= g_barcodereader_cntx.formatted_text_buf_length)
                {
                    pickNow = 1;
                }

                if (pickNow)
                {

                    pickNow = 0;
                    if (( g_barcodereader_cntx.formatted_text_buf[current_idx] == 'w') || (g_barcodereader_cntx.formatted_text_buf[current_idx] == 'p'))
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser II-1, last symbol is p or w ---*\n");
                        current_idx -= ENCODING_LENGTH;
                    }
                    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser II-1, when picking, digit_count = %d ---*\n",
                                         digit_count);
                    if (digit_count >= 3 && g_barcodereader_cntx.app_list_idx < MMI_BARCODEREADER_APPLIACTION_LIST_NUM)
                    {
                        g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].length = (current_idx - start_idx + ENCODING_LENGTH) / 2;    /* + ENCODING_LENGTH; */
                        g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].str_addr =
                            (PS8) & g_barcodereader_cntx.formatted_text_buf[start_idx];
                        g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.app_list_idx] =
                            MMI_BARCODEREADER_APP_PHONENUMBER;
                        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,
                                             "*---Parser II,app_list_idx = %d, length = %d, value = %d ---*\n",
                                             g_barcodereader_cntx.app_list_idx,
                                             g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].length,
                                             (int)(g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].
                                                   str_addr));
                        g_barcodereader_cntx.app_list_idx++;
                        is_number = TRUE;
                        break;
                    }
                    else
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---Parser II, not a number ---*\n");
                        is_number = FALSE;
                        break;
                    }
                }
                else
                {
                    current_idx += ENCODING_LENGTH;
                }

            } while (1);

            idx = current_idx;

        }

      /*********************************************************************
      * Email address
      *********************************************************************/
        if (is_url == FALSE && is_number == FALSE)
        {

        }
        /* check next character */
        idx += ENCODING_LENGTH;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_highlight_app
 * DESCRIPTION
 *  app menu item hilight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    SetLeftSoftkeyFunction(mmi_barcodereader_enter_main_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_enter_main_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else
    SetLeftSoftkeyFunction(mmi_barcodereader_enter_preview_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_enter_preview_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_view_detail
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_highlight_to_qrv_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_barcodereader_enter_qrv_editor_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_enter_qrv_editor_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_qrv_editor_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_exit_qrv_editor_screen(void)
{
    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_qrv_editor_screen
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_enter_qrv_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 bufferSize;
    U8 *guiBuffer;
    static S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S8 fmgr_filepath[FMGR_PATH_BUFFER_SIZE];
    FMGR_FILE_INFO_STRUCT file_info;
    FS_HANDLE file_handle;
    U32 read_size;
    mmi_chset_enum file_encoding_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory from App-Based ASM */
    if (g_barcodereader_cntx.app_mem_pool==NULL)
    {
        g_barcodereader_cntx.app_mem_pool 
            = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BARCODEREADER, BR_APP_TOTAL_SIZE);

        if (g_barcodereader_cntx.app_mem_pool == NULL)
        {
            g_barcodereader_cntx.entry_app_callback = mmi_barcodereader_enter_qrv_editor_screen;
            
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_BARCODEREADER,
                IMG_ID_BARCODEREADER_APP_ICON,
                BR_APP_TOTAL_SIZE,
                mmi_barcodereader_app_mem_success_callback);
            return;
        }
    }

    /* create adm related resource */
    mmi_barcodereader_create_adm_resource();


    EntryNewScreen(SCR_ID_BARCODEREADER_EDITOR, mmi_barcodereader_exit_qrv_editor_screen, mmi_barcodereader_enter_qrv_editor_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_EDITOR);

    SetDelScrnIDCallbackHandler(SCR_ID_BARCODEREADER_EDITOR, mmi_barcodereader_del_scr_callback);    
    if (guiBuffer != NULL)
    {
        mmi_fmgr_kernel_get_path_name(fmgr_filepath);
        /*mmi_barcodereader_get_storage_file_path(buf_filepath);*/

        if (mmi_ucs2cmp(buf_filepath, fmgr_filepath) != 0)
        {
            DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
            GoBackHistory();
            return;
        }
    }
    else
    {
        g_barcodereader_cntx.selected_hilight_idx = 0;

        mmi_fmgr_kernel_get_path_name(fmgr_filepath);
        mmi_ucs2cpy((PS8)buf_filepath, (PS8)fmgr_filepath);

        /* allocate string buffer */
        g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);

        /* check if restore path is ready or not */
        mmi_barcodereader_check_restore_path();

        /*to fix an issue, that when view the file frome fmgr and then enter the barcode, will not have disc full notify*/
        g_barcodereader_cntx.is_storage_ready = TRUE;

#ifdef __MMI_DOWNLOAD_AGENT__
        /* download agent file */
        if (fmgr_is_da_file())
        {
            FS_HANDLE handle;
            /* Check if file exists or not */
            handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);        
            if (handle > FS_NO_ERROR)
            {
                FS_GetFileSize(handle,&file_info.file_size);
            	FS_Close(handle);
            }
            else
            {
                DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
                return;
            }
            mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
            mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);
            file_info.is_short = FALSE;
        }
        /* non download agent file */
        else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
        {
            index = mmi_fmgr_kernel_get_cur_idx();
            mmi_fmgr_kernel_get_file_info(index, &file_info);
        }

        if (file_info.file_size > BR_TEXT_BUFFER_SIZE)
        {
            #if defined(__MMI_HORIZONTAL_BARCODEREADER__)
                DisplayPopupRotated(
                    (PU8) GetString(STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE,
                    g_barcodereader_cntx.osd_rotate);
            #else /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
                DisplayPopup(
                    (PU8) GetString(STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            #endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
            DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
            return;

        }

        /* append the name to path */
        mmi_fmgr_kernel_get_path_name((PS8)g_barcodereader_cntx.storage_filepath);

#ifdef __MMI_DOWNLOAD_AGENT__
        /* download agent file */
        if (!fmgr_is_da_file())
#endif
        {
            mmi_ucs2cat((PS8)g_barcodereader_cntx.storage_filepath, file_info.file_name);
        }


        memset(g_barcodereader_cntx.text_buf,0,BR_TEXT_BUFFER_SIZE);
        memset(g_barcodereader_cntx.formatted_text_buf,0xff,BR_TEXT_BUFFER_SIZE);
        file_handle = FS_Open((U16*)g_barcodereader_cntx.storage_filepath, FS_READ_ONLY);
        FS_Read(file_handle, (void*)g_barcodereader_cntx.text_buf, file_info.file_size, (U32*) &read_size);
        FS_Close(file_handle);

        file_encoding_type = mmi_barcodereader_get_encoding_type(g_barcodereader_cntx.text_buf);

        if (file_encoding_type != MMI_CHSET_UCS2)
        {
            mmi_chset_convert(file_encoding_type,
                              MMI_CHSET_UCS2, 
                              (char*)g_barcodereader_cntx.text_buf, 
                              (char*)g_barcodereader_cntx.formatted_text_buf, 
                              BR_TEXT_BUFFER_SIZE);
            mmi_ucs2cpy(g_barcodereader_cntx.text_buf,g_barcodereader_cntx.formatted_text_buf);
            memset(g_barcodereader_cntx.formatted_text_buf,0xff,BR_TEXT_BUFFER_SIZE);
        }
        else
        {
            S32 i=2;
            /* if it has 0xff 0xfx as BOM, move the content 2 bytes forward */
            while (i<BR_TEXT_BUFFER_SIZE)
            {
                g_barcodereader_cntx.text_buf[i-2]=g_barcodereader_cntx.text_buf[i];
                i++;
            }
            g_barcodereader_cntx.text_buf[BR_TEXT_BUFFER_SIZE-1] = 0;
            g_barcodereader_cntx.text_buf[BR_TEXT_BUFFER_SIZE-2] = 0;

        }
        mmi_barcodereader_parse_text();
    }

    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

    g_barcodereader_cntx.app_list_idx_count = g_barcodereader_cntx.app_list_idx;
    MMI_multiline_inputbox.current_hilite_idx = 0;

    ShowCategory228Screen(
        STR_ID_BARCODEREADER_APP_NAME,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_barcodereader_cntx.formatted_text_buf,
        bufferSize,
        g_barcodereader_cntx.app_content.ct_element,
        (U16) g_barcodereader_cntx.app_list_idx,
        mmi_barcodereader_callback,
        guiBuffer);
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---total highlight count = %d---*\n",
                         g_barcodereader_cntx.app_list_idx);

#ifndef __MMI_BARCODEREADER_OPERATOR1__
    SetLeftSoftkeyFunction(mmi_barcodereader_forward_to_apps, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(mmi_barcodereader_forward_to_apps_operator1, KEY_EVENT_UP);
#endif
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_app_mem_success_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_app_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.app_mem_pool 
        = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BARCODEREADER, BR_APP_TOTAL_SIZE);
    ASSERT(g_barcodereader_cntx.app_mem_pool!=NULL); /* It should provide enough memory */

    ASSERT(g_barcodereader_cntx.entry_app_callback!=NULL);
    g_barcodereader_cntx.entry_app_callback();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_app_mem_stop_callback
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_app_mem_stop_callback(void)
{
    /* De-initialize Application */

    /* Free Memory */
     mmi_barcoderader_free_memory_and_destory_adm_resource();


    /*Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_BARCODEREADER,KAL_TRUE);
    
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    DeleteUptoScrID(SCR_ID_BARCODEREADER_PREVIEW);
    DeleteScreenIfPresent(SCR_ID_BARCODEREADER_PREVIEW);
#else
    DeleteUptoScrID(SCR_ID_BARCODEREADER_MAIN);
    DeleteScreenIfPresent(SCR_ID_BARCODEREADER_MAIN);
#endif

    DeleteUptoScrID(SCR_ID_BARCODEREADER_EDITOR);
    DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_create_adm_resource
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_create_adm_resource(void)
{

    U8 i = 0;
//#ifdef  __MTK_TARGET__
    /* Create MemoryPool */
    if (g_barcodereader_cntx.adm_pool_id == NULL)
    {
        g_barcodereader_cntx.adm_pool_id  = 
            kal_adm_create((void*)g_barcodereader_cntx.app_mem_pool, BR_APP_TOTAL_SIZE, NULL, KAL_FALSE);

        ASSERT(g_barcodereader_cntx.adm_pool_id != NULL);
    
        /* allocate memory from adm for each resource */

        g_barcodereader_cntx.text_buf = 
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id,BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.text_buf != NULL);
        
        g_barcodereader_cntx.formatted_text_buf = 
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id,BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.formatted_text_buf != NULL);

        g_barcodereader_cntx.working_buffer = 
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id,BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.working_buffer != NULL);    

        g_barcodereader_cntx.input_string = 
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id,BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.input_string != NULL);    

        g_barcodereader_cntx.input_string_tmp = 
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id,BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.input_string_tmp != NULL);    

        g_barcodereader_cntx.decode_text = 
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id,BR_VERSION_ONE_SLOT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.decode_text != NULL);    
        
        for (i = 0 ; i < BR_VERSION_NODE_COUNT ; i++)
        {
            g_barcodereader_cntx.text_slot[i] = 
                (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id,BR_VERSION_ONE_SLOT_BUFFER_SIZE);
            ASSERT(g_barcodereader_cntx.text_slot[i] != NULL);
        }    

    }
//#endif /* __MTK_TARGET__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_free_adm_resource
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_free_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    kal_status ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__ 
    if (g_barcodereader_cntx.adm_pool_id  )
    {
        for (;i<16;i++)
        {
            kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void *)g_barcodereader_cntx.text_slot[i]);
            g_barcodereader_cntx.text_slot[i] = NULL;
        }

        kal_adm_free(g_barcodereader_cntx.adm_pool_id,(void *) g_barcodereader_cntx.text_buf);
        g_barcodereader_cntx.text_buf = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id,(void *) g_barcodereader_cntx.formatted_text_buf);
        g_barcodereader_cntx.formatted_text_buf = NULL;
        
        kal_adm_free(g_barcodereader_cntx.adm_pool_id,(void *) g_barcodereader_cntx.working_buffer);
        g_barcodereader_cntx.working_buffer = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id,(void *) g_barcodereader_cntx.input_string);
        g_barcodereader_cntx.input_string = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id,(void *) g_barcodereader_cntx.input_string_tmp);
        g_barcodereader_cntx.input_string_tmp = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id,(void *) g_barcodereader_cntx.decode_text);
        g_barcodereader_cntx.decode_text = NULL;

        ret = kal_adm_delete(g_barcodereader_cntx.adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        g_barcodereader_cntx.adm_pool_id   = NULL;
    }
#endif /* __MTK_TARGET__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_del_scr_callback
 * DESCRIPTION
 *  delete screen id callback handler of BARCODEREADER applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_barcodereader_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free kal adm memory pool */
    mmi_barcodereader_free_adm_resource();

    /* free app-based memory */
    if (g_barcodereader_cntx.app_mem_pool != NULL)
    {
        applib_mem_ap_free((void*)g_barcodereader_cntx.app_mem_pool);
        g_barcodereader_cntx.app_mem_pool = NULL;    
    }

    /* check if it is in incall state, if yes, we need to reserve some incall screen */
    if (isInCall() == TRUE)
    {
        return MMI_FALSE;
    }

    /* if end_screen or marker_screen == 0, delete all barcodereader screen */
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    DeleteUptoScrID(SCR_ID_BARCODEREADER_PREVIEW);
#else
    DeleteUptoScrID(SCR_ID_BARCODEREADER_MAIN);
#endif
    DeleteUptoScrID(SCR_ID_BARCODEREADER_EDITOR);
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_init_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* initialize application memory pool */
    applib_mem_ap_register(APPLIB_MEM_AP_ID_BARCODEREADER,STR_ID_BARCODEREADER_APP_NAME 
                ,IMG_ID_BARCODEREADER_APP_ICON ,mmi_barcodereader_app_mem_stop_callback);
    g_barcodereader_cntx.adm_pool_id  = NULL;
    g_barcodereader_cntx.app_mem_pool = NULL;
    
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    g_barcodereader_cntx.is_commend = MMI_FALSE;
#endif

    /* initialize Append Structure QR Code */
    g_barcodereader_cntx.is_append_qrcode = FALSE;
    g_barcodereader_cntx.nsymbol = 0;
    g_barcodereader_cntx.symbol_count = 0;
    g_barcodereader_cntx.paritydata = 0;
    g_barcodereader_cntx.encoding = 0;
    g_barcodereader_cntx.symbol_masks = 0;

    mmi_barcodereader_load_setting();

    SetHiliteHandler(MENU_ID_BARCODEREADER_APP, mmi_barcodereader_highlight_app);
    SetHiliteHandler(MENU_ID_BARCODEREADER_TO_QRV_EDITOR, mmi_barcodereader_highlight_to_qrv_editor);

#ifndef __MMI_BARCODEREADER_OPERATOR1__
#ifdef __MMI_BARCODEREADER_STORAGE__
    SetHiliteHandler(MENU_ID_BARCODEREADER_OPTION_SETTINGS, mmi_barcodereader_highlight_settings);
    SetHiliteHandler(MENU_ID_BARCODEREADER_OPTION_STORAGE, mmi_barcodereader_highlight_storage);
#endif
#endif

    g_barcodereader_cntx.app_state = MMI_BARCODEREADER_STATE_EXIT;
    g_barcodereader_cntx.app_prev_state = MMI_BARCODEREADER_STATE_EXIT;
    g_barcodereader_cntx.app_next_state = MMI_BARCODEREADER_STATE_EXIT;

    g_barcodereader_cntx.is_storage_path_changed = FALSE;
    g_barcodereader_cntx.is_setting_loaded = FALSE;
    g_barcodereader_cntx.is_mainlcd_resource = FALSE;
    g_barcodereader_cntx.is_sublcd_display = FALSE;
    g_barcodereader_cntx.is_cat65_show = FALSE;
    g_barcodereader_cntx.is_manual_autofocus = FALSE;
    g_barcodereader_cntx.is_storage_ready = TRUE;

    g_barcodereader_cntx.base_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    g_barcodereader_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_barcodereader_cntx.sublcd_base_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_barcodereader_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    g_barcodereader_cntx.osd_rotate = MMI_BARCODEREADER_OSD_ROTATE_0;
    g_barcodereader_cntx.base_UI_device_width = LCD_HEIGHT;
    g_barcodereader_cntx.base_UI_device_height = LCD_WIDTH;
#else /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
    g_barcodereader_cntx.osd_rotate = MMI_BARCODEREADER_OSD_ROTATE_0;
    g_barcodereader_cntx.base_UI_device_width = LCD_WIDTH;
    g_barcodereader_cntx.base_UI_device_height = LCD_HEIGHT;
#endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

    g_barcodereader_cntx.active_barcodereader_osd_ptr = &g_barcodereader_osd_cntx;

    g_barcodereader_cntx.osd_UI_device_width = LCD_WIDTH;
    g_barcodereader_cntx.osd_UI_device_height = LCD_HEIGHT;


#define INIT_OSD_TOUCH_ICON(a,A)                                                                                    \
   do {                                                                                                                \
      if(g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.is_show)                                             \
      {                                                                                                                \
         gdi_image_get_dimension_id((U16)(IMG_ID_BARCODEREADER_OSD_##A##_START+1),                                     \
                                    &g_barcodereader_cntx.touch_##a##.width,                                           \
                                    &g_barcodereader_cntx.touch_##a##.height);                                         \
         g_barcodereader_cntx.touch_##a##.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.offset_x;\
         g_barcodereader_cntx.touch_##a##.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.offset_y;\
         g_barcodereader_cntx.touch_##a##.is_press = FALSE;                                                            \
      }                                                                                                                \
   } while(0);

    /* draw icon */
    INIT_OSD_TOUCH_ICON(flash, FLASH);
    INIT_OSD_TOUCH_ICON(af_mode, FOCUS_MODE);
    INIT_OSD_TOUCH_ICON(storage, STORAGE);

#ifndef __MMI_BARCODEREADER_OPERATOR1__
    /* ev inc */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_EV_INC),
        &g_barcodereader_cntx.touch_ev_inc.width,
        &g_barcodereader_cntx.touch_ev_inc.height);

    g_barcodereader_cntx.touch_ev_inc.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_x;
    g_barcodereader_cntx.touch_ev_inc.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_y;
    g_barcodereader_cntx.touch_ev_inc.is_press = FALSE;

    /* ev dec */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_EV_DEC),
        &g_barcodereader_cntx.touch_ev_dec.width,
        &g_barcodereader_cntx.touch_ev_dec.height);

    g_barcodereader_cntx.touch_ev_dec.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_x;
    g_barcodereader_cntx.touch_ev_dec.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_y;
    g_barcodereader_cntx.touch_ev_dec.is_press = FALSE;

    /* mf inc */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_MF_INC),
        &g_barcodereader_cntx.touch_mf_inc.width,
        &g_barcodereader_cntx.touch_mf_inc.height);

    g_barcodereader_cntx.touch_mf_inc.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_x;
    g_barcodereader_cntx.touch_mf_inc.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_y;
    g_barcodereader_cntx.touch_mf_inc.is_press = FALSE;

    /* mf dec */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_MF_DEC),
        &g_barcodereader_cntx.touch_mf_dec.width,
        &g_barcodereader_cntx.touch_mf_dec.height);

    g_barcodereader_cntx.touch_mf_dec.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_x;
    g_barcodereader_cntx.touch_mf_dec.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_y;
    g_barcodereader_cntx.touch_mf_dec.is_press = FALSE;
#endif

    /* capture */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_CAPTURE),
        &g_barcodereader_cntx.touch_capture.width,
        &g_barcodereader_cntx.touch_capture.height);

    g_barcodereader_cntx.touch_capture.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_x;
    g_barcodereader_cntx.touch_capture.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_y;
    g_barcodereader_cntx.touch_capture.is_press = FALSE;

    /* initialize forword menu highlight handler */
    mmi_barcodereader_init_forward_menu();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_option_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for camera setting menu
 * PARAMETERS
 *  index       [IN]        Highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_option_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_barcodereader_option_setting_set_value);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_option_setting_set_value
 * DESCRIPTION
 *  set camera setting values
 * PARAMETERS
 *  void
 *  idx(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_option_setting_set_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_barcodereader_cntx.setting.flash = g_barcodereader_menu_cntx.flash_selected;
    g_barcodereader_cntx.setting.ev = g_barcodereader_menu_cntx.ev_selected;
    g_barcodereader_cntx.setting.af_mode = g_barcodereader_menu_cntx.af_mode_selected;
    g_barcodereader_cntx.setting.banding = g_barcodereader_menu_cntx.banding_selected;
    mmi_barcodereader_store_setting();

    #if defined(__CAMERA_OSD_HORIZONTAL__)
        DisplayPopupRotated(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            ST_NOTIFYDURATION,
            SUCCESS_TONE,
            g_barcodereader_cntx.osd_rotate);
    #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_setting_screen
 * DESCRIPTION
 *  option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;
    S32 i;

    
    MMI_ID_TYPE item_icons[MMI_BARCODEREADER_SETTING_ITEM_COUNT * 2] = 
    {

    #ifdef __MMI_BARCODEREADER_FLASH__
        IMG_ID_BARCODEREADER_MENUICON_FLASH,
        0,
    #endif /* __BARCODEREADER_FLASH__ */ 

        IMG_ID_BARCODEREADER_MENUICON_EV,
        0,

    #ifdef __MMI_BARCODEREADER_FOCUS_MODE__
        IMG_ID_BARCODEREADER_MENUICON_FOCUS_MODE,
        0,
    #endif /* __BARCODEREADER_FOCUS_MODE__ */ 

    #ifdef __MMI_BARCODEREADER_BANDING__
        IMG_ID_BARCODEREADER_MENUICON_BANDING,
        0,
    #endif /* __BARCODEREADER_BANDING__ */

    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_BARCODEREADER_SETTING,
        mmi_barcodereader_exit_setting_screen,
        NULL,
        NULL);


    /* allocate storage path buffer */
    g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_barcodereader_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    mmi_barcodereader_get_storage_file_path((PS8)g_barcodereader_cntx.storage_filepath);

#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

    InitializeCategory57Screen();

    g_barcodereader_menu_cntx.flash_selected = g_barcodereader_cntx.setting.flash;
    g_barcodereader_menu_cntx.ev_selected = g_barcodereader_cntx.setting.ev;
    g_barcodereader_menu_cntx.af_mode_selected = g_barcodereader_cntx.setting.af_mode;
    g_barcodereader_menu_cntx.storage_selected = g_barcodereader_cntx.setting.storage;
    g_barcodereader_menu_cntx.banding_selected = g_barcodereader_cntx.setting.banding;
   /******************************************************************
   *  MACRO to create inline selection. 
   ******************************************************************/
#define MMI_BARCODEREADER_SETTING_INLINE_SELECT(a, A)                                                                     \
   {                                                                                                                     \
      for(i = 0 ; i < MMI_BARCODEREADER_SETTING_##A##_COUNT; i++)                                                            \
      {                                                                                                                  \
         g_barcodereader_menu_cntx.##a##_str[i] = (UI_string_type)GetString((U16)(STR_ID_BARCODEREADER_##A##_START+i+1));\
      }                                                                                                                  \
      SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8)GetString((U16)(STR_ID_BARCODEREADER_##A)));          \
      SetInlineItemActivation(&wgui_inline_items[item_offset],                                                           \
                              INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,                                                    \
                              0 );                                                                                       \
      SetInlineItemSelect( &wgui_inline_items[item_offset++],                                                            \
                           MMI_BARCODEREADER_SETTING_##A##_COUNT,                                                            \
                           (U8**)g_barcodereader_menu_cntx.##a##_str,                                                    \
                           &g_barcodereader_menu_cntx.##a##_selected);                                                   \
   }

   /****************************************************************************
   *  Create inline selection                                                               
   *****************************************************************************/
#ifdef __MMI_BARCODEREADER_FLASH__
    MMI_BARCODEREADER_SETTING_INLINE_SELECT(flash, FLASH);
#endif 

    MMI_BARCODEREADER_SETTING_INLINE_SELECT(ev, EV);

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    MMI_BARCODEREADER_SETTING_INLINE_SELECT(af_mode, FOCUS_MODE);
#endif 


#ifdef __MMI_BARCODEREADER_BANDING__
    MMI_BARCODEREADER_SETTING_INLINE_SELECT(banding, BANDING);
#endif 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_BARCODEREADER_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_BARCODEREADER_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_barcodereader_option_setting_highlight_hdlr);

    /* show category */
    ShowCategory57Screen(
        STR_ID_BARCODEREADER_SETTING,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_barcodereader_option_setting_set_value);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_setting_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_BARCODEREADER_SETTING;
    currHistory.entryFuncPtr = mmi_barcodereader_enter_setting_screen;
    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);

    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_append_qrcode_continue
 * DESCRIPTION
 *  exit help screen, and still in append_barcode mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_append_qrcode_continue(void)
{
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_append_qrcode_reset
 * DESCRIPTION
 *  exit help screen, and reset append_barcode mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_append_qrcode_reset(void)
{
    g_barcodereader_cntx.is_append_qrcode = FALSE;
    g_barcodereader_cntx.symbol_masks = 0;
    g_barcodereader_cntx.symbol_count = 1;
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_tip_screen
 * DESCRIPTION
 *  this screen is for user to decoded continue to decode append
 *  barcode or to reset application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_tip_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buffer;
    S32 bufferSize;
    U8 *guiBuffer;
    U16 str_id;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BARCODEREADER_TIP, mmi_barcodereader_exit_tip_screen, mmi_barcodereader_enter_tip_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_TIP);

    switch (g_barcodereader_cntx.help_str_enum)
    {
        case MMI_BARCODEREADER_HELP_DECODE_NEXT:
            str_id = STR_ID_BARCODEREADER_HELP_APPEND_BARCODE;
            break;
        case MMI_BARCODEREADER_HELP_WRONG_SERIES:
            str_id = STR_ID_BARCODEREADER_HELP_WRONG_SERIES;
            break;
        case MMI_BARCODEREADER_HELP_DUPLICATED_CODE:
            str_id = STR_ID_BARCODEREADER_HELP_DUPLICATED_CODE;
            break;
        default:
            str_id = STR_ID_BARCODEREADER_HELP_APPEND_BARCODE;            
            break;
    }
    buffer = GetString(str_id);
    mmi_ucs2cpy(g_barcodereader_cntx.input_string_tmp, buffer); 

    if (g_barcodereader_cntx.help_str_enum!=MMI_BARCODEREADER_HELP_WRONG_SERIES)
    {
        sprintf((PS8)g_barcodereader_cntx.working_buffer, "#%d, ", g_barcodereader_cntx.symbolid);         
        mmi_asc_to_ucs2(g_barcodereader_cntx.input_string, g_barcodereader_cntx.working_buffer);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,g_barcodereader_cntx.input_string);
    }

    buffer = GetString(STR_ID_BARCODEREADER_HELP_DECODE_NEXT);
    mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp,buffer);

    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.input_string_tmp);
    
    ShowCategory74Screen(
        STR_ID_BARCODEREADER_ORDER_ATTENTION,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_ID_BARCODEREADER_RSK_CONTINUE,
        IMG_GLOBAL_OK,
        STR_ID_BARCODEREADER_LSK_RESET,
        IMG_GLOBAL_BACK,
        (PU8)g_barcodereader_cntx.input_string_tmp,
        bufferSize,
        NULL);

    SetKeyHandler(mmi_barcodereader_append_qrcode_reset, KEY_RSK, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_barcodereader_append_qrcode_reset, KEY_EVENT_UP);

    SetKeyHandler(mmi_barcodereader_append_qrcode_continue, KEY_LSK, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_append_qrcode_continue, KEY_EVENT_UP);

    g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_tip_screen
 * DESCRIPTION
 *  exit screen function of mmi_barcodereader_enter_tip_screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_tip_screen(void)
{
    ClearKeyEvents();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_decode_result_hdlr
 * DESCRIPTION
 *  no block burst shot capture result handler, symbolid start from 1, nsymbol means how many symbol
 * PARAMETERS
 *  ret                 [IN]        Decode result ( Succeed or Fail )
 *  decode_times(?)     [IN]        How many time have we decoded.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_decode_result_hdlr(mdi_result ret, U8 encoding, U8 nsymbol, U8 symbolid, U8 paritydata, mdi_camera_barcode_type_enum barcode_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* working_src;
    U8* working_dest;
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    MMI_BOOL result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* decode successfully */
    if (ret == 0)
    {
#ifdef __MMI_BARCODEREADER_OPERATOR1__
        g_barcodereader_cntx.b_stop_decode = MMI_FALSE;
#endif
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---STRING CONTENT = %s---*\n", g_barcodereader_cntx.decode_text);
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---STRING LENGTH = %d---*\n",mmi_ucs2strlen(g_barcodereader_cntx.decode_text));
        if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE)
        {
            /* if application is in APPEND_BARCODE state currently  */
            if (TRUE == g_barcodereader_cntx.is_append_qrcode)      /* node struct*/
            {
                g_barcodereader_cntx.symbolid = symbolid;

                /* if the new decoded text is correct and undecoded before */
                if ((paritydata == g_barcodereader_cntx.paritydata)
                    && (nsymbol == g_barcodereader_cntx.nsymbol)
                    && (0 == ((1<<(symbolid-1))&g_barcodereader_cntx.symbol_masks)))
                {
                    g_barcodereader_cntx.symbol_count++;
                    g_barcodereader_cntx.symbol_masks |= (1<<(symbolid-1));
    
                    /* copy decode string to text slot */
                    working_src = (U8*)g_barcodereader_cntx.decode_text;
                    memset(g_barcodereader_cntx.text_slot[symbolid-1],0xff,BR_VERSION_ONE_SLOT_BUFFER_SIZE); 
                    working_dest = (U8*)g_barcodereader_cntx.text_slot[symbolid-1];
                    while(*working_src!=0)
                    {
                        *working_dest++=*working_src;
                        working_src++;
                    }
                    *working_dest=0;

                    if (encoding < g_barcodereader_cntx.encoding)
                    {
                        g_barcodereader_cntx.encoding = encoding;
                    }

                    /* if all append barcodes are decoded */
                    if (g_barcodereader_cntx.symbol_count == nsymbol)
                    {
                        U8 count ;
                        working_dest = (U8*) g_barcodereader_cntx.formatted_text_buf;
                        memset(g_barcodereader_cntx.formatted_text_buf,0xff,BR_TEXT_BUFFER_SIZE);            
                        /* conbime slot to text_buffer */
                        for (count=0;count<nsymbol;count++)
                        {
                            working_src = (U8*)g_barcodereader_cntx.text_slot[count];
                            while(*working_src!=0)
                            {
                                *working_dest++=*working_src;
                                working_src++;
                            }
                        }
                        *working_dest=0;

                        if (0x01 == (encoding & 0x01))
                        {
                            mmi_chset_convert(
                                MMI_CHSET_GB2312,
                                MMI_CHSET_UCS2, 
                                (char*)g_barcodereader_cntx.formatted_text_buf, 
                                (char*)g_barcodereader_cntx.text_buf, 
                                BR_TEXT_BUFFER_SIZE );
                        }
                        else if (0x04 == (encoding & 0x04) || 0x02 == (encoding & 0x02))
                        {
                            mmi_chset_convert(
                                MMI_CHSET_UTF8,
                                MMI_CHSET_UCS2, 
                                (char*)g_barcodereader_cntx.formatted_text_buf, 
                                (char*)g_barcodereader_cntx.text_buf, 
                                BR_TEXT_BUFFER_SIZE);
                        }
                        else
                        {
                            mmi_chset_convert(
                                MMI_CHSET_GB2312,
                                MMI_CHSET_UCS2, 
                                (char*)g_barcodereader_cntx.formatted_text_buf, 
                                (char*)g_barcodereader_cntx.text_buf, 
                                BR_TEXT_BUFFER_SIZE );
                        }

                        memset(g_barcodereader_cntx.formatted_text_buf,0xff,BR_TEXT_BUFFER_SIZE);  
                        g_barcodereader_cntx.is_append_qrcode = FALSE;
                        g_barcodereader_cntx.symbol_masks = 0;
                        g_barcodereader_cntx.symbol_count = 1;
#ifdef __MMI_BARCODEREADER_OPERATOR1__
                        result = mmi_barcodereader_parse_text();
#else
                        mmi_barcodereader_parse_text();
#endif
                         
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                        mmi_barcodereader_entry_editor_screen();                        
#else
                        if (result == MMI_TRUE)
                        {
                            mmi_barcodereader_enter_app_preview_screen();
                        }
                        else
                        {
                            mmi_barcodereader_display_error_popup();
                        }
#endif
                    }
                    else
                    {
                        /* shows 3: please decode the next one barcode */
                        g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_DECODE_NEXT;
                        mmi_barcodereader_enter_tip_screen();
                    }
                }
                else if ((paritydata != g_barcodereader_cntx.paritydata)    /* node struct*/
                        || (nsymbol != g_barcodereader_cntx.nsymbol))
                {
                    /* if the decoded barcode is not correct */
                    /* shows 1: this barcode is not the same series */
                    g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_WRONG_SERIES;                
                    mmi_barcodereader_enter_tip_screen();
                }
                else if (0 != ((1<<(symbolid-1))&g_barcodereader_cntx.symbol_masks))
                {
                    /* if the decoded barcode was decoded before */
                    /* shows 2: this barcode was decoded before */
                    g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_DUPLICATED_CODE;
                    mmi_barcodereader_enter_tip_screen();
                }
            }
            else if (FALSE == g_barcodereader_cntx.is_append_qrcode)
            {

                if (nsymbol == 1)
                {              
                    if (0x01 == (encoding  & 0x01))
                    {
                        mmi_chset_convert(
                            MMI_CHSET_GB2312,
                            MMI_CHSET_UCS2, 
                            (char*)g_barcodereader_cntx.decode_text, 
                            (char*)g_barcodereader_cntx.formatted_text_buf, 
                            BR_VERSION_ONE_SLOT_BUFFER_SIZE );
                    }
                    else if (0x04 == (encoding & 0x04)||0x02 == (encoding & 0x02))
                    {
                        mmi_chset_convert(
                            MMI_CHSET_UTF8,
                            MMI_CHSET_UCS2, 
                            (char*)g_barcodereader_cntx.decode_text, 
                            (char*)g_barcodereader_cntx.formatted_text_buf, 
                            BR_VERSION_ONE_SLOT_BUFFER_SIZE );
                    }
                    else    /* default encoding type is gb2312*/
                    {
                        mmi_chset_convert(
                            MMI_CHSET_GB2312,
                            MMI_CHSET_UCS2, 
                            (char*)g_barcodereader_cntx.decode_text, 
                            (char*)g_barcodereader_cntx.formatted_text_buf, 
                            BR_VERSION_ONE_SLOT_BUFFER_SIZE );
                    }

                    mmi_ucs2cpy(g_barcodereader_cntx.text_buf,g_barcodereader_cntx.formatted_text_buf);
                    memset(g_barcodereader_cntx.formatted_text_buf,0xff,BR_TEXT_BUFFER_SIZE);            
                    
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                    mmi_barcodereader_parse_text();
                    mmi_barcodereader_entry_editor_screen();
#else
                    result = mmi_barcodereader_parse_text();
                    if (result == MMI_TRUE)
                    {
                        mmi_barcodereader_enter_app_preview_screen();
                    }
                    else
                    {
                        mmi_barcodereader_display_error_popup();
                    }
#endif
                }
                else if (nsymbol > 1)
                {
                    g_barcodereader_cntx.is_append_qrcode = TRUE;
                    g_barcodereader_cntx.paritydata = paritydata;
                    g_barcodereader_cntx.nsymbol = nsymbol;
                    g_barcodereader_cntx.symbolid = symbolid;
                    g_barcodereader_cntx.symbol_masks = 0;
                    g_barcodereader_cntx.symbol_count = 1;
                    g_barcodereader_cntx.symbol_masks |= (1<<(symbolid-1));
                    g_barcodereader_cntx.encoding = encoding;

                    /* copy decode string to text slot */
                    working_src = (U8*)g_barcodereader_cntx.decode_text;
                    memset(g_barcodereader_cntx.text_slot[symbolid-1],0xff,BR_VERSION_ONE_SLOT_BUFFER_SIZE); 
                    working_dest = (U8*)g_barcodereader_cntx.text_slot[symbolid-1];
                    while(*working_src!=0)
                    {
                        *working_dest++=*working_src;
                        working_src++;
                    }
                    *working_dest=0;    

                    /* shows 3: please decode the next one barcode */
                    g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_DECODE_NEXT;
                    mmi_barcodereader_enter_tip_screen();
                }
                else 
                    ASSERT(0);
            }

        }
        else if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
        {
            mmi_barcodereader_preview_start();
        }
    }
    else
    {
        g_barcodereader_cntx.last_error.error_result = ret;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
        /* currently, it should not go here */
        mmi_barcodereader_display_error_popup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_restore_setting
 * DESCRIPTION
 *  restore camera setting to default value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.setting.flash = MMI_BARCODEREADER_DEFAULT_SETTING_FLASH;
    g_barcodereader_cntx.setting.banding = MMI_BARCODEREADER_DEFAULT_SETTING_BANDING;
    g_barcodereader_cntx.setting.ev = MMI_BARCODEREADER_DEFAULT_SETTING_EV;
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
    g_barcodereader_cntx.setting.af_mode = 0;
#endif 
#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        g_barcodereader_cntx.osd_rotate = MMI_BARCODEREADER_OSD_ROTATE_0;
        g_barcodereader_cntx.previous_osd_rotate = MMI_BARCODEREADER_OSD_ROTATE_RESET;
    }
#endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

    g_barcodereader_cntx.setting.storage = (U16) MMI_PUBLIC_DRV;
    /* mmi_camera_preview_update_capture_size(); */

    mmi_barcodereader_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_load_setting
 * DESCRIPTION
 *  load camera settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded from NVRAM, it is already exist in memory, do not loaded again */
    if (!g_barcodereader_cntx.is_setting_loaded)
    {
        ReadRecord(
            NVRAM_EF_BARCODEREADER_SETTING_LID,
            1,
            (void*)&g_barcodereader_cntx.setting,
            NVRAM_EF_BARCODEREADER_SETTING_SIZE,
            &error);

        /* first time init */
        if (g_barcodereader_cntx.setting.ev == 0xffff)
        {
            mmi_barcodereader_restore_setting();
        }

        /* init preview size based on LCD size */
        // it seems don't need 20060417
        // mmi_camera_preview_update_capture_size();

        g_barcodereader_cntx.is_setting_loaded = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_store_setting
 * DESCRIPTION
 *  store camera settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_BARCODEREADER_SETTING_LID,
        1,
        (void*)&g_barcodereader_cntx.setting,
        NVRAM_EF_BARCODEREADER_SETTING_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_bolder_rect
 * DESCRIPTION
 *  draw rect with bolder
 * PARAMETERS
 *  x1                  [IN]        Start x
 *  y1                  [IN]        Start y
 *  x2                  [IN]        End x
 *  y2                  [IN]        End y
 *  bolder_width        [IN]        Width of bolder
 *  frame_color         [IN]        
 *  gdi_color(?)        [IN]        Color of bolder
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_bolder_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 bolder_width, gdi_color frame_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_rect(x1 - bolder_width, y1 - bolder_width, x2 + bolder_width, y2 + bolder_width, frame_color);
    gdi_draw_rect(x1 + bolder_width, y1 + bolder_width, x2 - bolder_width, y2 - bolder_width, frame_color);
}

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_focus_process
 * DESCRIPTION
 *  draw focus related OSD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_focus_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U16 image_id = 0; */
    U16 af_x = 0;
    U16 af_y = 0;
    U16 af_width = 0;
    gdi_color af_color = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_barcodereader_cntx.af_state)
    {
        case MMI_BARCODEREADER_AF_CALCULATE:

            if (g_barcodereader_cntx.is_manual_autofocus == FALSE)
            {
                if (g_barcodereader_cntx.af_animation_process == MMI_BARCODEREADER_AF_ANIMATION_END)
                {
                    g_barcodereader_cntx.af_animation_process = MMI_BARCODEREADER_AF_ANIMATION_STEP1;
                }

                switch (g_barcodereader_cntx.af_animation_process)
                {
                    case MMI_BARCODEREADER_AF_ANIMATION_STEP1:
                        af_width = MMI_BARCODEREADER_AF_LARGE_WIDTH;
                        af_color = GDI_COLOR_WHITE;
                        break;
                    case MMI_BARCODEREADER_AF_ANIMATION_STEP2:
                        af_color = GDI_COLOR_GRAY;
                        af_width = MMI_BARCODEREADER_AF_NORMAL_WIDTH;
                        break;
                    case MMI_BARCODEREADER_AF_ANIMATION_STEP3:
                        af_color = GDI_COLOR_BLACK;
                        af_width = MMI_BARCODEREADER_AF_SMALL_WIDTH;
                        break;
                }

                af_x = g_barcodereader_cntx.af_zone0_x - af_width / 2;
                af_y = g_barcodereader_cntx.af_zone0_y - af_width / 2;
                mmi_barcodereader_draw_bolder_rect(
                    af_x,
                    af_y,
                    af_x + af_width - 1,
                    af_y + af_width - 1,
                    1,
                    GDI_COLOR_WHITE);

                g_barcodereader_cntx.af_animation_process++;
            }

            break;
        case MMI_BARCODEREADER_AF_SUCCEED:
            af_width = MMI_BARCODEREADER_AF_SMALL_WIDTH;

            af_x = g_barcodereader_cntx.af_zone0_x - af_width / 2;
            af_y = g_barcodereader_cntx.af_zone0_y - af_width / 2;
            mmi_barcodereader_draw_bolder_rect(
                af_x,
                af_y,
                af_x + af_width - 1,
                af_y + af_width - 1,
                1,
                GDI_COLOR_GREEN);

            break;
        case MMI_BARCODEREADER_AF_FAIL:
            af_width = MMI_BARCODEREADER_AF_SMALL_WIDTH;

            af_x = g_barcodereader_cntx.af_zone0_x - af_width / 2;
            af_y = g_barcodereader_cntx.af_zone0_y - af_width / 2;
            mmi_barcodereader_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, GDI_COLOR_RED);

            break;
        case MMI_BARCODEREADER_AF_IDLE:
        case MMI_BARCODEREADER_AF_ONFOCUS:
            break;

    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_sublcd_screen
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_barcodereader_enter_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_barcodereader_exit_sublcd_screen);

    g_barcodereader_cntx.is_sublcd_display = TRUE;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_sublcd_screen
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_barcodereader_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode sub_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_sublcd_display = FALSE;

    sub_history.entryFuncPtr = mmi_barcodereader_enter_sublcd_screen;
    AddSubLCDHistory(&sub_history);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_sublcd_draw_icon
 * DESCRIPTION
 *  draw a sublcd icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_barcodereader_sublcd_draw_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 lcd_width;
    S32 lcd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_BARCODEREADER_PREVIEW_SUBLCD_ICON, &image_width, &image_height);
    gdi_image_draw_id(
        (lcd_width - image_width) >> 1,
        (lcd_height - image_height) >> 1,
        IMG_ID_BARCODEREADER_PREVIEW_SUBLCD_ICON);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_stop
 * DESCRIPTION
 *  stop previewing of main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop previewing */
    mdi_camera_barcodereader_preview_stop();

    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    mmi_barcodereader_preview_clear_background();
#endif 
}


/*****************************************************************************
 * FUNCTION
*  mmi_barcodereader_entry_option_menu_screen
* DESCRIPTION
*  option menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_barcodereader_entry_option_menu_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BARCODEREADER_STORAGE__
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BARCODEREADER_STORAGE__
    EntryNewScreen(SCR_ID_BARCODEREADER_OPTION, NULL, mmi_barcodereader_entry_option_menu_screen, NULL);
    
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_OPTION);
    nItems = GetNumOfChild_Ext(MENU_ID_BARCODEREADER_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_BARCODEREADER_OPTION, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_BARCODEREADER_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_BARCODEREADER_OPTION);
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }
    
    ConstructHintsList(MENU_ID_BARCODEREADER_OPTION, PopUpList);
    
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#else
    mmi_barcodereader_enter_setting_screen();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_preview_screen
 * DESCRIPTION
 *  exit barcode reader application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit camera state */
    MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_EXIT);

    /* stop capture and stop dummy bg midi for multi-channel sound */

    /* reset af related var */
#if defined(__CAMERA_AUTOFOCUS__)
    if (g_barcodereader_cntx.af_state != MMI_BARCODEREADER_AF_IDLE)
    {
        if (g_barcodereader_cntx.is_camera_powered_on)
        {
            mdi_camera_stop_autofocus_process();
        }
    }

    g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_IDLE;
#endif /* defined(__CAMERA_AUTOFOCUS__) */ 

#if defined(__MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__) && !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
    gui_cancel_timer(mmi_barcodereader_capture_button_press);
#endif

#if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
    gui_cancel_timer(mmi_barcodereader_start_capture_and_decode);
#endif

#ifdef __MMI_BARCODEREADER_OPERATOR1__
    gui_cancel_timer(mmi_barcodereader_decode_listen_hdlr);
#endif

    /* stop hide hint timer */
    gui_cancel_timer(mmi_barcodereader_hide_hint);
    gui_cancel_timer(mmi_barcodereader_draw_osd_timer);

    /* shut down camera */
    mdi_camera_power_off();

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* resume LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_RELEASE);

    /* let MMI can sleep */
    TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;


    /* turn off led */
#ifdef __MMI_BARCODEREADER_FLASH__
    if (g_barcodereader_cntx.setting.flash == MMI_BARCODEREADER_SETTING_FLASH_ON)
    {
        if(g_barcodereader_cntx.is_camera_powered_on == MMI_TRUE)
        {
            mdi_camera_flash_setting(FALSE);
        }
    }
#endif /* __MMI_BARCODEREADER_FLASH__ */ 

#ifdef __MMI_SUBLCD__
    gdi_layer_push_and_set_active(g_barcodereader_cntx.sublcd_base_layer_handle);
    gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    gdi_layer_pop_and_restore_active();

    /* exit sublcd */
    if (g_barcodereader_cntx.is_sublcd_display)
    {
        GoBackSubLCDHistory();
        g_barcodereader_cntx.is_sublcd_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_rotate_by_layer(FALSE);
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 
#else
    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
#endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

    /* free preview resource */
    mmi_barcodereader_free_resource();

    /* store camera setting back to NVRAM */
    mmi_barcodereader_store_setting();

    /* this will force title status to redraw */
    entry_full_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_dummy_func
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_dummy_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty function */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_autofocus_callback
 * DESCRIPTION
 *  callback while AF is succeed/fail
 * PARAMETERS
 *  result      [IN]        
 *  void(?)     [OUT]       PMsg
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_autofocus_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* parse pMsg to get result */
    /* and response to osd layer */
    if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_IDLE)
    {
        return;
    }

    g_barcodereader_cntx.af_result = (U8) result;

    if (g_barcodereader_cntx.app_state != MMI_BARCODEREADER_STATE_EXIT)
    {
        if (g_barcodereader_cntx.af_result == 0xFF)
        {
            g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_FAIL;
            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
            mmi_barcodereader_set_hint((PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE), NULL, HINT_POPUP_FADE_TIME);

            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            if (g_barcodereader_cntx.is_af_capture == TRUE)
            {
                g_barcodereader_cntx.is_af_capture = FALSE;
                mmi_barcodereader_capture_button_press();
            }
        }
        else
        {
            g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_SUCCEED;

            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
            mmi_barcodereader_set_hint((PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE), NULL, HINT_POPUP_FADE_TIME);
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            if (g_barcodereader_cntx.is_af_capture == TRUE)
            {
                g_barcodereader_cntx.is_af_capture = FALSE;
                mmi_barcodereader_capture_button_press();
            }
        }
        g_barcodereader_cntx.is_draw_timer_on = FALSE;
        g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_ONFOCUS;
        gui_start_timer(100, mmi_barcodereader_draw_osd_timer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_osd_timer
 * DESCRIPTION
 *  redraw osd timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_osd_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
    if (g_barcodereader_cntx.is_draw_timer_on)
    {
        gui_start_timer(100, mmi_barcodereader_draw_osd_timer);
    }
}

#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_focus_button_press
 * DESCRIPTION
 *  press AF button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_focus_button_press()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_is_ready_to_capture() == TRUE)
    {
        /* g_barcodereader_cntx.is_autofocus_pressed = TRUE; */
        g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_CALCULATE;
        g_barcodereader_cntx.af_animation_process = MMI_BARCODEREADER_AF_ANIMATION_STEP1;

        /* send command to driver to start cal focus */
        mdi_camera_start_autofocus_process((mdi_callback) mmi_barcodereader_autofocus_callback);

        /* clear key handler */
        ClearInputEventHandler(MMI_DEVICE_KEY);

        SetKeyHandler(mmi_barcodereader_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_lsk_release, KEY_LSK, KEY_EVENT_UP);

        SetKeyHandler(mmi_barcodereader_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_rsk_release, KEY_RSK, KEY_EVENT_UP);

        /* register capture and control keys */
        if (MMI_BARCODEREADER_CAPTURE_KEY != -1)
        {
            SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_UP);
        }

        if (MMI_BARCODEREADER_CAPTURE_EXTRA_KEY != -1)
        {
            SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_UP);
        }

        /* draw animation for focus process */
        g_barcodereader_cntx.is_draw_timer_on = TRUE;
        gui_start_timer(100, mmi_barcodereader_draw_osd_timer);

        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_af_and_capture
 * DESCRIPTION
 *  capture button presse
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_af_and_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BARCODEREADER_AF_SUPPORT__)   
    //if (g_barcodereader_cntx.setting.af_mode != MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL)
    {
        mmi_barcodereader_focus_button_press();
    }
#endif 
    mmi_barcodereader_capture_button_press();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_capture_button_press
 * DESCRIPTION
 *  capture button presse
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_capture_button_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* capture only works if camera is ready, otherwise will ignore this action */

    switch (g_barcodereader_cntx.app_state)
    {
        case MMI_BARCODEREADER_STATE_PREVIEW:
            if (mdi_camera_is_ready_to_capture() == TRUE)
            {
                if (g_barcodereader_cntx.is_capturing == FALSE)
                {
                    /* entry capture and decode state */
#if defined(__MMI_BARCODEREADER_FOCUS_MODE__)
                    if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_CALCULATE &&
                        g_barcodereader_cntx.setting.af_mode == MMI_BARCODEREADER_SETTING_FOCUS_MODE_AUTO)
                    {
                        g_barcodereader_cntx.is_af_capture = TRUE;
                        mmi_barcodereader_draw_osd();
                        gdi_layer_blt_previous(
                            0,
                            0,
                            g_barcodereader_cntx.base_UI_device_width - 1,
                            g_barcodereader_cntx.base_UI_device_height - 1);
                        return;
                    }
#endif
                    /* if not self timer, capture the image */
                    MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE);
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "ready to capture , but find that you not press the capture key");
                    ASSERT(0);
                }
            }
            break;

        case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
            if (g_barcodereader_cntx.is_capturing == TRUE)
            {
                if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_ONFOCUS)
                {
                    mdi_camera_stop_autofocus_process();
                }
                /* entry preview state */
                mmi_barcodereader_hide_hint();
                MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_PREVIEW);
            }
            else
            {
            #if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
                gui_cancel_timer(mmi_barcodereader_start_capture_and_decode);
                mmi_barcodereader_hide_hint();
                MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_PREVIEW);
            #else
                ASSERT(0);
            #endif                
            }
            break;
    }
    /* flush key event */
    ClearKeyEvents();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_capture_button_release
 * DESCRIPTION
 *  capture button release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_capture_button_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* flush all key event */
    ClearKeyEvents();
}


#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
static void mmi_barcodereader_mf_status_change(mmi_barcodereader_mf_status_enum status_change)
{
    if(MMI_BARCODEREADER_MF_STATUS_FORWARD)
    {
        if (!g_barcodereader_cntx.is_up_arrow_pressed)
        {
#if defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
            mmi_barcodereader_mf_forward();
#endif 
        }
        g_barcodereader_cntx.is_up_arrow_pressed = TRUE;
    }
    else
    {
        if (!g_barcodereader_cntx.is_down_arrow_pressed)
        {
#if defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
            mmi_barcodereader_mf_backward();
#endif 
        }
        g_barcodereader_cntx.is_down_arrow_pressed = TRUE;
    }
}

static void mmi_barcodereader_mf_status_revert(mmi_barcodereader_mf_status_enum status_change)
{
    if(MMI_BARCODEREADER_MF_STATUS_FORWARD)
    {
        g_barcodereader_cntx.is_up_arrow_pressed = FALSE;
        
        g_barcodereader_cntx.touch_mf_inc.is_press = FALSE;
        
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
        if (g_barcodereader_cntx.is_mf_continue == TRUE)
        {
            g_barcodereader_cntx.is_draw_timer_on = FALSE;
            mmi_barcodereader_mf_stop();
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
        }
        else
        {
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            gui_cancel_timer(mmi_barcodereader_mf_forward_continue);
        }
#endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 
    }
    else
    {
        g_barcodereader_cntx.is_down_arrow_pressed = FALSE;
        
        g_barcodereader_cntx.touch_mf_dec.is_press = FALSE;
        
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
        if (g_barcodereader_cntx.is_mf_continue == TRUE)
        {
            g_barcodereader_cntx.is_draw_timer_on = FALSE;
            mmi_barcodereader_mf_stop();
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
        }
        else
        {
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            gui_cancel_timer(mmi_barcodereader_mf_backward_continue);
        }
#endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 
    }
}

#endif  /*__MMI_BARCODEREADER_MF_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_storage_hotkey_press
 * DESCRIPTION
 *  delay_timer hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_BARCODEREADER_STORAGE__)
static void mmi_barcodereader_storage_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_storage_change(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_storage_change
 * DESCRIPTION
 *  storage change
 * PARAMETERS
 *  is_next     [IN]        Change storage to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_storage_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    U16 cur_storage = 0;
    S32 create_result = 0;
    U8 current_storage_index = 0;
    U8 total_num = 0;



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fmgr_get_exist_storage_inline_list((S8)g_barcodereader_cntx.setting.storage,&total_num,&(g_barcodereader_cntx.drv_inline_list_p),(PU8)&current_storage_index);

    if (total_num > 1) g_barcodereader_cntx.is_storage_path_changed = TRUE;

    /* current_storage_index must <= total_num */
    ASSERT(current_storage_index <= total_num);

    if (is_next)
    {
        if (current_storage_index < total_num - 1)
        {
            current_storage_index++;
        }
        else
        {
            current_storage_index = 0;
        }
    }
    else
    {
        if (current_storage_index >= 1)
        {
            current_storage_index--;
        }
        else
        {
            current_storage_index = total_num-1;
        }

    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_BARCODEREADER_STORAGE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_barcodereader_set_hint(
        (PS8) str_buf,
        (PS8) (((U8**) (g_barcodereader_cntx.drv_inline_list_p))[current_storage_index]),
        HINT_POPUP_FADE_TIME);

    mmi_fmgr_get_drive_letter_by_inline_index(current_storage_index,(S8*)&g_barcodereader_cntx.setting.storage);


    /* storage changed */
    if (g_barcodereader_cntx.is_storage_path_changed)
    {
        /* check if path is valid or not. if not will pop up a screen after the preview screen is show */
        cur_storage = g_barcodereader_cntx.setting.storage;

        if (mmi_barcodereader_check_and_restore_valid_drv())
        {
            /* drv is valid, create directory */
            mmi_barcodereader_get_storage_file_path((PS8)g_barcodereader_cntx.storage_filepath);
            create_result = mmi_barcodereader_create_file_dir((PS8)g_barcodereader_cntx.storage_filepath);

            /* create directory failed */
            if (create_result == FS_WRITE_PROTECTION)
            {
                g_barcodereader_cntx.last_error.error_result = FS_WRITE_PROTECTION;
                g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;


                /* has error - restore to phone */
                g_barcodereader_cntx.setting.storage = (U16) MMI_PUBLIC_DRV;
                g_barcodereader_cntx.is_storage_path_changed = TRUE;
            }
            else if (create_result == FS_DISK_FULL)
            {
                if (cur_storage == (U16) MMI_PUBLIC_DRV)
                {
                    g_barcodereader_cntx.last_error.error_result = FS_DISK_FULL;
                    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
                }
                else
                {
                    /* storage is card */
                    g_barcodereader_cntx.last_error.error_result = FS_DISK_FULL;
                    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;

                    /* has error - restore to phone */
                    g_barcodereader_cntx.setting.storage = (U16) MMI_PUBLIC_DRV;
                    g_barcodereader_cntx.is_storage_path_changed = TRUE;
                }
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                if (cur_storage == (U16) MMI_PUBLIC_DRV)
                {
                    g_barcodereader_cntx.last_error.error_result = FS_ROOT_DIR_FULL;
                    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
                }
                else
                {
                    /* storage is card */
                    g_barcodereader_cntx.last_error.error_result = FS_ROOT_DIR_FULL;
                    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;

                    /* has error - restore to phone */
                    g_barcodereader_cntx.setting.storage = (U16) MMI_PUBLIC_DRV;
                    g_barcodereader_cntx.is_storage_path_changed = TRUE;
                }
            }

        }
        else
        {
            /* drv no valid, means card is plugged out (or phone FAT corrupted) */

            /* if storage before restoration is already in phone, means FAT is corrupted */
            if (cur_storage == (U16) MMI_PUBLIC_DRV)
            {
                g_barcodereader_cntx.last_error.error_result = FS_FAT_ALLOC_ERROR;
                g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
            }
            else
            {
                g_barcodereader_cntx.last_error.error_result = FS_DRIVE_NOT_READY;
                g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
            }
        }
        
        /* check if preview success */
        /*if (g_barcodereader_cntx.last_error.error_result != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_barcodereader_display_error_popup();
            return;
        }*/
    }

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous( 
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}

#endif /* defined(__MMI_BARCODEREADER_STORAGE__) */ 


#ifdef __MMI_BARCODEREADER_BANDING__
static void mmi_barcodereader_banding_hotkey_press(void)
{
    mmi_barcodereader_banding_change(MMI_TRUE);
}


static void mmi_barcodereader_banding_change(MMI_BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next == MMI_TRUE)
    {
        g_barcodereader_cntx.setting.banding = 
            (g_barcodereader_cntx.setting.banding + 1) % MMI_BARCODEREADER_SETTING_BANDING_COUNT;
    }
    else
    {
        g_barcodereader_cntx.setting.banding = 
            (g_barcodereader_cntx.setting.banding - 1 + MMI_BARCODEREADER_SETTING_BANDING_COUNT) % 
            MMI_BARCODEREADER_SETTING_BANDING_COUNT;
    }
    
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_BARCODEREADER_BANDING));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    /* update  parameter to mdi_camera */
    mdi_camera_update_para_banding(barcodereader_focus_mode_command_map[g_barcodereader_cntx.setting.banding]);
    
    mmi_barcodereader_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_barcodereader_cntx.setting.banding + STR_ID_BARCODEREADER_BANDING_START + 1)),
        HINT_POPUP_FADE_TIME);
    mmi_barcodereader_draw_osd();
    
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_storage_file_path
 * DESCRIPTION
 *  get current active storage file path.
 * PARAMETERS
 *  filepath        [IN]        
 *  a(?)            [OUT]       Fill storage full path
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_barcodereader_get_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv_buf[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_barcodereader_get_storage_disk_path(&g_barcodereader_cntx.setting.storage, drv_buf))
    {
        mmi_ucs2cpy((PS8) filepath, (PS8) drv_buf);
        mmi_ucs2cat((PS8) filepath, (PS8) MMI_BARCODEREADER_STORAGE_FILEPATH_PHONE);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_storage_disk_path
 * DESCRIPTION
 *  get current active storage disk path.
 * PARAMETERS
 *  drv_buf     [IN]        
 *  a(?)        [OUT]       Fill disk's name string.
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_barcodereader_get_storage_disk_path(PU16 drive, PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];
    int error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR == FS_GetDevStatus((UINT)(*drive), FS_MOUNT_STATE_ENUM))
    {
        sprintf(buf, "%c:\\", (U8)(*drive) );
        mmi_asc_to_ucs2(drv_buf, buf);
        return TRUE;
    }
    else
    {
        *drive = (U16) MMI_PUBLIC_DRV;
        error = FS_GetDevStatus((UINT)(*drive), FS_MOUNT_STATE_ENUM);

        if (FS_NO_ERROR == error)
        {
            sprintf(buf, "%c:\\", (U8)*drive  );
            mmi_asc_to_ucs2(drv_buf, buf);
            return TRUE;
        }
        else
        {
            PRINT_INFORMATION_2(
                MMI_TRACE_G8_MEDIA, 
                "barcodereader storage error in mmi_barcodereader_get_storage_disk_path\n");
            g_barcodereader_cntx.last_error.error_result = error;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;

            return FALSE;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_create_file_dir
 * DESCRIPTION
 *  create directly from a file path (resursivly)
 * PARAMETERS
 *  filepath        [IN]        
 *  a(?)            [IN]        File path to create
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_barcodereader_create_file_dir(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_createpath[FMGR_PATH_BUFFER_SIZE];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 fs_ret;
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return FS_NO_ERROR;   
    }

    /* create directory if it is not there */
    mmi_ucs2cpy((PS8) buf_filepath, (PS8) filepath);

    str_len = mmi_ucs2strlen((PS8) buf_filepath);
    str_len *= ENCODING_LENGTH;

    /* skip drive. "C:\" */
    for (i = 3 * ENCODING_LENGTH; i < str_len; i += 2)
    {
        cmp_ret = mmi_ucs2ncmp((PS8) & buf_filepath[i], (PS8) L"\\", 1);
        if (cmp_ret == 0)
        {
            /* create dir */

            mmi_ucs2ncpy((PS8) buf_createpath, (PS8) buf_filepath, i / ENCODING_LENGTH);
            buf_createpath[i] = '\0';
            buf_createpath[i + 1] = '\0';

            fs_ret = FS_CreateDir((PU16) buf_createpath);

            if (fs_ret < 0)
            {
                return fs_ret;
            }
        }
    }

    return fs_ret;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_flash_hotkey_press
 * DESCRIPTION
 *  flash hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_BARCODEREADER_FLASH__)
static void mmi_barcodereader_flash_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_flash_change(TRUE);
}
#endif /* defined(__MMI_BARCODEREADER_FLASH__) */ 

static void mmi_barcodereader_ev_status_hotkey_press(void)
{
    mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_INC);    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_flash_change
 * DESCRIPTION
 *  flash change
 * PARAMETERS
 *  is_next     [IN]        Change led highlight to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_BARCODEREADER_FLASH__
static void mmi_barcodereader_flash_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        g_barcodereader_cntx.setting.flash =
            (g_barcodereader_cntx.setting.flash + 1) % MMI_BARCODEREADER_SETTING_FLASH_COUNT; 
    }
    else
    {
        g_barcodereader_cntx.setting.flash =
            (g_barcodereader_cntx.setting.flash - 1 + MMI_BARCODEREADER_SETTING_FLASH_COUNT) % 
            MMI_BARCODEREADER_SETTING_FLASH_COUNT; 
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_BARCODEREADER_FLASH));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_barcodereader_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_barcodereader_cntx.setting.flash + STR_ID_BARCODEREADER_FLASH_START + 1)),
        HINT_POPUP_FADE_TIME);

    /* update quality parameter to mdi_camera */
    /* mdi_camera_update_para_flash(barcodereader_flash_command_map[g_barcodereader_cntx.setting.flash]); */
    if (g_barcodereader_cntx.setting.flash == MMI_BARCODEREADER_SETTING_FLASH_OFF)
    {
        mdi_camera_flash_setting(FALSE);
    }
    else
    {
        mdi_camera_flash_setting(TRUE);
    }

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

}
#endif /* __MMI_BARCODEREADER_FLASH__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_af_mode_hotkey_press
 * DESCRIPTION
 *  focus mode hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
static void mmi_barcodereader_af_mode_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_focus_mode_change(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_focus_mode_change
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  is_next     [IN]        Change shot mode to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_focus_mode_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        g_barcodereader_cntx.setting.af_mode = 
            (g_barcodereader_cntx.setting.af_mode + 1) % MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT;
    }
    else
    {
        g_barcodereader_cntx.setting.af_mode = 
            (g_barcodereader_cntx.setting.af_mode - 1 + MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT) % 
            MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT;
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_BARCODEREADER_FOCUS_MODE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_af_mode(barcodereader_focus_mode_command_map[g_barcodereader_cntx.setting.af_mode]);

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    if (g_barcodereader_cntx.setting.af_mode == MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL)
    {
        mdi_camera_get_focus_steps(&(g_barcodereader_cntx.mf_level_cnt), &(g_barcodereader_cntx.mf_level_idx));
    }
#endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 

    mmi_barcodereader_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_barcodereader_cntx.setting.af_mode + STR_ID_BARCODEREADER_FOCUS_MODE_START + 1)),
        HINT_POPUP_FADE_TIME);
    mmi_barcodereader_draw_osd();

    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}
#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 


static void mmi_barcodereader_ev_status_change(mmi_barcodereader_ev_status_enum status_change)
{
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    S8 str_buf[256];
#endif 

    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        if (status_change == MMI_BARCODEREADER_EV_STATUS_DEC)
        {
            if (g_barcodereader_cntx.setting.ev == 0)
            {
                return;
            }
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                g_barcodereader_cntx.touch_ev_dec.is_press = TRUE;
#endif
                g_barcodereader_cntx.setting.ev = 
                    (g_barcodereader_cntx.setting.ev - 1 + MMI_BARCODEREADER_SETTING_EV_COUNT) %
                    MMI_BARCODEREADER_SETTING_EV_COUNT;
        }
        else if (status_change == MMI_BARCODEREADER_EV_STATUS_INC)
        {
            if (g_barcodereader_cntx.setting.ev == MMI_BARCODEREADER_SETTING_EV_COUNT - 1)
            {
                return;
            }
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                g_barcodereader_cntx.touch_ev_inc.is_press = TRUE;
#endif
                g_barcodereader_cntx.setting.ev = 
                    (g_barcodereader_cntx.setting.ev + 1) %
                    MMI_BARCODEREADER_SETTING_EV_COUNT;
        }          
            
        mdi_camera_update_para_ev(barcodereader_ev_command_map[g_barcodereader_cntx.setting.ev]);
#ifndef __MMI_BARCODEREADER_OPERATOR1__
        mmi_barcodereader_set_hint(NULL, NULL, 0);
#else
        mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
        mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_BARCODEREADER_EV));
        mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
        mmi_barcodereader_set_hint(
            (PS8) str_buf,
            (PS8) GetString((U16) (g_barcodereader_cntx.setting.ev + STR_ID_BARCODEREADER_EV_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);
    }    
}


static void mmi_barcodereader_ev_status_revert(mmi_barcodereader_ev_status_enum status_change)
{
    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
        if(status_change == MMI_BARCODEREADER_EV_STATUS_INC)
        {
            g_barcodereader_cntx.touch_ev_inc.is_press = FALSE;
        }
        else
        {
            g_barcodereader_cntx.touch_ev_dec.is_press = FALSE;
        }
#endif
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_rsk_press
 * DESCRIPTION
 *  previwe rsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    g_barcodereader_cntx.is_rsk_pressed = TRUE;
#endif

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_rsk_release
 * DESCRIPTION
 *  previwe rsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    g_barcodereader_cntx.is_rsk_pressed = FALSE;
#endif

    mmi_barcodereader_draw_osd();

    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

    /* camera with only 23key, will use RSK to capture */
#ifndef __MMI_BARCODEREADER_OPERATOR1__
#ifdef __MMI_CAMERA_23KEY__
    mmi_barcodereader_capture_button_press();
#else 
    GoBackHistory();
#endif 
#else
    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE)
    {
        g_barcodereader_cntx.b_stop_decode = MMI_FALSE;
        gui_cancel_timer(mmi_barcodereader_decode_listen_hdlr);
        mmi_barcodereader_capture_button_press();
    }
    else
    {
        GoBackHistory();
    }
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_lsk_press
 * DESCRIPTION
 *  previwe lsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    g_barcodereader_cntx.is_lsk_pressed = TRUE;
#endif

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_lsk_release
 * DESCRIPTION
 *  previwe lsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    g_barcodereader_cntx.is_lsk_pressed = FALSE;
#endif

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

    /* Enter barcode reader option menu screen */
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    mmi_barcodereader_entry_option_menu_screen();
#else
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
    mmi_barcodereader_af_and_capture();
#else 
    mmi_barcodereader_capture_button_press();
#endif        
#endif

}


static void mmi_barcodereader_key_hdlr(void)
{
    U16 key_code, key_type;

    GetkeyInfo(&key_code, &key_type);
    switch(key_code)
    {
    case MMI_BARCODEREADER_CAPTURE_EXTRA_KEY:
    case MMI_BARCODEREADER_CAPTURE_KEY:
        switch(key_type)
        {
        case KEY_EVENT_UP:
            mmi_barcodereader_capture_button_release();
            break;

        case KEY_EVENT_DOWN:
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
#ifdef __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__
            mmi_barcodereader_re_focus_press();
#else
            mmi_barcodereader_af_and_capture();
#endif
#else
            mmi_barcodereader_capture_button_press();
#endif
            break;

        case KEY_EVENT_REPEAT:
            mmi_barcodereader_dummy_func();
            break;

        default:
            break;
        }
        break;

    case KEY_UP_ARROW:
        switch(key_type)
        {
        case KEY_EVENT_UP:
            if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_INC);
#endif
            }
            else if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_180)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
                mmi_barcodereader_mf_status_revert(MMI_BARCODEREADER_MF_STATUS_BACKWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            else if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_DEC);
#endif
            }   
            else
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
                mmi_barcodereader_mf_status_revert(MMI_BARCODEREADER_MF_STATUS_FORWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            break;
            
        case KEY_EVENT_DOWN:
            if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_DEC);
#endif
            }
            else if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_180)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
                mmi_barcodereader_mf_status_change(MMI_BARCODEREADER_MF_STATUS_FORWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            else if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_INC);
#endif
            }   
            else
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
                mmi_barcodereader_mf_status_change(MMI_BARCODEREADER_MF_STATUS_BACKWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            break;

        default:
            break;
        }
        break;
        
    case KEY_DOWN_ARROW:
        switch(key_type)
        {
        case KEY_EVENT_UP:
            if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_INC);
#endif
            }
            else if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_180)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
                mmi_barcodereader_mf_status_revert(MMI_BARCODEREADER_MF_STATUS_BACKWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            else if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_DEC);
#endif
            }   
            else
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__                
                mmi_barcodereader_mf_status_revert(MMI_BARCODEREADER_MF_STATUS_FORWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            break;
            
        case KEY_EVENT_DOWN:
            if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_INC);
#endif
            }
            else if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_180)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_change(MMI_BARCODEREADER_MF_STATUS_BACKWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            else if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_DEC);
#endif
            }   
            else
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_change(MMI_BARCODEREADER_MF_STATUS_FORWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            break;

        default:
            break;
        }
        break;
        
    case KEY_LEFT_ARROW:
        switch(key_type)
        {
        case KEY_EVENT_UP:
            if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_revert(MMI_BARCODEREADER_MF_STATUS_FORWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            else if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_180)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_INC);
#endif
            }
            else if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_revert(MMI_BARCODEREADER_MF_STATUS_BACKWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }   
            else
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_DEC);
#endif
            }
            break;
            
        case KEY_EVENT_DOWN:
            if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_change(MMI_BARCODEREADER_MF_STATUS_FORWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            else if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_180)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_INC);
#endif
            }
            else if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_change(MMI_BARCODEREADER_MF_STATUS_BACKWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }   
            else
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_DEC);
#endif
            }
            break;
            
        default:
            break;
        }
        break;
        
    case KEY_RIGHT_ARROW:
        switch(key_type)
        {
        case KEY_EVENT_UP:
            if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_revert(MMI_BARCODEREADER_MF_STATUS_BACKWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            else if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_180)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_DEC);
#endif
            }
            else if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_revert(MMI_BARCODEREADER_MF_STATUS_FORWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }   
            else
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_INC);
#endif
            }
            break;
            
        case KEY_EVENT_DOWN:
            if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_change(MMI_BARCODEREADER_MF_STATUS_BACKWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }
            else if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_180)
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_DEC);
#endif
            }
            else if(g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
            {
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__     
                mmi_barcodereader_mf_status_change(MMI_BARCODEREADER_MF_STATUS_FORWARD);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__*/
            }   
            else
            {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_INC);
#endif
            }
            break;

        default:
            break;
        }
        break;
        
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
    case MMI_BARCODEREADER_FOCUS_MODE_KEY:
        switch(key_type)
        {
        case KEY_EVENT_DOWN:
            mmi_barcodereader_af_mode_hotkey_press();
            break;

        default:
            break;
        }
        break;
#endif
        
#ifdef __MMI_BARCODEREADER_FLASH__
    case MMI_BARCODEREADER_FLASH_KEY:
        switch(key_type)
        {            
        case KEY_EVENT_DOWN:
            mmi_barcodereader_flash_hotkey_press();
            break;
            
        default:
            break;
        }
        break;
#endif

#ifdef __MMI_BARCODEREADER_STORAGE__
    case MMI_BARCODEREADER_STORAGE_KEY:
        switch(key_type)
        {            
        case KEY_EVENT_DOWN:
            mmi_barcodereader_storage_hotkey_press();
            break;
                        
        default:
            break;
        }
        break;
#endif

#ifdef MMI_BARCODEREADER_BANDING_KEY
    case MMI_BARCODEREADER_BANDING_KEY:
        switch(key_type)
        {
        case KEY_EVENT_DOWN:
            mmi_barcodereader_banding_hotkey_press();
            break;

        default:
            break;
        }
        break;
#endif

#ifdef MMI_BARCODEREADER_EV_STATUS_KEY
    case MMI_BARCODEREADER_EV_STATUS_KEY:
        switch(key_type)
        {
        case KEY_EVENT_DOWN:
             mmi_barcodereader_ev_status_hotkey_press();
             break;
              
        default:
            break;
        }
        break;
#endif

    case KEY_LSK:
        switch(key_type)
        {
        case KEY_EVENT_UP:
                mmi_barcodereader_lsk_release();
            break;
            
        case KEY_EVENT_DOWN:
                mmi_barcodereader_lsk_press();
            break;

        default:
            break;
        }
        break;

    case KEY_RSK:
        switch(key_type)
        {
        case KEY_EVENT_UP:
                mmi_barcodereader_rsk_release();
            break;
            
        case KEY_EVENT_DOWN:
            mmi_barcodereader_rsk_press();
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_start
 * DESCRIPTION
 *  start previewing of main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_setting_struct camera_setting_data;
    GDI_HANDLE preview_layer_handle = 0;
    U32 preview_layer_flag = 0;
    U32 blt_layer_flag = 0;
    S32 preview_wnd_offset_x = 0;
    S32 preview_wnd_offset_y = 0;
    U16 preview_wnd_width = 0;
    U16 preview_wnd_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_load_default_setting(&camera_setting_data);

    camera_setting_data.osd_rotate = 0;

    /* preview parametes */
    camera_setting_data.ev = barcodereader_ev_command_map[g_barcodereader_cntx.setting.ev];
    camera_setting_data.flash = barcodereader_flash_command_map[g_barcodereader_cntx.setting.flash];
    camera_setting_data.af_mode = barcodereader_focus_mode_command_map[g_barcodereader_cntx.setting.af_mode];
    camera_setting_data.banding = barcodereader_banding_command_map[g_barcodereader_cntx.setting.banding];
    camera_setting_data.osd_rotate = g_barcodereader_cntx.osd_rotate;
    camera_setting_data.preview_width = g_barcodereader_cntx.preview_width;
    camera_setting_data.preview_height = g_barcodereader_cntx.preview_height;

    /* capture parameters */
    camera_setting_data.image_width = g_barcodereader_cntx.image_width;
    camera_setting_data.image_height = g_barcodereader_cntx.image_height;

    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data.preview_rotate = MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE;
    camera_setting_data.lcm_rotate = MMI_BARCODEREADER_LCM_MAINLCD_ROTATE;

    /* turn on led highlight */
    /* mmi_barcodereader_turn_on_preview_led_highlight(); */

    /* if using MT6218B series moudle with a Master backend (AIT700, etc),
       we have to clear the preview layer's background to transparent,
       and we have to resoret it after preview stop (stopped by capture command) */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
#endif 

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
#ifdef __MMI_HORIZONTAL_BARCODEREADER__
    {
        S32 tmp;

        if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
        {
            camera_setting_data.af_zone0_x = MMI_BARCODEREADER_AF_POSITION_1_X;
            camera_setting_data.af_zone0_y = MMI_BARCODEREADER_AF_POSITION_1_Y;
            camera_setting_data.af_zone1_x = MMI_BARCODEREADER_AF_POSITION_4_X;
            camera_setting_data.af_zone1_y = MMI_BARCODEREADER_AF_POSITION_4_Y;
            camera_setting_data.af_zone2_x = MMI_BARCODEREADER_AF_POSITION_5_X;
            camera_setting_data.af_zone2_y = MMI_BARCODEREADER_AF_POSITION_5_Y;
            camera_setting_data.af_zone3_x = MMI_BARCODEREADER_AF_POSITION_3_X;
            camera_setting_data.af_zone3_y = MMI_BARCODEREADER_AF_POSITION_3_Y;
            camera_setting_data.af_zone4_x = MMI_BARCODEREADER_AF_POSITION_2_X;
            camera_setting_data.af_zone4_y = MMI_BARCODEREADER_AF_POSITION_2_Y;

            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone0_x, camera_setting_data.af_zone0_y, tmp);
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone1_x, camera_setting_data.af_zone1_y, tmp);
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone2_x, camera_setting_data.af_zone2_y, tmp);
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone3_x, camera_setting_data.af_zone3_y, tmp);
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone4_x, camera_setting_data.af_zone4_y, tmp);

            g_barcodereader_cntx.af_zone0_x = camera_setting_data.af_zone0_x;
            g_barcodereader_cntx.af_zone1_x = camera_setting_data.af_zone1_x;
            g_barcodereader_cntx.af_zone2_x = camera_setting_data.af_zone2_x;
            g_barcodereader_cntx.af_zone3_x = camera_setting_data.af_zone3_x;
            g_barcodereader_cntx.af_zone4_x = camera_setting_data.af_zone4_x;

            g_barcodereader_cntx.af_zone0_y = camera_setting_data.af_zone0_y;
            g_barcodereader_cntx.af_zone1_y = camera_setting_data.af_zone1_y;
            g_barcodereader_cntx.af_zone2_y = camera_setting_data.af_zone2_y;
            g_barcodereader_cntx.af_zone3_y = camera_setting_data.af_zone3_y;
            g_barcodereader_cntx.af_zone4_y = camera_setting_data.af_zone4_y;
        }
        else
        {
            g_barcodereader_cntx.af_zone0_x = camera_setting_data.af_zone0_x = MMI_BARCODEREADER_AF_POSITION_1_X;
            g_barcodereader_cntx.af_zone0_y = camera_setting_data.af_zone0_y = MMI_BARCODEREADER_AF_POSITION_1_Y;
            g_barcodereader_cntx.af_zone1_x = camera_setting_data.af_zone1_x = MMI_BARCODEREADER_AF_POSITION_2_X;
            g_barcodereader_cntx.af_zone1_y = camera_setting_data.af_zone1_y = MMI_BARCODEREADER_AF_POSITION_2_Y;
            g_barcodereader_cntx.af_zone2_x = camera_setting_data.af_zone2_x = MMI_BARCODEREADER_AF_POSITION_3_X;
            g_barcodereader_cntx.af_zone2_y = camera_setting_data.af_zone2_y = MMI_BARCODEREADER_AF_POSITION_3_Y;
            g_barcodereader_cntx.af_zone3_x = camera_setting_data.af_zone3_x = MMI_BARCODEREADER_AF_POSITION_4_X;
            g_barcodereader_cntx.af_zone3_y = camera_setting_data.af_zone3_y = MMI_BARCODEREADER_AF_POSITION_4_Y;
            g_barcodereader_cntx.af_zone4_x = camera_setting_data.af_zone4_x = MMI_BARCODEREADER_AF_POSITION_5_X;
            g_barcodereader_cntx.af_zone4_y = camera_setting_data.af_zone4_y = MMI_BARCODEREADER_AF_POSITION_5_Y;

            /*  remove at 2007/06/27 for useless
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone0_x, camera_setting_data.af_zone0_y, tmp);
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone1_x, camera_setting_data.af_zone1_y, tmp);
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone2_x, camera_setting_data.af_zone2_y, tmp);
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone3_x, camera_setting_data.af_zone3_y, tmp);
            MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone4_x, camera_setting_data.af_zone4_y, tmp);
            */
        }
    }
#else /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    g_barcodereader_cntx.af_zone0_x = camera_setting_data.af_zone0_x = //MMI_BARCODEREADERREADER_AF_POSITION_1_X;
        MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH / 2 + MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X;
    g_barcodereader_cntx.af_zone0_y = camera_setting_data.af_zone0_y = //MMI_BARCODEREADERREADER_AF_POSITION_1_Y;
        MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT / 2 + MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y;
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
#endif /* __MMI_BARCODEREADERREADER_FOCUS_MODE__ */ 

    preview_layer_handle = g_barcodereader_cntx.preview_layer_handle;

    /* use preview wnd's position */
    preview_wnd_offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->preview_wnd.offset_x;
    preview_wnd_offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->preview_wnd.offset_y;
    preview_wnd_width = g_barcodereader_cntx.preview_width;
    preview_wnd_height = g_barcodereader_cntx.preview_height;


    /* preview (hw), OSD */
#if (MDI_CAMERA_MT6227_SERIES||MDI_CAMERA_MT6228_SERIES)
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
#else /* (MDI_CAMERA_MT6227_SERIES||MDI_CAMERA_MT6228_SERIES) */ 
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
#endif /* (MDI_CAMERA_MT6227_SERIES||MDI_CAMERA_MT6228_SERIES) */ 

    g_barcodereader_cntx.last_error.error_result = MDI_RES_CAMERA_SUCCEED;
    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA;

#ifdef __MMI_BARCODEREADER_OPERATOR1__
    mmi_barcodereader_set_interupt_hdlr();
#endif
    g_barcodereader_cntx.last_error.error_result
        = mdi_camera_barcodereader_preview_start(
            preview_layer_handle,
            preview_wnd_offset_x,
            preview_wnd_offset_y,
            preview_wnd_width,
            preview_wnd_height,
            blt_layer_flag,
            preview_layer_flag,
            GDI_COLOR_TRANSPARENT,
            TRUE,
            &camera_setting_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hide_hint
 * DESCRIPTION
 *  hide hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_set_hint(NULL, NULL, 255);
    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_style_text
 * DESCRIPTION
 *  draw style text
 * PARAMETERS
 *  str             [IN]        String
 *  offset_x        [IN]        Offset x
 *  offset_y        [IN]        Offset y
 *  style_txt       [IN]        Text style
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_style_text(
                PS8 str,
                S32 offset_x,
                S32 offset_y,
                barcodereader_style_text_struct *style_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_NORMAL)
    {

        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_print_text((UI_string_type) str);
    }
    else if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_BORDER)
    {
        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
        gui_print_bordered_text((UI_string_type) str);
    }
    else if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_SHADOW)
    {
        gui_move_text_cursor(offset_x + 1, offset_y + 1);
        gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
        gui_print_text((UI_string_type) str);

        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_print_text((UI_string_type) str);
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_softkey
 * DESCRIPTION
 *  draw preview softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    S32 str_width;
    S32 str_height;
    PS8 str_ptr;
    U16 lsk_id;
    U16 rsk_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lsk_id = STR_GLOBAL_OPTIONS;

    /* if only have 23key, use rsk to capture */
#ifdef __MMI_CAMERA_23KEY__
    rsk_id = STR_ID_BARCODEREADER_RSK_CAPTURE;
#else 
    rsk_id = STR_GLOBAL_BACK;
#endif 

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    gui_set_font(&MMI_medium_font);
    
        /* lsk */
    str_ptr = (PS8) GetString(lsk_id);
        
    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
    wgui_softkey_get_offset((UI_string_type)str_ptr, &lsk_offset_x, &lsk_offset_y, MMI_LEFT_SOFTKEY);
        
    if (r2lMMIFlag)
    {
        lsk_offset_x -= str_width;
    }

    if (g_barcodereader_cntx.is_lsk_pressed)
    {
        lsk_offset_x++;
        lsk_offset_y++;
    }
        
    mmi_barcodereader_draw_style_text(
        str_ptr,
        lsk_offset_x,
        lsk_offset_y,
        &g_barcodereader_cntx.active_barcodereader_osd_ptr->softkey.lsk);
        
    g_barcodereader_cntx.touch_lsk.offset_x = lsk_offset_x;
    g_barcodereader_cntx.touch_lsk.offset_y = lsk_offset_y;
    g_barcodereader_cntx.touch_lsk.width = str_width;
    g_barcodereader_cntx.touch_lsk.height = str_height;

    /* rsk */
    str_ptr = (PS8) GetString(rsk_id);

    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
    wgui_softkey_get_offset((UI_string_type)str_ptr, &rsk_offset_x, &rsk_offset_y, MMI_RIGHT_SOFTKEY);

    if (r2lMMIFlag)
    {
        rsk_offset_x -= str_width;
    }

    if (g_barcodereader_cntx.is_rsk_pressed)
    {
        rsk_offset_x++;
        rsk_offset_y++;
    }

    mmi_barcodereader_draw_style_text(
        str_ptr,
        rsk_offset_x ,
        rsk_offset_y ,
        &g_barcodereader_cntx.active_barcodereader_osd_ptr->softkey.rsk);

    g_barcodereader_cntx.touch_rsk.offset_x = rsk_offset_x;
    g_barcodereader_cntx.touch_rsk.offset_y = rsk_offset_y;
    g_barcodereader_cntx.touch_rsk.width = str_width;
    g_barcodereader_cntx.touch_rsk.height = str_height;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_title
 * DESCRIPTION
 *  draw preview title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if not fullscreen and need title */
    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_title_bar &&
        g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_caption)
    {
        gdi_layer_lock_frame_buffer();
        
        show_title_status_icon();
        wgui_title_change(
            GetRootTitleIcon(MENU_ID_BARCODEREADER_APP), 
            0, 
            (U8*)GetString(STR_ID_BARCODEREADER_PREVIEW),
            WGUI_TITLE_CHANGE_ICON | WGUI_TITLE_CHANGE_TEXT);
        draw_title();

        gdi_layer_unlock_frame_buffer();
        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_hint
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str1_width;
    S32 str1_height;
    S32 str2_width;
    S32 str2_height;
    S32 str1_offset_x;
    S32 str1_offset_y;
    S32 str2_offset_x;
    S32 str2_offset_y;
    S32 spacing;
    PS8 hint_str1;
    PS8 hint_str2;

    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear hint background region */

    /* draw hint */
    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.is_show)
    {
        hint_str1 = g_barcodereader_cntx.hint1_buf;
        hint_str2 = g_barcodereader_cntx.hint2_buf;

        /* be removed : clear hint backgounrd */

        gui_set_text_clip(
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_x,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_y,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_x + g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.width - 1,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_y + g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.height - 1);

        gui_measure_string((UI_string_type) hint_str1, &str1_width, &str1_height);
        gui_measure_string((UI_string_type) hint_str2, &str2_width, &str2_height);

        str1_offset_x = (g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.width - str1_width) >> 1;

        spacing = g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.height - str1_height - str2_height;
        spacing = (spacing > 0) ? (spacing / 3 + 1) : 0;

        str1_offset_y = spacing;
        str2_offset_y = str1_offset_y + spacing + str1_height;
        str2_offset_x = (g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.width - str2_width) >> 1;

        gdi_layer_reset_clip();
        gui_reset_text_clip();

        mmi_barcodereader_draw_style_text(
            hint_str1,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_x + str1_offset_x - offset_x,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_y + str1_offset_y - offset_y,
            &g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.style_text);

        mmi_barcodereader_draw_style_text(
            hint_str2,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_x + str2_offset_x - offset_x,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_y + str2_offset_y - offset_y,
            &g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.style_text);

        if (g_barcodereader_cntx.fade_time != 0 && g_barcodereader_cntx.fade_time != 255)
        {
            gui_start_timer(HINT_POPUP_FADE_TIME, mmi_barcodereader_hide_hint);
            g_barcodereader_cntx.fade_time = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_icon
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //      S8      str_buf[256];
    //      U8              str_buf_UCS2[512];      
    //      S32     str_width;
    //      S32     str_height;     
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*****************************************************
   *  define MACRO
   *****************************************************/
#define DRAW_OSD_ICON(a,A)                                                                                \
   do {                                                                                                      \
      if(g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.is_show)                                   \
      {                                                                                                      \
         gdi_image_draw_id(g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.offset_x,                \
                           g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.offset_y,                \
                           (U16)(IMG_ID_BARCODEREADER_OSD_##A##_START+g_barcodereader_cntx.setting.##a##+1));\
      }                                                                                                      \
   } while(0);

    if (!g_barcodereader_cntx.is_hide_osd)
    {
        /* draw icon */
    #ifdef __MMI_BARCODEREADER_FLASH__
        DRAW_OSD_ICON(flash, FLASH);
    #endif 

    #ifdef __MMI_BARCODEREADER_FOCUS_MODE__
        DRAW_OSD_ICON(af_mode, FOCUS_MODE);
    #endif 

    #ifdef __MMI_BARCODEREADER_STORAGE__
        if (g_barcodereader_cntx.active_barcodereader_osd_ptr->storage.is_show)
        {
            if (g_barcodereader_cntx.setting.storage == MMI_PUBLIC_DRV)
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->storage.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->storage.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_STORAGE_PHONE));
            }
            else
            {
            gdi_image_draw_id(
                g_barcodereader_cntx.active_barcodereader_osd_ptr->storage.offset_x - offset_x,
                g_barcodereader_cntx.active_barcodereader_osd_ptr->storage.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD));
            }        
        }
    #endif /* __MMI_BARCODEREADER_STORAGE__ */ 

        /* ev */
        DRAW_OSD_ICON(ev, EV);

        if (g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.is_show)
        {
            if (g_barcodereader_cntx.touch_ev_inc.is_press)
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_INC_SEL));
            }
            else
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_INC));
            }
        }

        if (g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.is_show)
        {
            if (g_barcodereader_cntx.touch_ev_dec.is_press)
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_DEC_SEL));
            }
            else
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_DEC));
            }
        }

    #ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
        if (g_barcodereader_cntx.setting.af_mode == MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL)
        {
            S32 bar_width, bar_height, slider_x, slider_y, slider_width, slider_height;
            U8 total_idx, current_idx;

            gdi_image_draw_id(
                g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_x - offset_x,
                g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_y - offset_y,
                IMG_ID_BARCODEREADER_OSD_MF_BAR);

            /* CALCULATE THE SLIDER LOACTION AND DRAW */
            if (g_barcodereader_cntx.is_mf_continue == TRUE)
            {
                mdi_camera_get_focus_steps(&(g_barcodereader_cntx.mf_level_cnt), &(g_barcodereader_cntx.mf_level_idx));
            }

            total_idx = (U8) g_barcodereader_cntx.mf_level_cnt;
            current_idx = (U8) g_barcodereader_cntx.mf_level_idx;

            gdi_image_get_dimension_id(IMG_ID_BARCODEREADER_OSD_MF_BAR, &bar_width, &bar_height);
            gdi_image_get_dimension_id(IMG_ID_BARCODEREADER_OSD_MF_SLIDER, &slider_width, &slider_height);

            slider_x =
                g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_x - (S32) (slider_width - bar_width) / 2;

            if (current_idx == total_idx)
            {
                slider_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_y;
            }
            else if (current_idx == 0)
            {
                slider_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_y + bar_height - slider_height;
            }
            else
            {
                slider_y =
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_y + (total_idx -
                                                                                      current_idx) * (bar_height -
                                                                                                      slider_height) /
                    total_idx;

            }

            gdi_image_draw_id(slider_x - offset_x, slider_y - offset_y, IMG_ID_BARCODEREADER_OSD_MF_SLIDER);

            if (g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.is_show)
            {
                if (g_barcodereader_cntx.touch_mf_inc.is_press)
                {
                    gdi_image_draw_id(
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_x - offset_x,
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_y - offset_y,
                        (U16) (IMG_ID_BARCODEREADER_OSD_MF_INC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_x - offset_x,
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_y - offset_y,
                        (U16) (IMG_ID_BARCODEREADER_OSD_MF_INC));
                }
            }

            if (g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.is_show)
            {

                if (g_barcodereader_cntx.touch_mf_dec.is_press)
                {
                    gdi_image_draw_id(
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_x - offset_x,
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_y - offset_y,
                        (U16) (IMG_ID_BARCODEREADER_OSD_MF_DEC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_x - offset_x,
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_y - offset_y,
                        (U16) (IMG_ID_BARCODEREADER_OSD_MF_DEC));
                }
            }
        }
    #endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 
    }


    /* capture icon */
    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.is_show)
    {
        if (g_barcodereader_cntx.is_capturing || g_barcodereader_cntx.is_af_capture)
        {
            gdi_image_draw_id(
                g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_x - offset_x,
                g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_y - offset_y,
                (U16) (IMG_ID_BARCODEREADER_OSD_CAPTURE_SEL));
        }
        else
        {
            gdi_image_draw_id(
                g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_x - offset_x,
                g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_y - offset_y,
                (U16) (IMG_ID_BARCODEREADER_OSD_CAPTURE));
        }
    }
#else
    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.is_show)
    {
        if (g_barcodereader_cntx.is_capturing || g_barcodereader_cntx.is_af_capture)
        {
            gdi_image_draw_id(
                MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X,
                MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y,
                (U16) (IMG_ID_BARCODEREADER_OSD_CAPTURE_SEL));
        }
        else
        {
            gdi_image_draw_id(
                MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X,
                MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y,
                (U16) (IMG_ID_BARCODEREADER_OSD_CAPTURE));
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_osd
 * DESCRIPTION
 *  draw preview osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_barcodereader_cntx.osd_layer_handle);
    /* toggle double buffer */
    gdi_layer_toggle_double();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

#ifndef __MMI_BARCODEREADER_OPERATOR1__
    /* draw background */
    gdi_image_draw_id(0, 0, IMG_ID_BARCODEREADER_PREVIEW_BACKGROUND);
#endif

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    /* if(g_barcodereader_cntx.is_autofocus_pressed == TRUE) */
    mmi_barcodereader_draw_focus_process();
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 
    mmi_barcodereader_draw_softkey();
    mmi_barcodereader_draw_title();   

    if (g_barcodereader_cntx.fade_time != 255)
    {
        mmi_barcodereader_draw_hint();
        g_barcodereader_cntx.fade_time = 0;
    }

    mmi_barcodereader_draw_icon();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_clear_background
 * DESCRIPTION
 *  clear backgroud of preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_clear_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color bg_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);

    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.is_draw_bg_color)
    {
        bg_color = GDI_RGB_TO_BUFFER_FORMAT(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.r,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.g,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.b);

        gdi_layer_clear(bg_color);
    }

    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.is_draw_bg_image)
    {
        gdi_image_draw_id(0, 0, IMG_ID_BARCODEREADER_PREVIEW_BACKGROUND);
    }

    if (!g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.is_draw_bg_color &&
        !g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.is_draw_bg_image)
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_set_hint
 * DESCRIPTION
 *  set hint string
 * PARAMETERS
 *  hint_str1       [IN]        String 1
 *  hint_str2       [IN]        String 2
 *  fade_time       [IN]        Hint fade out time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear buffer */
    memset(g_barcodereader_cntx.hint1_buf, 0, BR_HINT_BUFFER_SIZE);
    memset(g_barcodereader_cntx.hint2_buf, 0, BR_HINT_BUFFER_SIZE);

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_barcodereader_cntx.hint1_buf, (PS8) hint_str1, (BR_HINT_BUFFER_SIZE/ENCODING_LENGTH)-1);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_barcodereader_cntx.hint2_buf, (PS8) hint_str2, (BR_HINT_BUFFER_SIZE/ENCODING_LENGTH)-1);
    }

    g_barcodereader_cntx.fade_time = fade_time;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_free_resource
 * DESCRIPTION
 *  free main lcd's preview layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.hint1_buf != NULL)
    {
    mmi_frm_scrmem_free((void*)g_barcodereader_cntx.hint1_buf);
    g_barcodereader_cntx.hint1_buf= NULL;
    }
    
    if (g_barcodereader_cntx.hint2_buf != NULL)
    {
    mmi_frm_scrmem_free((void*)g_barcodereader_cntx.hint2_buf);
    g_barcodereader_cntx.hint2_buf= NULL;
    }

   /****** free osd layer ******/
    if (g_barcodereader_cntx.osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        set_status_icon_bar_layer(0, GDI_ERROR_HANDLE);
        gdi_layer_free(g_barcodereader_cntx.osd_layer_handle);
        g_barcodereader_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_barcodereader_cntx.osd_layer_buf_ptr);
        g_barcodereader_cntx.osd_layer_buf_ptr = NULL;
    }

   /****** preview layer ******/
    mmi_barcodereader_free_preview_resource();
    g_barcodereader_cntx.is_mainlcd_resource = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_current_state
 * DESCRIPTION
 *  exit function handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_current_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_barcodereader_cntx.app_state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            /* do nothing */
            break;

        case MMI_BARCODEREADER_STATE_PREVIEW:
            mmi_barcodereader_exit_preview_state();
            break;

        case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
            mmi_barcodereader_exit_capture_and_decode_state();
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_state(barcodereader_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.app_prev_state = g_barcodereader_cntx.app_state;
    g_barcodereader_cntx.app_state = state;

    switch (state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            /* do nothing */
            break;

        case MMI_BARCODEREADER_STATE_PREVIEW:
            mmi_barcodereader_enter_preview_state();
            break;

        case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
            mmi_barcodereader_enter_capture_and_decode_state();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_free_preview_resource
 * DESCRIPTION
 *  create preview resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_free_preview_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.preview_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        return;
    }
    gdi_layer_free(g_barcodereader_cntx.preview_layer_handle);
    g_barcodereader_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_create_preview_resource
 * DESCRIPTION
 *  create preview resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_create_preview_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 buf_ptr;
    S32 buf_size;

    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /************ preview layer ************/
#ifdef __MMI_HORIZONTAL_BARCODEREADER__
    offset_x = MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y;
    offset_y = MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X;
#else /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    /* offset_y = (LCD_HEIGHT - g_barcodereader_cntx.preview_height)>>1; */
    offset_x = MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X;
    offset_y = MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y;
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 

    ASSERT(g_barcodereader_cntx.preview_width * g_barcodereader_cntx.preview_height <= LCD_WIDTH * LCD_HEIGHT);

    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);
    gdi_layer_get_buffer_ptr(&buf_ptr);

    /* if < MT 6227 **************************************************************** */
    /*  calculate the right buf_ptr position.                                       */
   /********************************************************************************/
    //      if(offset_x !=0 || offset_y !=0)
    //      {
    //              #ifdef HORIZONTAL_CAMERA
    //                      buf_ptr += ((offset_y*LCD_HEIGHT*GDI_LAYER.bits_per_pixel)>>3);
    //              #else
    //                      buf_ptr += ((offset_y*LCD_WIDTH*GDI_LAYER.bits_per_pixel)>>3);
    //              #endif
    //              buf_ptr += ((offset_x*GDI_LAYER.bits_per_pixel)>>3);
    //      }
    buf_size =
        ((g_barcodereader_cntx.preview_width * g_barcodereader_cntx.preview_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);
    gdi_layer_create_using_outside_memory(
        0,
        0,
        g_barcodereader_cntx.preview_width,
        g_barcodereader_cntx.preview_height,
        &g_barcodereader_cntx.preview_layer_handle,
        (PU8) buf_ptr,
        buf_size);
    
    gdi_layer_set_active(g_barcodereader_cntx.preview_layer_handle);
#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_set_position(offset_x, offset_y);
    gdi_layer_pop_and_restore_active();

}


static void mmi_barcoderader_malloc_memory_and_create_adm_resource(void)
{
    if (g_barcodereader_cntx.app_mem_pool==NULL)
    {
        g_barcodereader_cntx.app_mem_pool 
            = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BARCODEREADER, BR_APP_TOTAL_SIZE);
        
        if (g_barcodereader_cntx.app_mem_pool == NULL)
        {
            g_barcodereader_cntx.entry_app_callback = mmi_barcodereader_enter_preview_screen;
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_BARCODEREADER,
                IMG_ID_BARCODEREADER_APP_ICON,
                BR_APP_TOTAL_SIZE,
                mmi_barcodereader_app_mem_success_callback);
            return;
        }
        
    }
    
    /* create adm related resource */
    mmi_barcodereader_create_adm_resource();
}

static void mmi_barcoderader_free_memory_and_destory_adm_resource(void)
{
    mmi_barcodereader_free_adm_resource();
    
    ASSERT(g_barcodereader_cntx.app_mem_pool != NULL);
    
    /* free app-based memory */
    applib_mem_ap_free((void*)g_barcodereader_cntx.app_mem_pool);
    g_barcodereader_cntx.app_mem_pool = NULL;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_preview_state
 * DESCRIPTION
 *  entry of preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize preview data */

    switch (g_barcodereader_cntx.app_prev_state)
    {
        case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
            /* register keys */
            mmi_barcodereader_set_key_hdlr();

            /* draw panel and softkey */
            mmi_barcodereader_draw_osd();

            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            break;

            /* if enter from EXIT */
        case MMI_BARCODEREADER_STATE_EXIT:
            g_barcodereader_cntx.is_lsk_pressed = FALSE;
            g_barcodereader_cntx.is_rsk_pressed = FALSE;
            g_barcodereader_cntx.is_up_arrow_pressed = FALSE;
            g_barcodereader_cntx.is_down_arrow_pressed = FALSE;

            g_barcodereader_cntx.is_capturing = FALSE;
            g_barcodereader_cntx.is_draw_timer_on = FALSE;
        #ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
            g_barcodereader_cntx.is_mf_continue = FALSE;
        #endif
#ifndef __MMI_BARCODEREADER_OPERATOR1__
            g_barcodereader_cntx.touch_flash.is_press = FALSE;
            g_barcodereader_cntx.touch_ev_inc.is_press = FALSE;
            g_barcodereader_cntx.touch_ev_dec.is_press = FALSE;
            g_barcodereader_cntx.touch_mf_inc.is_press = FALSE;
            g_barcodereader_cntx.touch_mf_dec.is_press = FALSE;
            g_barcodereader_cntx.touch_capture.is_press = FALSE;
            g_barcodereader_cntx.touch_af_mode.is_press = FALSE;
#endif

            /* load mdi_camera default data */
    #ifdef CAMERA_MODULE_WITH_LCD
            gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    #endif 

    #ifdef __MMI_SUBLCD__
            /* draw sublcd icon */
            mmi_barcodereader_sublcd_draw_icon();
    #endif /* __MMI_SUBLCD__ */ 

            /* init title bar */
            if (g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_title_bar)
            {
            #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
                reset_title_status_icon();
                show_status_icon_bar(0);
            #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 

                /* hide short cut */
                MMI_menu_shortcut_number = -1;

                if (g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_caption)
                {
                    ChangeTitle(MAIN_MENU_TITLE_MULTIMEDIA_ICON, (PU8) GetString(STR_ID_BARCODEREADER_APP_NAME));
                }
                else
                {
                    ChangeTitle(0, (PU8) GetString(STR_ID_BARCODEREADER_APP_NAME));
                }
            }
            else
            {
            #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
                hide_status_icon_bar(0);
            #endif 
            }

            /* register keys */
            mmi_barcodereader_set_key_hdlr();

            /* clear base layer bg */
            mmi_barcodereader_preview_clear_background();

            /* draw panel and softkey */
            mmi_barcodereader_set_hint(NULL, NULL, 0);
            mmi_barcodereader_draw_osd();

            /* set blt layer for non-previwing, and blt first skin */
            mmi_barcodereader_preview_set_blt_layer(FALSE);
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            /* check if any error occurs in mmi_barcodereader_enter_preview_screen function */
            if (g_barcodereader_cntx.last_error.error_result != MDI_RES_CAMERA_SUCCEED)
            {
                mmi_barcodereader_display_error_popup();
                return;
            }
            else
            {
                /* if no error occurs, start preview */
                mmi_barcodereader_preview_set_blt_layer(TRUE);
                mmi_barcodereader_preview_start();
                #ifdef __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__          
                    #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
                        mmi_barcodereader_af_and_capture();
                    #else
                        gui_start_timer(200,mmi_barcodereader_capture_button_press);
                    #endif
                #endif
            }

            /* check if preview success */
            if (g_barcodereader_cntx.last_error.error_result != MDI_RES_CAMERA_SUCCEED)
            {
                mmi_barcodereader_display_error_popup();
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_set_key_hdlr
 * DESCRIPTION
 *  set key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_set_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    const U16 mmi_barcodereader_preview_all_key[] = 
    {
        MMI_BARCODEREADER_CAPTURE_KEY, 
        MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, 
        KEY_UP_ARROW,
        KEY_DOWN_ARROW,
        KEY_LEFT_ARROW,
        KEY_RIGHT_ARROW,
        MMI_BARCODEREADER_FOCUS_MODE_KEY,
        MMI_BARCODEREADER_FLASH_KEY,			
        MMI_BARCODEREADER_STORAGE_KEY,	
#ifdef MMI_BARCODEREADER_BANDING_KEY
        MMI_BARCODEREADER_BANDING_KEY,
#endif
#ifdef MMI_BARCODEREADER_EV_STATUS_KEY
        MMI_BARCODEREADER_EV_STATUS_KEY,
#endif
        KEY_LSK,
        KEY_RSK
    };
    const U16 mmi_barcodereader_capture_and_decode_all_key[] = 
    {
        MMI_BARCODEREADER_CAPTURE_KEY, 
        MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, 
        KEY_LSK,
        KEY_RSK
    };
#define MMI_BARCODEREADER_PREVIEW_KEY_COUNT  (sizeof(mmi_barcodereader_preview_all_key)/\
    sizeof(mmi_barcodereader_preview_all_key[0]))
#define MMI_BARCODEREADER_CAPTURE_AND_DECODE_KEY_COUNT  (sizeof(mmi_barcodereader_capture_and_decode_all_key)/\
                                                sizeof(mmi_barcodereader_capture_and_decode_all_key[0]))
    PU16 current_keymap;
    U8   current_key_count;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE)
    {
        current_keymap = (PU16)mmi_barcodereader_capture_and_decode_all_key;
        current_key_count = MMI_BARCODEREADER_CAPTURE_AND_DECODE_KEY_COUNT;
    }
    else
    {
        current_keymap = (PU16)mmi_barcodereader_preview_all_key;
        current_key_count = MMI_BARCODEREADER_PREVIEW_KEY_COUNT;
    }

    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();

    SetGroupKeyHandler(
        mmi_barcodereader_key_hdlr, 
        (PU16)current_keymap, 
        current_key_count, 
        KEY_EVENT_DOWN);
    SetGroupKeyHandler(
        mmi_barcodereader_key_hdlr, 
        (PU16)current_keymap, 
        current_key_count, 
        KEY_EVENT_UP);
    SetGroupKeyHandler(
        mmi_barcodereader_key_hdlr, 
        (PU16)current_keymap, 
        current_key_count, 
        KEY_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_display_error_popup
 * DESCRIPTION
 *  display a popup error message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_display_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    U8 tone_id = WARNING_TONE;
    U16 image_id = IMG_GLOBAL_WARNING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if has error */

    ClearAllKeyHandler();
    switch (g_barcodereader_cntx.last_error.error_type)
    {
    case MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA:
        string_id = mmi_camera_get_error_string_by_error_enum(g_barcodereader_cntx.last_error.error_result);
        tone_id = ERROR_TONE;
        image_id = IMG_GLOBAL_ERROR;
        break;
        
    case MMI_BARCODEREADER_ERROR_TYPE_FROM_FS:
        string_id = GetFileSystemErrorString(g_barcodereader_cntx.last_error.error_result);
        tone_id = ERROR_TONE;
        image_id = IMG_GLOBAL_ERROR;
        break;
        
    case MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER:
        string_id = mmi_barcodereader_get_error_string(g_barcodereader_cntx.last_error.error_result);
        break;
    
    default:
        string_id = STR_GLOBAL_ERROR;
        break;
    }

    if (string_id == MMI_BARCODEREADER_ERROR_ENCODING_ERROR)
    {
        DeleteUptoScrID(SCR_ID_BARCODEREADER_MAIN);
    }
    
    #if defined(__MMI_HORIZONTAL_BARCODEREADER__)
        DisplayPopupRotated(
            (PU8) GetString(string_id),
            image_id,
            1,
            ST_NOTIFYDURATION,
            tone_id,
            g_barcodereader_cntx.osd_rotate);
    #else /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
        DisplayPopup((PU8) GetString(string_id), image_id, 1, ST_NOTIFYDURATION, tone_id);
    #endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

        if ((g_barcodereader_cntx.last_error.error_result == MMI_BARCODEREADER_ERR_PHONE_DISK_FULL)
            || (g_barcodereader_cntx.last_error.error_result == MMI_BARCODEREADER_ERR_CARD_DISK_FULL)
            || (g_barcodereader_cntx.last_error.error_result == MMI_BARCODEREADER_ERR_ROOT_DIR_FULL))
        {
            return;
        }
        else if (g_barcodereader_cntx.last_error.error_result == MDI_RES_CAMERA_ERR_HW_NOT_READY)
        {
           DeleteNHistory(1);
        }
        g_barcodereader_cntx.last_error.error_result = MDI_RES_CAMERA_SUCCEED;
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_set_blt_layer
 * DESCRIPTION
 *  set blt layer based on current status (ex: is previwing, has add frame, etc )
 * PARAMETERS
 *  is_previewing       [IN]        Is preview flag
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_set_blt_layer(BOOL is_previewing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (is_previewing)
    {
        /* (1) previwing */
    #if (MDI_CAMERA_MT6219_SERIES)
        gdi_layer_set_blt_layer(
            g_barcodereader_cntx.base_layer_handle,
            g_barcodereader_cntx.preview_layer_handle,
            g_barcodereader_cntx.osd_layer_handle,
            0);
    #else /* MDI_CAMERA_MT6219_SERIES */
        gdi_layer_set_blt_layer(g_barcodereader_cntx.preview_layer_handle, g_barcodereader_cntx.osd_layer_handle, 0, 0);

    #endif /* MDI_CAMERA_MT6219_SERIES */ 
    }
    else
    {
        gdi_layer_set_blt_layer(g_barcodereader_cntx.base_layer_handle, g_barcodereader_cntx.osd_layer_handle, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_preview_state
 * DESCRIPTION
 *  exit of preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free preview resource */
    switch (g_barcodereader_cntx.app_next_state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            mmi_barcodereader_preview_stop();
            break;
    }
}

#if defined(__MMI_BARCODEREADER_AF_SUPPORT__) && defined(__MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_re_focus_press
 * DESCRIPTION
 *  do focus process again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_re_focus_press(void)
{
    mmi_barcodereader_capture_button_press();
    mmi_barcodereader_af_and_capture();
}
#endif


#if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_start_capture_and_decode
 * DESCRIPTION
 *  entry of capture_and_decode state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_start_capture_and_decode(void)
{
    mdi_camera_capture_and_decode_barcode(
        g_barcodereader_cntx.decode_text,
        BR_VERSION_ONE_SLOT_BUFFER_SIZE - ENCODING_LENGTH,
        mmi_barcodereader_decode_result_hdlr,
        MDI_CAMERA_BARCODE_TYPE_QR);

#ifdef __MMI_BARCODEREADER_OPERATOR1__
    g_barcodereader_cntx.b_stop_decode = MMI_TRUE;
    gui_start_timer(MMI_BARCODEREADER_DECODE_INTERVAL, mmi_barcodereader_decode_listen_hdlr);
#endif

    mmi_barcodereader_set_key_hdlr();
    g_barcodereader_cntx.is_capturing = TRUE;
    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_capture_and_decode_state
 * DESCRIPTION
 *  entry of capture_and_decode state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_capture_and_decode_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_barcodereader_cntx.app_prev_state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            ASSERT(g_barcodereader_cntx.app_prev_state != MMI_BARCODEREADER_STATE_EXIT);
            break;

        case MMI_BARCODEREADER_STATE_PREVIEW:
            memset(g_barcodereader_cntx.decode_text, 0, BR_VERSION_ONE_SLOT_BUFFER_SIZE);

            #if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
                mmi_barcodereader_set_hint((PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE), NULL, HINT_POPUP_FADE_TIME);
                mmi_barcodereader_start_capture_and_decode();
                mmi_barcodereader_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_barcodereader_cntx.base_UI_device_width - 1,
                    g_barcodereader_cntx.base_UI_device_height - 1);
                return;
            #else
            mdi_camera_capture_and_decode_barcode(
                g_barcodereader_cntx.decode_text,
                BR_VERSION_ONE_SLOT_BUFFER_SIZE-ENCODING_LENGTH,
                mmi_barcodereader_decode_result_hdlr,
                MDI_CAMERA_BARCODE_TYPE_QR);
#ifdef __MMI_BARCODEREADER_OPERATOR1__
            g_barcodereader_cntx.b_stop_decode = MMI_TRUE;
            gui_start_timer(MMI_BARCODEREADER_DECODE_INTERVAL, mmi_barcodereader_decode_listen_hdlr);
#endif
            g_barcodereader_cntx.is_capturing = TRUE;
            #endif

            /* due to manual AF */
        #if defined(__MMI_BARCODEREADER_FOCUS_MODE__) && defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
            if (g_barcodereader_cntx.setting.af_mode == MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL)
            {
                mmi_barcodereader_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_barcodereader_cntx.base_UI_device_width - 1,
                    g_barcodereader_cntx.base_UI_device_height - 1);
            }           
        #endif
            mmi_barcodereader_set_key_hdlr();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_capture_and_decode_state
 * DESCRIPTION
 *  exit of capture_and_decode state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_capture_and_decode_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_barcodereader_cntx.app_next_state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            g_barcodereader_cntx.is_capturing = FALSE;
            mmi_barcodereader_preview_stop();

    #if (MDI_CAMERA_MT6227_SERIES||MDI_CAMERA_MT6228_SERIES)
            gdi_layer_flatten_to_base(
                g_barcodereader_cntx.preview_layer_handle,
                g_barcodereader_cntx.osd_layer_handle,
                0,
                0);
    #else /*(MDI_CAMERA_MT6227_SERIES||MDI_CAMERA_MT6228_SERIES)*/ 
            gdi_layer_flatten_to_base(
                g_barcodereader_cntx.base_layer_handle,
                g_barcodereader_cntx.preview_layer_handle,
                g_barcodereader_cntx.osd_layer_handle,
                0);
    #endif /*(MDI_CAMERA_MT6227_SERIES||MDI_CAMERA_MT6228_SERIES)*/ 
            break;
        case MMI_BARCODEREADER_STATE_PREVIEW:
            mdi_camera_stop_capture_and_decode_barcode();
            g_barcodereader_cntx.is_capturing = FALSE;
            break;
    }
}

#ifdef __MMI_HORIZONTAL_BARCODEREADER__


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_sensor_orientation
 * DESCRIPTION
 *  check sensor orientation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_check_sensor_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate base layer */
    gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_270);
    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);
    gdi_layer_resize(LCD_HEIGHT, LCD_WIDTH);
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_osd_orientation
 * DESCRIPTION
 *  check sensor orientation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_check_osd_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.previous_osd_rotate != g_barcodereader_cntx.osd_rotate)
    {
        switch (g_barcodereader_cntx.osd_rotate)
        {
            case MMI_BARCODEREADER_OSD_ROTATE_0:
                g_barcodereader_cntx.active_barcodereader_osd_ptr = &g_barcodereader_osd_cntx;
                g_barcodereader_cntx.osd_UI_device_height = LCD_HEIGHT;
                g_barcodereader_cntx.osd_UI_device_width = LCD_WIDTH;
                gdi_layer_push_and_set_active(g_barcodereader_cntx.osd_layer_handle);
                gdi_layer_toggle_double();
                gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_270);
                gdi_layer_resize(g_barcodereader_cntx.osd_UI_device_width, g_barcodereader_cntx.osd_UI_device_height);
                gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
                break;

            case MMI_BARCODEREADER_OSD_ROTATE_270:
                g_barcodereader_cntx.active_barcodereader_osd_ptr = &g_barcodereader_osd_cntx_270;
                g_barcodereader_cntx.osd_UI_device_height = LCD_WIDTH;
                g_barcodereader_cntx.osd_UI_device_width = LCD_HEIGHT;
                gdi_layer_push_and_set_active(g_barcodereader_cntx.osd_layer_handle);
                gdi_layer_toggle_double();
                gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
                gdi_layer_resize(g_barcodereader_cntx.osd_UI_device_width, g_barcodereader_cntx.osd_UI_device_height);
                gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
                break;

            default:
                ASSERT(0);
                break;
        }

        g_barcodereader_cntx.previous_osd_rotate = g_barcodereader_cntx.osd_rotate;

    }

}
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_encoding_type
 * DESCRIPTION
 *  check if the lrc is an Unicode encoded file or the user specified encoded file.
 * PARAMETERS
 *  str     [IN]        Pointer to the text source.
 * RETURNS
 *  a mmi_chset_enum that sprcifies UTF8/UCS2/User Specified  encoded type.
 *****************************************************************************/
static mmi_chset_enum mmi_barcodereader_get_encoding_type(const S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str[0] == (S8) 0xEF && str[1] == (S8) 0xBB && str[2] == (S8) 0xBF)
    {
        return MMI_CHSET_UTF8;
    }
    else if (str[0] == (S8) 0xFE && str[1] == (S8) 0xFF)
    {
        return MMI_CHSET_UCS2;
    }
    else if (str[0] == (S8) 0xFF && str[1] == (S8) 0xFE)
    {
        return MMI_CHSET_UCS2;
    }
    else
    {
        return PhnsetGetDefEncodingType();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_preview_screen
 * DESCRIPTION
 *  entry barcodereader application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_enter_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /***************************************************
     * Do not remove this section <START>
     ***************************************************/
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    /* if usb is plugged in , then forbid to entry the barcode reader*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        
        if (mmi_usb_check_path_exported((PS8) MMI_BARCODEREADER_STORAGE_FILEPATH_PHONE))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    /* allocate memory from App-Based ASM , and create adm related resource*/
    mmi_barcoderader_malloc_memory_and_create_adm_resource();
    if (g_barcodereader_cntx.app_mem_pool == NULL)
    {   
        return;
    }

#endif

    /***************************************************
     * Do not remove this section <END>
     ***************************************************/

    MMI_BARCODEREADER_CHECK_STATE(MMI_BARCODEREADER_STATE_EXIT);

    /* entry new screen */
    EntryNewScreen(
        SCR_ID_BARCODEREADER_PREVIEW,
        mmi_barcodereader_exit_preview_screen,
        mmi_barcodereader_enter_preview_screen,
        MMI_FULL_SCREEN);
#ifndef  __MMI_BARCODEREADER_OPERATOR1__
    SetDelScrnIDCallbackHandler(SCR_ID_BARCODEREADER_PREVIEW, mmi_barcodereader_del_scr_callback);
#endif

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_PREVIEW);

#ifdef __MMI_BARCODEREADER_STORAGE__
    if (g_barcodereader_cntx.is_storage_ready == FALSE)
    {
        mmi_barcodereader_entry_storage_screen();
        return ;
    }
#endif
    
    /************ init/config framework's environment  ************/
    mmi_barcodereader_init_framework();
      
    /************ init camera app environment *********************/
    mmi_barcodereader_init_camera();
    
    /* load Setting */
    mmi_barcodereader_load_setting();

    /* allocate storage path buffer */
    g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    g_barcodereader_cntx.storage_filepath[0] = 0;

    /* check if restore path is ready or not */
    mmi_barcodereader_check_restore_path();

    /* each time newly enter camera, do anything ... ? */
    if (guiBuffer == NULL)
    {
        g_barcodereader_cntx.zoom_idx = MMI_BARCODEREADER_DEFAULT_SETTING_ZOOM_IDX;
        g_barcodereader_cntx.is_append_qrcode = FALSE;
        g_barcodereader_cntx.symbol_masks = 0;
        g_barcodereader_cntx.symbol_count = 1;
    }


    /* power on and init hardware module */
    g_barcodereader_cntx.is_camera_powered_on = MMI_FALSE;
    if (g_barcodereader_cntx.last_error.error_result == MDI_RES_CAMERA_SUCCEED)
    {
        g_barcodereader_cntx.is_camera_powered_on = MMI_TRUE;
        g_barcodereader_cntx.last_error.error_result = mdi_camera_power_on();
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA;
    }

    /* create preview resource */
    mmi_barcodereader_create_resource();

    /* we always use LCD rotate */
    gdi_lcd_set_rotate_by_layer(TRUE);

#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    g_barcodereader_cntx.previous_osd_rotate = MMI_BARCODEREADER_OSD_ROTATE_RESET;
    mmi_barcodereader_check_sensor_orientation();       /* turn the base layer*/
    mmi_barcodereader_check_osd_orientation();          /* turn the osd layer*/

#if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)
    /* mmi_camera_update_osd_touch_icon(); */
#endif 
#endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

    /* check if there is small screen above camera */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    if (g_barcodereader_cntx.last_error.error_result == MDI_RES_CAMERA_SUCCEED)
    {
        /* check flash status */
        mmi_barcodereader_check_flash_status();     /*turn on/off the flash */
    }

#ifdef __MMI_TVOUT__
    /* since someone change lcd/lcm rotate mechanism (gdi_lcd_set_rotate_by_layer()), 
       we must call this function to change driver's mode */
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);  /*the same with lcd*/
    }
#endif /* __MMI_TVOUT__ */ 



    /************ enter preview state ************/
    /* no error, if has error, will enter main then show error popup */
    if (g_barcodereader_cntx.last_error.error_result == MDI_RES_CAMERA_SUCCEED)
    {
        MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_PREVIEW);
        
#if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)
        wgui_register_pen_down_handler(mmi_barcodereader_touch_scr_pen_down_hdlr);
        wgui_register_pen_up_handler(mmi_barcodereader_touch_scr_pen_up_hdlr);
        wgui_register_pen_move_handler(mmi_barcodereader_touch_scr_pen_move_hdlr);
#endif /* defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__) */     
    }
    else
    {
        mmi_barcodereader_display_error_popup();
    }
}


static void mmi_barcodereader_init_framework(void)
{
    /* entry full screen app */
    entry_full_screen();
    
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    
    /* stop bg music */
    mdi_audio_suspend_background_play();
    
    /* 
     * This is used to solve a very rare situation. When playing a IMELODY 
     * with backlight on/off, and the screen previous to this screen is a 
     * horizontal screen. Before enter this screen, the IMELODY turn off the
     * backlight. While exit previous screen, the layer rotate back to normal
     * size and the content is not correct. So when calling TurnOnBacklight, 
     * LCD is in sleepin state and draw wrong content to LCD.
     * So we need to clear the buffer first to avoid this situation.
     */
    gdi_layer_clear(GDI_COLOR_BLACK);

    /* stop MMI sleep */
    TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* stop LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_GET);

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

   /*********** init layer var ************/
    /* get mainlcd based layer handle */
    gdi_layer_get_base_handle(&g_barcodereader_cntx.base_layer_handle);

    /* get sublcd base layer handle */

#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&g_barcodereader_cntx.sublcd_base_layer_handle);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */ 

   /************ draw sublcd and hook msg hdlr ************/
#ifdef __MMI_SUBLCD__
    /* entry sublcd */
    if (!g_barcodereader_cntx.is_sublcd_display)
    {
        ForceSubLCDScreen(mmi_barcodereader_enter_sublcd_screen);
    }
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_BARCODEREADER_OPERATOR1__
    g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_title_bar = MMI_TRUE;
    g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_caption = MMI_TRUE;
#else
    g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_title_bar = MMI_FALSE;
    g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_caption = MMI_FALSE;
#endif

}


static void mmi_barcodereader_init_camera(void)
{
    /* init some flags */
    g_barcodereader_cntx.last_error.error_result = MDI_RES_CAMERA_SUCCEED;
    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA;
    g_barcodereader_cntx.lcm_rotate = MMI_BARCODEREADER_LCM_MAINLCD_ROTATE;
    
#ifdef __MMI_HORIZONTAL_BARCODEREADER__
    g_barcodereader_cntx.preview_height = MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH;
    g_barcodereader_cntx.preview_width = MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT;
#else /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    g_barcodereader_cntx.preview_height = MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT;
    g_barcodereader_cntx.preview_width = MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH;
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    
#ifdef __MMI_HORIZONTAL_BARCODEREADER__     /* preview area */
    g_barcodereader_cntx.image_width = MMI_BARCODEREADER_IMAGE_HEIGHT;
    g_barcodereader_cntx.image_height = MMI_BARCODEREADER_IMAGE_WIDTH;
#else /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    g_barcodereader_cntx.image_width = MMI_BARCODEREADER_IMAGE_WIDTH;
    g_barcodereader_cntx.image_height = MMI_BARCODEREADER_IMAGE_HEIGHT;
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    
#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_IDLE;
    g_barcodereader_cntx.is_af_capture = FALSE;
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_create_resource
 * DESCRIPTION
 *  create layer resource
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_barcodereader_create_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_barcodereader_cntx.is_mainlcd_resource == FALSE);
    /* if main lcd resoruce is not created */

    g_barcodereader_cntx.hint1_buf= (S8*)mmi_frm_scrmem_alloc(BR_HINT_BUFFER_SIZE);
    ASSERT(g_barcodereader_cntx.hint1_buf!= NULL);
    g_barcodereader_cntx.hint2_buf= (S8*)mmi_frm_scrmem_alloc(BR_HINT_BUFFER_SIZE);
    ASSERT(g_barcodereader_cntx.hint2_buf!= NULL);

    memset(g_barcodereader_cntx.hint1_buf, 0, BR_HINT_BUFFER_SIZE);
    memset(g_barcodereader_cntx.hint2_buf, 0, BR_HINT_BUFFER_SIZE);

   /************ base layer ************/
    /* get both MainLCD and SubLCD base handle */
    gdi_layer_get_base_handle(&g_barcodereader_cntx.base_layer_handle);

    /* clear fullscreen */
    gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
#endif 

   /************ osd layer ************/
    g_barcodereader_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc(BR_SCR_OSD_SIZE);
    ASSERT(g_barcodereader_cntx.osd_layer_buf_ptr != NULL);

    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_barcodereader_cntx.osd_layer_handle,
        (PU8) g_barcodereader_cntx.osd_layer_buf_ptr,
        (S32) (BR_SCR_OSD_SIZE));

    set_status_icon_bar_layer(0, g_barcodereader_cntx.osd_layer_handle);
    gdi_layer_push_and_set_active(g_barcodereader_cntx.osd_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

   /************ preview layer ***********/
    mmi_barcodereader_create_preview_resource();

    g_barcodereader_cntx.is_mainlcd_resource = TRUE;
    return g_barcodereader_cntx.is_mainlcd_resource;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_restore_path
 * DESCRIPTION
 *  check barcodereader application restore path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_check_restore_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_storage;
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if path is valid or not. if not will pop up a screen after the preview screen is show */
    cur_storage = g_barcodereader_cntx.setting.storage;

    if (mmi_barcodereader_check_and_restore_valid_drv())
    {
        /* drv is valid, create directory */
        mmi_barcodereader_get_storage_file_path((PS8)g_barcodereader_cntx.storage_filepath);
        create_result = mmi_barcodereader_create_file_dir((PS8)g_barcodereader_cntx.storage_filepath);

        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            g_barcodereader_cntx.last_error.error_result = FS_WRITE_PROTECTION;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
            g_barcodereader_cntx.is_storage_ready = FALSE;
            /* has error - restore to phone */
            g_barcodereader_cntx.setting.storage = (U16)MMI_PUBLIC_DRV;
            g_barcodereader_cntx.is_storage_path_changed = TRUE;
        }
        else if (create_result == FS_DISK_FULL)
        {

                g_barcodereader_cntx.last_error.error_result = FS_DISK_FULL;
                g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;


                /* has error - restore to phone */
            g_barcodereader_cntx.is_storage_ready = FALSE;
                g_barcodereader_cntx.is_storage_path_changed = TRUE;
            
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
                g_barcodereader_cntx.last_error.error_result = FS_ROOT_DIR_FULL;
                g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;

                /* has error - restore to phone */
            g_barcodereader_cntx.is_storage_ready = FALSE;
                g_barcodereader_cntx.is_storage_path_changed = TRUE;
            }

    }
    else
    {
        /* no any storage */

        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_NO_STORAGE;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
            
            g_barcodereader_cntx.is_storage_ready = FALSE;
        }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_and_restore_valid_drv
 * DESCRIPTION
 *  Check if desired path is ready or not. If not, will restore to valid path.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_barcodereader_check_and_restore_valid_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR == FS_GetDevStatus(g_barcodereader_cntx.setting.storage, FS_MOUNT_STATE_ENUM))
        return TRUE;
    else
    {
        g_barcodereader_cntx.setting.storage = (U16) MMI_PUBLIC_DRV;
        if (FS_NO_ERROR == FS_GetDevStatus(g_barcodereader_cntx.setting.storage ,FS_MOUNT_STATE_ENUM))
        {
            g_barcodereader_cntx.is_storage_path_changed = TRUE;
            mmi_barcodereader_store_setting();
            return TRUE;
        }
        else
        {
            PRINT_INFORMATION_2(
                MMI_TRACE_G8_MEDIA, 
                "barcodereader storage error in mmi_barcodereader_check_and_restore_valid_drv\n");

            return FALSE;
        }
    }
}

/*****************************************************************************
*
* touch screen support 
*
*****************************************************************************/
#if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_touch_scr_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen down
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    /* other screen use generic touch screen handler */
    if (!g_barcodereader_cntx.active_barcodereader_osd_ptr->softkey.is_draw_mmi_softkey)
    {
        /* LSK */
        if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_lsk) == MMI_TRUE)
        {
            switch (g_barcodereader_cntx.app_state)
            {
                    /* main lcd */
                case MMI_BARCODEREADER_STATE_PREVIEW:
                case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
                    mmi_barcodereader_lsk_press();
                    break;
            }
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_LSK;
            return;
        }

        /* RSK */
        if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_rsk) == MMI_TRUE)
        {
            switch (g_barcodereader_cntx.app_state)
            {
                    /* main lcd */
                case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
                case MMI_BARCODEREADER_STATE_PREVIEW:
                    mmi_barcodereader_rsk_press();
                    break;
            }
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_RSK;
            return;
        }

    }
    else
    {
        if (wgui_test_lsk_position(pos) == MMI_TRUE)
        {
            /* draw clicked lsk */
            mmi_barcodereader_lsk_press();
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_LSK;
            return;
        }
        if (wgui_test_rsk_position(pos) == MMI_TRUE)
        {
            /* draw clicked rsk */
            mmi_barcodereader_rsk_press();
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_RSK;
            return;
        }
    }
    /* while af is calculating, disable touch panel */
#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_CALCULATE)    /* || g_barcodereader_cntx.is_autofocus_pressed ==TRUE) */
    {
        g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_NONE;
        return;
    }
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 

    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW && g_barcodereader_cntx.is_capturing == FALSE)
    {
        /* osd test */
#define MMI_BARCODEREADER_OSD_ICON_TOUCH_TEST(a,A)                                                             \
      do {                                                                                                       \
         if(g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.is_show)                                    \
         {                                                                                                       \
            if(mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_##a##) == MMI_TRUE)\
            {                                                                                                    \
               mmi_barcodereader_##a##_hotkey_press();                                                           \
               g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_##A;                                      \
               return;                                                                                           \
            }                                                                                                    \
         }                                                                                                       \
      } while(0);

        if (!g_barcodereader_cntx.is_hide_osd)
        {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
        #ifdef __MMI_BARCODEREADER_FLASH__
            MMI_BARCODEREADER_OSD_ICON_TOUCH_TEST(flash, FLASH);
        #endif 

        #ifdef __MMI_BARCODEREADER_FOCUS_MODE__
            MMI_BARCODEREADER_OSD_ICON_TOUCH_TEST(af_mode, FOCUS_MODE);
        #endif 

        #ifdef __MMI_BARCODEREADER_STORAGE__
            MMI_BARCODEREADER_OSD_ICON_TOUCH_TEST(storage, STORAGE);
        #endif 
#endif
            /* ev inc test */
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_inc) == MMI_TRUE)
            {
                //mmi_barcodereader_ev_inc_key_press();
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_INC);
                g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_EV_INC;
                return;
            }

            /* ev dec test */
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_dec) == MMI_TRUE)
            {
                //mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_INC);                //mmi_barcodereader_ev_dec_key_press();
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_DEC);
                g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_EV_DEC;
                return;
            }

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
        }

    }

    #ifdef __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__
        /* capture */
        #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
        if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_capture) == MMI_TRUE)
        {
            //mmi_barcodereader_capture_button_press();
            /* capture */
            //mmi_barcodereader_af_and_capture();
            mmi_barcodereader_re_focus_press();
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_CAPTURE;
            return;
        }
        #endif
    #else
        /* capture */
        if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_capture) == MMI_TRUE)
        {
            if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
            {
                /* capture */
            #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
                mmi_barcodereader_af_and_capture();
            #else 
                mmi_barcodereader_capture_button_press();
            #endif 
            }
            else if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE)
            {
                mmi_barcodereader_capture_button_press();
            }

            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_CAPTURE;
            return;
        }
    #endif

    g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_touch_scr_pen_up_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen up
 * PARAMETERS
 *  pos     [IN]        Pen up position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    switch (g_barcodereader_cntx.touch_object)
    {
        case MMI_BARCODEREADER_TOUCH_LSK:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_lsk) == MMI_TRUE)
            {
                switch (g_barcodereader_cntx.app_state)
                {
                        /* main lcd */
                    case MMI_BARCODEREADER_STATE_PREVIEW:
                    case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
                        mmi_barcodereader_lsk_release();
                        break;

                }
            }
            break;

        case MMI_BARCODEREADER_TOUCH_RSK:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_rsk) == MMI_TRUE)
            {
                switch (g_barcodereader_cntx.app_state)
                {
                        /* main lcd */
                    case MMI_BARCODEREADER_STATE_PREVIEW:
                    case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
                        mmi_barcodereader_rsk_release();
                        break;
                }
            }
            break;

        case MMI_BARCODEREADER_TOUCH_EV_INC:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_inc) == MMI_TRUE)
            {
                //mmi_barcodereader_ev_inc_key_release();
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_INC);
            }
            break;

        case MMI_BARCODEREADER_TOUCH_EV_DEC:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_dec) == MMI_TRUE)
            {
                //mmi_barcodereader_ev_dec_key_release();
                mmi_barcodereader_ev_status_revert(MMI_BARCODEREADER_EV_STATUS_DEC);
            }
            break;
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
#endif
        case MMI_BARCODEREADER_TOUCH_CAPTURE:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_capture) == MMI_TRUE)
            {
                mmi_barcodereader_capture_button_release();
            }
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_touch_scr_pen_move_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen move
 * PARAMETERS
 *  pos     [IN]        Pen move position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL softkey_pressed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    softkey_pressed = FALSE;
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    switch (g_barcodereader_cntx.touch_object)
    {
        case MMI_BARCODEREADER_TOUCH_LSK:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_lsk))
            {
                softkey_pressed = TRUE;
            }
            else
            {
                softkey_pressed = FALSE;
            }

            if (softkey_pressed != g_barcodereader_cntx.is_lsk_pressed)
            {
                g_barcodereader_cntx.is_lsk_pressed = softkey_pressed;
                mmi_barcodereader_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_barcodereader_cntx.base_UI_device_width - 1,
                    g_barcodereader_cntx.base_UI_device_height - 1);
            }
            break;

        case MMI_BARCODEREADER_TOUCH_RSK:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_rsk))
            {
                softkey_pressed = TRUE;
            }
            else
            {
                softkey_pressed = FALSE;
            }

            if (softkey_pressed != g_barcodereader_cntx.is_rsk_pressed)
            {
                g_barcodereader_cntx.is_rsk_pressed = softkey_pressed;
                mmi_barcodereader_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_barcodereader_cntx.base_UI_device_width - 1,
                    g_barcodereader_cntx.base_UI_device_height - 1);
            }
            break;

        case MMI_BARCODEREADER_TOUCH_EV_INC:
            if (!mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_inc))
            {
                /* move out, treat as key release */
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_INC);
                //mmi_barcodereader_ev_inc_key_release();
            }
            break;

        case MMI_BARCODEREADER_TOUCH_EV_DEC:
            if (!mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_dec))
            {
                /* move out, treat as key release */
                //mmi_barcodereader_ev_dec_key_release();
                mmi_barcodereader_ev_status_change(MMI_BARCODEREADER_EV_STATUS_DEC);
            }
            break;
#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
        case MMI_BARCODEREADER_TOUCH_MF_INC:
            if (!mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_mf_inc))
            {
                /* move out, treat as key release */
                mmi_barcodereader_up_arrow_release();
            }
            break;

        case MMI_BARCODEREADER_TOUCH_MF_DEC:
            if (!mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_mf_dec))
            {
                /* move out, treat as key release */
                mmi_barcodereader_down_arrow_release();
            }
#endif
            break;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_touch_scr_hit_test
 * DESCRIPTION
 *  test if is within touch region
 * PARAMETERS
 *  pos_x           [IN]        Position x
 *  pos_y           [IN]        Position y
 *  touch_obj       [?]         
 *  touch(?)        [IN]        Touch object structure
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_barcodereader_touch_scr_hit_test(S32 pos_x, S32 pos_y, barcodereader_ui_touch_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif /* defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__) */ 

#if defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_forward
 * DESCRIPTION
 *  mf forward once
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
        && (g_barcodereader_cntx.mf_level_idx < g_barcodereader_cntx.mf_level_cnt))
    {
        g_barcodereader_cntx.mf_level_idx++;
        g_barcodereader_cntx.touch_mf_inc.is_press = TRUE;

        mdi_camera_mf_forward();
        mmi_barcodereader_set_hint(NULL, NULL, 0);
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

        if (!g_barcodereader_cntx.is_up_arrow_pressed)
        {
            gui_start_timer(200, mmi_barcodereader_mf_forward_continue);
        }
    }
    else if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        g_barcodereader_cntx.touch_mf_inc.is_press = FALSE;
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_backward
 * DESCRIPTION
 *  mf backward once
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_backward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW) && (g_barcodereader_cntx.mf_level_idx > 0))
    {
        g_barcodereader_cntx.mf_level_idx--;
        g_barcodereader_cntx.touch_mf_dec.is_press = TRUE;
        mdi_camera_mf_backward();
        mmi_barcodereader_set_hint(NULL, NULL, 0);
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

        if (!g_barcodereader_cntx.is_down_arrow_pressed)
        {
            gui_start_timer(200, mmi_barcodereader_mf_backward_continue);
        }
    }
    else if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        g_barcodereader_cntx.touch_mf_dec.is_press = FALSE;
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_stop
 * DESCRIPTION
 *  stop mf action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_stop_mf_continue();
    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
    g_barcodereader_cntx.is_mf_continue = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_forward_continue
 * DESCRIPTION
 *  start mf forward continue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_forward_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_mf_continue = TRUE;
    mdi_camera_start_mf_continue(TRUE);
    g_barcodereader_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_barcodereader_draw_osd_timer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_backward_continue
 * DESCRIPTION
 *  start mf backward continue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_backward_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_mf_continue = TRUE;
    mdi_camera_start_mf_continue(FALSE);
    g_barcodereader_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_barcodereader_draw_osd_timer);
}


#endif /* defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__) */ 



static void mmi_barcodereader_copy_from_unicode_to_unicode(U16 which, U8* dest, S32 length)
{
    U32 current_len = 0;

    if(g_barcodereader_cntx.app_content.ct_element[which].str_addr!=NULL)                                                                                                     
    {                                                                                                                                                                 
        current_len = g_barcodereader_cntx.app_content.ct_element[which].length;
        if (current_len > length)
        {
            current_len = length;
        }
        mmi_ucs2ncpy(
            (S8*)dest, 
            g_barcodereader_cntx.app_content.ct_element[which].str_addr,
            current_len);  
        memset (dest + current_len * ENCODING_LENGTH, 0 , 2);
    }   
}


/*****************************************************************************
* FUNCTION
*  mmi_barcodereader_callback
* DESCRIPTION
*  callback function which will be called from categoryscreen
* PARAMETERS
*  selected_idx        [IN]        The index of the selected highlight item
* RETURNS
*  void
*****************************************************************************/
static void mmi_barcodereader_callback(S32 selected_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.selected_hilight_idx = selected_idx;
}


#ifndef __MMI_BARCODEREADER_OPERATOR1__
static void mmi_barcodereader_entry_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bufferSize;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BARCODEREADER_EDITOR, mmi_barcodereader_exit_editor_screen, mmi_barcodereader_entry_editor_screen, NULL);

    /* allocate storage path buffer */
    g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_barcodereader_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    mmi_barcodereader_get_storage_file_path((PS8)g_barcodereader_cntx.storage_filepath);


    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_EDITOR);
    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

    if (guiBuffer == NULL)
    {
        g_barcodereader_cntx.selected_hilight_idx = 0;
    }

    g_barcodereader_cntx.app_list_idx_count = g_barcodereader_cntx.app_list_idx;

    ShowCategory228Screen(
        STR_ID_BARCODEREADER_APP_NAME,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_barcodereader_cntx.formatted_text_buf,
        bufferSize,
        g_barcodereader_cntx.app_content.ct_element,
        (U16) g_barcodereader_cntx.app_list_idx,
        mmi_barcodereader_callback,
        guiBuffer);
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---total highlight count = %d---*\n",
                         g_barcodereader_cntx.app_list_idx);

    SetLeftSoftkeyFunction(mmi_barcodereader_forward_to_apps, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_editor_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_editor_screen(void)
{
    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_exit
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteNHistory(1);
    GoBackHistory();
}

#endif


#ifdef __MMI_BARCODEREADER_STORAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_highlight_storage_hdlr
 * DESCRIPTION
 *  entry storage screen highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_highlight_storage_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_menu_cntx.storage_selected = idx;
    SetLeftSoftkeyFunction(mmi_barcodereader_set_storage_value, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_set_storage_value, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}

 /*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_settings
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_highlight_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_barcodereader_enter_setting_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_enter_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_entry_storage_screen
 * DESCRIPTION
 *  entry storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_entry_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_list[FMGR_TOTAL_STORAGE];
    PU8 pop_ptr_list[FMGR_TOTAL_STORAGE];
    U8 *guiBuffer;
    U8 storage_total_num;
    U32 *drv_inline_list_p;
    U8 highlight_idx;
    S32 i;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BARCODEREADER_OPTION_STORAGE, NULL, mmi_barcodereader_entry_storage_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_OPTION_STORAGE);

    mmi_fmgr_get_exist_storage_inline_list(
        (S8)g_barcodereader_cntx.setting.storage,
        &storage_total_num,
        (PU32)&drv_inline_list_p,
        &highlight_idx);

    RegisterHighlightHandler(mmi_barcodereader_highlight_storage_hdlr);

    SetDelScrnIDCallbackHandler(SCR_ID_BARCODEREADER_OPTION_STORAGE, mmi_barcodereader_delete_select_storage_screen_without_selecting);  

    for (i = 0; i < storage_total_num; i++)
    {
        icon_list[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < storage_total_num; i++)
    {
        pop_ptr_list[i] = NULL;
    }

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_BARCODEREADER_STORAGE),
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        storage_total_num,
        (PU8*)drv_inline_list_p,
        icon_list,
        pop_ptr_list,
        0,
        (S32)highlight_idx,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_barcodereader_exit_select_storage_screen_without_selecting, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_exit_select_storage_screen_without_selecting, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_barcodereader_set_storage_value, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_set_storage_value, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_storage
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_highlight_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_barcodereader_entry_storage_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_entry_storage_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_set_storage_value
 * DESCRIPTION
 *  set storage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_set_storage_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    S8 drv_letter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_get_drive_letter_by_inline_index((U8)g_barcodereader_menu_cntx.storage_selected, (S8*)&g_barcodereader_cntx.setting.storage);
    drv_letter = g_barcodereader_cntx.setting.storage;

    if (drv_letter != 0)
    {           
        mmi_barcodereader_get_storage_file_path(buf_filepath);
        create_result = mmi_barcodereader_create_file_dir(buf_filepath);
        g_barcodereader_cntx.is_storage_ready = FALSE;

        if (create_result == FS_WRITE_PROTECTION)
        {
            DisplayPopup(
                (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                IMG_GLOBAL_ERROR,
                0,
                ST_NOTIFYDURATION,
                ERROR_TONE);
        }
        else if (create_result == FS_DISK_FULL)
        {
            DisplayPopup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_ERROR,
                0,
                ST_NOTIFYDURATION,
                ERROR_TONE);
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            DisplayPopup(
                (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                IMG_GLOBAL_ERROR,
                0,
                ST_NOTIFYDURATION,
                ERROR_TONE);
        }
        else
        {
            g_barcodereader_cntx.is_storage_ready = TRUE;
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    ST_NOTIFYDURATION,
                    SUCCESS_TONE);

            #ifdef __MMI_CAMERA__
                DeleteScreenIfPresent(SCR_ID_BARCODEREADER_OPTION_STORAGE);
            #endif
        }

        /* storge setting to NVRAM */
        mmi_barcodereader_store_setting();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_select_storage_screen_without_selecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_select_storage_screen_without_selecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /***************************************************
     * for new storage error handling machenism 
     ***************************************************/
    if (IsScreenPresent(SCR_ID_BARCODEREADER_OPTION)==MMI_FALSE)
    {
        DeleteUptoScrID(SCR_ID_BARCODEREADER_PREVIEW);
        DeleteNHistory(1);
    }

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_delete_select_storage_screen_without_selecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_barcodereader_delete_select_storage_screen_without_selecting(void *ptr)
{
    g_barcodereader_cntx.is_storage_ready = TRUE;
    return MMI_FALSE;
}
#endif


static U16 mmi_barcodereader_get_error_string(S32 error_code)
{
    U16 string_id = STR_GLOBAL_ERROR;

    switch (error_code)
    {
    case MMI_BARCODEREADER_ERROR_ENCODING_ERROR:
        string_id = STR_ID_BARCODEREADER_ENCODING_ERROR;
        break;
        
    case MMI_BARCODEREADER_ERROR_COMMON:
        string_id = STR_GLOBAL_ERROR;   
        break;
        
    case MMI_BARCODEREADER_ERROR_TOO_LONG_NUMBER:
        string_id = STR_GLOBAL_ERROR;   
        break;
        
    case MMI_BARCODEREADER_ERROR_DECODE_FAILED:
        string_id = STR_ID_BARCODEREADER_DECODE_FAILED;
        break;

    case MDI_RES_BARCODEREADER_DECODE_TIMEOUT:
        string_id = STR_ID_BARCODEREADER_ERROR_DECODE_TIMEOUT;
        break;
        
    case MMI_BARCODEREADER_ERROR_NO_STORAGE:
        string_id = STR_ID_BARCODEREADER_NOTIFY_NO_MEMORY_CARD;
        break;

    case MDI_RES_BARCODEREADER_IMAGE_ERROR:
    case MDI_RES_BARCODEREADER_MODULE_ERROR:
    case MDI_RES_BARCODEREADER_OUT_OF_MEMORY:
    case MDI_RES_BARCODEREADER_OVER_VERSION:
    case MDI_RES_BARCODEREADER_ERROR_CODE_TYPE:
        string_id = STR_ID_BARCODEREADER_DECODE_FAILED;
        break;

    default:
        string_id = STR_GLOBAL_ERROR;    
        }
    return string_id;
}


#ifdef __MMI_BARCODEREADER_OPERATOR1__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_app_preview_screen
 * DESCRIPTION
 *  callback function which will be called from categoryscreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_app_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bufferSize;
    U8 *guiBuffer;
    static HILITE_STR p[23];
    U16 i,j, string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BARCODEREADER_APP_PREVIEW, mmi_barcodereader_exit_app_preview_screen, mmi_barcodereader_enter_app_preview_screen, NULL);

    g_barcodereader_cntx.selected_app_type =
           g_barcodereader_cntx.app_type_list[0];

    /* allocate storage path buffer */
    g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_barcodereader_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    mmi_barcodereader_get_storage_file_path((PS8)g_barcodereader_cntx.storage_filepath);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_APP_PREVIEW);
    mmi_barcodereader_format_string();
    //mmi_ucs2cpy(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf);
    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

    if (guiBuffer == NULL)
    {
        g_barcodereader_cntx.selected_hilight_idx = 0;
    }
    g_barcodereader_cntx.app_list_idx_count = g_barcodereader_cntx.app_list_idx;

    j = 0;
    for (i = 0 ; i < g_barcodereader_cntx.highlight_total_count ; i ++)
    {
        p[j].str_addr = g_barcodereader_cntx.highlight[i].content.str_addr;
        p[j++].length = g_barcodereader_cntx.highlight[i].content.length;
    }

    switch (g_barcodereader_cntx.selected_app_type)
    {
    case MMI_BARCODEREADER_APP_VCARD:
        string_id = STR_ID_BARCODEREADER_VCARD;
        break;

    case MMI_BARCODEREADER_APP_EMAIL:
        string_id = STR_ID_BARCODEREADER_EMAIL;
        break;

    case MMI_BARCODEREADER_APP_SMS:
        string_id = STR_ID_BARCODEREADER_SMS;
        break;

    case MMI_BARCODEREADER_APP_DTXT:
        string_id = STR_ID_BARCODEREADER_DTXT;
        break;

    case MMI_BARCODEREADER_APP_WAPSELL:
        string_id = STR_ID_BARCODEREADER_WAPSELL;
        break;

    case MMI_BARCODEREADER_APP_SMSSELL:
        string_id = STR_ID_BARCODEREADER_SMSSELL;
        break;

    case MMI_BARCODEREADER_APP_IVRSELL:
        string_id = STR_ID_BARCODEREADER_IVRSELL;
        break;

    default:
        string_id = STR_ID_BARCODEREADER_APP_NAME;
        break;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory228Screen(
        string_id,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_barcodereader_cntx.formatted_text_buf,
        bufferSize,
        p,
        (U16)(g_barcodereader_cntx.highlight_total_count),
        mmi_barcodereader_app_preview_callback,
        guiBuffer);
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---total highlight count = %d---*\n",
                         g_barcodereader_cntx.app_list_idx);

    //wgui_register_pen_down_handler(mmi_barcodereader_touch_scr_pen_down_hdlr);
    //SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    SetLeftSoftkeyFunction(mmi_barcodereader_forward_to_apps, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(mmi_barcodereader_forward_to_apps_operator1, KEY_EVENT_UP);
#endif
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_app_preview_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_app_preview_screen(void)
{
    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;

}



static void mmi_barcodereader_ucs2_strtoken(PS8 string, S8 seperate, PS32 length)
{
    PS8 tail;

    if (string == NULL)
    {
       *length = 0;
       return;
    }

    tail = mmi_ucs2chr(string, seperate);
    if(!tail)
    {
        *length = 0;
        return ;
    }

    *length = (tail - string) / 2;
}


static MMI_BOOL mmi_barcodereader_ucs2_check_continue_signal(PS8 string, U32 length, S8 escape_signal) /*caution : the string is UCS2*/
{
    S32 i, escape_signal_count = 0;

    if (string[(length - 1) * 2] == escape_signal && string[(length - 1) * 2 + 1] == 0 ) 
    {
        for (i = (length - 1) * 2 ; i >= 0 ; i -= 2)
        {
            if (string[i] == escape_signal &&  string[i+ 1] == 0)
            {
                escape_signal_count++;
            }
            else
            {
                break;
            }
        }   
    }

    if (escape_signal_count%2 == 1)
    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}

// 
// static MMI_BOOL mmi_barcodereader_check_operator1_escape_signal_encoding(PS8 string, U32 length, PS8 escape_signal)
// {
//     int i;
// 
//     for (i = 0 ; i < 2 * (length - 1) ; i += 2)
//     {
//         if ((string[i] == escape_signal[0]) && (string[i + 2] == escape_signal[0]))
//         {
//             i += 2;
//         }
//         else if (((string[i] == escape_signal[0]) && (string[i + 2] == escape_signal[1])) ||
//                   ((string[i] == escape_signal[2]) && (string[i + 2] == escape_signal[2])))
//         {
//             i += 2;
//         }
//         else
//         {
//             return MMI_FALSE;
//         }
//     }
// 
//     if (string[ 2 * length] == escape_signal[0])
//     {
//         return MMI_FALSE;
//     }
// 
//     return MMI_TRUE;
// }


static U32 mmi_barcodereader_calc_attribute_multi_content(PS8 string, U32 string_length, S8 seperate)
{
    U32 i= 0, result = 1;

    for (i = 0 ; i < string_length * 2 ; i += 2)
    {
        if (string[i] == seperate && string[i+1] == 0)
        {
            result++;
        }
    }

    return result;
}


static U32 mmi_barcodereader_split_multi_content(PS8 string, U32 string_length, S8 seperate, HILITE_STR *p, U32 count)
{
    U32 transfor_count = 0, i= 0;
    PS8 current_head = string;

    for (i = 0 ; i < string_length * 2; i += 2)
    {
        if (string[i] == seperate && string[i+1] == 0)
        {
            p[transfor_count].str_addr = current_head;
            p[transfor_count].length = (string + i - current_head) / 2;
            transfor_count++;
            current_head = string + i + 2;
        }
    }
    
    p[transfor_count].str_addr = current_head;
    p[transfor_count].length = (string + i - current_head) / 2;

    return transfor_count;    
}


static void mmi_barcodereader_add_highlight_content(U32 highlight_attr, PS8 string, S32 start, U16 length, U16 string_id)
{
    g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].content.str_addr = 
        g_barcodereader_cntx.formatted_text_buf + start*2;
    g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].content.length = 
        length;

    if (string_id != 0)
    {
        switch (string_id)
        {
        case STR_ID_BARCODEREADER_TO_ACCESSS:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_OPEN_URL;
            break;

        case STR_ID_BARCODEREADER_SAVE_BOOKMARK:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_SAVE_URL;
            break;
            
        case STR_ID_BARCODEREADER_TO_COMMEND:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_COMMEND;
            break;
            
        case STR_ID_BARCODEREADER_TO_LISTEN:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_LISTEN;
            break;
            
        case STR_ID_BARCODEREADER_TO_ORDER:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_ORDER;
            break;

        default:
            break;
        }
    }
    else
    {
        switch (highlight_attr)
        {
        case MMI_BARCODEREADER_ATTRIBUTE_VALUE_CT:
        case MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_TEL;
            break;
            
        case MMI_BARCODEREADER_ATTRIBUTE_VALUE_DG:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_ORDER;
            break;
            
        case MMI_BARCODEREADER_ATTRIBUTE_VALUE_M:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_M;
            break;
            
        case MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_EM;
            break;
            
        case MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].highlight_type =
                MMI_BARCODEREADER_HIGHLIGHT_TYPE_URL;
            break;
            
        default:
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].content.str_addr = 0;
            g_barcodereader_cntx.highlight[g_barcodereader_cntx.highlight_total_count].content.length = 0;
            g_barcodereader_cntx.highlight_total_count--;
            break;
    }
    }
    
    g_barcodereader_cntx.highlight_total_count++;
}

static void mmi_barcodereader_multi_content_select_screen(void)
{
    U32 i = 0;
    U8  *guiBuffer, total = 0, index, *inputBuffer;
    U16 inputBufferSize;
    HILITE_STR highlight[MMI_BARCODEREADER_CONTENT_MAX_COUNT];
    U32 content_count;
    S16 m[MMI_BARCODEREADER_CONTENT_MAX_COUNT][MAX_PB_NUMBER_LENGTH + 1];
    S16 tel[MMI_BARCODEREADER_CONTENT_MAX_COUNT][MAX_PB_NUMBER_LENGTH + 1];
    S16 fax[MMI_BARCODEREADER_CONTENT_MAX_COUNT][MAX_PB_NUMBER_LENGTH + 1];
    S16 email[MMI_BARCODEREADER_CONTENT_MAX_COUNT][MAX_PB_EMAIL_LENGTH + 1];
    S16 *m_p[MMI_BARCODEREADER_CONTENT_MAX_COUNT], 
        *tel_p[MMI_BARCODEREADER_CONTENT_MAX_COUNT],
        *fax_p[MMI_BARCODEREADER_CONTENT_MAX_COUNT],
        *email_p[MMI_BARCODEREADER_CONTENT_MAX_COUNT];
    U16 length;

    for (i = 0 ; i < MMI_BARCODEREADER_PHB_MULTI_CONTENT_MAX_COUNT ; i++)
    {
        g_barcodereader_cntx.phb_selected[i].index = 0; 
        g_barcodereader_cntx.phb_selected[i].value = 0;
    }
        
    EntryNewScreen(
        SCR_ID_BARCODEREADER_PHONEBOOK_MULTI_CONTENT_SEL, 
        NULL, 
        NULL, 
        NULL);
    
    /*currently the phonebook multicontent has four */
    InitializeCategory57Screen();
    
    total = 0;
    index = 0;
    if (g_barcodereader_cntx.phb_multiple_content_to_select & MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL)
    {
        SetInlineItemCaption(&wgui_inline_items[index++], (PU8)GetString((U16)(STR_ID_BARCODEREADER_ATTR_TEL)));
        SetInlineItemActivation(&wgui_inline_items[index],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0 );

        content_count = mmi_barcodereader_calc_attribute_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TEL].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TEL].length,
                    MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);

        if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
        {
            content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
        }
        
        mmi_barcodereader_split_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TEL].str_addr, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_TEL].length, 
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
            highlight, 
            content_count);

        for (i = 0 ; i < content_count ; i++)
        {
            length = highlight[i].length;
            if (length > MAX_PB_NUMBER_LENGTH)
            {
                length = MAX_PB_NUMBER_LENGTH;
            }
            mmi_ucs2ncpy((PS8)tel[i], highlight[i].str_addr, length);
            memset(tel[i] + length * ENCODING_LENGTH, 0, 2);
            tel_p[i] = tel[i];
        }
        
        SetInlineItemSelect( &wgui_inline_items[index++],
            content_count,
            (U8 **) tel_p,
            (PS32)&g_barcodereader_cntx.phb_selected[total].index);
        g_barcodereader_cntx.phb_selected[total++].value = MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL;
    }

    if (g_barcodereader_cntx.phb_multiple_content_to_select & MMI_BARCODEREADER_ATTRIBUTE_VALUE_M)
    {
        SetInlineItemCaption(&wgui_inline_items[index++], (PU8)GetString((U16)(STR_ID_BARCODEREADER_ATTR_M)));
        SetInlineItemActivation(&wgui_inline_items[index],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0 );
        
        content_count = mmi_barcodereader_calc_attribute_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_M].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_M].length,
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);
        
        if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
        {
            content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
        }
        
        mmi_barcodereader_split_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_M].str_addr, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_M].length, 
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
            highlight, 
            content_count);
        
        for (i = 0 ; i < content_count ; i++)
        {
            length = highlight[i].length;
            if (length > MAX_PB_NUMBER_LENGTH)
            {
                length = MAX_PB_NUMBER_LENGTH;
            }
            mmi_ucs2ncpy((PS8)m[i], highlight[i].str_addr, length);
            memset(m[i] + length * ENCODING_LENGTH, 0, 2);
            m_p[i] = m[i];
        }
        
        SetInlineItemSelect( &wgui_inline_items[index++],
            content_count,
            (U8 **) m_p,
            (PS32)&g_barcodereader_cntx.phb_selected[total].index);
        g_barcodereader_cntx.phb_selected[total++].value = MMI_BARCODEREADER_ATTRIBUTE_VALUE_M;
    }

    if (g_barcodereader_cntx.phb_multiple_content_to_select & MMI_BARCODEREADER_ATTRIBUTE_VALUE_FAX)
    {
        SetInlineItemCaption(&wgui_inline_items[index++], (PU8)GetString((U16)(STR_ID_BARCODEREADER_ATTR_FAX)));
        SetInlineItemActivation(&wgui_inline_items[index],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0 );
        
        content_count = mmi_barcodereader_calc_attribute_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_FAX].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_FAX].length,
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);
        
        if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
        {
            content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
        }
        
        mmi_barcodereader_split_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_FAX].str_addr, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_FAX].length, 
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
            highlight, 
            content_count);
        
        for (i = 0 ; i < content_count ; i++)
        {
            length = highlight[i].length;
            if (length > MAX_PB_NUMBER_LENGTH)
            {
                length = MAX_PB_NUMBER_LENGTH;
            }
            mmi_ucs2ncpy((PS8)fax[i], highlight[i].str_addr, length);
            memset(fax[i] + length * ENCODING_LENGTH, 0, 2);
            fax_p[i] = fax[i];
        }
        
        SetInlineItemSelect( &wgui_inline_items[index++],
            content_count,
            (U8 **) fax,
            (PS32)&g_barcodereader_cntx.phb_selected[total].index);
        g_barcodereader_cntx.phb_selected[total++].value = MMI_BARCODEREADER_ATTRIBUTE_VALUE_FAX;
    }

    if (g_barcodereader_cntx.phb_multiple_content_to_select & MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM)
    {
        SetInlineItemCaption(&wgui_inline_items[index++], (PU8)GetString((U16)(STR_ID_BARCODEREADER_ATTR_M)));
        SetInlineItemActivation(&wgui_inline_items[index],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0 );
        
        content_count = mmi_barcodereader_calc_attribute_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_M].str_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_M].length,
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);
        
        if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
        {
            content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
        }
        
        mmi_barcodereader_split_multi_content(
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_M].str_addr, 
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_M].length, 
            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
            highlight, 
            content_count);
        
        for (i = 0 ; i < content_count ; i++)
        {
            length = highlight[i].length;
            if (length > MAX_PB_NUMBER_LENGTH)
            {
                length = MAX_PB_NUMBER_LENGTH;
            }
            mmi_ucs2ncpy((PS8)email[i], highlight[i].str_addr, length);
            memset(email[i] + length * ENCODING_LENGTH, 0, 2);
            email_p[i] = email[i];
        }
        
        SetInlineItemSelect( &wgui_inline_items[index++],
            content_count,
            (U8 **) email,
            (PS32)&g_barcodereader_cntx.phb_selected[total].index);
        g_barcodereader_cntx.phb_selected[total++].value = MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM;
    }
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_PHONEBOOK_MULTI_CONTENT_SEL);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_BARCODEREADER_PHONEBOOK_MULTI_CONTENT_SEL, &inputBufferSize);
    
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_BARCODEREADER_SETTING_ITEM_COUNT * 2, inputBuffer);
    }
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory57Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        NULL,
        wgui_inline_items,
        0,
        NULL);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_barcodereader_save_phonebook_from_content_select);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


static void mmi_barcodereader_save_phonebook_from_content_select(void)
{
    S16 pbName[(MAX_PB_NAME_LENGTH + 1)] = {0};
    S16 pbNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1)] = {0};
    PHB_OPTIONAL_FIELDS_STRUCT opt_fields;
    PHB_INFO_FIELDS_STRUCT info_fields;

    memset(&opt_fields, 0, sizeof(PHB_OPTIONAL_FIELDS_STRUCT));
    memset(&info_fields, 0, sizeof(PHB_INFO_FIELDS_STRUCT));

    mmi_barcodereader_fille_phb_content(pbName, pbNumber, &opt_fields, &info_fields);
    mmi_phb_save_entry_from_others((PS8) pbName, (PS8) pbNumber, &opt_fields, NULL, &info_fields, NULL, NULL);
}


static void mmi_barcodereader_fille_phb_content(
                                                PS16 pbName, 
                                                PS16 pbNumber, 
                                                PHB_OPTIONAL_FIELDS_STRUCT *opt_fields,
                                                PHB_INFO_FIELDS_STRUCT *info_fields)
{
    U8 i, j;
    U32 length;
    U16 buffer[MAX_PB_NUMBER_LENGTH + 1];
    HILITE_STR attr_content[MMI_BARCODEREADER_CONTENT_MAX_COUNT]; 
    U32 content_count;

    for (i = 0 ; i < MMI_BARCODEREADER_ATTRIBUTE_ALL ; i++)
    {
        if (g_barcodereader_cntx.app_content.ct_attribute & mmi_barcodereader_attribute[i].value)
        {
            switch (mmi_barcodereader_attribute[i].value)
            {
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_N:   //ucs2
                length = g_barcodereader_cntx.app_content.ct_element[i].length;
                if (length > MAX_PB_NAME_LENGTH)
                {
                    length = MAX_PB_NAME_LENGTH;
                }
                mmi_ucs2ncpy(
                    (PS8)pbName,
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    length);
                memset(pbName + length * ENCODING_LENGTH, 0, 2);
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_TIL://ucs2
                length = g_barcodereader_cntx.app_content.ct_element[i].length;
                if (length > MAX_PB_TITLE_LENGTH)
                {
                    length = MAX_PB_TITLE_LENGTH;
                }
                mmi_ucs2ncpy(
                    (PS8)info_fields->title,
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    length);
                memset(info_fields->title + length * ENCODING_LENGTH, 0, 2);
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_DIV:
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_COR: //ucs2
                length = g_barcodereader_cntx.app_content.ct_element[i].length;
                if (length > MAX_PB_COMPANY_LENGTH)
                {
                    length = MAX_PB_COMPANY_LENGTH;
                }
                mmi_ucs2ncpy(
                    (PS8)opt_fields->companyName,
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    length);
                memset(opt_fields->companyName + length * ENCODING_LENGTH, 0, 2);
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_ADR: //ansii
                length = g_barcodereader_cntx.app_content.ct_element[i].length;
                if (length > MAX_PB_ADDRESS_LENGTH)
                {
                    length = MAX_PB_ADDRESS_LENGTH;
                }
                mmi_ucs2ncpy(
                    (PS8)info_fields->address,
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    length);
                memset(info_fields->address + length, 0, 1);
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_ZIP:
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL://ansii
                if (g_barcodereader_cntx.phb_multiple_content_to_select & MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL)
                {
                    content_count = mmi_barcodereader_calc_attribute_multi_content(
                        g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                        g_barcodereader_cntx.app_content.ct_element[i].length,
                        MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);

                    if (content_count == 1)
                    {
                        length = g_barcodereader_cntx.app_content.ct_element[i].length;
                    }
                    else
                    {
                        if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
                        {
                            content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
                        }
                        
                        mmi_barcodereader_split_multi_content(
                            g_barcodereader_cntx.app_content.ct_element[i].str_addr, 
                            g_barcodereader_cntx.app_content.ct_element[i].length, 
                            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
                            attr_content, 
                            content_count);
                    }

                    for (j = 0 ; j < MMI_BARCODEREADER_PHB_MULTI_CONTENT_MAX_COUNT ; j++)
                    {
                        if (g_barcodereader_cntx.phb_selected[j].value == mmi_barcodereader_attribute[i].value)
                        {
                            length = attr_content[g_barcodereader_cntx.phb_selected[j].index].length;
                            if (length > MAX_PB_NUMBER_LENGTH)
                            {
                                length = MAX_PB_NUMBER_LENGTH;
                            }
                            mmi_ucs2ncpy((PS8)buffer, attr_content[g_barcodereader_cntx.phb_selected[j].index].str_addr, length);
                            memset(buffer + length *ENCODING_LENGTH, 0, 2);
                            mmi_ucs2_to_asc((PS8)opt_fields->homeNumber, (PS8)buffer);  
                            break;
                        }
                    }
                }
                else
                {
                    length = g_barcodereader_cntx.app_content.ct_element[i].length;
                    if (length > MAX_PB_NUMBER_LENGTH)
                    {
                        length = MAX_PB_NUMBER_LENGTH;
                    }
                    mmi_ucs2ncpy((PS8)buffer, g_barcodereader_cntx.app_content.ct_element[i].str_addr, length);
                    memset(buffer + length *ENCODING_LENGTH, 0, 2);
                    mmi_ucs2_to_asc((PS8)opt_fields->homeNumber, (PS8)buffer);    
                }                   
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_M :  //ucs2
                if (g_barcodereader_cntx.phb_multiple_content_to_select & MMI_BARCODEREADER_ATTRIBUTE_VALUE_M)
                {
                    content_count = mmi_barcodereader_calc_attribute_multi_content(
                        g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                        g_barcodereader_cntx.app_content.ct_element[i].length,
                        MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);
                    
                    if (content_count == 1)
                    {
                        length = g_barcodereader_cntx.app_content.ct_element[i].length;
                    }
                    else
                    {
                        if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
                        {
                            content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
                        }
                        
                        mmi_barcodereader_split_multi_content(
                            g_barcodereader_cntx.app_content.ct_element[i].str_addr, 
                            g_barcodereader_cntx.app_content.ct_element[i].length, 
                            MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
                            attr_content, 
                            content_count);
                    }
                    
                    for (j = 0 ; j < MMI_BARCODEREADER_PHB_MULTI_CONTENT_MAX_COUNT ; j++)
                    {
                        if (g_barcodereader_cntx.phb_selected[j].value == mmi_barcodereader_attribute[i].value)
                        {
                            length = attr_content[g_barcodereader_cntx.phb_selected[j].index].length;
                            if (length > MAX_PB_NUMBER_LENGTH)
                            {
                                length = MAX_PB_NUMBER_LENGTH;
                            }
                            mmi_ucs2ncpy(
                                (PS8)pbNumber,
                                attr_content[g_barcodereader_cntx.phb_selected[j].index].str_addr,
                                length);
                            memset(pbNumber + length * ENCODING_LENGTH, 0, 2);
                            break;
                        }
                    }
                }
                else
                {
                    length = g_barcodereader_cntx.app_content.ct_element[i].length;
                    if (length > MAX_PB_NUMBER_LENGTH)
                    {
                        length = MAX_PB_NUMBER_LENGTH;
                    }
                    mmi_ucs2ncpy(
                        (PS8)pbNumber,
                        g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                        length);
                    memset(pbNumber + length * ENCODING_LENGTH, 0, 2);
                }
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_FAX : //ansii
                if (g_barcodereader_cntx.phb_multiple_content_to_select & MMI_BARCODEREADER_ATTRIBUTE_VALUE_FAX)
                {
                    content_count = mmi_barcodereader_calc_attribute_multi_content(
                        g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                        g_barcodereader_cntx.app_content.ct_element[i].length,
                    MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);
                }
                else
                {
                    length = g_barcodereader_cntx.app_content.ct_element[i].length;
                    if (length > MAX_PB_NAME_LENGTH)
                    {
                        length = MAX_PB_NAME_LENGTH;
                    }
                    mmi_ucs2ncpy((PS8)buffer, g_barcodereader_cntx.app_content.ct_element[i].str_addr, length);
                    memset(buffer + length *ENCODING_LENGTH, 0, 2);
                    mmi_ucs2_to_asc((PS8)opt_fields->faxNumber, (PS8)buffer);   
                }
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM:  //ansii
                if (g_barcodereader_cntx.phb_multiple_content_to_select & MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM)
                {
                    content_count = mmi_barcodereader_calc_attribute_multi_content(
                        g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                        g_barcodereader_cntx.app_content.ct_element[i].length,
                    MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);
                }
                else
                {
                    length = g_barcodereader_cntx.app_content.ct_element[i].length;
                    if (length > MAX_PB_EMAIL_LENGTH)
                    {
                        length = MAX_PB_EMAIL_LENGTH;
                    }
                    mmi_ucs2ncpy((PS8)buffer, g_barcodereader_cntx.app_content.ct_element[i].str_addr, length);
                    memset(buffer + length *ENCODING_LENGTH, 0, 2);
                    mmi_ucs2_to_asc((PS8)opt_fields->emailAddress, (PS8)buffer); 
                }
                break;
                
            case MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL: // ucs2
                length = g_barcodereader_cntx.app_content.ct_element[i].length;
                if (length > MAX_PB_NAME_LENGTH)
                {
                    length = MAX_PB_NAME_LENGTH;
                }
                mmi_ucs2ncpy(
                    (PS8)info_fields->url,
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    length);
                memset(info_fields->url + length * ENCODING_LENGTH, 0, 2);
                break;
                    }
                }
            } 
}


static void mmi_barcodereader_decode_listen_hdlr(void)
{
    if (g_barcodereader_cntx.b_stop_decode == MMI_TRUE)
    {
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_DECODE_FAILED;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;

        mmi_barcodereader_exit_capture_and_decode_state();
        mmi_barcodereader_enter_preview_state();
        mmi_barcodereader_display_error_popup();
        g_barcodereader_cntx.b_stop_decode = FALSE;
    }
}





#ifdef __MMI_BARCODEREADER_GEN_TYPE_FILE__
static void mmi_barcodereader_gen_type_file(void)
{
    FS_HANDLE handle = 0;
    U16 a1[200], a2[400], a3[50];
    UINT length1, length2;
    UINT hehe;
    
    mmi_asc_to_ucs2((S8*)a3, (S8*)"D:\\data\\ivrsell.mbc");
    handle = FS_Open(a3, FS_READ_WRITE | FS_CREATE);
    
    hehe = 0x01;
    FS_Write(handle, &hehe, 1, &length2);
    hehe = 0x00;
    FS_Write(handle, &hehe, 1, &length2);
    hehe = 0x10;
    FS_Write(handle, &hehe, 1, &length2);
    hehe = 0x00;
    FS_Write(handle, &hehe, 1, &length2);
    
    strcpy(a1, "");
    /*vcard*/
    //strcat(a1, "card:N:zhangyingchun;TIL:engineer;DIV:fp2/mm;cor:mtk;adr:jinqiuguoji;zip:100086;tel:60156838;m:1381,147,9771;FAX:123456;EM:onion555@163.com;URL:www.npzw.com;;");
    /*wapsell*/
    //strcat(a1, "WAPSELL:sub:wapsell;intr:wapsell hehe;url:www.wapsell.com;tel:1381,147,9771;;");
    /*smssell*/
    //strcat(a1,"smssell:sub:smssell;intr:show me the money;dg:dg183;sid:*#3646633#;tel:1381,147,9771;;");
    /*ivrsell*/
    strcat(a1,"ivrsell:sub:ivrsell;intr:wo yao zu fang zi;ct:82800818/83082;tel:1381,147,9771;;");
    mmi_asc_to_ucs2(a2, a1);
    length1 = mmi_ucs2strlen(a2);
    FS_Write(handle, a2, length1*2, &length2);
    FS_Close(handle);
}
#endif /* __MMI_BARCODEREADER_GEN_TYPE_FILE__*/


static void mmi_barcodereader_format_string(void)
{
    U8 i, j;
    S32 length;
    U32 content_count = 0;
    
    if (g_barcodereader_cntx.text_buf == NULL)
    {
        return;
    }
    
    mmi_ucs2cpy(g_barcodereader_cntx.formatted_text_buf, "");
    memset(g_barcodereader_cntx.highlight, 0, sizeof(g_barcodereader_cntx.highlight));
    g_barcodereader_cntx.highlight_total_count = 0;
    
    for(i = 0; i < MMI_BARCODEREADER_ATTRIBUTE_ALL; i++)      
    {
        if (g_barcodereader_cntx.app_type_list[0] == MMI_BARCODEREADER_APP_WAPSELL ||
            g_barcodereader_cntx.app_type_list[0] == MMI_BARCODEREADER_APP_SMSSELL ||
            g_barcodereader_cntx.app_type_list[0] == MMI_BARCODEREADER_APP_IVRSELL)
        {
            if (g_barcodereader_cntx.app_content.ct_attribute & mmi_barcodereader_attribute[i].value)
            {
                MMI_BOOL is_special = MMI_FALSE;
                U16 string_id[3] = {0}, string_number = 0, j = 0;
                
                if (mmi_barcodereader_attribute[i].value & MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL)
                {
                    string_id[0] = STR_ID_BARCODEREADER_TO_ACCESSS;
                    string_id[1] = STR_ID_BARCODEREADER_SAVE_BOOKMARK;
                    string_id[2] = STR_ID_BARCODEREADER_TO_COMMEND;
                    string_number = 3;
                    is_special = MMI_TRUE;
                }
                else if (mmi_barcodereader_attribute[i].value & MMI_BARCODEREADER_ATTRIBUTE_VALUE_CT)
                {
                    string_id[0] = STR_ID_BARCODEREADER_TO_LISTEN;
                    string_id[1] = STR_ID_BARCODEREADER_TO_COMMEND;
                    string_number = 2;
                    is_special = MMI_TRUE;
                }
                else if (mmi_barcodereader_attribute[i].value & MMI_BARCODEREADER_ATTRIBUTE_VALUE_DG)
                {
                    string_id[0] = STR_ID_BARCODEREADER_TO_ORDER;
                    string_id[1] = STR_ID_BARCODEREADER_TO_COMMEND;
                    string_number = 2;
                    is_special = MMI_TRUE;
                }
                else if (mmi_barcodereader_attribute[i].value & MMI_BARCODEREADER_ATTRIBUTE_VALUE_SID)
                {
                    is_special = MMI_TRUE;
                    string_number = 0;
                }
                
                if (is_special)
                {
                    for (j = 0 ; j < string_number ; j++)
                    {
                        length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
                        mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)GetString(string_id[j]));
                        mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L"\n");
                        mmi_barcodereader_add_highlight_content(
                            mmi_barcodereader_attribute[i].value, 
                            g_barcodereader_cntx.formatted_text_buf,
                            length,
                            (U16)mmi_ucs2strlen(GetString(string_id[j])),
                            string_id[j]);
                    }
                    continue;
                }
            }
        }
        if (g_barcodereader_cntx.app_content.ct_attribute & mmi_barcodereader_attribute[i].value)
        {
            mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)GetString(mmi_barcodereader_attribute[i].string_id));
            mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L":");
            mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L"\n");
            
            /*check is multiple content attribute or not*/
            //MMI_BARCODEREADER_CONTENT_MAX_COUNTl;
            if (mmi_barcodereader_attribute[i].value & MMI_BARCODEREADER_MULTI_CONTENT_ATTRIBUTE)
            {
                content_count = mmi_barcodereader_calc_attribute_multi_content(
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    g_barcodereader_cntx.app_content.ct_element[i].length,
                    MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR);    
            }
            else
            {
                content_count = 1;
            }
            
            if (content_count == 1)
            {
                mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L" ");
                length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
                mmi_ucs2ncat(
                    g_barcodereader_cntx.formatted_text_buf, 
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr,
                    g_barcodereader_cntx.app_content.ct_element[i].length);
                mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L"\n");
                g_barcodereader_cntx.formatted_text_buf[(length + g_barcodereader_cntx.app_content.ct_element[i].length + 1) * 2] =
                    0;
                g_barcodereader_cntx.formatted_text_buf[(length + g_barcodereader_cntx.app_content.ct_element[i].length + 1) * 2 + 1] =
                    0;
                
                /*check if the attribute can be highlight or not*/
                if (mmi_barcodereader_attribute[i].value & MMI_BARCODEREADER_HIGHLIGHT_CONTENT_ATTRIBUTE)
                {
                    mmi_barcodereader_add_highlight_content(
                        mmi_barcodereader_attribute[i].value, 
                        g_barcodereader_cntx.formatted_text_buf,
                        length,
                        (U16)g_barcodereader_cntx.app_content.ct_element[i].length, 
                        0);
                }   
            }
            else
            {
                HILITE_STR attr_content[MMI_BARCODEREADER_CONTENT_MAX_COUNT];
                if (content_count > MMI_BARCODEREADER_CONTENT_MAX_COUNT)
                {
                    content_count = MMI_BARCODEREADER_CONTENT_MAX_COUNT;
                }
                
                mmi_barcodereader_split_multi_content(
                    g_barcodereader_cntx.app_content.ct_element[i].str_addr, 
                    g_barcodereader_cntx.app_content.ct_element[i].length, 
                    MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR, 
                    attr_content, 
                    content_count);
                
                for (j = 0 ; j < content_count ; j++)
                {
                    mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L" ");
                    length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
                    mmi_ucs2ncat(
                        g_barcodereader_cntx.formatted_text_buf, 
                        attr_content[j].str_addr,
                        attr_content[j].length);
                    //mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L"\n");
                    
                    g_barcodereader_cntx.formatted_text_buf[(length + g_barcodereader_cntx.app_content.ct_element[i].length + 1) * 2] =
                        0;
                    g_barcodereader_cntx.formatted_text_buf[(length + g_barcodereader_cntx.app_content.ct_element[i].length + 1) * 2 + 1] =
                        0;
                    
                    mmi_ucs2cat(g_barcodereader_cntx.formatted_text_buf, (S8*)L"\n");
                    
                    if (mmi_barcodereader_attribute[i].value & MMI_BARCODEREADER_HIGHLIGHT_CONTENT_ATTRIBUTE)
                    {
                        mmi_barcodereader_add_highlight_content(
                            mmi_barcodereader_attribute[i].value, 
                            g_barcodereader_cntx.formatted_text_buf,
                            length,
                            attr_content[j].length,
                            0);
                    } 
                    
                }
            }
            
        }
        }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_callback
 * DESCRIPTION
 *  callback function which will be called from categoryscreen
 * PARAMETERS
 *  selected_idx        [IN]        The index of the selected highlight item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_app_preview_callback(S32 selected_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_pen_down;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//     if (selected_idx == 0)
//         return;
// 
//     return;

    //g_barcodereader_cntx.current_highlight = selected_idx -1 ;
    g_barcodereader_cntx.current_highlight = selected_idx;
    is_pen_down = wgui_multi_line_get_pen_down_flag();
    if (!is_pen_down)
    {
        return;
    }
    wgui_multi_line_clear_pen_down_flag();
    
    switch (g_barcodereader_cntx.highlight[selected_idx].highlight_type)
    {
    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_LISTEN:
    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_TEL:
    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_M:  
        mmi_barcodereader_func_make_call();
        break;

#ifdef __MMI_EMAIL__
    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_EM:
        mmi_barcodereader_func_send_by_email();
        break;
#endif
        
    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_OPEN_URL:
        //change_left_softkey(STR_ID_BARCODEREADER_SETTING, 0);
        //mmi_barcodereader_hilight_open_url();
        mmi_barcodereader_func_open_url();
        break;

    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_SAVE_URL:
        //change_left_softkey(STR_ID_BARCODEREADER_SETTING, 0);
        //mmi_barcodereader_hilight_save_url();
        mmi_barcodereader_func_save_url();
        break;
        
    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_COMMEND:
        mmi_barcodereader_func_to_commend();
        break;

    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_ORDER:
        //change_left_softkey();
        //mmi_barcodereader_hilight_edit_by_sms();  
        mmi_barcodereader_func_order(); 
        break;

    case MMI_BARCODEREADER_HIGHLIGHT_TYPE_URL:
        mmi_barcodereader_func_url();
        break;
            
    default:
        break;
    }
}


static void mmi_barcodereader_func_url()
{
    U16     image_list[MMI_BARCODEREADER_MENU_COUNT] = 
                {IMG_GLOBAL_L1, IMG_GLOBAL_L2};
    U16     string_list[MMI_BARCODEREADER_MENU_COUNT] = 
                {STR_ID_BARCODEREADER_FUNC_OPEN_URL, STR_ID_BARCODEREADER_FUNC_SAVE_URL};
    U8      *gui_buffer;

    EntryNewScreen(
        SCR_ID_BARCODEREADER_URL,
        NULL,
        mmi_barcodereader_func_url,
        NULL);
   
    gui_buffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_URL);
    RegisterHighlightHandler(mmi_barcodereader_func_url_hilight_hdlr);
    
    ShowCategory52Screen(
        STR_ID_BARCODEREADER_APP_NAME,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP) ,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        string_list,
        image_list,
        NULL,
        0,
        0,
        gui_buffer);
}


static void mmi_barcodereader_func_url_hilight_hdlr(S32 index)
{
    enum
    {
        MMI_BARCODERERADER_FUNC_URL_OPEN = 0,    
        MMI_BARCODERERADER_FUNC_URL_SAVE,
        MMI_BARCODERERADER_FUNC_URL_ALL
    };

    switch(index)
    {
    case MMI_BARCODERERADER_FUNC_URL_OPEN:
        SetLeftSoftkeyFunction(mmi_barcodereader_func_open_url, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(mmi_barcodereader_func_open_url, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        break;

    case MMI_BARCODERERADER_FUNC_URL_SAVE:
        SetLeftSoftkeyFunction(mmi_barcodereader_func_save_url, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(mmi_barcodereader_func_open_url, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        break;

    default:
        SetLeftSoftkeyFunction(mmi_barcodereader_dummy_func, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(mmi_barcodereader_dummy_func, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        break;
    }
}

static void mmi_barcodereader_func_to_commend(void)
{
    g_barcodereader_cntx.is_commend = MMI_TRUE;
    mmi_barcodereader_func_edit_by_sms();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_is_network_permit
 * DESCRIPTION
 *  is net work is available
 * PARAMETERS
 *  MMI_TRUE  judge the net work
 *  MMI_FALSE judge the sim valid
 * RETURNS
 *  MMI_TRUE  net work is available
 *  MMI_FALSE net work is unavailable
 *****************************************************************************/
static MMI_BOOL mmi_barcodereader_is_network_permit(MMI_BOOL is_net)
{
    if (mmi_bootup_get_active_flight_mode() != 0)    
    {
        return MMI_FALSE;
    }

#if !defined(__MMI_DUAL_SIM_MASTER__)
    
    if (is_net)
    {
        if (mmi_bootup_is_network_service_available() == TRUE)
        {
            return MMI_TRUE;
        }
    }
    else
    {
        if (mmi_bootup_is_sim_valid())
        {
            return MMI_TRUE;
        }
    }
    
#else
    
    if ((mmi_bootup_is_sim_valid() == TRUE && MTPNP_AD_Get_Startup_Mode() != MTPNP_AD_NVRAM_CARD2) || 
        (!MTPNP_PFAL_Is_Card2Absent() && !MTPNP_PFAL_Is_Card2CHVBlocked() && MTPNP_AD_Get_Startup_Mode() != MTPNP_AD_NVRAM_CARD1))
    {
        return MMI_TRUE;
    }

    if (is_net)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_netset_get_active_preferred_mode())
        {
            return MMI_TRUE;
        }
    #endif
    }
    
#endif

    return MMI_FALSE;
}

#endif /* __MMI_MMI_BARCODEREADER__ */ 

