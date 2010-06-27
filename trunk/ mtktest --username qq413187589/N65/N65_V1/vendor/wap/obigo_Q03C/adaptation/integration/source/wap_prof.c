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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * wap_prof.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for wap profile access function.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#define _FILE_CODE_  _WAP_PROF_C_

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */
#include "app_buff_alloc.h"

#include "stdio.h"
#include "stdlib.h"

#include "msf_chrs.h"
#include "msm_int.h"
#include "msm_env.h"
#include "bra_prof.h"
#include "bra_bkm.h"
#include "bra_set.h"
#include "wapadp.h"
#include "widget_extension.h"
#include "wap_ps_struct.h"
#include "wap2l4c_struct.h"

typedef enum
{
    WAP_OK,
    WAP_OK_VAL,
    WAP_ERR,
    WAP_ERR_VAL
} wap_prof_access_rlt_enum;

typedef struct wap_prof_access_struct
{
    kal_uint8 src_id;
    wap_prof_access_req_struct *access_req_ptr;

} wap_prof_access_struct;

wap_prof_access_struct wap_prof_access;

extern int msf_mod_status[MSF_NUMBER_OF_MODULES];


/*****************************************************************************
 * FUNCTION
 *  wap_prof_access_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wap_prof_access_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_prof_access.src_id = ilm_ptr->src_mod_id;
    wap_prof_access.access_req_ptr = (wap_prof_access_req_struct*) ilm_ptr->local_para_ptr;
    hold_local_para(ilm_ptr->local_para_ptr);
    MSMc_registryGet(0, "/BRA", "prof_id");
}


/*****************************************************************************
 * FUNCTION
 *  wap_send_prof_access_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_access_ptr     [?]         
 *  result              [IN]        
 *  ret_val             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_prof_access_cnf(wap_prof_access_struct *prof_access_ptr, int result, char *ret_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cwap_prof_access_cnf_struct *access_cnf_ptr;
    ilm_struct *ilm_ptr = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_uint16 len = (kal_uint16) 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    access_cnf_ptr = (l4cwap_prof_access_cnf_struct*)
        construct_local_para((kal_uint16) sizeof(l4cwap_prof_access_cnf_struct), TD_CTRL);

    access_cnf_ptr->src_id = prof_access_ptr->src_id;
    access_cnf_ptr->query = prof_access_ptr->access_req_ptr->query;
    access_cnf_ptr->cmd = prof_access_ptr->access_req_ptr->cmd;
    access_cnf_ptr->result = result;

    if (ret_val)
    {
        kal_uint16 pdulen = strlen((const char*)ret_val);

        peer_buff_ptr = construct_peer_buff(pdulen, 0, 0, TD_CTRL);
        kal_mem_cpy(get_pdu_ptr(peer_buff_ptr, &len), ret_val, pdulen);
    }

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) access_cnf_ptr;
    ilm_ptr->msg_id = MSG_ID_L4CWAP_PROF_ACCESS_CNF;
    ilm_ptr->peer_buff_ptr = peer_buff_ptr;
SEND_ILM(MOD_WAP, prof_access_ptr->src_id, WAP_MMI_SAP, ilm_ptr)}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewil_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewil_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char on = 0;
    char n_ask[20];
    char n_load[20];
    char *i, *j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(n_ask, 0, 20);
    memset(n_load, 0, 20);

    if (access_ptr->cmd == WAP_PROF_SET)
    {
        /* check if specified profile ID is valid */
        if (access_ptr->param[0][0] == '0')
        {
            on = 0;
        }
        else if (access_ptr->param[0][0] == '1')
        {
            on = 1;
        }
        else
        {
            return WAP_ERR;
        }
    }

    if (msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED)
    {
        char *ask;
        char *load;

        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                load = bra_prof_get_key_str_value(1, "obj_load");
                ask = bra_prof_get_key_str_value(1, "obj_ask");
                if (load == NULL || ask == NULL)
                {
                    return WAP_ERR;
                }
                if (on)
                {
                    if (!strstr((const char*)load, "image/*"))
                    {
                        /* append "image\*" to obj_load */
                        sprintf(n_load, "%s,%s", load, "image/*");
                    }
                }
                else
                {
                    i = strstr((const char*)load, "image/*");
                    if (i)
                    {
                        /* remove "image\*" to obj_load */
                        if (i == load)
                        {
                            j = strchr(i, ',');
                            if (j)
                            {
                                sprintf(n_load, "%s", j + 1);
                            }
                        }
                        else
                        {
                            int len = i - load;

                            strncpy(n_load, load, len - 1);
                            j = strchr(i, ',');
                            if (j)
                            {
                                sprintf(n_load + len, "%s", j);
                            }
                        }
                    }
                }
                i = strstr((const char*)ask, "image/*");
                if (i)
                {
                    /* remove "image\*" to obj_ask */
                    if (i == ask)
                    {
                        j = strchr(i, ',');
                        if (j)
                        {
                            sprintf(n_ask, "%s", j + 1);
                        }
                    }
                    else
                    {
                        int len = i - ask;

                        strncpy(n_ask, ask, len - 1);
                        j = strchr(i, ',');
                        if (j)
                        {
                            sprintf(n_ask + len, "%s", j);
                        }
                    }
                }
                bra_prof_change_key_str_value(1, "obj_load", NULL, NULL);
                bra_prof_change_key_str_value(1, "obj_ask", NULL, NULL);
                return WAP_OK;
            case WAP_PROF_READ:
                load = bra_prof_get_key_str_value(1, "obj_load");
                if (load == NULL)
                {
                    return WAP_ERR;
                }
                else if (strstr(load, "image/*"))
                {
                    sprintf(val, "1");
                }
                else
                {
                    sprintf(val, "0");
                }
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "0,1");
                return WAP_OK_VAL;
        }
    }
    else
    {
        char load[20];
        char ask[20];

        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                if (!bra_prof_off_line_read_profile_key(prof_id, "obj_load", load)
                    || !bra_prof_off_line_read_profile_key(prof_id, "obj_ask", ask))
                {
                    return WAP_ERR;
                }
                if (on)
                {
                    if (!strstr((const char*)load, "image/*"))
                    {
                        /* append "image\*" to obj_load */
                        sprintf(n_load, "%s,%s", load, "image/*");
                    }
                }
                else
                {
                    i = strstr((const char*)load, "image/*");
                    if (i)
                    {
                        /* remove "image\*" to obj_load */
                        if (i == load)
                        {
                            j = strchr(i, ',');
                            if (j)
                            {
                                sprintf(n_load, "%s", j + 1);
                            }
                        }
                        else
                        {
                            int len = i - load;

                            strncpy(n_load, load, len - 1);
                            j = strchr(i, ',');
                            if (j)
                            {
                                sprintf(n_load + len, "%s", j);
                            }
                        }
                    }
                }
                i = strstr((const char*)ask, "image/*");
                if (i)
                {
                    /* remove "image\*" to obj_ask */
                    if (i == ask)
                    {
                        j = strchr(i, ',');
                        if (j)
                        {
                            sprintf(n_ask, "%s", j + 1);
                        }
                    }
                    else
                    {
                        int len = i - ask;

                        strncpy(n_ask, ask, len - 1);
                        j = strchr(i, ',');
                        if (j)
                        {
                            sprintf(n_ask + len, "%s", j);
                        }
                    }
                }
                bra_prof_off_line_save_profile_key(prof_id, "obj_load", n_load);
                bra_prof_off_line_save_profile_key(prof_id, "obj_ask", n_ask);
                return WAP_OK;
            case WAP_PROF_READ:
                if (!bra_prof_off_line_read_profile_key(prof_id, "obj_load", load))
                {
                    return WAP_ERR;
                }
                else if (strstr(load, "image/*"))
                {
                    sprintf(val, "1");
                }
                else
                {
                    sprintf(val, "0");
                }
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "0,1");
                return WAP_OK_VAL;
        }
    }
    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewhp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewhp_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED)
    {
        char *homepage;

        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                bra_prof_change_key_str_value(1, "homepage_url", (char*)access_ptr->param[0], NULL);
                return WAP_OK;
            case WAP_PROF_READ:
                homepage = bra_prof_get_key_str_value(1, "homepage_url");
                if (val == NULL)
                {
                    return WAP_ERR;
                }
                else
                {
                    sprintf(val, "%s", homepage);
                }
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "96");
                return WAP_OK_VAL;
        }
    }
    else
    {
        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                bra_prof_off_line_save_profile_key(prof_id, "homepage_url", (char*)access_ptr->param[0]);
                return WAP_OK;
            case WAP_PROF_READ:
                if (!bra_prof_off_line_read_profile_key(prof_id, "homepage_url", val))
                {
                    return WAP_ERR;
                }
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "96");
                return WAP_OK_VAL;
        }
    }
    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewpr_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewpr_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (access_ptr->cmd == WAP_PROF_SET)
    {
        /* check if specified profile ID is valid */
        i = atoi((const char*)access_ptr->param[0]);
        if (i == 0 || i > BRA_CFG_N_PROFILES)
        {
            return WAP_ERR;
        }
    }

    if (msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED)
    {
        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                bra_prof_set_selected_profile(1, i, NULL);
                return WAP_OK;
            case WAP_PROF_READ:
                sprintf(val, "%d", prof_id);
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "1-%d", BRA_CFG_N_PROFILES);
                return WAP_OK_VAL;
        }
    }
    else
    {
        void *reg_handle;

        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                /* write registry */
                reg_handle = MSF_REGISTRY_SET_INIT(MSF_MODID_MSM);
                MSF_REGISTRY_SET_PATH(reg_handle, BRA_PROF_KEY_PROF_ID_PATH);
                MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, BRA_PROF_KEY_PROF_ID, i);
                MSF_REGISTRY_SET_COMMIT(reg_handle);
                return WAP_OK;
            case WAP_PROF_READ:
                sprintf(val, "%d", prof_id);
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "1-%d", BRA_CFG_N_PROFILES);
                return WAP_OK_VAL;
        }
    }
    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewpn_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewpn_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (access_ptr->cmd == WAP_PROF_SET)
    {
        /* check if specified profile ID is valid */
        i = atoi((const char*)access_ptr->param[0]);
        if (i == 0 || i > BRA_CFG_N_PROFILES)
        {
            return WAP_ERR;
        }
    }

    switch (access_ptr->cmd)
    {
        case WAP_PROF_SET:
            if (msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED && i == prof_id)
            {
                bra_prof_change_key_str_value(1, "prof_str", (char*)access_ptr->param[1], NULL);
            }
            else
            {
                bra_prof_off_line_save_profile_key(i, "prof_str", (char*)access_ptr->param[1]);
            }
            return WAP_OK;
        case WAP_PROF_READ:
            for (i = 0; i < BRA_CFG_N_PROFILES; i++)
            {
                char subval[32];

                memset(subval, 0, 32);
                if (bra_prof_off_line_read_profile_key(i, "prof_str", subval))
                {
                    sprintf(val + idx, "%d,%s\r\n", i, subval);
                    idx += strlen(subval);
                }
            }
            if (idx == 0)
            {
                return WAP_ERR;
            }
            else
            {
                return WAP_OK_VAL;
            }
        case WAP_PROF_TEST:
            sprintf(val, "1-%d, 20", BRA_CFG_N_PROFILES);
            return WAP_OK_VAL;
    }

    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewdt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewdt_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int timeout;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED)
    {
        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                if (strcmp((const char*)access_ptr->param[0], "0") == 0)
                {
                    bra_prof_change_key_int_value(1, "timeout", 0, NULL);
                }
                else
                {
                    timeout = atoi((const char*)access_ptr->param[0]);
                    if (timeout == 0)
                    {
                        return WAP_ERR;
                    }
                    else
                    {
                        bra_prof_change_key_int_value(1, "timeout", timeout, NULL);
                    }
                }
                return WAP_OK;
            case WAP_PROF_READ:
                timeout = bra_prof_get_key_int_value(1, "timeout");
                sprintf(val, "%d", timeout);
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "15-300");
                return WAP_OK_VAL;
        }
    }
    else
    {
        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                if (strcmp((const char*)access_ptr->param[0], "0") != 0 &&
                    atoi((const char*)access_ptr->param[0]) == 0)
                {
                    return WAP_ERR;
                }
                else
                {
                    bra_prof_off_line_save_profile_key(prof_id, "timeout", (char*)access_ptr->param[0]);
                }
                return WAP_OK;
            case WAP_PROF_READ:
                bra_prof_off_line_read_profile_key(prof_id, "timeout", val);
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "15-300");
                return WAP_OK_VAL;
        }
    }
    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewli_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewli_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED)
    {
        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                bra_prof_change_key_str_value(1, "prx_uid", (char*)access_ptr->param[0], NULL);
                bra_prof_change_key_str_value(1, "prx_pwd", (char*)access_ptr->param[1], NULL);
                return WAP_OK;
            case WAP_PROF_READ:
                sprintf(val, "%s", bra_prof_get_key_str_value(1, "prx_uid"));
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "32,20");
                return WAP_OK_VAL;
        }
    }
    else
    {
        char uid[32], pwd[20];

        memset(uid, 0, 32);
        memset(pwd, 0, 20);

        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                bra_prof_off_line_save_profile_key(prof_id, "prx_uid", (char*)access_ptr->param[0]);
                bra_prof_off_line_save_profile_key(prof_id, "prx_pwd", (char*)access_ptr->param[1]);
                return WAP_OK;
            case WAP_PROF_READ:
                bra_prof_off_line_read_profile_key(prof_id, "prx_uid", uid);
                sprintf(val, "%s", uid);
                return WAP_OK_VAL;
            case WAP_PROF_TEST:
                sprintf(val, "32,20");
                return WAP_OK_VAL;
        }
    }
    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewba_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewba_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int bmix, total, i, idx = 0;
    char title[20], url[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TBD: access bookmark even if BRA is not running */
    if (!msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED)
    {
        return WAP_ERR;
    }

    total = bra_bkm_get_bkm_total_num();

    switch (access_ptr->cmd)
    {
        case WAP_PROF_SET:
            if ((bmix = atoi((const char*)access_ptr->param[0])) == 0)
            {
                /* add a entry */
                bra_bkm_add_new_bookmark((char*)access_ptr->param[2], (char*)access_ptr->param[1]);
                return WAP_OK;
            }
            else
            {
                /* delete a entry */
                if (bmix > total)
                {
                    return WAP_ERR;
                }
                else
                {
                    /* TBD */
                    return WAP_ERR;
                }
            }
            return WAP_OK;
        case WAP_PROF_READ:
            for (i = 1; i <= total; i++)
            {
                memset(title, 0, 20);
                memset(url, 0, 32);
                bra_bkm_get_bkm(i, title, url);

                if ((strlen(val) + 3 + strlen(url) + strlen(title)) >= 128)
                {
                    break;
                }

                sprintf(val + idx, "%d,%s,%s", i, url, title);
                idx += 3 + strlen(url) + strlen(title);
            }
            if (idx > 0)
            {
                return WAP_OK_VAL;
            }
            else
            {
                return WAP_OK;
            }
        case WAP_PROF_TEST:
            if (total == 0)
            {
                sprintf(val, "0, 96, 20");
            }
            else if (total == 1)
            {
                sprintf(val, "1, 96, 20");
            }
            else
            {
                sprintf(val, "%d, 96, 20", total);
            }
            return WAP_OK_VAL;
    }
    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewbr_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewbr_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int bmix;
    char title[20], url[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(title, 0, 20);
    memset(url, 0, 32);

    /* TBD: access bookmark even if BRA is not running */
    if (!msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED)
    {
        return WAP_ERR;
    }

    switch (access_ptr->cmd)
    {
        case WAP_PROF_READ:
            bmix = atoi((const char*)access_ptr->param[0]);
            if (bmix == 0)
            {
                return WAP_ERR;
            }
            else
            {
                bra_bkm_get_bkm(bmix, title, url);
                sprintf(val, "%s,%s", url, title);
            }
            return WAP_OK_VAL;
        case WAP_PROF_TEST:
            bmix = bra_bkm_get_bkm_total_num();
            if (bmix == 0)
            {
                sprintf(val, "0");
            }
            else if (bmix == 1)
            {
                sprintf(val, "1");
            }
            else
            {
                sprintf(val, "1-%d", bmix);
            }
            return WAP_OK_VAL;
    }
    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_ewni_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id         [IN]        
 *  access_ptr      [?]         
 *  val             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int wap_prof_ewni_hdlr(int prof_id, wap_prof_access_req_struct *access_ptr, char *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int acc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msf_mod_status[MSF_MODID_BRA] != MSM_MODULE_STATUS_TERMINATED)
    {
        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                if (strcmp((const char*)access_ptr->param[0], "0") == 0)
                {
                    bra_prof_change_key_int_value(1, "acc_id", 0, NULL);
                }
                else
                {
                    if ((acc_id = atoi((const char*)access_ptr->param[0])) == 0)
                    {
                        return WAP_ERR;
                    }
                    else
                    {
                        bra_prof_change_key_int_value(1, "acc_id", acc_id, NULL);
                    }
                }
                return WAP_OK;
            case WAP_PROF_READ:
                acc_id = bra_prof_get_key_int_value(1, "acc_id");
                sprintf(val, "%d", acc_id);
                return WAP_OK_VAL;
        }
    }
    else
    {
        switch (access_ptr->cmd)
        {
            case WAP_PROF_SET:
                if (strcmp((const char*)access_ptr->param[0], "0") != 0 &&
                    atoi((const char*)access_ptr->param[0]) == 0)
                {
                    return WAP_ERR;
                }
                else
                {
                    bra_prof_off_line_save_profile_key(prof_id, "acc_id", (char*)access_ptr->param[0]);
                }
                return WAP_OK;
            case WAP_PROF_READ:
                bra_prof_off_line_read_profile_key(prof_id, "acc_id", val);
                return WAP_OK_VAL;
        }
    }

    /* fail to handle */
    return WAP_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  wap_prof_access_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_prof_access_proc(int prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_prof_access_req_struct *access_ptr = (wap_prof_access_req_struct*) wap_prof_access.access_req_ptr;
    int result = 0;
    char val[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof_id < 0)
    {
        wap_send_prof_access_cnf(&wap_prof_access, 0, NULL);
    }

    memset(val, 0, 128);

    switch (access_ptr->query)
    {
        case WAP_PROF_EWIL: /* WAP Image Load */
            result = wap_prof_ewil_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWHP: /* WAP Homepage */
            result = wap_prof_ewhp_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWPR: /* WAP Profiles */
            result = wap_prof_ewpr_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWPN: /* WAP Profile Name */
            result = wap_prof_ewpn_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWDT: /* WAP Download Timeout */
            result = wap_prof_ewdt_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWLI: /* WAP Login */
            result = wap_prof_ewli_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWBA: /* WAP Bookmark Add */
            result = wap_prof_ewba_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWBR: /* WAP Bookmark Read */
            result = wap_prof_ewbr_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWNI: /* WAP Current Network Account Id */
            result = wap_prof_ewni_hdlr(prof_id, access_ptr, val);
            break;
        case WAP_PROF_EWPB: /* WAP Preferred Bearer, non-support */
        case WAP_PROF_EWCG: /* WAP CSD Gateway, non-support */
        case WAP_PROF_EWCT: /* WAP Connection Timeout, non-support */
            break;
    }

    switch (result)
    {
        case WAP_OK:
            wap_send_prof_access_cnf(&wap_prof_access, 1, NULL);
            break;
        case WAP_OK_VAL:
            wap_send_prof_access_cnf(&wap_prof_access, 1, val);
            break;
        case WAP_ERR:
            wap_send_prof_access_cnf(&wap_prof_access, 0, NULL);
            break;
        case WAP_ERR_VAL:
            wap_send_prof_access_cnf(&wap_prof_access, 0, val);
            break;
    }

    free_local_para((local_para_struct*) wap_prof_access.access_req_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_prof_list_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_src_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_get_prof_list_req_hdlr(module_type req_src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_get_prof_list_rsp_struct *prof_list_rsp;
    bra_prof_list_t *prof_list;
    ilm_struct *ilm_ptr;
    MSF_UINT8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_list_rsp =
        (wap_get_prof_list_rsp_struct*) construct_local_para(sizeof(wap_get_prof_list_rsp_struct), TD_CTRL);
    result = bra_prof_offline_get_prof_list(&prof_list);

    if (result != WAP_PROF_SUCCESS)
    {
        prof_list_rsp->result = result;
        prof_list_rsp->number = 0;
        prof_list_rsp->prof_list = NULL;
    }
    else
    {
        int i;

        prof_list_rsp->result = WAP_PROF_SUCCESS;
        prof_list_rsp->number = prof_list->n_items;
        prof_list_rsp->prof_list =
            (wap_prof_entry_struct*)
            get_ctrl_buffer((kal_uint16) (sizeof(wap_prof_entry_struct) * prof_list->n_items));

        for (i = 0; i < prof_list->n_items; i++)
        {
            /* UTF8,convert to UCS2 */
            char *s = prof_list->prof[i].prof_name;

            /* long srcLen = strlen(s); */
            long dstLen = WAP_PROF_MAX_NAME_SIZE;

            /* msf_charset_utf8_to_ucs2le(s, &srcLen, (char*)(prof_list_rsp->prof_list[i].name.value), &dstLen); */

            dstLen = widget_utf8_to_ucs2_string(
                        (kal_uint8*) (prof_list_rsp->prof_list[i].name.value),
                        dstLen,
                        (const kal_uint8*)s);

            prof_list_rsp->prof_list[i].name.len = dstLen;
            prof_list_rsp->prof_list[i].id = i;
            BRA_FREE(prof_list->prof[i].prof_name);

            if (prof_list->prof[i].con_type == BRA_SET_CONNECTION_TYPE_HTTP)
            {
                prof_list_rsp->prof_list[i].conn_type = WAP_PROF_CONN_TYPE_HTTP;
            }
            else if (prof_list->prof[i].con_type == BRA_SET_CONNECTION_TYPE_WSP_CL)
            {
                prof_list_rsp->prof_list[i].conn_type = WAP_PROF_CONN_TYPE_WSP_CL;
            }
            else if (prof_list->prof[i].con_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
            {
                prof_list_rsp->prof_list[i].conn_type = WAP_PROF_CONN_TYPE_WSP_CO;
            }
        }
        BRA_FREE(prof_list);
    }

    {
        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->local_para_ptr = (local_para_struct*) prof_list_rsp;
        ilm_ptr->msg_id = MSG_ID_WAP_GET_PROF_LIST_RSP;
        ilm_ptr->peer_buff_ptr = NULL;
    #ifdef __J2ME__
        if (req_src_id == MOD_J2ME)
            SEND_ILM(MOD_WAP, req_src_id, WAP_J2ME_SAP, ilm_ptr)
            else
    #endif /* __J2ME__ */ 
            SEND_ILM(MOD_WAP, req_src_id, WAP_MMI_SAP, ilm_ptr)}
            }


/*****************************************************************************
 * FUNCTION
 *  wap_get_prof_content_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  content_req_ptr     [?]         
 *  req_src_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
            void wap_get_prof_content_req_hdlr(
                    wap_get_prof_content_req_struct *content_req_ptr,
                    module_type req_src_id)
        {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            wap_get_prof_content_rsp_struct *prof_cont_rsp;
            bra_prof_content_t *prof_cont;
            MSF_UINT8 result;
            ilm_struct *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
            prof_cont_rsp =
                (wap_get_prof_content_rsp_struct*) construct_local_para(
                                                    sizeof(wap_get_prof_content_rsp_struct),
                                                    TD_CTRL);

            result = bra_prof_off_line_load_profile(content_req_ptr->id, &prof_cont);
            if (result != WAP_PROF_SUCCESS)
            {
                prof_cont_rsp->result = result;
            }
            else
            {
                prof_cont_rsp->result = WAP_PROF_SUCCESS;

                if (prof_cont->con_type == BRA_SET_CONNECTION_TYPE_HTTP)
                {
                    prof_cont_rsp->conn_type = WAP_PROF_CONN_TYPE_HTTP;
                }
                else if (prof_cont->con_type == BRA_SET_CONNECTION_TYPE_WSP_CL)
                {
                    prof_cont_rsp->conn_type = WAP_PROF_CONN_TYPE_WSP_CL;
                }
                else if (prof_cont->con_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
                {
                    prof_cont_rsp->conn_type = WAP_PROF_CONN_TYPE_WSP_CO;
                }

                prof_cont_rsp->net_id = prof_cont->net_id;
                prof_cont_rsp->net_id2 = prof_cont->net_id2;
                prof_cont_rsp->id = prof_cont->id;

                if (prof_cont->password == NULL)
                {
                    prof_cont_rsp->password[0] = '\0';
                }
                else if (strlen(prof_cont->password) >= WAP_PROF_MAX_PWD_SIZE)
                {
                    strncpy((char*)prof_cont_rsp->password, prof_cont->password, WAP_PROF_MAX_PWD_SIZE - 1);
                    prof_cont_rsp->password[WAP_PROF_MAX_PWD_SIZE - 1] = '\0';
                }
                else
                {
                    strcpy((char*)prof_cont_rsp->password, prof_cont->password);
                }

                BRA_FREE(prof_cont->password);

                if (prof_cont->username == NULL)
                {
                    prof_cont_rsp->username[0] = '\0';
                }
                else if (strlen(prof_cont->username) >= WAP_PROF_MAX_UID_SIZE)
                {
                    strncpy((char*)prof_cont_rsp->username, prof_cont->username, WAP_PROF_MAX_UID_SIZE - 1);
                    prof_cont_rsp->username[WAP_PROF_MAX_UID_SIZE - 1] = '\0';
                }
                else
                {
                    strcpy((char*)prof_cont_rsp->username, prof_cont->username);
                }

                BRA_FREE(prof_cont->username);

                memcpy(prof_cont_rsp->prx_ip, prof_cont->prx_ip, 4);

                prof_cont_rsp->prx_port = prof_cont->prx_port;
            }

            {
                ilm_ptr = allocate_ilm(MOD_WAP);
                ilm_ptr->local_para_ptr = (local_para_struct*) prof_cont_rsp;
                ilm_ptr->msg_id = MSG_ID_WAP_GET_PROF_CONTENT_RSP;
                ilm_ptr->peer_buff_ptr = NULL;
            #ifdef __J2ME__
                if (req_src_id == MOD_J2ME)
                    SEND_ILM(MOD_WAP, req_src_id, WAP_J2ME_SAP, ilm_ptr)
                    else
            #endif /* __J2ME__ */ 
                    SEND_ILM(MOD_WAP, req_src_id, WAP_MMI_SAP, ilm_ptr)}
                    }


/*****************************************************************************
 * FUNCTION
 *  wap_get_bra_prof_id_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_src_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
                    void wap_get_bra_prof_id_req_hdlr(module_type req_src_id)
                {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
                    wap_get_bra_prof_id_rsp_struct *bra_prof_id_rsp;
                    ilm_struct *ilm_ptr;
                    bra_prof_content_t *prof_cont;
                    MSF_UINT8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
                    bra_prof_id_rsp =
                        (wap_get_bra_prof_id_rsp_struct*) construct_local_para(
                                                            sizeof(wap_get_bra_prof_id_rsp_struct),
                                                            TD_CTRL);

                    bra_prof_id_rsp->prof_id = bra_prof_get_sim_profile_id_in_active_use(BRA_PROF_ID_BRA, 0);
                    result = bra_prof_off_line_load_bra_active_profile(&prof_cont);
                    if (result != WAP_PROF_SUCCESS)
                    {
                        bra_prof_id_rsp->net_id = 0xFF;
                        bra_prof_id_rsp->net_id2 = 0xFF;
                    }
                    else
                    {
                        bra_prof_id_rsp->net_id = prof_cont->net_id;
                        bra_prof_id_rsp->net_id2 = prof_cont->net_id2;
                        BRA_FREE(prof_cont->password);
                        BRA_FREE(prof_cont->username);
                    }

                    {
                        ilm_ptr = allocate_ilm(MOD_WAP);
                        ilm_ptr->local_para_ptr = (local_para_struct*) bra_prof_id_rsp;
                        ilm_ptr->msg_id = MSG_ID_WAP_GET_BRA_PROF_ID_RSP;
                        ilm_ptr->peer_buff_ptr = NULL;
                    #ifdef __J2ME__
                        if (req_src_id == MOD_J2ME)
                            SEND_ILM(MOD_WAP, req_src_id, WAP_J2ME_SAP, ilm_ptr)
                            else
                    #endif /* __J2ME__ */ 
                            SEND_ILM(MOD_WAP, req_src_id, WAP_MMI_SAP, ilm_ptr)}
                            }

void wap_get_user_agent_req_hdlr(module_type req_src_id)
{
   const char *user_agent;
   wap_get_user_agent_rsp_struct *user_agent_rsp;
   ilm_struct *ilm_ptr;

   user_agent_rsp = (wap_get_user_agent_rsp_struct*) construct_local_para(sizeof(wap_get_user_agent_rsp_struct), TD_CTRL);

   user_agent = bra_prof_get_cur_user_agent();

   user_agent_rsp->user_agent_len = strlen(user_agent);
   strncpy((char *)user_agent_rsp->user_agent, user_agent, strlen(user_agent));
   
   {
      ilm_ptr = allocate_ilm(MOD_WAP);
      ilm_ptr->local_para_ptr = (local_para_struct*)user_agent_rsp;
      ilm_ptr->msg_id         = MSG_ID_WAP_GET_USER_AGENT_RSP;
      ilm_ptr->peer_buff_ptr  = NULL;
#ifdef __J2ME__
      if(req_src_id == MOD_J2ME)
        SEND_ILM(MOD_WAP, req_src_id, WAP_J2ME_SAP, ilm_ptr)
      else
#endif
        SEND_ILM(MOD_WAP, req_src_id, WAP_MMI_SAP, ilm_ptr)
   }  
}

