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
 * PhoneBookHandlerJava.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for providing phonebook interface for java package
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_PHONEBOOKJAVAHANDLER_C
#define _MMI_PHONEBOOKJAVAHANDLER_C

#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "PhoneBookTypes.h"
#include "PhoneBookDef.h"
#include "PhoneBookProt.h"
#include "PhoneBookGProt.h"
#include "PhoneBookJavaHandler.h"
#include "SettingDefs.h"        /* For FDN on check */
#include "SettingsGdcl.h"
#include "Nvram_user_defs.h"
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
#include "DateTimeType.h"
#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
#include "app_datetime.h"
#endif
/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U8 g_phb_java_storage;
static U8 g_phb_java_sort;

#if defined(__MMI_PHB_EMAIL_SORT__)
extern U8 g_phb_email_sorted;
#endif 

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern U16 PhoneBookEntryCount;
extern U8 g_phb_enter_from;
extern U16 g_phb_name_index[];

extern S8 pbName[];
extern S8 pbNumber[];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
extern S8 pbHomeNumber[];
extern S8 pbOfficeNumber[];
extern S8 pbFaxNumber[];
extern S8 pbEmailAddress[];
extern S8 pbCompanyName[];
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
extern const kal_uint8 g_dt_day_per_mon[];
extern S8 pbDay[];
extern S8 pbMon[];
extern S8 pbYear[];
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
extern PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
#endif 

/* 
 * Global Function
 */
extern void mmi_phb_callergroup_copy_group_info(U8 group_index, U8* group_name);


