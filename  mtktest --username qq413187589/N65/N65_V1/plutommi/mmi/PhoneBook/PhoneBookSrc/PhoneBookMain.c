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
 * PhoneBookMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for phonebook main function.
 *   Including initialize procedure, main menu, common utilities, etc.
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
 *
 *
 * removed!
 * removed!
 *
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
#ifndef _PHONEBOOKMAIN_C
#define _PHONEBOOKMAIN_C

#include "ProtocolEvents.h"
#include "wgui_status_icons.h"
#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhonebookProt.h"
#include "PhonebookGprot.h"
#include "mainmenudef.h"
#include "IdleAppDef.h"
#include "SpeedDial.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "CommonScreens.h"
#include "SettingGprots.h"
#include "gpioInc.h"
#include "CommonScreens.h"
#include "SettingDefs.h"        /* For FDN on Message */
#include "SettingsGdcl.h"
#include "custom_equipment.h"
#include "nvram_data_items.h"
#include "GSM7BitDefaultAlphabet.h"
#if defined(__MMI_PHB_UPDATE_CALL_LOG_AFTER_SAVE__)     /* Update Call Log after save number */
#include "CallHistoryGProts.h"
#endif 
#if defined(__MMI_FILE_MANAGER__)
#endif

#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
#include "PhoneBookJavaHandler.h"
#endif 

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
#include "ProfileGprots.h"
#endif 
#include "CallManagementGprot.h"

#if defined(__MMI_VRSI__)
#include "Mdi_datatype.h"
#include "VRSIResDef.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#endif /* defined(__MMI_VRSI__) */ 

#if !defined(__MMI_KEYPADLOCK_WITH_KEYTONE__)
#endif 

#include "PictureEditorDefs.h"
#include "SimDetectionGprot.h"

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */

#ifdef __USB_IN_NORMAL_MODE__ 
#include "USBDeviceGprot.h"
#endif /* __USB_IN_NORMAL_MODE__ */

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_Master_ADN.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_CC.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

/*
 * Local Variable
 */
static PHB_OPTIONAL_IDS_STRUCT g_phb_optional_ids;
static PHB_CALLER_GROUP_STRUCT g_phb_caller_group[MAX_PB_CALLER_GROUPS];

#ifdef __MMI_PHB_USIM_FIELD__
static MMI_PHB_NAME_STRUCT g_phb_usim_group[MAX_PB_USIM_GROUPS];
#endif 

static U16 g_phb_message;
static U16 g_phb_message_icon;
static U16 g_phb_alpha_index_list[ALPHA_LIST_LENGTH];
static U16 g_phb_highlight_alpha;

#if defined(__MMI_VOIP__)
static U8 phb_voip_number_index = 0xff;
#endif 

#if defined(__MMI_PHB_NAME_LIST_FILTER__)
static U32 g_phb_list_index_total;
#endif /* defined(__MMI_PHB_NAME_LIST_FILTER__) */

mmi_phb_context_struct g_phb_cntx;

U16 PhoneBookEntryCount;

#if (MAX_PB_ENTRIES)
U16 g_phb_name_index[MAX_PB_ENTRIES];   /* Sorting Order by Name Field. */
MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[MAX_PB_ENTRIES];

#if (MAX_PB_ENTRIES >= 1000)
U16 g_phb_list_filter[MAX_PB_ENTRIES];
#endif /* MAX_PB_ENTRIES >= 1000 */
#else /* (MAX_PB_ENTRIES) */ 
U16 g_phb_name_index[1];    /* Sorting Order by Name Field. */
MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[1];
#endif /* (MAX_PB_ENTRIES) */ 

#ifdef __MMI_PHB_USIM_FIELD__
MMI_PHB_EMAIL_STRUCT phb_email[MAX_PB_SIM_ENTRIES];
MMI_PHB_NUMBER_BCD_STRUCT phb_anr[MAX_PB_SIM_ENTRIES][3];
#endif /* __MMI_PHB_USIM_FIELD__ */ 

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
#endif 
MMI_PHB_LOOKUP_NODE_STRUCT LookUpTable[MAX_LOOKUP_TABLE_COUNT];

#ifdef __MTK_TARGET__
__align(2)
#endif
S8 pbName[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
#ifdef __MTK_TARGET__
__align(2)
#endif
S8 pbNumber[(MAX_PB_NUMBER_LENGTH+1+1)*ENCODING_LENGTH];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
S8 pbHomeNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];      /* ANRA */
S8 pbCompanyName[(MAX_PB_COMPANY_LENGTH + 1) * ENCODING_LENGTH];        /* ANRB */
S8 pbEmailAddress[(MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH];
S8 pbOfficeNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
S8 pbFaxNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];       /* ANRC */
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
S8 pbBday[12 * ENCODING_LENGTH];    /* Use for display total sstring, Format: xxxx/xx/xx */
S8 pbDay[3 * ENCODING_LENGTH];
S8 pbMon[3 * ENCODING_LENGTH];
S8 pbYear[6 * ENCODING_LENGTH];
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
#if defined(__MMI_PHB_INFO_FIELD__)
PHB_INFO_FIELDS_STRUCT PhoneBookInfoFields;
S8 pbTitle[(MAX_PB_TITLE_LENGTH + 1) * ENCODING_LENGTH];
S8 pbUrl[(MAX_PB_URL_LENGTH + 1) * ENCODING_LENGTH];
S8 pbAddress[(MAX_PB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
S8 pbNote[(MAX_PB_NOTE_LENGTH + 1) * ENCODING_LENGTH];
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 

#if defined(__MMI_PHB_IMPS_FIELD__)
S8 PhoneBookImpsField[MAX_PB_IMPS_LENGTH + 1];
S8 pbImps[(MAX_PB_IMPS_LENGTH + 1) * ENCODING_LENGTH];
#endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 

#if defined(__MMI_VOIP__)
S8 PhoneBookVoipField[VOIP_URI_LEN];
S8 pbVoip[(VOIP_URI_LEN) * ENCODING_LENGTH];
#endif /* defined(__MMI_VOIP__) */ 

#ifdef __MMI_PHB_USIM_FIELD__
S8 pbNickName[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
#endif 

U8 gPictureItemIndex = 10;
U16 TitleStrings[MAX_PB_FIELDS];

#ifdef __MMI_INTELLIGENT_CALL_ALERT__
U8 g_phb_is_speaking_name = 0;
#endif 

/*
 * Global Variable
 */
extern MMI_PHB_LIST_VIEW phbListView;
extern wgui_inline_item wgui_inline_items[];
extern BOOL r2lMMIFlag; /* For right to left language */
extern U16 g_phb_read_index;

extern BOOL g_phb_mass_op_success;  /* for sim refresh */
extern U16 g_phb_mass_op_count;

extern U8 g_phb_enter_from;

/*
 * Global Function
 */
extern void MakeCall(PS8);
extern void set_wgui_inline_list_menu_changed(void);

#if defined(__IP_NUMBER__)
extern void SetTempUseIPNumber(pBOOL flag);
#endif 
#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)
static U8 g_phb_sim_check;
#ifdef __GEMINI__
extern kal_bool is_sim_replaced(kal_uint8 simInterface);
#else /* __GEMINI__ */
extern kal_bool is_sim_replaced(void);
#endif /* __GEMINI__ */
#endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 

#if defined(__MMI_FILE_MANAGER__)
extern void Cat212ShortCutHdlr(S32 item_index); /* For Image List Fast Jump */
#endif 

/*
 * Static Function
 */
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
static void mmi_phb_two_line_send_key_handler(void);
#endif 

#ifdef __MMI_PHB_USIM_FIELD__
static void mmi_phb_ind_startup_phase1_finish(void *info);
static void mmi_phb_startup_anr_read_rsp(void *info);
static void mmi_phb_startup_email_read_rsp(void *info);
static void mmi_phb_startup_gas_read_rsp(void *info);
static void mmi_phb_read_usim_field(U8 access_id);
static void mmi_phb_read_usim_anr_field(void *info);
static void mmi_phb_read_usim_email_field(void *info);
static void mmi_phb_read_usim_gas_field(void *info);
static void mmi_phb_read_usim_grp_field(void *info);
#endif /* __MMI_PHB_USIM_FIELD__ */ 


#define MMI_PHB_INIT
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_protocol
 * DESCRIPTION
 *  Initialize phonebook protocol handler. This should be call before L4 begin to read
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init_protocol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_init_protocol.>\n", __FILE__, __LINE__);
#ifdef __MMI_PHB_USIM_FIELD__
    SetProtocolEventHandler(mmi_phb_ind_startup_phase1_finish, PRT_PHB_STARTUP_PHASE1_FINISH_IND);
    SetProtocolEventHandler(mmi_phb_read_usim_anr_field, PRT_PHB_STARTUP_READ_ANR_IND);
    SetProtocolEventHandler(mmi_phb_read_usim_email_field, PRT_PHB_STARTUP_READ_EMAIL_IND);
    SetProtocolEventHandler(mmi_phb_read_usim_gas_field, PRT_PHB_STARTUP_READ_GAS_IND);
    SetProtocolEventHandler(mmi_phb_read_usim_grp_field, PRT_PHB_STARTUP_READ_GRP_IND);
#endif /* __MMI_PHB_USIM_FIELD__ */ 

    SetProtocolEventHandler(mmi_phb_ind_startup_finish, PRT_PHB_STARTUP_FINISH_IND);
    SetProtocolEventHandler(mmi_phb_ind_startup_begin, PRT_PHB_STARTUP_BEGIN_IND);
    SetProtocolEventHandler(mmi_phb_ind_startup_read, PRT_PHB_STARTUP_READ_IND);

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    mmi_phb_java_handler_init();
#endif 

    /* Initial Global Context. */
    g_phb_cntx.phb_ready = FALSE;
    g_phb_cntx.processing = FALSE;
    g_phb_cntx.nvram_data_init = FALSE;
    g_phb_cntx.optional_ids = &g_phb_optional_ids;
    g_phb_cntx.caller_group = &g_phb_caller_group[0];
#ifdef __MMI_PHB_USIM_FIELD__
    g_phb_cntx.usim_group = &g_phb_usim_group[0];
    g_phb_cntx.usim_ready_stage = MMI_PHB_USIM_NOT_READY;
    memset(g_phb_cntx.support_field, 0, MMI_PHB_USIM_FIELD_TOTAL);
#endif /* __MMI_PHB_USIM_FIELD__ */ 
    g_phb_cntx.list_filter = NULL;
    g_phb_cntx.start_scr_id = 0;
    g_phb_cntx.end_scr_id = 0;
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;
    g_phb_cntx.highlight_entry = 0;
    g_phb_cntx.new_highlight_entry = 0xffff;
    PhoneBookEntryCount = 0;
    g_phb_cntx.sim_used = 0;
    g_phb_cntx.phone_used = 0;
    g_phb_cntx.populate_count = 0;
    g_phb_cntx.lookup_table_count = 0;
    g_phb_cntx.current_op = MMI_PHB_OP_NONE;

    g_phb_cntx.selected_pic_index = 0;
    g_phb_cntx.selected_ring_index = 0;
    g_phb_cntx.selected_grp_index = 0;
    g_phb_cntx.selected_pattern_index = 0;
    g_phb_cntx.selected_alert_index = 0;
    g_phb_cntx.selected_pic_in_view = 0;
    g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
    g_phb_cntx.set_done_flag = 0;
    g_phb_cntx.dial_from_list = MMI_PHB_NONE;
#if defined(__MMI_PHB_PINYIN_SORT__)
    g_phb_cntx.sort_type = MMI_PHB_SORT_PINYIN;
#else 
    g_phb_cntx.sort_type = MMI_PHB_SORT_ENCODING;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init
 * DESCRIPTION
 *  Initialize phonebook applications.
 *  (This is used to initialize hilite/hint handlers and PS reponse callback functions)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_init.>\n", __FILE__, __LINE__);

    mmi_phb_search_init();
    mmi_phb_operate_single_init();
    mmi_phb_operate_mass_init();
    mmi_phb_caller_group_init();
    mmi_phb_extra_number_init();
    mmi_phb_setting_init();
    PhbInitSpeedDial();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_main_menu_highlight_handler
 * DESCRIPTION
 *  Set phonebook main menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_set_main_menu_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_set_main_menu_highlight_handler.>\n",
                         __FILE__, __LINE__);

    SetHiliteHandler(MITEM101_PBOOK_SEARCH_ENTRY, mmi_phb_highlight_search_name);
#if defined(__MMI_PHB_QUICK_SEARCH__)
    SetHiliteHandler(MENU_ID_PHB_QUICK_SEARCH, mmi_phb_highlight_quick_search_list);
#endif 

    /* Add Entry */
    SetHiliteHandler(MITEM102_PBOOK_NEW_ENTRY, mmi_phb_highlight_op_add_entry);

#if defined(__MMI_PHB_MULTI_OPERATION__)
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP, mmi_phb_highlight_multi_operation);
#else
    /* Copy All */
    SetHiliteHandler(MITEM104_PBOOK_COPY_ALL, mmi_phb_highlight_copy_all);

//huzhuhua 080722 begin
#ifdef __PHONEBOOK_OUTPUT_INPUT__
      SetHiliteHandler(MITEM104_PBOOK_OUTPUT, mmi_phb_output_highlight);
#endif
#ifdef __PHONEBOOK_INPUT__
      SetHiliteHandler(MITEM104_PBOOK_INPUT, mmi_phb_input_highlight);
      pb_input_init();
#endif
//end

    /* Delete All */
    SetHiliteHandler(MITEM103_PBOOK_DELETE_ALL, mmi_phb_highlight_delete_all);
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
    SetHiliteHandler(MITEM109_PBOOK_CALLER_GROUPS, mmi_phb_highlight_callergroup);

    mmi_phb_extra_number_init();

    /* Settings */
    SetHiliteHandler(MITEM110_PBOOK_SETTINGS, mmi_phb_highlight_setting);
    SetHiliteHandler(MITEM1101_PBOOK_MEMORY_STATUS, mmi_phb_highlight_memory_status);
    SetHiliteHandler(MITEM1102_PBOOK_STORAGE_LOCATION, mmi_phb_highlight_storage_location);
    SetHiliteHandler(MITEM1103_PBOOK_VIEW_FIELDS, mmi_phb_highlight_view_field);

    SetHintHandler(MITEM1102_PBOOK_STORAGE_LOCATION, mmi_phb_hint_storage_location);
    SetHintHandler(MITEM_STORAGE_LOCATION_SIM, mmi_phb_hint_storage_location_in_sim);
    SetHintHandler(MITEM_STORAGE_LOCATION_PHONE, mmi_phb_hint_storage_location_in_phone);

#if defined(__MMI_PHB_NAME_LIST_FILTER__)
    SetHiliteHandler(MENU_ID_PHB_NAME_LIST_FILTER, mmi_phb_highlight_name_list_filter);		
    SetHintHandler(MENU_ID_PHB_NAME_LIST_FILTER, mmi_phb_hint_name_list_filter);
#endif /* defined(__MMI_PHB_NAME_LIST_FILTER__) */
    
#if defined(__MMI_VCARD__)
    /* My vCard */
    SetHiliteHandler(MENU_ID_PHB_VCARD_MYCARD, mmi_phb_highlight_vcard_mycard);
    SetHiliteHandler(MENU_ID_PHB_VCARD_EDIT_MYCARD, mmi_phb_highlight_vcard_edit_mycard);
    SetHiliteHandler(MENU_ID_PHB_VCARD_SEND_MYCARD, mmi_phb_highlight_vcard_send_mycard);
#if defined(__MMI_VCARD_V30__)
    /* vCard version */
    SetHiliteHandler(MENU_ID_PHB_VCARD_VERSION, mmi_phb_highlight_vcard_version);
    SetHintHandler(MENU_ID_PHB_VCARD_VERSION, mmi_phb_hint_vcard_version);
    SetHiliteHandler(MENU_ID_PHB_VCARD_VERSION_21, mmi_phb_highlight_vcard_version_21);
    SetHiliteHandler(MENU_ID_PHB_VCARD_VERSION_30, mmi_phb_highlight_vcard_version_30);
#endif /* defined(__MMI_VCARD_V30__) */
#endif /* defined(__MMI_VCARD__) */
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    SetHiliteHandler(MENU_ID_PHB_SPEAK_NAME, mmi_phb_highlight_speak_name);
    SetHintHandler(MENU_ID_PHB_SPEAK_NAME, mmi_phb_hint_speak_name);
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

    /* Forward resource to phonebook entry */
#if defined(__MMI_PHB_CALLER_RES_SETTING__)
    /* For submenu in phonebook */
    SetHiliteHandler(MENU_ID_PHB_CALLER_PIC, mmi_phb_highlight_caller_pic);
    SetHiliteHandler(MENU_ID_PHB_CALLER_RING, mmi_phb_highlight_caller_ring);
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    SetHiliteHandler(MENU_ID_PHB_CALLER_VIDEO, mmi_phb_highlight_caller_video);
#endif 
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 

#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    /* Save Image From File Manager */
    SetHiliteHandler(MENU_ID_PHB_FMGR_SAVE_NEW, mmi_phb_highlight_fmgr_add_entry);
    SetHiliteHandler(MENU_ID_PHB_FMGR_SAVE_LIST, mmi_phb_highlight_fmgr_edit_entry);
    SetHiliteHandler(MENU_ID_PHB_FMGR_SAVE_CALLGRP, mmi_phb_highlight_edit_callergroup);
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

    /* Done and Input Method */
    mmi_frm_set_highlight_handler();
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_begin
 * DESCRIPTION
 *  Initialize variables before L4 Phb start to read
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_reset_phb_entry_before_begin(U8 module_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 phb_min_index, phb_max_index;
    U16 total_count, max_total;
    U16 i, j, temp_store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_total = MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES + MAX_PB_SIM2_ENTRIES;

    if (module_id == 0)
    {
    	phb_min_index = 0;
    	phb_max_index = MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES;
    }
    else
    {
    	phb_min_index = MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES;
        phb_max_index = MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES + MAX_PB_SIM2_ENTRIES;
    }
    
    total_count = PhoneBookEntryCount;
    for (i = 0; i < total_count; i++)
    {
    	temp_store_index = g_phb_name_index[i];
    	if ((temp_store_index >= phb_min_index) && (temp_store_index < phb_max_index))
        {
        	g_phb_name_index[i] = max_total;
        	PhoneBookEntryCount--;
        }
    }
    i = 0;
    j = 0;
    while (i < PhoneBookEntryCount)
    {
    	if (g_phb_name_index[i] == max_total)
        {
        	while (j < total_count)
            {
            	if ((j > i) && (g_phb_name_index[j] != max_total))
                {
                	g_phb_name_index[i] = g_phb_name_index[j];
                	g_phb_name_index[j] = max_total;
                	break;
                }
                j++;
            }
        }
        i++;
    }
g_phb_cntx.lookup_table_count = 0;
}
#endif /*__MMI_DUAL_SIM_MASTER__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_begin
 * DESCRIPTION
 *  Initialize variables before L4 Phb start to read
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ind_startup_begin(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.phb_ready = FALSE;
#ifdef __MMI_PHB_USIM_FIELD__
    g_phb_cntx.usim_ready_stage = MMI_PHB_USIM_NOT_READY;
#endif 
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((g_phb_cntx.sim_used + g_phb_cntx.phone_used) != 0)
    {
        mmi_phb_reset_phb_entry_before_begin(0);
    }
    g_phb_cntx.startup_before_sort = FALSE;
#else /* __MMI_DUAL_SIM_MASTER__ */
    PhoneBookEntryCount = 0;
    g_phb_cntx.lookup_table_count = 0;
#endif /* __MMI_DUAL_SIM_MASTER__ */
    g_phb_cntx.sim_used = 0;
    g_phb_cntx.phone_used = 0;
    g_phb_cntx.populate_count = 0;
    g_phb_cntx.current_op = MMI_PHB_OP_NONE;

#if defined(__MMI_VRSI__)
    /* Phonebook reload so need reset VR. After sorting done, add phonebook entry again. */
    mmi_vrsi_init_central_reset();
#endif /* defined(__MMI_VRSI__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sat_handler
 * DESCRIPTION
 *  Handler sim refresh cmd
 * PARAMETERS
 *  reset_adn        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sat_handler(BOOL reset_adn)
{
    g_phb_cntx.phb_ready = FALSE;
#ifdef __MMI_PHB_USIM_FIELD__
    g_phb_cntx.usim_ready_stage = MMI_PHB_USIM_NOT_READY;
#endif

#ifndef __MMI_DUAL_SIM_MASTER__
    if (reset_adn)
    {
        g_phb_cntx.sim_used = 0;
        g_phb_cntx.phone_used = 0;
        PhoneBookEntryCount = 0;
    }
    g_phb_cntx.lookup_table_count = 0;
    g_phb_cntx.populate_count = 0;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_phb_sat_handler_end_current_op();
}

void mmi_phb_sat_handler_end_current_op(void)
{
#if defined(__MMI_VRSI__)
    /* Phonebook reload so need reset VR. After sorting done, add phonebook entry again. */
    mmi_vrsi_init_central_reset();
#endif /* defined(__MMI_VRSI__) */ 

    if (g_phb_cntx.processing)
    {
        S8 outBuf[100], count[10];

        g_phb_cntx.processing = FALSE;
        TurnOnBacklight(1); /* Turn On Back Light When done */
        DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
        if (g_phb_cntx.copy_all
        #ifdef __MMI_DUAL_SIM_MASTER__
            || MTPNP_PFAL_ADN_get_slave_is_copy_all()
        #endif
            )
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            if (MTPNP_PFAL_ADN_get_slave_is_copy_all() == TRUE)
            {
                MTPNP_PFAL_ADN_set_slave_is_copy_all(FALSE);
                MTPNP_PFAL_ADN_set_slave_mass_op_success_flag(TRUE);
                sprintf(count, "%d ", MTPNP_PFAL_ADN_get_slave_mass_op_count());
            }
            else
        #endif
            {
                g_phb_cntx.copy_all = FALSE;
                /* Display result for !g_phb_mass_op_success */
                g_phb_mass_op_success = TRUE;
                sprintf(count, "%d ", g_phb_mass_op_count);
            }
            mmi_asc_to_ucs2(outBuf, count);
            if (g_phb_mass_op_count <= 1)
            {
                mmi_ucs2cat(outBuf, GetString(STR_ENTRY_COPIED));
            }
            else
            {
                mmi_ucs2cat(outBuf, GetString(STR_ENTRIES_COPIED));
            }
            DisplayPopup((PU8) outBuf, IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);

            /* Solve Copying Screen Hang Problem */
            DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);
        }
        else
        {
            /* Display result for !g_phb_mass_op_success */
        #ifdef __MMI_DUAL_SIM_MASTER__
            if (MTPNP_PFAL_ADN_get_slave_is_delete_all() == TRUE)
            {
                MTPNP_PFAL_ADN_set_slave_is_delete_all(FALSE);
                MTPNP_PFAL_ADN_set_slave_mass_op_success_flag(TRUE);
                sprintf(count, "%d ", MTPNP_PFAL_ADN_get_slave_mass_op_count());
            }
            else
        #endif
            {
                g_phb_mass_op_success = TRUE;
                sprintf(count, "%d ", g_phb_mass_op_count);
            }
            mmi_asc_to_ucs2(outBuf, count);
            if (g_phb_mass_op_count <= 1)
            {
                mmi_ucs2cat(outBuf, GetString(STR_ID_PHB_ENTRY_DELETED));
            }
            else
            {
                mmi_ucs2cat(outBuf, GetString(STR_ID_PHB_ENTRIES_DELETED));
            }
            DisplayPopup((U8*) outBuf, IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);

            /* Solve Copying Screen Hang Problem */
            DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);

            /* Re-add all central command for vrsi. */
        #if defined(__MMI_VRSI__)
            mmi_vrsi_init_central_abort();
            /* Also remove SD tag if entry is deleted. */
        #if defined(__MMI_VRSI_TRAIN_TAG__)
            mmi_vrsi_ndial_central_update_sd_mapping();
        #endif 
        #endif /* defined(__MMI_VRSI__) */ 
        }
    }
    else if (g_phb_cntx.current_op == MMI_PHB_OP_ADD)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        mmi_phb_clear_old_add_history();
    }
    else if (g_phb_cntx.current_op == MMI_PHB_OP_EDIT)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        mmi_phb_clear_old_edit_history();
    }
    g_phb_enter_from = MMI_PHB_ENTER_NONE;
    /* copyEntry = duplicateEntry = moveEntry = FALSE;*/
    g_phb_cntx.current_op = MMI_PHB_NONE;
}


