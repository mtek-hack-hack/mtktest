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
 * vCard.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sending and receving vcard object.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VCARD_C
#define _MMI_VCARD_C

#if defined(__MMI_VCARD__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "vObjects.h"
#include "PhoneBookDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookProt.h"
#include "PhoneBookGProt.h"
#include "vCard.h"
#include "MessagesExDcl.h"
#include "IrdaMMIGprots.h"
#include "app_qp.h"
#include "gui_data_types.h"     /* UI_character_type */
#if defined(__MMI_FILE_MANAGER__)
#include "FileManagerDef.h"     /* error string id */
#endif /* defined(__MMI_FILE_MANAGER__) */
#include "FileManagerGProt.h" 
#include "fmt_struct.h"

#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
#include "SMSApi.h"
#endif

#if defined(__MMI_MMS__)
#include "Wapadp.h"
#include "CallManagementGProt.h"        /* To check if is in call for MMS */
#if defined (OBIGO_SUPPORT)
#include "WapResDef.h"        /* MMS ID */
#endif /* defined (OBIGO_SUPPORT) */ 
#endif /* defined(__MMI_MMS__) */ 

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"  /* wgui_register_list_item_selected_callback_all */
#endif 

#ifdef __MMI_OPP_SUPPORT__
#include "OPPMMIGprots.h"
#include "ExtDeviceDefs.h"
#endif /* __MMI_OPP_SUPPORT__ */ 

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
#include "app_datetime.h"
#endif 
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */

#include "SimDetectionGprot.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_PFAL_resource.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*
 * Typedef
 */
#define  VCARD_WRITER_FIELD_BUFFER  500 /* Writer Buffer for single field. over 50 x 9 */
#define  VCARD_LINE_BREAK  "\r\n"
#define VCARD_VERSION_21 "2.1"
#define VCARD_VERSION_30 "3.0"
#define VCARD_HEADER "VCARD"

typedef enum
{
    VCARD_PARA_CELL,
    VCARD_PARA_HOME,
    VCARD_PARA_WORK,
    VCARD_PARA_VOICE,
    VCARD_PARA_FAX,
    VCARD_PARA_PAGER,
    VCARD_PARA_PREF,
    VCARD_PARA_TOTAL
} vcard_para_enum;


typedef enum
{
    VCARD_EMAIL_PARA_INTERNET,
    VCARD_EMAIL_PARA_TOTAL
} vcard_email_para_enum;

/* for vcard 3.0 number type */
typedef enum
{
    VCARD_TYPE_PARA_TYPE,
    VCARD_TYPE_PARA_TOTAL
}vcard_type_para_enum;


/*
 * Define
 */
#define VCARD_WRITE_BUFF_LEN      2000 /* 1024 + 728(info field) */
#define VCARD_READ_BUFF_LEN       1024


/*
 * Local Variable
 */
vcard_context_struct g_vcard_cntx;

const S8 *g_vcard_field[VCARD_FIELD_TOTAL] = 
{
    "BEGIN",
    "VERSION",
    "FN",
    "N",
    "TEL",
    "EMAIL",
    "ORG",
    "BDAY",
    "TITLE",
    "URL",
    "NOTE",
    "ADR",
    "PHOTO",
    "REV",
    "LABEL",
    "NICKNAME",
    "MAILER",
    "TZ",
    "GEO",
    "ROLE",
    "LOGO",
    "AGENT",
    "CATEGORIES",
    "PRODID",
    "SORT-STRING",
    "SOUND",
    "UID",
    "CLASS",
    "KEY",
    "X-",
    "END"
};

const S8 *g_vcard_para[VCARD_PARA_TOTAL] = 
{
    "CELL",
    "HOME",
    "WORK",
    "VOICE",
    "FAX",
    "PAGER",
    "PREF"
};

const S8 *g_vcard_email_para[VCARD_EMAIL_PARA_TOTAL] = 
{
    "INTERNET"
};

/* for vcard 3.0 number type */
const S8 *g_vcard_type_para[VCARD_TYPE_PARA_TOTAL] = 
{
    "TYPE"
};

static U8 g_vcard_number = 0;

/*
 * Local Function
 */
#ifdef __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__
static void mmi_vcard_util_get_name(S8 *str, U16 length);
#else /* __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__ */
static BOOL mmi_vcard_util_has_transform_name(S8 *str, U16 length);
#endif /* __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__ */
#if !defined(__MMI_VCARD_NAME_IN_ENGLISH_FORMAT__) || defined(__MMI_PHB_INFO_FIELD__)
static void mmi_vcard_util_transform_field_delimiter(S8 *str, U16 length);
#endif /* !defined(__MMI_VCARD_NAME_IN_ENGLISH_FORMAT__) || defined(__MMI_PHB_INFO_FIELD__) */
#if defined(__MMI_VCARD_V30__)
static void mmi_vcard_util_v30_number_field_preprocess(S8 *str, U16 length);
#endif /* defined(__MMI_VCARD_V30__) */
#ifdef __MMI_OPP_SUPPORT__
static void mmi_vcard_highlight_forward_bt(void);
static void mmi_vcard_forward_bt(void);
static void mmi_vcard_forward_bt_callback(void *buf_p, U32 result);
#endif /* __MMI_OPP_SUPPORT__ */ 


/*
 * Global Variable
 */
extern const S8 *g_vobj_paras[];
extern const S8 *g_vobj_charset[];
extern const S8 *g_vobj_encoding[];

extern U16 g_phb_name_index[];
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
extern PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
extern S8 pbName[];
extern S8 pbNumber[];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
extern S8 pbHomeNumber[];
extern S8 pbCompanyName[];
extern S8 pbEmailAddress[];
extern S8 pbOfficeNumber[];
extern S8 pbFaxNumber[];
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
extern const kal_uint8 g_dt_day_per_mon[];
extern S8 pbDay[];
extern S8 pbMon[];
extern S8 pbYear[];
extern S8 pbBday[];
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */ 

#if defined(__MMI_PHB_INFO_FIELD__)
extern PHB_INFO_FIELDS_STRUCT PhoneBookInfoFields;
extern S8 pbTitle[];
extern S8 pbUrl[];
extern S8 pbAddress[];
extern S8 pbNote[];
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 

extern U16 TitleStrings[];

extern U8 g_phb_enter_from;
extern MMI_PHB_LIST_VIEW phbListView;

/*
 * Global Function
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_init
 * DESCRIPTION
 *  Initialize function of vcard application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* vcard forward highlight handler. */
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    SetHiliteHandler(MENU_ID_VCARD_FORWARD_SMS, mmi_vcard_highlight_forward_sms);
#endif 
#if defined(__MMI_MMS__)
    SetHiliteHandler(MENU_ID_VCARD_FORWARD_MMS, mmi_vcard_highlight_forward_mms);
#endif 
#if defined(__MMI_IRDA_SUPPORT__)
    SetHiliteHandler(MENU_ID_VCARD_FORWARD_IRDA, mmi_vcard_highlight_forward_irda);
#endif 
#if defined(EMAIL_APP_SUPPORT)
    SetHiliteHandler(MENU_ID_VCARD_FORWARD_EMAIL, mmi_vcard_highlight_forward_email);
#endif 
#if defined(__MMI_FILE_MANAGER__)
    SetHiliteHandler(MENU_ID_VCARD_FORWARD_FMGR, mmi_vcard_highlight_forward_fmgr);
#endif 

#if defined(__MMI_OPP_SUPPORT__)
    SetHiliteHandler(MENU_ID_VCARD_FORWARD_BT, mmi_vcard_highlight_forward_bt);
#endif 

    /* vcard save file enter file name option highlight handler */
#if defined(__MMI_FILE_MANAGER__)
    SetHiliteHandler(MENU_ID_VCARD_ENTER_FILENAME_OPT_DONE, mmi_vcard_highlight_enter_filename_done);
    SetHiliteHandler(MENU_ID_VCARD_ENTER_FILENAME_OPT_INPUT_METHOD, mmi_vcard_highlight_enter_filename_input_method);
#endif /* defined(__MMI_FILE_MANAGER__) */ 

    /* vcard receive option highlight handler. */
    SetHiliteHandler(MENU_ID_VCARD_RECV_OPTION_TO_SIM, mmi_vcard_highlight_recv_save_to_sim);
#ifdef __MMI_DUAL_SIM_MASTER__
    SetHiliteHandler(MENU_MTPNP_VCARD_RECV_OPTION_TO_SIM, HighlightVcardRecvSaveToSim);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetHiliteHandler(MENU_ID_VCARD_RECV_OPTION_TO_PHONE, mmi_vcard_highlight_recv_save_to_phone);
#if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)
    SetHiliteHandler(MENU_ID_VCARD_RECV_OPTION_FMGR, mmi_vcard_highlight_recv_save_to_fmgr);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_deinit
 * DESCRIPTION
 *  Deinitialize function of vcard application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vcard_free_path_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_free_path_buffer
 * DESCRIPTION
 *  Free allocate file path buffer when exit vcard application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_free_path_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vcard_cntx.FilePathPtr)
    {
        OslMfree(g_vcard_cntx.FilePathPtr);
        g_vcard_cntx.FilePathPtr = NULL;
    }
    if (g_vcard_cntx.FileNamePtr)
    {
        OslMfree(g_vcard_cntx.FileNamePtr);
        g_vcard_cntx.FileNamePtr = NULL;
    }
}

/*--------------------------------------------------BEGIN vCard Forward operation ---------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_option_my_card
 * DESCRIPTION
 *  Pre - Entry function of vcard forward option, will call by phonebook application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_option_my_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vcard_cntx.CardType = MMI_VCARD_SEND_MY_CARD;
    mmi_vcard_entry_forward_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_option_select_card
 * DESCRIPTION
 *  Pre - Entry function of vcard forward option, will call by phonebook application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_option_select_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vcard_cntx.CardType = MMI_VCARD_SEND_SELECT_CARD;
    mmi_vcard_entry_forward_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_entry_forward_option
 * DESCRIPTION
 *  Entry function of vcard forward option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_entry_forward_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;

    MMI_PHB_VCARD_STRUCT myCard;
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __USB_IN_NORMAL_MODE__
        S8 path[VOBJ_MAX_PATH_LENGTH];
        mmi_vobj_get_full_path_name(0, path, MMI_VOBJ_UNRECOGNIZED);   
        if (mmi_usb_is_in_mass_storage_mode())
        {
            /* in mass storage mode */
            if (mmi_usb_check_path_exported((PS8) path))
            {
                /* phone drive is exported, cant use this app */
                mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
                return;
            }
        }
    #endif /* __USB_IN_NORMAL_MODE__ */    

    /* Check if the name field is empy before send vCard */
    if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
    {
        ReadRecord(NVRAM_EF_PHB_VCARD_LID, 1, (void*)&myCard, MMI_PHB_VCARD_RECORD_SIZE, &pError);
        if (!mmi_ucs2strlen(myCard.name))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VCARD_NAME_EMPTY),
                IMG_GLOBAL_ERROR,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
    }
    else
    {
        if (!mmi_ucs2strlen((S8*) PhoneBook[g_phb_name_index[g_phb_cntx.active_index]].alpha_id.name))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VCARD_NAME_EMPTY),
                IMG_GLOBAL_ERROR,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
    }

    mmi_vcard_init();   /* Regiser highlight handler again. */
    EntryNewScreen(SCR_ID_VCARD_FORWARD_OPTION, mmi_vcard_exit_forward_option, mmi_vcard_entry_forward_option, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_VCARD_FORWARD_OPTION, (HistoryDelCBPtr)mmi_vcard_forward_option_delete_cb);

    /* unhide all menu */
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    mmi_frm_unhide_menu_item(MENU_ID_VCARD_FORWARD_SMS);
#endif
#if defined(__MMI_MMS__)
    mmi_frm_unhide_menu_item(MENU_ID_VCARD_FORWARD_MMS);
#endif
#if  defined(__MMI_IRDA_SUPPORT__)	 
    mmi_frm_unhide_menu_item(MENU_ID_VCARD_FORWARD_IRDA);
#endif		
#ifdef __MMI_OPP_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_VCARD_FORWARD_BT);
#endif
//#if  defined(EMAIL_APP_SUPPORT)
//    mmi_frm_unhide_menu_item(MENU_ID_VCARD_FORWARD_EMAIL);
//#endif	
    /* unhide all menu */

   /* hide menu */
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_VCARD_FORWARD_SMS);        
    }
#endif

#if defined(MMS_SUPPORT)
    if (!mms_is_ready())
    {
        mmi_frm_hide_menu_item(MENU_ID_VCARD_FORWARD_MMS);    
    }
#endif

//#if  defined(EMAIL_APP_SUPPORT)
//    mmi_frm_hide_menu_item(MENU_ID_VCARD_FORWARD_EMAIL);
//#endif	

#if defined (__FLIGHT_MODE_SUPPORT__)
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
    #if  defined(__MMI_IRDA_SUPPORT__)
        mmi_frm_hide_menu_item(MENU_ID_VCARD_FORWARD_IRDA);
    #endif
    #if defined(__MMI_OPP_SUPPORT__)
        mmi_frm_hide_menu_item(MENU_ID_VCARD_FORWARD_BT);    
    #endif    
    }
