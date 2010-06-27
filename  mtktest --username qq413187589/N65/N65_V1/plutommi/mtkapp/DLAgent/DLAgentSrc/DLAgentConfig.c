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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include "MMI_include.h"
#if defined (__MMI_DOWNLOAD_AGENT__)

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "app_mine.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"

#include "drm_def.h"                    /* DRM_PROC_RESULT_OK */
#include "DLAgentDef.h"
#include "DLAgentGprot.h"
#include "DLAgentprot.h"
#include "DLAgentResDef.h"
#ifdef __MMI_VIDEO_PDL__
#include "VdoPlyGProt.h"
#endif 
#if defined (__MMI_SWFLASH__)
#include "SWFlashGProt.h"
#endif
#ifdef SYNCML_DM_SUPPORT
#include "DMGProt.h"
#endif /* SYNCML_DM_SUPPORT */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
#include "SyncMLGProt.h"
#endif
#ifdef __MMI_BARCODEREADER__
#include "mmi_features_barcodereader.h"
#include "barcodereadergprot.h"
#endif

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef struct
{
    applib_mime_subtype_enum mime_subtype;
    UI_string_ID_type string_id;
} mmi_da_mime_type_str_struct;


/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

//#define OLD_STYLE
#ifdef __J2ME__
extern void mmi_java_receive_da_file (S32 session_id, S32 mime_type, S32 mime_subtype,S32 action, PU16 file_path, PS8 url, PS8 mime_type_string);
#endif

#if defined (JATAAYU_SUPPORT)
extern void mmi_prov_receive_da_file(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, PS8 url, PS8 mime_type_string);
#endif

#if defined (__IMPS__)
extern void imps_receive_da_file(S32 session_id,S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, PS8 url, PS8 mime_type_string);
#endif
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern void mmi_ta_receive_theme_file(S32 session_id,S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, PS8 url, PS8 mime_type_string);
#endif
#ifdef __CERTMAN_SUPPORT__
extern void mmi_certman_install_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action_type,
        PU16 filename,
        PS8 download_url,
        PS8 mime_type_str_string);
#endif


/****************************************************************************
* Static Variable
*****************************************************************************/

/* *FORMATTER-DISABLE* */
const static mmi_da_type_handler_struct mmi_da_hdlr_tbl[] =
{
    {MIME_TYPE_UNKNOWN, MIME_SUBTYPE_UNRECOGNIZED, NULL, mmi_da_default_setting},

#ifdef __J2ME__
    {MIME_TYPE_TEXT, MIME_SUBTYPE_JAD,        mmi_java_receive_da_file, mmi_da_bypass_setting},
#ifdef __NO_JAR_DL__
    {MIME_TYPE_TEXT, MIME_SUBTYPE_JAR,        NULL, mmi_da_default_setting},
#else
    {MIME_TYPE_TEXT, MIME_SUBTYPE_JAR,        mmi_java_receive_da_file, mmi_da_bypass_setting},
#endif
#endif

#ifdef __DRM_SUPPORT__
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_CONTENT, NULL, mmi_da_bypass_setting},
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_MESSAGE, NULL, mmi_da_bypass_setting},
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_RIGHTS_WBXML, NULL, mmi_da_push_setting},
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_RIGHTS_XML, NULL, mmi_da_push_setting},
    #ifdef __DRM_V02__
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_CONTENT_V2, NULL, mmi_da_bypass_setting},
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_ROAP_PDU, NULL, mmi_da_bypass_setting},
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_ROAP_TRIGGER, NULL, mmi_da_bypass_setting},
    {MIME_TYPE_APPLICATION, MIMI_SUBTYPE_PROTECTED_RO, NULL, mmi_da_push_setting},
    #endif
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_THEME,mmi_ta_receive_theme_file, mmi_ta_da_setting},
#endif

#ifdef __MMI_OMA_DD_DOWNLOAD__
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_DD,mmi_da_oma_process_dd_file, mmi_da_oma_setting},
#ifdef __MMI_OMA_DD2_DOWNLOAD__
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_DD2,mmi_da_oma_process_dd2_file, mmi_da_oma2_setting},
#endif
#endif