#ifdef __MMI_INTELLIGENT_CALL_ALERT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speak_name_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speak_name_handler(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_is_speaking_name = 0;
}
#endif /* __MMI_INTELLIGENT_CALL_ALERT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_read_entry
 * DESCRIPTION
 *  This function set the read indication data from L4 Phb at bootup time.
 *  Stores each indication to the global phonebook list.
 * PARAMETERS
 *  phb_entry       [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_read_entry(l4c_phb_bcd_entry_struct phb_entry, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U8 bcd_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhoneBook[store_index].field = 0;
    /* Name Field */
    PhoneBook[store_index].alpha_id.name_length = phb_entry.alpha_id.name_length;
    PhoneBook[store_index].alpha_id.name_dcs = phb_entry.alpha_id.name_dcs;

    if (PhoneBook[store_index].alpha_id.name_length == 0 
        || (phb_entry.alpha_id.name[0] == 0xff && phb_entry.alpha_id.name[1] == 0xff))
    {
        memset(PhoneBook[store_index].alpha_id.name, 0, 2);
    }
    else
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        InputboxConvertGSMToDeviceEncoding(
            phb_entry.alpha_id.name,
            PhoneBook[store_index].alpha_id.name,
            phb_entry.alpha_id.name_length,
            (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
            phb_entry.alpha_id.name_dcs,
            0,
            1);
    }
#if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
    if (PhoneBook[store_index].alpha_id.name_dcs == MMI_PHB_UCS2_81 ||
        PhoneBook[store_index].alpha_id.name_dcs == MMI_PHB_UCS2_82)
    {
        PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_UCS2;
    }
#endif /* defined(__PHB_0x81_SUPPORT__) */ 

#if defined(__MMI_PHB_PINYIN_SORT__)
    mmi_phb_util_make_pinyin_cache(store_index);
#endif 

    /* Number Field
       For L4 phb struct, the first byte of addr_bcd is TON, and the rest are BCD numbers.
       And the length is the total byte of TON + BCD numbers. */
    PhoneBook[store_index].tel.type = phb_entry.tel.addr_bcd[0];
    if (phb_entry.tel.addr_length > 0)
    {
        bcd_length =
            ((phb_entry.tel.addr_length - 1) <
             ((MAX_PB_NUMBER_LENGTH + 1) / 2)) ? (phb_entry.tel.addr_length - 1) : ((MAX_PB_NUMBER_LENGTH + 1) / 2);
    }

    if (bcd_length > 0)
    {
        /* strncpy((S8*)PhoneBook[store_index].tel.number, (S8*)(LocalPtr->phb_entry.tel.addr_bcd+1), (MAX_PB_NUMBER_LENGTH + 1) / 2); */
        memset(PhoneBook[store_index].tel.number, 0xff, ((MAX_PB_NUMBER_LENGTH + 1) / 2));
        memcpy(PhoneBook[store_index].tel.number, (phb_entry.tel.addr_bcd + 1), bcd_length);
    }
    else
    {
        PhoneBook[store_index].tel.number[0] = 0xff;
    }
    mmi_phb_convert_to_digit(num_ascii, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    PhoneBook[store_index].tel.length = strlen((S8*) num_ascii);

    /* Update flag for number exists entry, Clear it first. */
    if ((PhoneBook[store_index].tel.number[0] & 0x0f) != 0x0f)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
    }

#ifdef __MMI_PHB_USIM_FIELD__
    if (store_index >= MAX_PB_PHONE_ENTRIES) /* No matter sim or usim */
    {
        phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].number[0] = 0xff;
        phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].number[0] = 0xff;
        phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].number[0] = 0xff;
        memset(phb_email[store_index - MAX_PB_PHONE_ENTRIES].email_address, 0, 2);
    }
