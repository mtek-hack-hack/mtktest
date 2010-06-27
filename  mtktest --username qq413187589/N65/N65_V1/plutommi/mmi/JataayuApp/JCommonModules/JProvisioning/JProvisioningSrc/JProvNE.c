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
 * JProvNE.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file intends for nokia\ericsson OTA settings.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _JPROVNE_C
#define _JPROVNE_C

#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
#include <ddl.h>
#ifndef __MMI_JATAAYU_CCA_SUPPORT__

#include "JProvWap.h"
#include "JProvNE.h"
#include "JProfileHandlerTypes.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMIGprots.h"

extern pBOOL GetUCS2Flag(PS8 buffer);
extern BOOL mmi_phb_op_check_valid_number(S8 *number);
extern PROV_RETCODE mmi_brw_add_prov_bookmark(U8 *, U8 *);

const characteristic_tag_handler_struct NE_tag_handler_map[PROV_NE_CHARACTERISTIC_NUM] = 
{
    "ADDRESS", mmi_prov_NE_handle_address_tag,
    "URL", mmi_prov_NE_handle_url_tag,
    "NAME", mmi_prov_NE_handle_name_tag,
    "BOOKMARK", mmi_prov_NE_handle_bookmark_tag,
    "MMSURL", mmi_prov_NE_handle_mmsurl_tag,
    "ID", mmi_prov_NE_handle_id_tag
};


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_handle_settings
 * DESCRIPTION
 *  Add's the prov. into the queue & if the queue size is 1 show new settings popup
 * PARAMETERS
 *  prov_buffer_p       [IN]        Prov. data buffer
 *  prov_length         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_NE_handle_settings(S8 *prov_buffer_p, U32 prov_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_add_to_queue(prov_buffer_p, prov_length);

    //   if (g_prov_data_queue_size == 1)
    //  {
    mmi_prov_show_new_settings_popup();
    /* } */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_insert_settings_parm
 * DESCRIPTION
 *  This API check out for the xml tags one by one and calls the respective handlers for the various characteristcs
 *  tags encountered
 * PARAMETERS
 *  root_p      [IN]        Root tag
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_NE_insert_settings_parm(TAG *root_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    U32 map_array_index;
    S8 characteristic_element[PROV_MIN_SIZE_REQ + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = root_p->next;

    while (root_p->next != NULL || root_p->attribute_list != NULL)
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
                for (map_array_index = 0; map_array_index < PROV_NE_CHARACTERISTIC_NUM; ++map_array_index)
                {
                    mmi_ucs2_to_asc(characteristic_element, (S8*) attr_p->value);
                    if (strcmp(characteristic_element, NE_tag_handler_map[map_array_index].characteristic_tags) == 0)
                    {
                        i_ret = NE_tag_handler_map[map_array_index].characteristic_tag_hdlr(&root_p);
                        if (i_ret == PROV_ERR)
                        {
                            return i_ret;
                        }
                        break;
                    }

                }
                /* MAUI_00555503 starts */
            }
            else
            {
                root_p = root_p->next;
            }
            /* MAUI_00555503 ends */
            if (root_p == NULL)
            {
                return i_ret;
            }
        }
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_handle_address_tag
 * DESCRIPTION
 *  ADDRESS characteristic tag obtained in the NE OTA settings is handled
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_NE_handle_address_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_MIN_SIZE_REQ + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_HTTP;
    g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_HTTP;

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
                if (strcmp(parm_element, BEARER) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        if (strcmp(parm_element, GPRS) == 0)
                        {
                            g_prov_bearer = PROV_GPRS_BEARER;
                        }
                        else if (strcmp(parm_element, GSMCSD) == 0)
                        {
                            g_prov_bearer = PROV_CSD_BEARER;
                            if (g_prov_set_csd_req_p)
                            {
                                g_prov_set_csd_req_p->rate = CSD_PROF_RATE_9600;        /* Default Value *//* added by tk */
                            }

                        }

                    }

                }
                else if (strcmp(parm_element, PROXY) == 0)
                {

                    attr_p = attr_p->next;
                    mmi_prov_handle_proxy_ip(attr_p);

                }

                else if (strcmp(parm_element, PROXY_AUTHNAME) == 0)
                {

                    attr_p = attr_p->next;
                    mmi_prov_NE_handle_proxy_authname(attr_p);

                }
                else if (strcmp(parm_element, PROXY_AUTHSECRET) == 0)
                {

                    attr_p = attr_p->next;
                    mmi_prov_NE_handle_proxy_authsecret(attr_p);

                }
                else if (strcmp(parm_element, PROXY_LOGINTYPE) == 0)
                {

                    attr_p = attr_p->next;

                }

                else if (strcmp(parm_element, CSD_DIALSTRING) == 0)
                {
                    attr_p = attr_p->next;
                    if (g_prov_bearer == PROV_CSD_BEARER)
                    {
                        mmi_prov_NE_handle_csd_dialstring(attr_p);
                    }
                }

                else if (strcmp(parm_element, PPP_AUTHTYPE) == 0)
                {
                    attr_p = attr_p->next;
                    mmi_prov_handle_nap_auth_type(attr_p);
                }
                else if (strcmp(parm_element, PPP_AUTHNAME) == 0)
                {

                    attr_p = attr_p->next;
                    mmi_prov_handle_nap_auth_name(attr_p);
                }
                else if (strcmp(parm_element, PPP_AUTHSECRET) == 0)
                {
                    attr_p = attr_p->next;
                    mmi_prov_handle_nap_auth_pw(attr_p);

                }

                else if (strcmp(parm_element, GPRS_ACCESSPOINTNAME) == 0)
                {
                    attr_p = attr_p->next;
                    if (g_prov_bearer == PROV_GPRS_BEARER)
                    {
                        mmi_prov_NE_handle_gprs_apn(attr_p);
                    }
                }
                else if (strcmp(parm_element, PORT) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        U32 proxy_port = 0;

                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

                        proxy_port = atoi(parm_element);

                        if (proxy_port < PH_USHORT_MAX)
                        {
                            g_ph_cntx.ph_wap_profile_p->proxy_port = proxy_port;
                            g_ph_cntx.ph_mms_profile_p->proxy_port = proxy_port;
                        }
                        else if (proxy_port >= PH_USHORT_MAX)
                        {
                            g_ph_cntx.ph_wap_profile_p->proxy_port = 0x00;
                            g_ph_cntx.ph_mms_profile_p->proxy_port = 0x00;
                        }

                        if (strcmp(parm_element, "9201") == 0)
                        {
                            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED;
                            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED;
                        }
                        else if (strcmp(parm_element, "9203") == 0)
                        {
                            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;
                            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;
                        }
                        else if ((strcmp(parm_element, "9200") == 0) || (strcmp(parm_element, "9202") == 0))
                        {
                            return PROV_ERR;    // PROV_ERR_UNSUPPORTED_SETTING;/*changes PROV*/
                        }
                        else
                        {
                            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_HTTP;
                            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_HTTP;
                        }
                    }

                }
                else if (strcmp(parm_element, CSD_CALLSPEED) == 0)
                {
                    attr_p = attr_p->next;
                    if (g_prov_bearer == PROV_CSD_BEARER)
                    {
                        mmi_prov_NE_handle_csd_callspeed(attr_p);
                    }

                }
                else if (strcmp(parm_element, CSD_CALLTYPE) == 0)
                {
                    attr_p = attr_p->next;
                    if (g_prov_bearer == PROV_CSD_BEARER)
                    {
                        mmi_prov_NE_handle_csd_calltype(attr_p);
                    }
                }

                else if (strcmp(parm_element, ISP_NAME) == 0)
                {

                    attr_p = attr_p->next;
                    mmi_prov_handle_profile_name(attr_p);

                }
            }
        }

        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
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
 *  mmi_prov_NE_handle_url_tag
 * DESCRIPTION
 *  URL characteristic tag obtained in the NE OTA settings is handled
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  void
 *****************************************************************************/