#ifdef JATAAYU_SUPPORT
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_PROV_WBXML,mmi_prov_receive_da_file,mmi_da_push_setting},
	{MIME_TYPE_TEXT, MIME_SUBTYPE_OMA_PROV_XML,mmi_prov_receive_da_file,mmi_da_push_setting},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_NOKIA_PROV_BROWSER,mmi_prov_receive_da_file,mmi_da_push_setting},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_NOKIA_PROV_BOOKMARKS,mmi_prov_receive_da_file,mmi_da_push_setting},
#endif
#ifdef __CERTMAN_SUPPORT__
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT,mmi_certman_install_da_file,mmi_da_default_setting},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT,mmi_certman_install_da_file,mmi_da_default_setting},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS7_CERT,mmi_certman_install_da_file,mmi_da_default_setting},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS12_CERT,mmi_certman_install_da_file,mmi_da_default_setting},
#else        
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT, NULL, mmi_da_default_setting},
#endif /*__CERTMAN_SUPPORT__*/
#ifdef __IMPS__
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_XML,imps_receive_da_file,mmi_da_bypass_setting},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_WBXML,imps_receive_da_file,mmi_da_bypass_setting},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_CIR,imps_receive_da_file,mmi_da_bypass_setting},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_SMS,imps_receive_da_file,mmi_da_bypass_setting},
#endif
#ifdef __MMI_SWFLASH__
	{MIME_TYPE_APPLICATION,MIME_SUBTYPE_WFD,mmi_swflash_receive_da_file,mmi_da_bypass_setting},
	{MIME_TYPE_APPLICATION,MIME_SUBTYPE_CIM,mmi_swflash_receive_da_file,mmi_da_bypass_setting},
	{MIME_TYPE_APPLICATION,MIME_SUBTYPE_ZDD,mmi_swflash_receive_da_file,mmi_da_bypass_setting},
#endif
#ifdef __MMI_VIDEO_PDL__
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_3GPP_VIDEO, fmgr_receive_da_file, mmi_vdoply_pdl_da_notify_file},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_3GPP_VIDEO_1, fmgr_receive_da_file, mmi_vdoply_pdl_da_notify_file},
	{MIME_TYPE_APPLICATION, MIME_SUBTYPE_3GPP_VIDEO_2, fmgr_receive_da_file, mmi_vdoply_pdl_da_notify_file},
#endif
#ifdef __MMI_VIDEO_STREAM__
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_SDP, mmi_vdoply_stream_receive_da_file, mmi_da_bypass_setting},
#endif
#ifdef SYNCML_DM_SUPPORT
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_WBXML, dm_receive_da_file, mmi_da_push_setting},
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_XML, dm_receive_da_file, mmi_da_push_setting},
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_NOTIFICATION, dm_receive_da_file, mmi_da_push_setting},
#endif /* SYNCML_DM_SUPPORT */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_DS_NOTIFICATION, mmi_syncml_receive_da_file, mmi_da_bypass_setting},
#endif
    {MIME_TYPE_NONE, MIME_SUBTYPE_NONE, fmgr_receive_da_file, mmi_da_default_setting}
};
const static S32 mmi_da_hdlr_num = sizeof(mmi_da_hdlr_tbl) / sizeof(mmi_da_type_handler_struct);

const static mmi_da_mime_type_str_struct mmi_da_mime_type_string_tbl[] =
{
    {MIME_SUBTYPE_JPEG,		     STR_DA_IMAGE_FILE},   /*      image/jpeg */
    {MIME_SUBTYPE_VCARD,         STR_DA_VCARD_FILE},
    {MIME_SUBTYPE_XVCARD,        STR_DA_VCARD_FILE},
    {MIME_SUBTYPE_CALENDAR,      STR_DA_VCALENDAR_FILE},
    {MIME_SUBTYPE_XVCALENDAR,    STR_DA_VCALENDAR_FILE},
    {MIME_SUBTYPE_XIMELODY,      STR_DA_AUDIO_FILE},   /*      text/x-imelody */
    {MIME_SUBTYPE_THEME,         STR_DA_APP_FILE},
#ifdef M3D_MMI_SUPPORT
    {MIME_SUBTYPE_M3D,           STR_DA_IMAGE_FILE},
#endif
#if defined(MP4_CODEC)
    {MIME_SUBTYPE_3GPP_AUDIO,    STR_DA_VIDEO_FILE},
#endif
    {MIME_SUBTYPE_UNRECOGNIZED,  STR_DA_UNKNOWN_FILE} /*      Un-recognized file type */

};
const static S32 mmi_da_mime_type_string_num = sizeof(mmi_da_mime_type_string_tbl) / sizeof(mmi_da_mime_type_str_struct);