#endif /* __MMI_PHB_USIM_FIELD__ */ 

    g_phb_name_index[PhoneBookEntryCount] = store_index;
    PhoneBookEntryCount++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_read
 * DESCRIPTION
 *  This function receives the read indication from L4 Phb at bootup time.
 *  Stores each indication to the global phonebook list.
 * PARAMETERS
 *  info        [IN]        Indication from L4 PHB
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ind_startup_read(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_READ_IND_STRUCT *LocalPtr;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LocalPtr = (MSG_PHB_STARTUP_READ_IND_STRUCT*) info;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "record_index: [%d]  storage: [%d] \n",
                         LocalPtr->phb_entries[0].phb_entry[0].record_index,
                         LocalPtr->phb_entries[0].phb_entry[0].storage);

    /* Send read confirm messaeg back to L4 */
    mmi_phb_ind_startup_read_next_req(LocalPtr->access_id);

    /* Parse and save data from indication */
    if (LocalPtr->phb_entries[0].phb_entry[0].storage == MMI_SIM && (mmi_bootup_is_sim_valid() && !gSecuritySetupContext.FdlStatus))
    {
        g_phb_cntx.sim_used++;
        store_index = LocalPtr->phb_entries[0].phb_entry[0].record_index + MAX_PB_PHONE_ENTRIES - 1;    /* Storage Location in array. */
        MMI_ASSERT((g_phb_cntx.sim_used <= MAX_PB_SIM_ENTRIES) && (store_index < MAX_PB_ENTRIES));
        mmi_phb_startup_read_entry(LocalPtr->phb_entries[0].phb_entry[0], store_index);
    }
    else if (LocalPtr->phb_entries[0].phb_entry[0].storage == MMI_NVRAM) /* NVRAM has multiple-read */
    {
        int i;

        for (i = 0; i < LocalPtr->phb_entries[0].num_of_entry; i++)
        {
            g_phb_cntx.phone_used++;
            store_index = LocalPtr->phb_entries[0].phb_entry[i].record_index - 1;       /* Storage Location in array. */
            MMI_ASSERT((g_phb_cntx.phone_used <= MAX_PB_PHONE_ENTRIES) && (store_index < MAX_PB_PHONE_ENTRIES));
            mmi_phb_startup_read_entry(LocalPtr->phb_entries[0].phb_entry[i], store_index);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_read_next_req
 * DESCRIPTION
 *  This function receives the read indication from L4 Phb at bootup time.
 *  and send confirm to L4 to read next entry.
 * PARAMETERS
 *  access_id       [IN]        
 *  info(?)         [IN]        Indication from L4 PHB
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ind_startup_read_next_req(U8 access_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_READ_NEXT_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (MSG_PHB_STARTUP_READ_NEXT_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_STARTUP_READ_NEXT_REQ_STRUCT));
    myMsgPtr->access_id = access_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_STARTUP_READ_NEXT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}

void mmi_phb_startup_finish_final_step(void)
{
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((g_phb_cntx.startup_before_sort == TRUE) && (MTPNP_PFAL_ADN_Is_PHB_Before_Sort()))
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
    #if defined(__MMI_PHB_BOOT_UP_RECURSIVE_SORTING__)
        if (PhoneBookEntryCount > 1)
        {        
            mmi_phb_sort_build_name_index_with_timer();
        }
        else
        {
            mmi_phb_ind_startup_finish_after_name_sort();
        }
    #else /* defined(__MMI_PHB_BOOT_UP_RECURSIVE_SORTING__) */
        /* Sort name list */
        mmi_phb_sort_build_name_index();
        mmi_phb_ind_startup_finish_after_name_sort();
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_finish
 * DESCRIPTION
 *  Reads the Phonebook ready indication from PS and prepare to sort.
 * PARAMETERS
 *  info        [IN]        Finish indication
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ind_startup_finish(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_FINISH_IND_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_ind_startup_finish.>\n", __FILE__,
                         __LINE__);

    localPtr = (MSG_PHB_STARTUP_FINISH_IND_STRUCT*) info;
#ifdef __MMI_PHB_USIM_FIELD__
    g_phb_cntx.usim_ready_stage = MMI_PHB_USIM_READY;
    if (!g_phb_cntx.is_usim)
#endif /* __MMI_PHB_USIM_FIELD__ */ 
    {
        g_phb_cntx.sim_name_len = localPtr->phb_len;
        g_phb_cntx.fdn_name_len = localPtr->fdn_len;
        g_phb_cntx.bdn_name_len = localPtr->bdn_len;
        g_phb_cntx.owner_name_len = localPtr->owner_len;
        g_phb_cntx.sim_total = localPtr->sim_max_num;
        g_phb_cntx.phone_total = localPtr->phb_max_num;

        if (g_phb_cntx.sim_total > MAX_PB_SIM_ENTRIES)
        {
            g_phb_cntx.sim_total = MAX_PB_SIM_ENTRIES;
        }
        if (g_phb_cntx.phone_total > MAX_PB_PHONE_ENTRIES)
        {
            g_phb_cntx.phone_total = MAX_PB_PHONE_ENTRIES;  /* This two values should be the same */
        }

        if (!g_phb_cntx.nvram_data_init)
        {
            mmi_phb_init_get_data_from_nvram();
            g_phb_cntx.nvram_data_init = TRUE;
        }

        /*
         *   Use SIM storage buffer to store FDN list when FDN is enable.
         *   Because when FDN is enable, the ADN entry cannot be retrieved from SIM card.
         *   This list is for incoming call lookup name usage.
         *
         *   Note: Be sure to retrieve speed dial number after retrieve FDN list.
         */
        if (gSecuritySetupContext.FdlStatus)
        {
            mmi_phb_fdn_get_list_to_ram();
        }
        else
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            g_phb_cntx.startup_before_sort = TRUE;
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            mmi_phb_startup_finish_final_step();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_finish_after_name_sort
 * DESCRIPTION
 *  Complete phb initial after phb sorting
 * PARAMETERS
 *  info        [IN]        Finish indication
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ind_startup_finish_after_name_sort(void)
{
#ifdef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_sim_valid() && !mmi_bootup_is_sim2_valid())
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!mmi_bootup_is_sim_valid())
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        g_phb_cntx.phb_ready = TRUE;
        mmi_phb_init_build_lookup_table();
    }
    else
    {
        /*
         * Get Speed Dial Info. If FDN on, get speed dial info after FDN list retrieved.
         * Because they all use same message.
         */
        PhbGetSpeedDialInfo();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_get_data_from_nvram
 * DESCRIPTION
 *  Retrieves the phonebook data like, Caller Group details, view fields,
 *  preferred storage, etc from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init_get_data_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S16 pError;
    U16 tempStorageLocation;    /* Temp Solution For Read/Write 2 bytes NVRAM_PHB_STORAGE_LOCATION */
    U16 tempNameListFilter;
    PHB_CALLER_GROUP_STRUCT *callerGroups;
    U8 viewField[NVRAM_PHB_SETTINGS_SIZE];
#if defined(__MMI_VCARD_V30__)
    U16 tempVcardVersion;
#endif /* defined(__MMI_VCARD_V30__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;

    ReadRecord(NVRAM_EF_PHB_SETTINGS_LID, 1, viewField, NVRAM_PHB_SETTINGS_SIZE, &pError);
    memcpy(g_phb_cntx.view_field, viewField, MAX_PB_VIEW_FIELDS);

    ReadValue(NVRAM_PHB_STORAGE_LOCATION, &tempStorageLocation, DS_SHORT, &pError);     /* 2 bytes for DS_SHORT */
    g_phb_cntx.prefer_storage = (U8) tempStorageLocation;
    
    ReadValue(NVRAM_PHB_NAME_LIST_FILTER, &tempNameListFilter, DS_SHORT, &pError);     /* 2 bytes for DS_SHORT */
    g_phb_cntx.name_list_filter = (U8) tempNameListFilter;
    
#if defined(__MMI_VCARD_V30__)    
    ReadValue(NVRAM_PHB_VCARD_VERSION, &tempVcardVersion, DS_SHORT, &pError);     /* 2 bytes for DS_SHORT */
    g_phb_cntx.vcard_version = (U8) tempVcardVersion;
#endif /* defined(__MMI_VCARD_V30__) */

    ReadRecord(NVRAM_EF_PHB_CALLER_GROUPS_LID, 1, callerGroups, CALLER_GROUPS_RECORD_SIZE, &pError);

    if (g_phb_cntx.prefer_storage != MMI_SIM && g_phb_cntx.prefer_storage != MMI_NVRAM
    #ifdef __MMI_DUAL_SIM_MASTER__
        && g_phb_cntx.prefer_storage != MMI_SIM2
    #endif
        )
    {
        g_phb_cntx.prefer_storage = MMI_SIM;
        tempStorageLocation = g_phb_cntx.prefer_storage;
        WriteValue(NVRAM_PHB_STORAGE_LOCATION, &tempStorageLocation, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
    }

    if ((g_phb_cntx.name_list_filter != MMI_SIM) && (g_phb_cntx.name_list_filter != MMI_NVRAM) && (g_phb_cntx.name_list_filter != MMI_STORAGE_BOTH)
    #ifdef __MMI_DUAL_SIM_MASTER__
        && g_phb_cntx.name_list_filter != MMI_SIM2
    #endif
        )
    {
        g_phb_cntx.name_list_filter = MMI_STORAGE_BOTH;
        tempNameListFilter = g_phb_cntx.name_list_filter;
        WriteValue(NVRAM_PHB_NAME_LIST_FILTER, &tempNameListFilter, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
    }

#if defined(__MMI_VCARD_V30__)
    if ((g_phb_cntx.vcard_version != MMI_PHB_VCARD_VERSION_21) && (g_phb_cntx.vcard_version != MMI_PHB_VCARD_VERSION_30))
    {
        g_phb_cntx.vcard_version = MMI_PHB_VCARD_VERSION_21;
        tempVcardVersion = g_phb_cntx.vcard_version;
        WriteValue(NVRAM_PHB_VCARD_VERSION, &tempVcardVersion, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
    }
#endif /* defined(__MMI_VCARD_V30__) */

    /* No alert or LED seting in caller group. */
    for (i = 0; i < MAX_PB_CALLER_GROUPS; ++i)
    {
    #if defined(__MMI_CALLERGROUP_NO_ALERT__)
        callerGroups[i].alertType = MMI_ALERT_NONE;
    #endif 

    #if defined(HARDWARE_LED_NOT_SUPPORT)
        callerGroups[i].LEDPatternId = 0;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_build_lookup_table
 * DESCRIPTION
 *  This function builds the lookup table for cross-referencing during MO/MT calls.
 *  This table contains the home/mobile/fax/office number(s) of a phonebook entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init_build_lookup_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count, store_index;
    U8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    /* Read compare length from NVRAM */
    mmi_phb_util_read_compare_length();

    while (count < PhoneBookEntryCount)
    {
        store_index = g_phb_name_index[count];

        /* Populate Mobile Number Field. Either in SIM or in NVRAM */
        mmi_phb_convert_to_digit(num_ascii, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
        mmi_phb_op_increase_lookup_table(store_index, (S8*) num_ascii, NULL, NULL, NULL);
        count++;
    }
#if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    mmi_phb_lookup_table_sort();
#else /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
    /* Start a timer to avoid extensive NVRAM access which may cause MMI hang shortly */
    /* mmi_phb_init_populate_lookup_table(); */
    StartTimer(PHB_READ_OPT_FILED_TIMER, 500, mmi_phb_init_populate_lookup_table);
#endif /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
}

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_the_nearest_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_phb_get_the_nearest_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nearest_index = MAX_PB_PHONE_ENTRIES;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < PhoneBookEntryCount)
    {
        if ((g_phb_name_index[count] < nearest_index) && (g_phb_name_index[count] >= index))
        {
            nearest_index = g_phb_name_index[count];
        }
        count++;
    }
    return nearest_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_field_need_populate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static BOOL mmi_phb_field_need_populate(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U16 nearest_index = MAX_PB_PHONE_ENTRIES; */
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < PhoneBookEntryCount)
    {
        if (g_phb_name_index[count] == index)
        {
            return TRUE;
        }
        count++;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_populate_lookup_table
 * DESCRIPTION
 *  This function populates the lookup table with home/fax/mobile/office numbers after
 *  converting the last 7(or 9) characters of the phone number into digits.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init_populate_lookup_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    S16 pError;
    U16 max_rec_amount = 2000 / OPTIONAL_FIELDS_RECORD_SIZE;    /* 8 */
    void *p_data = OslMalloc((U16) (OPTIONAL_FIELDS_RECORD_SIZE * max_rec_amount));
    U16 processed_index = g_phb_cntx.populate_count;
    U16 read_rec_amount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_FUNC_PopulateLookUpTable_BEGIN, g_phb_cntx.populate_count);
    if (!p_data)
    {
        max_rec_amount = max_rec_amount / 2;
        p_data = OslMalloc((U16) (OPTIONAL_FIELDS_RECORD_SIZE * max_rec_amount));
    }
    /* Populate Optional Number Field. Only Populate record in NVRAM */
    while ((processed_index = mmi_phb_get_the_nearest_index(processed_index)) < MAX_PB_PHONE_ENTRIES)
    {
        U8 multi_record_index;

        if ((MAX_PB_PHONE_ENTRIES - processed_index) < max_rec_amount)
        {
            read_rec_amount = (MAX_PB_PHONE_ENTRIES - processed_index);
        }
        else
        {
            read_rec_amount = max_rec_amount;
        }
        ReadMultiRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (processed_index + 1),
            p_data,
            (U16) (OPTIONAL_FIELDS_RECORD_SIZE * read_rec_amount),
            read_rec_amount,
            &pError);

        count++;
        for (multi_record_index = 0; multi_record_index < read_rec_amount; multi_record_index++)
        {
            if (multi_record_index == 0 || mmi_phb_field_need_populate(processed_index))
            {
                memcpy(
                    &PhoneBookOptionalFields,
                    ((U8*) p_data) + (multi_record_index * OPTIONAL_FIELDS_RECORD_SIZE),
                    OPTIONAL_FIELDS_RECORD_SIZE);
                mmi_phb_op_increase_lookup_table(
                    processed_index,
                    NULL,
                    (S8*) PhoneBookOptionalFields.faxNumber,
                    (S8*) PhoneBookOptionalFields.homeNumber,
                    (S8*) PhoneBookOptionalFields.officeNumber);

                /* Update if phonebook column exists flag. */
                mmi_phb_op_update_field_flag(
                    processed_index,
                    NULL,
                    (S8*) PhoneBookOptionalFields.homeNumber,
                    (S8*) PhoneBookOptionalFields.officeNumber,
                    (S8*) PhoneBookOptionalFields.faxNumber,
                    (S8*) PhoneBookOptionalFields.emailAddress,
                    FALSE);
            }
            processed_index++;
        }
        if ((count % 10) == 0)  /* Populate at least 10 entries each time */
        {
            break;
        }
    }
    OslMfree(p_data);
    g_phb_cntx.populate_count = processed_index;
    MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_FUNC_PopulateLookUpTable_END, g_phb_cntx.populate_count);

    if (processed_index < MAX_PB_PHONE_ENTRIES) /* More entries to populate */
    {
        StopTimer(PHB_READ_OPT_FILED_TIMER);
        StartTimer(PHB_READ_OPT_FILED_TIMER, 250, mmi_phb_init_populate_lookup_table);
    }
    else    /* All entries populated, begin to sort it. */
    {
        mmi_phb_lookup_table_sort();
    }
}
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 


#ifdef __MMI_PHB_USIM_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_phase1_finish
 * DESCRIPTION
 *  Reads the Phonebook ready indication from PS and prepare to sort.
 * PARAMETERS
 *  info        [IN]        Finish indication
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_ind_startup_phase1_finish(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_FINISH_PHASE1_IND_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_ind_startup_phase1_finish.>\n", __FILE__,
                         __LINE__);

    localPtr = (MSG_PHB_STARTUP_FINISH_PHASE1_IND_STRUCT*) info;

    g_phb_cntx.is_usim = TRUE;   /* since only usim have this indicator */

    g_phb_cntx.sim_name_len = localPtr->phb_len;
    g_phb_cntx.fdn_name_len = localPtr->fdn_len;
    g_phb_cntx.bdn_name_len = localPtr->bdn_len;
    g_phb_cntx.owner_name_len = localPtr->owner_len;
    g_phb_cntx.sim_total = localPtr->sim_max_num;
    g_phb_cntx.phone_total = localPtr->phb_max_num;

    if (g_phb_cntx.sim_total > MAX_PB_SIM_ENTRIES)
    {
        g_phb_cntx.sim_total = MAX_PB_SIM_ENTRIES;
    }
    if (g_phb_cntx.phone_total > MAX_PB_PHONE_ENTRIES)
    {
        g_phb_cntx.phone_total = MAX_PB_PHONE_ENTRIES;  /* This two values should be the same */
    }
    if (localPtr->is_group_support)
    {
        g_phb_cntx.support_field[MMI_PHB_USIM_FIELD_GROUP] = 1;
        if (localPtr->group_max_num > MAX_PB_USIM_GROUPS)
        {
            g_phb_cntx.gas_total = MAX_PB_USIM_GROUPS;
        }
        else
        {
            g_phb_cntx.gas_total = localPtr->group_max_num;
        }
        if (localPtr->group_len > MAX_GRP_NAME_LENGTH)
        {
            g_phb_cntx.group_name_len = MAX_GRP_NAME_LENGTH;
        }
        else
        {
            g_phb_cntx.group_name_len = localPtr->group_len;
        }
    }
    if (localPtr->anra_support_type > 0)
    {
        g_phb_cntx.support_field[MMI_PHB_USIM_FIELD_ANRA] = 1;
    }
    if (localPtr->anrb_support_type > 0)
    {
    }
    if (localPtr->anrc_support_type > 0)
    {
    }
    if (localPtr->email_support_type > 0)
    {
        g_phb_cntx.support_field[MMI_PHB_USIM_FIELD_EMAIL] = 1;
        g_phb_cntx.email_total = localPtr->email_max_num;
        g_phb_cntx.email_length = localPtr->email_len;
    }

    if (!g_phb_cntx.nvram_data_init)
    {
        mmi_phb_init_get_data_from_nvram();
        g_phb_cntx.nvram_data_init = TRUE;
    }

    /* Sort name list */
    mmi_phb_sort_build_name_index();

    /*
     *   Use SIM storage buffer to store FDN list when FDN is enable.
     *   Because when FDN is enable, the ADN entry cannot be retrieved from SIM card.
     *   This list is for incoming call lookup name usage.
     *
     *   Note: Be sure to retrieve speed dial number after retrieve FDN list.
     */
    if (gSecuritySetupContext.FdlStatus)
    {
        mmi_phb_fdn_get_list_to_ram();
    }
    /*
     * Get Speed Dial Info. If FDN on, get speed dial info after FDN list retrieved.
     * Because they all use same message.
     */
    else
    {
        if (!mmi_bootup_is_sim_valid() || mmi_bootup_get_active_flight_mode() == 1)
        {
            g_phb_cntx.phb_ready = TRUE;
            mmi_phb_init_build_lookup_table();
        }
        else
        {
            PhbGetSpeedDialInfo();
        }
        /* After sorting done, init vrsi engine to add phonebook data. */
    #if defined(__MMI_VRSI__)
        mmi_vrsi_init_central_reset();
        /* mmi_vrsi_init_central_add_all(); */
    #endif /* defined(__MMI_VRSI__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_read_usim_anr_field
 * DESCRIPTION
 *  This function reads the anr field in usim card.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_read_usim_anr_field(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_phb_cntx.is_usim)
    {
        ASSERT(0);
        return;
    }
    if (g_phb_cntx.usim_ready_stage < MMI_PHB_USIM_READY_ANR)
    {
        g_phb_cntx.usim_ready_stage = MMI_PHB_USIM_READY_ANR;
    }
    SetProtocolEventHandler(mmi_phb_startup_anr_read_rsp, PRT_PHB_STARTUP_READ_ANR_IND);
    mmi_phb_startup_anr_read_rsp(info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_read_usim_email_field
 * DESCRIPTION
 *  This function reads the email field in usim card.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_read_usim_email_field(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_phb_cntx.is_usim)
    {
        ASSERT(0);
        return;
    }
    if (g_phb_cntx.usim_ready_stage < MMI_PHB_USIM_READY_EMAIL)
    {
        g_phb_cntx.usim_ready_stage = MMI_PHB_USIM_READY_EMAIL;
    }
    SetProtocolEventHandler(mmi_phb_startup_email_read_rsp, PRT_PHB_STARTUP_READ_EMAIL_IND);
    mmi_phb_startup_email_read_rsp(info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_read_usim_gas_field
 * DESCRIPTION
 *  This function reads the gas field in usim card.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_read_usim_gas_field(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_phb_cntx.is_usim)
    {
        ASSERT(0);
        return;
    }
    if (g_phb_cntx.usim_ready_stage < MMI_PHB_USIM_READY_GAS)
    {
        g_phb_cntx.usim_ready_stage = MMI_PHB_USIM_READY_GAS;
    }
    SetProtocolEventHandler(mmi_phb_startup_gas_read_rsp, PRT_PHB_STARTUP_READ_GAS_IND);
    mmi_phb_startup_gas_read_rsp(info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_read_usim_grp_field
 * DESCRIPTION
 *  This function reads the gas field in usim card.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_read_usim_grp_field(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_READ_GRP_IND_STRUCT *localPtr;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_read_usim_grp_field.>\n", __FILE__,
                         __LINE__);
    if (!g_phb_cntx.is_usim)
    {
        ASSERT(0);
        return;
    }
    if (g_phb_cntx.usim_ready_stage < MMI_PHB_USIM_READY_GRP)
    {
        g_phb_cntx.usim_ready_stage = MMI_PHB_USIM_READY_GRP;
    }

    localPtr = (MSG_PHB_STARTUP_READ_GRP_IND_STRUCT*) info;
    for (i = 0; i < g_phb_cntx.sim_total; i++)
    {
        if (localPtr->grp[i] > MAX_PB_USIM_GROUPS)
        {
            g_phb_cntx.group_type[i] = 0;
        }
        else
        {
            g_phb_cntx.group_type[i] = localPtr->grp[i];
        }
    }
    //memcpy(g_phb_cntx.group_type, (localPtr->grp), MAX_PB_SIM_ENTRIES);
    //read next usim field or finish;
    mmi_phb_read_usim_field(localPtr->access_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_read_usim_field
 * DESCRIPTION
 *  Sends the L4 request to read usim email field
 * PARAMETERS
 *  access_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_read_usim_field(U8 access_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ_STRUCT *myMsgPtr;

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_read_email_req.>\n", __FILE__, __LINE__);

    myMsgPtr = (MSG_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ_STRUCT*)
        OslConstructDataPtr(sizeof(MSG_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ_STRUCT));
    myMsgPtr->access_id = access_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_gas_read_rsp
 * DESCRIPTION
 *  Handle the L4 response for reading the usim gas field
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_gas_read_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_READ_GAS_IND_STRUCT *localPtr;
    U8 i;
    MMI_PHB_NAME_STRUCT *usim_group = (MMI_PHB_NAME_STRUCT*) g_phb_cntx.usim_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_startup_read_gas_rsp.>\n", __FILE__,
                         __LINE__);

    localPtr = (MSG_PHB_STARTUP_READ_GAS_IND_STRUCT*) info;
    for (i = 0; i < localPtr->num_of_entry; ++i)
    {
        if (g_phb_read_index <= MAX_PB_USIM_GROUPS)
        {
            g_phb_read_index = localPtr->gas_entry[i].record_index;
            usim_group[g_phb_read_index - 1].name_length = localPtr->gas_entry[i].alpha_id.name_length;
            usim_group[g_phb_read_index - 1].name_dcs = localPtr->gas_entry[i].alpha_id.name_dcs;
            InputboxConvertGSMToDeviceEncoding(
                localPtr->gas_entry[i].alpha_id.name,
                usim_group[g_phb_read_index - 1].name,
                localPtr->gas_entry[i].alpha_id.name_length,
                (MAX_GRP_NAME_LENGTH + 1) * ENCODING_LENGTH,
                localPtr->gas_entry[i].alpha_id.name_dcs,
                0,
                1);
        }
    }
    /* read next usim field or finish */
    mmi_phb_read_usim_field(localPtr->access_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_email_read_rsp
 * DESCRIPTION
 *  Handle the L4 response for reading the usim email field
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_email_read_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_READ_EMAIL_IND_STRUCT *localPtr;
    U16 i;
    U16 store_index;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_startup_email_read_rsp.>\n", __FILE__,
                         __LINE__);
    localPtr = (MSG_PHB_STARTUP_READ_EMAIL_IND_STRUCT*) info;
    for (i = 0; i < localPtr->num_of_entry; ++i)
    {
        //if (g_phb_cntx.email_used < g_phb_cntx.email_total)
        //{
        store_index = localPtr->email_entry[i].adn_record_index + MAX_PB_PHONE_ENTRIES - 1;
        index = localPtr->email_entry[i].adn_record_index - 1;
        /* PhoneBook[store_index].usim_field |= MMI_PHB_ENTRY_FIELD_EMAIL; */
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_EMAIL;
        g_phb_cntx.email_used++;
        /* Email Field */
        phb_email[index].email_length = localPtr->email_entry[i].email_length;

        if (phb_email[index].email_length == 0)
        {
            memset(phb_email[index].email_address, 0, 2);
        }
        else
        {
            ConvertGSM7BitDefaultEncodingToAscii(
                phb_email[index].email_address,
                localPtr->email_entry[i].email_address,
                localPtr->email_entry[i].email_length,
                (U16*) & (localPtr->email_entry[i].email_length));
        }
        //}       
        //else
        //{
        //        break;
        //}
    }

    /* read next usim field or finish */
    mmi_phb_read_usim_field(localPtr->access_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_anr_read_rsp
 * DESCRIPTION
 *  Handle the L4 response for reading the usim anr field
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_anr_read_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_STARTUP_READ_ANR_IND_STRUCT *local_ptr;
    U16 i = 0;
    U16 store_index;
    U8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U8 bcd_length = 0;
    U8 type_of_anr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_startup_email_read_rsp.>\n", __FILE__,
                         __LINE__);
    local_ptr = (MSG_PHB_STARTUP_READ_ANR_IND_STRUCT*) info;
    type_of_anr = local_ptr->anr_entry[i].anr_type;
    for (i = 0; i < local_ptr->num_of_entry; ++i)
    {
        /* if (g_phb_cntx.anra_used < g_phb_cntx.anra_total && type_of_anr == 0) // ANRA */
        if (type_of_anr == 0)   /* ANRA */
        {
            store_index = local_ptr->anr_entry[i].adn_record_index;
            /* PhoneBook[store_index + MAX_PB_PHONE_ENTRIES - 1].usim_field |= MMI_PHB_ENTRY_FIELD_ANRA; */
            PhoneBook[store_index + MAX_PB_PHONE_ENTRIES - 1].field |= MMI_PHB_ENTRY_FIELD_ANRA;
            g_phb_cntx.anra_used++;
            /* Number Field
               For L4 anr struct, the first byte of addr_bcd is TON, and the rest are BCD numbers.
               And the length is the total byte of TON + BCD numbers. */
            phb_anr[store_index - 1][type_of_anr].type = local_ptr->anr_entry[i].tel_number.addr_bcd[0];
            if (local_ptr->anr_entry[i].tel_number.addr_length > 0)
            {
                bcd_length = ((local_ptr->anr_entry[i].tel_number.addr_length - 1) < ((MAX_PB_NUMBER_LENGTH + 1) / 2))
                    ? (local_ptr->anr_entry[i].tel_number.addr_length - 1) : ((MAX_PB_NUMBER_LENGTH + 1) / 2);
            }

            if (bcd_length > 0)
            {
                // TODO:
                //strncpy((S8*)PhoneBook[store_index].tel.number, (S8*)(LocalPtr->phb_entry.tel.addr_bcd+1), (MAX_PB_NUMBER_LENGTH + 1) / 2);
                memset(phb_anr[store_index - 1][type_of_anr].number, 0xff, ((MAX_PB_NUMBER_LENGTH + 1) / 2));
                memcpy(
                    phb_anr[store_index - 1][type_of_anr].number,
                    (local_ptr->anr_entry[i].tel_number.addr_bcd + 1),
                    bcd_length);
            }
            else
            {
                phb_anr[store_index - 1][type_of_anr].number[0] = 0xff;
            }
            mmi_phb_convert_to_digit(num_ascii, phb_anr[store_index - 1][type_of_anr].number, MAX_PB_NUMBER_LENGTH + 1);
            phb_anr[store_index - 1][type_of_anr].length = strlen((S8*) num_ascii);
            mmi_phb_op_increase_lookup_table(
                (U16) (store_index + MAX_PB_PHONE_ENTRIES - 1),
                (S8*) num_ascii,
                NULL,
                NULL,
                NULL);

            /* Update flag for number exists entry, Clear it first. */

            // TODO: what is the field flag for anr?
            //PhoneBook[store_index].field = 0;
            if (phb_anr[store_index - 1][type_of_anr].number[0] != 0xff)
            {
                PhoneBook[store_index - 1].field |= MMI_PHB_ENTRY_FIELD_ANRA;
            }

        }
        else
        {
            break;
        }
    }
    //if ((localPtr->num_of_entry == MAX_EMAIL_ENTRIES_IN_LIST) && (g_phb_cntx.email_used < g_phb_cntx.email_total) &&
    //   g_phb_read_index < g_phb_cntx.email_total)
    {
        /* mmi_phb_email_read_req(g_phb_name_index[++g_phb_cntx.usim_field_read_count]); */
    }
    /* else */
    {
        /* read next usim field or finish; */
        mmi_phb_read_usim_field(local_ptr->access_id);
    }
}
#endif /* __MMI_PHB_USIM_FIELD__ */ 


#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_check_sim_change
 * DESCRIPTION
 *  This function checks if sim changes for phonebook.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if updated. FALSE if not.
 *****************************************************************************/
BOOL mmi_phb_init_check_sim_change(void)
{
    /* Check SIM change only on hardware */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U16 i;
    S16 pError;
    U8 optid_record, optid_index, current_record = 0;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_sim_check == 0)
    {
        g_phb_sim_check = 1;
    #ifdef __GEMINI__
        if (is_sim_replaced(0x00))
    #else /* __GEMINI__ */
        if (is_sim_replaced())
    #endif /* __GEMINI__ */
        {
            /* Count entry number first */
            for (i = MAX_PB_PHONE_ENTRIES; i < MAX_PB_ENTRIES; ++i)
            {
                /* Get optional IDs record. */
                optid_record = (i / OPTIONAL_IDS_RECORD_TOTAL) + 1;
                optid_index = i - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

                if (optid_record != current_record)
                {
                    ReadRecord(
                        NVRAM_EF_PHB_IDS_LID,
                        optid_record,
                        (void*)PhbOptIDs,
                        OPTIONAL_IDS_RECORD_SIZE,
                        &pError);
                    current_record = optid_record;
                }

                if (PhbOptIDs[optid_index].callerGroupID != 0)
                {
                    count++;
                }
            }

            /* If id exists, prompt user to delete. */
            if (count)
            {
                mmi_phb_init_entry_sim_refresh_confirm();
                return TRUE;
            }
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_entry_sim_refresh_confirm
 * DESCRIPTION
 *  This function is the confirmation screen for SIM changed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init_entry_sim_refresh_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8* guiBuffer; */

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_PHB_REFRESH_SIM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    //EntryNewScreen(SCR_ID_PHB_REFRESH_SIM_CONFIRM, NULL, mmi_phb_init_entry_sim_refresh_confirm, NULL);
    //guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_REFRESH_SIM_CONFIRM);

    //ShowCategory164Screen(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO,IMG_GLOBAL_NO,
    //   STR_ID_PHB_REFRESH_SIM, IMG_GLOBAL_QUESTION, guiBuffer);
    SetLeftSoftkeyFunction(mmi_phb_init_delete_caller_group_in_sim, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* playRequestedTone(WARNING_TONE); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_delete_caller_group_in_sim
 * DESCRIPTION
 *  This function clears all caller group associate to SIM card.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init_delete_caller_group_in_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S16 pError;
    U8 optid_record, optid_index, current_record = 0;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MAX_PB_PHONE_ENTRIES; i < MAX_PB_ENTRIES; ++i)
    {
        /* Get optional IDs record. */
        optid_record = (i / OPTIONAL_IDS_RECORD_TOTAL) + 1;
        optid_index = i - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

        if (optid_record != current_record)
        {
            if (current_record != 0)    /* Write result back for previous optional ID record. */
            {
                WriteRecord(NVRAM_EF_PHB_IDS_LID, current_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
            }

            /* Read out next record. */
            ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
            current_record = optid_record;
        }

        memset(&PhbOptIDs[optid_index], 0, sizeof(PHB_OPTIONAL_IDS_STRUCT));
    }

    /* Write back for last record. */
    WriteRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    DeleteNScrId(SCR_ID_PHB_REFRESH_SIM_CONFIRM);
}
#endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 

#define MMI_PHB_MAIN_MENU


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_main_menu
 * DESCRIPTION
 *  Shows the Phonebook main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nImgIltemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *hintList[MAX_SUB_MENUS];    /* Array for hint */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_main_menu.>\n", __FILE__, __LINE__);
    /* g_phb_cntx.selected_pic_in_view = 0; */

    /* if sync now, user cannot enter phonebook */
#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */

    g_phb_enter_from = MMI_PHB_ENTER_NONE;
    EntryNewScreen(SCR_PBOOK_MAIN_MENU, mmi_phb_exit_main_menu, mmi_phb_entry_main_menu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_PBOOK_MAIN_MENU);  /* Getting the Index from history */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim_valid() || mmi_bootup_is_sim2_valid())
    {
        nNumofItem = GetNumOfChild_Ext(MAIN_MENU_PHONEBOOK_MENUID);
        GetSequenceStringIds_Ext(MAIN_MENU_PHONEBOOK_MENUID, nStrItemList);
        GetSequenceImageIds_Ext(MAIN_MENU_PHONEBOOK_MENUID, nImgIltemList);
        SetParentHandler(MAIN_MENU_PHONEBOOK_MENUID);
        /* Construct List To Show Hint */
        ConstructHintsList(MAIN_MENU_PHONEBOOK_MENUID, hintList);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid())
    {
        nNumofItem = GetNumOfChild(MAIN_MENU_PHONEBOOK_MENUID);
        GetSequenceStringIds(MAIN_MENU_PHONEBOOK_MENUID, nStrItemList);
        GetSequenceImageIds(MAIN_MENU_PHONEBOOK_MENUID, nImgIltemList);
        SetParentHandler(MAIN_MENU_PHONEBOOK_MENUID);
        /* Construct List To Show Hint */
        ConstructHintsList(MAIN_MENU_PHONEBOOK_MENUID, hintList);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else
    {
        nNumofItem = GetNumOfChild(MAIN_MENU_PHONEBOOK_NO_SIM_MENUID);
        GetSequenceStringIds(MAIN_MENU_PHONEBOOK_NO_SIM_MENUID, nStrItemList);
        GetSequenceImageIds(MAIN_MENU_PHONEBOOK_NO_SIM_MENUID, nImgIltemList);
        SetParentHandler(MAIN_MENU_PHONEBOOK_NO_SIM_MENUID);
        /* Construct List To Show Hint */
        ConstructHintsList(MAIN_MENU_PHONEBOOK_NO_SIM_MENUID, hintList);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Call option menu may invoke before mmi_phb_init is executed */
    mmi_phb_set_main_menu_highlight_handler();

    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
#if defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_valid() || mmi_bootup_is_sim2_valid())
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid())
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        wgui_enable_mini_tab_bar(MAIN_MENU_PHONEBOOK_MENUID);
    }
    else
    {
        wgui_enable_mini_tab_bar(MAIN_MENU_PHONEBOOK_NO_SIM_MENUID);
    }
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
    /* MTK Leo end */
    /* Screen with hint, if no hint needed, can change to Screen 15 */
    ShowCategory52Screen(
        STR_SCR_PBOOK_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        nImgIltemList,
        hintList,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_main_menu
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_main_menu()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.start_scr_id = SCR_PBOOK_MAIN_MENU;
    g_phb_cntx.end_scr_id = SCR_PBOOK_MAIN_MENU;

    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_disable_mini_tab_bar();
#endif 
    /* MTK Leo end */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_not_ready
 * DESCRIPTION
 *  Displays Phobebook not ready screen
 * PARAMETERS
 *  str_id        [IN]   String id for display     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_not_ready(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_PHB_DUMMY, mmi_phb_exit_not_ready, NULL, NULL);
    StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, mmi_phb_wait_and_go_back);
    ShowCategory66Screen(
        STR_SCR_PBOOK_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) GetString(str_id),
        IMG_PROCESSING_PHONEBOOK,
        NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_not_ready
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_not_ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);
    g_idle_context.ToNameScrFromIdleApp = 0;
    g_idle_context.RskPressedFromIdleApp = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_wait_and_go_back
 * DESCRIPTION
 *  Goes back to history after timer expires
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_wait_and_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);
    GoBackHistory();
    g_idle_context.ToNameScrFromIdleApp = 0;
    g_idle_context.RskPressedFromIdleApp = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_show_in_progress
 * DESCRIPTION
 *  To display work-in-progress status
 * PARAMETERS
 *  msg         [IN]        
 *  msgIcon     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_show_in_progress(U16 msg, U16 msgIcon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_message = msg;
    g_phb_message_icon = msgIcon;
    mmi_phb_entry_in_progress();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_in_progress
 * DESCRIPTION
 *  Draws the in-progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_in_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* EntryNewScreen(SCR_IN_PROGRESS_PHB, mmi_phb_exit_in_progress, NULL,NULL); */
    EntryNewScreen(SCR_IN_PROGRESS_PHB, NULL, NULL, NULL);
    /* PMT HIMANSHU START 20050920 */
#ifdef __MMI_MAINLCD_240X320__
    /* passing 0xffff for Title string and Title icon for the disbling the status bar and title display. */
    ShowCategory8Screen(0xffff, 0xffff, 0, 0, 0, 0, g_phb_message, g_phb_message_icon, NULL);
#else /* __MMI_MAINLCD_240X320__ */ 
    ShowCategory8Screen(
        STR_SCR_PBOOK_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        0,
        0,
        0,
        0,
        g_phb_message,
        g_phb_message_icon,
        NULL);
#endif /* __MMI_MAINLCD_240X320__ */ 

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_show_mass_processing
 * DESCRIPTION
 *  To display work-in-progress status for mass operation. (Copy All, Delete All)
 * PARAMETERS
 *  msg         [IN]        
 *  msgIcon     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_show_mass_processing(U16 msg, U16 msgIcon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_message = msg;
    g_phb_message_icon = msgIcon;
    mmi_phb_entry_mass_processing();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mass_processing_scr_del_callback
 * DESCRIPTION
 *  Call back function when the screen is deleted
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_mass_processing_scr_del_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.processing & (!isInCall()))  /* if phonebook still copying or deleting, do not deleted this screen */
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mass_processing
 * DESCRIPTION
 *  Draws the in-progress screen for mass operation. (This screen has abort function.)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mass_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_COPY_ALL_PROGRESS, mmi_phb_exit_mass_processing, NULL, NULL);

    ShowCategory8Screen(
        STR_SCR_PBOOK_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_COPY_ALL_ABORT,
        g_phb_message,
        g_phb_message_icon,
        NULL);

    /* If this screen is deleted, call back function. */
    SetDelScrnIDCallbackHandler(SCR_COPY_ALL_PROGRESS, (HistoryDelCBPtr) mmi_phb_mass_processing_scr_del_callback);

    if (!isInCall())
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }

    SetRightSoftkeyFunction(mmi_phb_mass_processing_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_mass_processing
 * DESCRIPTION
 *  Exit function to mmi_phb_entry_mass_processing()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_mass_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.processing)
    {
        g_phb_cntx.end_scr_id = SCR_COPY_ALL_PROGRESS;
        h.scrnID = SCR_COPY_ALL_PROGRESS;
        h.entryFuncPtr = mmi_phb_entry_mass_processing;
        mmi_ucs2cpy((PS8) h.inputBuffer, (PS8) & nHistory);
        GetCategoryHistory(h.guiBuffer);
        AddHistory(h);
    }
}

#define MMI_PHB_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_allocate_filter
 * DESCRIPTION
 *  allocate memory phonebook list filter buffer. The filter is used for display phonebook list
 *  with certain conditions.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_allocate_filter(void)
{
#if (MAX_PB_ENTRIES >= 1000)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.list_filter = (U16*) g_phb_list_filter;
#else /* (MAX_PB_ENTRIES >= 1000) */ 
    if (g_phb_cntx.list_filter == NULL)
    {
        g_phb_cntx.list_filter = OslMalloc(MAX_PB_ENTRIES * 2);
    }
#endif /* (MAX_PB_ENTRIES >= 1000) */ /* MAX_PB_ENTRIES >= 1000 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_free_filter
 * DESCRIPTION
 *  free memory phonebook list filter buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_free_filter(void)
{
#if (MAX_PB_ENTRIES < 1000)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.list_filter)
    {
        OslMfree(g_phb_cntx.list_filter);
        g_phb_cntx.list_filter = NULL;
    }
#endif /* (MAX_PB_ENTRIES < 1000) */ /* MAX_PB_ENTRIES < 1000 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_pre_entry
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_list_pre_entry.>\n", __FILE__, __LINE__);

#if defined(__MMI_FILE_MANAGER__) && (!defined __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__)
    if (UI_device_height == 220 && UI_device_width == 176)
    {
        mmi_phb_entry_image_list1();
    }
    else
#endif /* defined(__MMI_FILE_MANAGER__) && (!defined __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__) */ 
    {
        FunctionPtr send_key_ptr;
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
        if (phbListView == MMI_PHB_LIST_FOR_PHB)
        {
            send_key_ptr = mmi_phb_two_line_send_key_handler;
        }
        else 
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */
        {
            send_key_ptr = mmi_phb_choose_number_normal;
        }

        mmi_phb_entry_list(PhoneBookEntryCount,             /* Total Entry */
                           STR_SCR_PBOOK_VIEW_CAPTION,      /* Title String */
                           IMG_SCR_PBOOK_CAPTION,           /* Title Image */
                           STR_GLOBAL_OPTIONS,              /* LSK */
                           IMG_GLOBAL_OPTIONS,              /* LSK */
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
                           mmi_phb_get_index_speak_name,
#else 
                           mmi_phb_get_index,               /* Highlight Callback */
#endif 
                           mmi_phb_entry_op_option,         /* LSK Callback */
                           send_key_ptr,                    /* SEND Key Callback */
                           mmi_phb_list_get_item,           /* List Callback */
                           mmi_phb_list_get_hint,           /* Hint Callback */
                           mmi_phb_list_pre_entry,          /* Re-Entry Callback */
                           TRUE,                            /* Alpha Index */
                           TRUE);                           /* Right Arrow Key */
    }
}

#if defined(__MMI_PHB_NAME_LIST_FILTER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_nlf_list_pre_entry
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list with 
 *  name list filter feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_nlf_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_nlf_list_pre_entry.>\n", __FILE__, __LINE__);

#if defined(__MMI_FILE_MANAGER__) && (!defined __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__)
    if (UI_device_height == 220 && UI_device_width == 176)
    {
        mmi_phb_nlf_entry_image_list1();
    }
    else
#endif /* defined(__MMI_FILE_MANAGER__) && (!defined __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__) */ 
    {
        FunctionPtr send_key_ptr;
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
        if (phbListView == MMI_PHB_LIST_FOR_PHB)
        {
            send_key_ptr = mmi_phb_two_line_send_key_handler;
        }
        else 
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */
        {
            send_key_ptr = mmi_phb_choose_number_normal;
        }

        if(g_phb_cntx.name_list_filter == MMI_SIM)
        {
            g_phb_list_index_total = g_phb_cntx.sim_used;
        }
        else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
        {
            g_phb_list_index_total = g_phb_cntx.phone_used;
        }
#ifdef __MMI_DUAL_SIM_MASTER__
        else if(g_phb_cntx.name_list_filter == MMI_SIM2)
        {
             g_phb_list_index_total = MTPNP_AD_ADN_SIM2GetUsedNumber();
        }
#endif /* __MMI_DUAL_SIM_MASTER__ */
        else
        {
            g_phb_list_index_total = PhoneBookEntryCount;
        }

        mmi_phb_nlf_entry_list(g_phb_list_index_total,          /* Total Entry */
                           STR_SCR_PBOOK_VIEW_CAPTION,      /* Title String */
                           IMG_SCR_PBOOK_CAPTION,           /* Title Image */
                           STR_GLOBAL_OPTIONS,              /* LSK */
                           IMG_GLOBAL_OPTIONS,              /* LSK */
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
                           mmi_phb_get_index_speak_name_nlf,
#else 
                           mmi_phb_get_index_nlf,               /* Highlight Callback */
#endif 
                           mmi_phb_entry_op_option,     /* LSK Callback */
                           send_key_ptr,                    /* SEND Key Callback */
                           mmi_phb_nlf_list_get_item,       /* List Callback */
                           mmi_phb_nlf_list_get_hint,       /* Hint Callback */
                           mmi_phb_nlf_list_pre_entry,      /* Re-Entry Callback */
                           TRUE,                            /* Alpha Index */
                           TRUE);                           /* Right Arrow Key */
    }
}
#endif /* defined(__MMI_PHB_NAME_LIST_FILTER__) */


#if defined(__MMI_EMAIL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_second_level_list_for_email
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_second_level_list_for_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 EntryCount = 0;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if it can be list first */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
        return;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */

    /* Allocate buffer for phonebook memeber list filter */
    mmi_phb_list_allocate_filter();
    /* Build list according to filter */
    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        store_index = g_phb_name_index[i];
        if (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_EMAIL)
        {
            g_phb_cntx.list_filter[EntryCount] = store_index;
            EntryCount++;
        }
    }

    if (EntryCount)
    {
        mmi_phb_entry_list(
            EntryCount,                                 /* Total Entry */
            STR_SCR_PBOOK_VIEW_CAPTION,                 /* Title String */
            IMG_SCR_PBOOK_CAPTION,                      /* Title Image */
            STR_GLOBAL_OK,                              /* LSK */
            IMG_GLOBAL_OK,                              /* LSK */
            mmi_phb_get_index_by_store_location_second, /* Highlight Callback */
            mmi_phb_email_choose_entry,                 /* LSK Callback */
            mmi_phb_email_choose_entry,                 /* SEND Key Callback */
            mmi_phb_filter_list_get_item,               /* List Callback */
            mmi_phb_filter_list_get_hint,               /* Hint Callback */
            mmi_phb_list_pre_entry_second_level,        /* Re-Entry Callback */
            TRUE,                                       /* Alpha Index */
            TRUE);                                      /* Right Arrow Key */
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NO_ENTRY_TO_SELECT),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
        mmi_phb_list_free_filter();
    }
}
#endif /* defined(__MMI_EMAIL__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_pre_entry_second_level
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_pre_entry_second_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*LSKEntryPtr) (void) = NULL;
    void (*SendKeyPtr) (void) = NULL;

    if ((phbListView == MMI_PHB_LIST_FOR_SMS) || (phbListView == MMI_PHB_LIST_FOR_CHAT) ||
        (phbListView == MMI_PHB_LIST_FOR_SMS_SEARCH_NAME))
    {
        LSKEntryPtr = mmi_phb_sms_send_data_choose_entry;
        SendKeyPtr = mmi_phb_sms_send_data_choose_entry;
    }
    else if (phbListView == MMI_PHB_LIST_FOR_CHAT_NO_CHECK)
    {
        LSKEntryPtr = mmi_phb_sms_send_data_for_entry_name_only;
        SendKeyPtr = mmi_phb_sms_send_data_for_entry_name_only;
    }

    else if (phbListView == MMI_PHB_LIST_FOR_SPEED_DIAL)
    {
        LSKEntryPtr = PhbSetSpeedDialFormList;
    }