#endif

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCARD_FORWARD_OPTION);
    nNumofItem = GetNumOfChild_Ext(MENU_ID_VCARD_FORWARD_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_VCARD_FORWARD_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_VCARD_FORWARD_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_PHB_VCARD_SEND_ENTRY,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_exit_forward_option
 * DESCRIPTION
 *  Exit function of vcard forward option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_exit_forward_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_VCARD_FORWARD_OPTION;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_option_delete_cb
 * DESCRIPTION
 *  Delete cb function of vcard forward option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vcard_forward_option_delete_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 path[VOBJ_MAX_PATH_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vcard_util_get_default_file(path);   
    FS_Delete((U16*) path);
    
    return MMI_FALSE;
}


#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_forward_sms
 * DESCRIPTION
 *  Highlight function of forward vcard through SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_forward_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_sms, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vcard_forward_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_sms
 * DESCRIPTION
 *  forward vcard thorugh SMS, will create vcard object into file and call SMS function to send.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path;
    S32 result;
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create file path and folder. */
    if (check_result == FS_NO_ERROR)
    {
        path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        mmi_vcard_util_get_default_file(path);

        if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
        {
            result = mmi_vcard_writer_v21_mycard_to_file(path);
        }
        else
        {
            result = mmi_vcard_writer_v21_select_card_to_file(path);
        }
        if (result != VOBJ_ERR_NO_ERROR)
        {
            FS_Delete((U16*) path);
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            OslMfree(path);
            return;
        }
        mmi_ems_vobject_send_by_ems(VOBJ_SRC_PORT, VOBJ_VCARD_PORT, path, mmi_vcard_forward_sms_call_back);
        OslMfree(path);
    }
    else
    {
        /* Error Handling here. */
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_sms_call_back
 * DESCRIPTION
 *  call back function of send vcard through SMS, will get error cause from SMS
 *  should go back to proper screen when send finish.
 * PARAMETERS
 *  flag        [IN]        Result of send vcard through SMS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_sms_call_back(void *flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vcard_util_del_default_file();
    DeleteScreenIfPresent(SCR_ID_VCARD_FORWARD_OPTION);

    //if(g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
    //DeleteUptoScrID(SCR_ID_PHB_VCARD_MYCARD);
    //else
    //DeleteUptoScrID(SCR_PBOOK_ENTRY_OPTIONS);
}
#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */ // #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)

#if defined(__MMI_MMS__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_forward_mms
 * DESCRIPTION
 *  Highlight function for send vcard through MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_forward_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_mms, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vcard_forward_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_mms
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path;
    S32 result;
    S32 check_result = mmi_vobj_fs_check_folder();
    mms_content_entry_struct data;
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create file path and folder. */
    if (check_result == FS_NO_ERROR)
    {
        path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        mmi_vcard_util_get_default_file_name(path);
        fh = FS_Open((U16*) path, FS_CREATE_ALWAYS | FS_READ_WRITE);
        FS_Close(fh);
        if (fh == FS_INVALID_FILENAME)
        {
            mmi_vcard_util_get_default_file(path);
        }
        if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
        {
            result = mmi_vcard_writer_v21_mycard_to_file(path);
        }
        else
        {
            result = mmi_vcard_writer_v21_select_card_to_file(path);
        }
        if (result != VOBJ_ERR_NO_ERROR)
        {
            FS_Delete((U16*) path);
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            OslMfree(path);
            return;
        }

        memset(&data, 0x00, sizeof(mms_content_entry_struct));
        data.mode = MEA_NEW_FILE;
        data.file_path = path;
        data.callback = mmi_vcard_forward_mms_call_back;
        data.callback_param = path;
        mms_content_insert_hdlr_with_callback(&data);
    }
    else
    {
        /* Error Handling here. */
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_mms_call_back
 * DESCRIPTION
 *  call back function of send vcard through MMS, will get error cause from MMS
 *  should go back to proper screen when send finish.
 * PARAMETERS
 *  flag        [IN]        Result of send vcard through SMS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_mms_call_back(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Delete((U16*) param);
    OslMfree(param);
    DeleteScreenIfPresent(SCR_ID_VCARD_FORWARD_OPTION);

    //if(g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
    //DeleteUptoScrID(SCR_ID_PHB_VCARD_MYCARD);
    //else
    //DeleteUptoScrID(SCR_PBOOK_ENTRY_OPTIONS);
}
#endif /* defined(__MMI_MMS__) */ /* END #if defined(__MMI_MMS__) */

#if defined(__MMI_IRDA_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_forward_irda
 * DESCRIPTION
 *  highlight function for forward vcard to IrDA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_forward_irda(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_irda, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vcard_forward_irda, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_irda
 * DESCRIPTION
 *  Forward vcard thorugh IrDA, will create vcard object into file and call IrDA function to send.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_irda(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path;
    S32 result;
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create file path and folder. */
    if (check_result == FS_NO_ERROR)
    {
        path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        mmi_vcard_util_get_default_file(path);

        if (mmi_ucs2strlen(path) > 0)
        {
            if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
            {
                result = mmi_vcard_writer_v21_mycard_to_file(path);
            }
            else
            {
                result = mmi_vcard_writer_v21_select_card_to_file(path);
            }

            if (result != VOBJ_ERR_NO_ERROR)
            {
                FS_Delete((U16*) path);
                DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(result)),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                OslMfree(path);
                return;
            }

            if (MMI_IRDA_ERR_SUCCESS == mmi_irda_send_file_obj(path, mmi_vcard_forward_irda_callback))
            {
                mmi_vobj_entry_irda_processing_screen();
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }

        OslMfree(path);
    }
    else
    {
        /* Error Handling Here. */
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_irda_callback
 * DESCRIPTION
 *  call back function for forward vcard through IrDA, will bring error cause.
 *  If send vcard through IrDA by using SRAM instead of file, also free buffer here.
 * PARAMETERS
 *  buf_p       [IN]        Buffer to release
 *  result      [IN]        Error cause
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_irda_callback(void *buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vcard_util_del_default_file();

    /* Free buffer if send to IrDA by using SRAM */
    if (buf_p != NULL)
    {
        OslMfree(buf_p);
        buf_p = NULL;
    }

    if (result == MMI_IRDA_ERR_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    DeleteBetweenScreen(SCR_ID_VCARD_FORWARD_OPTION, SCR_ID_VOBJ_IRDA_FORWARD_PROCESSING);

    //if(g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
    //DeleteUptoScrID(SCR_ID_PHB_VCARD_MYCARD);
    //else
    //DeleteUptoScrID(SCR_PBOOK_ENTRY_OPTIONS);

}
#endif /* defined(__MMI_IRDA_SUPPORT__) */ /* END of #if  defined(__MMI_IRDA_SUPPORT__) */

#if defined(__MMI_OPP_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_forward_bt
 * DESCRIPTION
 *  highlight function for forward vcard to Blue Tooth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcard_highlight_forward_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_bt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vcard_forward_bt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_bt
 * DESCRIPTION
 *  Forward vcard thorugh Blue Tooth, will create vcard object into file and call IrDA function to send.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcard_forward_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path;
    S32 result;
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create file path and folder. */
    if (check_result == FS_NO_ERROR)
    {
        path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        mmi_vcard_util_get_default_file(path);

        if (mmi_ucs2strlen(path) > 0)
        {
            if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
            {
                result = mmi_vcard_writer_v21_mycard_to_file(path);
            }
            else
            {
                result = mmi_vcard_writer_v21_select_card_to_file(path);
            }

            if (result != VOBJ_ERR_NO_ERROR)
            {
                FS_Delete((U16*) path);
                DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(result)),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                OslMfree(path);
                return;
            }

            if (MMI_OPP_ERR_SUCCESS == mmi_opp_discovery_device((PS8) path, mmi_vcard_forward_bt_callback))
            {
                mmi_opp_entry_opp_device_discovery();
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }

        OslMfree(path);
    }
    else
    {
        /* Error Handling Here. */
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_bt_callback
 * DESCRIPTION
 *  call back function for forward vcard through Blue Tooth, will bring error cause.
 *  If send vcard through Blue Tooth by using SRAM instead of file, also free buffer here.
 * PARAMETERS
 *  buf_p       [IN]        Buffer to release
 *  result      [IN]        Error cause
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcard_forward_bt_callback(void *buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vcard_util_del_default_file();

    /* Free buffer if send to bt by using SRAM */
    if (buf_p != NULL)
    {
        OslMfree(buf_p);
        buf_p = NULL;
    }

    if (result == MMI_OPP_ERR_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    DeleteBetweenScreen(SCR_ID_VCARD_FORWARD_OPTION, SCR_OPP_SENDING);
}
#endif /* defined(__MMI_OPP_SUPPORT__) */ 


#if defined(EMAIL_APP_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_forward_email
 * DESCRIPTION
 *  Highlight function for forward to email app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_forward_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_email, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vcard_forward_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_email
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_ID_VOBJ_FUNC_NOT_SUPPORTED),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE);
}
#endif /* defined(EMAIL_APP_SUPPORT) */ /* END #if defined(EMAIL_APP_SUPPORT) */


#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_forward_fmgr
 * DESCRIPTION
 *  highlight function for save vcard to file manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_forward_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_fmgr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vcard_forward_fmgr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_vcard_cntx.FileLoc = MMI_VCARD_SAVE_TO_FILE_FROM_PHB;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_enter_filename_done
 * DESCRIPTION
 *  highlight function for forward vcard to file manger enter name done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_enter_filename_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_fmgr_enter_filename_done, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_goback_1_history
 * DESCRIPTION
 *  Go back 1 history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_goback_1_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_enter_filename_input_method
 * DESCRIPTION
 *  highlight function for save vcard to file manager enter name change input method.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_enter_filename_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(IMG_SCR_PBOOK_CAPTION);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);

    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_vcard_goback_1_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_entry_enter_filename
 * DESCRIPTION
 *  entry function for enter file name after select file path from file manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_entry_enter_filename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(SCR_ID_VCARD_ENTER_FILENAME, mmi_vcard_exit_enter_filename, mmi_vcard_entry_enter_filename,NULL); */
    EntryNewScreen(SCR_ID_VCARD_ENTER_FILENAME, mmi_vcard_exit_enter_filename, mmi_vcard_entry_enter_filename, NULL);
    SetParentHandler(0);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCARD_ENTER_FILENAME);

    ShowCategory5Screen(
        STR_ID_VOBJ_FILENAME,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_vcard_cntx.FileNamePtr,
        VOBJ_MAX_FILENAME_LENGTH / ENCODING_LENGTH, /* Use same length as other application. */
        guiBuffer);                                 /*===> also change related size of g_vcard_cntx.FileNamePtr */

    SetLeftSoftkeyFunction(mmi_vcard_entry_enter_filename_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* SetGenericExitHandler(SCR_ID_VCARD_ENTER_FILENAME, mmi_vcard_exit_enter_filename, mmi_vcard_entry_enter_filename); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_exit_enter_filename
 * DESCRIPTION
 *  Exit function for enter file name. Will keep screen ID only when enter from phonebook.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_exit_enter_filename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
    {
        g_phb_cntx.end_scr_id = SCR_ID_VCARD_ENTER_FILENAME;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_entry_enter_filename_option
 * DESCRIPTION
 *  entry function of options for save vcard to file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_entry_enter_filename_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[2];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(
        SCR_ID_VCARD_ENTER_FILENAME_OPT,
        mmi_vcard_exit_enter_filename_option,
        mmi_vcard_entry_enter_filename_option,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCARD_ENTER_FILENAME_OPT);
    SetParentHandler(MENU_ID_VCARD_ENTER_FILENAME_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    nItems = GetNumOfChild(MENU_ID_VCARD_ENTER_FILENAME_OPT);
    GetSequenceStringIds(MENU_ID_VCARD_ENTER_FILENAME_OPT, ItemList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* SetGenericExitHandler(SCR_ID_VCARD_ENTER_FILENAME_OPT, mmi_vcard_exit_enter_filename_option, mmi_vcard_entry_enter_filename_option); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_exit_enter_filename_option
 * DESCRIPTION
 *  exit function of options for save vcard to file, only keep screen id when enter from phonebook.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_exit_enter_filename_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
    {
        g_phb_cntx.end_scr_id = SCR_ID_VCARD_ENTER_FILENAME_OPT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_fmgr
 * DESCRIPTION
 *  save vcard to file manager, file manager will take over screen after calling.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_PHONEBOOK,
        FMGR_SELECT_FOLDER,
        filter,
        (S8*) L"root",
        mmi_vcard_forward_fmgr_select_path_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_fmgr_select_path_done
 * DESCRIPTION
 *  call back function of save vcard to file manager, will bring back selected file path
 * PARAMETERS
 *  path            [IN]        Selected file path
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_fmgr_select_path_done(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. Go Back To Upto forward option or recv option. */
    {
        if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
        {
            GoBackToHistory(SCR_ID_VCARD_FORWARD_OPTION);
        }
        else    /* MMI_VCARD_SAVE_TO_FILE_FROM_RECV */
        {
            GoBackToHistory(SCR_ID_VCARD_RECV_OPT);
        }

        return;
    }

    if (g_vcard_cntx.FilePathPtr == NULL)   /* Should free after save or free in deinit func. */
    {
        g_vcard_cntx.FilePathPtr = OslMalloc(VOBJ_MAX_PATH_LENGTH);
    }

    mmi_ucs2cpy(g_vcard_cntx.FilePathPtr, (S8*) path);

    /* Enter File Name before save */
    mmi_vcard_forward_fmgr_pre_enter_filename();

    /* Delete all screens for selecting file path. Upto forward option or recv option. */
    if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
    {
        DeleteUptoScrID(SCR_ID_VCARD_FORWARD_OPTION);
    }
    else    /* MMI_VCARD_SAVE_TO_FILE_FROM_RECV */
    {
        DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_fmgr_pre_enter_filename
 * DESCRIPTION
 *  create filename buffer for input,
 *  Also bring name field as default file name, if user forward a vcard from phonebook.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_fmgr_pre_enter_filename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_PHB_VCARD_STRUCT myCard;
    S16 pError;
    U16 length;
    S8* temp_filename;
    S8* temp_ptr;
    U16 temp_filename_length = (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vcard_cntx.FileNamePtr == NULL)   /* Should free after save or free in deinit func. */
    {
        g_vcard_cntx.FileNamePtr = OslMalloc(VOBJ_MAX_FILENAME_LENGTH);
    }

    /* Create default file name. */
    if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
    {
        if (VOBJ_MAX_FILENAME_LENGTH > (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH)
        {
            length = (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH;
        }
        else
        {
            length = VOBJ_MAX_FILENAME_LENGTH;
        }

        temp_filename = OslMalloc(temp_filename_length);
        if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
        {
            ReadRecord(NVRAM_EF_PHB_VCARD_LID, 1, (void*)&myCard, MMI_PHB_VCARD_RECORD_SIZE, &pError);
            memcpy(temp_filename, myCard.name, temp_filename_length);
        }
        else
        {
            memcpy(
                temp_filename,
                PhoneBook[g_phb_name_index[g_phb_cntx.active_index]].alpha_id.name,
                temp_filename_length);
        }
        temp_ptr = mmi_fmgr_skip_space(temp_filename);
        mmi_ucs2cpy(g_vcard_cntx.FileNamePtr, temp_ptr);
        OslMfree(temp_filename);
    }
    else
    {
        memset(g_vcard_cntx.FileNamePtr, 0, VOBJ_MAX_FILENAME_LENGTH);
    }

    mmi_vcard_entry_enter_filename();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_fmgr_enter_filename_done
 * DESCRIPTION
 *  enter file name done, save vcard to destination path and handle the error message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_fmgr_enter_filename_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
    {
        result = mmi_vcard_forward_fmgr_save_file();
    }
    else
    {
        result = mmi_vcard_recv_move_obj_to_file();

        if (result == VOBJ_ERR_NO_ERROR)    /* Send message to copy, handle result in callback */
        {
            return;
        }
    }

    mmi_vcard_forward_fmgr_save_file_done(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_fmgr_save_file
 * DESCRIPTION
 *  save vcard to the destination file path
 * PARAMETERS
 *  void
 * RETURNS
 *  S32   error cause
 *****************************************************************************/
S32 mmi_vcard_forward_fmgr_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 filename[VOBJ_MAX_FILE_EXT_LEN];
    FS_HANDLE fh;
    U16 path_len;
    U16 name_len;
    S32 result;
    S8* temp_filename;
    S8* temp_ptr;
    U16 temp_filename_length = VOBJ_MAX_FILENAME_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_vcard_cntx.FilePathPtr != NULL);
    path_len = mmi_ucs2strlen(g_vcard_cntx.FilePathPtr);

    MMI_ASSERT(g_vcard_cntx.FileNamePtr != NULL);
    name_len = mmi_ucs2strlen(g_vcard_cntx.FileNamePtr);

    temp_filename = OslMalloc(temp_filename_length);
    memset(temp_filename, 0, sizeof(temp_filename));
    temp_ptr = mmi_fmgr_skip_space(g_vcard_cntx.FileNamePtr);
    mmi_ucs2ncpy(temp_filename, temp_ptr, (temp_filename_length - 1));

    /* Check if name empty */
    if (mmi_ucs2strlen(temp_filename) == 0)
    {
        OslMfree(temp_filename);
        return VOBJ_ERR_EMPTY_NAME;
    }

    /* Check if file path is too long */
    if ((path_len + name_len + VOBJ_MAX_FILE_EXT_LEN / ENCODING_LENGTH) > VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH)
    {
        OslMfree(temp_filename);
        return VOBJ_ERR_SELECT_PATH_TOO_LONG;
    }

    /* Check if file name contain '/' or '\' */
    if (!mmi_fmgr_is_filename_valid(temp_filename))
    {
        OslMfree(temp_filename);
        return VOBJ_ERR_INVALID_FILENAME;
    }

    /* Concatenate file path */
    mmi_ucs2cat(g_vcard_cntx.FilePathPtr, temp_filename);
    OslMfree(temp_filename);
    mmi_asc_to_ucs2(filename, VOBJ_VCARD_FILE_EXT);
    mmi_ucs2cat(g_vcard_cntx.FilePathPtr, filename);

    /* Test if file already exists. */
    fh = FS_Open((U16*) g_vcard_cntx.FilePathPtr, FS_READ_ONLY);
    if (fh > 0)
    {
        FS_Close(fh);
        memset((g_vcard_cntx.FilePathPtr + path_len * ENCODING_LENGTH), 0, 2);  /* Clear file name concatenate after path */
        return VOBJ_ERR_DUPLICATE_NAME;
    }

    if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
    {
        result = mmi_vcard_writer_v21_mycard_to_file(g_vcard_cntx.FilePathPtr);
    }
    else
    {
        result = mmi_vcard_writer_v21_select_card_to_file(g_vcard_cntx.FilePathPtr);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_forward_fmgr_save_file_done
 * DESCRIPTION
 *  save vcard to the destination file path
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_forward_fmgr_save_file_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case VOBJ_ERR_NO_ERROR:
            mmi_vcard_free_path_buffer();
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);

            if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
            {
                if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
                {
                    DeleteUptoScrID(SCR_ID_PHB_VCARD_MYCARD);
                }
                else
                {
                    DeleteUptoScrID(SCR_PBOOK_ENTRY_OPTIONS);
                }
            }
            else
            {
                mmi_vobj_clear_one_file_buffer();
                DeleteNScrId(SCR_ID_VCARD_RECV_OPT);
                DeleteScreenIfPresent(SCR_ID_VOBJ_RECV_OBJECT);
            }

            break;
        case VOBJ_ERR_EMPTY_NAME:
            DisplayPopup(
                (PU8) GetString(STR_ID_VOBJ_EMPTY_FILENAME),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_VCARD_ENTER_FILENAME);
            break;
        case VOBJ_ERR_DUPLICATE_NAME:
            DisplayPopup(
                (PU8) GetString(STR_ID_VOBJ_DUPLICATE_FILENAME),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_VCARD_ENTER_FILENAME);
            break;
        case VOBJ_ERR_INVALID_FILENAME:
            DisplayPopup(
                (PU8) GetString(STR_ID_VOBJ_INVALID_FILENAME),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_VCARD_ENTER_FILENAME);
            break;
        case VOBJ_ERR_SELECT_PATH_TOO_LONG:
            DisplayPopup(
                (PU8) GetString(STR_ID_VOBJ_FILE_PATH_TOO_LONG),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
            {
                DeleteUptoScrID(SCR_ID_VCARD_FORWARD_OPTION);
            }
            else
            {
                DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
            }

            break;
        case VOBJ_ERR_UNKNOWN:
            if (g_vcard_cntx.FilePathPtr)
            {
                FS_Delete((U16*) g_vcard_cntx.FilePathPtr);
            }
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
            {
                DeleteUptoScrID(SCR_ID_VCARD_FORWARD_OPTION);
            }
            else
            {
                DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
            }
            break;
        default:
            if (g_vcard_cntx.FilePathPtr)
            {
                FS_Delete((U16*) g_vcard_cntx.FilePathPtr);
            }
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            if (g_vcard_cntx.FileLoc == MMI_VCARD_SAVE_TO_FILE_FROM_PHB)
            {
                DeleteUptoScrID(SCR_ID_VCARD_FORWARD_OPTION);
            }
            else
            {
                DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
            }
            break;
    }
}

#endif /* defined(__MMI_FILE_MANAGER__) */
/*--------------------------------------------------END vCard Forward operation ---------------------------------------------------*/



/*--------------------------------------------------BEGIN vCard Received operation ---------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_recv_save_to_sim
 * DESCRIPTION
 *  highlight function for options "save to SIM" of receiving a vcard.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_recv_save_to_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_recv_view_detail_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_vcard_recv_view_detail_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    g_vcard_cntx.StorageLoc = MMI_SIM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_recv_save_to_phone
 * DESCRIPTION
 *  highlight function for options "save to Phone" of receiving a vcard.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_recv_save_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_recv_view_detail_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_vcard_recv_view_detail_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    g_vcard_cntx.StorageLoc = MMI_NVRAM;
}


#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_highlight_recv_save_to_fmgr
 * DESCRIPTION
 *  highlight function for options "save to file" of receiving a vcard.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_highlight_recv_save_to_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_fmgr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vcard_forward_fmgr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    g_vcard_cntx.FileLoc = MMI_VCARD_SAVE_TO_FILE_FROM_RECV;
}
#endif /* __MMI_FILE_MANAGER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_entry_recv_option
 * DESCRIPTION
 *  Entry screen of save a vcard option. It can save to SIM, NVRAM or File manager.
 *  If forward from file manager, there's no "Save to File" option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_entry_recv_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    U8 hilitedStorage = 0;
    U8 hilight_sim, highlight_phone;
#ifdef __MMI_DUAL_SIM_MASTER__
    U8 hilight_SlaveSIM;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vcard_init();   /* Regiser highlight handler again. */

    EntryNewScreen(SCR_ID_VCARD_RECV_OPT, NULL, mmi_vcard_entry_recv_option, NULL);

    mmi_frm_unhide_menu_item(MENU_ID_VCARD_RECV_OPTION_TO_SIM);
#ifdef __MMI_DUAL_SIM_MASTER__        
    mmi_frm_unhide_menu_item(MENU_MTPNP_VCARD_RECV_OPTION_TO_SIM);
#endif
#if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)	    
    mmi_frm_unhide_menu_item(MENU_ID_VCARD_RECV_OPTION_FMGR);
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__) */

    if (!mmi_bootup_is_sim_valid())
    {
        mmi_frm_hide_menu_item(MENU_ID_VCARD_RECV_OPTION_TO_SIM);        
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if(!mmi_bootup_is_sim2_valid())
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_VCARD_RECV_OPTION_TO_SIM);        
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)
    if (g_vcard_cntx.ParseLoc == MMI_VCARD_PARSE_FROM_FILE_MANAGER)
    {
        mmi_frm_hide_menu_item(MENU_ID_VCARD_RECV_OPTION_FMGR);
    }
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__) */ 

    hilight_sim = GetIndexOfStringId_Ext(MENU_ID_VCARD_RECV_OPTION, MENU_ID_VCARD_RECV_OPTION_TO_SIM);
    highlight_phone = GetIndexOfStringId_Ext(MENU_ID_VCARD_RECV_OPTION, MENU_ID_VCARD_RECV_OPTION_TO_PHONE);
#ifdef __MMI_DUAL_SIM_MASTER__
    hilight_SlaveSIM = GetIndexOfStringId_Ext(MENU_ID_VCARD_RECV_OPTION, MENU_MTPNP_VCARD_RECV_OPTION_TO_SIM);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    
    if (mmi_bootup_is_sim_valid())
    {
        if (g_phb_cntx.prefer_storage == MMI_SIM)
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            hilitedStorage = hilight_sim;
        #else /* __MMI_DUAL_SIM_MASTER__ */
            if ((g_phb_cntx.sim_used < g_phb_cntx.sim_total) || (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
            {
                hilitedStorage = hilight_sim;
            }
            else
            {
                hilitedStorage = highlight_phone;
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        }
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim2_valid())
    {
        if (g_phb_cntx.prefer_storage == MMI_SIM2)
        {
            hilitedStorage = hilight_SlaveSIM;
        }        
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (g_phb_cntx.prefer_storage == MMI_NVRAM)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        hilitedStorage = highlight_phone;
    #else /* __MMI_DUAL_SIM_MASTER__ */
        if (!mmi_bootup_is_sim_valid() || (g_phb_cntx.phone_used < g_phb_cntx.phone_total) || (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
        {
            hilitedStorage = highlight_phone;
        }
        else
        {
            hilitedStorage = hilight_sim;
        }  
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
        
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCARD_RECV_OPT);
    nNumofItem = GetNumOfChild_Ext(MENU_ID_VCARD_RECV_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_VCARD_RECV_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_VCARD_RECV_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        hilitedStorage,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* SetGenericExitHandler(SCR_ID_VCARD_RECV_OPT, NULL, mmi_vcard_entry_recv_option); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_from_idle_screen
 * DESCRIPTION
 *  A pre-entry function of receiving vcard functuion. This vcard is displayed when in idle screen.
 *  If vcard is received from IrDA or SMS, it will enter from this path.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_recv_from_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vcard_cntx.ParseLoc = MMI_VCARD_PARSE_FROM_VOBJ_BUFFER;
    mmi_vcard_entry_recv_option();
}


#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_from_file_mgr
 * DESCRIPTION
 *  A pre-entry function of receiving vcard functuion. This vcard is forwarded from file manager.
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_recv_from_file_mgr(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        return;
    }

    if (g_vcard_cntx.FilePathPtr == NULL)
    {
        g_vcard_cntx.FilePathPtr = OslMalloc(VOBJ_MAX_PATH_LENGTH);
    }

    mmi_ucs2cpy(g_vcard_cntx.FilePathPtr, path);

    g_vcard_cntx.ParseLoc = MMI_VCARD_PARSE_FROM_FILE_MANAGER;

    mmi_vcard_entry_recv_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_fmgr_sms_forward
 * DESCRIPTION
 *  Forward vcard to SMS from file manager.
 *  This is a intermediate function between file manager and SMS app.
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_fmgr_sms_forward(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    mmi_ems_vobject_send_by_ems(VOBJ_SRC_PORT, VOBJ_VCARD_PORT, path, NULL);
#endif 
}
#endif /* defined(__MMI_FILE_MANAGER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_entry_recv_view_detail
 * DESCRIPTION
 *  This is the detail message of a vcard after parsing. Show details to users before saving.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_entry_recv_view_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pbEntry[MAX_PB_FIELDS];
    U16 DetailPbNameImageList[MAX_PB_FIELDS];
    U8 *guiBuffer;
    U8 j = 0;
#if defined(__PHB_0x81_SUPPORT__)  
    U8 ucs2_0x81_name_length;
    S8 ucs2_0x81_name[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
#endif /* defined(__PHB_0x81_SUPPORT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_VCARD_RECV_VIEW_DETAIL, NULL, mmi_vcard_entry_recv_view_detail, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCARD_RECV_VIEW_DETAIL);

    /* Parse again if not first get in. */
    if (guiBuffer != NULL)
    {
        mmi_vcard_recv_parse_file();
    }

    /* RegisterHighlightHandler(); */

    /* Truncated to fit buffer size */
#if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
    memcpy(ucs2_0x81_name, pbName, ((MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH));
    if ((ucs2_0x81_name_length = mmi_phb_convert_to_0x81((S8*) ucs2_0x81_name, TRUE)) > 0)
    {
        U8 pos;
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (g_vcard_cntx.StorageLoc == MMI_NVRAM || !MTPNP_PFAL_Phb_IsReady())		
    #else   /* __MMI_DUAL_SIM_MASTER__ */
        if (g_vcard_cntx.StorageLoc == MMI_NVRAM || !g_phb_cntx.phb_ready)
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        {
            pos = (MAX_PB_NAME_LENGTH - 3) * 2;
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (g_vcard_cntx.StorageLoc == MMI_SIM2)
        {
            pos = (MTPNP_AD_ADN_SIM2GetTagLen() - 3) * 2;
        }
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        else    /* Need phonebook ready to get the Maximum SIM length */
        {
            pos = (g_phb_cntx.sim_name_len - 3) * 2;
        }

        memset(pbName + pos, 0, 2);
    }
    else
#endif /* defined(__PHB_0x81_SUPPORT__) */ 
    if (GetUCS2Flag(pbName))
    {
        U8 pos;
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (g_vcard_cntx.StorageLoc == MMI_NVRAM || !MTPNP_PFAL_Phb_IsReady())		
    #else /* __MMI_DUAL_SIM_MASTER__ */
        if (g_vcard_cntx.StorageLoc == MMI_NVRAM || !g_phb_cntx.phb_ready)
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        {
            pos = ((MAX_PB_NAME_LENGTH - 1) / 2) * 2;
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (g_vcard_cntx.StorageLoc == MMI_SIM2)
        {
            pos = ((MTPNP_AD_ADN_SIM2GetTagLen() - 1) / 2) * 2;
        }
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        else    /* Need phonebook ready to get the Maximum SIM length */
        {
            pos = ((g_phb_cntx.sim_name_len - 1) / 2) * 2;
        }

        memset(pbName + pos, 0, 2);
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)		
#else /* __MMI_DUAL_SIM_MASTER__ */
    else if (g_phb_cntx.phb_ready)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        U8 ex_count = 0;
        U8 ex_len = 1; /* need second bytes */
        U8 buffer_len = mmi_ucs2strlen(pbName) * ENCODING_LENGTH;
        U8 max_name_ln;
        if (g_vcard_cntx.StorageLoc == MMI_SIM && g_phb_cntx.sim_name_len < MAX_PB_NAME_LENGTH)
        {
            max_name_ln = g_phb_cntx.sim_name_len;
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (g_vcard_cntx.StorageLoc == MMI_SIM2 && MTPNP_AD_ADN_SIM2GetTagLen() < MAX_PB_NAME_LENGTH)
        {
            max_name_ln = MTPNP_AD_ADN_SIM2GetTagLen();
        }
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        else
        {
            max_name_ln = MAX_PB_NAME_LENGTH;
        }
        while (ex_count < max_name_ln && ex_len < buffer_len)
        {
            UI_character_type ch;
            ch = ((UI_character_type) pbName[ex_len] << 8) | ((UI_character_type) pbName[ex_len - 1]);
            if (UI_TEST_GSM_EXTENDED(ch))
            {
                ex_count++;
            }
            ex_count++;
            ex_len += 2;
        }
        ex_len--;
        if (max_name_ln < ex_count && ex_len > 2)
        {
            ex_len = ex_len - 2;
        }
        memset(pbName + ex_len, 0, 2);
    }

    /* begin to associate to inline editor */
    pbEntry[j] = pbName;
    DetailPbNameImageList[j] = IMG_NAME;
    TitleStrings[j++] = STR_ID_PHB_NAME;

    pbEntry[j] = pbNumber;
    DetailPbNameImageList[j] = IMG_MOBILE_NUMBER;
    TitleStrings[j++] = STR_ID_PHB_MOBILE_NUMBER;

    if (g_vcard_cntx.StorageLoc == MMI_NVRAM)
    {
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    	
        if(mmi_ucs2strlen(pbHomeNumber))
        {
            pbEntry[j] = pbHomeNumber;
            TitleStrings[j] = STR_HOME_NUMBER;
            DetailPbNameImageList[j++] = IMG_HOME_NUMBER;
        }
    	if(mmi_ucs2strlen(pbCompanyName))
    	{
            pbEntry[j] = pbCompanyName;
            TitleStrings[j] = STR_COMPNAY_NAME;
            DetailPbNameImageList[j++] = IMG_COMPANY_NAME;
        }
     	if(mmi_ucs2strlen(pbEmailAddress))
    	{
            pbEntry[j] = pbEmailAddress;
            TitleStrings[j] = STR_EMAIL_ADRESS;
            DetailPbNameImageList[j++] = IMG_EMAIL_ADDRESS;
        }
    	if(mmi_ucs2strlen(pbOfficeNumber))
    	{
            pbEntry[j] = pbOfficeNumber;
            TitleStrings[j] = STR_OFFICE_NUMBER;
            DetailPbNameImageList[j++] = IMG_OFFICE_NUMBER;
        }
    	if(mmi_ucs2strlen(pbFaxNumber))
    	{
            pbEntry[j] = pbFaxNumber;
            TitleStrings[j] = STR_FAX_NUMBER;
            DetailPbNameImageList[j++] = IMG_FAX_NUMBER;
        }
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)*/

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        if (mmi_ucs2cmp((const S8*)pbYear, (const S8*)MMI_PHB_BDAY_YEAR_STR) != 0 ||
            mmi_ucs2cmp((const S8*)pbMon, (const S8*)MMI_PHB_BDAY_MON_STR) != 0 ||
            mmi_ucs2cmp((const S8*)pbDay, (const S8*)MMI_PHB_BDAY_DAY_STR) != 0)
        {
            mmi_phb_bday_editor_callback((U8*) pbBday, (U8*) pbDay, (U8*) pbMon, (U8*) pbYear);
            pbEntry[j] = pbBday;
            TitleStrings[j] = STR_ID_PHB_BIRTHDAY;
            DetailPbNameImageList[j++] = IMG_ID_PHB_BIRTHDAY;
        }
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

    #if defined(__MMI_PHB_INFO_FIELD__)
    	if(mmi_ucs2strlen(pbTitle))
    	{
            pbEntry[j] = pbTitle;
            TitleStrings[j] = STR_ID_PHB_TITLE;
            DetailPbNameImageList[j++] = IMG_ID_PHB_TITLE;
        }
     	if(mmi_ucs2strlen(pbUrl))
    	{       
            pbEntry[j] = pbUrl;
            TitleStrings[j] = STR_ID_PHB_URL;
            DetailPbNameImageList[j++] = IMG_ID_PHB_URL;
        }
     	if(mmi_ucs2strlen(pbAddress))
    	{  
            pbEntry[j] = pbAddress;
            TitleStrings[j] = STR_ID_PHB_ADDRESS;
            DetailPbNameImageList[j++] = IMG_ID_PHB_ADDRESS;
        }
     	if(mmi_ucs2strlen(pbNote))
    	{  
            pbEntry[j] = pbNote;
            TitleStrings[j] = STR_ID_PHB_NOTE;
            DetailPbNameImageList[j++] = IMG_ID_PHB_NOTE;
        }
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
    }

    ShowCategory84Screen(
        STR_ID_VOBJ_RECV_VCARD,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_SAVE,
        0,
        STR_GLOBAL_BACK,
        0,
        j,
        (U8 **) pbEntry,
        DetailPbNameImageList,
        0,
        0,
        guiBuffer);

    ChangeLeftSoftkey(STR_GLOBAL_SAVE, 0);
    SetLeftSoftkeyFunction(mmi_vcard_recv_save_obj_to_phb, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif 

    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* SetGenericExitHandler(SCR_ID_VCARD_RECV_VIEW_DETAIL, NULL, mmi_vcard_entry_recv_view_detail); */

    if (g_vcard_cntx.ParseLoc == MMI_VCARD_PARSE_FROM_VOBJ_BUFFER)      /* Clear vCard temp file before go back to Idle screen if enter from idle screen */
    {
        SetKeyHandler(mmi_vcard_recv_abort_vcard, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_view_detail_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_recv_view_detail_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vcard_recv_parse_file())
    {
        mmi_vcard_entry_recv_view_detail();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_abort_vcard
 * DESCRIPTION
 *  abort receiving a vcard, clear buffer or screen before aborting.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_recv_abort_vcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vcard_cntx.ParseLoc == MMI_VCARD_PARSE_FROM_FILE_MANAGER)
    {
        DeleteNScrId(SCR_ID_VCARD_RECV_VIEW_DETAIL);
        GoBackHistory();
    }
    else if (g_vcard_cntx.ParseLoc == MMI_VCARD_PARSE_FROM_VOBJ_BUFFER)
    {

        mmi_vobj_clear_one_file_buffer();
        DisplayIdleScreen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_parse_file
 * DESCRIPTION
 *  a pre- parsing vcard function. Create path and do some error handling before
 *  send file to parser.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vcard_recv_parse_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vcard_cntx.ParseLoc == MMI_VCARD_PARSE_FROM_FILE_MANAGER)
    {
        if (mmi_vcard_reader_from_file_path(g_vcard_cntx.FilePathPtr) == VCARD_PARSE_NO_ERROR)
        {
            return TRUE;
        }

        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        mmi_vobj_clear_one_file_buffer();
        DeleteNScrId(SCR_ID_VCARD_RECV_OPT);
    }
    else
    {
        /* S8 ascii_path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH]; */
        S8 path[VOBJ_MAX_PATH_LENGTH];
        S32 check_result = mmi_vobj_fs_check_folder();

        /* Create file path and folder. */
        if (check_result == FS_NO_ERROR)
            if (mmi_vobj_get_file_buffer_size() > 0)
            {
                //sprintf(ascii_path, "%c:\\%s\\%d.vcf", VOBJ_DRV,VOBJ_FILE_PATH,g_vobj_cntx.buffer_begin);
                //mmi_asc_to_ucs2(path, ascii_path);
                mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin, path, MMI_VOBJ_VCARD);

                if (mmi_vcard_reader_from_file_path(path) == VCARD_PARSE_NO_ERROR)
                {
                    return TRUE;
                }
            }
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        /* mmi_vobj_clear_one_file_buffer(); */
        DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_save_obj_to_phb
 * DESCRIPTION
 *  save parsed vcard to phonebook after parsing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_recv_save_obj_to_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing) /* Phonebook not ready */
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        str_id = STR_PROCESSING_PHONEBOOK;
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        str_id = STR_ID_PHB_PROCESSING_USIM;
    }
#endif /* __MMI_PHB_USIM_FIELD__ */
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        str_id = STR_ID_SYNC_PLEASE_WAIT;
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (!mmi_ucs2strlen(pbName) && !mmi_phb_calculate_number_valid_length(pbNumber))  /* Both name and number empty */
    {
        str_id = STR_ID_PHB_NAME_NUM_REQUIRE;
    }
    else if (g_vcard_cntx.StorageLoc == MMI_NVRAM && g_phb_cntx.phone_used >= g_phb_cntx.phone_total)   /* Phone storage full. */
    {
        str_id = STR_PHONE_FULL_MSG;
    }
    else if (g_vcard_cntx.StorageLoc == MMI_SIM && g_phb_cntx.sim_used >= g_phb_cntx.sim_total) /* SIM storage full. */
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        str_id = STRING_MTPNP_SIM1_STORAGE_FULL;
    #else
        str_id = STR_SIM_FULL_MSG;
    #endif
    }
    else if ((g_vcard_cntx.StorageLoc == MMI_SIM) && !mmi_phb_op_check_valid_number(pbNumber))
    {
        str_id = STR_ID_PHB_NUM_INVALID;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (g_vcard_cntx.StorageLoc == MMI_SIM2 && (MTPNP_AD_ADN_SIM2GetUsedNumber() >= MTPNP_AD_ADN_SIM2GetCapacity()))
    {
        str_id = STRING_MTPNP_SIM2_STORAGE_FULL;
    }
    else if ((g_vcard_cntx.StorageLoc == MMI_SIM2) && !mmi_phb_op_check_valid_number(pbNumber))
    {
        str_id = STR_ID_PHB_NUM_INVALID;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else if ((g_vcard_cntx.StorageLoc == MMI_NVRAM) && (!mmi_phb_op_check_valid_number(pbNumber) /* Number format not correct */
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        || !mmi_phb_op_check_valid_number(pbHomeNumber)
        || !mmi_phb_op_check_valid_number(pbOfficeNumber)
        || !mmi_phb_op_check_valid_number(pbFaxNumber)
    #endif    
        ))
    {
        str_id = STR_ID_PHB_NUM_INVALID;
    }

    if (str_id != 0)
    {
        DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
    }
    else
    {
        if (g_vcard_cntx.StorageLoc == MMI_SIM)
        {
            g_phb_cntx.selected_storage = MMI_SIM;
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
	else if (g_vcard_cntx.StorageLoc == MMI_SIM2)
        {
            g_phb_cntx.selected_storage = MMI_SIM2;
	}
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        else
        {
            g_phb_cntx.selected_storage = MMI_NVRAM;
        }
        g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;    /* No Image. */
        mmi_phb_op_add_entry_req();

        if (g_vcard_cntx.ParseLoc == MMI_VCARD_PARSE_FROM_FILE_MANAGER)
        {
            DeleteNScrId(SCR_ID_VCARD_RECV_VIEW_DETAIL);
        }
        else if (g_vcard_cntx.ParseLoc == MMI_VCARD_PARSE_FROM_VOBJ_BUFFER)
        {
            g_phb_enter_from = MMI_PHB_ENTER_FROM_IDLE_SCREEN;
            //DeleteNScrId(SCR_ID_VOBJ_RECV_OBJECT);
            //mmi_vobj_clear_one_file_buffer();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_move_obj_to_file
 * DESCRIPTION
 *  move vcard to the path selected by user.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32   error cause
 *****************************************************************************/
S32 mmi_vcard_recv_move_obj_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filename[VOBJ_MAX_FILE_EXT_LEN];
    FS_HANDLE fh;
    U16 path_len;
    U16 name_len;
    S32 result;
    S8 *src_path;
    S8* temp_filename;
    S8* temp_ptr;
    U16 temp_filename_length = VOBJ_MAX_FILENAME_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_vcard_cntx.FilePathPtr != NULL);
    path_len = mmi_ucs2strlen(g_vcard_cntx.FilePathPtr);

    MMI_ASSERT(g_vcard_cntx.FileNamePtr != NULL);
    name_len = mmi_ucs2strlen(g_vcard_cntx.FileNamePtr);

    /* Check if name empty */
    if (mmi_ucs2strlen(g_vcard_cntx.FileNamePtr) == 0)
    {
        return VOBJ_ERR_EMPTY_NAME;
    }

    /* Check if file path is too long */
    if ((path_len + name_len + VOBJ_MAX_FILE_EXT_LEN / ENCODING_LENGTH) > VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH)
    {
        return VOBJ_ERR_SELECT_PATH_TOO_LONG;
    }

    temp_filename = OslMalloc(temp_filename_length);
    temp_ptr = mmi_fmgr_skip_space(g_vcard_cntx.FileNamePtr);
    mmi_ucs2cpy(temp_filename, temp_ptr);
    /* Check if file name contain '/' or '\' */
    if (!mmi_fmgr_is_filename_valid(temp_filename))
    {
        OslMfree(temp_filename);
        return VOBJ_ERR_INVALID_FILENAME;
    }

    /* Concatenate file path */
    mmi_ucs2cat(g_vcard_cntx.FilePathPtr, temp_filename);
    OslMfree(temp_filename);
    mmi_asc_to_ucs2(filename, VOBJ_VCARD_FILE_EXT);
    mmi_ucs2cat(g_vcard_cntx.FilePathPtr, filename);

    /* Test if file already exists. */
    fh = FS_Open((U16*) g_vcard_cntx.FilePathPtr, FS_READ_ONLY);
    if (fh > 0)
    {
        FS_Close(fh);
        memset((g_vcard_cntx.FilePathPtr + path_len * ENCODING_LENGTH), 0, 2);  /* Clear file name concatenate after path */
        return VOBJ_ERR_DUPLICATE_NAME;
    }

    /* Move the file to the destinatio. */
    if (mmi_vobj_get_file_buffer_size() > 0)
    {
        src_path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin, src_path, MMI_VOBJ_VCARD);

        /* Use move instead of rename because user may save to card. */
        /* result = FS_Rename((U16*)src_path, (U16*)g_vcard_cntx.FilePathPtr); */
    #if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)
        mmi_fmgr_send_copy_req(
            FMGR_ACTION_MOVE,
            (U8*) src_path,
            (U8*) g_vcard_cntx.FilePathPtr,
            mmi_vcard_recv_move_obj_to_file_callback);
        result = VOBJ_ERR_NO_ERROR;
    #else
        result = VOBJ_ERR_UNKNOWN;  /* Should hine menu when MOVE not support. */
    #endif /* defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)	 */ 

        OslMfree(src_path);
    }
    else
    {
        result = VOBJ_ERR_UNKNOWN;
    }

    return result;
}


#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_move_obj_to_file_callback
 * DESCRIPTION
 *  move vcard to the path selected by user.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  S32   error cause(?)
 *****************************************************************************/
void mmi_vcard_recv_move_obj_to_file_callback(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;
    int attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;

    if (msgPtr->result >= 0)
    {
        attr = FS_GetAttributes((WCHAR*) g_vcard_cntx.FilePathPtr);
        attr &= ~FS_ATTR_HIDDEN;
        FS_SetAttributes((WCHAR*) g_vcard_cntx.FilePathPtr, (BYTE)attr);
        mmi_vcard_forward_fmgr_save_file_done(VOBJ_ERR_NO_ERROR);
    }
    else
    {
        mmi_vcard_forward_fmgr_save_file_done(msgPtr->result);
    }
}
#endif /* defined(__MMI_FILE_MANAGER__) */
/*--------------------------------------------------END vCard Received operation ---------------------------------------------------*/


/*--------------------------------------------------BEGIN vCard writer ---------------------------------------------------*/
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_get_bday_to_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  b_day           [?]         
 *  a(?)            [IN]        Store index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vcard_get_bday_to_buff(U16 store_index, S8 *b_day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bday_record, bday_index;
    S16 pError;
    MMI_PHB_BDAY_STRUCT bday_data[NVRAM_EF_PHB_BIRTHDAY_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bday_record = (store_index / NVRAM_EF_PHB_BIRTHDAY_COUNT) + 1;
    bday_index = store_index - (bday_record - 1) * NVRAM_EF_PHB_BIRTHDAY_COUNT;

    ReadRecord(NVRAM_EF_PHB_BIRTHDAY_LID, bday_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);

    /* Year */
    if (bday_data[bday_index].bYear <= MMI_PHB_BDAY_MAX_YEAR_INT)
    {
        _snprintf(b_day, 5, "%04d", bday_data[bday_index].bYear);
    }
    else
    {
        strcpy(b_day, "0000");
    }

    /* Month */
    if (bday_data[bday_index].bMonth <= 12)
    {
        _snprintf(b_day + 4, 3, "%02d", bday_data[bday_index].bMonth);
    }
    else
    {
        strcpy(b_day + 4, "00");
    }

    /* Day */
    if (bday_data[bday_index].bDay <= 31)
    {
        _snprintf(b_day + 6, 3, "%02d", bday_data[bday_index].bDay);
    }
    else
    {
        strcpy(b_day + 6, "00");
    }
}
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_writer_v21_mycard_to_file
 * DESCRIPTION
 *  write my vcard entry into vcard format into destination file.
 * PARAMETERS
 *  path        [IN]        Destination path
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vcard_writer_v21_mycard_to_file(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_PHB_VCARD_STRUCT myCard;
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read my vCard from NVRAM. */
    ReadRecord(NVRAM_EF_PHB_VCARD_LID, 1, (void*)&myCard, MMI_PHB_VCARD_RECORD_SIZE, &pError);

    return mmi_vcard_writer_to_file(
            path,
            (S8*) myCard.name,
            (S8*) myCard.number,
            (S8*) myCard.homeNumber,
            (S8*) myCard.officeNumber,
            (S8*) myCard.faxNumber,
            (S8*) myCard.emailAddress,
            (S8*) myCard.companyName,
            NULL,
            NULL,
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_writer_v21_select_card_to_file
 * DESCRIPTION
 *  write select phonebook entry into vcard format into destination file.
 * PARAMETERS
 *  path        [IN]        Destination path
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vcard_writer_v21_select_card_to_file(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S8 number_buff[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    S16 pError;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phbListView == MMI_PHB_LIST_FOR_ALL_SHARED)
    {
        store_index = g_phb_name_index[g_phb_cntx.active_index_second];
    }
    else
    {
        store_index = g_phb_name_index[g_phb_cntx.active_index];
    }
//    phbListView = MMI_PHB_LIST_FOR_NONE;
    
    /* Mobile Number */
    if (((PhoneBook[store_index].tel.type & 0x90) == 0x90) && (PhoneBook[store_index].tel.type != 0xFF))
    {
        number_buff[0] = '+';
        mmi_phb_convert_to_digit((U8*) number_buff + 1, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    }
    else
    {
        mmi_phb_convert_to_digit((U8*) number_buff, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    }

    if (store_index < MAX_PB_PHONE_ENTRIES) /* In NVRAM */
    {
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        S8 b_day[9];    /* Format: yyyymmdd */

        mmi_vcard_get_bday_to_buff(store_index, (S8*) b_day);
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */
    #ifdef __MMI_PHB_INFO_FIELD__
        mmi_phb_info_read_data_to_buff(store_index);
    #endif 
        return mmi_vcard_writer_to_file(path, (S8*) PhoneBook[store_index].alpha_id.name, (S8*) number_buff,
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
                                            (S8*) PhoneBookOptionalFields.homeNumber,
                                            (S8*) PhoneBookOptionalFields.officeNumber,
                                            (S8*) PhoneBookOptionalFields.faxNumber,
                                            (S8*) PhoneBookOptionalFields.emailAddress,
                                            (S8*) PhoneBookOptionalFields.companyName,
    #else /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
                                            NULL, NULL, NULL, NULL, NULL,
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
                                            b_day,
    #else 
                                            NULL,
    #endif 
    #if defined(__MMI_PHB_INFO_FIELD__)
                                            &PhoneBookInfoFields,
    #else 
                                            NULL,
    #endif
                                            NULL);
    }
    return mmi_vcard_writer_to_file(
            path,
            (S8*) PhoneBook[store_index].alpha_id.name,
            (S8*) number_buff,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_writer_v21_to_file
 * DESCRIPTION
 *  write entry into vcard format into destination file.
 * PARAMETERS
 *  path                [IN]        Destination path
 *  ucs2_name           [IN]         
 *  number              [IN]         
 *  home_num            [IN]         
 *  office_num          [IN]         
 *  fax_num             [IN]         
 *  email_addr          [IN]         
 *  ucs2_company        [IN]         
 *  b_day               [IN]         
 *  title               [?]         
 *  url                 [?]         
 *  note                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vcard_writer_v21_to_file(
        S8 *path,
        S8 *ucs2_name,
        S8 *number,
        S8 *home_num,
        S8 *office_num,
        S8 *fax_num,
        S8 *email_addr,
        S8 *ucs2_company,
        S8 *b_day,
        PHB_INFO_FIELDS_STRUCT *info_fields,
        S8 *nick_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    U32 write_len;
    U32 object_len;
    U32 temp_len;
    S8 *object;
    S8 *temp_buf;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Open the file to write, overwrite if already exists. */
    fh = FS_Open((U16*) path, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (fh > 0)
    {
        /* Allocate buffer */
        object = OslMalloc(VCARD_WRITE_BUFF_LEN);
        memset(object, 0, VCARD_WRITE_BUFF_LEN);

        temp_buf = OslMalloc(VCARD_WRITER_FIELD_BUFFER);

        /* Header */
        strcpy(object, g_vcard_field[VCARD_FIELD_BEGIN]);
        strcat(object, VOBJ_VALUE_SEP_STR);
        strcat(object, VCARD_HEADER);
        strcat(object, VCARD_LINE_BREAK);

        /* Version */
        strcat(object, g_vcard_field[VCARD_FIELD_VERSION]);
        strcat(object, VOBJ_VALUE_SEP_STR);
        strcat(object, VCARD_VERSION_21);
        strcat(object, VCARD_LINE_BREAK);

        /* Name Field, write N field. */
        if (mmi_ucs2strlen(ucs2_name))
        {
            mmi_vcard_writer_v21_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_N], ucs2_name);
            /* mmi_vcard_writer_v21_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_FN], ucs2_name); */
        }

        /* Mobile Number */
        if (strlen(number))
        {
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
//                "%s;%s;%s:%s%s",
                "%s;%s:%s%s",
                g_vcard_field[VCARD_FIELD_TEL],
                g_vcard_para[VCARD_PARA_CELL],
//                g_vcard_para[VCARD_PARA_VOICE],
                number,
                VCARD_LINE_BREAK);
        }

    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        /* Home Number */
        if ((home_num != NULL) && strlen(home_num))
        {
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
                //"%s;%s;%s:%s%s",
                "%s;%s:%s%s",
                g_vcard_field[VCARD_FIELD_TEL],
                g_vcard_para[VCARD_PARA_HOME],
                //g_vcard_para[VCARD_PARA_VOICE],
                home_num,
                VCARD_LINE_BREAK);
        }

        /* Office Number */
        if ((office_num != NULL) && strlen(office_num))
        {
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
                //"%s;%s;%s:%s%s",
                "%s;%s:%s%s",
                g_vcard_field[VCARD_FIELD_TEL],
                g_vcard_para[VCARD_PARA_WORK],
                //g_vcard_para[VCARD_PARA_VOICE],
                office_num,
                VCARD_LINE_BREAK);
        }

        /* Fax Number */
        if ((fax_num != NULL) && strlen(fax_num))
        {
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
                "%s;%s:%s%s",
                g_vcard_field[VCARD_FIELD_TEL],
                g_vcard_para[VCARD_PARA_FAX],
                fax_num,
                VCARD_LINE_BREAK);
        }

        /* Email */
        if ((email_addr != NULL) && strlen(email_addr))
        {
            temp_len = strlen(object);
            sprintf((object + temp_len), "%s;%s:%s%s", g_vcard_field[VCARD_FIELD_EMAIL], 
                g_vcard_email_para[VCARD_EMAIL_PARA_INTERNET], email_addr, VCARD_LINE_BREAK);
        }

        /* Company Name */
        if ((ucs2_company != NULL) && mmi_ucs2strlen(ucs2_company))
        {
            mmi_vcard_writer_v21_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_ORG], ucs2_company);
        }
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */

    #ifdef __MMI_PHB_BIRTHDAY_FIELD__
        /* Birthday */
        if ((b_day != NULL) && strlen(b_day) && strcmp(b_day, "00000000") != 0)
        {
            temp_len = strlen(object);
            sprintf((object + temp_len), "%s:%s%s", g_vcard_field[VCARD_FIELD_BDAY], b_day, VCARD_LINE_BREAK);
        }
    #endif/* def __MMI_PHB_BIRTHDAY_FIELD__ */

    #ifdef __MMI_PHB_INFO_FIELD__
        /* Info field */
        if (info_fields != NULL)
        {
            /* title */
            if (mmi_ucs2strlen((S8*)info_fields->title))
            {
                mmi_vcard_writer_v21_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_TITLE], (S8*)info_fields->title);
            }
            /* url */
            if (strlen((const char*)info_fields->url))
            {
                temp_len = strlen(object);
                sprintf((object + temp_len), "%s:%s%s", g_vcard_field[VCARD_FIELD_URL], info_fields->url, VCARD_LINE_BREAK);
            }
            /* address */
            if (mmi_ucs2strlen((S8*)info_fields->address))
            {
                mmi_vcard_writer_v21_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_ADR], (S8*)info_fields->address);
            }
            /* note */
            if (mmi_ucs2strlen((S8*)info_fields->note))
            {
                mmi_vcard_writer_v21_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_NOTE], (S8*)info_fields->note);
            }
        }
    #endif /* def __MMI_PHB_INFO_FIELD__ */

        /* Footer */
        strcat(object, g_vcard_field[VCARD_FIELD_END]);
        strcat(object, VOBJ_VALUE_SEP_STR);
        strcat(object, VCARD_HEADER);
        strcat(object, VCARD_LINE_BREAK);

        /* Write to file. */
        object_len = strlen(object);

        MMI_ASSERT(object_len < VCARD_WRITE_BUFF_LEN);

        result = FS_Write(fh, object, object_len, (U32*) & write_len);
        FS_Close(fh);

        OslMfree(temp_buf);
        OslMfree(object);
        return result;
    }

    return (S32) fh;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_writer_v21_append_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object          [?]     
 *  temp_buf        [?]     
 *  field_name      [?]     
 *  field_value     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_writer_v21_append_name(S8 *object, S8 *temp_buf, S8 *field_name, S8 *field_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_len;
    U8 valueType = 0;
    U8 isUCS2 = 1;
    S8 *qp_buf;
    S8 *temp_ucs2_buff;
    U16 i = 0, j = 0, num_of_semicolon = 0;
    U16 field_length = mmi_ucs2strlen(field_value);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Always use UTF-8 to encode. */
    if ((isUCS2 /*=GetUCS2Flag(field_value) */ ) > 0)
    {
        i = 0;
        while (i < field_length)
        {
            if (field_value[2 * i] == ';') /* ; */
            {
                num_of_semicolon++;
            }
            i++;
        }

        if (num_of_semicolon > 0)
        {
            temp_ucs2_buff = OslMalloc((field_length + num_of_semicolon + 1) * 2);
            memset(temp_ucs2_buff, 0, ((field_length + num_of_semicolon + 1) * 2));

            i = 0;
            j = 0;
            while (i < field_length)
            {
                if (field_value[2 * i] == ';') /* ; */
                {
                    temp_ucs2_buff[2 * j] = '\\';
                    temp_ucs2_buff[2 * j + 1] = '\0';
                    j++;
                }
                temp_ucs2_buff[2 * j] = field_value[2 * i];
                temp_ucs2_buff[2 * j + 1] = field_value[2 * i + 1];
                i++;
                j++;
            }        
       
            valueType = mmi_vcard_util_convert_to_system_encoding(temp_buf, temp_ucs2_buff);
            OslMfree(temp_ucs2_buff);       
        }
        else
        {
            valueType = mmi_vcard_util_convert_to_system_encoding(temp_buf, field_value);            
        }
    }
    else
    {
        mmi_ucs2_to_asc(temp_buf, field_value);
    }

    qp_buf = OslMalloc(VCARD_WRITER_FIELD_BUFFER);
    applib_qprint_encode_ext(temp_buf, strlen(temp_buf), qp_buf, VOBJ_WRITE_BUFF_LEN, TRUE);

    /* Append Field Name */
    strcat(object, field_name);

    /* Append Charset Type */
    if (isUCS2)
    {
        temp_len = strlen(object);
        sprintf((object + temp_len), ";%s=%s", g_vobj_paras[VOBJ_PARA_CHARSET], g_vobj_charset[valueType]);
    }

    /* Append Encoding Type */
    temp_len = strlen(object);
    sprintf((object + temp_len), ";%s=%s", g_vobj_paras[VOBJ_PARA_ENCODING], g_vobj_encoding[VOBJ_EN_QP]);

    strcat(object, VOBJ_VALUE_SEP_STR);
    strcat(object, qp_buf);
    strcat(object, VCARD_LINE_BREAK);
    OslMfree(qp_buf);
}


#if defined(__MMI_VCARD_V30__)
void mmi_vcard_util_transfer_capital_to_lowercase(S8* output, S8* input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; *(input + i) != '\0'; i++)
    {
        *(output + i) = *(input + i) + 32;
    }
    *(output + i) = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_writer_v30_to_file
 * DESCRIPTION
 *  write entry into vcard format into destination file.
 * PARAMETERS
 *  path                [IN]        Destination path
 *  ucs2_name           [IN]         
 *  number              [IN]         
 *  home_num            [IN]         
 *  office_num          [IN]         
 *  fax_num             [IN]         
 *  email_addr          [IN]         
 *  ucs2_company        [IN]         
 *  b_day               [IN]         
 *  info_fields         [IN]         
 *  nick_name           [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vcard_writer_v30_to_file(
        S8 *path,
        S8 *ucs2_name,
        S8 *number,
        S8 *home_num,
        S8 *office_num,
        S8 *fax_num,
        S8 *email_addr,
        S8 *ucs2_company,
        S8 *b_day,
        PHB_INFO_FIELDS_STRUCT *info_fields,
        S8 *nick_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    U32 write_len;
    U32 object_len;
    U32 temp_len;
    S8 *object;
    S8 *temp_buf;
    S32 result;
    S8 para_buff[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Open the file to write, overwrite if already exists. */
    fh = FS_Open((U16*) path, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (fh > 0)
    {
        /* Allocate buffer */
        object = OslMalloc(VCARD_WRITE_BUFF_LEN);
        memset(object, 0, VCARD_WRITE_BUFF_LEN);

        temp_buf = OslMalloc(VCARD_WRITER_FIELD_BUFFER);

        /* Header */
        strcpy(object, g_vcard_field[VCARD_FIELD_BEGIN]);
        strcat(object, VOBJ_VALUE_SEP_STR);
        strcat(object, VCARD_HEADER);
        strcat(object, VCARD_LINE_BREAK);

        /* Version */
        strcat(object, g_vcard_field[VCARD_FIELD_VERSION]);
        strcat(object, VOBJ_VALUE_SEP_STR);
        strcat(object, VCARD_VERSION_30);
        strcat(object, VCARD_LINE_BREAK);

        /* Name Field, write N field. */
        if (mmi_ucs2strlen(ucs2_name))
        {
            mmi_vcard_writer_v30_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_N], ucs2_name);
            /* mmi_vcard_writer_v21_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_FN], ucs2_name); */
        }

        /* Mobile Number */
        if (strlen(number))
        {
            mmi_vcard_util_transfer_capital_to_lowercase(para_buff, (S8*) g_vcard_para[VCARD_PARA_CELL]);
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
                "%s;%s=%s:%s%s",
                g_vcard_field[VCARD_FIELD_TEL],
                g_vcard_type_para[VCARD_TYPE_PARA_TYPE],
                para_buff,
                number,
                VCARD_LINE_BREAK);
        }

    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        /* Home Number */
        if ((home_num != NULL) && strlen(home_num))
        {
            mmi_vcard_util_transfer_capital_to_lowercase(para_buff, (S8*) g_vcard_para[VCARD_PARA_HOME]);
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
                "%s;%s=%s:%s%s",
                g_vcard_field[VCARD_FIELD_TEL],
                g_vcard_type_para[VCARD_TYPE_PARA_TYPE],
                para_buff,
                home_num,
                VCARD_LINE_BREAK);
        }

        /* Office Number */
        if ((office_num != NULL) && strlen(office_num))
        {
            mmi_vcard_util_transfer_capital_to_lowercase(para_buff, (S8*) g_vcard_para[VCARD_PARA_WORK]);
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
                "%s;%s=%s:%s%s",
                g_vcard_field[VCARD_FIELD_TEL],
                g_vcard_type_para[VCARD_TYPE_PARA_TYPE],
                para_buff,
                office_num,
                VCARD_LINE_BREAK);
        }

        /* Fax Number */
        if ((fax_num != NULL) && strlen(fax_num))
        {
            mmi_vcard_util_transfer_capital_to_lowercase(para_buff, (S8*) g_vcard_para[VCARD_PARA_FAX]);
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
                "%s;%s=%s:%s%s",
                g_vcard_field[VCARD_FIELD_TEL],
                g_vcard_type_para[VCARD_TYPE_PARA_TYPE],
                para_buff,
                fax_num,
                VCARD_LINE_BREAK);
        }

        /* Email */
        if ((email_addr != NULL) && strlen(email_addr))
        {
            mmi_vcard_util_transfer_capital_to_lowercase(para_buff, (S8*) g_vcard_email_para[VCARD_EMAIL_PARA_INTERNET]);
            temp_len = strlen(object);
            sprintf(
                (object + temp_len),
                "%s;%s=%s:%s%s",
                g_vcard_field[VCARD_FIELD_EMAIL],
                g_vcard_type_para[VCARD_TYPE_PARA_TYPE],
                para_buff,
                email_addr,
                VCARD_LINE_BREAK);
        }

        /* Company Name */
        if ((ucs2_company != NULL) && mmi_ucs2strlen(ucs2_company))
        {
            mmi_vcard_writer_v30_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_ORG], ucs2_company);
        }
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */

    #ifdef __MMI_PHB_BIRTHDAY_FIELD__
        /* Birthday */
        if ((b_day != NULL) && strlen(b_day) && strcmp(b_day, "00000000") != 0)
        {
            temp_len = strlen(object);
            sprintf((object + temp_len), "%s:%s%s", g_vcard_field[VCARD_FIELD_BDAY], b_day, VCARD_LINE_BREAK);
        }
    #endif/* def __MMI_PHB_BIRTHDAY_FIELD__ */

    #ifdef __MMI_PHB_INFO_FIELD__
        /* Info field */
        if (info_fields != NULL)
        {
            /* title */
            if (mmi_ucs2strlen((S8*)info_fields->title))
            {
                mmi_vcard_writer_v30_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_TITLE], (S8*)info_fields->title);
            }
            /* url */
            if (strlen((const char*)info_fields->url))
            {
                temp_len = strlen(object);
                sprintf((object + temp_len), "%s:%s%s", g_vcard_field[VCARD_FIELD_URL], info_fields->url, VCARD_LINE_BREAK);
            }
            /* address */
            if (mmi_ucs2strlen((S8*)info_fields->address))
            {
                mmi_vcard_writer_v30_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_ADR], (S8*)info_fields->address);
            }
            /* note */
            if (mmi_ucs2strlen((S8*)info_fields->note))
            {
                mmi_vcard_writer_v30_append_name(object, temp_buf, (S8*) g_vcard_field[VCARD_FIELD_NOTE], (S8*)info_fields->note);
            }
        }
    #endif /* def __MMI_PHB_INFO_FIELD__ */

        /* Footer */
        strcat(object, g_vcard_field[VCARD_FIELD_END]);
        strcat(object, VOBJ_VALUE_SEP_STR);
        strcat(object, VCARD_HEADER);
        strcat(object, VCARD_LINE_BREAK);

        /* Write to file. */
        object_len = strlen(object);

        MMI_ASSERT(object_len < VCARD_WRITE_BUFF_LEN);

        result = FS_Write(fh, object, object_len, (U32*) & write_len);
        FS_Close(fh);

        OslMfree(temp_buf);
        OslMfree(object);
        return result;
    }

    return (S32) fh;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_writer_v30_append_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object          [?]     
 *  temp_buf        [?]     
 *  field_name      [?]     
 *  field_value     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_writer_v30_append_name(S8 *object, S8 *temp_buf, S8 *field_name, S8 *field_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_len;
    U8 valueType = 0;
    U8 isUCS2 = 1;    
    S8 *temp_ucs2_buff;
    U16 i = 0, j = 0, num_of_semicolon = 0;
    U16 field_length = mmi_ucs2strlen(field_value);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Always use UTF-8 to encode. */
    if ((isUCS2 /* GetUCS2Flag(field_value) */ ) > 0)
    {
        i = 0;
        while (i < field_length)
        {
            if (field_value[2 * i] == ';') /* ; */
            {
                num_of_semicolon++;
            }
            i++;
        }

        if (num_of_semicolon > 0)
        {
            temp_ucs2_buff = OslMalloc((field_length + num_of_semicolon + 1) * 2);
            memset(temp_ucs2_buff, 0, ((field_length + num_of_semicolon + 1) * 2));

            i = 0;
            j = 0;
            while (i < field_length)
            {
                if (field_value[2 * i] == ';') /* ; */
                {
                    temp_ucs2_buff[2 * j] = '\\';
                    temp_ucs2_buff[2 * j + 1] = '\0';
                    j++;
                }
                temp_ucs2_buff[2 * j] = field_value[2 * i];
                temp_ucs2_buff[2 * j + 1] = field_value[2 * i + 1];
                i++;
                j++;
            }        
       
            valueType = mmi_vcard_util_convert_to_system_encoding(temp_buf, temp_ucs2_buff);
            OslMfree(temp_ucs2_buff);       
        }
        else
        {
            valueType = mmi_vcard_util_convert_to_system_encoding(temp_buf, field_value);            
        }
    }
    else
    {
        mmi_ucs2_to_asc(temp_buf, field_value);
    }

    /* Append Field Name */
    strcat(object, field_name);

    /* Append Charset Type */
    if (isUCS2 /* GetUCS2Flag(field_value) */)
    {
        temp_len = strlen(object);
        sprintf((object + temp_len), ";%s=%s", g_vobj_paras[VOBJ_PARA_CHARSET], g_vobj_charset[valueType]);
    }

    /* Append Encoding Type */
    strcat(object, VOBJ_VALUE_SEP_STR);
    strcat(object, temp_buf);
    strcat(object, VCARD_LINE_BREAK);
}
#endif /* defined(__MMI_VCARD_V30__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_writer_to_file
 * DESCRIPTION
 *  write entry into vcard format into destination file.
 * PARAMETERS
 *  path                [IN]        Destination path
 *  ucs2_name           [IN]         
 *  number              [IN]         
 *  home_num            [IN]         
 *  office_num          [IN]         
 *  fax_num             [IN]         
 *  email_addr          [IN]         
 *  ucs2_company        [IN]         
 *  b_day               [IN]         
 *  info_fields         [IN]         
 *  nick_name           [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vcard_writer_to_file(
        S8 *path,
        S8 *ucs2_name,
        S8 *number,
        S8 *home_num,
        S8 *office_num,
        S8 *fax_num,
        S8 *email_addr,
        S8 *ucs2_company,
        S8 *b_day,
        PHB_INFO_FIELDS_STRUCT *info_fields,
        S8 *nick_name)
{
#if defined(__MMI_VCARD_V30__)
    if (g_phb_cntx.vcard_version == MMI_PHB_VCARD_VERSION_30)
    {
        return mmi_vcard_writer_v30_to_file(
                    path,
                    ucs2_name,
                    number,
                    home_num,
                    office_num,
                    fax_num,
                    email_addr,
                    ucs2_company,
                    b_day,
                    info_fields,
                    nick_name);                    
    }
    else
#endif /* defined(__MMI_VCARD_V30__) */
    {
        return mmi_vcard_writer_v21_to_file(
                    path,
                    ucs2_name,
                    number,
                    home_num,
                    office_num,
                    fax_num,
                    email_addr,
                    ucs2_company,
                    b_day,
                    info_fields,
                    nick_name);     
    }	
}
/*--------------------------------------------------END vCard writer ---------------------------------------------------*/

/*--------------------------------------------------Begin vcard parser ---------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_from_file_path
 * DESCRIPTION
 *  Clear buffer and open the file to parse.
 * PARAMETERS
 *  path        [IN]        The vcard file location in file system.
 * RETURNS
 *  parse result.
 *****************************************************************************/
U8 mmi_vcard_reader_from_file_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    U8 error_code = VCARD_PARSE_UNKNOW_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = FS_Open((U16*) path, FS_READ_ONLY);

    if (fh > 0)
    {
        mmi_phb_util_clear_buffer(TRUE);    /* Clear all phonebook temp buffer before parsing */
        g_vcard_number = 0;
        g_vcard_cntx.CharSet = g_chset_text_encoding;
        error_code = mmi_vcard_reader_parse_line(fh);

    }
    else
    {
        error_code = MMI_PHB_VCARD_OPEN_FILE_ERROR;
    }

    FS_Close(fh);
    return error_code;
}

#ifdef __MMI_PHB_BIRTHDAY_FIELD__


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_bday
 * DESCRIPTION
 *  parse birthday field of a vcard object.s
 * PARAMETERS
 *  String          [IN]        String read from file for one line
 *  pb_year         [?]         
 *  pb_mon          [?]         
 *  pb_day          [?]         
 *  change_flag     [IN]        
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_bday(S8 *String, S8 *pb_year, S8 *pb_mon, S8 *pb_day, BOOL change_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = mmi_vobj_uti_get_value(String);
    mmi_phb_retrieve_bday(cursor, pb_year, pb_mon, pb_day, change_flag);
    return VCARD_PARSE_NO_ERROR;
}
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_uti_get_single_line
 * DESCRIPTION
 *  Get a line from file system, excluding the escape characters for vcard.
 * PARAMETERS
 *  strOutput       [IN/OUT]        Storage location for data
 *  fh              [IN]            File handle
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vcard_uti_get_single_line(S8 *strOutput, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    S8 strCRLF[4];
    S8 strLF[2];
    S8 *currCursor;
    S8 str_photo_end[12];
    S8 *photo_end_cursor;
    S32 strLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(strCRLF, "%c%c", VOBJ_CR_CHAR, VOBJ_LF_CHAR);
    sprintf(strLF, "%c", VOBJ_LF_CHAR);
    sprintf(str_photo_end, "//Z%s%s", strCRLF, strCRLF);
    FS_Read(fh, strOutput, VCARD_READ_BUFF_LEN - 1, &nBytes);

    strOutput[nBytes] = VOBJ_NULL;

    if (!nBytes)
    {
        return 0;
    }

    if ((currCursor = strstr(strOutput, strLF)) != NULL)  /* find out first LF */
    {
        if ((photo_end_cursor = strstr(strOutput, str_photo_end)) != NULL)  /* find out photo end */
        {
            if (currCursor > photo_end_cursor)
            {
                currCursor = photo_end_cursor + 6;
            }
        }
        strLen = (S32) (currCursor - strOutput);
        if (strOutput[strLen - 1] == VOBJ_CR_CHAR)
        {
            strOutput[strLen - 1] = VOBJ_NULL;
        }
        else
        {
            strOutput[strLen] = VOBJ_NULL;
        }


        FS_Seek(fh, (S32) (strLen - nBytes + 1), SEEK_CUR);
        nBytes = strLen;
    }
    else    /* CRLF not found, read until CRLF */
    {
        strOutput[nBytes] = VOBJ_NULL;
    }

    return nBytes;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_uti_get_line
 * DESCRIPTION
 *  Get a line from file system, excluding the escape characters for vcard.
 * PARAMETERS
 *  strOutput       [IN/OUT]        Storage location for data
 *  fh              [IN]            File handle
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vcard_uti_get_line(S8 *strOutput, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    S8 *buffer = OslMalloc(VCARD_READ_BUFF_LEN);
    S32 i;
    S32 strLen;
    S8 *curr_cursor;
    S8 *cursor = NULL;
    U16 buffer_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Read(fh, buffer, VCARD_READ_BUFF_LEN - 1, &nBytes);
    buffer[nBytes] = '\0';

    if (!nBytes)
    {
        OslMfree(buffer);
        return 0;
    }

    // only the VERSION and END are sure to be single line
    if ((strncmp(g_vcard_field[VCARD_FIELD_END], buffer, strlen(g_vcard_field[VCARD_FIELD_END])) == 0) ||
        (strncmp(g_vcard_field[VCARD_FIELD_VERSION], buffer, strlen(g_vcard_field[VCARD_FIELD_VERSION])) == 0))
    {
        FS_Seek(fh, 0 - nBytes, SEEK_CUR);
        OslMfree(buffer);
        return mmi_vcard_uti_get_single_line(strOutput, fh);
    }

    /* find next filed */
    for (i = VCARD_FIELD_FN; i < VCARD_FIELD_TOTAL; i++)
    {
        buffer_offset = 1;
        do
        {
            curr_cursor = strstr(buffer + buffer_offset, g_vcard_field[i]);
            if (curr_cursor != (S8*) NULL)
            {
                buffer_offset += (curr_cursor - (buffer + buffer_offset) + 1);//strlen(g_vcard_field[i]);
            }
        }while(curr_cursor != (S8*) NULL && *(curr_cursor - 1) != 0x0A);

        if (curr_cursor == (S8*) NULL)
        {
            continue;
        }
        else if (cursor == (S8*) NULL && (*(curr_cursor - 1) == 0x0A))
        {
            cursor = curr_cursor;
        }
        else if (((S32) cursor > (S32) curr_cursor) && (*(curr_cursor - 1) == 0x0A))
        {
            cursor = curr_cursor;
        }
    }
    if (cursor == NULL)
    {
        OslMfree(buffer);
        return 0;
    }

    strLen = (S32) cursor - (S32) buffer;
    strncpy(strOutput, buffer, strLen);
    strOutput[strLen] = VOBJ_NULL;

    /* Remove end of line "\r\n" */
    if (strncmp((S8*) ((strOutput + strLen) - strlen(VOBJ_LF_STR)), (S8*) VOBJ_LF_STR, strlen(VOBJ_LF_STR)) ==
        0)
    {
        if (strOutput[strLen - strlen(VOBJ_LF_STR) - 1] == VOBJ_CR_CHAR)
        {
            strOutput[strLen - strlen(VOBJ_LF_STR) - 1] = VOBJ_NULL;
        }
        else
        {
            strOutput[strLen - strlen(VOBJ_LF_STR)] = VOBJ_NULL;
        }
    }

    FS_Seek(fh, (S32) (strLen - nBytes), SEEK_CUR);

    OslMfree(buffer);
    return strLen;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_parse_line
 * DESCRIPTION
 *  Read one line to parse for each filed.
 * PARAMETERS
 *  fh      [IN]        file handle ready to read and parse.
 * RETURNS
 *  parse  error cause
 *****************************************************************************/
U8 mmi_vcard_reader_parse_line(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inBuff[VCARD_READ_BUFF_LEN];
    U8 token;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* BEGIN:VCARD */
    if (mmi_vcard_uti_get_single_line(inBuff, fh) != 0)
    {
        if (mmi_vcard_reader_get_field(inBuff) != VCARD_FIELD_BEGIN)
        {
            return VCARD_BEGIN_ERROR;
        }
        else if (!mmi_vcard_reader_check_header(inBuff))
        {
            return VCARD_BEGIN_ERROR;
        }
    }
    else
    {
        return VCARD_PARSE_UNKNOW_ERROR;
    }

    /* PARSE EACH FIELD */
    while (mmi_vcard_uti_get_line(inBuff, fh) != 0)
    {
        token = mmi_vcard_reader_get_field(inBuff);

        switch (token)
        {
            case VCARD_FIELD_END:
                if (!mmi_vcard_reader_check_header(inBuff))
                {
                    return VCARD_PARSE_UNKNOW_ERROR;
                }
                else
                {
                    return VCARD_PARSE_NO_ERROR;
                }
                break;                
                
            case VCARD_FIELD_PHOTO:
            case VCARD_FIELD_LABEL:
            case VCARD_FIELD_NICKNAME:
            case VCARD_FIELD_MAILER:
            case VCARD_FIELD_TZ:
            case VCARD_FIELD_GEO:
            case VCARD_FIELD_ROLE:
            case VCARD_FIELD_LOGO:
            case VCARD_FIELD_AGENT:
            case VCARD_FIELD_CATEGORIES:
            case VCARD_FIELD_PRODID:
            case VCARD_FIELD_SORT_STRING:
            case VCARD_FIELD_SOUND:
            case VCARD_FIELD_UID:
            case VCARD_FIELD_CLASS:
            case VCARD_FIELD_KEY:
            case VCARD_FIELD_X:
                break;

            /* VERSION */
            case VCARD_FIELD_VERSION:
                if (!mmi_vcard_reader_check_version(inBuff))
                {
                    return VCARD_VERSION_ERROR;
                }
                break;

            case VCARD_FIELD_N:
                mmi_vcard_reader_retrive_name(inBuff);
                break;

            case VCARD_FIELD_TEL:
            #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)           	
                mmi_vcard_reader_retrive_number(inBuff, pbNumber, pbHomeNumber, pbOfficeNumber, pbFaxNumber);
            #else
                mmi_vcard_reader_retrive_number(inBuff, pbNumber, NULL, NULL, NULL);            
            #endif
                break;

        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            case VCARD_FIELD_EMAIL:
                mmi_vcard_reader_retrive_email(inBuff, pbEmailAddress);
                break;

            case VCARD_FIELD_ORG:
                mmi_vcard_reader_retrive_org(inBuff, pbCompanyName);
                break;
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */

        #ifdef __MMI_PHB_BIRTHDAY_FIELD__
            case VCARD_FIELD_BDAY:
                mmi_vcard_reader_retrive_bday(inBuff, pbYear, pbMon, pbDay, TRUE);
                break;
        #endif /* __MMI_PHB_BIRTHDAY_FIELD__ */ 

        #ifdef __MMI_PHB_INFO_FIELD__
            case VCARD_FIELD_TITLE:
                mmi_vcard_reader_retrive_title(inBuff, pbTitle);
                break;
            case VCARD_FIELD_URL:
                mmi_vcard_reader_retrive_url(inBuff, pbUrl);
                break;
            case VCARD_FIELD_ADR:
                mmi_vcard_reader_retrive_address(inBuff, pbAddress);
                break;
            case VCARD_FIELD_NOTE:
                mmi_vcard_reader_retrive_note(inBuff, pbNote);
                break;
        #endif /* __MMI_PHB_INFO_FIELD__ */ 

            default:
                break;
        }
    }
    return VCARD_PARSE_UNKNOW_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_check_header
 * DESCRIPTION
 *  Check the VCARD header.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
BOOL mmi_vcard_reader_check_header(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = (S8*)strstr(String, (S8*) VOBJ_VALUE_SEP_STR);
    if (!cursor || !mmi_vobj_uti_strnicmp((cursor + 1), VCARD_HEADER, strlen(VCARD_HEADER)))
    {
        return TRUE;
    }
    else
    {
        return FALSE;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_check_version
 * DESCRIPTION
 *  Check the version field of a vcard object.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
BOOL mmi_vcard_reader_check_version(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = mmi_vobj_uti_get_value(String);
    if (!mmi_vobj_uti_strnicmp(cursor, VCARD_VERSION_21, strlen(VCARD_VERSION_21)) ||
        !mmi_vobj_uti_strnicmp(cursor, VCARD_VERSION_30, strlen(VCARD_VERSION_30)))
    {
        return TRUE;
    }
    else
    {
        return FALSE;    
    }
}


#if !defined(__MMI_VCARD_NAME_IN_ENGLISH_FORMAT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_check_if_all_English
 * DESCRIPTION
 *  check if the field is all english.
 * PARAMETERS
 *  str      [IN]        String to be checked
 * RETURNS
 *  if all character is English or not
 *****************************************************************************/
static BOOL mmi_vcard_check_if_all_English(const char *str)
{
    BOOL ret = TRUE;
    while(*str)
    {
        if (*str & 0x80)
        {
            ret = FALSE;
            break;
        }
        str++;
    }
    return ret;
}
#endif /* __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_name
 * DESCRIPTION
 *  parse the name field of a vcard object.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_name(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_buf[MAX_PB_NAME_LENGTH * 3 + 4 + 1];    /* For UTF-8 Encoding Size and add 4 bytes more to store delimiters. */
    S8 *cursor;
    U8 value;
    S8 ucs2_name[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = mmi_vobj_uti_get_value(String);
    if (cursor != NULL)
    {
        memset(temp_buf, 0, sizeof(temp_buf));
        strncpy(temp_buf, cursor, (sizeof(temp_buf) - 1));

        /* Check if there is CRLF */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_ENCODING], VOBJ_PARA_ENCODING, &value) &&
            value == VOBJ_EN_QP)
        {
            /* mmi_vobj_util_eliminate_qp_CRLF(temp_buf); */
            applib_qprint_decode(cursor, strlen(cursor), temp_buf, MAX_PB_NAME_LENGTH * 3 + 4 + 1);
        }

    #ifdef __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__
        mmi_vcard_util_get_name(temp_buf, sizeof(temp_buf));
    #else
        if (mmi_vcard_check_if_all_English((const char*)temp_buf))
        {
            if (!mmi_vcard_util_has_transform_name(temp_buf, sizeof(temp_buf)))
            {
                mmi_vcard_util_transform_field_delimiter(temp_buf, sizeof(temp_buf));    
            }
        }
        else
        {
            /* Remove delimiter. */
            mmi_vcard_util_remove_field_delimiter(temp_buf, sizeof(temp_buf));
        }
    #endif /* __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__ */
        /* decode */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_CHARSET], VOBJ_PARA_CHARSET, &value))
        {
            mmi_vcard_util_convert_to_ucs2(ucs2_name, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH, temp_buf, value);
        }
        else
        {
            mmi_chset_convert(
                g_vcard_cntx.CharSet,
                MMI_CHSET_UCS2,
                (char*)temp_buf,
                (char*)ucs2_name,
                (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
        }

        mmi_ucs2ncpy(pbName, ucs2_name, MAX_PB_NAME_LENGTH);
        mmi_phb_truncate_pbname_buffer(MMI_NVRAM);
    }
    return VCARD_PARSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_number
 * DESCRIPTION
 *  parse number field of a vcard object.s
 * PARAMETERS
 *  String              [IN]        String read from file for one line
 *  number              [?]         
 *  home_number         [?]         
 *  office_number       [?]         
 *  fax_number          [?]         
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_number(S8 *String, S8 *number, S8 *home_number, S8 *office_number, S8 *fax_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 result; */
    U8 type = VCARD_PARA_TOTAL;
    U8 pref;
    S8 temp_buf[MAX_PB_NUMBER_LENGTH + 1 + 1];
    S8 *cursor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VCARD_V30__)    
    mmi_vcard_util_v30_number_field_preprocess(String, (U16)strlen(String));
#endif /* defined(__MMI_VCARD_V30__) */

    cursor = mmi_vobj_uti_get_value(String);
    if (cursor != NULL && *cursor != '\0')
    {
        mmi_vcard_reader_get_para_number(String, &type, &pref);
        memset(temp_buf, 0, sizeof(temp_buf));
        strncpy(temp_buf, cursor, MAX_PB_NUMBER_LENGTH + 1);

        switch (type)
        {
            case VCARD_PARA_HOME:
                if (home_number && !mmi_ucs2strlen(home_number))
                {
                    if (temp_buf[0] == '+')
                        mmi_asc_n_to_ucs2(home_number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH + 1);
                    else
                        mmi_asc_n_to_ucs2(home_number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH);
                }
                break;
            case VCARD_PARA_WORK:
                if (office_number && !mmi_ucs2strlen(office_number))
                {
                    if (temp_buf[0] == '+')
                        mmi_asc_n_to_ucs2(office_number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH + 1);
                    else
                        mmi_asc_n_to_ucs2(office_number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH);
                }
                break;
            case VCARD_PARA_FAX:
                if (fax_number && !mmi_ucs2strlen(fax_number))
                {
                    if (temp_buf[0] == '+')
                        mmi_asc_n_to_ucs2(fax_number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH + 1);
                    else
                        mmi_asc_n_to_ucs2(fax_number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH);
                }
                break;
            case VCARD_PARA_PAGER:
                break; /* Don't have pager field */
        #ifdef __MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__
            case VCARD_PARA_CELL:
                if (number && !mmi_ucs2strlen(number))
                {
                    if (temp_buf[0] == '+')
                        mmi_asc_n_to_ucs2(number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH + 1);
                    else
                        mmi_asc_n_to_ucs2(number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH);
                }
                break;
            default:
                break;
        #else /* __MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__ */
            /* demo project not define the compile option */
            case VCARD_PARA_CELL:
            default:
                if (number && !mmi_ucs2strlen(number))
                {
                    if (temp_buf[0] == '+')
                        mmi_asc_n_to_ucs2(number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH + 1);
                    else
                        mmi_asc_n_to_ucs2(number, (S8*) temp_buf, MAX_PB_NUMBER_LENGTH);
                }
                break;
        #endif /* __MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__ */
        }
    }
    return VCARD_PARSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_email
 * DESCRIPTION
 *  parse email field of a vcard object.s
 * PARAMETERS
 *  String              [IN]        String read from file for one line
 *  email_address       [?]         
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_email(S8 *String, S8 *email_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_address && !mmi_ucs2strlen(email_address))
    {
        S8 temp_buf[MAX_PB_EMAIL_LENGTH + 1];
        S8 *cursor;
        U8 value;

        cursor = mmi_vobj_uti_get_value(String);
        if (cursor != NULL)
        {
            memset(temp_buf, 0, sizeof(temp_buf));
            strncpy(temp_buf, cursor, MAX_PB_EMAIL_LENGTH);

            /* Check if there is CRLF */
            if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_ENCODING], VOBJ_PARA_ENCODING, &value) &&
                value == VOBJ_EN_QP)
            {
                applib_qprint_decode(cursor, strlen(cursor), temp_buf, MAX_PB_EMAIL_LENGTH);
            }
            mmi_vcard_util_remove_field_delimiter(temp_buf, sizeof(temp_buf));

            /* decode */
            if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_CHARSET], VOBJ_PARA_CHARSET, &value))
            {
                mmi_vcard_util_convert_to_ucs2(email_address, (MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH, temp_buf, value);
            }
            else
            {
                mmi_chset_convert(
                    g_vcard_cntx.CharSet,
                    MMI_CHSET_UCS2,
                    (char*)temp_buf,
                    (char*)email_address,
                    (MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH);
            }
        }
    }
    return VCARD_PARSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_org
 * DESCRIPTION
 *  parse org field of a vcard object.s
 * PARAMETERS
 *  String              [IN]        String read from file for one line
 *  company_name        [?]         
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_org(S8 *String, S8 *company_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *temp_buf = OslMalloc(VCARD_WRITER_FIELD_BUFFER);    /* For UTF-8 Encoding Size and add 4 bytes more to store delimiters. */
    S8 *cursor;
    U8 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = mmi_vobj_uti_get_value(String);
    if (cursor != NULL)
    {
        memset(temp_buf, 0, VCARD_WRITER_FIELD_BUFFER);
        strncpy(temp_buf, cursor, (VCARD_WRITER_FIELD_BUFFER - 1));

        /* Check if there is CRLF */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_ENCODING], VOBJ_PARA_ENCODING, &value) &&
            value == VOBJ_EN_QP)
        {
            applib_qprint_decode(cursor, strlen(cursor), temp_buf, VCARD_WRITER_FIELD_BUFFER);
        }   

        /* Remove delimiter. */
        mmi_vcard_util_remove_field_delimiter(temp_buf, VCARD_WRITER_FIELD_BUFFER);
    
        /* decode */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_CHARSET], VOBJ_PARA_CHARSET, &value))
        {
            mmi_vcard_util_convert_to_ucs2(company_name, (MAX_PB_COMPANY_LENGTH + 1) * ENCODING_LENGTH, temp_buf, value);
        }
        else
        {
            mmi_chset_convert(
                g_vcard_cntx.CharSet,
                MMI_CHSET_UCS2,
                (char*)temp_buf,
                (char*)company_name,
                (MAX_PB_COMPANY_LENGTH + 1) * ENCODING_LENGTH);
        }
    }
    OslMfree(temp_buf);
    return VCARD_PARSE_NO_ERROR;
}


