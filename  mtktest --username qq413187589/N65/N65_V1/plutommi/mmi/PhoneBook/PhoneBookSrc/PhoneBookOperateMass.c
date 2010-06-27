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
 * PhoneBookOperateMass.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for phonebook mass operation.
 *   Such as Copy All and Delete All.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _PHONEBOOKOPERATEMASS_C
#define _PHONEBOOKOPERATEMASS_C

#include "ProtocolEvents.h"
#include "PhoneBookGprot.h"
#include "wgui_status_icons.h"       /* for Missed Call*/
#include "GSM7BitDefaultAlphabet.h"
#include "PhonebookDef.h"
#include "PhoneBookProt.h"
#include "SettingDefs.h"
#include "SettingGprots.h"
#include "SettingsGdcl.h"
#include "CallSetUpEnum.h"
#include "CallsDefs.h"
#include "CallsStruct.h"
#include "SimDetectionGprot.h"

#include "gpioInc.h"
#include "CommonScreens.h"

#ifdef __MMI_VCARD__
#include "FileManagerGProt.h"
#include "vObjects.h"
#include "vCard.h"
#endif /* __MMI_VCARD__ */ 

#if defined(__MMI_VRSD_DIAL__)
#include "VRSDDial.h"
#endif 

#if defined(__MMI_VRSI__)
#include "Mdi_datatype.h"
#include "VRSIResDef.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#endif /* defined(__MMI_VRSI__) */ 

#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */

#ifdef __MERCURY_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Master_ADN.h"
#endif	/* __MERCURY_MASTER__*/

/* 
 * Local Variable
 */
static U16 g_phb_mass_op_index;
static U16 g_phb_mass_op_lookup_count;
static BOOL g_phb_mass_op_abort;

#ifdef __MMI_VCARD__
static S8 pbvCardHomeNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
static S8 pbvCardCompanyName[(MAX_PB_COMPANY_LENGTH + 1) * ENCODING_LENGTH];
static S8 pbvCardEmailAddress[(MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH];
static S8 pbvCardOfficeNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
static S8 pbvCardFaxNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
static S8 pbvCardDay[3 * ENCODING_LENGTH];
static S8 pbvCardMon[3 * ENCODING_LENGTH];
static S8 pbvCardYear[6 * ENCODING_LENGTH];
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
#endif /* __MMI_VCARD__ */ 

#if defined(__MMI_PHB_MULTI_OPERATION__) || defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
static U8 g_phb_multi_select_bitmask[MAX_PB_ENTRIES] = {0};
static U16 g_phb_multi_operation_count = 0;
static S32 g_phb_multi_select_current_index = 0;
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) || defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */

#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
U16 g_phb_multi_select_limit = 0;
#endif /* defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */
#if defined(__MMI_PHB_MULTI_OPERATION__)
static U8 g_phb_multi_operation = 0; /* copy or delete */
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */

/* 
 * Global Variable
 */
BOOL g_phb_mass_op_success = TRUE;
U16 g_phb_mass_op_count;

extern U16 PhoneBookEntryCount;

extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[MAX_PB_ENTRIES];

#ifdef __MMI_PHB_USIM_FIELD__
extern MMI_PHB_EMAIL_STRUCT phb_email[MAX_PB_SIM_ENTRIES];
extern MMI_PHB_NUMBER_BCD_STRUCT phb_anr[MAX_PB_SIM_ENTRIES][3];
extern S8 pbNickName[];
#endif /* __MMI_PHB_USIM_FIELD__ */ 

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
extern PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
#endif 

extern U8 gPhonePassword[];
extern U16 g_phb_name_index[];

extern MMI_PHB_LOOKUP_NODE_STRUCT LookUpTable[];

extern S8 pbName[];
extern S8 pbNumber[];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
extern S8 pbHomeNumber[];
extern S8 pbCompanyName[];
extern S8 pbEmailAddress[];
extern S8 pbOfficeNumber[];
extern S8 pbFaxNumber[];
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */

#if defined(__MMI_PHB_EMAIL_SORT__)
extern U8 g_phb_email_sorted;
#endif 

#if defined(__MMI_PHB_INFO_FIELD__)
extern PHB_INFO_FIELDS_STRUCT PhoneBookInfoFields;
#endif 

/*card2 operate mass*/
#ifdef __MMI_DUAL_SIM_MASTER__
extern BOOL Slave_CopyAll;
extern MTPNP_BOOL Slave_g_phb_mass_delall;
extern MTPNP_BOOL Slave_g_phb_mass_op_abort;
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
extern U8 phb_list_view_type;
extern mmi_phb_get_index_from_group_callback_type phb_generic_multi_select_list_call_back;
#endif

/* 
 * Local Functions
 */
static void mmi_phb_vcard_req(void *info);

#ifdef __MMI_VCARD__
static void mmi_phb_vcard_req_set_default_file(S8 *path);
#endif 
#ifdef __MMI_PHB_USIM_FIELD__
static void mmi_phb_op_copy_all_to_usim_one_after_one_req(void);
#endif 

#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
/* phb_generic_multi_select_check_call_back now only used for generic multi select */
mmi_phb_check_selected_index_callback_type phb_generic_multi_select_check_call_back; 
#endif

#if defined(__MMI_PHB_MULTI_OPERATION__) || defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
static S32 mmi_phb_multi_select_set_state(S32 item_index);
static S32 mmi_phb_multi_select_get_state(S32 item_index, PU8 *checkbox_image);
static void mmi_phb_multi_select_check(void);
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) || defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */

/* 
 * Global Function
 */
extern void SECSETVerifyPINReq(U8 pin_type, U8 *ucs2_pin, U8 *ucs2_new_pin, FuncPtr success_callback);
extern void mmi_chist_delete_miss_call_notify_screen(void);


#define MMI_PHB_MASS_INIT
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_operate_mass_init
 * DESCRIPTION
 *  Initialization of "Copy All, Delete All" feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_operate_mass_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_operate_mass_init.>\n", __FILE__,
                         __LINE__);

#if defined(__MMI_PHB_MULTI_OPERATION__)
    /* Multi Copy and Delete */
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP, mmi_phb_highlight_multi_operation);	
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP_SELECT_ALL, mmi_phb_highlight_multi_op_select_all);
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL, mmi_phb_highlight_multi_op_unselect_all);
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP_SELECT_ALL_FROM_SIM, mmi_phb_highlight_multi_op_select_all_from_sim);
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL_FROM_SIM, mmi_phb_highlight_multi_op_unselect_all_from_sim);
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP_SELECT_ALL_FROM_PHONE, mmi_phb_highlight_multi_op_select_all_from_phone);	
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL_FROM_PHONE, mmi_phb_highlight_multi_op_unselect_all_from_phone);
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP_COPY_SELECTED, mmi_phb_highlight_multi_op_copy_selected);
    SetHiliteHandler(MENU_ID_PHB_MULTI_OP_DELETE_SELECTED, mmi_phb_highlight_multi_op_delete_selected);
#else /* defined(__MMI_PHB_MULTI_OPERATION__) */
    /* Copy All */
    SetHiliteHandler(MITEM104_PBOOK_COPY_ALL, mmi_phb_highlight_copy_all);
    SetHiliteHandler(MITEM_PBOOK_COPY_ALL_SIM, mmi_phb_highlight_copy_all_from_sim);
    SetHiliteHandler(MITEM_PBOOK_COPY_ALL_PHONE, mmi_phb_highlight_copy_all_from_phone);
    SetHintHandler(MITEM_PBOOK_COPY_ALL_SIM, mmi_phb_hint_copy_all_from_sim);
    SetHintHandler(MITEM_PBOOK_COPY_ALL_PHONE, mmi_phb_hint_copy_all_from_phone);

    /* Delete All */
    SetHiliteHandler(MITEM103_PBOOK_DELETE_ALL, mmi_phb_highlight_delete_all);
    SetHiliteHandler(MITEM103_PBOOK_DELETE_ALL_NO_SIM, mmi_phb_highlight_delete_all);	
    SetHiliteHandler(MITEM_PBOOK_DELETE_ALL_SIM, mmi_phb_highlight_delete_all_from_sim);
    SetHiliteHandler(MITEM_PBOOK_DELETE_ALL_PHONE, mmi_phb_highlight_delete_all_from_phone);
    SetHintHandler(MITEM_PBOOK_DELETE_ALL_SIM, mmi_phb_hint_delete_all_from_sim);
    SetHintHandler(MITEM_PBOOK_DELETE_ALL_PHONE, mmi_phb_hint_delete_all_from_phone);
    SetHiliteHandler(MENU_ID_PHB_DELETE_ALL_ONE_BY_ONE, mmi_phb_highlight_delete_all_one_by_one);
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */

//huzhuhua 080722 begin
#ifdef __PHONEBOOK_OUTPUT_INPUT__
      SetHiliteHandler(MITEM104_PBOOK_OUTPUT, mmi_phb_output_highlight);
#endif
#ifdef __PHONEBOOK_INPUT__
      SetHiliteHandler(MITEM104_PBOOK_INPUT, mmi_phb_input_highlight);
      SetHiliteHandler(MENU_ID_PB_INPUT_OPTION_INPUT, mmi_phb_option_input_highlight);      
      pb_input_init();    //huzhuhua 080724
#endif
//end

    /* AT Command Update */
    SetProtocolEventHandler(mmi_phb_ind_update, PRT_PHB_UPDATE_IND);
    SetProtocolEventHandler(mmi_phb_vcard_req, PRT_PHB_VCARD_REQ_IND);
}


#if defined(__MMI_PHB_MULTI_OPERATION__) || defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_multi_select_populate_selected_list
 * DESCRIPTION
 *  populate selected list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_generic_multi_select_populate_selected_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 selected_count = g_phb_multi_operation_count;
    U16 i, j = 0;
    U16 store_index = 0;
    S32 inner_index = 0;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < PhoneBookEntryCount ; ++i)
    {
        if (g_phb_multi_select_bitmask[i] == 1)
        {
            selected_count--;

            index = -1;
            inner_index = 0;          
            while (index < i)
            {
                store_index = g_phb_name_index[inner_index];
                if (PhoneBook[store_index].field & phb_list_view_type)
                {
                    index++;  
                }	
                inner_index++;
            }
            g_phb_cntx.list_filter[j++] = store_index;
        }
        if (selected_count == 0)
            break;
    }
}
#endif /*defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_multi_select_highlight_hdlr
 * DESCRIPTION
 *  Highlight Handler for multi select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_multi_select_highlight_hdlr(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_multi_select_current_index = i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_multi_select_set_state
 * DESCRIPTION
 *  set check box state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_phb_multi_select_set_state(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)    
    MMI_BOOL check_result = MMI_TRUE;
#endif /* defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_multi_select_bitmask[item_index] = !g_phb_multi_select_bitmask[item_index];
    if (g_phb_multi_select_bitmask[g_phb_multi_select_current_index])
    {
        g_phb_multi_operation_count += 1;
        MMI_ASSERT(g_phb_multi_operation_count <= PhoneBookEntryCount);
    #if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
        if (phb_generic_multi_select_check_call_back != NULL)
        {
            mmi_phb_generic_multi_select_populate_selected_list();
            check_result = phb_generic_multi_select_check_call_back(g_phb_multi_operation_count, g_phb_cntx.list_filter);
        }

        if ((g_phb_multi_operation_count > g_phb_multi_select_limit) || check_result == MMI_FALSE)
        {
            g_phb_multi_select_bitmask[g_phb_multi_select_current_index] = !g_phb_multi_select_bitmask[g_phb_multi_select_current_index];
            g_phb_multi_operation_count -= 1;
            if (g_phb_multi_operation_count > g_phb_multi_select_limit)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_PHB_MULTI_OP_MAX_ITEM_REACH),
                    IMG_GLOBAL_WARNING,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    WARNING_TONE);
            }
        }
    #endif /* defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */        
    }
    else
    {
        MMI_ASSERT(g_phb_multi_operation_count >= 1);
        g_phb_multi_operation_count -= 1;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_multi_select_get_state
 * DESCRIPTION
 *  get check box state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_phb_multi_select_get_state(S32 item_index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *checkbox_image = (g_phb_multi_select_bitmask[item_index]) ? (PU8)GetImage(CHECKBOX_ON_IMAGE_ID) : (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID) ;
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_multi_select_check
 * DESCRIPTION
 *  set check box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_multi_select_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_multi_select_set_state(g_phb_multi_select_current_index);    
    RedrawCategoryFunction();
}
#endif


#if defined(__MMI_PHB_MULTI_OPERATION__)
#define MMI_PHB_OP_MULTI_OP
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op
 * DESCRIPTION
 *  Highlight handler for "Multi Operation" in PHB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_operation.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_multi_operation, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_multi_operation, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op_select_all
 * DESCRIPTION
 *  Highlight handler for "Select All" in PHB -> Multi Operation -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_op_select_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_op_select_all.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_op_select_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_multi_op_select_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op_unselect_all
 * DESCRIPTION
 *  Highlight handler for "Unselect All" in PHB -> Multi Operation -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_op_unselect_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_op_unselect_all.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_op_unselect_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_multi_op_unselect_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op_select_all_from_sim
 * DESCRIPTION
 *  Highlight handler for "Select All From SIM" in PHB -> Multi Operation -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_op_select_all_from_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_op_select_all_from_sim.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_op_select_all_from_sim, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_multi_op_select_all_from_sim, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op_unselect_all_from_sim
 * DESCRIPTION
 *  Highlight handler for "Unselect All From SIM" in PHB -> Multi Operation -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_op_unselect_all_from_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_op_unselect_all_from_sim.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_op_unselect_all_from_sim, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_multi_op_unselect_all_from_sim, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op_select_all_from_phone
 * DESCRIPTION
 *  Highlight handler for "Select All From Phone" in PHB -> Multi Operation -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_op_select_all_from_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_op_select_all_from_phone.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_op_select_all_from_phone, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_multi_op_select_all_from_phone, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op_unselect_all_from_phone
 * DESCRIPTION
 *  Highlight handler for "Unselect All From Phone" in PHB -> Multi Operation -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_op_unselect_all_from_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_op_unselect_all_from_phone.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_op_unselect_all_from_phone, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_multi_op_unselect_all_from_phone, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op_copy_selected
 * DESCRIPTION
 *  Highlight handler for "Copy Selected" in PHB -> Multi Operation -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_op_copy_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_op_copy_selected.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_op_copy_selected, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_multi_op_copy_selected, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_multi_op_delete_selected
 * DESCRIPTION
 *  Highlight handler for "Delete Selected" in PHB -> Multi Operation -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_multi_op_delete_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_multi_op_delete_selected.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_op_delete_selected, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_multi_op_delete_selected, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_select_all
 * DESCRIPTION
 *  Select All entry in phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_select_all(void)
{
    U16 index = 0;
    for(index = 0; index < PhoneBookEntryCount; index++)
    {
        g_phb_multi_select_bitmask[index] = 1;
        g_phb_multi_operation_count = PhoneBookEntryCount;
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_unselect_all_op
 * DESCRIPTION
 *  Unselect All entry in phb (for operation)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_unselect_all_op(void)
{
    U16 index = 0;
    for(index = 0; index < PhoneBookEntryCount; index++)
    {
        g_phb_multi_select_bitmask[index] = 0;
        g_phb_multi_operation_count = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_unselect_all
 * DESCRIPTION
 *  Unselect All entry in phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_unselect_all(void)
{
    mmi_phb_op_multi_op_unselect_all_op();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_select_all_from_sim
 * DESCRIPTION
 *  Select All entry in SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_select_all_from_sim(void)
{
    U16 index = 0;
    for(index = 0; index < PhoneBookEntryCount; index++)
    {
        if ((g_phb_name_index[index] >= MAX_PB_PHONE_ENTRIES) && (g_phb_multi_select_bitmask[index] == 0))
        {
            g_phb_multi_select_bitmask[index] = 1;
            g_phb_multi_operation_count++;            
            MMI_ASSERT(g_phb_multi_operation_count <= PhoneBookEntryCount);          
        }
    }
    GoBackHistory();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_unselect_all_from_sim
 * DESCRIPTION
 *  Unselect All entry in SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_unselect_all_from_sim(void)
{
    U16 index = 0;
    for (index = 0; index < PhoneBookEntryCount; index++)
    {
        if ((g_phb_name_index[index] >= MAX_PB_PHONE_ENTRIES) && (g_phb_multi_select_bitmask[index] == 1))
        {
            g_phb_multi_select_bitmask[index] = 0;
            MMI_ASSERT(g_phb_multi_operation_count >= 1);            
            g_phb_multi_operation_count--;            
        }
    }
    GoBackHistory();  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_select_all_from_phone
 * DESCRIPTION
 *  Select All entry in Phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_select_all_from_phone(void)
{
    U16 index = 0;
    for (index = 0; index < PhoneBookEntryCount; index++)
    {
        if ((g_phb_name_index[index] < MAX_PB_PHONE_ENTRIES) && (g_phb_multi_select_bitmask[index] == 0))
        {
            g_phb_multi_select_bitmask[index] = 1;
            g_phb_multi_operation_count++;            
            MMI_ASSERT(g_phb_multi_operation_count <= PhoneBookEntryCount);    
        }
    }
    GoBackHistory();  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_unselect_all_from_phone
 * DESCRIPTION
 *  Unselect All entry in Phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_unselect_all_from_phone(void)
{
    U16 index = 0;
    for (index = 0; index < PhoneBookEntryCount; index++)
    {
        if ((g_phb_name_index[index] < MAX_PB_PHONE_ENTRIES) && (g_phb_multi_select_bitmask[index] == 1))
        {
            g_phb_multi_select_bitmask[index] = 0;
            MMI_ASSERT(g_phb_multi_operation_count >= 1);           
            g_phb_multi_operation_count--;            
        }
    }
    GoBackHistory(); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_copy_selected
 * DESCRIPTION
 *  Copy Selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_copy_selected(void)
{
    g_phb_multi_operation = MMI_PHB_MULTI_COPY;
    mmi_phb_entry_op_multi_copy_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_multi_copy_confirm
 * DESCRIPTION
 *  confirm multi_copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_multi_copy_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_multi_copy_confirm.>\n", __FILE__,
                         __LINE__);
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)GetString(STR_ID_PHB_MULTI_OP_COPY_SELECTED_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_copy_pre_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_copy_pre_req
 * DESCRIPTION
 *  pre check before multi copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_copy_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL find_first_entry = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_multi_operation_count = 0;
    if (PhoneBookEntryCount == MAX_PB_ENTRIES)
    {
        mmi_phb_op_multi_op_unselect_all_op();
        DisplayPopup((PU8) GetString(STR_ID_PHB_MULTI_OP_DEST_FULL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        DeleteUptoScrID(SCR_ID_PHB_MULTI_OP_PHB_LIST);
    }
    else
    {
        g_phb_mass_op_index = 0;
        g_phb_mass_op_count = 0;
        g_phb_mass_op_lookup_count = 0;  
        for (i = g_phb_mass_op_index; i < PhoneBookEntryCount; i ++)
        {
            if (g_phb_multi_select_bitmask[i] == 1)
            {
                g_phb_mass_op_index = i;
                if ((!((g_phb_name_index[g_phb_mass_op_index] >= MAX_PB_PHONE_ENTRIES) && (g_phb_cntx.phone_used == g_phb_cntx.phone_total)))
                    && (!((g_phb_name_index[g_phb_mass_op_index] < MAX_PB_PHONE_ENTRIES) && (g_phb_cntx.sim_used == g_phb_cntx.sim_total))))
                {
                    find_first_entry = MMI_TRUE;                   
                    break;
                }
                else
                {
                    g_phb_multi_select_bitmask[g_phb_mass_op_index] = 0;
                }
            }
        }

        if (find_first_entry == MMI_FALSE)
        {
            mmi_phb_op_multi_op_unselect_all_op();
            DisplayPopup((PU8) GetString(STR_ID_PHB_MULTI_OP_DEST_FULL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            DeleteUptoScrID(SCR_ID_PHB_MULTI_OP_PHB_LIST);
        }
        else
        {
            g_phb_mass_op_abort = FALSE;  
            g_phb_cntx.processing = TRUE;

            g_phb_cntx.copy_all = TRUE; /* copy all flag for distinguish copy all or delete all if sim refresh */
            
            mmi_phb_show_mass_processing(STR_GLOBAL_COPYING, IMG_COPIED);
            mmi_phb_op_multi_copy_one_after_one_req();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_copy_one_after_one_req
 * DESCRIPTION
 *  multi copy one after one
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_copy_one_after_one_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_multi_copy_one_after_one_req.>\n",
                         __FILE__, __LINE__);

    store_index = g_phb_name_index[g_phb_mass_op_index];
#if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
    mmi_phb_util_make_pinyin_cache(store_index);
#endif 

    myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));

    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_NVRAM : MMI_SIM;
    myMsgPtr->list.index = 0xFFFF;
    myMsgPtr->list.record_index = 0xFFFF;

    mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_phb_op_multi_copy_one_after_one_rsp, PRT_PHB_SET_ENTRY_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_copy_one_after_one_rsp
 * DESCRIPTION
 *  response message after copy one entry.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_copy_one_after_one_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;
    U8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];
    S16 pError;
    U16 store_index, src_store_index, inserted_pos = 0, i;
    MMI_BOOL find_next_entry = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_multi_copy_one_after_one_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0 /* OK */ )
    {
        g_phb_mass_op_count += 1;
        src_store_index = g_phb_name_index[g_phb_mass_op_index];

        store_index = mmi_phb_op_get_store_index_and_increase_counter(localPtr->list[0].storage, localPtr->list[0].record_index);

        if (localPtr->list[0].storage == MMI_NVRAM) /* From SIM to NVRAM */
        {
        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            /* Optional Fields */
            memset(&PhoneBookOptionalFields, 0, sizeof(PhoneBookOptionalFields));
        #ifdef __MMI_PHB_USIM_FIELD__
            mmi_phb_op_set_option_data_by_usim_index(src_store_index, &PhoneBookOptionalFields);
        #endif 
            WriteRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (localPtr->list[0].record_index),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
            /* Clear Optional Selection Fields */
            mmi_phb_clear_optional_ids(store_index);

            /* Clear video field. */
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_delete_by_index(store_index);
        #endif 
            /* Clear birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            mmi_phb_bday_delete_field(store_index);
        #endif 
        #if defined(__MMI_PHB_INFO_FIELD__)
            /* Information Fields */
            mmi_phb_info_delete_field(store_index);
        #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
        #if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
            mmi_phb_service_delete_field(store_index);
        #endif 
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_ADD, store_index);
        #endif
        }
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        mmi_phb_copy_optional_ids(store_index, src_store_index);

        if (localPtr->list[0].storage == MMI_SIM)
        {
            mmi_phb_clear_optional_ids_for_sim(store_index);
        }
    #endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 


        mmi_phb_convert_to_digit(num_ascii, PhoneBook[src_store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
        g_phb_mass_op_lookup_count += mmi_phb_op_increase_lookup_table(store_index, (S8*) num_ascii, NULL, NULL, NULL);

        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list[0], store_index);
    
        if (localPtr->list[0].storage == MMI_SIM)
        {
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                TRUE);
        }
        else
        {
        #if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                TRUE);
        #else /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                (S8*) PhoneBookOptionalFields.homeNumber,
                (S8*) PhoneBookOptionalFields.officeNumber,
                (S8*) PhoneBookOptionalFields.faxNumber,
                (S8*) PhoneBookOptionalFields.emailAddress,
                TRUE);
        #endif /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
        }

        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }

    #if defined(__MMI_PHB_PINYIN_SORT__)    /* Update Pinyin Cache for sort */
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 

        /* Insert name index to name sorting mapping table. */
        inserted_pos = mmi_phb_sort_insert_name_index(store_index);

        /* Insert email index to email sorting mapping table */
    #if defined(__MMI_PHB_EMAIL_SORT__)
        if ((localPtr->list[0].storage == MMI_NVRAM) && (g_phb_email_sorted == 1))      /* From SIM to NVRAM */
        {
            mmi_phb_sort_email_insert_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

        /* add central command for vrsi. */
    #if defined(__MMI_VRSI__)
        mmi_vrsi_ndial_central_add_single(store_index);
    #endif

        /* result = success, insert the new entry, move back all the rest entry bitmask*/
        g_phb_multi_select_bitmask[g_phb_mass_op_index] = 0;
        for (i = (PhoneBookEntryCount - 1); i > inserted_pos; i--)
        {
            g_phb_multi_select_bitmask[i] = g_phb_multi_select_bitmask[i - 1];
        }
        g_phb_multi_select_bitmask[inserted_pos] = 0;
    }
    else
    {
        g_phb_multi_select_bitmask[g_phb_mass_op_index] = 0;
        g_phb_mass_op_success = MMI_FALSE;
    }

    /* find the next entry to operate */
    if (g_phb_mass_op_abort)
    {
        g_phb_mass_op_success = FALSE;
        mmi_phb_op_multi_copy_done();
    }
    else
    {
        for (i = g_phb_mass_op_index; i < PhoneBookEntryCount; i ++)
        {
            if (g_phb_multi_select_bitmask[i] == 1)
            {
                g_phb_mass_op_index = i;
                if (!(((g_phb_name_index[g_phb_mass_op_index] >= MAX_PB_PHONE_ENTRIES) && (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
                    || ((g_phb_name_index[g_phb_mass_op_index] < MAX_PB_PHONE_ENTRIES) && (g_phb_cntx.sim_used == g_phb_cntx.sim_total))))
                {
                    find_next_entry = MMI_TRUE;                  
                    break;
                }
                else
                {
                    g_phb_multi_select_bitmask[g_phb_mass_op_index] = 0;
                    g_phb_mass_op_success = MMI_FALSE;
                }
            }
        }

        if (find_next_entry == MMI_TRUE)
        {
            mmi_phb_op_multi_copy_one_after_one_req();
        }
        else
        {
            mmi_phb_op_multi_copy_done();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_copy_done
 * DESCRIPTION
 *  multi copy done. displays result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_copy_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 outBuf[100], count[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.processing = FALSE;
    TurnOnBacklight(1); /* Turn On Back Light When done */
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    /* Sort lookup table */
    if (g_phb_mass_op_lookup_count)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count += g_phb_mass_op_lookup_count;
    }

    /* No need to clear video id, because it will reset when set new entry */

    /* Display result */
    if (g_phb_mass_op_success)
    {
        DisplayPopup((PU8) GetString(STR_ID_PHB_COPIED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    }
    else if (!g_phb_mass_op_success)
    {
        g_phb_mass_op_success = TRUE;
        sprintf(count, "%d ", g_phb_mass_op_count);
        mmi_asc_to_ucs2(outBuf, count);
        if (g_phb_mass_op_count <= 1)
        {
            mmi_ucs2cat(outBuf, GetString(STR_ENTRY_COPIED));
        }
        else
        {
            mmi_ucs2cat(outBuf, GetString(STR_ENTRIES_COPIED));
        }
        DisplayPopup((U8*) outBuf, IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_PHB_MULTI_OP_OPTION);

    /* Re-add all central command for vrsi. */
#if defined(__MMI_VRSI__)
    mmi_vrsi_init_central_abort();

    /* Also remove SD tag if entry is deleted. */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_ndial_central_update_sd_mapping();
#endif 

    /* mmi_vrsi_init_central_add_all(); */
#endif /* defined(__MMI_VRSI__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_op_delete_selected
 * DESCRIPTION
 *  Delete Selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_op_delete_selected(void)
{
	g_phb_multi_operation = MMI_PHB_MULTI_DELETE;
    mmi_phb_entry_op_multi_delete_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_multi_delete_confirm
 * DESCRIPTION
 *  confirm multi_delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_multi_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_multi_delete_confirm.>\n", __FILE__,
                         __LINE__);
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)GetString(STR_ID_PHB_MULTI_OP_DELETE_SELECTED_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_op_multi_delete_pre_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_delete_pre_req
 * DESCRIPTION
 *  pre check before multi delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_delete_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_multi_operation_count = 0;
    g_phb_mass_op_index = 0;
    g_phb_cntx.processing = TRUE;

    g_phb_cntx.copy_all = FALSE;

    g_phb_mass_op_abort = FALSE;
    g_phb_mass_op_count = 0;
    g_phb_mass_op_lookup_count = 0;

    for (i = g_phb_mass_op_index; i < PhoneBookEntryCount; i ++)
    {
        if (g_phb_multi_select_bitmask[i] == 1)
        {
            g_phb_mass_op_index = i;
            break;
        }
    }

    mmi_phb_show_mass_processing(STR_GLOBAL_DELETING, IMG_GLOBAL_DELETED);
    mmi_phb_op_multi_delete_one_after_one_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_delete_one_after_one_req
 * DESCRIPTION
 *  multi delete one entry after one.
 * PARAMETERS
 *  delete_storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_delete_one_after_one_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_multi_delete_one_after_one_req.>\n",
                         __FILE__, __LINE__);

    store_index = g_phb_name_index[g_phb_mass_op_index];
    storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;

    myMsgPtr = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));

    myMsgPtr->storage = storage;
    myMsgPtr->del_all = MMI_FALSE;
    myMsgPtr->no_data = 1;
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    myMsgPtr->index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_multi_delete_one_after_one_rsp, PRT_PHB_DEL_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_delete_one_after_one_rsp
 * DESCRIPTION
 *  response message after multi delete one entry.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_delete_one_after_one_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_RSP_STRUCT *localPtr;
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
    U16 store_index;
    U16 record_index;
    U8 storage;
    U16 i;
    MMI_BOOL find_next_entry = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT*) info;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_multi_delete_one_after_one_rsp.>\n",
                         __FILE__, __LINE__);

    if (localPtr->result.flag == 0 /* OK */ )
    {
        store_index = g_phb_name_index[g_phb_mass_op_index];
        storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;
        record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

        g_phb_mass_op_count++;

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_PHONEBOOK, NULL, NULL);

        if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
        {
            g_phb_cntx.sim_used--;
        #if defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(store_index);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__) */ 
        }
        else
        {
            g_phb_cntx.phone_used--;

        #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
            /* Delete image file in file folder */
            mmi_phb_read_optional_ids(store_index);
            opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;

            if ((opt_ids->pictureTagID == 1)
            #ifdef __MMI_AVATAR__
                || (opt_ids->pictureTagID == 2)
            #endif
                )
            {
                mmi_phb_image_delete_by_index(record_index);
            }
        #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
            /* Delete incoming call video */
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_delete_by_index(store_index);
        #endif
            //mmi_phb_clear_optional_ids(store_index);
            /* Clear birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_BIRTHDAY_REMINDER__)
            mmi_phb_bday_delete_field(store_index);
        #endif 

            /* Remove email entry from email sort mapping table */
        #if defined(__MMI_PHB_EMAIL_SORT__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(store_index);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_DELETE, store_index);
        #endif
        }

        /* Remove lookup table entry, and sort result when delete all done. */
        g_phb_mass_op_lookup_count += mmi_phb_op_clear_lookup_table_by_index(store_index);

    #if defined(__MMI_VRSD_DIAL__)
        /* remove voice dial tag if exists. */
        mmi_vrsddial_delete_tag_by_store_index(store_index);
    #endif /* defined(__MMI_VRSD_DIAL__) */ 

    #if defined(__MMI_VRSI__)
        /* remove voice dial tag if exists. */
        mmi_vrsi_ndial_central_delete_single(store_index);
    #endif /* defined(__MMI_VRSI__) */ 

        /* clear phonebook entry and remove from index */
        mmi_phb_op_delete_update_index(store_index);

        for (i = g_phb_mass_op_index; i < PhoneBookEntryCount; i++)
        {
            g_phb_multi_select_bitmask[i] = g_phb_multi_select_bitmask[i + 1];
        }
    }
    else
    {
        g_phb_mass_op_success = FALSE;
        g_phb_multi_select_bitmask[g_phb_mass_op_index] = 0; 
    }

    if (g_phb_mass_op_abort)
    {
        g_phb_mass_op_success = FALSE;
        mmi_phb_op_multi_delete_done();
    }
    else
    {
        for (i = g_phb_mass_op_index; i < PhoneBookEntryCount; i ++)
        {
            if (g_phb_multi_select_bitmask[i] == 1)
            {
                g_phb_mass_op_index = i;
                find_next_entry = MMI_TRUE;
                break;
            }
        }

        if (find_next_entry == MMI_TRUE)
        {
            mmi_phb_op_multi_delete_one_after_one_req();
        }
        else
        {
            mmi_phb_op_multi_delete_done();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_multi_delete_done
 * DESCRIPTION
 *  delete all done. displays result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_multi_delete_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 outBuf[100], count[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.processing = FALSE;
    TurnOnBacklight(1); /* Turn On Back Light When done */
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    /* Sort lookup table */
    if (g_phb_mass_op_lookup_count)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= g_phb_mass_op_lookup_count;
    }

    /* No need to clear video id, because it will reset when set new entry */

    /* Display result */
    if (g_phb_mass_op_success)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    }
    else if (!g_phb_mass_op_success)
    {
        g_phb_mass_op_success = TRUE;
        sprintf(count, "%d ", g_phb_mass_op_count);
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
    }

    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_PHB_MULTI_OP_OPTION);

    /* Re-add all central command for vrsi. */
#if defined(__MMI_VRSI__)
    mmi_vrsi_init_central_abort();

    /* Also remove SD tag if entry is deleted. */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_ndial_central_update_sd_mapping();
#endif 

    /* mmi_vrsi_init_central_add_all(); */
#endif /* defined(__MMI_VRSI__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_multi_op_option
 * DESCRIPTION
 *  Draws the Entry Options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_op_multi_op_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MMI_PHB_MULTI_OP_OPTION_ENUM_TOTAL];        /* Need Expand when has more options. */
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_multi_op_option.>\n", __FILE__, __LINE__);

    mmi_frm_unhide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL);
    mmi_frm_unhide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL);
    mmi_frm_unhide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL_FROM_SIM);
    mmi_frm_unhide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL_FROM_SIM);
    mmi_frm_unhide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL_FROM_PHONE);
    mmi_frm_unhide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL_FROM_PHONE);
    mmi_frm_unhide_menu_item(MENU_ID_PHB_MULTI_OP_COPY_SELECTED);
    mmi_frm_unhide_menu_item(MENU_ID_PHB_MULTI_OP_DELETE_SELECTED);

    if ((!mmi_bootup_is_sim_valid()) || (g_phb_cntx.sim_used == 0))
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL_FROM_SIM);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL_FROM_SIM);
    }
    if (g_phb_cntx.phone_used == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL);  
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL_FROM_PHONE);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL_FROM_PHONE);
    }
    if ((!mmi_bootup_is_sim_valid()) || (g_phb_multi_operation_count == 0))
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_COPY_SELECTED);
    }
    if (g_phb_multi_operation_count == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_DELETE_SELECTED);
    }
    if (gSecuritySetupContext.FdlStatus)   /* For FDN on Message */
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_SELECT_ALL_FROM_SIM);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_UNSELECT_ALL_FROM_SIM);
        mmi_frm_hide_menu_item(MENU_ID_PHB_MULTI_OP_COPY_SELECTED);        
    }
    EntryNewScreen(SCR_ID_PHB_MULTI_OP_OPTION, mmi_phb_exit_op_multi_op_option, mmi_phb_entry_op_multi_op_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_MULTI_OP_OPTION);
    
    nNumofItem = GetNumOfChild_Ext(MENU_ID_PHB_MULTI_OP_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_PHB_MULTI_OP_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_MULTI_OP_OPTION);
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
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_multi_op_option
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_multi_op_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_exit_op_multi_op_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_MULTI_OP_OPTION;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_multi_operation
 * DESCRIPTION
 *  Entry fuction of multi operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_multi_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *titleHintString;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_multi_operation.>\n", __FILE__, __LINE__);

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_entry_not_ready(STR_ID_PHB_PROCESSING_USIM);
    }
#endif /* __MMI_PHB_USIM_FIELD__ */
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (PhoneBookEntryCount)
    {
        EntryNewScreen(SCR_ID_PHB_MULTI_OP_PHB_LIST, mmi_phb_exit_multi_operation, mmi_phb_entry_multi_operation, NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_MULTI_OP_PHB_LIST);
        RegisterHighlightHandler(mmi_phb_multi_select_highlight_hdlr);
    
        if (guiBuffer == NULL)
        {   
            for (i = 0; i < MAX_PB_ENTRIES; i ++)
            {
                g_phb_multi_select_bitmask[i] = 0;
            }
            g_phb_multi_operation_count = 0;
        }

    #ifdef __MMI_TOUCH_SCREEN__
        titleHintString = (U8*) GetString(STR_ID_PHB_MULTI_OP_TOUCH_BOX);
    #else /* def __MMI_TOUCH_SCREEN__ */
        titleHintString = (U8*) GetString(STR_ID_PHB_MULTI_OP_PRESS_STAR);
    #endif /* def __MMI_TOUCH_SCREEN__ */

        ShowCategory384Screen(
            (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8)GetImage(IMG_SCR_PBOOK_CAPTION),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            titleHintString,
            PhoneBookEntryCount,
            mmi_phb_list_get_item,
            mmi_phb_list_get_hint,
            mmi_phb_multi_select_get_state,
            mmi_phb_multi_select_set_state,
            0,
            guiBuffer);

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif

        SetLeftSoftkeyFunction(mmi_phb_entry_op_multi_op_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_entry_op_multi_op_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        SetKeyHandler(mmi_phb_multi_select_check, KEY_ENTER, KEY_EVENT_UP);     
        SetKeyHandler(mmi_phb_multi_select_check, KEY_STAR, KEY_EVENT_UP);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_multi_operation
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_multi_operation()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_multi_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_MULTI_OP_PHB_LIST;
}
#else /* defined(__MMI_PHB_MULTI_OPERATION__) */

#define MMI_PHB_OP_COPY_ALL


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_copy_all
 * DESCRIPTION
 *  Highlight handler for "Copy All" in PHB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_copy_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_copy_all.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_copy_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_copy_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_copy_all_from_sim
 * DESCRIPTION
 *  Highlight handler for "From SIM" in Copy All menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_copy_all_from_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_cntx.selected_storage = MMI_SIM;

    if (g_phb_cntx.sim_used || gSecuritySetupContext.FdlStatus)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_copy_all_confirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_copy_all_from_phone
 * DESCRIPTION
 *  Highlight handler for "From Phone" in Copy All menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_copy_all_from_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_cntx.selected_storage = MMI_NVRAM;

    if (g_phb_cntx.phone_used)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_copy_all_confirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_copy_all_from_sim
 * DESCRIPTION
 *  Hint handler for "From SIM" in Copy All menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_copy_all_from_sim(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 simStatus[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_sim(simStatus);
    mmi_ucs2cpy((S8*) hintData[index], simStatus);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_copy_all_from_phone
 * DESCRIPTION
 *  Hint handler for "From Phone" in Copy All menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_copy_all_from_phone(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 phoneStatus[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_phone(phoneStatus);
    mmi_ucs2cpy((S8*) hintData[index], phoneStatus);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_copy_all
 * DESCRIPTION
 *  Draws the Copy All menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_copy_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 nStrItemList[6];
    U16 nImgIltemList[6];
    U8 *nHintList[6];
#else /* __MMI_DUAL_SIM_MASTER__ */
    U16 nStrItemList[2];
    U16 nImgIltemList[2];
    U8 *nHintList[2];
#endif /* __MMI_DUAL_SIM_MASTER__ */
    U16 nNumofItem;
    U8 hilitedStorage;
    U8 hilight_sim, highlight_phone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_copy_all.>\n", __FILE__, __LINE__);

    g_phb_mass_op_abort = FALSE;
#ifdef __MMI_DUAL_SIM_MASTER__
    Slave_g_phb_mass_op_abort= FALSE;
    if(MTPNP_PFAL_Phb_IsReady()==MTPNP_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_entry_not_ready(STR_ID_PHB_PROCESSING_USIM);
    }
#endif /* __MMI_PHB_USIM_FIELD__ */
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (PhoneBookEntryCount)
    {
        EntryNewScreen(SCR_COPY_ALL_MENU, mmi_phb_exit_copy_all, mmi_phb_entry_copy_all, NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_COPY_ALL_MENU);
#ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_PFAL_PB_CopyAll_Menu_Handle();

        nNumofItem = GetNumOfChild_Ext(MITEM104_PBOOK_COPY_ALL);
        GetSequenceStringIds_Ext(MITEM104_PBOOK_COPY_ALL, nStrItemList);
        GetSequenceImageIds_Ext(MITEM104_PBOOK_COPY_ALL, nImgIltemList);
#else /* __MMI_DUAL_SIM_MASTER__ */
        nNumofItem = GetNumOfChild(MITEM104_PBOOK_COPY_ALL);
        GetSequenceStringIds(MITEM104_PBOOK_COPY_ALL, nStrItemList);
        GetSequenceImageIds(MITEM104_PBOOK_COPY_ALL, nImgIltemList);
#endif /* __MMI_DUAL_SIM_MASTER__ */
        SetParentHandler(MITEM104_PBOOK_COPY_ALL);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        ConstructHintsList(MITEM104_PBOOK_COPY_ALL, nHintList);
        
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (g_phb_cntx.prefer_storage == MMI_SIM)
        {
            if (mmi_bootup_is_sim_valid())
            {
                hilitedStorage = GetIndexOfStringId_Ext(MITEM104_PBOOK_COPY_ALL, MITEM_PBOOK_COPY_ALL_SIM);
            }
            else
            {
                hilitedStorage = 0;
            }
        }
        else if (g_phb_cntx.prefer_storage == MMI_SIM2)
        {
            if (mmi_bootup_is_sim2_valid())
            {
                hilitedStorage = GetIndexOfStringId_Ext(MITEM104_PBOOK_COPY_ALL, MENU_MTPNP_PB_COPYALL_SIM2TOPHONE);
            }
            else
            {
                hilitedStorage = 0;
            }    
        }
        else
        {
            if (mmi_bootup_is_sim_valid())
            {
                hilitedStorage = GetIndexOfStringId_Ext(MITEM104_PBOOK_COPY_ALL, MITEM_PBOOK_COPY_ALL_PHONE);            
            }
            else if (mmi_bootup_is_sim2_valid())
            {
                hilitedStorage = GetIndexOfStringId_Ext(MITEM104_PBOOK_COPY_ALL, MENU_MTPNP_PB_COPYALL_PHONETOSIM2);        
            }
            else
            {
                hilitedStorage = 0;
            }
        }
    #else /* __MMI_DUAL_SIM_MASTER__ */
        hilight_sim = GetIndexOfStringId_Ext(MITEM104_PBOOK_COPY_ALL, MITEM_PBOOK_COPY_ALL_SIM);
        highlight_phone = GetIndexOfStringId_Ext(MITEM104_PBOOK_COPY_ALL, MITEM_PBOOK_COPY_ALL_PHONE);
        if (g_phb_cntx.prefer_storage == MMI_SIM)
        {
            if ((g_phb_cntx.sim_used > 0) || (g_phb_cntx.phone_used == 0))
            {
                hilitedStorage = hilight_sim;
            }
            else
            {
                hilitedStorage = highlight_phone;
            }
        }
        else
        {
            if ((g_phb_cntx.phone_used > 0) || (g_phb_cntx.sim_used == 0))
            {
                hilitedStorage = highlight_phone;
            }
            else
            {
                hilitedStorage = hilight_sim;
            }
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        ShowCategory52Screen(
            STR_SCR_COPY_ALL_MENU_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            nImgIltemList,
            nHintList,
            0,
            hilitedStorage,
            guiBuffer);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_copy_all
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_copy_all()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_copy_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_COPY_ALL_MENU;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_copy_all_confirm
 * DESCRIPTION
 *  confirm copy all from sim or phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_copy_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_all_confirm.>\n", __FILE__,
                         __LINE__);

    if (gSecuritySetupContext.FdlStatus)   /* For FDN on Message */
    {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return;
    }

    if (g_phb_cntx.selected_storage == MMI_SIM)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        message = get_string(STRING_MTPNP_PHB_COPY_ALL_FROM_SIM1);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        message = get_string(STR_COPY_ALL_SIM_QUERY);
    #endif /* __MMI_DUAL_SIM_MASTER__ */    
    }
    else
    {
        message = get_string(STR_COPY_ALL_PHONE_QUERY);
    }
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        message,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_op_copy_all_pre_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_all_pre_req
 * DESCRIPTION
 *  pre-entry function of copy all. check storage first.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_all_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_all_pre_req.>\n", __FILE__,
                         __LINE__);

    if ((g_phb_cntx.selected_storage == MMI_NVRAM) && (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STRING_MTPNP_SIM1_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);    
    #else /* __MMI_DUAL_SIM_MASTER__ */
        DisplayPopup((PU8) GetString(STR_SIM_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        DeleteNScrId(SCR_COPY_ALL_MENU);
    }
    else if ((g_phb_cntx.selected_storage == MMI_SIM) && (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
    {
        DisplayPopup((PU8) GetString(STR_PHONE_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        DeleteNScrId(SCR_COPY_ALL_MENU);
    }
    else    /* Have free space, begin to copy all */
    {
        g_phb_mass_op_index = 0;
        g_phb_mass_op_count = 0;

        g_phb_cntx.processing = TRUE;

        g_phb_cntx.copy_all = TRUE; /* copy all flag for distinguish copy all or delete all if sim refresh */

        mmi_phb_show_mass_processing(STR_GLOBAL_COPYING, IMG_COPIED);
        DeleteNScrId(SCR_COPY_ALL_MENU);
    #ifdef __MMI_PHB_USIM_FIELD__
        if (g_phb_cntx.is_usim && g_phb_cntx.selected_storage == MMI_NVRAM)
        {
            mmi_phb_op_copy_all_to_usim_one_after_one_req();
        }
        else
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
            mmi_phb_op_copy_all_one_after_one_req(g_phb_cntx.selected_storage);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_all_one_after_one_req
 * DESCRIPTION
 *  Copy all one entry after one.
 * PARAMETERS
 *  from_storage        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_all_one_after_one_req(U8 from_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_all_one_after_one_req.>\n",
                         __FILE__, __LINE__);

    if (from_storage == MMI_SIM)
    {
        while ((g_phb_name_index[g_phb_mass_op_index] < MAX_PB_PHONE_ENTRIES
        #ifdef __MMI_DUAL_SIM_MASTER__
            || g_phb_name_index[g_phb_mass_op_index] >= (MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES)
        #endif
            ) && (g_phb_mass_op_index < PhoneBookEntryCount))   /* Not in SIM */
        {
            g_phb_mass_op_index++;
        }
    }
    else
    {
        while ((g_phb_name_index[g_phb_mass_op_index] >= MAX_PB_PHONE_ENTRIES) && (g_phb_mass_op_index < PhoneBookEntryCount))  /* Not in NVRAM */
        {
            g_phb_mass_op_index++;
        }
    }

    if (g_phb_mass_op_index >= PhoneBookEntryCount)
    {
        mmi_phb_op_copy_all_done();
        return;
    }

    store_index = g_phb_name_index[g_phb_mass_op_index];

#if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
    mmi_phb_util_make_pinyin_cache(store_index);
#endif 

    myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));

    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.storage = (from_storage == MMI_SIM) ? MMI_NVRAM : MMI_SIM;
    myMsgPtr->list.index = 0xFFFF;
    myMsgPtr->list.record_index = 0xFFFF;

    mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_phb_op_copy_all_one_after_one_rsp, PRT_PHB_SET_ENTRY_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_all_one_after_one_rsp
 * DESCRIPTION
 *  copy all one entry set response.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_all_one_after_one_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    
    S16 pError;
#endif    
    U8 copy_from, copy_to = 0;
    U16 store_index;
    U32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_all_one_after_one_rsp.>\n",
                         __FILE__, __LINE__);

    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        if (localPtr->list[0].storage == MMI_SIM)
        {
            g_phb_cntx.sim_used++;
            store_index = localPtr->list[0].record_index + MAX_PB_PHONE_ENTRIES - 1;    /* Storage Location in array. */
            copy_to = MMI_SIM;
            copy_from = MMI_NVRAM;
        }
        else
        {
            g_phb_cntx.phone_used++;
            store_index = localPtr->list[0].record_index - 1;   /* Storage Location in array. */
            copy_to = MMI_NVRAM;
            copy_from = MMI_SIM;
            #ifdef __SYNCML_SUPPORT__
                mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_ADD, store_index);
            #endif
        }

        if (copy_to == MMI_NVRAM)
        {
            /* Clear Optional Field */
        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        #ifdef __MMI_PHB_USIM_FIELD__
            U16 origin_index = g_phb_name_index[g_phb_mass_op_index];

            mmi_phb_op_set_option_data_by_usim_index(origin_index, &PhoneBookOptionalFields);
        #else /* __MMI_PHB_USIM_FIELD__ */ 
            memset(&PhoneBookOptionalFields, 0, sizeof(PhoneBookOptionalFields));
        #endif /* __MMI_PHB_USIM_FIELD__ */ 
            WriteRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (store_index + 1),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
            /* Clear Optional Id */
            mmi_phb_clear_optional_ids(store_index);

            /* Clear video field. */
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_delete_by_index(store_index);
        #endif 
            /* Clear birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            mmi_phb_bday_delete_field(store_index);
        #endif 
        #if defined(__MMI_PHB_INFO_FIELD__)
            mmi_phb_info_delete_field(store_index);
        #endif 
        }
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        mmi_phb_copy_optional_ids(store_index, g_phb_name_index[g_phb_mass_op_index]);

        if (copy_to == MMI_SIM)
        {
            mmi_phb_clear_optional_ids_for_sim(store_index);
        }
    #endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 

        /* Populate Number Field */
        temp = mmi_phb_util_convert_number_to_int(localPtr->list[0].tel.number);
        if (temp < INVALID_NUMBER)
        {
            LookUpTable[g_phb_cntx.lookup_table_count].store_index = store_index;
            LookUpTable[g_phb_cntx.lookup_table_count++].number = temp;
        }

        /* Add result to Phonebook Storage */
        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list[0], store_index);

        /* Update field flag */
    #ifdef __MMI_PHB_USIM_FIELD__
        if (g_phb_cntx.is_usim)
        {
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                (S8*) PhoneBookOptionalFields.homeNumber,
                (S8*) PhoneBookOptionalFields.officeNumber,
                (S8*) PhoneBookOptionalFields.faxNumber,
                (S8*) PhoneBookOptionalFields.emailAddress,
                TRUE);
            mmi_phb_op_increase_lookup_table(
                store_index,
                NULL,
                (S8*) PhoneBookOptionalFields.faxNumber,
                (S8*) PhoneBookOptionalFields.homeNumber,
                (S8*) PhoneBookOptionalFields.officeNumber);
        }
        else
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                TRUE);

        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }
    #if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 
        /* Append new entry in the end of sorted list. Sorting when copy all done. */
        g_phb_name_index[PhoneBookEntryCount] = store_index;
        PhoneBookEntryCount++;
        g_phb_mass_op_count++;

        /* Insert email to email mapping table, not like name field, it should sort here. */
    #if defined(__MMI_PHB_EMAIL_SORT__)     /* USIM won't go this way */
        if ((copy_to == MMI_NVRAM) && (g_phb_email_sorted == 1))
        {
            mmi_phb_sort_email_insert_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

        if (g_phb_mass_op_abort)
        {
            g_phb_mass_op_success = FALSE;
            mmi_phb_op_copy_all_done();
        }
        else
        {
            if ((copy_to == MMI_SIM && g_phb_mass_op_count < g_phb_cntx.phone_used) ||
                (copy_to == MMI_NVRAM && g_phb_mass_op_count < g_phb_cntx.sim_used))
            {
                ++g_phb_mass_op_index;
                mmi_phb_op_copy_all_one_after_one_req(copy_from);
            }
            else
            {
                mmi_phb_op_copy_all_done();
            }
        }
    }
    else
    {
        g_phb_mass_op_success = FALSE;
        copy_from = (g_phb_name_index[g_phb_mass_op_index] >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;

        /* Not copy fail due to capacity full. */
        if ((localPtr->result.cause != MMI_PHB_CAUSE_CAPACITY_EXCEEDED) &&
            ((copy_from == MMI_NVRAM && g_phb_mass_op_count < g_phb_cntx.phone_used) ||
             (copy_from == MMI_SIM && g_phb_mass_op_count < g_phb_cntx.sim_used)))
        {
            g_phb_mass_op_index++;
            mmi_phb_op_copy_all_one_after_one_req(copy_from);
        }
        else
        {
            mmi_phb_op_copy_all_done();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_all_done
 * DESCRIPTION
 *  Display copy result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_all_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 outBuf[100], count[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.processing = FALSE;

    g_phb_cntx.copy_all = FALSE;

    TurnOnBacklight(1); /* Turn On Back Light When done */
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);

    /* Sort name index */
    mmi_phb_sort_build_name_index();

    /* Sort Number index */
    mmi_phb_lookup_table_sort();
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    if (g_phb_mass_op_success)
    {
        DisplayPopup((PU8) GetString(STR_ID_PHB_COPIED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    }
//mark 0115
/*
    else if (gSecuritySetupContext.FdlStatus)
    {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        g_phb_mass_op_success = TRUE;
    }*/
    else    /* !g_phb_mass_op_success */
    {
        g_phb_mass_op_success = TRUE;
        sprintf(count, "%d ", g_phb_mass_op_count);
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
    }

    /* Solve Copying Screen Hang Problem */
    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);

    /* add central command for vrsi. */
#if defined(__MMI_VRSI__)
    mmi_vrsi_init_central_abort();
    /* mmi_vrsi_init_central_add_all(); */
#endif /* defined(__MMI_VRSI__) */ 
}

#define MMI_PHB_OP_DELETE_ALL
/*----------------------------------------------  Begin of PhoneBook Delete ALL -----------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_delete_all
 * DESCRIPTION
 *  Highlight handler for "Delete All" in PHb main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_delete_all.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_phb_entry_delete_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_delete_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_delete_all_from_sim
 * DESCRIPTION
 *  Highlight handler for "From SIM" in Delete All menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_delete_all_from_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.selected_storage = MMI_SIM;

    if (g_phb_cntx.sim_used || gSecuritySetupContext.FdlStatus)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_pre_entry_delete_all_confirm, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_pre_entry_delete_all_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifndef __MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #endif /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)*/ 
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_delete_all_from_phone
 * DESCRIPTION
 *  Highlight handler for "From Phone" in Delete All menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_delete_all_from_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.selected_storage = MMI_NVRAM;

    if (g_phb_cntx.phone_used)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_pre_entry_delete_all_confirm, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_pre_entry_delete_all_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifndef __MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #endif /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__) */ 
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_delete_all_from_sim
 * DESCRIPTION
 *  Hint handler for "From SIM" in Delete All menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_delete_all_from_sim(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 simStatus[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_sim(simStatus);
    mmi_ucs2cpy((S8*) hintData[index], simStatus);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_delete_all_from_phone
 * DESCRIPTION
 *  Hint handler for "From Phone" in Delete All menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_delete_all_from_phone(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 phoneStatus[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_phone(phoneStatus);
    mmi_ucs2cpy((S8*) hintData[index], phoneStatus);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_delete_all_one_by_one
 * DESCRIPTION
 *  Highlight handler for "One By One" in Delete All menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_delete_all_one_by_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_phb_list_pre_delete_one_by_one, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_list_pre_delete_one_by_one, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_all
 * DESCRIPTION
 *  Draws the Delete All menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
#ifdef __MMI_DUAL_SIM_MASTER__
    U8 hilight_SlaveSIM;
    U16 nStrItemList[4];
    U16 nImgIltemList[4];
    U8 *nHintList[4];
#else /* __MMI_DUAL_SIM_MASTER__ */
    U16 nStrItemList[3];
    U16 nImgIltemList[3];
    U8 *nHintList[3];
#endif /* __MMI_DUAL_SIM_MASTER__ */
    U16 nNumofItem;
    U8 hilight_sim, highlight_phone;
    U8 hilitedStorage = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif/* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_entry_not_ready(STR_ID_PHB_PROCESSING_USIM);
    }
#endif /* __MMI_PHB_USIM_FIELD__ */
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (PhoneBookEntryCount)
    {
        EntryNewScreen(SCR_DELETE_ALL_MENU, mmi_phb_exit_delete_all, mmi_phb_entry_delete_all, NULL);    

        mmi_frm_unhide_menu_item(MITEM_PBOOK_DELETE_ALL_SIM);
    #ifdef __MMI_DUAL_SIM_MASTER__        
        mmi_frm_unhide_menu_item(MENU_MTPNP_PB_DELALL_SIM2);
    #endif

        if (!mmi_bootup_is_sim_valid())
        {
            mmi_frm_hide_menu_item(MITEM_PBOOK_DELETE_ALL_SIM);        
        }

    #ifdef __MMI_DUAL_SIM_MASTER__
        if (!mmi_bootup_is_sim2_valid())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_PB_DELALL_SIM2);        
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */

        hilight_sim = GetIndexOfStringId_Ext(MITEM103_PBOOK_DELETE_ALL, MITEM_PBOOK_DELETE_ALL_SIM);
        highlight_phone = GetIndexOfStringId_Ext(MITEM103_PBOOK_DELETE_ALL, MITEM_PBOOK_DELETE_ALL_PHONE);
    #ifdef __MMI_DUAL_SIM_MASTER__
        hilight_SlaveSIM = GetIndexOfStringId_Ext(MITEM103_PBOOK_DELETE_ALL, MENU_MTPNP_PB_DELALL_SIM2);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    
        if (mmi_bootup_is_sim_valid())
        {
            if (g_phb_cntx.prefer_storage == MMI_SIM)
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                hilitedStorage = hilight_sim;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                if (g_phb_cntx.sim_used > 0 || g_phb_cntx.phone_used == 0)
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
            if (g_phb_cntx.phone_used > 0 || g_phb_cntx.sim_used == 0)
            {
                hilitedStorage = highlight_phone;
            }
            else
            {
                hilitedStorage = hilight_sim;
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        }

        guiBuffer = GetCurrGuiBuffer(SCR_DELETE_ALL_MENU);
        nNumofItem = GetNumOfChild_Ext(MITEM103_PBOOK_DELETE_ALL);
        GetSequenceStringIds_Ext(MITEM103_PBOOK_DELETE_ALL, nStrItemList);
        GetSequenceImageIds_Ext(MITEM103_PBOOK_DELETE_ALL, nImgIltemList);
        SetParentHandler(MITEM103_PBOOK_DELETE_ALL);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        ConstructHintsList(MITEM103_PBOOK_DELETE_ALL, nHintList);
        ShowCategory52Screen(
            STR_GLOBAL_DELETE,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            nImgIltemList,
            nHintList,
            0,
            hilitedStorage,
            guiBuffer);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_delete_all
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_delete_all()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_DELETE_ALL_MENU;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_delete_all_confirm
 * DESCRIPTION
 *  check before delete all confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_pre_entry_delete_all_confirm(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_phb_cntx.selected_storage == MMI_SIM && gSecuritySetupContext.FdlStatus)
#ifdef __MMI_DUAL_SIM_MASTER__
        || (g_phb_cntx.selected_storage == MMI_SIM2 && MTPNP_AD_FDN_GetStatus())
#endif
        )
    {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
    #if defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)
        mmi_phb_entry_delete_all_phone_lock();
    #else /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__) */ 
        mmi_phb_entry_delete_all_confirm();
    #endif /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)*/  
    }
}


#if defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_delete_all_phone_lock
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_delete_all_phone_lock()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_delete_all_phone_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_DELETE_ALL_CHECK_PHONE_LOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_all_phone_lock
 * DESCRIPTION
 *  check phone lock before delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_delete_all_phone_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_DELETE_ALL_CHECK_PHONE_LOCK,
        mmi_phb_exit_delete_all_phone_lock,
        mmi_phb_entry_delete_all_phone_lock,
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DELETE_ALL_CHECK_PHONE_LOCK);

    if (guiBuffer == NULL)
    {
        memset(gPhonePassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_RESTORE_PHONE,
        INPUT_TYPE_NUMERIC_PASSWORD,
        gPhonePassword,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_phb_delete_all_verify_phone_lock, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_delete_all_verify_phone_lock, KEY_POUND, KEY_EVENT_UP);

    /* micha0606 */
    gSecuritySetupContext.PasswdLenCheckCallBack = mmi_phb_delete_all_verify_phone_lock;
    if (mmi_ucs2strlen((S8*) gPhonePassword) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_all_verify_phone_lock
 * DESCRIPTION
 *  Call security function to check phone lock. Also provide call back function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_delete_all_verify_phone_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempBuffer[(MAX_SIM_SETTING_PASSWD_LEN + 1)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
    SECSETVerifyPINReq(MMI_SETTING_TYPE_PHONELOCK, gPhonePassword, tempBuffer, mmi_phb_op_delete_all_pre_req);
}

#else /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_all_confirm
 * DESCRIPTION
 *  Confirms before deleting all entries from the selected storage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_delete_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.selected_storage == MMI_NVRAM)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_DELETEALL_QUERY_PHONE_MSG),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (g_phb_cntx.selected_storage == MMI_SIM2)
    {
        DisplayConfirm(STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO, 
            IMG_GLOBAL_NO,
            get_string(STRING_MTPNP_QUERY_DELETEALL_CARD2), 
            IMG_GLOBAL_QUESTION, 
            WARNING_TONE); 
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_DELETEALL_QUERY_SIM_MSG),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }

    SetLeftSoftkeyFunction(mmi_phb_op_delete_all_pre_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
#endif /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_all_pre_req
 * DESCRIPTION
 *  ();
 *  pre check before delete all.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_all_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_phb_cntx.selected_storage == MMI_SIM2)
    {
        MTPNP_PFAL_ADN_DelAllPreReq();
    }
    else
#endif
    {
        g_phb_mass_op_index = 0;

        g_phb_cntx.processing = TRUE;

        g_phb_cntx.copy_all = FALSE;

        g_phb_mass_op_abort = FALSE;
        g_phb_mass_op_count = 0;
        g_phb_mass_op_lookup_count = 0;

        mmi_phb_show_mass_processing(STR_GLOBAL_DELETING, IMG_GLOBAL_DELETED);
        DeleteNScrId(SCR_DELETE_ALL_MENU);

        mmi_phb_op_delete_all_one_after_one_req(g_phb_cntx.selected_storage);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_all_one_after_one_req
 * DESCRIPTION
 *  delete all one entry after one.
 * PARAMETERS
 *  delete_storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_all_one_after_one_req(U8 delete_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_delete_all_one_after_one_req.>\n",
                         __FILE__, __LINE__);

    if (((delete_storage == MMI_SIM) && (g_phb_cntx.sim_used == 0)) || ((delete_storage == MMI_NVRAM) && (g_phb_cntx.phone_used == 0)))
    {
        mmi_phb_op_delete_all_done();
        return;
    }
    if (delete_storage == MMI_SIM)
#ifdef __MMI_DUAL_SIM_MASTER__
        while((g_phb_name_index[g_phb_mass_op_index] < MAX_PB_PHONE_ENTRIES) ||(g_phb_name_index[g_phb_mass_op_index] >= (MAX_PB_SIM_ENTRIES+MAX_PB_PHONE_ENTRIES)))/*Not in SIM*/
#else /* __MMI_DUAL_SIM_MASTER__ */
        while (g_phb_name_index[g_phb_mass_op_index] < MAX_PB_PHONE_ENTRIES)    /* Not in SIM */
#endif /* __MMI_DUAL_SIM_MASTER__ */
        {
            g_phb_mass_op_index++;
        }
    else
        while (g_phb_name_index[g_phb_mass_op_index] >= MAX_PB_PHONE_ENTRIES)   /* Not in NVRAM */
        {
            g_phb_mass_op_index++;
        }

    store_index = g_phb_name_index[g_phb_mass_op_index];

    myMsgPtr = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));

    myMsgPtr->storage = delete_storage;
    myMsgPtr->del_all = MMI_FALSE;
    myMsgPtr->no_data = 1;
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    myMsgPtr->index = (delete_storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_delete_all_one_after_one_rsp, PRT_PHB_DEL_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
    DeleteNScrId(SCR_DELETE_ALL_MENU);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_all_one_after_one_rsp
 * DESCRIPTION
 *  response message after delete one entry.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_all_one_after_one_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_RSP_STRUCT *localPtr;
    U16 store_index;
    U16 record_index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT*) info;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_delete_all_one_after_one_rsp.>\n",
                         __FILE__, __LINE__);

    if (localPtr->result.flag == 0 /* OK */ )
    {
        store_index = g_phb_name_index[g_phb_mass_op_index];
        storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;
        record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

        g_phb_mass_op_count++;

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_PHONEBOOK, NULL, NULL);

        if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
        {
            g_phb_cntx.sim_used--;
        #if defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(store_index);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__) */ 
        }
        else
        {
            g_phb_cntx.phone_used--;

            /* Clear birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_BIRTHDAY_REMINDER__)
            mmi_phb_bday_delete_field(store_index);
        #endif 
            /* Remove email entry from email sort mapping table */
        #if defined(__MMI_PHB_EMAIL_SORT__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(store_index);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_DELETE, store_index);
        #endif
        }

        /* Remove lookup table entry, and sort result when delete all done. */
        g_phb_mass_op_lookup_count += mmi_phb_op_clear_lookup_table_by_index(store_index);

    #if defined(__MMI_VRSD_DIAL__)
        /* remove voice dial tag if exists. */
        mmi_vrsddial_delete_tag_by_store_index(store_index);
    #endif /* defined(__MMI_VRSD_DIAL__) */ 

        /* clear phonebook entry and remove from index */
        mmi_phb_op_delete_update_index(store_index);

        if (g_phb_mass_op_abort)
        {
            g_phb_mass_op_success = FALSE;
            mmi_phb_op_delete_all_done();
        }
        else
        {
            if ((storage == MMI_SIM && g_phb_cntx.sim_used > 0) || (storage == MMI_NVRAM && g_phb_cntx.phone_used > 0))
            {
                /* g_phb_mass_op_index++; */
                mmi_phb_op_delete_all_one_after_one_req(storage);
            }
            else
            {
                mmi_phb_op_delete_all_done();
            }
        }
    }
    else
    {
        g_phb_mass_op_success = FALSE;
        mmi_phb_op_delete_all_done();

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_all_done
 * DESCRIPTION
 *  delete all done. displays result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_all_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 outBuf[100], count[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.processing = FALSE;
    TurnOnBacklight(1); /* Turn On Back Light When done */
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    /* Sort lookup table */
    if (g_phb_mass_op_lookup_count)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= g_phb_mass_op_lookup_count;
    }

    /* Clear up optional id field */
    if (g_phb_cntx.selected_storage == MMI_NVRAM)
    {
        mmi_phb_op_delete_all_update_optioal_id();
    }

    /* No need to clear video id, because it will reset when set new entry */

    /* Display result */
    if (g_phb_mass_op_success)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    }
    else if (!g_phb_mass_op_success)
    {
        g_phb_mass_op_success = TRUE;
        sprintf(count, "%d ", g_phb_mass_op_count);
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
    }

    /* Solve Copying Screen Hang Problem */
    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);

    /* Re-add all central command for vrsi. */
#if defined(__MMI_VRSI__)
    mmi_vrsi_init_central_abort();

    /* Also remove SD tag if entry is deleted. */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_ndial_central_update_sd_mapping();
#endif 

    /* mmi_vrsi_init_central_add_all(); */
#endif /* defined(__MMI_VRSI__) */ 
}
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */


#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_multi_select_list_get_item
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
static pBOOL mmi_phb_generic_multi_select_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask) 
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
    while (i < item_index)
    {
        store_index = g_phb_name_index[inner_index];
		
        if (PhoneBook[store_index].field & phb_list_view_type)
        {
            i++;  
        }	
        inner_index++;
    }

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
 *  mmi_phb_generic_multi_select_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_phb_generic_multi_select_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S8 temp_number[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    S32 i = -1;
    S32 inner_index = 0;
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
    PHB_OPTIONAL_FIELDS_STRUCT tempPhoneBookOptionalFields;
    S8 temp_email[(MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH];
    S16 pError;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < item_index)
    {
        store_index = g_phb_name_index[inner_index];
		
        if (PhoneBook[store_index].field & phb_list_view_type)
        {
            i++;  
        }
        inner_index++;
    }

    if (phb_list_view_type & MMI_PHB_ENTRY_FIELD_ALL_NUMBER)
    {
        mmi_phb_convert_get_ucs2_number((S8*) temp_number, store_index);

        if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name) && mmi_ucs2strlen((S8*) temp_number))
        {	
            mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_number);
        }
        else
        {
            return 0;
        }
    }
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
    else if (phb_list_view_type & MMI_PHB_ENTRY_FIELD_EMAIL)
    {
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&tempPhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
        mmi_asc_to_ucs2(temp_email, (PS8) tempPhoneBookOptionalFields.emailAddress);
        if (mmi_ucs2strlen((S8*) temp_email))
        {	
            mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_email);
        }
        else
        {
            return 0;
        }
    }
#endif
    else
    {
        return 0;
    }

    return 1;   /* One hint data only, can be more hints. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_multi_select_list_done
 * DESCRIPTION
 *  set check box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_generic_multi_select_list_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_generic_multi_select_populate_selected_list();
    phb_generic_multi_select_list_call_back(g_phb_multi_operation_count, g_phb_cntx.list_filter);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_multi_select_go_back_history
 * DESCRIPTION
 *  go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_generic_multi_select_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_free_filter();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_generic_multi_select_list
 * DESCRIPTION
 *  set check box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_generic_multi_select_list(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 FilterEntryCount = 0;
    U16 store_index;
    U8 *guiBuffer;
    U8 *titleHintString;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_generic_multi_select_list.>\n", __FILE__,
                         __LINE__);

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
    else
#endif /* __SYNCML_SUPPORT__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
    {
        /* Build list according to filter */
        for (i = 0; i < PhoneBookEntryCount; i++)
        {
            store_index = g_phb_name_index[i];

            if (PhoneBook[store_index].field & phb_list_view_type)
            {
                FilterEntryCount++;
            }
        }
        PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "mmi_phb_entry_generic_multi_select_list[] FilterEntryCount = %d\n", FilterEntryCount);
        if (FilterEntryCount)
        {
            g_phb_cntx.highlight_entry = 0;
            
            EntryNewScreen(SCR_ID_PHB_GENERIC_MULTI_SELECT, mmi_phb_exit_generic_multi_select_list, mmi_phb_entry_generic_multi_select_list, MMI_FULL_SCREEN);
            guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_GENERIC_MULTI_SELECT);
    
            RegisterHighlightHandler(mmi_phb_multi_select_highlight_hdlr);

            /* First Time enter or any entry has been modified.. */
            if (guiBuffer == NULL)
            {   
                for (i = 0; i < MAX_PB_ENTRIES; i ++)
                {
                    g_phb_multi_select_bitmask[i] = 0;
                }
                g_phb_multi_operation_count = 0;
                mmi_phb_list_allocate_filter();               
            }
            
        #ifdef __MMI_TOUCH_SCREEN__
            titleHintString = (U8*) GetString(STR_ID_PHB_MULTI_OP_TOUCH_BOX);
        #else /* def __MMI_TOUCH_SCREEN__ */
            titleHintString = (U8*) GetString(STR_ID_PHB_MULTI_OP_PRESS_STAR);
        #endif /* def __MMI_TOUCH_SCREEN__ */

            ShowCategory384Screen(
                (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
                (PU8)GetImage(IMG_SCR_PBOOK_CAPTION),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                titleHintString,
                FilterEntryCount,
                mmi_phb_generic_multi_select_list_get_item,
                mmi_phb_generic_multi_select_list_get_hint,
                mmi_phb_multi_select_get_state,
                mmi_phb_multi_select_set_state,
                0,
                guiBuffer);

        #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_list_item_selected_callback_all(UI_dummy_function);
        #endif

            SetLeftSoftkeyFunction(mmi_phb_generic_multi_select_list_done, KEY_EVENT_UP);
            SetKeyHandler(mmi_phb_generic_multi_select_list_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(mmi_phb_generic_multi_select_go_back_history, KEY_EVENT_UP);
            SetKeyHandler(mmi_phb_generic_multi_select_go_back_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_phb_multi_select_check, KEY_ENTER, KEY_EVENT_UP);     
            SetKeyHandler(mmi_phb_multi_select_check, KEY_STAR, KEY_EVENT_UP);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PHB_NO_ENTRY_TO_SELECT),
                IMG_GLOBAL_EMPTY,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                EMPTY_LIST_TONE);
        }
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_generic_multi_select_list
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_generic_multi_select_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_generic_multi_select_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_GENERIC_MULTI_SELECT;
}
#endif /* defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_refresh_phb_list
 * DESCRIPTION
 *  Refresh phonebook list screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_refresh_phb_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = GetExitScrnID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scr_id == SCR_PBOOK_LIST || scr_id == SCR_ID_PHB_QUICK_SEARCH_LIST)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_update_confirm
 * DESCRIPTION
 *  After MMI update done, send back confirm message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ind_update_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_at_general_res_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    myMsgPtr->result = TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_AT_GENERAL_RES_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_update
 * DESCRIPTION
 *  This function handles the update indication  from stack,  after the phonebook has been
 *  updated through AT commands
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ind_update(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_UPDATE_IND_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_ind_update.>\n", __FILE__, __LINE__);
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;
    switch (localPtr->action)
    {
        case MMI_PHB_UPDATE:
            if ((g_phb_cntx.sim_used == localPtr->sim_used) && (g_phb_cntx.phone_used == localPtr->nvram_used))
            {
                mmi_phb_at_cmd_edit(info);
            }
            else
            {
                mmi_phb_at_cmd_add(info);
            }
            break;
        case MMI_PHB_DELETE:
            mmi_phb_at_cmd_delete(info);
            break;
        case MMI_PHB_DELETE_ALL:
            /* currently, AT didn't have DELETE ALL cmd */
            mmi_phb_at_cmd_delete_all(info);
            break;
        case MMI_WRITE_LND:
        #if (MAX_PHB_LN_ENTRY > 20)
            if (chis_p->nDialedCalls < TOT_SIZE_OF_DIALED_LIST)
            {
                chis_p->nDialedCalls++;
            }
        #else /* (MAX_PHB_LN_ENTRY > 20) */ 
            chis_p->nDialedCalls = (U8) localPtr->no_list;
        #endif /* (MAX_PHB_LN_ENTRY > 20) */ 
            break;
        case MMI_WRITE_LNM:
        #if (MAX_PHB_LN_ENTRY > 20)
            if (chis_p->nMissedCalls < TOT_SIZE_OF_DIALED_LIST)
            {
                chis_p->nMissedCalls++;
            }
        #else /* (MAX_PHB_LN_ENTRY > 20) */ 
            chis_p->nMissedCalls = (U8) localPtr->no_list;
        #endif /* (MAX_PHB_LN_ENTRY > 20) */ 
            break;
        case MMI_WRITE_LNR:
        #if (MAX_PHB_LN_ENTRY > 20)
            if (chis_p->nRecvdCalls < TOT_SIZE_OF_DIALED_LIST)
            {
                chis_p->nRecvdCalls++;
            }
        #else /* (MAX_PHB_LN_ENTRY > 20) */ 
            chis_p->nRecvdCalls = (U8) localPtr->no_list;
        #endif /* (MAX_PHB_LN_ENTRY > 20) */ 
            break;
        case MMI_DELETE_LND:
            if (localPtr->old_index < chis_p->nDialedCalls)
            {
                chis_p->nDialedCalls--;
            }
            break;
        case MMI_DELETE_LNM:
            if (localPtr->old_index < chis_p->nMissedCalls)
            {
                chis_p->nMissedCalls--;
            }
            break;
        case MMI_DELETE_LNR:
            if (localPtr->old_index < chis_p->nRecvdCalls)
            {
                chis_p->nRecvdCalls--;
            }
            break;
    }

    mmi_phb_ind_update_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_at_cmd_edit
 * DESCRIPTION
 *  Handles the phonebook update indication after an entry is edited through AT command
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_at_cmd_edit(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_UPDATE_IND_STRUCT *localPtr;
    U16 deletedCnt = 0;
    U8 flag = 0;
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    
    S16 pError;
#endif    
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;

    if (localPtr->list[0].storage == MMI_SIM)
    {
        store_index = localPtr->list[0].record_index + MAX_PB_PHONE_ENTRIES - 1;        /* Storage Location in array. */
    }
    else
    {
        store_index = localPtr->list[0].record_index - 1;   /* Storage Location in array. */
    }

    /* Clear lookup table first, add later if exists. */
    deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

    if (localPtr->list[0].storage == MMI_NVRAM)
    {
        /* Clear Optional Field */
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        memset(&PhoneBookOptionalFields, 0, sizeof(PhoneBookOptionalFields));
        WriteRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
        /* Clear birthday field */
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        mmi_phb_bday_delete_field(store_index);
    #endif 
    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_phb_info_delete_field(store_index);
    #endif 
    #ifdef __SYNCML_SUPPORT__
        mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_MODIFY, store_index);
    #endif
    }

    flag = mmi_phb_op_increase_lookup_table(store_index, (S8*) localPtr->list[0].tel.number, NULL, NULL, NULL);

    if (flag || deletedCnt)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }

    PhoneBook[store_index].alpha_id.name_length = localPtr->list[0].alpha_id.name_length;
    PhoneBook[store_index].alpha_id.name_dcs = localPtr->list[0].alpha_id.name_dcs;
    InputboxConvertGSMToDeviceEncoding(
        localPtr->list[0].alpha_id.name,
        PhoneBook[store_index].alpha_id.name,
        localPtr->list[0].alpha_id.name_length,
        (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
        localPtr->list[0].alpha_id.name_dcs,
        0,
        1);

    PhoneBook[store_index].tel.type = localPtr->list[0].tel.type;
    PhoneBook[store_index].tel.length = localPtr->list[0].tel.length;
    mmi_phb_convert_to_bcd(
        PhoneBook[store_index].tel.number,
        localPtr->list[0].tel.number,
        (MAX_PB_NUMBER_LENGTH + 1) / 2);

    /* Update is column exists flag. */
    PhoneBook[store_index].field = 0;
    if (localPtr->list[0].alpha_id.name_length)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }
    if (strlen((S8*) localPtr->list[0].tel.number))
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
    }

    /* Update Pinyin Cache for sort */
#if defined(__MMI_PHB_PINYIN_SORT__)
    mmi_phb_util_make_pinyin_cache(store_index);
#endif 

    /* Name sorting mapping table should Re-Sort HERE, and get the new highlight position!!! */
    mmi_phb_op_delete_update_index(store_index);
    mmi_phb_sort_insert_name_index(store_index);
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    /* Update email sorting mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_email_sorted == 1)
#else 
    if ((localPtr->list[0].storage == MMI_NVRAM) && (g_phb_email_sorted == 1))
#endif 
    {
        mmi_phb_sort_email_delete_index(store_index);
        mmi_phb_sort_email_insert_index(store_index);
    }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_at_cmd_add
 * DESCRIPTION
 *  Handles the phonebook update indication after an entry is added through AT command
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_at_cmd_add(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MSG_PHB_UPDATE_IND_STRUCT *localPtr;
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    
    S16 pError;
#endif    
    U16 store_index;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;

    store_index = mmi_phb_op_get_store_index_and_increase_counter(localPtr->list[0].storage, localPtr->list[0].record_index);

    if (localPtr->list[0].storage == MMI_NVRAM)
    {
        /* Clear Optional Field */
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        memset(&PhoneBookOptionalFields, 0, sizeof(PhoneBookOptionalFields));
        WriteRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
        /* Clear video field. */
    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        mmi_phb_video_delete_by_index(store_index);
    #endif 
        /* Clear birthday field */
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        mmi_phb_bday_delete_field(store_index);
    #endif 
    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_phb_info_delete_field(store_index);
    #endif 
    #ifdef __SYNCML_SUPPORT__
        mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_ADD, store_index);
    #endif
    }

#if !defined(__MMI_PHB_CALLERGROUP_IN_SIM__)    /* Associate caller group in SIM card entry */
    if (localPtr->list[0].storage == MMI_NVRAM)
#endif 
    {
        mmi_phb_clear_optional_ids(store_index);
    }

    flag = mmi_phb_op_increase_lookup_table(store_index, (S8*) localPtr->list[0].tel.number, NULL, NULL, NULL);
    if (flag)
    {
        mmi_phb_lookup_table_sort();
    }

    PhoneBook[store_index].alpha_id.name_length = localPtr->list[0].alpha_id.name_length;
    PhoneBook[store_index].alpha_id.name_dcs = localPtr->list[0].alpha_id.name_dcs;
    InputboxConvertGSMToDeviceEncoding(
        localPtr->list[0].alpha_id.name,
        PhoneBook[store_index].alpha_id.name,
        localPtr->list[0].alpha_id.name_length,
        (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
        localPtr->list[0].alpha_id.name_dcs,
        0,
        1);

    PhoneBook[store_index].tel.type = localPtr->list[0].tel.type;
    PhoneBook[store_index].tel.length = localPtr->list[0].tel.length;
    mmi_phb_convert_to_bcd(
        PhoneBook[store_index].tel.number,
        localPtr->list[0].tel.number,
        (MAX_PB_NUMBER_LENGTH + 1) / 2);

    /* Update is column exists flag. */
    PhoneBook[store_index].field = 0;
    if (localPtr->list[0].alpha_id.name_length)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }
    if (strlen((S8*) localPtr->list[0].tel.number))
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
    }

    /* Update Pinyin Cache for sort */
#if defined(__MMI_PHB_PINYIN_SORT__)
    mmi_phb_util_make_pinyin_cache(store_index);
#endif 

    /* Insert name to name mapping table. */
    mmi_phb_sort_insert_name_index(store_index);

    /* Insert email to email mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_email_sorted == 1)
#else 
    if ((localPtr->list[0].storage == MMI_NVRAM) && (g_phb_email_sorted == 1))
#endif 
        mmi_phb_sort_email_insert_index(store_index);
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_at_cmd_delete
 * DESCRIPTION
 *  Handles the phonebook update indication after an entry is deleted through AT command.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_at_cmd_delete(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_UPDATE_IND_STRUCT *localPtr;
    U16 deletedCnt = 0;
    U16 store_index;
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)    
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;

    if (localPtr->list[0].storage == MMI_SIM)
    {
        store_index = localPtr->list[0].record_index + MAX_PB_PHONE_ENTRIES - 1;        /* Storage Location in array. */
    }
    else    /* MMI_NVRAM */
    {
        store_index = localPtr->list[0].record_index - 1;
    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        /* Delete image file in file folder */
        mmi_phb_read_optional_ids(store_index);
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;

        if (opt_ids->pictureTagID == 1
        #ifdef __MMI_AVATAR__
            || opt_ids->pictureTagID == 2
        #endif
            )
        {
            mmi_phb_image_delete_by_index((U16) (store_index + 1));
        }
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        mmi_phb_video_delete_by_index(store_index); /* Clear video field. */
    #endif 
        /* Clear birthday field */
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_BIRTHDAY_REMINDER__)
        mmi_phb_bday_delete_field(store_index);
    #endif 

        /* Remove email entry from email sort mapping table */
    #if defined(__MMI_PHB_EMAIL_SORT__)
        if (g_phb_email_sorted == 1)
        {
            mmi_phb_sort_email_delete_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
    }

    if (mmi_phb_util_check_entry_exist(store_index))
    {
        if (localPtr->list[0].storage == MMI_SIM)
        {
            g_phb_cntx.sim_used--;
        }
        else    /* MMI_NVRAM */
        {
            g_phb_cntx.phone_used--;
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_DELETE, store_index);
        #endif
        }
    }

    /* Remove lookup table entry */
    deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

    if (deletedCnt)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }

    /* clear phonebook entry and remove from index */
    mmi_phb_op_delete_update_index(store_index);

    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;
    mmi_phb_refresh_phb_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_at_cmd_delete_all
 * DESCRIPTION
 *  Handles the phonebook update indication after an all the entries of one storage
 *  location is deleted through AT command
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_at_cmd_delete_all(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage;
    MSG_PHB_UPDATE_IND_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;

    if (localPtr->nvram_used == 0 && g_phb_cntx.phone_used != 0)
    {
        storage = MMI_NVRAM;
        mmi_phb_op_delete_all_update_optioal_id();
    }
    else
    {
        storage = MMI_SIM;
    }

    /* Clear all storage and clear up name index. */
    mmi_phb_op_delete_all_update_index(storage);
    mmi_phb_op_delete_all_update_lookup_table(storage);

    /* Remove email entry from email sort mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
    if ((storage == MMI_NVRAM) && (g_phb_email_sorted == 1))
    {
        mmi_phb_sort_email_delete_all_index();
    }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
    mmi_phb_refresh_phb_list();
}


#ifdef __MMI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_req_writer_v21_to_file
 * DESCRIPTION
 *  write select phonebook entry into vcard format into destination file.
 * PARAMETERS
 *  path            [IN]        Destination path
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_phb_vcard_req_writer_v21_to_file(S8 *path, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 number_buff[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    
    PHB_OPTIONAL_FIELDS_STRUCT phb_opt_fields;
    S16 pError;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
            (void*)&phb_opt_fields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_phb_info_read_data_to_buff(store_index);
    #endif
        return mmi_vcard_writer_v21_to_file(path, (S8*) PhoneBook[store_index].alpha_id.name, (S8*) number_buff,
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
                                            (S8*) phb_opt_fields.homeNumber,
                                            (S8*) phb_opt_fields.officeNumber,
                                            (S8*) phb_opt_fields.faxNumber,
                                            (S8*) phb_opt_fields.emailAddress, (S8*) phb_opt_fields.companyName,
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
    return mmi_vcard_writer_v21_to_file(
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
#endif /* __MMI_VCARD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_req_confirm
 * DESCRIPTION
 *  After MMI update done, send back confirm message.
 * PARAMETERS
 *  mode            [IN]        
 *  req_result      [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_vcard_req_confirm(U8 mode, BOOL req_result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_vcard_res_req_struct *myMsgPtr;
    MYQUEUE Message;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_eq_vcard_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_vcard_res_req_struct));
#ifdef __MMI_VCARD__
    if (mode == 1)  /* req_result value is FALSE at first */
    {
        if (mmi_phb_util_check_entry_exist(store_index))
        {
            S32 check_result = mmi_vobj_fs_check_folder();

            /* Create file path and folder. */
            if (check_result == FS_NO_ERROR)
            {
                mmi_phb_vcard_req_set_default_file((S8*) myMsgPtr->file_path);

                result = mmi_phb_vcard_req_writer_v21_to_file((S8*) myMsgPtr->file_path, store_index);
                if (result != VOBJ_ERR_NO_ERROR)
                {
                    FS_Delete((U16*) myMsgPtr->file_path);
                }
                else
                {
                    req_result = TRUE;  /* only this case is true */
                }
            }
        }
    }
#endif /* __MMI_VCARD__ */ 
    myMsgPtr->result = req_result;
    myMsgPtr->mode = mode;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_VCARD_RES_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}

#ifdef __MMI_VCARD__


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_clear_data_buffer
 * DESCRIPTION
 *  Clears buffers used for adding/editing entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_vcard_clear_data_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pbvCardHomeNumber, 0, ENCODING_LENGTH);
    memset(pbvCardCompanyName, 0, ENCODING_LENGTH);
    memset(pbvCardEmailAddress, 0, ENCODING_LENGTH);
    memset(pbvCardOfficeNumber, 0, ENCODING_LENGTH);
    memset(pbvCardFaxNumber, 0, ENCODING_LENGTH);

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    mmi_ucs2cpy(pbvCardYear, (S8*) MMI_PHB_BDAY_YEAR_STR);
    mmi_ucs2cpy(pbvCardMon, (S8*) MMI_PHB_BDAY_MON_STR);
    mmi_ucs2cpy(pbvCardDay, (S8*) MMI_PHB_BDAY_DAY_STR);
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_req_set_default_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_vcard_req_set_default_file(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ascii_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ascii_path = OslMalloc(25);
    /* VOBJ_FILE_PATH */
    sprintf(ascii_path, "%c:\\Received\\~vcard_r.vcf", MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2(path, ascii_path);
    OslMfree(ascii_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_reader_parse_line
 * DESCRIPTION
 *  Read one line to parse for each filed.
 * PARAMETERS
 *  fh      [IN]        file handle ready to read and parse.
 * RETURNS
 *  parse  error cause
 *****************************************************************************/
U8 mmi_phb_vcard_reader_parse_line(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inBuff[512]; /* same as VOBJ_READ_BUFF_LEN */
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
                return VCARD_PARSE_NO_ERROR;

            /* VERSION */
            case VCARD_FIELD_VERSION:
                if (!mmi_vcard_reader_check_version(inBuff))
                {
                    return VCARD_VERSION_ERROR;
                }
                break;

            case VCARD_FIELD_N:
                /* mmi_vcard_reader_retrive_name(inBuff); */
                break;

            case VCARD_FIELD_TEL:
                mmi_vcard_reader_retrive_number(inBuff, NULL, pbvCardHomeNumber, pbvCardOfficeNumber, pbvCardFaxNumber);
                break;

            case VCARD_FIELD_EMAIL:
                mmi_vcard_reader_retrive_email(inBuff, pbvCardEmailAddress);
                break;

            case VCARD_FIELD_ORG:
                mmi_vcard_reader_retrive_org(inBuff, pbvCardCompanyName);
                break;

        #ifdef __MMI_PHB_BIRTHDAY_FIELD__
            case VCARD_FIELD_BDAY:
                mmi_vcard_reader_retrive_bday(inBuff, pbvCardYear, pbvCardMon, pbvCardDay, FALSE);
                break;
        #endif /* __MMI_PHB_BIRTHDAY_FIELD__ */ 
        #ifdef __MMI_PHB_INFO_FIELD__
            case VCARD_FIELD_TITLE:
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
 *  mmi_phb_vcard_req_save_obj_to_phb
 * DESCRIPTION
 *  save parsed vcard to phonebook after parsing.
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_phb_vcard_req_save_obj_to_phb(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PHB_OPTIONAL_FIELDS_STRUCT phb_opt_fields;
    S16 pError;
    U8 temp_number[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U16 deletedCnt = 0;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
     if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else /* __MMI_DUAL_SIM_MASTER__ */
     if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        return FALSE;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        return FALSE;
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (store_index >= MAX_PB_PHONE_ENTRIES)   /* only nvram data. */
    {
        return FALSE;
    }
    else if ((!mmi_phb_op_check_valid_number(pbvCardHomeNumber) ||      /* Number format not correct */
              !mmi_phb_op_check_valid_number(pbvCardOfficeNumber) || !mmi_phb_op_check_valid_number(pbvCardFaxNumber)))
    {
        return FALSE;
    }

    mmi_phb_convert_to_digit(temp_number, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);

    /* Clear lookup table first, add later if exists. */
    deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

    mmi_ucs2_to_asc((PS8) phb_opt_fields.homeNumber, pbvCardHomeNumber);
    mmi_ucs2cpy((PS8) phb_opt_fields.companyName, pbvCardCompanyName);
    mmi_ucs2_to_asc((PS8) phb_opt_fields.emailAddress, pbvCardEmailAddress);
    mmi_ucs2_to_asc((PS8) phb_opt_fields.officeNumber, pbvCardOfficeNumber);
    mmi_ucs2_to_asc((PS8) phb_opt_fields.faxNumber, pbvCardFaxNumber);

    WriteRecord(
        NVRAM_EF_PHB_FIELDS_LID,
        (U16) (store_index + 1),
        (void*)&phb_opt_fields,
        OPTIONAL_FIELDS_RECORD_SIZE,
        &pError);

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    flag = mmi_phb_op_increase_lookup_table(
            store_index,
            NULL,
            (S8*) phb_opt_fields.faxNumber,
            (S8*) phb_opt_fields.homeNumber,
            (S8*) phb_opt_fields.officeNumber);
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

    flag += mmi_phb_op_increase_lookup_table(store_index, (S8*) temp_number, NULL, NULL, NULL);

    if (deletedCnt || flag)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }

    /* Update is column exists flag. */
#if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    mmi_phb_op_update_field_flag(store_index, (S8*) temp_number, NULL, NULL, NULL, NULL, FALSE);
#else /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
    mmi_phb_op_update_field_flag(
        store_index,
        (S8*) temp_number,
        (S8*) phb_opt_fields.homeNumber,
        (S8*) phb_opt_fields.officeNumber,
        (S8*) phb_opt_fields.faxNumber,
        (S8*) phb_opt_fields.emailAddress,
        TRUE);
#endif /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

    if (PhoneBook[store_index].alpha_id.name_length)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }

    /* Save birthday field */
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    mmi_phb_bday_update_field(store_index, (S8*) pbvCardYear, (S8*) pbvCardMon, (S8*) pbvCardDay);
#endif 

    /* Update email sorting mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_email_sorted == 1)
#else 
    if ((store_index < MAX_PB_PHONE_ENTRIES) && (g_phb_email_sorted == 1))
#endif 
    {
        mmi_phb_sort_email_delete_index(store_index);
        mmi_phb_sort_email_insert_index(store_index);
    }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_save_vcard_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]         
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_save_vcard_req(S8 *path, U16 index)
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
        mmi_phb_vcard_clear_data_buffer();  /* Clear all phonebook vcard temp buffer before parsing */
        error_code = mmi_phb_vcard_reader_parse_line(fh);
        FS_Close(fh);
    }
    else
    {
        error_code = MMI_PHB_VCARD_OPEN_FILE_ERROR;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_save_vcard_req. error_code: %d>\n",
                         __FILE__, __LINE__, error_code);

    if (error_code == VCARD_PARSE_NO_ERROR)
    {
        return mmi_phb_vcard_req_save_obj_to_phb(index);
    }
    else
    {
        return FALSE;
    }
}
#endif /* __MMI_VCARD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_req
 * DESCRIPTION
 *  This function handles the read indication through AT commands
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_vcard_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_vcard_req_ind_struct *localPtr;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_vcard_req.>\n", __FILE__, __LINE__);
    localPtr = (mmi_eq_vcard_req_ind_struct*) info;
    index = localPtr->index;
    ASSERT(index >= 1) index--; /* 1-based */

#ifdef __MMI_VCARD__
    if (localPtr->mode == 0 && mmi_phb_save_vcard_req((S8*) localPtr->file_path, index))
    {
        mmi_phb_vcard_req_confirm(localPtr->mode, TRUE, index);
    }
    else
    {
        mmi_phb_vcard_req_confirm(localPtr->mode, FALSE, index);
    }
#else /* __MMI_VCARD__ */ 
    mmi_phb_vcard_req_confirm(localPtr->mode, FALSE, index);
#endif /* __MMI_VCARD__ */ 
}


#define MMI_PHB_OPERATE_UTIL
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mass_processing_abort
 * DESCRIPTION
 *  abort function of processing screen. It will set up the abort flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mass_processing_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_MULTI_OPERATION__)
    U16 i;
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (Slave_CopyAll || Slave_g_phb_mass_delall)
    {
        Slave_g_phb_mass_op_abort = TRUE;
    }
    else
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        g_phb_mass_op_abort = TRUE;
    }
    mmi_phb_show_in_progress(STR_GLOBAL_CANCELLING, IMG_COPY_ALL_ABORTING);
#if defined(__MMI_PHB_MULTI_OPERATION__)
    for(i = 0; i < PhoneBookEntryCount; i++)
    {
        g_phb_multi_select_bitmask[i] = 0;
        g_phb_multi_operation_count = 0;
    }
    DeleteScreenIfPresent(SCR_ID_PHB_MULTI_OP_OPTION);
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_all_update_index
 * DESCRIPTION
 *  update name index after delete all.
 * PARAMETERS
 *  storage     [IN]        Storage location
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_all_update_index(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        if ((storage == MMI_SIM && g_phb_name_index[i] >= MAX_PB_PHONE_ENTRIES) ||
            (storage == MMI_NVRAM && g_phb_name_index[i] < MAX_PB_PHONE_ENTRIES))
        {
            g_phb_name_index[i] = 0xffff;
        }
    }

    pos = 0;
    while (pos < PhoneBookEntryCount)
    {
        if (g_phb_name_index[pos] == 0xffff)
        {
            for (i = pos; i < PhoneBookEntryCount; i++)
            {
                g_phb_name_index[i] = g_phb_name_index[i + 1];
            }

            PhoneBookEntryCount--;
        }
        pos++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_all_update_lookup_table
 * DESCRIPTION
 *  clear lookup table
 * PARAMETERS
 *  storage     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_all_update_lookup_table(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 k;
    U16 deletedCnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Remove lookup table entry */
    for (k = 0; k < g_phb_cntx.lookup_table_count; ++k)
    {
        if ((storage == MMI_SIM && LookUpTable[k].store_index >= MAX_PB_PHONE_ENTRIES) ||
            (storage == MMI_NVRAM && LookUpTable[k].store_index < MAX_PB_PHONE_ENTRIES))
        {

            LookUpTable[k].number = INVALID_NUMBER;
            ++deletedCnt;
        }
    }
    if (deletedCnt)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_all_update_optioal_id
 * DESCRIPTION
 *  Update optional id on NVRAM after delete all.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_all_update_optioal_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    S16 pError;
    U8 optid_record, optid_index, current_record = 0;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PB_PHONE_ENTRIES; i++)
    {
        /* If entry still exist, do not clear. */
        for (j = 0; j < PhoneBookEntryCount; j++)
        {
            if (i == g_phb_name_index[j])
            {
                continue;
            }
        }
        /* Get optional IDs record. */
        optid_record = (i / OPTIONAL_IDS_RECORD_TOTAL) + 1;
        optid_index = i - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

        if (optid_record != current_record)
        {
            ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
            current_record = optid_record;
        }

        /* Clear image in file system */
    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        if (PhbOptIDs[optid_index].pictureTagID == 1
        #ifdef __MMI_AVATAR__
            || PhbOptIDs[optid_index].pictureTagID == 2
        #endif
            )
        {
            mmi_phb_image_delete_by_index((U16) (i + 1));
        }
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_update_optional_field
 * DESCRIPTION
 *  Saves optional fields of a Phone entry on NVRAM
 * PARAMETERS
 *  store_index     [IN]        
 *  storage         [IN]        
 *  type            [IN]  if type 0 is for Java PIM, don't need copy opt IDs.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_update_optional_field(U16 store_index, U8 storage, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 optid_record;
    U8 optid_index;

    /* U8 grpIndex; */
    PHB_OPTIONAL_IDS_STRUCT tempIDs;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     *  Update optional fields.
     */
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    if (storage == MMI_NVRAM)
    {
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.homeNumber, pbHomeNumber);
        mmi_ucs2cpy((PS8) PhoneBookOptionalFields.companyName, pbCompanyName);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.emailAddress, pbEmailAddress);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.officeNumber, pbOfficeNumber);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.faxNumber, pbFaxNumber);

        WriteRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
    }
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

    /*
     *  Update optional selection field (id), and caller group counter
     */
    /* Read out related optional id record */
    optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;
    ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    if (type == 0)
    {
        memcpy(&tempIDs, &PhbOptIDs[optid_index], sizeof(PHB_OPTIONAL_IDS_STRUCT));
    }
    else
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
    {
        /* assign user selected optional id */
    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        if (g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 1)
        {
            tempIDs.pictureTagID = 1;
        }
        else
    #ifdef __MMI_AVATAR__
        if (g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 2)
        {
            tempIDs.pictureTagID = 2;
        }
        else    
    #endif
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
            tempIDs.pictureTagID = g_phb_cntx.image_id_list[g_phb_cntx.selected_pic_index];

        tempIDs.callerGroupID = (U8) g_phb_cntx.selected_grp_index;
        tempIDs.ringToneID = g_phb_cntx.ring_tone_list[g_phb_cntx.selected_ring_index];

    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        if (storage == MMI_SIM)
        {
            tempIDs.pictureTagID = 0;
            tempIDs.ringToneID = 0;
        }
    #endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 
    }

    /* Update associate id and write it back */
    memcpy(&PhbOptIDs[optid_index], &tempIDs, sizeof(PHB_OPTIONAL_IDS_STRUCT));
    WriteRecord(NVRAM_EF_PHB_IDS_LID, optid_record, PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_read_optional_ids
 * DESCRIPTION
 *  read one optional id for one entry
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_read_optional_ids(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 optid_record;
    U8 optid_index;
    S16 pError;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

    ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    memcpy(g_phb_cntx.optional_ids, &PhbOptIDs[optid_index], sizeof(PHB_OPTIONAL_IDS_STRUCT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_clear_optional_ids
 * DESCRIPTION
 *  clear optional id field
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_clear_optional_ids(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 optid_record;
    U8 optid_index;
    S16 pError;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

    ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    memset(&PhbOptIDs[optid_index], 0, sizeof(PHB_OPTIONAL_IDS_STRUCT));
    WriteRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_clear_optional_ids_for_sim
 * DESCRIPTION
 *  clear optional id field
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
void mmi_phb_clear_optional_ids_for_sim(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 optid_record;
    U8 optid_index;
    S16 pError;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

    ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    /* Clear Picture ID and Ring Tone ID for SIM because SIM does not have these fields. */
    PhbOptIDs[optid_index].pictureTagID = 0;
    PhbOptIDs[optid_index].ringToneID = 0;

    WriteRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
}
#endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_copy_optional_ids
 * DESCRIPTION
 *  copy optional id field and caller picture
 * PARAMETERS
 *  dst_store_index     [IN]        
 *  src_store_index     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_copy_optional_ids(U16 dst_store_index, U16 src_store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 src_optid_record, dst_optid_record;
    U8 optid_index;
    S16 pError;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];
    PHB_OPTIONAL_IDS_STRUCT tempIDs;
    BOOL copy_image = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read Source ID first */
    src_optid_record = (src_store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = src_store_index - (src_optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

    ReadRecord(NVRAM_EF_PHB_IDS_LID, src_optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    /* Copy to temp buffer. */
    memcpy(&tempIDs, &PhbOptIDs[optid_index], sizeof(PHB_OPTIONAL_IDS_STRUCT));

    /* Read Destination ID */
    dst_optid_record = (dst_store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = dst_store_index - (dst_optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

    if (dst_optid_record != src_optid_record)
    {
        ReadRecord(NVRAM_EF_PHB_IDS_LID, dst_optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
    }

    /* Copy from temp buffer. */
    memcpy(&PhbOptIDs[optid_index], &tempIDs, sizeof(PHB_OPTIONAL_IDS_STRUCT));
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    if (dst_store_index  < MAX_PB_PHONE_ENTRIES && src_store_index < MAX_PB_PHONE_ENTRIES) /* duplicate phone entry*/
    {
        /* Duplicate image in file system. */
        if (PhbOptIDs[optid_index].pictureTagID == 1
        #ifdef __MMI_AVATAR__
            || PhbOptIDs[optid_index].pictureTagID == 2
        #endif
            )
        {
            copy_image = mmi_phb_image_duplicate_by_index((U16) (dst_store_index + 1), (U16) (src_store_index + 1));
            if (!copy_image)
            {
                PhbOptIDs[optid_index].pictureTagID = 0;
            }
        }
    }
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
    /* Write Back To buffer */
    WriteRecord(NVRAM_EF_PHB_IDS_LID, dst_optid_record, PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
    return copy_image;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_truncate_pbname_buffer
 * DESCRIPTION
 *  truncate pbName buffer to fit the max size
 * PARAMETERS
 *  dst_store_index     [IN]        
 *  src_store_index     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_truncate_pbname_buffer(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_name_len;
#if defined(__PHB_0x81_SUPPORT__)  
    U8 ucs2_0x81_name_length;
    S8 ucs2_0x81_name[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
#endif /* defined(__PHB_0x81_SUPPORT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == MMI_NVRAM)
    {
        max_name_len = MAX_PB_NAME_LENGTH;
    }
    else
    {
        max_name_len = g_phb_cntx.sim_name_len;    
    }

#if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
    mmi_ucs2ncpy(ucs2_0x81_name, pbName, (MAX_PB_NAME_LENGTH + 1));
    // use ucs2_0x81_name to store original content
    if ((ucs2_0x81_name_length = mmi_phb_convert_to_0x81((S8*) ucs2_0x81_name, TRUE)) > 0)
    {
        if (ucs2_0x81_name_length > max_name_len)
        {
            memset(pbName + ((max_name_len - 3) * 2), 0, 2);
        }
        else
        {
            memset(pbName + ((ucs2_0x81_name_length - 3) * 2), 0, 2);
        }
    }
    else
#endif /* defined(__PHB_0x81_SUPPORT__) */         	
    if (GetUCS2Flag(pbName)) /* there is chinese character, length = 14 */
    {
        memset(pbName + ((max_name_len - 1) / 2 * 2), 0, 2);
    }
    else
    {
        U8 name_extend_char_num = GetUCS2ExtendedNum((PS8)pbName, (U8)mmi_ucs2strlen(pbName));
        if ((mmi_ucs2strlen(pbName) + name_extend_char_num) > max_name_len)
        {     
            memset(pbName + ((max_name_len - name_extend_char_num) * 2), 0, 2);
        }
        else
        {
            memset(pbName + (max_name_len * 2), 0, 2);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_calculate_number_valid_length
 * DESCRIPTION
 *  calculate valid number length before save to L4
 * PARAMETERS
 *  in_number     [IN]     
 *  out_number    [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_calculate_number_valid_length(S8 *in_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 valid_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*in_number == 0) && (*(in_number + 1) == 0)))
    {
        if ((*in_number >= '0' && *in_number <= '9') || *in_number =='*' || *in_number == '+' || 
            *in_number == '#' || *in_number == 'p'|| *in_number == 'P'|| *in_number == 'w' || *in_number == 'W')
        {
            valid_length ++;
        }
        in_number += 2;        
    }
    return valid_length;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_copy_number_without_parentheses
 * DESCRIPTION
 *  prepare name and number by user input  before send to L4
 * PARAMETERS
 *  in_number     [IN]     
 *  out_number    [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_copy_number_without_parentheses(S8 *in_number, S8 *out_number)
{
    while (!((*in_number == 0) && (*(in_number + 1) == 0)))
    {
        if ((*in_number >= '0' && *in_number <= '9') || *in_number =='*' || *in_number == '+' || 
            *in_number == '#' || *in_number == 'p'|| *in_number == 'P'|| *in_number == 'w' || *in_number == 'W')
        {
            *out_number = *(in_number);
            *(out_number + 1) =  *(in_number + 1);
            out_number += 2;
        }
        in_number += 2;
    }
    *out_number = 0;
    *(out_number + 1) = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_remove_invalid_character
 * DESCRIPTION
 *  remove invalid characters in number
 * PARAMETERS
 *  in_number     [IN]     
 *  out_number    [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_number_remove_invalid_character(S8 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*num == 0) && (*(num + 1) == 0)))
    {
        if (!((*num >= '0' && *num <= '9') || *num =='*' || *num == '+' || 
            *num == '#' || *num == 'p'|| *num == 'P'|| *num == 'w' || *num == 'W'))
        {
            for(i = 0; (!(*(num + i) == 0) && (*(num + i + 1) == 0)); (i = i + 2))
            {
                *(num + i) = *(num + i + 2);
                *(num + i + 1) = *(num + i + 3);
            }
            *(num + i) = 0;
            *(num + i + 1) = 0;
        }
        else
        {
            num += 2;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_set_entry_prepare_name_number
 * DESCRIPTION
 *  prepare name and number by user input  before send to L4
 * PARAMETERS
 *  dst_msg     [?]     
 *  in_name     [?]     
 *  in_num      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_set_entry_prepare_name_number(void *dst_msg, S8 *in_name, S8 *in_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4c_phb_entry_struct *phb_entry = (l4c_phb_entry_struct*) dst_msg;

#if defined(__PHB_0x81_SUPPORT__)
    U8 length;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dst_msg == NULL)
    {
        return;
    }

    if (in_num != NULL)
    {
        S8* valid_num = OslMalloc((MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
        mmi_phb_copy_number_without_parentheses(in_num, valid_num);
        /* Prepate Number Data */
        if (in_num[0] == '+')
        {
            phb_entry->tel.type = MMI_CSMCC_INTERNATIONAL_ADDR; /* INTERNATIONAL */
            phb_entry->tel.length = (U8) mmi_ucs2strlen(valid_num + ENCODING_LENGTH);    /* Exclude "+" */
            mmi_ucs2_to_asc((PS8) phb_entry->tel.number, valid_num + ENCODING_LENGTH);
        }
        else
        {
            phb_entry->tel.type = MMI_CSMCC_DEFAULT_ADDR_TYPE;  /* DEFAULT */
            phb_entry->tel.length = (U8) mmi_ucs2strlen(valid_num);
            mmi_ucs2_to_asc((PS8) phb_entry->tel.number, valid_num);
        }
        OslMfree(valid_num);
    }

    if (in_name != NULL)
    {
        /* Prepare Name Data */
        if (GetUCS2Flag(in_name))
        {
        #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
            if ((length = mmi_phb_convert_to_0x81((S8*) in_name, TRUE)) > 0)
            {
                phb_entry->alpha_id.name_dcs = 0x09;
                phb_entry->alpha_id.name_length = length;
                memcpy(phb_entry->alpha_id.name, in_name, length);
                memset(phb_entry->alpha_id.name + length, 0x00, 1);
            }
            else
        #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            {
                phb_entry->alpha_id.name_dcs = MMI_PHB_UCS2;
                phb_entry->alpha_id.name_length = ((U8) mmi_ucs2strlen(in_name)) * ENCODING_LENGTH;
                InputboxConvertDeviceEncodingToGSM(
                    (PU8) in_name,
                    phb_entry->alpha_id.name,
                    MAX_PS_NAME_LENGTH,
                    MMI_PHB_UCS2,
                    0,
                    1);
            }
        }
        else
        {
            phb_entry->alpha_id.name_dcs = MMI_PHB_ASCII;
            phb_entry->alpha_id.name_length = InputboxConvertDeviceEncodingToGSM(
                                                (PU8) in_name,
                                                phb_entry->alpha_id.name,
                                                MAX_PS_NAME_LENGTH,
                                                MMI_PHB_ASCII,
                                                0,
                                                1) - 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_set_entry_prepare_name_number_by_index
 * DESCRIPTION
 *  prepare name and number by store index before send to L4
 * PARAMETERS
 *  dst_msg         [?]         
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_set_entry_prepare_name_number_by_index(void *dst_msg, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4c_phb_entry_struct *phb_entry = (l4c_phb_entry_struct*) dst_msg;

#if defined(__PHB_0x81_SUPPORT__)
    U8 length;
    S8 *in_name = OslMalloc((MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(in_name, PhoneBook[store_index].alpha_id.name, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
#endif /* defined(__PHB_0x81_SUPPORT__) */ 

    phb_entry->alpha_id.name_length = PhoneBook[store_index].alpha_id.name_length;
    phb_entry->alpha_id.name_dcs = PhoneBook[store_index].alpha_id.name_dcs;
#if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
    if ((PhoneBook[store_index].alpha_id.name_dcs == MMI_PHB_UCS2)
        && ((length = mmi_phb_convert_to_0x81(in_name, TRUE)) > 0))
    {
        phb_entry->alpha_id.name_dcs = 0x09;
        phb_entry->alpha_id.name_length = length;
        memcpy(phb_entry->alpha_id.name, in_name, length);
        memset(phb_entry->alpha_id.name + length, 0x00, 1);
    }
    else
#endif /* defined(__PHB_0x81_SUPPORT__) */ 
    {
        InputboxConvertDeviceEncodingToGSM(
            PhoneBook[store_index].alpha_id.name,
            phb_entry->alpha_id.name,
            MAX_PS_NAME_LENGTH,
            PhoneBook[store_index].alpha_id.name_dcs,
            0,
            1);
    }

    phb_entry->tel.type = PhoneBook[store_index].tel.type;
    /* myMsgPtr->list.tel.length = PhoneBook[store_index].tel.length; */
    mmi_phb_convert_to_digit(phb_entry->tel.number, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    phb_entry->tel.length = strlen((S8*) phb_entry->tel.number);
#if defined(__PHB_0x81_SUPPORT__)
    OslMfree(in_name);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_set_entry_rsp_name_number
 * DESCRIPTION
 *  set name and number in the set entry response message.
 * PARAMETERS
 *  rsp_msg         [?]         
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_set_entry_rsp_name_number(void *rsp_msg, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    l4c_phb_entry_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (l4c_phb_entry_struct*) rsp_msg;

    PhoneBook[store_index].alpha_id.name_length = localPtr->alpha_id.name_length;
    PhoneBook[store_index].alpha_id.name_dcs = localPtr->alpha_id.name_dcs;
    InputboxConvertGSMToDeviceEncoding(
        localPtr->alpha_id.name,
        PhoneBook[store_index].alpha_id.name,
        localPtr->alpha_id.name_length,
        (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
        localPtr->alpha_id.name_dcs,
        0,
        1);
#if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
    if (PhoneBook[store_index].alpha_id.name_dcs == MMI_PHB_UCS2_81 ||
        PhoneBook[store_index].alpha_id.name_dcs == MMI_PHB_UCS2_82)
    {
        PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_UCS2;
    }
#endif /* defined(__PHB_0x81_SUPPORT__) */ 

    PhoneBook[store_index].tel.type = localPtr->tel.type;
    PhoneBook[store_index].tel.length = localPtr->tel.length;
    mmi_phb_convert_to_bcd(PhoneBook[store_index].tel.number, localPtr->tel.number, (MAX_PB_NUMBER_LENGTH + 1) / 2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_get_store_index_and_increase_counter
 * DESCRIPTION
 *  Use storage and record_index to get phonebook store_index(store position in the array)
 * PARAMETERS
 *  storage             [IN]        
 *  record_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_op_get_store_index_and_increase_counter(U8 storage, U16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == MMI_SIM)
    {
        g_phb_cntx.sim_used++;
        store_index = record_index + MAX_PB_PHONE_ENTRIES - 1;  /* Storage Location in array. */
        MMI_ASSERT((g_phb_cntx.sim_used <= g_phb_cntx.sim_total) && (store_index < MAX_PB_ENTRIES));
    }
    else
    {
        g_phb_cntx.phone_used++;
        store_index = record_index - 1; /* Storage Location in array. */
        MMI_ASSERT((g_phb_cntx.phone_used <= g_phb_cntx.phone_total) && (store_index < MAX_PB_PHONE_ENTRIES));
    }

    return store_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_clear_lookup_table_by_index
 * DESCRIPTION
 *  clear one entry in number lookup table
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_op_clear_lookup_table_by_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 deletedCnt = 0;
    U16 k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (k = 0; k < g_phb_cntx.lookup_table_count; ++k)
    {
        if (LookUpTable[k].store_index == store_index)
        {
            LookUpTable[k].number = INVALID_NUMBER;
            deletedCnt++;
        }
    }

    return deletedCnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_increase_lookup_table
 * DESCRIPTION
 *  add one entry into lookup table
 * PARAMETERS
 *  store_index     [IN]        
 *  number          [?]         
 *  fax             [?]         
 *  home            [?]         
 *  office          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_op_increase_lookup_table(U16 store_index, S8 *number, S8 *fax, S8 *home, S8 *office)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL)
    {
        temp = mmi_phb_util_convert_number_to_int((U8*) number);
        if (temp < INVALID_NUMBER && g_phb_cntx.lookup_table_count < MAX_LOOKUP_TABLE_COUNT)
        {
            flag = 1;
            LookUpTable[g_phb_cntx.lookup_table_count].store_index = store_index;
            LookUpTable[g_phb_cntx.lookup_table_count++].number = temp;
        }
    }

    if (fax != NULL)
    {
        temp = mmi_phb_util_convert_number_to_int((U8*) fax);
        if (temp < INVALID_NUMBER && g_phb_cntx.lookup_table_count < MAX_LOOKUP_TABLE_COUNT)
        {
            flag = 1;
            LookUpTable[g_phb_cntx.lookup_table_count].store_index = store_index;
            LookUpTable[g_phb_cntx.lookup_table_count++].number = temp;
        }
    }

    if (home != NULL)
    {
        temp = mmi_phb_util_convert_number_to_int((U8*) home);
        if (temp < INVALID_NUMBER && g_phb_cntx.lookup_table_count < MAX_LOOKUP_TABLE_COUNT)
        {
            flag = 1;
            LookUpTable[g_phb_cntx.lookup_table_count].store_index = store_index;
            LookUpTable[g_phb_cntx.lookup_table_count++].number = temp;
        }
    }

    if (office != NULL)
    {
        temp = mmi_phb_util_convert_number_to_int((U8*) office);
        if (temp < INVALID_NUMBER && g_phb_cntx.lookup_table_count < MAX_LOOKUP_TABLE_COUNT)
        {
            flag = 1;
            LookUpTable[g_phb_cntx.lookup_table_count].store_index = store_index;
            LookUpTable[g_phb_cntx.lookup_table_count++].number = temp;
        }
    }

    return flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_update_field_flag
 * DESCRIPTION
 *  update fileter flag of each entry.
 * PARAMETERS
 *  store_index     [IN]        
 *  number          [?]         
 *  home            [?]         
 *  office          [?]         
 *  fax             [?]         
 *  email           [?]         
 *  is_new          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_update_field_flag(
        U16 store_index,
        S8 *number,
        S8 *home,
        S8 *office,
        S8 *fax,
        S8 *email,
        BOOL is_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* New record, clear first. */
    if (is_new)
    {
        PhoneBook[store_index].field = 0;
    }

    if (number != NULL)
    {
        if (strlen(number))
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
        }
        else if (!is_new)   /* Clear flag when the field is empty and the record is not a new record */
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_NUMBER;
        }
    }

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    if (home != NULL)
    {
        if (strlen(home) > 0)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_HOME;
        }
        else if (!is_new)
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_HOME;
        }
    }

    if (office != NULL)
    {
        if (strlen(office) > 0)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_OFFICE;
        }
        else if (!is_new)
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_OFFICE;
        }
    }

    if (fax != NULL)
    {
        if (strlen(fax) > 0)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_FAX;
        }
        else if (!is_new)
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_FAX;
        }
    }

    if (email != NULL)
    {
        if (strlen(email) > 0)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_EMAIL;
        }
        else if (!is_new)
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_EMAIL;
        }
    }
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
}


#ifdef __MMI_PHB_USIM_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_all_to_usim_one_after_one_rsp
 * DESCRIPTION
 *  copy all one entry set response.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_copy_all_to_usim_one_after_one_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_USIM_ENRTY_RSP_STRUCT *localPtr;
    U8 copy_from, copy_to = 0;
    U16 store_index;
    U32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_all_to_usim_one_after_one_rsp.>\n",
                         __FILE__, __LINE__);

    localPtr = (MSG_PHB_SET_USIM_ENRTY_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        g_phb_cntx.sim_used++;
        store_index = localPtr->list.record_index + MAX_PB_PHONE_ENTRIES - 1;   /* Storage Location in array. */
        copy_to = MMI_SIM;
        copy_from = MMI_NVRAM;

        /* Populate Number Field */
        temp = mmi_phb_util_convert_number_to_int(localPtr->list.tel.number);
        if (temp < INVALID_NUMBER)
        {
            LookUpTable[g_phb_cntx.lookup_table_count].store_index = store_index;
            LookUpTable[g_phb_cntx.lookup_table_count++].number = temp;
        }

        /* Add result to Phonebook Storage */
        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list, store_index);

        /* Update field flag */
        mmi_phb_op_set_entry_usim_fields(&PhoneBookOptionalFields, store_index);
        mmi_phb_op_update_usim_field_flag(
            store_index,
            (S8*) localPtr->list.tel.number,
            (S8*) PhoneBookOptionalFields.homeNumber,
            (S8*) PhoneBookOptionalFields.officeNumber,
            (S8*) PhoneBookOptionalFields.faxNumber,
            (S8*) PhoneBookOptionalFields.emailAddress,
            TRUE);
        mmi_phb_op_increase_lookup_table(
            store_index,
            NULL,
            (S8*) PhoneBookOptionalFields.faxNumber,
            (S8*) PhoneBookOptionalFields.homeNumber,
            (S8*) PhoneBookOptionalFields.officeNumber);
        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }
    #if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 
        /* Append new entry in the end of sorted list. Sorting when copy all done. */
        g_phb_name_index[PhoneBookEntryCount] = store_index;
        PhoneBookEntryCount++;
        g_phb_mass_op_count++;

        /* Insert email to email mapping table, not like name field, it should sort here. */
    #if defined(__MMI_PHB_EMAIL_SORT__)
        if (g_phb_email_sorted == 1)
        {
            mmi_phb_sort_email_insert_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

        if (g_phb_mass_op_abort)
        {
            g_phb_mass_op_success = FALSE;
            mmi_phb_op_copy_all_done();
        }
        else
        {
            if ((copy_to == MMI_SIM && g_phb_mass_op_count < g_phb_cntx.phone_used))
            {
                ++g_phb_mass_op_index;
                mmi_phb_op_copy_all_to_usim_one_after_one_req();
            }
            else
            {
                mmi_phb_op_copy_all_done();
            }
        }
    }
    else
    {
        g_phb_mass_op_success = FALSE;
        copy_from = MMI_NVRAM;

        /* Not copy fail due to capacity full. */
        if ((localPtr->result.cause != MMI_PHB_CAUSE_CAPACITY_EXCEEDED) &&
            ((copy_from == MMI_NVRAM && g_phb_mass_op_count < g_phb_cntx.phone_used)))
        {
            g_phb_mass_op_index++;
            mmi_phb_op_copy_all_to_usim_one_after_one_req();
        }
        else
        {
            mmi_phb_op_copy_all_done();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_all_to_usim_one_after_one_req
 * DESCRIPTION
 *  Copy all one entry after one.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_copy_all_to_usim_one_after_one_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_all_to_usim_one_after_one_req.>\n",
                         __FILE__, __LINE__);
    while ((g_phb_name_index[g_phb_mass_op_index] >= MAX_PB_PHONE_ENTRIES) && (g_phb_mass_op_index < PhoneBookEntryCount))      /* Not in NVRAM */
    {
        g_phb_mass_op_index++;
    }
    if (g_phb_mass_op_index >= PhoneBookEntryCount)
    {
        mmi_phb_op_copy_all_done();
        return;
    }
    store_index = g_phb_name_index[g_phb_mass_op_index];
#if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
    mmi_phb_util_make_pinyin_cache(store_index);
#endif 

    myMsgPtr = (MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT));
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.index = 0xFFFF;
    myMsgPtr->list.record_index = 0xFFFF;
    myMsgPtr->list.storage = MMI_SIM;
    myMsgPtr->anra.record_index = 0xFFFF;
    myMsgPtr->anrb.record_index = 0xFFFF;
    myMsgPtr->anrc.record_index = 0xFFFF;
    myMsgPtr->email.adn_record_index = 0xFFFF;

    mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);
    mmi_phb_op_set_entry_prepare_usim_data_by_index(store_index);
    mmi_phb_op_set_entry_prepare_usim_data(
        myMsgPtr,
        pbNickName,
        pbHomeNumber,
        pbOfficeNumber,
        pbFaxNumber,
        pbEmailAddress);
    myMsgPtr->group_type = 0;
    // TODO: hidden info
    //myMsgPtr->hidden_info = ;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_WRITE_USIM_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_copy_all_to_usim_one_after_one_rsp, PRT_PHB_WRITE_USIM_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_set_entry_usim_fields
 * DESCRIPTION
 *  set name and number in the set entry response message.
 * PARAMETERS
 *  field_msg       [?]         
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_set_entry_usim_fields(void *field_msg, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PHB_OPTIONAL_FIELDS_STRUCT *localPtr = (PHB_OPTIONAL_FIELDS_STRUCT*) field_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(store_index >= MAX_PB_PHONE_ENTRIES);
    store_index -= MAX_PB_PHONE_ENTRIES;
    if (localPtr->homeNumber[0] == '+')
    {
        phb_anr[store_index][0].type = MMI_CSMCC_INTERNATIONAL_ADDR;    /* INTERNATIONAL */
        phb_anr[store_index][0].length = 
            mmi_phb_convert_to_bcd(phb_anr[store_index][0].number, localPtr->homeNumber + 1, (MAX_PB_NUMBER_LENGTH + 1) / 2);
    }
    else
    {
        phb_anr[store_index][0].type = MMI_CSMCC_DEFAULT_ADDR_TYPE;     /* DEFAULT */
        phb_anr[store_index][0].length = 
            mmi_phb_convert_to_bcd(phb_anr[store_index][0].number, localPtr->homeNumber, (MAX_PB_NUMBER_LENGTH + 1) / 2);
    }

    if (localPtr->officeNumber[0] == '+')
    {
        phb_anr[store_index][1].type = MMI_CSMCC_INTERNATIONAL_ADDR;    /* INTERNATIONAL */
        phb_anr[store_index][1].length = 
            mmi_phb_convert_to_bcd(phb_anr[store_index][1].number, localPtr->officeNumber + 1, (MAX_PB_NUMBER_LENGTH + 1) / 2);
    }
    else
    {
        phb_anr[store_index][1].type = MMI_CSMCC_DEFAULT_ADDR_TYPE;     /* DEFAULT */
        phb_anr[store_index][1].length = 
            mmi_phb_convert_to_bcd(phb_anr[store_index][1].number, localPtr->officeNumber, (MAX_PB_NUMBER_LENGTH + 1) / 2);
    }

    if (localPtr->faxNumber[0] == '+')
    {
        phb_anr[store_index][2].type = MMI_CSMCC_INTERNATIONAL_ADDR;    /* INTERNATIONAL */
        phb_anr[store_index][2].length = 
            mmi_phb_convert_to_bcd(phb_anr[store_index][2].number, localPtr->faxNumber + 1, (MAX_PB_NUMBER_LENGTH + 1) / 2);
    }
    else
    {
        phb_anr[store_index][2].type = MMI_CSMCC_DEFAULT_ADDR_TYPE;     /* DEFAULT */
        phb_anr[store_index][2].length = 
            mmi_phb_convert_to_bcd(phb_anr[store_index][2].number, localPtr->faxNumber, (MAX_PB_NUMBER_LENGTH + 1) / 2);
    }

    mmi_ucs2_to_asc((S8*) phb_email[store_index].email_address, (S8*) pbEmailAddress);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_update_usim_field_flag
 * DESCRIPTION
 *  update fileter flag of each entry.
 * PARAMETERS
 *  store_index     [IN]        
 *  number          [?]         
 *  anra            [?]         
 *  anrb            [?]         
 *  anrc            [?]         
 *  email           [?]         
 *  is_new          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_update_usim_field_flag(
        U16 store_index,
        S8 *number,
        S8 *anra,
        S8 *anrb,
        S8 *anrc,
        S8 *email,
        BOOL is_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* New record, clear first. */
    if (is_new)
    {
        PhoneBook[store_index].field = 0;
    }

    if (number != NULL)
    {
        if (strlen(number))
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
        }
        else if (!is_new)   /* Clear flag when the field is empty and the record is not a new record */
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_NUMBER;
        }
    }

    if (anra != NULL)
    {
        if (strlen(anra) > 0)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_ANRA;
        }
        else if (!is_new)
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_ANRA;
        }
    }

    if (anrb != NULL)
    {
        if (strlen(anrb) > 0)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_ANRB;
        }
        else if (!is_new)
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_ANRB;
        }
    }

    if (anrc != NULL)
    {
        if (strlen(anrc) > 0)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_ANRC;
        }
        else if (!is_new)
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_ANRC;
        }
    }

    if (email != NULL)
    {
        if (strlen(email) > 0)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_EMAIL;
        }
        else if (!is_new)
        {
            PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_EMAIL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_set_entry_prepare_usim_data_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_set_entry_prepare_usim_data_by_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* memset(pbNumber, 0, ENCODING_LENGTH); */
    memset(pbHomeNumber, 0, ENCODING_LENGTH);
    memset(pbEmailAddress, 0, ENCODING_LENGTH);
    memset(pbOfficeNumber, 0, ENCODING_LENGTH);
    memset(pbFaxNumber, 0, ENCODING_LENGTH);
    memset(pbEmailAddress, 0, ENCODING_LENGTH);
    /* mmi_phb_convert_get_ucs2_number((S8*)pbNumber, index); */
    if (index < MAX_PB_PHONE_ENTRIES)   /* from nvram */
    {
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        S16 pError;

        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
        mmi_asc_to_ucs2(pbHomeNumber, (PS8) PhoneBookOptionalFields.homeNumber);
        mmi_asc_to_ucs2(pbEmailAddress, (PS8) PhoneBookOptionalFields.emailAddress);
        mmi_asc_to_ucs2(pbOfficeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
        mmi_asc_to_ucs2(pbFaxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
    }
    else
    {
        mmi_phb_convert_get_ucs2_anr((S8*) pbHomeNumber, (S8*) pbOfficeNumber, (S8*) pbFaxNumber, index);
        if (index >= MAX_PB_PHONE_ENTRIES)
        {
            mmi_asc_to_ucs2((S8*) pbEmailAddress, (S8*) phb_email[index - MAX_PB_PHONE_ENTRIES].email_address);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_set_entry_prepare_usim_data
 * DESCRIPTION
 *  prepare usim fields (except name and number) by user input  before send to L4
 * PARAMETERS
 *  dst_msg         [?]     
 *  in_name         [?]     
 *  in_num          [?]     
 *  in_numb         [?]     
 *  in_numc         [?]     
 *  in_email        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_set_entry_prepare_usim_data(
        void *dst_msg,
        S8 *in_name,
        S8 *in_num,
        S8 *in_numb,
        S8 *in_numc,
        S8 *in_email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT *myMsgPtr;

#if defined(__PHB_0x81_SUPPORT__)
    U8 length;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT*) dst_msg;

    if (dst_msg == NULL)
    {
        return;
    }

    if (in_name != NULL)
    {
        /* Prepare Second Name Data */
        if (GetUCS2Flag(in_name))
        {
        #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
            if ((length = mmi_phb_convert_to_0x81((S8*) in_name, TRUE)) > 0)
            {
                myMsgPtr->sne.name_dcs = 0x09;
                myMsgPtr->sne.name_length = length;
                memcpy(myMsgPtr->sne.name, in_name, length);
                memset(myMsgPtr->sne.name + length, 0x00, 1);
            }
            else
        #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            {
                myMsgPtr->sne.name_dcs = MMI_PHB_UCS2;
                myMsgPtr->sne.name_length = ((U8) mmi_ucs2strlen(in_name)) * ENCODING_LENGTH;
                InputboxConvertDeviceEncodingToGSM(
                    (PU8) in_name,
                    myMsgPtr->sne.name,
                    MAX_PS_NAME_LENGTH,
                    MMI_PHB_UCS2,
                    0,
                    1);
            }
        }
        else
        {
            myMsgPtr->sne.name_dcs = MMI_PHB_ASCII;
            myMsgPtr->sne.name_length = InputboxConvertDeviceEncodingToGSM(
                                            (PU8) in_name,
                                            myMsgPtr->sne.name,
                                            MAX_PS_NAME_LENGTH,
                                            MMI_PHB_ASCII,
                                            0,
                                            1) - 1;
        }
    }

    if (in_num != NULL)
    {
        /* Prepare Addtional Number A Data */
        if (in_num[0] == '+')
        {
            myMsgPtr->anra.tel_number.type = MMI_CSMCC_INTERNATIONAL_ADDR;      /* INTERNATIONAL */
            myMsgPtr->anra.tel_number.length = (U8) mmi_ucs2strlen(in_num + ENCODING_LENGTH); /* Exclude "+" */
            mmi_ucs2_to_asc((PS8) myMsgPtr->anra.tel_number.number, in_num + ENCODING_LENGTH);
        }
        else
        {
            myMsgPtr->anra.tel_number.type = MMI_CSMCC_DEFAULT_ADDR_TYPE;       /* DEFAULT */
            myMsgPtr->anra.tel_number.length = (U8) mmi_ucs2strlen(in_num);
            mmi_ucs2_to_asc((PS8) myMsgPtr->anra.tel_number.number, in_num);
        }
    }

    if (in_numb != NULL)
    {
        /* Prepare Addtional Number B Data */
        if (in_num[0] == '+')
        {
            myMsgPtr->anrb.tel_number.type = MMI_CSMCC_INTERNATIONAL_ADDR;      /* INTERNATIONAL */
            myMsgPtr->anrb.tel_number.length = (U8) mmi_ucs2strlen(in_numb + ENCODING_LENGTH);        /* Exclude "+" */
            mmi_ucs2_to_asc((PS8) myMsgPtr->anrb.tel_number.number, in_numb + ENCODING_LENGTH);
        }
        else
        {
            myMsgPtr->anrb.tel_number.type = MMI_CSMCC_DEFAULT_ADDR_TYPE;       /* DEFAULT */
            myMsgPtr->anrb.tel_number.length = (U8) mmi_ucs2strlen(in_numb);
            mmi_ucs2_to_asc((PS8) myMsgPtr->anrb.tel_number.number, in_numb);
        }
    }

    if (in_numc != NULL)
    {
        /* Prepare Addtional Number C Data */
        if (in_num[0] == '+')
        {
            myMsgPtr->anrc.tel_number.type = MMI_CSMCC_INTERNATIONAL_ADDR;      /* INTERNATIONAL */
            myMsgPtr->anrc.tel_number.length = (U8) mmi_ucs2strlen(in_numc + ENCODING_LENGTH);        /* Exclude "+" */
            mmi_ucs2_to_asc((PS8) myMsgPtr->anrc.tel_number.number, in_numc + ENCODING_LENGTH);
        }
        else
        {
            myMsgPtr->anrc.tel_number.type = MMI_CSMCC_DEFAULT_ADDR_TYPE;       /* DEFAULT */
            myMsgPtr->anrc.tel_number.length = (U8) mmi_ucs2strlen(in_numc);
            mmi_ucs2_to_asc((PS8) myMsgPtr->anrc.tel_number.number, in_numc);
        }
    }

    if (in_email != NULL)
    {
        /* Prepare email Data */
        myMsgPtr->email.email_length = InputboxConvertDeviceEncodingToGSM(
                                        (PU8) in_email,
                                        myMsgPtr->email.email_address,
                                        MAX_PB_EMAIL_LENGTH + 1,
                                        MMI_PHB_ASCII,
                                        0,
                                        1) - 1;
        myMsgPtr->email.adn_record_index = myMsgPtr->list.record_index;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_set_option_data_by_usim_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  opt_fields      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_set_option_data_by_usim_index(U16 index, PHB_OPTIONAL_FIELDS_STRUCT *opt_fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= MAX_PB_PHONE_ENTRIES)
    {
        mmi_phb_convert_get_ansii_anr(
            (S8*) opt_fields->homeNumber,
            (S8*) opt_fields->officeNumber,
            (S8*) opt_fields->faxNumber,
            index);
        memcpy(opt_fields->emailAddress, phb_email[index - MAX_PB_PHONE_ENTRIES].email_address, MAX_PB_EMAIL_LENGTH);
    }
}
#endif /* __MMI_PHB_USIM_FIELD__ */ 

//huzhuhua 080722 begin
#ifdef __PHONEBOOK_OUTPUT_INPUT__
#include "FileManagerGProt.h"
#include "ConnectivityResDef.h"
#include "MainMenuDef.h"
extern void SettingInlineCustomFunction(void);
extern void GoBack2TheHistory(void);
extern void mmi_popup_file_system_error_handler(S32 error_code);
extern  int sys_get_disk_free_space(kal_wchar *drive_name, U16 need_space);
extern pBOOL IsTrChineseSet(void);
extern pBOOL IsSmChineseSet(void);
extern void get_curr_file_fullpath_name(S8* str);
S8 PBFILENAMEText[(MAX_PBBACKUP_NAME_TEXT + 1) * ENCODING_LENGTH] = {0};
U8 output_state = 0x0;    //sim1,sim2,phone,all
S16 g_mmi_pboutput_list_highlighted_item;
U8   is_entry_pb_output_scr = 0;

void PB_Output_Menu_Handle(void)
{
     U8 state1=0,state2=0;
     state1 =  MTPNP_PFAL_Is_Card1Absent();
     state2 =  MTPNP_PFAL_Is_Card2Absent();
     
    mmi_frm_hide_menu_item(MITEM_PBOOK_BACKUP_SIM1TOCARD);
    mmi_frm_hide_menu_item(MITEM_PBOOK_BACKUP_SIM2TOCARD);
    mmi_frm_hide_menu_item(MITEM_PBOOK_BACKUP_PHONETOCARD);
    mmi_frm_hide_menu_item(MITEM_PBOOK_BACKUP_ALLTOCARD);

    if(state1&&state2)
    {
             mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_PHONETOCARD);
             output_state = 0x2;             
    }
    else if(state1&&!state2) 
    {
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_SIM2TOCARD);
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_PHONETOCARD);
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_ALLTOCARD);
            output_state = 0x7;    
    }
    else if(state2&&!state1) 
    {
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_SIM1TOCARD);
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_PHONETOCARD);
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_ALLTOCARD);
            output_state = 0xb;          
    }
    else
    {
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_SIM1TOCARD);
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_SIM2TOCARD);
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_PHONETOCARD);
            mmi_frm_unhide_menu_item(MITEM_PBOOK_BACKUP_ALLTOCARD);
            output_state = 0xf;        
    }
}

void mmi_pb_backup_output_highlight_hdlr(S32 index)
{
     g_mmi_pboutput_list_highlighted_item = index;
}

void mmi_phb_output_highlight(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_pb_backup_output, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_pb_backup_output, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void mmi_pb_backup_output(void)
{
    U8 *guiBuffer;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 nStrItemList[4];
    U16 nImgIltemList[4];
    U8 *nHintList[4];
#else 
    U16 nStrItemList[2];
    U16 nImgIltemList[2];
    U8 *nHintList[2];
#endif 
    U16 nNumofItem;
    U8 hilitedStorage;
    U8 hilight_sim, highlight_phone;

 //判断是否在U盘模式
     #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            DisplayPopup((PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
            return;
        }
    #endif 

//判断t卡是否存在
    if (FS_NO_ERROR != FS_GetDevStatus(MMI_CARD_DRV ,FS_MOUNT_STATE_ENUM))
    {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;
    }

//电话本是否准备好
#ifdef __MMI_DUAL_SIM_MASTER__
    Slave_g_phb_mass_op_abort= FALSE;
    if(MTPNP_PFAL_Phb_IsReady()==MTPNP_FALSE)
#else  
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif 
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_entry_not_ready(STR_ID_PHB_PROCESSING_USIM);
    }
#endif 
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif 
    else if (PhoneBookEntryCount)
    {
        EntryNewScreen(SCR_PB_OUTPUT_MENU, NULL, mmi_pb_backup_output, NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_PB_OUTPUT_MENU);
#ifdef __MMI_DUAL_SIM_MASTER__
        PB_Output_Menu_Handle();

        nNumofItem = GetNumOfChild_Ext(MITEM104_PBOOK_OUTPUT);
        GetSequenceStringIds_Ext(MITEM104_PBOOK_OUTPUT, nStrItemList);
        GetSequenceImageIds_Ext(MITEM104_PBOOK_OUTPUT, nImgIltemList);
#else 
        nNumofItem = GetNumOfChild(MITEM104_PBOOK_OUTPUT);
        GetSequenceStringIds(MITEM104_PBOOK_OUTPUT, nStrItemList);
        GetSequenceImageIds(MITEM104_PBOOK_OUTPUT, nImgIltemList);
#endif 
        SetParentHandler(MITEM104_PBOOK_OUTPUT);
        RegisterHighlightHandler(mmi_pb_backup_output_highlight_hdlr);
        ConstructHintsList(MITEM104_PBOOK_OUTPUT, nHintList);
        
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (mmi_bootup_is_sim_valid())
        {
                hilitedStorage = GetIndexOfStringId_Ext(MITEM104_PBOOK_OUTPUT, MITEM_PBOOK_BACKUP_SIM1TOCARD);            
        }
        else if (mmi_bootup_is_sim2_valid())
        {
                hilitedStorage = GetIndexOfStringId_Ext(MITEM104_PBOOK_OUTPUT, MITEM_PBOOK_BACKUP_SIM2TOCARD);        
        }
        else
        {
                hilitedStorage = 0;
        }
    #else 
        hilight_sim = GetIndexOfStringId_Ext(MITEM104_PBOOK_COPY_ALL, MITEM_PBOOK_COPY_ALL_SIM);
        highlight_phone = GetIndexOfStringId_Ext(MITEM104_PBOOK_COPY_ALL, MITEM_PBOOK_COPY_ALL_PHONE);
        if (g_phb_cntx.prefer_storage == MMI_SIM)
        {
            if ((g_phb_cntx.sim_used > 0) || (g_phb_cntx.phone_used == 0))
            {
                hilitedStorage = hilight_sim;
            }
            else
            {
                hilitedStorage = highlight_phone;
            }
        }
        else
        {
            if ((g_phb_cntx.phone_used > 0) || (g_phb_cntx.sim_used == 0))
            {
                hilitedStorage = highlight_phone;
            }
            else
            {
                hilitedStorage = hilight_sim;
            }
        }
    #endif 
        ShowCategory52Screen(
            STR_PB_BACKUP_OUTPUT,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            nImgIltemList,
            nHintList,
            0,
            hilitedStorage,
            guiBuffer);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
        return;
    }

     SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
     SetLeftSoftkeyFunction(mmi_pb_output_common_handler, KEY_EVENT_UP);

}    

//输入导出的文件名
S8 *GetDefaultPbText(void)
{
    U8 data[(MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH];
    S16 error;
    S8 *defaltString = NULL;

    memset(data, 0, (MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH);
    defaltString = OslMalloc((MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH);

    if (defaltString == NULL)
    {
        return NULL;
    }
    memset(defaltString, 0, (MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH);

    sprintf((PS8) data, "%s", FMGR_PB_DEFAULT_FILENAME);
    mmi_asc_to_ucs2((PS8) defaltString, (PS8) data);

    return defaltString;
}

static void FillPbEditStruct(void *pInlineStruct)
{
    S8 *defaltString = NULL;
    InlineItem *InlineStruct = (InlineItem*) pInlineStruct;

    defaltString = GetDefaultPbText();

    memset(PBFILENAMEText,0,(MAX_PBBACKUP_NAME_TEXT + 1) * ENCODING_LENGTH);
    
    mmi_ucs2cpy((S8*) PBFILENAMEText, (const S8*)defaltString);
    OslMfree(defaltString);

    SetInlineItemActivation(&InlineStruct[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&InlineStruct[0], (PU8) (U8*) GetString(STR_PB_OUTPUT_NAME));

    SetInlineItemActivation(&InlineStruct[1], KEY_LSK, KEY_EVENT_UP);

    SetInlineItemFullScreenEdit_ext(
        &InlineStruct[1],
        STR_PB_BACKUP_OUTPUT,
        MAIN_MENU_TITLE_PHONEBOOK_ICON,
        (PU8) PBFILENAMEText,
        MAX_PBBACKUP_NAME_TEXT + 1,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(&InlineStruct[1], SettingInlineCustomFunction);

}

void EntryPBTextDoneHdlr(void)
{
    U8 *guiBuffer;  

    EntryNewScreen(SCR9146_WELCOME_TEXT_ON, NULL, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR9146_WELCOME_TEXT_ON);

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) GetString(STR_PB_IS_OUTPUT),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    
    SetLeftSoftkeyFunction(mmi_output_pb_comm_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBack2TheHistory, KEY_EVENT_UP);

    playRequestedTone(WARNING_TONE);
}

void mmi_pb_output_common_exit_handler(void)
{
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;    

    is_entry_pb_output_scr = 0;
    Scr.scrnID = SCR_PB_OUTPUT_NAMING;
    CloseCategory57Screen();
    Scr.entryFuncPtr = mmi_pb_output_common_handler;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    
    GetCategory57Data((U8*) Scr.inputBuffer);          
    AddNHistory(Scr, (U16) inputBufferSize);          
}

void mmi_pb_output_common_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem = 2; 
    U8 *inputBuffer;   
    U8 *guiBuffer;     
    U16 inputBufferSize;
    U16 ItemIcons[2] = {0, 0};
    InlineItem greet_text_inline_edit_list[2];

    EntryNewScreen(SCR_PB_OUTPUT_NAMING, mmi_pb_output_common_exit_handler, NULL, NULL);
    
    is_entry_pb_output_scr = 1;
    
    guiBuffer = GetCurrGuiBuffer(SCR_PB_OUTPUT_NAMING);

    InitializeCategory57Screen();
    memset(greet_text_inline_edit_list, 0, sizeof(greet_text_inline_edit_list));
    FillPbEditStruct((void*)greet_text_inline_edit_list);
    inputBuffer = GetCurrNInputBuffer(SCR9146_WELCOME_TEXT, &inputBufferSize);  
    if (inputBuffer != NULL)
    {
        SetCategory57Data(greet_text_inline_edit_list, nNumofItem, inputBuffer);
    }

    ClearHighlightHandler();

    ShowCategory57Screen(
        STR_PB_BACKUP_OUTPUT,
        MAIN_MENU_TITLE_PHONEBOOK_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        nNumofItem,
        ItemIcons,
        greet_text_inline_edit_list,
        0,
        guiBuffer);

   ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
   SetCategory57RightSoftkeyFunctions(EntryPBTextDoneHdlr, EntryPBTextDoneHdlr);

}

void mmi_output_pb_comm_handler(void)
{
    FS_HANDLE file_handle,file_handle_txt;
    S8 list_path_phb[(FMGR_MAX_PB_PATH_LEN + 1) * ENCODING_LENGTH] = {0};
    S8 *list_path = OslMalloc((FMGR_MAX_PB_PATH_LEN + 1) * ENCODING_LENGTH);
    S32 ret_drv;
    U32 written_len; 
    U16 i, store_index, name_len,company_len;
    U8  attr, is_disk_full = 0;
    S32 create_result = 0 ;
    S8 buffer_UCS2[128]={0};
    PHB_OUTPUT_INPUT_STRUCT *temp_phb_info = (PHB_OUTPUT_INPUT_STRUCT*)OslMalloc(sizeof(PHB_OUTPUT_INPUT_STRUCT));

//获取盘符
    ret_drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

    if(ret_drv >= 0)
    {
//判断空间是否够，至少56K 剩余空间
    kal_wsprintf((kal_wchar*) buffer_UCS2, "%c:\\", ret_drv);
    is_disk_full = sys_get_disk_free_space((kal_wchar *)buffer_UCS2,(U16)PB_MEMORY_MIN_SIZE);
    if(!is_disk_full)
    {
	mmi_popup_file_system_error_handler(FS_DISK_FULL);
       return;
    }

     kal_prompt_trace(MOD_SIM,"huzhuhua mmi_output_pb_comm_handler size = %d",sizeof(PHB_OUTPUT_INPUT_STRUCT));
     memset(list_path, 0, (FMGR_MAX_PB_PATH_LEN + 1) * ENCODING_LENGTH);
//判断文件夹是否存在
    kal_wsprintf((kal_wchar*) list_path, "%c:\\%w", ret_drv, FMGR_DEFAULT_FOLDER_PB);
    file_handle = FS_Open((U16*)list_path, FS_READ_ONLY);
    if(file_handle<0)
    {
           //create folder
          kal_prompt_trace(MOD_SIM,"huzhuhua create folder !");
          FS_Close( file_handle);
          create_result = FS_CreateDir((U16*)list_path);
          if(create_result<0)
          {
          	mmi_popup_file_system_error_handler(create_result);
          	return;
           }
    }
    else
    {
            FS_Close( file_handle);
    }

//创建文件
    mmi_ucs2cat((S8*)list_path,(const S8*)PBFILENAMEText);
 #ifdef __PHONEBOOK_INPUT__   
    mmi_ucs2cpy((S8*)list_path_phb,(const S8*)list_path);
 #endif   
    mmi_ucs2cat((S8*) list_path, (S8*) FMGR_PB_BACKUP_FILE);
 #ifdef __PHONEBOOK_INPUT__   
    mmi_ucs2cat((S8*) list_path_phb, (S8*) FMGR_PB_BACKUP_FILE_INPUT);
 #endif   

//判断备份文件是否存在
#ifdef __PHONEBOOK_INPUT__
    file_handle = FS_Open((U16*)list_path, FS_READ_ONLY);
    if(file_handle>=0)
    {
          //delete file
          FS_Close( file_handle);
          kal_prompt_trace(MOD_SIM,"huzhuhua delete file !");
          create_result = FS_Delete((U16*)list_path);
          if(create_result < 0)
          {
               mmi_popup_file_system_error_handler(create_result);
               return;
           }
    }
    else
    {
           FS_Close( file_handle);
    }
#endif

    file_handle_txt = FS_Open((U16*)list_path_phb, FS_READ_ONLY);
    if(file_handle_txt>=0)
    {
          //delete file
          FS_Close( file_handle_txt);
          kal_prompt_trace(MOD_SIM,"huzhuhua delete file !");
          create_result = FS_Delete((U16*)list_path_phb);
          if(create_result < 0)
          {
               mmi_popup_file_system_error_handler(create_result);
               return;
           }
    }
    else
    {
           FS_Close( file_handle_txt);
    }

//生成.phb文件.txt文件
#ifdef __PHONEBOOK_INPUT__
    file_handle = FS_Open((U16*) list_path_phb, FS_CREATE | FS_READ_WRITE);
#endif    
    file_handle_txt = FS_Open((U16*) list_path, FS_CREATE | FS_READ_WRITE);
    
    if(file_handle_txt>=0)
    {
                 #ifdef __PHONEBOOK_INPUT__
                     if(file_handle<0)
                     {
               		FS_Close( file_handle);
               		mmi_popup_file_system_error_handler(file_handle);
              		return;               		
                     }
                 #endif
                  
			//写入头
			 if(IsSmChineseSet())
     				FS_Write(file_handle_txt, (void*)FMGR_PB_HAEDER_LINE1_SM, strlen(FMGR_PB_HAEDER_LINE1_SM), (U32*) & written_len);
     			 else if(IsTrChineseSet())
     				FS_Write(file_handle_txt, (void*)FMGR_PB_HAEDER_LINE1_TR, strlen(FMGR_PB_HAEDER_LINE1_TR), (U32*) & written_len);
     		        else
     				FS_Write(file_handle_txt, (void*)FMGR_PB_HAEDER_LINE1_EN, strlen(FMGR_PB_HAEDER_LINE1_EN), (U32*) & written_len);
     		            
     				FS_Write(file_handle_txt,FMGR_PB_NEW_LINE1,strlen(FMGR_PB_NEW_LINE1),(U32*) & written_len);
     				FS_Write(file_handle_txt, (void*)FMGR_PB_HAEDER_LINE2, strlen(FMGR_PB_HAEDER_LINE2), (U32*) & written_len);
     				FS_Write(file_handle_txt,FMGR_PB_NEW_LINE1,strlen(FMGR_PB_NEW_LINE1),(U32*) & written_len);    
    
     				
                      //写入内容
    				 for (i = 0; i < PhoneBookEntryCount; i++)
     				{      
       				store_index = g_phb_name_index[i];

                                   switch(output_state)
                                   {
                                       case 0xf:
                                       {
                                           switch(g_mmi_pboutput_list_highlighted_item)
                                           {
                                            	case 0://sim1
                                                  if (store_index >= MAX_PB_PHONE_ENTRIES && store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)){}
                                                  else 
                                                  	goto next_circle;
                                            	break;
                                            	case 1: //sim2
                                                  if (store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)){}
                                                  else 
                                                  	goto next_circle;                                            	
                                            	break;
                                             	case 2: //phone
                                                  if ((store_index >= MAX_PB_PHONE_ENTRIES && store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
                                                       ||(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
                                                  	goto next_circle;                                             	
                                             	break;
                                             	default://all
                                             	break;
                                           }
                                       }
                                       break;
                                       case 0xb:
                                       {
                                           switch(g_mmi_pboutput_list_highlighted_item)
                                           {
                                            	case 0://sim1
                                                  if (store_index >= MAX_PB_PHONE_ENTRIES && store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)){}
                                                  else 
                                                  	goto next_circle;
                                            	break;
                                             	case 1:  //phone
                                                  if ((store_index >= MAX_PB_PHONE_ENTRIES && store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
                                                       ||(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
                                                  	goto next_circle;                                             	
                                             	break;
                                             	default://all
                                             	break;
                                           }
                                       }
                                       break;
                                       case 0x7:
					   {
                                           switch(g_mmi_pboutput_list_highlighted_item)
                                           {
                                            	case 0://sim2
                                                  if (store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)){}
                                                  else 
                                                  	goto next_circle;
                                            	break;
                                             	case 1:  //phone
                                                  if ((store_index >= MAX_PB_PHONE_ENTRIES && store_index < (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
                                                       ||(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)))
                                                  	goto next_circle;                                             	
                                             	break;
                                             	default://all
                                             	break;
                                           }
                                       }
                                       break;
                                       case 0x2:
                                       break;
                                   }

                                  name_len = 0;company_len = 0;
                                  construct_pb_output_list(&temp_phb_info,store_index,&name_len,&company_len);

     			//写入名字
       				FS_Write(file_handle_txt, (void*)FMGR_PB_KUANG_BEGIN, strlen(FMGR_PB_KUANG_BEGIN), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)temp_phb_info->Name, name_len, (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)FMGR_PB_KUANG_END, strlen(FMGR_PB_KUANG_END), (U32*) & written_len);
     
     			//写入号码
       				FS_Write(file_handle_txt, (void*)FMGR_PB_GOU_BEGIN, strlen(FMGR_PB_GOU_BEGIN), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)temp_phb_info->Number,(PhoneBook[store_index].tel.length),(U32*) & written_len);
					FS_Write(file_handle_txt, (void*)FMGR_PB_GOU_END, strlen(FMGR_PB_GOU_END), (U32*) & written_len);

                if ((store_index < MAX_PB_PHONE_ENTRIES)&&(store_index>=0))
                {
     			//家庭电话
       				FS_Write(file_handle_txt, (void*)FMGR_PB_GOU_BEGIN, strlen(FMGR_PB_GOU_BEGIN), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)temp_phb_info->num_filed.homeNumber, strlen((const char*)temp_phb_info->num_filed.homeNumber), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)FMGR_PB_GOU_END, strlen(FMGR_PB_GOU_END), (U32*) & written_len);

     			//公司名称
       				FS_Write(file_handle_txt, (void*)FMGR_PB_KUANG_BEGIN, strlen(FMGR_PB_KUANG_BEGIN), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)temp_phb_info->num_filed.companyName, company_len, (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)FMGR_PB_KUANG_END, strlen(FMGR_PB_KUANG_END), (U32*) & written_len);

     			//电子邮箱
       				FS_Write(file_handle_txt, (void*)FMGR_PB_KUANG_BEGIN, strlen(FMGR_PB_KUANG_BEGIN), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)temp_phb_info->num_filed.emailAddress, strlen((const char*)temp_phb_info->num_filed.emailAddress), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)FMGR_PB_KUANG_END, strlen(FMGR_PB_KUANG_END), (U32*) & written_len);

     			//家庭电话
       				FS_Write(file_handle_txt, (void*)FMGR_PB_GOU_BEGIN, strlen(FMGR_PB_GOU_BEGIN), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)temp_phb_info->num_filed.officeNumber, strlen((const char*)temp_phb_info->num_filed.officeNumber), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)FMGR_PB_GOU_END, strlen(FMGR_PB_GOU_END), (U32*) & written_len);

     			//传真号码
       				FS_Write(file_handle_txt, (void*)FMGR_PB_GOU_BEGIN, strlen(FMGR_PB_GOU_BEGIN), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)temp_phb_info->num_filed.faxNumber, strlen((const char*)temp_phb_info->num_filed.faxNumber), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)FMGR_PB_GOU_END, strlen(FMGR_PB_GOU_END), (U32*) & written_len);

     			//生日
       				FS_Write(file_handle_txt, (void*)FMGR_PB_KUANG_BEGIN, strlen(FMGR_PB_KUANG_BEGIN), (U32*) & written_len);
       				memset(buffer_UCS2,0,128);
       				strcpy(buffer_UCS2,temp_phb_info->birth.Year);
       				strcat(buffer_UCS2,"-");
        				strcat(buffer_UCS2,temp_phb_info->birth.Mon);
       				strcat(buffer_UCS2,"-");
       				strcat(buffer_UCS2,temp_phb_info->birth.Day); 				
					FS_Write(file_handle_txt, (void*)buffer_UCS2, strlen(buffer_UCS2), (U32*) & written_len);
					FS_Write(file_handle_txt, (void*)FMGR_PB_KUANG_END, strlen(FMGR_PB_KUANG_END), (U32*) & written_len);
                     }         
                         #ifdef __PHONEBOOK_INPUT__
                                  FS_Write(file_handle, (void*)temp_phb_info, (UINT)sizeof(PHB_OUTPUT_INPUT_STRUCT), (U32*) & written_len);
                         #endif         
                                  FS_Write(file_handle_txt,FMGR_PB_NEW_LINE1,strlen(FMGR_PB_NEW_LINE1),(U32*) & written_len);    
                                  

                                  next_circle:
                                  ;
     				}
     			#ifdef __PHONEBOOK_INPUT__	
   				FS_Close(file_handle);
   			#endif	
   				FS_Close(file_handle_txt);
     }
     else
     {
               FS_Close(file_handle_txt);
               mmi_popup_file_system_error_handler(file_handle_txt);
               return;
     }

//设置文件属性
#if 0
    attr = FS_GetAttributes((U16*)list_path);
    kal_prompt_trace(MOD_SIM,"huzhuhua attr = %x",attr);
    if (attr >= FS_NO_ERROR)
    {
        FS_SetAttributes((U16*)list_path, (U8) (attr | FS_ATTR_READ_ONLY));
    }
#endif
    
   OslMfree(list_path);
   OslMfree(temp_phb_info);
   DisplayPopup(
				    (PU8) GetString(STR_GLOBAL_DONE),
				    IMG_GLOBAL_ACTIVATED, 
				    1, 
				    UI_POPUP_NOTIFYDURATION_TIME, 
				    SUCCESS_TONE
			    );
    GoBack2TheHistory();
}
else
{
	mmi_popup_file_system_error_handler((S32)ret_drv);
       return;
}
}

#if defined(__MMI_PHB_BIRTHDAY_FIELD__) 
extern S8 pbDay[];
extern S8 pbMon[];
extern S8 pbYear[];
#endif 
void construct_pb_output_list(PHB_OUTPUT_INPUT_STRUCT **pb_text_output_para, U16 store_index,U16* name_len,U16* company_len)
{
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    
    S16 pError;
#endif
    PHB_OPTIONAL_IDS_STRUCT *opt_ids = NULL;
    U8  str_dec,pos = 0,len=0,counter = 0;
    U8 temp_field = NULL;
    S8 temp_number[(PB_NUMBER_LEN+1)*ENCODING_LENGTH];
    PHB_OUTPUT_INPUT_STRUCT *pb_text_output =  (PHB_OUTPUT_INPUT_STRUCT*)(*pb_text_output_para);

   temp_field = PhoneBook[store_index].field;

    str_dec = (PhoneBook[store_index].alpha_id.name_dcs);
    mmi_ucs2cpy(pbName, (PS8) PhoneBook[store_index].alpha_id.name);
    mmi_phb_convert_get_ucs2_number(pbNumber, store_index);

    if(str_dec == 0x8)
    {
       UINCODE_UCS2GB((U16*)pb_text_output->Name,(U16*)(PhoneBook[store_index].alpha_id.name),((PhoneBook[store_index].alpha_id.name_length)));

       for(len=0; len<((PhoneBook[store_index].alpha_id.name_length)-counter);)
       {
                if((pb_text_output->Name)[len] == 0x0)
                {
                         	pos = len;
                         	for(;(pos+1)<((PhoneBook[store_index].alpha_id.name_length));pos++)
                                	(pb_text_output->Name)[pos] = (pb_text_output->Name)[pos+1];

                          	(pb_text_output->Name)[pos] = 0x0;
                          	counter++;
                 }
                 else
                 {
                        	len++;
                 }
       }
       (*name_len) = len;
    }
    else if(str_dec == 0x0)
    {
            mmi_ucs2_to_asc((S8*)pb_text_output->Name,(S8*)(PhoneBook[store_index].alpha_id.name));
            (*name_len) = PhoneBook[store_index].alpha_id.name_length;
    }

    mmi_phb_convert_get_ucs2_number((S8*)temp_number, store_index);
    mmi_ucs2_to_asc((S8*)pb_text_output->Number,temp_number);

    if (store_index >= MAX_PB_PHONE_ENTRIES)   
    {
    		#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)   
       		mmi_phb_read_optional_ids(store_index);
        		opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;
        		pb_text_output->callerGroupID = opt_ids->callerGroupID;
    		#endif
    }
    else
    {
        mmi_phb_read_optional_ids(store_index);
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;
        pb_text_output->pictureTagID = opt_ids->pictureTagID;
        pb_text_output->ringToneID = opt_ids->ringToneID;
        pb_text_output->callerGroupID = opt_ids->callerGroupID;

    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)     
    ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError); 

     memcpy(&(pb_text_output->num_filed),&PhoneBookOptionalFields,OPTIONAL_FIELDS_RECORD_SIZE);

     if(GetUCS2Flag((PS8)pb_text_output->num_filed.companyName))
     {
       	UINCODE_UCS2GB((U16*)pb_text_output->num_filed.companyName,(U16*)(PhoneBookOptionalFields.companyName),sizeof((PhoneBookOptionalFields.companyName)));

       	for(len=0; len<(sizeof((PhoneBookOptionalFields.companyName))-counter);)
       	{
               	 if((pb_text_output->num_filed.companyName)[len] == 0x0)
                	{
                         	pos = len;
                         	for(;(pos+1)<sizeof(PhoneBookOptionalFields.companyName);pos++)
                                	(pb_text_output->num_filed.companyName)[pos] = (pb_text_output->num_filed.companyName)[pos+1];

                          	(pb_text_output->num_filed.companyName)[pos] = 0x0;
                          	counter++;
                 	 }
                 	else
                 	{
                        	len++;
                 	}
       	} 
       	(*company_len) = len;
      }      
     else
     {
              mmi_ucs2_to_asc((S8*)(pb_text_output->num_filed.companyName),(S8*)(PhoneBookOptionalFields.companyName));
              (*company_len) = (U16)strlen((const char*)pb_text_output->num_filed.companyName);
     } 
    #endif 

    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        pb_text_output->videoID = mmi_phb_video_get_id_by_index(store_index);
    #endif 

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        mmi_phb_bday_read_data_to_buff(store_index);
        mmi_ucs2_to_asc((S8*)pb_text_output->birth.Year,(S8*)pbYear);
        mmi_ucs2_to_asc((S8*)pb_text_output->birth.Mon,(S8*)pbMon);
        mmi_ucs2_to_asc((S8*)pb_text_output->birth.Day,(S8*)pbDay);
    #endif 
    }
}
#endif

#ifdef __PHONEBOOK_INPUT__
S16 g_mmi_pb_input_highlighted_menu_item;
S16 g_mmi_pb_input_highlighted_menu_item2;
U8 input_state = 0x0;    //sim1,sim2,phone
S8 storagePath_input[(FMGR_MAX_PB_PATH_LEN - MAX_PBBACKUP_NAME_TEXT)*ENCODING_LENGTH] = {0};

void PB_Input_Menu_Handle(void)
{
     U8 state1=0,state2=0;
     state1 =  MTPNP_PFAL_Is_Card1Absent();
     state2 =  MTPNP_PFAL_Is_Card2Absent();
     
    mmi_frm_hide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM1);
    mmi_frm_hide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM2);
    mmi_frm_hide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOPHONE);

    if(state1&&state2)
    {
             mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOPHONE);
             input_state = 0x1;             
    }
    else if(state1&&!state2) 
    {
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM2);
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOPHONE);
            input_state = 0x3;    
    }
    else if(state2&&!state1) 
    {
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM1);
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOPHONE);
            input_state = 0x5;          
    }
    else
    {
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM1);
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM2);
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOPHONE);
            input_state = 0x7;        
    }
}

void PB_Input_Menu_Handle_Second(void)
{    
    mmi_frm_hide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM1);
    mmi_frm_hide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM2);
    mmi_frm_hide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOPHONE);

    if(g_mmi_pb_input_highlighted_menu_item == 0)
    {
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM2);
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOPHONE);          
    }
    else if(g_mmi_pb_input_highlighted_menu_item == 1) 
    {
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM1);
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOPHONE);    
    }
    else
    {
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM1);
            mmi_frm_unhide_menu_item(MENU_ID_PB_INPUT_OPTION_INPUT_TOSIM2);    
    }
}

void mmi_phb_input_highlight(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_pb_input_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_pb_input_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void mmi_phb_option_input_highlight(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryOptionInputFormat, KEY_EVENT_UP);
    SetKeyHandler(EntryOptionInputFormat, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void EntryOptionInputFormatScr2(void)
{
    if(input_state == 0x3 ||input_state == 0x5)
    {
         //直接导入
         mmi_input_pb_comm_handler();
    }
    else
    	EntryOptionInputFormatMenuScr2();
}

void mmi_pb_backup_input_highlight_hdlr(S32 index)
{
     g_mmi_pb_input_highlighted_menu_item = index;
}

void EntryOptionInputFormat(void)
{
    U16 nStrItemList[3];  
    int nNumofItem;      
    U16 nDispAttribute;       
    U8 *guiBuffer;    
    U8 *ItemType[3];
    U8 *subDGSetMenuDataPtrs[3];
    U16 i = 0;
    U16 default_value = 0;

    PB_Input_Menu_Handle();
    if(input_state == 0x1)
    {
         //直接往手机中导入
         mmi_input_pb_comm_handler();
    }
    else
   {   
    	EntryNewScreen(PB_OPTION_INPUT_FIRST_SCREENID, NULL, EntryOptionInputFormat, NULL);

    	guiBuffer = GetCurrGuiBuffer(PB_OPTION_INPUT_FIRST_SCREENID);

    	nDispAttribute = GetDispAttributeOfItem(MENU_ID_PB_INPUT_OPTION_INPUT);
    
    	nNumofItem = GetNumOfChild_Ext(MENU_ID_PB_INPUT_OPTION_INPUT);

    	GetSequenceStringIds_Ext(MENU_ID_PB_INPUT_OPTION_INPUT, nStrItemList);

    	for(i=0;i<3;i++)
    	{
    	     subDGSetMenuDataPtrs[i] =  (U8 *) GetString(nStrItemList[i]);
    	}

    	SetParentHandler(MENU_ID_PB_INPUT_OPTION_INPUT);

    	RegisterHighlightHandler(mmi_pb_backup_input_highlight_hdlr);

    	ConstructHintsList(MENU_ID_PB_INPUT_OPTION_INPUT, ItemType);

    	ShowCategory36Screen(STR_PB_BACKUP_INPUT_FIRST, MAIN_MENU_TITLE_PHONEBOOK_ICON,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, (U8 **) subDGSetMenuDataPtrs, default_value, guiBuffer);

    	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    	SetLeftSoftkeyFunction(EntryOptionInputFormatScr2, KEY_EVENT_UP);
    }
}

void mmi_pb_backup_input_highlight_hdlr2(S32 index)
{
     g_mmi_pb_input_highlighted_menu_item2 = index;
}

void EntryOptionInputFormatMenuScr2(void)
{
    U16 nStrItemList[2];  
    int nNumofItem;      
    U16 nDispAttribute;       
    U8 *guiBuffer;    
    U8 *ItemType[2];
    U8 *subDGSetMenuDataPtrs[2];
    U16 i = 0;
    U16 default_value = 0;

    PB_Input_Menu_Handle_Second();
   
    EntryNewScreen(PB_OPTION_INPUT_SECOND_SCREENID, NULL, EntryOptionInputFormatMenuScr2, NULL);

    guiBuffer = GetCurrGuiBuffer(PB_OPTION_INPUT_SECOND_SCREENID);
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_PB_INPUT_OPTION_INPUT);
    nNumofItem = GetNumOfChild_Ext(MENU_ID_PB_INPUT_OPTION_INPUT);
    GetSequenceStringIds_Ext(MENU_ID_PB_INPUT_OPTION_INPUT, nStrItemList);
    SetParentHandler(MENU_ID_PB_INPUT_OPTION_INPUT);

    for(i=0;i<3;i++)
    {
    	     subDGSetMenuDataPtrs[i] =  (U8 *) GetString(nStrItemList[i]);
    }

    RegisterHighlightHandler(mmi_pb_backup_input_highlight_hdlr2);

    ConstructHintsList(MENU_ID_PB_INPUT_OPTION_INPUT, ItemType);

    ShowCategory36Screen(STR_PB_BACKUP_INPUT_SECOND, MAIN_MENU_TITLE_PHONEBOOK_ICON,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, (U8 **) subDGSetMenuDataPtrs, default_value, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_input_pb_comm_handler, KEY_EVENT_UP);
}

//导入备份文件到sim卡或手机
//导入最好用另外一种方式。
MMI_OWNER_NUMBER_STRUCT PhoneBookFromFile[MAX_PB_ENTRIES];
void mmi_input_pb_comm_handler(void)
{
        S8 filePath[(FMGR_MAX_PB_PATH_LEN+1) * ENCODING_LENGTH];
        FS_HANDLE file_handle;
        U64 len = 0;
        UINT read_len;
        S8  curChr = 0x0;
        int i=0,j=0,k=0;
        S8 temp_name[PB_NAME_LEN] = {0}; 
        S8 temp_num[PB_NUMBER_LEN] = {0};  

        memset(filePath,0,(FMGR_MAX_PB_PATH_LEN+1) * ENCODING_LENGTH);
   //获取全路径     
        kal_wsprintf((kal_wchar*) filePath, "%c:\\%w", MMI_CARD_DRV, FMGR_DEFAULT_FOLDER_PB);
        get_curr_file_fullpath_name((S8*)filePath);

  //读取文件里的数据到buffer
       memset(PhoneBookFromFile,0, sizeof(MMI_OWNER_NUMBER_STRUCT)*MAX_PB_ENTRIES);
       file_handle =  FS_Open((U16*)filePath, FS_READ_ONLY);
       if(file_handle >= 0)
       {
             len = FS_Seek(file_handle, 0, FS_FILE_END);
             FS_Seek(file_handle, 0, FS_FILE_BEGIN);
             while(len>0)
             {
                   FS_Read(file_handle, &curChr, 1, (UINT*)&read_len);
                   if(curChr == 0x5b)
                   {                   
                         FS_Read(file_handle, &curChr, 1, (UINT*)&read_len);
                         while((curChr != 0x5d)&&i<PB_NAME_LEN)
                         {
                                temp_name[i] = curChr;
                                i++;
                         	    FS_Read(file_handle, &curChr, 1, (UINT*)&read_len);
                         }
                         len = len -i -2;
                         
     			   if(GetUCS2Flag((PS8)temp_name))
     				UINCODE_GB2UCS((U16*)PhoneBookFromFile[k].name,(const U8 *)temp_name,PB_NAME_LEN); 
    			   else
              		mmi_asc_to_ucs2((S8*)PhoneBookFromFile[k].name,(S8*)temp_name);

                        memset(temp_name,0, PB_NAME_LEN);	                        
                   }
                   else if(curChr == 0x3c)
                   {
                        FS_Read(file_handle, &curChr, 1, (UINT*)&read_len);
                         while((curChr != 0x3e)&&j<PB_NUMBER_LEN)
                         {
                                 temp_num[j] = curChr;
                                 j++;
                         	    FS_Read(file_handle, &curChr, 1, (UINT*)&read_len);
                         }
                         len = len -j -2;

                       if(k<MAX_PB_ENTRIES)
                       {
     			       mmi_asc_to_ucs2((S8*)PhoneBookFromFile[k].number,(S8*)temp_num);
     			       k++;
     			  }
     			  else
     			  {
     			      //报错
     			  }
                       
     			  memset(temp_num,0, PB_NUMBER_LEN);		
                   }
                   else
                        len--;

                  i = 0; j=0;      
             }
             
             FS_Close(file_handle);
       }
       else
       {
               FS_Close(file_handle);
               mmi_popup_file_system_error_handler(file_handle);
       }      

     //开始导入数据到sim卡或手机
     
}

void check_is_pb_input_folder_created(void)
{
    FS_HANDLE file_handle;
    
    file_handle = FS_Open((U16*)storagePath_input, FS_READ_ONLY);
    if(file_handle<0)
    {
           //create folder
          kal_prompt_trace(MOD_SIM,"huzhuhua create folder !");
          FS_Close( file_handle);
          FS_CreateDir((U16*)storagePath_input);
    }
    else
    {
            FS_Close( file_handle);
    }
}

void mmi_pb_input_get_full_path(S16 drv_letter)
{
    kal_wsprintf(
        (kal_wchar*) storagePath_input,
        "%c:\\%w",
        drv_letter,
        FMGR_DEFAULT_FOLDER_PB);
}

void pb_input_init(void)
{
    mmi_pb_input_get_full_path((S16)MMI_CARD_DRV);
    check_is_pb_input_folder_created();
}
void mmi_pb_input_filename_callback(void *fullname, int is_short)
{
    DeleteScreenIfPresent(PB_INPUT_SCREENID);
    GoBackHistory();
}

void pb_input_empty_list_callback(void)
{
    DeleteScreenIfPresent(PB_INPUT_SCREENID);
    GoBackHistory();
}
 
void mmi_pb_input_entry(void)
{
    FMGR_FILTER filter;

     #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            DisplayPopup((PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
            return;
        }
    #endif 
    
    if (FS_NO_ERROR != FS_GetDevStatus(MMI_CARD_DRV ,FS_MOUNT_STATE_ENUM))
    {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    Slave_g_phb_mass_op_abort= FALSE;
    if(MTPNP_PFAL_Phb_IsReady()==MTPNP_FALSE)
#else  
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif 
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_entry_not_ready(STR_ID_PHB_PROCESSING_USIM);
    }
#endif 
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif 
    else
    {
    EntryNewScreen(PB_INPUT_SCREENID, NULL, mmi_pb_input_entry, NULL); 
    
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_EBOOK_TXT);

    mmi_pb_input_get_full_path((S16)MMI_CARD_DRV);
    mmi_fmgr_select_path_and_enter(
        APP_PB_INPUT,
        FMGR_SELECT_BROWSE,
        filter,
        (PS8) storagePath_input, 
        mmi_pb_input_filename_callback);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}

S32 mmi_get_total_countof_pb_input_file()
{
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    UI_character_type filename[PB_NAME_LEN*ENCODING_LENGTH];
    U8 count = 0;
    S8 path[PB_NAME_LEN * ENCODING_LENGTH];

    mmi_ucs2cpy(
        (S8*) path,
        (S8*) storagePath_input);

   mmi_ucs2cat( (S8*) path,(S8*)L"*.txt");

    if ((fh_cur = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (U16*) filename,
                    60 * ENCODING_LENGTH)) >= 0)
    {
        do
        {

            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                count++;
                break;
            }
        } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, 60 * ENCODING_LENGTH) ==
                  FS_NO_ERROR));
        FS_FindClose(fh_cur);
    }
    return count;
}


U16 mmi_pb_input_get_menuId(void)
{
    S16 count_no_of_nfo_file;

    count_no_of_nfo_file = mmi_get_total_countof_pb_input_file();
    if (count_no_of_nfo_file <= 0)
    {
        return MENU_ID_PB_INPUT_OPTION;
    }
    else
    {
        return MENU_ID_PB_INPUT_OPTION;
    }
}
#endif

#if !defined(__SP_SERVICE_LM__)&&defined(__PHONEBOOK_OUTPUT_INPUT__)
#define INVALID_GB_INNER_CODE   0x0000 //0xA0A0      /* 非法的内码 */ 
const U16 UniCodeToGBTable[]= 
{
	0xD2BB,
	0xB6A1,
	INVALID_GB_INNER_CODE,
	0xC6DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDF2,
	0xD5C9,
	0xC8FD,
	0xC9CF,
	0xCFC2,
	0xD8A2,
	0xB2BB,
	0xD3EB,
	INVALID_GB_INNER_CODE,
	0xD8A4,
	0xB3F3,
	INVALID_GB_INNER_CODE,
	0xD7A8,
	0xC7D2,
	0xD8A7,
	0xCAC0,
	INVALID_GB_INNER_CODE,
	0xC7F0,
	0xB1FB,
	0xD2B5,
	0xB4D4,
	0xB6AB,
	0xCBBF,
	0xD8A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6AA,
	INVALID_GB_INNER_CODE,
	0xC1BD,
	0xD1CF,
	INVALID_GB_INNER_CODE,
	0xC9A5,
	0xD8AD,
	INVALID_GB_INNER_CODE,
	0xB8F6,
	0xD1BE,
	0xE3DC,
	0xD6D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7E1,
	INVALID_GB_INNER_CODE,
	0xB4AE,
	INVALID_GB_INNER_CODE,
	0xC1D9,
	INVALID_GB_INNER_CODE,
	0xD8BC,
	INVALID_GB_INNER_CODE,
	0xCDE8,
	0xB5A4,
	0xCEAA,
	0xD6F7,
	INVALID_GB_INNER_CODE,
	0xC0F6,
	0xBED9,
	0xD8AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4CB,
	INVALID_GB_INNER_CODE,
	0xBEC3,
	INVALID_GB_INNER_CODE,
	0xD8B1,
	0xC3B4,
	0xD2E5,
	INVALID_GB_INNER_CODE,
	0xD6AE,
	0xCEDA,
	0xD5A7,
	0xBAF5,
	0xB7A6,
	0xC0D6,
	INVALID_GB_INNER_CODE,
	0xC6B9,
	0xC5D2,
	0xC7C7,
	INVALID_GB_INNER_CODE,
	0xB9D4,
	INVALID_GB_INNER_CODE,
	0xB3CB,
	0xD2D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8BF,
	0xBEC5,
	0xC6F2,
	0xD2B2,
	0xCFB0,
	0xCFE7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAE9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2F2,
	0xC2D2,
	INVALID_GB_INNER_CODE,
	0xC8E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1CB,
	INVALID_GB_INNER_CODE,
	0xD3E8,
	0xD5F9,
	INVALID_GB_INNER_CODE,
	0xCAC2,
	0xB6FE,
	0xD8A1,
	0xD3DA,
	0xBFF7,
	INVALID_GB_INNER_CODE,
	0xD4C6,
	0xBBA5,
	0xD8C1,
	0xCEE5,
	0xBEAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8A8,
	INVALID_GB_INNER_CODE,
	0xD1C7,
	0xD0A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8BD,
	0xD9EF,
	0xCDF6,
	0xBFBA,
	INVALID_GB_INNER_CODE,
	0xBDBB,
	0xBAA5,
	0xD2E0,
	0xB2FA,
	0xBAE0,
	0xC4B6,
	INVALID_GB_INNER_CODE,
	0xCFED,
	0xBEA9,
	0xCDA4,
	0xC1C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7D7,
	0xD9F1,
	INVALID_GB_INNER_CODE,
	0xD9F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8CB,
	0xD8E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2DA,
	0xCAB2,
	0xC8CA,
	0xD8EC,
	0xD8EA,
	0xD8C6,
	0xBDF6,
	0xC6CD,
	0xB3F0,
	INVALID_GB_INNER_CODE,
	0xD8EB,
	0xBDF1,
	0xBDE9,
	INVALID_GB_INNER_CODE,
	0xC8D4,
	0xB4D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2D8,
	INVALID_GB_INNER_CODE,
	0xB2D6,
	0xD7D0,
	0xCACB,
	0xCBFB,
	0xD5CC,
	0xB8B6,
	0xCFC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9DA,
	0xD8F0,
	0xC7AA,
	INVALID_GB_INNER_CODE,
	0xD8EE,
	INVALID_GB_INNER_CODE,
	0xB4FA,
	0xC1EE,
	0xD2D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8ED,
	INVALID_GB_INNER_CODE,
	0xD2C7,
	0xD8EF,
	0xC3C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1F6,
	INVALID_GB_INNER_CODE,
	0xD6D9,
	0xD8F2,
	INVALID_GB_INNER_CODE,
	0xD8F5,
	0xBCFE,
	0xBCDB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8CE,
	INVALID_GB_INNER_CODE,
	0xB7DD,
	INVALID_GB_INNER_CODE,
	0xB7C2,
	INVALID_GB_INNER_CODE,
	0xC6F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8F8,
	0xD2C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEE9,
	0xBCBF,
	0xB7FC,
	0xB7A5,
	0xD0DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6DA,
	0xD3C5,
	0xBBEF,
	0xBBE1,
	0xD8F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9A1,
	0xCEB0,
	0xB4AB,
	INVALID_GB_INNER_CODE,
	0xD8F3,
	INVALID_GB_INNER_CODE,
	0xC9CB,
	0xD8F6,
	0xC2D7,
	0xD8F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEB1,
	0xD8F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2AE,
	0xB9C0,
	INVALID_GB_INNER_CODE,
	0xD9A3,
	INVALID_GB_INNER_CODE,
	0xB0E9,
	INVALID_GB_INNER_CODE,
	0xC1E6,
	INVALID_GB_INNER_CODE,
	0xC9EC,
	INVALID_GB_INNER_CODE,
	0xCBC5,
	INVALID_GB_INNER_CODE,
	0xCBC6,
	0xD9A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEBB,
	0xB5CD,
	0xD7A1,
	0xD7F4,
	0xD3D3,
	INVALID_GB_INNER_CODE,
	0xCCE5,
	INVALID_GB_INNER_CODE,
	0xBACE,
	INVALID_GB_INNER_CODE,
	0xD9A2,
	0xD9DC,
	0xD3E0,
	0xD8FD,
	0xB7F0,
	0xD7F7,
	0xD8FE,
	0xD8FA,
	0xD9A1,
	0xC4E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3B6,
	0xD8F4,
	0xD9DD,
	INVALID_GB_INNER_CODE,
	0xD8FB,
	INVALID_GB_INNER_CODE,
	0xC5E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1F0,
	0xB0DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCD1,
	0xD9A6,
	INVALID_GB_INNER_CODE,
	0xD9A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9AC,
	0xD9AE,
	INVALID_GB_INNER_CODE,
	0xD9AB,
	0xCAB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9A9,
	0xD6B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3DE,
	0xD9A8,
	INVALID_GB_INNER_CODE,
	0xC0FD,
	INVALID_GB_INNER_CODE,
	0xCACC,
	INVALID_GB_INNER_CODE,
	0xD9AA,
	INVALID_GB_INNER_CODE,
	0xD9A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9A9,
	INVALID_GB_INNER_CODE,
	0xD2C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2C2,
	INVALID_GB_INNER_CODE,
	0xBDC4,
	0xD5EC,
	0xB2E0,
	0xC7C8,
	0xBFEB,
	0xD9AD,
	INVALID_GB_INNER_CODE,
	0xD9AF,
	INVALID_GB_INNER_CODE,
	0xCEEA,
	0xBAEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4D9,
	0xB6ED,
	0xD9B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9DE,
	0xC7CE,
	0xC0FE,
	0xD9B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBD7,
	0xB7FD,
	INVALID_GB_INNER_CODE,
	0xD9B5,
	INVALID_GB_INNER_CODE,
	0xD9B7,
	0xB1A3,
	0xD3E1,
	0xD9B9,
	INVALID_GB_INNER_CODE,
	0xD0C5,
	INVALID_GB_INNER_CODE,
	0xD9B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9B1,
	INVALID_GB_INNER_CODE,
	0xD9B2,
	0xC1A9,
	0xD9B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCF3,
	0xD0DE,
	0xB8A9,
	INVALID_GB_INNER_CODE,
	0xBEE3,
	INVALID_GB_INNER_CODE,
	0xD9BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9BA,
	INVALID_GB_INNER_CODE,
	0xB0B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9C4,
	0xB1B6,
	INVALID_GB_INNER_CODE,
	0xD9BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5B9,
	INVALID_GB_INNER_CODE,
	0xBEF3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCC8,
	0xBAF2,
	0xD2D0,
	INVALID_GB_INNER_CODE,
	0xD9C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDE8,
	INVALID_GB_INNER_CODE,
	0xB3AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9C5,
	0xBEEB,
	INVALID_GB_INNER_CODE,
	0xD9C6,
	0xD9BB,
	0xC4DF,
	INVALID_GB_INNER_CODE,
	0xD9BE,
	0xD9C1,
	0xD9C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5AE,
	INVALID_GB_INNER_CODE,
	0xD6B5,
	INVALID_GB_INNER_CODE,
	0xC7E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCD9,
	0xD9CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9BC,
	INVALID_GB_INNER_CODE,
	0xD9CB,
	0xC6AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7F6,
	INVALID_GB_INNER_CODE,
	0xCDA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5BC,
	0xCDB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9C7,
	0xB3A5,
	0xBFFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4F6,
	INVALID_GB_INNER_CODE,
	0xD9CE,
	INVALID_GB_INNER_CODE,
	0xD9CF,
	0xB4A2,
	0xD9D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9D1,
	0xC9B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFF1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9D6,
	0xC9AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9D5,
	0xD9D4,
	0xD9D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBDB,
	INVALID_GB_INNER_CODE,
	0xBDA9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9D3,
	0xD9D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6F9,
	0xD8A3,
	0xD4CA,
	INVALID_GB_INNER_CODE,
	0xD4AA,
	0xD0D6,
	0xB3E4,
	0xD5D7,
	INVALID_GB_INNER_CODE,
	0xCFC8,
	0xB9E2,
	INVALID_GB_INNER_CODE,
	0xBFCB,
	INVALID_GB_INNER_CODE,
	0xC3E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDC3,
	0xD9EE,
	0xD9F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5B3,
	INVALID_GB_INNER_CODE,
	0xB6B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEA4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0CB,
	0xB9AB,
	0xC1F9,
	0xD9E2,
	INVALID_GB_INNER_CODE,
	0xC0BC,
	0xB9B2,
	INVALID_GB_INNER_CODE,
	0xB9D8,
	0xD0CB,
	0xB1F8,
	0xC6E4,
	0xBEDF,
	0xB5E4,
	0xD7C8,
	INVALID_GB_INNER_CODE,
	0xD1F8,
	0xBCE6,
	0xCADE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCBD,
	0xD9E6,
	0xD8E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8D4,
	0xC8BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2E1,
	0xD4D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3E1,
	0xDAA2,
	0xC8DF,
	INVALID_GB_INNER_CODE,
	0xD0B4,
	INVALID_GB_INNER_CODE,
	0xBEFC,
	0xC5A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9DA,
	INVALID_GB_INNER_CODE,
	0xDAA3,
	INVALID_GB_INNER_CODE,
	0xD4A9,
	0xDAA4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9FB,
	0xB6AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7EB,
	0xB1F9,
	0xD9FC,
	0xB3E5,
	0xBEF6,
	INVALID_GB_INNER_CODE,
	0xBFF6,
	0xD2B1,
	0xC0E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6B3,
	0xD9FE,
	0xD9FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEBB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6E0,
	INVALID_GB_INNER_CODE,
	0xD7BC,
	0xDAA1,
	INVALID_GB_INNER_CODE,
	0xC1B9,
	INVALID_GB_INNER_CODE,
	0xB5F2,
	0xC1E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCF5,
	INVALID_GB_INNER_CODE,
	0xB4D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1DD,
	INVALID_GB_INNER_CODE,
	0xC4FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCB8,
	0xB7B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9EC,
	INVALID_GB_INNER_CODE,
	0xC6BE,
	INVALID_GB_INNER_CODE,
	0xBFAD,
	0xBBCB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5CA,
	INVALID_GB_INNER_CODE,
	0xDBC9,
	0xD0D7,
	INVALID_GB_INNER_CODE,
	0xCDB9,
	0xB0BC,
	0xB3F6,
	0xBBF7,
	0xDBCA,
	0xBAAF,
	INVALID_GB_INNER_CODE,
	0xD4E4,
	0xB5B6,
	0xB5F3,
	0xD8D6,
	0xC8D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7D6,
	0xC7D0,
	0xD8D7,
	INVALID_GB_INNER_CODE,
	0xBFAF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBBB,
	0xD8D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0CC,
	0xBBAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBBE,
	0xC1D0,
	0xC1F5,
	0xD4F2,
	0xB8D5,
	0xB4B4,
	INVALID_GB_INNER_CODE,
	0xB3F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5D9,
	0xC0FB,
	INVALID_GB_INNER_CODE,
	0xB1F0,
	INVALID_GB_INNER_CODE,
	0xD8D9,
	0xB9CE,
	INVALID_GB_INNER_CODE,
	0xB5BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6C6,
	0xCBA2,
	0xC8AF,
	0xC9B2,
	0xB4CC,
	0xBFCC,
	INVALID_GB_INNER_CODE,
	0xB9F4,
	INVALID_GB_INNER_CODE,
	0xD8DB,
	0xD8DC,
	0xB6E7,
	0xBCC1,
	0xCCEA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFF7,
	INVALID_GB_INNER_CODE,
	0xD8DD,
	0xC7B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9D0,
	0xBDA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCDE,
	INVALID_GB_INNER_CODE,
	0xC6CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8E0,
	INVALID_GB_INNER_CODE,
	0xD8DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0FE,
	INVALID_GB_INNER_CODE,
	0xBEE7,
	INVALID_GB_INNER_CODE,
	0xCAA3,
	0xBCF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8E2,
	INVALID_GB_INNER_CODE,
	0xBDCB,
	INVALID_GB_INNER_CODE,
	0xD8E4,
	0xD8E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1A6,
	INVALID_GB_INNER_CODE,
	0xC8B0,
	0xB0EC,
	0xB9A6,
	0xBCD3,
	0xCEF1,
	0xDBBD,
	0xC1D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6AF,
	0xD6FA,
	0xC5AC,
	0xBDD9,
	0xDBBE,
	0xDBBF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0F8,
	0xBEA2,
	0xC0CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBC0,
	0xCAC6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3C2,
	INVALID_GB_INNER_CODE,
	0xC3E3,
	INVALID_GB_INNER_CODE,
	0xD1AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBC2,
	INVALID_GB_INNER_CODE,
	0xC0D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBC3,
	INVALID_GB_INNER_CODE,
	0xBFB1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9E8,
	0xC9D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9B4,
	0xCEF0,
	0xD4C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0FC,
	0xB4D2,
	INVALID_GB_INNER_CODE,
	0xD0D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9E9,
	INVALID_GB_INNER_CODE,
	0xDECB,
	0xD9EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8B0,
	0xBBAF,
	0xB1B1,
	INVALID_GB_INNER_CODE,
	0xB3D7,
	0xD8CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDB3,
	0xBFEF,
	INVALID_GB_INNER_CODE,
	0xCFBB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6A5,
	0xC7F8,
	0xD2BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8D2,
	0xC4E4,
	INVALID_GB_INNER_CODE,
	0xCAAE,
	INVALID_GB_INNER_CODE,
	0xC7A7,
	INVALID_GB_INNER_CODE,
	0xD8A6,
	INVALID_GB_INNER_CODE,
	0xC9FD,
	0xCEE7,
	0xBBDC,
	0xB0EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBAA,
	0xD0AD,
	INVALID_GB_INNER_CODE,
	0xB1B0,
	0xD7E4,
	0xD7BF,
	INVALID_GB_INNER_CODE,
	0xB5A5,
	0xC2F4,
	0xC4CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2A9,
	INVALID_GB_INNER_CODE,
	0xB2B7,
	INVALID_GB_INNER_CODE,
	0xB1E5,
	0xDFB2,
	0xD5BC,
	0xBFA8,
	0xC2AC,
	0xD8D5,
	0xC2B1,
	INVALID_GB_INNER_CODE,
	0xD8D4,
	0xCED4,
	INVALID_GB_INNER_CODE,
	0xDAE0,
	INVALID_GB_INNER_CODE,
	0xCEC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8B4,
	0xC3AE,
	0xD3A1,
	0xCEA3,
	INVALID_GB_INNER_CODE,
	0xBCB4,
	0xC8B4,
	0xC2D1,
	INVALID_GB_INNER_CODE,
	0xBEED,
	0xD0B6,
	INVALID_GB_INNER_CODE,
	0xDAE1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3A7,
	INVALID_GB_INNER_CODE,
	0xB6F2,
	0xCCFC,
	0xC0FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0F7,
	INVALID_GB_INNER_CODE,
	0xD1B9,
	0xD1E1,
	0xD8C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0E5,
	INVALID_GB_INNER_CODE,
	0xBAF1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8C8,
	INVALID_GB_INNER_CODE,
	0xD4AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFE1,
	0xD8C9,
	INVALID_GB_INNER_CODE,
	0xD8CA,
	0xCFC3,
	INVALID_GB_INNER_CODE,
	0xB3F8,
	0xBEC7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBCC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFD8,
	INVALID_GB_INNER_CODE,
	0xC8FE,
	0xB2CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3D6,
	0xB2E6,
	0xBCB0,
	0xD3D1,
	0xCBAB,
	0xB7B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAE5,
	INVALID_GB_INNER_CODE,
	0xC8A1,
	0xCADC,
	0xB1E4,
	0xD0F0,
	INVALID_GB_INNER_CODE,
	0xC5D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBC5,
	0xB5FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFDA,
	0xB9C5,
	0xBEE4,
	0xC1ED,
	INVALID_GB_INNER_CODE,
	0xDFB6,
	0xDFB5,
	0xD6BB,
	0xBDD0,
	0xD5D9,
	0xB0C8,
	0xB6A3,
	0xBFC9,
	0xCCA8,
	0xDFB3,
	0xCAB7,
	0xD3D2,
	INVALID_GB_INNER_CODE,
	0xD8CF,
	0xD2B6,
	0xBAC5,
	0xCBBE,
	0xCCBE,
	INVALID_GB_INNER_CODE,
	0xDFB7,
	0xB5F0,
	0xDFB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3F5,
	INVALID_GB_INNER_CODE,
	0xB3D4,
	0xB8F7,
	INVALID_GB_INNER_CODE,
	0xDFBA,
	INVALID_GB_INNER_CODE,
	0xBACF,
	0xBCAA,
	0xB5F5,
	INVALID_GB_INNER_CODE,
	0xCDAC,
	0xC3FB,
	0xBAF3,
	0xC0F4,
	0xCDC2,
	0xCFF2,
	0xDFB8,
	0xCFC5,
	INVALID_GB_INNER_CODE,
	0xC2C0,
	0xDFB9,
	0xC2F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEFD,
	INVALID_GB_INNER_CODE,
	0xC1DF,
	0xCDCC,
	0xD2F7,
	0xB7CD,
	0xDFC1,
	INVALID_GB_INNER_CODE,
	0xDFC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7F1,
	0xB0C9,
	0xB6D6,
	0xB7D4,
	INVALID_GB_INNER_CODE,
	0xBAAC,
	0xCCFD,
	0xBFD4,
	0xCBB1,
	0xC6F4,
	INVALID_GB_INNER_CODE,
	0xD6A8,
	0xDFC5,
	INVALID_GB_INNER_CODE,
	0xCEE2,
	0xB3B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEFC,
	0xB4B5,
	INVALID_GB_INNER_CODE,
	0xCEC7,
	0xBAF0,
	INVALID_GB_INNER_CODE,
	0xCEE1,
	INVALID_GB_INNER_CODE,
	0xD1BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4F4,
	INVALID_GB_INNER_CODE,
	0xB3CA,
	INVALID_GB_INNER_CODE,
	0xB8E6,
	0xDFBB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4C5,
	INVALID_GB_INNER_CODE,
	0xDFBC,
	0xDFBD,
	0xDFBE,
	0xC5BB,
	0xDFBF,
	0xDFC2,
	0xD4B1,
	0xDFC3,
	INVALID_GB_INNER_CODE,
	0xC7BA,
	0xCED8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4D8,
	INVALID_GB_INNER_CODE,
	0xDFCA,
	INVALID_GB_INNER_CODE,
	0xDFCF,
	INVALID_GB_INNER_CODE,
	0xD6DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFC9,
	0xDFDA,
	0xCEB6,
	INVALID_GB_INNER_CODE,
	0xBAC7,
	0xDFCE,
	0xDFC8,
	0xC5DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9EB,
	0xBAF4,
	0xC3FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBED7,
	INVALID_GB_INNER_CODE,
	0xDFC6,
	INVALID_GB_INNER_CODE,
	0xDFCD,
	INVALID_GB_INNER_CODE,
	0xC5D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5A6,
	0xBACD,
	INVALID_GB_INNER_CODE,
	0xBECC,
	0xD3BD,
	0xB8C0,
	INVALID_GB_INNER_CODE,
	0xD6E4,
	INVALID_GB_INNER_CODE,
	0xDFC7,
	0xB9BE,
	0xBFA7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1FC,
	0xDFCB,
	0xDFCC,
	INVALID_GB_INNER_CODE,
	0xDFD0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFDB,
	0xDFE5,
	INVALID_GB_INNER_CODE,
	0xDFD7,
	0xDFD6,
	0xD7C9,
	0xDFE3,
	0xDFE4,
	0xE5EB,
	0xD2A7,
	0xDFD2,
	INVALID_GB_INNER_CODE,
	0xBFA9,
	INVALID_GB_INNER_CODE,
	0xD4DB,
	INVALID_GB_INNER_CODE,
	0xBFC8,
	0xDFD4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFCC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFDD,
	INVALID_GB_INNER_CODE,
	0xD1CA,
	INVALID_GB_INNER_CODE,
	0xDFDE,
	0xB0A7,
	0xC6B7,
	0xDFD3,
	INVALID_GB_INNER_CODE,
	0xBAE5,
	INVALID_GB_INNER_CODE,
	0xB6DF,
	0xCDDB,
	0xB9FE,
	0xD4D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFDF,
	0xCFEC,
	0xB0A5,
	0xDFE7,
	0xDFD1,
	0xD1C6,
	0xDFD5,
	0xDFD8,
	0xDFD9,
	0xDFDC,
	INVALID_GB_INNER_CODE,
	0xBBA9,
	INVALID_GB_INNER_CODE,
	0xDFE0,
	0xDFE1,
	INVALID_GB_INNER_CODE,
	0xDFE2,
	0xDFE6,
	0xDFE8,
	0xD3B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8E7,
	0xC5B6,
	0xDFEA,
	0xC9DA,
	0xC1A8,
	0xC4C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFDE,
	0xCFF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5DC,
	0xDFEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2B8,
	INVALID_GB_INNER_CODE,
	0xBADF,
	0xDFEC,
	INVALID_GB_INNER_CODE,
	0xDBC1,
	INVALID_GB_INNER_CODE,
	0xD1E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBF4,
	0xB4BD,
	INVALID_GB_INNER_CODE,
	0xB0A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFF1,
	0xCCC6,
	0xDFF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFE9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFEB,
	INVALID_GB_INNER_CODE,
	0xDFEF,
	0xDFF0,
	0xBBBD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFF3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFF4,
	INVALID_GB_INNER_CODE,
	0xBBA3,
	INVALID_GB_INNER_CODE,
	0xCADB,
	0xCEA8,
	0xE0A7,
	0xB3AA,
	INVALID_GB_INNER_CODE,
	0xE0A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFFE,
	INVALID_GB_INNER_CODE,
	0xCDD9,
	0xDFFC,
	INVALID_GB_INNER_CODE,
	0xDFFA,
	INVALID_GB_INNER_CODE,
	0xBFD0,
	0xD7C4,
	INVALID_GB_INNER_CODE,
	0xC9CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFF8,
	0xB0A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFFD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFFB,
	0xE0A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6A1,
	0xC9B6,
	0xC0B2,
	0xDFF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5BE,
	INVALID_GB_INNER_CODE,
	0xD8C4,
	0xDFF9,
	0xC4F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0A3,
	0xE0A4,
	0xE0A5,
	0xD0A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0B4,
	0xCCE4,
	INVALID_GB_INNER_CODE,
	0xE0B1,
	INVALID_GB_INNER_CODE,
	0xBFA6,
	0xE0AF,
	0xCEB9,
	0xE0AB,
	0xC9C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0AE,
	0xE0AE,
	0xBAED,
	0xBAB0,
	0xE0A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFF6,
	INVALID_GB_INNER_CODE,
	0xE0B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4AD,
	0xE0B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFB2,
	0xBAC8,
	INVALID_GB_INNER_CODE,
	0xE0B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0AC,
	INVALID_GB_INNER_CODE,
	0xD4FB,
	INVALID_GB_INNER_CODE,
	0xDFF7,
	INVALID_GB_INNER_CODE,
	0xC5E7,
	INVALID_GB_INNER_CODE,
	0xE0AD,
	INVALID_GB_INNER_CODE,
	0xD3F7,
	INVALID_GB_INNER_CODE,
	0xE0B6,
	0xE0B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0C4,
	0xD0E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0C9,
	0xE0CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0BE,
	0xE0AA,
	0xC9A4,
	0xE0C1,
	INVALID_GB_INNER_CODE,
	0xE0B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAC8,
	0xE0C3,
	INVALID_GB_INNER_CODE,
	0xE0B5,
	INVALID_GB_INNER_CODE,
	0xCECB,
	INVALID_GB_INNER_CODE,
	0xCBC3,
	0xE0CD,
	0xE0C6,
	0xE0C2,
	INVALID_GB_INNER_CODE,
	0xE0CB,
	INVALID_GB_INNER_CODE,
	0xE0BA,
	0xE0BF,
	0xE0C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0C7,
	0xE0C8,
	INVALID_GB_INNER_CODE,
	0xE0CC,
	INVALID_GB_INNER_CODE,
	0xE0BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBD4,
	0xE0D5,
	INVALID_GB_INNER_CODE,
	0xE0D6,
	0xE0D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0D0,
	0xBCCE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0D1,
	INVALID_GB_INNER_CODE,
	0xB8C2,
	0xD8C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0CF,
	0xE0BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0D4,
	0xE0D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0DC,
	0xE0D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6F6,
	0xB3B0,
	INVALID_GB_INNER_CODE,
	0xD7EC,
	INVALID_GB_INNER_CODE,
	0xCBBB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0DA,
	INVALID_GB_INNER_CODE,
	0xCEFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAD9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0E1,
	0xE0DD,
	0xD2AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0DB,
	0xE0D9,
	0xE0DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0DE,
	INVALID_GB_INNER_CODE,
	0xE0E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6F7,
	0xD8AC,
	0xD4EB,
	0xE0E6,
	0xCAC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0E7,
	0xE0E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0E9,
	0xE0E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBABF,
	0xCCE7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFF9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7F4,
	0xCBC4,
	INVALID_GB_INNER_CODE,
	0xE0EE,
	0xBBD8,
	0xD8B6,
	0xD2F2,
	0xE0EF,
	0xCDC5,
	INVALID_GB_INNER_CODE,
	0xB6DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0F1,
	INVALID_GB_INNER_CODE,
	0xD4B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0A7,
	0xB4D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEA7,
	0xE0F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0F2,
	0xB9CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9FA,
	0xCDBC,
	0xE0F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6D4,
	0xE0F4,
	INVALID_GB_INNER_CODE,
	0xD4B2,
	INVALID_GB_INNER_CODE,
	0xC8A6,
	0xE0F6,
	0xE0F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAA5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4DA,
	0xDBD7,
	0xDBD9,
	INVALID_GB_INNER_CODE,
	0xDBD8,
	0xB9E7,
	0xDBDC,
	0xDBDD,
	0xB5D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBDA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBDB,
	0xB3A1,
	0xDBDF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBF8,
	INVALID_GB_INNER_CODE,
	0xD6B7,
	INVALID_GB_INNER_CODE,
	0xDBE0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEF9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7BB,
	INVALID_GB_INNER_CODE,
	0xDBD0,
	0xCCAE,
	0xBFB2,
	0xBBB5,
	0xD7F8,
	0xBFD3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFE9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCE1,
	0xCCB3,
	0xDBDE,
	0xB0D3,
	0xCEEB,
	0xB7D8,
	0xD7B9,
	0xC6C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0A4,
	INVALID_GB_INNER_CODE,
	0xCCB9,
	INVALID_GB_INNER_CODE,
	0xDBE7,
	0xDBE1,
	0xC6BA,
	0xDBE3,
	INVALID_GB_INNER_CODE,
	0xDBE8,
	INVALID_GB_INNER_CODE,
	0xC5F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBEA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBE9,
	0xBFC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBE6,
	0xDBE5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4B9,
	0xC0AC,
	0xC2A2,
	0xDBE2,
	0xDBE4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0CD,
	0xDBED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0DD,
	0xDBF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBF3,
	0xDBD2,
	0xB9B8,
	0xD4AB,
	0xDBEC,
	INVALID_GB_INNER_CODE,
	0xBFD1,
	0xDBF0,
	INVALID_GB_INNER_CODE,
	0xDBD1,
	INVALID_GB_INNER_CODE,
	0xB5E6,
	INVALID_GB_INNER_CODE,
	0xDBEB,
	0xBFE5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBEE,
	INVALID_GB_INNER_CODE,
	0xDBF1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBF9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9A1,
	0xB0A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3C7,
	0xDBEF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBF8,
	INVALID_GB_INNER_CODE,
	0xC6D2,
	0xDBF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBF5,
	0xDBF7,
	0xDBF6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBFE,
	INVALID_GB_INNER_CODE,
	0xD3F2,
	0xB2BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBFD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCA4,
	INVALID_GB_INNER_CODE,
	0xDBFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBFC,
	0xC5E0,
	0xBBF9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCA5,
	INVALID_GB_INNER_CODE,
	0xCCC3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6D1,
	0xDDC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCA1,
	INVALID_GB_INNER_CODE,
	0xDCA2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCA7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCA6,
	INVALID_GB_INNER_CODE,
	0xDCA9,
	0xB1A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFB0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCA8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBFA,
	0xEBF3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBDC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCAA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCEE,
	0xDCAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBD3,
	INVALID_GB_INNER_CODE,
	0xDCAF,
	0xDCAC,
	INVALID_GB_INNER_CODE,
	0xBEB3,
	INVALID_GB_INNER_CODE,
	0xCAFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCAD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9CA,
	0xC4B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7BD,
	0xDCAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4F6,
	0xD0E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4AB,
	0xB6D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBD4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBD5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBD6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBABE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCABF,
	0xC8C9,
	INVALID_GB_INNER_CODE,
	0xD7B3,
	INVALID_GB_INNER_CODE,
	0xC9F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFC7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2BA,
	INVALID_GB_INNER_CODE,
	0xB4A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8B4,
	INVALID_GB_INNER_CODE,
	0xCFC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9E7,
	0xCFA6,
	0xCDE2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9ED,
	0xB6E0,
	INVALID_GB_INNER_CODE,
	0xD2B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2B9,
	0xE2B7,
	INVALID_GB_INNER_CODE,
	0xB4F3,
	INVALID_GB_INNER_CODE,
	0xCCEC,
	0xCCAB,
	0xB7F2,
	INVALID_GB_INNER_CODE,
	0xD8B2,
	0xD1EB,
	0xBABB,
	INVALID_GB_INNER_CODE,
	0xCAA7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2C4,
	0xBFE4,
	0xBCD0,
	0xB6E1,
	INVALID_GB_INNER_CODE,
	0xDEC5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEC6,
	0xDBBC,
	INVALID_GB_INNER_CODE,
	0xD1D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6E6,
	0xC4CE,
	0xB7EE,
	INVALID_GB_INNER_CODE,
	0xB7DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFFC,
	0xD7E0,
	INVALID_GB_INNER_CODE,
	0xC6F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1BC,
	0xDEC8,
	0xBDB1,
	0xCCD7,
	0xDECA,
	INVALID_GB_INNER_CODE,
	0xDEC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5EC,
	INVALID_GB_INNER_CODE,
	0xC9DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5AE,
	0xC5AB,
	INVALID_GB_INNER_CODE,
	0xC4CC,
	INVALID_GB_INNER_CODE,
	0xBCE9,
	0xCBFD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAC3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5F9,
	0xC8E7,
	0xE5FA,
	0xCDFD,
	INVALID_GB_INNER_CODE,
	0xD7B1,
	0xB8BE,
	0xC2E8,
	INVALID_GB_INNER_CODE,
	0xC8D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6CA,
	0xBCCB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1FD,
	0xE6A1,
	INVALID_GB_INNER_CODE,
	0xC3EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5FE,
	0xE6A5,
	0xCDD7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7C1,
	0xE5FC,
	0xE5FD,
	0xE6A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4DD,
	0xE6A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3C3,
	INVALID_GB_INNER_CODE,
	0xC6DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6A2,
	0xCABC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDE3,
	0xB9C3,
	0xE6A6,
	0xD0D5,
	0xCEAF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6A9,
	0xE6B0,
	INVALID_GB_INNER_CODE,
	0xD2A6,
	INVALID_GB_INNER_CODE,
	0xBDAA,
	0xE6AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6AF,
	INVALID_GB_INNER_CODE,
	0xC0D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCA7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6B1,
	INVALID_GB_INNER_CODE,
	0xD2F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7CB,
	INVALID_GB_INNER_CODE,
	0xCDFE,
	INVALID_GB_INNER_CODE,
	0xCDDE,
	0xC2A6,
	0xE6AB,
	0xE6AC,
	0xBDBF,
	0xE6AE,
	0xE6B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6B6,
	INVALID_GB_INNER_CODE,
	0xE6B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEEA,
	0xC9EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6B7,
	INVALID_GB_INNER_CODE,
	0xB6F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3E9,
	0xE6B4,
	INVALID_GB_INNER_CODE,
	0xE6B5,
	INVALID_GB_INNER_CODE,
	0xC8A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDF1,
	0xE6BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBE9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3A4,
	0xE6BF,
	0xC9F4,
	0xE6C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3C4,
	0xE6C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6C7,
	0xCFB1,
	INVALID_GB_INNER_CODE,
	0xEBF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCDE,
	0xC9A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFD3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6C8,
	INVALID_GB_INNER_CODE,
	0xE6C9,
	INVALID_GB_INNER_CODE,
	0xE6CE,
	INVALID_GB_INNER_CODE,
	0xE6D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6CB,
	0xB5D5,
	INVALID_GB_INNER_CODE,
	0xE6CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4DB,
	INVALID_GB_INNER_CODE,
	0xE6C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6D4,
	0xE6D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6D5,
	INVALID_GB_INNER_CODE,
	0xD9F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7D3,
	0xE6DD,
	INVALID_GB_INNER_CODE,
	0xE6DE,
	0xBFD7,
	0xD4D0,
	INVALID_GB_INNER_CODE,
	0xD7D6,
	0xB4E6,
	0xCBEF,
	0xE6DA,
	0xD8C3,
	0xD7CE,
	0xD0A2,
	INVALID_GB_INNER_CODE,
	0xC3CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6DF,
	0xBCBE,
	0xB9C2,
	0xE6DB,
	0xD1A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAA2,
	0xC2CF,
	INVALID_GB_INNER_CODE,
	0xD8AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAEB,
	0xE5EE,
	INVALID_GB_INNER_CODE,
	0xE6DC,
	INVALID_GB_INNER_CODE,
	0xB7F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5B2,
	0xC4FE,
	INVALID_GB_INNER_CODE,
	0xCBFC,
	0xE5B3,
	0xD5AC,
	INVALID_GB_INNER_CODE,
	0xD3EE,
	0xCAD8,
	0xB0B2,
	INVALID_GB_INNER_CODE,
	0xCBCE,
	0xCDEA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAEA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5B5,
	INVALID_GB_INNER_CODE,
	0xE5B4,
	INVALID_GB_INNER_CODE,
	0xD7DA,
	0xB9D9,
	0xD6E6,
	0xB6A8,
	0xCDF0,
	0xD2CB,
	0xB1A6,
	0xCAB5,
	INVALID_GB_INNER_CODE,
	0xB3E8,
	0xC9F3,
	0xBFCD,
	0xD0FB,
	0xCAD2,
	0xE5B6,
	0xBBC2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFDC,
	0xB9AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAA6,
	0xD1E7,
	0xCFFC,
	0xBCD2,
	INVALID_GB_INNER_CODE,
	0xE5B7,
	0xC8DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFED,
	0xB1F6,
	0xCBDE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCC5,
	INVALID_GB_INNER_CODE,
	0xBCC4,
	0xD2FA,
	0xC3DC,
	0xBFDC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3C2,
	INVALID_GB_INNER_CODE,
	0xBAAE,
	0xD4A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7DE,
	0xC4AF,
	0xB2EC,
	INVALID_GB_INNER_CODE,
	0xB9D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5BB,
	0xC1C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5BC,
	INVALID_GB_INNER_CODE,
	0xE5BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4E7,
	0xB6D4,
	0xCBC2,
	0xD1B0,
	0xB5BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAD9,
	INVALID_GB_INNER_CODE,
	0xB7E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9E4,
	INVALID_GB_INNER_CODE,
	0xBDAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEBE,
	0xD7F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0A1,
	INVALID_GB_INNER_CODE,
	0xC9D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6FB,
	0xE6D8,
	0xBCE2,
	INVALID_GB_INNER_CODE,
	0xB3BE,
	INVALID_GB_INNER_CODE,
	0xC9D0,
	INVALID_GB_INNER_CODE,
	0xE6D9,
	0xB3A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDECC,
	INVALID_GB_INNER_CODE,
	0xD3C8,
	0xDECD,
	INVALID_GB_INNER_CODE,
	0xD2A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDECE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBECD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDECF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAAC,
	0xD2FC,
	0xB3DF,
	0xE5EA,
	0xC4E1,
	0xBEA1,
	0xCEB2,
	0xC4F2,
	0xBED6,
	0xC6A8,
	0xB2E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBED3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7FC,
	0xCCEB,
	0xBDEC,
	0xCEDD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCABA,
	0xC6C1,
	0xE5EC,
	0xD0BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAF4,
	INVALID_GB_INNER_CODE,
	0xCDC0,
	0xC2C5,
	INVALID_GB_INNER_CODE,
	0xE5EF,
	INVALID_GB_INNER_CODE,
	0xC2C4,
	0xE5F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5F8,
	0xCDCD,
	INVALID_GB_INNER_CODE,
	0xC9BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2D9,
	0xE1A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3EC,
	INVALID_GB_INNER_CODE,
	0xCBEA,
	0xC6F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1A7,
	0xE1A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1AA,
	0xE1AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2ED,
	INVALID_GB_INNER_CODE,
	0xE1AB,
	0xB8DA,
	0xE1AD,
	0xE1AE,
	0xE1B0,
	0xB5BA,
	0xE1B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1B3,
	0xE1B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1D2,
	INVALID_GB_INNER_CODE,
	0xE1B6,
	0xE1B5,
	0xC1EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1B7,
	INVALID_GB_INNER_CODE,
	0xD4C0,
	INVALID_GB_INNER_CODE,
	0xE1B2,
	INVALID_GB_INNER_CODE,
	0xE1BA,
	0xB0B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1B4,
	INVALID_GB_INNER_CODE,
	0xBFF9,
	INVALID_GB_INNER_CODE,
	0xE1B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFBF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1BD,
	0xE1BF,
	0xC2CD,
	INVALID_GB_INNER_CODE,
	0xB6EB,
	INVALID_GB_INNER_CODE,
	0xD3F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1C0,
	0xE1C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1C7,
	0xB3E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4DE,
	INVALID_GB_INNER_CODE,
	0xD1C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1C5,
	INVALID_GB_INNER_CODE,
	0xE1C3,
	0xE1C2,
	INVALID_GB_INNER_CODE,
	0xB1C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5B8,
	0xE1C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1CC,
	0xE1CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEFFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1D3,
	0xE1D2,
	0xC7B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1CE,
	INVALID_GB_INNER_CODE,
	0xE1D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1D4,
	INVALID_GB_INNER_CODE,
	0xE1D1,
	0xE1CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7DD,
	INVALID_GB_INNER_CODE,
	0xB4A8,
	0xD6DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1B2,
	0xB3B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9A4,
	0xD7F3,
	0xC7C9,
	0xBEDE,
	0xB9AE,
	INVALID_GB_INNER_CODE,
	0xCED7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2EE,
	0xDBCF,
	INVALID_GB_INNER_CODE,
	0xBCBA,
	0xD2D1,
	0xCBC8,
	0xB0CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFEF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9E3,
	0xBDED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1D2,
	0xCAD0,
	0xB2BC,
	INVALID_GB_INNER_CODE,
	0xCBA7,
	0xB7AB,
	INVALID_GB_INNER_CODE,
	0xCAA6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0F8,
	0xD5CA,
	0xE0FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0FA,
	0xC5C1,
	0xCCFB,
	INVALID_GB_INNER_CODE,
	0xC1B1,
	0xE0F9,
	0xD6E3,
	0xB2AF,
	0xD6C4,
	0xB5DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4F8,
	0xD6A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFAF,
	0xB0EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1A1,
	0xB3A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE0FD,
	0xE0FE,
	0xC3B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3DD,
	INVALID_GB_INNER_CODE,
	0xE1A2,
	0xB7F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBCF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1A3,
	0xC4BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1A6,
	0xB4B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8C9,
	0xC6BD,
	0xC4EA,
	INVALID_GB_INNER_CODE,
	0xB2A2,
	INVALID_GB_INNER_CODE,
	0xD0D2,
	INVALID_GB_INNER_CODE,
	0xE7DB,
	0xBBC3,
	0xD3D7,
	0xD3C4,
	INVALID_GB_INNER_CODE,
	0xB9E3,
	0xE2CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7AF,
	INVALID_GB_INNER_CODE,
	0xC7EC,
	0xB1D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4B2,
	0xE2D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0F2,
	0xC2AE,
	0xE2D0,
	INVALID_GB_INNER_CODE,
	0xBFE2,
	0xD3A6,
	0xB5D7,
	0xE2D2,
	0xB5EA,
	INVALID_GB_INNER_CODE,
	0xC3ED,
	0xB8FD,
	INVALID_GB_INNER_CODE,
	0xB8AE,
	INVALID_GB_INNER_CODE,
	0xC5D3,
	0xB7CF,
	0xE2D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2D3,
	0xB6C8,
	0xD7F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDA5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2D8,
	INVALID_GB_INNER_CODE,
	0xE2D6,
	0xCAFC,
	0xBFB5,
	0xD3B9,
	0xE2D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1AE,
	0xC0C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2DB,
	0xE2DA,
	0xC0AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2DD,
	INVALID_GB_INNER_CODE,
	0xE2DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBC8,
	INVALID_GB_INNER_CODE,
	0xD1D3,
	0xCDA2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDA8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEC3,
	0xD8A5,
	0xBFAA,
	0xDBCD,
	0xD2EC,
	0xC6FA,
	0xC5AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEC4,
	INVALID_GB_INNER_CODE,
	0xB1D7,
	0xDFAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCABD,
	INVALID_GB_INNER_CODE,
	0xDFB1,
	INVALID_GB_INNER_CODE,
	0xB9AD,
	INVALID_GB_INNER_CODE,
	0xD2FD,
	INVALID_GB_INNER_CODE,
	0xB8A5,
	0xBAEB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5DC,
	0xD5C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3D6,
	0xCFD2,
	0xBBA1,
	INVALID_GB_INNER_CODE,
	0xE5F3,
	0xE5F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5F4,
	INVALID_GB_INNER_CODE,
	0xCDE4,
	INVALID_GB_INNER_CODE,
	0xC8F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5AF,
	0xC7BF,
	INVALID_GB_INNER_CODE,
	0xE5F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECB0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5E6,
	INVALID_GB_INNER_CODE,
	0xB9E9,
	0xB5B1,
	INVALID_GB_INNER_CODE,
	0xC2BC,
	0xE5E8,
	0xE5E7,
	0xE5E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1EA,
	0xD0CE,
	INVALID_GB_INNER_CODE,
	0xCDAE,
	INVALID_GB_INNER_CODE,
	0xD1E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2CA,
	0xB1EB,
	INVALID_GB_INNER_CODE,
	0xB1F2,
	0xC5ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5C3,
	0xD3B0,
	INVALID_GB_INNER_CODE,
	0xE1DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1DD,
	INVALID_GB_INNER_CODE,
	0xD2DB,
	INVALID_GB_INNER_CODE,
	0xB3B9,
	0xB1CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDF9,
	0xD5F7,
	0xE1DE,
	INVALID_GB_INNER_CODE,
	0xBEB6,
	0xB4FD,
	INVALID_GB_INNER_CODE,
	0xE1DF,
	0xBADC,
	0xE1E0,
	0xBBB2,
	0xC2C9,
	0xE1E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0EC,
	INVALID_GB_INNER_CODE,
	0xCDBD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1E2,
	INVALID_GB_INNER_CODE,
	0xB5C3,
	0xC5C7,
	0xE1E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1E5,
	INVALID_GB_INNER_CODE,
	0xD1AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1E6,
	0xCEA2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1E7,
	INVALID_GB_INNER_CODE,
	0xB5C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1E8,
	0xBBD5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0C4,
	0xE2E0,
	0xB1D8,
	0xD2E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCC9,
	0xC8CC,
	INVALID_GB_INNER_CODE,
	0xE2E3,
	0xECFE,
	0xECFD,
	0xDFAF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2E2,
	0xD6BE,
	0xCDFC,
	0xC3A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6D2,
	0xE2E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2EC,
	0xBFEC,
	INVALID_GB_INNER_CODE,
	0xE2ED,
	0xE2E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0C3,
	INVALID_GB_INNER_CODE,
	0xBAF6,
	0xE2E9,
	0xB7DE,
	0xBBB3,
	0xCCAC,
	0xCBCB,
	0xE2E4,
	0xE2E6,
	0xE2EA,
	0xE2EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2F4,
	0xD4F5,
	0xE2F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5AD,
	INVALID_GB_INNER_CODE,
	0xD5FA,
	0xC5C2,
	0xB2C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2EF,
	INVALID_GB_INNER_CODE,
	0xE2F2,
	0xC1AF,
	0xCBBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5A1,
	0xE2F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCB1,
	0xE2F1,
	0xD0D4,
	0xD4B9,
	0xE2F5,
	0xB9D6,
	0xE2F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7DC,
	0xEDA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2F8,
	INVALID_GB_INNER_CODE,
	0xEDA5,
	0xE2FE,
	0xCAD1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1B5,
	INVALID_GB_INNER_CODE,
	0xBBD0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFD6,
	INVALID_GB_INNER_CODE,
	0xBAE3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDA6,
	0xEDA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDA2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBD6,
	0xEDA7,
	0xD0F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDA4,
	0xBADE,
	0xB6F7,
	0xE3A1,
	0xB6B2,
	0xCCF1,
	0xB9A7,
	INVALID_GB_INNER_CODE,
	0xCFA2,
	0xC7A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFD2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6F1,
	INVALID_GB_INNER_CODE,
	0xE2FA,
	0xE2FB,
	0xE2FD,
	0xE2FC,
	0xC4D5,
	0xE3A2,
	INVALID_GB_INNER_CODE,
	0xD3C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3A7,
	0xC7C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFA4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3A9,
	0xBAB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3A8,
	INVALID_GB_INNER_CODE,
	0xBBDA,
	INVALID_GB_INNER_CODE,
	0xE3A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3A4,
	0xE3AA,
	INVALID_GB_INNER_CODE,
	0xE3A6,
	INVALID_GB_INNER_CODE,
	0xCEF2,
	0xD3C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4C3,
	INVALID_GB_INNER_CODE,
	0xC4FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDA8,
	0xD0FC,
	0xE3A5,
	INVALID_GB_INNER_CODE,
	0xC3F5,
	INVALID_GB_INNER_CODE,
	0xE3AD,
	0xB1AF,
	INVALID_GB_INNER_CODE,
	0xE3B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCC2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3AC,
	0xB5BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7E9,
	0xE3B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEAA,
	0xCDEF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBF3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCE8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3AF,
	INVALID_GB_INNER_CODE,
	0xE3B1,
	INVALID_GB_INNER_CODE,
	0xCFA7,
	0xE3AE,
	INVALID_GB_INNER_CODE,
	0xCEA9,
	0xBBDD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5EB,
	0xBEE5,
	0xB2D2,
	0xB3CD,
	INVALID_GB_INNER_CODE,
	0xB1B9,
	0xE3AB,
	0xB2D1,
	0xB5AC,
	0xB9DF,
	0xB6E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFEB,
	0xE3B7,
	INVALID_GB_INNER_CODE,
	0xBBCC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8C7,
	0xD0CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3B8,
	0xB3EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDA9,
	INVALID_GB_INNER_CODE,
	0xD3FA,
	0xD3E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDAA,
	0xE3B9,
	0xD2E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8D0,
	0xE3B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3B6,
	0xB7DF,
	INVALID_GB_INNER_CODE,
	0xE3B4,
	0xC0A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4C8,
	INVALID_GB_INNER_CODE,
	0xE3BB,
	INVALID_GB_INNER_CODE,
	0xBBC5,
	INVALID_GB_INNER_CODE,
	0xC9F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBDB,
	0xBFAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEBF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3BC,
	INVALID_GB_INNER_CODE,
	0xBFB6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDAD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3BF,
	0xBAA9,
	0xEDAC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAB6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0B8,
	INVALID_GB_INNER_CODE,
	0xB0C3,
	0xEDAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDAF,
	0xC0C1,
	INVALID_GB_INNER_CODE,
	0xE3C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCB2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDB0,
	INVALID_GB_INNER_CODE,
	0xB8EA,
	INVALID_GB_INNER_CODE,
	0xCEEC,
	0xEAA7,
	0xD0E7,
	0xCAF9,
	0xC8D6,
	0xCFB7,
	0xB3C9,
	0xCED2,
	0xBDE4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3DE,
	0xBBF2,
	0xEAA8,
	0xD5BD,
	INVALID_GB_INNER_CODE,
	0xC6DD,
	0xEAA9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAAA,
	INVALID_GB_INNER_CODE,
	0xEAAC,
	0xEAAB,
	INVALID_GB_INNER_CODE,
	0xEAAE,
	0xEAAD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDD8,
	INVALID_GB_INNER_CODE,
	0xEAAF,
	INVALID_GB_INNER_CODE,
	0xC2BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4C1,
	0xB4F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBA7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECE6,
	0xECE5,
	0xB7BF,
	0xCBF9,
	0xB1E2,
	INVALID_GB_INNER_CODE,
	0xECE7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9C8,
	0xECE8,
	0xECE9,
	INVALID_GB_INNER_CODE,
	0xCAD6,
	0xDED0,
	0xB2C5,
	0xD4FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6CB,
	0xB0C7,
	0xB4F2,
	0xC8D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDD0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFB8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFDB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7A4,
	0xD6B4,
	INVALID_GB_INNER_CODE,
	0xC0A9,
	0xDED1,
	0xC9A8,
	0xD1EF,
	0xC5A4,
	0xB0E7,
	0xB3B6,
	0xC8C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6F3,
	INVALID_GB_INNER_CODE,
	0xD5D2,
	0xB3D0,
	0xBCBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEF1,
	0xB0D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2D6,
	0xCAE3,
	0xD7A5,
	INVALID_GB_INNER_CODE,
	0xCDB6,
	0xB6B6,
	0xBFB9,
	0xD5DB,
	INVALID_GB_INNER_CODE,
	0xB8A7,
	0xC5D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDED2,
	0xBFD9,
	0xC2D5,
	0xC7C0,
	INVALID_GB_INNER_CODE,
	0xBBA4,
	0xB1A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5FB,
	0xCCA7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4A8,
	INVALID_GB_INNER_CODE,
	0xDED3,
	0xD1BA,
	0xB3E9,
	INVALID_GB_INNER_CODE,
	0xC3F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7F7,
	INVALID_GB_INNER_CODE,
	0xD6F4,
	0xB5A3,
	0xB2F0,
	0xC4B4,
	0xC4E9,
	0xC0AD,
	0xDED4,
	INVALID_GB_INNER_CODE,
	0xB0E8,
	0xC5C4,
	0xC1E0,
	INVALID_GB_INNER_CODE,
	0xB9D5,
	INVALID_GB_INNER_CODE,
	0xBEDC,
	0xCDD8,
	0xB0CE,
	INVALID_GB_INNER_CODE,
	0xCDCF,
	0xDED6,
	0xBED0,
	0xD7BE,
	0xDED5,
	0xD5D0,
	0xB0DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2A3,
	0xBCF0,
	INVALID_GB_INNER_CODE,
	0xD3B5,
	0xC0B9,
	0xC5A1,
	0xB2A6,
	0xD4F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0A8,
	0xCAC3,
	0xDED7,
	0xD5FC,
	INVALID_GB_INNER_CODE,
	0xB9B0,
	INVALID_GB_INNER_CODE,
	0xC8AD,
	0xCBA9,
	INVALID_GB_INNER_CODE,
	0xDED9,
	0xBFBD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6B4,
	0xD7A7,
	0xCAB0,
	0xC4C3,
	INVALID_GB_INNER_CODE,
	0xB3D6,
	0xB9D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6B8,
	0xEAFC,
	0xB0B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFE6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDDA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6BF,
	0xC2CE,
	INVALID_GB_INNER_CODE,
	0xCECE,
	0xCCA2,
	0xD0AE,
	0xC4D3,
	0xB5B2,
	0xDED8,
	0xD5F5,
	0xBCB7,
	0xBBD3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0A4,
	INVALID_GB_INNER_CODE,
	0xC5B2,
	0xB4EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAFD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEDA,
	0xCDA6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDEC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEE6,
	0xDEDC,
	INVALID_GB_INNER_CODE,
	0xCDB1,
	0xC0A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7BD,
	INVALID_GB_INNER_CODE,
	0xDEDB,
	0xB0C6,
	0xBAB4,
	0xC9D3,
	0xC4F3,
	0xBEE8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0CC,
	0xCBF0,
	INVALID_GB_INNER_CODE,
	0xBCF1,
	0xBBBB,
	0xB5B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5F5,
	INVALID_GB_INNER_CODE,
	0xDEE6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEE3,
	0xBEDD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEDF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4B7,
	0xBDDD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEE0,
	0xC4ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFC6,
	INVALID_GB_INNER_CODE,
	0xB5E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6DE,
	0xCADA,
	0xB5F4,
	0xDEE5,
	INVALID_GB_INNER_CODE,
	0xD5C6,
	INVALID_GB_INNER_CODE,
	0xDEE1,
	0xCCCD,
	0xC6FE,
	INVALID_GB_INNER_CODE,
	0xC5C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2B4,
	INVALID_GB_INNER_CODE,
	0xBEF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2D3,
	INVALID_GB_INNER_CODE,
	0xCCBD,
	0xB3B8,
	INVALID_GB_INNER_CODE,
	0xBDD3,
	INVALID_GB_INNER_CODE,
	0xBFD8,
	0xCDC6,
	0xD1DA,
	0xB4EB,
	INVALID_GB_INNER_CODE,
	0xDEE4,
	0xDEDD,
	0xDEE7,
	INVALID_GB_INNER_CODE,
	0xEAFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2B0,
	0xDEE2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6C0,
	0xB5A7,
	INVALID_GB_INNER_CODE,
	0xB2F4,
	INVALID_GB_INNER_CODE,
	0xDEE8,
	INVALID_GB_INNER_CODE,
	0xDEF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEED,
	INVALID_GB_INNER_CODE,
	0xDEF1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7E1,
	0xDEEF,
	0xC3E8,
	0xCCE1,
	INVALID_GB_INNER_CODE,
	0xB2E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEEE,
	INVALID_GB_INNER_CODE,
	0xDEEB,
	0xCED5,
	INVALID_GB_INNER_CODE,
	0xB4A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFAB,
	0xBEBE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDD2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEE9,
	INVALID_GB_INNER_CODE,
	0xD4AE,
	INVALID_GB_INNER_CODE,
	0xDEDE,
	INVALID_GB_INNER_CODE,
	0xDEEA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0BF,
	INVALID_GB_INNER_CODE,
	0xDEEC,
	0xB2F3,
	0xB8E9,
	0xC2A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEF5,
	0xDEF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2AB,
	0xB4A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4EA,
	0xC9A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEF6,
	0xCBD1,
	INVALID_GB_INNER_CODE,
	0xB8E3,
	INVALID_GB_INNER_CODE,
	0xDEF7,
	0xDEFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEF9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCC2,
	INVALID_GB_INNER_CODE,
	0xB0E1,
	0xB4EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2EB,
	INVALID_GB_INNER_CODE,
	0xEBA1,
	INVALID_GB_INNER_CODE,
	0xDEF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9E3,
	0xDEF3,
	0xB0DA,
	0xD2A1,
	0xB1F7,
	INVALID_GB_INNER_CODE,
	0xCCAF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEF0,
	INVALID_GB_INNER_CODE,
	0xCBA4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4DD,
	INVALID_GB_INNER_CODE,
	0xC4A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEFD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3FE,
	0xC4A1,
	0xDFA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1CC,
	INVALID_GB_INNER_CODE,
	0xDEFC,
	0xBEEF,
	INVALID_GB_INNER_CODE,
	0xC6B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3C5,
	0xC8F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBBA,
	0xDEFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFA4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7CB,
	0xB2A5,
	0xB4E9,
	INVALID_GB_INNER_CODE,
	0xD7AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4EC,
	INVALID_GB_INNER_CODE,
	0xDFA2,
	0xDFA3,
	INVALID_GB_INNER_CODE,
	0xDFA5,
	INVALID_GB_INNER_CODE,
	0xBAB3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFA6,
	INVALID_GB_INNER_CODE,
	0xC0DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2D9,
	0xC7E6,
	INVALID_GB_INNER_CODE,
	0xDFA7,
	INVALID_GB_INNER_CODE,
	0xC7DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFA8,
	0xEBA2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBD3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFAA,
	INVALID_GB_INNER_CODE,
	0xDFA9,
	INVALID_GB_INNER_CODE,
	0xB2C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFAC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEF0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDFAD,
	0xD6A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAB7,
	0xEBB6,
	0xCAD5,
	INVALID_GB_INNER_CODE,
	0xD8FC,
	0xB8C4,
	INVALID_GB_INNER_CODE,
	0xB9A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7C5,
	0xD5FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0A7,
	0xF4CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3F4,
	INVALID_GB_INNER_CODE,
	0xBEC8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBB7,
	0xB0BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDCC,
	INVALID_GB_INNER_CODE,
	0xC1B2,
	INVALID_GB_INNER_CODE,
	0xB1D6,
	0xB3A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8D2,
	0xC9A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBB8,
	0xBEB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAFD,
	INVALID_GB_INNER_CODE,
	0xC7C3,
	INVALID_GB_INNER_CODE,
	0xD5FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5AB,
	0xB1F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECB3,
	0xB0DF,
	INVALID_GB_INNER_CODE,
	0xECB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6B7,
	INVALID_GB_INNER_CODE,
	0xC1CF,
	INVALID_GB_INNER_CODE,
	0xF5FA,
	0xD0B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5E5,
	INVALID_GB_INNER_CODE,
	0xCED3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDEF,
	0xB3E2,
	INVALID_GB_INNER_CODE,
	0xB8AB,
	INVALID_GB_INNER_CODE,
	0xD5B6,
	INVALID_GB_INNER_CODE,
	0xEDBD,
	INVALID_GB_INNER_CODE,
	0xB6CF,
	INVALID_GB_INNER_CODE,
	0xCBB9,
	0xD0C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECB6,
	0xCAA9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5D4,
	INVALID_GB_INNER_CODE,
	0xECB9,
	0xECB8,
	0xC2C3,
	0xECB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0FD,
	0xECBA,
	INVALID_GB_INNER_CODE,
	0xECBB,
	0xD7E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECBD,
	0xC6EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEDE,
	INVALID_GB_INNER_CODE,
	0xBCC8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8D5,
	0xB5A9,
	0xBEC9,
	0xD6BC,
	0xD4E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1AE,
	0xD0F1,
	0xEAB8,
	0xEAB9,
	0xEABA,
	0xBAB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAB1,
	0xBFF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAC0,
	INVALID_GB_INNER_CODE,
	0xB0BA,
	0xEABE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEABB,
	INVALID_GB_INNER_CODE,
	0xB2FD,
	INVALID_GB_INNER_CODE,
	0xC3F7,
	0xBBE8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2D7,
	0xCEF4,
	0xEABF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEABC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAC3,
	INVALID_GB_INNER_CODE,
	0xD0C7,
	0xD3B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4BA,
	INVALID_GB_INNER_CODE,
	0xC3C1,
	0xD7F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5D1,
	INVALID_GB_INNER_CODE,
	0xCAC7,
	INVALID_GB_INNER_CODE,
	0xEAC5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAC4,
	0xEAC7,
	0xEAC6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6E7,
	INVALID_GB_INNER_CODE,
	0xCFD4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEACB,
	INVALID_GB_INNER_CODE,
	0xBBCE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDFA,
	0xC9CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEACC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9B9,
	0xCFFE,
	0xEACA,
	0xD4CE,
	0xEACD,
	0xEACF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAC9,
	INVALID_GB_INNER_CODE,
	0xEACE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEEE,
	INVALID_GB_INNER_CODE,
	0xBBDE,
	INVALID_GB_INNER_CODE,
	0xB3BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6D5,
	0xBEB0,
	0xCEFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7E7,
	INVALID_GB_INNER_CODE,
	0xBEA7,
	0xEAD0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4DD,
	INVALID_GB_INNER_CODE,
	0xEAD1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFBE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAD2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5AF,
	0xB0B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAD4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAD3,
	0xF4DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAD5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAEF,
	INVALID_GB_INNER_CODE,
	0xEAD6,
	0xEAD7,
	0xC6D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAD8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAD9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4BB,
	INVALID_GB_INNER_CODE,
	0xC7FA,
	0xD2B7,
	0xB8FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAC2,
	INVALID_GB_INNER_CODE,
	0xB2DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2FC,
	INVALID_GB_INNER_CODE,
	0xD4F8,
	0xCCE6,
	0xD7EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4C2,
	0xD3D0,
	0xEBC3,
	0xC5F3,
	INVALID_GB_INNER_CODE,
	0xB7FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBD4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBB7,
	0xEBDE,
	INVALID_GB_INNER_CODE,
	0xC0CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDFB,
	INVALID_GB_INNER_CODE,
	0xB3AF,
	INVALID_GB_INNER_CODE,
	0xC6DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBFC,
	INVALID_GB_INNER_CODE,
	0xC4BE,
	INVALID_GB_INNER_CODE,
	0xCEB4,
	0xC4A9,
	0xB1BE,
	0xD4FD,
	INVALID_GB_INNER_CODE,
	0xCAF5,
	INVALID_GB_INNER_CODE,
	0xD6EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6D3,
	0xB6E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9B1,
	INVALID_GB_INNER_CODE,
	0xD4D3,
	0xC8A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8CB,
	INVALID_GB_INNER_CODE,
	0xE8BE,
	0xC9BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8BB,
	INVALID_GB_INNER_CODE,
	0xC0EE,
	0xD0D3,
	0xB2C4,
	0xB4E5,
	INVALID_GB_INNER_CODE,
	0xE8BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6C5,
	INVALID_GB_INNER_CODE,
	0xE8BD,
	0xCAF8,
	0xB8DC,
	0xCCF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1EE,
	0xE8BF,
	0xE8C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBABC,
	INVALID_GB_INNER_CODE,
	0xB1AD,
	0xBDDC,
	INVALID_GB_INNER_CODE,
	0xEABD,
	0xE8C3,
	INVALID_GB_INNER_CODE,
	0xE8C6,
	INVALID_GB_INNER_CODE,
	0xE8CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8CC,
	INVALID_GB_INNER_CODE,
	0xCBC9,
	0xB0E5,
	INVALID_GB_INNER_CODE,
	0xBCAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8C1,
	INVALID_GB_INNER_CODE,
	0xCDF7,
	INVALID_GB_INNER_CODE,
	0xE8CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEF6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5ED,
	INVALID_GB_INNER_CODE,
	0xC1D6,
	0xE8C4,
	INVALID_GB_INNER_CODE,
	0xC3B6,
	INVALID_GB_INNER_CODE,
	0xB9FB,
	0xD6A6,
	0xE8C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAE0,
	0xD4E6,
	INVALID_GB_INNER_CODE,
	0xE8C0,
	INVALID_GB_INNER_CODE,
	0xE8C5,
	0xE8C7,
	INVALID_GB_INNER_CODE,
	0xC7B9,
	0xB7E3,
	INVALID_GB_INNER_CODE,
	0xE8C9,
	INVALID_GB_INNER_CODE,
	0xBFDD,
	0xE8D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8D7,
	INVALID_GB_INNER_CODE,
	0xE8D5,
	0xBCDC,
	0xBCCF,
	0xE8DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8DE,
	INVALID_GB_INNER_CODE,
	0xE8DA,
	0xB1FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0D8,
	0xC4B3,
	0xB8CC,
	0xC6E2,
	0xC8BE,
	0xC8E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8CF,
	0xE8D4,
	0xE8D6,
	INVALID_GB_INNER_CODE,
	0xB9F1,
	0xE8D8,
	0xD7F5,
	INVALID_GB_INNER_CODE,
	0xC4FB,
	INVALID_GB_INNER_CODE,
	0xE8DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFC2,
	0xE8CD,
	0xD6F9,
	INVALID_GB_INNER_CODE,
	0xC1F8,
	0xB2F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8DF,
	INVALID_GB_INNER_CODE,
	0xCAC1,
	0xE8D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5A4,
	INVALID_GB_INNER_CODE,
	0xB1EA,
	0xD5BB,
	0xE8CE,
	0xE8D0,
	0xB6B0,
	0xE8D3,
	INVALID_GB_INNER_CODE,
	0xE8DD,
	0xC0B8,
	INVALID_GB_INNER_CODE,
	0xCAF7,
	INVALID_GB_INNER_CODE,
	0xCBA8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6DC,
	0xC0F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8F2,
	0xD6EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8E0,
	0xE8E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1F9,
	0xBACB,
	0xB8F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8F1,
	0xD4D4,
	0xE8EF,
	INVALID_GB_INNER_CODE,
	0xE8EE,
	0xE8EC,
	0xB9F0,
	0xCCD2,
	0xE8E6,
	0xCEA6,
	0xBFF2,
	INVALID_GB_INNER_CODE,
	0xB0B8,
	0xE8F1,
	0xE8F0,
	INVALID_GB_INNER_CODE,
	0xD7C0,
	INVALID_GB_INNER_CODE,
	0xE8E4,
	INVALID_GB_INNER_CODE,
	0xCDA9,
	0xC9A3,
	INVALID_GB_INNER_CODE,
	0xBBB8,
	0xBDDB,
	0xE8EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8E2,
	0xE8E3,
	0xE8E5,
	0xB5B5,
	0xE8E7,
	0xC7C5,
	0xE8EB,
	0xE8ED,
	0xBDB0,
	0xD7AE,
	INVALID_GB_INNER_CODE,
	0xE8F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8F5,
	INVALID_GB_INNER_CODE,
	0xCDB0,
	0xE8F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1BA,
	INVALID_GB_INNER_CODE,
	0xE8E8,
	INVALID_GB_INNER_CODE,
	0xC3B7,
	0xB0F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3CE,
	0xCEE0,
	0xC0E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBF3,
	INVALID_GB_INNER_CODE,
	0xCCDD,
	0xD0B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAE1,
	INVALID_GB_INNER_CODE,
	0xE8F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCEC,
	INVALID_GB_INNER_CODE,
	0xE8F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3DE,
	INVALID_GB_INNER_CODE,
	0xC6E5,
	INVALID_GB_INNER_CODE,
	0xB9F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCAC,
	INVALID_GB_INNER_CODE,
	0xC5EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9AD,
	INVALID_GB_INNER_CODE,
	0xE9A2,
	0xC0E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFC3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8FE,
	0xB9D7,
	INVALID_GB_INNER_CODE,
	0xE8FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9A3,
	INVALID_GB_INNER_CODE,
	0xD6B2,
	0xD7B5,
	INVALID_GB_INNER_CODE,
	0xE9A7,
	INVALID_GB_INNER_CODE,
	0xBDB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8FC,
	0xE8FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDD6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4AA,
	INVALID_GB_INNER_CODE,
	0xB4BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9AC,
	0xC0E3,
	INVALID_GB_INNER_CODE,
	0xE9AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFAC,
	0xE9B1,
	0xE9BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9AF,
	INVALID_GB_INNER_CODE,
	0xB8C5,
	INVALID_GB_INNER_CODE,
	0xE9AD,
	INVALID_GB_INNER_CODE,
	0xD3DC,
	0xE9B4,
	0xE9B5,
	0xE9B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0C6,
	0xE9C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9BB,
	0xB0F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9BC,
	0xD5A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9BE,
	INVALID_GB_INNER_CODE,
	0xE9BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9C3,
	INVALID_GB_INNER_CODE,
	0xE9B3,
	INVALID_GB_INNER_CODE,
	0xE9B6,
	INVALID_GB_INNER_CODE,
	0xBBB1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCF7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9C4,
	0xE9C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2DB,
	INVALID_GB_INNER_CODE,
	0xE9C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9CB,
	0xE9CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5C1,
	INVALID_GB_INNER_CODE,
	0xC4A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9D8,
	INVALID_GB_INNER_CODE,
	0xBAE1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9C9,
	INVALID_GB_INNER_CODE,
	0xD3A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9D7,
	0xE9D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9D9,
	0xB3C8,
	INVALID_GB_INNER_CODE,
	0xE9D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFF0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFAD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9D5,
	INVALID_GB_INNER_CODE,
	0xE9DC,
	0xE9DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9DD,
	INVALID_GB_INNER_CODE,
	0xE9DF,
	0xC3CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7B7,
	0xB4CE,
	0xBBB6,
	0xD0C0,
	0xECA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECA4,
	INVALID_GB_INNER_CODE,
	0xECA5,
	0xC6DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECA6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECA7,
	0xD0AA,
	INVALID_GB_INNER_CODE,
	0xC7B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECA8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6B9,
	0xD5FD,
	0xB4CB,
	0xB2BD,
	0xCEE4,
	0xC6E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDE1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4F5,
	INVALID_GB_INNER_CODE,
	0xCBC0,
	0xBCDF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9E2,
	0xE9E3,
	0xD1EA,
	0xE9E5,
	INVALID_GB_INNER_CODE,
	0xB4F9,
	0xE9E4,
	INVALID_GB_INNER_CODE,
	0xD1B3,
	0xCAE2,
	0xB2D0,
	INVALID_GB_INNER_CODE,
	0xE9E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9E6,
	0xE9E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9E9,
	0xE9EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECAF,
	0xC5B9,
	0xB6CE,
	INVALID_GB_INNER_CODE,
	0xD2F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5EE,
	INVALID_GB_INNER_CODE,
	0xBBD9,
	0xECB1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEE3,
	INVALID_GB_INNER_CODE,
	0xC4B8,
	INVALID_GB_INNER_CODE,
	0xC3BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6BE,
	0xD8B9,
	0xB1C8,
	0xB1CF,
	0xB1D1,
	0xC5FE,
	INVALID_GB_INNER_CODE,
	0xB1D0,
	INVALID_GB_INNER_CODE,
	0xC3AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBA4,
	0xBAC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCBA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBA5,
	INVALID_GB_INNER_CODE,
	0xEBA7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBA8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBA6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBA9,
	0xEBAB,
	0xEBAA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBAC,
	INVALID_GB_INNER_CODE,
	0xCACF,
	0xD8B5,
	0xC3F1,
	INVALID_GB_INNER_CODE,
	0xC3A5,
	0xC6F8,
	0xEBAD,
	0xC4CA,
	INVALID_GB_INNER_CODE,
	0xEBAE,
	0xEBAF,
	0xEBB0,
	0xB7D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7FA,
	INVALID_GB_INNER_CODE,
	0xEBB1,
	0xC7E2,
	INVALID_GB_INNER_CODE,
	0xEBB3,
	INVALID_GB_INNER_CODE,
	0xBAA4,
	0xD1F5,
	0xB0B1,
	0xEBB2,
	0xEBB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5AA,
	0xC2C8,
	0xC7E8,
	INVALID_GB_INNER_CODE,
	0xEBB5,
	INVALID_GB_INNER_CODE,
	0xCBAE,
	0xE3DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDA1,
	0xD6AD,
	0xC7F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9E0,
	0xBBE3,
	INVALID_GB_INNER_CODE,
	0xBABA,
	0xE3E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3E0,
	0xC9C7,
	INVALID_GB_INNER_CODE,
	0xBAB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1B4,
	0xE3E1,
	0xC8EA,
	0xB9AF,
	0xBDAD,
	0xB3D8,
	0xCEDB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3E8,
	0xE3E9,
	0xCDF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCAD,
	INVALID_GB_INNER_CODE,
	0xBCB3,
	INVALID_GB_INNER_CODE,
	0xE3EA,
	INVALID_GB_INNER_CODE,
	0xE3EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6FB,
	0xB7DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7DF,
	0xD2CA,
	0xCED6,
	INVALID_GB_INNER_CODE,
	0xE3E4,
	0xE3EC,
	INVALID_GB_INNER_CODE,
	0xC9F2,
	0xB3C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6E3,
	0xE3E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDB3,
	0xE3E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9B3,
	INVALID_GB_INNER_CODE,
	0xC5E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9B5,
	INVALID_GB_INNER_CODE,
	0xC3BB,
	INVALID_GB_INNER_CODE,
	0xE3E3,
	0xC5BD,
	0xC1A4,
	0xC2D9,
	0xB2D7,
	INVALID_GB_INNER_CODE,
	0xE3ED,
	0xBBA6,
	0xC4AD,
	INVALID_GB_INNER_CODE,
	0xE3F0,
	0xBEDA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3FB,
	0xE3F5,
	0xBAD3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7D0,
	0xD3CD,
	INVALID_GB_INNER_CODE,
	0xD6CE,
	0xD5D3,
	0xB9C1,
	0xD5B4,
	0xD1D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0B9,
	0xC7F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8AA,
	0xB2B4,
	INVALID_GB_INNER_CODE,
	0xC3DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3FC,
	0xE3EF,
	0xB7A8,
	0xE3F7,
	0xE3F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5A2,
	INVALID_GB_INNER_CODE,
	0xE3F6,
	0xC5DD,
	0xB2A8,
	0xC6FC,
	INVALID_GB_INNER_CODE,
	0xC4E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7A2,
	INVALID_GB_INNER_CODE,
	0xC0E1,
	0xE3F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3FA,
	0xE3FD,
	0xCCA9,
	0xE3F3,
	INVALID_GB_INNER_CODE,
	0xD3BE,
	INVALID_GB_INNER_CODE,
	0xB1C3,
	0xEDB4,
	0xE3F1,
	0xE3F2,
	INVALID_GB_INNER_CODE,
	0xE3F8,
	0xD0BA,
	0xC6C3,
	0xD4F3,
	0xE3FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDE0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1F3,
	0xE4A3,
	INVALID_GB_INNER_CODE,
	0xE4A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFB4,
	INVALID_GB_INNER_CODE,
	0xE4A8,
	0xE4AE,
	0xC2E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDF2,
	INVALID_GB_INNER_CODE,
	0xE4A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAE9,
	0xE4AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6FD,
	0xD6DE,
	0xE4B2,
	INVALID_GB_INNER_CODE,
	0xE4AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4A1,
	INVALID_GB_INNER_CODE,
	0xBBEE,
	0xCDDD,
	0xC7A2,
	0xC5C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1F7,
	INVALID_GB_INNER_CODE,
	0xE4A4,
	INVALID_GB_INNER_CODE,
	0xC7B3,
	0xBDAC,
	0xBDBD,
	0xE4A5,
	INVALID_GB_INNER_CODE,
	0xD7C7,
	0xB2E2,
	INVALID_GB_INNER_CODE,
	0xE4AB,
	0xBCC3,
	0xE4AF,
	INVALID_GB_INNER_CODE,
	0xBBEB,
	0xE4B0,
	0xC5A8,
	0xE4B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5E3,
	0xBFA3,
	INVALID_GB_INNER_CODE,
	0xE4BA,
	INVALID_GB_INNER_CODE,
	0xE4B7,
	INVALID_GB_INNER_CODE,
	0xE4BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAC6,
	0xC0CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8A1,
	0xE4B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAA3,
	0xBDFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDBF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFFB,
	0xC9E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3BF,
	INVALID_GB_INNER_CODE,
	0xCFD1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4B3,
	INVALID_GB_INNER_CODE,
	0xE4B8,
	0xE4B9,
	0xCCE9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCCE,
	INVALID_GB_INNER_CODE,
	0xC0D4,
	0xE4B5,
	0xC1B0,
	0xE4B6,
	0xCED0,
	INVALID_GB_INNER_CODE,
	0xBBC1,
	0xB5D3,
	INVALID_GB_INNER_CODE,
	0xC8F3,
	0xBDA7,
	0xD5C7,
	0xC9AC,
	0xB8A2,
	0xE4CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4CC,
	0xD1C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAAD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAD4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4C3,
	0xB5ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7CD,
	0xE4C0,
	0xCFFD,
	0xE4BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1DC,
	0xCCCA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAE7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4D7,
	INVALID_GB_INNER_CODE,
	0xCCD4,
	0xE4C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4C7,
	0xE4C1,
	INVALID_GB_INNER_CODE,
	0xE4C4,
	0xB5AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3D9,
	INVALID_GB_INNER_CODE,
	0xE4C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2F9,
	0xB4E3,
	INVALID_GB_INNER_CODE,
	0xBBB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9EE,
	INVALID_GB_INNER_CODE,
	0xB4BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBEC,
	INVALID_GB_INNER_CODE,
	0xD1CD,
	INVALID_GB_INNER_CODE,
	0xCCED,
	0xEDB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4A8,
	INVALID_GB_INNER_CODE,
	0xE4CB,
	0xD7D5,
	0xE4C2,
	INVALID_GB_INNER_CODE,
	0xBDA5,
	0xE4C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3E6,
	INVALID_GB_INNER_CODE,
	0xE4C9,
	0xC9F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7FE,
	0xB6C9,
	INVALID_GB_INNER_CODE,
	0xD4FC,
	0xB2B3,
	0xE4D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEC2,
	INVALID_GB_INNER_CODE,
	0xE4CD,
	INVALID_GB_INNER_CODE,
	0xCEBC,
	INVALID_GB_INNER_CODE,
	0xB8DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4D6,
	INVALID_GB_INNER_CODE,
	0xBFCA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3CE,
	INVALID_GB_INNER_CODE,
	0xC3EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5C8,
	0xE4D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDC4,
	0xE4CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4D4,
	0xE4D5,
	INVALID_GB_INNER_CODE,
	0xBAFE,
	INVALID_GB_INNER_CODE,
	0xCFE6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDE5,
	0xCAAA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0A3,
	INVALID_GB_INNER_CODE,
	0xBDA6,
	0xE4D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4E7,
	0xD4B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4DF,
	INVALID_GB_INNER_CODE,
	0xE4E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFAA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBDD,
	INVALID_GB_INNER_CODE,
	0xE4DA,
	0xE4D1,
	INVALID_GB_INNER_CODE,
	0xE4E5,
	INVALID_GB_INNER_CODE,
	0xC8DC,
	0xE4E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4E7,
	0xE4E2,
	INVALID_GB_INNER_CODE,
	0xE4E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3FC,
	0xE4E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4E6,
	INVALID_GB_INNER_CODE,
	0xBBAC,
	INVALID_GB_INNER_CODE,
	0xD7D2,
	0xCCCF,
	0xEBF8,
	INVALID_GB_INNER_CODE,
	0xE4E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6CD,
	0xE4D9,
	0xE4DC,
	0xC2FA,
	0xE4DE,
	INVALID_GB_INNER_CODE,
	0xC2CB,
	0xC0C4,
	0xC2D0,
	INVALID_GB_INNER_CODE,
	0xB1F5,
	0xCCB2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0EC,
	0xD1DD,
	0xE4EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4F6,
	0xE4F4,
	0xC2FE,
	INVALID_GB_INNER_CODE,
	0xE4DD,
	INVALID_GB_INNER_CODE,
	0xE4F0,
	INVALID_GB_INNER_CODE,
	0xCAFE,
	INVALID_GB_INNER_CODE,
	0xD5C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4EB,
	0xE4EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4F2,
	INVALID_GB_INNER_CODE,
	0xCEAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7B1,
	INVALID_GB_INNER_CODE,
	0xC2BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCB6,
	0xB3B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4FB,
	INVALID_GB_INNER_CODE,
	0xE4F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4FA,
	INVALID_GB_INNER_CODE,
	0xE4FD,
	INVALID_GB_INNER_CODE,
	0xE4FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3BA,
	0xE4F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4F9,
	0xE4F8,
	0xC5EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCA4,
	INVALID_GB_INNER_CODE,
	0xE5A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE4FE,
	0xB1F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5A8,
	INVALID_GB_INNER_CODE,
	0xE5A9,
	0xE5A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5A7,
	0xE5AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5AB,
	0xE5AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBF0,
	0xECE1,
	0xC3F0,
	INVALID_GB_INNER_CODE,
	0xB5C6,
	0xBBD2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1E9,
	0xD4EE,
	INVALID_GB_INNER_CODE,
	0xBEC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7C6,
	INVALID_GB_INNER_CODE,
	0xD4D6,
	0xB2D3,
	0xECBE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2AF,
	0xB4B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3B4,
	INVALID_GB_INNER_CODE,
	0xC8B2,
	0xBFBB,
	0xECC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECBF,
	0xECC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECC5,
	0xBEE6,
	0xCCBF,
	0xC5DA,
	0xBEBC,
	INVALID_GB_INNER_CODE,
	0xECC6,
	INVALID_GB_INNER_CODE,
	0xB1FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECC4,
	0xD5A8,
	0xB5E3,
	INVALID_GB_INNER_CODE,
	0xECC2,
	0xC1B6,
	0xB3E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECC3,
	0xCBB8,
	0xC0C3,
	0xCCFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1D2,
	INVALID_GB_INNER_CODE,
	0xECC8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAE6,
	0xC0D3,
	INVALID_GB_INNER_CODE,
	0xD6F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFBE,
	INVALID_GB_INNER_CODE,
	0xB7B3,
	0xC9D5,
	0xECC7,
	0xBBE2,
	INVALID_GB_INNER_CODE,
	0xCCCC,
	0xBDFD,
	0xC8C8,
	INVALID_GB_INNER_CODE,
	0xCFA9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDE9,
	INVALID_GB_INNER_CODE,
	0xC5EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1C9,
	0xBAB8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECCA,
	INVALID_GB_INNER_CODE,
	0xBBC0,
	0xECCB,
	INVALID_GB_INNER_CODE,
	0xECE2,
	0xB1BA,
	0xB7D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECCC,
	0xD1E6,
	0xECCD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECD1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECD3,
	INVALID_GB_INNER_CODE,
	0xBBCD,
	INVALID_GB_INNER_CODE,
	0xBCE5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECCF,
	INVALID_GB_INNER_CODE,
	0xC9B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3BA,
	INVALID_GB_INNER_CODE,
	0xECE3,
	0xD5D5,
	0xECD0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECD2,
	0xECCE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECD4,
	INVALID_GB_INNER_CODE,
	0xECD5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFA8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECD6,
	0xCEF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAEC,
	0xECDA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECD9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECD7,
	INVALID_GB_INNER_CODE,
	0xECD8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECE4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECDC,
	0xD1E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECDB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4EF,
	INVALID_GB_INNER_CODE,
	0xECDD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBC6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECDE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECDF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECE0,
	INVALID_GB_INNER_CODE,
	0xD7A6,
	INVALID_GB_INNER_CODE,
	0xC5C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBBC,
	0xB0AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEF4,
	0xB8B8,
	0xD2AF,
	0xB0D6,
	0xB5F9,
	INVALID_GB_INNER_CODE,
	0xD8B3,
	INVALID_GB_INNER_CODE,
	0xCBAC,
	INVALID_GB_INNER_CODE,
	0xE3DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6AC,
	0xB0E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5C6,
	0xEBB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBBA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBBB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1C0,
	INVALID_GB_INNER_CODE,
	0xC5A3,
	INVALID_GB_INNER_CODE,
	0xEAF2,
	INVALID_GB_INNER_CODE,
	0xC4B2,
	INVALID_GB_INNER_CODE,
	0xC4B5,
	0xC0CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAF3,
	0xC4C1,
	INVALID_GB_INNER_CODE,
	0xCEEF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAF0,
	0xEAF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCD8,
	0xCEFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAF5,
	0xEAF6,
	0xCFAC,
	0xC0E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAF7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6BF,
	0xEAF8,
	INVALID_GB_INNER_CODE,
	0xEAF9,
	INVALID_GB_INNER_CODE,
	0xEAFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAF1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8AE,
	0xE1EB,
	INVALID_GB_INNER_CODE,
	0xB7B8,
	0xE1EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1ED,
	INVALID_GB_INNER_CODE,
	0xD7B4,
	0xE1EE,
	0xE1EF,
	0xD3CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1F1,
	0xBFF1,
	0xE1F0,
	0xB5D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1F3,
	0xE1F2,
	INVALID_GB_INNER_CODE,
	0xBAFC,
	INVALID_GB_INNER_CODE,
	0xE1F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9B7,
	INVALID_GB_INNER_CODE,
	0xBED1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4FC,
	INVALID_GB_INNER_CODE,
	0xBADD,
	0xBDC6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1F5,
	0xE1F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6C0,
	0xCFC1,
	0xCAA8,
	0xE1F6,
	0xD5F8,
	0xD3FC,
	0xE1F8,
	0xE1FC,
	0xE1F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1FA,
	0xC0EA,
	INVALID_GB_INNER_CODE,
	0xE1FE,
	0xE2A1,
	0xC0C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1FB,
	INVALID_GB_INNER_CODE,
	0xE1FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2A3,
	INVALID_GB_INNER_CODE,
	0xE2A8,
	0xB2FE,
	0xE2A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3CD,
	0xB2C2,
	0xE2A7,
	0xE2A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2A4,
	0xE2A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0C9,
	0xD6ED,
	0xC3A8,
	0xE2AC,
	INVALID_GB_INNER_CODE,
	0xCFD7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAEF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE9E0,
	0xE2AD,
	0xE2AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBAB,
	0xD4B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2AF,
	INVALID_GB_INNER_CODE,
	0xE9E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2B3,
	0xCCA1,
	INVALID_GB_INNER_CODE,
	0xE2B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2CA,
	INVALID_GB_INNER_CODE,
	0xD3F1,
	INVALID_GB_INNER_CODE,
	0xCDF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDE6,
	INVALID_GB_INNER_CODE,
	0xC3B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7E2,
	0xBBB7,
	0xCFD6,
	INVALID_GB_INNER_CODE,
	0xC1E1,
	0xE7E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7F4,
	0xB2A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7EA,
	INVALID_GB_INNER_CODE,
	0xE7E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7EC,
	0xE7EB,
	0xC9BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5E4,
	INVALID_GB_INNER_CODE,
	0xE7E5,
	0xB7A9,
	0xE7E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7F3,
	INVALID_GB_INNER_CODE,
	0xD6E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7ED,
	INVALID_GB_INNER_CODE,
	0xE7F2,
	INVALID_GB_INNER_CODE,
	0xE7F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7F2,
	INVALID_GB_INNER_CODE,
	0xC0C5,
	0xC0ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1F0,
	0xE7F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7F6,
	0xCBF6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8A2,
	0xE8A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7FA,
	0xE7F9,
	INVALID_GB_INNER_CODE,
	0xE7FB,
	INVALID_GB_INNER_CODE,
	0xE7F7,
	INVALID_GB_INNER_CODE,
	0xE7FE,
	INVALID_GB_INNER_CODE,
	0xE7FD,
	INVALID_GB_INNER_CODE,
	0xE7FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1D5,
	0xC7D9,
	0xC5FD,
	0xC5C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8A6,
	INVALID_GB_INNER_CODE,
	0xE8A5,
	INVALID_GB_INNER_CODE,
	0xE8A7,
	0xBAF7,
	0xE7F8,
	0xE8A4,
	INVALID_GB_INNER_CODE,
	0xC8F0,
	0xC9AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1FE,
	0xE8A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8AA,
	INVALID_GB_INNER_CODE,
	0xE8AD,
	0xE8AE,
	INVALID_GB_INNER_CODE,
	0xC1A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8AC,
	INVALID_GB_INNER_CODE,
	0xE8B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8AB,
	INVALID_GB_INNER_CODE,
	0xE8B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8B5,
	0xE8B2,
	0xE8B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE8B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9CF,
	INVALID_GB_INNER_CODE,
	0xF0AC,
	INVALID_GB_INNER_CODE,
	0xF0AD,
	INVALID_GB_INNER_CODE,
	0xC6B0,
	0xB0EA,
	0xC8BF,
	INVALID_GB_INNER_CODE,
	0xCDDF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCECD,
	0xEAB1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAB2,
	INVALID_GB_INNER_CODE,
	0xC6BF,
	0xB4C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAB3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDF9,
	INVALID_GB_INNER_CODE,
	0xEAB4,
	INVALID_GB_INNER_CODE,
	0xEAB5,
	INVALID_GB_INNER_CODE,
	0xEAB6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8CA,
	0xDFB0,
	0xC9F5,
	INVALID_GB_INNER_CODE,
	0xCCF0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3C3,
	0xCBA6,
	INVALID_GB_INNER_CODE,
	0xB8A6,
	0xF0AE,
	0xB1C2,
	INVALID_GB_INNER_CODE,
	0xE5B8,
	0xCCEF,
	0xD3C9,
	0xBCD7,
	0xC9EA,
	INVALID_GB_INNER_CODE,
	0xB5E7,
	INVALID_GB_INNER_CODE,
	0xC4D0,
	0xB5E9,
	INVALID_GB_INNER_CODE,
	0xEEAE,
	0xBBAD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7DE,
	INVALID_GB_INNER_CODE,
	0xEEAF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEB2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEB1,
	0xBDE7,
	INVALID_GB_INNER_CODE,
	0xEEB0,
	0xCEB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1F4,
	0xDBCE,
	0xEEB3,
	0xD0F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2D4,
	0xC6E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEB4,
	INVALID_GB_INNER_CODE,
	0xB3EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBFB,
	0xEEB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE7DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEB6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAE8,
	INVALID_GB_INNER_CODE,
	0xD2C9,
	0xF0DA,
	INVALID_GB_INNER_CODE,
	0xF0DB,
	INVALID_GB_INNER_CODE,
	0xF0DC,
	0xC1C6,
	INVALID_GB_INNER_CODE,
	0xB8ED,
	0xBECE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0DE,
	INVALID_GB_INNER_CODE,
	0xC5B1,
	0xF0DD,
	0xD1F1,
	INVALID_GB_INNER_CODE,
	0xF0E0,
	0xB0CC,
	0xBDEA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2DF,
	0xF0DF,
	INVALID_GB_INNER_CODE,
	0xB4AF,
	0xB7E8,
	0xF0E6,
	0xF0E5,
	0xC6A3,
	0xF0E1,
	0xF0E2,
	0xB4C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0E3,
	0xD5EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCDB,
	0xBED2,
	0xBCB2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0E8,
	0xF0E7,
	0xF0E4,
	0xB2A1,
	INVALID_GB_INNER_CODE,
	0xD6A2,
	0xD3B8,
	0xBEB7,
	0xC8AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1F7,
	INVALID_GB_INNER_CODE,
	0xD6CC,
	0xBADB,
	0xF0E9,
	INVALID_GB_INNER_CODE,
	0xB6BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1A1,
	0xF0EB,
	0xF0EE,
	INVALID_GB_INNER_CODE,
	0xF0ED,
	0xF0F0,
	0xF0EC,
	INVALID_GB_INNER_CODE,
	0xBBBE,
	0xF0EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCB5,
	0xF0F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0F4,
	0xF0F6,
	0xB4E1,
	INVALID_GB_INNER_CODE,
	0xF0F1,
	INVALID_GB_INNER_CODE,
	0xF0F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0FA,
	INVALID_GB_INNER_CODE,
	0xF0F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0FD,
	INVALID_GB_INNER_CODE,
	0xF0F9,
	0xF0FC,
	0xF0FE,
	INVALID_GB_INNER_CODE,
	0xF1A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEC1,
	0xF1A4,
	INVALID_GB_INNER_CODE,
	0xF1A3,
	INVALID_GB_INNER_CODE,
	0xC1F6,
	0xF0FB,
	0xCADD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4F1,
	0xB1F1,
	0xCCB1,
	INVALID_GB_INNER_CODE,
	0xF1A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1AC,
	0xD5CE,
	0xF1A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1A2,
	INVALID_GB_INNER_CODE,
	0xF1AB,
	0xF1A8,
	0xF1A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0A9,
	0xF1AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1AF,
	INVALID_GB_INNER_CODE,
	0xF1B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1B0,
	INVALID_GB_INNER_CODE,
	0xF1AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5C7,
	INVALID_GB_INNER_CODE,
	0xB0D7,
	0xB0D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4ED,
	INVALID_GB_INNER_CODE,
	0xB5C4,
	INVALID_GB_INNER_CODE,
	0xBDD4,
	0xBBCA,
	0xF0A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0A8,
	INVALID_GB_INNER_CODE,
	0xF0A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6E5,
	0xF1E4,
	INVALID_GB_INNER_CODE,
	0xF1E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6D1,
	0xC5E8,
	INVALID_GB_INNER_CODE,
	0xD3AF,
	INVALID_GB_INNER_CODE,
	0xD2E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEC1,
	0xB0BB,
	0xD5B5,
	0xD1CE,
	0xBCE0,
	0xBAD0,
	INVALID_GB_INNER_CODE,
	0xBFF8,
	INVALID_GB_INNER_CODE,
	0xB8C7,
	0xB5C1,
	0xC5CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAA2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEC2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4BF,
	0xB6A2,
	INVALID_GB_INNER_CODE,
	0xEDEC,
	0xC3A4,
	INVALID_GB_INNER_CODE,
	0xD6B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFE0,
	0xEDEF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5CE,
	INVALID_GB_INNER_CODE,
	0xB6DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDF0,
	0xEDF1,
	0xC3BC,
	INVALID_GB_INNER_CODE,
	0xBFB4,
	INVALID_GB_INNER_CODE,
	0xEDEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDF4,
	0xEDF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5E6,
	0xC3DF,
	INVALID_GB_INNER_CODE,
	0xEDF3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDF6,
	INVALID_GB_INNER_CODE,
	0xD5A3,
	0xD1A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDF5,
	INVALID_GB_INNER_CODE,
	0xC3D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDF7,
	0xBFF4,
	0xBEEC,
	0xEDF8,
	INVALID_GB_INNER_CODE,
	0xCCF7,
	INVALID_GB_INNER_CODE,
	0xD1DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7C5,
	0xD5F6,
	INVALID_GB_INNER_CODE,
	0xEDFC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDF9,
	0xEDFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDFD,
	0xBEA6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBAF,
	0xEEA1,
	0xB6BD,
	INVALID_GB_INNER_CODE,
	0xEEA2,
	0xC4C0,
	INVALID_GB_INNER_CODE,
	0xEDFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDDE,
	0xB2C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEA5,
	0xD8BA,
	0xEEA3,
	0xEEA6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3E9,
	0xB3F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEA7,
	0xEEA4,
	0xCFB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEA8,
	0xC2F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEA9,
	0xEEAA,
	INVALID_GB_INNER_CODE,
	0xDEAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6B3,
	INVALID_GB_INNER_CODE,
	0xC7C6,
	INVALID_GB_INNER_CODE,
	0xD6F5,
	0xB5C9,
	INVALID_GB_INNER_CODE,
	0xCBB2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDAB,
	INVALID_GB_INNER_CODE,
	0xEEAC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5B0,
	INVALID_GB_INNER_CODE,
	0xEEAD,
	INVALID_GB_INNER_CODE,
	0xF6C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBC7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3AC,
	0xF1E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAB8,
	0xD2D3,
	INVALID_GB_INNER_CODE,
	0xD6AA,
	INVALID_GB_INNER_CODE,
	0xEFF2,
	INVALID_GB_INNER_CODE,
	0xBED8,
	INVALID_GB_INNER_CODE,
	0xBDC3,
	0xEFF3,
	0xB6CC,
	0xB0AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAAF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDB6,
	INVALID_GB_INNER_CODE,
	0xEDB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEF9,
	0xB7AF,
	0xBFF3,
	0xEDB8,
	0xC2EB,
	0xC9B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6F6,
	0xBFB3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDBC,
	0xC5F8,
	INVALID_GB_INNER_CODE,
	0xD1D0,
	INVALID_GB_INNER_CODE,
	0xD7A9,
	0xEDBA,
	0xEDBB,
	INVALID_GB_INNER_CODE,
	0xD1E2,
	INVALID_GB_INNER_CODE,
	0xEDBF,
	0xEDC0,
	INVALID_GB_INNER_CODE,
	0xEDC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDC8,
	INVALID_GB_INNER_CODE,
	0xEDC6,
	0xEDCE,
	0xD5E8,
	INVALID_GB_INNER_CODE,
	0xEDC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDC7,
	0xEDBE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9E9,
	0xD4D2,
	0xEDC1,
	0xEDC2,
	0xEDC3,
	0xEDC5,
	INVALID_GB_INNER_CODE,
	0xC0F9,
	INVALID_GB_INNER_CODE,
	0xB4A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9E8,
	INVALID_GB_INNER_CODE,
	0xEDD0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDD1,
	INVALID_GB_INNER_CODE,
	0xEDCA,
	INVALID_GB_INNER_CODE,
	0xEDCF,
	INVALID_GB_INNER_CODE,
	0xCEF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBB6,
	0xEDCC,
	0xEDCD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDD2,
	0xC1F2,
	0xD3B2,
	0xEDCB,
	0xC8B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCEF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDD6,
	INVALID_GB_INNER_CODE,
	0xB5EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2B5,
	0xB0AD,
	0xCBE9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1AE,
	INVALID_GB_INNER_CODE,
	0xEDD4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDEB,
	0xB5E2,
	INVALID_GB_INNER_CODE,
	0xEDD5,
	0xEDD3,
	0xEDD7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5FA,
	INVALID_GB_INNER_CODE,
	0xEDD8,
	INVALID_GB_INNER_CODE,
	0xEDD9,
	INVALID_GB_INNER_CODE,
	0xEDDC,
	INVALID_GB_INNER_CODE,
	0xB1CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5F6,
	0xBCEE,
	0xEDDA,
	0xCCBC,
	0xB2EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDDB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDDF,
	0xC0DA,
	0xB4E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDDD,
	0xBFC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDDE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDE0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDE1,
	INVALID_GB_INNER_CODE,
	0xEDE3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBC7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDB8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDE2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDE4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDE6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDE5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDE7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCABE,
	0xECEA,
	0xC0F1,
	INVALID_GB_INNER_CODE,
	0xC9E7,
	INVALID_GB_INNER_CODE,
	0xECEB,
	0xC6EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECEC,
	INVALID_GB_INNER_CODE,
	0xC6ED,
	0xECED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECF0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7E6,
	0xECF3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECF1,
	0xECEE,
	0xECEF,
	0xD7A3,
	0xC9F1,
	0xCBEE,
	0xECF4,
	INVALID_GB_INNER_CODE,
	0xECF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFE9,
	INVALID_GB_INNER_CODE,
	0xECF6,
	0xC6B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCC0,
	INVALID_GB_INNER_CODE,
	0xECF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5BB,
	0xBBF6,
	INVALID_GB_INNER_CODE,
	0xECF7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9F7,
	0xBDFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2BB,
	0xECF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECF9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECFC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3ED,
	0xD8AE,
	0xC0EB,
	INVALID_GB_INNER_CODE,
	0xC7DD,
	0xBACC,
	INVALID_GB_INNER_CODE,
	0xD0E3,
	0xCBBD,
	INVALID_GB_INNER_CODE,
	0xCDBA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1FC,
	INVALID_GB_INNER_CODE,
	0xC7EF,
	INVALID_GB_INNER_CODE,
	0xD6D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFC6,
	0xC3EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEFF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEFF7,
	0xB3D3,
	INVALID_GB_INNER_CODE,
	0xC7D8,
	0xD1ED,
	INVALID_GB_INNER_CODE,
	0xD6C8,
	INVALID_GB_INNER_CODE,
	0xEFF8,
	INVALID_GB_INNER_CODE,
	0xEFF6,
	INVALID_GB_INNER_CODE,
	0xBBFD,
	0xB3C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDD5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2C6,
	INVALID_GB_INNER_CODE,
	0xBBE0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFA1,
	INVALID_GB_INNER_CODE,
	0xEFFC,
	0xEFFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEFF9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3CC,
	INVALID_GB_INNER_CODE,
	0xC9D4,
	0xCBB0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEFFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEFFD,
	INVALID_GB_INNER_CODE,
	0xB3ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEC8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0A2,
	INVALID_GB_INNER_CODE,
	0xF0A1,
	INVALID_GB_INNER_CODE,
	0xB5BE,
	0xBCDA,
	0xBBFC,
	INVALID_GB_INNER_CODE,
	0xB8E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBEB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1A8,
	INVALID_GB_INNER_CODE,
	0xBEBF,
	0xC7EE,
	0xF1B6,
	0xF1B7,
	0xBFD5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4A9,
	0xF1B8,
	0xCDBB,
	INVALID_GB_INNER_CODE,
	0xC7D4,
	0xD5AD,
	INVALID_GB_INNER_CODE,
	0xF1B9,
	INVALID_GB_INNER_CODE,
	0xF1BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2A4,
	0xD6CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1BB,
	0xBDD1,
	0xB4B0,
	0xBEBD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4DC,
	0xCED1,
	INVALID_GB_INNER_CODE,
	0xBFDF,
	0xF1BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFFA,
	0xF1BC,
	INVALID_GB_INNER_CODE,
	0xF1BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1BE,
	0xF1C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEBA,
	0xBEB9,
	0xD5C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFA2,
	INVALID_GB_INNER_CODE,
	0xCDAF,
	0xF1B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDDF,
	INVALID_GB_INNER_CODE,
	0xB6CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6F1,
	0xF3C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3C4,
	INVALID_GB_INNER_CODE,
	0xB8CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3C6,
	0xF3C7,
	INVALID_GB_INNER_CODE,
	0xB0CA,
	INVALID_GB_INNER_CODE,
	0xF3C5,
	INVALID_GB_INNER_CODE,
	0xF3C9,
	0xCBF1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3CB,
	INVALID_GB_INNER_CODE,
	0xD0A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1CA,
	0xF3C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3CF,
	INVALID_GB_INNER_CODE,
	0xB5D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3D7,
	INVALID_GB_INNER_CODE,
	0xF3D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3D4,
	0xF3D3,
	0xB7FB,
	INVALID_GB_INNER_CODE,
	0xB1BF,
	INVALID_GB_INNER_CODE,
	0xF3CE,
	0xF3CA,
	0xB5DA,
	INVALID_GB_INNER_CODE,
	0xF3D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3D1,
	INVALID_GB_INNER_CODE,
	0xF3D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3CD,
	INVALID_GB_INNER_CODE,
	0xBCE3,
	INVALID_GB_INNER_CODE,
	0xC1FD,
	INVALID_GB_INNER_CODE,
	0xF3D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3DA,
	INVALID_GB_INNER_CODE,
	0xF3CC,
	INVALID_GB_INNER_CODE,
	0xB5C8,
	INVALID_GB_INNER_CODE,
	0xBDEE,
	0xF3DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7A4,
	0xBFF0,
	0xD6FE,
	0xCDB2,
	INVALID_GB_INNER_CODE,
	0xB4F0,
	INVALID_GB_INNER_CODE,
	0xB2DF,
	INVALID_GB_INNER_CODE,
	0xF3D8,
	INVALID_GB_INNER_CODE,
	0xF3D9,
	0xC9B8,
	INVALID_GB_INNER_CODE,
	0xF3DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3DE,
	INVALID_GB_INNER_CODE,
	0xF3E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3E3,
	0xF3E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3DB,
	INVALID_GB_INNER_CODE,
	0xBFEA,
	INVALID_GB_INNER_CODE,
	0xB3EF,
	INVALID_GB_INNER_CODE,
	0xF3E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7A9,
	INVALID_GB_INNER_CODE,
	0xBCF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2AD,
	0xBBFE,
	INVALID_GB_INNER_CODE,
	0xCBE3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3ED,
	0xF3E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9DC,
	0xF3EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3E5,
	0xF3E6,
	0xF3EA,
	0xC2E1,
	0xF3EC,
	0xF3EF,
	0xF3E8,
	0xBCFD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFE4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7AD,
	0xC6AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3F1,
	INVALID_GB_INNER_CODE,
	0xC2A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8DD,
	0xF3F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3F6,
	0xF3F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3FB,
	INVALID_GB_INNER_CODE,
	0xF3FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3FE,
	0xF3F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4A3,
	0xBBC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2BE,
	0xF4A6,
	0xF4A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3D7,
	0xD9E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0E0,
	0xF4CC,
	0xD7D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4CE,
	0xC1A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6C9,
	INVALID_GB_INNER_CODE,
	0xB4D6,
	0xD5B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4D0,
	0xF4CF,
	0xF4D1,
	0xCBDA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4D2,
	INVALID_GB_INNER_CODE,
	0xD4C1,
	0xD6E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1BB,
	0xF4D3,
	0xBEAC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4D4,
	0xF4D5,
	0xBEAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4DB,
	INVALID_GB_INNER_CODE,
	0xF4D7,
	0xF4DA,
	INVALID_GB_INNER_CODE,
	0xBAFD,
	INVALID_GB_INNER_CODE,
	0xF4D8,
	0xF4D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8E2,
	0xCCC7,
	0xF4DC,
	INVALID_GB_INNER_CODE,
	0xB2DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4E3,
	0xBFB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBD8,
	INVALID_GB_INNER_CODE,
	0xCBF7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6F9,
	0xBEC0,
	0xE6FA,
	0xBAEC,
	0xE6FB,
	0xCFCB,
	0xE6FC,
	0xD4BC,
	0xBCB6,
	0xE6FD,
	0xE6FE,
	0xBCCD,
	0xC8D2,
	0xCEB3,
	0xE7A1,
	INVALID_GB_INNER_CODE,
	0xB4BF,
	0xE7A2,
	0xC9B4,
	0xB8D9,
	0xC4C9,
	INVALID_GB_INNER_CODE,
	0xD7DD,
	0xC2DA,
	0xB7D7,
	0xD6BD,
	0xCEC6,
	0xB7C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5A6,
	0xE7A3,
	0xCFDF,
	0xE7A4,
	0xE7A5,
	0xE7A6,
	0xC1B7,
	0xD7E9,
	0xC9F0,
	0xCFB8,
	0xD6AF,
	0xD6D5,
	0xE7A7,
	0xB0ED,
	0xE7A8,
	0xE7A9,
	0xC9DC,
	0xD2EF,
	0xBEAD,
	0xE7AA,
	0xB0F3,
	0xC8DE,
	0xBDE1,
	0xE7AB,
	0xC8C6,
	INVALID_GB_INNER_CODE,
	0xE7AC,
	0xBBE6,
	0xB8F8,
	0xD1A4,
	0xE7AD,
	0xC2E7,
	0xBEF8,
	0xBDCA,
	0xCDB3,
	0xE7AE,
	0xE7AF,
	0xBEEE,
	0xD0E5,
	INVALID_GB_INNER_CODE,
	0xCBE7,
	0xCCD0,
	0xBCCC,
	0xE7B0,
	0xBCA8,
	0xD0F7,
	0xE7B1,
	INVALID_GB_INNER_CODE,
	0xD0F8,
	0xE7B2,
	0xE7B3,
	0xB4C2,
	0xE7B4,
	0xE7B5,
	0xC9FE,
	0xCEAC,
	0xC3E0,
	0xE7B7,
	0xB1C1,
	0xB3F1,
	INVALID_GB_INNER_CODE,
	0xE7B8,
	0xE7B9,
	0xD7DB,
	0xD5C0,
	0xE7BA,
	0xC2CC,
	0xD7BA,
	0xE7BB,
	0xE7BC,
	0xE7BD,
	0xBCEA,
	0xC3E5,
	0xC0C2,
	0xE7BE,
	0xE7BF,
	0xBCA9,
	INVALID_GB_INNER_CODE,
	0xE7C0,
	0xE7C1,
	0xE7B6,
	0xB6D0,
	0xE7C2,
	INVALID_GB_INNER_CODE,
	0xE7C3,
	0xE7C4,
	0xBBBA,
	0xB5DE,
	0xC2C6,
	0xB1E0,
	0xE7C5,
	0xD4B5,
	0xE7C6,
	0xB8BF,
	0xE7C8,
	0xE7C7,
	0xB7EC,
	INVALID_GB_INNER_CODE,
	0xE7C9,
	0xB2F8,
	0xE7CA,
	0xE7CB,
	0xE7CC,
	0xE7CD,
	0xE7CE,
	0xE7CF,
	0xE7D0,
	0xD3A7,
	0xCBF5,
	0xE7D1,
	0xE7D2,
	0xE7D3,
	0xE7D4,
	0xC9C9,
	0xE7D5,
	0xE7D6,
	0xE7D7,
	0xE7D8,
	0xE7D9,
	0xBDC9,
	0xE7DA,
	0xF3BE,
	INVALID_GB_INNER_CODE,
	0xB8D7,
	INVALID_GB_INNER_CODE,
	0xC8B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3BF,
	INVALID_GB_INNER_CODE,
	0xF3C0,
	0xF3C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9DE,
	0xCDF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8E8,
	0xBAB1,
	INVALID_GB_INNER_CODE,
	0xC2DE,
	0xEEB7,
	INVALID_GB_INNER_CODE,
	0xB7A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEB9,
	INVALID_GB_INNER_CODE,
	0xEEB8,
	0xB0D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEBB,
	0xD5D6,
	0xD7EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEBD,
	0xCAF0,
	INVALID_GB_INNER_CODE,
	0xEEBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEBE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEBF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1F2,
	INVALID_GB_INNER_CODE,
	0xC7BC,
	INVALID_GB_INNER_CODE,
	0xC3C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4C6,
	0xD0DF,
	0xF4C7,
	INVALID_GB_INNER_CODE,
	0xCFDB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4C9,
	0xF4CA,
	INVALID_GB_INNER_CODE,
	0xF4CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9FA,
	0xB8FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5F1,
	0xD3F0,
	INVALID_GB_INNER_CODE,
	0xF4E0,
	INVALID_GB_INNER_CODE,
	0xCECC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1B4,
	INVALID_GB_INNER_CODE,
	0xD2EE,
	INVALID_GB_INNER_CODE,
	0xF4E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFE8,
	0xF4E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5D4,
	0xB4E4,
	0xF4E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4E3,
	0xF4E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4E7,
	INVALID_GB_INNER_CODE,
	0xBAB2,
	0xB0BF,
	INVALID_GB_INNER_CODE,
	0xF4E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7AD,
	0xD2ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2AB,
	0xC0CF,
	INVALID_GB_INNER_CODE,
	0xBFBC,
	0xEBA3,
	0xD5DF,
	0xEAC8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1F3,
	0xB6F8,
	0xCBA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4CD,
	INVALID_GB_INNER_CODE,
	0xF1E7,
	INVALID_GB_INNER_CODE,
	0xF1E8,
	0xB8FB,
	0xF1E9,
	0xBAC4,
	0xD4C5,
	0xB0D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1EB,
	INVALID_GB_INNER_CODE,
	0xF1EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1ED,
	0xF1EE,
	0xF1EF,
	0xF1F1,
	0xF1F0,
	0xC5D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1F2,
	INVALID_GB_INNER_CODE,
	0xB6FA,
	INVALID_GB_INNER_CODE,
	0xF1F4,
	0xD2AE,
	0xDEC7,
	0xCBCA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3DC,
	INVALID_GB_INNER_CODE,
	0xB5A2,
	INVALID_GB_INNER_CODE,
	0xB9A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4F4,
	0xF1F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1C4,
	0xC1FB,
	0xD6B0,
	0xF1F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1F8,
	INVALID_GB_INNER_CODE,
	0xC1AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6B8,
	INVALID_GB_INNER_CODE,
	0xBEDB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1F9,
	0xB4CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDB2,
	0xEDB1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBE0,
	0xD2DE,
	INVALID_GB_INNER_CODE,
	0xCBC1,
	0xD5D8,
	INVALID_GB_INNER_CODE,
	0xC8E2,
	INVALID_GB_INNER_CODE,
	0xC0DF,
	0xBCA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0A4,
	INVALID_GB_INNER_CODE,
	0xD6E2,
	INVALID_GB_INNER_CODE,
	0xB6C7,
	0xB8D8,
	0xEBC0,
	0xB8CE,
	INVALID_GB_INNER_CODE,
	0xEBBF,
	0xB3A6,
	0xB9C9,
	0xD6AB,
	INVALID_GB_INNER_CODE,
	0xB7F4,
	0xB7CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCE7,
	0xB7BE,
	0xEBC6,
	INVALID_GB_INNER_CODE,
	0xEBC7,
	0xB0B9,
	0xBFCF,
	INVALID_GB_INNER_CODE,
	0xEBC5,
	0xD3FD,
	INVALID_GB_INNER_CODE,
	0xEBC8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7CE,
	INVALID_GB_INNER_CODE,
	0xEBC2,
	0xEBC4,
	0xC9F6,
	0xD6D7,
	0xD5CD,
	0xD0B2,
	0xEBCF,
	0xCEB8,
	0xEBD0,
	INVALID_GB_INNER_CODE,
	0xB5A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1B3,
	0xEBD2,
	0xCCA5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5D6,
	0xEBD3,
	INVALID_GB_INNER_CODE,
	0xEBD1,
	0xC5DF,
	0xEBCE,
	0xCAA4,
	0xEBD5,
	0xB0FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8B7,
	0xF1E3,
	INVALID_GB_INNER_CODE,
	0xEBCA,
	0xEBCB,
	0xEBCC,
	0xEBCD,
	0xEBD6,
	0xE6C0,
	0xEBD9,
	INVALID_GB_INNER_CODE,
	0xBFE8,
	0xD2C8,
	0xEBD7,
	0xEBDC,
	0xB8EC,
	0xEBD8,
	INVALID_GB_INNER_CODE,
	0xBDBA,
	INVALID_GB_INNER_CODE,
	0xD0D8,
	INVALID_GB_INNER_CODE,
	0xB0B7,
	INVALID_GB_INNER_CODE,
	0xEBDD,
	0xC4DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2F6,
	0xBCB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBDA,
	0xEBDB,
	0xD4E0,
	0xC6EA,
	0xC4D4,
	0xEBDF,
	0xC5A7,
	0xD9F5,
	INVALID_GB_INNER_CODE,
	0xB2B1,
	INVALID_GB_INNER_CODE,
	0xEBE4,
	INVALID_GB_INNER_CODE,
	0xBDC5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBE2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBE3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8AC,
	INVALID_GB_INNER_CODE,
	0xCDD1,
	0xEBE5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBE1,
	INVALID_GB_INNER_CODE,
	0xC1B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCF3,
	INVALID_GB_INNER_CODE,
	0xEBE6,
	INVALID_GB_INNER_CODE,
	0xC0B0,
	0xD2B8,
	0xEBE7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8AF,
	0xB8AD,
	INVALID_GB_INNER_CODE,
	0xEBE8,
	0xC7BB,
	0xCDF3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBEA,
	0xEBEB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0C8,
	INVALID_GB_INNER_CODE,
	0xEBF2,
	INVALID_GB_INNER_CODE,
	0xEBEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBF1,
	0xC8F9,
	INVALID_GB_INNER_CODE,
	0xD1FC,
	0xEBEC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBE9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8B9,
	0xCFD9,
	0xC4E5,
	0xEBEF,
	0xEBF0,
	0xCCDA,
	0xCDC8,
	0xB0F2,
	INVALID_GB_INNER_CODE,
	0xEBF6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBF5,
	INVALID_GB_INNER_CODE,
	0xB2B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8E0,
	INVALID_GB_INNER_CODE,
	0xEBF7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCC5,
	0xC4A4,
	0xCFA5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBF9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECA2,
	INVALID_GB_INNER_CODE,
	0xC5F2,
	INVALID_GB_INNER_CODE,
	0xEBFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2DF,
	0xEBFE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDCE,
	0xECA1,
	0xB1DB,
	0xD3B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBFD,
	INVALID_GB_INNER_CODE,
	0xEBFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAB0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7D4,
	INVALID_GB_INNER_CODE,
	0xF4AB,
	0xB3F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6C1,
	0xD6C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5E9,
	0xBECA,
	INVALID_GB_INNER_CODE,
	0xF4A7,
	INVALID_GB_INNER_CODE,
	0xD2A8,
	0xF4A8,
	0xF4A9,
	INVALID_GB_INNER_CODE,
	0xF4AA,
	0xBECB,
	0xD3DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9E0,
	0xC9E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3C2,
	INVALID_GB_INNER_CODE,
	0xCAE6,
	INVALID_GB_INNER_CODE,
	0xCCF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2B6,
	0xCBB4,
	INVALID_GB_INNER_CODE,
	0xCEE8,
	0xD6DB,
	INVALID_GB_INNER_CODE,
	0xF4AD,
	0xF4AE,
	0xF4AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4B2,
	INVALID_GB_INNER_CODE,
	0xBABD,
	0xF4B3,
	0xB0E3,
	0xF4B0,
	INVALID_GB_INNER_CODE,
	0xF4B1,
	0xBDA2,
	0xB2D5,
	INVALID_GB_INNER_CODE,
	0xF4B6,
	0xF4B7,
	0xB6E6,
	0xB2B0,
	0xCFCF,
	0xF4B4,
	0xB4AC,
	INVALID_GB_INNER_CODE,
	0xF4B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDA7,
	INVALID_GB_INNER_CODE,
	0xF4BA,
	INVALID_GB_INNER_CODE,
	0xF4BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBD2,
	INVALID_GB_INNER_CODE,
	0xF4BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4DE,
	0xC1BC,
	0xBCE8,
	INVALID_GB_INNER_CODE,
	0xC9AB,
	0xD1DE,
	0xE5F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCB3,
	0xD2D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCB4,
	0xB0AC,
	0xDCB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDDA,
	INVALID_GB_INNER_CODE,
	0xDCB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8C2,
	INVALID_GB_INNER_CODE,
	0xDCB7,
	0xD3F3,
	INVALID_GB_INNER_CODE,
	0xC9D6,
	0xDCBA,
	0xDCB6,
	INVALID_GB_INNER_CODE,
	0xDCBB,
	0xC3A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCBC,
	0xDCC5,
	0xDCBD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEDF,
	0xD6A5,
	INVALID_GB_INNER_CODE,
	0xDCCF,
	INVALID_GB_INNER_CODE,
	0xDCCD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCD2,
	0xBDE6,
	0xC2AB,
	INVALID_GB_INNER_CODE,
	0xDCB8,
	0xDCCB,
	0xDCCE,
	0xDCBE,
	0xB7D2,
	0xB0C5,
	0xDCC7,
	0xD0BE,
	0xDCC1,
	0xBBA8,
	INVALID_GB_INNER_CODE,
	0xB7BC,
	0xDCCC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCC6,
	0xDCBF,
	0xC7DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1BF,
	0xDCC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCCA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCD0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEAD,
	0xDCC2,
	INVALID_GB_INNER_CODE,
	0xDCC3,
	0xDCC8,
	0xDCC9,
	0xB2D4,
	0xDCD1,
	0xCBD5,
	INVALID_GB_INNER_CODE,
	0xD4B7,
	0xDCDB,
	0xDCDF,
	0xCCA6,
	0xDCE6,
	INVALID_GB_INNER_CODE,
	0xC3E7,
	0xDCDC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFC1,
	0xDCD9,
	INVALID_GB_INNER_CODE,
	0xB0FA,
	0xB9B6,
	0xDCE5,
	0xDCD3,
	INVALID_GB_INNER_CODE,
	0xDCC4,
	0xDCD6,
	0xC8F4,
	0xBFE0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1BD,
	INVALID_GB_INNER_CODE,
	0xD3A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCDA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCD5,
	INVALID_GB_INNER_CODE,
	0xC6BB,
	INVALID_GB_INNER_CODE,
	0xDCDE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7C2,
	0xC3AF,
	0xB7B6,
	0xC7D1,
	0xC3A9,
	0xDCE2,
	0xDCD8,
	0xDCEB,
	0xDCD4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCDD,
	INVALID_GB_INNER_CODE,
	0xBEA5,
	0xDCD7,
	INVALID_GB_INNER_CODE,
	0xDCE0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCE3,
	0xDCE4,
	INVALID_GB_INNER_CODE,
	0xDCF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCE1,
	0xDDA2,
	0xDCE7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCEB,
	0xB4C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3A3,
	0xB2E7,
	0xDCFA,
	INVALID_GB_INNER_CODE,
	0xDCF2,
	INVALID_GB_INNER_CODE,
	0xDCEF,
	INVALID_GB_INNER_CODE,
	0xDCFC,
	0xDCEE,
	0xD2F0,
	0xB2E8,
	INVALID_GB_INNER_CODE,
	0xC8D7,
	0xC8E3,
	0xDCFB,
	INVALID_GB_INNER_CODE,
	0xDCED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCF7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCF5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEA3,
	0xDCF4,
	INVALID_GB_INNER_CODE,
	0xB2DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCF3,
	0xBCF6,
	0xDCE8,
	0xBBC4,
	INVALID_GB_INNER_CODE,
	0xC0F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCD4,
	0xDCE9,
	0xDCEA,
	INVALID_GB_INNER_CODE,
	0xDCF1,
	0xDCF6,
	0xDCF9,
	0xB5B4,
	INVALID_GB_INNER_CODE,
	0xC8D9,
	0xBBE7,
	0xDCFE,
	0xDCFD,
	0xD3AB,
	0xDDA1,
	0xDDA3,
	0xDDA5,
	0xD2F1,
	0xDDA4,
	0xDDA6,
	0xDDA7,
	0xD2A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAC9,
	0xDDA9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDB6,
	0xDDB1,
	0xDDB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDB0,
	0xC6CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCEC,
	0xDDAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCF0,
	0xDDAF,
	INVALID_GB_INNER_CODE,
	0xDDB8,
	INVALID_GB_INNER_CODE,
	0xDDAC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDB9,
	0xDDB3,
	0xDDAD,
	0xC4AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDA8,
	0xC0B3,
	0xC1AB,
	0xDDAA,
	0xDDAB,
	INVALID_GB_INNER_CODE,
	0xDDB2,
	0xBBF1,
	0xDDB5,
	0xD3A8,
	0xDDBA,
	INVALID_GB_INNER_CODE,
	0xDDBB,
	0xC3A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDD2,
	0xDDBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDD1,
	INVALID_GB_INNER_CODE,
	0xB9BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBED5,
	INVALID_GB_INNER_CODE,
	0xBEFA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBACA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDCA,
	INVALID_GB_INNER_CODE,
	0xDDC5,
	INVALID_GB_INNER_CODE,
	0xDDBF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2CB,
	0xDDC3,
	INVALID_GB_INNER_CODE,
	0xDDCB,
	0xB2A4,
	0xDDD5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDBE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6D0,
	0xDDD0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDD4,
	0xC1E2,
	0xB7C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDCE,
	0xDDCF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDBD,
	INVALID_GB_INNER_CODE,
	0xDDCD,
	0xCCD1,
	INVALID_GB_INNER_CODE,
	0xDDC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDC2,
	0xC3C8,
	0xC6BC,
	0xCEAE,
	0xDDCC,
	INVALID_GB_INNER_CODE,
	0xDDC8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDC6,
	0xC2DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3A9,
	0xD3AA,
	0xDDD3,
	0xCFF4,
	0xC8F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDE6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDC7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDE0,
	0xC2E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDE1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDD7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6F8,
	INVALID_GB_INNER_CODE,
	0xDDD9,
	0xDDD8,
	0xB8F0,
	0xDDD6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6CF,
	INVALID_GB_INNER_CODE,
	0xB6AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDE2,
	INVALID_GB_INNER_CODE,
	0xBAF9,
	0xD4E1,
	0xDDE7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4D0,
	INVALID_GB_INNER_CODE,
	0xDDDA,
	INVALID_GB_INNER_CODE,
	0xBFFB,
	0xDDE3,
	INVALID_GB_INNER_CODE,
	0xDDDF,
	INVALID_GB_INNER_CODE,
	0xDDDD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDDB,
	0xDDDC,
	0xDDDE,
	INVALID_GB_INNER_CODE,
	0xBDAF,
	0xDDE4,
	INVALID_GB_INNER_CODE,
	0xDDE5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDF5,
	INVALID_GB_INNER_CODE,
	0xC3C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBE2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDF2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6D1,
	INVALID_GB_INNER_CODE,
	0xDDF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5F4,
	0xDDF3,
	0xDDF0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDEC,
	INVALID_GB_INNER_CODE,
	0xDDEF,
	INVALID_GB_INNER_CODE,
	0xDDE8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8D8,
	0xDDEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDE9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDEA,
	0xCBF2,
	INVALID_GB_INNER_CODE,
	0xDDED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0B6,
	INVALID_GB_INNER_CODE,
	0xBCBB,
	0xDDF1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDF7,
	INVALID_GB_INNER_CODE,
	0xDDF6,
	0xDDEB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC5EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDFB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEA4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3EF,
	INVALID_GB_INNER_CODE,
	0xC2FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDDFD,
	INVALID_GB_INNER_CODE,
	0xB2CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4E8,
	0xCADF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7BE,
	0xDDFA,
	0xDDFC,
	0xDDFE,
	0xDEA2,
	0xB0AA,
	0xB1CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEAC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEA6,
	0xBDB6,
	0xC8EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEA1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEA5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEA9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEA8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEA7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEAD,
	INVALID_GB_INNER_CODE,
	0xD4CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEB3,
	0xDEAA,
	0xDEAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1A1,
	0xDEB6,
	INVALID_GB_INNER_CODE,
	0xDEB1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEB2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1A6,
	0xDEB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEAF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEB0,
	INVALID_GB_INNER_CODE,
	0xD0BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEB4,
	0xCAED,
	0xDEB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEB8,
	INVALID_GB_INNER_CODE,
	0xDEB7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEBB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDE5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2D8,
	0xC3EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEBA,
	INVALID_GB_INNER_CODE,
	0xC5BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCD9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEBD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEBF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEC1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEBE,
	INVALID_GB_INNER_CODE,
	0xDEC0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDEC2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2AE,
	0xBBA2,
	0xC2B2,
	0xC5B0,
	0xC2C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBBD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3E6,
	0xF2B0,
	INVALID_GB_INNER_CODE,
	0xF2B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAAD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAE7,
	0xF2B3,
	0xF2B5,
	0xF2B4,
	0xCBE4,
	0xCFBA,
	0xF2B2,
	0xCAB4,
	0xD2CF,
	0xC2EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEC3,
	0xF2B8,
	0xB0F6,
	0xF2B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2BE,
	INVALID_GB_INNER_CODE,
	0xB2CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1C1,
	0xF2BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2BC,
	0xD4E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2BB,
	0xF2B6,
	0xF2BF,
	0xF2BD,
	INVALID_GB_INNER_CODE,
	0xF2B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2C7,
	0xF2C4,
	0xF2C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2CA,
	0xF2C2,
	0xF2C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2C1,
	INVALID_GB_INNER_CODE,
	0xC7F9,
	0xC9DF,
	INVALID_GB_INNER_CODE,
	0xF2C8,
	0xB9C6,
	0xB5B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2C3,
	0xF2C9,
	0xF2D0,
	0xF2D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBD7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2D5,
	0xCDDC,
	INVALID_GB_INNER_CODE,
	0xD6EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2D2,
	0xF2D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2CE,
	0xC2F9,
	INVALID_GB_INNER_CODE,
	0xD5DD,
	0xF2CC,
	0xF2CD,
	0xF2CF,
	0xF2D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2D9,
	0xD3BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6EA,
	INVALID_GB_INNER_CODE,
	0xCAF1,
	INVALID_GB_INNER_CODE,
	0xB7E4,
	0xF2D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2D8,
	0xF2DA,
	0xF2DD,
	0xF2DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1D1,
	0xF2D1,
	INVALID_GB_INNER_CODE,
	0xCDC9,
	INVALID_GB_INNER_CODE,
	0xCECF,
	0xD6A9,
	INVALID_GB_INNER_CODE,
	0xF2E3,
	INVALID_GB_INNER_CODE,
	0xC3DB,
	INVALID_GB_INNER_CODE,
	0xF2E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0AF,
	0xF2EC,
	0xF2DE,
	INVALID_GB_INNER_CODE,
	0xF2E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2E4,
	0xF2EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3AC,
	0xF2E5,
	0xB2F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2F2,
	INVALID_GB_INNER_CODE,
	0xD0AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBC8,
	INVALID_GB_INNER_CODE,
	0xF2F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2F6,
	0xF2F8,
	0xF2FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2F3,
	INVALID_GB_INNER_CODE,
	0xF2F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAFB,
	INVALID_GB_INNER_CODE,
	0xB5FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2EF,
	0xF2F7,
	0xF2ED,
	0xF2EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2EB,
	0xF3A6,
	INVALID_GB_INNER_CODE,
	0xF3A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2F4,
	INVALID_GB_INNER_CODE,
	0xC8DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF2FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3A7,
	0xF3A9,
	0xF3A4,
	INVALID_GB_INNER_CODE,
	0xF2FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3AB,
	INVALID_GB_INNER_CODE,
	0xF3AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3A1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B1,
	0xF3AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3AF,
	0xF2FE,
	0xF3AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3B7,
	INVALID_GB_INNER_CODE,
	0xC8E4,
	0xF3B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3BB,
	0xB4C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEC3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF3BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4AC,
	0xD0C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0D0,
	0xD1DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFCE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDD6,
	INVALID_GB_INNER_CODE,
	0xD1C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAE2,
	0xE1E9,
	0xD2C2,
	0xF1C2,
	0xB2B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1ED,
	0xF1C3,
	INVALID_GB_INNER_CODE,
	0xC9C0,
	0xB3C4,
	INVALID_GB_INNER_CODE,
	0xD9F2,
	INVALID_GB_INNER_CODE,
	0xCBA5,
	INVALID_GB_INNER_CODE,
	0xF1C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD6D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1C5,
	0xF4C0,
	0xF1C6,
	INVALID_GB_INNER_CODE,
	0xD4AC,
	0xF1C7,
	INVALID_GB_INNER_CODE,
	0xB0C0,
	0xF4C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4FC,
	INVALID_GB_INNER_CODE,
	0xC5DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCBB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDE0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1C8,
	INVALID_GB_INNER_CODE,
	0xD9F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1BB,
	INVALID_GB_INNER_CODE,
	0xCFAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2C3,
	0xC1D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7B0,
	0xF1C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9F6,
	INVALID_GB_INNER_CODE,
	0xD2E1,
	0xD4A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4C3,
	0xC8B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1CD,
	0xF1CF,
	0xBFE3,
	0xF1D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1D6,
	0xF1D1,
	INVALID_GB_INNER_CODE,
	0xC9D1,
	0xC5E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2E3,
	0xB9FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1D3,
	INVALID_GB_INNER_CODE,
	0xF1D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAD6,
	INVALID_GB_INNER_CODE,
	0xB0FD,
	0xF1D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1D8,
	0xF1D2,
	0xF1DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDCA,
	0xF1DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1DC,
	INVALID_GB_INNER_CODE,
	0xF1DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFE5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4C5,
	0xBDF3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF1E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEF7,
	INVALID_GB_INNER_CODE,
	0xD2AA,
	INVALID_GB_INNER_CODE,
	0xF1FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCFB,
	0xB9DB,
	INVALID_GB_INNER_CODE,
	0xB9E6,
	0xC3D9,
	0xCAD3,
	0xEAE8,
	0xC0C0,
	0xBEF5,
	0xEAE9,
	0xEAEA,
	0xEAEB,
	INVALID_GB_INNER_CODE,
	0xEAEC,
	0xEAED,
	0xEAEE,
	0xEAEF,
	0xBDC7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5FD,
	INVALID_GB_INNER_CODE,
	0xF5FE,
	INVALID_GB_INNER_CODE,
	0xF5FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDE2,
	INVALID_GB_INNER_CODE,
	0xF6A1,
	0xB4A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECB2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEBA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3FE,
	0xCCDC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAC4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEAF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAA5,
	0xBCC6,
	0xB6A9,
	0xB8BC,
	0xC8CF,
	0xBCA5,
	0xDAA6,
	0xDAA7,
	0xCCD6,
	0xC8C3,
	0xDAA8,
	0xC6FD,
	INVALID_GB_INNER_CODE,
	0xD1B5,
	0xD2E9,
	0xD1B6,
	0xBCC7,
	INVALID_GB_INNER_CODE,
	0xBDB2,
	0xBBE4,
	0xDAA9,
	0xDAAA,
	0xD1C8,
	0xDAAB,
	0xD0ED,
	0xB6EF,
	0xC2DB,
	INVALID_GB_INNER_CODE,
	0xCBCF,
	0xB7ED,
	0xC9E8,
	0xB7C3,
	0xBEF7,
	0xD6A4,
	0xDAAC,
	0xDAAD,
	0xC6C0,
	0xD7E7,
	0xCAB6,
	INVALID_GB_INNER_CODE,
	0xD5A9,
	0xCBDF,
	0xD5EF,
	0xDAAE,
	0xD6DF,
	0xB4CA,
	0xDAB0,
	0xDAAF,
	INVALID_GB_INNER_CODE,
	0xD2EB,
	0xDAB1,
	0xDAB2,
	0xDAB3,
	0xCAD4,
	0xDAB4,
	0xCAAB,
	0xDAB5,
	0xDAB6,
	0xB3CF,
	0xD6EF,
	0xDAB7,
	0xBBB0,
	0xB5AE,
	0xDAB8,
	0xDAB9,
	0xB9EE,
	0xD1AF,
	0xD2E8,
	0xDABA,
	0xB8C3,
	0xCFEA,
	0xB2EF,
	0xDABB,
	0xDABC,
	INVALID_GB_INNER_CODE,
	0xBDEB,
	0xCEDC,
	0xD3EF,
	0xDABD,
	0xCEF3,
	0xDABE,
	0xD3D5,
	0xBBE5,
	0xDABF,
	0xCBB5,
	0xCBD0,
	0xDAC0,
	0xC7EB,
	0xD6EE,
	0xDAC1,
	0xC5B5,
	0xB6C1,
	0xDAC2,
	0xB7CC,
	0xBFCE,
	0xDAC3,
	0xDAC4,
	0xCBAD,
	0xDAC5,
	0xB5F7,
	0xDAC6,
	0xC1C2,
	0xD7BB,
	0xDAC7,
	0xCCB8,
	INVALID_GB_INNER_CODE,
	0xD2EA,
	0xC4B1,
	0xDAC8,
	0xB5FD,
	0xBBD1,
	0xDAC9,
	0xD0B3,
	0xDACA,
	0xDACB,
	0xCEBD,
	0xDACC,
	0xDACD,
	0xDACE,
	0xB2F7,
	0xDAD1,
	0xDACF,
	0xD1E8,
	0xDAD0,
	0xC3D5,
	0xDAD2,
	INVALID_GB_INNER_CODE,
	0xDAD3,
	0xDAD4,
	0xDAD5,
	0xD0BB,
	0xD2A5,
	0xB0F9,
	0xDAD6,
	0xC7AB,
	0xDAD7,
	0xBDF7,
	0xC3A1,
	0xDAD8,
	0xDAD9,
	0xC3FD,
	0xCCB7,
	0xDADA,
	0xDADB,
	0xC0BE,
	0xC6D7,
	0xDADC,
	0xDADD,
	0xC7B4,
	0xDADE,
	0xDADF,
	0xB9C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6B9,
	0xF4F8,
	INVALID_GB_INNER_CODE,
	0xF4F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDE3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEBE0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFF3,
	0xBBBF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAC0,
	0xD4A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE1D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5F4,
	0xB1AA,
	0xB2F2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAD1,
	0xF5F6,
	INVALID_GB_INNER_CODE,
	0xC3B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1B4,
	0xD5EA,
	0xB8BA,
	INVALID_GB_INNER_CODE,
	0xB9B1,
	0xB2C6,
	0xD4F0,
	0xCFCD,
	0xB0DC,
	0xD5CB,
	0xBBF5,
	0xD6CA,
	0xB7B7,
	0xCCB0,
	0xC6B6,
	0xB1E1,
	0xB9BA,
	0xD6FC,
	0xB9E1,
	0xB7A1,
	0xBCFA,
	0xEADA,
	0xEADB,
	0xCCF9,
	0xB9F3,
	0xEADC,
	0xB4FB,
	0xC3B3,
	0xB7D1,
	0xBAD8,
	0xEADD,
	0xD4F4,
	0xEADE,
	0xBCD6,
	0xBBDF,
	0xEADF,
	0xC1DE,
	0xC2B8,
	0xD4DF,
	0xD7CA,
	0xEAE0,
	0xEAE1,
	0xEAE4,
	0xEAE2,
	0xEAE3,
	0xC9DE,
	0xB8B3,
	0xB6C4,
	0xEAE5,
	0xCAEA,
	0xC9CD,
	0xB4CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2D9,
	0xC5E2,
	0xEAE6,
	0xC0B5,
	INVALID_GB_INNER_CODE,
	0xD7B8,
	0xEAE7,
	0xD7AC,
	0xC8FC,
	0xD8D3,
	0xD8CD,
	0xD4DE,
	INVALID_GB_INNER_CODE,
	0xD4F9,
	0xC9C4,
	0xD3AE,
	0xB8D3,
	0xB3E0,
	INVALID_GB_INNER_CODE,
	0xC9E2,
	0xF4F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBAD5,
	INVALID_GB_INNER_CODE,
	0xF4F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4F1,
	0xB8B0,
	0xD5D4,
	0xB8CF,
	0xC6F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4F2,
	0xB3AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4BD,
	0xC7F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCCB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4F5,
	INVALID_GB_INNER_CODE,
	0xD7E3,
	0xC5BF,
	0xF5C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5BB,
	INVALID_GB_INNER_CODE,
	0xF5C3,
	INVALID_GB_INNER_CODE,
	0xF5C2,
	INVALID_GB_INNER_CODE,
	0xD6BA,
	0xF5C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4BE,
	0xF5C4,
	INVALID_GB_INNER_CODE,
	0xF5CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0CF,
	0xB5F8,
	INVALID_GB_INNER_CODE,
	0xF5C9,
	0xF5CA,
	INVALID_GB_INNER_CODE,
	0xC5DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5C5,
	0xF5C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5C7,
	0xF5CB,
	INVALID_GB_INNER_CODE,
	0xBEE0,
	0xF5C8,
	0xB8FA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5D0,
	0xF5D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFE7,
	INVALID_GB_INNER_CODE,
	0xB9F2,
	0xF5BC,
	0xF5CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCF8,
	INVALID_GB_INNER_CODE,
	0xBCF9,
	INVALID_GB_INNER_CODE,
	0xF5CE,
	0xF5CF,
	0xF5D1,
	0xB6E5,
	0xF5D2,
	INVALID_GB_INNER_CODE,
	0xF5D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5BD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5D4,
	0xD3BB,
	INVALID_GB_INNER_CODE,
	0xB3EC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCA4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5D7,
	0xBEE1,
	0xF5D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCDF,
	0xF5DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2C8,
	0xD7D9,
	INVALID_GB_INNER_CODE,
	0xF5D9,
	INVALID_GB_INNER_CODE,
	0xF5DA,
	0xF5DC,
	INVALID_GB_INNER_CODE,
	0xF5E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5DF,
	0xF5DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5E1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5DE,
	0xF5E4,
	0xF5E5,
	INVALID_GB_INNER_CODE,
	0xCCE3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5BF,
	0xB5B8,
	0xF5E3,
	0xF5E8,
	0xCCA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5E6,
	0xF5E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5C5,
	0xB2E4,
	INVALID_GB_INNER_CODE,
	0xF5EC,
	0xF5E9,
	INVALID_GB_INNER_CODE,
	0xB6D7,
	INVALID_GB_INNER_CODE,
	0xF5ED,
	INVALID_GB_INNER_CODE,
	0xF5EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4DA,
	INVALID_GB_INNER_CODE,
	0xD4EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5EE,
	INVALID_GB_INNER_CODE,
	0xB3F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5EF,
	0xF5F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5F2,
	INVALID_GB_INNER_CODE,
	0xF5F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC9ED,
	0xB9AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCC9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEAA6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3B5,
	0xD4FE,
	0xB9EC,
	0xD0F9,
	INVALID_GB_INNER_CODE,
	0xE9ED,
	0xD7AA,
	0xE9EE,
	0xC2D6,
	0xC8ED,
	0xBAE4,
	0xE9EF,
	0xE9F0,
	0xE9F1,
	0xD6E1,
	0xE9F2,
	0xE9F3,
	0xE9F5,
	0xE9F4,
	0xE9F6,
	0xE9F7,
	0xC7E1,
	0xE9F8,
	0xD4D8,
	0xE9F9,
	0xBDCE,
	INVALID_GB_INNER_CODE,
	0xE9FA,
	0xE9FB,
	0xBDCF,
	0xE9FC,
	0xB8A8,
	0xC1BE,
	0xE9FD,
	0xB1B2,
	0xBBD4,
	0xB9F5,
	0xE9FE,
	INVALID_GB_INNER_CODE,
	0xEAA1,
	0xEAA2,
	0xEAA3,
	0xB7F8,
	0xBCAD,
	INVALID_GB_INNER_CODE,
	0xCAE4,
	0xE0CE,
	0xD4AF,
	0xCFBD,
	0xD5B7,
	0xEAA4,
	0xD5DE,
	0xEAA5,
	0xD0C1,
	0xB9BC,
	INVALID_GB_INNER_CODE,
	0xB4C7,
	0xB1D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1E6,
	0xB1E7,
	INVALID_GB_INNER_CODE,
	0xB1E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3BD,
	0xC8E8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5C1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1C9,
	0xB4EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7A8,
	0xD3D8,
	INVALID_GB_INNER_CODE,
	0xC6F9,
	0xD1B8,
	INVALID_GB_INNER_CODE,
	0xB9FD,
	0xC2F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3AD,
	INVALID_GB_INNER_CODE,
	0xD4CB,
	0xBDFC,
	INVALID_GB_INNER_CODE,
	0xE5C2,
	0xB7B5,
	0xE5C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBB9,
	0xD5E2,
	INVALID_GB_INNER_CODE,
	0xBDF8,
	0xD4B6,
	0xCEA5,
	0xC1AC,
	0xB3D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCCF6,
	INVALID_GB_INNER_CODE,
	0xE5C6,
	0xE5C4,
	0xE5C8,
	INVALID_GB_INNER_CODE,
	0xE5CA,
	0xE5C7,
	0xB5CF,
	0xC6C8,
	INVALID_GB_INNER_CODE,
	0xB5FC,
	0xE5C5,
	INVALID_GB_INNER_CODE,
	0xCAF6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3D4,
	0xB1C5,
	0xBCA3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDCB,
	0xCBCD,
	0xCACA,
	0xCCD3,
	0xE5CC,
	0xE5CB,
	0xC4E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD1A1,
	0xD1B7,
	0xE5CD,
	INVALID_GB_INNER_CODE,
	0xE5D0,
	INVALID_GB_INNER_CODE,
	0xCDB8,
	0xD6F0,
	0xE5CF,
	0xB5DD,
	INVALID_GB_INNER_CODE,
	0xCDBE,
	INVALID_GB_INNER_CODE,
	0xE5D1,
	0xB6BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCDA8,
	0xB9E4,
	INVALID_GB_INNER_CODE,
	0xCAC5,
	0xB3D1,
	0xCBD9,
	0xD4EC,
	0xE5D2,
	0xB7EA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5D5,
	0xB4FE,
	0xE5D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5D3,
	0xE5D4,
	INVALID_GB_INNER_CODE,
	0xD2DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2DF,
	0xB1C6,
	INVALID_GB_INNER_CODE,
	0xD3E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6DD,
	0xCBEC,
	INVALID_GB_INNER_CODE,
	0xE5D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1E9,
	INVALID_GB_INNER_CODE,
	0xB6F4,
	0xE5DA,
	0xE5D8,
	0xE5D9,
	0xB5C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2C5,
	0xE5DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5DD,
	0xC7B2,
	INVALID_GB_INNER_CODE,
	0xD2A3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5DB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4E2,
	0xD5DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5E0,
	0xD7F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5E1,
	INVALID_GB_INNER_CODE,
	0xB1DC,
	0xD1FB,
	INVALID_GB_INNER_CODE,
	0xE5E2,
	0xE5E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2D8,
	INVALID_GB_INNER_CODE,
	0xB5CB,
	INVALID_GB_INNER_CODE,
	0xE7DF,
	INVALID_GB_INNER_CODE,
	0xDAF5,
	INVALID_GB_INNER_CODE,
	0xDAF8,
	INVALID_GB_INNER_CODE,
	0xDAF6,
	INVALID_GB_INNER_CODE,
	0xDAF7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAFA,
	0xD0CF,
	0xC4C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0B0,
	INVALID_GB_INNER_CODE,
	0xDAF9,
	INVALID_GB_INNER_CODE,
	0xD3CA,
	0xBAAA,
	0xDBA2,
	0xC7F1,
	INVALID_GB_INNER_CODE,
	0xDAFC,
	0xDAFB,
	0xC9DB,
	0xDAFD,
	INVALID_GB_INNER_CODE,
	0xDBA1,
	0xD7DE,
	0xDAFE,
	0xC1DA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBA5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBA7,
	0xDBA4,
	INVALID_GB_INNER_CODE,
	0xDBA8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC0C9,
	0xDBA3,
	0xDBA6,
	0xD6A3,
	INVALID_GB_INNER_CODE,
	0xDBA9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBAD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBAE,
	0xDBAC,
	0xBAC2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFA4,
	0xDBAB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBAA,
	0xD4C7,
	0xB2BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBAF,
	INVALID_GB_INNER_CODE,
	0xB9F9,
	INVALID_GB_INNER_CODE,
	0xDBB0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6BC,
	0xDBB1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB6F5,
	INVALID_GB_INNER_CODE,
	0xDBB2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBB3,
	0xDBB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBB7,
	INVALID_GB_INNER_CODE,
	0xDBB6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBB8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBB9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBBA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3CF,
	0xF4FA,
	0xC7F5,
	0xD7C3,
	0xC5E4,
	0xF4FC,
	0xF4FD,
	0xF4FB,
	INVALID_GB_INNER_CODE,
	0xBEC6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7D3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD4CD,
	0xCCAA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5A2,
	0xF5A1,
	0xBAA8,
	0xF4FE,
	0xCBD6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5A4,
	0xC0D2,
	INVALID_GB_INNER_CODE,
	0xB3EA,
	INVALID_GB_INNER_CODE,
	0xCDAA,
	0xF5A5,
	0xF5A3,
	0xBDB4,
	0xF5A8,
	INVALID_GB_INNER_CODE,
	0xF5A9,
	0xBDCD,
	0xC3B8,
	0xBFE1,
	0xCBE1,
	0xF5AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5A6,
	0xF5A7,
	0xC4F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5AC,
	INVALID_GB_INNER_CODE,
	0xB4BC,
	INVALID_GB_INNER_CODE,
	0xD7ED,
	INVALID_GB_INNER_CODE,
	0xB4D7,
	0xF5AB,
	0xF5AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5AD,
	0xF5AF,
	0xD0D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3D1,
	0xC8A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5B0,
	0xF5B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5B3,
	0xF5B4,
	0xF5B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5B7,
	0xF5B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5B8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2C9,
	INVALID_GB_INNER_CODE,
	0xD3D4,
	0xCACD,
	INVALID_GB_INNER_CODE,
	0xC0EF,
	0xD6D8,
	0xD2B0,
	0xC1BF,
	INVALID_GB_INNER_CODE,
	0xBDF0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBCF8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6C9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEC4,
	0xEEC5,
	0xEEC6,
	0xD5EB,
	0xB6A4,
	0xEEC8,
	0xEEC7,
	0xEEC9,
	0xEECA,
	0xC7A5,
	0xEECB,
	0xEECC,
	INVALID_GB_INNER_CODE,
	0xB7B0,
	0xB5F6,
	0xEECD,
	0xEECF,
	INVALID_GB_INNER_CODE,
	0xEECE,
	INVALID_GB_INNER_CODE,
	0xB8C6,
	0xEED0,
	0xEED1,
	0xEED2,
	0xB6DB,
	0xB3AE,
	0xD6D3,
	0xC4C6,
	0xB1B5,
	0xB8D6,
	0xEED3,
	0xEED4,
	0xD4BF,
	0xC7D5,
	0xBEFB,
	0xCED9,
	0xB9B3,
	0xEED6,
	0xEED5,
	0xEED8,
	0xEED7,
	0xC5A5,
	0xEED9,
	0xEEDA,
	0xC7AE,
	0xEEDB,
	0xC7AF,
	0xEEDC,
	0xB2A7,
	0xEEDD,
	0xEEDE,
	0xEEDF,
	0xEEE0,
	0xEEE1,
	0xD7EA,
	0xEEE2,
	0xEEE3,
	0xBCD8,
	0xEEE4,
	0xD3CB,
	0xCCFA,
	0xB2AC,
	0xC1E5,
	0xEEE5,
	0xC7A6,
	0xC3AD,
	INVALID_GB_INNER_CODE,
	0xEEE6,
	0xEEE7,
	0xEEE8,
	0xEEE9,
	0xEEEA,
	0xEEEB,
	0xEEEC,
	INVALID_GB_INNER_CODE,
	0xEEED,
	0xEEEE,
	0xEEEF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEEF0,
	0xEEF1,
	0xEEF2,
	0xEEF4,
	0xEEF3,
	INVALID_GB_INNER_CODE,
	0xEEF5,
	0xCDAD,
	0xC2C1,
	0xEEF6,
	0xEEF7,
	0xEEF8,
	0xD5A1,
	0xEEF9,
	0xCFB3,
	0xEEFA,
	0xEEFB,
	INVALID_GB_INNER_CODE,
	0xEEFC,
	0xEEFD,
	0xEFA1,
	0xEEFE,
	0xEFA2,
	0xB8F5,
	0xC3FA,
	0xEFA3,
	0xEFA4,
	0xBDC2,
	0xD2BF,
	0xB2F9,
	0xEFA5,
	0xEFA6,
	0xEFA7,
	0xD2F8,
	0xEFA8,
	0xD6FD,
	0xEFA9,
	0xC6CC,
	INVALID_GB_INNER_CODE,
	0xEFAA,
	0xEFAB,
	0xC1B4,
	0xEFAC,
	0xCFFA,
	0xCBF8,
	0xEFAE,
	0xEFAD,
	0xB3FA,
	0xB9F8,
	0xEFAF,
	0xEFB0,
	0xD0E2,
	0xEFB1,
	0xEFB2,
	0xB7E6,
	0xD0BF,
	0xEFB3,
	0xEFB4,
	0xEFB5,
	0xC8F1,
	0xCCE0,
	0xEFB6,
	0xEFB7,
	0xEFB8,
	0xEFB9,
	0xEFBA,
	0xD5E0,
	0xEFBB,
	0xB4ED,
	0xC3AA,
	0xEFBC,
	INVALID_GB_INNER_CODE,
	0xEFBD,
	0xEFBE,
	0xEFBF,
	INVALID_GB_INNER_CODE,
	0xCEFD,
	0xEFC0,
	0xC2E0,
	0xB4B8,
	0xD7B6,
	0xBDF5,
	INVALID_GB_INNER_CODE,
	0xCFC7,
	0xEFC3,
	0xEFC1,
	0xEFC2,
	0xEFC4,
	0xB6A7,
	0xBCFC,
	0xBEE2,
	0xC3CC,
	0xEFC5,
	0xEFC6,
	INVALID_GB_INNER_CODE,
	0xEFC7,
	0xEFCF,
	0xEFC8,
	0xEFC9,
	0xEFCA,
	0xC7C2,
	0xEFF1,
	0xB6CD,
	0xEFCB,
	INVALID_GB_INNER_CODE,
	0xEFCC,
	0xEFCD,
	0xB6C6,
	0xC3BE,
	0xEFCE,
	INVALID_GB_INNER_CODE,
	0xEFD0,
	0xEFD1,
	0xEFD2,
	0xD5F2,
	INVALID_GB_INNER_CODE,
	0xEFD3,
	0xC4F7,
	INVALID_GB_INNER_CODE,
	0xEFD4,
	0xC4F8,
	0xEFD5,
	0xEFD6,
	0xB8E4,
	0xB0F7,
	0xEFD7,
	0xEFD8,
	0xEFD9,
	INVALID_GB_INNER_CODE,
	0xEFDA,
	0xEFDB,
	0xEFDC,
	0xEFDD,
	INVALID_GB_INNER_CODE,
	0xEFDE,
	0xBEB5,
	0xEFE1,
	0xEFDF,
	0xEFE0,
	INVALID_GB_INNER_CODE,
	0xEFE2,
	0xEFE3,
	0xC1CD,
	0xEFE4,
	0xEFE5,
	0xEFE6,
	0xEFE7,
	0xEFE8,
	0xEFE9,
	0xEFEA,
	0xEFEB,
	0xEFEC,
	0xC0D8,
	INVALID_GB_INNER_CODE,
	0xEFED,
	0xC1AD,
	0xEFEE,
	0xEFEF,
	0xEFF0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFE2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3A4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC3C5,
	0xE3C5,
	0xC9C1,
	0xE3C6,
	INVALID_GB_INNER_CODE,
	0xB1D5,
	0xCECA,
	0xB4B3,
	0xC8F2,
	0xE3C7,
	0xCFD0,
	0xE3C8,
	0xBCE4,
	0xE3C9,
	0xE3CA,
	0xC3C6,
	0xD5A2,
	0xC4D6,
	0xB9EB,
	0xCEC5,
	0xE3CB,
	0xC3F6,
	0xE3CC,
	INVALID_GB_INNER_CODE,
	0xB7A7,
	0xB8F3,
	0xBAD2,
	0xE3CD,
	0xE3CE,
	0xD4C4,
	0xE3CF,
	INVALID_GB_INNER_CODE,
	0xE3D0,
	0xD1CB,
	0xE3D1,
	0xE3D2,
	0xE3D3,
	0xE3D4,
	0xD1D6,
	0xE3D5,
	0xB2FB,
	0xC0BB,
	0xE3D6,
	INVALID_GB_INNER_CODE,
	0xC0AB,
	0xE3D7,
	0xE3D8,
	0xE3D9,
	INVALID_GB_INNER_CODE,
	0xE3DA,
	0xE3DB,
	INVALID_GB_INNER_CODE,
	0xB8B7,
	0xDAE2,
	INVALID_GB_INNER_CODE,
	0xB6D3,
	INVALID_GB_INNER_CODE,
	0xDAE4,
	0xDAE3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAE6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8EE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAE5,
	0xB7C0,
	0xD1F4,
	0xD2F5,
	0xD5F3,
	0xBDD7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7E8,
	0xDAE8,
	0xDAE7,
	INVALID_GB_INNER_CODE,
	0xB0A2,
	0xCDD3,
	INVALID_GB_INNER_CODE,
	0xDAE9,
	INVALID_GB_INNER_CODE,
	0xB8BD,
	0xBCCA,
	0xC2BD,
	0xC2A4,
	0xB3C2,
	0xDAEA,
	INVALID_GB_INNER_CODE,
	0xC2AA,
	0xC4B0,
	0xBDB5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFDE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAEB,
	0xC9C2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB1DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAEC,
	INVALID_GB_INNER_CODE,
	0xB6B8,
	0xD4BA,
	INVALID_GB_INNER_CODE,
	0xB3FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAED,
	0xD4C9,
	0xCFD5,
	0xC5E3,
	INVALID_GB_INNER_CODE,
	0xDAEE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAEF,
	INVALID_GB_INNER_CODE,
	0xDAF0,
	0xC1EA,
	0xCCD5,
	0xCFDD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3E7,
	0xC2A1,
	INVALID_GB_INNER_CODE,
	0xDAF1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBE5,
	INVALID_GB_INNER_CODE,
	0xDAF2,
	INVALID_GB_INNER_CODE,
	0xCBE6,
	0xD2FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8F4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAF3,
	0xB0AF,
	0xCFB6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD5CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDAF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE3C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6BF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6C0,
	0xF6C1,
	0xC4D1,
	INVALID_GB_INNER_CODE,
	0xC8B8,
	0xD1E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0DB,
	0xD1C5,
	0xBCAF,
	0xB9CD,
	INVALID_GB_INNER_CODE,
	0xEFF4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB4C6,
	0xD3BA,
	0xF6C2,
	0xB3FB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB5F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6C5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3EA,
	0xF6A7,
	0xD1A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6A9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6A8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1E3,
	0xC0D7,
	INVALID_GB_INNER_CODE,
	0xB1A2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEED,
	INVALID_GB_INNER_CODE,
	0xD0E8,
	0xF6AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCFF6,
	INVALID_GB_INNER_CODE,
	0xF6AA,
	0xD5F0,
	0xF6AC,
	0xC3B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBF4,
	0xF6AE,
	0xF6AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCBAA,
	INVALID_GB_INNER_CODE,
	0xCFBC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6B1,
	INVALID_GB_INNER_CODE,
	0xC2B6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB0D4,
	0xC5F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6B2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7E0,
	0xF6A6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEB8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBEB2,
	INVALID_GB_INNER_CODE,
	0xB5E5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7C7,
	INVALID_GB_INNER_CODE,
	0xBFBF,
	0xC3D2,
	0xC3E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8CC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDF9,
	0xD1A5,
	INVALID_GB_INNER_CODE,
	0xB0D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7B1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD0AC,
	INVALID_GB_INNER_CODE,
	0xB0B0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7B2,
	0xF7B3,
	INVALID_GB_INNER_CODE,
	0xF7B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7CA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBECF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7B7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7B6,
	INVALID_GB_INNER_CODE,
	0xB1DE,
	INVALID_GB_INNER_CODE,
	0xF7B5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7B8,
	INVALID_GB_INNER_CODE,
	0xF7B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCEA4,
	0xC8CD,
	INVALID_GB_INNER_CODE,
	0xBAAB,
	0xE8B8,
	0xE8B9,
	0xE8BA,
	0xBEC2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2F4,
	INVALID_GB_INNER_CODE,
	0xD4CF,
	0xC9D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD2B3,
	0xB6A5,
	0xC7EA,
	0xF1FC,
	0xCFEE,
	0xCBB3,
	0xD0EB,
	0xE7EF,
	0xCDE7,
	0xB9CB,
	0xB6D9,
	0xF1FD,
	0xB0E4,
	0xCBCC,
	0xF1FE,
	0xD4A4,
	0xC2AD,
	0xC1EC,
	0xC6C4,
	0xBEB1,
	0xF2A1,
	0xBCD5,
	INVALID_GB_INNER_CODE,
	0xF2A2,
	0xF2A3,
	INVALID_GB_INNER_CODE,
	0xF2A4,
	0xD2C3,
	0xC6B5,
	INVALID_GB_INNER_CODE,
	0xCDC7,
	0xF2A5,
	INVALID_GB_INNER_CODE,
	0xD3B1,
	0xBFC5,
	0xCCE2,
	INVALID_GB_INNER_CODE,
	0xF2A6,
	0xF2A7,
	0xD1D5,
	0xB6EE,
	0xF2A8,
	0xF2A9,
	0xB5DF,
	0xF2AA,
	0xF2AB,
	INVALID_GB_INNER_CODE,
	0xB2FC,
	0xF2AC,
	0xF2AD,
	0xC8A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xECA9,
	0xECAA,
	0xECAB,
	INVALID_GB_INNER_CODE,
	0xECAC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6AE,
	0xECAD,
	0xECAE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB7C9,
	0xCAB3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2B8,
	0xF7CF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB2CD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7D1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7D3,
	0xF7D2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2BB,
	INVALID_GB_INNER_CODE,
	0xBCA2,
	INVALID_GB_INNER_CODE,
	0xE2BC,
	0xE2BD,
	0xE2BE,
	0xE2BF,
	0xE2C0,
	0xE2C1,
	0xB7B9,
	0xD2FB,
	0xBDA4,
	0xCACE,
	0xB1A5,
	0xCBC7,
	INVALID_GB_INNER_CODE,
	0xE2C2,
	0xB6FC,
	0xC8C4,
	0xE2C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBDC8,
	INVALID_GB_INNER_CODE,
	0xB1FD,
	0xE2C4,
	INVALID_GB_INNER_CODE,
	0xB6F6,
	0xE2C5,
	0xC4D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE2C6,
	0xCFDA,
	0xB9DD,
	0xE2C7,
	0xC0A1,
	INVALID_GB_INNER_CODE,
	0xE2C8,
	0xB2F6,
	INVALID_GB_INNER_CODE,
	0xE2C9,
	INVALID_GB_INNER_CODE,
	0xC1F3,
	0xE2CA,
	0xE2CB,
	0xC2F8,
	0xE2CC,
	0xE2CD,
	0xE2CE,
	0xCAD7,
	0xD8B8,
	0xD9E5,
	0xCFE3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDCB0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2ED,
	0xD4A6,
	0xCDD4,
	0xD1B1,
	0xB3DB,
	0xC7FD,
	INVALID_GB_INNER_CODE,
	0xB2B5,
	0xC2BF,
	0xE6E0,
	0xCABB,
	0xE6E1,
	0xE6E2,
	0xBED4,
	0xE6E3,
	0xD7A4,
	0xCDD5,
	0xE6E5,
	0xBCDD,
	0xE6E4,
	0xE6E6,
	0xE6E7,
	0xC2EE,
	INVALID_GB_INNER_CODE,
	0xBDBE,
	0xE6E8,
	0xC2E6,
	0xBAA7,
	0xE6E9,
	INVALID_GB_INNER_CODE,
	0xE6EA,
	0xB3D2,
	0xD1E9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFA5,
	0xE6EB,
	0xC6EF,
	0xE6EC,
	0xE6ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE6EE,
	0xC6AD,
	0xE6EF,
	INVALID_GB_INNER_CODE,
	0xC9A7,
	0xE6F0,
	0xE6F1,
	0xE6F2,
	0xE5B9,
	0xE6F3,
	0xE6F4,
	0xC2E2,
	0xE6F5,
	0xE6F6,
	0xD6E8,
	0xE6F7,
	INVALID_GB_INNER_CODE,
	0xE6F8,
	0xB9C7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7BB,
	0xF7BA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7BE,
	0xF7BC,
	0xBAA1,
	INVALID_GB_INNER_CODE,
	0xF7BF,
	INVALID_GB_INNER_CODE,
	0xF7C0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7C2,
	0xF7C1,
	0xF7C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7C3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7C5,
	0xF7C6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7C7,
	INVALID_GB_INNER_CODE,
	0xCBE8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7D4,
	INVALID_GB_INNER_CODE,
	0xF7D5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7D6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7D8,
	INVALID_GB_INNER_CODE,
	0xF7DA,
	INVALID_GB_INNER_CODE,
	0xF7D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7DB,
	INVALID_GB_INNER_CODE,
	0xF7D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD7D7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7DD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7DE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7DF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7E0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xDBCB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8AA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xE5F7,
	0xB9ED,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBFFD,
	0xBBEA,
	0xF7C9,
	0xC6C7,
	0xF7C8,
	INVALID_GB_INNER_CODE,
	0xF7CA,
	0xF7CC,
	0xF7CB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7CD,
	INVALID_GB_INNER_CODE,
	0xCEBA,
	INVALID_GB_INNER_CODE,
	0xF7CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4A7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3E3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6CF,
	INVALID_GB_INNER_CODE,
	0xC2B3,
	0xF6D0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6D1,
	0xF6D2,
	0xF6D3,
	0xF6D4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6D6,
	INVALID_GB_INNER_CODE,
	0xB1AB,
	0xF6D7,
	INVALID_GB_INNER_CODE,
	0xF6D8,
	0xF6D9,
	0xF6DA,
	INVALID_GB_INNER_CODE,
	0xF6DB,
	0xF6DC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6DD,
	0xF6DE,
	0xCFCA,
	INVALID_GB_INNER_CODE,
	0xF6DF,
	0xF6E0,
	0xF6E1,
	0xF6E2,
	0xF6E3,
	0xF6E4,
	0xC0F0,
	0xF6E5,
	0xF6E6,
	0xF6E7,
	0xF6E8,
	0xF6E9,
	INVALID_GB_INNER_CODE,
	0xF6EA,
	INVALID_GB_INNER_CODE,
	0xF6EB,
	0xF6EC,
	INVALID_GB_INNER_CODE,
	0xF6ED,
	0xF6EE,
	0xF6EF,
	0xF6F0,
	0xF6F1,
	0xF6F2,
	0xF6F3,
	0xF6F4,
	0xBEA8,
	INVALID_GB_INNER_CODE,
	0xF6F5,
	0xF6F6,
	0xF6F7,
	0xF6F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC8FA,
	0xF6F9,
	0xF6FA,
	0xF6FB,
	0xF6FC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6FD,
	0xF6FE,
	0xF7A1,
	0xF7A2,
	0xF7A3,
	0xF7A4,
	0xF7A5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7A6,
	0xF7A7,
	0xF7A8,
	0xB1EE,
	0xF7A9,
	0xF7AA,
	0xF7AB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7AC,
	0xF7AD,
	0xC1DB,
	0xF7AE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7AF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4F1,
	0xF0AF,
	0xBCA6,
	0xF0B0,
	0xC3F9,
	INVALID_GB_INNER_CODE,
	0xC5B8,
	0xD1BB,
	INVALID_GB_INNER_CODE,
	0xF0B1,
	0xF0B2,
	0xF0B3,
	0xF0B4,
	0xF0B5,
	0xD1BC,
	INVALID_GB_INNER_CODE,
	0xD1EC,
	INVALID_GB_INNER_CODE,
	0xF0B7,
	0xF0B6,
	0xD4A7,
	INVALID_GB_INNER_CODE,
	0xCDD2,
	0xF0B8,
	0xF0BA,
	0xF0B9,
	0xF0BB,
	0xF0BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB8EB,
	0xF0BD,
	0xBAE8,
	INVALID_GB_INNER_CODE,
	0xF0BE,
	0xF0BF,
	0xBEE9,
	0xF0C0,
	0xB6EC,
	0xF0C1,
	0xF0C2,
	0xF0C3,
	0xF0C4,
	0xC8B5,
	0xF0C5,
	0xF0C6,
	INVALID_GB_INNER_CODE,
	0xF0C7,
	0xC5F4,
	INVALID_GB_INNER_CODE,
	0xF0C8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0C9,
	INVALID_GB_INNER_CODE,
	0xF0CA,
	0xF7BD,
	INVALID_GB_INNER_CODE,
	0xF0CB,
	0xF0CC,
	0xF0CD,
	INVALID_GB_INNER_CODE,
	0xF0CE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF0CF,
	0xBAD7,
	INVALID_GB_INNER_CODE,
	0xF0D0,
	0xF0D1,
	0xF0D2,
	0xF0D3,
	0xF0D4,
	0xF0D5,
	0xF0D6,
	0xF0D8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD3A5,
	0xF0D7,
	INVALID_GB_INNER_CODE,
	0xF0D9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF5BA,
	0xC2B9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7E5,
	0xF7E6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7E7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7E8,
	0xC2B4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7EA,
	INVALID_GB_INNER_CODE,
	0xF7EB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2F3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4F0,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF4EF,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC2E9,
	INVALID_GB_INNER_CODE,
	0xF7E1,
	0xF7E2,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xBBC6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD9E4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAF2,
	0xC0E8,
	0xF0A4,
	INVALID_GB_INNER_CODE,
	0xBADA,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC7AD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC4AC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7EC,
	0xF7ED,
	0xF7EE,
	INVALID_GB_INNER_CODE,
	0xF7F0,
	0xF7EF,
	INVALID_GB_INNER_CODE,
	0xF7F1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7F4,
	INVALID_GB_INNER_CODE,
	0xF7F3,
	INVALID_GB_INNER_CODE,
	0xF7F2,
	0xF7F5,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7F6,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xEDE9,
	INVALID_GB_INNER_CODE,
	0xEDEA,
	0xEDEB,
	INVALID_GB_INNER_CODE,
	0xF6BC,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6BD,
	INVALID_GB_INNER_CODE,
	0xF6BE,
	0xB6A6,
	INVALID_GB_INNER_CODE,
	0xD8BE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9C4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xD8BB,
	INVALID_GB_INNER_CODE,
	0xDCB1,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xCAF3,
	INVALID_GB_INNER_CODE,
	0xF7F7,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7F8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7F9,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7FB,
	INVALID_GB_INNER_CODE,
	0xF7FA,
	INVALID_GB_INNER_CODE,
	0xB1C7,
	INVALID_GB_INNER_CODE,
	0xF7FC,
	0xF7FD,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF7FE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC6EB,
	0xECB4,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB3DD,
	0xF6B3,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xF6B4,
	0xC1E4,
	0xF6B5,
	0xF6B6,
	0xF6B7,
	0xF6B8,
	0xF6B9,
	0xF6BA,
	0xC8A3,
	0xF6BB,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xC1FA,
	0xB9A8,
	0xEDE8,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	INVALID_GB_INNER_CODE,
	0xB9EA,
	0xD9DF
};

U16  UniCodeToGB(const U16 unicodeIndex)
{
    if(unicodeIndex >= 0x4E00 && unicodeIndex <= 0x9fA0)
    {
        return(UniCodeToGBTable[unicodeIndex - 0x4E00]);
    }
    else
    {
        return(INVALID_GB_INNER_CODE); 
    }
}

U16 UINCODE_UCS2GB( U16 *gb_ptr, 	//destination: string pointer to UCS2 string.
						const U16 *ucs2_ptr,//source: string pointer to GB string
						U16 len			//the length to convert from GB to UCS2.
						)
{
	U16  count = 0;

	while((len > 0) && (len < 0xfff))
	{
		len-=2;
		count+=2;
		*gb_ptr++ = UniCodeToGB(*ucs2_ptr++);
		*(gb_ptr-1) = ((*(gb_ptr-1)<<8) & 0xff00)  |  ( (*(gb_ptr-1)>>8) & 0xff);
	}
}
#endif

//end

#endif /* _PHONEBOOKOPERATEMASS_C */ 
