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
 *  PopulateRes.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Populate Resource Engine
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define _POPULATE_RES_C

 /****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#include "GlobalMenuItems.h"
#include "custdatares.h"
#include "CustDataProts.h"
#include "custmenures.h"
#include "FontDCL.h"
#include "CallsDefs.h"
#include "Globaldefs.h"
#include "wgui_categories_res.h"

#ifdef __FOTA_ENABLE__
#include "lcd_sw_rnd.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
/***************************************************************************** 
*
* FIRST_PASS is for Resgen on PC
*
*****************************************************************************/
#include "CustResDef.h"
#include "SettingDefs.h"

extern void Trace(char *fmt, ...);
#define PRINT_INFORMATION(args) Trace args

/***************************************************************************** 
* Define
*****************************************************************************/
#define  OUTPUT_IMAGE_ID_FILENAME      CUST_IMG_PATH"\\\\images_file_list.ini"
/* 101205 audio resource Calvin Satrt */
#define  OUTPUT_AUDIO_ID_FILENAME      CUST_ADO_PATH"\\\\audio_file_list.ini"
/* 101205 audio resource Calvin End */
#define  OUTPUT_MENUTREE_ID_FILENAME   "..\\..\\Customer\\CustResource\\CustMenuTreeID_Out.c"

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* for generate String list file in first pass */
FILE *StringListFile = NULL;
FILE *EnumListFile = NULL;
FILE *OutputImgIDFile = NULL;

/* 101205 audio resource Calvin Satrt */
FILE *OutputAdoIDFile = NULL;

/* 101205 audio resource Calvin End */
FILE *OutputMenutreeIDFile = NULL;
FILE *RepeatIDListFile = NULL;  /* 102604 Calvin added */
U16 gCurrLangIndex;

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
FILE *fpMenuResourceUsage = NULL;
FILE *fpImageResourceUsage = NULL;
FILE *fpAudioResourceUsage = NULL;
FILE *fpStringResourceUsage = NULL;

#define MYFOPEN(fp, filename, type) \
do                                  \
{                                   \
    fp = fopen(filename, type);     \
    if (fp == NULL)                 \
    {                               \
        fprintf(stderr, "%s cannot open\n", filename);  \
    }                               \
} while (0)

#define MYFCLOSE(fp, filename)  \
    do                          \
    {                           \
        if (fp != NULL)         \
        {                       \
            fprintf(stderr, "output %s done.\n", filename); \
            fclose(fp);         \
        }                       \
    } while (0)

#define PRTRESTITLE(fp)     \
    do                      \
    {                       \
        if (fp != NULL)     \
        {                   \
            fprintf(fp, "APP_name\tRes_base\tID\tID_name\tsize\tdata\tres_filename\n"); \
        }                   \
    } while (0)
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */

U16 CurrMaxStringNum;
U32 CurrTotalStrLen;
U16 CurrMaxStringId;
U16 CurrMaxStringIdSearch;

/***************************************************************************** 
* Local Function
*****************************************************************************/
void PopulateGlobalData(void);
#ifdef __FOTA_ENABLE__
static void PopulateFOTAData(void);
#endif /* __FOTA_ENABLE__ */

/****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/
extern U16 CurrMaxImageId;
extern U16 CurrMaxImageNum;
extern U16 CurrMaxImageIdEXT;   /* 040805 CustPack: Calvin added */
extern U16 CurrMaxImageNumEXT;  /* 040805 CustPack: Calvin added */

/* 101205 audio resource Calvin Satrt */
extern U16 CurrMaxAudioId;
extern U16 CurrMaxAudioNum;
extern U16 CurrMaxAudioIdEXT;
extern U16 CurrMaxAudioNumEXT;

/* 101205 audio resource Calvin End */

extern U16 CurrMaxMenuItemIndex;    /* Max menu IDs */
extern U16 CurrMaxStringId;
#ifndef __POPULATE_ENGINE_
extern HWND hWnd;
#endif

/* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern U16 CurrMaxENFBAssociatedIDNum;
#endif
/* 101806 E-NFB end */

extern CUSTOM_IMAGE_MAP ImageIdMap[];
extern CUSTOM_IMAGE_MAP ImageIdMapEXT[];
extern CUSTOM_AUDIO_MAP AudioIdMap[];
extern CUSTOM_AUDIO_MAP AudioIdMapEXT[];
extern CUSTOM_MENU nCustMenus[];

const CUSTOM_STRING *gpStringRes;
const CUSTOM_STRING_MAP *gpStringMapRes;
const CUSTOM_STRMAP_SEARCH *gpStrMapSearch;
extern StringResList *gStringList;

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
extern int toolFlag;    /* 040805 CustPack: Calvin added */

/* __CUSTPACK_MULTIBIN Calvin END */

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern FILE *enfb_img_data_file;//100206 ENFB support
#endif

/****************************************************************************
* Global Function - Extern                                                                 
*****************************************************************************/

/* Populate without compile option */
extern void PopulateNFBProgressImg(void);
extern void PopulateMainMenuRes(void);
extern void PopulateIdleMenuRes(void);
extern void PopulatePbResData(void);
extern void PopulateMainDemoRes(void);
extern void PopulateCmResData(void);
extern void PopulateQuickAccessData(void);
extern void populateSettingMenu(void);
extern void populateFunAndGamesMenu(void);
extern void PopulateJavaRes(void);
extern void PopulateResData(void);
extern void PopulateSimDetectionMenuRes(void);
extern void PopulateprofileMenu(void);
extern void PopulateSSCRes(void);
extern void PopulateCallHistoryRes(void);
extern void PopulateHelpResources(void);
extern void PopulateDataAccountMenuList(void);
extern void PopulateChgrPwrOnScrRes(void);
extern void PopulateOrganizerRes(void);
extern void PopulateExtraRes(void);
extern void PopulateAlarmRes(void);
extern void PopulateSATRes(void);
extern void PopulateSpofRes(void);
extern void PopulateResourcesCal(void);
extern void PopulateToDoList(void);
extern void PopulateScreenSaverRes(void);
extern void PopulateCommonScreensResData(void);
extern void PopulateEMSObjectResources(void);
extern void PopulatevObjectRes(void);
extern void PopulateVRSDRes(void);
extern void PopulateWapRes(void);
extern void PopulateMmiapiRes(void);

#if defined(JATAAYU_SUPPORT)
extern void PopulateJaatayuBrowserRes(void);
extern void PopulateJataayuJDDRes(void);
#endif /* defined(JATAAYU_SUPPORT) */ 
#ifdef __MMI_BROWSER_2__
extern void PopulateBrowserRes(void);
#endif /* __MMI_BROWSER_2__ */

/* Populate with compile option */
#if defined(__MMI_NITZ__)
extern void PopulateResourceNITZ(void);
#endif 

#if defined(__MMI_MESSAGES_CHAT__)
extern void PopulateChatAppRes(void);
#endif 

#if defined(__MMI_ENGINEER_MODE__)
extern void populateEngineerModeMenu(void);
#endif 

#if defined(__MMI_FACTORY_MODE__)
extern void populateFactoryModeMenu(void);
#endif 

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
extern void PopulateComposeRingTone(void);
#endif 

#if defined(__MMI_AUDIO_PLAYER__)
extern void populateAudioPlayerMenu(void);
#endif 

#if defined(__MMI_AB_REPEATER__)
extern void populateABRepeaterMenu(void);
#endif 

#if defined(__MMI_FILE_MANAGER__)
extern void populateFileManagerMenu(void);
#endif 

#if defined(__MMI_MY_FAVORITE__)
extern void PopulateMyFavoriteRes(void);
#endif 

#if defined(__MMI_SOUND_RECORDER__)
extern void populateSoundRecorderMenu(void);
#endif 

#if defined(__MMI_CAMERA__)
extern void PopulateCameraRes(void);
#endif 

#if defined(__MMI_BARCODEREADER__)
extern void PopulateBarcodeReaderRes(void);
#endif 

#if defined(__MMI_AVATAR__)
extern void PopulateAvatarRes(void);
#endif

#if defined(__MMI_MOBILE_TV_PLAYER__)
extern void PopulateMobileTVPlayerRes(void);
#endif

#if defined(__MMI_IMAGE_VIEWER__)
extern void PopulateImageViewerRes(void);
#endif 

#if defined(__MMI_VIDEO_PLAYER__)
extern void PopulateVdoPlyRes(void);
#endif 

#if defined(__MMI_VIDEO_RECORDER__)
extern void PopulateVdoRecRes(void);
#endif 

#if defined(__MMI_VIDEO_EDITOR__)
extern void PopulateVdoEdtRes(void);
#endif

#if defined(__MMI_FM_RADIO__)
extern void PopulateFMRadioRes(void);
#endif 

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
extern void PopulateFMScheduleRecRes(void);
#endif 

#if defined(__MOD_SMSAL__)
extern void PopulateMessagesResData(void);
#endif 

#if defined(__MMI_UNIFIED_MESSAGE__)
extern void PopulateUnifiedMessageResData(void);
#endif 

#if defined(__MMI_UNIFIED_COMPOSER__)
extern void PopulateUnifiedComposerResData(void);
#endif

#if defined(__MMI_STOPWATCH__)
extern void PopulateStopwatchRes(void);
#endif 

#if defined(__MMI_PHOTOEDITOR__)
extern void PopulatePhotoEditorRes(void);
#endif 

#if defined(__MMI_SLIDESHOW__)
extern void PopulateSlideShowRes(void);
#endif


#if defined(__MMI_BG_SOUND_EFFECT__)
extern void PopulateBGSoundRes(void);
#endif 

#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#endif

#if defined(__MMI_EXT_DEVICE__)

#ifdef __MMI_USB_SUPPORT__
extern void PopulateExtDevUSBRes(void);
#endif 

#ifdef __MMI_IRDA_SUPPORT__
extern void PopulateExtDevIrDARes(void);
#endif 