/* Hook_patch */
const static mmi_da_hook_handler_struct mmi_da_hook_hdlr_tbl[] =
{
#ifdef __MMI_OP02_BARCODEREADER__
    {MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVCARD, mmi_barcodereader_vcf_dla_callback},
#endif
    {MIME_TYPE_NONE, MIME_SUBTYPE_NONE, NULL}
};
const static S32 mmi_da_hook_hdlr_num = (sizeof(mmi_da_hook_hdlr_tbl) / sizeof(mmi_da_hook_handler_struct)) - 1;
/* *FORMATTER-ENABLE* */

/****************************************************************************
* Function 
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*   mmi_da_default_setting
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_config_set_folder(S32 mime_type, S32 mime_subtype, U16 *folder)
{
    switch (mime_type)
    {
        case MIME_TYPE_AUDIO:
            mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_AUDIO);
            break;
        case MIME_TYPE_IMAGE:
            mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_IMAGES);
            break;
        case MIME_TYPE_VIDEO:
            mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_VIDEO);
            break;
        case MIME_TYPE_APPLICATION:
            if (mime_subtype == MIME_SUBTYPE_THEME)
            {
                mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_THEMES);
            }
            else
            {
                mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_RECEIVED);
            }
            break;
        default:
            mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_RECEIVED);
            break;
    }

    if(0)
    {
    }
#ifdef M3D_MMI_SUPPORT
    else if(mime_subtype == MIME_SUBTYPE_M3D)
    {

        mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_IMAGES);
    }
#endif
#ifdef __MMI_EBOOK_READER__
    else if(mime_subtype == MIME_SUBTYPE_PDB)
    {
        mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_EBOOKS);
    }
#endif
#ifdef __MMI_BARCODEREADER__
    else if(mime_subtype == MIME_SUBTYPE_MBC)
    {
        mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_BARCODE);
    }
#endif
#ifdef LANGLN_DIGIDEA
    else if(mime_subtype == MIME_SUBTYPE_DZD || mime_subtype == MIME_SUBTYPE_DZDX)
    {
        mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_LANGLN);
    }
#endif
#ifdef __MMI_MESSAGES_EMS__
    else if(mime_subtype == MIME_SUBTYPE_EMS)
    {
        mmi_ucs2cpy((S8*)folder, (S8*)FMGR_DEFAULT_FOLDER_IMAGES);
    }
#endif
    ASSERT(mmi_ucs2strlen((S8*)folder) > 0);
}


/*****************************************************************************
* FUNCTION
*   mmi_da_default_setting
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_da_default_setting(
	S32	session_id,
	S32	mime_type,                  /* applib_mime_type_enum */
	S32	mime_subtype,               /* applib_mime_subtype_enum */
	S32 action,
	U32	filesize,
	PS8	url,                        /* WAP_DL_MAX_URL_LEN */
	PS8	mime_type_string,           /* WAP_DL _MAX_MIME_TYPE_LEN */
	U32	content_len,
	PS8	content,
	mmi_da_setting_struct * setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(setting, 0, sizeof(mmi_da_setting_struct));

    setting->bypass = MMI_DA_BYPASS_FALSE;
    setting->default_filename = MMI_FALSE;
    setting->filename[0] = setting->filename[1]  = 0; /* Enter by User */

    mmi_da_config_set_folder(mime_type, mime_subtype, setting->folder);

    setting->filepath_hdlr = NULL;
    setting->percentage_bar = MMI_TRUE;
    setting->report_hdlr = NULL;
    setting->storage = MMI_DA_STORAGE_NONE; /* decide by user */
    setting->drv = 0;
    setting->keepfile = MMI_FALSE;

    setting->confirm_dispatch = TRUE;
    setting->confirm_push = TRUE;
    setting->can_minimize = TRUE;
    setting->do_dispatch = TRUE;
    
}

