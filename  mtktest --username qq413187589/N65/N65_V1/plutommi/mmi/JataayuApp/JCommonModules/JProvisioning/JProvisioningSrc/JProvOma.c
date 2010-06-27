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
 * JProvOma.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file handles OMA OTA provisioning
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _JPROVOMA_C
#define _JPROVOMA_C

#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
#include <ddl.h>
#ifndef __MMI_JATAAYU_CCA_SUPPORT__


#include "JBrowserMMIGprots.h"
#include "JProvWap.h"
#include "JProvOma.h"
#include "JProfileHandlerResDef.h"
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"
#include "jdi_urivalidation.h"

extern BOOL mmi_phb_op_check_valid_number(S8 *number);
extern pBOOL GetUCS2Flag(PS8 buffer);

const characteristic_tag_handler_struct oma_tag_handler_map[PROV_OMA_CHARACTERISTIC_NUM] = 
{
    "BOOTSTRAP", mmi_prov_oma_handle_bootstrap_tag,
    "NAPDEF", mmi_prov_oma_handle_napdef_tag,
    "PXLOGICAL", mmi_prov_oma_handle_pxlogical_tag,
    //      "PXPHYSICAL",mmi_prov_oma_handle_pxphysical_tag,
    //      "PORT",mmi_prov_oma_handle_port_tag,
    "APPLICATION", mmi_prov_oma_handle_application_tag,
    //      "NAPAUTHINFO",mmi_prov_oma_handle_napauthinfo_tag,
    //      "PXAUTHINFO",mmi_prov_oma_handle_pxauthinfo_tag,
    //      "RESOURCE",mmi_prov_oma_handle_resource_tag,
};

const security_parm_handler_struct oma_security_handler_map[PROV_SEC_TYPE_SUPP_NUM] = 
{
    SEC_NETWPIN, mmi_prov_oma_handle_netwpin,
    SEC_USERPIN, mmi_prov_oma_handle_userpin,
    SEC_USERNETWPIN, mmi_prov_oma_handle_usernetwpin,
    SEC_USERPINMAC, mmi_prov_oma_handle_userpinmac,

};

application_data *g_prov_app_brw_p = NULL;
application_data *g_prov_app_mms_p = NULL;

static prov_logical_proxy_struct *g_prov_proxy_data_p = NULL;
static prov_napdef_struct *g_prov_napdef_data_p = NULL;
static prov_proxy_port_struct prov_proxy_port;

prov_data_account_data_struct *g_prov_dataAccountData_p = NULL;

static U8 *g_prov_imsi_p = NULL;
static U8 *g_prov_MAC_value_p = NULL;

static U8 g_prov_password[30];