PROV_RETCODE mmi_prov_NE_handle_url_tag(TAG **nextroot_p)
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
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {

        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            /*          if (strcmp(attr_p->name, TYPE) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, TYPE) == 0)) /* MAUI_00555503 */
            {
                attr_p = attr_p->next;
                mmi_prov_handle_homepage_url(attr_p);
            }
        }

        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            *nextroot_p = root_p;
            return i_ret;
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
 *  mmi_prov_NE_handle_name_tag
 * DESCRIPTION
 *  NAME characteristic tag obtained in the NE OTA settings is handled
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  void
 *****************************************************************************/
PROV_RETCODE mmi_prov_NE_handle_name_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_PROFILE_PROFILE_NAME_LEN + 1];

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
                    mmi_prov_handle_profile_name(attr_p);
                }
            }
        }

        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
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
 *  mmi_prov_NE_handle_bookmark_tag
 * DESCRIPTION
 *  BOOKMARK characteristic tag obtained in the NE OTA settings is handled
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_NE_handle_bookmark_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_MIN_SIZE_REQ + 1];
    U8 bkm_title_p[PROV_BKM_TITLE_LEN * ENCODING_LENGTH] = {0, };
    U8 bkm_url_p[PROV_BKM_URL_LEN * ENCODING_LENGTH] = {0, };
    U32 valid_bookmark = 0;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_NE_handle_bookmark_tag");
    /* to handle the case when only bookmarks are received */
    if (g_prov_bearer == PROV_INVALID_BEARER)
    {
        g_prov_setting_type |= PROV_BOOKMARK_SETTINGS;
        i_ret = PROV_BKM_INVALID;
    }

    root_p = *nextroot_p;
    root_p = root_p->next;
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {
        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            *nextroot_p = root_p;
            if (valid_bookmark)
            {
                PRINT_INFORMATION("Inside mmi_prov_NE_handle_bookmark_tag - Add Bookmark");
                i_ret = mmi_brw_add_prov_bookmark(bkm_title_p, bkm_url_p);
            }
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
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_BKM_TITLE_LEN)
                        {
                            len = PROV_BKM_TITLE_LEN - 1;
                        }
                        mmi_ucs2ncpy((S8*) bkm_title_p, (S8*) attr_p->value, len);
                    }

                }
                else if (strcmp(parm_element, URL) == 0)
                {
                    attr_p = attr_p->next;
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        len = mmi_ucs2strlen((S8*) attr_p->value);
                        if (len >= PROV_BKM_URL_LEN)
                        {
                            len = PROV_BKM_URL_LEN - 1;
                        }
                        mmi_ucs2ncpy((S8*) bkm_url_p, (S8*) attr_p->value, len);
                        valid_bookmark = 0x01;
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
                if (valid_bookmark)
                {
                    PRINT_INFORMATION("Inside mmi_prov_NE_handle_bookmark_tag - Add Bookmark");
                    i_ret = mmi_brw_add_prov_bookmark(bkm_title_p, bkm_url_p);
                }
                *nextroot_p = root_p;
                return i_ret;
            }
        }
        else
        {
            *nextroot_p = root_p;

            if (valid_bookmark)
            {
                i_ret = mmi_brw_add_prov_bookmark(bkm_title_p, bkm_url_p);
            }
            return i_ret;
        }
    }
    if (valid_bookmark)
    {
        i_ret = mmi_brw_add_prov_bookmark(bkm_title_p, bkm_url_p);
    }
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_handle_mmsurl_tag
 * DESCRIPTION
 *  MMSCURL characteristic tag obtained in the NE OTA settings is handled
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_NE_handle_mmsurl_tag(TAG **nextroot_p)
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
    attr_p = root_p->attribute_list;

    while (root_p != NULL)
    {
        if (strcmp(root_p->name, CHARACTERISTIC) == 0)
        {
            /*          if (strcmp(attr_p->name, TYPE) == 0) MAUI_00555503 */
            if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, TYPE) == 0)) /* MAUI_00555503 */
            {
                attr_p = attr_p->next;
                mmi_prov_handle_mmsc_url(attr_p);
                g_prov_setting_type |= PROV_MMS_SETTINGS;
                g_prov_setting_type &= ~PROV_BRS_SETTINGS;
            }
        }
        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
            *nextroot_p = root_p;
            return i_ret;
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
 *  mmi_prov_NE_handle_id_tag
 * DESCRIPTION
 *  ID characteristic tag obtained in the NE OTA settings is handled
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_NE_handle_id_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_RETCODE i_ret = PROV_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 parm_element[PROV_MIN_SIZE_REQ + 1];

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
                    /*                    if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
                    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
                    {
                        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
                        /* Note : dara check if we need to support this */
                    }
                }
            }
        }

        root_p = root_p->next;
        if (root_p != NULL)
        {
            attr_p = root_p->attribute_list;
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
 *  mmi_prov_NE_handle_csd_calltype
 * DESCRIPTION
 *  This function handles CSD calll type parm received in the Nokia settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_NE_handle_csd_calltype(ATTRIBUTE *attr_p)
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
        if (strcmp(parm_element, ANALOGUE) == 0)
        {
            g_prov_set_csd_req_p->type = CSMCC_ITC_3_1_K_AUDIO;
        }
        else if (strcmp(parm_element, "ISDN") == 0)
        {
            g_prov_set_csd_req_p->type = CSMCC_ITC_UDI;
        }
        else
        {
            g_prov_set_csd_req_p->type = CSMCC_ITC_3_1_K_AUDIO;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_handle_csd_callspeed
 * DESCRIPTION
 *  This function handles CSD call speed parameter received in the OMA settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_NE_handle_csd_callspeed(ATTRIBUTE *attr_p)
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

        if (strcmp(parm_element, AUTO) == 0 || strcmp(parm_element, "9600") == 0)
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
 *  mmi_prov_NE_handle_proxy_authname
 * DESCRIPTION
 *  This function handles CSD call speed parameter received in the OMA settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_NE_handle_proxy_authname(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        len = mmi_ucs2strlen((S8*) attr_p->value);
        if (len >= PROV_PROFILE_USERNAME_LEN)
        {
            len = PROV_PROFILE_USERNAME_LEN - 1;
        }
        if (GetUCS2Flag((PS8) attr_p->value))
        {
            memset(g_ph_cntx.ph_wap_profile_p->username, 0, PROV_PROFILE_USERNAME_LEN);
            memset(g_ph_cntx.ph_mms_profile_p->username, 0, PROV_PROFILE_USERNAME_LEN);
        }
        mmi_ucs2_n_to_asc((S8*) g_ph_cntx.ph_wap_profile_p->username, (S8*) attr_p->value, len * ENCODING_LENGTH);
        g_ph_cntx.ph_wap_profile_p->username[len] = '\0';
        mmi_ucs2_n_to_asc((S8*) g_ph_cntx.ph_mms_profile_p->username, (S8*) attr_p->value, len * ENCODING_LENGTH);
        g_ph_cntx.ph_mms_profile_p->username[len] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_handle_proxy_authsecret
 * DESCRIPTION
 *  This function handles CSD call speed parameter received in the OMA settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_NE_handle_proxy_authsecret(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        len = mmi_ucs2strlen((S8*) attr_p->value);
        if (len >= PROV_PROFILE_PASSWORD_LEN)
        {
            len = PROV_PROFILE_PASSWORD_LEN - 1;
        }
        if (GetUCS2Flag((PS8) attr_p->value))
        {
            memset(g_ph_cntx.ph_wap_profile_p->password, 0, PROV_PROFILE_PASSWORD_LEN);
            memset(g_ph_cntx.ph_mms_profile_p->password, 0, PROV_PROFILE_PASSWORD_LEN);
        }
        mmi_ucs2_n_to_asc((S8*) g_ph_cntx.ph_wap_profile_p->password, (S8*) attr_p->value, len * ENCODING_LENGTH);
        g_ph_cntx.ph_wap_profile_p->password[len] = '\0';
        mmi_ucs2_n_to_asc((S8*) g_ph_cntx.ph_mms_profile_p->password, (S8*) attr_p->value, len * ENCODING_LENGTH);
        g_ph_cntx.ph_mms_profile_p->password[len] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_handle_csd_dialstring
 * DESCRIPTION
 *  This function handles CSD dail string parameter received in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_NE_handle_csd_dialstring(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        len = mmi_ucs2strlen((S8*) attr_p->value);

        if (g_prov_set_csd_req_p != NULL)
        {
            if (len >= PROV_MAX_DIAL_NUM_LEN)
            {
                len = PROV_MAX_DIAL_NUM_LEN - 1;
            }

            if (mmi_phb_op_check_valid_number((S8*) attr_p->value))
            {
                mmi_ucs2_n_to_asc((S8*) g_prov_set_csd_req_p->dest.number, (S8*) attr_p->value, len * ENCODING_LENGTH);
                g_prov_set_csd_req_p->dest.number[len] = '\0';
                g_prov_set_csd_req_p->dest.type = CSMCC_DEFAULT_ADDR_TYPE;
            }
            else
            {
                memset(g_prov_set_csd_req_p->dest.number, 0, MAX_DIAL_NUM_LEN);
                g_prov_set_csd_req_p->dest.type = CSMCC_DEFAULT_ADDR_TYPE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_handle_gprs_apn
 * DESCRIPTION
 *  This function handles GPRS APN parameter received for the GPRS bearer in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_NE_handle_gprs_apn(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        len = mmi_ucs2strlen((S8*) attr_p->value);
    #ifdef __MMI_GPRS_FEATURES__
        if (g_prov_set_gprs_req_p != NULL)
        {

            if (len >= PROV_MAX_GPRS_MMI_APN_LEN)
            {
                len = PROV_MAX_GPRS_MMI_APN_LEN - 1;
            }
            g_prov_set_gprs_req_p->gprs_account.apn_length = len;
            mmi_ucs2_n_to_asc(
                (S8*) g_prov_set_gprs_req_p->gprs_account.apn,
                (S8*) attr_p->value,
                len * ENCODING_LENGTH);
            g_prov_set_gprs_req_p->gprs_account.apn[len] = '\0';
        }
    #endif /* __MMI_GPRS_FEATURES__ */ 
    }
}

/* temp function shall be removed once jattayu provides */


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_NE_handle_WSP_headers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prov_buffer_p       [IN]        
 *  provLength          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_NE_handle_WSP_headers(U8 **prov_buffer_p, U32 *provLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buffLen;
    U8 *tempBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tempBuffer = *prov_buffer_p;

    if (tempBuffer[1] == WSP_PUSH_HEADER)
    {
        buffLen = tempBuffer[2];
        tempBuffer += 3;
        *provLength -= 3;
        tempBuffer += buffLen;
        *provLength -= buffLen;
        memcpy(*prov_buffer_p, tempBuffer, (*provLength));
    }
}

#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 

#endif /* _JPROVNE_C */ 