#if defined(__MMI_PHB_INFO_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_title
 * DESCRIPTION
 *  parse title field of a vcard object.s
 * PARAMETERS
 *  String              [IN]        String read from file for one line
 *  company_name        [?]         
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_title(S8 *String, S8 *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *temp_buf = OslMalloc(VCARD_WRITER_FIELD_BUFFER);    /* For UTF-8 Encoding Size and add 4 bytes more to store delimiters. */
    S8 *cursor;
    U8 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = mmi_vobj_uti_get_value(String);
    if (cursor != NULL)
    {
        memset(temp_buf, 0, VCARD_WRITER_FIELD_BUFFER);
        strncpy(temp_buf, cursor, (VCARD_WRITER_FIELD_BUFFER - 1));

        /* Check if there is CRLF */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_ENCODING], VOBJ_PARA_ENCODING, &value) &&
            value == VOBJ_EN_QP)
        {
            applib_qprint_decode(cursor, strlen(cursor), temp_buf, VCARD_WRITER_FIELD_BUFFER);
        }

        /* Remove delimiter. */
        mmi_vcard_util_remove_field_delimiter(temp_buf, VCARD_WRITER_FIELD_BUFFER);

        /* decode */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_CHARSET], VOBJ_PARA_CHARSET, &value))
        {
            mmi_vcard_util_convert_to_ucs2(title, (MAX_PB_TITLE_LENGTH + 1) * ENCODING_LENGTH, temp_buf, value);
        }
        else
        {
            mmi_chset_convert(
                g_vcard_cntx.CharSet,
                MMI_CHSET_UCS2,
                (char*)temp_buf,
                (char*)title,
                (MAX_PB_TITLE_LENGTH + 1) * ENCODING_LENGTH);
        }
    }
    OslMfree(temp_buf);
    return VCARD_PARSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_url
 * DESCRIPTION
 *  parse url field of a vcard object.s
 * PARAMETERS
 *  String              [IN]        String read from file for one line
 *  email_address       [?]         
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_url(S8 *String, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (url && !mmi_ucs2strlen(url))
    {
        S8 temp_buf[MAX_PB_URL_LENGTH + 1];
        S8 *cursor;
        U8 value;

        cursor = mmi_vobj_uti_get_value(String);
        if (cursor != NULL)
        {
            memset(temp_buf, 0, sizeof(temp_buf));
            strncpy(temp_buf, cursor, MAX_PB_URL_LENGTH);

            /* Check if there is CRLF */
            if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_ENCODING], VOBJ_PARA_ENCODING, &value) &&
                value == VOBJ_EN_QP)
            {
                applib_qprint_decode(cursor, strlen(cursor), temp_buf, MAX_PB_URL_LENGTH * 3 + 4 + 1);
            }
            mmi_vcard_util_remove_field_delimiter(temp_buf, sizeof(temp_buf));

            /* decode */
            if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_CHARSET], VOBJ_PARA_CHARSET, &value))
            {
                mmi_vcard_util_convert_to_ucs2(url, (U8)((MAX_PB_URL_LENGTH + 1) * ENCODING_LENGTH), temp_buf, value);
            }
            else
            {
                mmi_chset_convert(
                    g_vcard_cntx.CharSet,
                    MMI_CHSET_UCS2,
                    (char*)temp_buf,
                    (char*)url,
                    (MAX_PB_URL_LENGTH + 1) * ENCODING_LENGTH);
            }
        }
    }
    return VCARD_PARSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_address
 * DESCRIPTION
 *  parse title field of a vcard object.s
 * PARAMETERS
 *  String              [IN]        String read from file for one line
 *  company_name        [?]         
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_address(S8 *String, S8 *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *temp_buf = OslMalloc(VCARD_WRITER_FIELD_BUFFER);    /* For UTF-8 Encoding Size and add 4 bytes more to store delimiters. */
    S8 *cursor;
    U8 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = mmi_vobj_uti_get_value(String);
    if (cursor != NULL)
    {
        memset(temp_buf, 0, VCARD_WRITER_FIELD_BUFFER);
        strncpy(temp_buf, cursor, (VCARD_WRITER_FIELD_BUFFER - 1));

        /* Check if there is CRLF */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_ENCODING], VOBJ_PARA_ENCODING, &value) &&
            value == VOBJ_EN_QP)
        {
            applib_qprint_decode(cursor, strlen(cursor), temp_buf, VCARD_WRITER_FIELD_BUFFER);
        }

        /* Transform delimiter. */
        mmi_vcard_util_transform_field_delimiter(temp_buf, VCARD_WRITER_FIELD_BUFFER);

        /* decode */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_CHARSET], VOBJ_PARA_CHARSET, &value))
        {
            mmi_vcard_util_convert_to_ucs2(address, (MAX_PB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH, temp_buf, value);
        }
        else
        {
            mmi_chset_convert(
                g_vcard_cntx.CharSet,
                MMI_CHSET_UCS2,
                (char*)temp_buf,
                (char*)address,
                (MAX_PB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH);
        }
    }
    OslMfree(temp_buf);
    return VCARD_PARSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_retrive_note
 * DESCRIPTION
 *  parse note field of a vcard object.s
 * PARAMETERS
 *  String              [IN]        String read from file for one line
 *  note        [?]         
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vcard_reader_retrive_note(S8 *String, S8 *note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *temp_buf = OslMalloc(VCARD_WRITER_FIELD_BUFFER);    /* For UTF-8 Encoding Size and add 4 bytes more to store delimiters. */
    S8 *cursor;
    U8 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = mmi_vobj_uti_get_value(String);
    if (cursor != NULL)
    {
        memset(temp_buf, 0, VCARD_WRITER_FIELD_BUFFER);
        strncpy(temp_buf, cursor, (VCARD_WRITER_FIELD_BUFFER - 1));

        /* Check if there is CRLF */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_ENCODING], VOBJ_PARA_ENCODING, &value) &&
            value == VOBJ_EN_QP)
        {
            applib_qprint_decode(cursor, strlen(cursor), temp_buf, VCARD_WRITER_FIELD_BUFFER);
        }

        /* Remove delimiter. */
        mmi_vcard_util_remove_field_delimiter(temp_buf, VCARD_WRITER_FIELD_BUFFER);

        /* decode */
        if (mmi_vcard_reader_get_para_value(String, g_vobj_paras[VOBJ_PARA_CHARSET], VOBJ_PARA_CHARSET, &value))
        {
            mmi_vcard_util_convert_to_ucs2(note, (MAX_PB_NOTE_LENGTH + 1) * ENCODING_LENGTH, temp_buf, value);
        }
        else
        {
            mmi_chset_convert(
                g_vcard_cntx.CharSet,
                MMI_CHSET_UCS2,
                (char*)temp_buf,
                (char*)note,
                (MAX_PB_NOTE_LENGTH + 1) * ENCODING_LENGTH);
        }
    }
    OslMfree(temp_buf);
    return VCARD_PARSE_NO_ERROR;
}
#endif /* defined(__MMI_PHB_INFO_FIELD__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_get_field
 * DESCRIPTION
 *  parse field name of a vcard string.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  field enum
 *****************************************************************************/