#ifdef __MMI_BT_SUPPORT__
extern void PopulateExtDevBTRes(void);
#endif 

#ifdef __MMI_RMGR__
extern void PopulateRightsMgrRes(void);
#endif

#ifdef __DRM_SUPPORT__
extern void PopulateDRMRes(void);
#endif

/* micha_PoC */
#ifdef __MMI_POC__
extern void PoCResourceData(void);
#endif 

#ifdef __MMI_VOIP__
extern void VoIPResourceData(void);
#endif /* __MMI_VOIP__ */

#ifdef __MMI_UCM__
extern void UCMResourceData(void);
#endif /* __MMI_UCM__ */

#ifdef __SYNCML_SUPPORT__
extern void SyncMLResourceData(void);
#endif 

#endif /* defined(__MMI_EXT_DEVICE__) */ 
#if defined(__MMI_DOWNLOAD_AGENT__)
extern void PopulateDownloadAgentRes(void);
#endif 

#if defined(__FOTA_ENABLE__)
extern void PopulateDMMenuList(void);
extern int BMPLoader(char *in_filename, char *out_filename, S8 color_depth);
#endif 

#ifdef __MMI_CCA_SUPPORT__
extern void PopulateCCARes(void);
#endif

#ifdef __CAT_SCR_BROWSER__
extern void populateCSBrowserMenu(void);
#endif	/* __CAT_SCR_BROWSER__ */

#ifdef SYNCML_DM_SUPPORT
extern void PopulateDMUIRes(void);
#endif

#if defined(__MMI_MOBILE_SERVICE__)
extern void PopulateMobileServiceRes(void);
#endif

#if defined(__MMI_CUSTOMER_SERVICE__)
extern void PopulateCustomerServiceRes(void);
#endif

#if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__) 
extern void PopulateGISRes(void);    
#endif 

#ifdef __CERTMAN_SUPPORT__
extern void PopulateCertManRes(void);
#endif /*__CERTMAN_SUPPORT__*/

/* hongzhe.liu add start */
#if defined(ANALOG_TV_SUPPORT)
extern void PopulateAnalogTvRes(void);
#endif
/* hongzhe.liu add end */

#ifdef __CMS_WAP__//“∆»ÌWAP&MMS
extern void	PopulateCmsWAPResData();
extern void	PopulateCmsMMSResData();
#endif
/*****************************************************************************
 * FUNCTION
 *  ToolPopulateInitial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ToolPopulateInitial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j;
    unsigned char a[4];
    char cmd[512];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHWIMageFile();
#ifndef __POPULATE_ENGINE_
    SendMessage(hWnd, WM_CLEARFILES, (WPARAM) 0, (LPARAM) 0);
#endif 
    /* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    CurrMaxENFBAssociatedIDNum = 0;
#endif
    /* 101806 E-NFB end */

    CurrMaxImageId = 0;
    CurrMaxImageNum = 0;
    CurrMaxImageIdEXT = 0;  /* 040805 CustPack: Calvin added */
    CurrMaxImageNumEXT = 0;

    CurrMaxAudioId = 0;
    CurrMaxAudioNum = 0;
    CurrMaxAudioIdEXT = 0;
    CurrMaxAudioNumEXT = 0;

    CurrMaxMenuItemIndex = MAX_MENU_ITEMS;

    /* to read from NVRAM if possible -vanita */
    gCurrLangIndex = 0;

    memset(nCustMenus, 0, sizeof(CUSTOM_MENU) * MAX_MENU_ITEMS);

    for (i = 0; i < MAX_IMAGE_IDS_SIZE; i++)
    {
        ImageIdMap[i].nImageNum = -1;
        ImageIdMapEXT[i].nImageNum = -1;    /* 040805 CustPack: Calvin added */
    }

    for (i = 0; i < MAX_AUDIO_IDS_SIZE; i++)
    {
        AudioIdMap[i].nAudioNum = -1;
        AudioIdMapEXT[i].nAudioNum = -1;
    }
}

/* 101205 audio resource Calvin End */


/*****************************************************************************
 * FUNCTION
 *  ToolPopulateDone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ToolPopulateDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  for generate string list file in first pass */
    fwprintf(StringListFile, L"##number\t%d\r\n", CurrMaxStringId);
    fclose(StringListFile);
    fprintf(EnumListFile, "};\n");
    fclose(EnumListFile);

    /* 091004 MTK Calvin added to reduce populate time */
    fclose(OutputImgIDFile);
    fclose(OutputMenutreeIDFile);
    fclose(RepeatIDListFile);   /* 102604 MTK Calvin added */
    /* MTK Calvin end */

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
    MYFCLOSE(fpMenuResourceUsage, "menu_resource_usage.txt");
    MYFCLOSE(fpImageResourceUsage, "image_resource_usage.txt");
    MYFCLOSE(fpAudioResourceUsage, "audio_resource_usage.txt");
    MYFCLOSE(fpStringResourceUsage, "string_resource_usage.txt");
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */
}

/* __CUSTPACK_MULTIBIN Calvin End */

#define TYPE__(A) A##_MENU
#define TYPE_(A)  TYPE__(A)
#define TYPE(A) TYPE_(A)