/*****************************************************************************
* FUNCTION
*   mmi_da_bypass_setting
* DESCRIPTION
*   This setting is used for application want to control the file by itself
*   User cannot input filename and select drv.
*   Download agent will save the file into temp folder.
*   Application must move the file to suitable folder if they want reserve
*   the file. The temp folder would be deleted.
* PARAMETERS
* RETURNS
*   void
*****************************************************************************/
void mmi_da_bypass_setting(
    S32 session_id,
    S32 mime_type,                  /* applib_mime_type_enum */
    S32 mime_subtype,               /* applib_mime_subtype_enum */
	S32 action,
    U32 filesize,
    PS8 url,                        /* WAP_DL_MAX_URL_LEN */
    PS8 mime_type_string,           /* WAP_DL _MAX_MIME_TYPE_LEN */
    U32 content_len,
    PS8 content,
    mmi_da_setting_struct * setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting->bypass = MMI_DA_BYPASS_LEVEL_2;
    setting->default_filename = MMI_TRUE;
    setting->filename[0] = setting->filename[1]  = 0;

    if( mime_subtype == MIME_SUBTYPE_JAD || mime_subtype == MIME_SUBTYPE_JAR )
    {
        setting->can_minimize = FALSE;
        mmi_ucs2cpy((S8*)setting->folder, (S8*)FMGR_DEFAULT_FOLDER_RECEIVED);
    }
    else
    {
        setting->can_minimize = TRUE;
        mmi_ucs2cpy((S8*)setting->folder, (S8*)FMGR_DEFAULT_FOLDER_TEMP);
    }
    setting->filepath_hdlr = NULL;
    setting->percentage_bar = MMI_TRUE;
    setting->report_hdlr = NULL;

    setting->storage = MMI_DA_STORAGE_AUTO;
    setting->drv = 0;

    setting->keepfile = MMI_FALSE;
    
    setting->confirm_dispatch = FALSE;
    setting->confirm_push = TRUE;
    setting->do_dispatch = TRUE;

    if( mime_subtype == MIME_SUBTYPE_ZDD )
    {
        setting->can_minimize = FALSE;
    }        
}

/*****************************************************************************
* FUNCTION
*   mmi_da_push_setting
* DESCRIPTION
*   This setting is used for application want to control the file by itself
*   User cannot input filename and select drv.
*   And this kind of push would not insert into the ring buffer. DLA will
*   dispatch the push message to AP immedialy.
* PARAMETERS
* RETURNS
*   void
*****************************************************************************/
void mmi_da_push_setting(
    S32 session_id,
    S32 mime_type,                  /* applib_mime_type_enum */
    S32 mime_subtype,               /* applib_mime_subtype_enum */
	S32 action,
    U32 filesize,
    PS8 url,                        /* WAP_DL_MAX_URL_LEN */
    PS8 mime_type_string,           /* WAP_DL _MAX_MIME_TYPE_LEN */
    U32 content_len,
    PS8 content,
    mmi_da_setting_struct * setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting->bypass = MMI_DA_BYPASS_LEVEL_3;
    setting->default_filename = MMI_TRUE;
    setting->filename[0] = setting->filename[1]  = 0;

    mmi_ucs2cpy((S8*)setting->folder, (S8*)FMGR_DEFAULT_FOLDER_RECEIVED);

    setting->filepath_hdlr = NULL;
    setting->percentage_bar = MMI_TRUE;
    setting->report_hdlr = NULL;

    setting->storage = MMI_DA_STORAGE_AUTO;
    setting->drv = 0;

    setting->keepfile = MMI_FALSE;
    
    setting->confirm_dispatch = FALSE;
    setting->confirm_push = FALSE;
    setting->can_minimize = FALSE;
    setting->do_dispatch = TRUE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_search_mime_type_handler
* DESCRIPTION
*   Search corresponding mime type handler
* PARAMETERS
*   mime_type_string    IN  The MIME type string
* RETURNS
*   A pointer point to the corresponding handler structure.
*****************************************************************************/
const mmi_da_type_handler_struct* mmi_da_search_mime_type_handler(const applib_mime_type_struct * type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == NULL)
    {
        return &mmi_da_hdlr_tbl[0];
    }

    for (i = mmi_da_hdlr_num- 1; i >= 0; i--)
    {
        if (mmi_da_hdlr_tbl[i].mime_subtype == type->mime_subtype)

        {
            return &mmi_da_hdlr_tbl[i];
        }
    }

    return &mmi_da_hdlr_tbl[mmi_da_hdlr_num-1];
}