#define MMI_PHB_JAVA_HANDLER
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_handler_init
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_handler_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_phb_java_write_req, MSG_ID_MMI_PHB_JAVA_SET_ENTRY_REQ);
    SetProtocolEventHandler(mmi_phb_java_read_req, MSG_ID_MMI_PHB_JAVA_GET_ENTRY_REQ);
    SetProtocolEventHandler(mmi_phb_java_search_req, MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_REQ);
    SetProtocolEventHandler(mmi_phb_java_get_group_info_req, MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_REQ);
    SetProtocolEventHandler(mmi_phb_java_set_group_info_req, MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_REQ);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_write_req
 * DESCRIPTION
 *  This function write a phonebook entry from JAVA request
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_write_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_entry_req_struct *LocalPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LocalPtr = (mmi_phb_handler_set_entry_req_struct*) info;

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_java_write_rsp(MMI_PHB_JAVA_NOT_READY, 0xffff);
        return;
    }
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_java_write_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }
#endif /* __MMI_PHB_USIM_FIELD__ */
#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_java_write_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */

    g_phb_java_storage = LocalPtr->storage;
    //g_phb_java_sort = LocalPtr->sort_type;

    /* [Add or Update] operation. (Not Delete) */
    if (LocalPtr->entry_ptr)
    {
        /*  Check if name and number are both empty and all numbers are valid. */
        if ((!mmi_ucs2strlen(LocalPtr->entry_ptr->name) && !mmi_phb_calculate_number_valid_length(LocalPtr->entry_ptr->number)) ||
            !mmi_phb_op_check_valid_number(LocalPtr->entry_ptr->number) ||
            !mmi_phb_op_check_valid_number(LocalPtr->entry_ptr->homeNumber) ||
            !mmi_phb_op_check_valid_number(LocalPtr->entry_ptr->officeNumber) ||
            !mmi_phb_op_check_valid_number(LocalPtr->entry_ptr->faxNumber))
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_ERROR, 0xffff);
            return;
        }
    }

    /* [Add] operation. */
    if (LocalPtr->index == 0xffff)
    {
        /* Support Email sorting */
//        if (g_phb_java_sort == MMI_PHB_BY_EMAIL)
//        {
//        #if defined(__MMI_PHB_EMAIL_SORT__)
//            #ifndef __MMI_PHB_USIM_FIELD__
//            if (g_phb_java_storage != MMI_NVRAM)
//            {
//                mmi_phb_java_write_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0xffff);
//                return;
//            }
//            #endif /* ~__MMI_PHB_USIM_FIELD__ */
            /* Email sorting not populated after bootup. */
//            if (g_phb_email_sorted == 0)
//           {
//                mmi_phb_java_util_rebuild_email_sorting();
//                g_phb_email_sorted = 1;
//            }
//        #else /* defined(__MMI_PHB_EMAIL_SORT__) */
//            mmi_phb_java_write_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0xffff);
//            return;
//        #endif /* defined(__MMI_PHB_EMAIL_SORT__) */
//        }

        /* Check free space and assign storage location */
        if (!mmi_bootup_is_sim_valid())
        {
            if (LocalPtr->storage == MMI_SIM)
            {
                mmi_phb_java_write_rsp(MMI_PHB_JAVA_NO_SIM_CARD, 0xffff);
                return;
            }	
            else if (g_phb_cntx.phone_used < g_phb_cntx.phone_total)
            {
                g_phb_cntx.selected_storage = MMI_NVRAM;	
            }	
            else
            {
                mmi_phb_java_write_rsp(MMI_PHB_JAVA_STORAGE_FULL, 0xffff);
                return;
            }	
        }
        else
        {
            if ((LocalPtr->storage == MMI_STORAGE_BOTH) && (PhoneBookEntryCount < (g_phb_cntx.sim_total + g_phb_cntx.phone_total)))
            {
                if (g_phb_cntx.prefer_storage == MMI_NVRAM)
                {
                    if (g_phb_cntx.phone_used < g_phb_cntx.phone_total)
                    {
                        g_phb_cntx.selected_storage = MMI_NVRAM;
                    }
                    else if(g_phb_cntx.sim_used < g_phb_cntx.sim_total)
                    {
                        g_phb_cntx.selected_storage = MMI_SIM;
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
                else if (g_phb_cntx.prefer_storage == MMI_SIM)
                {
                    if (g_phb_cntx.sim_used < g_phb_cntx.sim_total)
                    {
                        g_phb_cntx.selected_storage = MMI_SIM;
                    }
                    else if (g_phb_cntx.phone_used < g_phb_cntx.phone_total)
                    {
                        g_phb_cntx.selected_storage = MMI_NVRAM;
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
                else
                {
                    ASSERT(0);
                }
            }
            else if (((LocalPtr->storage == MMI_SIM) && (g_phb_cntx.sim_used < g_phb_cntx.sim_total)) ||
                     ((LocalPtr->storage == MMI_NVRAM) && (g_phb_cntx.phone_used < g_phb_cntx.phone_total)))
            {
                g_phb_cntx.selected_storage = LocalPtr->storage;
            }
            else
            {
                mmi_phb_java_write_rsp(MMI_PHB_JAVA_STORAGE_FULL, 0xffff);
                return;
            }	
        }
        /*
         * Prepare data for name and number field
         */
        mmi_phb_util_clear_buffer(TRUE);
 
        if (LocalPtr->entry_ptr->name)
        {
            mmi_ucs2ncpy(pbName, LocalPtr->entry_ptr->name, MAX_PB_NAME_LENGTH);        	
            mmi_phb_truncate_pbname_buffer(MMI_NVRAM);
        }

        memcpy(pbNumber, LocalPtr->entry_ptr->number, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);

        /*
         * Prepare data for optional fields
         */
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)         
        memcpy(pbHomeNumber, LocalPtr->entry_ptr->homeNumber, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
        memcpy(pbOfficeNumber, LocalPtr->entry_ptr->officeNumber, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
        memcpy(pbFaxNumber, LocalPtr->entry_ptr->faxNumber, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
        memcpy(pbEmailAddress, LocalPtr->entry_ptr->emailAddress, (MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH);
        memcpy(pbCompanyName, LocalPtr->entry_ptr->companyName, (MAX_PB_COMPANY_LENGTH + 1) * ENCODING_LENGTH);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */        
        /*
         * Prepare data for birthday
         */
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
        if (mmi_phb_java_check_bday_is_valid(&(LocalPtr->entry_ptr->bDay)) == 0)
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_BIRTHDAY_ERROR, 0xffff);
            return;
        }
		mmi_phb_bday_set_changed();
        mmi_phb_java_set_bday(&(LocalPtr->entry_ptr->bDay), pbYear, pbMon, pbDay);
#endif /* def __MMI_PHB_BIRTHDAY_FIELD__ */
        /*
         * prepare data for optional id
         */
        g_phb_cntx.selected_pic_index = 0;
        g_phb_cntx.selected_ring_index = 0;
        if (g_phb_cntx.selected_storage == MMI_NVRAM && LocalPtr->entry_ptr->group_id <= MAX_PB_CALLER_GROUPS)
        {
            g_phb_cntx.selected_grp_index = LocalPtr->entry_ptr->group_id;
        }
#ifdef __MMI_PHB_USIM_FIELD__
        else if (g_phb_cntx.selected_storage == MMI_SIM && g_phb_cntx.is_usim &&
            LocalPtr->entry_ptr->group_id > MAX_PB_CALLER_GROUPS &&
            LocalPtr->entry_ptr->group_id <= (MAX_PB_CALLER_GROUPS + g_phb_cntx.gas_total))
        {
            g_phb_cntx.selected_grp_index = LocalPtr->entry_ptr->group_id - MAX_PB_CALLER_GROUPS;
        }
#endif /* __MMI_PHB_USIM_FIELD__ */
        else
        {
            g_phb_cntx.selected_grp_index = 0;
        }
        g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;

        g_phb_enter_from = MMI_PHB_ENTER_FROM_JAVA;
    #ifdef __MMI_PHB_USIM_FIELD__
        if (g_phb_cntx.is_usim && g_phb_cntx.selected_storage == MMI_SIM)
        {
            mmi_phb_op_add_usim_entry_req();
        }
        /* Email sorting not populated after bootup. */
        else
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
        {
            mmi_phb_op_add_entry_req();
        }
    }
    else
    {
        U16 pos;
        g_phb_cntx.java_store_index = 0xffff;
        for (pos = 0; pos < PhoneBookEntryCount; pos++)
        {
            if (g_phb_name_index[pos] == LocalPtr->index)
            {
                g_phb_cntx.java_store_index = LocalPtr->index;
                break;
            }
        }
        if (g_phb_cntx.java_store_index == 0xffff)
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_OUT_OF_INDEX, 0xffff);
            return;
        }
        g_phb_enter_from = MMI_PHB_ENTER_FROM_JAVA;
        
        /* [Delete] operation. */
        if (LocalPtr->entry_ptr == NULL)
        {
            mmi_phb_op_delete_entry_req();
        }
        /* [Update] operation. */
        else
        {
            /* Prepare data for name and number field */
            mmi_phb_util_clear_buffer(TRUE);
            if (LocalPtr->entry_ptr->name)
            {
                mmi_ucs2ncpy(pbName, LocalPtr->entry_ptr->name, MAX_PB_NAME_LENGTH);        	
                mmi_phb_truncate_pbname_buffer(MMI_NVRAM);
            }
            memcpy(pbNumber, LocalPtr->entry_ptr->number, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);

            /* Prepare data for optional fields */
        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)            
            memcpy(pbHomeNumber, LocalPtr->entry_ptr->homeNumber, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
            memcpy(pbOfficeNumber, LocalPtr->entry_ptr->officeNumber, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
            memcpy(pbFaxNumber, LocalPtr->entry_ptr->faxNumber, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
            memcpy(pbEmailAddress, LocalPtr->entry_ptr->emailAddress, (MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH);
            memcpy(pbCompanyName, LocalPtr->entry_ptr->companyName, (MAX_PB_COMPANY_LENGTH + 1) * ENCODING_LENGTH);
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */
        #ifdef __MMI_PHB_BIRTHDAY_FIELD__
            if (mmi_phb_java_check_bday_is_valid(&(LocalPtr->entry_ptr->bDay)) == 0)
            {
                mmi_phb_java_write_rsp(MMI_PHB_JAVA_BIRTHDAY_ERROR, 0xffff);
                return;
            }
			mmi_phb_bday_set_changed();
            mmi_phb_java_set_bday(&(LocalPtr->entry_ptr->bDay), pbYear, pbMon, pbDay);
        #endif /* def __MMI_PHB_BIRTHDAY_FIELD__ */

            if (LocalPtr->index < MAX_PB_PHONE_ENTRIES && LocalPtr->entry_ptr->group_id <= MAX_PB_CALLER_GROUPS)
            {
                g_phb_cntx.selected_grp_index = LocalPtr->entry_ptr->group_id;
            }
        #ifdef __MMI_PHB_USIM_FIELD__
            else if (LocalPtr->index >= MAX_PB_PHONE_ENTRIES && g_phb_cntx.is_usim &&
                LocalPtr->entry_ptr->group_id > MAX_PB_CALLER_GROUPS &&
                LocalPtr->entry_ptr->group_id <= (MAX_PB_CALLER_GROUPS + g_phb_cntx.gas_total))
            {
                g_phb_cntx.selected_grp_index = LocalPtr->entry_ptr->group_id - MAX_PB_CALLER_GROUPS;
            }
        #endif /* __MMI_PHB_USIM_FIELD__ */
            else
            {
                g_phb_cntx.selected_grp_index = 0;
            }

        #ifdef __MMI_PHB_USIM_FIELD__
            if (g_phb_cntx.is_usim && LocalPtr->index >= MAX_PB_PHONE_ENTRIES)
            {
                mmi_phb_op_edit_usim_entry_req();
            }
            /* Email sorting not populated after bootup. */
            else
        #endif /* __MMI_PHB_USIM_FIELD__ */
            {
                /* prepare data for optional id */
                //g_phb_cntx.selected_pic_index = 0;
                //g_phb_cntx.selected_ring_index = 0;
                //g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
                mmi_phb_op_edit_entry_req();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_write_rsp
 * DESCRIPTION
 *  This function return write result to JAVA
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_write_rsp(U16 result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_entry_rsp_struct *MsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MsgPtr = (mmi_phb_handler_set_entry_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_set_entry_rsp_struct));
//    MsgPtr->index = 0xffff;

    /* Decide error cause */
    if ((MsgPtr->result = result) == MMI_PHB_JAVA_SUCCESS)
    {
//        MsgPtr->index = mmi_phb_java_util_get_index_by_store_index(g_phb_java_sort, g_phb_java_storage, store_index);
        MsgPtr->store_index = store_index; /* >= MAX_PB_PHONE_ENTRIES is SIM entry */
    }
    else if ((MsgPtr->result = result) == MMI_PHB_JAVA_NOT_SUPPORT)
    {
        /* Do nothing */ ;
    }
    else if ((MsgPtr->result = result) == MMI_PHB_JAVA_STORAGE_FULL)
    {
        /* Do nothing */ ;
    }
    else if ((MsgPtr->result = result) == MMI_PHB_JAVA_NOT_READY)
    {
        /* Do nothing */ ;
    }
    else if (result == MMI_SIM_EF_RECORD_FULL)
    {
        MsgPtr->result = MMI_PHB_JAVA_NUMBER_TOO_LONG;
    }
    else if (gSecuritySetupContext.FdlStatus)
    {
        MsgPtr->result = MMI_PHB_JAVA_FDN_ON;
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (result == MMI_PHB_USIM_EMAIL_FULL)
    {
        MsgPtr->result = MMI_PHB_JAVA_EMAIL_FULL;
    }
    else if (result == MMI_PHB_USIM_ANR_FULL)
    {
        MsgPtr->result = MMI_PHB_JAVA_ANR_FULL;
    }
#endif /* __MMI_PHB_USIM_FIELD__ */
    else
    {
        MsgPtr->result = MMI_PHB_JAVA_ERROR;
    }

    g_phb_enter_from = MMI_PHB_ENTER_NONE;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_JASYN;
    Message.oslMsgId = MSG_ID_MMI_PHB_JAVA_SET_ENTRY_RSP;
    Message.oslDataPtr = (oslParaType*) MsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_read_req
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_read_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos;
    U16 count = 0;
    U16 store_index = 0;
    mmi_phb_handler_get_entry_req_struct *LocalPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LocalPtr = (mmi_phb_handler_get_entry_req_struct*) info;

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_java_read_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }
#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_java_read_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */
    /*
     * Get entry data
     */
    if ((LocalPtr->count > 0) && (LocalPtr->entry_ptr != NULL))
    {
        /*
         *  Check valid index first.
         */
        if (((LocalPtr->storage == MMI_STORAGE_BOTH) && (LocalPtr->index > PhoneBookEntryCount)) ||
            ((LocalPtr->storage == MMI_NVRAM) && (LocalPtr->index > g_phb_cntx.phone_used)) ||
            ((LocalPtr->storage == MMI_SIM) && (LocalPtr->index > g_phb_cntx.sim_used)))
        {
            mmi_phb_java_read_rsp(MMI_PHB_JAVA_OUT_OF_INDEX, 0);
            return;
        }

        /* Sort By NAME */
        if (LocalPtr->sort_type == MMI_PHB_BY_NAME)
        {
            /* Find index position */
            for (pos = 0; pos < PhoneBookEntryCount; pos++)
            {
                store_index = g_phb_name_index[pos];

                if ((LocalPtr->storage == MMI_STORAGE_BOTH) ||
                    (LocalPtr->storage == MMI_NVRAM && store_index < MAX_PB_PHONE_ENTRIES) ||
                    (LocalPtr->storage == MMI_SIM && store_index >= MAX_PB_PHONE_ENTRIES))
                {
                    count++;
                }

                if (count == LocalPtr->index)
                {
                    break;
                }
            }
            /* Copy entry by assigned count number */
            count = 0;
            LocalPtr->entry_ptr[count].sort_index = LocalPtr->index;
            mmi_phb_java_util_copy_entry_from_phb(store_index, &LocalPtr->entry_ptr[count++]);

            while ((++pos < PhoneBookEntryCount) && (count < LocalPtr->count))
            {
                store_index = g_phb_name_index[pos];

                if ((LocalPtr->storage == MMI_STORAGE_BOTH) ||
                    (LocalPtr->storage == MMI_NVRAM && store_index < MAX_PB_PHONE_ENTRIES) ||
                    (LocalPtr->storage == MMI_SIM && store_index >= MAX_PB_PHONE_ENTRIES))
                {
                    LocalPtr->entry_ptr[count].sort_index = LocalPtr->index+count;
                    mmi_phb_java_util_copy_entry_from_phb(store_index, &LocalPtr->entry_ptr[count++]);
                }
            }

            mmi_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }
        /* Support Email sorting */
    #if defined(__MMI_PHB_EMAIL_SORT__)
    #ifdef __MMI_PHB_USIM_FIELD__
        if (LocalPtr->sort_type == MMI_PHB_BY_EMAIL)
    #else 
        if ((LocalPtr->sort_type == MMI_PHB_BY_EMAIL) && (LocalPtr->storage == MMI_NVRAM))
    #endif 
        {
            S16 pError;

        #ifdef __MMI_PHB_USIM_FIELD__
            U16 g_phb_email_index[MAX_PB_ENTRIES];
        #else 
            U16 g_phb_email_index[MAX_PB_PHONE_ENTRIES];
        #endif 

            /* Email sorting not populated after bootup. */
            if (g_phb_email_sorted == 0)
            {
                mmi_phb_java_util_rebuild_email_sorting();
                g_phb_email_sorted = 1;
            }

        #ifdef __MMI_PHB_USIM_FIELD__
            ReadRecord(
                NVRAM_EF_PHB_EMAIL_SORT_LID,
                1,
                (void*)g_phb_email_index,
                MAX_PB_ENTRIES * sizeof(U16),
                &pError);
        #else /* __MMI_PHB_USIM_FIELD__ */ 
            ReadRecord(
                NVRAM_EF_PHB_EMAIL_SORT_LID,
                1,
                (void*)g_phb_email_index,
                MAX_PB_PHONE_ENTRIES * sizeof(U16),
                &pError);
        #endif /* __MMI_PHB_USIM_FIELD__ */ 

            /* Find first index position */
            pos = LocalPtr->index - 1;

            /* Copy entry by assigned count number */
            store_index = g_phb_email_index[pos];
            LocalPtr->entry_ptr[count].sort_index = LocalPtr->index;
            mmi_phb_java_util_copy_entry_from_phb(store_index, &LocalPtr->entry_ptr[count++]);

        #ifdef __MMI_PHB_USIM_FIELD__
            while ((++pos < PhoneBookEntryCount) && (count < LocalPtr->count))
        #else 
            while ((++pos < g_phb_cntx.phone_used) && (count < LocalPtr->count))
        #endif 
            {
                store_index = g_phb_email_index[pos];

            #ifndef __MMI_PHB_USIM_FIELD__
                if (store_index < MAX_PB_PHONE_ENTRIES) /* In NVRAM */
            #endif 
                {
                    LocalPtr->entry_ptr[count].sort_index = LocalPtr->index+count;
                    mmi_phb_java_util_copy_entry_from_phb(store_index, &LocalPtr->entry_ptr[count++]);
                }
            }

            mmi_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
    }
    /*
     * Get total count by storage, no need to return data.
     */
    else if (LocalPtr->count == 0)
    {
        if (LocalPtr->storage == MMI_STORAGE_BOTH)
        {
            mmi_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, PhoneBookEntryCount);
            return;
        }
        else if (LocalPtr->storage == MMI_NVRAM)
        {
            mmi_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, g_phb_cntx.phone_used);
            return;
        }
        else if (LocalPtr->storage == MMI_SIM)
        {
            mmi_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, g_phb_cntx.sim_used);
            return;
        }
    }

    /* Error */
    mmi_phb_java_read_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_read_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result      [IN]        
 *  count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_read_rsp(U16 result, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_get_entry_rsp_struct *MsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MsgPtr = (mmi_phb_handler_get_entry_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_get_entry_rsp_struct));

    MsgPtr->result = result;
    MsgPtr->count = count;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_JASYN;
    Message.oslMsgId = MSG_ID_MMI_PHB_JAVA_GET_ENTRY_RSP;
    Message.oslDataPtr = (oslParaType*) MsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_req
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  info        [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_search_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U16 index;
    S32 distance;
    U8 same_count;
    mmi_phb_handler_search_entry_req_struct *LocalPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LocalPtr = (mmi_phb_handler_search_entry_req_struct*) info;

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_READY, 0xffff);
        return;
    }
#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_READY, 0xffff);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */
    g_phb_java_sort = LocalPtr->sort_type;
    g_phb_java_storage = LocalPtr->storage;

    /* Check if search pattern empty */
    if (mmi_ucs2strlen((S8*) LocalPtr->pattern) == 0)
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
        return;
    }

    /* Search by name */
    if (LocalPtr->search_type == MMI_PHB_BY_NAME)
    {
        /* Find the closest entry */
        index = mmi_phb_search_name_binary_search(0, (PhoneBookEntryCount - 1), LocalPtr->pattern);

        if ((index + LocalPtr->start_index) >=  PhoneBookEntryCount)
        {
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
            return;
        }
        store_index = g_phb_name_index[index + LocalPtr->start_index];

        /* Check if the closest entry prefix match the pattern */
        mmi_phb_compare_ucs2_strings(
            LocalPtr->pattern,
            (S8*) PhoneBook[store_index].alpha_id.name,
            &same_count,
            &distance);

        if (mmi_ucs2strlen(LocalPtr->pattern) == same_count)
        {
            LocalPtr->entry_ptr->sort_index = index;
            /* store_index will be set in mmi_phb_java_util_copy_entry_from_phb */
            mmi_phb_java_util_copy_entry_from_phb(store_index, LocalPtr->entry_ptr);
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_SUCCESS, store_index);
        }
        else
        {
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
        }
    }
    /* Search by email */
#if defined(__MMI_PHB_EMAIL_SORT__)
    else if (LocalPtr->search_type == MMI_PHB_BY_EMAIL)
    {
    #ifdef __MMI_PHB_USIM_FIELD__
        U16 g_phb_email_index[MAX_PB_ENTRIES];
    #else 
        U16 g_phb_email_index[MAX_PB_PHONE_ENTRIES];
    #endif 
        S16 pError;

        /* Email sorting not populated after bootup. */
        if (g_phb_email_sorted == 0)
        {
            mmi_phb_java_util_rebuild_email_sorting();
            g_phb_email_sorted = 1;
        }

    #ifdef __MMI_PHB_USIM_FIELD__
        ReadRecord(
            NVRAM_EF_PHB_EMAIL_SORT_LID,
            1,
            (void*)g_phb_email_index,
            MAX_PB_ENTRIES * sizeof(U16),
            &pError);

        /* Find the closest entry */
        store_index = mmi_phb_search_email_binary_search(0, (PhoneBookEntryCount - 1), LocalPtr->pattern);
        if ((store_index + LocalPtr->start_index) >=  PhoneBookEntryCount)
        {
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
            return;
        }
        store_index = g_phb_name_index[store_index + LocalPtr->start_index];
        /* Check if the closest entry prefix match the pattern */
        if (store_index >= MAX_PB_PHONE_ENTRIES)
        {
            mmi_asc_to_ucs2((S8*) pbEmailAddress, (S8*) phb_email[first - MAX_PB_PHONE_ENTRIES].email_address);
        }
        else
    #else /* __MMI_PHB_USIM_FIELD__ */ 
        ReadRecord(
            NVRAM_EF_PHB_EMAIL_SORT_LID,
            1,
            (void*)g_phb_email_index,
            MAX_PB_PHONE_ENTRIES * sizeof(U16),
            &pError);

        /* Find the closest entry */
        store_index = mmi_phb_search_email_binary_search(0, (g_phb_cntx.phone_used - 1), LocalPtr->pattern);
        if ((store_index + LocalPtr->start_index) >=  g_phb_cntx.phone_used)
        {
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
            return;
        }
        store_index = g_phb_name_index[store_index + LocalPtr->start_index];
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
        {
            ReadRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (store_index + 1),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);
            mmi_asc_to_ucs2(pbEmailAddress, (PS8) PhoneBookOptionalFields.emailAddress);
        }
        /* Check if the closest entry prefix match the pattern */
        mmi_phb_compare_ucs2_strings(LocalPtr->pattern, pbEmailAddress, &same_count, &distance);

        if (mmi_ucs2strlen(LocalPtr->pattern) == same_count || distance == 0)
        {
            mmi_phb_java_util_copy_entry_from_phb(store_index, LocalPtr->entry_ptr);
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_SUCCESS, store_index);
        }
        else
        {
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
        }
    }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
    /* Search by number */
    else if (LocalPtr->search_type == MMI_PHB_BY_NUMBER)
    {
        U32 num;
        U8 number_ASCII[MAX_PB_NUMBER_LENGTH + 1 + 1];

        /* Number not sorted yet */
        if (g_phb_cntx.populate_count != 0xffff)
        {
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_READY, 0xffff);
            return;
        }
        if (LocalPtr->sort_type != MMI_PHB_BY_NAME
        #ifdef __MMI_PHB_EMAIL_SORT__
            && LocalPtr->sort_type != MMI_PHB_BY_EMAIL
        #endif
            )
        {
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0);
            return;
        }
        memset(number_ASCII, 0, ENCODING_LENGTH);
        mmi_ucs2_to_asc((S8*) number_ASCII, LocalPtr->pattern);

        num = mmi_phb_util_convert_number_to_int(number_ASCII);
        if (num < INVALID_NUMBER)
        {
            store_index = mmi_phb_lookup_table_search(num, 0, (U16)(g_phb_cntx.lookup_table_count - 1), 
                (S8*) number_ASCII, g_phb_java_storage);

            if (store_index < 0xffff)   /* storage location in array, begin from 0. */
            {
                mmi_phb_java_util_copy_entry_from_phb(store_index, LocalPtr->entry_ptr);
                //sort_index will be set in search rsp
                mmi_phb_java_search_rsp(MMI_PHB_JAVA_SUCCESS, store_index);
            }
            else
            {
                mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
            }
        }
        else
        {
            mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
        }
    }
    else
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0xffff);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_search_rsp(U16 result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_search_entry_rsp_struct *MsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MsgPtr =
        (mmi_phb_handler_search_entry_rsp_struct*)
        OslConstructDataPtr(sizeof(mmi_phb_handler_search_entry_rsp_struct));

    /* Decide error cause */
    MsgPtr->result = result;
    MsgPtr->index = store_index;

    if (result == MMI_PHB_JAVA_SUCCESS)
    {
        MsgPtr->index = mmi_phb_java_util_get_index_by_store_index(g_phb_java_sort, g_phb_java_storage, store_index);
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_JASYN;
    Message.oslMsgId = MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_RSP;
    Message.oslDataPtr = (oslParaType*) MsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_get_group_info_req
 * DESCRIPTION
 *  This function gets group information.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_get_group_info_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    mmi_phb_handler_get_group_info_req_struct *LocalPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LocalPtr = (mmi_phb_handler_get_group_info_req_struct*) info;

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }
#endif /* __MMI_PHB_USIM_FIELD__ */

    /* Get entry data */
    if(LocalPtr->storage == MMI_STORAGE_BOTH)
    {
        if (LocalPtr->group_ptr == NULL)
        {
        #ifdef __MMI_PHB_USIM_FIELD__
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, (U8)(MAX_PB_CALLER_GROUPS + g_phb_cntx.gas_total));
        #else
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, MAX_PB_CALLER_GROUPS);
        #endif
            return;
        }
        if ((LocalPtr->max_group > 0) && (LocalPtr->group_ptr != NULL))
        {
            /* Copy group information by assigned count number */

            for (count = 0; count < LocalPtr->max_group;count++)
            {
                if (count < (MAX_PB_CALLER_GROUPS )) /* max group no in phone */
                {
                    mmi_phb_callergroup_copy_group_info(count, LocalPtr->group_ptr[count].group_name);
                    LocalPtr->group_ptr[count].group_id = count;
                }
            #ifdef __MMI_PHB_USIM_FIELD__
                else if (g_phb_cntx.is_usim && count < (MAX_PB_CALLER_GROUPS + g_phb_cntx.gas_total))
                {
                    mmi_phb_op_edit_usim_entry_req();
                }
                /* Email sorting not populated after bootup. */
            #endif /* __MMI_PHB_USIM_FIELD__ */
                else
                {
                    mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, count);
                    return;
                }
            }
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }
        /* Error */
        mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_ERROR, 0);
    }
    else if (LocalPtr->storage == MMI_NVRAM)
    {
        if (LocalPtr->group_ptr == NULL)
        {
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, MAX_PB_CALLER_GROUPS);
            return;
        }
        if ((LocalPtr->max_group > 0) && (LocalPtr->group_ptr != NULL))
        {
            /* Copy group information by assigned count number */

            for (count = 0; count < LocalPtr->max_group;count++)
            {
                if (count < (MAX_PB_CALLER_GROUPS )) /* max group no in phone */
                {
                    mmi_phb_callergroup_copy_group_info(count, LocalPtr->group_ptr[count].group_name);
                    LocalPtr->group_ptr[count].group_id = count;
                }
                else
                {
                    mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, count);
                    return;
                }
            }
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }
        /* Error */
        mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_ERROR, 0);
    }
    else if (LocalPtr->storage == MMI_SIM)
    {
    #ifdef __MMI_PHB_USIM_FIELD__
        if (LocalPtr->group_ptr == NULL)
        {
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, g_phb_cntx.gas_total);
            return;
        }
    #else /* __MMI_PHB_USIM_FIELD__ */
        if (LocalPtr->group_ptr == NULL)
        {
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, 0);
            return;
        }
        else
        {
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_ERROR, 0);
            return;
        }
    #endif /* __MMI_PHB_USIM_FIELD__ */
    }
    else
    {
        mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_ERROR, 0);
        return;
    }
}