/*****************************************************************************
 * FUNCTION
 *  PopulateResData
 * DESCRIPTION
 *  Populate Resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateResData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j;
    unsigned char a[4];
    char path[] = CUST_IMG_PATH;
    char cmd[512];

    /* MTK Leo add */
    FILE *OutputImgDataFile = NULL;
    FILE *nfb_img_res_file = NULL;
    FILE *nfb_img_data_file = NULL;
    FILE *java_img_data_file = NULL;//100206 ENFB support

    /* MTK Leo end */

    sprintf(cmd, "copy_images.bat ");
    j = 16;
    for (i = 0; i < strlen(path); i++)
    {
        if (!(path[i] == '\\' && path[i + 1] == '\\'))
        {
            cmd[j] = path[i];
            j++;
        }
    }
    cmd[j] = '\0';
    system(cmd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfb_img_res_file = fopen(NFB_IMAGE_RES_FILENAME, "w");
    if (nfb_img_res_file == NULL)
    {
        printf("nfb_img_res_file could not open!\n");
    }
    else
    {
        fprintf(nfb_img_res_file, "#include \"CustDataRes.h\" \n");
        fprintf(nfb_img_res_file, "#include \"CustNFBProgressImg.h\" \n");
        fprintf(nfb_img_res_file, "const U8* nfb_progress_images[]={\n");
        fclose(nfb_img_res_file);
    }

    nfb_img_data_file = fopen(NFB_IMAGE_DATA_FILENAME, "w");
    if (nfb_img_data_file == NULL)
    {
        printf("nfb_img_data_file could not open!\n");
    }
    else
    {
        fprintf(nfb_img_data_file, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
        fclose(nfb_img_data_file);
    }
    StringListFile = fopen(CUS_STR_RES_FILENAME, "wb");
    if (StringListFile == NULL)
    {
        printf("StringListFile could not open!\n");
    }
    EnumListFile = fopen("enum_list.h", "w");
    if (EnumListFile == NULL)
    {
        printf("EnumListFile could not open!\n");
    }
    fclose(EnumListFile);
    EnumListFile = fopen("enum_list.h", "a");
    if (EnumListFile == NULL)
    {
        printf("EnumListFile could not open with again!\n");
    }

    /* 091004 MTK Calvin added to reduce populate time */
    OutputImgIDFile = fopen(OUTPUT_IMAGE_ID_FILENAME, "w");
    if (OutputImgIDFile == NULL)
    {
        printf("OutputImgIDFile could not open!\n");
        exit(0);
    }
    fclose(OutputImgIDFile);
    OutputImgIDFile = fopen(OUTPUT_IMAGE_ID_FILENAME, "a");
    if (OutputImgIDFile == NULL)
    {
        printf("OutputImgIDFile could not open again!\n");
    }
    fprintf(OutputImgIDFile, "[Image File List]\n");

    OutputMenutreeIDFile = fopen(OUTPUT_MENUTREE_ID_FILENAME, "w");
    if (OutputMenutreeIDFile == NULL)
    {
        printf("OutputMenutreeIDFile could not open!\n");
    }
    fclose(OutputMenutreeIDFile);
    OutputMenutreeIDFile = fopen(OUTPUT_MENUTREE_ID_FILENAME, "a");
    if (OutputMenutreeIDFile == NULL)
    {
        printf("OutputMenutreeIDFile could not open again!\n");
    }
    /* MTK Calvin end */

    /* 101205 audio resource Calvin Satrt */
    OutputAdoIDFile = fopen(OUTPUT_AUDIO_ID_FILENAME, "w");
    if (OutputAdoIDFile == NULL)
    {
        printf("OutputAdoIDFile could not open!\n");
        exit(0);
    }
    fclose(OutputAdoIDFile);
    OutputAdoIDFile = fopen(OUTPUT_AUDIO_ID_FILENAME, "a");
    if (OutputAdoIDFile == NULL)
    {
        printf("OutputAdoIDFile could not open again!\n");
    }
    fprintf(OutputAdoIDFile, "[Audio File List]\n");
    /* 101205 audio resource Calvin End */

    /* 102604 MTK Calvin added */
    RepeatIDListFile = fopen("repeat_id_list", "w");
    if (RepeatIDListFile == NULL)
    {
        printf("RepeatIDListFile could not open!\n");
    }
    fclose(RepeatIDListFile);
    RepeatIDListFile = fopen("repeat_id_list", "a");
    if (RepeatIDListFile == NULL)
    {
        printf("RepeatIDListFile could not open again!\n");
    }
    fprintf(RepeatIDListFile, "StrId\tEnum_Value\t\tString or Image\n");
    /* MTK Calvin end */

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
    MYFOPEN(fpMenuResourceUsage, "menu_resource_usage.txt", "w");
    PRTRESTITLE(fpMenuResourceUsage);
    MYFOPEN(fpImageResourceUsage, "image_resource_usage.txt", "w");
    PRTRESTITLE(fpImageResourceUsage);
    MYFOPEN(fpAudioResourceUsage, "audio_resource_usage.txt", "w");
    PRTRESTITLE(fpAudioResourceUsage);
    MYFOPEN(fpStringResourceUsage, "string_resource_usage.txt", "w");
    PRTRESTITLE(fpStringResourceUsage);

    /* Print resource base mapping table */
    {
        U32 i = 0;
        FILE *fp;

        fp = fopen("resource_base_table.txt", "w");
        if (fp != NULL)
        {
            fprintf(fp, "min\tmax\tappname\n");
            while (1)
            {
                if (strncmp(g_mmi_resource_base_table[i].appname, "END", 3) == 0)
                {
                    break;
                }
                else
                {
                    fprintf(fp, "%d\t%d\t%s\n",
                            g_mmi_resource_base_table[i].min,
                            g_mmi_resource_base_table[i].max,
                            g_mmi_resource_base_table[i].appname);
                    i++;            
                }
            }
            fclose(fp);
        }

        fprintf(stderr, "output resource_base_table.txt done.\n");
    }
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */

    java_img_data_file = fopen(JAVA_GAME_FILENAME, "w");//100206 ENFB support
    if (java_img_data_file == NULL)
    {
        printf("OutputAdoIDFile could not open!\n");
        exit(0);
    }
    fclose(java_img_data_file);

    a[0] = 0xFF;
    a[1] = 0xFE;
    a[2] = 0x4E;
    a[3] = 0x00;

    fprintf(StringListFile, a);
    fprintf(StringListFile, "%c", a[3]);
    fwprintf(StringListFile, L"Number Of Languages\t1\r\n");
    fwprintf(StringListFile, L"Enum Value\tID\tDescription\tEnglish\r\n");
    fprintf(EnumListFile, "const int ENUM_VALUE_MAP[]={\n");

    ClearHWIMageFile();
#ifndef __POPULATE_ENGINE_
    SendMessage(hWnd, WM_CLEARFILES, (WPARAM) 0, (LPARAM) 0);
#endif 

    /* 101205 audio resource Calvin Satrt */
    CurrMaxImageId = 0;
    CurrMaxImageNum = 0;
    /* __CUSTPACK_MULTIBIN Calvin BEGIN */
    CurrMaxImageIdEXT = 0;  /* 040805 CustPack: Calvin added */
    CurrMaxImageNumEXT = 0;
    /* __CUSTPACK_MULTIBIN Calvin END */

    CurrMaxAudioId = 0;
    CurrMaxAudioNum = 0;
    CurrMaxAudioIdEXT = 0;
    CurrMaxAudioNumEXT = 0;

    CurrMaxMenuItemIndex = MAX_MENU_ITEMS;
    /* 101205 audio resource Calvin End */

    /* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    CurrMaxENFBAssociatedIDNum = 0;
#endif
    /* 101806 E-NFB end */

    /* to read from NVRAM if possible -vanita */
    gCurrLangIndex = 0;

    memset(nCustMenus, 0, sizeof(CUSTOM_MENU) * MAX_MENU_ITEMS);

   /*****************************************************************************
   * Add applcation
   *****************************************************************************/
    ADD_APPLICATION(APP_MAINMENU, "MainMenu Base", MAIN_MENU_BASE, MAIN_MENU_BASE_MAX);
    ADD_APPLICATION(APP_IDLEAPP, "IdleApp", IDLE_APP_BASE, IDLE_APP_BASE_MAX);
    ADD_APPLICATION(APP_BOOTUP, "BootUp", SIM_DETECTION_BASE, SIM_DETECTION_BASE_MAX);
    ADD_APPLICATION(APP_SIMTOOLKIT, "Sim Toolkit", SAT_BASE, SAT_BASE_MAX);
    ADD_APPLICATION(APP_GLOBALDEFS, "Global Defines", GLOBAL_BASE, GLOBAL_BASE_MAX);
    ADD_APPLICATION(APP_CHARGER, "Charger", CHARGER_BASE, CHARGER_BASE_MAX);
    ADD_APPLICATION(APP_UIFRAMEWORK, "UI Framework", CATEGORY_SCREENS_BASE, CATEGORY_SCREENS_BASE_MAX);

    ADD_APPLICATION(APP_PHONEBOOK, "PhoneBook", PHONE_BOOK_BASE, PHONE_BOOK_BASE_MAX);
    ADD_APPLICATION(APP_SHORTCUTS, "ShortCuts", SHORTCUTS_BASE, SHORTCUTS_BASE_MAX);
    ADD_APPLICATION(APP_FUNANDGAMES, "Fun Games", FUN_GAMES_BASE, FUN_GAMES_BASE_MAX);
    ADD_APPLICATION(APP_SERVICES, "Services", SERVICES_BASE, SERVICES_BASE_MAX);
    ADD_APPLICATION(APP_ORGANIZER, "Organizer", ORGANIZER_BASE, ORGANIZER_BASE_MAX);
    ADD_APPLICATION(APP_MESSAGES, "Messages", MESSAGES_BASE, MESSAGES_BASE_MAX);
    ADD_APPLICATION(APP_CHAT, "Chat", CHAT_BASE, CHAT_BASE_MAX);
    ADD_APPLICATION(APP_SETTINGS, "Settings", SETTINGS_BASE, SETTINGS_BASE_MAX);
    ADD_APPLICATION(APP_CALLMANAGEMENT, "CallManagement", CALL_MANAGEMENT_BASE, CALL_MANAGEMENT_BASE_MAX);
    ADD_APPLICATION(APP_DEMOAPP, "DemoApp", DEMO_APP_BASE, DEMO_APP_BASE_MAX);
    ADD_APPLICATION(APP_CALLHISTORY, "Call History", CALL_HISTORY_BASE, CALL_HISTORY_BASE_MAX);
    ADD_APPLICATION(APP_CALLSETUP, "Call Setup", CALL_NEW_BASE, CALL_NEW_BASE_MAX);
    ADD_APPLICATION(APP_PROFILES, "Profiles", PROFILES_BASE, PROFILES_BASE_MAX);
    ADD_APPLICATION(APP_NETWORKSETUP, "Network Setup", NETWORK_SETUP_BASE, NETWORK_SETUP_BASE_MAX);
    ADD_APPLICATION(APP_DATAACCOUNT, "Data Account", DATA_ACCOUNT_BASE, DATA_ACCOUNT_BASE_MAX);
    ADD_APPLICATION(APP_PHONESETUP, "Phone Setup", PHONE_SETUP_BASE, PHONE_SETUP_BASE + 999);
    ADD_APPLICATION(APP_TODOLIST, "To do List", TO_DO_LIST_BASE, TO_DO_LIST_BASE_MAX);
    ADD_APPLICATION(APP_INPUTMETHOD, "INPUTMETHOD", INPUT_METHOD_BASE, INPUT_METHOD_BASE_MAX);
    ADD_APPLICATION(APP_VOICEMEMO, "Voice Memo", VOICE_MEMO_BASE, VOICE_MEMO_BASE_MAX);
    ADD_APPLICATION(APP_ENGINEERMODE, "Engineer Mode", ENGINEER_MODE_BASE, ENGINEER_MODE_BASE_MAX);
    ADD_APPLICATION(APP_CALENDAR, "Calendar", CAL_BASE, CAL_BASE_MAX);
    ADD_APPLICATION(APP_FACTORYMODE, "Factory Mode", FACTORY_MODE_BASE, FACTORY_MODE_BASE_MAX);
    ADD_APPLICATION(APP_GAMES, "Games", GAME_BASE, GAME_BASE_MAX);
    ADD_APPLICATION(APP_WAP, "Wap", WAP_BASE, WAP_BASE_MAX);
#ifdef __MMI_MMS_BGSR_SUPPORT__
    ADD_APPLICATION(APP_MMS_BGSR, "MMS BGSR", MMS_BGSR_BASE, MMS_BGSR_BASE_MAX);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
    ADD_APPLICATION(APP_PICTURE_EDITOR, "Image Editor", PICTURE_EDITOR_BASE, PICTURE_EDITOR_BASE_MAX);
    ADD_APPLICATION(APP_ALARM, "Alarm", ALARM_BASE, ALARM_BASE_MAX);
    ADD_APPLICATION(APP_CALCULATOR, "Calculator", CALCULATOR_BASE, CALCULATOR_BASE_MAX);
    ADD_APPLICATION(APP_UNITCONVETER, "Unit Converter", UNIT_CONVERTER_BASE, UNIT_CONVERTER_BASE_MAX);
    ADD_APPLICATION(APP_CURRENCYCONVERTER, "Currency Converter", CURRENCY_CONVERTER_BASE, CURRENCY_CONVERTER_BASE_MAX);
    ADD_APPLICATION(APP_WORLDCLOCK, "World Clock", WORLD_CLOCK_BASE, WORLD_CLOCK_BASE_MAX);
    ADD_APPLICATION(APP_HEALTHBMI, "Health BMI", HEALTH_BMI_BASE, HEALTH_BMI_BASE_MAX);
    ADD_APPLICATION(APP_HEALTHCALORIE, "Health Calorie", HEALTH_CALORIE_BASE, HEALTH_CALORIE_BASE_MAX);
    ADD_APPLICATION(APP_HEALTHMENSTRUAL, "Health Menstrual", HEALTH_MENSTRUAL_BASE, HEALTH_MENSTRUAL_BASE_MAX);
    ADD_APPLICATION(APP_SECURITY_SETUP, "Security Setup", SECURITY_SETUP_BASE, SECURITY_SETUP_BASE_MAX);
    ADD_APPLICATION(APP_FILEMANAGER, "File Manager", FILE_MANAGER_BASE, FILE_MANAGER_BASE_MAX);
    ADD_APPLICATION(APP_MULTIMEDIA, "Multimedia", MMEDIA_BASE, MMEDIA_BASE_MAX);

    ADD_APPLICATION(APP_RMGR, "Rights Manager", RMGR_BASE, RMGR_BASE_MAX);

#ifdef __MMI_MY_FAVORITE
    ADD_APPLICATION(APP_MYFAVORITE, "My Favorite", MY_FAVORITE_BASE, MY_FAVORITE_BASE_MAX);
#endif    
    
#if defined(__DOWNLOAD__)
    ADD_APPLICATION(APP_DOWNLOAD, "Download", DOWNLOAD_BASE, DOWNLOAD_BASE_MAX);
#endif 
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
    ADD_APPLICATION(
        APP_RINGTONECOMPOSER,
        "RingToneComposer",
        COMPOSE_RING_TONE_ENGINE_BASE,
        COMPOSE_RING_TONE_ENGINE_BASE_MAX);
#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ 

#ifdef __MMI_STOPWATCH__
    ADD_APPLICATION(APP_STOPWATCH, "Stopwatch", STOPWATCH_BASE, STOPWATCH_BASE_MAX);
#endif 

#if defined(__MMI_AUDIO_PLAYER__)
    ADD_APPLICATION(APP_AUDIOPLAYER, "Audio Player", AUDIO_PLAYER_BASE, AUDIO_PLAYER_BASE_MAX);
#endif 

#if defined(__MMI_SOUND_RECORDER__)
    ADD_APPLICATION(APP_SOUNDRECORDER, "Sound Recorder", SOUND_RECORDER_BASE, SOUND_RECORDER_BASE_MAX);
#endif 

#ifdef __MMI_CAMERA__
    ADD_APPLICATION(APP_CAMERA, "Camera", CAMERA_BASE, CAMERA_BASE_MAX);
#endif 

#ifdef __MMI_IMAGE_VIEWER__
    ADD_APPLICATION(APP_IMAGEVIEWER, "Image Viewer", IMAGE_VIEWER_BASE, IMAGE_VIEWER_BASE_MAX);
#endif 

#ifdef __MMI_VIDEO_PLAYER__
    ADD_APPLICATION(APP_VDOPLY, "Video Player", VDOPLY_BASE, VDOPLY_BASE_MAX);
#endif 

#ifdef __MMI_VIDEO_RECORDER__
    ADD_APPLICATION(APP_VDOREC, "Video Recorder", VDOREC_BASE, VDOREC_BASE_MAX);
#endif 

#ifdef __MMI_VIDEO_EDITOR__
    ADD_APPLICATION(APP_VDOEDT, "Video Editor", VDOEDT_BASE, VDOEDT_BASE_MAX);
#endif

#if defined(__MMI_EXT_DEVICE__)
    ADD_APPLICATION(APP_EXTDEVICE, "External Device", EXT_DEVICE_BASE, EXT_DEVICE_BASE_MAX);
#endif 

#if defined(__MMI_VERSION_2__)
    ADD_APPLICATION(APP_EXTRA, "Extra", EXTRA_APP_BASE, EXTRA_APP_BASE_MAX);
#endif 

#ifdef __J2ME__
    ADD_APPLICATION(APP_JAVA, "JAVA", JAVA_BASE, JAVA_BASE_MAX);
#endif 

#ifdef __MMI_EMAIL__
    ADD_APPLICATION(APP_EMAIL, "Email", EMAIL_BASE, EMAIL_BASE_MAX);
#endif 

#ifdef __CERTMAN_SUPPORT__
	ADD_APPLICATION(APP_MMI_CERTMAN, "Certificate Manager mmi", MMI_CERTMAN_BASE, MMI_CERTMAN_BASE_MAX);
#endif /*__CERTMAN_SUPPORT__*/

#ifdef __MMI_IMPS__
    ADD_APPLICATION(APP_IMPS, "IMPS", IMPS_BASE, IMPS_BASE_MAX);
#endif 

#ifdef __MMI_FM_RADIO__
    ADD_APPLICATION(APP_FMRDO, "FM Radio", FM_RADIO_BASE, FM_RADIO_BASE_MAX);
#endif 

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__
    ADD_APPLICATION(
        APP_FMSCHEDULEREC,
        "FM Radio Schedule Record",
        FM_SCHEDULE_REC_BASE,
        FM_SCHEDULE_REC_BASE + FM_SCHEDULE_REC_BASE_MAX);
#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ 

#ifdef __MMI_MESSAGES_CLUB__
    ADD_APPLICATION(APP_MESSAGE_CLUB, "Message Club", MESSAGE_CLUB_BASE, MESSAGE_CLUB_BASE_MAX);
#endif 

#if defined (JATAAYU_SUPPORT)
    ADD_APPLICATION(APP_JATAAYU_BROWSER, "Jataayu Browser", JATAAYU_BROWSER_BASE, JATAAYU_BROWSER_BASE_MAX);
    ADD_APPLICATION(
        APP_JATAAYU_PROVISIONING,
        "Jataayu Provisioning",
        JATAAYU_PROVISIONING_BASE,
        JATAAYU_PROVISIONING_BASE_MAX);
    ADD_APPLICATION(APP_JATAAYU_JDD, "Jataayu JDD", JATAAYU_JDD_BASE, JATAAYU_JDD_BASE_MAX);

    ADD_APPLICATION(
        APP_JATAAYU_PROFILE,
        "Jataayu Profile",
        JATAAYU_PROFILE_BASE,
        JATAAYU_PROFILE_BASE_MAX);

#if defined(MMS_SUPPORT)
    ADD_APPLICATION(APP_JATAAYU_MMS, "Jataayu MMS", JATAAYU_MMS_BASE, JATAAYU_MMS_BASE_MAX);
#endif 
#endif /* defined (JATAAYU_SUPPORT) */ 
#if defined(__MMI_MMS_2__)
    ADD_APPLICATION(APP_UMMS_MMS, "UMMS MMS", UMMS_MMS_BASE, UMMS_MMS_BASE_MAX);
#endif 

#ifdef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION(APP_MERCURY, "MERCURY DUAL MODE", MERCURY_BASE, MERCURY_BASE_MAX);
#endif

    for (i = 0; i < MAX_IMAGE_IDS_SIZE; i++)
    {
        ImageIdMap[i].nImageNum = -1;
        /* __CUSTPACK_MULTIBIN Calvin BEGIN */
        ImageIdMapEXT[i].nImageNum = -1;    /* 040805 CustPack: Calvin added */
        /* __CUSTPACK_MULTIBIN Calvin END */
    }

    /* 101205 audio resource Calvin Satrt */
    for (i = 0; i < MAX_AUDIO_IDS_SIZE; i++)
    {
        AudioIdMap[i].nAudioNum = -1;
        AudioIdMapEXT[i].nAudioNum = -1;
    }
    /* 101205 audio resource Calvin End */

    /* add an empty image icon */
    ADD_APPLICATION_IMAGE(IMG_NONE, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp");

    /* 101205 audio resource Calvin Satrt */
    ADD_APPLICATION_AUDIO2(
        ADO_GLOBAL_EMPTYAUDIO,
        "..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3",
        "..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3");
    ADD_APPLICATION_AUDIO3(ADO_GLOBAL_EMPTYAUDIO_EXT, "..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3", "..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3");    /* for custpack */
    ADD_APPLICATION_AUDIO2(
        ADO_GLOBAL_NOAUDIO,
        "..\\\\..\\\\Customer\\\\Audio\\\\NoAudio.mp3",
        "..\\\\..\\\\Customer\\\\Audio\\\\NoAudio.mp3");
    ADD_APPLICATION_AUDIO2(
        ADO_GLOBAL_DEFAULT,
        "..\\\\..\\\\Customer\\\\Audio\\\\Default.mp3",
        "..\\\\..\\\\Customer\\\\Audio\\\\Default.mp3");
    /* 101205 audio resource Calvin End */

   /*****************************************************************************
   * Populate Resoruce
   *****************************************************************************/
    PopulateNFBProgressImg();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    PRINT_INFORMATION(("Populating Golbal Resources\n"));
    PopulateGlobalData();

    PRINT_INFORMATION(("Populating Main Menu Resources\n"));
    PopulateMainMenuRes();

    PRINT_INFORMATION(("Populating Idle Menu Resources\n"));
    PopulateIdleMenuRes();

    PRINT_INFORMATION(("Populating Phone Book Resources\n"));
    PopulatePbResData();

    PRINT_INFORMATION(("Populating Main Demo Resources\n"));
    PopulateMainDemoRes();

    PRINT_INFORMATION(("Populating Setting Resources\n"));
    populateSettingMenu();

    PRINT_INFORMATION(("Populating Fun & Games Resources\n"));
    populateFunAndGamesMenu();

    PRINT_INFORMATION(("Populating SIM Detect Resources\n"));
    PopulateSimDetectionMenuRes();

    PRINT_INFORMATION(("Populating Charger Power On Resources\n"));
    PopulateChgrPwrOnScrRes();

    PRINT_INFORMATION(("Populating Common Screen Resources\n"));
    PopulateCommonScreensResData();

    PRINT_INFORMATION(("Populating EMS object Resources\n"));
    PopulateEMSObjectResources();

    PRINT_INFORMATION(("Populating CM Resources\n"));
    PopulateCmResData();

    PRINT_INFORMATION(("Populating Quick Access Resources\n"));
    PopulateQuickAccessData();


    PRINT_INFORMATION(("Populating Profiles Resources\n"));
    PopulateprofileMenu();

    PRINT_INFORMATION(("Populating SSC Resources\n"));
    PopulateSSCRes();

    PRINT_INFORMATION(("Populating Call History Resources\n"));
    PopulateCallHistoryRes();

    PRINT_INFORMATION(("Populating Call History Resources\n"));
    PopulateDataAccountMenuList();

    PRINT_INFORMATION(("Populating Organizer Resources\n"));
    PopulateOrganizerRes();

    PRINT_INFORMATION(("Populating Extra Resources\n"));
    PopulateExtraRes();

    PRINT_INFORMATION(("Populating Alarm Resources\n"));
    PopulateAlarmRes();

    PRINT_INFORMATION(("Populating SPOF Resources\n"));
    PopulateSpofRes();

    PRINT_INFORMATION(("Populating Calendar Resources\n"));
    PopulateResourcesCal();

    PRINT_INFORMATION(("Populating ToDo Resources\n"));
    PopulateToDoList();

    PRINT_INFORMATION(("Populating vObjects Resource\n"));
    PopulatevObjectRes();

    PRINT_INFORMATION(("Populating Help Resources\n"));
    PopulateHelpResources();

#ifdef __CERTMAN_SUPPORT__
	PRINT_INFORMATION(("Populating CertificateManager\n"));
	PopulateCertManRes();
#endif /*__CERTMAN_SUPPORT__*/

#if 0   /* Cylen 0926, customize display char */
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    PRINT_INFORMATION(("Populating MMIAPI Resource\n"));
    PopulateMmiapiRes();

#ifdef __MOD_SMSAL__
    PRINT_INFORMATION(("Populating Messages Resources\n"));
    PopulateMessagesResData();

#ifdef __MMI_MESSAGES_CHAT__
    PopulateChatAppRes();
#endif 
#endif /* __MOD_SMSAL__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
    PopulateUnifiedMessageResData();
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
    PopulateUnifiedComposerResData();
#endif

#ifdef __MMI_EMAIL__
    PRINT_INFORMATION(("Populating Email Resources\n"));
    EmailResourceData();
#endif /* __MMI_EMAIL__ */ 


#ifdef __MMI_IMPS__
    PRINT_INFORMATION(("Populating IMPS Resources\n"));
    PopulateIMPSData();
#endif /* __MMI_IMPS__ */ 

#ifdef __SAT__
    PRINT_INFORMATION(("Populating SAT Resources\n"));
    PopulateSATRes();
#endif /* __SAT__ */ 

#if defined(JATAAYU_SUPPORT)
    PRINT_INFORMATION(("Populating Jataayu Browser Resources\n"));
    PopulateJaatayuBrowserRes();
    PRINT_INFORMATION(("Populating Jataayu Provisioning Resources\n"));
    PopulateJaatayuProvisioningRes();
    PRINT_INFORMATION(("Populating Jataayu JDD Resources\n"));
    PopulateJataayuJDDRes();
#endif /* defined(JATAAYU_SUPPORT) */ 

#ifdef __MMI_BROWSER_2__
    PRINT_INFORMATION(("Populating Browser Resources\n"));
    PopulateBrowserRes();
#endif /* __MMI_BROWSER_2__ */
#ifdef __MMI_ENGINEER_MODE__
    PRINT_INFORMATION(("Populating EM Resources\n"));
    populateEngineerModeMenu();
#endif /* __MMI_ENGINEER_MODE__ */ 

#ifdef __MMI_FACTORY_MODE__
    PRINT_INFORMATION(("Populating FM Resources\n"));
    populateFactoryModeMenu();
#endif /* __MMI_FACTORY_MODE__ */ 

#ifdef __MMI_AUDIO_PLAYER__
    PRINT_INFORMATION(("Populating Audio Player Resources\n"));
    populateAudioPlayerMenu();
#else /* __MMI_AUDIO_PLAYER__ */ 
    PRINT_INFORMATION(("Populating Audio Simple Player Resources\n"));
    populateAudioPlayerMenu();
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifdef __MMI_AB_REPEATER__
    PRINT_INFORMATION(("Populating AB Repeater Resources\n"));
    populateABRepeaterMenu();
#endif /* __MMI_AB_REPEATER__ */ 

#ifdef __MMI_SOUND_RECORDER__
    PRINT_INFORMATION(("Populating Sound Recorder Resources\n"));
    populateSoundRecorderMenu();
#endif /* __MMI_SOUND_RECORDER__ */ 

#ifdef __MMI_FILE_MANAGER__
    PRINT_INFORMATION(("Populating File Manager Resources\n"));
    populateFileManagerMenu();
#endif /* __MMI_FILE_MANAGER__ */ 

#ifdef __MMI_VIDEO_PLAYER__
    PRINT_INFORMATION(("Populating Video Player Resources\n"));
    PopulateVdoPlyRes();
#endif /* __MMI_VIDEO_PLAYER__ */ 

#ifdef __MMI_VIDEO_RECORDER__
    PRINT_INFORMATION(("Populating Video Recoder Resources\n"));
    PopulateVdoRecRes();
#endif /* __MMI_VIDEO_RECORDER__ */ 

#ifdef __MMI_VIDEO_EDITOR__
    PRINT_INFORMATION(("Populating Video Editor Resources\n"));
    PopulateVdoEdtRes();
#endif

#ifdef __MMI_NITZ__
    PRINT_INFORMATION(("Populating NITZ Resources\n"));
    PopulateResourceNITZ();
#endif /* __MMI_NITZ__ */ 

#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
    PRINT_INFORMATION(("End Populating Image Editor\n"));
    PopulatePictureEditor();
#endif /* __MMI_PICTURE_EDITOR_SUPPORT__ */ 

#ifdef __MMI_STOPWATCH__
    PRINT_INFORMATION(("Populating StopWatch Resources\n"));
    PopulateStopwatchRes();
#endif /* __MMI_STOPWATCH__ */ 

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
    PRINT_INFORMATION(("Populating Compose RingTone\n"));
    PopulateComposeRingTone();
#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ 

#ifdef __MMI_CAMERA__
    PRINT_INFORMATION(("Populating Camera Resource\n"));
    PopulateCameraRes();
#endif /* __MMI_CAMERA__ */ 

#ifdef __MMI_BARCODEREADER__
    PRINT_INFORMATION(("Populating Barcode Reader Resource\n"));
    PopulateBarcodeReaderRes();
#endif /* __MMI_BARCODEREADER__ */ 

#ifdef __MMI_AVATAR__
    PRINT_INFORMATION(("Populating Avatar Resource\n"));
    PopulateAvatarRes();
#endif /* __MMI_AVATAR__ */

#ifdef __MMI_MOBILE_TV_PLAYER__
    PRINT_INFORMATION (("Populating Mobile TV Player Resource\n"));
    PopulateMobileTVPlayerRes();
#endif /* __MMI_MOBILE_TV_PLAYER__ */

#ifdef __MMI_IMAGE_VIEWER__
    PRINT_INFORMATION(("Populating Image Viewer Resource\n"));
    PopulateImageViewerRes();
#endif /* __MMI_IMAGE_VIEWER__ */ 

#ifdef __MMI_FM_RADIO__
    PRINT_INFORMATION(("Populating FM Radio Resource\n"));
    PopulateFMRadioRes();
#endif /* __MMI_FM_RADIO__ */ 

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__
    PRINT_INFORMATION(("Populating Schedule FM Radio Record Resource\n"));
    PopulateFMScheduleRecRes();
#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ 

#if defined(__MMI_PHOTOEDITOR__)
    PRINT_INFORMATION(("Populating PhotoEditor Resource\n"));
    PopulatePhotoEditorRes();
#endif /* defined(__MMI_PHOTOEDITOR__) */ 

#if defined(__MMI_SLIDESHOW__)
    PRINT_INFORMATION(("Populating Slideshow Resource\n"));
    PopulateSlideShowRes();
#endif


#if defined (__MMI_EXT_DEVICE__)
#ifdef __MMI_USB_SUPPORT__
    PRINT_INFORMATION(("Populating USB Resource\n"));
    PopulateExtDevUSBRes();
#endif /* __MMI_USB_SUPPORT__ */ 

#ifdef __MMI_IRDA_SUPPORT__
    PRINT_INFORMATION(("Populating IRDA Resource\n"));
    PopulateExtDevIrDARes();
#endif /* __MMI_IRDA_SUPPORT__ */ 


#ifdef __MMI_BT_SUPPORT__
    PRINT_INFORMATION(("Populating Bluetooth Resource\n"));
    PopulateExtDevBTRes();
#endif /* __MMI_BT_SUPPORT__ */ 
#endif /* defined (__MMI_EXT_DEVICE__) */ 

#if defined(__MMI_VRSD__)
    PRINT_INFORMATION(("Populating Voice Recognition SD Resource\n"));
    PopulateVRSDRes();
#endif /* defined(__MMI_VRSD__) */ 

#if defined(__MMI_VRSI__)
    PRINT_INFORMATION(("Populating Voice Recognition SI Resource\n"));
    PopulateVRSIRes();
#endif /* defined(__MMI_VRSI__) */ 

#if defined(__MMI_BG_SOUND_EFFECT__)
    PRINT_INFORMATION(("Populating Background Sound Resource\n"));
    PopulateBGSoundRes();
#endif /* defined(__MMI_BG_SOUND_EFFECT__) */ 

#if defined(WAP_SUPPORT) || defined(__MMI_MMS__)
    PRINT_INFORMATION(("Populating WAP Resource\n"));
    PopulateWapRes();
#endif /* defined(WAP_SUPPORT) || defined(__MMI_MMS__) */ 

#ifdef __MMI_POC__
    PRINT_INFORMATION(("Populating PoC Resources\n"));
    PoCResourceData();
#endif /* __MMI_POC__ */ 

#ifdef __MMI_VOIP__
    PRINT_INFORMATION(("Populating VoIP Resources\n"));
    VoIPResourceData();
#endif /* __MMI_VOIP__ */

#ifdef __MMI_UCM__
    PRINT_INFORMATION(("Populating UCM Resources\n"));
    UCMResourceData();
#endif /* __MMI_UCM__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    PRINT_INFORMATION(("Populating VT Resources\n"));
    VTResourceData();
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __SYNCML_SUPPORT__
    PRINT_INFORMATION(("Populating SyncML Resources\n"));
    SyncMLResourceData();
#endif /* __SYNCML_SUPPORT__ */ 

#ifdef __MMI_CSB_BROWSER__
	PRINT_INFORMATION(("Populating CS Browser Resources\n"));
	populateCSBrowserMenu();
#endif	/* __MMI_CSB_BROWSER__ */


#ifndef __POPULATE_ENGINE_
    SendMessage(hWnd, WM_GENSTRFILE, (WPARAM) 0, (LPARAM) 0);
    PRINT_INFORMATION(("after 1 sendmsg"));

    SendMessage(hWnd, WM_GENIMGFILE, (WPARAM) 0, (LPARAM) 0);
    PRINT_INFORMATION(("after 2 send msg "));

    SendMessage(hWnd, WM_GENMENUFILE, (WPARAM) 0, (LPARAM) 0);
    PRINT_INFORMATION(("after 3 send msg "));
#endif /* __POPULATE_ENGINE_ */ 

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
    PopulateExtDevFTPRes();
    PRINT_INFORMATION(("Populating FTP Resource\n"));
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 
#ifdef __MMI_OPP_SUPPORT__
    PopulateExtDevOPPRes();
    PRINT_INFORMATION(("Populating OPP Resource\n"));
#endif /* __MMI_OPP_SUPPORT__ */ 
#ifdef __MMI_BPP_SUPPORT__
    PopulateExtDevBPPRes();
    PRINT_INFORMATION(("Populating BPP Resource\n"));
#endif /* __MMI_BPP_SUPPORT__ */ 

#ifdef __MMI_BIP_SUPPORT__
    PopulateExtDevBIPRes();
    PRINT_INFORMATION(("Populating BIP Resource\n"));
#endif /* __MMI_BIP_SUPPORT__ */ 

#ifdef __MMI_DOWNLOAD_AGENT__
    PRINT_INFORMATION(("Populating Download Agent Resources\n"));
    PopulateDownloadAgentRes();
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
#ifdef __MMI_SWFLASH__
	PRINT_INFORMATION(("Populating SWFlash Resource\n"));	
	PopulateSWFlashRes();
#endif /* __MMI_SWFLASH__ */

#if defined(__FOTA_ENABLE__)
    PRINT_INFORMATION(("Populating Device Management Resources\n"));
    PopulateDMMenuRes();
#endif /* __FOTA_ENABLE__ */ 

    //WRITE_STRING_RES_FILE;    /* Write the string resource file only for first pass */
    //WRITE_IMAGE_RES_FILE;     /* Write the image resource file only for first pass */
    //WRITE_MENU_RES_FILE;

#ifdef __FOTA_ENABLE__
    PRINT_INFORMATION(("Populating FOTA Resource\n"));	
    PopulateFOTAData();
#endif /* __FOTA_ENABLE__ */

#ifdef __MMI_CCA_SUPPORT__
    PRINT_INFORMATION(("Populating CCA Resource\n"));	
    PopulateCCARes();
#endif

#ifdef __MMI_RMGR__
    PRINT_INFORMATION(("Populating Rights Manager Resources\n"));
    PopulateRightsMgrRes();
#endif

#ifdef __DRM_SUPPORT__
    PRINT_INFORMATION(("Populating DRM Task Resources\n"));
    PopulateDRMRes();
#endif


#ifdef __MMI_MOBILE_SERVICE__
    PRINT_INFORMATION(("Populating Mobile Service\n"));
    PopulateMobileServiceRes();
#endif/*__MMI_MOBILE_SERVICE__*/

#if defined(__MMI_CUSTOMER_SERVICE__)
    PRINT_INFORMATION(("Populating Customer Service\n"));
    PopulateCustomerServiceRes();
#endif/*__MMI_CUSTOMER_SERVICE__*/

#ifdef __MMI_MY_FAVORITE__
    PRINT_INFORMATION(("Populating My Favorite Resources\n"));
    PopulateMyFavoriteRes();
#endif /* __MMI_MY_FAVORITE__ */ 
#ifdef __MMI_MMS_BGSR_SUPPORT__
    PRINT_INFORMATION(("Populating MMS BGSR\n"));
    PopulateMMSBGSRResData();
#endif /*__MMI_MMS_BGSR_SUPPORT__*/    

#ifdef SYNCML_DM_SUPPORT
    PRINT_INFORMATION(("Populating DMUI Resource\n"));  
    PopulateDMUIRes();
#endif

#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
/* under construction !*/
#endif /* (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__))) */

#if defined(__MMI_LANGLN__)
    PRINT_INFORMATION(("Populating Language Learning Resource\n"));
    PopulateLangLnRes();
#endif /* defined(__MMI_LANGLN__) */ 

#if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__) 
    PRINT_INFORMATION(("Populating GIS Resource\n"));
    PopulateGISRes();
#endif 

#ifdef __MMI_DUAL_SIM_MASTER__
    Mercury_ResPopulate();
#endif

/* hongzhe.liu add start */
#if defined(ANALOG_TV_SUPPORT)
    PopulateAnalogTvRes();
#endif

//05.10.18 pan add for wap&mms
#ifdef __CMS_WAP__//“∆»ÌWAP&MMS
		PopulateCmsWAPResData();
		PopulateCmsMMSResData();
#endif
/* hongzhe.liu add end */
    /*  for generate string list file in first pass */
    nfb_img_res_file = fopen(NFB_IMAGE_RES_FILENAME, "a");
    if (nfb_img_res_file != NULL)
    {
        fprintf(nfb_img_res_file, "\n};\n");
        fclose(nfb_img_res_file);
    }

    fwprintf(StringListFile, L"##number\t%d\r\n", CurrMaxStringId);
    fclose(StringListFile);
    fprintf(EnumListFile, "};\n");
    fclose(EnumListFile);

    /* 091004 MTK Calvin added to reduce populate time */
    fclose(OutputImgIDFile);

    /* 101205 audio resource Calvin Satrt */
    fclose(OutputAdoIDFile);
    /* 101205 audio resource Calvin End */

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
    MYFCLOSE(fpMenuResourceUsage, "menu_resource_usage.txt");
    MYFCLOSE(fpImageResourceUsage, "image_resource_usage.txt");
    MYFCLOSE(fpAudioResourceUsage, "audio_resource_usage.txt");
    MYFCLOSE(fpStringResourceUsage, "string_resource_usage.txt");
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */

    fclose(OutputMenutreeIDFile);
    fclose(RepeatIDListFile);   /* 102604 MTK Calvin added */
    /* MTK Calvin end */

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    fclose(enfb_img_data_file);//100206 ENFB support
#endif
}

#ifdef __FOTA_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  PopulateFOTAData
 * DESCRIPTION
 *  Populate FOTA data resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateFOTAData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp_in, *fp_out, *fp_temp;
    char filename_in[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_bg.pbm";
    char filename_out[] = "..\\..\\Customer\\CustResource\\CustFOTAImgData.h";
    char filename_temp[] = "TEMPIMAGE";
    char buff[256];
    int ret, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp_in = fopen(filename_in, "rb");
    if (fp_in == NULL)
    {
        fprintf(stderr, "[FOTA] Input file failed !!\n");
        return ;
    }
    fclose(fp_in);
    
    ret = BMPLoader(filename_in, filename_temp, DRV_MAINLCD_BIT_PER_PIXEL);
    if (ret == 0)
    {
        fprintf(stderr, "[FOTA] BMPLoader failed !!\n");
        return ;
    }

    fp_temp = fopen(filename_temp, "rb");
    if (fp_temp == NULL)
    {
        fprintf(stderr, "[FOTA] Read raw data file failed !!\n");
        return ;
    }
    fp_out = fopen(filename_out, "w");
    if (fp_out == NULL)
    {
        fprintf(stderr, "[FOTA] Output file failed !!\n");
        fclose(fp_temp);
        return ;
    }

    fprintf(fp_out, "const U8 FOTA_PBAR_IMG_DATA[] = ");

    while (!feof(fp_temp))
    {
        count = fread(buff, sizeof(char), 256, fp_temp);
        if (count)
        {
            fwrite(buff, sizeof(char), count, fp_out);
        }
    }
    fputs("\n", fp_out);

    fclose(fp_temp);
    fclose(fp_out);
}
#endif /* __FOTA_ENABLE__ */

/*****************************************************************************
 * FUNCTION
 *  PopulateGlobalData
 * DESCRIPTION
 *  Populate Global Resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateGlobalData()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ADD_APPLICATION_STRING2(STR_GLOBAL_0, "0", "Global String- 0");
    ADD_APPLICATION_STRING2(STR_GLOBAL_1, "1", "Global String- 1");
    ADD_APPLICATION_STRING2(STR_GLOBAL_2, "2", "Global String- 2");
    ADD_APPLICATION_STRING2(STR_GLOBAL_3, "3", "Global String- 3");
    ADD_APPLICATION_STRING2(STR_GLOBAL_4, "4", "Global String- 4");
    ADD_APPLICATION_STRING2(STR_GLOBAL_5, "5", "Global String- 5");
    ADD_APPLICATION_STRING2(STR_GLOBAL_6, "6", "Global String- 6");
    ADD_APPLICATION_STRING2(STR_GLOBAL_7, "7", "Global String- 7");
    ADD_APPLICATION_STRING2(STR_GLOBAL_8, "8", "Global String- 8");
    ADD_APPLICATION_STRING2(STR_GLOBAL_9, "9", "Global String- 9");
    ADD_APPLICATION_STRING2(STR_GLOBAL_10, "10", "Global String- 10");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ABORT, "Abort", "Global String- Abort");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ABORTING, "Aborting", "Global String- Aborting");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ACCEPT,"Accept","Global String- Accept");    
    ADD_APPLICATION_STRING2(STR_GLOBAL_ACCOUNTS,"Accounts",	"Accounts- configuration folder");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ACTIVATE, "Activate", "Global String- Activate");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ACTIVATED, "Activated", "Global String- Activated");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ADD, "Add", "Global String- Add");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ADDRESS, "Address", "Global String- Address");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ALARM, "Alarm", "Global String- Alarm");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AS_EMAIL, "As Email", "Global String- As Email- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AS_MULTIMEDIA_MSG, "As multimedia msg.", "Global String- As multimedia msg.- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AS_TEXT_MESSAGE, "As text message", "Global String- As text message- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ATTACHMENT, "Attachment", "Global String- Attachment");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AUTHENTICATION,"Authentication","Global String- Authentication");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AUTOMATIC,"Automatic","Global String- Automatic");
    ADD_APPLICATION_STRING2(STR_GLOBAL_BACK, "Back", "Global String- Back");
    ADD_APPLICATION_STRING2(STR_GLOBAL_BUSY_TRY_LATER, "Busy", "STR_GLOBAL_BUSY_TRY_LATER");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CANCEL, "Cancel", "Global String- Cancel");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CANCELLING, "Cancelling", "Global String- Cancelling");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CLEAR, "Clear", "Global String- Clear");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CLOSE, "Close", "Global String- Close");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONFIRM, "Confirm", "Global String- Confirm");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONNECT, "Connect", "Global String- Connect");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONNECTING, "Connecting", "Global String- Connecting");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONTACTS, "Contacts", "Global String- Contacts");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONTENT, "Content", "Global String- Content");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONTINUE, "Cont.", "Global String- Cont.- use as LSK for length limit");
    ADD_APPLICATION_STRING2(STR_GLOBAL_COPYING, "Copying", "Global String- Copying");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CUSTOM, "Custom", "Global String- Custom- user defined");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DATA_ACCOUNT, "Data account", "Global String- Data account");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DATE, "Date", "Global String- Date");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DEACTIVATE, "Deactivate", "Global String- Deactivate");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DEFAULT, "Default", "Global String- Default");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETE, "Delete", "Global String- Delete");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETE_ALL, "Delete All", "Global String- Delete All");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETED, "Deleted", "Global String- Deleted");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETING, "Deleting", "Global String- Deleting");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DETAILS, "Details", "Global String- Details");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DIAL, "Call", "Global String- Call");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DISCARD,"Discard","Global String- Discard");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DISCONNECT, "Disconnect", "Global String- Disconnect");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DISCONNECTING, "Disconnecting", "Global String- Disconnecting");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DONE, "Done", "Global String- Done");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DOWNLOAD, "Download", "STR_GLOBAL_DOWNLOAD");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DOWNLOAD_ASK, "Download?", "STR_GLOBAL_DOWNLOAD_ASK");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DOWNLOADING, "Downloading", "STR_GLOBAL_DOWNLOADING");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRAFTS, "Drafts", "Global String- Drafts- draft folder");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_FILE_EXISTS, "File Exists", "Global String- File Exists");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_FS_ERROR, "File Access Error", "Global String- File Access Error");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_INVALID_FORMAT, "Format Error", "Global String- Format Error");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_NON_DRM, "Not DRM File", "Global String- Not DRM File");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_PROCESSING, "DRM Processing", "Global String- DRM Processing");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_PROHIBITED, "DRM Prohibited", "Global String- DRM Prohibited");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_RO_RECEIVED, "DRM Rights Received", "Global String- DRM Rights Received");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_SIZE_TOO_BIG, "Size Too Big", "Global String- Size Too Big");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EARPHONE_IN, "Earphone plugged in!", "Global String- String Associated with Ear Phone Plug In Popup.");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EARPHONE_OUT, "Earphone plugged Out", "Global String- Earphone plugged Out");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EDIT, "Edit", "Global String- Edit");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EMAIL, "Email", "Global String- Email");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EMPTY, "Empty", "Global String- Empty");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EMPTY_LIST, "<Empty>", "Global String- <Empty>");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ERROR, "Error", "Global String- Error");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EXIT, "Exit", "Global String- Exit");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FAILED_TO_SAVE, "Failed to save", "Global String- Failed to save");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FAILED_TO_SEND, "Failed to send", "Global String- Failed to send");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FAST, "Fast", "Global String- Fast");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FILE_ALREADY_EXISTS, "File already exists", "Global String- File already exists");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FILENAME, "Filename", "Global String- Filename");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FORMAT, "Format", "Global String- Format- the type of file");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FORWARD, "Forward", "Global String- Forward- send message to other recipients");
    ADD_APPLICATION_STRING2(STR_GLOBAL_GO_TO, "Go to", "Global String- Go to- connect the URL");
    ADD_APPLICATION_STRING2(STR_GLOBAL_GPRS, "GPRS", "Global String- GPRS");
    ADD_APPLICATION_STRING2(STR_GLOBAL_GSM, "GSM", "Global String- GSM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_HELP, "Help", "Global String- Help- show the usage tips or notes");
    ADD_APPLICATION_STRING2(STR_GLOBAL_HIGH, "High", "Global String- High");
    ADD_APPLICATION_STRING2(STR_GLOBAL_HTTP, "HTTP", "Global String- HTTP");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INBOX, "Inbox", "Global String- Inbox");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INPUT_METHOD, "Input Method", "Global String- Input Method");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INSTALL, "Install", "Global String- Install");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INSUFFICIENT_MEMORY, "Insufficient memory", "Global String- Insufficient memory- not enough RAM to operate");    
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID, "Invalid", "Global String- Invalid");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_FILENAME, "Invalid filename", "Global String- Invalid filename");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_FORMAT, "Invalid format", "Global String- Invalid format");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_INPUT, "Invalid input", "Global String- Invalid input");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_URL, "Invalid URL", "Global String- Invalid URL");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LIST, "List", "Global String- List");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOADING, "Loading", "Global String- Loading");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOGIN, "Login", "Global String- Login");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOGO, "Logo", "Global String- Logo");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOGOUT, "Logout", "Global String- Logout");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOW, "Low", "Global String- Low");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MANUAL, "Manual", "Global String- Manual");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MARK, "Mark", "Global String- Mark");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MARK_ALL, "Mark all", "Global String- Mark all");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MAXIMUM, "Maximum", "Global String- Maximum");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MEDIUM, "Medium", "Global String- Medium");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MEMORY_CARD, "Memory card", "Global String- Memory card");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MEMORY_FULL, "Memory full", "Global String- Memory full- indicate user not save again");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MEMORY_STATUS, "Memory status", "Global String- Memory status");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MOVING, "Moving", "Global String- Moving");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MULTIMEDIA_MESSAGE, "Multimedia message", "Global String- Multimedia message");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MUTE, "Mute", "Global String- Mute");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NETWORK_SETTINGS, "Network settings", "Global String- Network settings");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NO, "No", "Global String- No");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NO_MEMORY_CARD, "No Memory Card", "[Notify-No Memory Card]");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NONE, "None", "Global String- None");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NORMAL, "Normal", "Global String- Normal");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_AVAILABLE, "Not Available", "Global String- Not Available");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_DONE, "Not Done", "Global String- Not Done");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_ENOUGH_MEMORY, "Not enough memory", "Global String- Not enough memory- memory is too small to save");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR, "Not Support at PC Simulator", "Global String- Not Support at PC Simulator");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_SUPPORTED, "Not supported", "Global String- Not supported");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OFF, "Off", "Global String- Off");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OK, "Ok", "Global String- OK");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ON, "On", "Global String- On");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OPEN, "Open", "Global String- Open");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OPTIONS, "Option", "Global String- Options");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OUTBOX, "Outbox", "Global String- Outbox");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OVERWRITE_EXISTING_FILE, "Overwrite existing file?", "Global String- Overwrite existing file?");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PASSWORD, "Password","Global String- Password menu");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PAUSE, "Pause","Global String- Pause");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PHONE, "Phone","Global String- Phone");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PICTURE, "Picture","Global String- Picture");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PLAY, "Play","Global String- Play");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PLEASE_WAIT, "Please Wait", "Global String- Please Wait");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PREFERRED_STORAGE, "Preferred storage", "Global String- Preferred storage");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PREVIEW, "Preview", "Global String- Preview");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PRINT, "Print", "Global String- Print");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PRIORITY, "Priority", "Global String- Priority");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PROXY, "Proxy", "Global String- Proxy");
    ADD_APPLICATION_STRING2(STR_GLOBAL_QUIT, "Quit", "Global String- Quit");
    ADD_APPLICATION_STRING2(STR_GLOBAL_READ, "Read", "Global String- Read");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RECEIVED, "Received", "Global String- Received");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RECEIVING, "Receiving", "Global String- Receiving");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RECIPIENTS, "Recipients", "Global String- Recipients- recipient list name");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REFRESH, "Refresh", "Global String- Refresh");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REMOVE, "Remove", "Global String- Remove- delete the reference link or remove accessory from phone");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REMOVED, "Removed", "Global String- Removed- remove successfully");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RENAME, "Rename", "Global String- Rename");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REPLACE, "Replace", "Global String- Replace");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REPLY, "Reply", "Global String- Reply");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RESET, "Reset", "Global String- Reset");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RESUME, "Resume", "Global String- Resume");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RINGTONE, "Ringtone", "Global String- Ringtone");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVE, "Save", "Global String- Save");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVE_ASK, "Save?", "Global String- Save?");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVE_TO_CONTACTS, "Save to contacts", "Global String- Save to contacts");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVED, "Saved", "Global String- Saved");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVING, "Saving", "Global String- Saving");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEARCH, "Search", "Global String- Search");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEARCHING, "Searching", "Global String- Searching");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SELECT, "Select", "Global String- Select");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEND, "Send", "Global String- Send");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SENDING, "Sending", "Global String- Sending");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SENT, "Sent", "Global String- Sent- send successfully");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SETTINGS, "Settings", "Global String- Settings");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SIM, "SIM", "Global String- SIM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SLOW, "Slow", "Global String- Slow");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SORT_BY, "Sort by", "Global String- Sort by- include sub options");
    ADD_APPLICATION_STRING2(STR_GLOBAL_START, "Start", "Global String- Start");
    ADD_APPLICATION_STRING2(STR_GLOBAL_STOP, "Stop", "Global String- Stop");
    ADD_APPLICATION_STRING2(STR_GLOBAL_STORAGE, "Storage", "Global String- Storage");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SUBJECT, "Subject", "Global String- Subject");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SUBMIT,"Submit","Accept");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TEXT, "Text", "Global String- Text");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TEXT_MESSAGE, "Text message", "Global String- Text message- SMS");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TIME, "Time", "Global String- Time");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UDP_PORT, "UDP port", "Global String- UDP port");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNFINISHED, "Unfinished", "Global String- Unfinished");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNMARK, "Unmark", "Global String- Unmark");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNMARK_ALL, "Unmark all", "Global String- Unmark all");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNSUPPORTED_FORMAT, "Unsupported Format", "Global String- Unsupported Format");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UPDATE, "Update", "Global String- Update");
    ADD_APPLICATION_STRING2(STR_GLOBAL_URL, "URL", "Global String- URL");
    ADD_APPLICATION_STRING2(STR_GLOBAL_USE_TEMPLATE, "Use Template", "Global String- Use Template");
    ADD_APPLICATION_STRING2(STR_GLOBAL_USERNAME, "User Name", "Global String- User name menu");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIA_BLUETOOTH, "Via Bluetooth", "Global String- Via Bluetooth- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIA_INFRARED, "Via infrared", "Global String- Via infrared- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIDEO, "Video", "Global String- Video");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIEW, "View", "Global String- View");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VOLUME, "Volume", "Global String- Volume");
    ADD_APPLICATION_STRING2(STR_GLOBAL_WAP, "WAP", "Global String- WAP");
    ADD_APPLICATION_STRING2(STR_GLOBAL_YES, "Yes", "Global String- Yes");

// Hongzhe.Liu : power on off logo bmp 
#if defined  __POWERONOFF_MISO_ANIM__  
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\MISO_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined __POWERONOFF_IMUSIC_ANIM__
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\IMUSIC_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined __POWERONOFF_CAR_ANIM__
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\CAR_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined __POWERONOFF_BUTTERFLY_ANIM__
     ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\BUTTERFLY_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined __POWERONOFF_GLASSBALL_ANIM__
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\GLASSBALL_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined __POWERONOFF_NEX_ANIM__
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\NEX_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined __POWERONOFF_MASTER_ANIM__
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\MASTER_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined(__POWERONOFF_IPHONE_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\IPHONE_logo.bmp",
        "Bootup Scanning Image");

#elif defined(__POWERONOFF_JPHONE_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\JPHONE_logo.bmp",
        "Bootup Scanning Image");

#elif defined(__POWERONOFF_APHONE_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\APHONE_logo.bmp",
        "Bootup Scanning Image");

/*shaokai add it start.090908*/
#elif defined(__POWERONOFF_MPMOBILE_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\MPMOBILE_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined(__POWERONOFF_STARPHONE_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\STARPHONE_LOGO.bmp",
        "Bootup Scanning Image");
		
#elif defined(__POWERONOFF_SCOOL_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\SCOOL_LOGO.bmp",
        "Bootup Scanning Image");