#if defined(MMS_SUPPORT)
    else if (phbListView == MMI_PHB_LIST_FOR_MMS_ALL)
    {
        LSKEntryPtr = mmi_phb_entry_mms_choose_number;
    }
#endif /* defined(MMS_SUPPORT) */ 
    else if (phbListView == MMI_PHB_LIST_FOR_ALL_SHARED)
    {
        LSKEntryPtr = mmi_phb_generic_enter_list_result;
    }
    if (phbListView != MMI_PHB_LIST_FOR_SMS_SEARCH_NAME)
    {
        g_phb_cntx.highlight_entry = 0;
    }

#if defined(__MMI_EMAIL__)
    if (phbListView == MMI_PHB_LIST_FOR_EMAIL_APP)
    {
        mmi_phb_entry_second_level_list_for_email();
    }
    else
#endif /* defined(__MMI_EMAIL__) */ 
        mmi_phb_entry_list(
            PhoneBookEntryCount,                    /* Total Entry */
            STR_SCR_PBOOK_VIEW_CAPTION,             /* Title String */
            IMG_SCR_PBOOK_CAPTION,                  /* Title Image */
            STR_GLOBAL_OK,                          /* LSK */
            IMG_GLOBAL_OK,                          /* LSK */
            mmi_phb_get_index_second_level,         /* Highlight Callback */
            LSKEntryPtr,                            /* LSK Callback */
            SendKeyPtr,                             /* SEND Key Callback */
            mmi_phb_list_get_item,                  /* List Callback */
            mmi_phb_list_get_hint,                  /* Hint Callback */
            mmi_phb_list_pre_entry_second_level,    /* Re-Entry Callback */
            TRUE,                                   /* Alpha Index */
            TRUE);                                  /* Right Arrow Key */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_pre_entry_for_fmgr_in_nvram
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_FILE_MANAGER__)
void mmi_phb_list_pre_entry_for_fmgr_in_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 EntryCount = 0;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_list_pre_entry_for_fmgr_in_nvram.>\n",
                         __FILE__, __LINE__);
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif /* __SYNCML_SUPPORT__ */
    else
    {
        /* Allocate buffer for phonebook memeber list filter */
        mmi_phb_list_allocate_filter();

        /* Find out entry in NVRAM and put it into filter list */
        for (i = 0; i < PhoneBookEntryCount; i++)
        {
            store_index = g_phb_name_index[i];
            if (store_index < MAX_PB_PHONE_ENTRIES)
            {
                g_phb_cntx.list_filter[EntryCount] = store_index;
                EntryCount++;
            }
        }

        if (EntryCount)
        {
            g_phb_cntx.highlight_entry = 0;
            mmi_phb_entry_list(
                EntryCount,                                 /* Total Entry */
                STR_SCR_PBOOK_VIEW_CAPTION,                 /* Title String */
                IMG_SCR_PBOOK_CAPTION,                      /* Title Image */
                STR_GLOBAL_OK,                              /* LSK */
                IMG_GLOBAL_OK,                              /* LSK */
                mmi_phb_get_index_by_store_location,        /* Highlight Callback */
                mmi_phb_fmgr_pre_edit_entry,                /* LSK Callback */
                NULL,                                       /* SEND Key Callback */
                mmi_phb_filter_list_get_item,               /* List Callback */
                mmi_phb_filter_list_get_hint,               /* Hint Callback */
                mmi_phb_list_pre_entry_for_fmgr_in_nvram,   /* Re-Entry Callback */
                FALSE,                                      /* Alpha Index */
                TRUE);                                      /* Right Arrow Key */

        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PHB_NO_ENTRY_TO_SELECT),
                IMG_GLOBAL_EMPTY,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                EMPTY_LIST_TONE);
            mmi_phb_list_free_filter();
        }
    }
}
#endif /* defined(__MMI_FILE_MANAGER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_pre_delete_one_by_one
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_pre_delete_one_by_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phbListView = MMI_PHB_LIST_FOR_DELETE_ONE_BY_ONE;
    g_phb_cntx.highlight_entry = 0;
    g_phb_highlight_alpha = 0;
    mmi_phb_entry_list(
        PhoneBookEntryCount,                /* Total Entry */
        STR_SCR_PBOOK_VIEW_CAPTION,         /* Title String */
        IMG_SCR_PBOOK_CAPTION,              /* Title Image */
        STR_GLOBAL_DELETE,                  /* LSK */
        0,                                  /* IMAGE LSK */
        mmi_phb_get_index,                  /* Highlight Callback */
        mmi_phb_entry_op_delete_confirm,    /* LSK Callback */
        NULL,                               /* SEND Key Callback */
        mmi_phb_list_get_item,              /* List Callback */
        mmi_phb_list_get_hint,              /* Hint Callback */
        mmi_phb_list_pre_delete_one_by_one, /* Re-Entry Callback */
        TRUE,                               /* Alpha Index */
        FALSE);                             /* Right Arrow Key */
}