/*****************************************************************************
* FUNCTION
 *  mmi_phb_java_get_group_info_rsp
* DESCRIPTION
*   This function initializes phonebook handler app.
* PARAMETERS
 *  result      [IN]        
 *  count       [IN]        
 * RETURNS
*  void
 *****************************************************************************/
void mmi_phb_java_get_group_info_rsp(U16 result, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_get_group_info_rsp_struct *MsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MsgPtr = (mmi_phb_handler_get_group_info_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_get_group_info_rsp_struct));

    MsgPtr->result = result;
    MsgPtr->count = count;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_JASYN;
    Message.oslMsgId = MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_RSP;
    Message.oslDataPtr = (oslParaType*) MsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_set_group_info_req
 * DESCRIPTION
 *  This function write a group name from JAVA request
 * PARAMETERS
 *  info        [IN]     
* RETURNS
*  void
*****************************************************************************/
void mmi_phb_java_set_group_info_req(void *info)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
    mmi_phb_handler_set_group_info_req_struct *LocalPtr;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    LocalPtr = (mmi_phb_handler_set_group_info_req_struct*) info;

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_NOT_READY);
        return;
    }
#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_NOT_READY);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY && 
        LocalPtr->group_id > MAX_PB_CALLER_GROUPS)
   {
        mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_NOT_READY);
        return;
    }
    if (LocalPtr->group_id > (MAX_PB_CALLER_GROUPS + g_phb_cntx.gas_total))