/*****************************************************************************
* FUNCTION
*   mmi_da_search_mime_type_handler
* DESCRIPTION
*   Search corresponding mime type handler
* PARAMETERS
*   mime_type_string    IN  The MIME type string
* RETURNS
*   A pointer point to the corresponding handler structure.
*****************************************************************************/
const mmi_da_type_handler_struct* mmi_da_get_default_mime_type_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &mmi_da_hdlr_tbl[mmi_da_hdlr_num-1];
}

/* Hook_patch */
S32 mmi_da_search_hook_handler(const applib_mime_type_struct *type, 
                               S32 s_index, 
                               mmi_da_hook_dispatch_hdlr* p_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(type)
    {
        while(s_index < mmi_da_hook_hdlr_num)
        {
            if (mmi_da_hook_hdlr_tbl[s_index].mime_subtype == type->mime_subtype)
            {
                *p_hdlr = mmi_da_hook_hdlr_tbl[s_index].hook_hdlr;
                return s_index+1;
            }
            s_index++;
        }
    }

    *p_hdlr = NULL;
    return -1;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_search_mime_type_string
* DESCRIPTION
*   Search the mime type string in table by mime_subtype
* PARAMETERS
*   mime_subtype    IN  Which mime_subtype you want to search.
* RETURNS
*   The string id
*****************************************************************************/
UI_string_ID_type mmi_da_search_mime_type_string(const applib_mime_type_struct * type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(type == NULL)
    {
        return STR_DA_UNKNOWN_FILE;
    }
    for (i = mmi_da_mime_type_string_num - 1; i >= 0; i--)
    {
        if (type->mime_subtype == mmi_da_mime_type_string_tbl[i].mime_subtype)
        {
            return mmi_da_mime_type_string_tbl[i].string_id;
        }
    }

    switch (type->mime_type)
    {
        case MIME_TYPE_TEXT:
            return STR_DA_TEXT_FILE;
        case MIME_TYPE_IMAGE:
            return STR_DA_IMAGE_FILE;
        case MIME_TYPE_AUDIO:
            return STR_DA_AUDIO_FILE;
        case MIME_TYPE_VIDEO:
            return STR_DA_VIDEO_FILE;
        case MIME_TYPE_APPLICATION:
            return STR_DA_APP_FILE;
        case MIME_TYPE_MESSAGE:
            return STR_DA_MSG_FILE;
        case MIME_TYPE_MULTIPART:
            return STR_DA_MULTI_FILE;
        default:
            return STR_DA_UNKNOWN_FILE;
    }

    return 0;
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
BOOL mmi_da_setting_check(const mmi_da_setting_struct *setting)
{
    /* AP must assign the default folder now */
    if( mmi_ucs2strlen((S8*)setting->folder)== 0)
        return FALSE;

    /* if ap use the default_filename, the length of filename must be zero */
    if( setting->default_filename == TRUE && mmi_ucs2strlen((S8*)setting->filename) > 0 )
        return FALSE;

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
#endif    

    /* percentage_bar must show when AP not control download scenario */
    if( setting->percentage_bar == FALSE)
    {
        if( setting->report_hdlr == NULL )
        {
            return FALSE;
        }
    }

    return TRUE;

}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
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