#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
static S32 phb_numbers[MMI_PHB_MAX_NUMBER_COUNT];
static S32 phb_total_number_present;
static U8 current_highligted_item = 0;
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_display_style
 * DESCRIPTION
 *  Returns the display style for the phonebook list(will return INLINE SELECT style always)
 * PARAMETERS
 *  item_index      [IN]        Actual index of the menuitem in the list
 * RETURNS
 *  U8 display style     TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT
 *****************************************************************************/
U8 mmi_phb_inline_display_style(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 store_index;
    U8 entries_present = 0;
    U8 pic_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_name_index[item_index];
    mmi_phb_convert_get_ucs2_number(pbNumber, store_index);
    if (store_index < MAX_PB_PHONE_ENTRIES) /* in NVRAM */
    {
        /*
         * The view field array doesn't have two mandatory fields 
         * * #define MAX_PB_MANDATORY_FIELDS   2
         * * #define MAX_PB_VIEW_FIELDS        (MMI_PHB_FIELD_TOTAL - MAX_PB_MANDATORY_FIELDS) 
         * * View Fields Array [MAX_PB_VIEW_FIELDS] 
         * * MMI_PHB_FIELD_ORDER_ENUM has those 2 mandatory fields
         * * so have to deduct MAX_PB_MANDATORY_FIELDS to arrive at the right index.
         */
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
        mmi_phb_read_optional_ids(store_index);
        if (*pbNumber)
        {
            ++entries_present;
        }
        if (g_phb_cntx.view_field[MMI_PHB_FIELD_HOME - MAX_PB_MANDATORY_FIELDS] && *PhoneBookOptionalFields.homeNumber)
        {
            ++entries_present;
        }
        if (g_phb_cntx.view_field[MMI_PHB_FIELD_OFFICE - MAX_PB_MANDATORY_FIELDS] &&
            *PhoneBookOptionalFields.officeNumber)
        {
            ++entries_present;
        }
        if (g_phb_cntx.view_field[MMI_PHB_FIELD_FAX - MAX_PB_MANDATORY_FIELDS] && *PhoneBookOptionalFields.faxNumber)
        {
            ++entries_present;
        }
        pic_index = mmi_phb_get_image_index(((PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids)->pictureTagID);
        if (g_phb_cntx.view_field[MMI_PHB_FIELD_PIC - MAX_PB_MANDATORY_FIELDS] &&    pic_index != 0)
        {
            if ((entries_present >= 1) || (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name)))
            {
                return TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT;
            }
        }
        else
        {
            if ((entries_present > 1) ||
                (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name) && (entries_present >= 1)))
            {
                return TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT;
            }
        }
    }
    else
    {
        if (*pbNumber && (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name)))
        {
            return TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_default_value
 * DESCRIPTION
 *  Returns the default inline item to be shown with the entry(Only phone
 *  numbers to be considered)
 * PARAMETERS
 *  item_index      [IN]        Actual index of the menuitem in the list
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_phb_inline_default_value(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return current_highligted_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_two_line_send_key_handler
 * DESCRIPTION
 *  This is the send key handler in case of two line menu item in phone book
 * PARAMETERS
 *  void
 *  Input: NONE(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_two_line_send_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U8 number_to_dial = 0;
    UI_string_type dialing_number[MAX_PB_NUMBER_LENGTH + 1 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_name_index[g_phb_cntx.active_index];
    while (phb_numbers[number_to_dial] != current_highligted_item + 1 && number_to_dial <= MMI_PHB_MAX_NUMBER_COUNT)
    {
        ++number_to_dial;
    }
#if defined(__IP_NUMBER__)
    SetTempUseIPNumber(FALSE);
#endif 

    switch (number_to_dial)
    {
        case MMI_PHB_MOBILE_NUMBER:
            mmi_phb_convert_get_ucs2_number(pbNumber, store_index);
            g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
            MakeCall((PS8) pbNumber);
            break;
        case MMI_PHB_HOME_NUMBER:
            mmi_asc_to_ucs2((S8*) dialing_number, (S8*) PhoneBookOptionalFields.homeNumber);
            g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
            MakeCall((PS8) dialing_number);
            break;
        case MMI_PHB_OFFICE_NUMBER:
            mmi_asc_to_ucs2((S8*) dialing_number, (PS8) PhoneBookOptionalFields.officeNumber);
            g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
            MakeCall((PS8) dialing_number);
            break;
        case MMI_PHB_FAX_NUMBER:
            mmi_asc_to_ucs2((S8*) dialing_number, (PS8) PhoneBookOptionalFields.faxNumber);
            g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
            MakeCall((PS8) dialing_number);
            break;
        default:
            if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Entry in SIM */
            {
                mmi_phb_convert_get_ucs2_number(pbNumber, store_index); /* BCD number format. */
                if (mmi_ucs2strlen(pbNumber))
                {
                    g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
                    MakeCall((PS8) pbNumber);
                    break;
                }
            }
            DisplayPopup(
                (PU8) GetString(STR_NO_NUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_select_data
 * DESCRIPTION
 *  This function sets the relevant data for the phonebook entry
 * PARAMETERS
 *  item_index              [IN]        Menuitem index
 *  inline_item_index       [IN]        Inline item index
 *  str_buff                [IN]        Inline Item String to be shown
 *  img_buff_p              [?]         Image to be shown with the inline item
 *  thumbnail               [?]         Thumbnail picture to be shown with the inline item
 * RETURNS
 *  S32
 *****************************************************************************/
pBOOL mmi_phb_inline_select_data(
        S32 item_index,
        S32 inline_item_index,
        UI_string_type str_buff,
        PU8 *img_buff_p,
        wgui_thumbnail_image_union *thumbnail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S16 next_phb_number_index = 0;
    pBOOL val = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_name_index[item_index];
    current_highligted_item = inline_item_index;
    while (phb_numbers[next_phb_number_index] != (inline_item_index + 1) &&
           next_phb_number_index <= MMI_PHB_MAX_NUMBER_COUNT)
    {
        next_phb_number_index++;
    }
    if (!phb_total_number_present)
    {
        next_phb_number_index = -1;
    }

    switch (next_phb_number_index)
    {
        case MMI_PHB_MOBILE_NUMBER:
            mmi_phb_convert_get_ucs2_number(pbNumber, store_index);
            mmi_ucs2cpy((S8*) str_buff, (S8*) & pbNumber);
            *img_buff_p = get_image((U16) (IMG_MOBILE_NUMBER));
            val = TRUE;
            break;
        case MMI_PHB_HOME_NUMBER:
            mmi_asc_to_ucs2((S8*) str_buff, (S8*) PhoneBookOptionalFields.homeNumber);
            *img_buff_p = get_image((U16) (IMG_HOME_NUMBER));
            val = TRUE;
            break;
        case MMI_PHB_OFFICE_NUMBER:
            mmi_asc_to_ucs2((S8*) str_buff, (PS8) PhoneBookOptionalFields.officeNumber);
            *img_buff_p = get_image((U16) (IMG_OFFICE_NUMBER));
            val = TRUE;
            break;
        case MMI_PHB_FAX_NUMBER:
            mmi_asc_to_ucs2((S8*) str_buff, (PS8) PhoneBookOptionalFields.faxNumber);
            *img_buff_p = get_image((U16) (IMG_FAX_NUMBER));
            val = TRUE;
            break;
        default:
            *img_buff_p = get_image((U16) UI_NULL_IMAGE);
            mmi_asc_to_ucs2((S8*) str_buff, (PS8) "");
            val = TRUE;
            break;
    }

    if (((PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids)->pictureTagID == 1)
    {
        thumbnail->path = mmi_phb_image_get_path_from_id((U16) (store_index + 1));
    }
    else
    {
        thumbnail->id = ((PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids)->pictureTagID;
    }
    return val;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_select_done
 * DESCRIPTION
 *  Sets highlighted item to zero always
 * PARAMETERS
 *  menuitem_index      [IN]        Actual index of the menuitem in the list
 *  selected_index      [IN]        Inline item currently selected
 *****************************************************************************/
void mmi_phb_inline_select_done(S32 menuitem_index, S32 selected_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_highligted_item = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_menuitem_properties
 * DESCRIPTION
 *  This function is used to get the properties of the selected menu item
 * PARAMETERS
 *  index                           [IN]        Menu item index
 *  current_menuitem_properties     [?]         Structure to be filled for menuitem properties
 * RETURNS
 *  U8(?)
 *****************************************************************************/
void mmi_phb_inline_menuitem_properties(int index, wgui_two_line_menuitem_struct *current_menuitem_properties)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S16 number_count = 0;
    S16 entry_count = 0;
    U8 pic_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_name_index[index];

    current_menuitem_properties->image_flags = UI_TWO_LINE_MENUITEM_NO_THUMBNAIL;

    if (store_index < MAX_PB_PHONE_ENTRIES) /* in NVRAM */
    {
        pic_index = mmi_phb_get_image_index(((PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids)->pictureTagID);
        if (g_phb_cntx.view_field[MMI_PHB_FIELD_PIC - MAX_PB_MANDATORY_FIELDS])
        {
            current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_LEFT_ALIGN_THUMBNAIL;

            if (((PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids)->pictureTagID == 1)
            {
                current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_FILE;
            }
            else if (pic_index)
            {
                current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_ID;
            }
            else
            {
                current_menuitem_properties->image_flags = UI_TWO_LINE_MENUITEM_NO_THUMBNAIL;
            }

        }
        else
        {
            current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_NO_THUMBNAIL;
        }

    }
    memset(phb_numbers, 0, sizeof(phb_numbers));

    mmi_phb_convert_get_ucs2_number(pbNumber, store_index);

    /* entry_count signifies the array entry,number_count corresponds to the index of the phone number */
    if (*pbNumber)
    {
        number_count++;
        phb_numbers[entry_count] = number_count;

    }
    /*
     * The view field array doesn't have two mandatory fields 
     * * #define MAX_PB_MANDATORY_FIELDS   2
     * * #define MAX_PB_VIEW_FIELDS        (MMI_PHB_FIELD_TOTAL - MAX_PB_MANDATORY_FIELDS) 
     * * View Fields Array [MAX_PB_VIEW_FIELDS] 
     * * MMI_PHB_FIELD_ORDER_ENUM has those 2 mandatory fields
     * * so have to deduct MAX_PB_MANDATORY_FIELDS to arrive at the right index.
     */
    if (store_index < MAX_PB_PHONE_ENTRIES)
    {
        entry_count++;
        if (g_phb_cntx.view_field[MMI_PHB_FIELD_HOME - MAX_PB_MANDATORY_FIELDS] && *PhoneBookOptionalFields.homeNumber)
        {
            number_count++;
            phb_numbers[entry_count] = number_count;
        }
        entry_count++;
        if (g_phb_cntx.view_field[MMI_PHB_FIELD_OFFICE - MAX_PB_MANDATORY_FIELDS] &&
            *PhoneBookOptionalFields.officeNumber)
        {
            number_count++;
            phb_numbers[entry_count] = number_count;
        }
        entry_count++;
        if (g_phb_cntx.view_field[MMI_PHB_FIELD_FAX - MAX_PB_MANDATORY_FIELDS] && *PhoneBookOptionalFields.faxNumber)
        {
            number_count++;
            phb_numbers[entry_count] = number_count;
        }
    }

    phb_total_number_present = number_count;
    current_menuitem_properties->num_of_items = phb_total_number_present;
    current_menuitem_properties->defualt_value_callback = mmi_phb_inline_default_value;
    current_menuitem_properties->complete_callback = mmi_phb_inline_select_done;
    current_menuitem_properties->two_line_data_callback.get_data_for_horizontal_select = mmi_phb_inline_select_data;
}
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_list
 * DESCRIPTION
 *  This function is for entering phonebook entry List
 * PARAMETERS
 *  EntryCount          [IN]        
 *  STR_TITLE           [IN]        
 *  IMG_TITLE           [IN]        
 *  STR_LSK             [IN]        
 *  IMG_LSK             [IN]        
 *  HighlightPtr        [IN]        
 *  LSKPtr              [IN]        
 *  SendKeyPtr          [IN]        
 *  ItemPtr             [IN]        
 *  HintPtr             [IN]        
 *  EntryPtr            [IN]        
 *  alpha_index         [IN]        
 *  right_arrow         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_list(
        U16 EntryCount,
        U16 STR_TITLE,
        U16 IMG_TITLE,
        U16 STR_LSK,
        U16 IMG_LSK,
        void (*HighlightPtr) (S32),
        FunctionPtr LSKPtr,
        FunctionPtr SendKeyPtr,
        GetItemPtr ItemPtr,
        GetHintPtr HintPtr,
        FunctionPtr EntryPtr,
        BOOL alpha_index,
        BOOL right_arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if it can be list first */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_list_free_filter();
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
        return;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_list_free_filter();
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (PhoneBookEntryCount == 0)
    {
        mmi_phb_list_free_filter();
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
        return;
    }

    /* Check if phonebook entry has been updated, and if need to use alpha_index function. */
    if (g_phb_cntx.refresh_list && alpha_index)
    {
        mmi_phb_list_build_alpha_index(NULL, 0, TRUE, MMI_STORAGE_NONE);
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_NO_CHANGE;
    }

    EntryNewScreen(SCR_PBOOK_LIST, mmi_phb_exit_list, EntryPtr, MMI_FULL_SCREEN);
    guiBuffer = GetCurrGuiBuffer(SCR_PBOOK_LIST);
    if (guiBuffer == NULL)
    {
        g_phb_highlight_alpha = 0;
    }
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
    if (!guiBuffer)
    {
        current_highligted_item = 0;
    }
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 
    if (g_phb_cntx.new_highlight_entry < 0xffff)
    {
        change_list_menu_category_history(guiBuffer, g_phb_cntx.new_highlight_entry, EntryCount, 0);
        g_phb_cntx.new_highlight_entry = 0xffff;
    }

#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    if (phbListView == MMI_PHB_LIST_FOR_PHB)
    {
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    }
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 

    RegisterHighlightHandler(HighlightPtr);

#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
    if (phbListView == MMI_PHB_LIST_FOR_PHB)
    {
        ShowCategory273Screen(
            STR_TITLE,
            IMG_TITLE,
            STR_LSK,
            IMG_LSK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            EntryCount,
            ItemPtr,
            mmi_phb_inline_display_style,
            mmi_phb_inline_menuitem_properties,
            g_phb_cntx.highlight_entry,
            guiBuffer);
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    }
    else
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 
    {
        ShowCategory184Screen(
            STR_TITLE,
            IMG_TITLE,
            STR_LSK,
            IMG_LSK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            EntryCount,
            ItemPtr,
            HintPtr,
            g_phb_cntx.highlight_entry,
            guiBuffer);
    }

    /* register multi-tap function for fast jump, for full list only */
    if (alpha_index)
    {
        register_multitap_no_draw_key_handlers();
        set_multitap_functions(mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback);
        change_multitap_mode(0);
    }

    SetLeftSoftkeyFunction(LSKPtr, KEY_EVENT_UP);
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
    if (phbListView != MMI_PHB_LIST_FOR_PHB)
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 
    {
        if (right_arrow)
        {
            SetKeyHandler(LSKPtr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
        else
        {
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(SendKeyPtr,KEY_EVENT_UP);
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(SendKeyPtr, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    if (phbListView == MMI_PHB_LIST_FOR_PHB)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if(SendKeyPtr != MTPNP_NULL)
	 {
            MTPNP_PFAL_CC_SetCenterFunc(SendKeyPtr);
            SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
	 }
	 else
	 {
            SetCenterSoftkeyFunction(SendKeyPtr, KEY_EVENT_UP);
	 }
    #else  /* __MMI_DUAL_SIM_MASTER__ */
        SetCenterSoftkeyFunction(SendKeyPtr, KEY_EVENT_UP);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
    if (phbListView != MMI_PHB_LIST_FOR_PHB)
#endif 
    {
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
#if defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__)   /* For IP Dial Key */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_list
 * DESCRIPTION
 *  This function is for existing entering phonebook entry List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.ToNameScrFromIdleApp)
    {
        g_phb_cntx.start_scr_id = SCR_PBOOK_LIST;
    }
    /* Avoid: Entry from Name List and re-entry from MT-> Deflect */
    if (!(phbListView == MMI_PHB_LIST_FOR_CM && 
        g_phb_cntx.start_scr_id == SCR_PBOOK_LIST))
    {
        g_phb_cntx.end_scr_id = SCR_PBOOK_LIST;
    }
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    StopTimer(PHB_LIST_SPEAK_NAME_TIMER);
    if (g_phb_is_speaking_name)
    {
        mdi_audio_stop_string();
    }
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

    reset_multitaps();

    StopTimer(KEYPAD_LOCK_TIMER);
#if defined(__MMI_VRSD_DIAL__)
    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);
#endif
#if defined(__MMI_VRSI__) && defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_phb_vrsi_exit_entry_list();
#endif

    g_idle_context.ToNameScrFromIdleApp = 0;
    g_idle_context.RskPressedFromIdleApp = 0;

    /* Free Member List Filter if exists */
    mmi_phb_list_free_filter();
#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    ResetCenterSoftkey();
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_phb_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index >= PhoneBookEntryCount))
    {
        return FALSE;
    }

    store_index = g_phb_name_index[item_index];

    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name))
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) PhoneBook[store_index].alpha_id.name);
    }
    else
    {
        mmi_phb_convert_get_ucs2_number((S8*) str_buff, store_index);
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
    {
        *img_buff_p = get_image(IMG_ID_CARD2_PHB_STORAGE_SIM);
    }
    else if (store_index >= MAX_PB_PHONE_ENTRIES && store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
    {
        *img_buff_p = get_image(IMG_ID_CARD1_PHB_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_phb_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S8 temp_number[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_name_index[item_index];

    mmi_phb_convert_get_ucs2_number((S8*) temp_number, store_index);

    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name) && mmi_ucs2strlen((S8*) temp_number))
    {
        mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_number);
    }
    else
    {
        return 0;   /* No Hint Data */
    }

    return 1;   /* One hint data only, can be more hints. */
}

#if defined(__MMI_PHB_NAME_LIST_FILTER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_nlf_entry_list
 * DESCRIPTION
 *  This function is for entering phonebook entry list with name list filter 
 * PARAMETERS
 *  EntryCount          [IN]        
 *  STR_TITLE           [IN]        
 *  IMG_TITLE           [IN]        
 *  STR_LSK             [IN]        
 *  IMG_LSK             [IN]        
 *  HighlightPtr        [IN]        
 *  LSKPtr              [IN]        
 *  SendKeyPtr          [IN]        
 *  ItemPtr             [IN]        
 *  HintPtr             [IN]        
 *  EntryPtr            [IN]        
 *  alpha_index         [IN]        
 *  right_arrow         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_nlf_entry_list(
        U16 EntryCount,
        U16 STR_TITLE,
        U16 IMG_TITLE,
        U16 STR_LSK,
        U16 IMG_LSK,
        void (*HighlightPtr) (S32),
        FunctionPtr LSKPtr,
        FunctionPtr SendKeyPtr,
        GetItemPtr ItemPtr,
        GetHintPtr HintPtr,
        FunctionPtr EntryPtr,
        BOOL alpha_index,
        BOOL right_arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if it can be list first */
    if(g_phb_cntx.name_list_filter == MMI_SIM)
    {
        g_phb_list_index_total = g_phb_cntx.sim_used;
    }
    else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
    {
        g_phb_list_index_total = g_phb_cntx.phone_used;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if(g_phb_cntx.name_list_filter == MMI_SIM2)
    {
         g_phb_list_index_total = MTPNP_AD_ADN_SIM2GetUsedNumber();
    }
#endif/* __MMI_DUAL_SIM_MASTER__ */

    else
    {
        g_phb_list_index_total = PhoneBookEntryCount;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif/* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_list_free_filter();
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
        return;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_list_free_filter();
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (g_phb_list_index_total == 0)
    {
        mmi_phb_list_free_filter();
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
        return;
    }

    /* Check if phonebook entry has been updated, and if need to use alpha_index function. */
    if (g_phb_cntx.refresh_list && alpha_index)
    {
        if (g_phb_cntx.name_list_filter == MMI_SIM || g_phb_cntx.name_list_filter == MMI_NVRAM
        #ifdef __MMI_DUAL_SIM_MASTER__
            || g_phb_cntx.name_list_filter == MMI_SIM2
        #endif
            )
        {
            mmi_phb_list_build_alpha_index(NULL, 0, TRUE, g_phb_cntx.name_list_filter);
        }
        else
        {
            mmi_phb_list_build_alpha_index(NULL, 0, TRUE, MMI_STORAGE_NONE);
        }
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_NO_CHANGE;
    }

    EntryNewScreen(SCR_PBOOK_LIST, mmi_phb_exit_list, EntryPtr, MMI_FULL_SCREEN);
    guiBuffer = GetCurrGuiBuffer(SCR_PBOOK_LIST);
    if (guiBuffer == NULL)
    {
        g_phb_highlight_alpha = 0;
    }
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
    if (!guiBuffer)
    {
        current_highligted_item = 0;
    }
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 
    if (g_phb_cntx.new_highlight_entry < 0xffff)
    {
        change_list_menu_category_history(guiBuffer, g_phb_cntx.new_highlight_entry, EntryCount, 0);
        g_phb_cntx.new_highlight_entry = 0xffff;
    }

#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    if (phbListView == MMI_PHB_LIST_FOR_PHB)
    {
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    }
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 

    RegisterHighlightHandler(HighlightPtr);

#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
    if (phbListView == MMI_PHB_LIST_FOR_PHB)
    {
        ShowCategory273Screen(
            STR_TITLE,
            IMG_TITLE,
            STR_LSK,
            IMG_LSK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            EntryCount,
            ItemPtr,
            mmi_phb_inline_display_style,
            mmi_phb_inline_menuitem_properties,
            g_phb_cntx.highlight_entry,
            guiBuffer);
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    }
    else
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 
    {
        ShowCategory184Screen(
            STR_TITLE,
            IMG_TITLE,
            STR_LSK,
            IMG_LSK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            EntryCount,
            ItemPtr,
            HintPtr,
            g_phb_cntx.highlight_entry,
            guiBuffer);
    }

    /* register multi-tap function for fast jump, for full list only */
    if (alpha_index)
    {
        register_multitap_no_draw_key_handlers();
        set_multitap_functions(mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback);
        change_multitap_mode(0);
    }

    SetLeftSoftkeyFunction(LSKPtr, KEY_EVENT_UP);
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
    if (phbListView != MMI_PHB_LIST_FOR_PHB)
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 
    {
        if (right_arrow)
        {
            SetKeyHandler(LSKPtr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
        else
        {
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(SendKeyPtr,KEY_EVENT_UP);
#else   /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(SendKeyPtr, KEY_SEND, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    if (phbListView == MMI_PHB_LIST_FOR_PHB)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if(SendKeyPtr != MTPNP_NULL)
        {
            MTPNP_PFAL_CC_SetCenterFunc(SendKeyPtr);
            SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
        }
        else
        {
        SetCenterSoftkeyFunction(SendKeyPtr, KEY_EVENT_UP);
    }
    #else  /* __MMI_DUAL_SIM_MASTER__ */
        SetCenterSoftkeyFunction(SendKeyPtr, KEY_EVENT_UP);
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        }
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
    if (phbListView != MMI_PHB_LIST_FOR_PHB)
#endif 
    {
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
#if defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__)   /* For IP Dial Key */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__) */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_nlf_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_phb_nlf_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S32 i=-1;
    S32 inner_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index >= PhoneBookEntryCount))
    {
        return FALSE;
    }
    while (i < item_index)
    {
        store_index = g_phb_name_index[inner_index];
#ifdef __MMI_DUAL_SIM_MASTER__
        if (g_phb_cntx.name_list_filter == MMI_SIM)
        {
             if ((store_index >= MAX_PB_PHONE_ENTRIES)&&(store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
             {
                    i++;
             }
        }
        else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
        {
             if(store_index < MAX_PB_PHONE_ENTRIES)
             {
                    i++;
             }
        }
        else if (g_phb_cntx.name_list_filter == MMI_SIM2)
        {
            if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
            {
                  i++;
            }
        }
#else /* __MMI_DUAL_SIM_MASTER__ */
        if (g_phb_cntx.name_list_filter == MMI_SIM)
        {
            if (store_index >= MAX_PB_PHONE_ENTRIES)
            {
                i++;
            }
        }
        else if (g_phb_cntx.name_list_filter == MMI_NVRAM)
        {
            if(store_index < MAX_PB_PHONE_ENTRIES)
            {
                i++;
            }
        }
#endif /* __MMI_DUAL_SIM_MASTER__ */
        else
        {
            i++;
        }
        inner_index ++;
    }
    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name))
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) PhoneBook[store_index].alpha_id.name);
    }
    else	
    {
        mmi_phb_convert_get_ucs2_number((S8*) str_buff, store_index);
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if(store_index >= (MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES))
    {
        *img_buff_p = get_image(IMG_ID_CARD2_PHB_STORAGE_SIM);
    }
    else if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_ID_CARD1_PHB_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */	
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_nlf_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_phb_nlf_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S8 temp_number[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    S32 i=-1;
    S32 inner_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < item_index)
    {
        store_index = g_phb_name_index[inner_index];
#ifdef __MMI_DUAL_SIM_MASTER__
        if (g_phb_cntx.name_list_filter == MMI_SIM)
        {
             if ((store_index >= MAX_PB_PHONE_ENTRIES)&&(store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
             {
                    i++;
             }
        }
        else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
        {
             if(store_index < MAX_PB_PHONE_ENTRIES)
             {
                    i++;
             }
        }
        else if (g_phb_cntx.name_list_filter == MMI_SIM2)
        {
            if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
            {
                  i++;
            }
        }
#else/* __MMI_DUAL_SIM_MASTER__ */
        if (g_phb_cntx.name_list_filter == MMI_SIM)
        {
            if (store_index >= MAX_PB_PHONE_ENTRIES)
            {
                i++;
            }
        }
        else if (g_phb_cntx.name_list_filter == MMI_NVRAM)
        {
            if(store_index < MAX_PB_PHONE_ENTRIES)
            {
                i++;
            }
        }
#endif	/* __MMI_DUAL_SIM_MASTER__ */	
        else
        {
            i++;
        }
        inner_index ++;
    }

    mmi_phb_convert_get_ucs2_number((S8*) temp_number, store_index);

    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name) && mmi_ucs2strlen((S8*) temp_number))
    {
        mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_number);
    }
    else
    {
        return 0;   /* No Hint Data */
    }

    return 1;   /* One hint data only, can be more hints. */
}
#endif /* defined(__MMI_PHB_NAME_LIST_FILTER__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_filter_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_phb_filter_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_cntx.list_filter[item_index];

    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name))
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) PhoneBook[store_index].alpha_id.name);
    }
    else
    {
        mmi_phb_convert_get_ucs2_number((S8*) str_buff, store_index);
    }

#ifndef __MMI_DUAL_SIM_MASTER__
    if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#else	/* __MMI_DUAL_SIM_MASTER__*/
    if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
    {
        *img_buff_p = get_image(IMG_ID_CARD2_PHB_STORAGE_SIM);
    }
    else if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_ID_CARD1_PHB_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_filter_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_phb_filter_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S8 temp_number[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_cntx.list_filter[item_index];

    mmi_phb_convert_get_ucs2_number((S8*) temp_number, store_index);

    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name) && mmi_ucs2strlen((S8*) temp_number))
    {
        mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_number);
    }
    else
    {
        return 0;
    }

    return 1;   /* One hint data only, can be more hints. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_get_null_hint
 * DESCRIPTION
 *  No hint needed in the dynamic list.
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_phb_list_get_null_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_choose_number_normal
 * DESCRIPTION
 *  choose normal phonebook entry number if has many(Only when IP number on)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_choose_number_normal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__IP_NUMBER__)
    SetTempUseIPNumber(FALSE);
#endif 
    mmi_phb_list_pre_choose_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_choose_number_ip_number
 * DESCRIPTION
 *  choose IP Dial phonebook entry number if has many(Only when IP number on)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_choose_number_ip_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__IP_NUMBER__)
    SetTempUseIPNumber(TRUE);
#endif 
    mmi_phb_list_pre_choose_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_index
 * DESCRIPTION
 *  This function calculates the index of the entry to be highlighted, if the user jumps to some
 *  entry using multi-tap on PHB list screen.
 * PARAMETERS
 *  input       [IN]        Input character
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_alpha_index(U16 input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input >= 'A' && input <= 'Z')
    {
        g_phb_highlight_alpha = g_phb_alpha_index_list[input - 'A'];
        g_phb_highlight_alpha--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_index_input_callback
 * DESCRIPTION
 *  Jumps to the hilited entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_alpha_index_input_callback(void)
{
#if defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_device_height == 220 && UI_device_width == 176)
    {
        Cat212ShortCutHdlr(g_phb_highlight_alpha);  /* For image list fast jump */
    }
    else
#endif /* defined(__MMI_FILE_MANAGER__) */ 
        dynamic_list_goto_item(g_phb_highlight_alpha);  /* Use Dynamic List */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_build_alpha_index
 * DESCRIPTION
 *  Build up alpha index for each characters
 * PARAMETERS
 *  filter_list         [?]         
 *  filter_value        [IN]        
 *  is_equal            [IN]        
 *  storage             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_build_alpha_index(U16 *filter_list, U16 filter_value, BOOL is_equal, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j, count = 0;
    BOOL valid_ch;
    U8 index = 0xff;
    U16 store_index;
    MMI_PHB_NAME_STRUCT *name_ptr;

#if defined(__MMI_PHB_PINYIN_SORT__)
    U8 *pinyin_ptr;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clear First */
    for (i = 0; i < ALPHA_LIST_LENGTH; i++)
    {
        g_phb_alpha_index_list[i] = 0;
    }

    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        U16 filter_index;

        store_index = g_phb_name_index[i];

        /* exclude storage location */
        if (storage == MMI_SIM && (store_index < MAX_PB_PHONE_ENTRIES
        #ifdef __MMI_DUAL_SIM_MASTER__
            || store_index >= (MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES)
        #endif
            ))
        {
            continue;
        }
        else if (storage == MMI_NVRAM && store_index >= MAX_PB_PHONE_ENTRIES)
        {
            continue;
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (storage == MMI_SIM2 && store_index < (MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES))
        {
            continue;
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */


        if (storage == MMI_SIM)
        {
            filter_index = store_index - MAX_PB_PHONE_ENTRIES;
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (storage == MMI_SIM)
        {
            filter_index = store_index - MAX_PB_PHONE_ENTRIES - MAX_PB_SIM_ENTRIES;
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        else
        {
            filter_index = store_index;
        }

        /* Filter List */
        if (filter_list != NULL && is_equal)    /* Exclude item not in the filter list. */
        {
            if (filter_list[filter_index] != filter_value)
            {
                continue;
            }
        }
        else if (filter_list != NULL && !is_equal)  /* Exclude item in the filter list. */
        {
            if (filter_list[filter_index] == filter_value)
            {
                continue;
            }
        }

        /* All character store in MMI by using UCS2(two-bytes) format */
        name_ptr = &PhoneBook[store_index].alpha_id;

        if ((name_ptr->name[1] == 0x00) && (name_ptr->name[0] >= 'a') && (name_ptr->name[0] <= 'z'))    /* lower case */
        {
            index = name_ptr->name[0] - 'a';
            valid_ch = TRUE;
        }
        else if ((name_ptr->name[1] == 0x00) && (name_ptr->name[0] >= 'A') && (name_ptr->name[0] <= 'Z'))       /* upper case */
        {
            index = name_ptr->name[0] - 'A';
            valid_ch = TRUE;
        }
    #if defined(__MMI_PHB_PINYIN_SORT__)
        else if ((name_ptr->name[0] != 0x00) && (name_ptr->name[1] != 0x00))    /* A 2-bytes character */
        {
            mmi_phb_util_get_pinyin_cache(store_index, &pinyin_ptr);
            if (pinyin_ptr[0] >= 'a' && pinyin_ptr[0] <= 'z')
            {
                index = pinyin_ptr[0] - 'a';
                valid_ch = TRUE;
            }
            else
            {
                valid_ch = FALSE;
            }
        }
    #endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 
        else
        {
            valid_ch = FALSE;
        }

        /* Assign alpha index */
        if (index < ALPHA_LIST_LENGTH && g_phb_alpha_index_list[index] == 0 && valid_ch)
        {
            for (j = 0; j < index; j++)
                if (g_phb_alpha_index_list[j] == 0)
                {
                    g_phb_alpha_index_list[j] = count + 1;
                }
            g_phb_alpha_index_list[index] = count + 1;
        }

        count++;
    }

    /* Handle unassigned index */
    count = 1;
    for (j = 0; j < ALPHA_LIST_LENGTH; j++)
    {
        if (g_phb_alpha_index_list[j] == 0)
        {
            g_phb_alpha_index_list[j] = count;
        }
        else
        {
            count = g_phb_alpha_index_list[j];
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_pre_choose_number
 * DESCRIPTION
 *  Allows the user to choose one number to dial  if the entry has more than one number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_pre_choose_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_list_choose_number(
        g_phb_name_index[g_phb_cntx.active_index],
        mmi_phb_list_pre_choose_number,
        mmi_phb_list_make_call,
        MakeCall,
    #ifdef __MMI_VOIP__
        mmi_voip_app_make_call,
    #else
        NULL,
    #endif
        STR_NO_NUMBER_TO_DIAL,
        TRUE);
}


#if defined(__MMI_PHB_DIAL_FROM_PHB__)
#if defined(__MMI_UCM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_ucm_make_call
 * DESCRIPTION
 *  Makes call to a number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ucm_make_call(PS8 strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_list_ucm_make_call.>\n", __FILE__, __LINE__);
    g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
    mmi_ucm_app_entry_dial_option((U8*) strNumber, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_ucm_make_call
 * DESCRIPTION
 *  Makes call to a number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_ucm_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_list_ucm_make_call.>\n", __FILE__, __LINE__);
    g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
    mmi_ucm_app_entry_dial_option((U8*) g_phb_cntx.number_to_dial[g_phb_cntx.active_index_third], NULL, NULL);
}


#endif /* defined(__MMI_UCM__) */
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_pre_choose_number_from_option_dial
 * DESCRIPTION
 *  Allows the user to choose one number to dial  if the entry has more than one number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_pre_choose_number_from_option_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    mmi_phb_entry_list_choose_number(
        g_phb_name_index[g_phb_cntx.active_index],
        mmi_phb_list_pre_choose_number_from_option_dial,
        mmi_phb_list_ucm_make_call,
        mmi_phb_ucm_make_call,
    #ifdef __MMI_VOIP__
        mmi_phb_ucm_make_call,
    #else
        NULL,
    #endif
        STR_NO_NUMBER_TO_DIAL,
        TRUE);
#else /* __MMI_UCM__ */
    mmi_phb_entry_list_choose_number(
        g_phb_name_index[g_phb_cntx.active_index],
        mmi_phb_list_pre_choose_number,
        mmi_phb_list_make_call,
        MakeCall,
    #ifdef __MMI_VOIP__
        mmi_voip_app_make_call,
    #else
        NULL,
    #endif
        STR_NO_NUMBER_TO_DIAL,
        TRUE);
#endif /* __MMI_UCM__ */
}
#endif /* defined(__MMI_PHB_DIAL_FROM_PHB__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_list_choose_number
 * DESCRIPTION
 *  Allows the user to choose one number to some action  if the entry has more than one number
 * PARAMETERS
 *  store_index         [IN]        
 *  EntryFunc           [IN]        
 *  RSKFunc             [IN]        
 *  ActionFunc          [IN]        
 *  empty_str_id        [IN]        
 *  dial_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_list_choose_number(
        U16 store_index,
        void (*EntryFunc) (void),
        void (*RSKFunc) (void),
        void (*ActionFunc) (S8*),
        void (*VoIPActionFunc) (U8*),
        U16 empty_str_id,
        BOOL dial_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 *guiBuffer;
    U16 numberTypeImageList[4];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) || defined(__MMI_VOIP__)
    S16 pError;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VOIP__
    phb_voip_number_index= 0xff;
#endif
    mmi_phb_convert_get_ucs2_number(pbNumber, store_index); /* BCD number format. */

    if (mmi_ucs2strlen(pbNumber))
    {
        g_phb_cntx.number_to_dial[i] = (U8*) pbNumber;
        numberTypeImageList[i++] = IMG_MOBILE_NUMBER;
    }
    if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Entry in SIM */
    {
    #ifdef __MMI_PHB_USIM_FIELD__
        if (g_phb_cntx.is_usim)
        {
            mmi_phb_convert_get_ucs2_anr(pbHomeNumber, pbOfficeNumber, pbFaxNumber, store_index);
            if (mmi_ucs2strlen(pbHomeNumber))
            {
                g_phb_cntx.number_to_dial[i] = (PU8) pbHomeNumber;
                numberTypeImageList[i++] = IMG_ID_PHB_ANR;
            }
            mmi_asc_to_ucs2(pbOfficeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
            if (mmi_ucs2strlen(pbOfficeNumber))
            {
                g_phb_cntx.number_to_dial[i] = (PU8) pbOfficeNumber;
                numberTypeImageList[i++] = IMG_ID_PHB_ANR;
            }
            mmi_asc_to_ucs2(pbFaxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
            if (mmi_ucs2strlen(pbFaxNumber))
            {
                g_phb_cntx.number_to_dial[i] = (PU8) pbFaxNumber;
                numberTypeImageList[i++] = IMG_ID_PHB_ANR;
            }
        }
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
    }
    else
    {
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        /* Read Optional Number Fields */
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);

        mmi_asc_to_ucs2(pbHomeNumber, (PS8) PhoneBookOptionalFields.homeNumber);
        if (mmi_ucs2strlen(pbHomeNumber))
        {
            g_phb_cntx.number_to_dial[i] = (PU8) pbHomeNumber;
            numberTypeImageList[i++] = IMG_HOME_NUMBER;
        }
        mmi_asc_to_ucs2(pbOfficeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
        if (mmi_ucs2strlen(pbOfficeNumber))
        {
            g_phb_cntx.number_to_dial[i] = (PU8) pbOfficeNumber;
            numberTypeImageList[i++] = IMG_OFFICE_NUMBER;
        }
        mmi_asc_to_ucs2(pbFaxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
        if (mmi_ucs2strlen(pbFaxNumber))
        {
            g_phb_cntx.number_to_dial[i] = (PU8) pbFaxNumber;
            numberTypeImageList[i++] = IMG_FAX_NUMBER;
        }
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
    }

#ifdef __MMI_VOIP__
    if (dial_list && store_index < MAX_PB_PHONE_ENTRIES)  /* make call */
    {
        ReadRecord(
            NVRAM_EF_PHB_VOIP_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookVoipField,
            VOIP_URI_LEN,
            &pError);
        mmi_asc_to_ucs2(pbVoip, (PS8) PhoneBookVoipField);
        if (mmi_ucs2strlen(pbVoip))
        {
            phb_voip_number_index = i;
            g_phb_cntx.number_to_dial[i] = (PU8) pbVoip;
            numberTypeImageList[i++] = IMG_ID_PHB_VOIP;
        }
    }
#endif /* __MMI_VOIP__ */
    if (!i)
    {
    #if defined(__IP_NUMBER__)
        SetTempUseIPNumber(FALSE);
    #endif 
        DisplayPopup((PU8) GetString(empty_str_id), IMG_GLOBAL_UNFINISHED, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else if (i == 1)
    {
        if (dial_list)  /* Will dial from list after select entry */
        {
            g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
#ifdef __MMI_VOIP__
            if (phb_voip_number_index != 0xff)
            {
                VoIPActionFunc((PU8)pbVoip);
                return;
            }
#endif /* __MMI_VOIP__ */
        }
        ActionFunc((PS8) g_phb_cntx.number_to_dial[0]);
    }
    else
    {
    #if defined(__IP_NUMBER__)      /* Do not keep choose number screen in history when IP dial enable */
        EntryNewScreen(SCR_CHOOSE_NUMBER, mmi_phb_exit_list_choose_number, NULL, NULL);
    #else 
        EntryNewScreen(SCR_CHOOSE_NUMBER, mmi_phb_exit_list_choose_number, EntryFunc, NULL);
    #endif 
        guiBuffer = GetCurrGuiBuffer(SCR_CHOOSE_NUMBER);
        RegisterHighlightHandler(mmi_phb_get_index_third_level);

        ShowCategory53Screen(
            STR_CHOOSE_NUMBER_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            i,
            g_phb_cntx.number_to_dial,
            numberTypeImageList,
            NULL,
            0,
            0,
            guiBuffer);

        SetLeftSoftkeyFunction(RSKFunc, KEY_EVENT_UP);
#ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_PFAL_CC_HandleSendKeys(RSKFunc,KEY_EVENT_UP);
#else	/* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(RSKFunc, KEY_SEND, KEY_EVENT_UP);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_list_choose_number
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_list_choose_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_CHOOSE_NUMBER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_make_call
 * DESCRIPTION
 *  Makes call to a number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_list_make_call.>\n", __FILE__, __LINE__);
    g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
#ifdef __MMI_VOIP__
    if (phb_voip_number_index == g_phb_cntx.active_index_third)
    {
        mmi_voip_app_make_call(g_phb_cntx.number_to_dial[g_phb_cntx.active_index_third]);
    }
    else
#endif
    {
        MakeCall((PS8) g_phb_cntx.number_to_dial[g_phb_cntx.active_index_third]);
    }
}


#define MMI_PHB_UTIL_FUNC
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_speak_name
 * DESCRIPTION
 *  Gets the index of the currently highlighted item in Phonebook menu list.
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index_speak_name(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index = (U16) nIndex;

    StopTimer(PHB_LIST_SPEAK_NAME_TIMER);
    if (g_phb_is_speaking_name)
    {
        mdi_audio_stop_string();
    }

    if (g_phb_cntx.speak_name)
    {
        StartTimer(PHB_LIST_SPEAK_NAME_TIMER, UI_POPUP_NOTIFYDURATION_TIME, mmi_phb_list_speak_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_speak_name_nlf
 * DESCRIPTION
 *  Gets the index of the currently highlighted item in Phonebook menu list 
 *  when name_list_filter opening.
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index_speak_name_nlf(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S32 i = -1;
	S32 inner_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (i < nIndex)
	{
		store_index = g_phb_name_index[inner_index];
#ifdef __MMI_DUAL_SIM_MASTER__
               if (g_phb_cntx.name_list_filter == MMI_SIM)
               {
                     if ((store_index >= MAX_PB_PHONE_ENTRIES)&&(store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
                     {
                            i++;
                     }
               }
               else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
               {
			if(store_index < MAX_PB_PHONE_ENTRIES)
			{
				i++;
			}
               }
               else if (g_phb_cntx.name_list_filter == MMI_SIM2)
               {
                    if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
                    {
                          i++;
                    }
               }
#else/* __MMI_DUAL_SIM_MASTER__ */
		if (g_phb_cntx.name_list_filter == MMI_SIM)
		{
			if (store_index >= MAX_PB_PHONE_ENTRIES)
			{
				i++;
			}
		}
		else if (g_phb_cntx.name_list_filter == MMI_NVRAM)
		{
			if(store_index < MAX_PB_PHONE_ENTRIES)
			{
				i++;
			}
		}
#endif/* __MMI_DUAL_SIM_MASTER__ */
		else
		{
			i++;
		}
		inner_index++;
	}

    g_phb_cntx.active_index = (U16) (inner_index - 1);

    StopTimer(PHB_LIST_SPEAK_NAME_TIMER);
    if (g_phb_is_speaking_name)
    {
        mdi_audio_stop_string();
    }

    if (g_phb_cntx.speak_name)
    {
        StartTimer(PHB_LIST_SPEAK_NAME_TIMER, UI_POPUP_NOTIFYDURATION_TIME, mmi_phb_list_speak_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_speak_name
 * DESCRIPTION
 *  Speak name or number for a phonebook entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_speak_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U8 text[(MAX_PB_NAME_LENGTH + MAX_PB_NUMBER_LENGTH + 10) * ENCODING_LENGTH];
    U16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_phb_cntx.active_index = (U16)nIndex; */

#ifdef __MMI_SILENT_MEETING_PROFILE__
    if (IsMeetingModeActivated())
    {
        /* not to play sound */
    }
    else
#endif /* __MMI_SILENT_MEETING_PROFILE__ */ 
        /* Flag is on and not in call */
    if (g_phb_cntx.speak_name && !isInCall() && !IsSilentModeActivated())
    {
        store_index = g_phb_name_index[g_phb_cntx.active_index];

    #if defined(SIMPLE_TTS) || defined(DIGIT_TONE_SUPPORT)
        /* Name */
        mmi_ucs2cpy((S8*) text, (S8*) PhoneBook[store_index].alpha_id.name);
        length = mmi_ucs2strlen((S8*) text);
    #endif /* defined(SIMPLE_TTS) || defined(DIGIT_TONE_SUPPORT) */ 

        /* Append Number */
    #ifdef DIGIT_TONE_SUPPORT
        mmi_phb_convert_get_ucs2_number((S8*) (text + length * ENCODING_LENGTH), store_index);
        length += mmi_ucs2strlen((S8*) (text + length * ENCODING_LENGTH));
    #endif /* DIGIT_TONE_SUPPORT */ 
        if (length > 0)
        {
            mdi_result result = mdi_audio_play_text_with_vol_path(
                                    (U8*) text,
                                    length,
                                    100,
                                    NULL,
                                    mmi_phb_speak_name_handler,
                                    GetRingVolumeLevel(),
                                    MDI_DEVICE_SPEAKER2);

            if (result == MDI_AUDIO_SUCCESS)
            {
                g_phb_is_speaking_name = 1;
            }
            else
            {
                g_phb_is_speaking_name = 0;
            }
        }
    }
}
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index
 * DESCRIPTION
 *  Gets the index of the currently highlighted item in Phonebook menu list.
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index = (U16) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_nlf
 * DESCRIPTION
 *  Gets the index of the currently highlighted item in Phonebook menu list
 *  when name_list_filter opening
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index_nlf(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S32 i = -1;
	S32 inner_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (i < nIndex)
	{
		store_index = g_phb_name_index[inner_index];
#ifdef __MMI_DUAL_SIM_MASTER__
               if (g_phb_cntx.name_list_filter == MMI_SIM)
               {
                     if ((store_index >= MAX_PB_PHONE_ENTRIES)&&(store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
                     {
                            i++;
                     }
               }
               else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
               {
			if(store_index < MAX_PB_PHONE_ENTRIES)
			{
				i++;
			}
               }
               else if (g_phb_cntx.name_list_filter == MMI_SIM2)
               {
                    if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
                    {
                          i++;
                    }
               }
#else/* __MMI_DUAL_SIM_MASTER__ */
		if (g_phb_cntx.name_list_filter == MMI_SIM)
		{
			if (store_index >= MAX_PB_PHONE_ENTRIES)
			{
				i++;
			}
		}
		else if (g_phb_cntx.name_list_filter == MMI_NVRAM)
		{
			if(store_index < MAX_PB_PHONE_ENTRIES)
			{
				i++;
			}
		}
#endif/* __MMI_DUAL_SIM_MASTER__ */
		else
		{
			i++;
		}
		inner_index++;
	}

    g_phb_cntx.active_index = (U16) (inner_index - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_second_level
 * DESCRIPTION
 *  Gets the index of the currently highlighted item in Phonebook menu list.
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index_second_level(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index_second = (U16) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_third_level
 * DESCRIPTION
 *  Gets the index of the currently highlighted item in Phonebook menu list.
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index_third_level(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index_third = (U16) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_by_store_location
 * DESCRIPTION
 *  call back function for dynamic list to get index according to the fileter list.
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index_by_store_location(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index = g_phb_cntx.list_filter[nIndex];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_by_store_location_second
 * DESCRIPTION
 *  call back function for dynamic list to get index according to the fileter list.
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index_by_store_location_second(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index_second = g_phb_cntx.list_filter[nIndex];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_clear_buffer
 * DESCRIPTION
 *  Clears buffers used for adding/editing entry
 * PARAMETERS
 *  clear_number        [IN]        
 *  flag_number(?)      [IN]        TRUE: clear number buffer. FALSE: Keep number buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_util_clear_buffer(BOOL clear_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pbName, 0, ENCODING_LENGTH);
    if (clear_number)
    {
        memset(pbNumber, 0, ENCODING_LENGTH);
    }
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)    
    memset(pbHomeNumber, 0, ENCODING_LENGTH);
    memset(pbCompanyName, 0, ENCODING_LENGTH);
    memset(pbEmailAddress, 0, ENCODING_LENGTH);
    memset(pbOfficeNumber, 0, ENCODING_LENGTH);
    memset(pbFaxNumber, 0, ENCODING_LENGTH);
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */    

    g_phb_cntx.selected_pic_index = 0;
    g_phb_cntx.selected_ring_index = 0;
    g_phb_cntx.selected_grp_index = 0;
    g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;

#if defined(__MMI_INCOMING_CALL_VIDEO__)
    g_phb_cntx.selected_video_index = 0;
    g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
#endif 

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    mmi_phb_util_clear_bday_buffer();
#endif 

#if defined(__MMI_PHB_INFO_FIELD__)
    mmi_phb_util_clear_info_buffer();
#endif

#if defined(__MMI_PHB_IMPS_FIELD__)
    memset(pbImps, 0, ENCODING_LENGTH);
#endif 
#if defined(__MMI_VOIP__)
    memset(pbVoip, 0, ENCODING_LENGTH);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_go_back_2_history
 * DESCRIPTION
 *  Goes back two screens in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_go_back_2_history(void)
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
 *  mmi_phb_go_back_3_history_and_clear
 * DESCRIPTION
 *  Goes back three screens in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_go_back_3_history_and_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_util_clear_buffer(TRUE);
    GoBacknHistory(2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_full_scr_lsk
 * DESCRIPTION
 *  Sets the LSK for Full-Screen editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_full_scr_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(IMG_SCR_PBOOK_CAPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_clear_old_history
 * DESCRIPTION
 *  Deletes old PHB screens from history if Phonebook is re-entered thru some other application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_clear_old_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 end_scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.start_scr_id && g_phb_cntx.end_scr_id && 
        IsScreenPresent(g_phb_cntx.start_scr_id))
    {
        if (g_phb_cntx.start_scr_id == g_phb_cntx.end_scr_id)
        {
            DeleteScreenIfPresent(g_phb_cntx.start_scr_id);
        }
        else
        {
            GetPreviousScrnIdOf(GetCmMarkerScrnID(), &end_scr_id);
            if (end_scr_id) /* since editor common screen won't be save to g_phb_cntx.end_scr_id */
            {
                g_phb_cntx.end_scr_id = end_scr_id;
            }
            DeleteBetweenScreen(g_phb_cntx.start_scr_id, g_phb_cntx.end_scr_id);
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_free_buf();
        #endif 
        }
    }
    else if (g_phb_cntx.end_scr_id && IsScreenPresent(g_phb_cntx.end_scr_id))
    {
        g_phb_cntx.start_scr_id = g_phb_cntx.end_scr_id;
        GetPreviousScrnIdOf(GetCmMarkerScrnID(), &end_scr_id);
        if (end_scr_id) /* since editor common screen won't be save to g_phb_cntx.end_scr_id */
        {
            g_phb_cntx.end_scr_id = end_scr_id;
        }
        DeleteBetweenScreen(g_phb_cntx.start_scr_id, g_phb_cntx.end_scr_id);
        //DeleteScreenIfPresent(g_phb_cntx.end_scr_id);
    }
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    DeleteScreenIfPresent(SCR_ID_PHB_VIDEO_PREVIEW);
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    DeleteScreenIfPresent(SCR_ID_PHB_IMAGE_VIEW_IMAGE);
#endif
    g_phb_cntx.start_scr_id = g_phb_cntx.end_scr_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_reset_scr_id
 * DESCRIPTION
 *  Resets the start and end screen ids on main-menu and idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_reset_scr_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.start_scr_id = g_phb_cntx.end_scr_id = 0;
}

#define MMI_PHB_IMAGE_LIST
#if defined(__MMI_FILE_MANAGER__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_list1_draw_title_info
 * DESCRIPTION
 *  Draw image list 1 title info. It will draw image, name and number here.
 * PARAMETERS
 *  item_idx        [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_list1_draw_title_info(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 char_height;
    S32 box_width, box_height;
    S32 img_box_width = 40, img_box_height = 40;
    S32 img_width, img_height;
    S32 img_draw_width, img_draw_height;
    S32 img_draw_offset_x, img_draw_offset_y;
    S32 spacing;
    S32 offset_x;   /* For name and image offset x */
    S32 offset_y;   /* For name and image offset y */
    S32 num_offset_y;
    S32 name_width;
    U16 store_index;
    S8 *image_path = NULL;
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
    S8 buffer_UCS2[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     *lock and push clip
     */
    gui_lock_double_buffer();
    gui_push_text_clip();
    gui_push_clip();

    gui_reset_clip();
    gui_reset_text_clip();

    /*
     * Get hint text info
     */
    store_index = g_phb_name_index[item_idx];
    mmi_phb_convert_get_ucs2_number((S8*) buffer_UCS2, store_index);

    /*
     * Calcuate text position
     */
    box_height = y2 - y1 + 1;
    box_width = x2 - x1 + 1;

    gui_set_font(&MMI_medium_font);
    char_height = gui_get_string_height((UI_string_type) GetString(STR_ID_PHB_MOBILE_NUMBER));
    spacing = (box_height - char_height * 2) / 3;

    offset_y = spacing + MMI_title_height + MMI_title_y;
    num_offset_y = spacing * 2 + char_height + MMI_title_height + MMI_title_y;

    if (r2lMMIFlag) /* For right to left language */
    {
        offset_x = x2 - img_box_width - 6;
    }
    else
    {
        offset_x = x1 + img_box_width + 6;
    }

    name_width = box_width - img_box_width - 12;

    /*
     * Draw Hint Text
     */
    gui_set_font(&MMI_medium_font);

    gui_reset_text_clip();
    gui_set_text_color(gui_color(0, 0, 0));

    /*
     * Draw name/number if not empty
     */
    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name))
    {
        gui_print_truncated_text(offset_x, offset_y, name_width, (UI_string_type) PhoneBook[store_index].alpha_id.name);

        if (mmi_ucs2strlen((S8*) buffer_UCS2))
        {
            gui_print_truncated_text(offset_x, num_offset_y, name_width, (UI_string_type) buffer_UCS2);
        }
    }
    else
    {
        gui_print_truncated_text(offset_x, offset_y, name_width, (UI_string_type) buffer_UCS2);
    }

    /*
     * Get Associate Picture path from file
     */
    if (store_index < MAX_PB_PHONE_ENTRIES)
    {
        mmi_phb_read_optional_ids(store_index); /* i is store index */
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;
        if (opt_ids->pictureTagID == 1
        #ifdef __MMI_AVATAR__
            || opt_ids->pictureTagID == 2
        #endif
            )
        {
            image_path = mmi_phb_image_get_path_from_id((U16) (store_index + 1));
        }
    }

    /*
     * Draw Associate Picture thumb image
     */
    gui_push_clip();

    if (r2lMMIFlag) /* For right to left language */
    {
        offset_x = x2 - img_box_width - 2;
    }
    else
    {
        offset_x = x1 + 2;
    }

    offset_y = y1 + 2;

    gui_set_clip(offset_x, offset_y, offset_x + img_box_width, offset_y + img_box_height);

    /* Get image from file */
#ifdef __USB_IN_NORMAL_MODE__ 
    if (mmi_usb_is_in_mass_storage_mode())
    {
        gdi_image_draw_resized_id(offset_x, offset_y, img_box_width, img_box_height, IMG_ID_PHB_LIST_ICON1);
    }
    else
#endif /* __USB_IN_NORMAL_MODE */
    {    	
        if ((image_path != NULL) && (gdi_image_get_dimension_file(image_path, &img_width, &img_height) >= 0))
        {
            gdi_util_fit_box(
                GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                img_box_width,
                img_box_height,
                img_width,
                img_height,
                &img_draw_offset_x,
                &img_draw_offset_y,
                &img_draw_width,
                &img_draw_height);

            gdi_image_draw_resized_file(
                offset_x + img_draw_offset_x,
                offset_y + img_draw_offset_y,
                img_draw_width,
                img_draw_height,
                image_path);
        }
        else    /* Use default image */
        {
            gdi_image_draw_resized_id(offset_x, offset_y, img_box_width, img_box_height, IMG_ID_PHB_LIST_ICON1);
        }
    }

    gui_pop_clip();

    /*
     * pop clip , unlock and blt
     */
    gui_pop_clip();
    gui_pop_text_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_image_list1
 * DESCRIPTION
 *  This function list all phonebook entry with picture info on the top.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_image_list1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check if it can be list in advance
     */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif/* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
        return;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (PhoneBookEntryCount == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
        return;
    }

    /*
     *Check if phonebook entry has been updated, and if need to use alpha_index function.
     */
    if (g_phb_cntx.refresh_list)
    {
        mmi_phb_list_build_alpha_index(NULL, 0, TRUE, MMI_STORAGE_NONE);
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_NO_CHANGE;
    }

    EntryNewScreen(SCR_PBOOK_LIST, mmi_phb_exit_list, mmi_phb_entry_image_list1, MMI_FULL_SCREEN);
    guiBuffer = GetCurrGuiBuffer(SCR_PBOOK_LIST);

    if (guiBuffer == NULL)
    {
        g_phb_highlight_alpha = 0;
    }
    /* for highlight after edit */
    if (g_phb_cntx.new_highlight_entry < 0xffff)
    {
        change_list_menu_category_history(guiBuffer, g_phb_cntx.new_highlight_entry, PhoneBookEntryCount, 0);
        g_phb_cntx.new_highlight_entry = 0xffff;
    }
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__)
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__) */ 

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    RegisterHighlightHandler(mmi_phb_get_index_speak_name);
#else 
    RegisterHighlightHandler(mmi_phb_get_index);
#endif 

    ShowCategory212Screen(
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,      /* Title */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,         /* LSK */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,            /* RSK */
        PhoneBookEntryCount,
        mmi_phb_list_get_item,
        mmi_phb_list_get_null_hint,
        mmi_phb_image_list1_draw_title_info,
        NULL,                       /* No call back needed when change highlight */
        2,                          /* Info box row count */
        0,                          /* info bg image id */
        g_phb_cntx.highlight_entry, /* Highlight item index */
        (U8*) guiBuffer);

    register_multitap_no_draw_key_handlers();
    set_multitap_functions(mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback);
    change_multitap_mode(0);

    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_op_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_phb_choose_number_normal,KEY_EVENT_UP);
#else   /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_phb_choose_number_normal, KEY_SEND, KEY_EVENT_UP);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__)
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_SetCenterFunc(mmi_phb_choose_number_normal);
    SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetCenterSoftkeyFunction(mmi_phb_choose_number_normal, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#endif
}

#if defined(__MMI_PHB_NAME_LIST_FILTER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_nlf_image_list1_draw_title_info
 * DESCRIPTION
 *  Draw image list 1 title info. It will draw image, name and number here.
 * PARAMETERS
 *  item_idx        [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_nlf_image_list1_draw_title_info(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 char_height;
    S32 box_width, box_height;
    S32 img_box_width = 40, img_box_height = 40;
    S32 img_width, img_height;
    S32 img_draw_width, img_draw_height;
    S32 img_draw_offset_x, img_draw_offset_y;
    S32 spacing;
    S32 offset_x;   /* For name and image offset x */
    S32 offset_y;   /* For name and image offset y */
    S32 num_offset_y;
    S32 name_width;
    U16 store_index = 0;
    S8 *image_path = NULL;
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
    S8 buffer_UCS2[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    S32 i = -1;
    S32 inner_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     *lock and push clip
     */
    gui_lock_double_buffer();
    gui_push_text_clip();
    gui_push_clip();

    gui_reset_clip();
    gui_reset_text_clip();

    while (i < item_idx)
    {
        store_index = g_phb_name_index[inner_index];
#ifdef __MMI_DUAL_SIM_MASTER__
        if (g_phb_cntx.name_list_filter == MMI_SIM)
        {
             if ((store_index >= MAX_PB_PHONE_ENTRIES)&&(store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
             {
                    i++;
             }
        }
        else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
        {
             if(store_index < MAX_PB_PHONE_ENTRIES)
             {
                    i++;
             }
        }
        else if (g_phb_cntx.name_list_filter == MMI_SIM2)
        {
            if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
            {
                  i++;
            }
        }
#else/* __MMI_DUAL_SIM_MASTER__ */
        if (g_phb_cntx.name_list_filter == MMI_SIM)
        {
            if (store_index >= MAX_PB_PHONE_ENTRIES)
            {
                i++;
            }
        }
        else if (g_phb_cntx.name_list_filter == MMI_NVRAM)
        {
            if(store_index < MAX_PB_PHONE_ENTRIES)
            {
                i++;
            }
        }
#endif/* __MMI_DUAL_SIM_MASTER__ */
        else
        {
            i++;
        }
        inner_index++;
    }
    /*
     * Get hint text info
     */
    mmi_phb_convert_get_ucs2_number((S8*) buffer_UCS2, store_index);

    /*
     * Calcuate text position
     */
    box_height = y2 - y1 + 1;
    box_width = x2 - x1 + 1;

    gui_set_font(&MMI_medium_font);
    char_height = gui_get_string_height((UI_string_type) GetString(STR_ID_PHB_MOBILE_NUMBER));
    spacing = (box_height - char_height * 2) / 3;

    offset_y = spacing + MMI_title_height + MMI_title_y;
    num_offset_y = spacing * 2 + char_height + MMI_title_height + MMI_title_y;

    if (r2lMMIFlag) /* For right to left language */
    {
        offset_x = x2 - img_box_width - 6;
    }
    else
    {
        offset_x = x1 + img_box_width + 6;
    }

    name_width = box_width - img_box_width - 12;

    /*
     * Draw Hint Text
     */
    gui_set_font(&MMI_medium_font);

    gui_reset_text_clip();
    gui_set_text_color(gui_color(0, 0, 0));

    /*
     * Draw name/number if not empty
     */
    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name))
    {
        gui_print_truncated_text(offset_x, offset_y, name_width, (UI_string_type) PhoneBook[store_index].alpha_id.name);

        if (mmi_ucs2strlen((S8*) buffer_UCS2))
        {
            gui_print_truncated_text(offset_x, num_offset_y, name_width, (UI_string_type) buffer_UCS2);
        }
    }
    else
    {
        gui_print_truncated_text(offset_x, offset_y, name_width, (UI_string_type) buffer_UCS2);
    }

    /*
     * Get Associate Picture path from file
     */
    if (store_index < MAX_PB_PHONE_ENTRIES)
    {
        mmi_phb_read_optional_ids(store_index); /* i is store index */
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;
        if (opt_ids->pictureTagID == 1
        #ifdef __MMI_AVATAR__
            || opt_ids->pictureTagID == 2
        #endif
            )
        {
            image_path = mmi_phb_image_get_path_from_id((U16) (store_index + 1));
        }
    }

    /*
     * Draw Associate Picture thumb image
     */
    gui_push_clip();

    if (r2lMMIFlag) /* For right to left language */
    {
        offset_x = x2 - img_box_width - 2;
    }
    else
    {
        offset_x = x1 + 2;
    }

    offset_y = y1 + 2;

    gui_set_clip(offset_x, offset_y, offset_x + img_box_width, offset_y + img_box_height);

    /* Get image from file */
#ifdef __USB_IN_NORMAL_MODE__ 
    if (mmi_usb_is_in_mass_storage_mode())
    {
        gdi_image_draw_resized_id(offset_x, offset_y, img_box_width, img_box_height, IMG_ID_PHB_LIST_ICON1);
    }
    else
#endif /* __USB_IN_NORMAL_MODE */
    {    	
        if ((image_path != NULL) && (gdi_image_get_dimension_file(image_path, &img_width, &img_height) >= 0))
        {
            gdi_util_fit_box(
                GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                img_box_width,
                img_box_height,
                img_width,
                img_height,
                &img_draw_offset_x,
                &img_draw_offset_y,
                &img_draw_width,
                &img_draw_height);

            gdi_image_draw_resized_file(
                offset_x + img_draw_offset_x,
                offset_y + img_draw_offset_y,
                img_draw_width,
                img_draw_height,
                image_path);
        }
        else    /* Use default image */
        {
            gdi_image_draw_resized_id(offset_x, offset_y, img_box_width, img_box_height, IMG_ID_PHB_LIST_ICON1);
        }
    }

    gui_pop_clip();

    /*
     * pop clip , unlock and blt
     */
    gui_pop_clip();
    gui_pop_text_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_nlf_entry_image_list1
 * DESCRIPTION
 *  This function list all phonebook entry with picture info on the top with
 *  name list filter feature.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_nlf_entry_image_list1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 i = 0, inner_index = 0, store_index =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check if it can be list in advance
     */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
        return;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (((g_phb_cntx.sim_used == 0) && (g_phb_cntx.name_list_filter == MMI_SIM)) || ((g_phb_cntx.phone_used ==0) && (g_phb_cntx.name_list_filter == MMI_NVRAM)) ||((PhoneBookEntryCount == 0) && (g_phb_cntx.name_list_filter == MMI_STORAGE_BOTH))||((MTPNP_AD_ADN_SIM2GetUsedNumber() == 0) && (g_phb_cntx.name_list_filter == MMI_SIM2)) )
#else   /* __MMI_DUAL_SIM_MASTER__ */
    else if (((g_phb_cntx.sim_used == 0) && (g_phb_cntx.name_list_filter == MMI_SIM)) || ((g_phb_cntx.phone_used == 0) && (g_phb_cntx.name_list_filter == MMI_NVRAM)) ||((PhoneBookEntryCount == 0) && (g_phb_cntx.name_list_filter == MMI_STORAGE_BOTH)))
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
        return;
    }

    /*
     *Check if phonebook entry has been updated, and if need to use alpha_index function.
     */
    if (g_phb_cntx.refresh_list)
    {
        if (g_phb_cntx.name_list_filter == MMI_SIM || g_phb_cntx.name_list_filter == MMI_NVRAM
        #ifdef __MMI_DUAL_SIM_MASTER__
            || g_phb_cntx.name_list_filter == MMI_SIM2
        #endif
            )
        {
            mmi_phb_list_build_alpha_index(NULL, 0, TRUE, g_phb_cntx.name_list_filter);
        }
        else
        {
            mmi_phb_list_build_alpha_index(NULL, 0, TRUE, MMI_STORAGE_NONE);
        }
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_NO_CHANGE;
    }

    EntryNewScreen(SCR_PBOOK_LIST, mmi_phb_exit_list, mmi_phb_nlf_entry_image_list1, MMI_FULL_SCREEN);
    guiBuffer = GetCurrGuiBuffer(SCR_PBOOK_LIST);
    if (guiBuffer == NULL)
    {
        g_phb_highlight_alpha = 0;
    }
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__)
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__) */ 

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    RegisterHighlightHandler(mmi_phb_get_index_speak_name_nlf);
#else 
    RegisterHighlightHandler(mmi_phb_get_index_nlf);
#endif 

    if(g_phb_cntx.name_list_filter == MMI_SIM)
    {
        g_phb_list_index_total = g_phb_cntx.sim_used;
    }
    else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
    {
        g_phb_list_index_total = g_phb_cntx.phone_used;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if(g_phb_cntx.name_list_filter == MMI_SIM2)
    {
         g_phb_list_index_total = MTPNP_AD_ADN_SIM2GetUsedNumber();
    }
#endif/* __MMI_DUAL_SIM_MASTER__ */
    else
    {
        g_phb_list_index_total = PhoneBookEntryCount;
    }

    /* for highlight after edit */
    if (g_phb_cntx.new_highlight_entry < 0xffff)
    {
        while (inner_index <= g_phb_cntx.new_highlight_entry)
        {
            store_index = g_phb_name_index[inner_index];
#ifdef __MMI_DUAL_SIM_MASTER__
            if (g_phb_cntx.name_list_filter == MMI_SIM)
            {
                 if ((store_index >= MAX_PB_PHONE_ENTRIES)&&(store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
                 {
                        i++;
                 }
            }
            else if(g_phb_cntx.name_list_filter == MMI_NVRAM)
            {
                 if(store_index < MAX_PB_PHONE_ENTRIES)
                 {
                        i++;
                 }
            }
            else if (g_phb_cntx.name_list_filter == MMI_SIM2)
            {
                if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
                {
                      i++;
                }
            }
#else/* __MMI_DUAL_SIM_MASTER__ */
            if (g_phb_cntx.name_list_filter == MMI_SIM)
            {
                if (store_index >= MAX_PB_PHONE_ENTRIES)
                {
                    i++;
                }   
            }
            else if (g_phb_cntx.name_list_filter == MMI_NVRAM)
            {
                if(store_index < MAX_PB_PHONE_ENTRIES)
                {
                    i++;
                }
            }
#endif/* __MMI_DUAL_SIM_MASTER__ */
            else
            {
                i++;
            }
            inner_index ++;
        }
        change_list_menu_category_history(guiBuffer, (i - 1), g_phb_list_index_total, 0);
        g_phb_cntx.new_highlight_entry = 0xffff;
    }

    ShowCategory212Screen(
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,      /* Title */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,         /* LSK */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,            /* RSK */
        g_phb_list_index_total,
        mmi_phb_nlf_list_get_item,
        mmi_phb_list_get_null_hint,
        mmi_phb_nlf_image_list1_draw_title_info,
        NULL,                       /* No call back needed when change highlight */
        2,                          /* Info box row count */
        0,                          /* info bg image id */
        g_phb_cntx.highlight_entry, /* Highlight item index */
        (U8*) guiBuffer);

    register_multitap_no_draw_key_handlers();
    set_multitap_functions(mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback);
    change_multitap_mode(0);

    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_op_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_phb_choose_number_normal,KEY_EVENT_UP);
#else   /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_phb_choose_number_normal, KEY_SEND, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */     

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__)
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_SetCenterFunc(mmi_phb_choose_number_normal);
    SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
#else  /* __MMI_DUAL_SIM_MASTER__ */
    SetCenterSoftkeyFunction(mmi_phb_choose_number_normal, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#endif 
}
#endif /* defined(__MMI_PHB_NAME_LIST_FILTER__) */
#endif /* defined(__MMI_FILE_MANAGER__)*/ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_max_pb_phone_entries
 * DESCRIPTION
 *  max configured phone entries
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_get_max_pb_phone_entries(void)
{
    return MAX_PB_PHONE_ENTRIES;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_max_pb_sim_entries
 * DESCRIPTION
 *  max configured phone entries
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_get_max_pb_sim_entries(void)
{
    return MAX_PB_SIM_ENTRIES;
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_max_pb_sim2_entries
 * DESCRIPTION
 *  max configured phone entries
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_get_max_pb_sim2_entries(void)
{
    return MAX_PB_SIM2_ENTRIES;
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


#define MMI_PHB_UTIL_OBSELETE
U8 inPinyinSearchScreen = FALSE;    /* For PinYin Search, Obselete Now */


/*****************************************************************************
 * FUNCTION
 *  PbookListSearchEntryReq
 * DESCRIPTION
 *  Sends the request to stack to search for an entry based on the name entered by the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PbookListSearchEntryReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* _PHONEBOOKMAIN_C */ 