#else
    if (LocalPtr->group_id > MAX_PB_CALLER_GROUPS )
#endif /* __MMI_PHB_USIM_FIELD__ */
    {
        mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_OUT_OF_INDEX);
        return;
    }


    /* Update group name operation. */
    if (LocalPtr->group_ptr != NULL)
    {
    #ifdef __MMI_PHB_USIM_FIELD__
        if (g_phb_cntx.is_usim && LocalPtr->group_id > MAX_PB_CALLER_GROUPS)
        {
            if (!mmi_phb_gas_is_duplicated(LocalPtr->group_id - MAX_PB_CALLER_GROUPS - 1, LocalPtr->group_ptr->group_name))
            {
                g_phb_cntx.java_store_index = LocalPtr->group_id - MAX_PB_CALLER_GROUPS - 1;
                g_phb_enter_from = MMI_PHB_ENTER_FROM_JAVA;
                /* Prepare data for group name field */
                memcpy(pbName, LocalPtr->group_ptr->group_name, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
                memset(pbNumber, 0, ENCODING_LENGTH);
                mmi_phb_gas_save_req();
            }
        }
        else
    #endif /* __MMI_PHB_USIM_FIELD__ */
        {
            if (!mmi_phb_callergroup_name_is_duplicated((U16)(LocalPtr->group_id - 1), (S8*)(LocalPtr->group_ptr->group_name)))
            {
                S16 pError;
                PHB_CALLER_GROUP_STRUCT* callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;

                callerGroups[LocalPtr->group_id - 1].is_modified = 1;
                mmi_ucs2ncpy(
                    (PS8)callerGroups[LocalPtr->group_id - 1].groupName,
                    (PS8)LocalPtr->group_ptr->group_name,
                    MAX_GRP_NAME_LENGTH);
                WriteRecord(NVRAM_EF_PHB_CALLER_GROUPS_LID, 1, callerGroups, CALLER_GROUPS_RECORD_SIZE, &pError);
                mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_SUCCESS);
                return;
            }
        }
    }
    mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_set_group_info_rsp
 * DESCRIPTION
 *  This function return set group info result to JAVA
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_set_group_info_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_group_info_rsp_struct *MsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MsgPtr = (mmi_phb_handler_set_group_info_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_set_group_info_rsp_struct));

    MsgPtr->result = result;
    g_phb_enter_from = MMI_PHB_ENTER_NONE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_JASYN;
    Message.oslMsgId = MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_RSP;
    Message.oslDataPtr = (oslParaType*) MsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