U8 mmi_vcard_reader_get_field(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VCARD_FIELD_TOTAL; i++)
    {
        if (mmi_vobj_uti_cmp_filed(String, g_vcard_field[i]))
        {
            break;
        }
    }
    /* Add check for tag "N" here. Because the above check will confuse tag "N" and "NOTE" */
    if ((i == VCARD_FIELD_N) && !((String[1] == ':') || (String[1] == ';')))
    {
    #if defined(__MMI_PHB_INFO_FIELD__)
        return VCARD_FIELD_NOTE;
    #else /* defined(__MMI_PHB_INFO_FIELD__) */
        return VCARD_FIELD_TOTAL;
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_get_para_value
 * DESCRIPTION
 *  read the value of a vcard parameter
 * PARAMETERS
 *  String          [IN]        String read from file for one line
 *  para            [IN]        Parameter for getting value
 *  para_enum       [IN]        
 *  value           [OUT]       Value of parameter
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
U8 mmi_vcard_reader_get_para_value(S8 *String, const S8 *para, U8 para_enum, U8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *para_pos;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr(String, ":") == NULL)
    {
        return FALSE;
    }

    para_pos = strstr(String, para);

    if (para_pos != NULL)
    {
        para_pos = strstr(para_pos, "=") + 1;
        if (para_pos != NULL)
        {

            if (para_enum == VOBJ_PARA_CHARSET)
            {
                for (i = 0; i < VOBJ_CH_TOTAL; i++)
                {
                    if (mmi_vobj_uti_cmp_filed(para_pos, g_vobj_charset[i]))
                    {
                        break;
                    }
                }
                *value = i;
                return TRUE;
            }
            else if (para_enum == VOBJ_PARA_ENCODING)
            {
                for (i = 0; i < VOBJ_EN_TOTAL; i++)
                {
                    if (mmi_vobj_uti_cmp_filed(para_pos, g_vobj_encoding[i]))
                    {
                        break;
                    }
                }
                *value = i;
                return TRUE;
            }
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_reader_get_para_number
 * DESCRIPTION
 *  parse number field. there are several kinds of number field in vcard.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 *  type        [OUT]       Number type, voice or fax
 *  pref        [OUT]       Is this field a prefer number
 * RETURNS
 *  number parameter enum
 *****************************************************************************/
U8 mmi_vcard_reader_get_para_number(S8 *String, U8 *type, U8 *pref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *sep_pos;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr(String, ":") == NULL)
    {
        return FALSE;
    }

    *pref = FALSE;
    sep_pos = String;
    while ((sep_pos = strstr(sep_pos, ";")) != NULL)
    {
        sep_pos++;
        for (i = 0; i < VCARD_PARA_TOTAL; i++)
            if (mmi_vobj_uti_cmp_filed(sep_pos, g_vcard_para[i]))
            {
                break;
            }

        switch (i)
        {
            case VCARD_PARA_CELL:
                *type = VCARD_PARA_CELL;
                break;
            case VCARD_PARA_HOME:
                *type = VCARD_PARA_HOME;
                break;
            case VCARD_PARA_WORK:
                *type = VCARD_PARA_WORK;
                break;
            case VCARD_PARA_FAX:
                *type = VCARD_PARA_FAX;
                break;
            case VCARD_PARA_PAGER:
                *type = VCARD_PARA_PAGER;
            case VCARD_PARA_PREF:
                *pref = TRUE;
                break;
            default:
                break;
        }
        if ((i == VCARD_PARA_CELL) && ((g_vcard_number & 0x01) != 0x01))
        {
            g_vcard_number |= 0x01;
            break;
        }
        else if ((i == VCARD_PARA_HOME) && ((g_vcard_number & 0x02) != 0x02))
        {
            g_vcard_number |= 0x02;
            break;
        }
        else if ((i == VCARD_PARA_WORK) && ((g_vcard_number & 0x04) != 0x04))
        {
            g_vcard_number |= 0x04;
            break;
        }
        else if ((i == VCARD_PARA_FAX) && ((g_vcard_number & 0x08) != 0x08))
        {
            g_vcard_number |= 0x08;
            break;
        }
        else if (i == VCARD_PARA_PAGER)
        {
            break;
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_remove_field_delimiter
 * DESCRIPTION
 *  remove field delimiter in a string.
 * PARAMETERS
 *  str         [IN]        String to remove
 *  length      [IN]        Maximum length to parse
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_util_remove_field_delimiter(S8 *str, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    BOOL has_delimiter = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (i < length)
    {
        if (str[i] == '\0') /* End of string */
        {
            if (str[0] == '\0' && has_delimiter)
            {
                str[0] = ';';
                str[1] = '\0';
            }
            return;
        }

        if (str[i] == ';')  /* Remove ';' and shift string forward. */
        {
            has_delimiter = TRUE;
            for (j = i; j < length && str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
            continue;
        }
        else if (str[i] == '\\' && str[i+1] == ';')  /* Remove '\' and shift string forward. */
        {
            for (j = i; j < length && str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
        i++;
    }
}


#ifdef __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_get_name
 * DESCRIPTION
 *  Transform name in "First Name" "Last Name".
 * PARAMETERS
 *  str         [IN]        String to check
 *  length      [IN]        Maximum length to parse
 * RETURNS
 *  if character already transfrom or not
 *****************************************************************************/
static void mmi_vcard_util_get_name(S8 *str, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* last_name = OslMalloc(length + 1);
    S8* first_name = OslMalloc(length + 1);
    U16 i = 0, j = 0, num_of_semicolon = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(last_name, 0, 1);
    memset(first_name, 0, 1);
 
    while (i < length)
    {
    	if (str[i] == '\0')
        {
            if (num_of_semicolon == 0)
            {
                last_name[j] = '\0';
            }
            else if (num_of_semicolon == 1)
            {
                first_name[j] = '\0';
            }
            break;
        }
    	else if (str[i] == ';' && str[i - 1] != '\\')
        {
            num_of_semicolon ++;
            if (num_of_semicolon == 1)
            {
                last_name[j] = '\0';
                j = 0;                    
            }
            else if (num_of_semicolon == 2)
            {
                first_name[j] = '\0';
                break;
            }
        }
        else
        {
            if (!(str[i] == '\\' && (str[i + 1] == ';' || str[i + 1] == ',')))
            {
                if (num_of_semicolon == 0)
                {
                    last_name[j++] = str[i]; 
                }
                else if (num_of_semicolon == 1)
                {
                    first_name[j++] = str[i];
                }
            }
        }
        i++;
    }

    if (strlen(first_name))
    {
        strncpy(str, first_name, strlen(first_name));
		str[strlen(first_name)] = '\0';
        strcat(str, " ");
        strcat(str, last_name);
		str[strlen(first_name) + strlen(last_name) + 1] = '\0';        
    }
    else
    {
        strncpy(str, last_name, strlen(last_name));
		str[strlen(last_name)] = '\0';        
    }
    OslMfree(first_name);
    OslMfree(last_name);
}
#else /* __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_need_transform_name
 * DESCRIPTION
 *  Transform field delimiter in a string.
 * PARAMETERS
 *  str         [IN]        String to check
 *  length      [IN]        Maximum length to parse
 * RETURNS
 *  if character already transfrom or not
 *****************************************************************************/
static BOOL mmi_vcard_util_has_transform_name(S8 *str, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    BOOL has_semicolon = FALSE;
    U8 first_character_count = 0;
    U8 last_character_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    if (str[i] == ';')
    {
        return FALSE;
    }
    while (i < length - 1)
    {
        if (str[i] == '\0') /* End of string */
        {
            if (first_character_count > 0 && last_character_count > 0 && has_semicolon)
            {
                /* transform the first & last name */
                S8* family_name = OslMalloc(first_character_count + 1);
                memcpy(family_name, str, first_character_count);
                i = 0;
                //j = last_character_count;
                for (j = last_character_count; j > 0; j--)
                {
                    str[i] = str[first_character_count + 1 + i];
                    i++;
                }
                str[last_character_count] = ' ';
                memcpy(str + last_character_count + 1, family_name, first_character_count);
                OslMfree(family_name);
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        if (str[i] == '\\' && str[i + 1] == ';')  /* "\;" */
        {
            return FALSE;
        }
        else if (str[i] == ';' && str[i+1] != '\0')
        {
            if (has_semicolon)
            {
                return FALSE;
            }
            else
            {
                has_semicolon = TRUE;
            }
        }
        else if (has_semicolon)
        {
            last_character_count++;
        }
        else
        {
            first_character_count++;
        }
        i++;
    }
    return FALSE;
}
#endif /* __MMI_VCARD_NAME_IN_ENGLISH_FORMAT__ */


#if !defined(__MMI_VCARD_NAME_IN_ENGLISH_FORMAT__) || defined(__MMI_PHB_INFO_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_transform_field_delimiter
 * DESCRIPTION
 *  Transform field delimiter in a string.
 * PARAMETERS
 *  str         [IN]        String to transform
 *  length      [IN]        Maximum length to parse
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcard_util_transform_field_delimiter(S8 *str, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (i < length - 1)
    {
        if (str[i] == '\0') /* End of string */
        {
            /* 1. More than one character, then remove ";" (if not "\;") */
            if (i > 1 && str[i-1] == ';' && str[i-2] != '\\')
            {
                str[i-1] = '\0';
            }
            break;
        }
        if (str[i] == ';' && str[i + 1] != '\0')
        {
            if (i == 0 || str[i+1] == ';')  /* Remove ';' and shift string forward. */
            {
                for (j = i; j < length && str[j] != '\0'; j++)
                {
                    str[j] = str[j + 1];
                }
                str[j] = '\0';
                continue;
            }
        }
        i++;
    }
    
    i = 0;
    while (i < length - 1)
    {
        if (str[i] == '\0') /* End of string */
        {
            return;
        }
        if (str[i] == '\\' && str[i + 1] == ';')  /* Remove '\' and shift string forward. */
        {
            for (j = i; j < length && str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
            if (str[i + 2] == '\0')
            {
                break;
            }
        }
        else if (str[i] == ';' && str[i+1] != '\0')
        {
            /* change ';' to ', ' and shift string backward. */
            {
                str[i] = ',';
                for (j = length - 2; j > (i + 1); j--)
                {
                    str[j] = str[j - 1];
                }
                str[i+1] = ' ';
            }
            continue;
        }
        i++;
    }
}
#endif /* !defined(__MMI_VCARD_NAME_IN_ENGLISH_FORMAT__) || defined(__MMI_PHB_INFO_FIELD__) */

#if defined(__MMI_VCARD_V30__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_v30_number_field_preprocess
 * DESCRIPTION
 *  Transform field delimiter in a string.
 * PARAMETERS
 *  str         [IN]        String to transform
 *  length      [IN]        Maximum length to parse
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcard_util_v30_number_field_preprocess(S8 *str, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (i < length) 
    {
        if (str[i] == ':') /* End of type */
            return;

        if ((str[i] == 'T' || str[i] == 't') && 
            (str[i + 1] == 'Y' || str[i + 1] == 'y') && 
            (str[i + 2] == 'P' || str[i + 2] == 'p') && 
            (str[i + 3] == 'E' || str[i + 3] == 'e') && 
            str[i + 4] == '=')
        {
            for (j = i; j < length && str[j] != '\0'; j++)
            {
                str[j] = str[j + 5];
            }
            str[j] = '\0';
        }
        else if (str[i] == ',')
        {
            str[i] = ';';
        }
        i++;
    }
}
#endif /* defined(__MMI_VCARD_V30__) */
/*--------------------------------------------------END vcard parser ---------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_get_default_file
 * DESCRIPTION
 *  Create default file path for send operation.
 * PARAMETERS
 *  path        [IN/OUT]        Path buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_util_get_default_file(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ascii_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ascii_path = OslMalloc(VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH);
    sprintf(ascii_path, "%c:\\%s\\%s", VOBJ_DRV, VOBJ_FILE_PATH, VOBJ_VCARD_DEFAULT_FILE_NAME);
    mmi_asc_to_ucs2(path, ascii_path);
    OslMfree(ascii_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_get_default_file_name
 * DESCRIPTION
 *  Create default file path for send operation.
 * PARAMETERS
 *  path        [IN/OUT]        Path buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_util_get_default_file_name(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ascii_path;
    S8 *file_name;
    S8 filename[VOBJ_MAX_FILE_EXT_LEN];
    MMI_PHB_VCARD_STRUCT myCard;
    S16 pError;
    U16 name_length;
    U16 path_length;
    S8* temp_filename;
    S8* temp_ptr;
    U16 temp_filename_length = (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ascii_path = OslMalloc(VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH);
    sprintf(ascii_path, "%c:\\%s\\", VOBJ_DRV, VOBJ_FILE_PATH);
    mmi_asc_to_ucs2(path, ascii_path);    
    path_length = mmi_ucs2strlen(path);
    OslMfree(ascii_path);

    file_name = OslMalloc(VOBJ_MAX_FILENAME_LENGTH);
    if (VOBJ_MAX_FILENAME_LENGTH > (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH)
    {
        name_length = (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH;
    }
    else
    {
        name_length = VOBJ_MAX_FILENAME_LENGTH;        
    }

    temp_filename = OslMalloc(temp_filename_length);
    if (g_vcard_cntx.CardType == MMI_VCARD_SEND_MY_CARD)
    {
        ReadRecord(NVRAM_EF_PHB_VCARD_LID, 1, (void*)&myCard, MMI_PHB_VCARD_RECORD_SIZE, &pError);
        memcpy(temp_filename, myCard.name, temp_filename_length);
    }
    else
    {
        memcpy(
            temp_filename,
            PhoneBook[g_phb_name_index[g_phb_cntx.active_index]].alpha_id.name,
            temp_filename_length);
    }
    temp_ptr = mmi_fmgr_skip_space(temp_filename);
    mmi_ucs2cpy(file_name, temp_ptr);
    OslMfree(temp_filename);

    if (!mmi_fmgr_is_filename_valid(file_name))
    {
        mmi_asc_to_ucs2(file_name, "~vcard");
        mmi_ucs2cat(path, file_name);
    }
    else
    {
        if ((path_length + name_length + VOBJ_MAX_FILE_EXT_LEN / ENCODING_LENGTH) > VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH)
        {
            mmi_ucs2ncat(path, file_name, (VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH - path_length - VOBJ_MAX_FILE_EXT_LEN / ENCODING_LENGTH));
        }
        else
        {
            mmi_ucs2cat(path, file_name);
        }
    }
    OslMfree(file_name);
    mmi_asc_to_ucs2(filename, VOBJ_VCARD_FILE_EXT);
    mmi_ucs2cat(path, filename);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_del_default_file
 * DESCRIPTION
 *  delete default file path after sending.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_util_del_default_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
    mmi_vcard_util_get_default_file(path);
    FS_Delete((U16*) path);
    OslMfree(path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_convert_to_system_encoding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vcard_util_convert_to_system_encoding(S8 *dst, S8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)src, (char*)dst, VCARD_WRITER_FIELD_BUFFER);

    return VOBJ_CH_UTF8;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_util_convert_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcard_util_convert_to_ucs2(S8 *dst, U8 dst_size, S8 *src, U8 encode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (encode == VOBJ_CH_UTF8)
    {
        mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)src, (char*)dst, dst_size);
    }
#ifdef __MMI_CHSET_UTF7__	
    else if (encode == VOBJ_CH_UTF7)
    {
        mmi_chset_convert(MMI_CHSET_UTF7, MMI_CHSET_UCS2, (char*)src, (char*)dst, dst_size);
    }
#endif /* __MMI_CHSET_UTF7__ */
    else
    {
        mmi_chset_convert(g_vcard_cntx.CharSet, MMI_CHSET_UCS2, (char*)src, (char*)dst, dst_size);
    }
}

#endif /* defined(__MMI_VCARD__) */ /* END #if defined(__MMI_VCARD__) */
#endif /* _MMI_VCARD_C */ /* END #define _MMI_VCARD_C */