#elif defined(__POWERONOFF_ZYQ_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\ZYQ_LOGO.bmp",
        "Bootup Scanning Image");
#elif defined(__POWERONOFF_SMILE_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\SMILE_LOGO.bmp",
        "Bootup Scanning Image");
/*shaokai add it end.090908*/

/**********************************************************************

New ring add before this line ... : hongzhe.liu

***********************************************************************/
#elif defined(__POWERONOFF_TEST_ANIM__)
    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\TEST_logo.bmp",
        "Bootup Scanning Image");

#elif defined(__POWERONOFF_NOKE_ANIM__)

    ADD_APPLICATION_IMAGE3(
        IMG_BOOTUP_SCANNING_LOGO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\NOKE_logo.bmp",
        "Bootup Scanning Image");

#else
#error "Hongzhe.liu : logo bmp error "

#endif


    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_OK, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-Ok");
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_BACK, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-Back");
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_YES, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-Yes");
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_NO, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-No");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_OPTIONS,
        "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp",
        "Global Image-Options");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L1,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB1.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L2,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB2.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L3,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB3.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L4,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB4.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L5,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB5.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L6,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB6.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L7,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB7.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L8,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB8.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L9,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB9.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L10,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB10.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L11,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB11.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L12,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB12.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L13,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB13.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L14,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB14.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L15,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB15.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L16,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB16.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L17,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB17.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L18,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB18.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L19,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB19.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L20,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB20.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L21,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB21.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L22,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB22.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L23,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB23.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L24,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB24.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L25,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB25.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L26,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB26.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L27,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB27.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L28,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB28.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L29,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB29.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_L30,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB30.PBM",
        "Menu Image");
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_CLEAR, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-Clear");
    ADD_APPLICATION_IMAGE2(IMG_STATUS, CUST_IMG_PATH "\\\\MainLCD\\\\Alarm\\\\OA_STATU.PBM", "Status Image");
    ADD_APPLICATION_IMAGE2(IMG_VICON, CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.bmp", "Status Image");
    ADD_APPLICATION_IMAGE2(IMG_TIME, CUST_IMG_PATH "\\\\MainLCD\\\\Alarm\\\\OA_TIME.PBM", "Time Image");
    ADD_APPLICATION_IMAGE2(IMG_REPEAT, CUST_IMG_PATH "\\\\MainLCD\\\\Alarm\\\\OA_REPT.PBM", "Repeat Image");
    ADD_APPLICATION_IMAGE2(
        IMG_CAL,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\Settings\\\\DateAndTime\\\\ST_CALEN.PBM",
        "Calendar Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_QUESTION,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_QUE"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Question Mark image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SAVE,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_SAV"__MMI_RES_TYPE_POPUP_SCREEN__,
        "saved image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_DELETED,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DEL"__MMI_RES_TYPE_POPUP_SCREEN__,
        "deleted image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_EMPTY,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_EMP"__MMI_RES_TYPE_POPUP_SCREEN__,
        "empty image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_UNFINISHED,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_UNF"__MMI_RES_TYPE_POPUP_SCREEN__,
        "unfinished image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_WARNING,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_WARN"__MMI_RES_TYPE_POPUP_SCREEN__,
        "warning image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_PROGRESS,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Progress Image");
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_DEFAULT, "..\\\\..\\\\Customer\\\\Images\\\\Default.bmp", "default image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_ACTIVATED,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DONE"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Activated image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_ERASED,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_ERASE"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Erased image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_ERROR,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_ERR"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Error Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_INFO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_INF"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Info Image");
    ADD_APPLICATION_IMAGE2(
        IMG_EARPHONE_POPUP_MAINLCD,
        CUST_IMG_PATH "\\\\MAINLCD\\\\WarningPage\\\\notification\\\\N_HDSET.PNG",
        "Main LCD Image Associated with Ear Phone Plug In Popup.");
    ADD_APPLICATION_IMAGE2(
        IMG_EARPHONE_POPUP_SUBLCD,
        CUST_IMG_PATH "\\\\SUBLCD\\\\Active\\\\SB_EAR.BMP",
        "Sub LCD Image Associated with Ear Phone Plug In Popup.");