static S8 *g_prov_oma_buff_p = NULL;
static U32 g_prov_oma_buff_len;


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_settings
 * DESCRIPTION
 *  It checks if there is security data available in the content type,if yes it handles it
 *  otherwise the data is stored in the queue
 * PARAMETERS
 *  prov_buffer_p       [IN]        
 *  prov_length         [IN]        
 *  content_type_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_handle_settings(S8 *prov_buffer_p, U32 prov_length, S8 *content_type_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_prov_oma_buff_p = jdd_MemAlloc(prov_length, 1); */
    g_prov_oma_buff_p = prov_buffer_p;
    g_prov_oma_buff_len = prov_length;
    /* memcpy(g_prov_oma_buff_p, prov_buffer_p, prov_length); */

    if (strcmp(content_type_p, APPLICATION_VND_WAP_CONNECTIVITY_WBXML) != 0)
    {
        i_ret = mmi_prov_extract_security_data(content_type_p, prov_buffer_p, prov_length);
        if (i_ret == PROV_OK)
        {
            mmi_prov_oma_save_received_settings(prov_buffer_p, prov_length);
        }

    }
    else if (strcmp(content_type_p, APPLICATION_VND_WAP_CONNECTIVITY_WBXML) == 0)
    {
        /* no security avaible ...add to queue */
        mmi_prov_oma_save_received_settings(prov_buffer_p, prov_length);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_save_received_settings
 * DESCRIPTION
 *  It adds the settings into the queue & checks if the queue size,
 *  if it is one to show new settings popup
 * PARAMETERS
 *  prov_buff_p         [IN]        
 *  prov_buff_len       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_save_received_settings(S8 *prov_buff_p, U32 prov_buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_add_to_queue(prov_buff_p, prov_buff_len);
    //if (g_prov_data_queue_size == 1)
    //{
    mmi_prov_show_new_settings_popup();
    /* } */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_insert_settings_parm
 * DESCRIPTION
 *  It calls the respective handler for the various OMA provisioning  characteristics supported & the One not supported
 *  all the needed information is extracted
 * PARAMETERS
 *  root_p      [IN]        
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_insert_settings_parm(TAG *root_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;

    U32 map_array_index;
    S8 characteristic_element[PROV_OMA_MIN_SIZE_REQ + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = root_p->next;

    while (root_p != NULL)
    {

        attr_p = root_p->attribute_list;

        if (strcmp(root_p->name, CHARACTERISTIC) != 0)
        {
            return PROV_ERR;
        }
        else
        {
            /* MAUI_00555503 starts */
            if (mmi_prov_check_not_null((void*)attr_p))
            {
                /* MAUI_00555503 */
                for (map_array_index = 0; map_array_index <= PROV_OMA_CHARACTERISTIC_NUM; ++map_array_index)
                {
                    mmi_ucs2_to_asc(characteristic_element, (S8*) attr_p->value);
                    if (strcmp(characteristic_element, oma_tag_handler_map[map_array_index].characteristic_tags) == 0)
                    {
                        oma_tag_handler_map[map_array_index].characteristic_tag_hdlr(&root_p);
                        break;
                    }
                    if (map_array_index == PROV_OMA_CHARACTERISTIC_NUM)
                    {
                        mmi_prov_oma_handle_unsupported_tag(&root_p);
                        /* For Handling characteristics that are not supported   */
                    }
                }
                /* MAUI_00555503 starts */
            }
            else
            {
                root_p = root_p->next;
            }
            /* MAUI_00555503 ends */
            if (root_p == NULL || (root_p->attribute_list == NULL && root_p->next == NULL))
            {
                return i_ret;
            }
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_extract_security_data
 * DESCRIPTION
 *  This will check for the SEC type & will call respective handler for the SEC types
 *  if error is returned by the SEC handlers Invalid settings popup is shown
 * PARAMETERS
 *  content_type_p      [IN]        
 *  prov_buffer_p       [IN]        
 *  prov_length         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
PROV_RETCODE mmi_prov_extract_security_data(S8 *content_type_p, S8 *prov_buffer_p, U32 prov_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 shiftlen;
    S8 *sec_data;
    U32 map_array_index = 0;
    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    shiftlen = strlen(APPLICATION_VND_WAP_CONNECTIVITY_WBXML);
    sec_data = content_type_p + shiftlen;

    if (*sec_data != SEMI_COLAN_SEPARATER)
    {
        /* No security available */
        mmi_prov_oma_save_received_settings(prov_buffer_p, prov_length);
        return i_ret;
    }
    else
    {
        g_prov_MAC_value_p = jdd_MemAlloc(PROV_OMA_NO_OF_MAC_VALUE_BYTES + 1, 1);
        /* memcpy(g_prov_MAC_value_p,,41); */
        sec_data += PROV_BYTES_TO_SHIFT_TO_SEC_PARM;
        for (; map_array_index < PROV_SEC_TYPE_SUPP_NUM; ++map_array_index)
        {
            if (mmi_prov_check_if_substring(sec_data, oma_security_handler_map[map_array_index].secId) == 0)
            {
                /* move to MAC value */
                sec_data += PROV_BYTES_TO_SHIFT_TO_MAC_PARM;
                memcpy(g_prov_MAC_value_p, sec_data, PROV_OMA_NO_OF_MAC_VALUE_BYTES + 1);
                i_ret = (oma_security_handler_map[map_array_index].sec_hdlr) (content_type_p, prov_buffer_p);
                if (i_ret != PROV_OK)
                {
                    PRINT_INFORMATION("Inside mmi_prov_extract_security_data");
                    DisplayPopup(
                        (PU8) GetString(STR_ID_PROV_INVALID_SETTINGS),
                        IMG_ID_PROV_INVALID_SETTINGS,
                        1,
                        PROV_INVALID_SETTINGS_TIMEOUT,
                        ERROR_TONE);
                }
                return i_ret;
            }
        }

    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_netwpin
 * DESCRIPTION
 *  
 *  This API handles the SEC method NETWPIN
 * PARAMETERS
 *  content_type_p      [IN]        
 *  prov_buff_p         [IN]        
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_netwpin(S8 *content_type_p, S8 *prov_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8 HMAC_value[41]; */

    //for  SEC MAC
    //RspToTestRoamingEnabled
    //gHomePLMNNum

    // mmi_prov_oma_get_imsi_req(); /* Dara temp blocked will be used when using the secirity */

    //HMAC_value=certicomHMAC(gHomePLMNNum,prov_buff_p);
    //haskkeygenarated=HMAC(keyin the form of IMSI,Prov DOc);
    //      memcmp(haskkeygenarated,macvaue from the contenet type,40);

    /* if memcmpm passes ..store the prov DOc ,else rejected */

    /* since we r not showning any indication to the user ...do we require any to indicate teh user if autehntication fails */

    /* dara note ..handle ..the MAC matching */
    return i_ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_userpin
 * DESCRIPTION
 *  
 *  This API handles the SEC method USERWPIN
 * PARAMETERS
 *  content_type_p      [IN]        
 *  prov_buff_p         [IN]        
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_userpin(S8 *content_type_p, S8 *prov_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // mmi_prov_oma_entry_enter_pin();  /* Temp blocked will be used when using Security */

    /* dara note ..handle ..the MAC matching */
    return i_ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_usernetwpin
 * DESCRIPTION
 *  
 *  This API handles the SEC method USERNETWPIN
 * PARAMETERS
 *  content_type_p      [IN]        
 *  prov_buff_p         [IN]        
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_usernetwpin(S8 *content_type_p, S8 *prov_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dara note ..handle ..the MAC matching */
    return i_ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_userpinmac
 * DESCRIPTION
 *  
 *  This API handles the SEC method USERPINMAC
 * PARAMETERS
 *  content_type_p      [IN]        
 *  prov_buff_p         [IN]        
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_userpinmac(S8 *content_type_p, S8 *prov_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dara note ..handle ..the MAC matching */
    return i_ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_bootstrap_tag
 * DESCRIPTION
 *  
 *  It handles the BOOTSTRAP characteristic type & its parm
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_bootstrap_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            *nextroot_p = root_p;
            return i_ret;
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {

            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                if (strcmp(parm_element, NAME_PARM) == 0)
                {
                    attr_p = attr_p->next;
                    // mmi_prov_handle_profile_name(attr_p);   /* check if this can be avoided ... */
                }
            }
        }

        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_napdef_tag
 * DESCRIPTION
 *  This function deals with the NAPDEF characteristic tag and its PARM elements
 * PARAMETERS
 *  nextroot_p      [IN/OUT]        
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_napdef_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];
    prov_data_account_data_struct *accountData_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    if (root_p != NULL)
    {
        accountData_p = jdd_MemAlloc(sizeof(prov_data_account_data_struct), 1);
    }
    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            /* MAUI_00555503 starts */
            if (mmi_prov_check_not_null((void*)root_p->attribute_list))
            {
                /* MAUI_00555503 */
                mmi_ucs2_to_asc(parm_element, (S8*) root_p->attribute_list->value);
                if (strcmp(parm_element, NAPAUTHINFO) == 0)
                {
                    mmi_prov_oma_handle_napauthinfo_tag(&root_p, &accountData_p);
                }
                if (!mmi_prov_oma_check_if_redundant_napdef(g_prov_napdef_data_p, accountData_p))
                {
                    mmi_prov_oma_add_napdef_info(&g_prov_napdef_data_p, accountData_p);
                }
                *nextroot_p = root_p;
                return i_ret;
            }   /* MAUI_00555503 */
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                if (strcmp(parm_element, NAME_PARM) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        if (GetUCS2Flag((S8*) attr_p->value))
                        {
                            mmi_ucs2_to_asc(
                                (S8*) accountData_p->name,
                                (S8*) GetString(STR_ID_PROF_HDLR_DEFAULT_PROFILE_NAME));
                        }
                        else
                        {
                            len = mmi_ucs2strlen((S8*) attr_p->value);
                            if (len >= MAX_DATA_ACCOUNT_NAME_LEN)
                            {
                                len = MAX_DATA_ACCOUNT_NAME_LEN - 1;
                            }
                            mmi_ucs2_n_to_asc((S8*) accountData_p->name, (S8*) attr_p->value, len * ENCODING_LENGTH);
                            accountData_p->name[len] = '\0';
                        }
                    }
                }

                else if (strcmp(parm_element, NAPID) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_NAP_ID_LEN)
                        {
                            len = PROV_NAP_ID_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc((S8*) accountData_p->napid, (S8*) attr_p->value, len * ENCODING_LENGTH);
                        accountData_p->napid[len] = '\0';
                    }
                }

                else if (strcmp(parm_element, BEARER) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        if ((strcmp(parm_element, GSM_CSD) == 0) || (strcmp(parm_element, GSM__CSD) == 0))
                        {
                            g_prov_bearer = PROV_CSD_BEARER;
                            accountData_p->bearer = PROV_CSD_BEARER;
                            accountData_p->dataAccountType.csdAccount.linkSpeed = CSD_PROF_RATE_9600;   /* Default value *//* added by tk */
                        }
                        else if ((strcmp(parm_element, GSM_GPRS) == 0) || (strcmp(parm_element, GSM__GPRS) == 0))
                        {
                            g_prov_bearer = PROV_GPRS_BEARER;
                            accountData_p->bearer = PROV_GPRS_BEARER;
                        }
                        else
                        {
                            accountData_p->bearer = PROV_INVALID_BEARER;
                        }

                    }

                }
                else if (strcmp(parm_element, NAP_ADDRESS) == 0)
                {
                    attr_p = attr_p->next;
                    /* MAUI_00555503 starts */
                    if (mmi_prov_check_not_null((void*)attr_p))
                    {
                        /* MAUI_00555503 */
                    #ifdef __MMI_GPRS_FEATURES__
                        if (g_prov_bearer == PROV_GPRS_BEARER)
                        {
                            len = mmi_ucs2strlen((S8*) attr_p->value);
                            if (len >= MAX_GPRS_MMI_APN_LEN)
                            {
                                len = MAX_GPRS_MMI_APN_LEN - 1;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) accountData_p->dataAccountType.gprsAccount.apn,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            accountData_p->dataAccountType.gprsAccount.apn[len] = '\0';
                        }
                        else
                    #endif /* __MMI_GPRS_FEATURES__ */ 
                        if (g_prov_bearer == PROV_CSD_BEARER)
                        {
                            if (strcmp(attr_p->name, PROV_VALUE) == 0)
                            {
                                len = mmi_ucs2strlen((S8*) attr_p->value);
                                if (len >= PROV_MAX_DIAL_NUM_LEN)
                                {
                                    len = PROV_MAX_DIAL_NUM_LEN - 1;
                                }

                                if (mmi_phb_op_check_valid_number((S8*) attr_p->value))
                                {
                                    mmi_ucs2_n_to_asc(
                                        (S8*) accountData_p->dataAccountType.csdAccount.csdDialString,
                                        (S8*) attr_p->value,
                                        len * ENCODING_LENGTH);
                                    accountData_p->dataAccountType.csdAccount.csdDialString[len] = '\0';
                                    accountData_p->dataAccountType.csdAccount.csdDialNumType = CSMCC_DEFAULT_ADDR_TYPE;
                                }
                                else
                                {
                                    memset(
                                        accountData_p->dataAccountType.csdAccount.csdDialString,
                                        0,
                                        MAX_DIAL_NUM_LEN);
                                    accountData_p->dataAccountType.csdAccount.csdDialNumType = CSMCC_DEFAULT_ADDR_TYPE;
                                }
                            }
                        }
                    }   /* MAUI_00555503 */
                }

                else if (strcmp(parm_element, CALLTYPE) == 0)
                {
                    attr_p = attr_p->next;
                    if (g_prov_bearer == PROV_CSD_BEARER)
                    {
                        /*                      if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                        if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))       /* MAUI_00555503 */
                        {
                            mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                            if (strcmp(parm_element, ANALOG_MODEM) == 0)
                            {
                                accountData_p->dataAccountType.csdAccount.callType = CSMCC_ITC_3_1_K_AUDIO;
                            }
                            else if ((strcmp(parm_element, "V.120") == 0) ||
                                     ((strcmp(parm_element, "V.110") == 0) || (strcmp(parm_element, "X.31") == 0)))
                            {
                                accountData_p->dataAccountType.csdAccount.callType = CSMCC_ITC_UDI;
                            }
                            else
                            {
                                accountData_p->dataAccountType.csdAccount.callType = CSMCC_ITC_3_1_K_AUDIO;
                            }
                        }
                    }
                }

                else if (strcmp(parm_element, LINKSPEED) == 0)
                {
                    attr_p = attr_p->next;
                    if (g_prov_bearer == PROV_CSD_BEARER)
                    {
                        /*                      if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                        if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))       /* MAUI_00555503 */
                        {
                            mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

                            if (strcmp(parm_element, AUTOBAUDING) == 0 || strcmp(parm_element, "9600") == 0)
                            {
                                accountData_p->dataAccountType.csdAccount.linkSpeed = CSD_PROF_RATE_9600;
                            }
                            else if (strcmp(parm_element, "4800") == 0)
                            {
                                accountData_p->dataAccountType.csdAccount.linkSpeed = CSD_PROF_RATE_4800;
                            }
                            else if (strcmp(parm_element, "14400") == 0)
                            {
                                accountData_p->dataAccountType.csdAccount.linkSpeed = CSD_PROF_RATE_14400;
                            }
                            else
                            {
                                accountData_p->dataAccountType.csdAccount.linkSpeed = CSD_PROF_RATE_9600;
                            }
                        }
                    }
                }
                else if (strcmp(parm_element, "DNS-ADDR") == 0)
                {

                    attr_p = attr_p->next;
                    if (g_prov_bearer == PROV_CSD_BEARER)
                    {
                        /*                      if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                        if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))       /* MAUI_00555503 */
                        {
                            PROV_RETCODE i_ret = PROV_OK;
                            U8 proxy_ip[MAX_PART_IP_ADDRESS];

                            mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                            i_ret = mmi_prov_convert_ip_string_to_array(parm_element, proxy_ip);
                            if (i_ret == PROV_ERR)
                            {
                                memset(proxy_ip, 0, MAX_PART_IP_ADDRESS);
                            }
                            memcpy(accountData_p->dataAccountType.csdAccount.dns_ip, proxy_ip, MAX_PART_IP_ADDRESS);
                        }
                    }

                }
            #ifdef __MMI_GPRS_FEATURES__
                else if (strcmp(parm_element, MAX_SDU_SIZE) == 0)
                {
                    attr_p = attr_p->next;
                    /*                  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        /* g_prov_set_gprs_req_p->gprs_account.req_qos.max_sdu_size=atoi(parm_element); */
                    }

                }
                else if (strcmp(parm_element, "GUARANTEED-BITRATE-UPLINK") == 0)
                {
                    attr_p = attr_p->next;
                    /*                  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        /* g_prov_set_gprs_req_p->gprs_account.req_qos.guarntd_bit_rate_up_lnk=atoi(parm_element); */

                    }

                }
                else if (strcmp(parm_element, "GUARANTEED-BITRATE-DNLINK") == 0)
                {
                    attr_p = attr_p->next;
                    /*                  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        /* g_prov_set_gprs_req_p->gprs_account.req_qos.guarntd_bit_rate_down_lnk=atoi(parm_element); */
                    }

                }
                else if (strcmp(parm_element, "TRAFFIC-HANDL-PRIO") == 0)
                {
                    attr_p = attr_p->next;
                    /*                  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        /* g_prov_set_gprs_req_p->gprs_account.req_qos.traffic_hndl_priority=atoi(parm_element); */
                    }

                }
                else if (strcmp(parm_element, "TRANSFER-DELAY") == 0)
                {
                    attr_p = attr_p->next;
                    /*                  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        /* g_prov_set_gprs_req_p->gprs_account.req_qos.transfer_delay=atoi(parm_element); */
                    }

                }

                else if (strcmp(parm_element, "SDU-ERROR-RATIO") == 0)
                {
                    attr_p = attr_p->next;
                    /*                  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        /* g_prov_set_gprs_req_p->gprs_account.req_qos.sdu_err_ratio=atoi(parm_element); */
                    }
                }
            #endif /* __MMI_GPRS_FEATURES__ */ 
            }
        }
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                if (!mmi_prov_oma_check_if_redundant_napdef(g_prov_napdef_data_p, accountData_p))
                {
                    mmi_prov_oma_add_napdef_info(&g_prov_napdef_data_p, accountData_p);
                }
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            if (!mmi_prov_oma_check_if_redundant_napdef(g_prov_napdef_data_p, accountData_p))
            {
                mmi_prov_oma_add_napdef_info(&g_prov_napdef_data_p, accountData_p);
            }
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_pxlogical_tag
 * DESCRIPTION
 *  This function deals with the PXLOGICAL characteristic tag and its PARM elements
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_pxlogical_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];
    prov_log_proxy_data_struct *logProxyData_p;
    prov_phy_proxy_data_struct *phyProxyData_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    logProxyData_p = jdd_MemAlloc(sizeof(prov_log_proxy_data_struct), 1);
    logProxyData_p->physicalProxy = NULL;
    memset((void*)&prov_proxy_port, 0, sizeof(prov_proxy_port));

    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            if (!mmi_prov_oma_check_if_redundant_logical_proxy(g_prov_proxy_data_p, logProxyData_p))
            {
                mmi_prov_oma_add_logical_proxy_info(&g_prov_proxy_data_p, logProxyData_p);
            }
            goto next;
          next:
            {
                if (root_p != NULL)
                {
                    /* MAUI_00555503 starts */
                    if (mmi_prov_check_not_null((void*)root_p->attribute_list))
                    {
                        /* MAUI_00555503 */
                        mmi_ucs2_to_asc(parm_element, (S8*) root_p->attribute_list->value);
                        if (strcmp(parm_element, PXPHYSICAL) == 0)
                        {
                            mmi_prov_oma_handle_pxphysical_tag(&root_p);
                            goto next;
                        }
                        else if (strcmp(parm_element, PXAUTHINFO) == 0)
                        {
                            mmi_prov_oma_handle_pxauthinfo_tag(&root_p, &logProxyData_p);
                            logProxyData_p->is_invalid_auth_info = 0x01;        /* Only first pxauth info will be stored */
                            goto next;
                        }
                        /* Added by tk */
                        else if (strcmp(parm_element, PORT) == 0)
                        {
                            phyProxyData_p = jdd_MemAlloc(sizeof(prov_phy_proxy_data_struct), 1);
                            mmi_prov_oma_handle_port_tag(&root_p, &phyProxyData_p);
                            prov_proxy_port.connType = phyProxyData_p->connType;
                            prov_proxy_port.port = phyProxyData_p->port;
                            if (phyProxyData_p != NULL)
                            {
                                jdd_MemFree(phyProxyData_p);
                                phyProxyData_p = NULL;
                            }

                            goto next;
                        }
                    }   /* MAUI_00555503 */
                }
            }
            mmi_prov_oma_add_pxauth_info(&g_prov_proxy_data_p, logProxyData_p);
            if (logProxyData_p != NULL)
            {
                jdd_MemFree(logProxyData_p);
                logProxyData_p = NULL;
            }
            *nextroot_p = root_p;
            return i_ret;
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                if (strcmp(parm_element, NAME_PARM) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        /* added by tk */
                        if (GetUCS2Flag((S8*) attr_p->value))
                        {
                            mmi_ucs2_to_asc(
                                (S8*) logProxyData_p->proxy_name,
                                (S8*) GetString(STR_ID_PROF_HDLR_DEFAULT_PROFILE_NAME));
                        }
                        else
                        {
                            len = mmi_ucs2strlen((S8*) attr_p->value);
                            if (len >= PROV_PROFILE_PROFILE_NAME_LEN)
                            {
                                len = PROV_PROFILE_PROFILE_NAME_LEN - 1;
                            }

                            mmi_ucs2_n_to_asc(
                                (S8*) logProxyData_p->proxy_name,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            logProxyData_p->proxy_name[len] = '\0';
                        }
                        /* end */
                    }
                }
                else if (strcmp(parm_element, PROV_DOMAIN) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

                    }
                }
                else if (strcmp(parm_element, PROXY_ID) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_PROXY_ID_LEN)
                        {
                            len = PROV_PROXY_ID_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc((S8*) logProxyData_p->proxy_id, (S8*) attr_p->value, len * ENCODING_LENGTH);
                        logProxyData_p->proxy_id[len] = '\0';

                    }
                }
                else if (strcmp(parm_element, STARTPAGE) == 0)
                {
                    attr_p = attr_p->next;
                    /* MAUI_00555503 starts */
                    if (mmi_prov_check_not_null((void*)attr_p))
                    {
                        /* MAUI_00555503 */
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_PROFILE_HOMEPAGE_URL_LEN)
                        {
                            len = PROV_PROFILE_HOMEPAGE_URL_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc(
                            (S8*) logProxyData_p->homepage_url,
                            (S8*) attr_p->value,
                            len * ENCODING_LENGTH);
                        logProxyData_p->homepage_url[len] = '\0';
                        // MAUI_00355388 Start
                        //                    mmi_prov_handle_homepage_url(attr_p);   /* check to finally remove this line .. */
                        // MAUI_00355388 End
                    }   /* MAUI_00555503 */
                }
            }
        }
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                if (!mmi_prov_oma_check_if_redundant_logical_proxy(g_prov_proxy_data_p, logProxyData_p))
                {
                    mmi_prov_oma_add_logical_proxy_info(&g_prov_proxy_data_p, logProxyData_p);
                }
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            if (!mmi_prov_oma_check_if_redundant_logical_proxy(g_prov_proxy_data_p, logProxyData_p))
            {
                mmi_prov_oma_add_logical_proxy_info(&g_prov_proxy_data_p, logProxyData_p);
            }
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_pxphysical_tag
 * DESCRIPTION
 *  This function deals with the PXPHYSICAL characteristic tag and its PARM elements
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_pxphysical_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];
    prov_phy_proxy_data_struct *phyProxyData_p;
    U32 len;
    U32 valid_pxphysical_tag = 0x00;
    U32 redundant_parm = 0x00;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phyProxyData_p = jdd_MemAlloc(sizeof(prov_phy_proxy_data_struct), 1);
    if (phyProxyData_p != NULL)
    {
        phyProxyData_p->connType = prov_proxy_port.connType;
        phyProxyData_p->port = prov_proxy_port.port;
    }
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            /* MAUI_00555503 starts */
            if (mmi_prov_check_not_null((void*)root_p->attribute_list))
            {
                /* MAUI_00555503 */
                mmi_ucs2_to_asc(parm_element, (S8*) root_p->attribute_list->value);
                if (strcmp(parm_element, PORT) == 0)
                {
                    mmi_prov_oma_handle_port_tag(&root_p, &phyProxyData_p);

                }
                if (g_prov_proxy_data_p->nextLogProxy_p)
                {
                    if ((valid_pxphysical_tag)
                        &&
                        (!mmi_prov_oma_check_if_redundant_physical_proxy
                         (g_prov_proxy_data_p->nextLogProxy_p->logProxyData.physicalProxy, phyProxyData_p)))
                    {
                        mmi_prov_oma_add_physical_proxy_info(
                            & (g_prov_proxy_data_p->nextLogProxy_p->logProxyData.physicalProxy),
                            phyProxyData_p);
                    }
                }
                else
                {
                    if ((valid_pxphysical_tag)
                        &&
                        (!mmi_prov_oma_check_if_redundant_physical_proxy
                         (g_prov_proxy_data_p->logProxyData.physicalProxy, phyProxyData_p)))
                    {
                        mmi_prov_oma_add_physical_proxy_info(
                            &(g_prov_proxy_data_p->logProxyData.physicalProxy),
                            phyProxyData_p);
                    }
                }
                *nextroot_p = root_p;
                return i_ret;
            }   /* MAUI_00555503 */
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

                if (strcmp(parm_element, PXADDR) == 0)
                {
                    attr_p = attr_p->next;
                    /* MAUI_00555503 starts */
                    if (mmi_prov_check_not_null((void*)attr_p))
                    {
                        /* MAUI_00555503 */
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_PX_ADDR_LEN)
                        {
                            len = PROV_PX_ADDR_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc((S8*) phyProxyData_p->pxAddr, (S8*) attr_p->value, len * ENCODING_LENGTH);
                        phyProxyData_p->pxAddr[len] = '\0';
                    }   /* MAUI_00555503 */
                }
                else if (strcmp(parm_element, TO_NAPID) == 0)
                {
                    attr_p = attr_p->next;
                    if (redundant_parm & PROV_OMA_IGNORE_OTHER_TO_NAPID)
                    {
                        goto next;
                    }
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_NAP_ID_LEN)
                        {
                            len = PROV_NAP_ID_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc((S8*) phyProxyData_p->toNapID, (S8*) attr_p->value, len * ENCODING_LENGTH);
                        phyProxyData_p->toNapID[len] = '\0';
                    }

                    redundant_parm |= PROV_OMA_IGNORE_OTHER_TO_NAPID;
                    valid_pxphysical_tag = 0x01;

                }
                else if (strcmp(parm_element, PROV_DOMAIN) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

                    }
                }
                else if (strcmp(parm_element, PHYSICAL_PROXY_ID) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_PHYSICAL_PROXY_ID_LEN)
                        {
                            len = PROV_PHYSICAL_PROXY_ID_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc(
                            (S8*) phyProxyData_p->physicalProxyID,
                            (S8*) attr_p->value,
                            len * ENCODING_LENGTH);
                        phyProxyData_p->physicalProxyID[len] = '\0';
                    }
                }
            }
        }
      next:
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                if ((valid_pxphysical_tag)
                    &&
                    (!mmi_prov_oma_check_if_redundant_physical_proxy
                     (g_prov_proxy_data_p->logProxyData.physicalProxy, phyProxyData_p)))
                {
                    mmi_prov_oma_add_physical_proxy_info(
                        &(g_prov_proxy_data_p->logProxyData.physicalProxy),
                        phyProxyData_p);
                }
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {

            if ((valid_pxphysical_tag)
                &&
                (!mmi_prov_oma_check_if_redundant_physical_proxy
                 (g_prov_proxy_data_p->logProxyData.physicalProxy, phyProxyData_p)))
            {
                mmi_prov_oma_add_physical_proxy_info(
                    &(g_prov_proxy_data_p->logProxyData.physicalProxy),
                    phyProxyData_p);
            }
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_port_tag
 * DESCRIPTION
 *  This function deals with the PORT characteristic tag and its PARM elements
 * PARAMETERS
 *  nextroot_p          [IN]        IN\OUT
 *  phyProxyData_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_port_tag(TAG **nextroot_p, prov_phy_proxy_data_struct **phyProxyData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    if (NULL == *phyProxyData_p)
    {
        ASSERT(0);
    }
    (*phyProxyData_p)->connType = PH_CONN_TYPE_HTTP;    /* Default value in case of port tag not present */

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            *nextroot_p = root_p;
            return i_ret;
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                if (strcmp(parm_element, PORTNBR) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        (*phyProxyData_p)->port = atoi(parm_element);
                    }
                }
                else if (strcmp(parm_element, SERVICE) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        if (strcmp(parm_element, "CO-WSP") == 0)
                        {
                            (*phyProxyData_p)->connType = PH_CONN_TYPE_CONNECTION_OREINTED;
                            /* g_ph_cntx.ph_wap_profile_p->conn_type=PH_CONN_TYPE_CONNECTION_OREINTED; */
                        }
                        else if (strcmp(parm_element, "CO-SEC-WSP") == 0)
                        {
                            (*phyProxyData_p)->connType = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;
                            /* g_ph_cntx.ph_wap_profile_p->conn_type=PH_CONN_TYPE_CONNECTION_OREINTED_SECURE; */
                        }
                        else if (strcmp(parm_element, "OTA-HTTP-TO") == 0)
                        {
                            (*phyProxyData_p)->connType = PH_CONN_TYPE_HTTP;
                        }
                        else if (strcmp(parm_element, "OTA-HTTP-TLS-TO") == 0)
                        {
                            (*phyProxyData_p)->connType = PH_CONN_TYPE_HTTP;
                        }
                        else if (strcmp(parm_element, "OTA-HTTP-PO") == 0)
                        {
                            (*phyProxyData_p)->connType = PH_CONN_TYPE_HTTP;
                        }
                        else if (strcmp(parm_element, "OTA-HTTP-TLS-PO") == 0)
                        {
                            (*phyProxyData_p)->connType = PH_CONN_TYPE_HTTP;
                        }
                    }
                }
            }
        }
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_napauthinfo_tag
 * DESCRIPTION
 *  This function deals with the NAPAUTHINFO characteristic tag and its PARM elements
 * PARAMETERS
 *  nextroot_p              [IN]        IN\OUT
 *  data_account_data_p     [IN]        IN\OUT
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_napauthinfo_tag(
                TAG **nextroot_p,
                prov_data_account_data_struct **data_account_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            *nextroot_p = root_p;
            return i_ret;
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

                if (strcmp(parm_element, AUTHTYPE) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        if (strcmp(parm_element, PAP) == 0)
                        {
                            (*data_account_data_p)->authType = PROV_AUTHTYPE_PAP;
                        }
                        else if (strcmp(parm_element, CHAP) == 0)
                        {
                            (*data_account_data_p)->authType = PROV_AUTHTYPE_CHAP;
                        }
                        else
                        {
                            (*data_account_data_p)->authType = PROV_AUTHTYPE_PAP;
                        }
                    }

                }
                else if (strcmp(parm_element, AUTHNAME) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_MAX_USER_LEN)
                        {
                            len = PROV_MAX_USER_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc(
                            (S8*) (*data_account_data_p)->userName,
                            (S8*) attr_p->value,
                            len * ENCODING_LENGTH);
                        (*data_account_data_p)->userName[len] = '\0';
                    }

                }
                else if (strcmp(parm_element, AUTHSECRET) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_MAX_PASSWD_LEN)
                        {
                            len = PROV_MAX_PASSWD_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc(
                            (S8*) (*data_account_data_p)->password,
                            (S8*) attr_p->value,
                            len * ENCODING_LENGTH);
                        (*data_account_data_p)->password[len] = '\0';
                    }
                }
            }
        }

        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_application_tag
 * DESCRIPTION
 *  This function deals with the APPLICATION characteristic tag and its PARM elements
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_application_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];
    U8 app_id[PROV_APPLICATION_APP_ID_LEN + 1];

    U32 redundant_parm = 0x00;
    U32 unsupported_appl = 0x00;

    /* MAUI_00355388 Start */
    U8 uri[PROV_PROFILE_MMSC_URL_LEN + 1];

    /* MAUI_00355388 End */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            /* MAUI_00555503 starts */
            if (mmi_prov_check_not_null((void*)root_p->attribute_list))
            {
                /* MAUI_00555503 */
                mmi_ucs2_to_asc(parm_element, (S8*) root_p->attribute_list->value);
                if (strcmp(parm_element, RESOURCE) == 0)
                {
                    if (!unsupported_appl)
                    {
                        mmi_prov_oma_handle_resource_tag(&root_p);
                    }
                }
                *nextroot_p = root_p;
                return i_ret;
            }   /* MAUI_00555503 */
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                if (unsupported_appl)
                {
                    goto next;
                }
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                if (strcmp(parm_element, APPID) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_APPLICATION_APP_ID_LEN)
                        {
                            len = PROV_APPLICATION_APP_ID_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc((S8*) app_id, (S8*) attr_p->value, len * ENCODING_LENGTH);
                        app_id[len] = '\0';

                        if (strcmp((S8*) app_id, BRW_APPL) == 0)
                        {
                            if (g_prov_app_brw_p == NULL)
                            {
                                g_prov_app_brw_p = (application_data*) jdd_MemAlloc(sizeof(application_data), 1);
                            }

                            if (strcmp((S8*) app_id, (S8*) g_prov_app_brw_p->app_id) == 0)
                            {
                                g_prov_app_brw_p->flags |= PROV_OMA_IGNORE_OTHER_WAP_APPL;
                                goto next;
                            }

                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_brw_p->app_id,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_brw_p->app_id[len] = '\0';
                            g_prov_appl_flag |= PROV_BROWSER_APPLICATION;
                        }
                        else if (strcmp((S8*) app_id, MMS_APPL) == 0)
                        {
                            if (g_prov_app_mms_p == NULL)
                            {
                                g_prov_app_mms_p = (application_data*) jdd_MemAlloc(sizeof(application_data), 1);
                            }

                            if (strcmp((S8*) app_id, (S8*) g_prov_app_mms_p->app_id) == 0)
                            {
                                g_prov_app_mms_p->flags |= PROV_OMA_IGNORE_OTHER_MMS_APPL;
                                goto next;
                            }

                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_mms_p->app_id,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_mms_p->app_id[len] = '\0';
                            g_prov_appl_flag |= PROV_MMS_APPLICATION;
                            g_prov_setting_type |= PROV_MMS_SETTINGS;
                        }
                        else
                        {
                            //handle all other supported application before this
                            //handle unsupported applications 
                            unsupported_appl = 0x01;

                        }
                    }
                }
                else if (strcmp(parm_element, NAME_PARM) == 0)
                {

                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_APPLICATION_APP_NAME_LEN)
                        {
                            len = PROV_APPLICATION_APP_NAME_LEN - 1;
                        }

                        if (strcmp((S8*) app_id, BRW_APPL) == 0)
                        {
                            if (g_prov_app_brw_p->flags & PROV_OMA_IGNORE_OTHER_WAP_APPL)
                            {
                                goto next;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_brw_p->application_name,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_brw_p->application_name[len] = '\0';

                        }
                        else if (strcmp((S8*) app_id, MMS_APPL) == 0)
                        {
                            if (g_prov_app_mms_p->flags & PROV_OMA_IGNORE_OTHER_MMS_APPL)
                            {
                                goto next;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_mms_p->application_name,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_mms_p->application_name[len] = '\0';
                        }
                    }
                }
                else if (strcmp(parm_element, TO_PROXY) == 0)
                {
                    attr_p = attr_p->next;

                    if (redundant_parm & PROV_OMA_APPL_IGNORE_OTHER_TO_PROXY)
                    {
                        goto next;
                    }
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_PROXY_ID_LEN)
                        {
                            len = PROV_PROXY_ID_LEN - 1;
                        }

                        if (strcmp((S8*) app_id, BRW_APPL) == 0)
                        {
                            if (g_prov_app_brw_p->flags & PROV_OMA_IGNORE_OTHER_WAP_APPL)
                            {
                                goto next;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_brw_p->proxy_id,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_brw_p->proxy_id[len] = '\0';

                        }
                        else if (strcmp((S8*) app_id, MMS_APPL) == 0)
                        {
                            if (g_prov_app_mms_p->flags & PROV_OMA_IGNORE_OTHER_MMS_APPL)
                            {
                                goto next;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_mms_p->proxy_id,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_mms_p->proxy_id[len] = '\0';
                        }
                    }

                    redundant_parm |= PROV_OMA_APPL_IGNORE_OTHER_TO_PROXY;
                }
                else if (strcmp(parm_element, TO_NAPID) == 0)
                {
                    attr_p = attr_p->next;

                    if (redundant_parm & PROV_OMA_APPL_IGNORE_OTHER_TO_NAPID)
                    {
                        goto next;
                    }
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_PROXY_ID_LEN)
                        {
                            len = PROV_PROXY_ID_LEN - 1;
                        }

                        if (strcmp((S8*) app_id, BRW_APPL) == 0)
                        {
                            if (g_prov_app_brw_p->flags & PROV_OMA_IGNORE_OTHER_WAP_APPL)
                            {
                                goto next;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_brw_p->nap_id,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_brw_p->nap_id[len] = '\0';

                        }
                        else if (strcmp((S8*) app_id, MMS_APPL) == 0)
                        {
                            if (g_prov_app_mms_p->flags & PROV_OMA_IGNORE_OTHER_MMS_APPL)
                            {
                                goto next;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_mms_p->nap_id,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_mms_p->nap_id[len] = '\0';
                        }

                    }
                    redundant_parm |= PROV_OMA_APPL_IGNORE_OTHER_TO_NAPID;
                }
                else if (strcmp(parm_element, ADDR) == 0)
                {
                    U32 len;

                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        if (strcmp((S8*) app_id, MMS_APPL) == 0)
                        {
                            if ((g_prov_app_mms_p->flags & PROV_OMA_IGNORE_OTHER_MMS_APPL)
                                || (redundant_parm & PROV_OMA_APPL_IGNORE_OTHER_ADDR))
                            {
                                goto next;
                            }
                            len = mmi_ucs2strlen((S8*) attr_p->value);
                            if (len >= PROV_PROFILE_MMSC_URL_LEN)
                            {
                                len = PROV_PROFILE_MMSC_URL_LEN - 1;
                            }

                            /* MAUI_00355388 Start */
                            mmi_ucs2_n_to_asc((S8*) uri, (S8*) attr_p->value, len * ENCODING_LENGTH);
                            uri[len] = '\0';

                            mmi_prov_oma_update_mms_profile_mmsc_url(uri);
                            /* MAUI_00355388 End */

                            mmi_ucs2_n_to_asc(
                                (S8*) g_prov_app_mms_p->mmsc_address,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            g_prov_app_mms_p->mmsc_address[len] = '\0';
                            redundant_parm |= PROV_OMA_APPL_IGNORE_OTHER_ADDR;

                        }
                    }
                }
            }
        }
      next:
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_pxauthinfo_tag
 * DESCRIPTION
 *  This function deals with the PXAUTHINFO characteristic tag and its PARM elements
 * PARAMETERS
 *  nextroot_p          [IN]        IN\OUT
 *  logProxyData_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_pxauthinfo_tag(TAG **nextroot_p, prov_log_proxy_data_struct **logProxyData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            *nextroot_p = root_p;
            return i_ret;
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                if (strcmp(parm_element, PXAUTH_TYPE) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

                    }

                }
                else if (strcmp(parm_element, PXAUTH_ID) == 0)
                {
                    attr_p = attr_p->next;
                    if (!(*logProxyData_p)->is_invalid_auth_info)
                    {
                        /*                      if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                        if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))       /* MAUI_00555503 */
                        {
                            len = mmi_ucs2strlen((S8*) attr_p->value);
                            if (len >= PROV_PROFILE_USERNAME_LEN)
                            {
                                len = PROV_PROFILE_USERNAME_LEN - 1;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) (*logProxyData_p)->px_auth_id,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            (*logProxyData_p)->px_auth_id[len] = '\0';

                            /* strcpy((S8*)g_ph_cntx.ph_wap_profile_p->username,parm_element); */
                        }
                    }
                }
                else if (strcmp(parm_element, PXAUTH_PW) == 0)
                {
                    attr_p = attr_p->next;
                    if (!(*logProxyData_p)->is_invalid_auth_info)
                    {
                        /*                      if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                        if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))       /* MAUI_00555503 */
                        {
                            len = mmi_ucs2strlen((S8*) attr_p->value);
                            if (len >= PROV_PROFILE_PASSWORD_LEN)
                            {
                                len = PROV_PROFILE_PASSWORD_LEN - 1;
                            }
                            mmi_ucs2_n_to_asc(
                                (S8*) (*logProxyData_p)->px_auth_pwd,
                                (S8*) attr_p->value,
                                len * ENCODING_LENGTH);
                            (*logProxyData_p)->px_auth_pwd[len] = '\0';
                            /* strcpy((S8*)g_ph_cntx.ph_wap_profile_p->password,parm_element); */
                        }
                    }
                }
            }
        }
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_resource_tag
 * DESCRIPTION
 *  This function deals with the RESOURCE characteristic tag and its PARM elements
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_resource_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_OMA_MIN_SIZE_REQ + 1];
    U8 uri[PROV_PROFILE_HOMEPAGE_URL_LEN + 1];
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    /* Dara NOTE : this will be part of Browser application only & NOt MMS application */
    while (root_p != NULL)
    {
        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            *nextroot_p = root_p;
            return i_ret;
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /*             if (strcmp(attr_p->name, NAME) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, NAME) == 0)) /* MAUI_00555503 */
            {
                mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                if (strcmp(parm_element, URI) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_PROFILE_HOMEPAGE_URL_LEN)
                        {
                            len = PROV_PROFILE_HOMEPAGE_URL_LEN - 1;
                        }
                        mmi_ucs2_n_to_asc((S8*) uri, (S8*) attr_p->value, len * ENCODING_LENGTH);
                        uri[len] = '\0';
                        // mmi_brw_add_prov_bookmark(NULL, uri);   /* Note : to add this URI in teh bookmark list */

                    }

                }
                else if (strcmp(parm_element, NAME_PARM) == 0)
                {
                    attr_p = attr_p->next;

                }
                else if (strcmp(parm_element, STARTPAGE) == 0)
                {
                    /* MAUI_00355388 Start */
                    mmi_prov_oma_update_wap_profile_homepage_url(uri);
                    /* MAUI_00355388 End */
                }
            }
        }
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_csd_callspeed
 * DESCRIPTION
 *  This function handles CSD call speed parameter received in the OMA settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_handle_csd_callspeed(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 parm_element[PROV_MIN_SIZE_REQ + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

        if (strcmp(parm_element, AUTOBAUDING) == 0 || strcmp(parm_element, "9600") == 0)
        {
            g_prov_set_csd_req_p->rate = CSD_PROF_RATE_9600;
        }
        else if (strcmp(parm_element, "4800") == 0)
        {
            g_prov_set_csd_req_p->rate = CSD_PROF_RATE_4800;
        }
        else if (strcmp(parm_element, "14400") == 0)
        {
            g_prov_set_csd_req_p->rate = CSD_PROF_RATE_14400;
        }
        else
        {
            g_prov_set_csd_req_p->rate = CSD_PROF_RATE_9600;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_unsupported_tag
 * DESCRIPTION
 *  This function handles the unsupported characteristics
 * PARAMETERS
 *  nextroot_p      [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_handle_unsupported_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            *nextroot_p = root_p;
            return i_ret;
        }
        else if (strcmp(root_p->name, PARM) == 0)
        {
            /* Do nothing ...dara */
        }
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            if (attr_p == NULL && root_p->name == NULL)
            {
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            *nextroot_p = root_p;
            return i_ret;
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_check_pending_application_callback
 * DESCRIPTION
 *  This API check if there is any pending appication settings to be installed before looking for new prov. doc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_check_pending_application_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // GoBackHistory(); /*Commented by TK*/
    mmi_prov_oma_check_pending_application();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_check_pending_application
 * DESCRIPTION
 *  This API check if there is any pending appication settings to be installed before looking for new prov. doc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_check_pending_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_dataAccountData_p != NULL)
    {
        jdd_MemFree(g_prov_dataAccountData_p);
        g_prov_dataAccountData_p = NULL;
    }
    if (g_prov_appl_flag > 0)
    {
        if ((g_ph_cntx.profile_module == PH_BROWSER_PROV_PROFILE) && (g_prov_appl_flag & PROV_BROWSER_APPLICATION))
        {
            g_prov_appl_flag &= ~PROV_BROWSER_APPLICATION;
            g_prov_setting_type &= ~PROV_BRS_SETTINGS;
            g_ph_cntx.profile_module = PH_PROFILE_NULL;
            if (g_prov_app_brw_p != NULL)
            {
                jdd_MemFree(g_prov_app_brw_p);
                g_prov_app_brw_p = NULL;
            }

        }
        else if ((g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE) && (g_prov_appl_flag & PROV_MMS_APPLICATION))
        {
            g_prov_appl_flag &= ~PROV_MMS_APPLICATION;
            g_prov_setting_type &= ~PROV_MMS_SETTINGS;
            g_ph_cntx.profile_module = PH_PROFILE_NULL;
            if (g_prov_app_mms_p != NULL)
            {
                jdd_MemFree(g_prov_app_mms_p);
                g_prov_app_mms_p = NULL;
            }
        }
        if (g_prov_appl_flag > 0)
        {
            mmi_prov_oma_show_install_application_settings_dialog();
        }
        else
        {

            mmi_prov_oma_free_napdef_info();
            mmi_prov_oma_free_proxy_info();

            mmi_prov_handle_get_next_prov_data();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_show_install_application_settings_dialog
 * DESCRIPTION
 *  This is the entry function for the Install Settings dialogue confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_show_install_application_settings_dialog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*   DisplayConfirm(
       STR_GLOBAL_OK,
       IMG_GLOBAL_OK,
       STR_GLOBAL_CANCEL,
       IMG_ID_PROV_CANCEL,
       get_string(STR_ID_PROV_INSTALL_SETTINGS),
       IMG_GLOBAL_QUESTION,
       0);
       
       SetLeftSoftkeyFunction(mmi_prov_oma_handle_install_application, KEY_EVENT_UP);
       SetRightSoftkeyFunction(mmi_prov_handle_cancel, KEY_EVENT_UP); */
    mmi_prov_entry_show_new_settings_popup();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_handle_install_application
 * DESCRIPTION
 *  This API checks for pending Applications to be installed,show tha profile list menu for the selected application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_handle_install_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_appl_flag & PROV_BROWSER_APPLICATION)
    {
        i_ret = mmi_prov_oma_get_application_data(g_prov_app_brw_p);
        if (i_ret == PROV_OK)
        {
            mmi_ph_pre_entry_show_profile_list_menu(PH_BROWSER_PROV_PROFILE);
        }
        else
        {
            g_ph_cntx.profile_module = PH_BROWSER_PROV_PROFILE;
            g_prov_timeout_hdlr = mmi_prov_oma_check_pending_application_callback;
            PRINT_INFORMATION("Inside mmi_prov_oma_handle_install_application for browser");
            mmi_prov_handle_error_code(i_ret);  /* changes PROV */
        }
    }
    else if (g_prov_appl_flag & PROV_MMS_APPLICATION)
    {
        i_ret = mmi_prov_oma_get_application_data(g_prov_app_mms_p);
        /* CSD bearer is not supported in MMS */
        if (g_prov_bearer == PROV_CSD_BEARER)
        {
            i_ret = PROV_ERR_UNSUPPORTED_SETTING;
        }
        if (i_ret == PROV_OK)
        {
            mmi_ph_pre_entry_show_profile_list_menu(PH_MMS_PROV_PROFILE);
        }
        else
        {
            g_ph_cntx.profile_module = PH_MMS_PROV_PROFILE;
            g_prov_timeout_hdlr = mmi_prov_oma_check_pending_application_callback;
            PRINT_INFORMATION("Inside mmi_prov_oma_handle_install_application for MMS");
            mmi_prov_handle_error_code(i_ret);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_add_napdef_info
 * DESCRIPTION
 *  THis API adds the napdef data into the napdef data list
 * PARAMETERS
 *  napdef_data_p       [IN]        IN\OUT
 *  accountData_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_add_napdef_info(prov_napdef_struct **napdef_data_p, prov_data_account_data_struct *accountData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    prov_napdef_struct *tmp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_p = jdd_MemAlloc(sizeof(prov_napdef_struct), 1);

    memcpy(&(tmp_p->accountData), accountData_p, sizeof(prov_data_account_data_struct));
    tmp_p->nextNapdef_p = *napdef_data_p;

    *napdef_data_p = tmp_p;

    if (accountData_p != NULL)
    {
        jdd_MemFree(accountData_p);
        accountData_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_add_logical_proxy_info
 * DESCRIPTION
 *  It adds the given Logical proxy info into the  Logical proxy list
 * PARAMETERS
 *  logProxy_p          [IN/OUT]        
 *  logProxyData_p      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_add_logical_proxy_info(
        prov_logical_proxy_struct **logProxy_p,
        prov_log_proxy_data_struct *logProxyData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    prov_logical_proxy_struct *tmp_p, *tmp1_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp1_p = *logProxy_p;

    if (tmp1_p == NULL)
    {
   /*----First Logical proxy ------*/
        tmp_p = jdd_MemAlloc(sizeof(prov_logical_proxy_struct), 1);
        memcpy(&(tmp_p->logProxyData), logProxyData_p, sizeof(prov_log_proxy_data_struct));
        tmp_p->nextLogProxy_p = NULL;
        tmp1_p = tmp_p;
    }
    else
    {
        while ((tmp1_p->nextLogProxy_p) != NULL)
        {
            tmp1_p = tmp1_p->nextLogProxy_p;
        }
        tmp_p = jdd_MemAlloc(sizeof(prov_logical_proxy_struct), 1);
        memcpy(&(tmp_p->logProxyData), logProxyData_p, sizeof(prov_log_proxy_data_struct));
        tmp1_p->nextLogProxy_p = tmp_p;
    }
    *logProxy_p = tmp1_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_add_physical_proxy_info
 * DESCRIPTION
 *  It adds the given physical proxy info into the  physical proxy list
 * PARAMETERS
 *  phyProxy_p          [IN]        IN\OUT
 *  phyProxyData_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_add_physical_proxy_info(
        prov_physical_proxy_struct **phyProxy_p,
        prov_phy_proxy_data_struct *phyProxyData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    prov_physical_proxy_struct *tmp_p, *tmp1_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp1_p = *phyProxy_p;
    if (tmp1_p == NULL)
    {
   /*----First Physcial proxy ------*/
        tmp_p = jdd_MemAlloc(sizeof(prov_physical_proxy_struct), 1);

        memcpy(&(tmp_p->phyProxyData), phyProxyData_p, sizeof(prov_phy_proxy_data_struct));

        tmp_p->nextPhyProxy_p = NULL;

        tmp1_p = tmp_p;
    }
    else
    {
        while ((tmp1_p->nextPhyProxy_p) != NULL)
        {
            tmp1_p = tmp1_p->nextPhyProxy_p;
        }
        tmp_p = jdd_MemAlloc(sizeof(prov_physical_proxy_struct), 1);
        memcpy(&(tmp_p->phyProxyData), phyProxyData_p, sizeof(prov_phy_proxy_data_struct));
        tmp1_p->nextPhyProxy_p = tmp_p;
    }
    *phyProxy_p = tmp1_p;

    /* tmp_p = jdd_MemAlloc(sizeof(prov_physical_proxy_struct), 1); */

    /* memcpy(&(tmp_p->phyProxyData), phyProxyData_p, sizeof(prov_phy_proxy_data_struct)); */

    /* tmp_p->nextPhyProxy_p = *phyProxy_p; */

    /* *phyProxy_p = tmp_p; */

    if (phyProxyData_p != NULL)
    {
        jdd_MemFree(phyProxyData_p);
        phyProxyData_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_add_pxauth_info
 * DESCRIPTION
 *  It updates the username & password of the logical proxy data list using the availbale values
 * PARAMETERS
 *  logProxy_p          [IN/OUT]        
 *  logProxyData_p      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_add_pxauth_info(prov_logical_proxy_struct **logProxy_p, prov_log_proxy_data_struct *logProxyData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy((S8*) (*logProxy_p)->logProxyData.px_auth_id, (S8*) logProxyData_p->px_auth_id);
    strcpy((S8*) (*logProxy_p)->logProxyData.px_auth_pwd, (S8*) logProxyData_p->px_auth_pwd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_get_application_data
 * DESCRIPTION
 *  THis matches the Proxy-Id & the Nap-Id of the application data with the proxy & Napdef data Lists
 *  if there is no proxy-Id available conenction type fopr the Browser & MMS profile is set to HTTP
 * PARAMETERS
 *  appData_p       [IN]        
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_get_application_data(application_data *appData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE i_ret = PROV_OK;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen((S8*) appData_p->application_name);
    if (len)
    {
        if (len >= PROV_PROFILE_PROFILE_NAME_LEN)
        {
            len = PROV_PROFILE_PROFILE_NAME_LEN - 1;
        }
        if (g_prov_profile_name_p == NULL)
        {
            g_prov_profile_name_p = (U8*) jdd_MemAlloc(PROV_PROFILE_PROFILE_NAME_LEN + 1, 1);
            memcpy((S8*) g_prov_profile_name_p, (S8*) appData_p->application_name, len);
        }
    }

    if (strlen((S8*) appData_p->proxy_id))
    {
        i_ret = mmi_prov_oma_search_and_fill_proxy_data(appData_p);
    }
    else if (strlen((S8*) appData_p->nap_id))
    {
        /* NOTE : Since there is no TO-PROXYID reference ....so the HTTP direct will be teh connection type */
        if (g_prov_appl_flag & PROV_BROWSER_APPLICATION)
        {
            if (g_ph_cntx.ph_wap_profile_p == NULL)
            {
                g_ph_cntx.ph_wap_profile_p =
                    (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
            }
            g_ph_cntx.ph_wap_profile_p->proxy_port = PROV_DEFAULT_HTTP_PORT;    /* default HTTP port */
            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_HTTP;
        }
        else if (g_prov_appl_flag & PROV_MMS_APPLICATION)
        {
            if (g_ph_cntx.ph_mms_profile_p == NULL)
            {
                g_ph_cntx.ph_mms_profile_p =
                    (nvram_mms_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE, 1);
            }
            g_ph_cntx.ph_mms_profile_p->proxy_port = PROV_DEFAULT_HTTP_PORT;    /* default HTTP port */
            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_HTTP;
        }

        i_ret = mmi_prov_oma_compare_appl_napdef_napid(appData_p);
    }
    else
    {
        return PROV_ERR;
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_search_and_fill_proxy_data
 * DESCRIPTION
 *  It searches and matches the proxy-Id available with the application data & the physical proxy data list
 * PARAMETERS
 *  appData_p       [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_search_and_fill_proxy_data(application_data *appData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE i_ret = PROV_OK;
    U32 count = 0x00;
    prov_logical_proxy_struct *tmp_logical_p = g_prov_proxy_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = mmi_prov_oma_get_logical_proxy_count(tmp_logical_p);

    if (count == 0x00)
    {
        return PROV_ERR;
    }
    else if (count == 0x01)
    {
        i_ret = mmi_prov_oma_search_physical_proxy(&tmp_logical_p->logProxyData);
        return i_ret;
    }
    else
    {
        do
        {
            if (strcmp((S8*) appData_p->proxy_id, (S8*) tmp_logical_p->logProxyData.proxy_id) == 0)
            {

                i_ret = mmi_prov_oma_search_physical_proxy(&tmp_logical_p->logProxyData);
                return i_ret;
            }
            tmp_logical_p = tmp_logical_p->nextLogProxy_p;
        } while (tmp_logical_p != NULL);
    }
    return PROV_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_search_physical_proxy
 * DESCRIPTION
 *  It gets the count of the physical proxy,and if there are more than one
 *  then matches the NAPID of the first physical proxy with the NAPID available with the Napdef data
 *  once the match is made it updates the global instances WAP & MMS profiles
 * PARAMETERS
 *  logProxy_p      [IN]        
 * RETURNS
 *  PROV_OK
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_search_physical_proxy(prov_log_proxy_data_struct *logProxy_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE i_ret = PROV_OK;
    U32 count;
    prov_physical_proxy_struct *tmp_physical_p = logProxy_p->physicalProxy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_oma_get_logical_proxy_data(logProxy_p);

    count = mmi_prov_oma_get_physical_proxy_count(tmp_physical_p);

    if (count == 0x00)
    {
        return PROV_ERR;
    }
    else
    {
        i_ret = mmi_prov_oma_compare_phproxy_napdef_napid(&tmp_physical_p->phyProxyData);
        if (i_ret == PROV_ERR)
        {
            if (g_prov_appl_flag & PROV_BROWSER_APPLICATION)
            {
                i_ret = mmi_prov_oma_compare_appl_napdef_napid(g_prov_app_brw_p);
            }
            else if (g_prov_appl_flag & PROV_MMS_APPLICATION)
            {
                i_ret = mmi_prov_oma_compare_appl_napdef_napid(g_prov_app_mms_p);
            }
            if (i_ret == PROV_ERR)
            {
                return i_ret;
            }
        }
        i_ret = mmi_prov_oma_get_physical_proxy_data(&tmp_physical_p->phyProxyData);
        return i_ret;
    }
    //    else if (count == 0x01)
    //    {
    //        i_ret = mmi_prov_oma_compare_phproxy_napdef_napid(&tmp_physical_p->phyProxyData);
    //                if(i_ret==PROV_ERR)
    //                {
    //                       return i_ret;
    //                } 
    //        i_ret=mmi_prov_oma_get_physical_proxy_data(&tmp_physical_p->phyProxyData);
    //        return i_ret;
    //    }
    //    else
    //    {
    //        do
    //        {
    //            if (count == 0x01)
    //            {
    //  /* select the first Physical proxy in the logical proxy */
    //                i_ret = mmi_prov_oma_compare_phproxy_napdef_napid(&tmp_physical_p->phyProxyData);
    //                              if(i_ret==PROV_ERR)
    //                              {
    //                                      return i_ret;
    //                              } 
    //                i_ret=mmi_prov_oma_get_physical_proxy_data(&tmp_physical_p->phyProxyData);
    //                return i_ret;
    //            }
    //            tmp_physical_p = tmp_physical_p->nextPhyProxy_p;
    //            --count;
    //        } while (tmp_physical_p != NULL);
    //    }
    //    return PROV_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_get_logical_proxy_data
 * DESCRIPTION
 *  This Fills up the profile struct info from the logical proxy data ,
 *  like profile name ,username ,password
 * PARAMETERS
 *  logProxy_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_get_logical_proxy_data(prov_log_proxy_data_struct *logProxy_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_profile_name_p == NULL)
    {
        g_prov_profile_name_p = (U8*) jdd_MemAlloc(PROV_PROFILE_PROFILE_NAME_LEN + 1, 1);
        strcpy((S8*) g_prov_profile_name_p, (S8*) logProxy_p->proxy_name);
    }

    if (g_prov_appl_flag & PROV_BROWSER_APPLICATION)
    {

        if (g_ph_cntx.ph_wap_profile_p == NULL)
        {
            g_ph_cntx.ph_wap_profile_p =
                (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
        }

        strcpy((S8*) g_ph_cntx.ph_wap_profile_p->username, (S8*) logProxy_p->px_auth_id);
        strcpy((S8*) g_ph_cntx.ph_wap_profile_p->password, (S8*) logProxy_p->px_auth_pwd);

        /* MAUI_00355388 Start */
        len = strlen((S8*) g_ph_cntx.ph_wap_profile_p->homepage_url);
        if (len == 0)   /* Homepage url is not updated thru application tag. so update with logProxy data */
        {
            mmi_prov_oma_update_wap_profile_homepage_url(logProxy_p->homepage_url);

        }
        /* MAUI_00355388 End */
    }
    else if (g_prov_appl_flag & PROV_MMS_APPLICATION)
    {
        if (g_ph_cntx.ph_mms_profile_p == NULL)
        {
            g_ph_cntx.ph_mms_profile_p =
                (nvram_mms_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE, 1);
        }
        strcpy((S8*) g_ph_cntx.ph_mms_profile_p->username, (S8*) logProxy_p->px_auth_id);
        strcpy((S8*) g_ph_cntx.ph_mms_profile_p->password, (S8*) logProxy_p->px_auth_pwd);

        /* MAUI_00355388 Start */
        len = strlen((S8*) g_ph_cntx.ph_mms_profile_p->mmsc_url);
        if (len == 0)   /* Mmsc url is not updated thru application tag. so update with logProxy data */
        {
            mmi_prov_oma_update_mms_profile_mmsc_url(logProxy_p->homepage_url);

        }
        /* MAUI_00355388 End */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_get_physical_proxy_data
 * DESCRIPTION
 *  This fills up the profile struct info from the physical proxy data ,
 *  like connection type ,port ,IP
 * PARAMETERS
 *  phy_Proxy_p     [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_get_physical_proxy_data(prov_phy_proxy_data_struct *phy_Proxy_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE i_ret = PROV_OK;
    PROV_RETCODE ret_code = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phy_Proxy_p->port >= PH_USHORT_MAX)
    {
        phy_Proxy_p->port = 0x00;
        phy_Proxy_p->port = 0x00;
    }
    else if ((phy_Proxy_p->port == 9200) || (phy_Proxy_p->port == 9202))
    {
        return PROV_ERR;        // PROV_ERR_UNSUPPORTED_SETTING;/*changes PROV*/
    }

    if (g_prov_appl_flag & PROV_BROWSER_APPLICATION)
    {
        if (g_ph_cntx.ph_wap_profile_p == NULL)
        {
            g_ph_cntx.ph_wap_profile_p =
                (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
        }

        g_ph_cntx.ph_wap_profile_p->proxy_port = phy_Proxy_p->port;
        g_ph_cntx.ph_wap_profile_p->conn_type = phy_Proxy_p->connType;

        if (g_ph_cntx.ph_wap_profile_p->proxy_port == 9201)
        {
            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED;

        }
        else if (g_ph_cntx.ph_wap_profile_p->proxy_port == 9203)
        {
            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;

        }
        else
        {
            /* default case */
            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_HTTP;
        }

        ret_code = mmi_prov_convert_ip_string_to_array(
                    (S8*) phy_Proxy_p->pxAddr,
                    (U8*) g_ph_cntx.ph_wap_profile_p->proxy_ip);
        if (ret_code == PROV_ERR)
        {
            memset(g_ph_cntx.ph_wap_profile_p->proxy_ip, 0, MAX_PART_IP_ADDRESS);
        }

    }
    else if (g_prov_appl_flag & PROV_MMS_APPLICATION)
    {
        if (g_ph_cntx.ph_mms_profile_p == NULL)
        {
            g_ph_cntx.ph_mms_profile_p =
                (nvram_mms_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE, 1);
        }

        g_ph_cntx.ph_mms_profile_p->proxy_port = phy_Proxy_p->port;
        g_ph_cntx.ph_mms_profile_p->conn_type = phy_Proxy_p->connType;

        if (g_ph_cntx.ph_mms_profile_p->proxy_port == 9201)
        {
            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED;

        }
        else if (g_ph_cntx.ph_mms_profile_p->proxy_port == 9203)
        {
            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;

        }
        else
        {
            /* default case */
            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_HTTP;
        }

        ret_code = mmi_prov_convert_ip_string_to_array(
                    (S8*) phy_Proxy_p->pxAddr,
                    (U8*) g_ph_cntx.ph_mms_profile_p->proxy_ip);
        if (ret_code == PROV_ERR)
        {
            memset(g_ph_cntx.ph_mms_profile_p->proxy_ip, 0, MAX_PART_IP_ADDRESS);
        }

    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_compare_phproxy_napdef_napid
 * DESCRIPTION
 *  THis compares the physical proxy Nap-Id with the Nap-ID's available with the NApdef data list
 * PARAMETERS
 *  phyProxyData_p      [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_compare_phproxy_napdef_napid(prov_phy_proxy_data_struct *phyProxyData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_napdef_struct *tmp_data_account_p = g_prov_napdef_data_p;
    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_dataAccountData_p == NULL)
    {
        g_prov_dataAccountData_p = jdd_MemAlloc(sizeof(prov_data_account_data_struct), 1);
    }

    do
    {
        if (strcmp((S8*) phyProxyData_p->toNapID, (S8*) tmp_data_account_p->accountData.napid) == 0)
        {
            //NOTE : what to do if no valid matching NAPDEF is there ?              
            //if not availbale this way get it from the Application data
            memcpy(g_prov_dataAccountData_p, &(tmp_data_account_p->accountData), sizeof(prov_data_account_data_struct));
            g_prov_bearer = g_prov_dataAccountData_p->bearer;
            return i_ret;

        }
        tmp_data_account_p = tmp_data_account_p->nextNapdef_p;
    } while (tmp_data_account_p != NULL);
    return PROV_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_compare_appl_napdef_napid
 * DESCRIPTION
 *  It compares the Nap-ID available with the application data & that in the Napdef data list
 * PARAMETERS
 *  appData_p       [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_oma_compare_appl_napdef_napid(application_data *appData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    prov_napdef_struct *tmp_data_account_p = g_prov_napdef_data_p;
    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_dataAccountData_p == NULL)
    {
        g_prov_dataAccountData_p = jdd_MemAlloc(sizeof(prov_data_account_data_struct), 1);
    }

    do
    {
        if (strcmp((S8*) appData_p->nap_id, (S8*) tmp_data_account_p->accountData.napid) == 0)
        {
            //NOTE : what to do if no valid matching NAPDEF is there ?              
            //if not availbale this way get it from the Application data
            memcpy(g_prov_dataAccountData_p, &(tmp_data_account_p->accountData), sizeof(prov_data_account_data_struct));
            g_prov_bearer = g_prov_dataAccountData_p->bearer;
            return i_ret;

        }
        tmp_data_account_p = tmp_data_account_p->nextNapdef_p;
    } while (tmp_data_account_p != NULL);
    return PROV_ERR;
}

#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_fill_gprs_data_account_info
 * DESCRIPTION
 *  This fills the data account info available into the set gprs req. struct
 * PARAMETERS
 *  dataAccountData_p       [IN]            
 *  set_gprs_req_p          [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_fill_gprs_data_account_info(
        prov_data_account_data_struct *dataAccountData_p,
        mmi_ps_set_gprs_data_account_req_struct **set_gprs_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen((S8*) dataAccountData_p->name);
    if (len >= PROV_MAX_GPRS_DATAACCOUNT_NAME)
    {
        len = PROV_MAX_GPRS_DATAACCOUNT_NAME - 1;
    }
    (*set_gprs_req_p)->gprs_account.name_dcs = PHB_ASCII;
    (*set_gprs_req_p)->gprs_account.name_length = len;

    memcpy((S8*) (*set_gprs_req_p)->gprs_account.name, (S8*) dataAccountData_p->name, len);
    (*set_gprs_req_p)->gprs_account.name[len] = '\0';

    len = strlen((S8*) dataAccountData_p->dataAccountType.gprsAccount.apn);
    if (len >= PROV_MAX_GPRS_MMI_APN_LEN)
    {
        len = PROV_MAX_GPRS_MMI_APN_LEN - 1;    /* modified by tk */
    }
    (*set_gprs_req_p)->gprs_account.apn_length = len;
    memcpy((S8*) (*set_gprs_req_p)->gprs_account.apn, dataAccountData_p->dataAccountType.gprsAccount.apn, len);
    (*set_gprs_req_p)->gprs_account.apn[len] = '\0';

    (*set_gprs_req_p)->gprs_account.authentication_type = dataAccountData_p->authType;

    len = strlen((S8*) dataAccountData_p->userName);
    if (len >= PROV_MAX_GPRS_USERNAME)
    {
        len = PROV_MAX_GPRS_USERNAME - 1;
    }
    memcpy((*set_gprs_req_p)->gprs_account.user_name, dataAccountData_p->userName, len);
    (*set_gprs_req_p)->gprs_account.user_name[len] = '\0';

    len = strlen((S8*) dataAccountData_p->password);
    if (len >= PROV_MAX_GPRS_USERPASSWD)
    {
        len = PROV_MAX_GPRS_USERPASSWD - 1;
    }
    memcpy((*set_gprs_req_p)->gprs_account.password, dataAccountData_p->password, len);
    (*set_gprs_req_p)->gprs_account.password[len] = '\0';
}
#endif /* __MMI_GPRS_FEATURES__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_fill_csd_data_account_info
 * DESCRIPTION
 *  It fills the data account info into the set csd profile req. structure
 * PARAMETERS
 *  dataAccountData_p       [IN]            
 *  set_csd_req_p           [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_fill_csd_data_account_info(
        prov_data_account_data_struct *dataAccountData_p,
        mmi_cc_set_csd_profile_req_struct **set_csd_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen((S8*) dataAccountData_p->name);
    if (len >= PROV_MAX_DATA_ACCOUNT_NAME_LEN)
    {
        len = PROV_MAX_DATA_ACCOUNT_NAME_LEN - 1;
    }

    memcpy((S8*) (*set_csd_req_p)->name.name, (S8*) dataAccountData_p->name, len);
    (*set_csd_req_p)->name.name[len] = '\0';

    (*set_csd_req_p)->name.name_dcs = PHB_ASCII;
    (*set_csd_req_p)->name.name_length = len;

    (*set_csd_req_p)->dest.type = dataAccountData_p->dataAccountType.csdAccount.csdDialNumType;

    len = strlen((S8*) dataAccountData_p->dataAccountType.csdAccount.csdDialString);
    if (len >= PROV_MAX_DIAL_NUM_LEN)
    {
        len = PROV_MAX_DIAL_NUM_LEN - 1;
    }
    memcpy(
        (S8*) ((*set_csd_req_p)->dest.number),
        (S8*) dataAccountData_p->dataAccountType.csdAccount.csdDialString,
        len);
    (*set_csd_req_p)->dest.number[len] = '\0';

    (*set_csd_req_p)->auth_type = dataAccountData_p->authType;

    len = strlen((S8*) dataAccountData_p->userName);
    if (len >= PROV_MAX_USER_LEN)
    {
        len = PROV_MAX_USER_LEN - 1;
    }
    memcpy((*set_csd_req_p)->user_id, dataAccountData_p->userName, len);
    (*set_csd_req_p)->user_id[len] = '\0';

    len = strlen((S8*) dataAccountData_p->password);
    if (len >= PROV_MAX_PASSWD_LEN)
    {
        len = PROV_MAX_PASSWD_LEN - 1;
    }
    memcpy((*set_csd_req_p)->passwd, dataAccountData_p->password, len);
    (*set_csd_req_p)->passwd[len] = '\0';

    memcpy((*set_csd_req_p)->dns, dataAccountData_p->dataAccountType.csdAccount.dns_ip, 4);

    (*set_csd_req_p)->type = dataAccountData_p->dataAccountType.csdAccount.callType;
    (*set_csd_req_p)->rate = dataAccountData_p->dataAccountType.csdAccount.linkSpeed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_free_napdef_info
 * DESCRIPTION
 *  Frees the data with Napdef data list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_free_napdef_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_prov_napdef_data_p != NULL)
    {
        jdd_MemFree(g_prov_napdef_data_p);
        g_prov_napdef_data_p = g_prov_napdef_data_p->nextNapdef_p;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_free_proxy_info
 * DESCRIPTION
 *  It frees memory with proxy data list(both logical & Physical)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_free_proxy_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_prov_proxy_data_p != NULL)
    {

        while (g_prov_proxy_data_p->logProxyData.physicalProxy != NULL)
        {

            jdd_MemFree(g_prov_proxy_data_p->logProxyData.physicalProxy);
            g_prov_proxy_data_p->logProxyData.physicalProxy =
                g_prov_proxy_data_p->logProxyData.physicalProxy->nextPhyProxy_p;
        }
        jdd_MemFree(g_prov_proxy_data_p);
        g_prov_proxy_data_p = g_prov_proxy_data_p->nextLogProxy_p;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_get_physical_proxy_count
 * DESCRIPTION
 *  This function counts the no of physical proxies with a particular logical proxy
 * PARAMETERS
 *  phyProxy_p      [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
U8 mmi_prov_oma_get_physical_proxy_count(prov_physical_proxy_struct *phyProxy_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0x00;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (phyProxy_p != NULL)
    {
        ++count;
        phyProxy_p = phyProxy_p->nextPhyProxy_p;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_get_logical_proxy_count
 * DESCRIPTION
 *  This function counts the no. of logical proxies
 * PARAMETERS
 *  logProxy_p      [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
U8 mmi_prov_oma_get_logical_proxy_count(prov_logical_proxy_struct *logProxy_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0x00;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (logProxy_p != NULL)
    {
        ++count;
        logProxy_p = logProxy_p->nextLogProxy_p;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_check_if_redundant_logical_proxy
 * DESCRIPTION
 *  This function checks if the logical proxy is an redundant one,ie already defined
 * PARAMETERS
 *  logProxy_p          [IN]        
 *  logProxyData_p      [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
U8 mmi_prov_oma_check_if_redundant_logical_proxy(
    prov_logical_proxy_struct *logProxy_p,
    prov_log_proxy_data_struct *logProxyData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (logProxy_p != NULL)
    {

        if (strcmp((S8*) logProxyData_p->proxy_id, (S8*) logProxy_p->logProxyData.proxy_id) == 0)
        {
            return 0x01;
        }

        logProxy_p = logProxy_p->nextLogProxy_p;
    }
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_check_if_redundant_physical_proxy
 * DESCRIPTION
 *  This function checks if the physical proxy is an redundant one,ie already defined
 * PARAMETERS
 *  phyProxy_p          [IN]        
 *  phyProxyData_p      [IN]        
 * RETURNS
 *  TRUE if its redundant
 *****************************************************************************/
U8 mmi_prov_oma_check_if_redundant_physical_proxy(
    prov_physical_proxy_struct *phyProxy_p,
    prov_phy_proxy_data_struct *phyProxyData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (phyProxy_p != NULL)
    {

        if (strcmp((S8*) phyProxyData_p->physicalProxyID, (S8*) phyProxy_p->phyProxyData.physicalProxyID) == 0)
        {
            return 0x01;
        }

        phyProxy_p = phyProxy_p->nextPhyProxy_p;
    }
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_check_if_redundant_napdef
 * DESCRIPTION
 *  This function checks if the NAP defination is an redundant one,ie already defined
 * PARAMETERS
 *  napdef_data_p       [IN]        
 *  accountData_p       [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
U8 mmi_prov_oma_check_if_redundant_napdef(
    prov_napdef_struct *napdef_data_p,
    prov_data_account_data_struct *accountData_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (napdef_data_p != NULL)
    {

        if (strcmp((S8*) napdef_data_p->accountData.napid, (S8*) accountData_p->napid) == 0)
        {
            return 0x01;
        }
        napdef_data_p = napdef_data_p->nextNapdef_p;
    }

    if ((accountData_p->bearer == PROV_GPRS_BEARER) || (accountData_p->bearer == PROV_CSD_BEARER))
    {
        return 0;
    }
    else
    {
        /* Do not store the NAPDEF without the supported bearer */
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_entry_enter_pin
 * DESCRIPTION
 *  Entry fn to get PIN from user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_entry_enter_pin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;   /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROV_OMA_ENTER_PIN, mmi_prov_oma_exit_enter_pin, NULL, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROV_OMA_ENTER_PIN);
    inputBuffer = GetCurrInputBuffer(SCR_ID_PROV_OMA_ENTER_PIN);

    if (inputBuffer == NULL)
    {
        memset(g_prov_password, 0, (PROV_OMA_MAX_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) g_prov_password, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(mmi_prov_oma_pin_length_validation);
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_ID_PROV_ENTER_PIN_CAPTION,
        INPUT_TYPE_NUMERIC_PASSWORD,
        g_prov_password,
        (PROV_OMA_MAX_PASSWD_LEN + 1),
        NULL,
        gui_buffer_p);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_prov_oma_validate_entered_pin, KEY_EVENT_UP);
    SetKeyHandler(mmi_prov_oma_validate_entered_pin, KEY_POUND, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_exit_enter_pin
 * DESCRIPTION
 *  Exit handler for the OMA Enter Pin screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_exit_enter_pin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_PROV_OMA_ENTER_PIN;
    Scr.entryFuncPtr = mmi_prov_oma_entry_enter_pin;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) g_prov_password);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_pin_length_validation
 * DESCRIPTION
 *  It checks if the Min. required PIN digits are been entered or not
 * PARAMETERS
 *  text_p          [IN]        
 *  cursor_p        [IN]        
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_pin_length_validation(U8 *text_p, U8 *cursor_p, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < PROV_OMA_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(mmi_prov_oma_validate_entered_pin, KEY_POUND, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_validate_entered_pin
 * DESCRIPTION
 *  This API will validate the PIN entered by the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_validate_entered_pin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8 HMAC_value[41]; */

    /* this API will */

    /* take         gSecuritySetupContext.Password   & the  Prov Doc & give it to the HMAC calculation algo SHA-1 */

    //HMAC_value=certicomHMAC(g_prov_password,prov_buff_p);
    //Now compare with teh HMAC received in the DOc

    /* if the password entered is correct */
    mmi_prov_oma_save_received_settings(g_prov_oma_buff_p, g_prov_oma_buff_len);
    //display popup for the authentication done 
    //      g_prov_settings_present=0x01;
    //      DisplayPopup ((PU8)GetString(STR_ID_PROV_AUTHENTICATION_PASSED), IMG_ID_PROV_AUTHENTICATION_PASSED, 1, PROV_AUTHENTICATION_DONE_TIMEOUT,0);
    //      DeleteUptoScrID(IDLE_SCREEN_ID);

    //else if password entered is not ok
    //      DisplayPopup ((PU8)GetString(STR_ID_PROV_WRONG_PIN_ENTERED), IMG_ID_PROV_WRONG_PIN_ENTERED, 1, PROV_WRONG_PIN_ENTERED_TIMEOUT,0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_get_imsi_req
 * DESCRIPTION
 *  To send message MSG_ID_MMI_SMU_GET_IMSI_REQ
 *  in response of this message imsi field is returned
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_get_imsi_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_prov_oma_get_imsi_rsp, PRT_GET_IMSI_RSP);

    PRINT_INFORMATION("@@@@@ Request To get the IMSI  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_GET_IMSI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_get_imsi_rsp
 * DESCRIPTION
 *  This handles the imsi response returned by L4
 * PARAMETERS
 *  msg_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_get_imsi_rsp(void *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_imsi_rsp_struct *local_data_p = (mmi_smu_get_imsi_rsp_struct*) msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside RspToTestRoamingEnabled");

    if (local_data_p->result == ST_SUCCESS)
    {
        /* store the IMSI obtained */
        g_prov_imsi_p = jdd_MemAlloc(17, 1);    /* check the size */

        strcpy((S8*) g_prov_imsi_p, (S8*) local_data_p->imsi);
        //call the certicom HMAC alogo
        //compare the MAC value returned with teh one  stored from doc g_prov_MAC_value_p.......
    }
    /* if HMAC matches */
    mmi_prov_oma_save_received_settings(g_prov_oma_buff_p, g_prov_oma_buff_len);
}

/* MAUI_00355388 Added */


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_update_wap_profile_homepage_url
 * DESCRIPTION
 *  To update homepage url of WAP profile
 * PARAMETERS
 *  uri     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_update_wap_profile_homepage_url(JC_UINT8 *uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen((S8*) uri);
    if (len >= PROV_PROFILE_HOMEPAGE_URL_LEN)
    {
        len = PROV_PROFILE_HOMEPAGE_URL_LEN - 1;
    }

    if (jdi_isValidUrl((JC_UINT8*) uri))
    {
        strcpy((S8*) g_ph_cntx.ph_wap_profile_p->homepage_url, (S8*) uri);
        g_ph_cntx.ph_wap_profile_p->homepage_url[len] = '\0';

        if (mmi_prov_check_if_substring((PS8) g_ph_cntx.ph_wap_profile_p->homepage_url, (PS8) "http://") != 0x00)
        {
            S8 homepage[PROV_PROFILE_HOMEPAGE_URL_LEN + 10] = "http://";

            strcat(homepage, (PS8) g_ph_cntx.ph_wap_profile_p->homepage_url);
            memset(g_ph_cntx.ph_wap_profile_p->homepage_url, 0, PROV_PROFILE_HOMEPAGE_URL_LEN);
            len = strlen(homepage);
            if (len >= PROV_PROFILE_HOMEPAGE_URL_LEN)
            {
                len = PROV_PROFILE_HOMEPAGE_URL_LEN - 1;
            }
            memcpy(g_ph_cntx.ph_wap_profile_p->homepage_url, homepage, len);
            g_ph_cntx.ph_wap_profile_p->homepage_url[len] = '\0';
        }
    }
    else
    {
        S8 *default_url = "http://";

        memset(g_ph_cntx.ph_wap_profile_p->homepage_url, 0, PROV_PROFILE_HOMEPAGE_URL_LEN);
        strcpy((PS8) g_ph_cntx.ph_wap_profile_p->homepage_url, default_url);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_update_mms_profile_mmsc_url
 * DESCRIPTION
 *  To update mmsc url of MMS profile
 * PARAMETERS
 *  uri     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_oma_update_mms_profile_mmsc_url(JC_UINT8 *uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen((S8*) uri);
    if (len >= PROV_PROFILE_MMSC_URL_LEN)
    {
        len = PROV_PROFILE_MMSC_URL_LEN - 1;
    }

    if (jdi_isValidUrl((JC_UINT8*) uri))
    {
        strcpy((S8*) g_ph_cntx.ph_mms_profile_p->mmsc_url, (S8*) uri);
        g_ph_cntx.ph_mms_profile_p->mmsc_url[len] = '\0';

        if (mmi_prov_check_if_substring((PS8) g_ph_cntx.ph_mms_profile_p->mmsc_url, (PS8) "http://") != 0x00)
        {
            S8 homepage[PROV_PROFILE_MMSC_URL_LEN + 10] = "http://";

            strcat(homepage, (PS8) g_ph_cntx.ph_mms_profile_p->mmsc_url);
            memset(g_ph_cntx.ph_mms_profile_p->mmsc_url, 0, PROV_PROFILE_MMSC_URL_LEN);
            len = strlen(homepage);
            if (len >= PROV_PROFILE_MMSC_URL_LEN)
            {
                len = PROV_PROFILE_MMSC_URL_LEN - 1;
            }
            memcpy(g_ph_cntx.ph_mms_profile_p->mmsc_url, homepage, len);
            g_ph_cntx.ph_mms_profile_p->mmsc_url[len] = '\0';
        }
    }
    else
    {
        S8 *default_url = "http://";

        memset(g_ph_cntx.ph_mms_profile_p->mmsc_url, 0, PROV_PROFILE_MMSC_URL_LEN);
        strcpy((PS8) g_ph_cntx.ph_mms_profile_p->mmsc_url, default_url);
    }
}

/* MAUI_00355388 End */

#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 
#endif /* _JPROVOMA_C */ 