#define MMI_PHB_JAVA_HANDLER_UTILITIES
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_util_get_index_by_store_index
 * DESCRIPTION
 *  This function reture sort index by store index.
 * PARAMETERS
 *  sort_type           [IN]        
 *  storage             [IN]        
 *  in_store_index      [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_java_util_get_index_by_store_index(U8 sort_type, U8 storage, U16 in_store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 count = 0;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Sort By Name
     */
    if (sort_type == MMI_PHB_BY_NAME)
    {
        for (i = 0; i < PhoneBookEntryCount; i++)
        {
            store_index = g_phb_name_index[i];

            if ((storage == MMI_STORAGE_BOTH) ||
                ((storage == MMI_NVRAM) && (store_index < MAX_PB_PHONE_ENTRIES)) ||
                ((storage == MMI_SIM) && (store_index >= MAX_PB_PHONE_ENTRIES)))
            {
                count++;
            }

            if (store_index == in_store_index)
            {
                return count;
            }
        }
    }
    /*
     * Sort By Email, Only for storage in NVRAM only.
     */
#if defined(__MMI_PHB_EMAIL_SORT__)
    else if (sort_type == MMI_PHB_BY_EMAIL)
    {
        S16 pError;

    #ifdef __MMI_PHB_USIM_FIELD__
        U16 g_phb_email_index[MAX_PB_ENTRIES];

        ReadRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_ENTRIES * sizeof(U16), &pError);

        for (i = 0; i < PhoneBookEntryCount; i++)
    #else /* __MMI_PHB_USIM_FIELD__ */ 
        U16 g_phb_email_index[MAX_PB_PHONE_ENTRIES];

        if (storage != MMI_NVRAM)
        {
            return 0xffff;
        }

        ReadRecord(
            NVRAM_EF_PHB_EMAIL_SORT_LID,
            1,
            (void*)g_phb_email_index,
            MAX_PB_PHONE_ENTRIES * sizeof(U16),
            &pError);

        for (i = 0; i < g_phb_cntx.phone_used; i++)
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
        {
            store_index = g_phb_email_index[i];

            count++;

            if (store_index == in_store_index)
            {
                return count;
            }
        }
    }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
    return 0xffff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_util_get_store_index_by_sort_index
 * DESCRIPTION
 *  This function reture store index by sort index.
 * PARAMETERS
 *  sort_type           [IN]        
 *  storage             [IN]        
 *  in_sort_index       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_java_util_get_store_index_by_sort_index(U8 sort_type, U8 storage, U16 in_sort_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U16 store_index;
    U16 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Sort By NAME */
    if (sort_type == MMI_PHB_BY_NAME)
    {
        /* Find index position */
        for (pos = 0; pos < PhoneBookEntryCount; pos++)
        {
            store_index = g_phb_name_index[pos];

            if ((storage == MMI_STORAGE_BOTH) ||
                (storage == MMI_NVRAM && store_index < MAX_PB_PHONE_ENTRIES) ||
                (storage == MMI_SIM && store_index >= MAX_PB_PHONE_ENTRIES))
            {
                count++;
            }

            if (count == in_sort_index)
            {
                return store_index;
            }
        }
    }
    /* Support Email sorting */
#if defined(__MMI_PHB_EMAIL_SORT__)
#ifdef __MMI_PHB_USIM_FIELD__
    else if (LocalPtr->sort_type == MMI_PHB_BY_EMAIL)
#else 
    else if ((LocalPtr->sort_type == MMI_PHB_BY_EMAIL) && (LocalPtr->storage == MMI_NVRAM))
#endif 
    {
        S16 pError;

    #ifdef __MMI_PHB_USIM_FIELD__
        U16 g_phb_email_index[MAX_PB_ENTRIES];
    #else 
        U16 g_phb_email_index[MAX_PB_PHONE_ENTRIES];
    #endif 

        /* Email sorting not populated after bootup. */
        if (g_phb_email_sorted == 0)
        {
            mmi_phb_java_util_rebuild_email_sorting();
            g_phb_email_sorted = 1;
        }

    #ifdef __MMI_PHB_USIM_FIELD__
        ReadRecord(
            NVRAM_EF_PHB_EMAIL_SORT_LID,
            1,
            (void*)g_phb_email_index,
            MAX_PB_ENTRIES * sizeof(U16),
            &pError);
    #else /* __MMI_PHB_USIM_FIELD__ */ 
        ReadRecord(
            NVRAM_EF_PHB_EMAIL_SORT_LID,
            1,
            (void*)g_phb_email_index,
            MAX_PB_PHONE_ENTRIES * sizeof(U16),
            &pError);
    #endif /* __MMI_PHB_USIM_FIELD__ */ 

        /* Find first index position */
        pos = in_sort_index - 1;
        return g_phb_email_index[pos];
    }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
    return 0xffff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_util_copy_entry_from_phb
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  store_index     [IN]        
 *  entry           [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_util_copy_entry_from_phb(U16 store_index, mmi_phb_handler_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    S16 pError;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry->store_index = store_index;
    memcpy(entry->name, PhoneBook[store_index].alpha_id.name, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
    mmi_phb_convert_get_ucs2_number(entry->number, store_index);

    if (store_index < MAX_PB_PHONE_ENTRIES) /* In NVRAM */
    {
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
        mmi_asc_to_ucs2(entry->homeNumber, (PS8) PhoneBookOptionalFields.homeNumber);
        mmi_ucs2cpy(entry->companyName, (PS8) PhoneBookOptionalFields.companyName);
        mmi_asc_to_ucs2(entry->emailAddress, (PS8) PhoneBookOptionalFields.emailAddress);
        mmi_asc_to_ucs2(entry->officeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
        mmi_asc_to_ucs2(entry->faxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
    #else /* clear buffer */
        memset(entry->homeNumber, 0, 2);
        memset(entry->companyName, 0, 2);
        memset(entry->emailAddress, 0, 2);
        memset(entry->officeNumber, 0, 2);
        memset(entry->faxNumber, 0, 2);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */
    #ifdef __MMI_PHB_BIRTHDAY_FIELD__
        mmi_phb_java_get_bday(store_index, &entry->bDay);
    #else
        mmi_phb_java_util_clear_bday(&entry->bDay);
    #endif
        mmi_phb_read_optional_ids(store_index);
        entry->group_id = ((PHB_OPTIONAL_IDS_STRUCT *)g_phb_cntx.optional_ids)->callerGroupID;
    }
    else
    {
    #ifdef __MMI_PHB_USIM_FIELD__
        mmi_phb_op_set_option_data_by_usim_index(store_index, &PhoneBookOptionalFields);
        mmi_asc_to_ucs2(entry->homeNumber, (PS8) PhoneBookOptionalFields.homeNumber);
        mmi_asc_to_ucs2(entry->officeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
        mmi_asc_to_ucs2(entry->faxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
        mmi_asc_to_ucs2(entry->emailAddress, (PS8) PhoneBookOptionalFields.emailAddress);
        entry->group_id = g_phb_cntx.group_type[store_index - MAX_PB_PHONE_ENTRIES];
    #else /* __MMI_PHB_USIM_FIELD__ */ 
        memset(entry->homeNumber, 0, 2);
        memset(entry->officeNumber, 0, 2);
        memset(entry->faxNumber, 0, 2);
        memset(entry->emailAddress, 0, 2);
        entry->group_id = 0;
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
    }

}


#if defined(__MMI_PHB_EMAIL_SORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_util_rebuild_email_sorting
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_util_rebuild_email_sorting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U16 store_index;
    S16 pError;
    U16 *g_phb_email_index;
    U16 pop_count = 0;
    U16 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.processing = TRUE;
    mmi_phb_java_entry_processing_email();

#ifdef __MMI_PHB_USIM_FIELD__
    g_phb_email_index = OslMalloc(MAX_PB_ENTRIES * sizeof(U16));
    memset(g_phb_email_index, 0xff, MAX_PB_ENTRIES * sizeof(U16));
#else /* __MMI_PHB_USIM_FIELD__ */ 
    g_phb_email_index = OslMalloc(MAX_PB_PHONE_ENTRIES * sizeof(U16));
    memset(g_phb_email_index, 0xff, MAX_PB_PHONE_ENTRIES * sizeof(U16));
#endif /* __MMI_PHB_USIM_FIELD__ */ 

    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        store_index = g_phb_name_index[i];

    #ifndef __MMI_PHB_USIM_FIELD__
        if (store_index < MAX_PB_PHONE_ENTRIES) /* Entry in phone */
    #endif 
        {
            ++pop_count;

            if (pop_count == 1)
            {
                g_phb_email_index[(pop_count - 1)] = store_index;
            }
            else
            {
                pos = mmi_phb_sort_email_find_insert_pos(0, (pop_count - 2), store_index, g_phb_email_index);

                for (j = (pop_count - 1); j > pos; j--)
                {
                    g_phb_email_index[j] = g_phb_email_index[j - 1];
                }
                g_phb_email_index[pos] = store_index;

            }

        }
    }

#ifdef __MMI_PHB_USIM_FIELD__
    WriteRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_ENTRIES * sizeof(U16), &pError);
#else 
    WriteRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_PHONE_ENTRIES * sizeof(U16), &pError);
#endif 
    OslMfree(g_phb_email_index);

    g_phb_cntx.processing = FALSE;
    /* DisplayPopup((PU8)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE); */
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_entry_processing_email
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_entry_processing_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_SORTING_EMAIL, mmi_phb_java_exit_processing_email, NULL, NULL);

    ShowCategory8Screen(
        STR_SCR_PBOOK_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        0,
        0,
        0,
        0,
        STR_ID_PHB_SORTING_EMAIL,
        IMG_PROCESSING_PHONEBOOK,
        NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_exit_processing_email
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_exit_processing_email(void)
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
        g_phb_cntx.end_scr_id = SCR_ID_PHB_SORTING_EMAIL;
        h.scrnID = SCR_ID_PHB_SORTING_EMAIL;
        h.entryFuncPtr = mmi_phb_java_entry_processing_email;
        mmi_ucs2cpy((PS8) h.inputBuffer, (PS8) & nHistory);
        GetCategoryHistory(h.guiBuffer);
        AddHistory(h);
    }
}
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */


#ifdef __MMI_PHB_BIRTHDAY_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_check_bday_is_valid
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  store_index     [IN]
 *  entry           [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_java_check_bday_is_valid(applib_time_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error handling */

	if ((t->nYear == 0) && (t->nMonth == 0) && (t->nDay == 0) && (t->nHour == 0) &&
        (t->nMin == 0) && (t->nSec == 0) && (t->DayIndex == 0))
	{
		return MMI_TRUE;
	}
	else
	{
        if (t->nYear > MMI_PHB_BDAY_MAX_YEAR_INT || t->nYear < MMI_PHB_BDAY_MIN_YEAR_INT)
        {
            return MMI_FALSE;
        }

        if (t->nMonth > 12)
        {
            return MMI_FALSE;
        }

        if (t->nMonth == 2)
        {
            if (t->nDay > (g_dt_day_per_mon[t->nMonth - 1] + applib_dt_is_leap_year(t->nYear)))
            {
                return MMI_FALSE;
            }
        }
        else
        {
            if (t->nDay > g_dt_day_per_mon[t->nMonth - 1])
            {
                return MMI_FALSE;
            }
        }

        if (t->nHour > 23)
        {
            return MMI_FALSE;
        }

        if (t->nMin > 59)
        {
            return MMI_FALSE;
        }

        if (t->nSec > 59)
        {
            return MMI_FALSE;
        }
        return MMI_TRUE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_set_bday
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  store_index     [IN]
 *  entry           [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_set_bday(applib_time_struct* b_day, S8* pb_Year, S8* pb_Mon, S8* pb_Day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_buff[6];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(ascii_buff, "%04d", b_day->nYear);
    mmi_asc_to_ucs2(pb_Year, ascii_buff);

    sprintf(ascii_buff, "%02d", b_day->nMonth);
    mmi_asc_to_ucs2(pb_Mon, ascii_buff);

    sprintf(ascii_buff, "%02d", b_day->nDay);
    mmi_asc_to_ucs2(pb_Day, ascii_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_get_bday
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  store_index     [IN]
 *  entry           [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_get_bday(U16 store_index, applib_time_struct *b_day)
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
    if (bday_data[bday_index].bYear <= MMI_PHB_BDAY_MAX_YEAR_INT && bday_data[bday_index].bYear >= MMI_PHB_BDAY_MIN_YEAR_INT)
    {
        b_day->nYear = bday_data[bday_index].bYear;
    }
    else
    {
        b_day->nYear = 0;
    }

    /* Month */
    if (bday_data[bday_index].bMonth <= 12)
    {
        b_day->nMonth = bday_data[bday_index].bMonth;
    }
    else
    {
        b_day->nMonth = 0;
    }

    /* Day */
    if (bday_data[bday_index].bDay <= 31)
    {
        b_day->nDay = bday_data[bday_index].bDay;
    }
    else
    {
        b_day->nDay = 0;
    }
    b_day->nHour = b_day->nMin = b_day->nSec = b_day->DayIndex = 0;
}


#else /* defined (__MMI_PHB_BIRTHDAY_FIELD__)*/
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_util_clear_bday
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  store_index     [IN]
 *  entry           [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_util_clear_bday(applib_time_struct* b_day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	b_day->nYear = b_day->nMonth = b_day->nDay = b_day->nHour = b_day->nMin = b_day->nSec = b_day->DayIndex = 0;
}
#endif /* defined (__MMI_PHB_BIRTHDAY_FIELD__)*/

#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 

#endif /* _MMI_PHONEBOOKJAVAHANDLER_C */ 