#ifdef __MMI_SLIM_PROGRESS_ANIMATION__
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_LOADING,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Loading Progress Image");
#else /* __MMI_SLIM_PROGRESS_ANIMATION__ */ 
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_LOADING,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Progress\\\\LOADING"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Loading Progress Image");
#endif /* __MMI_SLIM_PROGRESS_ANIMATION__ */ 
}

#else /* DEVELOPER_BUILD_FIRST_PASS */ 
/***************************************************************************** 
*
* Not FIRST_PASS, for MMI to get global resource info
*
*****************************************************************************/
U16 CurrMaxStringNum;
U32 CurrTotalStrLen;
U16 CurrMaxStringId;
U16 CurrMaxStringIdSearch;
U16 gCurrLangIndex;

const CUSTOM_STRING *gpStringRes;
const CUSTOM_STRING_MAP *gpStringMapRes;
const CUSTOM_STRMAP_SEARCH *gpStrMapSearch;
extern StringResList *gStringList;


/*****************************************************************************
 * FUNCTION
 *  PopulateResGetBaseIDTable
 * DESCRIPTION
 *  Dummy function to make ARM linker happy such that developers can access
 *  g_mmi_resource_base_table in Trace32/VC++ even though the variable is not used
 *  in other places.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *PopulateResGetBaseIDTable(void)
{
#if !defined(PRODUCTION_RELEASE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)g_mmi_resource_base_table;
#else /* !defined(PRODUCTION_RELEASE) */ 
    return NULL;
#endif /* !defined(PRODUCTION_RELEASE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  PopulateResData
 * DESCRIPTION
 *  Populate Resource, assign resource info to global variable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateResData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrLangIndex = 0;
    gpStringRes = gStringList[gCurrLangIndex].pStringRes;
    gpStringMapRes = gStringList[gCurrLangIndex].pStringMap;
    gpStrMapSearch = gStringList[gCurrLangIndex].pStrMapSearch;
    CurrMaxStringNum = gStringList[gCurrLangIndex].nTotalStrRes;
    CurrMaxStringId = gStringList[gCurrLangIndex].nTotalStrMap;
    CurrMaxStringIdSearch = gStringList[gCurrLangIndex].nTotalStrMapSearch;
    return;
}

#endif /* DEVELOPER_BUILD_FIRST_PASS */ 

